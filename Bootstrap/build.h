#include "../lang/Header.h"
struct TypeInfo95;
struct tuple1;
struct tuple2;
struct tuple3;
struct tuple4;
struct Type;
struct str133;
struct Spec;
struct TypeSpec97;
struct TypePointer98;
struct Expr99;
struct Block100;
struct Function102;
struct Structure103;
struct Variable104;
struct tuple5;
struct tuple6;
struct File;
struct tuple7;
struct Token144;
struct Lexer145;
struct DynamicArray1255;
struct tuple8;
struct tuple9;
struct Array1259;
struct tuple10;
struct TypeInfo95{
	u32 size;
};
struct tuple1{
	i64 i0;
	i64 i1;
};
struct tuple2{
	f64 i0;
	f64 i1;
};
struct tuple3{
	f32 i0;
	f32 i1;
};
struct tuple4{
	u64 i0;
	u64 i1;
};
struct str133{
	i64 length;
	i8* chars;
};
struct TypeSpec97{
	str133 ident;
	Spec* spec;
};
struct TypePointer98{
	Type* pointed;
};
struct Expr99{
	i64 kind;
	Type* typ;
};
struct Block100{
	Expr99 super;
};
struct Function102{
	Expr99 super;
	str133 ident;
};
struct Structure103{
	Expr99 super;
	str133 ident;
};
struct Variable104{
	Expr99 super;
	str133 ident;
};
struct tuple5{
	i64 i1;
};
struct tuple6{
	i8* i0;
	i8* i1;
	i64 i2;
};
struct tuple7{
	i64 i1;
};
struct Token144{
	i32 Type;
	str133 string;
	f64 number;
};
struct Lexer145{
	File* file;
	i32 nextCharacter;
	Token144 token;
};
struct DynamicArray1255{
	i64 capacity;
	i64 length;
	i8* elements;
};
struct tuple8{
	DynamicArray1255& i0;
	i8 i1;
};
struct tuple9{
	DynamicArray1255& i0;
	i64 i1;
};
struct Array1259{
	i64 length;
	i8* elements;
};
struct tuple10{
	Array1259& i0;
	i64 i1;
};
i32 Id105();
i32 Id106();
i32 Id107();
Structure103* Structure108(Expr99& expr);
Function102* Function109(Expr99& expr);
Variable104* Variable110(Expr99& expr);
Structure103* Structure111();
i32 main();
void Init0260(Array1259& array,i64 length);
i8& OpArray0261(Array1259& array,i64 index);
void Init0256(DynamicArray1255& array);
void Push0257(DynamicArray1255& array,i8 value);
void Reserve0258(DynamicArray1255& array,i64 size);
extern "C" i32 putchar(i32 c);
extern "C" void abort();
extern "C" i32 strlen(i8* string);
extern "C" i32 strcpy(i8* dst,i8* src);
void Print134(str133 string);
void Println135(str133 string);
str133 String136(i8* string);
void Error137(str133 string);
str133 add138(str133 a,str133 b);
str133 String139(i8* chars,i64 length);
str133 String140(i64 number);
str133 String141(f32 number);
i64 Equal142(str133 l,str133 r);
i64 Hash143(str133 string);
i32 Char146(str133 char);
Lexer145 Lexer147(str133 file);
i32 Peek148(Lexer145& self);
i32 Get149(Lexer145& self);
extern "C" i32 isspace(i32 v);
extern "C" i32 isalpha(i32 v);
extern "C" i32 isalnum(i32 v);
extern "C" i32 isdigit(i32 v);
void Consume154(Lexer145& self);
Token144 Next155(Lexer145& self);
extern "C" voidptr malloc(u64 c);
extern "C" voidptr calloc(u64 nmem,u64 size);
extern "C" voidptr realloc(voidptr nmem,u64 size);
extern "C" voidptr memcpy(voidptr dst,voidptr src,u64 count);
extern "C" voidptr memset(voidptr ptr,i32 value,u64 count);
void Assert163(i8 condition,str133 reason);
void Assert164(i8 condition);
i8* Alloc0252(i64 len);
Structure103* Alloc1254(i64 len);
void CopyPtr0253(i8* from,i8* to,i64 len);
i64 i64168(u8 i);
i64 i64169(u16 i);
i64 i64170(u32 i);
i64 i64171(u64 i);
i64 i64172(i8 i);
i64 i64173(i32 i);
i64 i64174(i64 i);
i64 i64175(f32 i);
i64 i64176(f64 i);
i32 i32177(u8 i);
i32 i32178(u32 i);
i32 i32179(u64 i);
i32 i32180(i8 i);
i32 i32181(i32 i);
i32 i32182(i64 i);
i32 i32183(f32 i);
i32 i32184(f64 i);
i8 i8185(u8 i);
i8 i8186(u32 i);
i8 i8187(u64 i);
i8 i8188(i8 i);
i8 i8189(i32 i);
i8 i8190(i64 i);
i8 i8191(f32 i);
i8 i8192(f64 i);
u8 u8193(u8 i);
u8 u8194(u32 i);
u8 u8195(u64 i);
u8 u8196(i8 i);
u8 u8197(i32 i);
u8 u8198(i64 i);
u8 u8199(f32 i);
u8 u8200(f64 i);
u16 u16201(u16 i);
u16 u16202(u32 i);
u16 u16203(u64 i);
u16 u16204(i8 i);
u16 u16205(i32 i);
u16 u16206(i64 i);
u16 u16207(f32 i);
u16 u16208(f64 i);
u32 u32209(u8 i);
u32 u32210(u32 i);
u32 u32211(u64 i);
u32 u32212(i8 i);
u32 u32213(i32 i);
u32 u32214(i64 i);
u32 u32215(f32 i);
u32 u32216(f64 i);
u64 u64217(u8 i);
u64 u64218(u32 i);
u64 u64219(u64 i);
u64 u64220(i8 i);
u64 u64221(i32 i);
u64 u64222(i64 i);
u64 u64223(f32 i);
u64 u64224(f64 i);
f32 f32225(u8 i);
f32 f32226(u32 i);
f32 f32227(u64 i);
f32 f32228(i8 i);
f32 f32229(i32 i);
f32 f32230(i64 i);
f32 f32231(f32 i);
f32 f32232(f64 i);
f64 f64233(u8 i);
f64 f64234(u32 i);
f64 f64235(u64 i);
f64 f64236(i8 i);
f64 f64237(i32 i);
f64 f64238(i64 i);
f64 f64239(f32 i);
f64 f64240(f64 i);
extern "C" File* FileOpen(i8* filename,i8* mode);
extern "C" u32 FileClose(File* file);
extern "C" u64 GetLine(i8** lineptr,u64* n,File* stream);
extern "C" u64 FileRead(i8* f,u64 a,u64 b,File* c);
extern "C" i32 FileGetChar(File* file);
extern "C" u64 FileWrite(voidptr ptr,u64 size,u64 count,File* stream);
extern "C" void FileFlush(File* file);
extern "C" File* FileOut();
extern "C" File* FileError();
extern "C" i32 chdir(i8* dir);
