#include <stdio.h>
#include <stdint.h>
// #include <stdlib.h>
//#include <cstdlib>

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

extern int atoi(const char* str);

// extern "C"
// {
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
	void Backtrace() {}
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
//}

#define char character
