#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

struct File;
#define true TRUE
#define false FALSE

extern "C" {
	File* FileOpen(u8* filename, u8* mode) {
		return (File*)fopen((const char*)filename, (const char*)mode);
	}
	u32 FileClose(File *file){
		return fclose((FILE*)file);
	}

	u64 GetLine(u8 **lineptr, u64 *n, File *file){
		return getline((char **)lineptr, n, (FILE*)file);
	}
	u64 FileRead(u8* f, u64 a, u64 b, File* c) {
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
}

#define char character
