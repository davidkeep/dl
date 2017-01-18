#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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

struct File;
#define true TRUE
#define false FALSE

extern "C" {
	File* FileOpen(i8* filename, i8* mode) {
		return (File*)fopen((const char*)filename, (const char*)mode);
	}
	u32 FileClose(File *file){
		return fclose((FILE*)file);
	}
	File* FileOut() {
		return (File*)stdout;
	}
	File* FileError() {
		return (File*)stderr;
	}
	i8* GetLine(File *file, i8 *data, i32 count){
		return (i8*)fgets((char*)data, count, (FILE*)file);
	}
	u64 FileRead(i8* f, u64 a, u64 b, File* c) {
		return fread(f, a, b, (FILE*)c);
	}
	i32 FileGetChar(File* file){
		return fgetc((FILE*)file);
	}
	u64 FileWrite (voidptr ptr, u64 size, u64 count, File* file){
		return fwrite(ptr, size, count, (FILE*)file);
	}
	void FileFlush(File* file){
		fflush((FILE*)file);
	}
	i32 FilePut (File* file, i8* data) {
		return fputs((const char*)data, (FILE*)file);
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
}

#define char character
