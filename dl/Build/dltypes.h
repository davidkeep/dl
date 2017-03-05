#include "header.h"
struct GLFWWindow;
struct FileHandle;
struct Str;
struct Position;
struct Error;
struct GenerateBasic;
struct Expr;
struct Array__ref_Expr;
struct TableNode_Str_ref_Expr;
struct Array_TableNode_Str_ref_Expr;
struct Table_Str_ref_Expr;
struct TableNode_Str_ref_TypeFunctions;
struct Array_TableNode_Str_ref_TypeFunctions;
struct Table_Str_ref_TypeFunctions;
struct Block;
struct Array__ref_Variable;
struct Array__ref_Type;
struct Type;
struct TypeType;
struct TypeStructure;
struct Array__ref_TypeStructure;
struct Structure;
struct ExpressionList;
struct Array__ref_FunctionSpec;
struct Function;
struct Array_Function;
struct Intrinsics;
struct Array__ref_Block;
struct Array__ref_Structure;
struct Semantic;
struct PrintVisitor;
struct Module;
struct Array__ref_Module;
struct Project;
struct TypeIdentifier;
struct Array__ref_Function;
struct TypeFunctions;
struct TypeRef;
struct TypeOption;
struct TypeGeneric;
struct TypeAny;
struct TypeTrait;
struct TypeNumber;
struct Array_i8;
struct Call;
struct Access;
struct NumberConstant;
struct StringConstant;
struct If;
struct For;
struct ForList;
struct Branch;
struct Return;
struct TypeAnyResolved;
struct Array_TypeAnyResolved;
struct FunctionSpec;
struct Known;
struct Trait;
struct Identifier;
struct Variable;
struct Assign;
struct TypeAs;
struct Token;
struct Array_Token;
struct Lexer;
struct Nil;
struct Array_Error;
struct Array_Str;
struct TableNode_StrStr;
struct Array_TableNode_StrStr;
struct Table_StrStr;
struct Array__ref_TypeNumber;
struct GLFWWindow {
};
struct FileHandle {
};
struct Str {
i64 length;
i8* chars;
};
struct Position {
i32 line;
i16 column;
i16 file;
};
struct Error {
Str message;
Position at;
};
struct GenerateBasic {
Semantic* semantic;
FileHandle* types;
FileHandle* header;
FileHandle* impl;
i32 indent;
};
struct Expr {
Position at;
i64 kind;
Type* typ;
};
struct Array__ref_Expr {
i64 length;
i64 capacity;
Expr** elements;
};
/*struct <inc>TableNode_<inc><TypeAny><TypeAny> {
i64 hash;
unknown type - 5 key;
unknown type - 5 value;
};
*//*struct <inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>TableNode_<inc><TypeAny><TypeAny>* elements;
};
*/struct TableNode_Str_ref_Expr {
i64 hash;
Str key;
Expr* value;
};
struct Array_TableNode_Str_ref_Expr {
i64 length;
i64 capacity;
TableNode_Str_ref_Expr* elements;
};
struct Table_Str_ref_Expr {
i64 length;
i64 capacity;
Array_TableNode_Str_ref_Expr data;
};
struct TableNode_Str_ref_TypeFunctions {
i64 hash;
Str key;
TypeFunctions* value;
};
struct Array_TableNode_Str_ref_TypeFunctions {
i64 length;
i64 capacity;
TableNode_Str_ref_TypeFunctions* elements;
};
struct Table_Str_ref_TypeFunctions {
i64 length;
i64 capacity;
Array_TableNode_Str_ref_TypeFunctions data;
};
struct Block {
Expr super;
Function* parent;
Array__ref_Expr expressions;
Table_Str_ref_Expr variables;
Table_Str_ref_TypeFunctions functions;
Block* outer;
};
struct Array__ref_Variable {
i64 length;
i64 capacity;
Variable** elements;
};
struct Array__ref_Type {
i64 length;
i64 capacity;
Type** elements;
};
struct Type {
i32 kind;
};
struct TypeType {
Type super;
Type* reference;
};
struct TypeStructure {
Type super;
Structure* parent;
Array__ref_Type fields;
Array__ref_Type constraints;
i8 incomplete;
};
struct Array__ref_TypeStructure {
i64 length;
i64 capacity;
TypeStructure** elements;
};
struct Structure {
Expr super;
Str ident;
i8 incomplete;
Block block;
Array__ref_Variable fields;
Array__ref_Type constraints;
Type* typeIdent;
TypeType typeType;
TypeStructure typeStructure;
Array__ref_TypeStructure typeSpecialized;
i32 state;
};
struct ExpressionList {
Expr super;
Array__ref_Expr list;
};
struct Array__ref_FunctionSpec {
i64 length;
i64 capacity;
FunctionSpec** elements;
};
struct Function {
Expr super;
Str ident;
Block* block;
ExpressionList params;
Type* result;
i8 traitFunction;
FunctionSpec* spec;
Array__ref_Type any;
Array__ref_FunctionSpec specializations;
};
struct Array_Function {
i64 length;
i64 capacity;
Function* elements;
};
struct Intrinsics {
Structure f32_;
Structure f64_;
Structure bool_;
Structure voidptr_;
Function isEq;
Function notEq;
Function greater;
Function greaterEq;
Function less;
Function lessEq;
Array_Function add;
Array_Function mul;
Array_Function sub;
Array_Function div;
Array_Function mod;
Function fnBegin;
Function ptr_add;
Function abortFn;
Function reference;
Function dereference;
Function castOp;
Function sizeFn;
Function i8_to_i32;
Function i16_to_i32;
Function i64_to_i32;
Function f32_to_i32;
Function f64_to_i32;
Function i8_to_i64;
Function i16_to_i64;
Function i32_to_i64;
Function f32_to_i64;
Function f64_to_i64;
Function i64_to_f32;
Function i64_to_f64;
Function f32_to_f64;
Function f64_to_f32;
Function u32_to_i64;
Function i32_to_u64;
Function to_i8;
Function to_i16;
Function to_i32;
Function to_i64;
Function to_u8;
Function to_u16;
Function to_u32;
Function to_u64;
Function to_f32;
Function add_i64;
Function sub_i64;
Function div_i64;
Function mul_i64;
Function mod_i64;
Function add_i32;
Function sub_i32;
Function div_i32;
Function mul_i32;
Function mod_i32;
Function add_f32;
Function sub_f32;
Function div_f32;
Function mul_f32;
Function mod_f32;
Function invert;
Function and_;
Function or_;
Array_Function to_;
Function fnEnd;
};
struct Array__ref_Block {
i64 length;
i64 capacity;
Block** elements;
};
struct Array__ref_Structure {
i64 length;
i64 capacity;
Structure** elements;
};
struct Semantic {
i8 error;
Intrinsics intrinsic;
Array__ref_Block scopes;
Array__ref_Structure structures;
};
struct PrintVisitor {
i32 indent;
};
struct Module {
Str path;
};
struct Array__ref_Module {
i64 length;
i64 capacity;
Module** elements;
};
struct Project {
Array__ref_Module files;
};
struct TypeIdentifier {
Type super;
Str ident;
Expr* spec;
};
struct Array__ref_Function {
i64 length;
i64 capacity;
Function** elements;
};
struct TypeFunctions {
Type super;
Array__ref_Function functions;
};
struct TypeRef {
Type super;
Type* reference;
};
struct TypeOption {
Type super;
Type* reference;
};
struct TypeGeneric {
Type super;
TypeIdentifier* ident;
Array__ref_Type constraints;
Expr* spec;
TypeStructure* referenced;
};
struct TypeAny {
Type super;
Str ident;
Type* reference;
TypeAny* parent;
i32 required;
};
struct TypeTrait {
Type super;
Trait* trai;
TypeTrait* parent;
Type* reference;
};
struct TypeNumber {
Type super;
i64 size;
i8 kind;
i8 constant;
Str ident;
};
struct Array_i8 {
i64 length;
i64 capacity;
i8* elements;
};
struct Call {
Expr super;
Expr* operand;
Expr* func;
ExpressionList params;
Array_i8 drefCount;
};
struct Access {
Expr super;
Expr* operand;
Str field;
Call* call;
};
struct NumberConstant {
Expr super;
Str value;
TypeNumber internalType;
};
struct StringConstant {
Expr super;
Str value;
};
struct If {
Expr super;
Expr* condition;
Block* trueBranch;
If* falseCondition;
Block* falseBranch;
};
struct For {
Expr super;
Expr* from;
Expr* to;
Call* test;
Expr* inc;
Variable* it;
Block* block;
};
struct ForList {
Expr super;
ExpressionList* list;
Variable* it;
Block* block;
};
struct Branch {
Expr super;
i32 token;
};
struct Return {
Expr super;
Expr* expr;
i64 drefCount;
};
struct TypeAnyResolved {
Type* any;
Type* typ;
};
struct Array_TypeAnyResolved {
i64 length;
i64 capacity;
TypeAnyResolved* elements;
};
struct FunctionSpec {
Expr super;
Function* function;
i64 index;
i8 incomplete;
Array_TypeAnyResolved known;
Array__ref_Type params;
};
struct Known {
Array_TypeAnyResolved known;
Array_i8 drefCount;
};
struct Trait {
Expr super;
Str ident;
TypeTrait typeTrait;
Array__ref_Function required;
Array__ref_Type constraints;
Array__ref_Structure implementers;
};
struct Identifier {
Expr super;
Str ident;
Expr* reference;
};
struct Variable {
Expr super;
Str ident;
Expr* assign;
i8 global;
i64 drefCount;
};
struct Assign {
Expr super;
Expr* left;
Expr* right;
i32 drefCount;
};
struct TypeAs {
Expr super;
Str ident;
};
struct Token {
i32 Type;
Str value;
Position at;
};
struct Array_Token {
i64 length;
i64 capacity;
Token* elements;
};
struct Lexer {
FileHandle* file;
i32 nextCharacter;
i32 nextNextCharacter;
Array_Token tokens;
i64 at;
i64 currentLine;
i64 currentColumn;
i64 currentFile;
i64 dataIndex;
i8* data;
};
struct Nil {
};
/*struct <inc>Array_<inc><typeTrait> {
i64 length;
i64 capacity;
unknown type - 9* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>Array_<inc><TypeAny> {
i64 length;
i64 capacity;
unknown type - 5* elements;
};
*//*struct <inc>TableNode_<inc><TypeAny><TypeAny> {
i64 hash;
unknown type - 5 key;
unknown type - 5 value;
};
*//*struct <inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>TableNode_<inc><TypeAny><TypeAny>* elements;
};
*//*struct <inc>Table_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> data;
};
*//*struct <inc>TableNode_<inc><TypeAny><TypeAny> {
i64 hash;
unknown type - 5 key;
unknown type - 5 value;
};
*//*struct <inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>TableNode_<inc><TypeAny><TypeAny>* elements;
};
*//*struct <inc>Table_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> data;
};
*//*struct <inc>TableNode_<inc><TypeAny><TypeAny> {
i64 hash;
unknown type - 5 key;
unknown type - 5 value;
};
*//*struct <inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>TableNode_<inc><TypeAny><TypeAny>* elements;
};
*//*struct <inc>Table_<inc><TypeAny><TypeAny> {
i64 length;
i64 capacity;
<inc>Array_<inc><inc>TableNode_<inc><TypeAny><TypeAny> data;
};
*/struct Array_Error {
i64 length;
i64 capacity;
Error* elements;
};
struct Array_Str {
i64 length;
i64 capacity;
Str* elements;
};
struct TableNode_StrStr {
i64 hash;
Str key;
Str value;
};
struct Array_TableNode_StrStr {
i64 length;
i64 capacity;
TableNode_StrStr* elements;
};
struct Table_StrStr {
i64 length;
i64 capacity;
Array_TableNode_StrStr data;
};
struct Array__ref_TypeNumber {
i64 length;
i64 capacity;
TypeNumber** elements;
};
