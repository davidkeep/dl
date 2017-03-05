#include "build.h"
#define f0__ "/Users/David/Desktop/dl/dl/Main.dl"
#define f1__ "/Users/David/Desktop/dl/dl/dl/Array.dl"
#define f2__ "/Users/David/Desktop/dl/dl/dl/String.dl"
#define f3__ "/Users/David/Desktop/dl/dl/Lexer.dl"
#define f4__ "/Users/David/Desktop/dl/dl/Print.dl"
#define f5__ "/Users/David/Desktop/dl/dl/Semantic.dl"
#define f6__ "/Users/David/Desktop/dl/dl/Intrinsic.dl"
#define f7__ "/Users/David/Desktop/dl/dl/GenerateBasic.dl"
#define f8__ "/Users/David/Desktop/dl/dl/Project.dl"
#define f9__ "/Users/David/Desktop/dl/dl/Interp.dl"
#define f10__ "/Users/David/Desktop/dl/dl/GenerateInterp.dl"
#define f11__ "/Users/David/Desktop/dl/dl/dl/Memory.dl"
#define f12__ "/Users/David/Desktop/dl/dl/dl/Conversion.dl"
#define f13__ "/Users/David/Desktop/dl/dl/dl/c.dl"
#define f14__ "/Users/David/Desktop/dl/dl/Apply.dl"
#define f15__ "/Users/David/Desktop/dl/dl/Expr/Expr.dl"
#define f16__ "/Users/David/Desktop/dl/dl/Expr/Type.dl"
#define f17__ "/Users/David/Desktop/dl/dl/Expr/Block.dl"
#define f18__ "/Users/David/Desktop/dl/dl/Expr/Call.dl"
#define f19__ "/Users/David/Desktop/dl/dl/Expr/Control.dl"
#define f20__ "/Users/David/Desktop/dl/dl/Expr/Function.dl"
#define f21__ "/Users/David/Desktop/dl/dl/Expr/Structure.dl"
#define f22__ "/Users/David/Desktop/dl/dl/Expr/Trait.dl"
#define f23__ "/Users/David/Desktop/dl/dl/Expr/Variable.dl"
#define f24__ "/Users/David/Desktop/dl/dl/Expr/Constant.dl"
#define f25__ "/Users/David/Desktop/dl/dl/Expr/Incomplete.dl"
TypeInfo75 typeinfo0={sizeof(str53)};
TypeInfo75 typeinfo1={sizeof(Type413)};
TypeInfo75 typeinfo2={sizeof(Trait490)};
TypeInfo75 typeinfo3={sizeof(Require493)};
TypeInfo75 typeinfo4={sizeof(TypeOption421)};
TypeInfo75 typeinfo5={sizeof(TypeType427)};
TypeInfo75 typeinfo6={sizeof(TypeGeneric423)};
TypeInfo75 typeinfo7={sizeof(TypeRef419)};
TypeInfo75 typeinfo8={sizeof(TypeAny425)};
TypeInfo75 typeinfo9={sizeof(ForList512)};
TypeInfo75 typeinfo10={sizeof(For449)};
TypeInfo75 typeinfo11={sizeof(Branch452)};
TypeInfo75 typeinfo12={sizeof(If447)};
TypeInfo75 typeinfo13={sizeof(Return454)};
TypeInfo75 typeinfo14={sizeof(NumberConstant507)};
TypeInfo75 typeinfo15={sizeof(StringConstant509)};
TypeInfo75 typeinfo16={sizeof(ExpressionList369)};
TypeInfo75 typeinfo17={sizeof(Expr366)};
TypeInfo75 typeinfo18={sizeof(Identifier495)};
TypeInfo75 typeinfo19={sizeof(Access445)};
TypeInfo75 typeinfo20={sizeof(Assign501)};
TypeInfo75 typeinfo21={sizeof(Error0)};
TypeInfo75 typeinfo22={sizeof(Block434)};
TypeInfo75 typeinfo23={sizeof(i8)};
TypeInfo75 typeinfo24={sizeof(Token77)};
TypeInfo75 typeinfo25={sizeof(Block434)};
TypeInfo75 typeinfo26={sizeof(TypeAs367)};
TypeInfo75 typeinfo27={sizeof(Structure473)};
TypeInfo75 typeinfo28={sizeof(TypeStructure481)};
TypeInfo75 typeinfo29={sizeof(Call442)};
TypeInfo75 typeinfo30={sizeof(Variable498)};
TypeInfo75 typeinfo31={sizeof(TypeIdentifier414)};
TypeInfo75 typeinfo32={sizeof(TypeTrait429)};
TypeInfo75 typeinfo33={sizeof(TypeNumber431)};
TypeInfo75 typeinfo34={sizeof(Function456)};
TypeInfo75 typeinfo35={sizeof(TableNode6221)};
TypeInfo75 typeinfo36={sizeof(Module155)};
TypeInfo75 typeinfo37={sizeof(Module155)};
TypeInfo75 typeinfo38={sizeof(i64)};
TypeInfo75 typeinfo39={sizeof(TableNode322)};
TypeInfo75 typeinfo40={sizeof(TableNode426)};
TypeInfo75 typeinfo41={sizeof(f64)};
TypeInfo75 typeinfo42={sizeof(DebugLocal207)};
TypeInfo75 typeinfo43={sizeof(DebugLocal207)};
TypeInfo75 typeinfo44={sizeof(TableNode530)};
TypeInfo75 typeinfo45={sizeof(i32)};
TypeInfo75 typeinfo46={sizeof(DebugFrame209)};
TypeInfo75 typeinfo47={sizeof(DebugFrame209)};
TypeInfo75 typeinfo48={sizeof(i16)};
TypeInfo75 typeinfo49={sizeof(u64)};
TypeInfo75 typeinfo50={sizeof(u32)};
TypeInfo75 typeinfo51={sizeof(u16)};
TypeInfo75 typeinfo52={sizeof(u8)};
TypeInfo75 typeinfo53={sizeof(f32)};
TypeInfo75 typeinfo54={sizeof(TypeFunctions417)};
TypeInfo75 typeinfo55={sizeof(TypeNumber431)};
TypeInfo75 typeinfo56={sizeof(TableNode16)};
TypeInfo75 typeinfo57={sizeof(TableNode210)};
TypeInfo75 typeinfo58={sizeof(Function456)};
TypeInfo75 typeinfo59={sizeof(FunctionSpec460)};
TypeInfo75 typeinfo60={sizeof(FunctionSpec460)};
TypeInfo75 typeinfo61={sizeof(TypeAnyResolved472)};
TypeInfo75 typeinfo62={sizeof(Structure473)};
TypeInfo75 typeinfo63={sizeof(Variable498)};
TypeInfo75 typeinfo64={sizeof(TypeStructure481)};
DynamicArray2133 errors={0};
i32 kBracketOpen=Char54(str53{1,(i8*)"{"});
i8 true=1;
i32 kBracketClose=Char54(str53{1,(i8*)"}"});
i32 kAt=Char54(str53{1,(i8*)"@"});
i32 kIdentifier=(-20);
i32 kString=(-21);
DynamicArray2234 filesToParse={0};
i32 kKeywordsBegin=(-100);
i32 kFunction=(kKeywordsBegin+2);
i32 kMultiply=Char54(str53{1,(i8*)"*"});
i32 kPlus=Char54(str53{1,(i8*)"+"});
i32 kMinus=Char54(str53{1,(i8*)"-"});
i32 kDivide=Char54(str53{1,(i8*)"/"});
i32 kMod=Char54(str53{1,(i8*)"%"});
i32 kLess=Char54(str53{1,(i8*)"<"});
i32 kGreater=Char54(str53{1,(i8*)">"});
i32 kComma=Char54(str53{1,(i8*)","});
i32 kEqual=Char54(str53{1,(i8*)"="});
i32 kNot=Char54(str53{1,(i8*)"!"});
i32 kBraceOpen=Char54(str53{1,(i8*)"["});
i32 kBraceClose=Char54(str53{1,(i8*)"]"});
i32 kStruct=(kKeywordsBegin+1);
i32 kSemicolon=(-25);
i32 kEndLine=(-26);
i32 kTrait=(kKeywordsBegin+5);
i32 kRequire=(kKeywordsBegin+6);
i32 kOption=Char54(str53{1,(i8*)"?"});
i32 kParenOpen=Char54(str53{1,(i8*)"("});
i32 kParenClose=Char54(str53{1,(i8*)")"});
i32 kRef=(kKeywordsBegin+3);
i32 kDollar=Char54(str53{1,(i8*)"$"});
i32 kFor=(kKeywordsBegin+7);
i32 kDot=Char54(str53{1,(i8*)"."});
i32 kBreak=(kKeywordsBegin+8);
i32 kContinue=(kKeywordsBegin+9);
i32 kIf=(kKeywordsBegin+10);
i32 kElse=(kKeywordsBegin+11);
i32 kReturn=(kKeywordsBegin+12);
i32 kNumber=(-22);
i32 kAnd=Char54(str53{1,(i8*)"&"});
i32 kOr=Char54(str53{1,(i8*)"|"});
Project156 project={0};
i32 kEnd=0;
str53 directory=str53{7,(i8*)"../dl2/"};
i8 false=0;
i32 kCaret=Char54(str53{1,(i8*)"^"});
i32 kKeywordsEnd=(-50);
i8 TypeNumberInteger=0;
i8 TypeNumberUnsigned=1;
i8 TypeNumberFloat=2;
i32 Declared=0;
i32 Visiting=1;
i32 Visited=2;
DynamicArray1114 structures={0};
TypeNumber431* i64Type=New433(TypeNumberInteger,8);
TypeNumber431* i8Type=New433(TypeNumberInteger,1);
TypeNumber431* i16Type=New433(TypeNumberInteger,2);
TypeNumber431* i32Type=New433(TypeNumberInteger,4);
TypeNumber431* u8Type=New433(TypeNumberUnsigned,1);
TypeNumber431* u16Type=New433(TypeNumberUnsigned,2);
TypeNumber431* u32Type=New433(TypeNumberUnsigned,4);
TypeNumber431* u64Type=New433(TypeNumberUnsigned,8);
TypeNumber431* f32Type=New433(TypeNumberFloat,4);
TypeNumber431* f64Type=New433(TypeNumberFloat,8);
Table6220 remapped={0};
DynamicArray54 gSpecializations={0};
i32 RTLD_LAZY=1;
i32 RTLD_NOW=2;
i32 RTLD_LOCAL=4;
i32 RTLD_GLOBAL=8;
i8 AddPtrInstr=3;
i8 AddInstr_i32=1;
i8 AddInstr_i64=2;
i8 MulInstr_i32=4;
i8 MulInstr_i64=5;
i8 SubInstr_i64=6;
i8 DivInstr_i64=7;
i8 AddInstr_f32=120;
i8 MulInstr_f32=121;
i8 SubInstr_f32=122;
i8 DivInstr_f32=123;
i8 ModInstr_i64=9;
i8 AndInstr_i64=10;
i8 OrInstr_i64=11;
i8 BitAndInstr_i64=12;
i8 BitOrInstr_i64=13;
i8 Loadi32=14;
i8 CallInstr=15;
i8 ReturnInstr=16;
i8 LoadInstr=17;
i8 LoadOffsetInstr=18;
i8 LoadAddressInstr=19;
i8 AddOffsetToAddressInstr=20;
i8 LoadAddressFromOffsetInstr=21;
i8 StoreOffsetInstr=22;
i8 StoreInstr=23;
i8 DiscardInstr=24;
i8 LoadConst=25;
i8 CompareInstr_i64=26;
i8 TestGreaterInstr=27;
i8 TestGreaterEqInstr=28;
i8 TestLessEqInstr=29;
i8 TestLessInstr=30;
i8 TestEqInstr=31;
i8 TestNotEqInstr=32;
i8 JumpInstr=33;
i8 CallExternVoid=34;
i8 CallExternPtr=35;
i8 CallExtern32=36;
i8 CallExtern64=37;
i8 CallExtern16=52;
i8 CallExtern8=53;
i8 ParamExtern_8=38;
i8 ParamExtern_16=39;
i8 ParamExtern_32=40;
i8 ParamExtern_64=41;
i8 ParamExtern_Ptr=42;
i8 ParamExtern_f32=100;
i8 ParamExtern_f64=101;
i8 CallExtern_16=102;
i8 CallExtern_8=103;
i8 CallExtern_f32=104;
i8 CallExtern_f64=105;
i8 CastInstr_i64_f64=43;
i8 CastInstr_i64_f32=44;
i8 CastInstr_f32_i64=45;
i8 CastInstr_f64_i64=46;
i8 CastInstr_f32_f64=150;
i8 CastInstr_f64_f32=151;
i8 WidenInstr_8_64=47;
i8 WidenInstr_16_64=48;
i8 WidenInstr_32_64=59;
i8 ConvertInstr_64_32=50;
i8 ConvertInstr=51;
i8 TrapInstr=0;
i8 TrapAbort=0;
i32 registerCount=256;
DynamicArray25248 labelAddresses={0};
i32 ContextLoad=2;
i32 ContextStore=1;
i32 ContextDiscard=3;
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
i32 gNextFnIndex={0};
		#line 20 f0__ //Expr
	;
	#line 22 f0__ //Expr
	Block434* ParseBasicBlock1(Lexer78& lexer){
		#line 23 f0__ //Expr
		Expect21(lexer,kBracketOpen);
		#line 24 f0__ //Expr
		Block434* block=Block436();
		#line 25 f0__ //Expr
		while(true){
			#line 27 f0__ //Expr
			Expr366* expr={0};
			#line 28 f0__ //Expr
			if((!expr)){
				#line 29 f0__ //Expr
				expr = (&(*ParseVariable12(lexer)).super);
			};
			#line 31 f0__ //Expr
			if((!expr)){
				#line 32 f0__ //Expr
				expr = ParseExpression19(lexer);
			};
			#line 34 f0__ //Expr
			if((!expr)){
				#line 35 f0__ //Expr
				expr = ParseControl13(lexer);
			};
			#line 37 f0__ //Expr
			if((!expr)){
				#line 38 f0__ //Expr
				if(equal80(At90(lexer,0),kBracketOpen)){
					#line 39 f0__ //Expr
					expr = (&(*ParseBasicBlock1(lexer)).super);
				};
			};
			#line 42 f0__ //Expr
			if((!expr)){
				#line 44 f0__ //Expr
				Expect21(lexer,kBracketClose);
				#line 45 f0__ //Expr
				return block;
			};
			#line 47 f0__ //Expr
			Add441((*block),expr);
		};
		#line 49 f0__ //Expr
		return block;
}
	#line 52 f0__ //Expr
	void ParseDirective2(Lexer78& lexer,Block434& block){
		#line 53 f0__ //Expr
		while(equal80(At90(lexer,0),kAt)){
			#line 55 f0__ //Expr
			Eat92(lexer,1);
			#line 57 f0__ //Expr
			if(equal80(At90(lexer,0),kIdentifier)){
				#line 59 f0__ //Expr
				if(equal68(At90(lexer,0).value,str53{6,(i8*)"extern"})){
					#line 61 f0__ //Expr
					Eat92(lexer,1);
					#line 62 f0__ //Expr
					Expect21(lexer,kBracketOpen);
					#line 64 f0__ //Expr
					while(true){
						#line 66 f0__ //Expr
						Expr366* expr={0};
						#line 67 f0__ //Expr
						expr = (&(*ParseFunction3(lexer)).super);
						#line 68 f0__ //Expr
						if(expr){
							#line 69 f0__ //Expr
							Add441(block,expr);
						}else{
							#line 73 f0__ //Expr
							Expect21(lexer,kBracketClose);
							#line 74 f0__ //Expr
							return ;
						};
					};
				}else{
					#line 78 f0__ //Expr
					if(equal68(At90(lexer,0).value,str53{6,(i8*)"import"})){
						#line 80 f0__ //Expr
						Eat92(lexer,1);
						#line 81 f0__ //Expr
						Expect21(lexer,kBracketOpen);
						#line 83 f0__ //Expr
						while(equal80(At90(lexer,0),kString)){
							#line 85 f0__ //Expr
							Push035(filesToParse,At90(lexer,0).value);
							#line 86 f0__ //Expr
							Eat92(lexer,1);
							#line 87 f0__ //Expr
							ExpectEndStatement22(lexer);
						};
						#line 89 f0__ //Expr
						Expect21(lexer,kBracketClose);
					}else{
						#line 92 f0__ //Expr
						Assert260(0,add64(str53{21,(i8*)"Unhandled directive  "},At90(lexer,0).value));
					};
				};
			}else{
				#line 96 f0__ //Expr
				Error20(str53{19,(i8*)"Expected identifier"},At90(lexer,0).at);
			};
		};
}
	#line 101 f0__ //Expr
	Function456* ParseFunction3(Lexer78& lexer){
		#line 103 f0__ //Expr
		if((equal80(At90(lexer,1),kFunction)&&(((((((equal80(At90(lexer,0),kIdentifier)||equal80(At90(lexer,0),kMultiply))||equal80(At90(lexer,0),kPlus))||equal80(At90(lexer,0),kMinus))||equal80(At90(lexer,0),kDivide))||equal80(At90(lexer,0),kMod))||equal80(At90(lexer,0),kLess))||equal80(At90(lexer,0),kGreater)))){
			#line 113 f0__ //Expr
			Function456* self=Function459();
			#line 114 f0__ //Expr
			(*self).super.at = At90(lexer,0).at;
			#line 115 f0__ //Expr
			if(equal80(At90(lexer,0),kIdentifier)){
				#line 116 f0__ //Expr
				(*self).ident = At90(lexer,0).value;
			}else{
				#line 119 f0__ //Expr
				(*self).ident = TokenString79(At90(lexer,0).Type);
			};
			#line 121 f0__ //Expr
			Eat92(lexer,2);
			#line 123 f0__ //Expr
			i8 done={0};
			#line 124 f0__ //Expr
			while((!done)){
				#line 126 f0__ //Expr
				Expr366* expr=(&(*ParseParameter11(lexer)).super);
				#line 127 f0__ //Expr
				if(expr){
					#line 128 f0__ //Expr
					Add371((*self).params,expr);
					#line 129 f0__ //Expr
					if(equal80(At90(lexer,0),kComma)){
						#line 131 f0__ //Expr
						Eat92(lexer,1);
					}else{
						#line 134 f0__ //Expr
						done = true;
					};
				}else{
					#line 138 f0__ //Expr
					done = true;
				};
			};
			#line 142 f0__ //Expr
			if((equal80(At90(lexer,0),kEqual)&&equal80(At90(lexer,1),kGreater))){
				#line 143 f0__ //Expr
				Eat92(lexer,2);
				#line 144 f0__ //Expr
				(*self).result = ParseType9(lexer);
			};
			#line 146 f0__ //Expr
			if(notEqual81(At90(lexer,0),kBracketOpen)){
				#line 147 f0__ //Expr
				ExpectEndStatement22(lexer);
				#line 148 f0__ //Expr
				return self;
			};
			#line 150 f0__ //Expr
			(*self).block = ParseBasicBlock1(lexer);
			#line 151 f0__ //Expr
			return self;
		};
		#line 153 f0__ //Expr
		if((equal80(At90(lexer,2),kFunction)&&(((equal80(At90(lexer,0),kEqual)&&equal80(At90(lexer,1),kEqual))||(equal80(At90(lexer,0),kNot)&&equal80(At90(lexer,1),kEqual)))||(equal80(At90(lexer,0),kBraceOpen)&&equal80(At90(lexer,1),kBraceClose))))){
			#line 160 f0__ //Expr
			Function456* self=Function459();
			#line 161 f0__ //Expr
			(*self).super.at = At90(lexer,0).at;
			#line 162 f0__ //Expr
			if(equal80(At90(lexer,0),kEqual)){
				#line 163 f0__ //Expr
				(*self).ident = str53{2,(i8*)"=="};
			}else{
				#line 165 f0__ //Expr
				if(equal80(At90(lexer,0),kNot)){
					#line 166 f0__ //Expr
					(*self).ident = str53{2,(i8*)"!="};
				}else{
					#line 168 f0__ //Expr
					if(equal80(At90(lexer,0),kBraceOpen)){
						#line 169 f0__ //Expr
						(*self).ident = str53{2,(i8*)"[]"};
					}else{
						#line 172 f0__ //Expr
						Assert260(0,str53{17,(i8*)"no function found"});
					};
				};
			};
			#line 174 f0__ //Expr
			Eat92(lexer,3);
			#line 176 f0__ //Expr
			i8 done={0};
			#line 177 f0__ //Expr
			while((!done)){
				#line 179 f0__ //Expr
				Expr366* expr=(&(*ParseParameter11(lexer)).super);
				#line 180 f0__ //Expr
				if(expr){
					#line 181 f0__ //Expr
					Add371((*self).params,expr);
					#line 182 f0__ //Expr
					if(equal80(At90(lexer,0),kComma)){
						#line 184 f0__ //Expr
						Eat92(lexer,1);
					}else{
						#line 187 f0__ //Expr
						done = true;
					};
				}else{
					#line 191 f0__ //Expr
					done = true;
				};
			};
			#line 195 f0__ //Expr
			if((equal80(At90(lexer,0),kEqual)&&equal80(At90(lexer,1),kGreater))){
				#line 196 f0__ //Expr
				Eat92(lexer,2);
				#line 197 f0__ //Expr
				(*self).result = ParseType9(lexer);
			};
			#line 199 f0__ //Expr
			if(notEqual81(At90(lexer,0),kBracketOpen)){
				#line 200 f0__ //Expr
				ExpectEndStatement22(lexer);
				#line 201 f0__ //Expr
				return self;
			};
			#line 203 f0__ //Expr
			(*self).block = ParseBasicBlock1(lexer);
			#line 204 f0__ //Expr
			return self;
		};
		#line 206 f0__ //Expr
		return (Function456*)0;
}
	#line 209 f0__ //Expr
	Structure473* ParseStructure4(Lexer78& lexer){
		#line 211 f0__ //Expr
		if((equal80(At90(lexer,1),kStruct)&&equal80(At90(lexer,0),kIdentifier))){
			#line 213 f0__ //Expr
			Structure473* structure=Structure475();
			#line 214 f0__ //Expr
			(*structure).ident = At90(lexer,0).value;
			#line 215 f0__ //Expr
			Eat92(lexer,2);
			#line 217 f0__ //Expr
			ParseConstraints5(lexer,(*structure).constraints);
			#line 219 f0__ //Expr
			if((equal80(At90(lexer,0),kSemicolon)||equal80(At90(lexer,0),kEndLine))){
				#line 220 f0__ //Expr
				Eat92(lexer,1);
				#line 221 f0__ //Expr
				(*structure).incomplete = true;
				#line 222 f0__ //Expr
				return structure;
			};
			#line 225 f0__ //Expr
			Expect21(lexer,kBracketOpen);
			#line 227 f0__ //Expr
			while(notEqual81(At90(lexer,0),kBracketClose)){
				#line 228 f0__ //Expr
				Variable498* field=ParseField10(lexer);
				#line 229 f0__ //Expr
				Add476((*structure),field);
			};
			#line 232 f0__ //Expr
			Expect21(lexer,kBracketClose);
			#line 234 f0__ //Expr
			return structure;
		};
		#line 237 f0__ //Expr
		return (Structure473*)0;
}
	#line 241 f0__ //Expr
	void ParseConstraints5(Lexer78& lexer,DynamicArray43& constraints){
		#line 244 f0__ //Expr
		while(notEqual81(At90(lexer,0),kBracketOpen)){
			#line 245 f0__ //Expr
			Type413* typ=ParseType9(lexer);
			#line 246 f0__ //Expr
			if((!typ)){
				#line 247 f0__ //Expr
				Error20(str53{35,(i8*)"Expected { or type following struct"},At90(lexer,0).at);
				#line 248 f0__ //Expr
				return ;
			};
			#line 250 f0__ //Expr
			Push137(constraints,typ);
			#line 251 f0__ //Expr
			if(notEqual81(At90(lexer,0),kBracketOpen)){
				#line 253 f0__ //Expr
				Expect21(lexer,kComma);
			};
		};
}
	#line 258 f0__ //Expr
	Trait490* ParseTrait6(Lexer78& lexer){
		#line 260 f0__ //Expr
		if((equal80(At90(lexer,1),kTrait)&&equal80(At90(lexer,0),kIdentifier))){
			#line 262 f0__ //Expr
			Trait490* elTrait=New039();
			#line 263 f0__ //Expr
			(*elTrait).ident = At90(lexer,0).value;
			#line 264 f0__ //Expr
			Eat92(lexer,2);
			#line 266 f0__ //Expr
			ParseConstraints5(lexer,(*elTrait).constraints);
			#line 267 f0__ //Expr
			Expect21(lexer,kBracketOpen);
			#line 269 f0__ //Expr
			i8 done={0};
			#line 270 f0__ //Expr
			while((!done)){
				#line 272 f0__ //Expr
				Function456* function=ParseFunction3(lexer);
				#line 273 f0__ //Expr
				if(function){
					#line 274 f0__ //Expr
					AddFunction492((*elTrait),function);
					#line 275 f0__ //Expr
					(*function).traitFunction = true;
					#line 276 f0__ //Expr
					Assert261(((i64)(*function).block==0));
				}else{
					#line 279 f0__ //Expr
					done = true;
				};
			};
			#line 283 f0__ //Expr
			Expect21(lexer,kBracketClose);
			#line 285 f0__ //Expr
			return elTrait;
		};
		#line 288 f0__ //Expr
		return (Trait490*)0;
}
	#line 291 f0__ //Expr
	Require493* ParseRequire7(Lexer78& lexer){
		#line 293 f0__ //Expr
		if((equal80(At90(lexer,1),kRequire)&&equal80(At90(lexer,0),kIdentifier))){
			#line 295 f0__ //Expr
			Require493* req=New142();
			#line 296 f0__ //Expr
			(*req).typeName = At90(lexer,0).value;
			#line 297 f0__ //Expr
			Eat92(lexer,2);
			#line 298 f0__ //Expr
			if(notEqual81(At90(lexer,0),kIdentifier)){
				#line 300 f0__ //Expr
				Error20(str53{39,(i8*)"Expected identifier after ident require"},At90(lexer,0).at);
			}else{
				#line 303 f0__ //Expr
				(*req).traitName = At90(lexer,0).value;
				#line 304 f0__ //Expr
				Eat92(lexer,1);
			};
			#line 306 f0__ //Expr
			ExpectEndStatement22(lexer);
			#line 307 f0__ //Expr
			return req;
		};
		#line 309 f0__ //Expr
		return (Require493*)0;
}
	#line 312 f0__ //Expr
	Type413* ParseOptions8(Lexer78& lexer,Type413* typ){
		#line 313 f0__ //Expr
		Type413* t=typ;
		#line 314 f0__ //Expr
		while(equal80(At90(lexer,0),kOption)){
			#line 315 f0__ //Expr
			Eat92(lexer,1);
			#line 316 f0__ //Expr
			TypeOption421* opt=New245();
			#line 317 f0__ //Expr
			(*opt).reference = t;
			#line 318 f0__ //Expr
			t = (&(*opt).super);
		};
		#line 320 f0__ //Expr
		return t;
}
	#line 322 f0__ //Expr
	Type413* ParseType9(Lexer78& lexer){
		#line 324 f0__ //Expr
		if(equal80(At90(lexer,0),kIdentifier)){
			#line 325 f0__ //Expr
			if(equal68(At90(lexer,0).value,str53{6,(i8*)"typeof"})){
				#line 326 f0__ //Expr
				TypeType427* typ=New348();
				#line 327 f0__ //Expr
				Eat92(lexer,1);
				#line 328 f0__ //Expr
				(*typ).reference = ParseType9(lexer);
				#line 329 f0__ //Expr
				return ParseOptions8(lexer,(&(*typ).super));
			}else{
				#line 332 f0__ //Expr
				TypeIdentifier414* typ=TypeIdentifier415();
				#line 333 f0__ //Expr
				(*typ).ident = At90(lexer,0).value;
				#line 334 f0__ //Expr
				Assert051((*typ).ident.chars,str53{23,(i8*)"failed in parse declare"});
				#line 335 f0__ //Expr
				Eat92(lexer,1);
				#line 337 f0__ //Expr
				if(equal80(At90(lexer,0),kParenOpen)){
					#line 338 f0__ //Expr
					TypeGeneric423* generic=New452();
					#line 339 f0__ //Expr
					(*generic).ident = typ;
					#line 340 f0__ //Expr
					Eat92(lexer,1);
					#line 342 f0__ //Expr
					while(true){
						#line 344 f0__ //Expr
						Push137((*generic).constraints,ParseType9(lexer));
						#line 345 f0__ //Expr
						if(equal80(At90(lexer,0),kComma)){
							#line 346 f0__ //Expr
							Eat92(lexer,1);
						}else{
							#line 350 f0__ //Expr
							Expect21(lexer,kParenClose);
							#line 351 f0__ //Expr
							return ParseOptions8(lexer,(&(*generic).super));
						};
					};
				};
				#line 355 f0__ //Expr
				return ParseOptions8(lexer,(&(*typ).super));
			};
		};
		#line 358 f0__ //Expr
		if(equal80(At90(lexer,0),kRef)){
			#line 359 f0__ //Expr
			TypeRef419* typ=New555();
			#line 360 f0__ //Expr
			Eat92(lexer,1);
			#line 361 f0__ //Expr
			Type413* r=ParseOptions8(lexer,(&(*typ).super));
			#line 362 f0__ //Expr
			(*typ).reference = ParseType9(lexer);
			#line 363 f0__ //Expr
			return r;
		};
		#line 365 f0__ //Expr
		if(equal80(At90(lexer,0),kDollar)){
			#line 366 f0__ //Expr
			Eat92(lexer,1);
			#line 367 f0__ //Expr
			if(notEqual81(At90(lexer,0),kIdentifier)){
				#line 368 f0__ //Expr
				Error20(str53{27,(i8*)"Expected identifier after $"},At90(lexer,0).at);
			};
			#line 370 f0__ //Expr
			TypeAny425* typ=New658();
			#line 371 f0__ //Expr
			(*typ).ident = At90(lexer,0).value;
			#line 372 f0__ //Expr
			Eat92(lexer,1);
			#line 374 f0__ //Expr
			return ParseOptions8(lexer,(&(*typ).super));
		};
		#line 377 f0__ //Expr
		return (Type413*)0;
}
	#line 380 f0__ //Expr
	Variable498* ParseField10(Lexer78& lexer){
		#line 382 f0__ //Expr
		Variable498* field=Variable500();
		#line 383 f0__ //Expr
		(*field).super.at = At90(lexer,0).at;
		#line 384 f0__ //Expr
		(*field).ident = At90(lexer,0).value;
		#line 385 f0__ //Expr
		Eat92(lexer,1);
		#line 387 f0__ //Expr
		(*field).super.typ = ParseType9(lexer);
		#line 388 f0__ //Expr
		if((!(*field).super.typ)){
			#line 389 f0__ //Expr
			Error20(str53{22,(i8*)"Expected type of field"},At90(lexer,0).at);
		};
		#line 391 f0__ //Expr
		ExpectEndStatement22(lexer);
		#line 392 f0__ //Expr
		return field;
}
	#line 395 f0__ //Expr
	Variable498* ParseParameter11(Lexer78& lexer){
		#line 397 f0__ //Expr
		if((equal80(At90(lexer,0),kIdentifier)&&((equal80(At90(lexer,1),kIdentifier)||equal80(At90(lexer,1),kRef))||equal80(At90(lexer,1),kDollar)))){
			#line 402 f0__ //Expr
			Variable498* variable=Variable500();
			#line 403 f0__ //Expr
			(*variable).super.at = At90(lexer,0).at;
			#line 404 f0__ //Expr
			if((!equal68(At90(lexer,0).value,str53{6,(i8*)"typeof"}))){
				#line 406 f0__ //Expr
				(*variable).ident = At90(lexer,0).value;
				#line 407 f0__ //Expr
				Eat92(lexer,1);
			};
			#line 409 f0__ //Expr
			(*variable).super.typ = ParseType9(lexer);
			#line 410 f0__ //Expr
			return variable;
		};
		#line 413 f0__ //Expr
		return (Variable498*)0;
}
	#line 416 f0__ //Expr
	Variable498* ParseVariable12(Lexer78& lexer){
		#line 418 f0__ //Expr
		if((equal80(At90(lexer,0),kIdentifier)&&((equal80(At90(lexer,1),kIdentifier)||equal80(At90(lexer,1),kRef))||equal80(At90(lexer,1),kDollar)))){
			#line 424 f0__ //Expr
			Variable498* variable=Variable500();
			#line 425 f0__ //Expr
			(*variable).super.at = At90(lexer,0).at;
			#line 426 f0__ //Expr
			if((!equal68(At90(lexer,0).value,str53{6,(i8*)"typeof"}))){
				#line 428 f0__ //Expr
				(*variable).ident = At90(lexer,0).value;
				#line 429 f0__ //Expr
				Eat92(lexer,1);
			};
			#line 432 f0__ //Expr
			(*variable).super.typ = ParseType9(lexer);
			#line 433 f0__ //Expr
			if(equal80(At90(lexer,0),kEqual)){
				#line 434 f0__ //Expr
				Eat92(lexer,1);
				#line 435 f0__ //Expr
				(*variable).assign = ParseExpression18(lexer,0);
				#line 436 f0__ //Expr
				if((!(*variable).assign)){
					#line 437 f0__ //Expr
					Error20(str53{31,(i8*)"Expected expression following ="},At90(lexer,0).at);
				};
			};
			#line 440 f0__ //Expr
			ExpectEndStatement22(lexer);
			#line 441 f0__ //Expr
			return variable;
		};
		#line 444 f0__ //Expr
		return (Variable498*)0;
}
	#line 446 f0__ //Expr
	Expr366* ParseControl13(Lexer78& lexer){
		#line 448 f0__ //Expr
		if(equal80(At90(lexer,0),kFor)){
			#line 449 f0__ //Expr
			Eat92(lexer,1);
			#line 451 f0__ //Expr
			Expr366* expr=ParseExpression18(lexer,0);
			#line 452 f0__ //Expr
			if((!expr)){
				#line 454 f0__ //Expr
				Error20(str53{33,(i8*)"Expected expression following for"},At90(lexer,0).at);
				#line 455 f0__ //Expr
				return (Expr366*)0;
			};
			#line 457 f0__ //Expr
			if(Is061((*expr))){
				#line 459 f0__ //Expr
				ForList512* self=New763();
				#line 460 f0__ //Expr
				(*self).super.at = At90(lexer,0).at;
				#line 461 f0__ //Expr
				(*self).list = As066((*expr));
				#line 462 f0__ //Expr
				(*self).block = ParseBasicBlock1(lexer);
				#line 463 f0__ //Expr
				return (&(*self).super);
			};
			#line 465 f0__ //Expr
			For449* self=New867();
			#line 466 f0__ //Expr
			(*self).super.at = At90(lexer,0).at;
			#line 467 f0__ //Expr
			(*self).from = expr;
			#line 469 f0__ //Expr
			if((equal80(At90(lexer,0),kDot)&&equal80(At90(lexer,1),kDot))){
				#line 470 f0__ //Expr
				Eat92(lexer,2);
				#line 471 f0__ //Expr
				(*self).to = ParseExpression18(lexer,0);
				#line 472 f0__ //Expr
				if((!(*self).to)){
					#line 474 f0__ //Expr
					Error20(str53{42,(i8*)"Expected expression following for expr .. "},At90(lexer,0).at);
					#line 475 f0__ //Expr
					return (Expr366*)0;
				};
			};
			#line 479 f0__ //Expr
			(*self).block = ParseBasicBlock1(lexer);
			#line 480 f0__ //Expr
			return (&(*self).super);
		};
		#line 482 f0__ //Expr
		if((equal80(At90(lexer,0),kBreak)||equal80(At90(lexer,0),kContinue))){
			#line 483 f0__ //Expr
			Branch452* self=New970();
			#line 484 f0__ //Expr
			(*self).token = At90(lexer,0).Type;
			#line 485 f0__ //Expr
			Eat92(lexer,1);
			#line 486 f0__ //Expr
			return (&(*self).super);
		};
		#line 488 f0__ //Expr
		if(equal80(At90(lexer,0),kIf)){
			#line 489 f0__ //Expr
			If447* self=New1073();
			#line 490 f0__ //Expr
			(*self).super.at = At90(lexer,0).at;
			#line 491 f0__ //Expr
			Eat92(lexer,1);
			#line 493 f0__ //Expr
			(*self).condition = ParseExpression18(lexer,0);
			#line 494 f0__ //Expr
			(*self).trueBranch = ParseBasicBlock1(lexer);
			#line 495 f0__ //Expr
			If447* current=self;
			#line 497 f0__ //Expr
			while(equal80(At90(lexer,0),kElse)){
				#line 498 f0__ //Expr
				Eat92(lexer,1);
				#line 500 f0__ //Expr
				if(equal80(At90(lexer,0),kBracketOpen)){
					#line 501 f0__ //Expr
					(*current).falseBranch = ParseBasicBlock1(lexer);
				}else{
					#line 504 f0__ //Expr
					(*current).falseCondition = New1073();
					#line 505 f0__ //Expr
					(*(*current).falseCondition).condition = ParseExpression18(lexer,0);
					#line 506 f0__ //Expr
					(*(*current).falseCondition).trueBranch = ParseBasicBlock1(lexer);
					#line 507 f0__ //Expr
					current = (*current).falseCondition;
				};
			};
			#line 510 f0__ //Expr
			return (&(*self).super);
		};
		#line 512 f0__ //Expr
		if(equal80(At90(lexer,0),kReturn)){
			#line 513 f0__ //Expr
			Return454* self=New1176();
			#line 514 f0__ //Expr
			(*self).super.at = At90(lexer,0).at;
			#line 515 f0__ //Expr
			Eat92(lexer,1);
			#line 516 f0__ //Expr
			(*self).expr = ParseExpression19(lexer);
			#line 517 f0__ //Expr
			return (&(*self).super);
		};
		#line 520 f0__ //Expr
		return (Expr366*)0;
}
	#line 522 f0__ //Expr
	Expr366* ParseOperand14(Lexer78& lexer,i32 precedence){
		#line 524 f0__ //Expr
		if(equal80(At90(lexer,0),kIdentifier)){
			#line 525 f0__ //Expr
			Identifier495* operand=Identifier496();
			#line 526 f0__ //Expr
			(*operand).super.at = At90(lexer,0).at;
			#line 527 f0__ //Expr
			(*operand).ident = At90(lexer,0).value;
			#line 528 f0__ //Expr
			Eat92(lexer,1);
			#line 529 f0__ //Expr
			return (&(*operand).super);
		};
		#line 532 f0__ //Expr
		if(equal80(At90(lexer,0),kNumber)){
			#line 533 f0__ //Expr
			NumberConstant507* operand=New1279();
			#line 534 f0__ //Expr
			(*operand).super.at = At90(lexer,0).at;
			#line 535 f0__ //Expr
			(*operand).value = At90(lexer,0).value;
			#line 536 f0__ //Expr
			Eat92(lexer,1);
			#line 537 f0__ //Expr
			return (&(*operand).super);
		};
		#line 539 f0__ //Expr
		if(equal80(At90(lexer,0),kString)){
			#line 540 f0__ //Expr
			StringConstant509* operand=New1382();
			#line 541 f0__ //Expr
			(*operand).super.at = At90(lexer,0).at;
			#line 542 f0__ //Expr
			(*operand).value = At90(lexer,0).value;
			#line 543 f0__ //Expr
			Eat92(lexer,1);
			#line 544 f0__ //Expr
			return (&(*operand).super);
		};
		#line 546 f0__ //Expr
		if(equal80(At90(lexer,0),kAnd)){
			#line 547 f0__ //Expr
			Call442* op=Call443();
			#line 548 f0__ //Expr
			Identifier495* identifier=Identifier496();
			#line 549 f0__ //Expr
			(*op).super.at = At90(lexer,0).at;
			#line 550 f0__ //Expr
			(*identifier).ident = str53{1,(i8*)"&"};
			#line 551 f0__ //Expr
			(*op).operand = (&(*identifier).super);
			#line 552 f0__ //Expr
			Eat92(lexer,1);
			#line 553 f0__ //Expr
			Expr366* expr=ParseExpression18(lexer,0);
			#line 554 f0__ //Expr
			if((!expr)){
				#line 555 f0__ //Expr
				Error20(str53{31,(i8*)"Expected expression following &"},At90(lexer,0).at);
			}else{
				#line 558 f0__ //Expr
				Add371((*op).params,expr);
			};
			#line 560 f0__ //Expr
			return (&(*op).super);
		};
		#line 562 f0__ //Expr
		if(equal80(At90(lexer,0),kNot)){
			#line 563 f0__ //Expr
			Call442* op=Call443();
			#line 564 f0__ //Expr
			Identifier495* identifier=Identifier496();
			#line 565 f0__ //Expr
			(*op).super.at = At90(lexer,0).at;
			#line 566 f0__ //Expr
			(*identifier).ident = str53{1,(i8*)"!"};
			#line 567 f0__ //Expr
			(*op).operand = (&(*identifier).super);
			#line 568 f0__ //Expr
			Eat92(lexer,1);
			#line 569 f0__ //Expr
			Expr366* expr=ParseExpression18(lexer,0);
			#line 570 f0__ //Expr
			if((!expr)){
				#line 571 f0__ //Expr
				Error20(str53{31,(i8*)"Expected expression following !"},At90(lexer,0).at);
			}else{
				#line 574 f0__ //Expr
				Add371((*op).params,expr);
			};
			#line 576 f0__ //Expr
			return (&(*op).super);
		};
		#line 578 f0__ //Expr
		if(equal80(At90(lexer,0),kParenOpen)){
			#line 579 f0__ //Expr
			Eat92(lexer,1);
			#line 580 f0__ //Expr
			Expr366* expr=ParseExpression18(lexer,0);
			#line 581 f0__ //Expr
			if((!expr)){
				#line 582 f0__ //Expr
				Error20(str53{31,(i8*)"Expected expression following ("},At90(lexer,0).at);
			};
			#line 584 f0__ //Expr
			Expect21(lexer,kParenClose);
			#line 585 f0__ //Expr
			return expr;
		};
		#line 596 f0__ //Expr
		if(equal80(At90(lexer,0),kBraceOpen)){
			#line 597 f0__ //Expr
			ExpressionList369* operand=New1485();
			#line 598 f0__ //Expr
			(*operand).super.at = At90(lexer,0).at;
			#line 599 f0__ //Expr
			Eat92(lexer,1);
			#line 601 f0__ //Expr
			while(true){
				#line 602 f0__ //Expr
				Expr366* expr=ParseExpression18(lexer,0);
				#line 603 f0__ //Expr
				if(expr){
					#line 604 f0__ //Expr
					Push288((*operand).list,expr);
					#line 605 f0__ //Expr
					if(equal80(At90(lexer,0),kComma)){
						#line 606 f0__ //Expr
						Eat92(lexer,1);
					}else{
						#line 609 f0__ //Expr
						Expect21(lexer,kBraceClose);
						#line 610 f0__ //Expr
						return (&(*operand).super);
					};
				}else{
					#line 614 f0__ //Expr
					Expect21(lexer,kBraceClose);
					#line 615 f0__ //Expr
					return (&(*operand).super);
				};
			};
			#line 620 f0__ //Expr
			return (&(*operand).super);
		};
		#line 622 f0__ //Expr
		Type413* typ=ParseType9(lexer);
		#line 623 f0__ //Expr
		if(typ){
			#line 625 f0__ //Expr
			Identifier495* ident=New1590();
			#line 626 f0__ //Expr
			TypeType427* as=New348();
			#line 627 f0__ //Expr
			(*as).reference = typ;
			#line 628 f0__ //Expr
			(*ident).super.typ = (&(*as).super);
			#line 629 f0__ //Expr
			return (&(*ident).super);
		};
		#line 633 f0__ //Expr
		return (Expr366*)0;
}
	#line 636 f0__ //Expr
	i8 IsOperator15(Token77 token){
		#line 637 f0__ //Expr
		return ((((equal80(token,kPlus)||equal80(token,kMinus))||equal80(token,kMultiply))||equal80(token,kDivide))||equal80(token,kMod));
}
	#line 640 f0__ //Expr
	i32 Precedence16(Token77 token){
		#line 653 f0__ //Expr
		if((equal80(token,kPlus)||equal80(token,kMinus))){
			#line 655 f0__ //Expr
			return 4;
		};
		#line 658 f0__ //Expr
		if(((equal80(token,kMultiply)||equal80(token,kDivide))||equal80(token,kMod))){
			#line 660 f0__ //Expr
			return 5;
		};
		#line 663 f0__ //Expr
		Assert260(0,add64(str53{29,(i8*)"Uknown precedence for token, "},TokenString79(token.Type)));
		#line 664 f0__ //Expr
		return 0;
}
	#line 667 f0__ //Expr
	Expr366* CreateCall17(str53 ident,Expr366* left,Expr366* right){
		#line 668 f0__ //Expr
		if((!right)){
			#line 669 f0__ //Expr
			Error20(add64(str53{30,(i8*)"Expected expression following "},ident),(*left).at);
			#line 670 f0__ //Expr
			return (Expr366*)0;
		};
		#line 672 f0__ //Expr
		Call442* op=Call443();
		#line 673 f0__ //Expr
		(*op).super.at = (*left).at;
		#line 675 f0__ //Expr
		Identifier495* identifier=Identifier496();
		#line 676 f0__ //Expr
		(*identifier).ident = ident;
		#line 677 f0__ //Expr
		(*op).operand = (&(*identifier).super);
		#line 678 f0__ //Expr
		Add371((*op).params,left);
		#line 679 f0__ //Expr
		Add371((*op).params,right);
		#line 680 f0__ //Expr
		return (&(*op).super);
}
	#line 683 f0__ //Expr
	Expr366* ParseExpression18(Lexer78& lexer,i32 precedence){
		#line 685 f0__ //Expr
		Expr366* left=ParseOperand14(lexer,precedence);
		#line 686 f0__ //Expr
		while(left){
			#line 688 f0__ //Expr
			if((equal80(At90(lexer,0),kDot)&&notEqual81(At90(lexer,1),kDot))){
				#line 689 f0__ //Expr
				Eat92(lexer,1);
				#line 690 f0__ //Expr
				Access445* access=New1693();
				#line 691 f0__ //Expr
				(*access).super.at = At90(lexer,0).at;
				#line 692 f0__ //Expr
				(*access).operand = left;
				#line 694 f0__ //Expr
				if(notEqual81(At90(lexer,0),kIdentifier)){
					#line 695 f0__ //Expr
					Assert260(0,str53{31,(i8*)"Expected identifier following ."});
				};
				#line 697 f0__ //Expr
				(*access).field = At90(lexer,0).value;
				#line 698 f0__ //Expr
				Eat92(lexer,1);
				#line 700 f0__ //Expr
				left = (&(*access).super);
			}else{
				#line 702 f0__ //Expr
				if((equal80(At90(lexer,0),kEqual)&&notEqual81(At90(lexer,1),kEqual))){
					#line 703 f0__ //Expr
					Assign501* assign=New1796();
					#line 704 f0__ //Expr
					(*assign).super.at = At90(lexer,0).at;
					#line 705 f0__ //Expr
					Eat92(lexer,1);
					#line 706 f0__ //Expr
					(*assign).left = left;
					#line 707 f0__ //Expr
					(*assign).right = ParseExpression18(lexer,0);
					#line 708 f0__ //Expr
					if((!(*assign).right)){
						#line 709 f0__ //Expr
						Error20(str53{31,(i8*)"Expected expression following ="},At90(lexer,0).at);
					};
					#line 711 f0__ //Expr
					left = (&(*assign).super);
				}else{
					#line 713 f0__ //Expr
					if(equal80(At90(lexer,0),kEqual)){
						#line 714 f0__ //Expr
						if((3<precedence)){
							#line 715 f0__ //Expr
							return left;
						};
						#line 717 f0__ //Expr
						Eat92(lexer,2);
						#line 718 f0__ //Expr
						left = CreateCall17(str53{2,(i8*)"=="},left,ParseExpression18(lexer,(3+1)));
					}else{
						#line 720 f0__ //Expr
						if((equal80(At90(lexer,0),kNot)&&equal80(At90(lexer,1),kEqual))){
							#line 721 f0__ //Expr
							if((3<precedence)){
								#line 722 f0__ //Expr
								return left;
							};
							#line 724 f0__ //Expr
							Eat92(lexer,2);
							#line 725 f0__ //Expr
							left = CreateCall17(str53{2,(i8*)"!="},left,ParseExpression18(lexer,(3+1)));
						}else{
							#line 727 f0__ //Expr
							if(equal80(At90(lexer,0),kBraceOpen)){
								#line 728 f0__ //Expr
								Eat92(lexer,1);
								#line 729 f0__ //Expr
								left = CreateCall17(str53{2,(i8*)"[]"},left,ParseExpression18(lexer,0));
								#line 730 f0__ //Expr
								Expect21(lexer,kBraceClose);
							}else{
								#line 732 f0__ //Expr
								if((equal80(At90(lexer,0),kGreater)&&equal80(At90(lexer,1),kEqual))){
									#line 733 f0__ //Expr
									if((3<precedence)){
										#line 734 f0__ //Expr
										return left;
									};
									#line 736 f0__ //Expr
									Eat92(lexer,2);
									#line 737 f0__ //Expr
									left = CreateCall17(str53{2,(i8*)">="},left,ParseExpression18(lexer,(3+1)));
								}else{
									#line 739 f0__ //Expr
									if(equal80(At90(lexer,0),kGreater)){
										#line 740 f0__ //Expr
										if((3<precedence)){
											#line 741 f0__ //Expr
											return left;
										};
										#line 743 f0__ //Expr
										Eat92(lexer,1);
										#line 744 f0__ //Expr
										left = CreateCall17(str53{1,(i8*)">"},left,ParseExpression18(lexer,(3+1)));
									}else{
										#line 746 f0__ //Expr
										if((equal80(At90(lexer,0),kLess)&&equal80(At90(lexer,1),kEqual))){
											#line 747 f0__ //Expr
											if((3<precedence)){
												#line 748 f0__ //Expr
												return left;
											};
											#line 750 f0__ //Expr
											Eat92(lexer,2);
											#line 751 f0__ //Expr
											left = CreateCall17(str53{2,(i8*)"<="},left,ParseExpression18(lexer,(3+1)));
										}else{
											#line 753 f0__ //Expr
											if((equal80(At90(lexer,0),kAnd)&&equal80(At90(lexer,1),kAnd))){
												#line 754 f0__ //Expr
												if((2<precedence)){
													#line 755 f0__ //Expr
													return left;
												};
												#line 757 f0__ //Expr
												Eat92(lexer,2);
												#line 758 f0__ //Expr
												left = CreateCall17(str53{2,(i8*)"&&"},left,ParseExpression18(lexer,(2+1)));
											}else{
												#line 760 f0__ //Expr
												if((equal80(At90(lexer,0),kOr)&&equal80(At90(lexer,1),kOr))){
													#line 761 f0__ //Expr
													if((1<precedence)){
														#line 762 f0__ //Expr
														return left;
													};
													#line 764 f0__ //Expr
													Eat92(lexer,2);
													#line 765 f0__ //Expr
													left = CreateCall17(str53{2,(i8*)"||"},left,ParseExpression18(lexer,(1+1)));
												}else{
													#line 767 f0__ //Expr
													if(equal80(At90(lexer,0),kLess)){
														#line 768 f0__ //Expr
														if((3<precedence)){
															#line 769 f0__ //Expr
															return left;
														};
														#line 771 f0__ //Expr
														Eat92(lexer,1);
														#line 772 f0__ //Expr
														left = CreateCall17(str53{1,(i8*)"<"},left,ParseExpression18(lexer,(3+1)));
													}else{
														#line 774 f0__ //Expr
														if(equal80(At90(lexer,0),kEqual)){
															#line 775 f0__ //Expr
															Eat92(lexer,2);
															#line 776 f0__ //Expr
															Call442* op=Call443();
															#line 777 f0__ //Expr
															(*op).super.at = At90(lexer,0).at;
															#line 778 f0__ //Expr
															Identifier495* identifier=Identifier496();
															#line 779 f0__ //Expr
															(*identifier).ident = str53{2,(i8*)"=="};
															#line 780 f0__ //Expr
															(*op).operand = (&(*identifier).super);
															#line 781 f0__ //Expr
															Add371((*op).params,left);
															#line 782 f0__ //Expr
															left = (&(*op).super);
														}else{
															#line 784 f0__ //Expr
															if(IsOperator15(At90(lexer,0))){
																#line 786 f0__ //Expr
																i32 nextPrecedence=Precedence16(At90(lexer,0));
																#line 788 f0__ //Expr
																if((nextPrecedence<precedence)){
																	#line 790 f0__ //Expr
																	return left;
																};
																#line 793 f0__ //Expr
																Call442* op=Call443();
																#line 794 f0__ //Expr
																(*op).super.at = At90(lexer,0).at;
																#line 795 f0__ //Expr
																Identifier495* identifier=Identifier496();
																#line 796 f0__ //Expr
																(*identifier).ident = TokenString79(At90(lexer,0).Type);
																#line 797 f0__ //Expr
																(*op).operand = (&(*identifier).super);
																#line 798 f0__ //Expr
																Eat92(lexer,1);
																#line 800 f0__ //Expr
																Expr366* right=ParseExpression18(lexer,(nextPrecedence+1));
																#line 801 f0__ //Expr
																Assert162(left,str53{13,(i8*)"Expected left"});
																#line 802 f0__ //Expr
																Assert162(right,str53{14,(i8*)"Expected right"});
																#line 804 f0__ //Expr
																Add371((*op).params,left);
																#line 805 f0__ //Expr
																Add371((*op).params,right);
																#line 806 f0__ //Expr
																left = (&(*op).super);
															}else{
																#line 808 f0__ //Expr
																if(equal80(At90(lexer,0),kParenOpen)){
																	#line 810 f0__ //Expr
																	Call442* call=Call443();
																	#line 811 f0__ //Expr
																	(*call).operand = left;
																	#line 812 f0__ //Expr
																	(*call).super.at = At90(lexer,0).at;
																	#line 813 f0__ //Expr
																	Eat92(lexer,1);
																	#line 815 f0__ //Expr
																	while(notEqual81(At90(lexer,0),kParenClose)){
																		#line 816 f0__ //Expr
																		Expr366* expr=ParseExpression18(lexer,0);
																		#line 817 f0__ //Expr
																		if((!expr)){
																			#line 818 f0__ //Expr
																			Error20(str53{10,(i8*)"Expected )"},At90(lexer,(-1)).at);
																			#line 819 f0__ //Expr
																			return left;
																		};
																		#line 821 f0__ //Expr
																		Add371((*call).params,expr);
																		#line 822 f0__ //Expr
																		if(equal80(At90(lexer,0),kComma)){
																			#line 823 f0__ //Expr
																			Eat92(lexer,1);
																		};
																	};
																	#line 826 f0__ //Expr
																	Expect21(lexer,kParenClose);
																	#line 827 f0__ //Expr
																	left = (&(*call).super);
																}else{
																	#line 830 f0__ //Expr
																	return left;
																};
															};
														};
													};
												};
											};
										};
									};
								};
							};
						};
					};
				};
			};
		};
		#line 833 f0__ //Expr
		return left;
}
	#line 836 f0__ //Expr
	Expr366* ParseExpression19(Lexer78& lexer){
		#line 838 f0__ //Expr
		Expr366* expr=ParseExpression18(lexer,0);
		#line 839 f0__ //Expr
		if(expr){
			#line 840 f0__ //Expr
			ExpectEndStatement22(lexer);
		};
		#line 842 f0__ //Expr
		return expr;
}
	#line 845 f0__ //Expr
	void Error20(str53 message,Position76 at){
		#line 847 f0__ //Expr
		Error0 error={0};
		#line 848 f0__ //Expr
		error.message = message;
		#line 849 f0__ //Expr
		error.at = at;
		#line 850 f0__ //Expr
		Push399(errors,error);
}
	#line 853 f0__ //Expr
	Position76 Expect21(Lexer78& lexer,i32 token){
		#line 855 f0__ //Expr
		Position76 at=At90(lexer,0).at;
		#line 857 f0__ //Expr
		if(notEqual81(At90(lexer,0),token)){
			#line 859 f0__ //Expr
			Error20(add64(add64(add64(str53{9,(i8*)"Expected "},TokenString79(token)),str53{8,(i8*)", found "}),TokenString79(At90(lexer,0).Type)),at);
		};
		#line 861 f0__ //Expr
		Eat92(lexer,1);
		#line 862 f0__ //Expr
		return at;
}
	#line 865 f0__ //Expr
	void ExpectEndStatement22(Lexer78& lexer){
		#line 867 f0__ //Expr
		if((((equal80(At90(lexer,0),kComma)||equal80(At90(lexer,0),kParenClose))||equal80(At90(lexer,0),kBracketClose))||equal80(At90(lexer,0),kBracketOpen))){
			#line 868 f0__ //Expr
			return ;
		};
		#line 870 f0__ //Expr
		if((notEqual81(At90(lexer,0),kSemicolon)&&notEqual81(At90(lexer,0),kEndLine))){
			#line 872 f0__ //Expr
			Error20(add64(add64(add64(str53{17,(i8*)"Expected ; found "},TokenString79(At90(lexer,0).Type)),str53{1,(i8*)" "}),String66(At90(lexer,(-1)).Type)),At90(lexer,0).at);
		};
		#line 874 f0__ //Expr
		Eat92(lexer,1);
}
	#line 877 f0__ //Expr
	void Parse23(Block434* block,str53 file){
		#line 879 f0__ //Expr
		Module155* module=AddFile158(project,file);
		#line 880 f0__ //Expr
		Lexer78 lexer=Lexer82(file,project.files.length);
		#line 881 f0__ //Expr
		while(true){
			#line 883 f0__ //Expr
			ParseDirective2(lexer,(*block));
			#line 885 f0__ //Expr
			Expr366* expr={0};
			#line 886 f0__ //Expr
			if((!expr)){
				#line 887 f0__ //Expr
				expr = (&(*ParseStructure4(lexer)).super);
			};
			#line 889 f0__ //Expr
			if((!expr)){
				#line 890 f0__ //Expr
				expr = (&(*ParseFunction3(lexer)).super);
			};
			#line 892 f0__ //Expr
			if((!expr)){
				#line 893 f0__ //Expr
				expr = (&(*ParseTrait6(lexer)).super);
			};
			#line 895 f0__ //Expr
			if((!expr)){
				#line 896 f0__ //Expr
				expr = (&(*ParseRequire7(lexer)).super);
			};
			#line 898 f0__ //Expr
			if((!expr)){
				#line 899 f0__ //Expr
				expr = (&(*ParseVariable12(lexer)).super);
			};
			#line 901 f0__ //Expr
			if((!expr)){
				#line 903 f0__ //Expr
				if(notEqual81(At90(lexer,0),kEnd)){
					#line 905 f0__ //Expr
					Error20(str53{52,(i8*)"Expected fn, struct, trait, or variable at top level"},At90(lexer,0).at);
				};
				#line 907 f0__ //Expr
				return ;
			};
			#line 909 f0__ //Expr
			Add441((*block),expr);
		};
}
	#line 913 f0__ //Expr
	;
	#line 914 f0__ //Expr
	;
	#line 916 f0__ //Expr
	Block434* Compile24(str53 file){
		#line 918 f0__ //Expr
		Block434* block=New18101();
		#line 919 f0__ //Expr
		Push035(filesToParse,file);
		#line 921 f0__ //Expr
		while(filesToParse.length){
			#line 924 f0__ //Expr
			str53 theFile=Last0104(filesToParse);
			#line 925 f0__ //Expr
			Pop0106(filesToParse);
			#line 927 f0__ //Expr
			if((!ContainsFile157(project,theFile))){
				#line 929 f0__ //Expr
				AddFile158(project,theFile);
				#line 930 f0__ //Expr
				Parse23(block,theFile);
				#line 931 f0__ //Expr
				if(errors.length){
					#line 932 f0__ //Expr
					return block;
				};
			};
		};
		#line 937 f0__ //Expr
		return block;
}
	#line 940 f0__ //Expr
	void PrintError25(Position76 at,str53 message){
		#line 942 f0__ //Expr
		str53 f={0};
		#line 943 f0__ //Expr
		if((at.file==0)){
			#line 944 f0__ //Expr
			f = str53{0,(i8*)""};
		}else{
			#line 947 f0__ //Expr
			f = add64(directory,(*OpArray1107(project.files,(at.file-1))).path);
		};
		#line 950 f0__ //Expr
		Error62(str53{294,(i8*)"••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"});
		#line 951 f0__ //Expr
		Println59(add64(add64(add64(add64(add64(add64(f,str53{1,(i8*)":"}),String66(at.line)),str53{1,(i8*)":"}),String66(at.column)),str53{9,(i8*)": error: "}),message));
		#line 953 f0__ //Expr
		PrintLines159(project,at,6);
		#line 955 f0__ //Expr
		Error62(str53{294,(i8*)"••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"});
}
	#line 958 f0__ //Expr
	void Run26(){
		#line 960 f0__ //Expr
		Println59(str53{17,(i8*)"Running c backend"});
		#line 961 f0__ //Expr
		str53 link=str53{138,(i8*)"-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo /Users/David/Desktop/Projects/glfw/src/libglfw.3.3.dylib libstb.a"};
		#line 962 f0__ //Expr
		str53 call=add64(add64(str53{95,(i8*)"clang++ -std=c++11 -stdlib=libc++ -Wno-parentheses-equality build/strap.cpp -o build/strap -O0 "},link),str53{16,(i8*)" && build/strap\0"});
		#line 963 f0__ //Expr
		dlSystem(call.chars);
}
	#line 966 f0__ //Expr
	;
	#line 968 f0__ //Expr
	i32 main(){
		#line 970 f0__ //Expr
		chdir(directory.chars);
		#line 971 f0__ //Expr
		Block434* block=Compile24(str53{7,(i8*)"Main.dl"});
		#line 973 f0__ //Expr
		if(errors.length){
			#line 975 f0__ //Expr
			PrintError25(OpArray2108(errors,0).at,OpArray2108(errors,0).message);
		};
		#line 978 f0__ //Expr
		if((errors.length==0)){
			#line 979 f0__ //Expr
			Semantic110 semantic={0};
			#line 980 f0__ //Expr
			Init111(semantic,(*block));
			#line 982 f0__ //Expr
			if((errors.length==0)){
				#line 984 f0__ //Expr
				GenerateBasic141 generate={0};
				#line 985 f0__ //Expr
				Init147(generate,semantic,(*block));
				#line 992 f0__ //Expr
				Run26();
			}else{
				#line 995 f0__ //Expr
				Println59(str53{14,(i8*)"Semantic error"});
			};
		};
		#line 1001 f0__ //Expr
		Println59(str53{0,(i8*)""});
		#line 1002 f0__ //Expr
		return 0;
}
			#line 15 f1__ //Expr
	void Init0111(Array218& array,i64 length){
		#line 16 f1__ //Expr
		array.elements = Alloc19109(length);
		#line 17 f1__ //Expr
		array.length = length;
}
void Init1213(Array4212& array,i64 length){
		#line 16 f1__ //Expr
		array.elements = Alloc25214(length);
		#line 17 f1__ //Expr
		array.length = length;
}
void Init2216(Array116& array,i64 length){
		#line 16 f1__ //Expr
		array.elements = Alloc26217(length);
		#line 17 f1__ //Expr
		array.length = length;
}
void Init3239(Array320& array,i64 length){
		#line 16 f1__ //Expr
		array.elements = Alloc28240(length);
		#line 17 f1__ //Expr
		array.length = length;
}
	#line 20 f1__ //Expr
	i8& OpArray0112(Array218& array,i64 index){
		#line 21 f1__ //Expr
		if((index>=array.length)){
			#line 22 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 24 f1__ //Expr
		return (*(array.elements+index));
}
TypeNumber431*& OpArray1215(Array4212& array,i64 index){
		#line 21 f1__ //Expr
		if((index>=array.length)){
			#line 22 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 24 f1__ //Expr
		return (*(array.elements+index));
}
Function456& OpArray2218(Array116& array,i64 index){
		#line 21 f1__ //Expr
		if((index>=array.length)){
			#line 22 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 24 f1__ //Expr
		return (*(array.elements+index));
}
	#line 28 f1__ //Expr
	str53& OpArray0105(DynamicArray2234& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Module155*& OpArray1107(DynamicArray1419& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Error0& OpArray2108(DynamicArray2133& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Token77& OpArray3115(DynamicArray10& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Expr366*& OpArray4122(DynamicArray21& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Variable498*& OpArray5125(DynamicArray912& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Type413*& OpArray6155(DynamicArray43& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Block434*& OpArray7161(DynamicArray1317& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
Function456*& OpArray8163(DynamicArray78& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TypeAnyResolved472& OpArray9179(DynamicArray32& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TableNode6221& OpArray10228(DynamicArray24222& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
FunctionSpec460*& OpArray11230(DynamicArray54& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TypeStructure481*& OpArray12231(DynamicArray1114& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TableNode322& OpArray13254(DynamicArray1523& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
i64& OpArray14255(DynamicArray25248& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
DebugLocal207*& OpArray15261(DynamicArray1624& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
DebugFrame209*& OpArray16262(DynamicArray1828& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TableNode530& OpArray17286(DynamicArray1931& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
i32& OpArray18290(DynamicArray2032& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TableNode426& OpArray19300(DynamicArray1727& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TableNode16& OpArray20345(DynamicArray67& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
TableNode210& OpArray21348(DynamicArray811& array,i64 index){
		#line 29 f1__ //Expr
		if((index>=array.length)){
			#line 30 f1__ //Expr
			Assert260(0,add64(add64(add64(add64(str53{28,(i8*)"Array access out of bounds ["},String66(index)),str53{1,(i8*)"]"}),str53{11,(i8*)" length is "}),String66(array.length)));
		};
		#line 32 f1__ //Expr
		return (*(array.elements+index));
}
	#line 35 f1__ //Expr
	void Init0117(DynamicArray23116& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (i8*)0;
}
void Init1226(DynamicArray24222& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TableNode6221*)0;
}
void Init2242(DynamicArray1523& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TableNode322*)0;
}
void Init3245(DynamicArray1727& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TableNode426*)0;
}
void Init4247(DynamicArray1828& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (DebugFrame209**)0;
}
void Init5249(DynamicArray25248& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (i64*)0;
}
void Init6258(DynamicArray1624& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (DebugLocal207**)0;
}
void Init7284(DynamicArray1931& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TableNode530*)0;
}
void Init8295(DynamicArray2032& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (i32*)0;
}
void Init9330(DynamicArray21& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (Expr366**)0;
}
void Init10331(DynamicArray43& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (Type413**)0;
}
void Init11338(DynamicArray67& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TableNode16*)0;
}
void Init12341(DynamicArray811& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TableNode210*)0;
}
void Init13361(DynamicArray32& array){
		#line 37 f1__ //Expr
		array.capacity = 0;
		#line 38 f1__ //Expr
		array.length = 0;
		#line 39 f1__ //Expr
		array.elements = (TypeAnyResolved472*)0;
}
	#line 42 f1__ //Expr
	void Insert0177(DynamicArray21& array,i64 index,Expr366* value){
		#line 44 f1__ //Expr
		Assert260(i8294(((index>=0)&&(index<(array.length+1)))),str53{28,(i8*)"Cant insert outside of range"});
		#line 45 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 47 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 48 f1__ //Expr
			if((capacity<10)){
				#line 49 f1__ //Expr
				Reserve289(array,10);
			}else{
				#line 52 f1__ //Expr
				Reserve289(array,capacity);
			};
		};
		#line 55 f1__ //Expr
		array.length = (array.length+1);
		#line 56 f1__ //Expr
		for(i64 it = i64271(index); it<(array.length-1);it++){
			#line 57 f1__ //Expr
			i64 at=((array.length-1)-it);
			#line 58 f1__ //Expr
			OpArray4122(array,at) = OpArray4122(array,(at-1));
		};
		#line 60 f1__ //Expr
		OpArray4122(array,index) = value;
}
	#line 63 f1__ //Expr
	void Push035(DynamicArray2234& array,str53 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve036(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve036(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push137(DynamicArray43& array,Type413* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve138(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve138(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push288(DynamicArray21& array,Expr366* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve289(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve289(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push399(DynamicArray2133& array,Error0 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve3100(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve3100(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push4113(DynamicArray10& array,Token77 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve4114(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve4114(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push5118(DynamicArray23116& array,i8 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve5119(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve5119(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push6158(DynamicArray1317& array,Block434* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve6159(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve6159(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push7169(DynamicArray1215& array,Structure473* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve7170(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve7170(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push8171(DynamicArray1114& array,TypeStructure481* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve8172(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve8172(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push9237(DynamicArray1419& array,Module155* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve9238(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve9238(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push10250(DynamicArray25248& array,i64 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve10251(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve10251(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push11280(DynamicArray1624& array,DebugLocal207* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve11281(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve11281(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push12291(DynamicArray2032& array,i32 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve12292(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve12292(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push13301(DynamicArray1828& array,DebugFrame209* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve13302(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve13302(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push14349(DynamicArray78& array,Function456* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve14350(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve14350(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push15357(DynamicArray54& array,FunctionSpec460* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve15358(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve15358(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push16359(DynamicArray32& array,TypeAnyResolved472 value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve16360(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve16360(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
void Push17364(DynamicArray912& array,Variable498* value){
		#line 65 f1__ //Expr
		if((array.capacity<(array.length+1))){
			#line 67 f1__ //Expr
			i64 capacity=(array.capacity*2);
			#line 68 f1__ //Expr
			if((capacity<25)){
				#line 69 f1__ //Expr
				Reserve17365(array,25);
			}else{
				#line 72 f1__ //Expr
				Reserve17365(array,capacity);
			};
		};
		#line 75 f1__ //Expr
		(*(array.elements+array.length)) = value;
		#line 76 f1__ //Expr
		array.length = (array.length+1);
}
	#line 79 f1__ //Expr
	void Reserve036(DynamicArray2234& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo0.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (str53*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo0.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve138(DynamicArray43& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo1.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Type413**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo1.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve289(DynamicArray21& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo17.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Expr366**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo17.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve3100(DynamicArray2133& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo21.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Error0*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo21.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve4114(DynamicArray10& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo24.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Token77*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo24.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve5119(DynamicArray23116& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo23.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (i8*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo23.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve6159(DynamicArray1317& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo25.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Block434**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo25.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve7170(DynamicArray1215& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo27.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Structure473**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo27.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve8172(DynamicArray1114& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo28.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (TypeStructure481**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo28.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve9238(DynamicArray1419& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo37.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Module155**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo37.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve10251(DynamicArray25248& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo38.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (i64*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo38.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve11281(DynamicArray1624& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo43.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (DebugLocal207**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo43.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve12292(DynamicArray2032& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo45.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (i32*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo45.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve13302(DynamicArray1828& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo47.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (DebugFrame209**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo47.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve14350(DynamicArray78& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo58.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Function456**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo58.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve15358(DynamicArray54& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo60.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (FunctionSpec460**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo60.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve16360(DynamicArray32& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo61.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (TypeAnyResolved472*)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo61.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
void Reserve17365(DynamicArray912& array,i64 size){
		#line 81 f1__ //Expr
		if((array.capacity<size)){
			#line 83 f1__ //Expr
			i64 bytes=((i64267(typeinfo63.size)*size)*2);
			#line 84 f1__ //Expr
			array.elements = (Variable498**)realloc((voidptr)array.elements,u64327(bytes));
			#line 85 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo63.size)*(size-array.capacity))));
			#line 86 f1__ //Expr
			array.capacity = size;
		};
}
	#line 90 f1__ //Expr
	void Resize0227(DynamicArray24222& array,i64 size){
		#line 92 f1__ //Expr
		if((array.capacity<size)){
			#line 94 f1__ //Expr
			i64 bytes=(i64267(typeinfo35.size)*size);
			#line 95 f1__ //Expr
			array.elements = (TableNode6221*)realloc((voidptr)array.elements,u64327(bytes));
			#line 96 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo35.size)*(size-array.capacity))));
			#line 97 f1__ //Expr
			array.capacity = size;
		};
		#line 99 f1__ //Expr
		array.length = size;
}
void Resize1243(DynamicArray1523& array,i64 size){
		#line 92 f1__ //Expr
		if((array.capacity<size)){
			#line 94 f1__ //Expr
			i64 bytes=(i64267(typeinfo39.size)*size);
			#line 95 f1__ //Expr
			array.elements = (TableNode322*)realloc((voidptr)array.elements,u64327(bytes));
			#line 96 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo39.size)*(size-array.capacity))));
			#line 97 f1__ //Expr
			array.capacity = size;
		};
		#line 99 f1__ //Expr
		array.length = size;
}
void Resize2246(DynamicArray1727& array,i64 size){
		#line 92 f1__ //Expr
		if((array.capacity<size)){
			#line 94 f1__ //Expr
			i64 bytes=(i64267(typeinfo40.size)*size);
			#line 95 f1__ //Expr
			array.elements = (TableNode426*)realloc((voidptr)array.elements,u64327(bytes));
			#line 96 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo40.size)*(size-array.capacity))));
			#line 97 f1__ //Expr
			array.capacity = size;
		};
		#line 99 f1__ //Expr
		array.length = size;
}
void Resize3285(DynamicArray1931& array,i64 size){
		#line 92 f1__ //Expr
		if((array.capacity<size)){
			#line 94 f1__ //Expr
			i64 bytes=(i64267(typeinfo44.size)*size);
			#line 95 f1__ //Expr
			array.elements = (TableNode530*)realloc((voidptr)array.elements,u64327(bytes));
			#line 96 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo44.size)*(size-array.capacity))));
			#line 97 f1__ //Expr
			array.capacity = size;
		};
		#line 99 f1__ //Expr
		array.length = size;
}
void Resize4339(DynamicArray67& array,i64 size){
		#line 92 f1__ //Expr
		if((array.capacity<size)){
			#line 94 f1__ //Expr
			i64 bytes=(i64267(typeinfo56.size)*size);
			#line 95 f1__ //Expr
			array.elements = (TableNode16*)realloc((voidptr)array.elements,u64327(bytes));
			#line 96 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo56.size)*(size-array.capacity))));
			#line 97 f1__ //Expr
			array.capacity = size;
		};
		#line 99 f1__ //Expr
		array.length = size;
}
void Resize5342(DynamicArray811& array,i64 size){
		#line 92 f1__ //Expr
		if((array.capacity<size)){
			#line 94 f1__ //Expr
			i64 bytes=(i64267(typeinfo57.size)*size);
			#line 95 f1__ //Expr
			array.elements = (TableNode210*)realloc((voidptr)array.elements,u64327(bytes));
			#line 96 f1__ //Expr
			memset((voidptr)(array.elements+array.capacity),0,u64327((i64267(typeinfo57.size)*(size-array.capacity))));
			#line 97 f1__ //Expr
			array.capacity = size;
		};
		#line 99 f1__ //Expr
		array.length = size;
}
	#line 102 f1__ //Expr
	void Pop0106(DynamicArray2234& array){
		#line 104 f1__ //Expr
		array.length = (array.length-1);
}
void Pop1162(DynamicArray1317& array){
		#line 104 f1__ //Expr
		array.length = (array.length-1);
}
void Pop2293(DynamicArray2032& array){
		#line 104 f1__ //Expr
		array.length = (array.length-1);
}
	#line 107 f1__ //Expr
	str53& Last0104(DynamicArray2234& array){
		#line 109 f1__ //Expr
		Assert260((array.length>0),str53{30,(i8*)"Array needs at least 1 element"});
		#line 110 f1__ //Expr
		return OpArray0105(array,(array.length-1));
}
Block434*& Last1160(DynamicArray1317& array){
		#line 109 f1__ //Expr
		Assert260((array.length>0),str53{30,(i8*)"Array needs at least 1 element"});
		#line 110 f1__ //Expr
		return OpArray7161(array,(array.length-1));
}
i32& Last2289(DynamicArray2032& array){
		#line 109 f1__ //Expr
		Assert260((array.length>0),str53{30,(i8*)"Array needs at least 1 element"});
		#line 110 f1__ //Expr
		return OpArray18290(array,(array.length-1));
}
	#line 113 f1__ //Expr
				#line 143 f1__ //Expr
	void Init0229(Table6220& table){
		#line 145 f1__ //Expr
		table.length = 0;
		#line 146 f1__ //Expr
		table.capacity = 16;
		#line 148 f1__ //Expr
		Init1226(table.data);
		#line 149 f1__ //Expr
		Resize0227(table.data,16);
}
void Init1241(Table321& table){
		#line 145 f1__ //Expr
		table.length = 0;
		#line 146 f1__ //Expr
		table.capacity = 16;
		#line 148 f1__ //Expr
		Init2242(table.data);
		#line 149 f1__ //Expr
		Resize1243(table.data,16);
}
void Init2244(Table425& table){
		#line 145 f1__ //Expr
		table.length = 0;
		#line 146 f1__ //Expr
		table.capacity = 16;
		#line 148 f1__ //Expr
		Init3245(table.data);
		#line 149 f1__ //Expr
		Resize2246(table.data,16);
}
void Init3294(Table529& table){
		#line 145 f1__ //Expr
		table.length = 0;
		#line 146 f1__ //Expr
		table.capacity = 16;
		#line 148 f1__ //Expr
		Init7284(table.data);
		#line 149 f1__ //Expr
		Resize3285(table.data,16);
}
void Init4337(Table15& table){
		#line 145 f1__ //Expr
		table.length = 0;
		#line 146 f1__ //Expr
		table.capacity = 16;
		#line 148 f1__ //Expr
		Init11338(table.data);
		#line 149 f1__ //Expr
		Resize4339(table.data,16);
}
void Init5340(Table29& table){
		#line 145 f1__ //Expr
		table.length = 0;
		#line 146 f1__ //Expr
		table.capacity = 16;
		#line 148 f1__ //Expr
		Init12341(table.data);
		#line 149 f1__ //Expr
		Resize5342(table.data,16);
}
	#line 152 f1__ //Expr
	void Resize0225(Table6220& table){
		#line 154 f1__ //Expr
		DynamicArray24222 data={0};
		#line 155 f1__ //Expr
		Init1226(data);
		#line 156 f1__ //Expr
		Resize0227(data,(table.capacity*2));
		#line 158 f1__ //Expr
		for(i64 it = i64265(0); it<table.data.length;it++){
			#line 160 f1__ //Expr
			if(OpArray10228(table.data,it).hash){
				#line 161 f1__ //Expr
				i64 hash=Hash70(OpArray10228(table.data,it).key);
				#line 162 f1__ //Expr
				i64 at=((hash%(data.length-1))+1);
				#line 164 f1__ //Expr
				i8 done=false;
				#line 165 f1__ //Expr
				while((!done)){
					#line 167 f1__ //Expr
					if((OpArray10228(data,at).hash==0)){
						#line 169 f1__ //Expr
						OpArray10228(data,at) = OpArray10228(table.data,it);
						#line 170 f1__ //Expr
						done = true;
					}else{
						#line 174 f1__ //Expr
						if(Equal69(OpArray10228(table.data,it).key,OpArray10228(data,at).key)){
							#line 176 f1__ //Expr
							OpArray10228(data,at) = OpArray10228(table.data,it);
							#line 177 f1__ //Expr
							done = true;
						};
						#line 179 f1__ //Expr
						at = ((at+1)%data.length);
					};
				};
			};
		};
		#line 185 f1__ //Expr
		table.data = data;
		#line 186 f1__ //Expr
		table.capacity = (table.capacity*2);
}
void Resize1253(Table321& table){
		#line 154 f1__ //Expr
		DynamicArray1523 data={0};
		#line 155 f1__ //Expr
		Init2242(data);
		#line 156 f1__ //Expr
		Resize1243(data,(table.capacity*2));
		#line 158 f1__ //Expr
		for(i64 it = i64265(0); it<table.data.length;it++){
			#line 160 f1__ //Expr
			if(OpArray13254(table.data,it).hash){
				#line 161 f1__ //Expr
				i64 hash=Hash70(OpArray13254(table.data,it).key);
				#line 162 f1__ //Expr
				i64 at=((hash%(data.length-1))+1);
				#line 164 f1__ //Expr
				i8 done=false;
				#line 165 f1__ //Expr
				while((!done)){
					#line 167 f1__ //Expr
					if((OpArray13254(data,at).hash==0)){
						#line 169 f1__ //Expr
						OpArray13254(data,at) = OpArray13254(table.data,it);
						#line 170 f1__ //Expr
						done = true;
					}else{
						#line 174 f1__ //Expr
						if(Equal69(OpArray13254(table.data,it).key,OpArray13254(data,at).key)){
							#line 176 f1__ //Expr
							OpArray13254(data,at) = OpArray13254(table.data,it);
							#line 177 f1__ //Expr
							done = true;
						};
						#line 179 f1__ //Expr
						at = ((at+1)%data.length);
					};
				};
			};
		};
		#line 185 f1__ //Expr
		table.data = data;
		#line 186 f1__ //Expr
		table.capacity = (table.capacity*2);
}
void Resize2283(Table529& table){
		#line 154 f1__ //Expr
		DynamicArray1931 data={0};
		#line 155 f1__ //Expr
		Init7284(data);
		#line 156 f1__ //Expr
		Resize3285(data,(table.capacity*2));
		#line 158 f1__ //Expr
		for(i64 it = i64265(0); it<table.data.length;it++){
			#line 160 f1__ //Expr
			if(OpArray17286(table.data,it).hash){
				#line 161 f1__ //Expr
				i64 hash=Hash0287(OpArray17286(table.data,it).key);
				#line 162 f1__ //Expr
				i64 at=((hash%(data.length-1))+1);
				#line 164 f1__ //Expr
				i8 done=false;
				#line 165 f1__ //Expr
				while((!done)){
					#line 167 f1__ //Expr
					if((OpArray17286(data,at).hash==0)){
						#line 169 f1__ //Expr
						OpArray17286(data,at) = OpArray17286(table.data,it);
						#line 170 f1__ //Expr
						done = true;
					}else{
						#line 174 f1__ //Expr
						if(Equal1288(OpArray17286(table.data,it).key,OpArray17286(data,at).key)){
							#line 176 f1__ //Expr
							OpArray17286(data,at) = OpArray17286(table.data,it);
							#line 177 f1__ //Expr
							done = true;
						};
						#line 179 f1__ //Expr
						at = ((at+1)%data.length);
					};
				};
			};
		};
		#line 185 f1__ //Expr
		table.data = data;
		#line 186 f1__ //Expr
		table.capacity = (table.capacity*2);
}
void Resize3299(Table425& table){
		#line 154 f1__ //Expr
		DynamicArray1727 data={0};
		#line 155 f1__ //Expr
		Init3245(data);
		#line 156 f1__ //Expr
		Resize2246(data,(table.capacity*2));
		#line 158 f1__ //Expr
		for(i64 it = i64265(0); it<table.data.length;it++){
			#line 160 f1__ //Expr
			if(OpArray19300(table.data,it).hash){
				#line 161 f1__ //Expr
				i64 hash=Hash75(OpArray19300(table.data,it).key);
				#line 162 f1__ //Expr
				i64 at=((hash%(data.length-1))+1);
				#line 164 f1__ //Expr
				i8 done=false;
				#line 165 f1__ //Expr
				while((!done)){
					#line 167 f1__ //Expr
					if((OpArray19300(data,at).hash==0)){
						#line 169 f1__ //Expr
						OpArray19300(data,at) = OpArray19300(table.data,it);
						#line 170 f1__ //Expr
						done = true;
					}else{
						#line 174 f1__ //Expr
						if(Equal73(OpArray19300(table.data,it).key,OpArray19300(data,at).key)){
							#line 176 f1__ //Expr
							OpArray19300(data,at) = OpArray19300(table.data,it);
							#line 177 f1__ //Expr
							done = true;
						};
						#line 179 f1__ //Expr
						at = ((at+1)%data.length);
					};
				};
			};
		};
		#line 185 f1__ //Expr
		table.data = data;
		#line 186 f1__ //Expr
		table.capacity = (table.capacity*2);
}
void Resize4344(Table15& table){
		#line 154 f1__ //Expr
		DynamicArray67 data={0};
		#line 155 f1__ //Expr
		Init11338(data);
		#line 156 f1__ //Expr
		Resize4339(data,(table.capacity*2));
		#line 158 f1__ //Expr
		for(i64 it = i64265(0); it<table.data.length;it++){
			#line 160 f1__ //Expr
			if(OpArray20345(table.data,it).hash){
				#line 161 f1__ //Expr
				i64 hash=Hash70(OpArray20345(table.data,it).key);
				#line 162 f1__ //Expr
				i64 at=((hash%(data.length-1))+1);
				#line 164 f1__ //Expr
				i8 done=false;
				#line 165 f1__ //Expr
				while((!done)){
					#line 167 f1__ //Expr
					if((OpArray20345(data,at).hash==0)){
						#line 169 f1__ //Expr
						OpArray20345(data,at) = OpArray20345(table.data,it);
						#line 170 f1__ //Expr
						done = true;
					}else{
						#line 174 f1__ //Expr
						if(Equal69(OpArray20345(table.data,it).key,OpArray20345(data,at).key)){
							#line 176 f1__ //Expr
							OpArray20345(data,at) = OpArray20345(table.data,it);
							#line 177 f1__ //Expr
							done = true;
						};
						#line 179 f1__ //Expr
						at = ((at+1)%data.length);
					};
				};
			};
		};
		#line 185 f1__ //Expr
		table.data = data;
		#line 186 f1__ //Expr
		table.capacity = (table.capacity*2);
}
void Resize5347(Table29& table){
		#line 154 f1__ //Expr
		DynamicArray811 data={0};
		#line 155 f1__ //Expr
		Init12341(data);
		#line 156 f1__ //Expr
		Resize5342(data,(table.capacity*2));
		#line 158 f1__ //Expr
		for(i64 it = i64265(0); it<table.data.length;it++){
			#line 160 f1__ //Expr
			if(OpArray21348(table.data,it).hash){
				#line 161 f1__ //Expr
				i64 hash=Hash70(OpArray21348(table.data,it).key);
				#line 162 f1__ //Expr
				i64 at=((hash%(data.length-1))+1);
				#line 164 f1__ //Expr
				i8 done=false;
				#line 165 f1__ //Expr
				while((!done)){
					#line 167 f1__ //Expr
					if((OpArray21348(data,at).hash==0)){
						#line 169 f1__ //Expr
						OpArray21348(data,at) = OpArray21348(table.data,it);
						#line 170 f1__ //Expr
						done = true;
					}else{
						#line 174 f1__ //Expr
						if(Equal69(OpArray21348(table.data,it).key,OpArray21348(data,at).key)){
							#line 176 f1__ //Expr
							OpArray21348(data,at) = OpArray21348(table.data,it);
							#line 177 f1__ //Expr
							done = true;
						};
						#line 179 f1__ //Expr
						at = ((at+1)%data.length);
					};
				};
			};
		};
		#line 185 f1__ //Expr
		table.data = data;
		#line 186 f1__ //Expr
		table.capacity = (table.capacity*2);
}
	#line 190 f1__ //Expr
	str53& OpArray0224(Table6220& table,str53 key){
		#line 192 f1__ //Expr
		Assert260((table.capacity!=0),str53{19,(i8*)"Table requires Init"});
		#line 193 f1__ //Expr
		if(((table.length*2.0)>table.capacity)){
			#line 195 f1__ //Expr
			Resize0225(table);
		};
		#line 198 f1__ //Expr
		i64 length=table.capacity;
		#line 199 f1__ //Expr
		i64 hash=Hash70(key);
		#line 200 f1__ //Expr
		i64 at=((hash%(length-1))+1);
		#line 202 f1__ //Expr
		table.length = (table.length+1);
		#line 204 f1__ //Expr
		while(1){
			#line 206 f1__ //Expr
			if((OpArray10228(table.data,at).hash==0)){
				#line 207 f1__ //Expr
				OpArray10228(table.data,at).key = key;
				#line 208 f1__ //Expr
				OpArray10228(table.data,at).hash = 1;
				#line 209 f1__ //Expr
				return OpArray10228(table.data,at).value;
			}else{
				#line 212 f1__ //Expr
				if(Equal69(key,OpArray10228(table.data,at).key)){
					#line 214 f1__ //Expr
					return OpArray10228(table.data,at).value;
				};
				#line 216 f1__ //Expr
				at = ((at+1)%length);
			};
		};
}
i64& OpArray1252(Table321& table,str53 key){
		#line 192 f1__ //Expr
		Assert260((table.capacity!=0),str53{19,(i8*)"Table requires Init"});
		#line 193 f1__ //Expr
		if(((table.length*2.0)>table.capacity)){
			#line 195 f1__ //Expr
			Resize1253(table);
		};
		#line 198 f1__ //Expr
		i64 length=table.capacity;
		#line 199 f1__ //Expr
		i64 hash=Hash70(key);
		#line 200 f1__ //Expr
		i64 at=((hash%(length-1))+1);
		#line 202 f1__ //Expr
		table.length = (table.length+1);
		#line 204 f1__ //Expr
		while(1){
			#line 206 f1__ //Expr
			if((OpArray13254(table.data,at).hash==0)){
				#line 207 f1__ //Expr
				OpArray13254(table.data,at).key = key;
				#line 208 f1__ //Expr
				OpArray13254(table.data,at).hash = 1;
				#line 209 f1__ //Expr
				return OpArray13254(table.data,at).value;
			}else{
				#line 212 f1__ //Expr
				if(Equal69(key,OpArray13254(table.data,at).key)){
					#line 214 f1__ //Expr
					return OpArray13254(table.data,at).value;
				};
				#line 216 f1__ //Expr
				at = ((at+1)%length);
			};
		};
}
InterpAddress237& OpArray2282(Table529& table,Expr366* key){
		#line 192 f1__ //Expr
		Assert260((table.capacity!=0),str53{19,(i8*)"Table requires Init"});
		#line 193 f1__ //Expr
		if(((table.length*2.0)>table.capacity)){
			#line 195 f1__ //Expr
			Resize2283(table);
		};
		#line 198 f1__ //Expr
		i64 length=table.capacity;
		#line 199 f1__ //Expr
		i64 hash=Hash0287(key);
		#line 200 f1__ //Expr
		i64 at=((hash%(length-1))+1);
		#line 202 f1__ //Expr
		table.length = (table.length+1);
		#line 204 f1__ //Expr
		while(1){
			#line 206 f1__ //Expr
			if((OpArray17286(table.data,at).hash==0)){
				#line 207 f1__ //Expr
				OpArray17286(table.data,at).key = key;
				#line 208 f1__ //Expr
				OpArray17286(table.data,at).hash = 1;
				#line 209 f1__ //Expr
				return OpArray17286(table.data,at).value;
			}else{
				#line 212 f1__ //Expr
				if(Equal1288(key,OpArray17286(table.data,at).key)){
					#line 214 f1__ //Expr
					return OpArray17286(table.data,at).value;
				};
				#line 216 f1__ //Expr
				at = ((at+1)%length);
			};
		};
}
DebugFrame209*& OpArray3298(Table425& table,i64 key){
		#line 192 f1__ //Expr
		Assert260((table.capacity!=0),str53{19,(i8*)"Table requires Init"});
		#line 193 f1__ //Expr
		if(((table.length*2.0)>table.capacity)){
			#line 195 f1__ //Expr
			Resize3299(table);
		};
		#line 198 f1__ //Expr
		i64 length=table.capacity;
		#line 199 f1__ //Expr
		i64 hash=Hash75(key);
		#line 200 f1__ //Expr
		i64 at=((hash%(length-1))+1);
		#line 202 f1__ //Expr
		table.length = (table.length+1);
		#line 204 f1__ //Expr
		while(1){
			#line 206 f1__ //Expr
			if((OpArray19300(table.data,at).hash==0)){
				#line 207 f1__ //Expr
				OpArray19300(table.data,at).key = key;
				#line 208 f1__ //Expr
				OpArray19300(table.data,at).hash = 1;
				#line 209 f1__ //Expr
				return OpArray19300(table.data,at).value;
			}else{
				#line 212 f1__ //Expr
				if(Equal73(key,OpArray19300(table.data,at).key)){
					#line 214 f1__ //Expr
					return OpArray19300(table.data,at).value;
				};
				#line 216 f1__ //Expr
				at = ((at+1)%length);
			};
		};
}
Expr366*& OpArray4343(Table15& table,str53 key){
		#line 192 f1__ //Expr
		Assert260((table.capacity!=0),str53{19,(i8*)"Table requires Init"});
		#line 193 f1__ //Expr
		if(((table.length*2.0)>table.capacity)){
			#line 195 f1__ //Expr
			Resize4344(table);
		};
		#line 198 f1__ //Expr
		i64 length=table.capacity;
		#line 199 f1__ //Expr
		i64 hash=Hash70(key);
		#line 200 f1__ //Expr
		i64 at=((hash%(length-1))+1);
		#line 202 f1__ //Expr
		table.length = (table.length+1);
		#line 204 f1__ //Expr
		while(1){
			#line 206 f1__ //Expr
			if((OpArray20345(table.data,at).hash==0)){
				#line 207 f1__ //Expr
				OpArray20345(table.data,at).key = key;
				#line 208 f1__ //Expr
				OpArray20345(table.data,at).hash = 1;
				#line 209 f1__ //Expr
				return OpArray20345(table.data,at).value;
			}else{
				#line 212 f1__ //Expr
				if(Equal69(key,OpArray20345(table.data,at).key)){
					#line 214 f1__ //Expr
					return OpArray20345(table.data,at).value;
				};
				#line 216 f1__ //Expr
				at = ((at+1)%length);
			};
		};
}
TypeFunctions417*& OpArray5346(Table29& table,str53 key){
		#line 192 f1__ //Expr
		Assert260((table.capacity!=0),str53{19,(i8*)"Table requires Init"});
		#line 193 f1__ //Expr
		if(((table.length*2.0)>table.capacity)){
			#line 195 f1__ //Expr
			Resize5347(table);
		};
		#line 198 f1__ //Expr
		i64 length=table.capacity;
		#line 199 f1__ //Expr
		i64 hash=Hash70(key);
		#line 200 f1__ //Expr
		i64 at=((hash%(length-1))+1);
		#line 202 f1__ //Expr
		table.length = (table.length+1);
		#line 204 f1__ //Expr
		while(1){
			#line 206 f1__ //Expr
			if((OpArray21348(table.data,at).hash==0)){
				#line 207 f1__ //Expr
				OpArray21348(table.data,at).key = key;
				#line 208 f1__ //Expr
				OpArray21348(table.data,at).hash = 1;
				#line 209 f1__ //Expr
				return OpArray21348(table.data,at).value;
			}else{
				#line 212 f1__ //Expr
				if(Equal69(key,OpArray21348(table.data,at).key)){
					#line 214 f1__ //Expr
					return OpArray21348(table.data,at).value;
				};
				#line 216 f1__ //Expr
				at = ((at+1)%length);
			};
		};
}
	#line 14 f2__ //Expr
		#line 15 f2__ //Expr
		#line 16 f2__ //Expr
		#line 17 f2__ //Expr
		#line 18 f2__ //Expr
		#line 19 f2__ //Expr
		#line 20 f2__ //Expr
		#line 23 f2__ //Expr
	;
	#line 24 f2__ //Expr
	;
		#line 31 f2__ //Expr
	i32 Char54(str53 char){
		#line 32 f2__ //Expr
		Assert260((char.length==1),str53{24,(i8*)"Exepcted str of length 1"});
		#line 33 f2__ //Expr
		return (*char.chars);
}
	#line 36 f2__ //Expr
	i32 i32FromString55(str53 string){
		#line 37 f2__ //Expr
		return dlStringToI64(string.chars);
}
	#line 39 f2__ //Expr
	i64 i64FromString56(str53 string){
		#line 40 f2__ //Expr
		return dlStringToI64(string.chars);
}
	#line 42 f2__ //Expr
	f64 f64FromString57(str53 string){
		#line 43 f2__ //Expr
		f64 value=dlStringToF64(string.chars);
		#line 44 f2__ //Expr
		return value;
}
	#line 48 f2__ //Expr
	void Print58(str53 string){
		#line 49 f2__ //Expr
		for(i64 it = (i64)0; it<string.length;it++){
			#line 50 f2__ //Expr
			putchar((i32)(*(string.chars+it)));
		};
		#line 52 f2__ //Expr
		FileFlush(FileOut());
}
	#line 55 f2__ //Expr
	void Println59(str53 string){
		#line 56 f2__ //Expr
		Print58(add64(string,str53{1,(i8*)"\n"}));
}
	#line 59 f2__ //Expr
	str53 String60(i8* string){
		#line 60 f2__ //Expr
		str53 out={0};
		#line 61 f2__ //Expr
		out.length = strlen(string);
		#line 62 f2__ //Expr
		out.chars = Alloc19109((out.length+1));
		#line 63 f2__ //Expr
		strcpy(out.chars,string);
		#line 64 f2__ //Expr
		return out;
}
	#line 67 f2__ //Expr
	str53 StringFromChar61(i8 char){
		#line 68 f2__ //Expr
		str53 out={0};
		#line 69 f2__ //Expr
		out.length = 1;
		#line 70 f2__ //Expr
		out.chars = Alloc19109((out.length+1));
		#line 71 f2__ //Expr
		(*out.chars) = char;
		#line 72 f2__ //Expr
		return out;
}
	#line 75 f2__ //Expr
	void Error62(str53 string){
		#line 77 f2__ //Expr
		i8 a=27;
		#line 78 f2__ //Expr
		i8 ab=0;
		#line 80 f2__ //Expr
		Print58(add64(add64(String65((&a),1),str53{4,(i8*)"[31m"}),string));
		#line 81 f2__ //Expr
		Print58(add64(String65((&a),1),str53{4,(i8*)"[0m\n"}));
}
	#line 84 f2__ //Expr
	void Errornl63(str53 string){
		#line 86 f2__ //Expr
		i8 a=27;
		#line 87 f2__ //Expr
		i8 ab=0;
		#line 89 f2__ //Expr
		Print58(add64(add64(String65((&a),1),str53{4,(i8*)"[31m"}),string));
		#line 90 f2__ //Expr
		Print58(add64(String65((&a),1),str53{3,(i8*)"[0m"}));
}
	#line 96 f2__ //Expr
	str53 add64(str53 a,str53 b){
		#line 98 f2__ //Expr
		str53 v={0};
		#line 99 f2__ //Expr
		v.chars = Alloc19109(((a.length+b.length)+1));
		#line 100 f2__ //Expr
		CopyPtr0110(a.chars,v.chars,a.length);
		#line 101 f2__ //Expr
		CopyPtr0110(b.chars,(v.chars+a.length),b.length);
		#line 103 f2__ //Expr
		v.length = (a.length+b.length);
		#line 104 f2__ //Expr
		(*(v.chars+v.length)) = 0;
		#line 105 f2__ //Expr
		return v;
}
	#line 108 f2__ //Expr
	str53 String65(i8* chars,i64 length){
		#line 110 f2__ //Expr
		str53 string={0};
		#line 111 f2__ //Expr
		string.chars = chars;
		#line 112 f2__ //Expr
		string.length = length;
		#line 113 f2__ //Expr
		return string;
}
	#line 116 f2__ //Expr
	str53 String66(i64 number){
		#line 118 f2__ //Expr
		if((number==0)){
			#line 119 f2__ //Expr
			return str53{1,(i8*)"0"};
		};
		#line 122 f2__ //Expr
		i8 negative=0;
		#line 123 f2__ //Expr
		if((number<0)){
			#line 124 f2__ //Expr
			negative = 1;
			#line 125 f2__ //Expr
			number = (0-number);
		};
		#line 128 f2__ //Expr
		i64 n=number;
		#line 129 f2__ //Expr
		i64 count=0;
		#line 130 f2__ //Expr
		while(n){
			#line 131 f2__ //Expr
			n = (n/10);
			#line 132 f2__ //Expr
			count = (count+1);
		};
		#line 135 f2__ //Expr
		Array218 characters={0};
		#line 136 f2__ //Expr
		Init0111(characters,(count+1));
		#line 138 f2__ //Expr
		i64 i={0};
		#line 139 f2__ //Expr
		while(number){
			#line 140 f2__ //Expr
			OpArray0112(characters,((count-i)-1)) = i8295(((number%10)+48));
			#line 141 f2__ //Expr
			number = (number/10);
			#line 142 f2__ //Expr
			i = (i+1);
		};
		#line 145 f2__ //Expr
		OpArray0112(characters,count) = 0;
		#line 146 f2__ //Expr
		str53 r={0};
		#line 147 f2__ //Expr
		r.length = count;
		#line 148 f2__ //Expr
		r.chars = characters.elements;
		#line 150 f2__ //Expr
		if(negative){
			#line 151 f2__ //Expr
			return add64(str53{1,(i8*)"-"},r);
		};
		#line 153 f2__ //Expr
		return r;
}
	#line 156 f2__ //Expr
	str53 String67(f32 number){
		#line 158 f2__ //Expr
		i64 top=i64272(number);
		#line 159 f2__ //Expr
		f32 fnumber=number;
		#line 160 f2__ //Expr
		if((top<0)){
			#line 161 f2__ //Expr
			fnumber = (0.0-fnumber);
		};
		#line 163 f2__ //Expr
		i64 bottom=i64272(((fnumber-f32335(i64272(fnumber)))*1000));
		#line 165 f2__ //Expr
		str53 r=String66(top);
		#line 166 f2__ //Expr
		if(bottom){
			#line 167 f2__ //Expr
			r = add64(add64(r,str53{1,(i8*)"."}),String66(bottom));
		};
		#line 169 f2__ //Expr
		return r;
}
	#line 172 f2__ //Expr
	i64 equal68(str53 l,str53 r){
		#line 174 f2__ //Expr
		return Equal69(l,r);
}
	#line 176 f2__ //Expr
	i64 Equal69(str53 l,str53 r){
		#line 178 f2__ //Expr
		if((l.length!=r.length)){
			#line 180 f2__ //Expr
			return 0;
		};
		#line 183 f2__ //Expr
		for(i64 it = i64265(0); it<l.length;it++){
			#line 185 f2__ //Expr
			i8 ll=(*(l.chars+it));
			#line 186 f2__ //Expr
			i8 rr=(*(r.chars+it));
			#line 187 f2__ //Expr
			if((i64269(ll)!=i64269(rr))){
				#line 189 f2__ //Expr
				return 0;
			};
		};
		#line 192 f2__ //Expr
		return 1;
}
	#line 195 f2__ //Expr
	i64 Hash70(str53 string){
		#line 197 f2__ //Expr
		i64 hash=5381;
		#line 198 f2__ //Expr
		for(i64 it = i64265(0); it<string.length;it++){
			#line 200 f2__ //Expr
			hash = (((hash+5)+hash)+i64269((*(string.chars+it))));
		};
		#line 202 f2__ //Expr
		return hash;
}
	#line 206 f2__ //Expr
	i8 equal0199(Type413* l,Type413* r){
		#line 208 f2__ //Expr
		return ((i64)l==(i64)r);
}
i8 equal1202(TypeTrait429* l,TypeTrait429* r){
		#line 208 f2__ //Expr
		return ((i64)l==(i64)r);
}
i8 equal2204(TypeStructure481* l,TypeStructure481* r){
		#line 208 f2__ //Expr
		return ((i64)l==(i64)r);
}
i8 equal3219(Function456* l,Function456* r){
		#line 208 f2__ //Expr
		return ((i64)l==(i64)r);
}
i8 equal4232(Structure473* l,Structure473* r){
		#line 208 f2__ //Expr
		return ((i64)l==(i64)r);
}
	#line 211 f2__ //Expr
	i64 Equal0205(TypeNumber431* l,TypeNumber431* r){
		#line 213 f2__ //Expr
		return ((i64)l==(i64)r);
}
i64 Equal1288(Expr366* l,Expr366* r){
		#line 213 f2__ //Expr
		return ((i64)l==(i64)r);
}
i64 Equal2353(Type413* l,Type413* r){
		#line 213 f2__ //Expr
		return ((i64)l==(i64)r);
}
	#line 216 f2__ //Expr
	i64 Equal73(i64 l,i64 r){
		#line 218 f2__ //Expr
		return ((i64)l==(i64)r);
}
	#line 221 f2__ //Expr
	i64 Hash0287(Expr366* p){
		#line 223 f2__ //Expr
		return (i64)p;
}
	#line 226 f2__ //Expr
	i64 Hash75(i64 p){
		#line 228 f2__ //Expr
		return p;
}
				#line 36 f3__ //Expr
	;
	#line 37 f3__ //Expr
	;
	#line 39 f3__ //Expr
	;
	#line 40 f3__ //Expr
	;
	#line 42 f3__ //Expr
	;
	#line 43 f3__ //Expr
	;
	#line 45 f3__ //Expr
	;
	#line 46 f3__ //Expr
	;
	#line 47 f3__ //Expr
	;
	#line 48 f3__ //Expr
	;
	#line 49 f3__ //Expr
	;
	#line 51 f3__ //Expr
	;
	#line 52 f3__ //Expr
	;
	#line 53 f3__ //Expr
	;
	#line 54 f3__ //Expr
	;
	#line 56 f3__ //Expr
	;
	#line 57 f3__ //Expr
	;
	#line 59 f3__ //Expr
	;
	#line 60 f3__ //Expr
	;
	#line 61 f3__ //Expr
	;
	#line 62 f3__ //Expr
	;
	#line 63 f3__ //Expr
	;
	#line 65 f3__ //Expr
	;
	#line 67 f3__ //Expr
	;
	#line 68 f3__ //Expr
	;
	#line 69 f3__ //Expr
	;
	#line 72 f3__ //Expr
	;
	#line 74 f3__ //Expr
	;
	#line 75 f3__ //Expr
	;
	#line 76 f3__ //Expr
	;
	#line 79 f3__ //Expr
	;
	#line 80 f3__ //Expr
	;
	#line 81 f3__ //Expr
	;
	#line 82 f3__ //Expr
	;
	#line 83 f3__ //Expr
	;
	#line 84 f3__ //Expr
	;
	#line 85 f3__ //Expr
	;
	#line 86 f3__ //Expr
	;
	#line 88 f3__ //Expr
	;
	#line 90 f3__ //Expr
	;
	#line 91 f3__ //Expr
	;
	#line 92 f3__ //Expr
	;
	#line 94 f3__ //Expr
	str53 TokenString79(i32 token){
		#line 95 f3__ //Expr
		if((token==kNumber)){
			#line 96 f3__ //Expr
			return str53{6,(i8*)"number"};
		};
		#line 98 f3__ //Expr
		if((token==kStruct)){
			#line 99 f3__ //Expr
			return str53{6,(i8*)"struct"};
		};
		#line 101 f3__ //Expr
		if((token==kIdentifier)){
			#line 102 f3__ //Expr
			return str53{10,(i8*)"identifier"};
		};
		#line 104 f3__ //Expr
		if((token==kString)){
			#line 105 f3__ //Expr
			return str53{6,(i8*)"string"};
		};
		#line 107 f3__ //Expr
		if((token==kRef)){
			#line 108 f3__ //Expr
			return str53{3,(i8*)"ref"};
		};
		#line 110 f3__ //Expr
		if((token==kTrait)){
			#line 111 f3__ //Expr
			return str53{5,(i8*)"trait"};
		};
		#line 113 f3__ //Expr
		if((token==kEndLine)){
			#line 114 f3__ //Expr
			return str53{11,(i8*)"end of line"};
		};
		#line 116 f3__ //Expr
		return StringFromChar61(i8294(token));
}
	#line 119 f3__ //Expr
	i8 equal80(Token77 token,i64 kind){
		#line 120 f3__ //Expr
		return (token.Type==kind);
}
	#line 122 f3__ //Expr
	i8 notEqual81(Token77 token,i64 kind){
		#line 123 f3__ //Expr
		return (token.Type!=kind);
}
	#line 126 f3__ //Expr
	Lexer78 Lexer82(str53 file,i64 fileNumber){
		#line 128 f3__ //Expr
		Lexer78 self={0};
		#line 129 f3__ //Expr
		self.currentLine = 1;
		#line 130 f3__ //Expr
		self.currentColumn = 0;
		#line 131 f3__ //Expr
		self.currentFile = fileNumber;
		#line 133 f3__ //Expr
		self.file = FileOpen(file.chars,str53{1,(i8*)"r"}.chars);
		#line 136 f3__ //Expr
		if((!self.file)){
			#line 137 f3__ //Expr
			Print58(add64(add64(str53{21,(i8*)"Failed to open file \'"},file),str53{1,(i8*)"\'"}));
			#line 138 f3__ //Expr
			return self;
		};
		#line 141 f3__ //Expr
		self.data = Alloc19109(100000);
		#line 142 f3__ //Expr
		u64 newLen=FileRead(self.data,1,100000,self.file);
		#line 144 f3__ //Expr
		Token77 token=Next93(self);
		#line 145 f3__ //Expr
		while(((token.Type!=0)&&(token.Type!=(-1)))){
			#line 147 f3__ //Expr
			Push4113(self.tokens,token);
			#line 148 f3__ //Expr
			token = Next93(self);
		};
		#line 151 f3__ //Expr
		Token77 none={0};
		#line 152 f3__ //Expr
		Push4113(self.tokens,none);
		#line 153 f3__ //Expr
		Push4113(self.tokens,none);
		#line 154 f3__ //Expr
		Push4113(self.tokens,none);
		#line 155 f3__ //Expr
		return self;
}
	#line 160 f3__ //Expr
	i32 Peek83(Lexer78& self){
		#line 162 f3__ //Expr
		return (*(self.data+self.dataIndex));
}
	#line 164 f3__ //Expr
	i32 Peek84(Lexer78& self,i64 at){
		#line 166 f3__ //Expr
		return (*((self.data+self.dataIndex)+at));
}
	#line 168 f3__ //Expr
	i32 Get85(Lexer78& self){
		#line 171 f3__ //Expr
		i32 character=Peek83(self);
		#line 172 f3__ //Expr
		self.dataIndex = (self.dataIndex+1);
		#line 173 f3__ //Expr
		self.currentColumn = (self.currentColumn+1);
		#line 174 f3__ //Expr
		return character;
}
	#line 179 f3__ //Expr
		#line 180 f3__ //Expr
		#line 181 f3__ //Expr
		#line 182 f3__ //Expr
		#line 185 f3__ //Expr
	Token77 At90(Lexer78& self,i64 i){
		#line 187 f3__ //Expr
		return OpArray3115(self.tokens,(self.at+i));
}
	#line 189 f3__ //Expr
	void Eat91(Lexer78& self){
		#line 190 f3__ //Expr
		self.at = (self.at+1);
}
	#line 192 f3__ //Expr
	void Eat92(Lexer78& self,i64 count){
		#line 193 f3__ //Expr
		self.at = (self.at+count);
}
	#line 196 f3__ //Expr
	Token77 Next93(Lexer78& self){
		#line 198 f3__ //Expr
		i8 insertNewLine={0};
		#line 199 f3__ //Expr
		while(isspace(Peek83(self))){
			#line 201 f3__ //Expr
			if((Get85(self)==Char54(str53{1,(i8*)"\n"}))){
				#line 203 f3__ //Expr
				self.currentLine = (self.currentLine+1);
				#line 204 f3__ //Expr
				self.currentColumn = 0;
				#line 205 f3__ //Expr
				insertNewLine = 1;
			};
		};
		#line 209 f3__ //Expr
		if((((insertNewLine&&(self.tokens.length>0))&&(Peek83(self)!=Char54(str53{1,(i8*)"{"})))&&(Peek83(self)!=Char54(str53{1,(i8*)"}"})))){
			#line 211 f3__ //Expr
			i32 t=OpArray3115(self.tokens,(self.tokens.length-1)).Type;
			#line 212 f3__ //Expr
			if(((((((t==kParenClose)||(t==kBraceClose))||(t==kIdentifier))||(t==kNumber))||(t==kString))||((t>=kKeywordsBegin)&&(t<kKeywordsEnd)))){
				#line 214 f3__ //Expr
				Token77 t={0};
				#line 215 f3__ //Expr
				t.Type = kEndLine;
				#line 216 f3__ //Expr
				t.at.line = i32279(self.currentLine);
				#line 217 f3__ //Expr
				t.at.file = i16287(self.currentFile);
				#line 218 f3__ //Expr
				t.at.column = i16287(self.currentColumn);
				#line 219 f3__ //Expr
				Push4113(self.tokens,t);
			};
		};
		#line 225 f3__ //Expr
		if((isalpha(Peek83(self))||(Peek83(self)==Char54(str53{1,(i8*)"_"})))){
			#line 227 f3__ //Expr
			Token77 t={0};
			#line 228 f3__ //Expr
			t.at.line = i32279(self.currentLine);
			#line 229 f3__ //Expr
			t.at.file = i16287(self.currentFile);
			#line 230 f3__ //Expr
			t.at.column = i16287(self.currentColumn);
			#line 232 f3__ //Expr
			DynamicArray23116 data={0};
			#line 233 f3__ //Expr
			Init0117(data);
			#line 234 f3__ //Expr
			while((isalnum(Peek83(self))||(Peek83(self)==Char54(str53{1,(i8*)"_"})))){
				#line 235 f3__ //Expr
				Push5118(data,i8294(Get85(self)));
			};
			#line 237 f3__ //Expr
			Push5118(data,0);
			#line 240 f3__ //Expr
			t.Type = kIdentifier;
			#line 241 f3__ //Expr
			t.value.chars = data.elements;
			#line 242 f3__ //Expr
			t.value.length = (data.length-1);
			#line 244 f3__ //Expr
			if(Equal69(t.value,str53{6,(i8*)"struct"})){
				#line 244 f3__ //Expr
				t.Type = kStruct;
			}else{
				#line 245 f3__ //Expr
				if(Equal69(t.value,str53{2,(i8*)"fn"})){
					#line 245 f3__ //Expr
					t.Type = kFunction;
				}else{
					#line 246 f3__ //Expr
					if(Equal69(t.value,str53{3,(i8*)"ref"})){
						#line 246 f3__ //Expr
						t.Type = kRef;
					}else{
						#line 248 f3__ //Expr
						if(Equal69(t.value,str53{5,(i8*)"trait"})){
							#line 248 f3__ //Expr
							t.Type = kTrait;
						}else{
							#line 249 f3__ //Expr
							if(Equal69(t.value,str53{7,(i8*)"require"})){
								#line 249 f3__ //Expr
								t.Type = kRequire;
							}else{
								#line 250 f3__ //Expr
								if(Equal69(t.value,str53{3,(i8*)"for"})){
									#line 250 f3__ //Expr
									t.Type = kFor;
								}else{
									#line 251 f3__ //Expr
									if(Equal69(t.value,str53{5,(i8*)"break"})){
										#line 251 f3__ //Expr
										t.Type = kBreak;
									}else{
										#line 252 f3__ //Expr
										if(Equal69(t.value,str53{8,(i8*)"continue"})){
											#line 252 f3__ //Expr
											t.Type = kContinue;
										}else{
											#line 253 f3__ //Expr
											if(Equal69(t.value,str53{2,(i8*)"if"})){
												#line 253 f3__ //Expr
												t.Type = kIf;
											}else{
												#line 254 f3__ //Expr
												if(Equal69(t.value,str53{4,(i8*)"else"})){
													#line 254 f3__ //Expr
													t.Type = kElse;
												}else{
													#line 255 f3__ //Expr
													if(Equal69(t.value,str53{6,(i8*)"return"})){
														#line 255 f3__ //Expr
														t.Type = kReturn;
													};
												};
											};
										};
									};
								};
							};
						};
					};
				};
			};
			#line 256 f3__ //Expr
			return t;
		};
		#line 259 f3__ //Expr
		if(isdigit(Peek83(self))){
			#line 262 f3__ //Expr
			DynamicArray23116 data={0};
			#line 263 f3__ //Expr
			Init0117(data);
			#line 265 f3__ //Expr
			if(((Peek83(self)==Char54(str53{1,(i8*)"0"}))&&(Peek84(self,1)==Char54(str53{1,(i8*)"x"})))){
				#line 266 f3__ //Expr
				Push5118(data,i8294(Get85(self)));
				#line 267 f3__ //Expr
				Push5118(data,i8294(Get85(self)));
				#line 269 f3__ //Expr
				while(((((((isdigit(Peek83(self))||(Peek83(self)==Char54(str53{1,(i8*)"A"})))||(Peek83(self)==Char54(str53{1,(i8*)"B"})))||(Peek83(self)==Char54(str53{1,(i8*)"C"})))||(Peek83(self)==Char54(str53{1,(i8*)"D"})))||(Peek83(self)==Char54(str53{1,(i8*)"E"})))||(Peek83(self)==Char54(str53{1,(i8*)"F"})))){
					#line 277 f3__ //Expr
					Push5118(data,i8294(Get85(self)));
				};
			}else{
				#line 282 f3__ //Expr
				while(isdigit(Peek83(self))){
					#line 284 f3__ //Expr
					Push5118(data,i8294(Get85(self)));
				};
				#line 286 f3__ //Expr
				if(((Peek83(self)==Char54(str53{1,(i8*)"."}))&&isdigit(Peek84(self,1)))){
					#line 288 f3__ //Expr
					Push5118(data,i8294(Get85(self)));
					#line 289 f3__ //Expr
					while(isdigit(Peek83(self))){
						#line 290 f3__ //Expr
						Push5118(data,i8294(Get85(self)));
					};
				};
			};
			#line 296 f3__ //Expr
			Push5118(data,0);
			#line 298 f3__ //Expr
			Token77 t={0};
			#line 299 f3__ //Expr
			t.Type = kNumber;
			#line 300 f3__ //Expr
			t.value.chars = data.elements;
			#line 301 f3__ //Expr
			t.value.length = (data.length-1);
			#line 302 f3__ //Expr
			t.at.line = i32279(self.currentLine);
			#line 303 f3__ //Expr
			t.at.file = i16287(self.currentFile);
			#line 304 f3__ //Expr
			t.at.column = i16287(self.currentColumn);
			#line 305 f3__ //Expr
			return t;
		};
		#line 307 f3__ //Expr
		if((Peek83(self)==Char54(str53{1,(i8*)"\'"}))){
			#line 309 f3__ //Expr
			Get85(self);
			#line 311 f3__ //Expr
			DynamicArray23116 data={0};
			#line 312 f3__ //Expr
			Init0117(data);
			#line 314 f3__ //Expr
			while((Peek83(self)!=Char54(str53{1,(i8*)"\'"}))){
				#line 315 f3__ //Expr
				i32 char=Get85(self);
				#line 316 f3__ //Expr
				if((char==92)){
					#line 317 f3__ //Expr
					i32 next=Get85(self);
					#line 318 f3__ //Expr
					if((next==Char54(str53{1,(i8*)"t"}))){
						#line 319 f3__ //Expr
						Push5118(data,i8290(9));
					}else{
						#line 321 f3__ //Expr
						if((next==39)){
							#line 322 f3__ //Expr
							Push5118(data,i8290(39));
						}else{
							#line 324 f3__ //Expr
							if((next==Char54(str53{1,(i8*)"n"}))){
								#line 325 f3__ //Expr
								Push5118(data,i8294(Char54(str53{1,(i8*)"\n"})));
							}else{
								#line 327 f3__ //Expr
								if((next==Char54(str53{1,(i8*)"0"}))){
									#line 328 f3__ //Expr
									Push5118(data,i8290(0));
								}else{
									#line 330 f3__ //Expr
									if((next==92)){
										#line 331 f3__ //Expr
										Push5118(data,i8290(92));
									};
								};
							};
						};
					};
				}else{
					#line 335 f3__ //Expr
					Push5118(data,char);
				};
			};
			#line 339 f3__ //Expr
			Push5118(data,0);
			#line 340 f3__ //Expr
			Get85(self);
			#line 342 f3__ //Expr
			Token77 t={0};
			#line 343 f3__ //Expr
			t.Type = kString;
			#line 344 f3__ //Expr
			t.value.chars = data.elements;
			#line 345 f3__ //Expr
			t.value.length = (data.length-1);
			#line 346 f3__ //Expr
			t.at.line = i32279(self.currentLine);
			#line 347 f3__ //Expr
			t.at.file = i16287(self.currentFile);
			#line 348 f3__ //Expr
			t.at.column = i16287(self.currentColumn);
			#line 349 f3__ //Expr
			return t;
		};
		#line 351 f3__ //Expr
		Token77 t={0};
		#line 352 f3__ //Expr
		t.Type = Get85(self);
		#line 354 f3__ //Expr
		if(((t.Type==Char54(str53{1,(i8*)"/"}))&&(Peek83(self)==Char54(str53{1,(i8*)"/"})))){
			#line 355 f3__ //Expr
			Get85(self);
			#line 356 f3__ //Expr
			while(((Peek83(self)!=Char54(str53{1,(i8*)"\n"}))&&(Peek83(self)!=0))){
				#line 357 f3__ //Expr
				Get85(self);
			};
			#line 359 f3__ //Expr
			return Next93(self);
		};
		#line 362 f3__ //Expr
		i8* chars=Alloc19109(2);
		#line 363 f3__ //Expr
		(*(chars+0)) = i8294(t.Type);
		#line 364 f3__ //Expr
		(*(chars+1)) = 0;
		#line 365 f3__ //Expr
		t.value = String60(chars);
		#line 366 f3__ //Expr
		t.at.line = i32279(self.currentLine);
		#line 367 f3__ //Expr
		t.at.file = i16287(self.currentFile);
		#line 368 f3__ //Expr
		t.at.column = i16287(self.currentColumn);
		#line 369 f3__ //Expr
		return t;
}
		#line 8 f4__ //Expr
	void PrintIndent95(PrintVisitor94& visitor){
		#line 10 f4__ //Expr
		for(i64 it = i64265(1); it<visitor.indent;it++){
			#line 11 f4__ //Expr
			Print58(str53{1,(i8*)"\t"});
		};
}
	#line 15 f4__ //Expr
	void Print96(Expr366& expr){
		#line 16 f4__ //Expr
		PrintVisitor94 printer={0};
		#line 17 f4__ //Expr
		Visit100(expr,printer);
}
	#line 20 f4__ //Expr
	void Print97(Type413& expr){
		#line 21 f4__ //Expr
		PrintVisitor94 printer={0};
		#line 22 f4__ //Expr
		Visit101(expr,printer);
}
	#line 25 f4__ //Expr
	void Print98(Type413* expr){
		#line 26 f4__ //Expr
		if((!expr)){
			#line 27 f4__ //Expr
			Print58(str53{2,(i8*)"()"});
			#line 28 f4__ //Expr
			return ;
		};
		#line 31 f4__ //Expr
		PrintVisitor94 printer={0};
		#line 32 f4__ //Expr
		Visit101((*expr),printer);
}
	#line 35 f4__ //Expr
		#line 44 f4__ //Expr
	void Visit100(Expr366& expr,PrintVisitor94& visitor){
		#line 46 f4__ //Expr
		if(Is1120(expr)){
			#line 47 f4__ //Expr
			Block434* self=As1121(expr);
			#line 48 f4__ //Expr
			if(visitor.indent){
				#line 49 f4__ //Expr
				Println59(str53{1,(i8*)"{"});
			};
			#line 51 f4__ //Expr
			visitor.indent = (visitor.indent+1);
			#line 53 f4__ //Expr
			for(i64 it = i64265(0); it<(*self).expressions.length;it++){
				#line 55 f4__ //Expr
				PrintIndent95(visitor);
				#line 56 f4__ //Expr
				Visit100((*OpArray4122((*self).expressions,it)),visitor);
				#line 57 f4__ //Expr
				Println59(str53{0,(i8*)""});
			};
			#line 59 f4__ //Expr
			visitor.indent = (visitor.indent-1);
			#line 61 f4__ //Expr
			if(visitor.indent){
				#line 62 f4__ //Expr
				Println59(str53{1,(i8*)"}"});
			};
			#line 64 f4__ //Expr
			return ;
		};
		#line 67 f4__ //Expr
		if(Is2123(expr)){
			#line 68 f4__ //Expr
			Structure473* self=As2124(expr);
			#line 69 f4__ //Expr
			Print58((*self).ident);
			#line 70 f4__ //Expr
			Print58(str53{7,(i8*)" struct"});
			#line 71 f4__ //Expr
			if((!(*self).incomplete)){
				#line 72 f4__ //Expr
				Println59(str53{2,(i8*)" {"});
				#line 73 f4__ //Expr
				visitor.indent = (visitor.indent+1);
				#line 74 f4__ //Expr
				for(i64 it = i64265(0); it<(*self).fields.length;it++){
					#line 75 f4__ //Expr
					PrintIndent95(visitor);
					#line 76 f4__ //Expr
					Print58((*OpArray5125((*self).fields,it)).ident);
					#line 77 f4__ //Expr
					Print58(str53{1,(i8*)" "});
					#line 78 f4__ //Expr
					Visit101((*(*OpArray5125((*self).fields,it)).super.typ),visitor);
					#line 79 f4__ //Expr
					Println59(str53{0,(i8*)""});
				};
				#line 81 f4__ //Expr
				visitor.indent = (visitor.indent-1);
				#line 82 f4__ //Expr
				Println59(str53{1,(i8*)"}"});
			}else{
				#line 86 f4__ //Expr
				Println59(str53{0,(i8*)""});
			};
			#line 88 f4__ //Expr
			return ;
		};
		#line 91 f4__ //Expr
		if(Is3126(expr)){
			#line 92 f4__ //Expr
			Function456* self=As3127(expr);
			#line 93 f4__ //Expr
			Print58((*self).ident);
			#line 94 f4__ //Expr
			Print58(str53{4,(i8*)" fn "});
			#line 95 f4__ //Expr
			Print96((*self).params.super);
			#line 96 f4__ //Expr
			Print58(str53{1,(i8*)" "});
			#line 97 f4__ //Expr
			Print98((*self).result);
			#line 102 f4__ //Expr
			return ;
		};
		#line 105 f4__ //Expr
		if(Is4128(expr)){
			#line 106 f4__ //Expr
			Identifier495* self=As4129(expr);
			#line 107 f4__ //Expr
			Print58((*self).ident);
			#line 108 f4__ //Expr
			return ;
		};
		#line 111 f4__ //Expr
		if(Is5130(expr)){
			#line 112 f4__ //Expr
			Call442* self=As5131(expr);
			#line 113 f4__ //Expr
			Visit100((*(*self).operand),visitor);
			#line 114 f4__ //Expr
			Visit100((*self).params.super,visitor);
			#line 115 f4__ //Expr
			return ;
		};
		#line 117 f4__ //Expr
		if(Is6132(expr)){
			#line 118 f4__ //Expr
			Access445* self=As6133(expr);
			#line 119 f4__ //Expr
			Visit100((*(*self).operand),visitor);
			#line 120 f4__ //Expr
			Print58(str53{1,(i8*)"."});
			#line 121 f4__ //Expr
			Print58((*self).field);
			#line 122 f4__ //Expr
			return ;
		};
		#line 125 f4__ //Expr
		if(Is061(expr)){
			#line 126 f4__ //Expr
			ExpressionList369* self=As066(expr);
			#line 127 f4__ //Expr
			Print58(str53{1,(i8*)"("});
			#line 128 f4__ //Expr
			for(i64 it = i64265(0); it<(*self).list.length;it++){
				#line 129 f4__ //Expr
				Visit100((*OpArray4122((*self).list,it)),visitor);
				#line 130 f4__ //Expr
				if((it!=((*self).list.length-1))){
					#line 131 f4__ //Expr
					Print58(str53{2,(i8*)", "});
				};
			};
			#line 134 f4__ //Expr
			Print58(str53{1,(i8*)")"});
			#line 135 f4__ //Expr
			return ;
		};
		#line 139 f4__ //Expr
		if(Is7134(expr)){
			#line 140 f4__ //Expr
			Variable498* self=As7135(expr);
			#line 141 f4__ //Expr
			Print58((*self).ident);
			#line 142 f4__ //Expr
			Print58(str53{1,(i8*)" "});
			#line 143 f4__ //Expr
			Visit101((*expr.typ),visitor);
			#line 144 f4__ //Expr
			return ;
		};
		#line 147 f4__ //Expr
		if(Is8136(expr)){
			#line 148 f4__ //Expr
			Trait490* self=As8137(expr);
			#line 149 f4__ //Expr
			Print58((*self).ident);
			#line 150 f4__ //Expr
			Print58(str53{6,(i8*)" trait"});
			#line 151 f4__ //Expr
			visitor.indent = (visitor.indent+1);
			#line 152 f4__ //Expr
			Println59(str53{2,(i8*)" {"});
			#line 154 f4__ //Expr
			visitor.indent = (visitor.indent-1);
			#line 155 f4__ //Expr
			Println59(str53{1,(i8*)"}"});
			#line 156 f4__ //Expr
			return ;
		};
		#line 158 f4__ //Expr
		Println59(str53{26,(i8*)"Unhandled print expr visit"});
}
	#line 161 f4__ //Expr
	void Visit101(Type413& t,PrintVisitor94& visitor){
		#line 163 f4__ //Expr
		Type413* expr=(&t);
		#line 164 f4__ //Expr
		Print58(String107(t));
}
	#line 167 f4__ //Expr
	void PrettyPrint102(Type413* expr){
		#line 169 f4__ //Expr
		if((!expr)){
			#line 170 f4__ //Expr
			Print58(str53{2,(i8*)"()"});
		}else{
			#line 173 f4__ //Expr
			PrettyPrint104((*expr));
		};
}
	#line 177 f4__ //Expr
	void PrettyPrint103(Expr366& expr){
		#line 179 f4__ //Expr
		if(Is2123(expr)){
			#line 180 f4__ //Expr
			Structure473* self=As2124(expr);
			#line 181 f4__ //Expr
			Print58((*self).ident);
			#line 182 f4__ //Expr
			return ;
		};
		#line 185 f4__ //Expr
		if(Is3126(expr)){
			#line 186 f4__ //Expr
			Function456* self=As3127(expr);
			#line 187 f4__ //Expr
			Print58((*self).ident);
			#line 188 f4__ //Expr
			return ;
		};
		#line 190 f4__ //Expr
		if(Is9138(expr)){
			#line 191 f4__ //Expr
			TypeAs367* self=As9139(expr);
			#line 192 f4__ //Expr
			PrettyPrint102((*self).super.typ);
			#line 193 f4__ //Expr
			return ;
		};
		#line 195 f4__ //Expr
		if(Is8136(expr)){
			#line 196 f4__ //Expr
			Trait490* self=As8137(expr);
			#line 197 f4__ //Expr
			Print58(str53{4,(i8*)"huh?"});
			#line 198 f4__ //Expr
			return ;
		};
		#line 201 f4__ //Expr
		Print58(add64(str53{5,(i8*)"none "},String66(expr.kind)));
}
	#line 204 f4__ //Expr
	void PrettyPrint104(Type413& expr){
		#line 206 f4__ //Expr
		Print58(String107(expr));
}
	#line 209 f4__ //Expr
	str53 String105(Type413* expr){
		#line 211 f4__ //Expr
		if((!expr)){
			#line 212 f4__ //Expr
			return str53{2,(i8*)"()"};
		}else{
			#line 215 f4__ //Expr
			return String107((*expr));
		};
}
	#line 219 f4__ //Expr
	str53 String106(Expr366& expr){
		#line 221 f4__ //Expr
		if(Is2123(expr)){
			#line 222 f4__ //Expr
			Structure473* self=As2124(expr);
			#line 223 f4__ //Expr
			return (*self).ident;
		};
		#line 226 f4__ //Expr
		if(Is3126(expr)){
			#line 227 f4__ //Expr
			Function456* self=As3127(expr);
			#line 228 f4__ //Expr
			return (*self).ident;
		};
		#line 230 f4__ //Expr
		if(Is9138(expr)){
			#line 231 f4__ //Expr
			TypeAs367* self=As9139(expr);
			#line 233 f4__ //Expr
			return add64(str53{2,(i8*)"as"},String105((*self).super.typ));
		};
		#line 235 f4__ //Expr
		if(Is8136(expr)){
			#line 236 f4__ //Expr
			Trait490* self=As8137(expr);
			#line 237 f4__ //Expr
			return add64(str53{1,(i8*)"$"},(*self).ident);
		};
		#line 239 f4__ //Expr
		return add64(str53{5,(i8*)"none "},String66(expr.kind));
}
	#line 242 f4__ //Expr
	str53 String107(Type413& expr){
		#line 244 f4__ //Expr
		Assert2140((&expr),str53{9,(i8*)"nil value"});
		#line 245 f4__ //Expr
		if(Is0141(expr)){
			#line 246 f4__ //Expr
			TypeRef419* self=As0142(expr);
			#line 247 f4__ //Expr
			return add64(str53{4,(i8*)"ref "},String107((*(*self).reference)));
		};
		#line 249 f4__ //Expr
		if(Is1143(expr)){
			#line 250 f4__ //Expr
			TypeIdentifier414* self=As1144(expr);
			#line 251 f4__ //Expr
			if((*self).spec){
				#line 252 f4__ //Expr
				return String106((*(*self).spec));
			}else{
				#line 256 f4__ //Expr
				return add64(add64(str53{8,(i8*)"untyped<"},(*self).ident),str53{1,(i8*)">"});
			};
		};
		#line 259 f4__ //Expr
		if(Is2145(expr)){
			#line 260 f4__ //Expr
			TypeAny425* self=As2146(expr);
			#line 261 f4__ //Expr
			if((*self).reference){
				#line 262 f4__ //Expr
				return add64(add64(add64(str53{1,(i8*)"$"},(*self).ident),str53{2,(i8*)"->"}),String107((*(*self).reference)));
			};
			#line 264 f4__ //Expr
			return add64(add64(str53{1,(i8*)"$"},(*self).ident),String66((i64)self));
		};
		#line 266 f4__ //Expr
		if(Is3147(expr)){
			#line 267 f4__ //Expr
			TypeTrait429* self=As3148(expr);
			#line 268 f4__ //Expr
			if((*self).reference){
				#line 269 f4__ //Expr
				return add64(add64(add64(str53{1,(i8*)"$"},(*(*self).trai).ident),str53{2,(i8*)"->"}),String107((*(*self).reference)));
			};
			#line 271 f4__ //Expr
			return add64(str53{1,(i8*)"$"},(*(*self).trai).ident);
		};
		#line 273 f4__ //Expr
		if(Is4149(expr)){
			#line 274 f4__ //Expr
			TypeOption421* self=As4150(expr);
			#line 275 f4__ //Expr
			Assert2140((*self).reference,str53{11,(i8*)"Require ref"});
			#line 277 f4__ //Expr
			str53 value={0};
			#line 278 f4__ //Expr
			if(Is0141((*Resolved127((*(*self).reference))))){
				#line 279 f4__ //Expr
				return add64(str53{5,(i8*)"ref? "},String107((*(*As0142((*Resolved127((*(*self).reference))))).reference)));
			}else{
				#line 283 f4__ //Expr
				return add64(String107((*(*self).reference)),str53{1,(i8*)"?"});
			};
		};
		#line 287 f4__ //Expr
		if(Is5151(expr)){
			#line 288 f4__ //Expr
			TypeType427* self=As5152(expr);
			#line 289 f4__ //Expr
			Print58(str53{7,(i8*)"typeof "});
			#line 290 f4__ //Expr
			return add64(str53{7,(i8*)"type of"},String105((*self).reference));
		};
		#line 292 f4__ //Expr
		if(Is6153(expr)){
			#line 293 f4__ //Expr
			TypeGeneric423* self=As6154(expr);
			#line 294 f4__ //Expr
			str53 value=add64(add64(add64(String107((*(*self).ident).super),str53{2,(i8*)"->"}),String66((i64)(*self).spec)),str53{1,(i8*)"("});
			#line 295 f4__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 296 f4__ //Expr
				value = add64(value,String107((*OpArray6155((*self).constraints,it))));
				#line 297 f4__ //Expr
				if((it!=((*self).constraints.length-1))){
					#line 298 f4__ //Expr
					value = add64(value,str53{2,(i8*)", "});
				};
			};
			#line 301 f4__ //Expr
			return add64(value,str53{1,(i8*)")"});
		};
		#line 303 f4__ //Expr
		if(Is7156(expr)){
			#line 304 f4__ //Expr
			TypeNumber431* self=As7157(expr);
			#line 305 f4__ //Expr
			if(((*self).kind==TypeNumberInteger)){
				#line 306 f4__ //Expr
				return add64(str53{1,(i8*)"i"},String66(((*self).size*8)));
			}else{
				#line 308 f4__ //Expr
				if(((*self).kind==TypeNumberUnsigned)){
					#line 309 f4__ //Expr
					return add64(str53{1,(i8*)"u"},String66(((*self).size*8)));
				}else{
					#line 311 f4__ //Expr
					if(((*self).kind==TypeNumberFloat)){
						#line 312 f4__ //Expr
						return add64(str53{1,(i8*)"f"},String66(((*self).size*8)));
					}else{
						#line 315 f4__ //Expr
						Assert261(0);
					};
				};
			};
			#line 317 f4__ //Expr
			return str53{0,(i8*)""};
		};
		#line 319 f4__ //Expr
		Println59(str53{20,(i8*)"Unhandled type visit"});
		#line 320 f4__ //Expr
		return str53{0,(i8*)""};
}
	#line 9 f5__ //Expr
	void Error108(Expr366& node,str53 message){
		#line 10 f5__ //Expr
		PrintError25(node.at,message);
		#line 11 f5__ //Expr
		Assert261(0);
}
	#line 13 f5__ //Expr
	void Error109(Position76 at,str53 message){
		#line 14 f5__ //Expr
		PrintError25(at,message);
		#line 15 f5__ //Expr
		Assert261(0);
}
		#line 26 f5__ //Expr
	void Init111(Semantic110& semantic,Block434& ast){
		#line 28 f5__ //Expr
		Push6158(semantic.scopes,(&ast));
		#line 30 f5__ //Expr
		Init138(semantic.intrinsic,semantic,ast);
		#line 32 f5__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 33 f5__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 34 f5__ //Expr
			Declare119(semantic,(*expr));
		};
		#line 38 f5__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 39 f5__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 40 f5__ //Expr
			if(Is2123((*expr))){
				#line 41 f5__ //Expr
				Visit122(semantic,(*expr));
			}else{
				#line 45 f5__ //Expr
				if(Is7134((*expr))){
					#line 46 f5__ //Expr
					(*As7135((*expr))).global = true;
				};
			};
		};
		#line 50 f5__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 51 f5__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 52 f5__ //Expr
			if(Is3126((*expr))){
				#line 53 f5__ //Expr
				Function456* self=As3127((*expr));
				#line 54 f5__ //Expr
				if((*self).block){
					#line 56 f5__ //Expr
					(*(*self).block).parent = self;
					#line 57 f5__ //Expr
					if((!(*(*self).block).outer)){
						#line 58 f5__ //Expr
						(*(*self).block).outer = Last1160(semantic.scopes);
						#line 59 f5__ //Expr
						Assert261(((i64)(&(*self).block)!=(i64)(*(*self).block).outer));
					};
					#line 61 f5__ //Expr
					Push6158(semantic.scopes,(*self).block);
					#line 62 f5__ //Expr
					for(i64 it = i64265(0); it<(*self).params.list.length;it++){
						#line 63 f5__ //Expr
						Variable498* variable=As7135((*OpArray4122((*self).params.list,it)));
						#line 65 f5__ //Expr
						if((!Is5151((*(*variable).super.typ)))){
							#line 67 f5__ //Expr
							Declare119(semantic,(*variable).super);
						}else{
							#line 70 f5__ //Expr
							Println59(str53{12,(i8*)"NOT DEClared"});
						};
						#line 73 f5__ //Expr
						AnnotateGeneric124(semantic,(*(*variable).super.typ),(*self));
					};
					#line 75 f5__ //Expr
					if((*self).result){
						#line 76 f5__ //Expr
						AnnotateGeneric124(semantic,(*(*self).result),(*self));
					};
					#line 78 f5__ //Expr
					Pop1162(semantic.scopes);
				}else{
					#line 81 f5__ //Expr
					for(i64 it = i64265(0); it<(*self).params.list.length;it++){
						#line 82 f5__ //Expr
						Variable498* variable=As7135((*OpArray4122((*self).params.list,it)));
						#line 83 f5__ //Expr
						AnnotateGeneric124(semantic,(*(*variable).super.typ),(*self));
					};
					#line 85 f5__ //Expr
					if((*self).result){
						#line 86 f5__ //Expr
						AnnotateGeneric124(semantic,(*(*self).result),(*self));
					};
				};
			};
		};
		#line 92 f5__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 93 f5__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 94 f5__ //Expr
			if(Is7134((*expr))){
				#line 95 f5__ //Expr
				Visit122(semantic,(*expr));
			};
		};
		#line 99 f5__ //Expr
		Pop1162(semantic.scopes);
		#line 101 f5__ //Expr
		Visit122(semantic,ast.super);
		#line 102 f5__ //Expr
		Push6158(semantic.scopes,(&ast));
		#line 104 f5__ //Expr
		Println59(str53{22,(i8*)"Finished semantic pass"});
}
	#line 108 f5__ //Expr
	Expr366* FindPrivate112(Semantic110& semantic,str53 ident){
		#line 109 f5__ //Expr
		Block434* scope=Last1160(semantic.scopes);
		#line 110 f5__ //Expr
		while(scope){
			#line 112 f5__ //Expr
			Expr366* expr=Lookup437((*scope),ident);
			#line 113 f5__ //Expr
			if(expr){
				#line 115 f5__ //Expr
				return expr;
			};
			#line 117 f5__ //Expr
			scope = (*scope).outer;
		};
		#line 119 f5__ //Expr
		return (Expr366*)0;
}
	#line 122 f5__ //Expr
	;
	#line 123 f5__ //Expr
	;
	#line 124 f5__ //Expr
	;
	#line 135 f5__ //Expr
	i8 Implements113(Semantic110& semantic,Trait490& trai,Type413& typ){
		#line 137 f5__ //Expr
		trai.typeTrait.reference = (&typ);
		#line 139 f5__ //Expr
		i8 implements=true;
		#line 141 f5__ //Expr
		for(i64 it = i64265(0); it<trai.required.length;it++){
			#line 143 f5__ //Expr
			Function456* function=OpArray8163(trai.required,it);
			#line 144 f5__ //Expr
			if((!FindMatch117(semantic,trai.super,(*function).ident,(*function).params))){
				#line 145 f5__ //Expr
				implements = false;
			};
		};
		#line 148 f5__ //Expr
		trai.typeTrait.reference = (Type413*)0;
		#line 149 f5__ //Expr
		return implements;
}
	#line 152 f5__ //Expr
	Expr366* FindType114(Semantic110& semantic,str53 ident,Position76 at){
		#line 153 f5__ //Expr
		Expr366* expr=FindPrivate112(semantic,ident);
		#line 154 f5__ //Expr
		if((!expr)){
			#line 155 f5__ //Expr
			Error109(at,add64(str53{20,(i8*)"No known type named "},ident));
		};
		#line 157 f5__ //Expr
		return expr;
}
	#line 159 f5__ //Expr
	Expr366* FindVariable115(Semantic110& semantic,str53 ident,Position76 at){
		#line 160 f5__ //Expr
		Expr366* expr=FindPrivate112(semantic,ident);
		#line 161 f5__ //Expr
		if((!expr)){
			#line 162 f5__ //Expr
			Error109(at,add64(str53{24,(i8*)"No known variable named "},ident));
		};
		#line 164 f5__ //Expr
		return expr;
}
	#line 167 f5__ //Expr
	TypeFunctions417* FindMatches116(Semantic110& semantic,Expr366& self,str53 ident,ExpressionList369& args){
		#line 169 f5__ //Expr
		Block434* scope=Last1160(semantic.scopes);
		#line 170 f5__ //Expr
		while(scope){
			#line 172 f5__ //Expr
			TypeFunctions417* expr=LookupFns438((*scope),ident);
			#line 173 f5__ //Expr
			if(expr){
				#line 175 f5__ //Expr
				return expr;
			};
			#line 177 f5__ //Expr
			scope = (*scope).outer;
		};
		#line 179 f5__ //Expr
		Error108(self,add64(str53{24,(i8*)"No known function named "},ident));
		#line 180 f5__ //Expr
		return (TypeFunctions417*)0;
}
	#line 183 f5__ //Expr
	Function456* FindMatch117(Semantic110& semantic,Expr366& self,str53 ident,ExpressionList369& args){
		#line 185 f5__ //Expr
		TypeFunctions417* funcs=FindMatches116(semantic,self,ident,args);
		#line 187 f5__ //Expr
		Function456* found={0};
		#line 188 f5__ //Expr
		Known470 foundKnown={0};
		#line 190 f5__ //Expr
		for(i64 it = i64265(0); it<(*funcs).functions.length;it++){
			#line 191 f5__ //Expr
			Function456* f=OpArray8163((*funcs).functions,it);
			#line 193 f5__ //Expr
			if((((*f).params.list.length==args.list.length)&&(!(*f).traitFunction))){
				#line 195 f5__ //Expr
				i8 matched=1;
				#line 196 f5__ //Expr
				Known470 known={0};
				#line 197 f5__ //Expr
				Init0111(known.drefCount,args.list.length);
				#line 198 f5__ //Expr
				for(i64 it = i64265(0); it<(*f).params.list.length;it++){
					#line 200 f5__ //Expr
					if((!Apply129(semantic,(*OpArray4122(args.list,it)).typ,(*OpArray4122((*f).params.list,it)).typ,known,it))){
						#line 202 f5__ //Expr
						if((!Coerce362((*OpArray4122((*f).params.list,it)),(*OpArray4122(args.list,it)),false))){
							#line 203 f5__ //Expr
							matched = 0;
						};
					};
				};
				#line 207 f5__ //Expr
				if(matched){
					#line 208 f5__ //Expr
					found = f;
					#line 209 f5__ //Expr
					foundKnown = known;
				};
			};
		};
		#line 213 f5__ //Expr
		return found;
}
	#line 217 f5__ //Expr
	void Declare118(Block434& block,Expr366& expr){
		#line 218 f5__ //Expr
		if(Is2123(expr)){
			#line 219 f5__ //Expr
			Structure473* self=As2124(expr);
			#line 220 f5__ //Expr
			(*As1144((*(*self).typeIdent))).ident = (*self).ident;
			#line 221 f5__ //Expr
			Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
			#line 222 f5__ //Expr
			Insert440(block,(*self).ident,(&expr));
		}else{
			#line 224 f5__ //Expr
			if(Is3126(expr)){
				#line 225 f5__ //Expr
				Function456* self=As3127(expr);
				#line 226 f5__ //Expr
				Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
				#line 227 f5__ //Expr
				InsertFn439(block,(*self).ident,self);
			}else{
				#line 229 f5__ //Expr
				if(Is7134(expr)){
					#line 230 f5__ //Expr
					Variable498* self=As7135(expr);
					#line 231 f5__ //Expr
					Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
					#line 232 f5__ //Expr
					Insert440(block,(*self).ident,(&expr));
				}else{
					#line 234 f5__ //Expr
					if(Is8136(expr)){
						#line 235 f5__ //Expr
						Trait490* self=As8137(expr);
						#line 236 f5__ //Expr
						Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
						#line 237 f5__ //Expr
						Insert440(block,(*self).ident,(&expr));
						#line 238 f5__ //Expr
						for(i64 it = i64265(0); it<(*self).required.length;it++){
							#line 239 f5__ //Expr
							Add441(block,(&(*OpArray8163((*self).required,it)).super));
						};
					}else{
						#line 242 f5__ //Expr
						if(Is9138(expr)){
							#line 243 f5__ //Expr
							TypeAs367* self=As9139(expr);
							#line 244 f5__ //Expr
							Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
							#line 245 f5__ //Expr
							Insert440(block,(*self).ident,(&expr));
						}else{
							#line 247 f5__ //Expr
							if(Is10164(expr)){
							}else{
								#line 250 f5__ //Expr
								Assert260(0,str53{48,(i8*)"Expected Structure, Function, Trait, or Variable"});
							};
						};
					};
				};
			};
		};
}
	#line 254 f5__ //Expr
	void Declare119(Semantic110& semantic,Expr366& expr){
		#line 255 f5__ //Expr
		Declare118((*Last1160(semantic.scopes)),expr);
}
	#line 258 f5__ //Expr
	i64 DrefCount120(Type413& desired,Type413& from){
		#line 259 f5__ //Expr
		Type413* typeLeft=Resolved127(desired);
		#line 260 f5__ //Expr
		Type413* typeRight=Resolved127(from);
		#line 261 f5__ //Expr
		i32 count={0};
		#line 263 f5__ //Expr
		if((!Equal132(typeRight,typeLeft,false))){
			#line 264 f5__ //Expr
			if(Is0141((*typeLeft))){
				#line 265 f5__ //Expr
				typeLeft = Resolved127((*(*As0142((*typeLeft))).reference));
				#line 266 f5__ //Expr
				count = (count-1);
			};
		};
		#line 269 f5__ //Expr
		return count;
}
	#line 272 f5__ //Expr
	i64 CheckAssignment121(Expr366& self,Type413* desired,Expr366* from){
		#line 274 f5__ //Expr
		if((!from)){
			#line 276 f5__ //Expr
			if(desired){
				#line 277 f5__ //Expr
				Error108(self,add64(str53{75,(i8*)"Cannot return a value of () from a from a function that requires return of "},String105(desired)));
			};
			#line 279 f5__ //Expr
			return 0;
		};
		#line 281 f5__ //Expr
		if((!desired)){
			#line 282 f5__ //Expr
			Error108(self,str53{67,(i8*)"Cannot return a value from a from a function without a return value"});
		};
		#line 286 f5__ //Expr
		Type413* typeRight=Resolved127((*(*from).typ));
		#line 287 f5__ //Expr
		Type413* typeLeft=Resolved127((*desired));
		#line 288 f5__ //Expr
		i32 count={0};
		#line 290 f5__ //Expr
		if((!Equal132(typeRight,typeLeft,false))){
			#line 291 f5__ //Expr
			if(Is0141((*typeRight))){
				#line 292 f5__ //Expr
				typeRight = Resolved127((*(*As0142((*typeRight))).reference));
				#line 293 f5__ //Expr
				count = (count-1);
			};
		}else{
			#line 297 f5__ //Expr
			return 0;
		};
		#line 300 f5__ //Expr
		if((!Equal132(typeRight,typeLeft,false))){
			#line 302 f5__ //Expr
			i32 value=Coerce363((*typeLeft),(*from),true);
			#line 303 f5__ //Expr
			if((value==0)){
				#line 304 f5__ //Expr
				Error108(self,add64(add64(String105(desired),str53{30,(i8*)" cannot be assigned a type of "}),String105((*from).typ)));
			};
		};
		#line 307 f5__ //Expr
		return count;
}
	#line 310 f5__ //Expr
	void Visit122(Semantic110& semantic,Expr366& expr){
		#line 312 f5__ //Expr
		if(Is1120(expr)){
			#line 313 f5__ //Expr
			Block434* self=As1121(expr);
			#line 314 f5__ //Expr
			if(semantic.scopes.length){
				#line 315 f5__ //Expr
				if((!(*self).outer)){
					#line 316 f5__ //Expr
					(*self).outer = Last1160(semantic.scopes);
					#line 317 f5__ //Expr
					Assert261(((i64)self!=(i64)(*self).outer));
				};
			};
			#line 320 f5__ //Expr
			Push6158(semantic.scopes,self);
			#line 322 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).expressions.length;it++){
				#line 323 f5__ //Expr
				Expr366* expr=OpArray4122((*self).expressions,it);
				#line 324 f5__ //Expr
				Visit122(semantic,(*expr));
			};
			#line 326 f5__ //Expr
			Pop1162(semantic.scopes);
			#line 327 f5__ //Expr
			return ;
		};
		#line 329 f5__ //Expr
		if(Is2123(expr)){
			#line 330 f5__ //Expr
			Structure473* self=As2124(expr);
			#line 332 f5__ //Expr
			if((((*self).state==Visiting)||((*self).state==Visited))){
				#line 333 f5__ //Expr
				return ;
			};
			#line 336 f5__ //Expr
			i32 isNew=(*self).state;
			#line 337 f5__ //Expr
			(*self).state = Visiting;
			#line 339 f5__ //Expr
			(*self).block.outer = Last1160(semantic.scopes);
			#line 340 f5__ //Expr
			Assert261(((i64)(&(*self).block)!=(i64)(*self).block.outer));
			#line 342 f5__ //Expr
			Push6158(semantic.scopes,(&(*self).block));
			#line 343 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 344 f5__ //Expr
				TypeAny425* any=As2146((*OpArray6155((*self).constraints,it)));
				#line 345 f5__ //Expr
				TypeAs367* as=New19165();
				#line 346 f5__ //Expr
				(*as).super.typ = (&(*any).super);
				#line 347 f5__ //Expr
				(*as).ident = (*any).ident;
				#line 348 f5__ //Expr
				Declare119(semantic,(*as).super);
			};
			#line 351 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).fields.length;it++){
				#line 352 f5__ //Expr
				Push137((*self).typeStructure.fields,(*OpArray5125((*self).fields,it)).super.typ);
			};
			#line 354 f5__ //Expr
			(*self).typeStructure.constraints = (*self).constraints;
			#line 355 f5__ //Expr
			Print58(add64(add64(add64(add64(add64(add64(str53{10,(i8*)" Created: "},(*self).ident),str53{1,(i8*)" "}),String0168((*self).constraints)),str53{2,(i8*)"->"}),String66((i64)(&(*self).typeStructure))),str53{1,(i8*)"\n"}));
			#line 357 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).fields.length;it++){
				#line 358 f5__ //Expr
				Visit122(semantic,(*OpArray5125((*self).fields,it)).super);
			};
			#line 360 f5__ //Expr
			Pop1162(semantic.scopes);
			#line 361 f5__ //Expr
			if((isNew==Declared)){
				#line 362 f5__ //Expr
				Push7169(semantic.structures,self);
				#line 363 f5__ //Expr
				if(((*self).constraints.length==0)){
					#line 364 f5__ //Expr
					Push8171(structures,(&(*self).typeStructure));
				};
				#line 366 f5__ //Expr
				Println59((*self).ident);
			};
			#line 368 f5__ //Expr
			(*self).state = Visited;
			#line 369 f5__ //Expr
			return ;
		};
		#line 371 f5__ //Expr
		if(Is3126(expr)){
			#line 372 f5__ //Expr
			Function456* self=As3127(expr);
			#line 373 f5__ //Expr
			if((*self).block){
				#line 375 f5__ //Expr
				(*(*self).block).parent = self;
				#line 376 f5__ //Expr
				if((!(*(*self).block).outer)){
					#line 377 f5__ //Expr
					(*(*self).block).outer = Last1160(semantic.scopes);
					#line 378 f5__ //Expr
					Assert261(((i64)(&(*self).block)!=(i64)(*(*self).block).outer));
				};
				#line 380 f5__ //Expr
				Push6158(semantic.scopes,(*self).block);
				#line 381 f5__ //Expr
				for(i64 it = i64265(0); it<(*self).params.list.length;it++){
					#line 382 f5__ //Expr
					Variable498* variable=As7135((*OpArray4122((*self).params.list,it)));
					#line 383 f5__ //Expr
					Annotate125(semantic,(*(*variable).super.typ));
				};
				#line 385 f5__ //Expr
				if((*self).result){
					#line 386 f5__ //Expr
					Annotate125(semantic,(*(*self).result));
				};
				#line 388 f5__ //Expr
				Pop1162(semantic.scopes);
				#line 389 f5__ //Expr
				Visit122(semantic,(*(*self).block).super);
			}else{
				#line 393 f5__ //Expr
				for(i64 it = i64265(0); it<(*self).params.list.length;it++){
					#line 394 f5__ //Expr
					Variable498* variable=As7135((*OpArray4122((*self).params.list,it)));
					#line 395 f5__ //Expr
					Annotate125(semantic,(*(*variable).super.typ));
				};
				#line 397 f5__ //Expr
				if((*self).result){
					#line 398 f5__ //Expr
					Annotate125(semantic,(*(*self).result));
				};
			};
			#line 401 f5__ //Expr
			return ;
		};
		#line 403 f5__ //Expr
		if(Is7134(expr)){
			#line 404 f5__ //Expr
			Variable498* self=As7135(expr);
			#line 405 f5__ //Expr
			Declare119(semantic,(*self).super);
			#line 406 f5__ //Expr
			Annotate125(semantic,(*(*self).super.typ));
			#line 407 f5__ //Expr
			if((*self).assign){
				#line 408 f5__ //Expr
				Visit122(semantic,(*(*self).assign));
				#line 409 f5__ //Expr
				(*self).drefCount = (-CheckAssignment121((*self).super,(*self).super.typ,(*self).assign));
			};
			#line 411 f5__ //Expr
			return ;
		};
		#line 413 f5__ //Expr
		if(Is4128(expr)){
			#line 414 f5__ //Expr
			Identifier495* self=As4129(expr);
			#line 415 f5__ //Expr
			if(equal68((*self).ident,str53{0,(i8*)""})){
				#line 416 f5__ //Expr
				Assert0173((*self).super.typ);
				#line 417 f5__ //Expr
				Annotate125(semantic,(*(*self).super.typ));
				#line 418 f5__ //Expr
				return ;
			};
			#line 421 f5__ //Expr
			Expr366* referenced=FindVariable115(semantic,(*self).ident,(*self).super.at);
			#line 422 f5__ //Expr
			(*self).reference = referenced;
			#line 424 f5__ //Expr
			if(Is9138((*referenced))){
				#line 425 f5__ //Expr
				TypeType427* t=New348();
				#line 426 f5__ //Expr
				(*t).reference = (*referenced).typ;
				#line 427 f5__ //Expr
				(*self).super.typ = (&(*t).super);
			}else{
				#line 430 f5__ //Expr
				(*self).super.typ = (*referenced).typ;
			};
			#line 432 f5__ //Expr
			Assert2140((*self).super.typ,str53{25,(i8*)"Expect type to be non nil"});
			#line 433 f5__ //Expr
			return ;
		};
		#line 435 f5__ //Expr
		if(Is6132(expr)){
			#line 436 f5__ //Expr
			Access445* self=As6133(expr);
			#line 437 f5__ //Expr
			Visit122(semantic,(*(*self).operand));
			#line 438 f5__ //Expr
			Type413* typ=Resolved127((*(*(*self).operand).typ));
			#line 439 f5__ //Expr
			while(Is0141((*typ))){
				#line 440 f5__ //Expr
				typ = (*As0142((*typ))).reference;
			};
			#line 442 f5__ //Expr
			TypeStructure481* spec=ResolveSpec128((*typ));
			#line 444 f5__ //Expr
			if((Is1143((*typ))&&Is2123((*(*As1144((*typ))).spec)))){
				#line 446 f5__ //Expr
				Structure473* structure=As2124((*(*As1144((*typ))).spec));
				#line 447 f5__ //Expr
				Variable498* variable=Lookup477((*structure),(*self).field);
				#line 448 f5__ //Expr
				if(variable){
					#line 450 f5__ //Expr
					(*self).super.typ = Clone133((*(*variable).super.typ));
				};
			};
			#line 453 f5__ //Expr
			if(spec){
				#line 455 f5__ //Expr
				TypeStructure481* typeStructure=spec;
				#line 456 f5__ //Expr
				(*self).super.typ = Lookup478((*typeStructure),(*self).field);
			};
			#line 458 f5__ //Expr
			if((!(*self).super.typ)){
				#line 460 f5__ //Expr
				Identifier495* ident=New1590();
				#line 461 f5__ //Expr
				(*ident).super.at = (*self).super.at;
				#line 462 f5__ //Expr
				(*ident).ident = (*self).field;
				#line 464 f5__ //Expr
				(*self).call = New20174();
				#line 465 f5__ //Expr
				(*(*self).call).super.at = (*self).super.at;
				#line 466 f5__ //Expr
				(*(*self).call).operand = (&(*ident).super);
				#line 467 f5__ //Expr
				Add371((*(*self).call).params,(*self).operand);
				#line 468 f5__ //Expr
				Visit122(semantic,(*(*self).call).super);
				#line 469 f5__ //Expr
				(*self).super.typ = (*(*self).call).super.typ;
				#line 470 f5__ //Expr
				return ;
			};
			#line 472 f5__ //Expr
			Assert2140((*self).super.typ,add64(str53{27,(i8*)"Could not find field named "},(*self).field));
			#line 474 f5__ //Expr
			return ;
		};
		#line 476 f5__ //Expr
		if(Is5130(expr)){
			#line 477 f5__ //Expr
			Call442* self=As5131(expr);
			#line 478 f5__ //Expr
			if(Is6132((*(*self).operand))){
				#line 479 f5__ //Expr
				Access445* access=As6133((*(*self).operand));
				#line 480 f5__ //Expr
				Visit122(semantic,(*(*access).operand));
				#line 481 f5__ //Expr
				Type413* typ=Resolved127((*(*(*access).operand).typ));
				#line 482 f5__ //Expr
				TypeStructure481* spec=ResolveSpec128((*typ));
				#line 484 f5__ //Expr
				if(Is1143((*Resolved127((*(*(*access).operand).typ))))){
					#line 486 f5__ //Expr
					Structure473* structure=As2124((*(*As1144((*Resolved127((*(*(*access).operand).typ))))).spec));
					#line 487 f5__ //Expr
					Variable498* variable=Lookup477((*structure),(*access).field);
					#line 488 f5__ //Expr
					if(variable){
						#line 490 f5__ //Expr
						(*access).super.typ = (*variable).super.typ;
					};
				}else{
					#line 493 f5__ //Expr
					if(spec){
						#line 494 f5__ //Expr
						TypeStructure481* typeStructure=spec;
						#line 495 f5__ //Expr
						(*self).super.typ = Lookup478((*typeStructure),(*access).field);
					};
				};
				#line 497 f5__ //Expr
				if((*access).super.typ){
					#line 498 f5__ //Expr
					return ;
				};
				#line 501 f5__ //Expr
				Insert0177((*self).params.list,0,(*access).operand);
				#line 502 f5__ //Expr
				Identifier495* ident=New1590();
				#line 503 f5__ //Expr
				(*ident).ident = (*access).field;
				#line 504 f5__ //Expr
				(*self).operand = (&(*ident).super);
			};
			#line 506 f5__ //Expr
			if(Is4128((*(*self).operand))){
				#line 508 f5__ //Expr
				Visit122(semantic,(*self).params.super);
				#line 510 f5__ //Expr
				TypeFunctions417* funcs=FindMatches116(semantic,(*self).super,(*As4129((*(*self).operand))).ident,(*self).params);
				#line 511 f5__ //Expr
				Function456* found={0};
				#line 512 f5__ //Expr
				Known470 foundKnown={0};
				#line 513 f5__ //Expr
				i32 foundCount={0};
				#line 515 f5__ //Expr
				for(i64 it = i64265(0); it<(*funcs).functions.length;it++){
					#line 516 f5__ //Expr
					Function456* f=OpArray8163((*funcs).functions,it);
					#line 517 f5__ //Expr
					Function456* parent=ParentFunction123(Last1160(semantic.scopes));
					#line 518 f5__ //Expr
					i8 ignore=((*f).traitFunction&&(!((i64)found==0)));
					#line 520 f5__ //Expr
					if((((*f).params.list.length==(*self).params.list.length)&&(!ignore))){
						#line 522 f5__ //Expr
						i8 matched=1;
						#line 523 f5__ //Expr
						Known470 known={0};
						#line 524 f5__ //Expr
						Init0111(known.drefCount,(*self).params.list.length);
						#line 525 f5__ //Expr
						for(i64 it = i64265(0); it<(*f).params.list.length;it++){
							#line 527 f5__ //Expr
							if((!Apply129(semantic,(*OpArray4122((*self).params.list,it)).typ,(*OpArray4122((*f).params.list,it)).typ,known,it))){
								#line 529 f5__ //Expr
								if((!Coerce362((*OpArray4122((*f).params.list,it)),(*OpArray4122((*self).params.list,it)),false))){
									#line 530 f5__ //Expr
									matched = 0;
								};
							};
						};
						#line 534 f5__ //Expr
						if(matched){
							#line 535 f5__ //Expr
							if(((!(*f).traitFunction)||((i64)found==0))){
								#line 536 f5__ //Expr
								found = f;
								#line 537 f5__ //Expr
								foundKnown = known;
								#line 538 f5__ //Expr
								foundCount = (foundCount+1);
							};
						};
					};
				};
				#line 543 f5__ //Expr
				if((!found)){
					#line 544 f5__ //Expr
					Println59(str53{45,(i8*)"---------------------------------------------"});
					#line 545 f5__ //Expr
					Print58((*As4129((*(*self).operand))).ident);
					#line 546 f5__ //Expr
					Print58(str53{5,(i8*)" fn ("});
					#line 547 f5__ //Expr
					for(i64 it = i64265(0); it<(*self).params.list.length;it++){
						#line 548 f5__ //Expr
						Print97((*(*OpArray4122((*self).params.list,it)).typ));
						#line 549 f5__ //Expr
						if((it!=((*self).params.list.length-1))){
							#line 550 f5__ //Expr
							Print58(str53{2,(i8*)", "});
						};
					};
					#line 553 f5__ //Expr
					Println59(str53{1,(i8*)")"});
					#line 554 f5__ //Expr
					Println59(str53{45,(i8*)"-------------------matches-------------------"});
					#line 555 f5__ //Expr
					for(i64 it = i64265(0); it<(*funcs).functions.length;it++){
						#line 556 f5__ //Expr
						Print96((*OpArray8163((*funcs).functions,it)).super);
						#line 557 f5__ //Expr
						Println59(str53{0,(i8*)""});
					};
					#line 559 f5__ //Expr
					Println59(str53{45,(i8*)"---------------------------------------------"});
					#line 561 f5__ //Expr
					Error108((*self).super,add64(str53{23,(i8*)"No match for function: "},(*As4129((*(*self).operand))).ident));
				};
				#line 565 f5__ //Expr
				for(i64 it = i64265(0); it<(*found).params.list.length;it++){
					#line 566 f5__ //Expr
					Coerce362((*OpArray4122((*found).params.list,it)),(*OpArray4122((*self).params.list,it)),false);
				};
				#line 568 f5__ //Expr
				(*self).drefCount = foundKnown.drefCount;
				#line 569 f5__ //Expr
				if(foundKnown.known.length){
					#line 573 f5__ //Expr
					FunctionSpec460* spec=Specialize462((*found),semantic,self,(*Last1160(semantic.scopes)).parent,foundKnown);
					#line 575 f5__ //Expr
					if((*Last1160(semantic.scopes)).parent){
						#line 576 f5__ //Expr
						if((*(*Last1160(semantic.scopes)).parent).spec){
							#line 577 f5__ //Expr
							if(((*(*(*Last1160(semantic.scopes)).parent).spec).incomplete==false)){
								#line 578 f5__ //Expr
								if((!IsIntrinsic140(semantic.intrinsic,found))){
									#line 579 f5__ //Expr
									Println59(add64(add64(add64(str53{15,(i8*)"Mismatched inc "},(*found).ident),str53{3,(i8*)"   "}),String66(foundCount)));
								};
							};
						};
					};
					#line 586 f5__ //Expr
					Assert1178(spec);
					#line 587 f5__ //Expr
					(*self).func = (&(*spec).super);
					#line 589 f5__ //Expr
					FunctionSpec460* prev=(*found).spec;
					#line 590 f5__ //Expr
					Apply468((*spec));
					#line 591 f5__ //Expr
					if((*found).result){
						#line 592 f5__ //Expr
						(*self).super.typ = Clone133((*Resolved127((*(*found).result))));
					};
					#line 595 f5__ //Expr
					if(prev){
						#line 596 f5__ //Expr
						Apply468((*prev));
					}else{
						#line 599 f5__ //Expr
						Clear469((*spec));
					};
					#line 602 f5__ //Expr
					if((!(*spec).incomplete)){
						#line 603 f5__ //Expr
						for(i64 it = i64265(0); it<(*spec).known.length;it++){
							#line 604 f5__ //Expr
							TypeAnyResolved472 t=OpArray9179((*spec).known,it);
							#line 605 f5__ //Expr
							Assert261((ContainsUnknown463((*t.typ))==false));
						};
					};
				}else{
					#line 611 f5__ //Expr
					(*self).func = (&(*found).super);
					#line 612 f5__ //Expr
					(*self).super.typ = (*found).result;
					#line 613 f5__ //Expr
					if((*found).result){
						#line 614 f5__ //Expr
						(*self).super.typ = Clone133((*Resolved127((*(*found).result))));
					};
				};
			}else{
				#line 620 f5__ //Expr
				Assert260(0,str53{34,(i8*)"Call without identifier as operand"});
			};
			#line 622 f5__ //Expr
			return ;
		};
		#line 625 f5__ //Expr
		if(Is061(expr)){
			#line 626 f5__ //Expr
			ExpressionList369* self=As066(expr);
			#line 627 f5__ //Expr
			Assert3180(self,str53{3,(i8*)"nil"});
			#line 628 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).list.length;it++){
				#line 629 f5__ //Expr
				Assert162(OpArray4122((*self).list,it),str53{16,(i8*)"nil item in list"});
				#line 631 f5__ //Expr
				Visit122(semantic,(*OpArray4122((*self).list,it)));
				#line 632 f5__ //Expr
				Assert2140((*OpArray4122((*self).list,it)).typ,str53{22,(i8*)"Type should be non nil"});
			};
			#line 634 f5__ //Expr
			return ;
		};
		#line 636 f5__ //Expr
		if(Is8136(expr)){
			#line 637 f5__ //Expr
			Trait490* self=As8137(expr);
			#line 638 f5__ //Expr
			return ;
		};
		#line 641 f5__ //Expr
		if(Is11181(expr)){
			#line 642 f5__ //Expr
			NumberConstant507* self=As10182(expr);
			#line 643 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).value.length;it++){
				#line 644 f5__ //Expr
				if(((*((*self).value.chars+it))==Char54(str53{1,(i8*)"."}))){
					#line 645 f5__ //Expr
					(*self).super.typ = (&(*i64Type).super);
					#line 646 f5__ //Expr
					return ;
				};
			};
			#line 649 f5__ //Expr
			i64 num=i64FromString56((*self).value);
			#line 650 f5__ //Expr
			if(((num<=127)&&(num>=(-127)))){
				#line 651 f5__ //Expr
				(*self).super.typ = (&(*i8Type).super);
			}else{
				#line 653 f5__ //Expr
				if(((num<=32767)&&(num>=(-32767)))){
					#line 654 f5__ //Expr
					(*self).super.typ = (&(*i16Type).super);
				}else{
					#line 656 f5__ //Expr
					if(((num<=2147483647)&&(num>=(-2147483647)))){
						#line 657 f5__ //Expr
						(*self).super.typ = (&(*i32Type).super);
					}else{
						#line 660 f5__ //Expr
						(*self).super.typ = (&(*i64Type).super);
					};
				};
			};
			#line 662 f5__ //Expr
			Assert0173((*self).super.typ);
			#line 663 f5__ //Expr
			return ;
		};
		#line 665 f5__ //Expr
		if(Is12183(expr)){
			#line 666 f5__ //Expr
			StringConstant509* self=As11184(expr);
			#line 667 f5__ //Expr
			Type413* t=(*As5152((*(*FindType114(semantic,str53{3,(i8*)"Str"},(*self).super.at)).typ))).reference;
			#line 668 f5__ //Expr
			(*self).super.typ = t;
			#line 669 f5__ //Expr
			return ;
		};
		#line 671 f5__ //Expr
		if(Is13185(expr)){
			#line 672 f5__ //Expr
			ForList512* self=As12186(expr);
			#line 673 f5__ //Expr
			Visit122(semantic,(*(*self).list).super);
			#line 674 f5__ //Expr
			if((!(*self).it)){
				#line 675 f5__ //Expr
				Variable498* variable=New21187();
				#line 676 f5__ //Expr
				(*variable).ident = str53{2,(i8*)"it"};
				#line 677 f5__ //Expr
				(*variable).super.typ = (*OpArray4122((*(*self).list).list,0)).typ;
				#line 678 f5__ //Expr
				(*self).it = variable;
				#line 680 f5__ //Expr
				Insert0177((*(*self).block).expressions,0,(&(*variable).super));
			};
			#line 682 f5__ //Expr
			Visit122(semantic,(*(*self).block).super);
			#line 683 f5__ //Expr
			return ;
		};
		#line 685 f5__ //Expr
		if(Is14190(expr)){
			#line 686 f5__ //Expr
			For449* self=As13191(expr);
			#line 687 f5__ //Expr
			Visit122(semantic,(*(*self).from));
			#line 688 f5__ //Expr
			if((!(*self).it)){
				#line 689 f5__ //Expr
				Variable498* variable=New21187();
				#line 690 f5__ //Expr
				(*variable).ident = str53{2,(i8*)"it"};
				#line 691 f5__ //Expr
				(*variable).super.typ = (*(*self).from).typ;
				#line 692 f5__ //Expr
				(*self).it = variable;
				#line 693 f5__ //Expr
				Declare118((*(*self).block),(*variable).super);
				#line 694 f5__ //Expr
				(*(*self).it).assign = (*self).from;
			};
			#line 697 f5__ //Expr
			if((*self).to){
				#line 699 f5__ //Expr
				(*(*self).block).outer = Last1160(semantic.scopes);
				#line 700 f5__ //Expr
				Push6158(semantic.scopes,(*self).block);
				#line 701 f5__ //Expr
				Visit122(semantic,(*(*self).to));
				#line 703 f5__ //Expr
				if((!(*self).test)){
					#line 705 f5__ //Expr
					Identifier495* it=Identifier496();
					#line 706 f5__ //Expr
					(*it).ident = str53{2,(i8*)"it"};
					#line 709 f5__ //Expr
					(*self).test = Call443();
					#line 710 f5__ //Expr
					Identifier495* ident=Identifier496();
					#line 711 f5__ //Expr
					(*ident).ident = str53{1,(i8*)"<"};
					#line 712 f5__ //Expr
					(*(*self).test).operand = (&(*ident).super);
					#line 713 f5__ //Expr
					Push288((*(*self).test).params.list,(&(*it).super));
					#line 714 f5__ //Expr
					Push288((*(*self).test).params.list,(*self).to);
				};
				#line 716 f5__ //Expr
				if((!(*self).inc)){
					#line 717 f5__ //Expr
					Identifier495* ident=Identifier496();
					#line 718 f5__ //Expr
					(*ident).ident = str53{2,(i8*)"it"};
					#line 720 f5__ //Expr
					NumberConstant507* constant=New1279();
					#line 721 f5__ //Expr
					(*constant).value = str53{1,(i8*)"1"};
					#line 723 f5__ //Expr
					Identifier495* add=Identifier496();
					#line 724 f5__ //Expr
					(*add).ident = str53{1,(i8*)"+"};
					#line 726 f5__ //Expr
					Call442* call=Call443();
					#line 727 f5__ //Expr
					(*call).operand = (&(*add).super);
					#line 728 f5__ //Expr
					Push288((*call).params.list,(&(*ident).super));
					#line 729 f5__ //Expr
					Push288((*call).params.list,(&(*constant).super));
					#line 730 f5__ //Expr
					Assign501* assign=New1796();
					#line 731 f5__ //Expr
					(*assign).super.at = (*self).super.at;
					#line 732 f5__ //Expr
					(*assign).left = (&(*ident).super);
					#line 733 f5__ //Expr
					(*assign).right = (&(*call).super);
					#line 735 f5__ //Expr
					(*self).inc = (&(*assign).super);
				};
				#line 737 f5__ //Expr
				Visit122(semantic,(*(*self).test).super);
				#line 738 f5__ //Expr
				Visit122(semantic,(*(*self).inc));
				#line 739 f5__ //Expr
				Pop1162(semantic.scopes);
			};
			#line 743 f5__ //Expr
			Visit122(semantic,(*(*self).block).super);
			#line 744 f5__ //Expr
			return ;
		};
		#line 746 f5__ //Expr
		if(Is15192(expr)){
			#line 747 f5__ //Expr
			Assign501* self=As14193(expr);
			#line 748 f5__ //Expr
			Visit122(semantic,(*(*self).left));
			#line 749 f5__ //Expr
			Visit122(semantic,(*(*self).right));
			#line 751 f5__ //Expr
			Type413* typeLeft=Resolved127((*(*(*self).left).typ));
			#line 752 f5__ //Expr
			Type413* typeRight=Resolved127((*(*(*self).right).typ));
			#line 753 f5__ //Expr
			i32 count={0};
			#line 755 f5__ //Expr
			if((!Equal132(typeRight,typeLeft,false))){
				#line 756 f5__ //Expr
				if(Is0141((*typeLeft))){
					#line 757 f5__ //Expr
					typeLeft = Resolved127((*(*As0142((*typeLeft))).reference));
					#line 758 f5__ //Expr
					count = (count-1);
				};
			};
			#line 762 f5__ //Expr
			(*self).drefCount = count;
			#line 764 f5__ //Expr
			if((!Equal132(typeRight,typeLeft,false))){
				#line 766 f5__ //Expr
				i32 value=Coerce363((*typeLeft),(*(*self).right),false);
				#line 767 f5__ //Expr
				if((value==0)){
					#line 768 f5__ //Expr
					Error108((*self).super,add64(add64(String105((*(*self).left).typ),str53{30,(i8*)" cannot be assigned a type of "}),String105((*(*self).right).typ)));
					#line 769 f5__ //Expr
					semantic.error = true;
				};
			};
			#line 773 f5__ //Expr
			return ;
		};
		#line 775 f5__ //Expr
		if(Is16194(expr)){
			#line 777 f5__ //Expr
			If447* self=As15195(expr);
			#line 778 f5__ //Expr
			Visit122(semantic,(*(*self).condition));
			#line 779 f5__ //Expr
			if((!Equal131((*(*self).condition).typ,(&(*i8Type).super)))){
				#line 780 f5__ //Expr
				Error108((*self).super,str53{63,(i8*)"Expected condition to be of type Bool, did you mean to use \"==\""});
			};
			#line 782 f5__ //Expr
			Visit122(semantic,(*(*self).trueBranch).super);
			#line 783 f5__ //Expr
			if((*self).falseBranch){
				#line 784 f5__ //Expr
				Visit122(semantic,(*(*self).falseBranch).super);
			};
			#line 786 f5__ //Expr
			if((*self).falseCondition){
				#line 787 f5__ //Expr
				Visit122(semantic,(*(*self).falseCondition).super);
			};
			#line 790 f5__ //Expr
			return ;
		};
		#line 792 f5__ //Expr
		if(Is17196(expr)){
			#line 793 f5__ //Expr
			return ;
		};
		#line 796 f5__ //Expr
		if(Is18197(expr)){
			#line 797 f5__ //Expr
			Return454* self=As16198(expr);
			#line 798 f5__ //Expr
			Type413* result=(*ParentFunction123(Last1160(semantic.scopes))).result;
			#line 799 f5__ //Expr
			if((*self).expr){
				#line 800 f5__ //Expr
				Visit122(semantic,(*(*self).expr));
			};
			#line 802 f5__ //Expr
			(*self).drefCount = (-CheckAssignment121((*self).super,result,(*self).expr));
			#line 803 f5__ //Expr
			return ;
		};
		#line 806 f5__ //Expr
		Println59(add64(str53{16,(i8*)"Unhandled visit "},String66(expr.kind)));
}
	#line 809 f5__ //Expr
	Function456* ParentFunction123(Block434* block){
		#line 810 f5__ //Expr
		Block434* cursor=block;
		#line 811 f5__ //Expr
		while((*cursor).outer){
			#line 812 f5__ //Expr
			if((*cursor).parent){
				#line 813 f5__ //Expr
				return (*cursor).parent;
			};
			#line 815 f5__ //Expr
			cursor = (*cursor).outer;
		};
		#line 817 f5__ //Expr
		return (*cursor).parent;
}
	#line 820 f5__ //Expr
	void AnnotateGeneric124(Semantic110& semantic,Type413& t,Function456& spec){
		#line 822 f5__ //Expr
		Type413* typ=Resolved127(t);
		#line 824 f5__ //Expr
		if(Is2145((*typ))){
			#line 825 f5__ //Expr
			AddAny461(spec,typ);
			#line 826 f5__ //Expr
			return ;
		};
		#line 828 f5__ //Expr
		if(Is3147((*typ))){
			#line 829 f5__ //Expr
			AddAny461(spec,typ);
			#line 830 f5__ //Expr
			spec.traitFunction = true;
			#line 832 f5__ //Expr
			return ;
		};
		#line 834 f5__ //Expr
		if(Is0141((*typ))){
			#line 835 f5__ //Expr
			TypeRef419* self=As0142((*typ));
			#line 836 f5__ //Expr
			AnnotateGeneric124(semantic,(*(*self).reference),spec);
			#line 837 f5__ //Expr
			return ;
		};
		#line 839 f5__ //Expr
		if(Is4149((*typ))){
			#line 840 f5__ //Expr
			TypeOption421* self=As4150((*typ));
			#line 841 f5__ //Expr
			AnnotateGeneric124(semantic,(*(*self).reference),spec);
			#line 842 f5__ //Expr
			return ;
		};
		#line 844 f5__ //Expr
		if(Is1143((*typ))){
			#line 845 f5__ //Expr
			TypeIdentifier414* self=As1144((*typ));
			#line 846 f5__ //Expr
			Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
			#line 847 f5__ //Expr
			(*self).spec = FindType114(semantic,(*self).ident,spec.super.at);
			#line 848 f5__ //Expr
			if((Is2123((*(*self).spec))&&((*As2124((*(*self).spec))).state!=Visited))){
				#line 849 f5__ //Expr
				Visit122(semantic,(*(*self).spec));
			};
			#line 854 f5__ //Expr
			Type413* t=Resolved127((*typ));
			#line 855 f5__ //Expr
			if((!equal0199(t,typ))){
				#line 856 f5__ //Expr
				AnnotateGeneric124(semantic,(*t),spec);
			};
			#line 858 f5__ //Expr
			return ;
		};
		#line 860 f5__ //Expr
		if(Is6153((*typ))){
			#line 861 f5__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 862 f5__ //Expr
			AnnotateGeneric124(semantic,(*(*self).ident).super,spec);
			#line 863 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 864 f5__ //Expr
				AnnotateGeneric124(semantic,(*OpArray6155((*self).constraints,it)),spec);
			};
			#line 866 f5__ //Expr
			Structure473* structure=As2124((*(*(*self).ident).spec));
			#line 867 f5__ //Expr
			(*self).referenced = SpecializeStructure486(semantic,(*structure).typeStructure,(*self).constraints);
			#line 868 f5__ //Expr
			return ;
		};
		#line 870 f5__ //Expr
		if(Is5151((*typ))){
			#line 871 f5__ //Expr
			TypeType427* self=As5152((*typ));
			#line 872 f5__ //Expr
			AnnotateGeneric124(semantic,(*(*self).reference),spec);
			#line 873 f5__ //Expr
			return ;
		};
		#line 875 f5__ //Expr
		if(Is7156((*typ))){
			#line 876 f5__ //Expr
			return ;
		};
		#line 878 f5__ //Expr
		Assert260(0,add64(str53{29,(i8*)"No annotate generic for type "},String66((*typ).kind)));
}
	#line 881 f5__ //Expr
	void Annotate125(Semantic110& semantic,Type413& t){
		#line 883 f5__ //Expr
		Annotate126(semantic,t,false);
}
	#line 885 f5__ //Expr
	void Annotate126(Semantic110& semantic,Type413& t,i8 reference){
		#line 887 f5__ //Expr
		Type413* typ=Resolved127(t);
		#line 888 f5__ //Expr
		if(Is0141((*typ))){
			#line 889 f5__ //Expr
			TypeRef419* self=As0142((*typ));
			#line 890 f5__ //Expr
			Annotate126(semantic,(*(*self).reference),true);
			#line 891 f5__ //Expr
			return ;
		};
		#line 893 f5__ //Expr
		if(Is1143((*typ))){
			#line 894 f5__ //Expr
			TypeIdentifier414* self=As1144((*typ));
			#line 895 f5__ //Expr
			Assert051((*self).ident.chars,str53{17,(i8*)"failed in declare"});
			#line 896 f5__ //Expr
			if((!(*self).spec)){
				#line 897 f5__ //Expr
				Position76 a={0};
				#line 898 f5__ //Expr
				(*self).spec = FindType114(semantic,(*self).ident,a);
				#line 899 f5__ //Expr
				if((!((reference&&Is2123((*(*self).spec)))&&((*As2124((*(*self).spec))).state!=Visited)))){
					#line 900 f5__ //Expr
					Visit122(semantic,(*(*self).spec));
				};
			};
			#line 903 f5__ //Expr
			return ;
		};
		#line 905 f5__ //Expr
		if(Is6153((*typ))){
			#line 906 f5__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 907 f5__ //Expr
			Annotate125(semantic,(*(*self).ident).super);
			#line 908 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 909 f5__ //Expr
				Annotate126(semantic,(*OpArray6155((*self).constraints,it)),reference);
			};
			#line 911 f5__ //Expr
			Structure473* structure=As2124((*(*(*self).ident).spec));
			#line 912 f5__ //Expr
			(*self).referenced = SpecializeStructure486(semantic,(*structure).typeStructure,(*self).constraints);
			#line 913 f5__ //Expr
			return ;
		};
		#line 915 f5__ //Expr
		if(Is5151((*typ))){
			#line 916 f5__ //Expr
			TypeType427* self=As5152((*typ));
			#line 917 f5__ //Expr
			Annotate126(semantic,(*(*self).reference),reference);
			#line 918 f5__ //Expr
			return ;
		};
		#line 920 f5__ //Expr
		if(Is4149((*typ))){
			#line 921 f5__ //Expr
			TypeOption421* self=As4150((*typ));
			#line 922 f5__ //Expr
			Annotate126(semantic,(*(*self).reference),reference);
			#line 923 f5__ //Expr
			return ;
		};
		#line 925 f5__ //Expr
		if(Is7156((*typ))){
			#line 926 f5__ //Expr
			return ;
		};
		#line 928 f5__ //Expr
		if(Is2145((*typ))){
			#line 929 f5__ //Expr
			return ;
		};
		#line 931 f5__ //Expr
		if(Is3147((*typ))){
			#line 932 f5__ //Expr
			return ;
		};
		#line 934 f5__ //Expr
		if(Is8200((*typ))){
			#line 935 f5__ //Expr
			return ;
		};
		#line 937 f5__ //Expr
		Assert260(0,add64(str53{30,(i8*)"No semantic annotate for type "},String66((*typ).kind)));
}
	#line 941 f5__ //Expr
	Type413* Resolved127(Type413& typ){
		#line 942 f5__ //Expr
		if(Is2145(typ)){
			#line 943 f5__ //Expr
			TypeAny425* any=As2146(typ);
			#line 944 f5__ //Expr
			if((*any).reference){
				#line 945 f5__ //Expr
				return Resolved127((*(*any).reference));
			};
		};
		#line 948 f5__ //Expr
		if(Is3147(typ)){
			#line 949 f5__ //Expr
			TypeTrait429* trai=As3148(typ);
			#line 950 f5__ //Expr
			if((*trai).reference){
				#line 951 f5__ //Expr
				return Resolved127((*(*trai).reference));
			};
		};
		#line 955 f5__ //Expr
		if(Is1143(typ)){
			#line 956 f5__ //Expr
			TypeIdentifier414* ident=As1144(typ);
			#line 957 f5__ //Expr
			Assert051((*ident).ident.chars,str53{17,(i8*)"failed in resolve"});
			#line 958 f5__ //Expr
			if((!(*ident).spec)){
			}else{
				#line 960 f5__ //Expr
				if(Is9138((*(*ident).spec))){
					#line 961 f5__ //Expr
					return Resolved127((*(*(*ident).spec).typ));
				}else{
					#line 963 f5__ //Expr
					if(Is8136((*(*ident).spec))){
						#line 964 f5__ //Expr
						return Resolved127((*(*(*ident).spec).typ));
					};
				};
			};
		};
		#line 967 f5__ //Expr
		return (&typ);
}
	#line 972 f5__ //Expr
	TypeStructure481* ResolveSpec128(Type413& typ){
		#line 973 f5__ //Expr
		Type413* t=Resolved127(typ);
		#line 974 f5__ //Expr
		if(Is6153(typ)){
			#line 975 f5__ //Expr
			TypeGeneric423* self=As6154((*t));
			#line 976 f5__ //Expr
			Assert4201((*self).referenced,str53{26,(i8*)"Generic type not annotated"});
			#line 977 f5__ //Expr
			return (*self).referenced;
		};
		#line 979 f5__ //Expr
		return (TypeStructure481*)0;
}
	#line 982 f5__ //Expr
	i8 Apply129(Semantic110& semantic,Type413* argument,Type413* parameter,Known470& known,i64 index){
		#line 983 f5__ //Expr
		Type413* arg=Resolved127((*argument));
		#line 984 f5__ //Expr
		Type413* param=Resolved127((*parameter));
		#line 985 f5__ //Expr
		i8 verbose=false;
		#line 986 f5__ //Expr
		if(((*arg).kind==(*param).kind)){
			#line 988 f5__ //Expr
			if(Is0141((*arg))){
				#line 990 f5__ //Expr
				TypeRef419* argPtr=As0142((*arg));
				#line 991 f5__ //Expr
				TypeRef419* paramPtr=As0142((*param));
				#line 993 f5__ //Expr
				return Apply129(semantic,(*argPtr).reference,(*paramPtr).reference,known,index);
			};
			#line 995 f5__ //Expr
			if(Is4149((*arg))){
				#line 997 f5__ //Expr
				TypeOption421* argPtr=As4150((*arg));
				#line 998 f5__ //Expr
				TypeOption421* paramPtr=As4150((*param));
				#line 1000 f5__ //Expr
				return Apply129(semantic,(*argPtr).reference,(*paramPtr).reference,known,index);
			};
			#line 1002 f5__ //Expr
			if(Is1143((*arg))){
				#line 1004 f5__ //Expr
				TypeIdentifier414* argIdent=As1144((*arg));
				#line 1005 f5__ //Expr
				TypeIdentifier414* paramIdent=As1144((*param));
				#line 1007 f5__ //Expr
				if(((i64)(*argIdent).spec!=(i64)(*paramIdent).spec)){
					#line 1008 f5__ //Expr
					if(verbose){
						#line 1009 f5__ //Expr
						Println59(str53{15,(i8*)"Failed in ident"});
					};
				};
				#line 1012 f5__ //Expr
				return ((i64)(*argIdent).spec==(i64)(*paramIdent).spec);
			};
			#line 1014 f5__ //Expr
			if(Is6153((*arg))){
				#line 1016 f5__ //Expr
				TypeGeneric423* argGen=As6154((*arg));
				#line 1017 f5__ //Expr
				TypeGeneric423* paramGen=As6154((*param));
				#line 1018 f5__ //Expr
				if((!Equal131((&(*(*argGen).ident).super),(&(*(*paramGen).ident).super)))){
					#line 1019 f5__ //Expr
					if(verbose){
						#line 1020 f5__ //Expr
						Println59(str53{23,(i8*)"Failed in type gen spec"});
					};
					#line 1022 f5__ //Expr
					return false;
				};
				#line 1024 f5__ //Expr
				if(((*argGen).constraints.length!=(*paramGen).constraints.length)){
					#line 1025 f5__ //Expr
					if(verbose){
						#line 1026 f5__ //Expr
						Println59(str53{17,(i8*)"Fauiled in length"});
					};
					#line 1028 f5__ //Expr
					return false;
				};
				#line 1031 f5__ //Expr
				for(i64 it = i64265(0); it<(*argGen).constraints.length;it++){
					#line 1032 f5__ //Expr
					if((!Apply129(semantic,OpArray6155((*argGen).constraints,it),OpArray6155((*paramGen).constraints,it),known,index))){
						#line 1033 f5__ //Expr
						if(verbose){
							#line 1034 f5__ //Expr
							Println59(str53{13,(i8*)"Failed in gen"});
						};
						#line 1036 f5__ //Expr
						return false;
					};
				};
				#line 1039 f5__ //Expr
				return true;
			};
			#line 1041 f5__ //Expr
			if(Is5151((*arg))){
				#line 1043 f5__ //Expr
				TypeType427* a=As5152((*arg));
				#line 1044 f5__ //Expr
				TypeType427* p=As5152((*param));
				#line 1046 f5__ //Expr
				return Apply129(semantic,(*a).reference,(*p).reference,known,index);
			};
			#line 1048 f5__ //Expr
			if(Is7156((*arg))){
				#line 1050 f5__ //Expr
				TypeNumber431* a=As7157((*arg));
				#line 1051 f5__ //Expr
				TypeNumber431* p=As7157((*param));
				#line 1053 f5__ //Expr
				if(((*a).kind!=(*p).kind)){
					#line 1054 f5__ //Expr
					if(((*a).kind==TypeNumberFloat)){
						#line 1055 f5__ //Expr
						return false;
					};
					#line 1057 f5__ //Expr
					if(((*p).kind==TypeNumberFloat)){
						#line 1058 f5__ //Expr
						return false;
					};
				};
				#line 1061 f5__ //Expr
				return ((*p).size>=(*a).size);
			};
		};
		#line 1066 f5__ //Expr
		if(Is2145((*param))){
			#line 1067 f5__ //Expr
			if(verbose){
				#line 1068 f5__ //Expr
				Print58(str53{18,(i8*)"Resolved type is: "});
				#line 1069 f5__ //Expr
				Print97((*arg));
				#line 1070 f5__ //Expr
				Print58(str53{7,(i8*)" ----- "});
			};
			#line 1075 f5__ //Expr
			if(Is5151((*arg))){
				#line 1076 f5__ //Expr
				return false;
			};
			#line 1079 f5__ //Expr
			Add471(known,param,arg);
			#line 1080 f5__ //Expr
			if(verbose){
				#line 1081 f5__ //Expr
				Print98(param);
				#line 1082 f5__ //Expr
				Println59(str53{0,(i8*)""});
			};
			#line 1084 f5__ //Expr
			return true;
		};
		#line 1087 f5__ //Expr
		if(Is0141((*arg))){
			#line 1088 f5__ //Expr
			OpArray0112(known.drefCount,index) = i8294((OpArray0112(known.drefCount,index)+1));
			#line 1089 f5__ //Expr
			return Apply129(semantic,(*As0142((*arg))).reference,param,known,index);
			#line 1091 f5__ //Expr
			if(Is5151((*arg))){
				#line 1092 f5__ //Expr
				return false;
			};
			#line 1095 f5__ //Expr
			if(verbose){
				#line 1096 f5__ //Expr
				Println59(str53{5,(i8*)"dref."});
			};
		};
		#line 1099 f5__ //Expr
		if(Is0141((*param))){
			#line 1100 f5__ //Expr
			OpArray0112(known.drefCount,index) = i8294((OpArray0112(known.drefCount,index)-1));
			#line 1101 f5__ //Expr
			if(verbose){
				#line 1102 f5__ //Expr
				Println59(str53{4,(i8*)"ref."});
			};
			#line 1104 f5__ //Expr
			return Apply129(semantic,arg,(*As0142((*param))).reference,known,index);
		};
		#line 1106 f5__ //Expr
		if(Is3147((*param))){
			#line 1108 f5__ //Expr
			if(Is3147((*arg))){
				#line 1109 f5__ //Expr
				TypeTrait429* paramTrait=As3148((*param));
				#line 1110 f5__ //Expr
				TypeTrait429* argTrait=As3148((*arg));
				#line 1111 f5__ //Expr
				if(equal1202((*argTrait).parent,(*paramTrait).parent)){
					#line 1112 f5__ //Expr
					Add471(known,param,arg);
					#line 1113 f5__ //Expr
					return true;
				};
			};
			#line 1117 f5__ //Expr
			Trait490* trai=(*As3148((*param))).trai;
			#line 1120 f5__ //Expr
			if((!equal0199((&(*trai).typeTrait.super),arg))){
				#line 1122 f5__ //Expr
				if(Implements113(semantic,(*trai),(*arg))){
					#line 1124 f5__ //Expr
					Add471(known,param,arg);
					#line 1125 f5__ //Expr
					return true;
				};
			};
		};
		#line 1130 f5__ //Expr
		if(equal0199(param,arg)){
			#line 1131 f5__ //Expr
			if(Is3147((*param))){
				#line 1132 f5__ //Expr
				Assert261(((i64)(*As3148((*param))).reference==0));
			};
			#line 1134 f5__ //Expr
			if(Is3147((*arg))){
				#line 1135 f5__ //Expr
				Assert261(((i64)(*As3148((*arg))).reference==0));
			};
			#line 1137 f5__ //Expr
			return true;
		};
		#line 1149 f5__ //Expr
		if(verbose){
			#line 1150 f5__ //Expr
			Println59(str53{23,(i8*)"Failed a bottom apply :"});
		};
		#line 1152 f5__ //Expr
		return false;
}
	#line 1155 f5__ //Expr
	i8 Equal130(DynamicArray43 left,DynamicArray43 right){
		#line 1156 f5__ //Expr
		if((left.length!=right.length)){
			#line 1157 f5__ //Expr
			return false;
		};
		#line 1160 f5__ //Expr
		for(i64 it = i64265(0); it<left.length;it++){
			#line 1161 f5__ //Expr
			if((!Equal131(OpArray6155(left,it),OpArray6155(right,it)))){
				#line 1162 f5__ //Expr
				return false;
			};
		};
		#line 1165 f5__ //Expr
		return true;
}
	#line 1168 f5__ //Expr
	i8 Equal131(Type413* from,Type413* to){
		#line 1170 f5__ //Expr
		return Equal132(from,to,false);
}
	#line 1173 f5__ //Expr
	i8 Equal132(Type413* from,Type413* to,i8 allowConversions){
		#line 1174 f5__ //Expr
		if(((i64)(!from)||(i64)(!to))){
			#line 1175 f5__ //Expr
			if((!equal0199(from,to))){
				#line 1176 f5__ //Expr
				return false;
			};
			#line 1178 f5__ //Expr
			return true;
		};
		#line 1181 f5__ //Expr
		Type413* f=Resolved127((*from));
		#line 1182 f5__ //Expr
		Type413* t=Resolved127((*to));
		#line 1184 f5__ //Expr
		if(((*f).kind!=(*t).kind)){
			#line 1185 f5__ //Expr
			return false;
		};
		#line 1188 f5__ //Expr
		if(Is0141((*f))){
			#line 1189 f5__ //Expr
			TypeRef419* fPtr=As0142((*f));
			#line 1190 f5__ //Expr
			TypeRef419* tPtr=As0142((*t));
			#line 1191 f5__ //Expr
			return Equal131((*fPtr).reference,(*tPtr).reference);
		};
		#line 1194 f5__ //Expr
		if(Is1143((*f))){
			#line 1195 f5__ //Expr
			TypeIdentifier414* fIdent=As1144((*f));
			#line 1196 f5__ //Expr
			TypeIdentifier414* tIdent=As1144((*t));
			#line 1197 f5__ //Expr
			Assert162((*fIdent).spec,str53{10,(i8*)"f spec nil"});
			#line 1198 f5__ //Expr
			Assert162((*tIdent).spec,str53{10,(i8*)"t spec nil"});
			#line 1199 f5__ //Expr
			return ((i64)(*fIdent).spec==(i64)(*tIdent).spec);
		};
		#line 1202 f5__ //Expr
		if(Is2145((*f))){
			#line 1203 f5__ //Expr
			TypeAny425* fAny=As2146((*f));
			#line 1204 f5__ //Expr
			TypeAny425* tAny=As2146((*t));
			#line 1207 f5__ //Expr
			return ((i64)(*fAny).parent==(i64)(*tAny).parent);
		};
		#line 1210 f5__ //Expr
		if(Is3147((*f))){
			#line 1211 f5__ //Expr
			TypeTrait429* fAny=As3148((*f));
			#line 1212 f5__ //Expr
			TypeTrait429* tAny=As3148((*t));
			#line 1215 f5__ //Expr
			return ((i64)(*fAny).parent==(i64)(*tAny).parent);
		};
		#line 1218 f5__ //Expr
		if(Is5151((*f))){
			#line 1219 f5__ //Expr
			TypeType427* fType=As5152((*f));
			#line 1220 f5__ //Expr
			TypeType427* tType=As5152((*t));
			#line 1221 f5__ //Expr
			return Equal131((*fType).reference,(*tType).reference);
		};
		#line 1223 f5__ //Expr
		if(Is4149((*f))){
			#line 1224 f5__ //Expr
			TypeOption421* fType=As4150((*f));
			#line 1225 f5__ //Expr
			TypeOption421* tType=As4150((*t));
			#line 1226 f5__ //Expr
			return Equal131((*fType).reference,(*tType).reference);
		};
		#line 1229 f5__ //Expr
		if(Is6153((*f))){
			#line 1231 f5__ //Expr
			TypeGeneric423* fGen=As6154((*f));
			#line 1232 f5__ //Expr
			TypeGeneric423* tGen=As6154((*t));
			#line 1233 f5__ //Expr
			Assert2203((*tGen).referenced);
			#line 1234 f5__ //Expr
			Assert2203((*fGen).referenced);
			#line 1236 f5__ //Expr
			if(equal2204((*tGen).referenced,(*fGen).referenced)){
				#line 1237 f5__ //Expr
				return true;
			};
			#line 1240 f5__ //Expr
			return false;
		};
		#line 1243 f5__ //Expr
		if(Is7156((*f))){
			#line 1244 f5__ //Expr
			TypeNumber431* fType=As7157((*f));
			#line 1245 f5__ //Expr
			TypeNumber431* tType=As7157((*t));
			#line 1246 f5__ //Expr
			return Equal0205(fType,tType);
		};
		#line 1249 f5__ //Expr
		Assert260(0,add64(str53{24,(i8*)"Unhandled type in Equal "},String66((*from).kind)));
		#line 1250 f5__ //Expr
		return false;
}
	#line 1253 f5__ //Expr
	Type413* Clone133(Type413& t){
		#line 1255 f5__ //Expr
		Type413* expr=Resolved127(t);
		#line 1257 f5__ //Expr
		if(Is0141((*expr))){
			#line 1258 f5__ //Expr
			TypeRef419* self=As0142((*expr));
			#line 1260 f5__ //Expr
			TypeRef419* out=New555();
			#line 1261 f5__ //Expr
			(*out).reference = Clone133((*(*self).reference));
			#line 1262 f5__ //Expr
			return (&(*out).super);
		};
		#line 1264 f5__ //Expr
		if(Is1143((*expr))){
			#line 1265 f5__ //Expr
			TypeIdentifier414* self=As1144((*expr));
			#line 1266 f5__ //Expr
			if(Is9138((*(*self).spec))){
				#line 1267 f5__ //Expr
				Assert261(0);
			};
			#line 1269 f5__ //Expr
			if(Is8136((*(*self).spec))){
				#line 1270 f5__ //Expr
				Assert261(0);
			};
			#line 1272 f5__ //Expr
			TypeIdentifier414* out=New22206();
			#line 1273 f5__ //Expr
			(*out).ident = (*self).ident;
			#line 1274 f5__ //Expr
			(*out).spec = (*self).spec;
			#line 1277 f5__ //Expr
			return (&(*out).super);
		};
		#line 1279 f5__ //Expr
		if(Is2145((*expr))){
			#line 1281 f5__ //Expr
			TypeAny425* self=As2146((*expr));
			#line 1283 f5__ //Expr
			if((!(*self).reference)){
				#line 1284 f5__ //Expr
				TypeAny425* out=New658();
				#line 1285 f5__ //Expr
				(*out).parent = (*self).parent;
				#line 1286 f5__ //Expr
				return (&(*out).super);
			};
			#line 1289 f5__ //Expr
			Assert261(0);
			#line 1290 f5__ //Expr
			return Clone133((*(*self).reference));
		};
		#line 1292 f5__ //Expr
		if(Is3147((*expr))){
			#line 1294 f5__ //Expr
			TypeTrait429* self=As3148((*expr));
			#line 1295 f5__ //Expr
			if((!(*self).reference)){
				#line 1296 f5__ //Expr
				TypeTrait429* out=New23209();
				#line 1297 f5__ //Expr
				(*out).trai = (*self).trai;
				#line 1298 f5__ //Expr
				(*out).parent = (*self).parent;
				#line 1299 f5__ //Expr
				return (&(*out).super);
			};
			#line 1302 f5__ //Expr
			Assert261(0);
			#line 1303 f5__ //Expr
			return Clone133((*(*self).reference));
		};
		#line 1305 f5__ //Expr
		if(Is4149((*expr))){
			#line 1306 f5__ //Expr
			TypeOption421* self=As4150((*expr));
			#line 1307 f5__ //Expr
			TypeOption421* out=New245();
			#line 1308 f5__ //Expr
			(*out).reference = Clone133((*(*self).reference));
			#line 1309 f5__ //Expr
			return (&(*out).super);
		};
		#line 1311 f5__ //Expr
		if(Is5151((*expr))){
			#line 1312 f5__ //Expr
			TypeType427* self=As5152((*expr));
			#line 1313 f5__ //Expr
			TypeType427* out=New348();
			#line 1314 f5__ //Expr
			(*out).reference = Clone133((*(*self).reference));
			#line 1315 f5__ //Expr
			return (&(*out).super);
		};
		#line 1317 f5__ //Expr
		if(Is6153((*expr))){
			#line 1318 f5__ //Expr
			TypeGeneric423* self=As6154((*expr));
			#line 1320 f5__ //Expr
			TypeGeneric423* out=New452();
			#line 1321 f5__ //Expr
			(*out).ident = (*self).ident;
			#line 1323 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 1324 f5__ //Expr
				Push137((*out).constraints,Clone133((*OpArray6155((*self).constraints,it))));
			};
			#line 1326 f5__ //Expr
			(*out).referenced = (*self).referenced;
			#line 1328 f5__ //Expr
			return (&(*out).super);
		};
		#line 1330 f5__ //Expr
		if(Is7156((*expr))){
			#line 1331 f5__ //Expr
			return expr;
		};
		#line 1333 f5__ //Expr
		if(Is8200((*expr))){
			#line 1334 f5__ //Expr
			return expr;
		};
		#line 1336 f5__ //Expr
		Println59(str53{20,(i8*)"Unhandled type visit"});
		#line 1337 f5__ //Expr
		Assert261(0);
		#line 1338 f5__ //Expr
		return (Type413*)0;
}
	#line 1342 f5__ //Expr
	Type413* CloneAny134(Type413& t,Type413*& any){
		#line 1344 f5__ //Expr
		Type413* expr=Resolved127(t);
		#line 1346 f5__ //Expr
		if(Is0141((*expr))){
			#line 1347 f5__ //Expr
			TypeRef419* self=As0142((*expr));
			#line 1349 f5__ //Expr
			TypeRef419* out=New555();
			#line 1350 f5__ //Expr
			(*out).reference = CloneAny134((*(*self).reference),any);
			#line 1351 f5__ //Expr
			return (&(*out).super);
		};
		#line 1353 f5__ //Expr
		if(Is1143((*expr))){
			#line 1354 f5__ //Expr
			TypeIdentifier414* self=As1144((*expr));
			#line 1355 f5__ //Expr
			if(Is9138((*(*self).spec))){
				#line 1356 f5__ //Expr
				Assert261(0);
				#line 1357 f5__ //Expr
				return CloneAny134((*(*As9139((*(*self).spec))).super.typ),any);
			};
			#line 1359 f5__ //Expr
			if(Is8136((*(*self).spec))){
				#line 1360 f5__ //Expr
				Assert261(0);
				#line 1361 f5__ //Expr
				return CloneAny134((*(*As8137((*(*self).spec))).super.typ),any);
			};
			#line 1363 f5__ //Expr
			TypeIdentifier414* out=New22206();
			#line 1364 f5__ //Expr
			(*out).ident = (*self).ident;
			#line 1365 f5__ //Expr
			(*out).spec = (*self).spec;
			#line 1368 f5__ //Expr
			return (&(*out).super);
		};
		#line 1370 f5__ //Expr
		if(Is2145((*expr))){
			#line 1372 f5__ //Expr
			TypeAny425* self=As2146((*expr));
			#line 1373 f5__ //Expr
			if((!(*self).reference)){
				#line 1374 f5__ //Expr
				TypeAny425* out=New658();
				#line 1375 f5__ //Expr
				(*out).parent = (*self).parent;
				#line 1376 f5__ //Expr
				any = expr;
				#line 1377 f5__ //Expr
				return (&(*out).super);
			};
			#line 1380 f5__ //Expr
			Assert261(0);
			#line 1381 f5__ //Expr
			return CloneAny134((*(*self).reference),any);
		};
		#line 1383 f5__ //Expr
		if(Is3147((*expr))){
			#line 1385 f5__ //Expr
			TypeTrait429* self=As3148((*expr));
			#line 1386 f5__ //Expr
			if((!(*self).reference)){
				#line 1387 f5__ //Expr
				TypeTrait429* out=New23209();
				#line 1388 f5__ //Expr
				(*out).trai = (*self).trai;
				#line 1389 f5__ //Expr
				(*out).parent = (*self).parent;
				#line 1390 f5__ //Expr
				any = expr;
				#line 1391 f5__ //Expr
				return (&(*out).super);
			};
			#line 1394 f5__ //Expr
			Assert261(0);
			#line 1395 f5__ //Expr
			return CloneAny134((*(*self).reference),any);
		};
		#line 1397 f5__ //Expr
		if(Is4149((*expr))){
			#line 1398 f5__ //Expr
			TypeOption421* self=As4150((*expr));
			#line 1399 f5__ //Expr
			TypeOption421* out=New245();
			#line 1400 f5__ //Expr
			(*out).reference = CloneAny134((*(*self).reference),any);
			#line 1401 f5__ //Expr
			return (&(*out).super);
		};
		#line 1403 f5__ //Expr
		if(Is5151((*expr))){
			#line 1404 f5__ //Expr
			TypeType427* self=As5152((*expr));
			#line 1405 f5__ //Expr
			TypeType427* out=New348();
			#line 1406 f5__ //Expr
			(*out).reference = CloneAny134((*(*self).reference),any);
			#line 1407 f5__ //Expr
			return (&(*out).super);
		};
		#line 1409 f5__ //Expr
		if(Is6153((*expr))){
			#line 1410 f5__ //Expr
			TypeGeneric423* self=As6154((*expr));
			#line 1412 f5__ //Expr
			TypeGeneric423* out=New452();
			#line 1413 f5__ //Expr
			(*out).ident = (*self).ident;
			#line 1415 f5__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 1416 f5__ //Expr
				Push137((*out).constraints,CloneAny134((*OpArray6155((*self).constraints,it)),any));
			};
			#line 1418 f5__ //Expr
			(*out).referenced = (*self).referenced;
			#line 1422 f5__ //Expr
			return (&(*out).super);
		};
		#line 1424 f5__ //Expr
		if(Is7156((*expr))){
			#line 1425 f5__ //Expr
			return expr;
		};
		#line 1427 f5__ //Expr
		if(Is8200((*expr))){
			#line 1428 f5__ //Expr
			return expr;
		};
		#line 1430 f5__ //Expr
		Println59(str53{20,(i8*)"Unhandled type visit"});
		#line 1431 f5__ //Expr
		Assert261(0);
		#line 1432 f5__ //Expr
		return (Type413*)0;
}
		#line 107 f6__ //Expr
	void Create136(Intrinsics135& self,Function456& func,Semantic110& semantic,str53 ident,Type413& t,Type413& r){
		#line 109 f6__ //Expr
		Init458(func);
		#line 110 f6__ //Expr
		Variable498* field=Variable500();
		#line 111 f6__ //Expr
		(*field).super.typ = (&t);
		#line 112 f6__ //Expr
		func.ident = ident;
		#line 113 f6__ //Expr
		Add371(func.params,(&(*field).super));
		#line 114 f6__ //Expr
		Add371(func.params,(&(*field).super));
		#line 115 f6__ //Expr
		func.result = (&r);
		#line 116 f6__ //Expr
		Declare119(semantic,func.super);
}
	#line 118 f6__ //Expr
	void Convert137(Intrinsics135& self,Semantic110& semantic,Function456& func,Structure473& from,Structure473& to){
		#line 119 f6__ //Expr
		Variable498* field=Variable500();
		#line 120 f6__ //Expr
		(*field).super.typ = from.typeIdent;
		#line 122 f6__ //Expr
		Assert2140(from.typeIdent,from.ident);
		#line 124 f6__ //Expr
		Init458(func);
		#line 125 f6__ //Expr
		func.ident = to.ident;
		#line 126 f6__ //Expr
		Add371(func.params,(&(*field).super));
		#line 127 f6__ //Expr
		func.result = to.typeIdent;
		#line 128 f6__ //Expr
		Declare119(semantic,func.super);
}
	#line 132 f6__ //Expr
	void Init138(Intrinsics135& self,Semantic110& semantic,Block434& ast){
		#line 134 f6__ //Expr
		Init474(self.voidptr_);
		#line 135 f6__ //Expr
		self.voidptr_.ident = str53{7,(i8*)"voidptr"};
		#line 136 f6__ //Expr
		Declare119(semantic,self.voidptr_.super);
		#line 137 f6__ //Expr
		self.voidptr_.incomplete = true;
		#line 140 f6__ //Expr
		{
			#line 140 f6__ //Expr
			TypeAs367* as=New19165();
			#line 141 f6__ //Expr
			(*as).ident = str53{2,(i8*)"i8"};
			#line 142 f6__ //Expr
			(*as).super.typ = (&(*i8Type).super);
			#line 143 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 146 f6__ //Expr
		{
			#line 146 f6__ //Expr
			TypeAs367* as=New19165();
			#line 147 f6__ //Expr
			(*as).ident = str53{3,(i8*)"i16"};
			#line 148 f6__ //Expr
			(*as).super.typ = (&(*i16Type).super);
			#line 149 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 152 f6__ //Expr
		{
			#line 152 f6__ //Expr
			TypeAs367* as=New19165();
			#line 153 f6__ //Expr
			(*as).ident = str53{3,(i8*)"i32"};
			#line 154 f6__ //Expr
			(*as).super.typ = (&(*i32Type).super);
			#line 155 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 158 f6__ //Expr
		{
			#line 158 f6__ //Expr
			TypeAs367* as=New19165();
			#line 159 f6__ //Expr
			(*as).ident = str53{3,(i8*)"i64"};
			#line 160 f6__ //Expr
			(*as).super.typ = (&(*i64Type).super);
			#line 161 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 165 f6__ //Expr
		{
			#line 165 f6__ //Expr
			TypeAs367* as=New19165();
			#line 166 f6__ //Expr
			(*as).ident = str53{2,(i8*)"u8"};
			#line 167 f6__ //Expr
			(*as).super.typ = (&(*u8Type).super);
			#line 168 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 171 f6__ //Expr
		{
			#line 171 f6__ //Expr
			TypeAs367* as=New19165();
			#line 172 f6__ //Expr
			(*as).ident = str53{3,(i8*)"u16"};
			#line 173 f6__ //Expr
			(*as).super.typ = (&(*u16Type).super);
			#line 174 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 177 f6__ //Expr
		{
			#line 177 f6__ //Expr
			TypeAs367* as=New19165();
			#line 178 f6__ //Expr
			(*as).ident = str53{3,(i8*)"u32"};
			#line 179 f6__ //Expr
			(*as).super.typ = (&(*u32Type).super);
			#line 180 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 183 f6__ //Expr
		{
			#line 183 f6__ //Expr
			TypeAs367* as=New19165();
			#line 184 f6__ //Expr
			(*as).ident = str53{3,(i8*)"u64"};
			#line 185 f6__ //Expr
			(*as).super.typ = (&(*u64Type).super);
			#line 186 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 189 f6__ //Expr
		{
			#line 189 f6__ //Expr
			TypeAs367* as=New19165();
			#line 190 f6__ //Expr
			(*as).ident = str53{3,(i8*)"f32"};
			#line 191 f6__ //Expr
			(*as).super.typ = (&(*f32Type).super);
			#line 192 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 195 f6__ //Expr
		{
			#line 195 f6__ //Expr
			TypeAs367* as=New19165();
			#line 196 f6__ //Expr
			(*as).ident = str53{3,(i8*)"f64"};
			#line 197 f6__ //Expr
			(*as).super.typ = (&(*f64Type).super);
			#line 198 f6__ //Expr
			Declare119(semantic,(*as).super);
;
		}
		#line 203 f6__ //Expr
		TypeAny425* any=New658();
		#line 204 f6__ //Expr
		(*any).ident = str53{1,(i8*)"T"};
		#line 205 f6__ //Expr
		Variable498* any_field=Variable500();
		#line 206 f6__ //Expr
		(*any_field).super.typ = (&(*any).super);
		#line 209 f6__ //Expr
		Variable498* i64_field=Variable500();
		#line 210 f6__ //Expr
		(*i64_field).super.typ = (&(*i64Type).super);
		#line 212 f6__ //Expr
		Init458(self.ptr_add);
		#line 213 f6__ //Expr
		self.ptr_add.ident = str53{6,(i8*)"PtrAdd"};
		#line 214 f6__ //Expr
		Add371(self.ptr_add.params,(&(*any_field).super));
		#line 215 f6__ //Expr
		Add371(self.ptr_add.params,(&(*i64_field).super));
		#line 216 f6__ //Expr
		self.ptr_add.result = (&(*any).super);
		#line 218 f6__ //Expr
		Add441(ast,(&self.ptr_add.super));
		#line 221 f6__ //Expr
		{
			#line 221 f6__ //Expr
			TypeAny425* any=New658();
			#line 222 f6__ //Expr
			(*any).ident = str53{1,(i8*)"T"};
			#line 223 f6__ //Expr
			Variable498* any_field=Variable500();
			#line 224 f6__ //Expr
			(*any_field).super.typ = (&(*any).super);
			#line 226 f6__ //Expr
			TypeRef419* refer=New555();
			#line 227 f6__ //Expr
			(*refer).reference = (&(*any).super);
			#line 229 f6__ //Expr
			Init458(self.reference);
			#line 230 f6__ //Expr
			self.reference.ident = str53{1,(i8*)"&"};
			#line 231 f6__ //Expr
			Add371(self.reference.params,(&(*any_field).super));
			#line 232 f6__ //Expr
			self.reference.result = (&(*refer).super);
			#line 234 f6__ //Expr
			Add441(ast,(&self.reference.super));
;
		}
		#line 238 f6__ //Expr
		{
			#line 238 f6__ //Expr
			TypeAny425* any=New658();
			#line 239 f6__ //Expr
			(*any).ident = str53{1,(i8*)"T"};
			#line 241 f6__ //Expr
			TypeRef419* refer=New555();
			#line 242 f6__ //Expr
			(*refer).reference = (&(*any).super);
			#line 244 f6__ //Expr
			Variable498* param=Variable500();
			#line 245 f6__ //Expr
			(*param).super.typ = (&(*refer).super);
			#line 248 f6__ //Expr
			TypeIdentifier414* ident=New22206();
			#line 249 f6__ //Expr
			(*ident).ident = str53{1,(i8*)"T"};
			#line 251 f6__ //Expr
			Init458(self.dereference);
			#line 252 f6__ //Expr
			self.dereference.ident = str53{4,(i8*)"dref"};
			#line 253 f6__ //Expr
			Add371(self.dereference.params,(&(*param).super));
			#line 254 f6__ //Expr
			self.dereference.result = (&(*any).super);
			#line 256 f6__ //Expr
			Add441(ast,(&self.dereference.super));
;
		}
		#line 260 f6__ //Expr
		{
			#line 260 f6__ //Expr
			TypeAny425* in=New658();
			#line 261 f6__ //Expr
			(*in).ident = str53{2,(i8*)"To"};
			#line 262 f6__ //Expr
			TypeType427* inOf=New348();
			#line 263 f6__ //Expr
			(*inOf).reference = (&(*in).super);
			#line 265 f6__ //Expr
			Variable498* toParam=Variable500();
			#line 266 f6__ //Expr
			(*toParam).super.typ = (&(*inOf).super);
			#line 268 f6__ //Expr
			TypeAny425* out=New658();
			#line 269 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 271 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 272 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 274 f6__ //Expr
			Init458(self.castOp);
			#line 275 f6__ //Expr
			self.castOp.ident = str53{4,(i8*)"cast"};
			#line 276 f6__ //Expr
			Add371(self.castOp.params,(&(*toParam).super));
			#line 277 f6__ //Expr
			Add371(self.castOp.params,(&(*fromParam).super));
			#line 278 f6__ //Expr
			self.castOp.result = (&(*in).super);
			#line 279 f6__ //Expr
			Add441(ast,(&self.castOp.super));
;
		}
		#line 284 f6__ //Expr
		{
			#line 284 f6__ //Expr
			TypeAny425* in=New658();
			#line 285 f6__ //Expr
			(*in).ident = str53{1,(i8*)"T"};
			#line 286 f6__ //Expr
			TypeType427* inOf=New348();
			#line 287 f6__ //Expr
			(*inOf).reference = (&(*in).super);
			#line 288 f6__ //Expr
			Variable498* toParam=Variable500();
			#line 289 f6__ //Expr
			(*toParam).super.typ = (&(*inOf).super);
			#line 291 f6__ //Expr
			Init458(self.sizeFn);
			#line 292 f6__ //Expr
			self.sizeFn.ident = str53{4,(i8*)"Size"};
			#line 293 f6__ //Expr
			Add371(self.sizeFn.params,(&(*toParam).super));
			#line 294 f6__ //Expr
			self.sizeFn.result = (&(*i64Type).super);
			#line 295 f6__ //Expr
			Add441(ast,(&self.sizeFn.super));
;
		}
		#line 298 f6__ //Expr
		Init458(self.abortFn);
		#line 299 f6__ //Expr
		self.abortFn.ident = str53{5,(i8*)"abort"};
		#line 300 f6__ //Expr
		Declare119(semantic,self.abortFn.super);
		#line 305 f6__ //Expr
		{
			#line 305 f6__ //Expr
			TypeAny425* out=New658();
			#line 306 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 307 f6__ //Expr
			(*out).required = Id410();
			#line 309 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 310 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 312 f6__ //Expr
			Init458(self.to_i8);
			#line 313 f6__ //Expr
			self.to_i8.ident = str53{2,(i8*)"i8"};
			#line 314 f6__ //Expr
			Add371(self.to_i8.params,(&(*fromParam).super));
			#line 315 f6__ //Expr
			self.to_i8.result = (&(*i8Type).super);
			#line 316 f6__ //Expr
			Add441(ast,(&self.to_i8.super));
;
		}
		#line 319 f6__ //Expr
		{
			#line 319 f6__ //Expr
			TypeAny425* out=New658();
			#line 320 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 321 f6__ //Expr
			(*out).required = Id410();
			#line 323 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 324 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 326 f6__ //Expr
			Init458(self.to_i16);
			#line 327 f6__ //Expr
			self.to_i16.ident = str53{3,(i8*)"i16"};
			#line 328 f6__ //Expr
			Add371(self.to_i16.params,(&(*fromParam).super));
			#line 329 f6__ //Expr
			self.to_i16.result = (&(*i16Type).super);
			#line 330 f6__ //Expr
			Add441(ast,(&self.to_i16.super));
;
		}
		#line 333 f6__ //Expr
		{
			#line 333 f6__ //Expr
			TypeAny425* out=New658();
			#line 334 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 335 f6__ //Expr
			(*out).required = Id410();
			#line 337 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 338 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 340 f6__ //Expr
			Init458(self.to_i32);
			#line 341 f6__ //Expr
			self.to_i32.ident = str53{3,(i8*)"i32"};
			#line 342 f6__ //Expr
			Add371(self.to_i32.params,(&(*fromParam).super));
			#line 343 f6__ //Expr
			self.to_i32.result = (&(*i32Type).super);
			#line 344 f6__ //Expr
			Add441(ast,(&self.to_i32.super));
;
		}
		#line 347 f6__ //Expr
		{
			#line 347 f6__ //Expr
			TypeAny425* out=New658();
			#line 348 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 349 f6__ //Expr
			(*out).required = Id410();
			#line 351 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 352 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 354 f6__ //Expr
			Init458(self.to_i64);
			#line 355 f6__ //Expr
			self.to_i64.ident = str53{3,(i8*)"i64"};
			#line 356 f6__ //Expr
			Add371(self.to_i64.params,(&(*fromParam).super));
			#line 357 f6__ //Expr
			self.to_i64.result = (&(*i64Type).super);
			#line 358 f6__ //Expr
			Add441(ast,(&self.to_i64.super));
;
		}
		#line 361 f6__ //Expr
		{
			#line 361 f6__ //Expr
			TypeAny425* out=New658();
			#line 362 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 363 f6__ //Expr
			(*out).required = Id410();
			#line 365 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 366 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 368 f6__ //Expr
			Init458(self.to_u8);
			#line 369 f6__ //Expr
			self.to_u8.ident = str53{2,(i8*)"u8"};
			#line 370 f6__ //Expr
			Add371(self.to_u8.params,(&(*fromParam).super));
			#line 371 f6__ //Expr
			self.to_u8.result = (&(*u8Type).super);
			#line 372 f6__ //Expr
			Add441(ast,(&self.to_u8.super));
;
		}
		#line 375 f6__ //Expr
		{
			#line 375 f6__ //Expr
			TypeAny425* out=New658();
			#line 376 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 377 f6__ //Expr
			(*out).required = Id410();
			#line 379 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 380 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 382 f6__ //Expr
			Init458(self.to_u16);
			#line 383 f6__ //Expr
			self.to_u16.ident = str53{3,(i8*)"u16"};
			#line 384 f6__ //Expr
			Add371(self.to_u16.params,(&(*fromParam).super));
			#line 385 f6__ //Expr
			self.to_u16.result = (&(*u16Type).super);
			#line 386 f6__ //Expr
			Add441(ast,(&self.to_u16.super));
;
		}
		#line 390 f6__ //Expr
		{
			#line 390 f6__ //Expr
			TypeAny425* out=New658();
			#line 391 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 392 f6__ //Expr
			(*out).required = Id410();
			#line 394 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 395 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 397 f6__ //Expr
			Init458(self.to_u32);
			#line 398 f6__ //Expr
			self.to_u32.ident = str53{3,(i8*)"u32"};
			#line 399 f6__ //Expr
			Add371(self.to_u32.params,(&(*fromParam).super));
			#line 400 f6__ //Expr
			self.to_u32.result = (&(*u32Type).super);
			#line 401 f6__ //Expr
			Add441(ast,(&self.to_u32.super));
;
		}
		#line 405 f6__ //Expr
		{
			#line 405 f6__ //Expr
			TypeAny425* out=New658();
			#line 406 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 407 f6__ //Expr
			(*out).required = Id410();
			#line 409 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 410 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 412 f6__ //Expr
			Init458(self.to_u64);
			#line 413 f6__ //Expr
			self.to_u64.ident = str53{3,(i8*)"u64"};
			#line 414 f6__ //Expr
			Add371(self.to_u64.params,(&(*fromParam).super));
			#line 415 f6__ //Expr
			self.to_u64.result = (&(*u64Type).super);
			#line 416 f6__ //Expr
			Add441(ast,(&self.to_u64.super));
;
		}
		#line 419 f6__ //Expr
		{
			#line 419 f6__ //Expr
			TypeAny425* out=New658();
			#line 420 f6__ //Expr
			(*out).ident = str53{4,(i8*)"From"};
			#line 421 f6__ //Expr
			(*out).required = Id410();
			#line 423 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 424 f6__ //Expr
			(*fromParam).super.typ = (&(*out).super);
			#line 426 f6__ //Expr
			Init458(self.to_f32);
			#line 427 f6__ //Expr
			self.to_f32.ident = str53{3,(i8*)"f32"};
			#line 428 f6__ //Expr
			Add371(self.to_f32.params,(&(*fromParam).super));
			#line 429 f6__ //Expr
			self.to_f32.result = (&(*f32Type).super);
			#line 430 f6__ //Expr
			Add441(ast,(&self.to_f32.super));
;
		}
		#line 434 f6__ //Expr
		{
			#line 434 f6__ //Expr
			Variable498* fromParam=Variable500();
			#line 435 f6__ //Expr
			(*fromParam).super.typ = (&(*i8Type).super);
			#line 437 f6__ //Expr
			Init458(self.invert);
			#line 438 f6__ //Expr
			self.invert.ident = str53{1,(i8*)"!"};
			#line 439 f6__ //Expr
			Add371(self.invert.params,(&(*fromParam).super));
			#line 440 f6__ //Expr
			self.invert.result = (&(*i8Type).super);
			#line 441 f6__ //Expr
			Add441(ast,(&self.invert.super));
;
		}
		#line 448 f6__ //Expr
		Create136(self,self.mul_f32,semantic,str53{1,(i8*)"*"},(*f32Type).super,(*f32Type).super);
		#line 449 f6__ //Expr
		Create136(self,self.add_f32,semantic,str53{1,(i8*)"+"},(*f32Type).super,(*f32Type).super);
		#line 450 f6__ //Expr
		Create136(self,self.sub_f32,semantic,str53{1,(i8*)"-"},(*f32Type).super,(*f32Type).super);
		#line 451 f6__ //Expr
		Create136(self,self.div_f32,semantic,str53{1,(i8*)"/"},(*f32Type).super,(*f32Type).super);
		#line 452 f6__ //Expr
		Create136(self,self.mod_f32,semantic,str53{1,(i8*)"%"},(*f32Type).super,(*f32Type).super);
		#line 454 f6__ //Expr
		Create136(self,self.mul_i64,semantic,str53{1,(i8*)"*"},(*i64Type).super,(*i64Type).super);
		#line 455 f6__ //Expr
		Create136(self,self.add_i64,semantic,str53{1,(i8*)"+"},(*i64Type).super,(*i64Type).super);
		#line 456 f6__ //Expr
		Create136(self,self.sub_i64,semantic,str53{1,(i8*)"-"},(*i64Type).super,(*i64Type).super);
		#line 457 f6__ //Expr
		Create136(self,self.div_i64,semantic,str53{1,(i8*)"/"},(*i64Type).super,(*i64Type).super);
		#line 458 f6__ //Expr
		Create136(self,self.mod_i64,semantic,str53{1,(i8*)"%"},(*i64Type).super,(*i64Type).super);
		#line 460 f6__ //Expr
		Create136(self,self.mul_i32,semantic,str53{1,(i8*)"*"},(*i32Type).super,(*i32Type).super);
		#line 461 f6__ //Expr
		Create136(self,self.add_i32,semantic,str53{1,(i8*)"+"},(*i32Type).super,(*i32Type).super);
		#line 462 f6__ //Expr
		Create136(self,self.sub_i32,semantic,str53{1,(i8*)"-"},(*i32Type).super,(*i32Type).super);
		#line 463 f6__ //Expr
		Create136(self,self.div_i32,semantic,str53{1,(i8*)"/"},(*i32Type).super,(*i32Type).super);
		#line 464 f6__ //Expr
		Create136(self,self.mod_i32,semantic,str53{1,(i8*)"%"},(*i32Type).super,(*i32Type).super);
		#line 467 f6__ //Expr
		Create136(self,self.notEq,semantic,str53{2,(i8*)"!="},(*i64Type).super,(*i8Type).super);
		#line 468 f6__ //Expr
		Create136(self,self.isEq,semantic,str53{2,(i8*)"=="},(*i64Type).super,(*i8Type).super);
		#line 469 f6__ //Expr
		Create136(self,self.less,semantic,str53{1,(i8*)"<"},(*i64Type).super,(*i8Type).super);
		#line 470 f6__ //Expr
		Create136(self,self.lessEq,semantic,str53{2,(i8*)"<="},(*i64Type).super,(*i8Type).super);
		#line 471 f6__ //Expr
		Create136(self,self.greater,semantic,str53{1,(i8*)">"},(*i64Type).super,(*i8Type).super);
		#line 472 f6__ //Expr
		Create136(self,self.greaterEq,semantic,str53{2,(i8*)">="},(*i64Type).super,(*i8Type).super);
		#line 474 f6__ //Expr
		Create136(self,self.and_,semantic,str53{2,(i8*)"&&"},(*i8Type).super,(*i8Type).super);
		#line 475 f6__ //Expr
		Create136(self,self.or_,semantic,str53{2,(i8*)"||"},(*i8Type).super,(*i8Type).super);
		#line 478 f6__ //Expr
		Array4212 types={0};
		#line 479 f6__ //Expr
		Init1213(types,10);
		#line 480 f6__ //Expr
		OpArray1215(types,0) = u8Type;
		#line 481 f6__ //Expr
		OpArray1215(types,1) = u16Type;
		#line 482 f6__ //Expr
		OpArray1215(types,2) = u32Type;
		#line 483 f6__ //Expr
		OpArray1215(types,3) = u64Type;
		#line 485 f6__ //Expr
		OpArray1215(types,4) = i8Type;
		#line 486 f6__ //Expr
		OpArray1215(types,5) = i16Type;
		#line 487 f6__ //Expr
		OpArray1215(types,6) = i32Type;
		#line 488 f6__ //Expr
		OpArray1215(types,7) = i64Type;
		#line 490 f6__ //Expr
		OpArray1215(types,8) = f32Type;
		#line 491 f6__ //Expr
		OpArray1215(types,9) = f64Type;
		#line 493 f6__ //Expr
		Init2216(self.to_,(10*10));
		#line 495 f6__ //Expr
		i64 at={0};
		#line 496 f6__ //Expr
		for(i64 it = i64265(0); it<10;it++){
			#line 497 f6__ //Expr
			TypeNumber431* to=OpArray1215(types,it);
			#line 498 f6__ //Expr
			str53 name=Mangle143((&(*to).super));
			#line 500 f6__ //Expr
			for(i64 it = i64265(0); it<10;it++){
				#line 502 f6__ //Expr
				TypeNumber431* from=OpArray1215(types,it);
				#line 503 f6__ //Expr
				Variable498* fromParam=Variable500();
				#line 504 f6__ //Expr
				(*fromParam).super.typ = (&(*from).super);
				#line 506 f6__ //Expr
				Init458(OpArray2218(self.to_,at));
				#line 507 f6__ //Expr
				OpArray2218(self.to_,at).ident = name;
				#line 508 f6__ //Expr
				Add371(OpArray2218(self.to_,at).params,(&(*fromParam).super));
				#line 509 f6__ //Expr
				OpArray2218(self.to_,at).result = (&(*to).super);
				#line 510 f6__ //Expr
				Add441(ast,(&OpArray2218(self.to_,at).super));
				#line 511 f6__ //Expr
				at = (at+1);
			};
		};
}
	#line 516 f6__ //Expr
	void IsIntrinsic139(Intrinsics135& intrinsics,Structure473* structure){
}
	#line 520 f6__ //Expr
	i8 IsIntrinsic140(Intrinsics135& intrinsics,Function456* function){
		#line 521 f6__ //Expr
		if((((i64)function>(i64)(&intrinsics.fnBegin))&&((i64)function<(i64)(&intrinsics.fnEnd)))){
			#line 522 f6__ //Expr
			return true;
		};
		#line 524 f6__ //Expr
		if((((i64)function>=(i64)(&OpArray2218(intrinsics.to_,0)))&&((i64)function<=(i64)(&OpArray2218(intrinsics.to_,99))))){
			#line 525 f6__ //Expr
			return true;
		};
		#line 527 f6__ //Expr
		if(equal3219(function,(&intrinsics.notEq))){
			#line 528 f6__ //Expr
			return true;
		};
		#line 530 f6__ //Expr
		if(equal3219(function,(&intrinsics.isEq))){
			#line 531 f6__ //Expr
			return true;
		};
		#line 533 f6__ //Expr
		if(equal3219(function,(&intrinsics.less))){
			#line 534 f6__ //Expr
			return true;
		};
		#line 536 f6__ //Expr
		if(equal3219(function,(&intrinsics.lessEq))){
			#line 537 f6__ //Expr
			return true;
		};
		#line 539 f6__ //Expr
		if(equal3219(function,(&intrinsics.greater))){
			#line 540 f6__ //Expr
			return true;
		};
		#line 542 f6__ //Expr
		if(equal3219(function,(&intrinsics.greaterEq))){
			#line 543 f6__ //Expr
			return true;
		};
		#line 545 f6__ //Expr
		return false;
}
	#line 5 f7__ //Expr
	;
		#line 16 f7__ //Expr
	void Indent142(GenerateBasic141& self){
		#line 17 f7__ //Expr
		for(i32 it = i32274(0); it<self.indent;it++){
			#line 18 f7__ //Expr
			Write148((*self.impl),str53{1,(i8*)"\t"});
		};
}
	#line 22 f7__ //Expr
	str53 Mangle143(Type413* self){
		#line 23 f7__ //Expr
		Type413* t=Resolved127((*self));
		#line 24 f7__ //Expr
		if(Is3147((*t))){
			#line 25 f7__ //Expr
			return str53{11,(i8*)"<typeTrait>"};
		};
		#line 27 f7__ //Expr
		if(Is2145((*t))){
			#line 28 f7__ //Expr
			return str53{9,(i8*)"<TypeAny>"};
		};
		#line 30 f7__ //Expr
		if(Is5151((*t))){
			#line 31 f7__ //Expr
			return add64(str53{7,(i8*)"_typeof"},Mangle143((*As5152((*t))).reference));
		};
		#line 33 f7__ //Expr
		if(Is0141((*t))){
			#line 34 f7__ //Expr
			return add64(str53{5,(i8*)"_ref_"},Mangle143((*As0142((*t))).reference));
		};
		#line 36 f7__ //Expr
		if(Is1143((*t))){
			#line 37 f7__ //Expr
			TypeIdentifier414* ident=As1144((*t));
			#line 38 f7__ //Expr
			if((!(*ident).spec)){
				#line 39 f7__ //Expr
				return str53{5,(i8*)"_nil_"};
			}else{
				#line 41 f7__ //Expr
				if(Is2123((*(*ident).spec))){
					#line 42 f7__ //Expr
					return Name144((*As2124((*(*ident).spec))));
				}else{
					#line 45 f7__ //Expr
					return str53{3,(i8*)"_t_"};
				};
			};
		};
		#line 48 f7__ //Expr
		if(Is6153((*t))){
			#line 49 f7__ //Expr
			TypeGeneric423* gen=As6154((*t));
			#line 50 f7__ //Expr
			return Mangle143((&(*(*gen).referenced).super));
		};
		#line 52 f7__ //Expr
		if(Is8200((*t))){
			#line 53 f7__ //Expr
			TypeStructure481* self=As8223((*t));
			#line 54 f7__ //Expr
			str53 out=(*(*self).parent).ident;
			#line 55 f7__ //Expr
			if((*self).constraints.length){
				#line 56 f7__ //Expr
				out = add64(out,str53{1,(i8*)"_"});
			};
			#line 58 f7__ //Expr
			if((*self).incomplete){
				#line 59 f7__ //Expr
				out = add64(add64(str53{5,(i8*)"<inc>"},out),str53{5,(i8*)"<inc>"});
			};
			#line 61 f7__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 62 f7__ //Expr
				out = add64(out,Mangle143(OpArray6155((*self).constraints,it)));
			};
			#line 64 f7__ //Expr
			return out;
		};
		#line 66 f7__ //Expr
		if(Is7156((*t))){
			#line 67 f7__ //Expr
			TypeNumber431* self=As7157((*t));
			#line 68 f7__ //Expr
			if(((*self).kind==TypeNumberInteger)){
				#line 69 f7__ //Expr
				return add64(str53{1,(i8*)"i"},String66(((*self).size*8)));
			}else{
				#line 71 f7__ //Expr
				if(((*self).kind==TypeNumberUnsigned)){
					#line 72 f7__ //Expr
					return add64(str53{1,(i8*)"u"},String66(((*self).size*8)));
				}else{
					#line 74 f7__ //Expr
					if(((*self).kind==TypeNumberFloat)){
						#line 75 f7__ //Expr
						return add64(str53{1,(i8*)"f"},String66(((*self).size*8)));
					}else{
						#line 78 f7__ //Expr
						Assert261(0);
					};
				};
			};
			#line 80 f7__ //Expr
			return str53{0,(i8*)""};
		};
		#line 82 f7__ //Expr
		return str53{0,(i8*)""};
}
	#line 86 f7__ //Expr
	str53 Name144(Structure473& self){
		#line 87 f7__ //Expr
		str53 out=self.ident;
		#line 88 f7__ //Expr
		for(i64 it = i64265(0); it<self.constraints.length;it++){
			#line 89 f7__ //Expr
			out = add64(add64(out,Mangle143(OpArray6155(self.constraints,it))),str53{12,(i8*)"_incomplete_"});
		};
		#line 91 f7__ //Expr
		return out;
}
	#line 94 f7__ //Expr
	str53 Name145(Function456& self){
		#line 95 f7__ //Expr
		str53 out=OpArray0224(remapped,self.ident);
		#line 96 f7__ //Expr
		if((out.length==0)){
			#line 97 f7__ //Expr
			out = self.ident;
		};
		#line 100 f7__ //Expr
		if(self.spec){
			#line 101 f7__ //Expr
			return Name146((*self.spec));
		}else{
			#line 104 f7__ //Expr
			if(self.block){
				#line 105 f7__ //Expr
				out = add64(out,str53{1,(i8*)"_"});
				#line 107 f7__ //Expr
				for(i64 it = i64265(0); it<self.params.list.length;it++){
					#line 108 f7__ //Expr
					out = add64(out,Mangle143((*OpArray4122(self.params.list,it)).typ));
				};
			};
		};
		#line 115 f7__ //Expr
		return out;
}
	#line 118 f7__ //Expr
	str53 Name146(FunctionSpec460& self){
		#line 119 f7__ //Expr
		str53 out=OpArray0224(remapped,(*self.function).ident);
		#line 120 f7__ //Expr
		if((out.length==0)){
			#line 121 f7__ //Expr
			out = (*self.function).ident;
		};
		#line 123 f7__ //Expr
		for(i64 it = i64265(0); it<self.params.length;it++){
			#line 124 f7__ //Expr
			out = add64(out,Mangle143(OpArray6155(self.params,it)));
		};
		#line 127 f7__ //Expr
		return out;
}
	#line 132 f7__ //Expr
	void Init147(GenerateBasic141& generate,Semantic110& semantic,Block434& ast){
		#line 134 f7__ //Expr
		generate.semantic = (&semantic);
		#line 135 f7__ //Expr
		generate.header = FileOpen(str53{13,(i8*)"build/strap.h"}.chars,str53{1,(i8*)"w"}.chars);
		#line 136 f7__ //Expr
		generate.impl = FileOpen(str53{15,(i8*)"build/strap.cpp"}.chars,str53{1,(i8*)"w"}.chars);
		#line 137 f7__ //Expr
		generate.types = FileOpen(str53{13,(i8*)"build/types.h"}.chars,str53{1,(i8*)"w"}.chars);
		#line 139 f7__ //Expr
		Assert260(((i64)generate.header!=0),str53{8,(i8*)"Bad file"});
		#line 140 f7__ //Expr
		Assert260(((i64)generate.impl!=0),str53{8,(i8*)"Bad file"});
		#line 142 f7__ //Expr
		Init0229(remapped);
		#line 143 f7__ //Expr
		OpArray0224(remapped,str53{1,(i8*)"*"}) = str53{5,(i8*)"_mul_"};
		#line 144 f7__ //Expr
		OpArray0224(remapped,str53{1,(i8*)"+"}) = str53{5,(i8*)"_add_"};
		#line 145 f7__ //Expr
		OpArray0224(remapped,str53{1,(i8*)"-"}) = str53{5,(i8*)"_sub_"};
		#line 146 f7__ //Expr
		OpArray0224(remapped,str53{1,(i8*)"/"}) = str53{5,(i8*)"_div_"};
		#line 148 f7__ //Expr
		OpArray0224(remapped,str53{2,(i8*)"[]"}) = str53{9,(i8*)"_bracket_"};
		#line 149 f7__ //Expr
		OpArray0224(remapped,str53{1,(i8*)"<"}) = str53{6,(i8*)"_less_"};
		#line 150 f7__ //Expr
		OpArray0224(remapped,str53{2,(i8*)"<="}) = str53{8,(i8*)"_lessEq_"};
		#line 151 f7__ //Expr
		OpArray0224(remapped,str53{1,(i8*)">"}) = str53{9,(i8*)"_greater_"};
		#line 152 f7__ //Expr
		OpArray0224(remapped,str53{2,(i8*)">="}) = str53{11,(i8*)"_greaterEq_"};
		#line 153 f7__ //Expr
		OpArray0224(remapped,str53{2,(i8*)"=="}) = str53{4,(i8*)"_eq_"};
		#line 154 f7__ //Expr
		OpArray0224(remapped,str53{2,(i8*)"!="}) = str53{7,(i8*)"_notEq_"};
		#line 157 f7__ //Expr
		Write148((*generate.impl),str53{19,(i8*)"#include \"strap.h\"\n"});
		#line 158 f7__ //Expr
		Write148((*generate.types),str53{20,(i8*)"#include \"header.h\"\n"});
		#line 159 f7__ //Expr
		Write148((*generate.header),str53{19,(i8*)"#include \"types.h\"\n"});
		#line 161 f7__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 162 f7__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 163 f7__ //Expr
			if(Is7134((*expr))){
				#line 164 f7__ //Expr
				Visit150(generate,(*expr));
				#line 165 f7__ //Expr
				Write148((*generate.impl),str53{2,(i8*)";\n"});
			};
		};
		#line 169 f7__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 170 f7__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 171 f7__ //Expr
			if(Is2123((*expr))){
			}else{
				#line 172 f7__ //Expr
				if(Is7134((*expr))){
				}else{
					#line 174 f7__ //Expr
					Visit150(generate,(*expr));
				};
			};
		};
		#line 178 f7__ //Expr
		Print58(add64(str53{24,(i8*)"gSpecializations.length "},String66(gSpecializations.length)));
		#line 179 f7__ //Expr
		for(i64 it = i64265(0); it<gSpecializations.length;it++){
			#line 180 f7__ //Expr
			FunctionSpec460* spec=OpArray11230(gSpecializations,it);
			#line 181 f7__ //Expr
			if((!(*spec).incomplete)){
				#line 183 f7__ //Expr
				if((!(*spec).incomplete)){
					#line 184 f7__ //Expr
					for(i64 it = i64265(0); it<(*spec).known.length;it++){
						#line 185 f7__ //Expr
						TypeAnyResolved472 t=OpArray9179((*spec).known,it);
						#line 186 f7__ //Expr
						Assert261((!ContainsAny464((*t.typ))));
					};
				};
				#line 189 f7__ //Expr
				Apply468((*spec));
				#line 190 f7__ //Expr
				Visit122((*generate.semantic),(*(*spec).function).super);
				#line 191 f7__ //Expr
				Visit150(generate,(*(*spec).function).super);
				#line 192 f7__ //Expr
				Clear469((*spec));
			};
		};
		#line 196 f7__ //Expr
		Print58(add64(str53{24,(i8*)"gSpecializations.length "},String66(gSpecializations.length)));
		#line 202 f7__ //Expr
		for(i64 it = i64265(0); it<structures.length;it++){
			#line 203 f7__ //Expr
			TypeStructure481* spec=OpArray12231(structures,it);
			#line 204 f7__ //Expr
			i8 hide=(equal4232((*spec).parent,(&(*generate.semantic).intrinsic.voidptr_))||(*spec).incomplete);
			#line 205 f7__ //Expr
			if((!hide)){
				#line 206 f7__ //Expr
				str53 name=Mangle143((&(*spec).super));
				#line 207 f7__ //Expr
				Write148((*generate.types),str53{7,(i8*)"struct "});
				#line 208 f7__ //Expr
				Write148((*generate.types),name);
				#line 209 f7__ //Expr
				Write148((*generate.types),str53{2,(i8*)";\n"});
			};
		};
		#line 214 f7__ //Expr
		for(i64 it = i64265(0); it<structures.length;it++){
			#line 215 f7__ //Expr
			TypeStructure481* spec=OpArray12231(structures,it);
			#line 217 f7__ //Expr
			i8 hide=(equal4232((*spec).parent,(&(*generate.semantic).intrinsic.voidptr_))||(*spec).incomplete);
			#line 218 f7__ //Expr
			if(hide){
				#line 220 f7__ //Expr
				Write148((*generate.types),str53{2,(i8*)"/*"});
			};
			#line 223 f7__ //Expr
			str53 name=Mangle143((&(*spec).super));
			#line 227 f7__ //Expr
			Write148((*generate.types),str53{7,(i8*)"struct "});
			#line 228 f7__ //Expr
			Write148((*generate.types),name);
			#line 229 f7__ //Expr
			Write148((*generate.types),str53{3,(i8*)" {\n"});
			#line 231 f7__ //Expr
			for(i64 it = i64265(0); it<(*spec).fields.length;it++){
				#line 232 f7__ //Expr
				Visit149((*generate.types),(*OpArray6155((*spec).fields,it)));
				#line 233 f7__ //Expr
				Write148((*generate.types),str53{1,(i8*)" "});
				#line 234 f7__ //Expr
				Write148((*generate.types),(*OpArray5125((*(*spec).parent).fields,it)).ident);
				#line 235 f7__ //Expr
				Write148((*generate.types),str53{2,(i8*)";\n"});
			};
			#line 237 f7__ //Expr
			Write148((*generate.types),str53{3,(i8*)"};\n"});
			#line 239 f7__ //Expr
			if(hide){
				#line 241 f7__ //Expr
				Write148((*generate.types),str53{2,(i8*)"*/"});
			};
		};
		#line 247 f7__ //Expr
		FileClose(generate.header);
		#line 248 f7__ //Expr
		FileClose(generate.impl);
		#line 249 f7__ //Expr
		FileClose(generate.types);
}
	#line 252 f7__ //Expr
	void Write148(File& file,str53 s){
		#line 253 f7__ //Expr
		FilePut((&file),s.chars);
}
	#line 256 f7__ //Expr
	void Visit149(File& file,Type413& t){
		#line 257 f7__ //Expr
		Type413* typ=Resolved127(t);
		#line 259 f7__ //Expr
		if(Is4149((*typ))){
			#line 260 f7__ //Expr
			TypeOption421* self=As4150((*typ));
			#line 261 f7__ //Expr
			if(Is0141((*(*self).reference))){
				#line 262 f7__ //Expr
				Visit149(file,(*(*self).reference));
			}else{
				#line 265 f7__ //Expr
				Write148(file,str53{6,(i8*)"OPTION"});
			};
			#line 268 f7__ //Expr
			return ;
		};
		#line 270 f7__ //Expr
		if(Is0141((*typ))){
			#line 271 f7__ //Expr
			TypeRef419* self=As0142((*typ));
			#line 272 f7__ //Expr
			Visit149(file,(*(*self).reference));
			#line 273 f7__ //Expr
			Write148(file,str53{1,(i8*)"*"});
			#line 274 f7__ //Expr
			return ;
		};
		#line 276 f7__ //Expr
		if(Is1143((*typ))){
			#line 277 f7__ //Expr
			TypeIdentifier414* self=As1144((*typ));
			#line 279 f7__ //Expr
			Write148(file,Name144((*As2124((*(*self).spec)))));
			#line 280 f7__ //Expr
			return ;
		};
		#line 282 f7__ //Expr
		if(Is6153((*typ))){
			#line 283 f7__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 284 f7__ //Expr
			Write148(file,Mangle143(typ));
			#line 285 f7__ //Expr
			return ;
		};
		#line 288 f7__ //Expr
		if(Is7156((*typ))){
			#line 289 f7__ //Expr
			TypeNumber431* self=As7157((*typ));
			#line 290 f7__ //Expr
			if(((*self).kind==TypeNumberInteger)){
				#line 291 f7__ //Expr
				Write148(file,str53{1,(i8*)"i"});
			}else{
				#line 293 f7__ //Expr
				if(((*self).kind==TypeNumberUnsigned)){
					#line 294 f7__ //Expr
					Write148(file,str53{1,(i8*)"u"});
				}else{
					#line 296 f7__ //Expr
					if(((*self).kind==TypeNumberFloat)){
						#line 297 f7__ //Expr
						Write148(file,str53{1,(i8*)"f"});
					}else{
						#line 300 f7__ //Expr
						Assert261(0);
					};
				};
			};
			#line 302 f7__ //Expr
			Write148(file,String66(((*self).size*8)));
			#line 303 f7__ //Expr
			return ;
		};
		#line 305 f7__ //Expr
		Write148(file,add64(str53{15,(i8*)"unknown type - "},String66((*typ).kind)));
}
	#line 310 f7__ //Expr
	void Visit150(GenerateBasic141& generate,Expr366& expr){
		#line 312 f7__ //Expr
		if(Is1120(expr)){
			#line 313 f7__ //Expr
			Indent142(generate);
			#line 314 f7__ //Expr
			Write148((*generate.impl),str53{2,(i8*)"{\n"});
			#line 315 f7__ //Expr
			Block434* self=As1121(expr);
			#line 316 f7__ //Expr
			generate.indent = (generate.indent+1);
			#line 317 f7__ //Expr
			for(i64 it = i64265(0); it<(*self).expressions.length;it++){
				#line 318 f7__ //Expr
				Expr366* expr=OpArray4122((*self).expressions,it);
				#line 319 f7__ //Expr
				Indent142(generate);
				#line 320 f7__ //Expr
				Visit150(generate,(*expr));
				#line 321 f7__ //Expr
				Write148((*generate.impl),str53{2,(i8*)";\n"});
			};
			#line 323 f7__ //Expr
			generate.indent = (generate.indent-1);
			#line 324 f7__ //Expr
			Indent142(generate);
			#line 325 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"}"});
			#line 327 f7__ //Expr
			return ;
		};
		#line 329 f7__ //Expr
		if(Is2123(expr)){
			#line 330 f7__ //Expr
			Structure473* self=As2124(expr);
			#line 334 f7__ //Expr
			if(equal4232(self,(&(*generate.semantic).intrinsic.voidptr_))){
				#line 335 f7__ //Expr
				return ;
			};
			#line 338 f7__ //Expr
			if((!(*self).constraints.length)){
				#line 339 f7__ //Expr
				str53 name=Name144((*self));
				#line 342 f7__ //Expr
				Write148((*generate.types),str53{15,(i8*)"typedef struct "});
				#line 343 f7__ //Expr
				Write148((*generate.types),name);
				#line 344 f7__ //Expr
				Write148((*generate.types),str53{3,(i8*)" {\n"});
				#line 346 f7__ //Expr
				for(i64 it = i64265(0); it<(*self).fields.length;it++){
					#line 347 f7__ //Expr
					Visit149((*generate.types),(*(*OpArray5125((*self).fields,it)).super.typ));
					#line 348 f7__ //Expr
					Write148((*generate.types),str53{1,(i8*)" "});
					#line 349 f7__ //Expr
					Write148((*generate.types),(*OpArray5125((*self).fields,it)).ident);
					#line 350 f7__ //Expr
					Write148((*generate.types),str53{2,(i8*)";\n"});
				};
				#line 352 f7__ //Expr
				Write148((*generate.types),str53{2,(i8*)"} "});
				#line 353 f7__ //Expr
				Write148((*generate.types),name);
				#line 354 f7__ //Expr
				Write148((*generate.types),str53{2,(i8*)";\n"});
			};
			#line 356 f7__ //Expr
			return ;
		};
		#line 358 f7__ //Expr
		if(Is3126(expr)){
			#line 359 f7__ //Expr
			Function456* self=As3127(expr);
			#line 360 f7__ //Expr
			if(IsIntrinsic140((*generate.semantic).intrinsic,self)){
				#line 362 f7__ //Expr
				return ;
			};
			#line 365 f7__ //Expr
			str53 ident=Name145((*self));
			#line 368 f7__ //Expr
			if((((*self).any.length==0)||((i64)(*self).spec!=0))){
				#line 370 f7__ //Expr
				Assert260(((((*self).any.length!=0)||((i64)(*self).spec==0))!=0),str53{34,(i8*)"Expected just one of these to pass"});
				#line 371 f7__ //Expr
				if((*self).spec){
					#line 372 f7__ //Expr
					Assert261((!(*(*self).spec).incomplete));
				};
				#line 374 f7__ //Expr
				if((!(*self).block)){
					#line 375 f7__ //Expr
					Write148((*generate.header),str53{11,(i8*)"extern \"C\" "});
				};
				#line 377 f7__ //Expr
				if((*self).result){
					#line 378 f7__ //Expr
					Visit149((*generate.header),(*(*self).result));
					#line 379 f7__ //Expr
					Write148((*generate.header),str53{1,(i8*)" "});
				}else{
					#line 382 f7__ //Expr
					Write148((*generate.header),str53{5,(i8*)"void "});
				};
				#line 384 f7__ //Expr
				Write148((*generate.header),ident);
				#line 385 f7__ //Expr
				if((*self).spec){
					#line 386 f7__ //Expr
					Write148((*generate.header),String66((*(*self).spec).index));
				};
				#line 388 f7__ //Expr
				Write148((*generate.header),str53{1,(i8*)"("});
				#line 389 f7__ //Expr
				i64 last=((*self).params.list.length-1);
				#line 390 f7__ //Expr
				while(((last>0)&&Is5151((*(*OpArray4122((*self).params.list,last)).typ)))){
					#line 392 f7__ //Expr
					last = (last-1);
				};
				#line 395 f7__ //Expr
				for(i64 it = i64265(0); it<(*self).params.list.length;it++){
					#line 396 f7__ //Expr
					if((!Is5151((*(*OpArray4122((*self).params.list,it)).typ)))){
						#line 401 f7__ //Expr
						Visit149((*generate.header),(*(*OpArray4122((*self).params.list,it)).typ));
						#line 402 f7__ //Expr
						Write148((*generate.header),str53{1,(i8*)" "});
						#line 403 f7__ //Expr
						Write148((*generate.header),(*As7135((*OpArray4122((*self).params.list,it)))).ident);
						#line 405 f7__ //Expr
						if((it!=last)){
							#line 406 f7__ //Expr
							Write148((*generate.header),str53{2,(i8*)", "});
						};
					};
				};
				#line 410 f7__ //Expr
				Write148((*generate.header),str53{3,(i8*)");\n"});
				#line 411 f7__ //Expr
				if((*self).block){
					#line 412 f7__ //Expr
					if((*self).result){
						#line 413 f7__ //Expr
						Visit149((*generate.impl),(*(*self).result));
						#line 414 f7__ //Expr
						Write148((*generate.impl),str53{1,(i8*)" "});
					}else{
						#line 417 f7__ //Expr
						Write148((*generate.impl),str53{5,(i8*)"void "});
					};
					#line 419 f7__ //Expr
					Write148((*generate.impl),ident);
					#line 420 f7__ //Expr
					if((*self).spec){
						#line 421 f7__ //Expr
						Write148((*generate.impl),String66((*(*self).spec).index));
					};
					#line 423 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)"("});
					#line 424 f7__ //Expr
					for(i64 it = i64265(0); it<(*self).params.list.length;it++){
						#line 425 f7__ //Expr
						if((!Is5151((*(*OpArray4122((*self).params.list,it)).typ)))){
							#line 430 f7__ //Expr
							Visit149((*generate.impl),(*(*OpArray4122((*self).params.list,it)).typ));
							#line 431 f7__ //Expr
							Write148((*generate.impl),str53{1,(i8*)" "});
							#line 432 f7__ //Expr
							Write148((*generate.impl),(*As7135((*OpArray4122((*self).params.list,it)))).ident);
							#line 434 f7__ //Expr
							if((it!=last)){
								#line 435 f7__ //Expr
								Write148((*generate.impl),str53{2,(i8*)", "});
							};
						};
					};
					#line 439 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)")"});
					#line 440 f7__ //Expr
					Visit150(generate,(*(*self).block).super);
					#line 441 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)"\n"});
				};
			};
			#line 444 f7__ //Expr
			return ;
		};
		#line 446 f7__ //Expr
		if(Is5130(expr)){
			#line 448 f7__ //Expr
			Call442* self=As5131(expr);
			#line 457 f7__ //Expr
			i64 last=((*self).params.list.length-1);
			#line 458 f7__ //Expr
			while(((last>0)&&(Is5151((*(*OpArray4122((*self).params.list,last)).typ))||Is9138((*OpArray4122((*self).params.list,last)))))){
				#line 460 f7__ //Expr
				last = (last-1);
			};
			#line 462 f7__ //Expr
			if(Is3126((*(*self).func))){
				#line 464 f7__ //Expr
				Function456* function=As3127((*(*self).func));
				#line 467 f7__ //Expr
				if(IsIntrinsic140((*generate.semantic).intrinsic,function)){
					#line 469 f7__ //Expr
					GenerateBasicIntrinsic154(generate,function,self);
				}else{
					#line 473 f7__ //Expr
					str53 name=Name145((*function));
					#line 475 f7__ //Expr
					Write148((*generate.impl),name);
					#line 476 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)"("});
					#line 477 f7__ //Expr
					for(i64 it = i64265(0); it<(*self).params.list.length;it++){
						#line 479 f7__ //Expr
						if((!(Is5151((*(*OpArray4122((*self).params.list,it)).typ))&&(!Is9138((*OpArray4122((*self).params.list,it))))))){
							#line 481 f7__ //Expr
							PerformVisitAutoReference151(generate,(*OpArray4122((*self).params.list,it)),i64269(OpArray0112((*self).drefCount,it)));
							#line 482 f7__ //Expr
							if((it!=last)){
								#line 484 f7__ //Expr
								Write148((*generate.impl),str53{1,(i8*)","});
							};
						};
					};
					#line 488 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)")"});
				};
			}else{
				#line 491 f7__ //Expr
				if(Is19233((*(*self).func))){
					#line 493 f7__ //Expr
					FunctionSpec460* spec=As17234((*(*self).func));
					#line 494 f7__ //Expr
					if(IsIntrinsic140((*generate.semantic).intrinsic,(*spec).function)){
						#line 496 f7__ //Expr
						GenerateBasicIntrinsic154(generate,(*spec).function,self);
					}else{
						#line 500 f7__ //Expr
						str53 name=Name146((*spec));
						#line 502 f7__ //Expr
						Write148((*generate.impl),name);
						#line 503 f7__ //Expr
						Write148((*generate.impl),String66((*spec).index));
						#line 504 f7__ //Expr
						Write148((*generate.impl),str53{1,(i8*)"("});
						#line 505 f7__ //Expr
						for(i64 it = i64265(0); it<(*self).params.list.length;it++){
							#line 507 f7__ //Expr
							if((!(Is5151((*(*OpArray4122((*self).params.list,it)).typ))&&(!Is9138((*OpArray4122((*self).params.list,it))))))){
								#line 509 f7__ //Expr
								PerformVisitAutoReference151(generate,(*OpArray4122((*self).params.list,it)),i64269(OpArray0112((*self).drefCount,it)));
								#line 510 f7__ //Expr
								if((it!=last)){
									#line 512 f7__ //Expr
									Write148((*generate.impl),str53{1,(i8*)","});
								};
							};
						};
						#line 516 f7__ //Expr
						Write148((*generate.impl),str53{1,(i8*)")"});
					};
					#line 518 f7__ //Expr
					Clear469((*spec));
				}else{
					#line 521 f7__ //Expr
					Assert260(0,add64(str53{23,(i8*)"Expected fn or fn spec "},String66((*(*self).operand).kind)));
				};
			};
			#line 523 f7__ //Expr
			return ;
		};
		#line 525 f7__ //Expr
		if(Is7134(expr)){
			#line 526 f7__ //Expr
			Variable498* self=As7135(expr);
			#line 527 f7__ //Expr
			if((!Is5151((*(*self).super.typ)))){
				#line 529 f7__ //Expr
				Visit149((*generate.impl),(*(*self).super.typ));
				#line 530 f7__ //Expr
				Write148((*generate.impl),str53{1,(i8*)" "});
				#line 531 f7__ //Expr
				Write148((*generate.impl),(*self).ident);
				#line 532 f7__ //Expr
				if((*self).assign){
					#line 533 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)"="});
					#line 534 f7__ //Expr
					for(i64 it = i64265(0); it<(*self).drefCount;it++){
						#line 535 f7__ //Expr
						Write148((*generate.impl),str53{1,(i8*)"*"});
					};
					#line 537 f7__ //Expr
					Visit150(generate,(*(*self).assign));
				}else{
					#line 540 f7__ //Expr
					Write148((*generate.impl),str53{4,(i8*)"={0}"});
				};
			};
			#line 543 f7__ //Expr
			return ;
		};
		#line 545 f7__ //Expr
		if(Is13185(expr)){
			#line 546 f7__ //Expr
			ForList512* self=As12186(expr);
			#line 548 f7__ //Expr
			for(i64 it = i64265(0); it<(*(*self).list).list.length;it++){
				#line 549 f7__ //Expr
				SetIt517((*generate.semantic),(*self),OpArray4122((*(*self).list).list,it));
				#line 550 f7__ //Expr
				Write148((*generate.impl),add64(add64(str53{10,(i8*)"/*ForList "},String66(it)),str53{2,(i8*)"*/"}));
				#line 551 f7__ //Expr
				(*(*self).it).assign = OpArray4122((*(*self).list).list,it);
				#line 552 f7__ //Expr
				(*(*self).it).super.typ = (*OpArray4122((*(*self).list).list,it)).typ;
				#line 553 f7__ //Expr
				Assert0173((*(*self).it).super.typ);
				#line 555 f7__ //Expr
				Visit150(generate,(*(*self).block).super);
			};
			#line 559 f7__ //Expr
			return ;
		};
		#line 561 f7__ //Expr
		if(Is14190(expr)){
			#line 562 f7__ //Expr
			For449* self=As13191(expr);
			#line 564 f7__ //Expr
			if((*self).to){
				#line 565 f7__ //Expr
				Write148((*generate.impl),str53{4,(i8*)"for("});
				#line 566 f7__ //Expr
				Visit150(generate,(*(*self).it).super);
				#line 567 f7__ //Expr
				Write148((*generate.impl),str53{2,(i8*)"; "});
				#line 569 f7__ //Expr
				Visit150(generate,(*(*self).test).super);
				#line 570 f7__ //Expr
				Write148((*generate.impl),str53{2,(i8*)"; "});
				#line 571 f7__ //Expr
				Visit150(generate,(*(*self).inc));
				#line 572 f7__ //Expr
				Write148((*generate.impl),str53{1,(i8*)")"});
			}else{
				#line 575 f7__ //Expr
				Write148((*generate.impl),str53{6,(i8*)"while("});
				#line 576 f7__ //Expr
				Visit150(generate,(*(*self).from));
				#line 577 f7__ //Expr
				Write148((*generate.impl),str53{1,(i8*)")"});
			};
			#line 581 f7__ //Expr
			Visit150(generate,(*(*self).block).super);
			#line 584 f7__ //Expr
			return ;
		};
		#line 586 f7__ //Expr
		if(Is16194(expr)){
			#line 587 f7__ //Expr
			If447* self=As15195(expr);
			#line 589 f7__ //Expr
			Write148((*generate.impl),str53{3,(i8*)"if("});
			#line 590 f7__ //Expr
			Visit150(generate,(*(*self).condition));
			#line 591 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 593 f7__ //Expr
			Visit150(generate,(*(*self).trueBranch).super);
			#line 595 f7__ //Expr
			if((*self).falseCondition){
				#line 596 f7__ //Expr
				Write148((*generate.impl),str53{5,(i8*)"else "});
				#line 597 f7__ //Expr
				Visit150(generate,(*(*self).falseCondition).super);
			};
			#line 599 f7__ //Expr
			if((*self).falseBranch){
				#line 600 f7__ //Expr
				Write148((*generate.impl),str53{4,(i8*)"else"});
				#line 601 f7__ //Expr
				Visit150(generate,(*(*self).falseBranch).super);
			};
			#line 606 f7__ //Expr
			return ;
		};
		#line 608 f7__ //Expr
		if(Is4128(expr)){
			#line 609 f7__ //Expr
			Identifier495* self=As4129(expr);
			#line 610 f7__ //Expr
			Write148((*generate.impl),(*self).ident);
			#line 611 f7__ //Expr
			return ;
		};
		#line 613 f7__ //Expr
		if(Is6132(expr)){
			#line 614 f7__ //Expr
			Access445* self=As6133(expr);
			#line 615 f7__ //Expr
			if((*self).call){
				#line 616 f7__ //Expr
				Visit150(generate,(*(*self).call).super);
				#line 617 f7__ //Expr
				return ;
			};
			#line 620 f7__ //Expr
			Type413* typ=Resolved127((*(*(*self).operand).typ));
			#line 621 f7__ //Expr
			if(Is0141((*typ))){
				#line 622 f7__ //Expr
				Write148((*generate.impl),str53{1,(i8*)"("});
				#line 623 f7__ //Expr
				while(Is0141((*typ))){
					#line 624 f7__ //Expr
					typ = Resolved127((*(*As0142((*typ))).reference));
					#line 625 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)"*"});
				};
				#line 627 f7__ //Expr
				Visit150(generate,(*(*self).operand));
				#line 628 f7__ //Expr
				Write148((*generate.impl),str53{1,(i8*)")"});
			}else{
				#line 631 f7__ //Expr
				Visit150(generate,(*(*self).operand));
			};
			#line 634 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"."});
			#line 637 f7__ //Expr
			Write148((*generate.impl),(*self).field);
			#line 638 f7__ //Expr
			return ;
		};
		#line 640 f7__ //Expr
		if(Is15192(expr)){
			#line 641 f7__ //Expr
			Assign501* self=As14193(expr);
			#line 642 f7__ //Expr
			for(i32 it = i32274(0); it<(-(*self).drefCount);it++){
				#line 643 f7__ //Expr
				Write148((*generate.impl),str53{1,(i8*)"*"});
			};
			#line 645 f7__ //Expr
			Visit150(generate,(*(*self).left));
			#line 646 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"="});
			#line 647 f7__ //Expr
			Visit150(generate,(*(*self).right));
			#line 648 f7__ //Expr
			return ;
		};
		#line 650 f7__ //Expr
		if(Is8136(expr)){
			#line 651 f7__ //Expr
			Trait490* self=As8137(expr);
			#line 652 f7__ //Expr
			return ;
		};
		#line 654 f7__ //Expr
		if(Is11181(expr)){
			#line 655 f7__ //Expr
			NumberConstant507* self=As10182(expr);
			#line 656 f7__ //Expr
			Write148((*generate.impl),(*self).value);
			#line 657 f7__ //Expr
			return ;
		};
		#line 659 f7__ //Expr
		if(Is12183(expr)){
			#line 660 f7__ //Expr
			StringConstant509* self=As11184(expr);
			#line 661 f7__ //Expr
			Write148((*generate.impl),str53{7,(i8*)"((Str){"});
			#line 662 f7__ //Expr
			str53 s=str53{1,(i8*)"0"};
			#line 664 f7__ //Expr
			Write148((*generate.impl),String66((*self).value.length));
			#line 665 f7__ //Expr
			Write148((*generate.impl),str53{8,(i8*)", (i8*)\""});
			#line 666 f7__ //Expr
			for(i64 it = i64265(0); it<(*self).value.length;it++){
				#line 669 f7__ //Expr
				i8 c=(*((*self).value.chars+it));
				#line 670 f7__ //Expr
				if((c==(*str53{1,(i8*)"\n"}.chars))){
					#line 671 f7__ //Expr
					Write148((*generate.impl),str53{1,(i8*)"\\n"});
				}else{
					#line 673 f7__ //Expr
					if((c==(*str53{1,(i8*)"\""}.chars))){
						#line 674 f7__ //Expr
						Write148((*generate.impl),str53{1,(i8*)"\\\""});
					}else{
						#line 676 f7__ //Expr
						if((c==(*str53{0,(i8*)"\\"}.chars))){
							#line 677 f7__ //Expr
							Write148((*generate.impl),str53{0,(i8*)"\\\\"});
						}else{
							#line 680 f7__ //Expr
							str53 v=StringFromChar61(c);
							#line 681 f7__ //Expr
							Write148((*generate.impl),v);
						};
					};
				};
			};
			#line 684 f7__ //Expr
			Write148((*generate.impl),str53{3,(i8*)"\"})"});
			#line 685 f7__ //Expr
			return ;
		};
		#line 687 f7__ //Expr
		if(Is18197(expr)){
			#line 688 f7__ //Expr
			Return454* self=As16198(expr);
			#line 689 f7__ //Expr
			Write148((*generate.impl),str53{7,(i8*)"return "});
			#line 690 f7__ //Expr
			if((*self).expr){
				#line 691 f7__ //Expr
				PerformVisitAutoReference151(generate,(*(*self).expr),(*self).drefCount);
			};
			#line 693 f7__ //Expr
			return ;
		};
		#line 695 f7__ //Expr
		Write148((*generate.impl),add64(add64(str53{20,(i8*)"---- unhandled node "},String66(expr.kind)),str53{6,(i8*)"---- \n"}));
}
	#line 699 f7__ //Expr
	void PerformVisitAutoReference151(GenerateBasic141& self,Expr366& expr,i64 count){
		#line 700 f7__ //Expr
		if((count<0)){
			#line 701 f7__ //Expr
			PerformReference152(self,expr,(-count));
			#line 702 f7__ //Expr
			return ;
		}else{
			#line 704 f7__ //Expr
			if((count>0)){
				#line 705 f7__ //Expr
				PerformDereference153(self,expr,count);
				#line 706 f7__ //Expr
				return ;
			};
		};
		#line 708 f7__ //Expr
		Assert260((count==0),str53{29,(i8*)"Internal: expected count == 0"});
		#line 709 f7__ //Expr
		Visit150(self,expr);
}
	#line 712 f7__ //Expr
	void PerformReference152(GenerateBasic141& self,Expr366& expr,i64 count){
		#line 713 f7__ //Expr
		Assert260((count==1),str53{44,(i8*)"Internal: expected dref count greater than 0"});
		#line 714 f7__ //Expr
		Write148((*self.impl),str53{2,(i8*)"(&"});
		#line 715 f7__ //Expr
		Visit150(self,expr);
		#line 716 f7__ //Expr
		Write148((*self.impl),str53{1,(i8*)")"});
}
	#line 719 f7__ //Expr
	void PerformDereference153(GenerateBasic141& self,Expr366& expr,i64 count){
		#line 721 f7__ //Expr
		Assert260((count>0),str53{44,(i8*)"Internal: expected dref count greater than 0"});
		#line 723 f7__ //Expr
		Write148((*self.impl),str53{2,(i8*)"(*"});
		#line 724 f7__ //Expr
		Visit150(self,expr);
		#line 725 f7__ //Expr
		Write148((*self.impl),str53{1,(i8*)")"});
}
	#line 728 f7__ //Expr
	void GenerateBasicIntrinsic154(GenerateBasic141& generate,Function456* function,Call442* call){
		#line 729 f7__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.abortFn))){
			#line 730 f7__ //Expr
			Write148((*generate.impl),str53{8,(i8*)"abort();"});
			#line 731 f7__ //Expr
			return ;
		};
		#line 734 f7__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.invert))){
			#line 735 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"!"});
			#line 736 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,0)),i64269(OpArray0112((*call).drefCount,0)));
			#line 737 f7__ //Expr
			return ;
		};
		#line 740 f7__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.ptr_add))){
			#line 741 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"("});
			#line 742 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,0)),i64269(OpArray0112((*call).drefCount,0)));
			#line 743 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"+"});
			#line 744 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,1)),i64269(OpArray0112((*call).drefCount,1)));
			#line 745 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 746 f7__ //Expr
			return ;
		};
		#line 749 f7__ //Expr
		if(((i64)(&(*generate.semantic).intrinsic.reference)==(i64)function)){
			#line 751 f7__ //Expr
			Write148((*generate.impl),str53{2,(i8*)"(&"});
			#line 752 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,0)),i64269(OpArray0112((*call).drefCount,0)));
			#line 753 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 754 f7__ //Expr
			return ;
		};
		#line 756 f7__ //Expr
		if(((i64)(&(*generate.semantic).intrinsic.dereference)==(i64)function)){
			#line 758 f7__ //Expr
			Write148((*generate.impl),str53{2,(i8*)"(*"});
			#line 759 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,0)),i64269(OpArray0112((*call).drefCount,0)));
			#line 760 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 761 f7__ //Expr
			return ;
		};
		#line 764 f7__ //Expr
		if(((i64)(&(*generate.semantic).intrinsic.castOp)==(i64)function)){
			#line 766 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"("});
			#line 767 f7__ //Expr
			Visit149((*generate.impl),(*(*call).super.typ));
			#line 768 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 769 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,1)),i64269(OpArray0112((*call).drefCount,1)));
			#line 770 f7__ //Expr
			return ;
		};
		#line 772 f7__ //Expr
		if(equal3219((&(*generate.semantic).intrinsic.sizeFn),function)){
			#line 774 f7__ //Expr
			i64 size=Size221((*As5152((*(*OpArray4122((*call).params.list,0)).typ))).reference);
			#line 775 f7__ //Expr
			Write148((*generate.impl),str53{7,(i8*)"sizeof("});
			#line 776 f7__ //Expr
			Visit149((*generate.impl),(*(*As5152((*(*OpArray4122((*call).params.list,0)).typ))).reference));
			#line 777 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 779 f7__ //Expr
			return ;
		};
		#line 781 f7__ //Expr
		if(((*call).params.list.length==1)){
			#line 782 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)"("});
			#line 783 f7__ //Expr
			Write148((*generate.impl),(*function).ident);
			#line 784 f7__ //Expr
			Write148((*generate.impl),str53{1,(i8*)")"});
			#line 785 f7__ //Expr
			PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,0)),i64269(OpArray0112((*call).drefCount,0)));
			#line 786 f7__ //Expr
			return ;
		};
		#line 788 f7__ //Expr
		Write148((*generate.impl),str53{1,(i8*)"("});
		#line 789 f7__ //Expr
		PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,0)),i64269(OpArray0112((*call).drefCount,0)));
		#line 790 f7__ //Expr
		Write148((*generate.impl),(*function).ident);
		#line 791 f7__ //Expr
		PerformVisitAutoReference151(generate,(*OpArray4122((*call).params.list,1)),i64269(OpArray0112((*call).drefCount,1)));
		#line 792 f7__ //Expr
		Write148((*generate.impl),str53{1,(i8*)")"});
		#line 793 f7__ //Expr
		return ;
}
			#line 15 f8__ //Expr
	Module155* ContainsFile157(Project156& self,str53 path){
		#line 16 f8__ //Expr
		for(i64 it = i64265(0); it<self.files.length;it++){
			#line 17 f8__ //Expr
			if(Equal69((*OpArray1107(self.files,it)).path,path)){
				#line 19 f8__ //Expr
				return OpArray1107(self.files,it);
			};
		};
		#line 22 f8__ //Expr
		return (Module155*)0;
}
	#line 25 f8__ //Expr
	Module155* AddFile158(Project156& self,str53 path){
		#line 27 f8__ //Expr
		Module155* hasFile=ContainsFile157(self,path);
		#line 28 f8__ //Expr
		if(hasFile){
			#line 29 f8__ //Expr
			return hasFile;
		};
		#line 32 f8__ //Expr
		Module155* file=new24235();
		#line 33 f8__ //Expr
		(*file).path = path;
		#line 34 f8__ //Expr
		Push9237(self.files,file);
		#line 35 f8__ //Expr
		return file;
}
	#line 38 f8__ //Expr
	void PrintLines159(Project156& self,Position76 position,i64 lines){
		#line 39 f8__ //Expr
		if((position.file==0)){
			#line 40 f8__ //Expr
			Println59(add64(add64(add64(add64(str53{20,(i8*)"Internal position: ("},String66(position.line)),str53{2,(i8*)", "}),String66(position.line)),str53{1,(i8*)")"}));
			#line 41 f8__ //Expr
			return ;
		};
		#line 44 f8__ //Expr
		File* file=FileOpen((*OpArray1107(self.files,(position.file-1))).path.chars,str53{1,(i8*)"r"}.chars);
		#line 46 f8__ //Expr
		i8* buffer=Alloc19109(1024);
		#line 49 f8__ //Expr
		for(i64 it = i64265(1); it<(position.line+lines);it++){
			#line 51 f8__ //Expr
			i8* ret=GetLine(file,buffer,1024);
			#line 53 f8__ //Expr
			if((it==position.line)){
				#line 56 f8__ //Expr
				i64 len=String66(it).length;
				#line 57 f8__ //Expr
				for(i64 it = i64265(0); it<len;it++){
					#line 58 f8__ //Expr
					Errornl63(str53{3,(i8*)"•"});
				};
				#line 61 f8__ //Expr
				for(i64 it = i64265(0); it<(position.column-1);it++){
					#line 62 f8__ //Expr
					if(((*(ret+it))==Char54(str53{1,(i8*)"\t"}))){
						#line 63 f8__ //Expr
						Errornl63(str53{9,(i8*)"•••"});
						#line 64 f8__ //Expr
						len = (len+3);
					}else{
						#line 67 f8__ //Expr
						Errornl63(str53{3,(i8*)"•"});
						#line 68 f8__ //Expr
						len = (len+1);
					};
				};
				#line 72 f8__ //Expr
				Errornl63(str53{7,(i8*)"  ▼  "});
				#line 73 f8__ //Expr
				for(i64 it = i64265(0); it<(93-len);it++){
					#line 74 f8__ //Expr
					Errornl63(str53{3,(i8*)"•"});
				};
				#line 76 f8__ //Expr
				Println59(str53{0,(i8*)""});
			};
			#line 78 f8__ //Expr
			if(((it>=position.line)&&(i64)ret)){
				#line 79 f8__ //Expr
				Print58(add64(String66(it),str53{2,(i8*)"  "}));
				#line 80 f8__ //Expr
				Print58(String60(buffer));
			};
		};
}
		#line 11 f9__ //Expr
	;
	#line 12 f9__ //Expr
	;
	#line 13 f9__ //Expr
	;
	#line 14 f9__ //Expr
	;
	#line 17 f9__ //Expr
		#line 18 f9__ //Expr
		#line 19 f9__ //Expr
		#line 20 f9__ //Expr
		#line 21 f9__ //Expr
		#line 22 f9__ //Expr
		#line 23 f9__ //Expr
		#line 24 f9__ //Expr
		#line 25 f9__ //Expr
		#line 27 f9__ //Expr
		#line 28 f9__ //Expr
		#line 29 f9__ //Expr
		#line 30 f9__ //Expr
		#line 31 f9__ //Expr
		#line 32 f9__ //Expr
		#line 33 f9__ //Expr
		#line 34 f9__ //Expr
		#line 36 f9__ //Expr
		#line 37 f9__ //Expr
		#line 48 f9__ //Expr
	;
	#line 50 f9__ //Expr
	;
	#line 51 f9__ //Expr
	;
	#line 52 f9__ //Expr
	;
	#line 53 f9__ //Expr
	;
	#line 54 f9__ //Expr
	;
	#line 55 f9__ //Expr
	;
	#line 57 f9__ //Expr
	;
	#line 58 f9__ //Expr
	;
	#line 59 f9__ //Expr
	;
	#line 60 f9__ //Expr
	;
	#line 63 f9__ //Expr
	;
	#line 64 f9__ //Expr
	;
	#line 65 f9__ //Expr
	;
	#line 66 f9__ //Expr
	;
	#line 67 f9__ //Expr
	;
	#line 69 f9__ //Expr
	;
	#line 72 f9__ //Expr
	;
	#line 73 f9__ //Expr
	;
	#line 78 f9__ //Expr
	;
	#line 85 f9__ //Expr
	;
	#line 90 f9__ //Expr
	;
	#line 94 f9__ //Expr
	;
	#line 99 f9__ //Expr
	;
	#line 104 f9__ //Expr
	;
	#line 110 f9__ //Expr
	;
	#line 114 f9__ //Expr
	;
	#line 121 f9__ //Expr
	;
	#line 128 f9__ //Expr
	;
	#line 132 f9__ //Expr
	;
	#line 133 f9__ //Expr
	;
	#line 134 f9__ //Expr
	;
	#line 135 f9__ //Expr
	;
	#line 136 f9__ //Expr
	;
	#line 137 f9__ //Expr
	;
	#line 140 f9__ //Expr
	;
	#line 144 f9__ //Expr
	;
	#line 145 f9__ //Expr
	;
	#line 146 f9__ //Expr
	;
	#line 147 f9__ //Expr
	;
	#line 148 f9__ //Expr
	;
	#line 149 f9__ //Expr
	;
	#line 153 f9__ //Expr
	;
	#line 154 f9__ //Expr
	;
	#line 155 f9__ //Expr
	;
	#line 156 f9__ //Expr
	;
	#line 157 f9__ //Expr
	;
	#line 159 f9__ //Expr
	;
	#line 160 f9__ //Expr
	;
	#line 161 f9__ //Expr
	;
	#line 162 f9__ //Expr
	;
	#line 163 f9__ //Expr
	;
	#line 164 f9__ //Expr
	;
	#line 171 f9__ //Expr
	;
	#line 172 f9__ //Expr
	;
	#line 174 f9__ //Expr
	;
	#line 175 f9__ //Expr
	;
	#line 177 f9__ //Expr
	;
	#line 178 f9__ //Expr
	;
	#line 181 f9__ //Expr
	;
	#line 182 f9__ //Expr
	;
	#line 183 f9__ //Expr
	;
	#line 185 f9__ //Expr
	;
	#line 187 f9__ //Expr
	;
	#line 190 f9__ //Expr
	;
	#line 191 f9__ //Expr
	;
			#line 226 f9__ //Expr
	void InsertAdd182(){
}
	#line 229 f9__ //Expr
	;
	#line 231 f9__ //Expr
	void Init183(Interp181& self){
		#line 233 f9__ //Expr
		Init3239(self.registers,registerCount);
		#line 234 f9__ //Expr
		Init0111(self.stack,(1024*1024));
		#line 235 f9__ //Expr
		Init0111(self.instructions,(1024*1024));
		#line 236 f9__ //Expr
		Init1241(self.labels);
		#line 238 f9__ //Expr
		self.sPtr = (self.stack.elements+(1000*1000));
		#line 239 f9__ //Expr
		self.stackTop = self.sPtr;
		#line 241 f9__ //Expr
		self.iPtr = 1;
		#line 242 f9__ //Expr
		self.instructionsSize = 1;
		#line 243 f9__ //Expr
		self.cvm = dcNewCallVM(1024);
		#line 245 f9__ //Expr
		dlopen(str53{56,(i8*)"/Users/David/Desktop/Projects/glfw/src/libglfw.3.3.dylib"}.chars,1);
		#line 246 f9__ //Expr
		dlopen(str53{47,(i8*)"/Users/David/Desktop/dl/dl/build/libdyndl.dylib"}.chars,1);
		#line 247 f9__ //Expr
		self.dlhandle = dlopen((i8*)0,i32279((RTLD_NOW|RTLD_GLOBAL)));
		#line 249 f9__ //Expr
		Init2244(self.frames);
		#line 250 f9__ //Expr
		Init4247(self.frameArray);
		#line 251 f9__ //Expr
		Init5249(labelAddresses);
		#line 252 f9__ //Expr
		Push10250(labelAddresses,0);
}
	#line 255 f9__ //Expr
	void PrintInstructions184(Interp181& self){
		#line 257 f9__ //Expr
		Println59(str53{15,(i8*)"---------------"});
		#line 258 f9__ //Expr
		Println59(str53{15,(i8*)"---------------"});
}
	#line 261 f9__ //Expr
	void Push0267(Interp181& self,i64 value){
		#line 262 f9__ //Expr
		self.sPtr = (i8*)((i64*)self.sPtr+(-1));
		#line 263 f9__ //Expr
		(*(i64*)self.sPtr) = value;
}
void Push1269(Interp181& self,i8 value){
		#line 262 f9__ //Expr
		self.sPtr = (i8*)((i8*)self.sPtr+(-1));
		#line 263 f9__ //Expr
		(*(i8*)self.sPtr) = value;
}
void Push2271(Interp181& self,f32 value){
		#line 262 f9__ //Expr
		self.sPtr = (i8*)((f32*)self.sPtr+(-1));
		#line 263 f9__ //Expr
		(*(f32*)self.sPtr) = value;
}
void Push3272(Interp181& self,i16 value){
		#line 262 f9__ //Expr
		self.sPtr = (i8*)((i16*)self.sPtr+(-1));
		#line 263 f9__ //Expr
		(*(i16*)self.sPtr) = value;
}
void Push4273(Interp181& self,i32 value){
		#line 262 f9__ //Expr
		self.sPtr = (i8*)((i32*)self.sPtr+(-1));
		#line 263 f9__ //Expr
		(*(i32*)self.sPtr) = value;
}
void Push5274(Interp181& self,f64 value){
		#line 262 f9__ //Expr
		self.sPtr = (i8*)((f64*)self.sPtr+(-1));
		#line 263 f9__ //Expr
		(*(f64*)self.sPtr) = value;
}
	#line 266 f9__ //Expr
	void Push0265(Interp181& self,i8* from,i64 size){
		#line 267 f9__ //Expr
		self.sPtr = (i8*)((i8*)self.sPtr+(-size));
		#line 268 f9__ //Expr
		CopyPtr0110(from,self.sPtr,size);
}
	#line 271 f9__ //Expr
	i64 Pop0266(Interp181& self){
		#line 273 f9__ //Expr
		i8* pPtr=self.sPtr;
		#line 274 f9__ //Expr
		self.sPtr = (i8*)((i64*)self.sPtr+1);
		#line 275 f9__ //Expr
		Assert260(((i64)self.sPtr>=(i64)self.stack.elements),str53{15,(i8*)"Stack underflow"});
		#line 277 f9__ //Expr
		return (*(i64*)pPtr);
}
i8 Pop1268(Interp181& self){
		#line 273 f9__ //Expr
		i8* pPtr=self.sPtr;
		#line 274 f9__ //Expr
		self.sPtr = (i8*)((i8*)self.sPtr+1);
		#line 275 f9__ //Expr
		Assert260(((i64)self.sPtr>=(i64)self.stack.elements),str53{15,(i8*)"Stack underflow"});
		#line 277 f9__ //Expr
		return (*(i8*)pPtr);
}
f32 Pop2270(Interp181& self){
		#line 273 f9__ //Expr
		i8* pPtr=self.sPtr;
		#line 274 f9__ //Expr
		self.sPtr = (i8*)((f32*)self.sPtr+1);
		#line 275 f9__ //Expr
		Assert260(((i64)self.sPtr>=(i64)self.stack.elements),str53{15,(i8*)"Stack underflow"});
		#line 277 f9__ //Expr
		return (*(f32*)pPtr);
}
i16 Pop3275(Interp181& self){
		#line 273 f9__ //Expr
		i8* pPtr=self.sPtr;
		#line 274 f9__ //Expr
		self.sPtr = (i8*)((i16*)self.sPtr+1);
		#line 275 f9__ //Expr
		Assert260(((i64)self.sPtr>=(i64)self.stack.elements),str53{15,(i8*)"Stack underflow"});
		#line 277 f9__ //Expr
		return (*(i16*)pPtr);
}
i32 Pop4276(Interp181& self){
		#line 273 f9__ //Expr
		i8* pPtr=self.sPtr;
		#line 274 f9__ //Expr
		self.sPtr = (i8*)((i32*)self.sPtr+1);
		#line 275 f9__ //Expr
		Assert260(((i64)self.sPtr>=(i64)self.stack.elements),str53{15,(i8*)"Stack underflow"});
		#line 277 f9__ //Expr
		return (*(i32*)pPtr);
}
f64 Pop5277(Interp181& self){
		#line 273 f9__ //Expr
		i8* pPtr=self.sPtr;
		#line 274 f9__ //Expr
		self.sPtr = (i8*)((f64*)self.sPtr+1);
		#line 275 f9__ //Expr
		Assert260(((i64)self.sPtr>=(i64)self.stack.elements),str53{15,(i8*)"Stack underflow"});
		#line 277 f9__ //Expr
		return (*(f64*)pPtr);
}
	#line 285 f9__ //Expr
	void StorePtr188(Interp181& self,i8* to,i8* from,i64 size){
		#line 287 f9__ //Expr
		CopyPtr0110(from,to,size);
}
	#line 295 f9__ //Expr
	void AddLabel189(Interp181& self,str53 name){
		#line 296 f9__ //Expr
		if((OpArray1252(self.labels,name)==0)){
			#line 297 f9__ //Expr
			OpArray1252(self.labels,name) = labelAddresses.length;
			#line 298 f9__ //Expr
			Push10250(labelAddresses,(-1));
		};
		#line 300 f9__ //Expr
		OpArray14255(labelAddresses,OpArray1252(self.labels,name)) = self.instructionsSize;
		#line 301 f9__ //Expr
		Println59(add64(add64(add64(str53{7,(i8*)"label: "},name),str53{4,(i8*)" at "}),String66(self.instructionsSize)));
}
	#line 303 f9__ //Expr
	i64 GetLabel190(Interp181& self,str53 name){
		#line 304 f9__ //Expr
		if((OpArray1252(self.labels,name)==0)){
			#line 305 f9__ //Expr
			OpArray1252(self.labels,name) = labelAddresses.length;
			#line 306 f9__ //Expr
			Push10250(labelAddresses,(-1));
		};
		#line 309 f9__ //Expr
		i64 r=OpArray1252(self.labels,name);
		#line 310 f9__ //Expr
		Assert260((r!=0),add64(str53{16,(i8*)"Label not found "},name));
		#line 311 f9__ //Expr
		return r;
}
	#line 314 f9__ //Expr
	void AddSpace191(Interp181& self,i8 value){
		#line 316 f9__ //Expr
		(*(i8*)(self.instructions.elements+self.instructionsSize)) = value;
		#line 317 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo23.size));
}
	#line 321 f9__ //Expr
	void AddValue192(Interp181& self,i8 value){
		#line 325 f9__ //Expr
		(*(i8*)(self.instructions.elements+self.instructionsSize)) = value;
		#line 326 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo23.size));
}
	#line 330 f9__ //Expr
	f64* AddValue193(Interp181& self,f64 value){
		#line 332 f9__ //Expr
		f64* r=(f64*)(self.instructions.elements+self.instructionsSize);
		#line 333 f9__ //Expr
		(*r) = value;
		#line 334 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo41.size));
		#line 335 f9__ //Expr
		return r;
}
	#line 337 f9__ //Expr
	i64* AddValue0256(Interp181& self,i64 value){
		#line 339 f9__ //Expr
		i64* r=(i64*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo38.size));
		#line 342 f9__ //Expr
		return r;
}
i32* AddValue1307(Interp181& self,i32 value){
		#line 339 f9__ //Expr
		i32* r=(i32*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo45.size));
		#line 342 f9__ //Expr
		return r;
}
i16* AddValue2310(Interp181& self,i16 value){
		#line 339 f9__ //Expr
		i16* r=(i16*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo48.size));
		#line 342 f9__ //Expr
		return r;
}
u64* AddValue3314(Interp181& self,u64 value){
		#line 339 f9__ //Expr
		u64* r=(u64*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo49.size));
		#line 342 f9__ //Expr
		return r;
}
u32* AddValue4317(Interp181& self,u32 value){
		#line 339 f9__ //Expr
		u32* r=(u32*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo50.size));
		#line 342 f9__ //Expr
		return r;
}
u16* AddValue5320(Interp181& self,u16 value){
		#line 339 f9__ //Expr
		u16* r=(u16*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo51.size));
		#line 342 f9__ //Expr
		return r;
}
u8* AddValue6323(Interp181& self,u8 value){
		#line 339 f9__ //Expr
		u8* r=(u8*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo52.size));
		#line 342 f9__ //Expr
		return r;
}
f32* AddValue7326(Interp181& self,f32 value){
		#line 339 f9__ //Expr
		f32* r=(f32*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo53.size));
		#line 342 f9__ //Expr
		return r;
}
str53* AddValue8329(Interp181& self,str53 value){
		#line 339 f9__ //Expr
		str53* r=(str53*)(self.instructions.elements+self.instructionsSize);
		#line 340 f9__ //Expr
		(*r) = value;
		#line 341 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo0.size));
		#line 342 f9__ //Expr
		return r;
}
	#line 345 f9__ //Expr
	f64* AddValue195(Interp181& self,f64 value){
		#line 347 f9__ //Expr
		f64* r=(f64*)(self.instructions.elements+self.instructionsSize);
		#line 348 f9__ //Expr
		(*r) = value;
		#line 349 f9__ //Expr
		self.instructionsSize = (self.instructionsSize+i64267(typeinfo41.size));
		#line 350 f9__ //Expr
		return r;
}
	#line 353 f9__ //Expr
	void AddLoadConstInstr0257(Interp181& self,i64 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo38.size));
		#line 356 f9__ //Expr
		AddValue0256(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo38.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr1304(Interp181& self,i8 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo23.size));
		#line 356 f9__ //Expr
		AddValue192(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo23.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr2306(Interp181& self,i32 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo45.size));
		#line 356 f9__ //Expr
		AddValue1307(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo45.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr3309(Interp181& self,i16 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo48.size));
		#line 356 f9__ //Expr
		AddValue2310(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo48.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr4313(Interp181& self,u64 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo49.size));
		#line 356 f9__ //Expr
		AddValue3314(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo49.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr5316(Interp181& self,u32 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo50.size));
		#line 356 f9__ //Expr
		AddValue4317(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo50.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr6319(Interp181& self,u16 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo51.size));
		#line 356 f9__ //Expr
		AddValue5320(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo51.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr7322(Interp181& self,u8 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo52.size));
		#line 356 f9__ //Expr
		AddValue6323(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo52.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr8325(Interp181& self,f32 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo53.size));
		#line 356 f9__ //Expr
		AddValue7326(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo53.size))),str53{6,(i8*)" value"}));
}
void AddLoadConstInstr9328(Interp181& self,str53 value){
		#line 354 f9__ //Expr
		AddValue192(self,LoadConst);
		#line 355 f9__ //Expr
		AddValue0256(self,i64267(typeinfo0.size));
		#line 356 f9__ //Expr
		AddValue8329(self,value);
		#line 357 f9__ //Expr
		PrintTabs364(1);
		#line 358 f9__ //Expr
		Println59(add64(add64(str53{6,(i8*)"load: "},String66(i64267(typeinfo0.size))),str53{6,(i8*)" value"}));
}
	#line 363 f9__ //Expr
	void StoreOffsetInstr197(Interp181& self,i64 offset,i64 size){
		#line 364 f9__ //Expr
		AddValue192(self,StoreOffsetInstr);
		#line 365 f9__ //Expr
		AddValue0256(self,(i64)size);
		#line 366 f9__ //Expr
		AddValue0256(self,(i64)offset);
		#line 367 f9__ //Expr
		PrintTabs364(1);
		#line 368 f9__ //Expr
		Println59(add64(add64(add64(str53{7,(i8*)"store: "},String66(size)),str53{9,(i8*)" offset: "}),String66(offset)));
}
	#line 372 f9__ //Expr
	void AddCall198(Interp181& self,str53 name){
		#line 374 f9__ //Expr
		PrintTabs364(1);
		#line 375 f9__ //Expr
		Println59(add64(str53{6,(i8*)"call: "},name));
		#line 376 f9__ //Expr
		AddLoadConstInstr0257(self,GetLabel190(self,name));
		#line 377 f9__ //Expr
		AddValue192(self,CallInstr);
		#line 378 f9__ //Expr
		Println59(str53{9,(i8*)"call end:"});
}
	#line 381 f9__ //Expr
	void AddCallExternVoid199(Interp181& self,str53 name){
		#line 382 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 383 f9__ //Expr
		AddValue192(self,CallExternVoid);
		#line 384 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 385 f9__ //Expr
		PrintTabs364(1);
		#line 386 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 389 f9__ //Expr
	void AddCallExtern8200(Interp181& self,str53 name){
		#line 390 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 391 f9__ //Expr
		AddValue192(self,CallExtern8);
		#line 392 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 393 f9__ //Expr
		PrintTabs364(1);
		#line 394 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 396 f9__ //Expr
	void AddCallExtern16201(Interp181& self,str53 name){
		#line 397 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 398 f9__ //Expr
		AddValue192(self,CallExtern16);
		#line 399 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 400 f9__ //Expr
		PrintTabs364(1);
		#line 401 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 403 f9__ //Expr
	void AddCallExtern32202(Interp181& self,str53 name){
		#line 404 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 405 f9__ //Expr
		AddValue192(self,CallExtern32);
		#line 406 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 407 f9__ //Expr
		PrintTabs364(1);
		#line 408 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 411 f9__ //Expr
	void AddCallExternf32203(Interp181& self,str53 name){
		#line 412 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 413 f9__ //Expr
		AddValue192(self,CallExtern_f32);
		#line 414 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 415 f9__ //Expr
		PrintTabs364(1);
		#line 416 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 419 f9__ //Expr
	void AddCallExtern64204(Interp181& self,str53 name){
		#line 420 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 421 f9__ //Expr
		AddValue192(self,CallExtern64);
		#line 422 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 423 f9__ //Expr
		PrintTabs364(1);
		#line 424 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 426 f9__ //Expr
	void AddCallExternPtr205(Interp181& self,str53 name){
		#line 427 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 428 f9__ //Expr
		AddValue192(self,CallExternPtr);
		#line 429 f9__ //Expr
		AddValue0256(self,(i64)func);
		#line 430 f9__ //Expr
		PrintTabs364(1);
		#line 431 f9__ //Expr
		Println59(add64(str53{13,(i8*)"call extern: "},name));
}
	#line 434 f9__ //Expr
	;
	#line 436 f9__ //Expr
	void AddExternCallLabel206(Interp181& self,str53 name){
		#line 437 f9__ //Expr
		voidptr func=dlsym(self.dlhandle,name.chars);
		#line 438 f9__ //Expr
		Assert260(((i64)func!=0),add64(add64(str53{34,(i8*)"Failed to find external function \""},name),str53{48,(i8*)"\" you probably need to dynamically link it first"}));
		#line 440 f9__ //Expr
		OpArray1252(self.labels,name) = (i64)func;
		#line 441 f9__ //Expr
		PrintTabs364(1);
		#line 442 f9__ //Expr
		Println59(add64(str53{15,(i8*)"label extern:  "},name));
}
		#line 450 f9__ //Expr
	void Init208(DebugLocal207& self,Variable498* variable,i64 offset){
		#line 451 f9__ //Expr
		self.variable = variable;
		#line 452 f9__ //Expr
		self.offset = offset;
}
		#line 461 f9__ //Expr
	void Init210(DebugFrame209& self,Function456* function){
		#line 462 f9__ //Expr
		self.function = function;
		#line 463 f9__ //Expr
		Init6258(self.locals);
}
	#line 466 f9__ //Expr
		#line 469 f9__ //Expr
	i8* GetInstr0263(Interp181& self){
		#line 470 f9__ //Expr
		i8* t=(i8*)(self.instructions.elements+self.iPtr);
		#line 471 f9__ //Expr
		self.iPtr = (self.iPtr+(i64)typeinfo23.size);
		#line 472 f9__ //Expr
		return t;
}
i64* GetInstr1264(Interp181& self){
		#line 470 f9__ //Expr
		i64* t=(i64*)(self.instructions.elements+self.iPtr);
		#line 471 f9__ //Expr
		self.iPtr = (self.iPtr+(i64)typeinfo38.size);
		#line 472 f9__ //Expr
		return t;
}
	#line 475 f9__ //Expr
	i8* GetInstr213(Interp181& self,i64 size){
		#line 476 f9__ //Expr
		i8* t=(i8*)(self.instructions.elements+self.iPtr);
		#line 477 f9__ //Expr
		self.iPtr = (self.iPtr+size);
		#line 478 f9__ //Expr
		return t;
}
	#line 482 f9__ //Expr
	i8* PrintType214(Type413* t,i8* location){
		#line 484 f9__ //Expr
		Type413* typ=Resolved127((*t));
		#line 486 f9__ //Expr
		if(Is0141((*typ))){
			#line 487 f9__ //Expr
			i64 value=(*(i64*)location);
			#line 488 f9__ //Expr
			Print58(add64(str53{1,(i8*)"x"},String66(value)));
			#line 489 f9__ //Expr
			Print58(str53{2,(i8*)": "});
			#line 490 f9__ //Expr
			if(value){
				#line 491 f9__ //Expr
				PrintType214((*As0142((*typ))).reference,(i8*)value);
			};
			#line 493 f9__ //Expr
			return (location+8);
		};
		#line 495 f9__ //Expr
		if(Is7156((*typ))){
			#line 496 f9__ //Expr
			TypeNumber431* self=As7157((*typ));
			#line 497 f9__ //Expr
			i64 value={0};
			#line 498 f9__ //Expr
			if(((*self).size==1)){
				#line 499 f9__ //Expr
				value = (*(i8*)location);
			};
			#line 501 f9__ //Expr
			if(((*self).size==2)){
				#line 502 f9__ //Expr
				value = (*(i16*)location);
			};
			#line 504 f9__ //Expr
			if(((*self).size==4)){
				#line 505 f9__ //Expr
				value = (*(i32*)location);
			};
			#line 507 f9__ //Expr
			if(((*self).size==8)){
				#line 508 f9__ //Expr
				value = (*(i64*)location);
			};
			#line 510 f9__ //Expr
			Print58(String66(value));
			#line 511 f9__ //Expr
			return (location+(*self).size);
		}else{
			#line 513 f9__ //Expr
			if(Is1143((*typ))){
				#line 514 f9__ //Expr
				Expr366* spec=(*As1144((*typ))).spec;
				#line 515 f9__ //Expr
				Structure473* structure=As2124((*spec));
				#line 516 f9__ //Expr
				if(equal68((*structure).ident,str53{7,(i8*)"voidptr"})){
					#line 517 f9__ //Expr
					i64 value=(*(i64*)location);
					#line 518 f9__ //Expr
					Print58(add64(str53{1,(i8*)"x"},String66(value)));
					#line 519 f9__ //Expr
					return (location+8);
				};
				#line 521 f9__ //Expr
				if(equal68((*structure).ident,str53{3,(i8*)"Str"})){
					#line 522 f9__ //Expr
					str53 chars=(*(str53*)location);
					#line 523 f9__ //Expr
					Print58(str53{1,(i8*)"\""});
					#line 524 f9__ //Expr
					Print58(chars);
					#line 525 f9__ //Expr
					Print58(str53{1,(i8*)"\""});
					#line 526 f9__ //Expr
					return (location+16);
				};
				#line 528 f9__ //Expr
				i8* at=location;
				#line 529 f9__ //Expr
				for(i64 it = i64265(0); it<(*structure).fields.length;it++){
					#line 530 f9__ //Expr
					Print58((*OpArray5125((*structure).fields,it)).ident);
					#line 531 f9__ //Expr
					Print58(str53{2,(i8*)": "});
					#line 532 f9__ //Expr
					at = PrintType214((*OpArray5125((*structure).fields,it)).super.typ,at);
					#line 533 f9__ //Expr
					Print58(str53{1,(i8*)" "});
				};
				#line 535 f9__ //Expr
				return at;
			};
		};
		#line 537 f9__ //Expr
		if(Is6153((*typ))){
			#line 538 f9__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 539 f9__ //Expr
			StructureSpec479* spec={0};
			#line 539 f9__ //Expr
			spec = As18259((*(*self).spec));
			#line 540 f9__ //Expr
			Apply487((*(*spec).structure),(*spec));
			#line 541 f9__ //Expr
			return PrintType214((*(*spec).structure).typeIdent,location);
		};
		#line 543 f9__ //Expr
		return location;
}
	#line 546 f9__ //Expr
	void PrintFrame215(Interp181& self,DebugFrame209* frame,i64 current,i64 instrPtr){
		#line 547 f9__ //Expr
		Println59(str53{49,(i8*)"----------------------Frame----------------------"});
		#line 549 f9__ //Expr
		Assert5260(frame,str53{8,(i8*)"No frame"});
		#line 551 f9__ //Expr
		if((*(*frame).function).super.at.file){
			#line 552 f9__ //Expr
			Print58((*OpArray1107(project.files,((*(*frame).function).super.at.file-1))).path);
		};
		#line 554 f9__ //Expr
		Print58(str53{1,(i8*)":"});
		#line 555 f9__ //Expr
		Print58(String66((*(*frame).function).super.at.line));
		#line 556 f9__ //Expr
		Print58(str53{1,(i8*)":"});
		#line 557 f9__ //Expr
		Print58(String66((*(*frame).function).super.at.column));
		#line 558 f9__ //Expr
		Println59(str53{1,(i8*)":"});
		#line 559 f9__ //Expr
		Println59((*(*frame).function).ident);
		#line 561 f9__ //Expr
		for(i64 it = i64265(0); it<(*frame).locals.length;it++){
			#line 562 f9__ //Expr
			DebugLocal207* local=OpArray15261((*frame).locals,it);
			#line 563 f9__ //Expr
			Print58(String66((*(*local).variable).super.at.line));
			#line 564 f9__ //Expr
			Print58(str53{1,(i8*)":"});
			#line 565 f9__ //Expr
			i64 len=(4-String66((*(*local).variable).super.at.line).length);
			#line 566 f9__ //Expr
			for(i64 it = i64265(0); it<len;it++){
				#line 567 f9__ //Expr
				Print58(str53{1,(i8*)" "});
			};
			#line 570 f9__ //Expr
			str53 value=add64(add64((*(*local).variable).ident,str53{1,(i8*)" "}),String105((*(*local).variable).super.typ));
			#line 571 f9__ //Expr
			while((value.length<25)){
				#line 572 f9__ //Expr
				value = add64(value,str53{1,(i8*)" "});
			};
			#line 575 f9__ //Expr
			Print58(value);
			#line 576 f9__ //Expr
			Print58(str53{2,(i8*)"= "});
			#line 577 f9__ //Expr
			PrintType214((*(*local).variable).super.typ,(i8*)(current-(*local).offset));
			#line 579 f9__ //Expr
			if(((*local).instr>=instrPtr)){
				#line 580 f9__ //Expr
				Print58(str53{26,(i8*)"    <<<<<-unreached ->>>>>"});
			};
			#line 582 f9__ //Expr
			Println59(str53{0,(i8*)""});
		};
		#line 584 f9__ //Expr
		Println59(str53{49,(i8*)"-------------------------------------------------"});
}
	#line 589 f9__ //Expr
	DebugFrame209* FrameAt216(Interp181& self,i64 instr){
		#line 591 f9__ //Expr
		Println59(add64(str53{10,(i8*)"Frame at: "},String66(instr)));
		#line 592 f9__ //Expr
		for(i64 it = i64265(0); it<self.frameArray.length;it++){
			#line 594 f9__ //Expr
			if(((instr>=(*OpArray16262(self.frameArray,it)).startInstr)&&(instr<=(*OpArray16262(self.frameArray,it)).endInstr))){
				#line 597 f9__ //Expr
				return OpArray16262(self.frameArray,it);
			};
		};
		#line 601 f9__ //Expr
		Assert260(0,add64(str53{16,(i8*)"frame not found "},String66(instr)));
		#line 602 f9__ //Expr
		return (DebugFrame209*)0;
}
	#line 605 f9__ //Expr
	void PrintFrame217(Interp181& self,i64 frame,i64 instr,i64 returnInstr){
		#line 607 f9__ //Expr
		if((!instr)){
			#line 608 f9__ //Expr
			return ;
		};
		#line 611 f9__ //Expr
		PrintFrame215(self,FrameAt216(self,instr),frame,instr);
		#line 616 f9__ //Expr
		if(((i64)frame>=(i64)self.stackTop)){
			#line 617 f9__ //Expr
			Assert260((frame==(i64)self.stackTop),str53{84,(i8*)"Santity check, Expected frame pointer of the top frame to be at the top of the stack"});
			#line 618 f9__ //Expr
			return ;
		};
		#line 621 f9__ //Expr
		i64 prevInstrPtr=(frame+8);
		#line 622 f9__ //Expr
		i64 prevFramePtr=(frame+0);
		#line 624 f9__ //Expr
		i64 prevFrame=(*(i64*)prevFramePtr);
		#line 625 f9__ //Expr
		i64 prevPreInstr=(*(i64*)prevInstrPtr);
		#line 627 f9__ //Expr
		PrintFrame217(self,prevFrame,returnInstr,prevPreInstr);
}
	#line 629 f9__ //Expr
	void PrintFrame218(Interp181& self){
		#line 631 f9__ //Expr
		PrintFrame217(self,self.frame,self.iPtr,self.rPtr);
}
	#line 635 f9__ //Expr
	void Run219(Interp181& self,str53 label){
		#line 637 f9__ //Expr
		self.iPtr = OpArray14255(labelAddresses,GetLabel190(self,str53{4,(i8*)"main"}));
		#line 638 f9__ //Expr
		self.frame = (i64)self.sPtr;
		#line 640 f9__ //Expr
		Assert261((self.iPtr>=0));
		#line 642 f9__ //Expr
		Println59(add64(str53{12,(i8*)"Running at: "},String66(self.iPtr)));
		#line 643 f9__ //Expr
		Println59(str53{37,(i8*)"------------running------------------"});
		#line 644 f9__ //Expr
		Run220(self);
		#line 645 f9__ //Expr
		Println59(str53{39,(i8*)"\n------------finished------------------"});
}
	#line 648 f9__ //Expr
	void Run220(Interp181& self){
		#line 650 f9__ //Expr
		while((self.iPtr<self.instructions.length)){
			#line 659 f9__ //Expr
			i8 op=(*GetInstr0263(self));
			#line 660 f9__ //Expr
			if((op==LoadConst)){
				#line 662 f9__ //Expr
				i64 size=(*GetInstr1264(self));
				#line 663 f9__ //Expr
				i8* data=GetInstr213(self,size);
				#line 664 f9__ //Expr
				Push0265(self,data,size);
			}else{
				#line 667 f9__ //Expr
				if((op==LoadInstr)){
					#line 669 f9__ //Expr
					i64 size=(*GetInstr1264(self));
					#line 670 f9__ //Expr
					i64 address=(*GetInstr1264(self));
					#line 671 f9__ //Expr
					Push0265(self,(i8*)address,size);
				}else{
					#line 675 f9__ //Expr
					if((op==LoadAddressInstr)){
						#line 677 f9__ //Expr
						i64 address=Pop0266(self);
						#line 680 f9__ //Expr
						i64 size=(*GetInstr1264(self));
						#line 681 f9__ //Expr
						Push0265(self,(i8*)address,size);
					}else{
						#line 684 f9__ //Expr
						if((op==LoadOffsetInstr)){
							#line 686 f9__ //Expr
							i64 size=(*GetInstr1264(self));
							#line 687 f9__ //Expr
							i64 offset=(*GetInstr1264(self));
							#line 690 f9__ //Expr
							i64 address=(self.frame-offset);
							#line 694 f9__ //Expr
							Push0265(self,(i8*)address,size);
						}else{
							#line 696 f9__ //Expr
							if((op==AddOffsetToAddressInstr)){
								#line 698 f9__ //Expr
								i64 offset=(*GetInstr1264(self));
								#line 699 f9__ //Expr
								i64 address=Pop0266(self);
								#line 700 f9__ //Expr
								Push0267(self,i64271((address+offset)));
							}else{
								#line 702 f9__ //Expr
								if((op==LoadAddressFromOffsetInstr)){
									#line 704 f9__ //Expr
									i64 offset=(*GetInstr1264(self));
									#line 705 f9__ //Expr
									i64 address=(self.frame-offset);
									#line 706 f9__ //Expr
									Push0267(self,i64271(address));
								}else{
									#line 709 f9__ //Expr
									if((op==StoreOffsetInstr)){
										#line 711 f9__ //Expr
										i64 size=(*GetInstr1264(self));
										#line 712 f9__ //Expr
										i64 offset=(*GetInstr1264(self));
										#line 713 f9__ //Expr
										i64 address=(self.frame-offset);
										#line 714 f9__ //Expr
										Assert261((address!=0));
										#line 716 f9__ //Expr
										i32 value=(*(i32*)self.sPtr);
										#line 719 f9__ //Expr
										StorePtr188(self,(i8*)address,self.sPtr,size);
										#line 720 f9__ //Expr
										self.sPtr = (self.sPtr+size);
									}else{
										#line 723 f9__ //Expr
										if((op==DiscardInstr)){
											#line 725 f9__ //Expr
											i64 size=(*GetInstr1264(self));
											#line 727 f9__ //Expr
											for(i64 it = i64265(0); it<size;it++){
												#line 728 f9__ //Expr
												Pop1268(self);
											};
										}else{
											#line 731 f9__ //Expr
											if((op==StoreInstr)){
												#line 733 f9__ //Expr
												i64 size=(*GetInstr1264(self));
												#line 734 f9__ //Expr
												i64 offset=(*GetInstr1264(self));
												#line 735 f9__ //Expr
												i64 address=(Pop0266(self)-offset);
												#line 737 f9__ //Expr
												Assert260((address!=0),str53{29,(i8*)"attempt to store at address 0"});
												#line 739 f9__ //Expr
												StorePtr188(self,(i8*)address,self.sPtr,size);
												#line 740 f9__ //Expr
												self.sPtr = (self.sPtr+size);
											}else{
												#line 747 f9__ //Expr
												if((op==AddPtrInstr)){
													#line 749 f9__ //Expr
													i64 size=(*GetInstr1264(self));
													#line 750 f9__ //Expr
													i64 right=(Pop0266(self)*size);
													#line 751 f9__ //Expr
													i64 left=Pop0266(self);
													#line 753 f9__ //Expr
													Push0267(self,i64271((left+right)));
												}else{
													#line 755 f9__ //Expr
													if((op==AddInstr_i64)){
														#line 757 f9__ //Expr
														i64 r=Pop0266(self);
														#line 758 f9__ //Expr
														i64 l=Pop0266(self);
														#line 760 f9__ //Expr
														Push0267(self,i64271((l+r)));
													}else{
														#line 762 f9__ //Expr
														if((op==MulInstr_i64)){
															#line 764 f9__ //Expr
															i64 l=Pop0266(self);
															#line 765 f9__ //Expr
															i64 r=Pop0266(self);
															#line 767 f9__ //Expr
															Push0267(self,i64271((l*r)));
														}else{
															#line 769 f9__ //Expr
															if((op==SubInstr_i64)){
																#line 771 f9__ //Expr
																i64 r=Pop0266(self);
																#line 772 f9__ //Expr
																i64 l=Pop0266(self);
																#line 774 f9__ //Expr
																Push0267(self,i64271((l-r)));
															}else{
																#line 776 f9__ //Expr
																if((op==DivInstr_i64)){
																	#line 778 f9__ //Expr
																	i64 r=Pop0266(self);
																	#line 779 f9__ //Expr
																	i64 l=Pop0266(self);
																	#line 781 f9__ //Expr
																	Push0267(self,i64271((l/r)));
																}else{
																	#line 783 f9__ //Expr
																	if((op==ModInstr_i64)){
																		#line 785 f9__ //Expr
																		i64 r=Pop0266(self);
																		#line 786 f9__ //Expr
																		i64 l=Pop0266(self);
																		#line 787 f9__ //Expr
																		Push0267(self,i64271((l%r)));
																	}else{
																		#line 789 f9__ //Expr
																		if((op==AndInstr_i64)){
																			#line 791 f9__ //Expr
																			i8 r=Pop1268(self);
																			#line 792 f9__ //Expr
																			i8 l=Pop1268(self);
																			#line 793 f9__ //Expr
																			Push1269(self,i8294((l&&r)));
																		}else{
																			#line 795 f9__ //Expr
																			if((op==OrInstr_i64)){
																				#line 797 f9__ //Expr
																				i8 r=Pop1268(self);
																				#line 798 f9__ //Expr
																				i8 l=Pop1268(self);
																				#line 799 f9__ //Expr
																				Push1269(self,i8294((l||r)));
																			}else{
																				#line 801 f9__ //Expr
																				if((op==AddInstr_f32)){
																					#line 803 f9__ //Expr
																					f32 r=Pop2270(self);
																					#line 804 f9__ //Expr
																					f32 l=Pop2270(self);
																					#line 806 f9__ //Expr
																					Push2271(self,f32336((l+r)));
																				}else{
																					#line 808 f9__ //Expr
																					if((op==MulInstr_f32)){
																						#line 810 f9__ //Expr
																						f32 l=Pop2270(self);
																						#line 811 f9__ //Expr
																						f32 r=Pop2270(self);
																						#line 813 f9__ //Expr
																						Push2271(self,f32336((l*r)));
																					}else{
																						#line 815 f9__ //Expr
																						if((op==SubInstr_f32)){
																							#line 817 f9__ //Expr
																							f32 r=Pop2270(self);
																							#line 818 f9__ //Expr
																							f32 l=Pop2270(self);
																							#line 820 f9__ //Expr
																							Push2271(self,f32336((l-r)));
																						}else{
																							#line 822 f9__ //Expr
																							if((op==DivInstr_f32)){
																								#line 824 f9__ //Expr
																								f32 r=Pop2270(self);
																								#line 825 f9__ //Expr
																								f32 l=Pop2270(self);
																								#line 827 f9__ //Expr
																								Push2271(self,f32336((l/r)));
																							}else{
																								#line 829 f9__ //Expr
																								if((op==CallInstr)){
																									#line 831 f9__ //Expr
																									i64 l=Pop0266(self);
																									#line 832 f9__ //Expr
																									i64 address=OpArray14255(labelAddresses,l);
																									#line 835 f9__ //Expr
																									Assert260((self.rPtr<self.instructionsSize),add64(str53{43,(i8*)"sr instr address outside possible range at:"},String66(self.iPtr)));
																									#line 839 f9__ //Expr
																									Push0267(self,(i64)self.rPtr);
																									#line 840 f9__ //Expr
																									Push0267(self,(i64)self.frame);
																									#line 842 f9__ //Expr
																									self.rPtr = self.iPtr;
																									#line 843 f9__ //Expr
																									self.iPtr = address;
																									#line 844 f9__ //Expr
																									Assert260((address<self.instructionsSize),str53{36,(i8*)"instr address outside possible range"});
																									#line 845 f9__ //Expr
																									self.frame = (i64)self.sPtr;
																								}else{
																									#line 847 f9__ //Expr
																									if((op==ReturnInstr)){
																										#line 848 f9__ //Expr
																										if((self.rPtr==0)){
																											#line 849 f9__ //Expr
																											self.iPtr = 10000000000000;
																										}else{
																											#line 853 f9__ //Expr
																											self.iPtr = self.rPtr;
																											#line 854 f9__ //Expr
																											Assert260((self.iPtr<self.instructionsSize),add64(str53{40,(i8*)"instr address outside possible range at:"},String66(self.iPtr)));
																											#line 856 f9__ //Expr
																											self.sPtr = (i8*)self.frame;
																											#line 860 f9__ //Expr
																											self.frame = Pop0266(self);
																											#line 861 f9__ //Expr
																											self.rPtr = Pop0266(self);
																											#line 862 f9__ //Expr
																											Assert260((self.rPtr<self.instructionsSize),add64(str53{42,(i8*)"r instr address outside possible range at:"},String66(self.iPtr)));
																										};
																									}else{
																										#line 867 f9__ //Expr
																										if((op==CallExternPtr)){
																											#line 868 f9__ //Expr
																											i64 address=(*GetInstr1264(self));
																											#line 869 f9__ //Expr
																											i64 ret=(i64)dcCallPointer(self.cvm,(voidptr)address);
																											#line 870 f9__ //Expr
																											Push0267(self,ret);
																											#line 871 f9__ //Expr
																											dcReset(self.cvm);
																										}else{
																											#line 874 f9__ //Expr
																											if((op==CallExternVoid)){
																												#line 875 f9__ //Expr
																												i64 address=(*GetInstr1264(self));
																												#line 876 f9__ //Expr
																												dcCallVoid(self.cvm,(voidptr)address);
																												#line 877 f9__ //Expr
																												dcReset(self.cvm);
																											}else{
																												#line 879 f9__ //Expr
																												if((op==CallExtern_8)){
																													#line 880 f9__ //Expr
																													i64 address=(*GetInstr1264(self));
																													#line 881 f9__ //Expr
																													Push1269(self,i8293(dcCallChar(self.cvm,(voidptr)address)));
																													#line 882 f9__ //Expr
																													dcReset(self.cvm);
																												}else{
																													#line 884 f9__ //Expr
																													if((op==CallExtern_16)){
																														#line 885 f9__ //Expr
																														i64 address=(*GetInstr1264(self));
																														#line 886 f9__ //Expr
																														Push3272(self,i16282(dcCallShort(self.cvm,(voidptr)address)));
																														#line 887 f9__ //Expr
																														dcReset(self.cvm);
																													}else{
																														#line 889 f9__ //Expr
																														if((op==CallExtern32)){
																															#line 890 f9__ //Expr
																															i64 address=(*GetInstr1264(self));
																															#line 891 f9__ //Expr
																															Push4273(self,i32278(dcCallInt(self.cvm,(voidptr)address)));
																															#line 892 f9__ //Expr
																															dcReset(self.cvm);
																														}else{
																															#line 894 f9__ //Expr
																															if((op==CallExtern64)){
																																#line 895 f9__ //Expr
																																i64 address=(*GetInstr1264(self));
																																#line 896 f9__ //Expr
																																Push0267(self,i64271(dcCallLong(self.cvm,(voidptr)address)));
																																#line 897 f9__ //Expr
																																dcReset(self.cvm);
																															}else{
																																#line 899 f9__ //Expr
																																if((op==CallExtern_f32)){
																																	#line 900 f9__ //Expr
																																	i64 address=(*GetInstr1264(self));
																																	#line 901 f9__ //Expr
																																	Push2271(self,f32336(dcCallFloat(self.cvm,(voidptr)address)));
																																	#line 902 f9__ //Expr
																																	dcReset(self.cvm);
																																}else{
																																	#line 904 f9__ //Expr
																																	if((op==CallExtern_f64)){
																																		#line 905 f9__ //Expr
																																		i64 address=(*GetInstr1264(self));
																																		#line 906 f9__ //Expr
																																		Push5274(self,f64345(dcCallDouble(self.cvm,(voidptr)address)));
																																		#line 907 f9__ //Expr
																																		dcReset(self.cvm);
																																	}else{
																																		#line 909 f9__ //Expr
																																		if((op==ParamExtern_8)){
																																			#line 910 f9__ //Expr
																																			i8 value=Pop1268(self);
																																			#line 911 f9__ //Expr
																																			dcArgChar(self.cvm,value);
																																		}else{
																																			#line 913 f9__ //Expr
																																			if((op==ParamExtern_16)){
																																				#line 914 f9__ //Expr
																																				i16 value=Pop3275(self);
																																				#line 915 f9__ //Expr
																																				dcArgShort(self.cvm,value);
																																			}else{
																																				#line 917 f9__ //Expr
																																				if((op==ParamExtern_32)){
																																					#line 918 f9__ //Expr
																																					i32 value=Pop4276(self);
																																					#line 919 f9__ //Expr
																																					dcArgInt(self.cvm,value);
																																				}else{
																																					#line 921 f9__ //Expr
																																					if((op==ParamExtern_64)){
																																						#line 922 f9__ //Expr
																																						i64 value=Pop0266(self);
																																						#line 923 f9__ //Expr
																																						dcArgLong(self.cvm,value);
																																					}else{
																																						#line 925 f9__ //Expr
																																						if((op==ParamExtern_Ptr)){
																																							#line 926 f9__ //Expr
																																							i64 ptr=Pop0266(self);
																																							#line 927 f9__ //Expr
																																							dcArgLong(self.cvm,ptr);
																																						}else{
																																							#line 929 f9__ //Expr
																																							if((op==ParamExtern_f32)){
																																								#line 930 f9__ //Expr
																																								f32 value=Pop2270(self);
																																								#line 931 f9__ //Expr
																																								dcArgFloat(self.cvm,value);
																																							}else{
																																								#line 933 f9__ //Expr
																																								if((op==ParamExtern_f64)){
																																									#line 934 f9__ //Expr
																																									f64 value=Pop5277(self);
																																									#line 935 f9__ //Expr
																																									dcArgDouble(self.cvm,value);
																																								}else{
																																									#line 937 f9__ //Expr
																																									if((op==CompareInstr_i64)){
																																										#line 938 f9__ //Expr
																																										i64 b=Pop0266(self);
																																										#line 939 f9__ //Expr
																																										i64 a=Pop0266(self);
																																										#line 942 f9__ //Expr
																																										Push1269(self,i8294(((a>b)-(a<b))));
																																									}else{
																																										#line 944 f9__ //Expr
																																										if((op==TestGreaterInstr)){
																																											#line 945 f9__ //Expr
																																											i8 test=Pop1268(self);
																																											#line 946 f9__ //Expr
																																											Push1269(self,i8293((test>0)));
																																										}else{
																																											#line 948 f9__ //Expr
																																											if((op==TestGreaterEqInstr)){
																																												#line 949 f9__ //Expr
																																												i8 test=Pop1268(self);
																																												#line 950 f9__ //Expr
																																												Push1269(self,i8293((test>=0)));
																																											}else{
																																												#line 952 f9__ //Expr
																																												if((op==TestLessInstr)){
																																													#line 953 f9__ //Expr
																																													i8 test=Pop1268(self);
																																													#line 954 f9__ //Expr
																																													Push1269(self,i8293((test<0)));
																																												}else{
																																													#line 956 f9__ //Expr
																																													if((op==TestLessEqInstr)){
																																														#line 957 f9__ //Expr
																																														i8 test=Pop1268(self);
																																														#line 958 f9__ //Expr
																																														Push1269(self,i8293((test<=0)));
																																													}else{
																																														#line 960 f9__ //Expr
																																														if((op==TestEqInstr)){
																																															#line 961 f9__ //Expr
																																															i8 test=Pop1268(self);
																																															#line 962 f9__ //Expr
																																															Push1269(self,i8293((test==0)));
																																														}else{
																																															#line 964 f9__ //Expr
																																															if((op==TestNotEqInstr)){
																																																#line 965 f9__ //Expr
																																																i8 test=Pop1268(self);
																																																#line 966 f9__ //Expr
																																																Push1269(self,i8293((test!=0)));
																																															}else{
																																																#line 968 f9__ //Expr
																																																if((op==JumpInstr)){
																																																	#line 969 f9__ //Expr
																																																	i64 instruction=(*GetInstr1264(self));
																																																	#line 970 f9__ //Expr
																																																	i8 test=Pop1268(self);
																																																	#line 971 f9__ //Expr
																																																	if((!test)){
																																																		#line 972 f9__ //Expr
																																																		self.iPtr = instruction;
																																																	};
																																																}else{
																																																	#line 975 f9__ //Expr
																																																	if((op==ConvertInstr_64_32)){
																																																		#line 977 f9__ //Expr
																																																		i32 value=i32279(Pop0266(self));
																																																		#line 979 f9__ //Expr
																																																		Push4273(self,value);
																																																	}else{
																																																		#line 981 f9__ //Expr
																																																		if((op==WidenInstr_8_64)){
																																																			#line 982 f9__ //Expr
																																																			i8 v=Pop1268(self);
																																																			#line 983 f9__ //Expr
																																																			Push0267(self,i64269(v));
																																																		}else{
																																																			#line 985 f9__ //Expr
																																																			if((op==WidenInstr_16_64)){
																																																				#line 986 f9__ //Expr
																																																				Push0267(self,i64271(Pop0266(self)));
																																																			}else{
																																																				#line 988 f9__ //Expr
																																																				if((op==WidenInstr_32_64)){
																																																					#line 989 f9__ //Expr
																																																					Push0267(self,i64270(Pop4276(self)));
																																																				}else{
																																																					#line 992 f9__ //Expr
																																																					if((op==CastInstr_i64_f64)){
																																																						#line 993 f9__ //Expr
																																																						Push5274(self,f64343(Pop0266(self)));
																																																					}else{
																																																						#line 995 f9__ //Expr
																																																						if((op==CastInstr_i64_f32)){
																																																							#line 996 f9__ //Expr
																																																							Push2271(self,f32335(Pop0266(self)));
																																																						}else{
																																																							#line 998 f9__ //Expr
																																																							if((op==CastInstr_f64_i64)){
																																																								#line 999 f9__ //Expr
																																																								Push0267(self,i64273(Pop5277(self)));
																																																							}else{
																																																								#line 1001 f9__ //Expr
																																																								if((op==CastInstr_f32_i64)){
																																																									#line 1002 f9__ //Expr
																																																									Push0267(self,i64272(Pop2270(self)));
																																																								}else{
																																																									#line 1004 f9__ //Expr
																																																									if((op==CastInstr_f32_f64)){
																																																										#line 1005 f9__ //Expr
																																																										Push5274(self,f64344(Pop2270(self)));
																																																									}else{
																																																										#line 1007 f9__ //Expr
																																																										if((op==CastInstr_f64_f32)){
																																																											#line 1008 f9__ //Expr
																																																											f64 value=Pop5277(self);
																																																											#line 1009 f9__ //Expr
																																																											Push2271(self,f32337(value));
																																																										}else{
																																																											#line 1011 f9__ //Expr
																																																											if((op==ConvertInstr)){
																																																												#line 1012 f9__ //Expr
																																																												i8 from=(*GetInstr0263(self));
																																																												#line 1013 f9__ //Expr
																																																												i8 to=(*GetInstr0263(self));
																																																												#line 1015 f9__ //Expr
																																																												i64 value={0};
																																																												#line 1016 f9__ //Expr
																																																												if((from==8)){
																																																													#line 1017 f9__ //Expr
																																																													value = Pop0266(self);
																																																												}else{
																																																													#line 1019 f9__ //Expr
																																																													if((from==4)){
																																																														#line 1020 f9__ //Expr
																																																														value = Pop4276(self);
																																																													}else{
																																																														#line 1022 f9__ //Expr
																																																														if((from==2)){
																																																															#line 1023 f9__ //Expr
																																																															value = Pop3275(self);
																																																														}else{
																																																															#line 1025 f9__ //Expr
																																																															if((from==1)){
																																																																#line 1026 f9__ //Expr
																																																																value = Pop1268(self);
																																																															}else{
																																																																#line 1029 f9__ //Expr
																																																																Assert260(0,str53{13,(i8*)"No conversion"});
																																																															};
																																																														};
																																																													};
																																																												};
																																																												#line 1032 f9__ //Expr
																																																												if((to==8)){
																																																													#line 1033 f9__ //Expr
																																																													Push0267(self,i64271(value));
																																																												}else{
																																																													#line 1035 f9__ //Expr
																																																													if((to==4)){
																																																														#line 1036 f9__ //Expr
																																																														Push4273(self,i32279(value));
																																																													}else{
																																																														#line 1038 f9__ //Expr
																																																														if((to==2)){
																																																															#line 1039 f9__ //Expr
																																																															Push3272(self,i16287(value));
																																																														}else{
																																																															#line 1041 f9__ //Expr
																																																															if((to==1)){
																																																																#line 1042 f9__ //Expr
																																																																Push1269(self,i8295(value));
																																																															}else{
																																																																#line 1045 f9__ //Expr
																																																																Assert260(0,str53{13,(i8*)"No conversion"});
																																																															};
																																																														};
																																																													};
																																																												};
																																																											}else{
																																																												#line 1048 f9__ //Expr
																																																												if((op==TrapInstr)){
																																																													#line 1049 f9__ //Expr
																																																													i8 code=(*GetInstr0263(self));
																																																													#line 1050 f9__ //Expr
																																																													if((code==0)){
																																																														#line 1052 f9__ //Expr
																																																														Println59(str53{9,(i8*)"\nAborting"});
																																																														#line 1053 f9__ //Expr
																																																														PrintFrame218(self);
																																																														#line 1054 f9__ //Expr
																																																														return ;
																																																													};
																																																													#line 1056 f9__ //Expr
																																																													Println59(add64(str53{19,(i8*)"Uhandled trap code "},String66(code)));
																																																													#line 1057 f9__ //Expr
																																																													return ;
																																																												}else{
																																																													#line 1061 f9__ //Expr
																																																													Println59(add64(add64(add64(str53{22,(i8*)"Unhandled instruction "},String66(op)),str53{5,(i8*)" at: "}),String66(self.iPtr)));
																																																													#line 1062 f9__ //Expr
																																																													Println59(str53{34,(i8*)"----------------------------------"});
																																																													#line 1063 f9__ //Expr
																																																													return ;
																																																												};
																																																											};
																																																										};
																																																									};
																																																								};
																																																							};
																																																						};
																																																					};
																																																				};
																																																			};
																																																		};
																																																	};
																																																};
																																															};
																																														};
																																													};
																																												};
																																											};
																																										};
																																									};
																																								};
																																							};
																																						};
																																					};
																																				};
																																			};
																																		};
																																	};
																																};
																															};
																														};
																													};
																												};
																											};
																										};
																									};
																								};
																							};
																						};
																					};
																				};
																			};
																		};
																	};
																};
															};
														};
													};
												};
											};
										};
									};
								};
							};
						};
					};
				};
			};
		};
}
	#line 9 f10__ //Expr
	i64 Size221(Type413* t){
		#line 10 f10__ //Expr
		Type413* typ=Resolved127((*t));
		#line 11 f10__ //Expr
		if(Is0141((*typ))){
			#line 12 f10__ //Expr
			return 8;
		}else{
			#line 14 f10__ //Expr
			if(Is1143((*typ))){
				#line 15 f10__ //Expr
				Expr366* spec=(*As1144((*typ))).spec;
				#line 16 f10__ //Expr
				Structure473* structure=As2124((*spec));
				#line 18 f10__ //Expr
				if(equal68((*structure).ident,str53{7,(i8*)"voidptr"})){
					#line 18 f10__ //Expr
					return 8;
				};
				#line 20 f10__ //Expr
				i64 size={0};
				#line 21 f10__ //Expr
				for(i64 it = i64265(0); it<(*structure).fields.length;it++){
					#line 22 f10__ //Expr
					size = (size+Size221((*OpArray5125((*structure).fields,it)).super.typ));
				};
				#line 24 f10__ //Expr
				return size;
			}else{
				#line 26 f10__ //Expr
				if(Is8200((*typ))){
					#line 27 f10__ //Expr
					TypeStructure481* self=As8223((*typ));
					#line 29 f10__ //Expr
					i64 size={0};
					#line 30 f10__ //Expr
					for(i64 it = i64265(0); it<(*self).fields.length;it++){
						#line 31 f10__ //Expr
						size = (size+Size221(OpArray6155((*self).fields,it)));
					};
					#line 33 f10__ //Expr
					return size;
				};
			};
		};
		#line 35 f10__ //Expr
		if(Is6153((*typ))){
			#line 36 f10__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 37 f10__ //Expr
			i64 size=Size221((&(*(*self).referenced).super));
			#line 38 f10__ //Expr
			return size;
		};
		#line 41 f10__ //Expr
		if(Is5151((*typ))){
			#line 42 f10__ //Expr
			return 0;
		};
		#line 44 f10__ //Expr
		if(Is7156((*typ))){
			#line 45 f10__ //Expr
			return (*As7157((*typ))).size;
		};
		#line 49 f10__ //Expr
		Println59(add64(str53{26,(i8*)"unhandled type for Size : "},String66((*typ).kind)));
		#line 50 f10__ //Expr
		return 0;
}
	#line 52 f10__ //Expr
	i64 Size222(ExpressionList369& expressions){
		#line 54 f10__ //Expr
		i64 size={0};
		#line 55 f10__ //Expr
		for(i64 it = i64265(0); it<expressions.list.length;it++){
			#line 56 f10__ //Expr
			size = (size+Size221((*OpArray4122(expressions.list,it)).typ));
		};
		#line 58 f10__ //Expr
		return size;
}
	#line 60 f10__ //Expr
	i64 Size223(Expr366* t){
		#line 61 f10__ //Expr
		if(Is9138((*t))){
			#line 62 f10__ //Expr
			return 0;
		};
		#line 64 f10__ //Expr
		return Size221((*t).typ);
}
	#line 67 f10__ //Expr
	i64 OffsetOfMemeber224(Structure473& self,str53 field){
		#line 69 f10__ //Expr
		i64 offset={0};
		#line 70 f10__ //Expr
		for(i64 it = i64265(0); it<self.fields.length;it++){
			#line 71 f10__ //Expr
			Variable498* fieldVar=OpArray5125(self.fields,it);
			#line 73 f10__ //Expr
			if(equal68((*fieldVar).ident,field)){
				#line 75 f10__ //Expr
				return offset;
			};
			#line 77 f10__ //Expr
			offset = (offset+Size221((*fieldVar).super.typ));
		};
		#line 79 f10__ //Expr
		Assert260(0,add64(add64(add64(str53{15,(i8*)"No field named "},field),str53{14,(i8*)" on structure "}),self.ident));
		#line 80 f10__ //Expr
		return 0;
}
	#line 83 f10__ //Expr
	void AddVariable225(GenerateInterp238& self,Variable498* variable){
		#line 85 f10__ //Expr
		i64 size=Size221((*variable).super.typ);
		#line 86 f10__ //Expr
		FrameOffset227(self,size);
		#line 88 f10__ //Expr
		DebugLocal207* local=new25278();
		#line 89 f10__ //Expr
		Init208((*local),variable,self.frameOffset);
		#line 90 f10__ //Expr
		(*local).instr = (*self.interp).instructionsSize;
		#line 91 f10__ //Expr
		Push11280((*self.currentFrame).locals,local);
		#line 93 f10__ //Expr
		if((*variable).assign){
			#line 94 f10__ //Expr
			PushContext240(self,ContextLoad);
			#line 95 f10__ //Expr
			Visit244(self,(*(*variable).assign));
			#line 96 f10__ //Expr
			PopContext241(self);
			#line 97 f10__ //Expr
			i64 rightSize=Size221((*(*variable).assign).typ);
			#line 99 f10__ //Expr
			if((Is7156((*Resolved127((*(*variable).super.typ))))&&Is7156((*Resolved127((*(*(*variable).assign).typ)))))){
				#line 101 f10__ //Expr
				TypeNumber431* to=As7157((*Resolved127((*(*variable).super.typ))));
				#line 102 f10__ //Expr
				TypeNumber431* from=As7157((*Resolved127((*(*(*variable).assign).typ))));
				#line 104 f10__ //Expr
				if(((*from).size!=(*to).size)){
					#line 105 f10__ //Expr
					AddValue192((*self.interp),ConvertInstr);
					#line 106 f10__ //Expr
					AddValue192((*self.interp),i8295((*from).size));
					#line 107 f10__ //Expr
					AddValue192((*self.interp),i8295((*to).size));
					#line 108 f10__ //Expr
					rightSize = (*to).size;
				};
			};
			#line 111 f10__ //Expr
			Assert261((size==rightSize));
		}else{
			#line 115 f10__ //Expr
			AddValue192((*self.interp),LoadConst);
			#line 116 f10__ //Expr
			AddValue0256((*self.interp),i64271(size));
			#line 118 f10__ //Expr
			for(i64 it = i64265(0); it<size;it++){
				#line 119 f10__ //Expr
				AddSpace191((*self.interp),i8290(0));
			};
		};
		#line 122 f10__ //Expr
		Print236(self,add64(add64(add64(add64(add64(add64(str53{10,(i8*)"variable: "},(*variable).ident),str53{6,(i8*)" size:"}),String66(size)),str53{8,(i8*)"		frame:"}),String66(self.frameOffset)),str53{1,(i8*)"\n"}));
		#line 123 f10__ //Expr
		InterpAddress237 address={0};
		#line 124 f10__ //Expr
		address.global = (*variable).global;
		#line 125 f10__ //Expr
		address.address = self.frameOffset;
		#line 126 f10__ //Expr
		OpArray2282(self.offsets,(&(*variable).super)) = address;
}
	#line 129 f10__ //Expr
	void LoadConst0303(GenerateInterp238& self,i64 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr0257((*self.interp),value);
}
void LoadConst1305(GenerateInterp238& self,i32 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr2306((*self.interp),value);
}
void LoadConst2308(GenerateInterp238& self,i16 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr3309((*self.interp),value);
}
void LoadConst3311(GenerateInterp238& self,i8 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr1304((*self.interp),value);
}
void LoadConst4312(GenerateInterp238& self,u64 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr4313((*self.interp),value);
}
void LoadConst5315(GenerateInterp238& self,u32 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr5316((*self.interp),value);
}
void LoadConst6318(GenerateInterp238& self,u16 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr6319((*self.interp),value);
}
void LoadConst7321(GenerateInterp238& self,u8 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr7322((*self.interp),value);
}
void LoadConst8324(GenerateInterp238& self,f32 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr8325((*self.interp),value);
}
void LoadConst9327(GenerateInterp238& self,str53 value){
		#line 130 f10__ //Expr
		AddLoadConstInstr9328((*self.interp),value);
}
	#line 134 f10__ //Expr
	void FrameOffset227(GenerateInterp238& self,i64 offset){
		#line 135 f10__ //Expr
		self.frameOffset = (self.frameOffset+offset);
}
	#line 138 f10__ //Expr
	void ReserveResult228(GenerateInterp238& self,Type413* typ){
		#line 140 f10__ //Expr
		i64 size=Size221(typ);
		#line 141 f10__ //Expr
		AddValue192((*self.interp),LoadConst);
		#line 142 f10__ //Expr
		AddValue0256((*self.interp),i64271(size));
		#line 145 f10__ //Expr
		for(i64 it = i64265(0); it<size;it++){
			#line 146 f10__ //Expr
			AddValue192((*self.interp),i8290(0));
		};
		#line 148 f10__ //Expr
		Print236(self,add64(add64(add64(add64(str53{14,(i8*)"result:  size:"},String66(size)),str53{8,(i8*)"		frame:"}),String66(self.frameOffset)),str53{1,(i8*)"\n"}));
}
	#line 152 f10__ //Expr
	void LoadAddressInstr229(GenerateInterp238& self,i64 size){
		#line 153 f10__ //Expr
		AddValue192((*self.interp),LoadAddressInstr);
		#line 154 f10__ //Expr
		AddValue0256((*self.interp),(i64)size);
		#line 155 f10__ //Expr
		Print236(self,add64(add64(str53{19,(i8*)"load address size: "},String66(size)),str53{1,(i8*)"\n"}));
}
	#line 158 f10__ //Expr
	void Discard230(GenerateInterp238& self,i64 size){
		#line 159 f10__ //Expr
		AddValue192((*self.interp),DiscardInstr);
		#line 160 f10__ //Expr
		AddValue0256((*self.interp),(i64)size);
		#line 161 f10__ //Expr
		Print236(self,add64(add64(str53{14,(i8*)"discard size: "},String66(size)),str53{1,(i8*)"\n"}));
}
	#line 164 f10__ //Expr
	void LoadAddressFromOffset231(GenerateInterp238& self,i64 offset){
		#line 165 f10__ //Expr
		AddValue192((*self.interp),LoadAddressFromOffsetInstr);
		#line 166 f10__ //Expr
		AddValue0256((*self.interp),offset);
		#line 167 f10__ //Expr
		Print236(self,add64(add64(str53{26,(i8*)"load address from offset: "},String66(offset)),str53{1,(i8*)"\n"}));
}
	#line 170 f10__ //Expr
	void LoadOffsetInstr232(GenerateInterp238& self,i64 offset,i64 size){
		#line 172 f10__ //Expr
		AddValue192((*self.interp),LoadOffsetInstr);
		#line 173 f10__ //Expr
		AddValue0256((*self.interp),(i64)size);
		#line 174 f10__ //Expr
		AddValue0256((*self.interp),(i64)offset);
		#line 176 f10__ //Expr
		Print236(self,add64(add64(add64(add64(add64(add64(str53{6,(i8*)"load: "},String66(size)),str53{9,(i8*)" offset: "}),String66(offset)),str53{11,(i8*)"     frame:"}),String66(self.frameOffset)),str53{1,(i8*)"\n"}));
}
	#line 178 f10__ //Expr
	void LoadInstr233(GenerateInterp238& self,i64 address,i64 size){
		#line 180 f10__ //Expr
		AddValue192((*self.interp),LoadInstr);
		#line 181 f10__ //Expr
		AddValue0256((*self.interp),(i64)size);
		#line 182 f10__ //Expr
		AddValue0256((*self.interp),(i64)address);
		#line 183 f10__ //Expr
		Print236(self,add64(add64(add64(add64(add64(add64(str53{13,(i8*)"load global: "},String66(size)),str53{9,(i8*)" offset: "}),String66(address)),str53{11,(i8*)"     frame:"}),String66(self.frameOffset)),str53{1,(i8*)"\n"}));
}
	#line 186 f10__ //Expr
	void Store234(GenerateInterp238& self,i64 size,i64 offset){
		#line 187 f10__ //Expr
		AddValue192((*self.interp),StoreInstr);
		#line 188 f10__ //Expr
		AddValue0256((*self.interp),(i64)size);
		#line 189 f10__ //Expr
		AddValue0256((*self.interp),(i64)offset);
		#line 190 f10__ //Expr
		Print236(self,add64(add64(add64(add64(str53{7,(i8*)"store: "},String66(size)),str53{9,(i8*)" offset: "}),String66(offset)),str53{1,(i8*)"\n"}));
}
	#line 193 f10__ //Expr
	void AddOffsetToAddress235(GenerateInterp238& self,i64 offset){
		#line 194 f10__ //Expr
		AddValue192((*self.interp),AddOffsetToAddressInstr);
		#line 195 f10__ //Expr
		AddValue0256((*self.interp),(i64)offset);
		#line 196 f10__ //Expr
		Print236(self,add64(add64(str53{12,(i8*)"add offset: "},String66(offset)),str53{1,(i8*)"\n"}));
}
	#line 199 f10__ //Expr
	void Print236(GenerateInterp238 self,str53 string){
		#line 200 f10__ //Expr
		for(i64 it = i64265(0); it<self.indent;it++){
			#line 201 f10__ //Expr
			Print58(str53{3,(i8*)"   "});
		};
		#line 203 f10__ //Expr
		Print58(string);
}
			#line 225 f10__ //Expr
	;
	#line 226 f10__ //Expr
	;
	#line 227 f10__ //Expr
	;
	#line 230 f10__ //Expr
	i32 Context239(GenerateInterp238& self){
		#line 232 f10__ //Expr
		return Last2289(self.context);
}
	#line 234 f10__ //Expr
	void PushContext240(GenerateInterp238& self,i32 context){
		#line 236 f10__ //Expr
		Push12291(self.context,context);
}
	#line 238 f10__ //Expr
	void PopContext241(GenerateInterp238& self){
		#line 240 f10__ //Expr
		Pop2293(self.context);
}
	#line 243 f10__ //Expr
	void Init242(GenerateInterp238& generate,Semantic110& semantic,Block434& ast,Interp181& interp){
		#line 245 f10__ //Expr
		generate.interp = (&interp);
		#line 246 f10__ //Expr
		generate.semantic = (&semantic);
		#line 247 f10__ //Expr
		Init3294(generate.offsets);
		#line 248 f10__ //Expr
		Init8295(generate.context);
		#line 249 f10__ //Expr
		PushContext240(generate,ContextLoad);
		#line 251 f10__ //Expr
		generate.currentFrame = new26296();
		#line 254 f10__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 255 f10__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 256 f10__ //Expr
			if(Is7134((*expr))){
				#line 257 f10__ //Expr
				Visit244(generate,(*expr));
			};
		};
		#line 260 f10__ //Expr
		AddValue192((*generate.interp),ReturnInstr);
		#line 262 f10__ //Expr
		for(i64 it = i64265(0); it<ast.expressions.length;it++){
			#line 263 f10__ //Expr
			Expr366* expr=OpArray4122(ast.expressions,it);
			#line 264 f10__ //Expr
			if((!Is7134((*expr)))){
				#line 265 f10__ //Expr
				Visit244(generate,(*expr));
			};
		};
		#line 269 f10__ //Expr
		for(i64 it = i64265(0); it<gSpecializations.length;it++){
			#line 270 f10__ //Expr
			FunctionSpec460* spec=OpArray11230(gSpecializations,it);
			#line 271 f10__ //Expr
			if((!(*spec).incomplete)){
				#line 273 f10__ //Expr
				Apply468((*spec));
				#line 274 f10__ //Expr
				Visit122((*generate.semantic),(*(*spec).function).super);
				#line 275 f10__ //Expr
				Visit244(generate,(*(*spec).function).super);
				#line 276 f10__ //Expr
				Clear469((*spec));
			};
		};
		#line 281 f10__ //Expr
		Println59(add64(str53{24,(i8*)"Starting data segment : "},String66((i64)(*generate.interp).sPtr)));
		#line 282 f10__ //Expr
		Run220(interp);
		#line 283 f10__ //Expr
		Println59(add64(str53{22,(i8*)"Ending data segment : "},String66((i64)(*generate.interp).sPtr)));
}
	#line 285 f10__ //Expr
	Structure473* StructureFromType243(Type413& typ){
		#line 286 f10__ //Expr
		Type413* resolved=Resolved127(typ);
		#line 287 f10__ //Expr
		if(Is1143((*resolved))){
			#line 288 f10__ //Expr
			return As2124((*(*As1144((*resolved))).spec));
		}else{
			#line 290 f10__ //Expr
			if(Is6153((*resolved))){
				#line 292 f10__ //Expr
				TypeGeneric423* self=As6154((*resolved));
				#line 293 f10__ //Expr
				StructureSpec479* spec=As18259((*(*self).spec));
				#line 294 f10__ //Expr
				Apply487((*(*spec).structure),(*spec));
				#line 295 f10__ //Expr
				return (*spec).structure;
			};
		};
		#line 298 f10__ //Expr
		Assert260(0,str53{34,(i8*)"Cannot resolve type to a structure"});
		#line 299 f10__ //Expr
		return (Structure473*)0;
}
	#line 301 f10__ //Expr
	void Visit244(GenerateInterp238& generate,Expr366& expr){
		#line 304 f10__ //Expr
		if(Is1120(expr)){
			#line 305 f10__ //Expr
			Block434* self=As1121(expr);
			#line 306 f10__ //Expr
			PushContext240(generate,ContextDiscard);
			#line 307 f10__ //Expr
			i64 discardSize=0;
			#line 309 f10__ //Expr
			for(i64 it = i64265(0); it<(*self).expressions.length;it++){
				#line 310 f10__ //Expr
				Expr366* expr=OpArray4122((*self).expressions,it);
				#line 311 f10__ //Expr
				Visit244(generate,(*expr));
				#line 312 f10__ //Expr
				if(Is7134((*expr))){
					#line 313 f10__ //Expr
					discardSize = (discardSize+Size223(expr));
				};
			};
			#line 316 f10__ //Expr
			Discard230(generate,discardSize);
			#line 317 f10__ //Expr
			generate.frameOffset = (generate.frameOffset-discardSize);
			#line 318 f10__ //Expr
			PopContext241(generate);
			#line 319 f10__ //Expr
			return ;
		};
		#line 321 f10__ //Expr
		if(Is2123(expr)){
			#line 322 f10__ //Expr
			Structure473* self=As2124(expr);
			#line 323 f10__ //Expr
			return ;
		};
		#line 325 f10__ //Expr
		if(Is3126(expr)){
			#line 326 f10__ //Expr
			Function456* self=As3127(expr);
			#line 327 f10__ //Expr
			if(IsIntrinsic140((*generate.semantic).intrinsic,self)){
				#line 329 f10__ //Expr
				return ;
			};
			#line 332 f10__ //Expr
			if((((*self).any.length==0)||((i64)(*self).spec!=0))){
				#line 334 f10__ //Expr
				str53 ident=Name145((*self));
				#line 336 f10__ //Expr
				generate.currentFrame = new26296();
				#line 337 f10__ //Expr
				Init210((*generate.currentFrame),self);
				#line 339 f10__ //Expr
				if((*self).block){
					#line 342 f10__ //Expr
					i64 resultSize={0};
					#line 343 f10__ //Expr
					if((*self).result){
						#line 344 f10__ //Expr
						resultSize = Size221((*self).result);
					};
					#line 348 f10__ //Expr
					generate.frameOffset = (-(Size222((*self).params)+16));
					#line 349 f10__ //Expr
					generate.retOffset = generate.frameOffset;
					#line 351 f10__ //Expr
					for(i64 it = i64265(0); it<(*self).params.list.length;it++){
						#line 353 f10__ //Expr
						Print58(str53{9,(i8*)"Param -- "});
						#line 354 f10__ //Expr
						Visit244(generate,(*OpArray4122((*self).params.list,it)));
					};
					#line 357 f10__ //Expr
					Assert260((generate.frameOffset==(-16)),str53{57,(i8*)"Expected -16 frame offset, space for return and frame ptr"});
					#line 358 f10__ //Expr
					generate.frameOffset = 0;
					#line 359 f10__ //Expr
					AddLabel189((*generate.interp),ident);
					#line 361 f10__ //Expr
					(*generate.currentFrame).startInstr = (*generate.interp).instructionsSize;
					#line 362 f10__ //Expr
					OpArray3298((*generate.interp).frames,(*generate.interp).instructionsSize) = generate.currentFrame;
					#line 363 f10__ //Expr
					Push13301((*generate.interp).frameArray,generate.currentFrame);
					#line 365 f10__ //Expr
					Visit244(generate,(*(*self).block).super);
					#line 366 f10__ //Expr
					AddValue192((*generate.interp),ReturnInstr);
					#line 367 f10__ //Expr
					(*generate.currentFrame).endInstr = ((*generate.interp).instructionsSize-1);
					#line 368 f10__ //Expr
					Println59(str53{0,(i8*)""});
					#line 369 f10__ //Expr
					Println59(str53{0,(i8*)""});
				}else{
					#line 373 f10__ //Expr
					generate.retOffset = 0;
					#line 374 f10__ //Expr
					generate.frameOffset = 0;
					#line 375 f10__ //Expr
					AddExternCallLabel206((*generate.interp),ident);
				};
			};
			#line 378 f10__ //Expr
			return ;
		};
		#line 380 f10__ //Expr
		if(Is5130(expr)){
			#line 382 f10__ //Expr
			Call442* self=As5131(expr);
			#line 383 f10__ //Expr
			if(Is3126((*(*self).func))){
				#line 385 f10__ //Expr
				Function456* function=As3127((*(*self).func));
				#line 386 f10__ //Expr
				if(IsIntrinsic140((*generate.semantic).intrinsic,function)){
					#line 388 f10__ //Expr
					GenerateBasicIntrinsic249(generate,function,self);
				}else{
					#line 392 f10__ //Expr
					str53 ident=Name145((*function));
					#line 393 f10__ //Expr
					if((*function).block){
						#line 394 f10__ //Expr
						PushContext240(generate,ContextLoad);
						#line 395 f10__ //Expr
						if((*function).result){
							#line 396 f10__ //Expr
							ReserveResult228(generate,(*function).result);
						};
						#line 398 f10__ //Expr
						for(i64 it = i64265(0); it<(*self).params.list.length;it++){
							#line 400 f10__ //Expr
							PerformVisitAutoReference245(generate,(*OpArray4122((*self).params.list,it)),i64269(OpArray0112((*self).drefCount,it)));
							#line 401 f10__ //Expr
							PerformCoercion248(generate,(*OpArray4122((*function).params.list,it)),(*OpArray4122((*self).params.list,it)));
						};
						#line 403 f10__ //Expr
						AddCall198((*generate.interp),ident);
						#line 404 f10__ //Expr
						Discard230(generate,Size222((*function).params));
						#line 405 f10__ //Expr
						PopContext241(generate);
					}else{
						#line 409 f10__ //Expr
						PushContext240(generate,ContextLoad);
						#line 410 f10__ //Expr
						for(i64 it = i64265(0); it<(*self).params.list.length;it++){
							#line 412 f10__ //Expr
							i64 i=(((*self).params.list.length-it)-1);
							#line 413 f10__ //Expr
							PerformVisitAutoReference245(generate,(*OpArray4122((*self).params.list,i)),i64269(OpArray0112((*self).drefCount,i)));
							#line 414 f10__ //Expr
							PerformCoercion248(generate,(*OpArray4122((*function).params.list,i)),(*OpArray4122((*self).params.list,i)));
						};
						#line 416 f10__ //Expr
						PopContext241(generate);
						#line 418 f10__ //Expr
						for(i64 it = i64265(0); it<(*function).params.list.length;it++){
							#line 420 f10__ //Expr
							Type413* t=Resolved127((*(*OpArray4122((*function).params.list,it)).typ));
							#line 422 f10__ //Expr
							if(Is0141((*t))){
								#line 423 f10__ //Expr
								AddValue192((*generate.interp),ParamExtern_Ptr);
							}else{
								#line 425 f10__ //Expr
								if((equal0199(t,(&(*i8Type).super))||equal0199(t,(&(*u8Type).super)))){
									#line 426 f10__ //Expr
									AddValue192((*generate.interp),ParamExtern_8);
								}else{
									#line 428 f10__ //Expr
									if((equal0199(t,(&(*i16Type).super))||equal0199(t,(&(*u16Type).super)))){
										#line 429 f10__ //Expr
										AddValue192((*generate.interp),ParamExtern_16);
									}else{
										#line 431 f10__ //Expr
										if((equal0199(t,(&(*i32Type).super))||equal0199(t,(&(*u32Type).super)))){
											#line 432 f10__ //Expr
											AddValue192((*generate.interp),ParamExtern_32);
										}else{
											#line 434 f10__ //Expr
											if((equal0199(t,(&(*i64Type).super))||equal0199(t,(&(*u64Type).super)))){
												#line 435 f10__ //Expr
												AddValue192((*generate.interp),ParamExtern_64);
											}else{
												#line 437 f10__ //Expr
												if(equal0199(t,(&(*f32Type).super))){
													#line 438 f10__ //Expr
													AddValue192((*generate.interp),ParamExtern_f32);
												}else{
													#line 440 f10__ //Expr
													if(equal0199(t,(&(*f64Type).super))){
														#line 441 f10__ //Expr
														AddValue192((*generate.interp),ParamExtern_f64);
													}else{
														#line 445 f10__ //Expr
														Assert260(0,str53{86,(i8*)"Parameter is of invalid type in @extern call, we only support basic types and pointers"});
													};
												};
											};
										};
									};
								};
							};
						};
						#line 449 f10__ //Expr
						if((*function).result){
							#line 451 f10__ //Expr
							Type413* t=Resolved127((*(*function).result));
							#line 453 f10__ //Expr
							if(Is0141((*t))){
								#line 454 f10__ //Expr
								AddCallExternPtr205((*generate.interp),ident);
							}else{
								#line 456 f10__ //Expr
								if((equal0199(t,(&(*i8Type).super))||equal0199(t,(&(*u8Type).super)))){
									#line 458 f10__ //Expr
									AddCallExtern8200((*generate.interp),ident);
								}else{
									#line 460 f10__ //Expr
									if((equal0199(t,(&(*i16Type).super))||equal0199(t,(&(*u16Type).super)))){
										#line 462 f10__ //Expr
										AddCallExtern16201((*generate.interp),ident);
									}else{
										#line 464 f10__ //Expr
										if((equal0199(t,(&(*i32Type).super))||equal0199(t,(&(*u32Type).super)))){
											#line 466 f10__ //Expr
											AddCallExtern32202((*generate.interp),ident);
										}else{
											#line 468 f10__ //Expr
											if((equal0199(t,(&(*i64Type).super))||equal0199(t,(&(*u64Type).super)))){
												#line 470 f10__ //Expr
												AddCallExtern64204((*generate.interp),ident);
											}else{
												#line 472 f10__ //Expr
												if(equal0199(t,(&(*f32Type).super))){
													#line 474 f10__ //Expr
													AddCallExternf32203((*generate.interp),ident);
												}else{
													#line 477 f10__ //Expr
													Assert260(0,str53{83,(i8*)"Return is of invalid type in @extern call, we only support basic types and pointers"});
												};
											};
										};
									};
								};
							};
						}else{
							#line 482 f10__ //Expr
							AddCallExternVoid199((*generate.interp),ident);
						};
					};
				};
				#line 486 f10__ //Expr
				if((*function).result){
					#line 487 f10__ //Expr
					if((Context239(generate)==ContextDiscard)){
						#line 488 f10__ //Expr
						Discard230(generate,Size221((*function).result));
					};
				};
			}else{
				#line 492 f10__ //Expr
				if(Is19233((*(*self).func))){
					#line 494 f10__ //Expr
					FunctionSpec460* spec=As17234((*(*self).func));
					#line 495 f10__ //Expr
					Function456* function=(*spec).function;
					#line 496 f10__ //Expr
					FunctionSpec460* prev=(*function).spec;
					#line 497 f10__ //Expr
					Apply468((*spec));
					#line 498 f10__ //Expr
					if(IsIntrinsic140((*generate.semantic).intrinsic,function)){
						#line 500 f10__ //Expr
						GenerateBasicIntrinsic249(generate,function,self);
					}else{
						#line 504 f10__ //Expr
						PushContext240(generate,ContextLoad);
						#line 505 f10__ //Expr
						str53 ident=Name145((*function));
						#line 507 f10__ //Expr
						if((*function).block){
							#line 508 f10__ //Expr
							if((*function).result){
								#line 509 f10__ //Expr
								ReserveResult228(generate,(*function).result);
							};
							#line 511 f10__ //Expr
							for(i64 it = i64265(0); it<(*self).params.list.length;it++){
								#line 513 f10__ //Expr
								PerformVisitAutoReference245(generate,(*OpArray4122((*self).params.list,it)),i64269(OpArray0112((*self).drefCount,it)));
								#line 514 f10__ //Expr
								PerformCoercion248(generate,(*OpArray4122((*function).params.list,it)),(*OpArray4122((*self).params.list,it)));
							};
							#line 517 f10__ //Expr
							AddCall198((*generate.interp),ident);
							#line 518 f10__ //Expr
							Discard230(generate,Size222((*function).params));
						};
						#line 520 f10__ //Expr
						PopContext241(generate);
					};
					#line 522 f10__ //Expr
					if((*function).result){
						#line 523 f10__ //Expr
						if((Context239(generate)==ContextDiscard)){
							#line 524 f10__ //Expr
							Discard230(generate,Size221((*function).result));
						};
					};
					#line 527 f10__ //Expr
					if(prev){
						#line 528 f10__ //Expr
						Apply468((*prev));
					}else{
						#line 531 f10__ //Expr
						Clear469((*spec));
					};
				}else{
					#line 535 f10__ //Expr
					Assert260(0,add64(str53{23,(i8*)"Expected fn or fn spec "},String66((*(*self).operand).kind)));
				};
			};
			#line 537 f10__ //Expr
			return ;
		};
		#line 539 f10__ //Expr
		if(Is7134(expr)){
			#line 540 f10__ //Expr
			Variable498* self=As7135(expr);
			#line 541 f10__ //Expr
			AddVariable225(generate,self);
			#line 542 f10__ //Expr
			return ;
		};
		#line 544 f10__ //Expr
		if(Is4128(expr)){
			#line 545 f10__ //Expr
			Identifier495* self=As4129(expr);
			#line 546 f10__ //Expr
			if((!(*self).reference)){
				#line 547 f10__ //Expr
				Println59(add64(add64(str53{19,(i8*)"not loading ident: "},(*self).ident),str53{21,(i8*)" no referenced object"}));
				#line 548 f10__ //Expr
				Assert260((Context239(generate)==ContextLoad),str53{108,(i8*)"Internal: Expected value context why would you take the address of something that doesnt refer to an address"});
				#line 549 f10__ //Expr
				return ;
			};
			#line 551 f10__ //Expr
			if((Context239(generate)==ContextStore)){
				#line 553 f10__ //Expr
				i64 a=OpArray2282(generate.offsets,(*self).reference).address;
				#line 554 f10__ //Expr
				if((*As7135((*(*self).reference))).global){
					#line 556 f10__ //Expr
					LoadConst0303(generate,i64271(((i64)(*generate.interp).stackTop-a)));
				}else{
					#line 559 f10__ //Expr
					LoadAddressFromOffset231(generate,a);
				};
			}else{
				#line 562 f10__ //Expr
				if((Context239(generate)==ContextLoad)){
					#line 564 f10__ //Expr
					i64 a=OpArray2282(generate.offsets,(*self).reference).address;
					#line 565 f10__ //Expr
					if(OpArray2282(generate.offsets,(*self).reference).global){
						#line 566 f10__ //Expr
						LoadInstr233(generate,((i64)(*generate.interp).stackTop-a),Size223((*self).reference));
					}else{
						#line 569 f10__ //Expr
						LoadOffsetInstr232(generate,a,Size223((*self).reference));
					};
				}else{
					#line 574 f10__ //Expr
					Println59(add64(str53{16,(i8*)"unused variable "},(*self).ident));
				};
			};
			#line 576 f10__ //Expr
			return ;
		};
		#line 578 f10__ //Expr
		if(Is13185(expr)){
			#line 579 f10__ //Expr
			ForList512* self=As12186(expr);
			#line 596 f10__ //Expr
			return ;
		};
		#line 598 f10__ //Expr
		if(Is14190(expr)){
			#line 599 f10__ //Expr
			For449* self=As13191(expr);
			#line 600 f10__ //Expr
			PushContext240(generate,ContextLoad);
			#line 602 f10__ //Expr
			if((*self).to){
				#line 603 f10__ //Expr
				Visit244(generate,(*(*self).it).super);
				#line 604 f10__ //Expr
				Visit244(generate,(*(*(*self).it).assign));
				#line 605 f10__ //Expr
				StoreOffsetInstr197((*generate.interp),OpArray2282(generate.offsets,(&(*(*self).it).super)).address,Size221((*(*(*self).it).assign).typ));
			};
			#line 608 f10__ //Expr
			i64 start=(*generate.interp).instructionsSize;
			#line 609 f10__ //Expr
			Println59(str53{6,(i8*)"start:"});
			#line 611 f10__ //Expr
			if((*self).to){
				#line 612 f10__ //Expr
				Visit244(generate,(*(*self).test).super);
			}else{
				#line 615 f10__ //Expr
				Assert261((Size223((*self).from)==1));
				#line 616 f10__ //Expr
				Visit244(generate,(*(*self).from));
			};
			#line 621 f10__ //Expr
			PrintTabs364(1);
			#line 622 f10__ //Expr
			Println59(str53{10,(i8*)"Jump: end "});
			#line 623 f10__ //Expr
			AddValue192((*generate.interp),JumpInstr);
			#line 624 f10__ //Expr
			i64* at=AddValue0256((*generate.interp),i64265(0));
			#line 625 f10__ //Expr
			PopContext241(generate);
			#line 627 f10__ //Expr
			Visit244(generate,(*(*self).block).super);
			#line 629 f10__ //Expr
			PushContext240(generate,ContextLoad);
			#line 630 f10__ //Expr
			if((*self).to){
				#line 631 f10__ //Expr
				Visit244(generate,(*(*self).inc));
			};
			#line 633 f10__ //Expr
			AddLoadConstInstr1304((*generate.interp),i8290(0));
			#line 634 f10__ //Expr
			AddValue192((*generate.interp),JumpInstr);
			#line 635 f10__ //Expr
			AddValue0256((*generate.interp),i64271(start));
			#line 636 f10__ //Expr
			PrintTabs364(1);
			#line 637 f10__ //Expr
			Println59(str53{11,(i8*)"Jump: start"});
			#line 638 f10__ //Expr
			Println59(str53{4,(i8*)"end:"});
			#line 639 f10__ //Expr
			(*at) = (*generate.interp).instructionsSize;
			#line 640 f10__ //Expr
			PopContext241(generate);
			#line 641 f10__ //Expr
			return ;
		};
		#line 644 f10__ //Expr
		if(Is16194(expr)){
			#line 645 f10__ //Expr
			If447* self=As15195(expr);
			#line 646 f10__ //Expr
			PushContext240(generate,ContextLoad);
			#line 647 f10__ //Expr
			Visit244(generate,(*(*self).condition));
			#line 648 f10__ //Expr
			PopContext241(generate);
			#line 650 f10__ //Expr
			PrintTabs364(1);
			#line 651 f10__ //Expr
			Println59(str53{10,(i8*)"Jump: end "});
			#line 652 f10__ //Expr
			AddValue192((*generate.interp),JumpInstr);
			#line 653 f10__ //Expr
			i64* at=AddValue0256((*generate.interp),i64265(0));
			#line 654 f10__ //Expr
			Visit244(generate,(*(*self).trueBranch).super);
			#line 655 f10__ //Expr
			(*at) = (*generate.interp).instructionsSize;
			#line 656 f10__ //Expr
			Println59(str53{4,(i8*)"end:"});
			#line 657 f10__ //Expr
			return ;
		};
		#line 660 f10__ //Expr
		if(Is6132(expr)){
			#line 661 f10__ //Expr
			Access445* self=As6133(expr);
			#line 663 f10__ //Expr
			if((*self).call){
				#line 664 f10__ //Expr
				Visit244(generate,(*(*self).call).super);
				#line 665 f10__ //Expr
				return ;
			};
			#line 668 f10__ //Expr
			Println59(str53{15,(i8*)"context address"});
			#line 669 f10__ //Expr
			PushContext240(generate,ContextStore);
			#line 670 f10__ //Expr
			Visit244(generate,(*(*self).operand));
			#line 671 f10__ //Expr
			PopContext241(generate);
			#line 673 f10__ //Expr
			Structure473* structure=StructureFromType243((*(*(*self).operand).typ));
			#line 674 f10__ //Expr
			if((Context239(generate)==ContextStore)){
				#line 675 f10__ //Expr
				AddOffsetToAddress235(generate,OffsetOfMemeber224((*structure),(*self).field));
			}else{
				#line 679 f10__ //Expr
				Println59(str53{13,(i8*)"context value"});
				#line 680 f10__ //Expr
				AddOffsetToAddress235(generate,OffsetOfMemeber224((*structure),(*self).field));
				#line 681 f10__ //Expr
				LoadAddressInstr229(generate,Size221((*self).super.typ));
			};
			#line 684 f10__ //Expr
			return ;
		};
		#line 687 f10__ //Expr
		if(Is15192(expr)){
			#line 688 f10__ //Expr
			Assign501* self=As14193(expr);
			#line 689 f10__ //Expr
			if(((*self).drefCount>0)){
				#line 691 f10__ //Expr
				PushContext240(generate,ContextStore);
				#line 692 f10__ //Expr
				Visit244(generate,(*(*self).right));
				#line 693 f10__ //Expr
				PopContext241(generate);
				#line 695 f10__ //Expr
				PushContext240(generate,ContextStore);
				#line 696 f10__ //Expr
				Visit244(generate,(*(*self).left));
				#line 697 f10__ //Expr
				PopContext241(generate);
				#line 699 f10__ //Expr
				i64 leftSize=Size221((*(*self).left).typ);
				#line 700 f10__ //Expr
				Store234(generate,leftSize,0);
				#line 701 f10__ //Expr
				return ;
			}else{
				#line 703 f10__ //Expr
				if(((*self).drefCount<0)){
					#line 706 f10__ //Expr
					PushContext240(generate,ContextLoad);
					#line 707 f10__ //Expr
					Visit244(generate,(*(*self).right));
					#line 708 f10__ //Expr
					PopContext241(generate);
					#line 710 f10__ //Expr
					PushContext240(generate,ContextStore);
					#line 711 f10__ //Expr
					Visit244(generate,(*(*self).left));
					#line 712 f10__ //Expr
					PopContext241(generate);
					#line 715 f10__ //Expr
					i64 rightSize=Size221((*(*self).right).typ);
					#line 716 f10__ //Expr
					Store234(generate,rightSize,0);
					#line 717 f10__ //Expr
					return ;
				};
			};
			#line 721 f10__ //Expr
			i64 leftSize=Size221((*(*self).left).typ);
			#line 722 f10__ //Expr
			i64 rightSize=Size221((*(*self).right).typ);
			#line 724 f10__ //Expr
			PushContext240(generate,ContextLoad);
			#line 725 f10__ //Expr
			Visit244(generate,(*(*self).right));
			#line 727 f10__ //Expr
			rightSize = PerformCoercion248(generate,(*(*self).left),(*(*self).right));
			#line 728 f10__ //Expr
			PopContext241(generate);
			#line 730 f10__ //Expr
			PushContext240(generate,ContextStore);
			#line 731 f10__ //Expr
			Visit244(generate,(*(*self).left));
			#line 732 f10__ //Expr
			PopContext241(generate);
			#line 734 f10__ //Expr
			Assert260((leftSize==rightSize),str53{71,(i8*)"Internal compiler interp error: Expected same size arguments for assign"});
			#line 736 f10__ //Expr
			Store234(generate,rightSize,0);
			#line 738 f10__ //Expr
			return ;
		};
		#line 740 f10__ //Expr
		if(Is18197(expr)){
			#line 741 f10__ //Expr
			PushContext240(generate,ContextLoad);
			#line 742 f10__ //Expr
			Return454* self=As16198(expr);
			#line 743 f10__ //Expr
			Visit244(generate,(*(*self).expr));
			#line 744 f10__ //Expr
			StoreOffsetInstr197((*generate.interp),generate.retOffset,Size221((*(*self).expr).typ));
			#line 745 f10__ //Expr
			PopContext241(generate);
			#line 746 f10__ //Expr
			AddValue192((*generate.interp),ReturnInstr);
			#line 747 f10__ //Expr
			return ;
		};
		#line 749 f10__ //Expr
		if(Is8136(expr)){
			#line 750 f10__ //Expr
			Trait490* self=As8137(expr);
			#line 751 f10__ //Expr
			return ;
		};
		#line 753 f10__ //Expr
		if(Is11181(expr)){
			#line 754 f10__ //Expr
			NumberConstant507* self=As10182(expr);
			#line 759 f10__ //Expr
			if((Context239(generate)==ContextLoad)){
				#line 761 f10__ //Expr
				if(equal0199((*self).super.typ,(&(*i64Type).super))){
					#line 762 f10__ //Expr
					LoadConst0303(generate,i64FromString56((*self).value));
				}else{
					#line 764 f10__ //Expr
					if(equal0199((*self).super.typ,(&(*i32Type).super))){
						#line 765 f10__ //Expr
						LoadConst1305(generate,i32279(i64FromString56((*self).value)));
					}else{
						#line 767 f10__ //Expr
						if(equal0199((*self).super.typ,(&(*i16Type).super))){
							#line 768 f10__ //Expr
							LoadConst2308(generate,i16287(i64FromString56((*self).value)));
						}else{
							#line 770 f10__ //Expr
							if(equal0199((*self).super.typ,(&(*i8Type).super))){
								#line 771 f10__ //Expr
								LoadConst3311(generate,i8295(i64FromString56((*self).value)));
							}else{
								#line 773 f10__ //Expr
								if(equal0199((*self).super.typ,(&(*u64Type).super))){
									#line 774 f10__ //Expr
									LoadConst4312(generate,u64327(i64FromString56((*self).value)));
								}else{
									#line 776 f10__ //Expr
									if(equal0199((*self).super.typ,(&(*u32Type).super))){
										#line 777 f10__ //Expr
										LoadConst5315(generate,u32319(i64FromString56((*self).value)));
									}else{
										#line 779 f10__ //Expr
										if(equal0199((*self).super.typ,(&(*u16Type).super))){
											#line 780 f10__ //Expr
											LoadConst6318(generate,u16311(i64FromString56((*self).value)));
										}else{
											#line 782 f10__ //Expr
											if(equal0199((*self).super.typ,(&(*u8Type).super))){
												#line 783 f10__ //Expr
												LoadConst7321(generate,u8303(i64FromString56((*self).value)));
											}else{
												#line 785 f10__ //Expr
												if(equal0199((*self).super.typ,(&(*f32Type).super))){
													#line 786 f10__ //Expr
													LoadConst8324(generate,f32337(f64FromString57((*self).value)));
												}else{
													#line 789 f10__ //Expr
													Assert260(0,str53{32,(i8*)"No match for NumberConstant type"});
												};
											};
										};
									};
								};
							};
						};
					};
				};
			}else{
				#line 793 f10__ //Expr
				Assert261(0);
			};
			#line 796 f10__ //Expr
			return ;
		};
		#line 798 f10__ //Expr
		if(Is12183(expr)){
			#line 799 f10__ //Expr
			StringConstant509* self=As11184(expr);
			#line 801 f10__ //Expr
			if((Context239(generate)==ContextStore)){
				#line 803 f10__ //Expr
				LoadConst0303(generate,(i64)(&(*self).value));
			}else{
				#line 805 f10__ //Expr
				if((Context239(generate)==ContextLoad)){
					#line 807 f10__ //Expr
					LoadConst9327(generate,(*self).value);
				}else{
					#line 811 f10__ //Expr
					Println59(str53{13,(i8*)"unused string"});
				};
			};
			#line 814 f10__ //Expr
			return ;
		};
}
	#line 818 f10__ //Expr
	void PerformVisitAutoReference245(GenerateInterp238& self,Expr366& expr,i64 count){
		#line 819 f10__ //Expr
		if((count<0)){
			#line 820 f10__ //Expr
			PerformReference246(self,expr,(-count));
			#line 821 f10__ //Expr
			return ;
		}else{
			#line 823 f10__ //Expr
			if((count>0)){
				#line 824 f10__ //Expr
				PerformDereference247(self,expr,count);
				#line 825 f10__ //Expr
				return ;
			};
		};
		#line 827 f10__ //Expr
		Assert260((count==0),str53{29,(i8*)"Internal: expected count == 0"});
		#line 828 f10__ //Expr
		Visit244(self,expr);
}
	#line 830 f10__ //Expr
	void PerformReference246(GenerateInterp238& self,Expr366& expr,i64 count){
		#line 831 f10__ //Expr
		Assert260((count==1),str53{44,(i8*)"Internal: expected dref count greater than 0"});
		#line 832 f10__ //Expr
		Assert261((Context239(self)==ContextLoad));
		#line 834 f10__ //Expr
		Println59(str53{3,(i8*)"ref"});
		#line 835 f10__ //Expr
		PushContext240(self,ContextStore);
		#line 836 f10__ //Expr
		Visit244(self,expr);
		#line 837 f10__ //Expr
		PopContext241(self);
}
	#line 840 f10__ //Expr
	void PerformDereference247(GenerateInterp238& self,Expr366& expr,i64 count){
		#line 842 f10__ //Expr
		Assert260((count>0),str53{44,(i8*)"Internal: expected dref count greater than 0"});
		#line 844 f10__ //Expr
		Println59(str53{4,(i8*)"dref"});
		#line 845 f10__ //Expr
		PushContext240(self,ContextLoad);
		#line 846 f10__ //Expr
		Visit244(self,expr);
		#line 847 f10__ //Expr
		PopContext241(self);
		#line 850 f10__ //Expr
		Type413* currentType=expr.typ;
		#line 852 f10__ //Expr
		for(i64 it = i64265(0); it<count;it++){
			#line 853 f10__ //Expr
			Assert260(Is0141((*currentType)),str53{32,(i8*)"Expected reference to derference"});
			#line 855 f10__ //Expr
			currentType = (*As0142((*currentType))).reference;
			#line 856 f10__ //Expr
			LoadAddressInstr229(self,Size221(currentType));
		};
		#line 861 f10__ //Expr
		Assert261((Context239(self)==ContextLoad));
}
	#line 864 f10__ //Expr
	i32 PerformCoercion248(GenerateInterp238& generate,Expr366& toExpr,Expr366& fromExpr){
		#line 866 f10__ //Expr
		if((Is7156((*Resolved127((*toExpr.typ))))&&Is7156((*Resolved127((*fromExpr.typ)))))){
			#line 868 f10__ //Expr
			TypeNumber431* to=As7157((*Resolved127((*toExpr.typ))));
			#line 869 f10__ //Expr
			TypeNumber431* from=As7157((*Resolved127((*fromExpr.typ))));
			#line 871 f10__ //Expr
			if(((*from).size!=(*to).size)){
				#line 873 f10__ //Expr
				AddValue192((*generate.interp),ConvertInstr);
				#line 874 f10__ //Expr
				AddValue192((*generate.interp),i8295((*from).size));
				#line 875 f10__ //Expr
				AddValue192((*generate.interp),i8295((*to).size));
			};
			#line 877 f10__ //Expr
			return (*to).size;
		};
		#line 879 f10__ //Expr
		return Size223((&toExpr));
}
	#line 882 f10__ //Expr
	void GenerateBasicIntrinsic249(GenerateInterp238& generate,Function456* function,Call442* call){
		#line 884 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.abortFn))){
			#line 885 f10__ //Expr
			AddValue192((*generate.interp),TrapInstr);
			#line 886 f10__ //Expr
			AddValue192((*generate.interp),TrapAbort);
			#line 887 f10__ //Expr
			return ;
		};
		#line 889 f10__ //Expr
		if(equal68((*function).ident,str53{1,(i8*)"&"})){
			#line 890 f10__ //Expr
			PushContext240(generate,ContextStore);
			#line 891 f10__ //Expr
			for(i64 it = i64265(0); it<(*call).params.list.length;it++){
				#line 892 f10__ //Expr
				PerformVisitAutoReference245(generate,(*OpArray4122((*call).params.list,it)),i64269(OpArray0112((*call).drefCount,it)));
			};
			#line 894 f10__ //Expr
			PopContext241(generate);
			#line 895 f10__ //Expr
			return ;
		}else{
			#line 899 f10__ //Expr
			if(equal68((*function).ident,str53{4,(i8*)"dref"})){
				#line 900 f10__ //Expr
				PushContext240(generate,ContextLoad);
				#line 902 f10__ //Expr
				for(i64 it = i64265(0); it<(*call).params.list.length;it++){
					#line 903 f10__ //Expr
					PerformVisitAutoReference245(generate,(*OpArray4122((*call).params.list,it)),i64269(OpArray0112((*call).drefCount,it)));
				};
				#line 906 f10__ //Expr
				PopContext241(generate);
			}else{
				#line 910 f10__ //Expr
				PushContext240(generate,ContextLoad);
				#line 911 f10__ //Expr
				for(i64 it = i64265(0); it<(*call).params.list.length;it++){
					#line 912 f10__ //Expr
					PerformVisitAutoReference245(generate,(*OpArray4122((*call).params.list,it)),i64269(OpArray0112((*call).drefCount,it)));
					#line 914 f10__ //Expr
					if((Is7156((*Resolved127((*(*OpArray4122((*call).params.list,it)).typ))))&&Is7156((*Resolved127((*(*OpArray4122((*function).params.list,it)).typ)))))){
						#line 916 f10__ //Expr
						TypeNumber431* from=As7157((*Resolved127((*(*OpArray4122((*call).params.list,it)).typ))));
						#line 917 f10__ //Expr
						TypeNumber431* to=As7157((*Resolved127((*(*OpArray4122((*function).params.list,it)).typ))));
						#line 919 f10__ //Expr
						if(((*from).size!=(*to).size)){
							#line 920 f10__ //Expr
							AddValue192((*generate.interp),ConvertInstr);
							#line 921 f10__ //Expr
							AddValue192((*generate.interp),i8295((*from).size));
							#line 922 f10__ //Expr
							AddValue192((*generate.interp),i8295((*to).size));
						};
					};
				};
				#line 926 f10__ //Expr
				PopContext241(generate);
			};
		};
		#line 929 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.ptr_add))){
			#line 930 f10__ //Expr
			AddValue192((*generate.interp),AddPtrInstr);
			#line 931 f10__ //Expr
			i64 size=Size221((*As0142((*(*OpArray4122((*call).params.list,0)).typ))).reference);
			#line 932 f10__ //Expr
			AddValue0256((*generate.interp),size);
			#line 933 f10__ //Expr
			Println59(add64(str53{6,(i8*)"Ptr + "},String66(size)));
			#line 934 f10__ //Expr
			return ;
		};
		#line 937 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.sizeFn))){
			#line 938 f10__ //Expr
			i64 size=Size221((*As5152((*(*OpArray4122((*call).params.list,0)).typ))).reference);
			#line 939 f10__ //Expr
			LoadConst0303(generate,(i64)size);
			#line 940 f10__ //Expr
			Print58(add64(str53{9,(i8*)"Size() : "},String66(size)));
			#line 941 f10__ //Expr
			Print58(str53{4,(i8*)"    "});
			#line 942 f10__ //Expr
			Print97((*(*OpArray4122((*call).params.list,0)).typ));
			#line 943 f10__ //Expr
			Println59(str53{0,(i8*)""});
			#line 944 f10__ //Expr
			return ;
		};
		#line 947 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.castOp))){
			#line 948 f10__ //Expr
			Println59(str53{6,(i8*)"Cast +"});
			#line 949 f10__ //Expr
			Assert260((Size221((*As5152((*Resolved127((*(*OpArray4122((*call).params.list,0)).typ))))).reference)==Size221((*OpArray4122((*call).params.list,1)).typ)),str53{41,(i8*)"Cant cast to between differnt sized types"});
			#line 950 f10__ //Expr
			return ;
		};
		#line 952 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_u8))){
			#line 954 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 955 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 956 f10__ //Expr
			AddValue192((*generate.interp),i8290(1));
			#line 957 f10__ //Expr
			return ;
		};
		#line 959 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_u16))){
			#line 961 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 962 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 963 f10__ //Expr
			AddValue192((*generate.interp),i8290(2));
			#line 964 f10__ //Expr
			return ;
		};
		#line 966 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_u32))){
			#line 968 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 969 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 970 f10__ //Expr
			AddValue192((*generate.interp),i8290(4));
			#line 971 f10__ //Expr
			return ;
		};
		#line 973 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_u64))){
			#line 975 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 976 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 977 f10__ //Expr
			AddValue192((*generate.interp),i8290(8));
			#line 978 f10__ //Expr
			return ;
		};
		#line 980 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_i8))){
			#line 982 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 983 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 984 f10__ //Expr
			AddValue192((*generate.interp),i8290(1));
			#line 985 f10__ //Expr
			return ;
		};
		#line 987 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_i16))){
			#line 989 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 990 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 991 f10__ //Expr
			AddValue192((*generate.interp),i8290(2));
			#line 992 f10__ //Expr
			return ;
		};
		#line 994 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_i32))){
			#line 996 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 997 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 998 f10__ //Expr
			AddValue192((*generate.interp),i8290(4));
			#line 999 f10__ //Expr
			return ;
		};
		#line 1001 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_i64))){
			#line 1002 f10__ //Expr
			if(equal0199(Resolved127((*(*OpArray4122((*call).params.list,0)).typ)),(&(*f32Type).super))){
				#line 1003 f10__ //Expr
				AddValue192((*generate.interp),CastInstr_f32_i64);
				#line 1004 f10__ //Expr
				return ;
			};
			#line 1007 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 1008 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 1009 f10__ //Expr
			AddValue192((*generate.interp),i8290(8));
			#line 1010 f10__ //Expr
			return ;
		};
		#line 1012 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.to_f32))){
			#line 1014 f10__ //Expr
			AddValue192((*generate.interp),ConvertInstr);
			#line 1015 f10__ //Expr
			AddValue192((*generate.interp),i8295(Size223(OpArray4122((*call).params.list,0))));
			#line 1016 f10__ //Expr
			AddValue192((*generate.interp),i8290(8));
			#line 1017 f10__ //Expr
			AddValue192((*generate.interp),CastInstr_i64_f32);
			#line 1018 f10__ //Expr
			return ;
		};
		#line 1021 f10__ //Expr
		if(equal3219(function,(&(*generate.semantic).intrinsic.add_i64))){
			#line 1022 f10__ //Expr
			AddValue192((*generate.interp),AddInstr_i64);
			#line 1023 f10__ //Expr
			Println59(str53{7,(i8*)"add i64"});
		}else{
			#line 1025 f10__ //Expr
			if(equal3219(function,(&(*generate.semantic).intrinsic.sub_i64))){
				#line 1026 f10__ //Expr
				AddValue192((*generate.interp),SubInstr_i64);
				#line 1027 f10__ //Expr
				Println59(str53{7,(i8*)"sub i64"});
			}else{
				#line 1029 f10__ //Expr
				if(equal3219(function,(&(*generate.semantic).intrinsic.div_i64))){
					#line 1030 f10__ //Expr
					AddValue192((*generate.interp),DivInstr_i64);
					#line 1031 f10__ //Expr
					Println59(str53{7,(i8*)"div i64"});
				}else{
					#line 1033 f10__ //Expr
					if(equal3219(function,(&(*generate.semantic).intrinsic.mul_i64))){
						#line 1034 f10__ //Expr
						AddValue192((*generate.interp),MulInstr_i64);
						#line 1035 f10__ //Expr
						Println59(str53{7,(i8*)"mul i64"});
					}else{
						#line 1037 f10__ //Expr
						if(equal3219(function,(&(*generate.semantic).intrinsic.mod_i64))){
							#line 1038 f10__ //Expr
							AddValue192((*generate.interp),ModInstr_i64);
							#line 1039 f10__ //Expr
							Println59(str53{7,(i8*)"mod i64"});
						}else{
							#line 1041 f10__ //Expr
							if(equal3219(function,(&(*generate.semantic).intrinsic.add_f32))){
								#line 1042 f10__ //Expr
								AddValue192((*generate.interp),AddInstr_f32);
								#line 1043 f10__ //Expr
								Println59(str53{7,(i8*)"add f32"});
							}else{
								#line 1045 f10__ //Expr
								if(equal3219(function,(&(*generate.semantic).intrinsic.sub_f32))){
									#line 1046 f10__ //Expr
									AddValue192((*generate.interp),SubInstr_f32);
									#line 1047 f10__ //Expr
									Println59(str53{7,(i8*)"sub f32"});
								}else{
									#line 1049 f10__ //Expr
									if(equal3219(function,(&(*generate.semantic).intrinsic.div_f32))){
										#line 1050 f10__ //Expr
										AddValue192((*generate.interp),DivInstr_f32);
										#line 1051 f10__ //Expr
										Println59(str53{7,(i8*)"div f32"});
									}else{
										#line 1053 f10__ //Expr
										if(equal3219(function,(&(*generate.semantic).intrinsic.mul_f32))){
											#line 1054 f10__ //Expr
											AddValue192((*generate.interp),MulInstr_f32);
											#line 1055 f10__ //Expr
											Println59(str53{7,(i8*)"mul f32"});
										}else{
											#line 1057 f10__ //Expr
											if(equal68((*function).ident,str53{2,(i8*)"=="})){
												#line 1058 f10__ //Expr
												Print236(generate,add64(str53{12,(i8*)"Comp: == i64"},str53{1,(i8*)"\n"}));
												#line 1059 f10__ //Expr
												AddValue192((*generate.interp),CompareInstr_i64);
												#line 1060 f10__ //Expr
												AddValue192((*generate.interp),TestEqInstr);
											}else{
												#line 1062 f10__ //Expr
												if(equal68((*function).ident,str53{2,(i8*)"!="})){
													#line 1063 f10__ //Expr
													Print236(generate,add64(str53{12,(i8*)"Comp: != i64"},str53{1,(i8*)"\n"}));
													#line 1064 f10__ //Expr
													AddValue192((*generate.interp),CompareInstr_i64);
													#line 1065 f10__ //Expr
													AddValue192((*generate.interp),TestNotEqInstr);
												}else{
													#line 1067 f10__ //Expr
													if(equal68((*function).ident,str53{1,(i8*)"<"})){
														#line 1068 f10__ //Expr
														Print236(generate,add64(str53{11,(i8*)"Comp: < i64"},str53{1,(i8*)"\n"}));
														#line 1069 f10__ //Expr
														AddValue192((*generate.interp),CompareInstr_i64);
														#line 1070 f10__ //Expr
														AddValue192((*generate.interp),TestLessInstr);
													}else{
														#line 1072 f10__ //Expr
														if(equal68((*function).ident,str53{1,(i8*)">"})){
															#line 1073 f10__ //Expr
															Print236(generate,add64(str53{11,(i8*)"Comp: > i64"},str53{1,(i8*)"\n"}));
															#line 1074 f10__ //Expr
															AddValue192((*generate.interp),CompareInstr_i64);
															#line 1075 f10__ //Expr
															AddValue192((*generate.interp),TestGreaterInstr);
														}else{
															#line 1077 f10__ //Expr
															if(equal68((*function).ident,str53{2,(i8*)"<="})){
																#line 1078 f10__ //Expr
																Print236(generate,add64(str53{12,(i8*)"Comp: <= i64"},str53{1,(i8*)"\n"}));
																#line 1079 f10__ //Expr
																AddValue192((*generate.interp),CompareInstr_i64);
																#line 1080 f10__ //Expr
																AddValue192((*generate.interp),TestLessEqInstr);
															}else{
																#line 1082 f10__ //Expr
																if(equal68((*function).ident,str53{2,(i8*)">="})){
																	#line 1083 f10__ //Expr
																	Print236(generate,add64(str53{12,(i8*)"Comp: >= i64"},str53{1,(i8*)"\n"}));
																	#line 1084 f10__ //Expr
																	AddValue192((*generate.interp),CompareInstr_i64);
																	#line 1085 f10__ //Expr
																	AddValue192((*generate.interp),TestGreaterEqInstr);
																}else{
																	#line 1087 f10__ //Expr
																	if(equal68((*function).ident,str53{4,(i8*)"dref"})){
																		#line 1088 f10__ //Expr
																		if((Context239(generate)==ContextStore)){
																			#line 1089 f10__ //Expr
																			Println59(str53{25,(i8*)"dref: no op context store"});
																		}else{
																			#line 1092 f10__ //Expr
																			Print58(str53{5,(i8*)"dref:"});
																			#line 1093 f10__ //Expr
																			LoadAddressInstr229(generate,Size221((*As0142((*Resolved127((*(*OpArray4122((*call).params.list,0)).typ))))).reference));
																		};
																	}else{
																		#line 1098 f10__ //Expr
																		Println59(add64(str53{36,(i8*)"----unhandled intrinsic interp -----"},(*function).ident));
																		#line 1099 f10__ //Expr
																		Assert261(0);
																	};
																};
															};
														};
													};
												};
											};
										};
									};
								};
							};
						};
					};
				};
			};
		};
}
	#line 11 f11__ //Expr
		#line 12 f11__ //Expr
		#line 13 f11__ //Expr
		#line 14 f11__ //Expr
		#line 15 f11__ //Expr
		#line 16 f11__ //Expr
		#line 19 f11__ //Expr
	Trait490* new040(){
		#line 20 f11__ //Expr
		Trait490* mem=Alloc041(1);
		#line 21 f11__ //Expr
		return mem;
}
Require493* new143(){
		#line 20 f11__ //Expr
		Require493* mem=Alloc144(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeOption421* new246(){
		#line 20 f11__ //Expr
		TypeOption421* mem=Alloc247(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeType427* new349(){
		#line 20 f11__ //Expr
		TypeType427* mem=Alloc350(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeGeneric423* new453(){
		#line 20 f11__ //Expr
		TypeGeneric423* mem=Alloc454(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeRef419* new556(){
		#line 20 f11__ //Expr
		TypeRef419* mem=Alloc557(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeAny425* new659(){
		#line 20 f11__ //Expr
		TypeAny425* mem=Alloc660(1);
		#line 21 f11__ //Expr
		return mem;
}
ForList512* new764(){
		#line 20 f11__ //Expr
		ForList512* mem=Alloc765(1);
		#line 21 f11__ //Expr
		return mem;
}
For449* new868(){
		#line 20 f11__ //Expr
		For449* mem=Alloc869(1);
		#line 21 f11__ //Expr
		return mem;
}
Branch452* new971(){
		#line 20 f11__ //Expr
		Branch452* mem=Alloc972(1);
		#line 21 f11__ //Expr
		return mem;
}
If447* new1074(){
		#line 20 f11__ //Expr
		If447* mem=Alloc1075(1);
		#line 21 f11__ //Expr
		return mem;
}
Return454* new1177(){
		#line 20 f11__ //Expr
		Return454* mem=Alloc1178(1);
		#line 21 f11__ //Expr
		return mem;
}
NumberConstant507* new1280(){
		#line 20 f11__ //Expr
		NumberConstant507* mem=Alloc1281(1);
		#line 21 f11__ //Expr
		return mem;
}
StringConstant509* new1383(){
		#line 20 f11__ //Expr
		StringConstant509* mem=Alloc1384(1);
		#line 21 f11__ //Expr
		return mem;
}
ExpressionList369* new1486(){
		#line 20 f11__ //Expr
		ExpressionList369* mem=Alloc1487(1);
		#line 21 f11__ //Expr
		return mem;
}
Identifier495* new1591(){
		#line 20 f11__ //Expr
		Identifier495* mem=Alloc1592(1);
		#line 21 f11__ //Expr
		return mem;
}
Access445* new1694(){
		#line 20 f11__ //Expr
		Access445* mem=Alloc1695(1);
		#line 21 f11__ //Expr
		return mem;
}
Assign501* new1797(){
		#line 20 f11__ //Expr
		Assign501* mem=Alloc1798(1);
		#line 21 f11__ //Expr
		return mem;
}
Block434* new18102(){
		#line 20 f11__ //Expr
		Block434* mem=Alloc18103(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeAs367* new19166(){
		#line 20 f11__ //Expr
		TypeAs367* mem=Alloc20167(1);
		#line 21 f11__ //Expr
		return mem;
}
Call442* new20175(){
		#line 20 f11__ //Expr
		Call442* mem=Alloc21176(1);
		#line 21 f11__ //Expr
		return mem;
}
Variable498* new21188(){
		#line 20 f11__ //Expr
		Variable498* mem=Alloc22189(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeIdentifier414* new22207(){
		#line 20 f11__ //Expr
		TypeIdentifier414* mem=Alloc23208(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeTrait429* new23210(){
		#line 20 f11__ //Expr
		TypeTrait429* mem=Alloc24211(1);
		#line 21 f11__ //Expr
		return mem;
}
Module155* new24235(){
		#line 20 f11__ //Expr
		Module155* mem=Alloc27236(1);
		#line 21 f11__ //Expr
		return mem;
}
DebugLocal207* new25278(){
		#line 20 f11__ //Expr
		DebugLocal207* mem=Alloc29279(1);
		#line 21 f11__ //Expr
		return mem;
}
DebugFrame209* new26296(){
		#line 20 f11__ //Expr
		DebugFrame209* mem=Alloc30297(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeFunctions417* new27332(){
		#line 20 f11__ //Expr
		TypeFunctions417* mem=Alloc31333(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeNumber431* new28335(){
		#line 20 f11__ //Expr
		TypeNumber431* mem=Alloc32336(1);
		#line 21 f11__ //Expr
		return mem;
}
Function456* new29351(){
		#line 20 f11__ //Expr
		Function456* mem=Alloc26217(1);
		#line 21 f11__ //Expr
		return mem;
}
FunctionSpec460* new30355(){
		#line 20 f11__ //Expr
		FunctionSpec460* mem=Alloc33356(1);
		#line 21 f11__ //Expr
		return mem;
}
Structure473* new31362(){
		#line 20 f11__ //Expr
		Structure473* mem=Alloc34363(1);
		#line 21 f11__ //Expr
		return mem;
}
TypeStructure481* new32367(){
		#line 20 f11__ //Expr
		TypeStructure481* mem=Alloc35368(1);
		#line 21 f11__ //Expr
		return mem;
}
	#line 24 f11__ //Expr
		#line 32 f11__ //Expr
	void Assert0173(Type413* condition){
		#line 33 f11__ //Expr
		Assert261(((i64)condition!=0));
}
void Assert1178(FunctionSpec460* condition){
		#line 33 f11__ //Expr
		Assert261(((i64)condition!=0));
}
void Assert2203(TypeStructure481* condition){
		#line 33 f11__ //Expr
		Assert261(((i64)condition!=0));
}
	#line 37 f11__ //Expr
	void Assert051(i8* condition,str53 reason){
		#line 38 f11__ //Expr
		Assert260(((i64)condition!=0),reason);
}
void Assert162(Expr366* condition,str53 reason){
		#line 38 f11__ //Expr
		Assert260(((i64)condition!=0),reason);
}
void Assert2140(Type413* condition,str53 reason){
		#line 38 f11__ //Expr
		Assert260(((i64)condition!=0),reason);
}
void Assert3180(ExpressionList369* condition,str53 reason){
		#line 38 f11__ //Expr
		Assert260(((i64)condition!=0),reason);
}
void Assert4201(TypeStructure481* condition,str53 reason){
		#line 38 f11__ //Expr
		Assert260(((i64)condition!=0),reason);
}
void Assert5260(DebugFrame209* condition,str53 reason){
		#line 38 f11__ //Expr
		Assert260(((i64)condition!=0),reason);
}
	#line 41 f11__ //Expr
	void Assert260(i8 condition,str53 reason){
		#line 42 f11__ //Expr
		if((!condition)){
			#line 43 f11__ //Expr
			Backtrace();
			#line 44 f11__ //Expr
			Println59(add64(str53{10,(i8*)"Aborting: "},reason));
			#line 45 f11__ //Expr
			abort();
		};
}
	#line 49 f11__ //Expr
	void Assert261(i8 condition){
		#line 50 f11__ //Expr
		if((!condition)){
			#line 51 f11__ //Expr
			Backtrace();
			#line 52 f11__ //Expr
			abort();
		};
}
	#line 56 f11__ //Expr
	Trait490* Alloc041(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo2.size*(u32)len);
		#line 59 f11__ //Expr
		return (Trait490*)calloc(1,size);
}
Require493* Alloc144(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo3.size*(u32)len);
		#line 59 f11__ //Expr
		return (Require493*)calloc(1,size);
}
TypeOption421* Alloc247(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo4.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeOption421*)calloc(1,size);
}
TypeType427* Alloc350(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo5.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeType427*)calloc(1,size);
}
TypeGeneric423* Alloc454(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo6.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeGeneric423*)calloc(1,size);
}
TypeRef419* Alloc557(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo7.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeRef419*)calloc(1,size);
}
TypeAny425* Alloc660(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo8.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeAny425*)calloc(1,size);
}
ForList512* Alloc765(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo9.size*(u32)len);
		#line 59 f11__ //Expr
		return (ForList512*)calloc(1,size);
}
For449* Alloc869(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo10.size*(u32)len);
		#line 59 f11__ //Expr
		return (For449*)calloc(1,size);
}
Branch452* Alloc972(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo11.size*(u32)len);
		#line 59 f11__ //Expr
		return (Branch452*)calloc(1,size);
}
If447* Alloc1075(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo12.size*(u32)len);
		#line 59 f11__ //Expr
		return (If447*)calloc(1,size);
}
Return454* Alloc1178(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo13.size*(u32)len);
		#line 59 f11__ //Expr
		return (Return454*)calloc(1,size);
}
NumberConstant507* Alloc1281(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo14.size*(u32)len);
		#line 59 f11__ //Expr
		return (NumberConstant507*)calloc(1,size);
}
StringConstant509* Alloc1384(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo15.size*(u32)len);
		#line 59 f11__ //Expr
		return (StringConstant509*)calloc(1,size);
}
ExpressionList369* Alloc1487(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo16.size*(u32)len);
		#line 59 f11__ //Expr
		return (ExpressionList369*)calloc(1,size);
}
Identifier495* Alloc1592(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo18.size*(u32)len);
		#line 59 f11__ //Expr
		return (Identifier495*)calloc(1,size);
}
Access445* Alloc1695(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo19.size*(u32)len);
		#line 59 f11__ //Expr
		return (Access445*)calloc(1,size);
}
Assign501* Alloc1798(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo20.size*(u32)len);
		#line 59 f11__ //Expr
		return (Assign501*)calloc(1,size);
}
Block434* Alloc18103(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo22.size*(u32)len);
		#line 59 f11__ //Expr
		return (Block434*)calloc(1,size);
}
i8* Alloc19109(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo23.size*(u32)len);
		#line 59 f11__ //Expr
		return (i8*)calloc(1,size);
}
TypeAs367* Alloc20167(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo26.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeAs367*)calloc(1,size);
}
Call442* Alloc21176(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo29.size*(u32)len);
		#line 59 f11__ //Expr
		return (Call442*)calloc(1,size);
}
Variable498* Alloc22189(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo30.size*(u32)len);
		#line 59 f11__ //Expr
		return (Variable498*)calloc(1,size);
}
TypeIdentifier414* Alloc23208(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo31.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeIdentifier414*)calloc(1,size);
}
TypeTrait429* Alloc24211(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo32.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeTrait429*)calloc(1,size);
}
TypeNumber431** Alloc25214(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo33.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeNumber431**)calloc(1,size);
}
Function456* Alloc26217(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo34.size*(u32)len);
		#line 59 f11__ //Expr
		return (Function456*)calloc(1,size);
}
Module155* Alloc27236(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo36.size*(u32)len);
		#line 59 f11__ //Expr
		return (Module155*)calloc(1,size);
}
i64* Alloc28240(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo38.size*(u32)len);
		#line 59 f11__ //Expr
		return (i64*)calloc(1,size);
}
DebugLocal207* Alloc29279(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo42.size*(u32)len);
		#line 59 f11__ //Expr
		return (DebugLocal207*)calloc(1,size);
}
DebugFrame209* Alloc30297(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo46.size*(u32)len);
		#line 59 f11__ //Expr
		return (DebugFrame209*)calloc(1,size);
}
TypeFunctions417* Alloc31333(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo54.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeFunctions417*)calloc(1,size);
}
TypeNumber431* Alloc32336(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo55.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeNumber431*)calloc(1,size);
}
FunctionSpec460* Alloc33356(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo59.size*(u32)len);
		#line 59 f11__ //Expr
		return (FunctionSpec460*)calloc(1,size);
}
Structure473* Alloc34363(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo62.size*(u32)len);
		#line 59 f11__ //Expr
		return (Structure473*)calloc(1,size);
}
TypeStructure481* Alloc35368(i64 len){
		#line 58 f11__ //Expr
		u64 size=(u64)(typeinfo64.size*(u32)len);
		#line 59 f11__ //Expr
		return (TypeStructure481*)calloc(1,size);
}
	#line 62 f11__ //Expr
		#line 68 f11__ //Expr
	void CopyPtr0110(i8* from,i8* to,i64 len){
		#line 69 f11__ //Expr
		u64 size=(u64)(typeinfo23.size*(u32)len);
		#line 70 f11__ //Expr
		memcpy((voidptr)to,(voidptr)from,size);
}
	#line 6 f12__ //Expr
	i64 i64265(u8 i){
		#line 6 f12__ //Expr
		return (i64)i;
}
	#line 7 f12__ //Expr
	i64 i64266(u16 i){
		#line 7 f12__ //Expr
		return (i64)i;
}
	#line 8 f12__ //Expr
	i64 i64267(u32 i){
		#line 8 f12__ //Expr
		return (i64)i;
}
	#line 9 f12__ //Expr
	i64 i64268(u64 i){
		#line 9 f12__ //Expr
		return (i64)i;
}
	#line 10 f12__ //Expr
	i64 i64269(i8 i){
		#line 10 f12__ //Expr
		return (i64)i;
}
	#line 11 f12__ //Expr
	i64 i64270(i32 i){
		#line 11 f12__ //Expr
		return (i64)i;
}
	#line 12 f12__ //Expr
	i64 i64271(i64 i){
		#line 12 f12__ //Expr
		return (i64)i;
}
	#line 13 f12__ //Expr
	i64 i64272(f32 i){
		#line 13 f12__ //Expr
		return (i64)i;
}
	#line 14 f12__ //Expr
	i64 i64273(f64 i){
		#line 14 f12__ //Expr
		return (i64)i;
}
	#line 16 f12__ //Expr
	i32 i32274(u8 i){
		#line 16 f12__ //Expr
		return (i32)i;
}
	#line 17 f12__ //Expr
	i32 i32275(u32 i){
		#line 17 f12__ //Expr
		return (i32)i;
}
	#line 18 f12__ //Expr
	i32 i32276(u64 i){
		#line 18 f12__ //Expr
		return (i32)i;
}
	#line 19 f12__ //Expr
	i32 i32277(i8 i){
		#line 19 f12__ //Expr
		return (i32)i;
}
	#line 20 f12__ //Expr
	i32 i32278(i32 i){
		#line 20 f12__ //Expr
		return (i32)i;
}
	#line 21 f12__ //Expr
	i32 i32279(i64 i){
		#line 21 f12__ //Expr
		return (i32)i;
}
	#line 22 f12__ //Expr
	i32 i32280(f32 i){
		#line 22 f12__ //Expr
		return (i32)i;
}
	#line 23 f12__ //Expr
	i32 i32281(f64 i){
		#line 23 f12__ //Expr
		return (i32)i;
}
	#line 25 f12__ //Expr
	i16 i16282(i16 i){
		#line 25 f12__ //Expr
		return (i16)i;
}
	#line 26 f12__ //Expr
	i16 i16283(u32 i){
		#line 26 f12__ //Expr
		return (i16)i;
}
	#line 27 f12__ //Expr
	i16 i16284(u64 i){
		#line 27 f12__ //Expr
		return (i16)i;
}
	#line 28 f12__ //Expr
	i16 i16285(i8 i){
		#line 28 f12__ //Expr
		return (i16)i;
}
	#line 29 f12__ //Expr
	i16 i16286(i32 i){
		#line 29 f12__ //Expr
		return (i16)i;
}
	#line 30 f12__ //Expr
	i16 i16287(i64 i){
		#line 30 f12__ //Expr
		return (i16)i;
}
	#line 31 f12__ //Expr
	i16 i16288(f32 i){
		#line 31 f12__ //Expr
		return (i16)i;
}
	#line 32 f12__ //Expr
	i16 i16289(f64 i){
		#line 32 f12__ //Expr
		return (i16)i;
}
	#line 34 f12__ //Expr
	i8 i8290(u8 i){
		#line 34 f12__ //Expr
		return (i8)i;
}
	#line 35 f12__ //Expr
	i8 i8291(u32 i){
		#line 35 f12__ //Expr
		return (i8)i;
}
	#line 36 f12__ //Expr
	i8 i8292(u64 i){
		#line 36 f12__ //Expr
		return (i8)i;
}
	#line 37 f12__ //Expr
	i8 i8293(i8 i){
		#line 37 f12__ //Expr
		return (i8)i;
}
	#line 38 f12__ //Expr
	i8 i8294(i32 i){
		#line 38 f12__ //Expr
		return (i8)i;
}
	#line 39 f12__ //Expr
	i8 i8295(i64 i){
		#line 39 f12__ //Expr
		return (i8)i;
}
	#line 40 f12__ //Expr
	i8 i8296(f32 i){
		#line 40 f12__ //Expr
		return (i8)i;
}
	#line 41 f12__ //Expr
	i8 i8297(f64 i){
		#line 41 f12__ //Expr
		return (i8)i;
}
	#line 43 f12__ //Expr
	u8 u8298(u8 i){
		#line 43 f12__ //Expr
		return (u8)i;
}
	#line 44 f12__ //Expr
	u8 u8299(u32 i){
		#line 44 f12__ //Expr
		return (u8)i;
}
	#line 45 f12__ //Expr
	u8 u8300(u64 i){
		#line 45 f12__ //Expr
		return (u8)i;
}
	#line 46 f12__ //Expr
	u8 u8301(i8 i){
		#line 46 f12__ //Expr
		return (u8)i;
}
	#line 47 f12__ //Expr
	u8 u8302(i32 i){
		#line 47 f12__ //Expr
		return (u8)i;
}
	#line 48 f12__ //Expr
	u8 u8303(i64 i){
		#line 48 f12__ //Expr
		return (u8)i;
}
	#line 49 f12__ //Expr
	u8 u8304(f32 i){
		#line 49 f12__ //Expr
		return (u8)i;
}
	#line 50 f12__ //Expr
	u8 u8305(f64 i){
		#line 50 f12__ //Expr
		return (u8)i;
}
	#line 52 f12__ //Expr
	u16 u16306(u16 i){
		#line 52 f12__ //Expr
		return (u16)i;
}
	#line 53 f12__ //Expr
	u16 u16307(u32 i){
		#line 53 f12__ //Expr
		return (u16)i;
}
	#line 54 f12__ //Expr
	u16 u16308(u64 i){
		#line 54 f12__ //Expr
		return (u16)i;
}
	#line 55 f12__ //Expr
	u16 u16309(i8 i){
		#line 55 f12__ //Expr
		return (u16)i;
}
	#line 56 f12__ //Expr
	u16 u16310(i32 i){
		#line 56 f12__ //Expr
		return (u16)i;
}
	#line 57 f12__ //Expr
	u16 u16311(i64 i){
		#line 57 f12__ //Expr
		return (u16)i;
}
	#line 58 f12__ //Expr
	u16 u16312(f32 i){
		#line 58 f12__ //Expr
		return (u16)i;
}
	#line 59 f12__ //Expr
	u16 u16313(f64 i){
		#line 59 f12__ //Expr
		return (u16)i;
}
	#line 61 f12__ //Expr
	u32 u32314(u8 i){
		#line 61 f12__ //Expr
		return (u32)i;
}
	#line 62 f12__ //Expr
	u32 u32315(u32 i){
		#line 62 f12__ //Expr
		return (u32)i;
}
	#line 63 f12__ //Expr
	u32 u32316(u64 i){
		#line 63 f12__ //Expr
		return (u32)i;
}
	#line 64 f12__ //Expr
	u32 u32317(i8 i){
		#line 64 f12__ //Expr
		return (u32)i;
}
	#line 65 f12__ //Expr
	u32 u32318(i32 i){
		#line 65 f12__ //Expr
		return (u32)i;
}
	#line 66 f12__ //Expr
	u32 u32319(i64 i){
		#line 66 f12__ //Expr
		return (u32)i;
}
	#line 67 f12__ //Expr
	u32 u32320(f32 i){
		#line 67 f12__ //Expr
		return (u32)i;
}
	#line 68 f12__ //Expr
	u32 u32321(f64 i){
		#line 68 f12__ //Expr
		return (u32)i;
}
	#line 70 f12__ //Expr
	u64 u64322(u8 i){
		#line 70 f12__ //Expr
		return (u64)i;
}
	#line 71 f12__ //Expr
	u64 u64323(u32 i){
		#line 71 f12__ //Expr
		return (u64)i;
}
	#line 72 f12__ //Expr
	u64 u64324(u64 i){
		#line 72 f12__ //Expr
		return (u64)i;
}
	#line 73 f12__ //Expr
	u64 u64325(i8 i){
		#line 73 f12__ //Expr
		return (u64)i;
}
	#line 74 f12__ //Expr
	u64 u64326(i32 i){
		#line 74 f12__ //Expr
		return (u64)i;
}
	#line 75 f12__ //Expr
	u64 u64327(i64 i){
		#line 75 f12__ //Expr
		return (u64)i;
}
	#line 76 f12__ //Expr
	u64 u64328(f32 i){
		#line 76 f12__ //Expr
		return (u64)i;
}
	#line 77 f12__ //Expr
	u64 u64329(f64 i){
		#line 77 f12__ //Expr
		return (u64)i;
}
	#line 79 f12__ //Expr
	f32 f32330(u8 i){
		#line 79 f12__ //Expr
		return (f32)i;
}
	#line 80 f12__ //Expr
	f32 f32331(u32 i){
		#line 80 f12__ //Expr
		return (f32)i;
}
	#line 81 f12__ //Expr
	f32 f32332(u64 i){
		#line 81 f12__ //Expr
		return (f32)i;
}
	#line 82 f12__ //Expr
	f32 f32333(i8 i){
		#line 82 f12__ //Expr
		return (f32)i;
}
	#line 83 f12__ //Expr
	f32 f32334(i32 i){
		#line 83 f12__ //Expr
		return (f32)i;
}
	#line 84 f12__ //Expr
	f32 f32335(i64 i){
		#line 84 f12__ //Expr
		return (f32)i;
}
	#line 85 f12__ //Expr
	f32 f32336(f32 i){
		#line 85 f12__ //Expr
		return (f32)i;
}
	#line 86 f12__ //Expr
	f32 f32337(f64 i){
		#line 86 f12__ //Expr
		return (f32)i;
}
	#line 88 f12__ //Expr
	f64 f64338(u8 i){
		#line 88 f12__ //Expr
		return (f64)i;
}
	#line 89 f12__ //Expr
	f64 f64339(u32 i){
		#line 89 f12__ //Expr
		return (f64)i;
}
	#line 90 f12__ //Expr
	f64 f64340(u64 i){
		#line 90 f12__ //Expr
		return (f64)i;
}
	#line 91 f12__ //Expr
	f64 f64341(i8 i){
		#line 91 f12__ //Expr
		return (f64)i;
}
	#line 92 f12__ //Expr
	f64 f64342(i32 i){
		#line 92 f12__ //Expr
		return (f64)i;
}
	#line 93 f12__ //Expr
	f64 f64343(i64 i){
		#line 93 f12__ //Expr
		return (f64)i;
}
	#line 94 f12__ //Expr
	f64 f64344(f32 i){
		#line 94 f12__ //Expr
		return (f64)i;
}
	#line 95 f12__ //Expr
	f64 f64345(f64 i){
		#line 95 f12__ //Expr
		return (f64)i;
}
		#line 5 f13__ //Expr
		#line 6 f13__ //Expr
		#line 7 f13__ //Expr
		#line 8 f13__ //Expr
		#line 9 f13__ //Expr
		#line 10 f13__ //Expr
		#line 11 f13__ //Expr
		#line 12 f13__ //Expr
		#line 13 f13__ //Expr
		#line 14 f13__ //Expr
		#line 15 f13__ //Expr
		#line 24 f13__ //Expr
		#line 25 f13__ //Expr
		#line 28 f13__ //Expr
	;
	#line 29 f13__ //Expr
	;
	#line 30 f13__ //Expr
	;
	#line 31 f13__ //Expr
	;
	#line 32 f13__ //Expr
	;
	#line 33 f13__ //Expr
	;
	#line 34 f13__ //Expr
	;
	#line 35 f13__ //Expr
	;
	#line 36 f13__ //Expr
	;
	#line 37 f13__ //Expr
	;
	#line 38 f13__ //Expr
	;
	#line 39 f13__ //Expr
	;
	#line 40 f13__ //Expr
	;
	#line 41 f13__ //Expr
	;
	#line 42 f13__ //Expr
	;
	#line 43 f13__ //Expr
	;
	#line 44 f13__ //Expr
	;
	#line 45 f13__ //Expr
	;
	#line 46 f13__ //Expr
	;
	#line 47 f13__ //Expr
	;
	#line 48 f13__ //Expr
	;
	#line 49 f13__ //Expr
	;
	#line 50 f13__ //Expr
	;
	#line 51 f13__ //Expr
	;
	#line 52 f13__ //Expr
	;
	#line 53 f13__ //Expr
	;
	#line 54 f13__ //Expr
	;
	#line 55 f13__ //Expr
	;
	#line 56 f13__ //Expr
	;
	#line 57 f13__ //Expr
	;
	#line 58 f13__ //Expr
	;
	#line 59 f13__ //Expr
	;
	#line 60 f13__ //Expr
	;
	#line 61 f13__ //Expr
	;
	#line 62 f13__ //Expr
	;
	#line 63 f13__ //Expr
	;
	#line 64 f13__ //Expr
	;
	#line 65 f13__ //Expr
	;
	#line 66 f13__ //Expr
	;
	#line 67 f13__ //Expr
	;
	#line 68 f13__ //Expr
	;
	#line 69 f13__ //Expr
	;
	#line 70 f13__ //Expr
	;
	#line 71 f13__ //Expr
	;
	#line 72 f13__ //Expr
	;
	#line 73 f13__ //Expr
	;
	#line 74 f13__ //Expr
	;
	#line 75 f13__ //Expr
	;
	#line 76 f13__ //Expr
	;
	#line 77 f13__ //Expr
	;
	#line 78 f13__ //Expr
	;
	#line 79 f13__ //Expr
	;
	#line 81 f13__ //Expr
	;
	#line 82 f13__ //Expr
	;
	#line 83 f13__ //Expr
	;
	#line 84 f13__ //Expr
	;
	#line 85 f13__ //Expr
	;
	#line 86 f13__ //Expr
	;
	#line 87 f13__ //Expr
	;
	#line 88 f13__ //Expr
	;
	#line 89 f13__ //Expr
	;
	#line 90 f13__ //Expr
	;
		#line 16 f14__ //Expr
	i32 Convert361(Expr366& desired,Expr366& from,i8 reportError){
		#line 18 f14__ //Expr
		if(Equal132(desired.typ,from.typ,true)){
			#line 19 f14__ //Expr
			return 1;
		};
		#line 21 f14__ //Expr
		i32 value=Coerce362(desired,from,reportError);
		#line 22 f14__ //Expr
		if((value!=0)){
			#line 24 f14__ //Expr
			return (value+1);
		};
		#line 26 f14__ //Expr
		return 0;
}
	#line 29 f14__ //Expr
	i32 Coerce362(Expr366& desired,Expr366& from,i8 reportError){
		#line 31 f14__ //Expr
		return Coerce363((*Resolved127((*desired.typ))),from,reportError);
}
	#line 34 f14__ //Expr
	i32 Coerce363(Type413& desiredType,Expr366& from,i8 reportError){
		#line 36 f14__ //Expr
		Type413* fromType=Resolved127((*from.typ));
		#line 38 f14__ //Expr
		if(Is11181(from)){
			#line 40 f14__ //Expr
			if(Is7156(desiredType)){
				#line 41 f14__ //Expr
				(*As10182(from)).super.typ = (&desiredType);
			}else{
				#line 44 f14__ //Expr
				return 0;
			};
			#line 47 f14__ //Expr
			return 1;
		};
		#line 50 f14__ //Expr
		if(Is7156(desiredType)){
			#line 52 f14__ //Expr
			if(Is7156((*fromType))){
				#line 54 f14__ //Expr
				TypeNumber431* f=As7157((*fromType));
				#line 55 f14__ //Expr
				TypeNumber431* d=As7157(desiredType);
				#line 57 f14__ //Expr
				if(((*d).kind==(*f).kind)){
					#line 58 f14__ //Expr
					if(((*d).size<(*f).size)){
						#line 60 f14__ //Expr
						return 0;
					};
				}else{
					#line 63 f14__ //Expr
					if(((((*d).kind==TypeNumberInteger)&&((*f).kind==TypeNumberUnsigned))||(((*f).kind==TypeNumberInteger)&&((*d).kind==TypeNumberUnsigned)))){
						#line 65 f14__ //Expr
						if(((*d).size<(*f).size)){
							#line 67 f14__ //Expr
							return 0;
						};
					}else{
						#line 80 f14__ //Expr
						return 0;
					};
				};
				#line 83 f14__ //Expr
				return 1;
			};
		};
		#line 86 f14__ //Expr
		if(reportError){
			#line 87 f14__ //Expr
			Error108(from,add64(add64(add64(str53{8,(i8*)"type of "},String107(desiredType)),str53{30,(i8*)" cannot be assigned a type of "}),String105(fromType)));
			#line 88 f14__ //Expr
			Assert261(0);
		};
		#line 90 f14__ //Expr
		return 0;
}
	#line 16 f15__ //Expr
	void PrintTabs364(i32 count){
		#line 17 f15__ //Expr
		for(i32 it = i32274(0); it<count;it++){
			#line 18 f15__ //Expr
			Print58(str53{1,(i8*)"\t"});
		};
}
	#line 22 f15__ //Expr
	Trait490* New039(){
		#line 23 f15__ //Expr
		Trait490* t=new040();
		#line 24 f15__ //Expr
		Init491((*t));
		#line 25 f15__ //Expr
		return t;
}
Require493* New142(){
		#line 23 f15__ //Expr
		Require493* t=new143();
		#line 24 f15__ //Expr
		Init494((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeOption421* New245(){
		#line 23 f15__ //Expr
		TypeOption421* t=new246();
		#line 24 f15__ //Expr
		Init422((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeType427* New348(){
		#line 23 f15__ //Expr
		TypeType427* t=new349();
		#line 24 f15__ //Expr
		Init428((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeGeneric423* New452(){
		#line 23 f15__ //Expr
		TypeGeneric423* t=new453();
		#line 24 f15__ //Expr
		Init424((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeRef419* New555(){
		#line 23 f15__ //Expr
		TypeRef419* t=new556();
		#line 24 f15__ //Expr
		Init420((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeAny425* New658(){
		#line 23 f15__ //Expr
		TypeAny425* t=new659();
		#line 24 f15__ //Expr
		Init426((*t));
		#line 25 f15__ //Expr
		return t;
}
ForList512* New763(){
		#line 23 f15__ //Expr
		ForList512* t=new764();
		#line 24 f15__ //Expr
		Init513((*t));
		#line 25 f15__ //Expr
		return t;
}
For449* New867(){
		#line 23 f15__ //Expr
		For449* t=new868();
		#line 24 f15__ //Expr
		Init451((*t));
		#line 25 f15__ //Expr
		return t;
}
Branch452* New970(){
		#line 23 f15__ //Expr
		Branch452* t=new971();
		#line 24 f15__ //Expr
		Init453((*t));
		#line 25 f15__ //Expr
		return t;
}
If447* New1073(){
		#line 23 f15__ //Expr
		If447* t=new1074();
		#line 24 f15__ //Expr
		Init448((*t));
		#line 25 f15__ //Expr
		return t;
}
Return454* New1176(){
		#line 23 f15__ //Expr
		Return454* t=new1177();
		#line 24 f15__ //Expr
		Init455((*t));
		#line 25 f15__ //Expr
		return t;
}
NumberConstant507* New1279(){
		#line 23 f15__ //Expr
		NumberConstant507* t=new1280();
		#line 24 f15__ //Expr
		Init508((*t));
		#line 25 f15__ //Expr
		return t;
}
StringConstant509* New1382(){
		#line 23 f15__ //Expr
		StringConstant509* t=new1383();
		#line 24 f15__ //Expr
		Init510((*t));
		#line 25 f15__ //Expr
		return t;
}
ExpressionList369* New1485(){
		#line 23 f15__ //Expr
		ExpressionList369* t=new1486();
		#line 24 f15__ //Expr
		Init370((*t));
		#line 25 f15__ //Expr
		return t;
}
Identifier495* New1590(){
		#line 23 f15__ //Expr
		Identifier495* t=new1591();
		#line 24 f15__ //Expr
		Init497((*t));
		#line 25 f15__ //Expr
		return t;
}
Access445* New1693(){
		#line 23 f15__ //Expr
		Access445* t=new1694();
		#line 24 f15__ //Expr
		Init446((*t));
		#line 25 f15__ //Expr
		return t;
}
Assign501* New1796(){
		#line 23 f15__ //Expr
		Assign501* t=new1797();
		#line 24 f15__ //Expr
		Init502((*t));
		#line 25 f15__ //Expr
		return t;
}
Block434* New18101(){
		#line 23 f15__ //Expr
		Block434* t=new18102();
		#line 24 f15__ //Expr
		Init435((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeAs367* New19165(){
		#line 23 f15__ //Expr
		TypeAs367* t=new19166();
		#line 24 f15__ //Expr
		Init368((*t));
		#line 25 f15__ //Expr
		return t;
}
Call442* New20174(){
		#line 23 f15__ //Expr
		Call442* t=new20175();
		#line 24 f15__ //Expr
		Init444((*t));
		#line 25 f15__ //Expr
		return t;
}
Variable498* New21187(){
		#line 23 f15__ //Expr
		Variable498* t=new21188();
		#line 24 f15__ //Expr
		Init499((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeIdentifier414* New22206(){
		#line 23 f15__ //Expr
		TypeIdentifier414* t=new22207();
		#line 24 f15__ //Expr
		Init416((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeTrait429* New23209(){
		#line 23 f15__ //Expr
		TypeTrait429* t=new23210();
		#line 24 f15__ //Expr
		Init430((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeNumber431* New24334(){
		#line 23 f15__ //Expr
		TypeNumber431* t=new28335();
		#line 24 f15__ //Expr
		Init432((*t));
		#line 25 f15__ //Expr
		return t;
}
FunctionSpec460* New25354(){
		#line 23 f15__ //Expr
		FunctionSpec460* t=new30355();
		#line 24 f15__ //Expr
		Init467((*t));
		#line 25 f15__ //Expr
		return t;
}
TypeStructure481* New26366(){
		#line 23 f15__ //Expr
		TypeStructure481* t=new32367();
		#line 24 f15__ //Expr
		Init482((*t));
		#line 25 f15__ //Expr
		return t;
}
			#line 39 f15__ //Expr
	void Init368(TypeAs367& self){
		#line 41 f15__ //Expr
		self.super.kind = Id393();
}
		#line 49 f15__ //Expr
	void Init370(ExpressionList369& self){
		#line 51 f15__ //Expr
		Init9330(self.list);
		#line 52 f15__ //Expr
		self.super.kind = Id385();
}
	#line 54 f15__ //Expr
	void Add371(ExpressionList369& list,Expr366* expr){
		#line 55 f15__ //Expr
		Assert162(expr,str53{21,(i8*)"Expected non nil item"});
		#line 56 f15__ //Expr
		Push288(list.list,expr);
}
		#line 64 f15__ //Expr
	void Init373(TypeList372& self){
		#line 66 f15__ //Expr
		Init10331(self.list);
		#line 67 f15__ //Expr
		self.super.kind = Id390();
}
	#line 69 f15__ //Expr
	void Add374(TypeList372& list,Type413* expr){
		#line 70 f15__ //Expr
		Assert2140(expr,str53{21,(i8*)"Expected non nil item"});
		#line 71 f15__ //Expr
		Push137(list.list,expr);
}
	#line 74 f15__ //Expr
	ExpressionList369* As066(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id385()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (ExpressionList369*)(&expr);
}
Block434* As1121(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id382()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Block434*)(&expr);
}
Structure473* As2124(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id380()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Structure473*)(&expr);
}
Function456* As3127(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id379()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Function456*)(&expr);
}
Identifier495* As4129(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id383()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Identifier495*)(&expr);
}
Call442* As5131(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id384()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Call442*)(&expr);
}
Access445* As6133(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id392()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Access445*)(&expr);
}
Variable498* As7135(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id381()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Variable498*)(&expr);
}
Trait490* As8137(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id388()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Trait490*)(&expr);
}
TypeAs367* As9139(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id393()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (TypeAs367*)(&expr);
}
NumberConstant507* As10182(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id398()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (NumberConstant507*)(&expr);
}
StringConstant509* As11184(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id397()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (StringConstant509*)(&expr);
}
ForList512* As12186(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id396()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (ForList512*)(&expr);
}
For449* As13191(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id387()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (For449*)(&expr);
}
Assign501* As14193(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id394()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Assign501*)(&expr);
}
If447* As15195(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id386()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (If447*)(&expr);
}
Return454* As16198(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id402()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (Return454*)(&expr);
}
FunctionSpec460* As17234(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id391()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (FunctionSpec460*)(&expr);
}
StructureSpec479* As18259(Expr366& expr){
		#line 75 f15__ //Expr
		Assert260((expr.kind==Id395()),str53{21,(i8*)"As type Type mismatch"});
		#line 76 f15__ //Expr
		return (StructureSpec479*)(&expr);
}
	#line 78 f15__ //Expr
	i8 Is061(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id385());
}
i8 Is1120(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id382());
}
i8 Is2123(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id380());
}
i8 Is3126(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id379());
}
i8 Is4128(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id383());
}
i8 Is5130(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id384());
}
i8 Is6132(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id392());
}
i8 Is7134(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id381());
}
i8 Is8136(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id388());
}
i8 Is9138(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id393());
}
i8 Is10164(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id389());
}
i8 Is11181(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id398());
}
i8 Is12183(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id397());
}
i8 Is13185(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id396());
}
i8 Is14190(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id387());
}
i8 Is15192(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id394());
}
i8 Is16194(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id386());
}
i8 Is17196(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id401());
}
i8 Is18197(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id402());
}
i8 Is19233(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id391());
}
i8 Is20352(Expr366& expr){
		#line 79 f15__ //Expr
		Assert162((&expr),str53{36,(i8*)"Is expr: Expected non nil expression"});
		#line 80 f15__ //Expr
		return (expr.kind==Id395());
}
	#line 82 f15__ //Expr
	TypeRef419* As0142(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id403())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id403()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id403())));
		#line 88 f15__ //Expr
		return (TypeRef419*)(&typ);
}
TypeIdentifier414* As1144(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id404())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id404()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id404())));
		#line 88 f15__ //Expr
		return (TypeIdentifier414*)(&typ);
}
TypeAny425* As2146(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id407())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id407()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id407())));
		#line 88 f15__ //Expr
		return (TypeAny425*)(&typ);
}
TypeTrait429* As3148(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id411())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id411()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id411())));
		#line 88 f15__ //Expr
		return (TypeTrait429*)(&typ);
}
TypeOption421* As4150(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id409())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id409()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id409())));
		#line 88 f15__ //Expr
		return (TypeOption421*)(&typ);
}
TypeType427* As5152(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id408())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id408()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id408())));
		#line 88 f15__ //Expr
		return (TypeType427*)(&typ);
}
TypeGeneric423* As6154(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id406())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id406()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id406())));
		#line 88 f15__ //Expr
		return (TypeGeneric423*)(&typ);
}
TypeNumber431* As7157(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id410())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id410()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id410())));
		#line 88 f15__ //Expr
		return (TypeNumber431*)(&typ);
}
TypeStructure481* As8223(Type413& typ){
		#line 83 f15__ //Expr
		Assert2140((&typ),str53{29,(i8*)"As tpe: Expected non nil type"});
		#line 84 f15__ //Expr
		if((typ.kind!=Id412())){
			#line 85 f15__ //Expr
			PrettyPrint104(typ);
		};
		#line 87 f15__ //Expr
		Assert260((typ.kind==Id412()),add64(add64(add64(str53{14,(i8*)"Type mismatch "},String66(typ.kind)),str53{8,(i8*)" is not "}),String66(Id412())));
		#line 88 f15__ //Expr
		return (TypeStructure481*)(&typ);
}
	#line 90 f15__ //Expr
	i8 Is0141(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id403());
}
i8 Is1143(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id404());
}
i8 Is2145(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id407());
}
i8 Is3147(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id411());
}
i8 Is4149(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id409());
}
i8 Is5151(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id408());
}
i8 Is6153(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id406());
}
i8 Is7156(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id410());
}
i8 Is8200(Type413& typ){
		#line 91 f15__ //Expr
		Assert2140((&typ),str53{30,(i8*)"Is type: Expected non nil type"});
		#line 92 f15__ //Expr
		return (typ.kind==Id412());
}
	#line 96 f15__ //Expr
	i32 Id379(){
		#line 97 f15__ //Expr
		return 1;
}
	#line 99 f15__ //Expr
	i32 Id380(){
		#line 100 f15__ //Expr
		return 2;
}
	#line 102 f15__ //Expr
	i32 Id381(){
		#line 103 f15__ //Expr
		return 3;
}
	#line 105 f15__ //Expr
	i32 Id382(){
		#line 106 f15__ //Expr
		return 4;
}
	#line 108 f15__ //Expr
	i32 Id383(){
		#line 109 f15__ //Expr
		return 5;
}
	#line 111 f15__ //Expr
	i32 Id384(){
		#line 112 f15__ //Expr
		return 7;
}
	#line 114 f15__ //Expr
	i32 Id385(){
		#line 115 f15__ //Expr
		return 8;
}
	#line 117 f15__ //Expr
	i32 Id386(){
		#line 118 f15__ //Expr
		return 9;
}
	#line 120 f15__ //Expr
	i32 Id387(){
		#line 121 f15__ //Expr
		return 10;
}
	#line 123 f15__ //Expr
	i32 Id388(){
		#line 124 f15__ //Expr
		return 11;
}
	#line 126 f15__ //Expr
	i32 Id389(){
		#line 127 f15__ //Expr
		return 12;
}
	#line 129 f15__ //Expr
	i32 Id390(){
		#line 130 f15__ //Expr
		return 13;
}
	#line 132 f15__ //Expr
	i32 Id391(){
		#line 133 f15__ //Expr
		return 14;
}
	#line 135 f15__ //Expr
	i32 Id392(){
		#line 136 f15__ //Expr
		return 15;
}
	#line 138 f15__ //Expr
	i32 Id393(){
		#line 139 f15__ //Expr
		return 16;
}
	#line 141 f15__ //Expr
	i32 Id394(){
		#line 142 f15__ //Expr
		return 17;
}
	#line 144 f15__ //Expr
	i32 Id395(){
		#line 145 f15__ //Expr
		return 18;
}
	#line 147 f15__ //Expr
	i32 Id396(){
		#line 148 f15__ //Expr
		return 19;
}
	#line 151 f15__ //Expr
	i32 Id397(){
		#line 152 f15__ //Expr
		return 20;
}
	#line 154 f15__ //Expr
	i32 Id398(){
		#line 155 f15__ //Expr
		return 21;
}
	#line 157 f15__ //Expr
	i32 Id399(){
		#line 158 f15__ //Expr
		return 22;
}
	#line 160 f15__ //Expr
	i32 Id400(){
		#line 161 f15__ //Expr
		return 22;
}
	#line 163 f15__ //Expr
	i32 Id401(){
		#line 164 f15__ //Expr
		return 23;
}
	#line 166 f15__ //Expr
	i32 Id402(){
		#line 167 f15__ //Expr
		return 24;
}
	#line 170 f15__ //Expr
	i32 Id403(){
		#line 171 f15__ //Expr
		return 1;
}
	#line 173 f15__ //Expr
	i32 Id404(){
		#line 174 f15__ //Expr
		return 2;
}
	#line 176 f15__ //Expr
	i32 Id405(){
		#line 177 f15__ //Expr
		return 3;
}
	#line 179 f15__ //Expr
	i32 Id406(){
		#line 180 f15__ //Expr
		return 4;
}
	#line 182 f15__ //Expr
	i32 Id407(){
		#line 183 f15__ //Expr
		return 5;
}
	#line 185 f15__ //Expr
	i32 Id408(){
		#line 186 f15__ //Expr
		return 6;
}
	#line 188 f15__ //Expr
	i32 Id409(){
		#line 189 f15__ //Expr
		return 7;
}
	#line 191 f15__ //Expr
	i32 Id410(){
		#line 192 f15__ //Expr
		return 8;
}
	#line 194 f15__ //Expr
	i32 Id411(){
		#line 195 f15__ //Expr
		return 9;
}
	#line 197 f15__ //Expr
	i32 Id412(){
		#line 198 f15__ //Expr
		return 10;
}
			#line 17 f16__ //Expr
	TypeIdentifier414* TypeIdentifier415(){
		#line 19 f16__ //Expr
		TypeIdentifier414* self=new22207();
		#line 20 f16__ //Expr
		(*self).super.kind = Id404();
		#line 21 f16__ //Expr
		return self;
}
	#line 23 f16__ //Expr
	void Init416(TypeIdentifier414& self){
		#line 24 f16__ //Expr
		self.super.kind = Id404();
}
		#line 32 f16__ //Expr
	TypeFunctions417* TypeFunctions418(){
		#line 34 f16__ //Expr
		TypeFunctions417* self=new27332();
		#line 35 f16__ //Expr
		(*self).super.kind = Id405();
		#line 36 f16__ //Expr
		return self;
}
		#line 43 f16__ //Expr
	void Init420(TypeRef419& self){
		#line 44 f16__ //Expr
		self.super.kind = Id403();
}
		#line 50 f16__ //Expr
	void Init422(TypeOption421& self){
		#line 51 f16__ //Expr
		self.super.kind = Id409();
}
		#line 63 f16__ //Expr
	void Init424(TypeGeneric423& self){
		#line 64 f16__ //Expr
		Init10331(self.constraints);
		#line 65 f16__ //Expr
		self.super.kind = Id406();
}
		#line 77 f16__ //Expr
	void Init426(TypeAny425& self){
		#line 78 f16__ //Expr
		self.super.kind = Id407();
		#line 79 f16__ //Expr
		self.parent = (&self);
}
		#line 86 f16__ //Expr
	void Init428(TypeType427& self){
		#line 87 f16__ //Expr
		self.super.kind = Id408();
}
		#line 96 f16__ //Expr
	void Init430(TypeTrait429& self){
		#line 97 f16__ //Expr
		self.super.kind = Id411();
		#line 98 f16__ //Expr
		self.parent = (&self);
}
	#line 102 f16__ //Expr
	;
	#line 103 f16__ //Expr
	;
	#line 104 f16__ //Expr
	;
		#line 112 f16__ //Expr
	void Init432(TypeNumber431& self){
		#line 113 f16__ //Expr
		self.super.kind = Id410();
}
	#line 116 f16__ //Expr
	TypeNumber431* New433(i8 kind,i64 size){
		#line 117 f16__ //Expr
		TypeNumber431* r=New24334();
		#line 118 f16__ //Expr
		(*r).kind = kind;
		#line 119 f16__ //Expr
		(*r).size = size;
		#line 120 f16__ //Expr
		return r;
}
	#line 124 f16__ //Expr
	;
	#line 125 f16__ //Expr
	;
	#line 126 f16__ //Expr
	;
	#line 127 f16__ //Expr
	;
	#line 129 f16__ //Expr
	;
	#line 130 f16__ //Expr
	;
	#line 131 f16__ //Expr
	;
	#line 132 f16__ //Expr
	;
	#line 134 f16__ //Expr
	;
	#line 135 f16__ //Expr
	;
		#line 15 f17__ //Expr
	void Init435(Block434& self){
		#line 16 f17__ //Expr
		self.super.kind = Id382();
		#line 17 f17__ //Expr
		Init9330(self.expressions);
		#line 18 f17__ //Expr
		Init4337(self.variables);
		#line 19 f17__ //Expr
		Init5340(self.functions);
}
	#line 23 f17__ //Expr
	Block434* Block436(){
		#line 24 f17__ //Expr
		Block434* self=new18102();
		#line 25 f17__ //Expr
		Init435((*self));
		#line 26 f17__ //Expr
		return self;
}
	#line 29 f17__ //Expr
	Expr366* Lookup437(Block434& self,str53 ident){
		#line 31 f17__ //Expr
		return OpArray4343(self.variables,ident);
}
	#line 34 f17__ //Expr
	TypeFunctions417* LookupFns438(Block434& self,str53 ident){
		#line 36 f17__ //Expr
		return OpArray5346(self.functions,ident);
}
	#line 39 f17__ //Expr
	void InsertFn439(Block434& self,str53 ident,Function456* function){
		#line 41 f17__ //Expr
		TypeFunctions417** fns=(&OpArray5346(self.functions,ident));
		#line 42 f17__ //Expr
		TypeFunctions417* funcs=(*fns);
		#line 43 f17__ //Expr
		if((!funcs)){
			#line 45 f17__ //Expr
			funcs = new27332();
			#line 46 f17__ //Expr
			(*fns) = funcs;
		};
		#line 48 f17__ //Expr
		Push14349((*funcs).functions,function);
}
	#line 51 f17__ //Expr
	void Insert440(Block434& self,str53 ident,Expr366* expr){
		#line 53 f17__ //Expr
		if(OpArray4343(self.variables,ident)){
		};
		#line 56 f17__ //Expr
		OpArray4343(self.variables,ident) = expr;
}
	#line 59 f17__ //Expr
	void Add441(Block434& self,Expr366* expr){
		#line 61 f17__ //Expr
		Push288(self.expressions,expr);
}
		#line 15 f18__ //Expr
	Call442* Call443(){
		#line 17 f18__ //Expr
		Call442* self=new20175();
		#line 18 f18__ //Expr
		Init444((*self));
		#line 19 f18__ //Expr
		return self;
}
	#line 22 f18__ //Expr
	void Init444(Call442& self){
		#line 24 f18__ //Expr
		self.super.kind = Id384();
		#line 25 f18__ //Expr
		Init370(self.params);
}
		#line 35 f18__ //Expr
	void Init446(Access445& self){
		#line 36 f18__ //Expr
		self.super.kind = Id392();
}
		#line 22 f19__ //Expr
	void Init448(If447& self){
		#line 24 f19__ //Expr
		self.super.kind = Id386();
}
		#line 39 f19__ //Expr
	For449* For450(){
		#line 41 f19__ //Expr
		For449* self=new868();
		#line 42 f19__ //Expr
		(*self).super.kind = Id387();
		#line 43 f19__ //Expr
		return self;
}
	#line 45 f19__ //Expr
	void Init451(For449& self){
		#line 47 f19__ //Expr
		self.super.kind = Id387();
}
		#line 56 f19__ //Expr
	void Init453(Branch452& self){
		#line 58 f19__ //Expr
		self.super.kind = Id401();
}
		#line 69 f19__ //Expr
	void Init455(Return454& self){
		#line 71 f19__ //Expr
		self.super.kind = Id402();
}
	#line 9 f20__ //Expr
	;
	#line 10 f20__ //Expr
	;
			#line 35 f20__ //Expr
	void Init458(Function456& self){
		#line 37 f20__ //Expr
		self.super.kind = Id379();
		#line 38 f20__ //Expr
		Init370(self.params);
		#line 39 f20__ //Expr
		Init10331(self.any);
}
	#line 44 f20__ //Expr
	Function456* Function459(){
		#line 46 f20__ //Expr
		Function456* self=new29351();
		#line 47 f20__ //Expr
		Init458((*self));
		#line 48 f20__ //Expr
		return self;
}
		#line 63 f20__ //Expr
	void AddAny461(Function456& self,Type413* typ){
		#line 64 f20__ //Expr
		Push137(self.any,typ);
		#line 66 f20__ //Expr
		if(Is2145((*typ))){
			#line 67 f20__ //Expr
			TypeAny425* any=As2146((*typ));
			#line 68 f20__ //Expr
			if(self.block){
				#line 69 f20__ //Expr
				TypeAs367* as=New19165();
				#line 70 f20__ //Expr
				(*as).super.typ = typ;
				#line 71 f20__ //Expr
				(*as).ident = (*any).ident;
				#line 72 f20__ //Expr
				Declare118((*self.block),(*as).super);
			};
		};
		#line 75 f20__ //Expr
		if(Is3147((*typ))){
			#line 76 f20__ //Expr
			TypeTrait429* any=As3148((*typ));
			#line 77 f20__ //Expr
			if(self.block){
				#line 78 f20__ //Expr
				TypeAs367* as=New19165();
				#line 79 f20__ //Expr
				(*as).super.typ = typ;
				#line 80 f20__ //Expr
				(*as).ident = (*(*any).trai).ident;
				#line 81 f20__ //Expr
				Declare118((*self.block),(*as).super);
			};
		};
}
	#line 88 f20__ //Expr
	FunctionSpec460* Specialize462(Function456& self,Semantic110& semantic,Call442* call,Function456* parent,Known470& known){
		#line 90 f20__ //Expr
		return Specialize466(self,semantic,call,parent,known,1);
}
	#line 92 f20__ //Expr
	i8 ContainsUnknown463(Type413& t){
		#line 93 f20__ //Expr
		Type413* typ=(&t);
		#line 94 f20__ //Expr
		if(Is0141((*typ))){
			#line 95 f20__ //Expr
			return ContainsUnknown463((*(*As0142((*typ))).reference));
		};
		#line 97 f20__ //Expr
		if(Is5151((*typ))){
			#line 98 f20__ //Expr
			return ContainsUnknown463((*(*As5152((*typ))).reference));
		};
		#line 100 f20__ //Expr
		if((Is2145((*typ))||Is3147((*typ)))){
			#line 101 f20__ //Expr
			return true;
		};
		#line 103 f20__ //Expr
		if(Is6153((*typ))){
			#line 104 f20__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 105 f20__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 106 f20__ //Expr
				if(ContainsUnknown463((*OpArray6155((*self).constraints,it)))){
					#line 107 f20__ //Expr
					return true;
				};
			};
			#line 110 f20__ //Expr
			return false;
		};
		#line 112 f20__ //Expr
		if(Is1143((*typ))){
			#line 113 f20__ //Expr
			Assert261((!Is20352((*(*As1144((*typ))).spec))));
			#line 114 f20__ //Expr
			if(Is9138((*(*As1144((*typ))).spec))){
				#line 115 f20__ //Expr
				return ContainsUnknown463((*(*As9139((*(*As1144((*typ))).spec))).super.typ));
			};
			#line 117 f20__ //Expr
			if(Is8136((*(*As1144((*typ))).spec))){
				#line 118 f20__ //Expr
				return ContainsUnknown463((*(*As8137((*(*As1144((*typ))).spec))).super.typ));
			};
			#line 121 f20__ //Expr
			return false;
		};
		#line 123 f20__ //Expr
		if(Is7156((*typ))){
			#line 124 f20__ //Expr
			return false;
		};
		#line 126 f20__ //Expr
		Assert261(0);
		#line 127 f20__ //Expr
		return false;
}
	#line 130 f20__ //Expr
	i8 ContainsAny464(Type413& t){
		#line 131 f20__ //Expr
		Type413* typ=(&t);
		#line 132 f20__ //Expr
		if(Is0141((*typ))){
			#line 133 f20__ //Expr
			return ContainsAny464((*(*As0142((*typ))).reference));
		};
		#line 135 f20__ //Expr
		if(Is5151((*typ))){
			#line 136 f20__ //Expr
			return ContainsAny464((*(*As5152((*typ))).reference));
		};
		#line 138 f20__ //Expr
		if((Is2145((*typ))||Is3147((*typ)))){
			#line 139 f20__ //Expr
			Assert260(((i64)(*As2146((*typ))).reference==0),str53{27,(i8*)"found any wither reference?"});
			#line 140 f20__ //Expr
			Assert261(0);
			#line 141 f20__ //Expr
			return true;
		};
		#line 143 f20__ //Expr
		if(Is6153((*typ))){
			#line 144 f20__ //Expr
			TypeGeneric423* self=As6154((*typ));
			#line 145 f20__ //Expr
			for(i64 it = i64265(0); it<(*self).constraints.length;it++){
				#line 146 f20__ //Expr
				if(ContainsAny464((*OpArray6155((*self).constraints,it)))){
					#line 147 f20__ //Expr
					Assert261(0);
					#line 148 f20__ //Expr
					return true;
				};
			};
			#line 151 f20__ //Expr
			return false;
		};
		#line 153 f20__ //Expr
		if(Is1143((*typ))){
			#line 154 f20__ //Expr
			if(Is9138((*(*As1144((*typ))).spec))){
				#line 155 f20__ //Expr
				return ContainsAny464((*(*As9139((*(*As1144((*typ))).spec))).super.typ));
			};
			#line 157 f20__ //Expr
			if(Is8136((*(*As1144((*typ))).spec))){
				#line 158 f20__ //Expr
				return ContainsAny464((*(*As8137((*(*As1144((*typ))).spec))).super.typ));
			};
			#line 160 f20__ //Expr
			return false;
		};
		#line 162 f20__ //Expr
		if(Is7156((*typ))){
			#line 163 f20__ //Expr
			return false;
		};
		#line 165 f20__ //Expr
		Assert261(0);
		#line 166 f20__ //Expr
		return false;
}
	#line 169 f20__ //Expr
	Type413* Parent465(Type413& self){
		#line 170 f20__ //Expr
		if(Is2145(self)){
			#line 171 f20__ //Expr
			return (&(*(*As2146(self)).parent).super);
		};
		#line 173 f20__ //Expr
		if(Is3147(self)){
			#line 174 f20__ //Expr
			return (&(*(*As3148(self)).parent).super);
		};
		#line 176 f20__ //Expr
		Assert261(0);
		#line 177 f20__ //Expr
		return (Type413*)0;
}
	#line 179 f20__ //Expr
	FunctionSpec460* Specialize466(Function456& self,Semantic110& semantic,Call442* call,Function456* parent,Known470& known,i32 level){
		#line 181 f20__ //Expr
		i8 verbose={0};
		#line 184 f20__ //Expr
		for(i64 it = i64265(0); it<self.specializations.length;it++){
			#line 185 f20__ //Expr
			FunctionSpec460* spec=OpArray11230(self.specializations,it);
			#line 186 f20__ //Expr
			if(((*spec).known.length==known.known.length)){
				#line 188 f20__ //Expr
				i64 found=1;
				#line 189 f20__ //Expr
				for(i64 it = i64265(0); it<known.known.length;it++){
					#line 190 f20__ //Expr
					if((!Equal2353(OpArray9179((*spec).known,it).typ,OpArray9179(known.known,it).typ))){
						#line 191 f20__ //Expr
						found = 0;
					};
				};
				#line 194 f20__ //Expr
				if(found){
					#line 195 f20__ //Expr
					Print58(str53{12,(i8*)"FOUADasfsadf"});
					#line 196 f20__ //Expr
					return spec;
				};
			};
		};
		#line 202 f20__ //Expr
		FunctionSpec460* spec=New25354();
		#line 203 f20__ //Expr
		Push15357(self.specializations,spec);
		#line 204 f20__ //Expr
		Push15357(gSpecializations,spec);
		#line 208 f20__ //Expr
		(*spec).function = (&self);
		#line 209 f20__ //Expr
		(*spec).index = self.specializations.length;
		#line 211 f20__ //Expr
		for(i64 it = i64265(0); it<known.known.length;it++){
			#line 212 f20__ //Expr
			TypeAnyResolved472 t=OpArray9179(known.known,it);
		};
		#line 215 f20__ //Expr
		if(verbose){
			#line 216 f20__ //Expr
			if((level==1)){
				#line 217 f20__ //Expr
				Print58(str53{17,(i8*)"Specializing: in "});
				#line 218 f20__ //Expr
				Println59((*parent).ident);
			};
			#line 220 f20__ //Expr
			PrintTabs364(level);
			#line 221 f20__ //Expr
			Print58(self.ident);
			#line 222 f20__ //Expr
			Print58(str53{3,(i8*)" fn"});
			#line 223 f20__ //Expr
			Print96(self.params.super);
			#line 224 f20__ //Expr
			PrintTabs364(1);
		};
		#line 228 f20__ //Expr
		for(i64 it = i64265(0); it<known.known.length;it++){
			#line 229 f20__ //Expr
			TypeAnyResolved472 t=OpArray9179(known.known,it);
			#line 231 f20__ //Expr
			for(i64 it = i64265(0); it<self.any.length;it++){
				#line 233 f20__ //Expr
				Type413* any=OpArray6155(self.any,it);
				#line 234 f20__ //Expr
				if(equal0199(Parent465((*any)),Parent465((*t.any)))){
					#line 236 f20__ //Expr
					TypeAnyResolved472 tt={0};
					#line 237 f20__ //Expr
					tt.any = any;
					#line 238 f20__ //Expr
					tt.typ = Clone133((*t.typ));
					#line 239 f20__ //Expr
					Push16359((*spec).known,tt);
					#line 240 f20__ //Expr
					Annotate125(semantic,(*tt.typ));
					#line 241 f20__ //Expr
					if(ContainsUnknown463((*tt.typ))){
						#line 242 f20__ //Expr
						(*spec).incomplete = true;
					};
				};
			};
		};
		#line 251 f20__ //Expr
		if((!(*spec).incomplete)){
			#line 252 f20__ //Expr
			for(i64 it = i64265(0); it<(*spec).known.length;it++){
				#line 253 f20__ //Expr
				Assert261((!ContainsAny464((*OpArray9179((*spec).known,it).typ))));
			};
		};
		#line 257 f20__ //Expr
		FunctionSpec460* prev=self.spec;
		#line 258 f20__ //Expr
		Apply468((*spec));
		#line 260 f20__ //Expr
		for(i64 it = i64265(0); it<self.params.list.length;it++){
			#line 261 f20__ //Expr
			Type413* typ=Clone133((*(*OpArray4122(self.params.list,it)).typ));
			#line 262 f20__ //Expr
			Push137((*spec).params,typ);
			#line 263 f20__ //Expr
			Annotate125(semantic,(*typ));
		};
		#line 266 f20__ //Expr
		if(prev){
			#line 267 f20__ //Expr
			Apply468((*prev));
		}else{
			#line 270 f20__ //Expr
			Clear469((*spec));
		};
		#line 272 f20__ //Expr
		return spec;
}
	#line 275 f20__ //Expr
	void Init467(FunctionSpec460& self){
		#line 277 f20__ //Expr
		self.super.kind = Id391();
		#line 278 f20__ //Expr
		Init13361(self.known);
}
	#line 281 f20__ //Expr
	void Apply468(FunctionSpec460& self){
		#line 282 f20__ //Expr
		(*self.function).spec = (&self);
		#line 284 f20__ //Expr
		for(i64 it = i64265(0); it<self.known.length;it++){
			#line 285 f20__ //Expr
			TypeAnyResolved472 t=OpArray9179(self.known,it);
			#line 286 f20__ //Expr
			if(Is2145((*t.any))){
				#line 287 f20__ //Expr
				(*As2146((*t.any))).reference = t.typ;
			}else{
				#line 289 f20__ //Expr
				if(Is3147((*t.any))){
					#line 291 f20__ //Expr
					(*As3148((*t.any))).reference = t.typ;
				}else{
					#line 294 f20__ //Expr
					Assert261(0);
				};
			};
		};
}
	#line 300 f20__ //Expr
	void Clear469(FunctionSpec460& self){
		#line 301 f20__ //Expr
		(*self.function).spec = (FunctionSpec460*)0;
		#line 302 f20__ //Expr
		for(i64 it = i64265(0); it<self.known.length;it++){
			#line 303 f20__ //Expr
			TypeAnyResolved472 t=OpArray9179(self.known,it);
			#line 304 f20__ //Expr
			if(Is2145((*t.any))){
				#line 305 f20__ //Expr
				(*As2146((*t.any))).reference = (Type413*)0;
			}else{
				#line 307 f20__ //Expr
				if(Is3147((*t.any))){
					#line 309 f20__ //Expr
					(*As3148((*t.any))).reference = (Type413*)0;
				}else{
					#line 312 f20__ //Expr
					Assert261(0);
				};
			};
		};
}
		#line 321 f20__ //Expr
	i8 Add471(Known470& self,Type413* any,Type413* typ){
		#line 322 f20__ //Expr
		TypeAnyResolved472 t={0};
		#line 323 f20__ //Expr
		t.any = any;
		#line 324 f20__ //Expr
		t.typ = typ;
		#line 325 f20__ //Expr
		for(i64 it = i64265(0); it<self.known.length;it++){
			#line 326 f20__ //Expr
			if(equal0199(Parent465((*OpArray9179(self.known,it).any)),Parent465((*any)))){
				#line 328 f20__ //Expr
				if((!Equal2353(OpArray9179(self.known,it).typ,typ))){
					#line 329 f20__ //Expr
					return false;
				};
			};
		};
		#line 333 f20__ //Expr
		Push16359(self.known,t);
		#line 334 f20__ //Expr
		return true;
}
			#line 32 f21__ //Expr
	;
	#line 35 f21__ //Expr
	void Init474(Structure473& self){
		#line 36 f21__ //Expr
		self.super.kind = Id380();
		#line 37 f21__ //Expr
		Init435(self.block);
		#line 38 f21__ //Expr
		TypeType427* typetype=New348();
		#line 39 f21__ //Expr
		TypeIdentifier414* ident=New22206();
		#line 40 f21__ //Expr
		(*ident).spec = (&self.super);
		#line 41 f21__ //Expr
		(*typetype).reference = (&(*ident).super);
		#line 42 f21__ //Expr
		self.super.typ = (&(*typetype).super);
		#line 43 f21__ //Expr
		self.typeIdent = (&(*ident).super);
		#line 44 f21__ //Expr
		Init482(self.typeStructure);
		#line 45 f21__ //Expr
		self.typeStructure.parent = (&self);
}
	#line 48 f21__ //Expr
	Structure473* Structure475(){
		#line 49 f21__ //Expr
		Structure473* self=new31362();
		#line 50 f21__ //Expr
		Init474((*self));
		#line 51 f21__ //Expr
		return self;
}
	#line 54 f21__ //Expr
	void Add476(Structure473& structure,Variable498* field){
		#line 55 f21__ //Expr
		Push17364(structure.fields,field);
}
	#line 57 f21__ //Expr
	Variable498* Lookup477(Structure473& structure,str53 ident){
		#line 58 f21__ //Expr
		for(i64 it = i64265(0); it<structure.fields.length;it++){
			#line 59 f21__ //Expr
			if(Equal69((*OpArray5125(structure.fields,it)).ident,ident)){
				#line 60 f21__ //Expr
				return OpArray5125(structure.fields,it);
			};
		};
		#line 63 f21__ //Expr
		return (Variable498*)0;
}
	#line 65 f21__ //Expr
	Type413* Lookup478(TypeStructure481& spec,str53 ident){
		#line 66 f21__ //Expr
		for(i64 it = i64265(0); it<spec.fields.length;it++){
			#line 67 f21__ //Expr
			if(Equal69((*OpArray5125((*spec.parent).fields,it)).ident,ident)){
				#line 68 f21__ //Expr
				return OpArray6155(spec.fields,it);
			};
		};
		#line 71 f21__ //Expr
		return (Type413*)0;
}
		#line 80 f21__ //Expr
	void Init480(StructureSpec479& self){
		#line 81 f21__ //Expr
		Init10331(self.constraints);
		#line 82 f21__ //Expr
		self.super.kind = Id395();
}
		#line 92 f21__ //Expr
	void Init482(TypeStructure481& self){
		#line 93 f21__ //Expr
		self.super.kind = Id412();
}
	#line 96 f21__ //Expr
	void ApplyConstraints483(DynamicArray43& anythings,DynamicArray43& constraints){
		#line 98 f21__ //Expr
		Assert260((anythings.length==constraints.length),str53{46,(i8*)"Internal: Expected constraints length to match"});
		#line 100 f21__ //Expr
		for(i64 it = i64265(0); it<anythings.length;it++){
			#line 101 f21__ //Expr
			Type413* any=OpArray6155(anythings,it);
			#line 102 f21__ //Expr
			Type413* constraint=OpArray6155(constraints,it);
			#line 104 f21__ //Expr
			if(Is2145((*any))){
				#line 105 f21__ //Expr
				(*As2146((*any))).reference = constraint;
			}else{
				#line 107 f21__ //Expr
				if(Is3147((*any))){
					#line 108 f21__ //Expr
					(*As3148((*any))).reference = constraint;
				}else{
					#line 111 f21__ //Expr
					Assert260(0,str53{18,(i8*)"Unhandled any type"});
				};
			};
		};
}
	#line 115 f21__ //Expr
	void ClearConstraints484(DynamicArray43& anythings){
		#line 116 f21__ //Expr
		for(i64 it = i64265(0); it<anythings.length;it++){
			#line 117 f21__ //Expr
			Type413* any=OpArray6155(anythings,it);
			#line 119 f21__ //Expr
			if(Is2145((*any))){
				#line 120 f21__ //Expr
				(*As2146((*any))).reference = (Type413*)0;
			}else{
				#line 122 f21__ //Expr
				if(Is3147((*any))){
					#line 123 f21__ //Expr
					(*As3148((*any))).reference = (Type413*)0;
				}else{
					#line 126 f21__ //Expr
					Assert260(0,str53{18,(i8*)"Unhandled any type"});
				};
			};
		};
}
	#line 131 f21__ //Expr
	str53 String0168(DynamicArray43& array){
		#line 132 f21__ //Expr
		str53 r={0};
		#line 133 f21__ //Expr
		for(i64 it = i64265(0); it<array.length;it++){
			#line 134 f21__ //Expr
			r = add64(add64(r,String105(OpArray6155(array,it))),str53{1,(i8*)" "});
		};
		#line 136 f21__ //Expr
		return r;
}
	#line 138 f21__ //Expr
	TypeStructure481* SpecializeStructure486(Semantic110& semantic,TypeStructure481& self,DynamicArray43& constraints){
		#line 141 f21__ //Expr
		Structure473* structure=self.parent;
		#line 143 f21__ //Expr
		for(i64 it = i64265(0); it<(*structure).typeSpecialized.length;it++){
			#line 145 f21__ //Expr
			if(Equal130((*OpArray12231((*structure).typeSpecialized,it)).constraints,constraints)){
				#line 146 f21__ //Expr
				TypeStructure481* spec=OpArray12231((*structure).typeSpecialized,it);
				#line 152 f21__ //Expr
				return spec;
			};
		};
		#line 156 f21__ //Expr
		TypeStructure481* spec=New26366();
		#line 157 f21__ //Expr
		(*spec).parent = self.parent;
		#line 162 f21__ //Expr
		ApplyConstraints483(self.constraints,constraints);
		#line 164 f21__ //Expr
		for(i64 it = i64265(0); it<self.fields.length;it++){
			#line 165 f21__ //Expr
			Type413* any=(Type413*)0;
			#line 166 f21__ //Expr
			Type413* field=CloneAny134((*OpArray6155(self.fields,it)),any);
			#line 167 f21__ //Expr
			Push137((*spec).fields,field);
			#line 168 f21__ //Expr
			if(any){
				#line 169 f21__ //Expr
				(*spec).incomplete = true;
			};
		};
		#line 172 f21__ //Expr
		for(i64 it = i64265(0); it<self.constraints.length;it++){
			#line 173 f21__ //Expr
			Push137((*spec).constraints,Clone133((*OpArray6155(self.constraints,it))));
		};
		#line 176 f21__ //Expr
		ClearConstraints484(self.constraints);
		#line 178 f21__ //Expr
		for(i64 it = i64265(0); it<(*spec).fields.length;it++){
			#line 179 f21__ //Expr
			Type413* field=OpArray6155((*spec).fields,it);
			#line 180 f21__ //Expr
			Annotate125(semantic,(*field));
		};
		#line 183 f21__ //Expr
		Push8171((*structure).typeSpecialized,spec);
		#line 184 f21__ //Expr
		Push8171(structures,spec);
		#line 185 f21__ //Expr
		return spec;
}
	#line 188 f21__ //Expr
	void Apply487(Structure473& self,StructureSpec479& spec){
		#line 189 f21__ //Expr
		self.spec = (&spec);
		#line 190 f21__ //Expr
		for(i64 it = i64265(0); it<self.constraints.length;it++){
			#line 191 f21__ //Expr
			(*As2146((*OpArray6155(self.constraints,it)))).reference = OpArray6155(spec.constraints,it);
			#line 192 f21__ //Expr
			if((!spec.incomplete)){
				#line 193 f21__ //Expr
				Assert261((!ContainsUnknown463((*OpArray6155(spec.constraints,it)))));
			};
		};
}
	#line 198 f21__ //Expr
	void Apply488(StructureSpec479& spec){
		#line 199 f21__ //Expr
		Apply487((*spec.structure),spec);
}
	#line 202 f21__ //Expr
	void Clear489(Structure473& self){
		#line 203 f21__ //Expr
		self.spec = (StructureSpec479*)0;
		#line 204 f21__ //Expr
		for(i64 it = i64265(0); it<self.constraints.length;it++){
			#line 205 f21__ //Expr
			(*As2146((*OpArray6155(self.constraints,it)))).reference = (Type413*)0;
		};
}
		#line 17 f22__ //Expr
	void Init491(Trait490& self){
		#line 19 f22__ //Expr
		self.super.kind = Id388();
		#line 20 f22__ //Expr
		Init430(self.typeTrait);
		#line 21 f22__ //Expr
		self.typeTrait.trai = (&self);
		#line 22 f22__ //Expr
		self.super.typ = (&self.typeTrait.super);
}
	#line 24 f22__ //Expr
	void AddFunction492(Trait490& self,Function456* function){
		#line 25 f22__ //Expr
		Push14349(self.required,function);
}
		#line 36 f22__ //Expr
	void Init494(Require493& self){
		#line 38 f22__ //Expr
		self.super.kind = Id389();
}
		#line 13 f23__ //Expr
	Identifier495* Identifier496(){
		#line 15 f23__ //Expr
		Identifier495* self=new1591();
		#line 16 f23__ //Expr
		Init497((*self));
		#line 17 f23__ //Expr
		return self;
}
	#line 19 f23__ //Expr
	void Init497(Identifier495& self){
		#line 21 f23__ //Expr
		self.super.kind = Id383();
}
		#line 32 f23__ //Expr
	void Init499(Variable498& self){
		#line 34 f23__ //Expr
		self.super.kind = Id381();
}
	#line 36 f23__ //Expr
	Variable498* Variable500(){
		#line 38 f23__ //Expr
		Variable498* self=new21188();
		#line 39 f23__ //Expr
		(*self).super.kind = Id381();
		#line 40 f23__ //Expr
		return self;
}
		#line 51 f23__ //Expr
	void Init502(Assign501& self){
		#line 53 f23__ //Expr
		self.super.kind = Id394();
}
		#line 62 f23__ //Expr
	void Init504(StripRef503& self){
		#line 64 f23__ //Expr
		self.super.kind = Id400();
}
		#line 73 f23__ //Expr
	void Init506(StripOption505& self){
		#line 75 f23__ //Expr
		self.super.kind = Id399();
}
		#line 13 f24__ //Expr
	void Init508(NumberConstant507& self){
		#line 15 f24__ //Expr
		self.super.kind = Id398();
		#line 16 f24__ //Expr
		Init432(self.internalType);
}
		#line 25 f24__ //Expr
	void Init510(StringConstant509& self){
		#line 27 f24__ //Expr
		self.super.kind = Id397();
}
			#line 20 f25__ //Expr
	void Init513(ForList512& self){
		#line 22 f25__ //Expr
		self.super.kind = Id396();
}
			#line 35 f25__ //Expr
	void Init516(ForListSpec515& self){
		#line 36 f25__ //Expr
		self.super.kind = Id520();
}
	#line 39 f25__ //Expr
	void SetIt517(Semantic110& semantic,ForList512& self,Expr366* it){
		#line 41 f25__ //Expr
		(*self.it).super.typ = (*it).typ;
		#line 42 f25__ //Expr
		Visit122(semantic,(*self.block).super);
		#line 43 f25__ //Expr
		Assert0173((*self.it).super.typ);
}
	#line 46 f25__ //Expr
		#line 50 f25__ //Expr
		#line 54 f25__ //Expr
	i32 Id520(){
		#line 55 f25__ //Expr
		return 1;
}
