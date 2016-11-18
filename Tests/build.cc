#include "build.h"
#define f0__ "/Users/Davie/Desktop/dl/Tests/Main.dl"
#define f1__ "/Users/Davie/Desktop/dl/Tests/Array.dl"
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
i32 main(){
	#line 0 f0__ //Variable
	i32 i={0};
	#line 0 f0__ //Variable
	f32 f={0};
	#line 0 f0__ //Variable
	Array1 array={0};
	#line 0 f0__ //Call
	Init0111(array,10);
	#line 31 f0__ //Return
	return (1+5);
}
#line 0 f0__ //FuncDef
i32* Alloc0112(i64 length){
	#line 0 f0__ //Return
	return (i32*)0;
}
#line 0 f0__ //FuncDef
void Init0111(Array1 array,i64 length){
	#line 18 f1__ //BinaryOp
	array.elements = Alloc0112(length);
	#line 19 f1__ //BinaryOp
	array.length = length;
}
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
#line 0 f0__ //FuncDef
