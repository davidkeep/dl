#include "../dl/Header.h"
struct File;
struct str53;
struct Position76;
struct Token77;
struct DynamicArray10;
struct Lexer78;
struct Type413;
struct Expr366;
struct DynamicArray21;
struct ExpressionList369;
struct TypeAnyResolved472;
struct DynamicArray32;
struct DynamicArray43;
struct FunctionSpec460;
struct DynamicArray54;
struct Function456;
struct tuple1;
struct TableNode16;
struct DynamicArray67;
struct Table15;
struct DynamicArray78;
struct TypeFunctions417;
struct tuple2;
struct TableNode210;
struct DynamicArray811;
struct Table29;
struct Block434;
struct StructureSpec479;
struct Variable498;
struct DynamicArray912;
struct DynamicArray1013;
struct TypeType427;
struct TypeStructure481;
struct DynamicArray1114;
struct Structure473;
struct TypeTrait429;
struct DynamicArray1215;
struct Trait490;
struct Require493;
struct PrintVisitor94;
struct Array116;
struct Intrinsics135;
struct DynamicArray1317;
struct Semantic110;
struct Array218;
struct Known470;
struct GenerateBasic141;
struct Call442;
struct Module155;
struct DynamicArray1419;
struct Project156;
struct DCCallVM;
struct Array320;
struct tuple3;
struct TableNode322;
struct DynamicArray1523;
struct Table321;
struct DebugLocal207;
struct DynamicArray1624;
struct DebugFrame209;
struct tuple4;
struct TableNode426;
struct DynamicArray1727;
struct Table425;
struct DynamicArray1828;
struct Interp181;
struct InterpAddress237;
struct tuple5;
struct TableNode530;
struct DynamicArray1931;
struct Table529;
struct DynamicArray2032;
struct GenerateInterp238;
struct TypeAs367;
struct TypeList372;
struct Identifier495;
struct If447;
struct For449;
struct Access445;
struct Assign501;
struct ForList512;
struct StringConstant509;
struct TypeNumber431;
struct NumberConstant507;
struct StripOption505;
struct StripRef503;
struct Branch452;
struct Return454;
struct TypeRef419;
struct TypeIdentifier414;
struct TypeGeneric423;
struct TypeAny425;
struct TypeOption421;
struct Specialized514;
struct ForListSpec515;
struct TypeInfo75;
struct tuple6;
struct tuple7;
struct tuple8;
struct tuple9;
struct Error0;
struct DynamicArray2133;
struct DynamicArray2234;
struct tuple10;
struct tuple11;
struct tuple12;
struct tuple13;
struct tuple14;
struct tuple15;
struct tuple16;
struct tuple17;
struct tuple18;
struct tuple19;
struct tuple20;
struct tuple21;
struct tuple22;
struct tuple23;
struct tuple24;
struct tuple25;
struct tuple26;
struct tuple27;
struct tuple28;
struct tuple29;
struct tuple30;
struct tuple31;
struct tuple32;
struct tuple33;
struct tuple34;
struct tuple35;
struct tuple36;
struct tuple37;
struct tuple38;
struct tuple39;
struct tuple40;
struct tuple41;
struct tuple42;
struct tuple43;
struct tuple44;
struct tuple45;
struct DynamicArray23116;
struct tuple46;
struct tuple47;
struct tuple48;
struct tuple49;
struct tuple50;
struct tuple51;
struct tuple52;
struct tuple53;
struct tuple54;
struct tuple55;
struct tuple56;
struct tuple57;
struct tuple58;
struct tuple59;
struct tuple60;
struct tuple61;
struct tuple62;
struct tuple63;
struct tuple64;
struct tuple65;
struct tuple66;
struct tuple67;
struct tuple68;
struct tuple69;
struct tuple70;
struct tuple71;
struct tuple72;
struct tuple73;
struct tuple74;
struct tuple75;
struct tuple76;
struct tuple77;
struct tuple78;
struct tuple79;
struct tuple80;
struct tuple81;
struct tuple82;
struct tuple83;
struct tuple84;
struct tuple85;
struct tuple86;
struct tuple87;
struct tuple88;
struct tuple89;
struct tuple90;
struct tuple91;
struct tuple92;
struct tuple93;
struct tuple94;
struct tuple95;
struct tuple96;
struct Array4212;
struct tuple97;
struct tuple98;
struct tuple99;
struct tuple100;
struct tuple101;
struct tuple102;
struct TableNode6221;
struct DynamicArray24222;
struct Table6220;
struct tuple103;
struct tuple104;
struct tuple105;
struct tuple106;
struct tuple107;
struct tuple108;
struct tuple109;
struct Instruction180;
struct tuple110;
struct tuple111;
struct tuple112;
struct tuple113;
struct DynamicArray25248;
struct tuple114;
struct tuple115;
struct tuple116;
struct tuple117;
struct tuple118;
struct tuple119;
struct tuple120;
struct tuple121;
struct tuple122;
struct tuple123;
struct tuple124;
struct tuple125;
struct tuple126;
struct tuple127;
struct tuple128;
struct tuple129;
struct tuple130;
struct tuple131;
struct tuple132;
struct tuple133;
struct tuple134;
struct tuple135;
struct tuple136;
struct tuple137;
struct tuple138;
struct tuple139;
struct tuple140;
struct tuple141;
struct tuple142;
struct i128360;
struct tuple143;
struct tuple144;
struct tuple145;
struct tuple146;
struct tuple147;
struct tuple148;
struct tuple149;
struct TypeFunction457;
struct tuple150;
struct tuple151;
struct tuple152;
struct tuple153;
struct tuple154;
struct tuple155;
struct DynamicArray26369;
struct Specializeable511;
struct str53{
	i64 length;
	i8* chars;
};
struct Position76{
	i32 line;
	i16 column;
	i16 file;
};
struct Token77{
	i32 Type;
	str53 value;
	Position76 at;
};
struct DynamicArray10{
	i64 capacity;
	i64 length;
	Token77* elements;
};
struct Lexer78{
	File* file;
	i32 nextCharacter;
	i32 nextNextCharacter;
	DynamicArray10 tokens;
	i64 at;
	i64 currentLine;
	i64 currentColumn;
	i64 currentFile;
	i64 dataIndex;
	i8* data;
};
struct Type413{
	i32 kind;
};
struct Expr366{
	Position76 at;
	i64 kind;
	Type413* typ;
};
struct DynamicArray21{
	i64 capacity;
	i64 length;
	Expr366** elements;
};
struct ExpressionList369{
	Expr366 super;
	DynamicArray21 list;
};
struct TypeAnyResolved472{
	Type413* any;
	Type413* typ;
};
struct DynamicArray32{
	i64 capacity;
	i64 length;
	TypeAnyResolved472* elements;
};
struct DynamicArray43{
	i64 capacity;
	i64 length;
	Type413** elements;
};
struct FunctionSpec460{
	Expr366 super;
	Function456* function;
	i64 index;
	i8 incomplete;
	DynamicArray32 known;
	DynamicArray43 params;
};
struct DynamicArray54{
	i64 capacity;
	i64 length;
	FunctionSpec460** elements;
};
struct Function456{
	Expr366 super;
	str53 ident;
	Block434* block;
	ExpressionList369 params;
	Type413* result;
	i8 traitFunction;
	FunctionSpec460* spec;
	DynamicArray43 any;
	DynamicArray54 specializations;
};
struct tuple1{
	str53 i0;
	Expr366* i1;
};
struct TableNode16{
	i64 hash;
	str53 key;
	Expr366* value;
};
struct DynamicArray67{
	i64 capacity;
	i64 length;
	TableNode16* elements;
};
struct Table15{
	i64 length;
	i64 capacity;
	DynamicArray67 data;
};
struct DynamicArray78{
	i64 capacity;
	i64 length;
	Function456** elements;
};
struct TypeFunctions417{
	Type413 super;
	DynamicArray78 functions;
};
struct tuple2{
	str53 i0;
	TypeFunctions417* i1;
};
struct TableNode210{
	i64 hash;
	str53 key;
	TypeFunctions417* value;
};
struct DynamicArray811{
	i64 capacity;
	i64 length;
	TableNode210* elements;
};
struct Table29{
	i64 length;
	i64 capacity;
	DynamicArray811 data;
};
struct Block434{
	Expr366 super;
	Function456* parent;
	DynamicArray21 expressions;
	Table15 variables;
	Table29 functions;
	Block434* outer;
};
struct StructureSpec479{
	Expr366 super;
	Structure473* structure;
	i8 incomplete;
	DynamicArray43 constraints;
};
struct Variable498{
	Expr366 super;
	str53 ident;
	Expr366* assign;
	i64 drefCount;
	i8 global;
};
struct DynamicArray912{
	i64 capacity;
	i64 length;
	Variable498** elements;
};
struct DynamicArray1013{
	i64 capacity;
	i64 length;
	StructureSpec479** elements;
};
struct TypeType427{
	Type413 super;
	Type413* reference;
};
struct TypeStructure481{
	Type413 super;
	Structure473* parent;
	DynamicArray43 fields;
	DynamicArray43 constraints;
	i8 incomplete;
};
struct DynamicArray1114{
	i64 capacity;
	i64 length;
	TypeStructure481** elements;
};
struct Structure473{
	Expr366 super;
	str53 ident;
	i8 incomplete;
	StructureSpec479* spec;
	Block434 block;
	DynamicArray912 fields;
	DynamicArray43 constraints;
	DynamicArray1013 specializations;
	Type413* typeIdent;
	TypeType427 typeType;
	TypeStructure481 typeStructure;
	DynamicArray1114 typeSpecialized;
	i32 state;
};
struct TypeTrait429{
	Type413 super;
	TypeTrait429* parent;
	Trait490* trai;
	Type413* reference;
};
struct DynamicArray1215{
	i64 capacity;
	i64 length;
	Structure473** elements;
};
struct Trait490{
	Expr366 super;
	str53 ident;
	TypeTrait429 typeTrait;
	DynamicArray78 required;
	DynamicArray43 constraints;
	DynamicArray1215 implementers;
};
struct Require493{
	Expr366 super;
	str53 typeName;
	str53 traitName;
};
struct PrintVisitor94{
	i32 indent;
};
struct Array116{
	i64 length;
	Function456* elements;
};
struct Intrinsics135{
	Structure473 f32_;
	Structure473 f64_;
	Structure473 bool_;
	Structure473 voidptr_;
	Function456 isEq;
	Function456 notEq;
	Function456 greater;
	Function456 greaterEq;
	Function456 less;
	Function456 lessEq;
	Array116 add;
	Array116 mul;
	Array116 sub;
	Array116 div;
	Array116 mod;
	Function456 fnBegin;
	Function456 ptr_add;
	Function456 abortFn;
	Function456 reference;
	Function456 dereference;
	Function456 castOp;
	Function456 sizeFn;
	Function456 i8_to_i32;
	Function456 i16_to_i32;
	Function456 i64_to_i32;
	Function456 f32_to_i32;
	Function456 f64_to_i32;
	Function456 i8_to_i64;
	Function456 i16_to_i64;
	Function456 i32_to_i64;
	Function456 f32_to_i64;
	Function456 f64_to_i64;
	Function456 i64_to_f32;
	Function456 i64_to_f64;
	Function456 f32_to_f64;
	Function456 f64_to_f32;
	Function456 u32_to_i64;
	Function456 i32_to_u64;
	Function456 to_i8;
	Function456 to_i16;
	Function456 to_i32;
	Function456 to_i64;
	Function456 to_u8;
	Function456 to_u16;
	Function456 to_u32;
	Function456 to_u64;
	Function456 to_f32;
	Function456 add_i64;
	Function456 sub_i64;
	Function456 div_i64;
	Function456 mul_i64;
	Function456 mod_i64;
	Function456 add_i32;
	Function456 sub_i32;
	Function456 div_i32;
	Function456 mul_i32;
	Function456 mod_i32;
	Function456 add_f32;
	Function456 sub_f32;
	Function456 div_f32;
	Function456 mul_f32;
	Function456 mod_f32;
	Function456 invert;
	Function456 and_;
	Function456 or_;
	Array116 to_;
	Function456 fnEnd;
};
struct DynamicArray1317{
	i64 capacity;
	i64 length;
	Block434** elements;
};
struct Semantic110{
	i8 error;
	Intrinsics135 intrinsic;
	DynamicArray1317 scopes;
	DynamicArray1215 structures;
};
struct Array218{
	i64 length;
	i8* elements;
};
struct Known470{
	DynamicArray32 known;
	Array218 drefCount;
};
struct GenerateBasic141{
	Semantic110* semantic;
	File* types;
	File* header;
	File* impl;
	i32 indent;
};
struct Call442{
	Expr366 super;
	Expr366* operand;
	Expr366* func;
	ExpressionList369 params;
	Array218 drefCount;
};
struct Module155{
	str53 path;
};
struct DynamicArray1419{
	i64 capacity;
	i64 length;
	Module155** elements;
};
struct Project156{
	DynamicArray1419 files;
};
struct Array320{
	i64 length;
	i64* elements;
};
struct tuple3{
	str53 i0;
	i64 i1;
};
struct TableNode322{
	i64 hash;
	str53 key;
	i64 value;
};
struct DynamicArray1523{
	i64 capacity;
	i64 length;
	TableNode322* elements;
};
struct Table321{
	i64 length;
	i64 capacity;
	DynamicArray1523 data;
};
struct DebugLocal207{
	Variable498* variable;
	i64 offset;
	i64 instr;
};
struct DynamicArray1624{
	i64 capacity;
	i64 length;
	DebugLocal207** elements;
};
struct DebugFrame209{
	Function456* function;
	DynamicArray1624 locals;
	i64 startInstr;
	i64 endInstr;
};
struct tuple4{
	i64 i0;
	DebugFrame209* i1;
};
struct TableNode426{
	i64 hash;
	i64 key;
	DebugFrame209* value;
};
struct DynamicArray1727{
	i64 capacity;
	i64 length;
	TableNode426* elements;
};
struct Table425{
	i64 length;
	i64 capacity;
	DynamicArray1727 data;
};
struct DynamicArray1828{
	i64 capacity;
	i64 length;
	DebugFrame209** elements;
};
struct Interp181{
	Array320 registers;
	Array218 instructions;
	Array218 stack;
	i64 iPtr;
	i64 rPtr;
	i8* sPtr;
	i8* stackTop;
	i64 frame;
	i64 instructionsSize;
	Table321 labels;
	DCCallVM* cvm;
	voidptr dlhandle;
	Table425 frames;
	DynamicArray1828 frameArray;
};
struct InterpAddress237{
	i64 address;
	i8 global;
};
struct tuple5{
	Expr366* i0;
	InterpAddress237 i1;
};
struct TableNode530{
	i64 hash;
	Expr366* key;
	InterpAddress237 value;
};
struct DynamicArray1931{
	i64 capacity;
	i64 length;
	TableNode530* elements;
};
struct Table529{
	i64 length;
	i64 capacity;
	DynamicArray1931 data;
};
struct DynamicArray2032{
	i64 capacity;
	i64 length;
	i32* elements;
};
struct GenerateInterp238{
	Semantic110* semantic;
	Interp181* interp;
	i64 frameOffset;
	i64 retOffset;
	i64 retDiscardSize;
	Table529 offsets;
	DebugFrame209* currentFrame;
	i32 addressContext;
	DynamicArray2032 context;
	i64 indent;
};
struct TypeAs367{
	Expr366 super;
	str53 ident;
};
struct TypeList372{
	Expr366 super;
	DynamicArray43 list;
};
struct Identifier495{
	Expr366 super;
	str53 ident;
	Expr366* reference;
};
struct If447{
	Expr366 super;
	Expr366* condition;
	Block434* trueBranch;
	If447* falseCondition;
	Block434* falseBranch;
};
struct For449{
	Expr366 super;
	Expr366* from;
	Expr366* to;
	Call442* test;
	Expr366* inc;
	Variable498* it;
	Block434* block;
};
struct Access445{
	Expr366 super;
	Expr366* operand;
	str53 field;
	Call442* call;
};
struct Assign501{
	Expr366 super;
	Expr366* left;
	Expr366* right;
	i32 drefCount;
};
struct ForList512{
	Expr366 super;
	ExpressionList369* list;
	Variable498* it;
	Block434* block;
};
struct StringConstant509{
	Expr366 super;
	str53 value;
};
struct TypeNumber431{
	Type413 super;
	i64 size;
	i8 kind;
	i8 constant;
};
struct NumberConstant507{
	Expr366 super;
	str53 value;
	TypeNumber431 internalType;
};
struct StripOption505{
	Expr366 super;
	Expr366* operand;
};
struct StripRef503{
	Expr366 super;
	Expr366* operand;
};
struct Branch452{
	Expr366 super;
	i32 token;
};
struct Return454{
	Expr366 super;
	Expr366* expr;
	i64 drefCount;
};
struct TypeRef419{
	Type413 super;
	Type413* reference;
};
struct TypeIdentifier414{
	Type413 super;
	str53 ident;
	Expr366* spec;
};
struct TypeGeneric423{
	Type413 super;
	TypeIdentifier414* ident;
	DynamicArray43 constraints;
	Expr366* spec;
	TypeStructure481* referenced;
};
struct TypeAny425{
	Type413 super;
	str53 ident;
	Type413* reference;
	TypeAny425* parent;
	i32 required;
};
struct TypeOption421{
	Type413 super;
	Type413* reference;
};
struct Specialized514{
	i32 kind;
};
struct ForListSpec515{
	Specialized514 super;
	ForList512* parent;
	ExpressionList369* list;
};
struct TypeInfo75{
	u32 size;
};
struct tuple6{
	i64 i0;
	i64 i1;
};
struct tuple7{
	f64 i0;
	f64 i1;
};
struct tuple8{
	f32 i0;
	f32 i1;
};
struct tuple9{
	u64 i0;
	u64 i1;
};
struct Error0{
	str53 message;
	Position76 at;
};
struct DynamicArray2133{
	i64 capacity;
	i64 length;
	Error0* elements;
};
struct DynamicArray2234{
	i64 capacity;
	i64 length;
	str53* elements;
};
struct tuple10{
	DynamicArray2234& i0;
	str53 i1;
};
struct tuple11{
	DynamicArray2234& i0;
	i64 i1;
};
struct tuple12{
	DynamicArray43& i0;
	Type413* i1;
};
struct tuple13{
	DynamicArray43& i0;
	i64 i1;
};
struct tuple14{
	i64 i1;
};
struct tuple15{
	i64 i1;
};
struct tuple16{
	i64 i1;
};
struct tuple17{
	i64 i1;
};
struct tuple18{
	i8* i0;
	str53 i1;
};
struct tuple19{
	i64 i1;
};
struct tuple20{
	i64 i1;
};
struct tuple21{
	i64 i1;
};
struct tuple22{
	Expr366& i0;
};
struct tuple23{
	Expr366* i0;
	str53 i1;
};
struct tuple24{
	i64 i1;
};
struct tuple25{
	i64 i1;
};
struct tuple26{
	i64 i1;
};
struct tuple27{
	i64 i1;
};
struct tuple28{
	i64 i1;
};
struct tuple29{
	i64 i1;
};
struct tuple30{
	i64 i1;
};
struct tuple31{
	i64 i1;
};
struct tuple32{
	DynamicArray21& i0;
	Expr366* i1;
};
struct tuple33{
	DynamicArray21& i0;
	i64 i1;
};
struct tuple34{
	i64 i1;
};
struct tuple35{
	i64 i1;
};
struct tuple36{
	i64 i1;
};
struct tuple37{
	DynamicArray2133& i0;
	Error0 i1;
};
struct tuple38{
	DynamicArray2133& i0;
	i64 i1;
};
struct tuple39{
	i64 i1;
};
struct tuple40{
	DynamicArray1419& i0;
	i64 i1;
};
struct tuple41{
	i64 i1;
};
struct tuple42{
	i8* i0;
	i8* i1;
	i64 i2;
};
struct tuple43{
	Array218& i0;
	i64 i1;
};
struct tuple44{
	DynamicArray10& i0;
	Token77 i1;
};
struct tuple45{
	DynamicArray10& i0;
	i64 i1;
};
struct DynamicArray23116{
	i64 capacity;
	i64 length;
	i8* elements;
};
struct tuple46{
	DynamicArray23116& i0;
	i8 i1;
};
struct tuple47{
	DynamicArray23116& i0;
	i64 i1;
};
struct tuple48{
	Expr366& i0;
};
struct tuple49{
	Expr366& i0;
};
struct tuple50{
	DynamicArray912& i0;
	i64 i1;
};
struct tuple51{
	Expr366& i0;
};
struct tuple52{
	Expr366& i0;
};
struct tuple53{
	Expr366& i0;
};
struct tuple54{
	Expr366& i0;
};
struct tuple55{
	Expr366& i0;
};
struct tuple56{
	Expr366& i0;
};
struct tuple57{
	Expr366& i0;
};
struct tuple58{
	Type413* i0;
	str53 i1;
};
struct tuple59{
	Type413& i0;
};
struct tuple60{
	Type413& i0;
};
struct tuple61{
	Type413& i0;
};
struct tuple62{
	Type413& i0;
};
struct tuple63{
	Type413& i0;
};
struct tuple64{
	Type413& i0;
};
struct tuple65{
	Type413& i0;
};
struct tuple66{
	Type413& i0;
};
struct tuple67{
	DynamicArray1317& i0;
	Block434* i1;
};
struct tuple68{
	DynamicArray1317& i0;
	i64 i1;
};
struct tuple69{
	DynamicArray78& i0;
	i64 i1;
};
struct tuple70{
	Expr366& i0;
};
struct tuple71{
	i64 i1;
};
struct tuple72{
	DynamicArray1215& i0;
	Structure473* i1;
};
struct tuple73{
	DynamicArray1215& i0;
	i64 i1;
};
struct tuple74{
	DynamicArray1114& i0;
	TypeStructure481* i1;
};
struct tuple75{
	DynamicArray1114& i0;
	i64 i1;
};
struct tuple76{
	i64 i1;
};
struct tuple77{
	DynamicArray21& i0;
	i64 i1;
	Expr366* i2;
};
struct tuple78{
	DynamicArray32& i0;
	i64 i1;
};
struct tuple79{
	ExpressionList369* i0;
	str53 i1;
};
struct tuple80{
	Expr366& i0;
};
struct tuple81{
	Expr366& i0;
};
struct tuple82{
	Expr366& i0;
};
struct tuple83{
	i64 i1;
};
struct tuple84{
	Expr366& i0;
};
struct tuple85{
	Expr366& i0;
};
struct tuple86{
	Expr366& i0;
};
struct tuple87{
	Expr366& i0;
};
struct tuple88{
	Expr366& i0;
};
struct tuple89{
	Type413* i0;
	Type413* i1;
};
struct tuple90{
	Type413& i0;
};
struct tuple91{
	TypeStructure481* i0;
	str53 i1;
};
struct tuple92{
	TypeTrait429* i0;
	TypeTrait429* i1;
};
struct tuple93{
	TypeStructure481* i0;
	TypeStructure481* i1;
};
struct tuple94{
	TypeNumber431* i0;
	TypeNumber431* i1;
};
struct tuple95{
	i64 i1;
};
struct tuple96{
	i64 i1;
};
struct Array4212{
	i64 length;
	TypeNumber431** elements;
};
struct tuple97{
	Array4212& i0;
	i64 i1;
};
struct tuple98{
	i64 i1;
};
struct tuple99{
	Array116& i0;
	i64 i1;
};
struct tuple100{
	i64 i1;
};
struct tuple101{
	Function456* i0;
	Function456* i1;
};
struct tuple102{
	str53 i0;
	str53 i1;
};
struct TableNode6221{
	i64 hash;
	str53 key;
	str53 value;
};
struct DynamicArray24222{
	i64 capacity;
	i64 length;
	TableNode6221* elements;
};
struct Table6220{
	i64 length;
	i64 capacity;
	DynamicArray24222 data;
};
struct tuple103{
	Table6220& i0;
	str53 i1;
};
struct tuple104{
	DynamicArray24222& i0;
	i64 i1;
};
struct tuple105{
	DynamicArray54& i0;
	i64 i1;
};
struct tuple106{
	Structure473* i0;
	Structure473* i1;
};
struct tuple107{
	Expr366& i0;
};
struct tuple108{
	i64 i1;
};
struct tuple109{
	DynamicArray1419& i0;
	Module155* i1;
};
struct Instruction180{
	i8 op;
};
struct tuple110{
	Array320& i0;
	i64 i1;
};
struct tuple111{
	i64 i1;
};
struct tuple112{
	DynamicArray1523& i0;
	i64 i1;
};
struct tuple113{
	DynamicArray1727& i0;
	i64 i1;
};
struct DynamicArray25248{
	i64 capacity;
	i64 length;
	i64* elements;
};
struct tuple114{
	DynamicArray25248& i0;
	i64 i1;
};
struct tuple115{
	Table321& i0;
	str53 i1;
};
struct tuple116{
	Interp181& i0;
	i64 i1;
};
struct tuple117{
	Expr366& i0;
};
struct tuple118{
	DebugFrame209* i0;
	str53 i1;
};
struct tuple119{
	DynamicArray1624& i0;
	i64 i1;
};
struct tuple120{
	DynamicArray1828& i0;
	i64 i1;
};
struct tuple121{
	Interp181& i0;
};
struct tuple122{
	Interp181& i0;
};
struct tuple123{
	Interp181& i0;
	i8* i1;
	i64 i2;
};
struct tuple124{
	Interp181& i0;
};
struct tuple125{
	Interp181& i0;
	f32 i1;
};
struct tuple126{
	Interp181& i0;
	f64 i1;
};
struct tuple127{
	Interp181& i0;
};
struct tuple128{
	i64 i1;
};
struct tuple129{
	DynamicArray1624& i0;
	DebugLocal207* i1;
};
struct tuple130{
	Table529& i0;
	Expr366* i1;
};
struct tuple131{
	DynamicArray1931& i0;
	i64 i1;
};
struct tuple132{
	Expr366* i0;
	Expr366* i1;
};
struct tuple133{
	DynamicArray2032& i0;
	i64 i1;
};
struct tuple134{
	i64 i1;
};
struct tuple135{
	Table425& i0;
	i64 i1;
};
struct tuple136{
	DynamicArray1828& i0;
	DebugFrame209* i1;
};
struct tuple137{
	GenerateInterp238& i0;
	i64 i1;
};
struct tuple138{
	GenerateInterp238& i0;
	u64 i1;
};
struct tuple139{
	Interp181& i0;
	u64 i1;
};
struct tuple140{
	GenerateInterp238& i0;
	f32 i1;
};
struct tuple141{
	GenerateInterp238& i0;
	str53 i1;
};
struct tuple142{
	Interp181& i0;
	str53 i1;
};
struct i128360{
	i64 hi;
	i64 lo;
};
struct tuple143{
	i64 i1;
};
struct tuple144{
	i64 i1;
};
struct tuple145{
	DynamicArray67& i0;
	i64 i1;
};
struct tuple146{
	DynamicArray811& i0;
	i64 i1;
};
struct tuple147{
	Table15& i0;
	str53 i1;
};
struct tuple148{
	Table29& i0;
	str53 i1;
};
struct tuple149{
	DynamicArray78& i0;
	Function456* i1;
};
struct TypeFunction457{
	Type413 super;
	ExpressionList369 params;
	Type413* result;
};
struct tuple150{
	i64 i1;
};
struct tuple151{
	DynamicArray54& i0;
	FunctionSpec460* i1;
};
struct tuple152{
	DynamicArray32& i0;
	TypeAnyResolved472 i1;
};
struct tuple153{
	i64 i1;
};
struct tuple154{
	DynamicArray912& i0;
	Variable498* i1;
};
struct tuple155{
	i64 i1;
};
struct DynamicArray26369{
	i64 capacity;
	i64 length;
	Specialized514** elements;
};
struct Specializeable511{
	DynamicArray26369 specializations;
};
Block434* ParseBasicBlock1(Lexer78& lexer);
void ParseDirective2(Lexer78& lexer,Block434& block);
Function456* ParseFunction3(Lexer78& lexer);
Structure473* ParseStructure4(Lexer78& lexer);
void ParseConstraints5(Lexer78& lexer,DynamicArray43& constraints);
Trait490* ParseTrait6(Lexer78& lexer);
Require493* ParseRequire7(Lexer78& lexer);
Type413* ParseOptions8(Lexer78& lexer,Type413* typ);
Type413* ParseType9(Lexer78& lexer);
Variable498* ParseField10(Lexer78& lexer);
Variable498* ParseParameter11(Lexer78& lexer);
Variable498* ParseVariable12(Lexer78& lexer);
Expr366* ParseControl13(Lexer78& lexer);
Expr366* ParseOperand14(Lexer78& lexer,i32 precedence);
i8 IsOperator15(Token77 token);
i32 Precedence16(Token77 token);
Expr366* CreateCall17(str53 ident,Expr366* left,Expr366* right);
Expr366* ParseExpression18(Lexer78& lexer,i32 precedence);
Expr366* ParseExpression19(Lexer78& lexer);
void Error20(str53 message,Position76 at);
Position76 Expect21(Lexer78& lexer,i32 token);
void ExpectEndStatement22(Lexer78& lexer);
void Parse23(Block434* block,str53 file);
Block434* Compile24(str53 file);
void PrintError25(Position76 at,str53 message);
void Run26();
i32 main();
void Init0111(Array218& array,i64 length);
void Init1213(Array4212& array,i64 length);
void Init2216(Array116& array,i64 length);
void Init3239(Array320& array,i64 length);
i8& OpArray0112(Array218& array,i64 index);
TypeNumber431*& OpArray1215(Array4212& array,i64 index);
Function456& OpArray2218(Array116& array,i64 index);
str53& OpArray0105(DynamicArray2234& array,i64 index);
Module155*& OpArray1107(DynamicArray1419& array,i64 index);
Error0& OpArray2108(DynamicArray2133& array,i64 index);
Token77& OpArray3115(DynamicArray10& array,i64 index);
Expr366*& OpArray4122(DynamicArray21& array,i64 index);
Variable498*& OpArray5125(DynamicArray912& array,i64 index);
Type413*& OpArray6155(DynamicArray43& array,i64 index);
Block434*& OpArray7161(DynamicArray1317& array,i64 index);
Function456*& OpArray8163(DynamicArray78& array,i64 index);
TypeAnyResolved472& OpArray9179(DynamicArray32& array,i64 index);
TableNode6221& OpArray10228(DynamicArray24222& array,i64 index);
FunctionSpec460*& OpArray11230(DynamicArray54& array,i64 index);
TypeStructure481*& OpArray12231(DynamicArray1114& array,i64 index);
TableNode322& OpArray13254(DynamicArray1523& array,i64 index);
i64& OpArray14255(DynamicArray25248& array,i64 index);
DebugLocal207*& OpArray15261(DynamicArray1624& array,i64 index);
DebugFrame209*& OpArray16262(DynamicArray1828& array,i64 index);
TableNode530& OpArray17286(DynamicArray1931& array,i64 index);
i32& OpArray18290(DynamicArray2032& array,i64 index);
TableNode426& OpArray19300(DynamicArray1727& array,i64 index);
TableNode16& OpArray20345(DynamicArray67& array,i64 index);
TableNode210& OpArray21348(DynamicArray811& array,i64 index);
void Init0117(DynamicArray23116& array);
void Init1226(DynamicArray24222& array);
void Init2242(DynamicArray1523& array);
void Init3245(DynamicArray1727& array);
void Init4247(DynamicArray1828& array);
void Init5249(DynamicArray25248& array);
void Init6258(DynamicArray1624& array);
void Init7284(DynamicArray1931& array);
void Init8295(DynamicArray2032& array);
void Init9330(DynamicArray21& array);
void Init10331(DynamicArray43& array);
void Init11338(DynamicArray67& array);
void Init12341(DynamicArray811& array);
void Init13361(DynamicArray32& array);
void Insert0177(DynamicArray21& array,i64 index,Expr366* value);
void Push035(DynamicArray2234& array,str53 value);
void Push137(DynamicArray43& array,Type413* value);
void Push288(DynamicArray21& array,Expr366* value);
void Push399(DynamicArray2133& array,Error0 value);
void Push4113(DynamicArray10& array,Token77 value);
void Push5118(DynamicArray23116& array,i8 value);
void Push6158(DynamicArray1317& array,Block434* value);
void Push7169(DynamicArray1215& array,Structure473* value);
void Push8171(DynamicArray1114& array,TypeStructure481* value);
void Push9237(DynamicArray1419& array,Module155* value);
void Push10250(DynamicArray25248& array,i64 value);
void Push11280(DynamicArray1624& array,DebugLocal207* value);
void Push12291(DynamicArray2032& array,i32 value);
void Push13301(DynamicArray1828& array,DebugFrame209* value);
void Push14349(DynamicArray78& array,Function456* value);
void Push15357(DynamicArray54& array,FunctionSpec460* value);
void Push16359(DynamicArray32& array,TypeAnyResolved472 value);
void Push17364(DynamicArray912& array,Variable498* value);
void Reserve036(DynamicArray2234& array,i64 size);
void Reserve138(DynamicArray43& array,i64 size);
void Reserve289(DynamicArray21& array,i64 size);
void Reserve3100(DynamicArray2133& array,i64 size);
void Reserve4114(DynamicArray10& array,i64 size);
void Reserve5119(DynamicArray23116& array,i64 size);
void Reserve6159(DynamicArray1317& array,i64 size);
void Reserve7170(DynamicArray1215& array,i64 size);
void Reserve8172(DynamicArray1114& array,i64 size);
void Reserve9238(DynamicArray1419& array,i64 size);
void Reserve10251(DynamicArray25248& array,i64 size);
void Reserve11281(DynamicArray1624& array,i64 size);
void Reserve12292(DynamicArray2032& array,i64 size);
void Reserve13302(DynamicArray1828& array,i64 size);
void Reserve14350(DynamicArray78& array,i64 size);
void Reserve15358(DynamicArray54& array,i64 size);
void Reserve16360(DynamicArray32& array,i64 size);
void Reserve17365(DynamicArray912& array,i64 size);
void Resize0227(DynamicArray24222& array,i64 size);
void Resize1243(DynamicArray1523& array,i64 size);
void Resize2246(DynamicArray1727& array,i64 size);
void Resize3285(DynamicArray1931& array,i64 size);
void Resize4339(DynamicArray67& array,i64 size);
void Resize5342(DynamicArray811& array,i64 size);
void Pop0106(DynamicArray2234& array);
void Pop1162(DynamicArray1317& array);
void Pop2293(DynamicArray2032& array);
str53& Last0104(DynamicArray2234& array);
Block434*& Last1160(DynamicArray1317& array);
i32& Last2289(DynamicArray2032& array);
void Init0229(Table6220& table);
void Init1241(Table321& table);
void Init2244(Table425& table);
void Init3294(Table529& table);
void Init4337(Table15& table);
void Init5340(Table29& table);
void Resize0225(Table6220& table);
void Resize1253(Table321& table);
void Resize2283(Table529& table);
void Resize3299(Table425& table);
void Resize4344(Table15& table);
void Resize5347(Table29& table);
str53& OpArray0224(Table6220& table,str53 key);
i64& OpArray1252(Table321& table,str53 key);
InterpAddress237& OpArray2282(Table529& table,Expr366* key);
DebugFrame209*& OpArray3298(Table425& table,i64 key);
Expr366*& OpArray4343(Table15& table,str53 key);
TypeFunctions417*& OpArray5346(Table29& table,str53 key);
extern "C" i32 putchar(i32 c);
extern "C" void abort();
extern "C" i32 strlen(i8* string);
extern "C" i32 strcpy(i8* dst,i8* src);
extern "C" i32 dlatoi(i8* src);
extern "C" i64 dlStringToI64(i8* string);
extern "C" f64 dlStringToF64(i8* string);
i32 Char54(str53 char);
i32 i32FromString55(str53 string);
i64 i64FromString56(str53 string);
f64 f64FromString57(str53 string);
void Print58(str53 string);
void Println59(str53 string);
str53 String60(i8* string);
str53 StringFromChar61(i8 char);
void Error62(str53 string);
void Errornl63(str53 string);
str53 add64(str53 a,str53 b);
str53 String65(i8* chars,i64 length);
str53 String66(i64 number);
str53 String67(f32 number);
i64 equal68(str53 l,str53 r);
i64 Equal69(str53 l,str53 r);
i64 Hash70(str53 string);
i8 equal0199(Type413* l,Type413* r);
i8 equal1202(TypeTrait429* l,TypeTrait429* r);
i8 equal2204(TypeStructure481* l,TypeStructure481* r);
i8 equal3219(Function456* l,Function456* r);
i8 equal4232(Structure473* l,Structure473* r);
i64 Equal0205(TypeNumber431* l,TypeNumber431* r);
i64 Equal1288(Expr366* l,Expr366* r);
i64 Equal2353(Type413* l,Type413* r);
i64 Equal73(i64 l,i64 r);
i64 Hash0287(Expr366* p);
i64 Hash75(i64 p);
str53 TokenString79(i32 token);
i8 equal80(Token77 token,i64 kind);
i8 notEqual81(Token77 token,i64 kind);
Lexer78 Lexer82(str53 file,i64 fileNumber);
i32 Peek83(Lexer78& self);
i32 Peek84(Lexer78& self,i64 at);
i32 Get85(Lexer78& self);
extern "C" i32 isspace(i32 v);
extern "C" i32 isalpha(i32 v);
extern "C" i32 isalnum(i32 v);
extern "C" i32 isdigit(i32 v);
Token77 At90(Lexer78& self,i64 i);
void Eat91(Lexer78& self);
void Eat92(Lexer78& self,i64 count);
Token77 Next93(Lexer78& self);
void PrintIndent95(PrintVisitor94& visitor);
void Print96(Expr366& expr);
void Print97(Type413& expr);
void Print98(Type413* expr);
void Visit100(Expr366& expr,PrintVisitor94& visitor);
void Visit101(Type413& t,PrintVisitor94& visitor);
void PrettyPrint102(Type413* expr);
void PrettyPrint103(Expr366& expr);
void PrettyPrint104(Type413& expr);
str53 String105(Type413* expr);
str53 String106(Expr366& expr);
str53 String107(Type413& expr);
void Error108(Expr366& node,str53 message);
void Error109(Position76 at,str53 message);
void Init111(Semantic110& semantic,Block434& ast);
Expr366* FindPrivate112(Semantic110& semantic,str53 ident);
i8 Implements113(Semantic110& semantic,Trait490& trai,Type413& typ);
Expr366* FindType114(Semantic110& semantic,str53 ident,Position76 at);
Expr366* FindVariable115(Semantic110& semantic,str53 ident,Position76 at);
TypeFunctions417* FindMatches116(Semantic110& semantic,Expr366& self,str53 ident,ExpressionList369& args);
Function456* FindMatch117(Semantic110& semantic,Expr366& self,str53 ident,ExpressionList369& args);
void Declare118(Block434& block,Expr366& expr);
void Declare119(Semantic110& semantic,Expr366& expr);
i64 DrefCount120(Type413& desired,Type413& from);
i64 CheckAssignment121(Expr366& self,Type413* desired,Expr366* from);
void Visit122(Semantic110& semantic,Expr366& expr);
Function456* ParentFunction123(Block434* block);
void AnnotateGeneric124(Semantic110& semantic,Type413& t,Function456& spec);
void Annotate125(Semantic110& semantic,Type413& t);
void Annotate126(Semantic110& semantic,Type413& t,i8 reference);
Type413* Resolved127(Type413& typ);
TypeStructure481* ResolveSpec128(Type413& typ);
i8 Apply129(Semantic110& semantic,Type413* argument,Type413* parameter,Known470& known,i64 index);
i8 Equal130(DynamicArray43 left,DynamicArray43 right);
i8 Equal131(Type413* from,Type413* to);
i8 Equal132(Type413* from,Type413* to,i8 allowConversions);
Type413* Clone133(Type413& t);
Type413* CloneAny134(Type413& t,Type413*& any);
void Create136(Intrinsics135& self,Function456& func,Semantic110& semantic,str53 ident,Type413& t,Type413& r);
void Convert137(Intrinsics135& self,Semantic110& semantic,Function456& func,Structure473& from,Structure473& to);
void Init138(Intrinsics135& self,Semantic110& semantic,Block434& ast);
void IsIntrinsic139(Intrinsics135& intrinsics,Structure473* structure);
i8 IsIntrinsic140(Intrinsics135& intrinsics,Function456* function);
void Indent142(GenerateBasic141& self);
str53 Mangle143(Type413* self);
str53 Name144(Structure473& self);
str53 Name145(Function456& self);
str53 Name146(FunctionSpec460& self);
void Init147(GenerateBasic141& generate,Semantic110& semantic,Block434& ast);
void Write148(File& file,str53 s);
void Visit149(File& file,Type413& t);
void Visit150(GenerateBasic141& generate,Expr366& expr);
void PerformVisitAutoReference151(GenerateBasic141& self,Expr366& expr,i64 count);
void PerformReference152(GenerateBasic141& self,Expr366& expr,i64 count);
void PerformDereference153(GenerateBasic141& self,Expr366& expr,i64 count);
void GenerateBasicIntrinsic154(GenerateBasic141& generate,Function456* function,Call442* call);
Module155* ContainsFile157(Project156& self,str53 path);
Module155* AddFile158(Project156& self,str53 path);
void PrintLines159(Project156& self,Position76 position,i64 lines);
extern "C" DCCallVM* dcNewCallVM(u32 size);
extern "C" void dcReset(DCCallVM* vm);
extern "C" void dcArgChar(DCCallVM* vm,i8 value);
extern "C" void dcArgShort(DCCallVM* vm,i16 value);
extern "C" void dcArgInt(DCCallVM* vm,i32 value);
extern "C" void dcArgLong(DCCallVM* vm,i64 value);
extern "C" void dcArgFloat(DCCallVM* vm,f32 value);
extern "C" void dcArgDouble(DCCallVM* vm,f64 value);
extern "C" void dcArgPointer(DCCallVM* vm,voidptr value);
extern "C" void dcCallVoid(DCCallVM* vm,voidptr func);
extern "C" i8 dcCallChar(DCCallVM* vm,voidptr func);
extern "C" i16 dcCallShort(DCCallVM* vm,voidptr func);
extern "C" i32 dcCallInt(DCCallVM* vm,voidptr func);
extern "C" i64 dcCallLong(DCCallVM* vm,voidptr func);
extern "C" f32 dcCallFloat(DCCallVM* vm,voidptr func);
extern "C" f64 dcCallDouble(DCCallVM* vm,voidptr func);
extern "C" voidptr dcCallPointer(DCCallVM* vm,voidptr func);
extern "C" voidptr dlopen(i8* path,i32 mode);
extern "C" voidptr dlsym(voidptr handle,i8* symbol);
void InsertAdd182();
void Init183(Interp181& self);
void PrintInstructions184(Interp181& self);
void Push0267(Interp181& self,i64 value);
void Push1269(Interp181& self,i8 value);
void Push2271(Interp181& self,f32 value);
void Push3272(Interp181& self,i16 value);
void Push4273(Interp181& self,i32 value);
void Push5274(Interp181& self,f64 value);
void Push0265(Interp181& self,i8* from,i64 size);
i64 Pop0266(Interp181& self);
i8 Pop1268(Interp181& self);
f32 Pop2270(Interp181& self);
i16 Pop3275(Interp181& self);
i32 Pop4276(Interp181& self);
f64 Pop5277(Interp181& self);
void StorePtr188(Interp181& self,i8* to,i8* from,i64 size);
void AddLabel189(Interp181& self,str53 name);
i64 GetLabel190(Interp181& self,str53 name);
void AddSpace191(Interp181& self,i8 value);
void AddValue192(Interp181& self,i8 value);
f64* AddValue193(Interp181& self,f64 value);
i64* AddValue0256(Interp181& self,i64 value);
i32* AddValue1307(Interp181& self,i32 value);
i16* AddValue2310(Interp181& self,i16 value);
u64* AddValue3314(Interp181& self,u64 value);
u32* AddValue4317(Interp181& self,u32 value);
u16* AddValue5320(Interp181& self,u16 value);
u8* AddValue6323(Interp181& self,u8 value);
f32* AddValue7326(Interp181& self,f32 value);
str53* AddValue8329(Interp181& self,str53 value);
f64* AddValue195(Interp181& self,f64 value);
void AddLoadConstInstr0257(Interp181& self,i64 value);
void AddLoadConstInstr1304(Interp181& self,i8 value);
void AddLoadConstInstr2306(Interp181& self,i32 value);
void AddLoadConstInstr3309(Interp181& self,i16 value);
void AddLoadConstInstr4313(Interp181& self,u64 value);
void AddLoadConstInstr5316(Interp181& self,u32 value);
void AddLoadConstInstr6319(Interp181& self,u16 value);
void AddLoadConstInstr7322(Interp181& self,u8 value);
void AddLoadConstInstr8325(Interp181& self,f32 value);
void AddLoadConstInstr9328(Interp181& self,str53 value);
void StoreOffsetInstr197(Interp181& self,i64 offset,i64 size);
void AddCall198(Interp181& self,str53 name);
void AddCallExternVoid199(Interp181& self,str53 name);
void AddCallExtern8200(Interp181& self,str53 name);
void AddCallExtern16201(Interp181& self,str53 name);
void AddCallExtern32202(Interp181& self,str53 name);
void AddCallExternf32203(Interp181& self,str53 name);
void AddCallExtern64204(Interp181& self,str53 name);
void AddCallExternPtr205(Interp181& self,str53 name);
void AddExternCallLabel206(Interp181& self,str53 name);
void Init208(DebugLocal207& self,Variable498* variable,i64 offset);
void Init210(DebugFrame209& self,Function456* function);
i8* GetInstr0263(Interp181& self);
i64* GetInstr1264(Interp181& self);
i8* GetInstr213(Interp181& self,i64 size);
i8* PrintType214(Type413* t,i8* location);
void PrintFrame215(Interp181& self,DebugFrame209* frame,i64 current,i64 instrPtr);
DebugFrame209* FrameAt216(Interp181& self,i64 instr);
void PrintFrame217(Interp181& self,i64 frame,i64 instr,i64 returnInstr);
void PrintFrame218(Interp181& self);
void Run219(Interp181& self,str53 label);
void Run220(Interp181& self);
i64 Size221(Type413* t);
i64 Size222(ExpressionList369& expressions);
i64 Size223(Expr366* t);
i64 OffsetOfMemeber224(Structure473& self,str53 field);
void AddVariable225(GenerateInterp238& self,Variable498* variable);
void LoadConst0303(GenerateInterp238& self,i64 value);
void LoadConst1305(GenerateInterp238& self,i32 value);
void LoadConst2308(GenerateInterp238& self,i16 value);
void LoadConst3311(GenerateInterp238& self,i8 value);
void LoadConst4312(GenerateInterp238& self,u64 value);
void LoadConst5315(GenerateInterp238& self,u32 value);
void LoadConst6318(GenerateInterp238& self,u16 value);
void LoadConst7321(GenerateInterp238& self,u8 value);
void LoadConst8324(GenerateInterp238& self,f32 value);
void LoadConst9327(GenerateInterp238& self,str53 value);
void FrameOffset227(GenerateInterp238& self,i64 offset);
void ReserveResult228(GenerateInterp238& self,Type413* typ);
void LoadAddressInstr229(GenerateInterp238& self,i64 size);
void Discard230(GenerateInterp238& self,i64 size);
void LoadAddressFromOffset231(GenerateInterp238& self,i64 offset);
void LoadOffsetInstr232(GenerateInterp238& self,i64 offset,i64 size);
void LoadInstr233(GenerateInterp238& self,i64 address,i64 size);
void Store234(GenerateInterp238& self,i64 size,i64 offset);
void AddOffsetToAddress235(GenerateInterp238& self,i64 offset);
void Print236(GenerateInterp238 self,str53 string);
i32 Context239(GenerateInterp238& self);
void PushContext240(GenerateInterp238& self,i32 context);
void PopContext241(GenerateInterp238& self);
void Init242(GenerateInterp238& generate,Semantic110& semantic,Block434& ast,Interp181& interp);
Structure473* StructureFromType243(Type413& typ);
void Visit244(GenerateInterp238& generate,Expr366& expr);
void PerformVisitAutoReference245(GenerateInterp238& self,Expr366& expr,i64 count);
void PerformReference246(GenerateInterp238& self,Expr366& expr,i64 count);
void PerformDereference247(GenerateInterp238& self,Expr366& expr,i64 count);
i32 PerformCoercion248(GenerateInterp238& generate,Expr366& toExpr,Expr366& fromExpr);
void GenerateBasicIntrinsic249(GenerateInterp238& generate,Function456* function,Call442* call);
extern "C" voidptr malloc(u64 c);
extern "C" voidptr calloc(u64 nmem,u64 size);
extern "C" voidptr realloc(voidptr nmem,u64 size);
extern "C" voidptr memcpy(voidptr dst,voidptr src,u64 count);
extern "C" voidptr memset(voidptr ptr,i32 value,u64 count);
extern "C" void Backtrace();
Trait490* new040();
Require493* new143();
TypeOption421* new246();
TypeType427* new349();
TypeGeneric423* new453();
TypeRef419* new556();
TypeAny425* new659();
ForList512* new764();
For449* new868();
Branch452* new971();
If447* new1074();
Return454* new1177();
NumberConstant507* new1280();
StringConstant509* new1383();
ExpressionList369* new1486();
Identifier495* new1591();
Access445* new1694();
Assign501* new1797();
Block434* new18102();
TypeAs367* new19166();
Call442* new20175();
Variable498* new21188();
TypeIdentifier414* new22207();
TypeTrait429* new23210();
Module155* new24235();
DebugLocal207* new25278();
DebugFrame209* new26296();
TypeFunctions417* new27332();
TypeNumber431* new28335();
Function456* new29351();
FunctionSpec460* new30355();
Structure473* new31362();
TypeStructure481* new32367();
void Assert0173(Type413* condition);
void Assert1178(FunctionSpec460* condition);
void Assert2203(TypeStructure481* condition);
void Assert051(i8* condition,str53 reason);
void Assert162(Expr366* condition,str53 reason);
void Assert2140(Type413* condition,str53 reason);
void Assert3180(ExpressionList369* condition,str53 reason);
void Assert4201(TypeStructure481* condition,str53 reason);
void Assert5260(DebugFrame209* condition,str53 reason);
void Assert260(i8 condition,str53 reason);
void Assert261(i8 condition);
Trait490* Alloc041(i64 len);
Require493* Alloc144(i64 len);
TypeOption421* Alloc247(i64 len);
TypeType427* Alloc350(i64 len);
TypeGeneric423* Alloc454(i64 len);
TypeRef419* Alloc557(i64 len);
TypeAny425* Alloc660(i64 len);
ForList512* Alloc765(i64 len);
For449* Alloc869(i64 len);
Branch452* Alloc972(i64 len);
If447* Alloc1075(i64 len);
Return454* Alloc1178(i64 len);
NumberConstant507* Alloc1281(i64 len);
StringConstant509* Alloc1384(i64 len);
ExpressionList369* Alloc1487(i64 len);
Identifier495* Alloc1592(i64 len);
Access445* Alloc1695(i64 len);
Assign501* Alloc1798(i64 len);
Block434* Alloc18103(i64 len);
i8* Alloc19109(i64 len);
TypeAs367* Alloc20167(i64 len);
Call442* Alloc21176(i64 len);
Variable498* Alloc22189(i64 len);
TypeIdentifier414* Alloc23208(i64 len);
TypeTrait429* Alloc24211(i64 len);
TypeNumber431** Alloc25214(i64 len);
Function456* Alloc26217(i64 len);
Module155* Alloc27236(i64 len);
i64* Alloc28240(i64 len);
DebugLocal207* Alloc29279(i64 len);
DebugFrame209* Alloc30297(i64 len);
TypeFunctions417* Alloc31333(i64 len);
TypeNumber431* Alloc32336(i64 len);
FunctionSpec460* Alloc33356(i64 len);
Structure473* Alloc34363(i64 len);
TypeStructure481* Alloc35368(i64 len);
void CopyPtr0110(i8* from,i8* to,i64 len);
i64 i64265(u8 i);
i64 i64266(u16 i);
i64 i64267(u32 i);
i64 i64268(u64 i);
i64 i64269(i8 i);
i64 i64270(i32 i);
i64 i64271(i64 i);
i64 i64272(f32 i);
i64 i64273(f64 i);
i32 i32274(u8 i);
i32 i32275(u32 i);
i32 i32276(u64 i);
i32 i32277(i8 i);
i32 i32278(i32 i);
i32 i32279(i64 i);
i32 i32280(f32 i);
i32 i32281(f64 i);
i16 i16282(i16 i);
i16 i16283(u32 i);
i16 i16284(u64 i);
i16 i16285(i8 i);
i16 i16286(i32 i);
i16 i16287(i64 i);
i16 i16288(f32 i);
i16 i16289(f64 i);
i8 i8290(u8 i);
i8 i8291(u32 i);
i8 i8292(u64 i);
i8 i8293(i8 i);
i8 i8294(i32 i);
i8 i8295(i64 i);
i8 i8296(f32 i);
i8 i8297(f64 i);
u8 u8298(u8 i);
u8 u8299(u32 i);
u8 u8300(u64 i);
u8 u8301(i8 i);
u8 u8302(i32 i);
u8 u8303(i64 i);
u8 u8304(f32 i);
u8 u8305(f64 i);
u16 u16306(u16 i);
u16 u16307(u32 i);
u16 u16308(u64 i);
u16 u16309(i8 i);
u16 u16310(i32 i);
u16 u16311(i64 i);
u16 u16312(f32 i);
u16 u16313(f64 i);
u32 u32314(u8 i);
u32 u32315(u32 i);
u32 u32316(u64 i);
u32 u32317(i8 i);
u32 u32318(i32 i);
u32 u32319(i64 i);
u32 u32320(f32 i);
u32 u32321(f64 i);
u64 u64322(u8 i);
u64 u64323(u32 i);
u64 u64324(u64 i);
u64 u64325(i8 i);
u64 u64326(i32 i);
u64 u64327(i64 i);
u64 u64328(f32 i);
u64 u64329(f64 i);
f32 f32330(u8 i);
f32 f32331(u32 i);
f32 f32332(u64 i);
f32 f32333(i8 i);
f32 f32334(i32 i);
f32 f32335(i64 i);
f32 f32336(f32 i);
f32 f32337(f64 i);
f64 f64338(u8 i);
f64 f64339(u32 i);
f64 f64340(u64 i);
f64 f64341(i8 i);
f64 f64342(i32 i);
f64 f64343(i64 i);
f64 f64344(f32 i);
f64 f64345(f64 i);
extern "C" File* FileOpen(i8* filename,i8* mode);
extern "C" u32 FileClose(File* file);
extern "C" i8* GetLine(File* stream,i8* data,i32 count);
extern "C" u64 FileRead(i8* f,u64 a,u64 b,File* c);
extern "C" i32 FileGetChar(File* file);
extern "C" u64 FileWrite(voidptr ptr,u64 size,u64 count,File* stream);
extern "C" void FileFlush(File* file);
extern "C" File* FileOut();
extern "C" File* FileError();
extern "C" i32 FilePut(File* file,i8* data);
extern "C" void FlushOut();
extern "C" i32 chdir(i8* dir);
extern "C" i32 dlSystem(i8* cmd);
i32 Convert361(Expr366& desired,Expr366& from,i8 reportError);
i32 Coerce362(Expr366& desired,Expr366& from,i8 reportError);
i32 Coerce363(Type413& desiredType,Expr366& from,i8 reportError);
void PrintTabs364(i32 count);
Trait490* New039();
Require493* New142();
TypeOption421* New245();
TypeType427* New348();
TypeGeneric423* New452();
TypeRef419* New555();
TypeAny425* New658();
ForList512* New763();
For449* New867();
Branch452* New970();
If447* New1073();
Return454* New1176();
NumberConstant507* New1279();
StringConstant509* New1382();
ExpressionList369* New1485();
Identifier495* New1590();
Access445* New1693();
Assign501* New1796();
Block434* New18101();
TypeAs367* New19165();
Call442* New20174();
Variable498* New21187();
TypeIdentifier414* New22206();
TypeTrait429* New23209();
TypeNumber431* New24334();
FunctionSpec460* New25354();
TypeStructure481* New26366();
void Init368(TypeAs367& self);
void Init370(ExpressionList369& self);
void Add371(ExpressionList369& list,Expr366* expr);
void Init373(TypeList372& self);
void Add374(TypeList372& list,Type413* expr);
ExpressionList369* As066(Expr366& expr);
Block434* As1121(Expr366& expr);
Structure473* As2124(Expr366& expr);
Function456* As3127(Expr366& expr);
Identifier495* As4129(Expr366& expr);
Call442* As5131(Expr366& expr);
Access445* As6133(Expr366& expr);
Variable498* As7135(Expr366& expr);
Trait490* As8137(Expr366& expr);
TypeAs367* As9139(Expr366& expr);
NumberConstant507* As10182(Expr366& expr);
StringConstant509* As11184(Expr366& expr);
ForList512* As12186(Expr366& expr);
For449* As13191(Expr366& expr);
Assign501* As14193(Expr366& expr);
If447* As15195(Expr366& expr);
Return454* As16198(Expr366& expr);
FunctionSpec460* As17234(Expr366& expr);
StructureSpec479* As18259(Expr366& expr);
i8 Is061(Expr366& expr);
i8 Is1120(Expr366& expr);
i8 Is2123(Expr366& expr);
i8 Is3126(Expr366& expr);
i8 Is4128(Expr366& expr);
i8 Is5130(Expr366& expr);
i8 Is6132(Expr366& expr);
i8 Is7134(Expr366& expr);
i8 Is8136(Expr366& expr);
i8 Is9138(Expr366& expr);
i8 Is10164(Expr366& expr);
i8 Is11181(Expr366& expr);
i8 Is12183(Expr366& expr);
i8 Is13185(Expr366& expr);
i8 Is14190(Expr366& expr);
i8 Is15192(Expr366& expr);
i8 Is16194(Expr366& expr);
i8 Is17196(Expr366& expr);
i8 Is18197(Expr366& expr);
i8 Is19233(Expr366& expr);
i8 Is20352(Expr366& expr);
TypeRef419* As0142(Type413& typ);
TypeIdentifier414* As1144(Type413& typ);
TypeAny425* As2146(Type413& typ);
TypeTrait429* As3148(Type413& typ);
TypeOption421* As4150(Type413& typ);
TypeType427* As5152(Type413& typ);
TypeGeneric423* As6154(Type413& typ);
TypeNumber431* As7157(Type413& typ);
TypeStructure481* As8223(Type413& typ);
i8 Is0141(Type413& typ);
i8 Is1143(Type413& typ);
i8 Is2145(Type413& typ);
i8 Is3147(Type413& typ);
i8 Is4149(Type413& typ);
i8 Is5151(Type413& typ);
i8 Is6153(Type413& typ);
i8 Is7156(Type413& typ);
i8 Is8200(Type413& typ);
i32 Id379();
i32 Id380();
i32 Id381();
i32 Id382();
i32 Id383();
i32 Id384();
i32 Id385();
i32 Id386();
i32 Id387();
i32 Id388();
i32 Id389();
i32 Id390();
i32 Id391();
i32 Id392();
i32 Id393();
i32 Id394();
i32 Id395();
i32 Id396();
i32 Id397();
i32 Id398();
i32 Id399();
i32 Id400();
i32 Id401();
i32 Id402();
i32 Id403();
i32 Id404();
i32 Id405();
i32 Id406();
i32 Id407();
i32 Id408();
i32 Id409();
i32 Id410();
i32 Id411();
i32 Id412();
TypeIdentifier414* TypeIdentifier415();
void Init416(TypeIdentifier414& self);
TypeFunctions417* TypeFunctions418();
void Init420(TypeRef419& self);
void Init422(TypeOption421& self);
void Init424(TypeGeneric423& self);
void Init426(TypeAny425& self);
void Init428(TypeType427& self);
void Init430(TypeTrait429& self);
void Init432(TypeNumber431& self);
TypeNumber431* New433(i8 kind,i64 size);
void Init435(Block434& self);
Block434* Block436();
Expr366* Lookup437(Block434& self,str53 ident);
TypeFunctions417* LookupFns438(Block434& self,str53 ident);
void InsertFn439(Block434& self,str53 ident,Function456* function);
void Insert440(Block434& self,str53 ident,Expr366* expr);
void Add441(Block434& self,Expr366* expr);
Call442* Call443();
void Init444(Call442& self);
void Init446(Access445& self);
void Init448(If447& self);
For449* For450();
void Init451(For449& self);
void Init453(Branch452& self);
void Init455(Return454& self);
void Init458(Function456& self);
Function456* Function459();
void AddAny461(Function456& self,Type413* typ);
FunctionSpec460* Specialize462(Function456& self,Semantic110& semantic,Call442* call,Function456* parent,Known470& known);
i8 ContainsUnknown463(Type413& t);
i8 ContainsAny464(Type413& t);
Type413* Parent465(Type413& self);
FunctionSpec460* Specialize466(Function456& self,Semantic110& semantic,Call442* call,Function456* parent,Known470& known,i32 level);
void Init467(FunctionSpec460& self);
void Apply468(FunctionSpec460& self);
void Clear469(FunctionSpec460& self);
i8 Add471(Known470& self,Type413* any,Type413* typ);
void Init474(Structure473& self);
Structure473* Structure475();
void Add476(Structure473& structure,Variable498* field);
Variable498* Lookup477(Structure473& structure,str53 ident);
Type413* Lookup478(TypeStructure481& spec,str53 ident);
void Init480(StructureSpec479& self);
void Init482(TypeStructure481& self);
void ApplyConstraints483(DynamicArray43& anythings,DynamicArray43& constraints);
void ClearConstraints484(DynamicArray43& anythings);
str53 String0168(DynamicArray43& array);
TypeStructure481* SpecializeStructure486(Semantic110& semantic,TypeStructure481& self,DynamicArray43& constraints);
void Apply487(Structure473& self,StructureSpec479& spec);
void Apply488(StructureSpec479& spec);
void Clear489(Structure473& self);
void Init491(Trait490& self);
void AddFunction492(Trait490& self,Function456* function);
void Init494(Require493& self);
Identifier495* Identifier496();
void Init497(Identifier495& self);
void Init499(Variable498& self);
Variable498* Variable500();
void Init502(Assign501& self);
void Init504(StripRef503& self);
void Init506(StripOption505& self);
void Init508(NumberConstant507& self);
void Init510(StringConstant509& self);
void Init513(ForList512& self);
void Init516(ForListSpec515& self);
void SetIt517(Semantic110& semantic,ForList512& self,Expr366* it);
i32 Id520();
