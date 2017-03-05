#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstdlib>
// #include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <execinfo.h>
#include <signal.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef unsigned long u64;

typedef void* voidptr;

typedef float f32;
typedef double f64;
typedef void* FnPtr;
typedef void* func;

typedef struct FileHandle FileHandle;

#define true TRUE
#define false FALSE

extern "C" int atoi(const char* str);

extern "C"
{
	FileHandle* FileOpen(i8* filename, i8* mode) {
		return (FileHandle*)fopen((const char*)filename, (const char*)mode);
	}
	u32 FileClose(FileHandle *file){
		return fclose((FILE*)file);
	}
	FileHandle* FileOut() {
		return (FileHandle*)stdout;
	}
	FileHandle* FileError() {
		return (FileHandle*)stderr;
	}
	i8* GetLine(FileHandle *file, i8 *lineptr, i32 n){
		return (i8*)fgets((char *)lineptr, n, (FILE*)file);
	}
	u64 FileRead(i8* f, u64 a, u64 b, FileHandle* c) {
		return fread(f, a, b, (FILE*)c);
	}
	i32 FileGetChar(FileHandle* file){
		return fgetc((FILE*)file);
	}
	u64 FileWrite (i8* ptr, u64 size, u64 count, FileHandle* file){
		return fwrite(ptr, size, count, (FILE*)file);
	}
	void Backtrace() {
		void* callstack[128];
		int i, frames = backtrace(callstack, 128);
		char** strs = backtrace_symbols(callstack, frames);
		for (i = 0; i < frames; ++i) {
			printf("%s\n", strs[i]);
		}
		free(strs);
	}
	void FileFlush(FileHandle* file){
		fflush((FILE*)file);
	}
	i32 FilePut(FileHandle* file, i8* chars){
		return fputs((const char*)chars, (FILE*)file);
	}
	void FlushOut() {
		fflush(stdout);
	}
	i32 dlatoi(i8* src) {
		return atoi((const char*)src);
	}
	i64 dlStringToI64(i8* src) {
		return strtoll((const char*)src, 0, 0);
	}
	f64 dlStringToF64(i8* src) {
		f64 a = strtod((const char*)src, 0);
		printf("asdfasdf%f\n", float(a));
		return a;
	}
	i32 dlSystem (i8* data) {
		return system((char*)data);
	}
}


i64 dl_ArgsCount;
i8** dl_Args;

extern "C" i8** dlArgs (i8* data) {
	return dl_Args;
}

extern "C" i64 dlArgsCount (i8* data) {
	return dl_ArgsCount;
}


// @TODO remove these extra size instructions when our size function matches c's output
extern "C" i8* dlMalloc (i64 size) {
	return (i8*)malloc(size * 100);
}
extern "C" i8* dlMallocZero (i64 size) {
	return (i8*)calloc(1, size * 100);
}

extern "C" i8* dlRealloc (i8* prev, i64 size) {
	return (i8*)realloc(prev, size * 100);
}

extern "C" i8* dlMemcpy (i8* dst, i8* src, i64 size) {
	return (i8*)memcpy(dst, src, size);
}

extern "C" i8* dlMemset (i8* dst, i32 value, i64 size) {
	return (i8*)memset(dst, value, size);
}

extern "C" void Main_();


int main(int argc, char** argv) 
{
	Main_();
	return 0;
}

#define char character
