#include "lang/Header.h"
struct i64i64;
struct i32i32;
struct f64f64;
struct f32f32;
struct u64u64;
struct u32u32;
struct TypeInfo;
struct Vec3;
struct Array1;
struct i64i64{
	i64 i0;
	i64 i1;
};
struct i32i32{
	i32 i0;
	i32 i1;
};
struct f64f64{
	f64 i0;
	f64 i1;
};
struct f32f32{
	f32 i0;
	f32 i1;
};
struct u64u64{
	u64 i0;
	u64 i1;
};
struct u32u32{
	u32 i0;
	u32 i1;
};
struct TypeInfo{
	i32 size;
};
struct Vec3{
	f32 x;
	f32 y;
	f32 z;
};
struct Array1{
	i64 length;
	i32* elements;
};
i32 main();
i32* Alloc0112(i64 length);
void Init0111(Array1 array,i64 length);
