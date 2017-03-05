#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstdlib>

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
	i8* GetLine(File *file, i8 *lineptr, i32 n){
		return (i8*)fgets((char *)lineptr, n, (FILE*)file);
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
	void Backtrace() {}
	void FileFlush(File* file){
		fflush((FILE*)file);
	}
	i32 FilePut(File* file, i8* chars){
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

#define char character
