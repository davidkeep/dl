#include "build.h"
#define f0__ "/Users/Davie/Desktop/dl/Compiler/Main.dl"
#define f1__ "/Users/Davie/Desktop/dl/Compiler/dl/Array.dl"
#define f2__ "/Users/Davie/Desktop/dl/Compiler/dl/String.dl"
#define f3__ "/Users/Davie/Desktop/dl/Compiler/lexer.dl"
#define f4__ "/Users/Davie/Desktop/dl/Compiler/dl/Memory.dl"
#define f5__ "/Users/Davie/Desktop/dl/Compiler/dl/Conversion.dl"
#define f6__ "/Users/Davie/Desktop/dl/Compiler/dl/c.dl"
TypeInfo95 typeinfo0={sizeof(i8)};
TypeInfo95 typeinfo1={sizeof(Structure103)};
i32 LexerIdentifier=(-1);
i32 LexerNumber=(-2);
i32 LexerString=(-3);
i8 true=1;
i8 false=0;
i8 CharA=65;
i8 CharB=66;
i8 CharC=67;
i8 CharD=68;
i8 CharE=69;
i8 CharF=70;
i8 CharG=71;
i8 CharH=72;
i8 CharI=73;
i8 CharJ=74;
i8 CharK=75;
i8 CharL=76;
i8 CharM=77;
i8 CharN=78;
i8 CharO=79;
i8 CharP=80;
i8 CharQ=81;
i8 CharR=82;
i8 CharS=83;
i8 CharT=84;
i8 CharU=85;
i8 CharV=86;
i8 CharW=87;
i8 CharX=88;
i8 CharY=89;
i8 CharZ=90;
i8 Chara=97;
i8 Charb=98;
i8 Charc=99;
i8 Chard=100;
i8 Chare=101;
i8 Charf=102;
i8 Charg=103;
i8 Charh=104;
i8 Chari=105;
i8 Charj=106;
i8 Chark=107;
i8 Charl=108;
i8 Charm=109;
i8 Charn=110;
i8 Charo=111;
i8 Charp=112;
i8 Charq=113;
i8 Charr=114;
i8 Chars=115;
i8 Chart=116;
i8 Charu=117;
i8 Charv=118;
i8 Charw=119;
i8 Charx=120;
i8 Chary=121;
i8 Charz=122;
i8 Char0=48;
i8 Char1=49;
i8 Char2=50;
i8 Char3=51;
i8 Char4=52;
i8 Char5=53;
i8 Char6=54;
i8 Char7=55;
i8 Char8=56;
i8 Char9=57;
										#line 54 f0__ //Func
	i32 Id105(){
		#line 55 f0__ //Return
		return 1;
}
	#line 57 f0__ //Func
	i32 Id106(){
		#line 58 f0__ //Return
		return 2;
}
	#line 60 f0__ //Func
	i32 Id107(){
		#line 61 f0__ //Return
		return 3;
}
	#line 65 f0__ //Func
	Structure103* Structure108(Expr99& expr){
		#line 67 f0__ //Call
		Assert163((expr.kind==Id106()),str133{13,(i8*)"Type mismatch"});
		#line 68 f0__ //Return
		return (Structure103*)(&expr);
}
	#line 71 f0__ //Func
	Function102* Function109(Expr99& expr){
		#line 73 f0__ //Call
		Assert163((expr.kind==Id105()),str133{13,(i8*)"Type mismatch"});
		#line 74 f0__ //Return
		return (Function102*)(&expr);
}
	#line 77 f0__ //Func
	Variable104* Variable110(Expr99& expr){
		#line 79 f0__ //Call
		Assert163((expr.kind==Id107()),str133{13,(i8*)"Type mismatch"});
		#line 80 f0__ //Return
		return (Variable104*)(&expr);
}
	#line 83 f0__ //Func
	Structure103* Structure111(){
		#line 85 f0__ //Variable
		Structure103* structure=Alloc1254(1);
		#line 86 f0__ //Binary
		(*structure).super.kind = Id106();
		#line 87 f0__ //Return
		return structure;
}
	#line 90 f0__ //Func
	i32 main(){
		#line 91 f0__ //Variable
		Lexer145 lexer=Lexer147(str133{7,(i8*)"Test.dl"});
		#line 93 f0__ //Variable
		Structure103* structure=Structure111();
		#line 94 f0__ //Call
		Structure108((*structure).super);
		#line 96 f0__ //For
		while(lexer.token.Type){
			#line 98 f0__ //Call
			Println135(lexer.token.string);
			#line 99 f0__ //Call
			Consume154(lexer);
		};
}
			#line 15 f1__ //Func
	void Init0260(Array1259& array,i64 length){
		#line 16 f1__ //Binary
		array.elements = Alloc0252(length);
		#line 17 f1__ //Binary
		array.length = length;
}
	#line 20 f1__ //Func
	i8& OpArray0261(Array1259& array,i64 index){
		#line 21 f1__ //If
		if((index>=array.length)){
			#line 22 f1__ //Call
			Assert163(0,add138(add138(add138(add138(str133{28,(i8*)"Array access out of bounds ["},String140(index)),str133{1,(i8*)"]"}),str133{11,(i8*)" length is "}),String140(array.length)));
		};
		#line 24 f1__ //Return
		return (*(array.elements+index));
}
	#line 28 f1__ //Func
		#line 35 f1__ //Func
	void Init0256(DynamicArray1255& array){
		#line 37 f1__ //Binary
		array.capacity = 0;
		#line 38 f1__ //Binary
		array.length = 0;
		#line 39 f1__ //Binary
		array.elements = (i8*)0;
}
	#line 42 f1__ //Func
	void Push0257(DynamicArray1255& array,i8 value){
		#line 44 f1__ //If
		if((array.capacity<(array.length+1))){
			#line 46 f1__ //Variable
			i64 capacity=(array.capacity*2);
			#line 47 f1__ //If
			if((capacity<10)){
				#line 48 f1__ //Call
				Reserve0258(array,10);
			}else{
				#line 51 f1__ //Call
				Reserve0258(array,capacity);
			};
		};
		#line 54 f1__ //Binary
		(*(array.elements+array.length)) = value;
		#line 55 f1__ //Binary
		array.length = (array.length+1);
}
	#line 58 f1__ //Func
	void Reserve0258(DynamicArray1255& array,i64 size){
		#line 60 f1__ //If
		if((array.capacity<size)){
			#line 62 f1__ //Variable
			i64 bytes=(i64170(typeinfo0.size)*size);
			#line 63 f1__ //Binary
			array.elements = (i8*)realloc((voidptr)array.elements,u64222(bytes));
			#line 64 f1__ //Call
			memset((voidptr)(array.elements+array.capacity),0,u64222((i64170(typeinfo0.size)*(size-array.capacity))));
			#line 65 f1__ //Binary
			array.capacity = size;
		};
}
	#line 69 f1__ //Func
		#line 81 f1__ //Func
		#line 86 f1__ //Func
				#line 116 f1__ //Func
		#line 125 f1__ //Func
		#line 164 f1__ //Func
		#line 13 f2__ //Func
		#line 14 f2__ //Func
		#line 15 f2__ //Func
		#line 16 f2__ //Func
		#line 20 f2__ //Variable
	;
	#line 21 f2__ //Variable
	;
		#line 28 f2__ //Func
	void Print134(str133 string){
		#line 29 f2__ //For
		for(i64 it = (i64)0; it<string.length;it++){
			#line 30 f2__ //Call
			putchar((i32)(*(string.chars+it)));
		};
		#line 32 f2__ //Call
		FileFlush(FileOut());
}
	#line 35 f2__ //Func
	void Println135(str133 string){
		#line 36 f2__ //Call
		Print134(add138(string,str133{1,(i8*)"\n"}));
}
	#line 39 f2__ //Func
	str133 String136(i8* string){
		#line 40 f2__ //Variable
		str133 out={0};
		#line 41 f2__ //Binary
		out.length = strlen(string);
		#line 42 f2__ //Binary
		out.chars = Alloc0252((out.length+1));
		#line 43 f2__ //Call
		strcpy(out.chars,string);
		#line 44 f2__ //Return
		return out;
}
	#line 47 f2__ //Func
	void Error137(str133 string){
		#line 49 f2__ //Call
		Print134(add138(add138(str133{6,(i8*)"\33[31m"},string),str133{1,(i8*)"\n"}));
		#line 50 f2__ //Call
		Print134(str133{5,(i8*)"\33[0m"});
}
	#line 54 f2__ //Func
	str133 add138(str133 a,str133 b){
		#line 56 f2__ //Variable
		str133 v={0};
		#line 57 f2__ //Binary
		v.chars = Alloc0252(((a.length+b.length)+1));
		#line 58 f2__ //Call
		CopyPtr0253(a.chars,v.chars,a.length);
		#line 59 f2__ //Call
		CopyPtr0253(b.chars,(v.chars+a.length),b.length);
		#line 61 f2__ //Binary
		v.length = (a.length+b.length);
		#line 62 f2__ //Binary
		(*(v.chars+v.length)) = 0;
		#line 63 f2__ //Return
		return v;
}
	#line 66 f2__ //Func
	str133 String139(i8* chars,i64 length){
		#line 68 f2__ //Variable
		str133 string={0};
		#line 69 f2__ //Binary
		string.chars = chars;
		#line 70 f2__ //Binary
		string.length = length;
		#line 71 f2__ //Return
		return string;
}
	#line 74 f2__ //Func
	str133 String140(i64 number){
		#line 76 f2__ //If
		if((number==0)){
			#line 77 f2__ //Return
			return str133{1,(i8*)"0"};
		};
		#line 80 f2__ //Variable
		i8 negative=0;
		#line 81 f2__ //If
		if((number<0)){
			#line 82 f2__ //Binary
			negative = 1;
			#line 83 f2__ //Binary
			number = (0-number);
		};
		#line 86 f2__ //Variable
		i64 n=number;
		#line 87 f2__ //Variable
		i64 count=0;
		#line 88 f2__ //For
		while(n){
			#line 89 f2__ //Binary
			n = (n/10);
			#line 90 f2__ //Binary
			count = (count+1);
		};
		#line 93 f2__ //Variable
		Array1259 characters={0};
		#line 94 f2__ //Call
		Init0260(characters,(count+1));
		#line 96 f2__ //Variable
		i64 i={0};
		#line 97 f2__ //For
		while(number){
			#line 98 f2__ //Binary
			OpArray0261(characters,((count-i)-1)) = i8190(((number%10)+48));
			#line 99 f2__ //Binary
			number = (number/10);
			#line 100 f2__ //Binary
			i = (i+1);
		};
		#line 103 f2__ //Binary
		OpArray0261(characters,count) = 0;
		#line 104 f2__ //Variable
		str133 r={0};
		#line 105 f2__ //Binary
		r.length = count;
		#line 106 f2__ //Binary
		r.chars = characters.elements;
		#line 108 f2__ //If
		if(negative){
			#line 109 f2__ //Return
			return add138(str133{1,(i8*)"-"},r);
		};
		#line 111 f2__ //Return
		return r;
}
	#line 114 f2__ //Func
	str133 String141(f32 number){
		#line 116 f2__ //Variable
		i64 top=i64175(number);
		#line 117 f2__ //Variable
		f32 fnumber=number;
		#line 118 f2__ //If
		if((top<0)){
			#line 119 f2__ //Binary
			fnumber = (0.0-fnumber);
		};
		#line 121 f2__ //Variable
		i64 bottom=i64175(((fnumber-f32230(i64175(fnumber)))*1000));
		#line 123 f2__ //Variable
		str133 r=String140(top);
		#line 124 f2__ //If
		if(bottom){
			#line 125 f2__ //Binary
			r = add138(add138(r,str133{1,(i8*)"."}),String140(bottom));
		};
		#line 127 f2__ //Return
		return r;
}
	#line 130 f2__ //Func
	i64 Equal142(str133 l,str133 r){
		#line 132 f2__ //If
		if((l.length!=r.length)){
			#line 134 f2__ //Return
			return 0;
		};
		#line 137 f2__ //For
		for(i64 it = i64168(0); it<l.length;it++){
			#line 139 f2__ //Variable
			i8 ll=(*(l.chars+it));
			#line 140 f2__ //Variable
			i8 rr=(*(r.chars+it));
			#line 141 f2__ //If
			if((i64172(ll)!=i64172(rr))){
				#line 143 f2__ //Return
				return 0;
			};
		};
		#line 146 f2__ //Return
		return 1;
}
	#line 149 f2__ //Func
	i64 Hash143(str133 string){
		#line 151 f2__ //Variable
		i64 hash=5381;
		#line 152 f2__ //For
		for(i64 it = i64168(0); it<string.length;it++){
			#line 154 f2__ //Binary
			hash = (((hash+5)+hash)+i64172((*(string.chars+it))));
		};
		#line 156 f2__ //Return
		return hash;
}
			#line 18 f3__ //Func
	i32 Char146(str133 char){
		#line 19 f3__ //Call
		Assert163((char.length==1),str133{24,(i8*)"Exepcted str of length 1"});
		#line 20 f3__ //Return
		return (*char.chars);
}
	#line 22 f3__ //Func
	Lexer145 Lexer147(str133 file){
		#line 24 f3__ //Variable
		Lexer145 self={0};
		#line 25 f3__ //Binary
		self.file = FileOpen(file.chars,str133{1,(i8*)"r"}.chars);
		#line 26 f3__ //If
		if(self.file){
			#line 28 f3__ //Call
			Get149(self);
			#line 29 f3__ //Call
			Consume154(self);
		}else{
			#line 32 f3__ //Call
			Print134(add138(add138(str133{21,(i8*)"Failed to open file \'"},file),str133{1,(i8*)"\'"}));
		};
		#line 34 f3__ //Return
		return self;
}
	#line 37 f3__ //Func
	i32 Peek148(Lexer145& self){
		#line 39 f3__ //Return
		return self.nextCharacter;
}
	#line 41 f3__ //Func
	i32 Get149(Lexer145& self){
		#line 43 f3__ //Variable
		i32 character=self.nextCharacter;
		#line 44 f3__ //Binary
		self.nextCharacter = FileGetChar(self.file);
		#line 45 f3__ //If
		if((self.nextCharacter==(-1))){
			#line 46 f3__ //Binary
			self.nextCharacter = 0;
		};
		#line 48 f3__ //Return
		return character;
}
	#line 51 f3__ //Variable
	;
	#line 52 f3__ //Variable
	;
	#line 53 f3__ //Variable
	;
	#line 57 f3__ //Func
		#line 58 f3__ //Func
		#line 59 f3__ //Func
		#line 60 f3__ //Func
		#line 63 f3__ //Func
	void Consume154(Lexer145& self){
		#line 65 f3__ //Binary
		self.token = Next155(self);
}
	#line 67 f3__ //Func
	Token144 Next155(Lexer145& self){
		#line 69 f3__ //For
		while(isspace(Peek148(self))){
			#line 71 f3__ //Call
			Get149(self);
		};
		#line 74 f3__ //If
		if((isalpha(Peek148(self))||(Peek148(self)==Char146(str133{1,(i8*)"_"})))){
			#line 76 f3__ //Variable
			DynamicArray1255 data={0};
			#line 77 f3__ //Call
			Init0256(data);
			#line 78 f3__ //For
			while(isalnum(Peek148(self))){
				#line 79 f3__ //Call
				Push0257(data,i8189(Get149(self)));
			};
			#line 81 f3__ //Call
			Push0257(data,0);
			#line 83 f3__ //Variable
			Token144 t={0};
			#line 84 f3__ //Binary
			t.Type = LexerIdentifier;
			#line 85 f3__ //Binary
			t.string.chars = data.elements;
			#line 86 f3__ //Binary
			t.string.length = (data.length-1);
			#line 87 f3__ //Return
			return t;
		};
		#line 90 f3__ //If
		if((((Peek148(self)==Char146(str133{1,(i8*)"."}))||isdigit(Peek148(self)))||i32180((Peek148(self)==Char146(str133{1,(i8*)"-"}))))){
			#line 92 f3__ //Variable
			f64 num=0;
			#line 93 f3__ //Variable
			f64 m=10;
			#line 94 f3__ //If
			if((Peek148(self)==Char146(str133{1,(i8*)"-"}))){
				#line 96 f3__ //Call
				Get149(self);
				#line 97 f3__ //Binary
				m = (-m);
			};
			#line 100 f3__ //For
			while(isdigit(Peek148(self))){
				#line 101 f3__ //Binary
				num = ((num*m)+f64237((Get149(self)-Char146(str133{1,(i8*)"0"}))));
			};
			#line 103 f3__ //If
			if((Peek148(self)==Char146(str133{1,(i8*)"."}))){
				#line 105 f3__ //Call
				Get149(self);
			};
			#line 107 f3__ //Binary
			m = (f64233(1.0)/m);
			#line 108 f3__ //For
			while(isdigit(Peek148(self))){
				#line 109 f3__ //Binary
				num = (num+(f64237((Get149(self)-Char146(str133{1,(i8*)"0"})))*m));
				#line 110 f3__ //Binary
				m = (m/f64233(10));
			};
			#line 112 f3__ //Variable
			Token144 t={0};
			#line 113 f3__ //Binary
			t.Type = LexerNumber;
			#line 114 f3__ //Binary
			t.number = num;
			#line 115 f3__ //Return
			return t;
		};
		#line 117 f3__ //If
		if((Peek148(self)==Char146(str133{1,(i8*)"\'"}))){
			#line 119 f3__ //Call
			Get149(self);
			#line 121 f3__ //Variable
			DynamicArray1255 data={0};
			#line 122 f3__ //Call
			Init0256(data);
			#line 124 f3__ //For
			while((Peek148(self)!=Char146(str133{1,(i8*)"\'"}))){
				#line 125 f3__ //Call
				Push0257(data,i8189(Get149(self)));
			};
			#line 128 f3__ //Call
			Push0257(data,0);
			#line 129 f3__ //Call
			Get149(self);
			#line 131 f3__ //Variable
			Token144 t={0};
			#line 132 f3__ //Binary
			t.Type = LexerString;
			#line 133 f3__ //Binary
			t.string.chars = data.elements;
			#line 134 f3__ //Binary
			t.string.length = (data.length-1);
			#line 135 f3__ //Return
			return t;
		};
		#line 137 f3__ //Variable
		Token144 t={0};
		#line 138 f3__ //Binary
		t.Type = Get149(self);
		#line 139 f3__ //Return
		return t;
}
	#line 11 f4__ //Func
		#line 12 f4__ //Func
		#line 13 f4__ //Func
		#line 14 f4__ //Func
		#line 15 f4__ //Func
		#line 18 f4__ //Func
		#line 23 f4__ //Func
		#line 29 f4__ //Func
	void Assert163(i8 condition,str133 reason){
		#line 30 f4__ //If
		if((!condition)){
			#line 31 f4__ //Call
			Println135(add138(str133{10,(i8*)"Aborting: "},reason));
			#line 32 f4__ //Call
			abort();
		};
}
	#line 36 f4__ //Func
	void Assert164(i8 condition){
		#line 37 f4__ //If
		if((!condition)){
			#line 38 f4__ //Call
			abort();
		}else{
			#line 41 f4__ //Call
			Println135(str133{11,(i8*)"Test passed"});
		};
}
	#line 45 f4__ //Func
	i8* Alloc0252(i64 len){
		#line 47 f4__ //Variable
		u64 size=(u64)(typeinfo0.size*(u32)len);
		#line 48 f4__ //Return
		return (i8*)calloc(1,size);
}
Structure103* Alloc1254(i64 len){
		#line 47 f4__ //Variable
		u64 size=(u64)(typeinfo1.size*(u32)len);
		#line 48 f4__ //Return
		return (Structure103*)calloc(1,size);
}
	#line 51 f4__ //Func
		#line 57 f4__ //Func
	void CopyPtr0253(i8* from,i8* to,i64 len){
		#line 58 f4__ //Variable
		u64 size=(u64)(typeinfo0.size*(u32)len);
		#line 59 f4__ //Call
		memcpy((voidptr)to,(voidptr)from,size);
}
	#line 6 f5__ //Func
	i64 i64168(u8 i){
		#line 6 f5__ //Return
		return (i64)i;
}
	#line 7 f5__ //Func
	i64 i64169(u16 i){
		#line 7 f5__ //Return
		return (i64)i;
}
	#line 8 f5__ //Func
	i64 i64170(u32 i){
		#line 8 f5__ //Return
		return (i64)i;
}
	#line 9 f5__ //Func
	i64 i64171(u64 i){
		#line 9 f5__ //Return
		return (i64)i;
}
	#line 10 f5__ //Func
	i64 i64172(i8 i){
		#line 10 f5__ //Return
		return (i64)i;
}
	#line 11 f5__ //Func
	i64 i64173(i32 i){
		#line 11 f5__ //Return
		return (i64)i;
}
	#line 12 f5__ //Func
	i64 i64174(i64 i){
		#line 12 f5__ //Return
		return (i64)i;
}
	#line 13 f5__ //Func
	i64 i64175(f32 i){
		#line 13 f5__ //Return
		return (i64)i;
}
	#line 14 f5__ //Func
	i64 i64176(f64 i){
		#line 14 f5__ //Return
		return (i64)i;
}
	#line 16 f5__ //Func
	i32 i32177(u8 i){
		#line 16 f5__ //Return
		return (i32)i;
}
	#line 17 f5__ //Func
	i32 i32178(u32 i){
		#line 17 f5__ //Return
		return (i32)i;
}
	#line 18 f5__ //Func
	i32 i32179(u64 i){
		#line 18 f5__ //Return
		return (i32)i;
}
	#line 19 f5__ //Func
	i32 i32180(i8 i){
		#line 19 f5__ //Return
		return (i32)i;
}
	#line 20 f5__ //Func
	i32 i32181(i32 i){
		#line 20 f5__ //Return
		return (i32)i;
}
	#line 21 f5__ //Func
	i32 i32182(i64 i){
		#line 21 f5__ //Return
		return (i32)i;
}
	#line 22 f5__ //Func
	i32 i32183(f32 i){
		#line 22 f5__ //Return
		return (i32)i;
}
	#line 23 f5__ //Func
	i32 i32184(f64 i){
		#line 23 f5__ //Return
		return (i32)i;
}
	#line 25 f5__ //Func
	i8 i8185(u8 i){
		#line 25 f5__ //Return
		return (i8)i;
}
	#line 26 f5__ //Func
	i8 i8186(u32 i){
		#line 26 f5__ //Return
		return (i8)i;
}
	#line 27 f5__ //Func
	i8 i8187(u64 i){
		#line 27 f5__ //Return
		return (i8)i;
}
	#line 28 f5__ //Func
	i8 i8188(i8 i){
		#line 28 f5__ //Return
		return (i8)i;
}
	#line 29 f5__ //Func
	i8 i8189(i32 i){
		#line 29 f5__ //Return
		return (i8)i;
}
	#line 30 f5__ //Func
	i8 i8190(i64 i){
		#line 30 f5__ //Return
		return (i8)i;
}
	#line 31 f5__ //Func
	i8 i8191(f32 i){
		#line 31 f5__ //Return
		return (i8)i;
}
	#line 32 f5__ //Func
	i8 i8192(f64 i){
		#line 32 f5__ //Return
		return (i8)i;
}
	#line 34 f5__ //Func
	u8 u8193(u8 i){
		#line 34 f5__ //Return
		return (u8)i;
}
	#line 35 f5__ //Func
	u8 u8194(u32 i){
		#line 35 f5__ //Return
		return (u8)i;
}
	#line 36 f5__ //Func
	u8 u8195(u64 i){
		#line 36 f5__ //Return
		return (u8)i;
}
	#line 37 f5__ //Func
	u8 u8196(i8 i){
		#line 37 f5__ //Return
		return (u8)i;
}
	#line 38 f5__ //Func
	u8 u8197(i32 i){
		#line 38 f5__ //Return
		return (u8)i;
}
	#line 39 f5__ //Func
	u8 u8198(i64 i){
		#line 39 f5__ //Return
		return (u8)i;
}
	#line 40 f5__ //Func
	u8 u8199(f32 i){
		#line 40 f5__ //Return
		return (u8)i;
}
	#line 41 f5__ //Func
	u8 u8200(f64 i){
		#line 41 f5__ //Return
		return (u8)i;
}
	#line 43 f5__ //Func
	u16 u16201(u16 i){
		#line 43 f5__ //Return
		return (u16)i;
}
	#line 44 f5__ //Func
	u16 u16202(u32 i){
		#line 44 f5__ //Return
		return (u16)i;
}
	#line 45 f5__ //Func
	u16 u16203(u64 i){
		#line 45 f5__ //Return
		return (u16)i;
}
	#line 46 f5__ //Func
	u16 u16204(i8 i){
		#line 46 f5__ //Return
		return (u16)i;
}
	#line 47 f5__ //Func
	u16 u16205(i32 i){
		#line 47 f5__ //Return
		return (u16)i;
}
	#line 48 f5__ //Func
	u16 u16206(i64 i){
		#line 48 f5__ //Return
		return (u16)i;
}
	#line 49 f5__ //Func
	u16 u16207(f32 i){
		#line 49 f5__ //Return
		return (u16)i;
}
	#line 50 f5__ //Func
	u16 u16208(f64 i){
		#line 50 f5__ //Return
		return (u16)i;
}
	#line 52 f5__ //Func
	u32 u32209(u8 i){
		#line 52 f5__ //Return
		return (u32)i;
}
	#line 53 f5__ //Func
	u32 u32210(u32 i){
		#line 53 f5__ //Return
		return (u32)i;
}
	#line 54 f5__ //Func
	u32 u32211(u64 i){
		#line 54 f5__ //Return
		return (u32)i;
}
	#line 55 f5__ //Func
	u32 u32212(i8 i){
		#line 55 f5__ //Return
		return (u32)i;
}
	#line 56 f5__ //Func
	u32 u32213(i32 i){
		#line 56 f5__ //Return
		return (u32)i;
}
	#line 57 f5__ //Func
	u32 u32214(i64 i){
		#line 57 f5__ //Return
		return (u32)i;
}
	#line 58 f5__ //Func
	u32 u32215(f32 i){
		#line 58 f5__ //Return
		return (u32)i;
}
	#line 59 f5__ //Func
	u32 u32216(f64 i){
		#line 59 f5__ //Return
		return (u32)i;
}
	#line 61 f5__ //Func
	u64 u64217(u8 i){
		#line 61 f5__ //Return
		return (u64)i;
}
	#line 62 f5__ //Func
	u64 u64218(u32 i){
		#line 62 f5__ //Return
		return (u64)i;
}
	#line 63 f5__ //Func
	u64 u64219(u64 i){
		#line 63 f5__ //Return
		return (u64)i;
}
	#line 64 f5__ //Func
	u64 u64220(i8 i){
		#line 64 f5__ //Return
		return (u64)i;
}
	#line 65 f5__ //Func
	u64 u64221(i32 i){
		#line 65 f5__ //Return
		return (u64)i;
}
	#line 66 f5__ //Func
	u64 u64222(i64 i){
		#line 66 f5__ //Return
		return (u64)i;
}
	#line 67 f5__ //Func
	u64 u64223(f32 i){
		#line 67 f5__ //Return
		return (u64)i;
}
	#line 68 f5__ //Func
	u64 u64224(f64 i){
		#line 68 f5__ //Return
		return (u64)i;
}
	#line 70 f5__ //Func
	f32 f32225(u8 i){
		#line 70 f5__ //Return
		return (f32)i;
}
	#line 71 f5__ //Func
	f32 f32226(u32 i){
		#line 71 f5__ //Return
		return (f32)i;
}
	#line 72 f5__ //Func
	f32 f32227(u64 i){
		#line 72 f5__ //Return
		return (f32)i;
}
	#line 73 f5__ //Func
	f32 f32228(i8 i){
		#line 73 f5__ //Return
		return (f32)i;
}
	#line 74 f5__ //Func
	f32 f32229(i32 i){
		#line 74 f5__ //Return
		return (f32)i;
}
	#line 75 f5__ //Func
	f32 f32230(i64 i){
		#line 75 f5__ //Return
		return (f32)i;
}
	#line 76 f5__ //Func
	f32 f32231(f32 i){
		#line 76 f5__ //Return
		return (f32)i;
}
	#line 77 f5__ //Func
	f32 f32232(f64 i){
		#line 77 f5__ //Return
		return (f32)i;
}
	#line 79 f5__ //Func
	f64 f64233(u8 i){
		#line 79 f5__ //Return
		return (f64)i;
}
	#line 80 f5__ //Func
	f64 f64234(u32 i){
		#line 80 f5__ //Return
		return (f64)i;
}
	#line 81 f5__ //Func
	f64 f64235(u64 i){
		#line 81 f5__ //Return
		return (f64)i;
}
	#line 82 f5__ //Func
	f64 f64236(i8 i){
		#line 82 f5__ //Return
		return (f64)i;
}
	#line 83 f5__ //Func
	f64 f64237(i32 i){
		#line 83 f5__ //Return
		return (f64)i;
}
	#line 84 f5__ //Func
	f64 f64238(i64 i){
		#line 84 f5__ //Return
		return (f64)i;
}
	#line 85 f5__ //Func
	f64 f64239(f32 i){
		#line 85 f5__ //Return
		return (f64)i;
}
	#line 86 f5__ //Func
	f64 f64240(f64 i){
		#line 86 f5__ //Return
		return (f64)i;
}
		#line 5 f6__ //Func
		#line 6 f6__ //Func
		#line 7 f6__ //Func
		#line 8 f6__ //Func
		#line 9 f6__ //Func
		#line 10 f6__ //Func
		#line 11 f6__ //Func
		#line 12 f6__ //Func
		#line 13 f6__ //Func
		#line 23 f6__ //Func
		#line 26 f6__ //Variable
	;
	#line 27 f6__ //Variable
	;
	#line 28 f6__ //Variable
	;
	#line 29 f6__ //Variable
	;
	#line 30 f6__ //Variable
	;
	#line 31 f6__ //Variable
	;
	#line 32 f6__ //Variable
	;
	#line 33 f6__ //Variable
	;
	#line 34 f6__ //Variable
	;
	#line 35 f6__ //Variable
	;
	#line 36 f6__ //Variable
	;
	#line 37 f6__ //Variable
	;
	#line 38 f6__ //Variable
	;
	#line 39 f6__ //Variable
	;
	#line 40 f6__ //Variable
	;
	#line 41 f6__ //Variable
	;
	#line 42 f6__ //Variable
	;
	#line 43 f6__ //Variable
	;
	#line 44 f6__ //Variable
	;
	#line 45 f6__ //Variable
	;
	#line 46 f6__ //Variable
	;
	#line 47 f6__ //Variable
	;
	#line 48 f6__ //Variable
	;
	#line 49 f6__ //Variable
	;
	#line 50 f6__ //Variable
	;
	#line 51 f6__ //Variable
	;
	#line 52 f6__ //Variable
	;
	#line 53 f6__ //Variable
	;
	#line 54 f6__ //Variable
	;
	#line 55 f6__ //Variable
	;
	#line 56 f6__ //Variable
	;
	#line 57 f6__ //Variable
	;
	#line 58 f6__ //Variable
	;
	#line 59 f6__ //Variable
	;
	#line 60 f6__ //Variable
	;
	#line 61 f6__ //Variable
	;
	#line 62 f6__ //Variable
	;
	#line 63 f6__ //Variable
	;
	#line 64 f6__ //Variable
	;
	#line 65 f6__ //Variable
	;
	#line 66 f6__ //Variable
	;
	#line 67 f6__ //Variable
	;
	#line 68 f6__ //Variable
	;
	#line 69 f6__ //Variable
	;
	#line 70 f6__ //Variable
	;
	#line 71 f6__ //Variable
	;
	#line 72 f6__ //Variable
	;
	#line 73 f6__ //Variable
	;
	#line 74 f6__ //Variable
	;
	#line 75 f6__ //Variable
	;
	#line 76 f6__ //Variable
	;
	#line 77 f6__ //Variable
	;
	#line 79 f6__ //Variable
	;
	#line 80 f6__ //Variable
	;
	#line 81 f6__ //Variable
	;
	#line 82 f6__ //Variable
	;
	#line 83 f6__ //Variable
	;
	#line 84 f6__ //Variable
	;
	#line 85 f6__ //Variable
	;
	#line 86 f6__ //Variable
	;
	#line 87 f6__ //Variable
	;
	#line 88 f6__ //Variable
	;
