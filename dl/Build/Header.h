#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstdlib>
// #include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <execinfo.h>
#include <cxxabi.h>

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
		void Backtrace()
{
	FILE *out = stderr;
	unsigned int max_frames = 63;
    fprintf(out, "stack trace:\n");

    // storage array for stack trace address data
    void* addrlist[max_frames+1];

    // retrieve current stack addresses
    int addrlen = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));

    if (addrlen == 0) {
	fprintf(out, "  <empty, possibly corrupt>\n");
	return;
    }

    // resolve addresses into strings containing "filename(function+address)",
    // this array must be free()-ed
    char** symbollist = backtrace_symbols(addrlist, addrlen);

    // allocate string which will be filled with the demangled function name
    size_t funcnamesize = 256;
    char* funcname = (char*)malloc(funcnamesize);

    // iterate over the returned symbol lines. skip the first, it is the
    // address of this function.
    for (int i = 1; i < addrlen; i++)
    {
	char *begin_name = 0, *begin_offset = 0, *end_offset = 0;

	// find parentheses and +address offset surrounding the mangled name:
	// ./module(function+0x15c) [0x8048a6d]
	for (char *p = symbollist[i]; *p; ++p)
	{
	    if (*p == '_')
		begin_name = p;
	    else if (*p == '+')
		begin_offset = p;
	    else if (*p == ' ' && begin_offset) {
		end_offset = p;
		break;
	    }
	}

	if (begin_name && begin_offset && end_offset
	    && begin_name < begin_offset)
	{
	    *begin_name++ = '\0';
	    *begin_offset++ = '\0';
	    *end_offset = '\0';

	    // mangled name is now in [begin_name, begin_offset) and caller
	    // offset in [begin_offset, end_offset). now apply
	    // __cxa_demangle():

	    int status;
	    char* ret = abi::__cxa_demangle(begin_name,
					    funcname, &funcnamesize, &status);
	    if (status == 0) {
		funcname = ret; // use possibly realloc()-ed string
		fprintf(out, "  %s : %s+%s\n",
			symbollist[i], funcname, begin_offset);
	    }
	    else {
		// demangling failed. Output function name as a C function with
		// no arguments.
		fprintf(out, "  %s : %s()+%s\n",
			symbollist[i], begin_name, begin_offset);
	    }
	}
	else
	{
	    // couldn't parse the line? print the whole line.
	    fprintf(out, "  %s\n", symbollist[i]);
	}
    }

    free(funcname);
    free(symbollist);
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
