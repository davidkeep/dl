#include "dl.h"
Array_Error errors={0};
Project project={0};
Array_Str filesToParse={0};
Str directory=((Str){7, (i8*)"../dl2/"});
Table_StrStr remapped={0};
i32 Declared=0;
i32 Visiting=1;
i32 Visited=2;
i8 TypeNumberInteger=0;
i8 TypeNumberUnsigned=1;
i8 TypeNumberFloat=2;
TypeNumber* i64Type=New__typeofTypeNumberi8i64Str(TypeNumberInteger,8,((Str){3, (i8*)"i64"}));
TypeNumber* i32Type=New__typeofTypeNumberi8i64Str(TypeNumberInteger,4,((Str){3, (i8*)"i32"}));
TypeNumber* i16Type=New__typeofTypeNumberi8i64Str(TypeNumberInteger,2,((Str){3, (i8*)"i16"}));
TypeNumber* i8Type=New__typeofTypeNumberi8i64Str(TypeNumberInteger,1,((Str){2, (i8*)"i8"}));
TypeNumber* u64Type=New__typeofTypeNumberi8i64Str(TypeNumberUnsigned,8,((Str){3, (i8*)"u64"}));
TypeNumber* u32Type=New__typeofTypeNumberi8i64Str(TypeNumberUnsigned,4,((Str){3, (i8*)"u32"}));
TypeNumber* u16Type=New__typeofTypeNumberi8i64Str(TypeNumberUnsigned,2,((Str){3, (i8*)"u16"}));
TypeNumber* u8Type=New__typeofTypeNumberi8i64Str(TypeNumberUnsigned,1,((Str){2, (i8*)"u8"}));
TypeNumber* f32Type=New__typeofTypeNumberi8i64Str(TypeNumberFloat,4,((Str){3, (i8*)"f32"}));
TypeNumber* f64Type=New__typeofTypeNumberi8i64Str(TypeNumberFloat,8,((Str){3, (i8*)"f64"}));
Array__ref_FunctionSpec gSpecializations={0};
Array__ref_TypeStructure structures={0};
i32 kParenOpen=Char_Str(((Str){1, (i8*)"("}));
i32 kParenClose=Char_Str(((Str){1, (i8*)")"}));
i32 kBracketOpen=Char_Str(((Str){1, (i8*)"{"}));
i32 kBracketClose=Char_Str(((Str){1, (i8*)"}"}));
i32 kBraceOpen=Char_Str(((Str){1, (i8*)"["}));
i32 kBraceClose=Char_Str(((Str){1, (i8*)"]"}));
i32 kPlus=Char_Str(((Str){1, (i8*)"+"}));
i32 kMinus=Char_Str(((Str){1, (i8*)"-"}));
i32 kDivide=Char_Str(((Str){1, (i8*)"/"}));
i32 kMultiply=Char_Str(((Str){1, (i8*)"*"}));
i32 kMod=Char_Str(((Str){1, (i8*)"%"}));
i32 kEqual=Char_Str(((Str){1, (i8*)"="}));
i32 kNot=Char_Str(((Str){1, (i8*)"!"}));
i32 kGreater=Char_Str(((Str){1, (i8*)">"}));
i32 kLess=Char_Str(((Str){1, (i8*)"<"}));
i32 kComma=Char_Str(((Str){1, (i8*)","}));
i32 kDot=Char_Str(((Str){1, (i8*)"."}));
i32 kCaret=Char_Str(((Str){1, (i8*)"^"}));
i32 kDollar=Char_Str(((Str){1, (i8*)"$"}));
i32 kOption=Char_Str(((Str){1, (i8*)"?"}));
i32 kAnd=Char_Str(((Str){1, (i8*)"&"}));
i32 kOr=Char_Str(((Str){1, (i8*)"|"}));
i32 kAt=Char_Str(((Str){1, (i8*)"@"}));
i32 kEnd=0;
i32 kSemicolon=(0-25);
i32 kEndLine=(0-26);
i32 kKeywordsBegin=(0-100);
i32 kStruct=(kKeywordsBegin+1);
i32 kFunction=(kKeywordsBegin+2);
i32 kRef=(kKeywordsBegin+3);
i32 kTrait=(kKeywordsBegin+5);
i32 kRequire=(kKeywordsBegin+6);
i32 kFor=(kKeywordsBegin+7);
i32 kBreak=(kKeywordsBegin+8);
i32 kContinue=(kKeywordsBegin+9);
i32 kIf=(kKeywordsBegin+10);
i32 kElse=(kKeywordsBegin+11);
i32 kReturn=(kKeywordsBegin+12);
i32 kKeywordsEnd=(0-50);
i32 kIdentifier=(0-20);
i32 kString=(0-21);
i32 kNumber=(0-22);
i8 false=0;
i8 true=1;
void Error_StrPosition(Str message, Position at){
	Error error={0};
	error.message=message;
	error.at=at;
	Push_ref_Array_ErrorError1((&errors),error);
	PrintError_PositionStr(error.at,message);
	abort();
}
Position Expect__ref_Lexeri32(Lexer* lexer, i32 token){
	Position at=At__ref_Lexeri64(lexer,0).at;
	if(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),token))	{
		Error_StrPosition(_add__StrStr(_add__StrStr(_add__StrStr(_add__StrStr(_add__StrStr(((Str){9, (i8*)"Expected "}),TokenString_i32(token)),((Str){8, (i8*)"  found "})),TokenString_i32(At__ref_Lexeri64(lexer,0).Type)),((Str){1, (i8*)" "})),TokenString_i32(At__ref_Lexeri64(lexer,1).Type)),At__ref_Lexeri64(lexer,0).at);
	};
	Eat__ref_Lexeri64(lexer,1);
	return at;
}
void ExpectEndStatement__ref_Lexer(Lexer* lexer){
	if((((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kComma)||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kParenClose))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketClose))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen)))	{
		return ;
	};
	if((_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kSemicolon)&&_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kEndLine)))	{
		Error_StrPosition(_add__StrStr(_add__StrStr(_add__StrStr(((Str){17, (i8*)"Expected ; found "}),TokenString_i32(At__ref_Lexeri64(lexer,0).Type)),((Str){1, (i8*)" "})),String_i64(At__ref_Lexeri64(lexer,(0-1)).Type)),At__ref_Lexeri64(lexer,0).at);
	};
	Eat__ref_Lexeri64(lexer,1);
}
Block* ParseBasicBlock__ref_Lexer(Lexer* lexer){
	Expect__ref_Lexeri32(lexer,kBracketOpen);
	Block* block=New_typeofBlock1();
	while(true)	{
		Expr* expr={0};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=(&(*ParseVariable__ref_Lexer(lexer)).super);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=ParseExpression__ref_Lexer(lexer);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=ParseControl__ref_Lexer(lexer);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen))			{
				expr=(&(*ParseBasicBlock__ref_Lexer(lexer)).super);
			};
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			Expect__ref_Lexeri32(lexer,kBracketClose);
			return block;
		};
		Add__ref_Block_ref_Expr(block,expr);
	};
	return block;
}
void ParseDirective__ref_Lexer_ref_Block(Lexer* lexer, Block* block){
	while(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kAt))	{
		Eat__ref_Lexeri64(lexer,1);
		if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier))		{
			if(_eq__StrStr(At__ref_Lexeri64(lexer,0).value,((Str){6, (i8*)"extern"})))			{
				Eat__ref_Lexeri64(lexer,1);
				Expect__ref_Lexeri32(lexer,kBracketOpen);
				while(true)				{
					Expr* expr={0};
					expr=(&(*ParseFunction__ref_Lexer(lexer)).super);
					if(_notEq__ref_Expr_typeofNil1(expr))					{
						Add__ref_Block_ref_Expr(block,expr);
					}else					{
						Expect__ref_Lexeri32(lexer,kBracketClose);
						return ;
					};
				};
			}else if(_eq__StrStr(At__ref_Lexeri64(lexer,0).value,((Str){6, (i8*)"import"})))			{
				Eat__ref_Lexeri64(lexer,1);
				Expect__ref_Lexeri32(lexer,kBracketOpen);
				while(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kString))				{
					if((At__ref_Lexeri64(lexer,0).value.length==0))					{
						Error_StrPosition(((Str){25, (i8*)"Expected non empty string"}),At__ref_Lexeri64(lexer,0).at);
					};
					Push_ref_Array_StrStr2((&filesToParse),At__ref_Lexeri64(lexer,0).value);
					Eat__ref_Lexeri64(lexer,1);
					ExpectEndStatement__ref_Lexer(lexer);
				};
				Expect__ref_Lexeri32(lexer,kBracketClose);
			}else			{
				assert_i8Str(0,_add__StrStr(((Str){21, (i8*)"Unhandled directive  "}),At__ref_Lexeri64(lexer,0).value));
			};
		}else		{
			Error_StrPosition(((Str){19, (i8*)"Expected identifier"}),At__ref_Lexeri64(lexer,0).at);
		};
	};
}
Function* ParseFunction__ref_Lexer(Lexer* lexer){
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kFunction)&&(((((((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier)||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kMultiply))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kPlus))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kMinus))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kDivide))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kMod))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kLess))||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kGreater))))	{
		Function* self=New_typeofFunction2();
		(*self).super.at=At__ref_Lexeri64(lexer,0).at;
		if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier))		{
			(*self).ident=At__ref_Lexeri64(lexer,0).value;
		}else		{
			(*self).ident=TokenString_i32(At__ref_Lexeri64(lexer,0).Type);
		};
		Eat__ref_Lexeri64(lexer,2);
		i8 done={0};
		while((done==false))		{
			Expr* expr=(&(*ParseParameter__ref_Lexer(lexer)).super);
			if(_notEq__ref_Expr_typeofNil1(expr))			{
				Add__ref_ExpressionList_ref_Expr((&(*self).params),expr);
				if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kComma))				{
					Eat__ref_Lexeri64(lexer,1);
				}else				{
					done=true;
				};
			}else			{
				done=true;
			};
		};
		if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kGreater)))		{
			Eat__ref_Lexeri64(lexer,2);
			(*self).result=ParseType__ref_Lexer(lexer);
		};
		if(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen))		{
			ExpectEndStatement__ref_Lexer(lexer);
			return self;
		};
		(*self).block=ParseBasicBlock__ref_Lexer(lexer);
		return self;
	};
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,2),kFunction)&&(((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kEqual))||(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kNot)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kEqual)))||(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBraceOpen)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kBraceClose)))))	{
		Function* self=New_typeofFunction3();
		(*self).super.at=At__ref_Lexeri64(lexer,0).at;
		if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual))		{
			(*self).ident=((Str){2, (i8*)"=="});
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kNot))		{
			(*self).ident=((Str){2, (i8*)"!="});
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBraceOpen))		{
			(*self).ident=((Str){2, (i8*)"[]"});
		}else		{
			assert_i8Str(0,((Str){17, (i8*)"no function found"}));
		};
		Eat__ref_Lexeri64(lexer,3);
		i8 done={0};
		while((done==false))		{
			Expr* expr=(&(*ParseParameter__ref_Lexer(lexer)).super);
			if(_notEq__ref_Expr_typeofNil1(expr))			{
				Add__ref_ExpressionList_ref_Expr((&(*self).params),expr);
				if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kComma))				{
					Eat__ref_Lexeri64(lexer,1);
				}else				{
					done=true;
				};
			}else			{
				done=true;
			};
		};
		if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kGreater)))		{
			Eat__ref_Lexeri64(lexer,2);
			(*self).result=ParseType__ref_Lexer(lexer);
		};
		if(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen))		{
			ExpectEndStatement__ref_Lexer(lexer);
			return self;
		};
		(*self).block=ParseBasicBlock__ref_Lexer(lexer);
		return self;
	};
	return (Function*)0;
}
Structure* ParseStructure__ref_Lexer(Lexer* lexer){
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kStruct)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier)))	{
		Structure* structure=New_typeofStructure4();
		(*structure).ident=At__ref_Lexeri64(lexer,0).value;
		Eat__ref_Lexeri64(lexer,2);
		ParseConstraints__ref_Lexer_ref_Array__ref_Type(lexer,(&(*structure).constraints));
		if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kSemicolon)||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEndLine)))		{
			Eat__ref_Lexeri64(lexer,1);
			(*structure).incomplete=true;
			return structure;
		};
		Expect__ref_Lexeri32(lexer,kBracketOpen);
		while(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketClose))		{
			Variable* field=ParseField__ref_Lexer(lexer);
			Add__ref_Structure_ref_Variable(structure,field);
		};
		Expect__ref_Lexeri32(lexer,kBracketClose);
		return structure;
	};
	return (Structure*)0;
}
void ParseConstraints__ref_Lexer_ref_Array__ref_Type(Lexer* lexer, Array__ref_Type* constraints){
	while(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen))	{
		Type* typ=ParseType__ref_Lexer(lexer);
		if(_eq__ref_Type_typeofNil2(typ))		{
			Error_StrPosition(((Str){35, (i8*)"Expected { or type following struct"}),At__ref_Lexeri64(lexer,0).at);
			return ;
		};
		Push_ref_Array__ref_Type_ref_Type3(constraints,typ);
		if(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen))		{
			Expect__ref_Lexeri32(lexer,kComma);
		};
	};
}
Trait* ParseTrait__ref_Lexer(Lexer* lexer){
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kTrait)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier)))	{
		Trait* elTrait=New_typeofTrait5();
		(*elTrait).ident=At__ref_Lexeri64(lexer,0).value;
		Eat__ref_Lexeri64(lexer,2);
		ParseConstraints__ref_Lexer_ref_Array__ref_Type(lexer,(&(*elTrait).constraints));
		Expect__ref_Lexeri32(lexer,kBracketOpen);
		i8 done={0};
		while((done==false))		{
			Function* function=ParseFunction__ref_Lexer(lexer);
			if(_notEq__ref_Function_typeofNil2(function))			{
				AddFunction__ref_Trait_ref_Function(elTrait,function);
				(*function).traitFunction=true;
				assert_i8(((i64)(*function).block==0));
			}else			{
				done=true;
			};
		};
		Expect__ref_Lexeri32(lexer,kBracketClose);
		return elTrait;
	};
	return (Trait*)0;
}
Type* ParseOptions__ref_Lexer_ref_Type(Lexer* lexer, Type* typ){
	Type* t=typ;
	while(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kOption))	{
		Eat__ref_Lexeri64(lexer,1);
		TypeOption* opt=New_typeofTypeOption6();
		(*opt).reference=t;
		t=(&(*opt).super);
	};
	return t;
}
Type* ParseType__ref_Lexer(Lexer* lexer){
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier))	{
		if(_eq__StrStr(At__ref_Lexeri64(lexer,0).value,((Str){6, (i8*)"typeof"})))		{
			TypeType* typ=New_typeofTypeType7();
			Eat__ref_Lexeri64(lexer,1);
			(*typ).reference=ParseType__ref_Lexer(lexer);
			return ParseOptions__ref_Lexer_ref_Type(lexer,(&(*typ).super));
		}else		{
			TypeIdentifier* typ=New_typeofTypeIdentifier8();
			(*typ).ident=At__ref_Lexeri64(lexer,0).value;
			assert_i8Str((*(*typ).ident.chars),((Str){23, (i8*)"failed in parse declare"}));
			Eat__ref_Lexeri64(lexer,1);
			if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kParenOpen))			{
				TypeGeneric* generic=New_typeofTypeGeneric9();
				(*generic).ident=typ;
				Eat__ref_Lexeri64(lexer,1);
				while(true)				{
					Push_ref_Array__ref_Type_ref_Type4((&(*generic).constraints),ParseType__ref_Lexer(lexer));
					if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kComma))					{
						Eat__ref_Lexeri64(lexer,1);
					}else					{
						Expect__ref_Lexeri32(lexer,kParenClose);
						return ParseOptions__ref_Lexer_ref_Type(lexer,(&(*generic).super));
					};
				};
			};
			return ParseOptions__ref_Lexer_ref_Type(lexer,(&(*typ).super));
		};
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kRef))	{
		TypeRef* typ=New_typeofTypeRef10();
		Eat__ref_Lexeri64(lexer,1);
		Type* r=ParseOptions__ref_Lexer_ref_Type(lexer,(&(*typ).super));
		(*typ).reference=ParseType__ref_Lexer(lexer);
		return r;
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kDollar))	{
		Eat__ref_Lexeri64(lexer,1);
		if(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier))		{
			Error_StrPosition(((Str){27, (i8*)"Expected identifier after $"}),At__ref_Lexeri64(lexer,0).at);
		};
		TypeAny* typ=New_typeofTypeAny11();
		(*typ).ident=At__ref_Lexeri64(lexer,0).value;
		Eat__ref_Lexeri64(lexer,1);
		return ParseOptions__ref_Lexer_ref_Type(lexer,(&(*typ).super));
	};
	return (Type*)0;
}
Variable* ParseField__ref_Lexer(Lexer* lexer){
	Variable* field=New_typeofVariable12();
	(*field).super.at=At__ref_Lexeri64(lexer,0).at;
	(*field).ident=At__ref_Lexeri64(lexer,0).value;
	Eat__ref_Lexeri64(lexer,1);
	(*field).super.typ=ParseType__ref_Lexer(lexer);
	if(_eq__ref_Type_typeofNil2((*field).super.typ))	{
		Error_StrPosition(((Str){22, (i8*)"Expected type of field"}),At__ref_Lexeri64(lexer,0).at);
	};
	ExpectEndStatement__ref_Lexer(lexer);
	return field;
}
Variable* ParseParameter__ref_Lexer(Lexer* lexer){
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier)&&((_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kIdentifier)||_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kRef))||_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kDollar))))	{
		Variable* variable=New_typeofVariable13();
		(*variable).super.at=At__ref_Lexeri64(lexer,0).at;
		if(!_eq__StrStr(At__ref_Lexeri64(lexer,0).value,((Str){6, (i8*)"typeof"})))		{
			(*variable).ident=At__ref_Lexeri64(lexer,0).value;
			Eat__ref_Lexeri64(lexer,1);
		};
		(*variable).super.typ=ParseType__ref_Lexer(lexer);
		return variable;
	};
	return (Variable*)0;
}
Variable* ParseVariable__ref_Lexer(Lexer* lexer){
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier)&&((_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kIdentifier)||_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kRef))||_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kDollar))))	{
		Variable* variable=New_typeofVariable14();
		(*variable).super.at=At__ref_Lexeri64(lexer,0).at;
		if(!_eq__StrStr(At__ref_Lexeri64(lexer,0).value,((Str){6, (i8*)"typeof"})))		{
			(*variable).ident=At__ref_Lexeri64(lexer,0).value;
			Eat__ref_Lexeri64(lexer,1);
		};
		(*variable).super.typ=ParseType__ref_Lexer(lexer);
		if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual))		{
			Eat__ref_Lexeri64(lexer,1);
			(*variable).assign=ParseExpression__ref_Lexeri32(lexer,0);
			if(_eq__ref_Expr_typeofNil1((*variable).assign))			{
				Error_StrPosition(((Str){31, (i8*)"Expected expression following ="}),At__ref_Lexeri64(lexer,0).at);
			};
		};
		ExpectEndStatement__ref_Lexer(lexer);
		return variable;
	};
	return (Variable*)0;
}
Expr* ParseControl__ref_Lexer(Lexer* lexer){
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kFor))	{
		Eat__ref_Lexeri64(lexer,1);
		Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
		if(_eq__ref_Expr_typeofNil1(expr))		{
			Error_StrPosition(((Str){33, (i8*)"Expected expression following for"}),At__ref_Lexeri64(lexer,0).at);
			return (Expr*)0;
		};
		if(Is_ref_Expr_typeofExpressionList1(expr))		{
			ForList* self=New_typeofForList15();
			(*self).super.at=At__ref_Lexeri64(lexer,0).at;
			(*self).list=As_ref_Expr_typeofExpressionList1(expr);
			(*self).block=ParseBasicBlock__ref_Lexer(lexer);
			return (&(*self).super);
		};
		For* self=New_typeofFor16();
		(*self).super.at=At__ref_Lexeri64(lexer,0).at;
		(*self).from=expr;
		if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kDot)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kDot)))		{
			Eat__ref_Lexeri64(lexer,2);
			(*self).to=ParseExpression__ref_Lexeri32(lexer,0);
			if(_eq__ref_Expr_typeofNil1((*self).to))			{
				Error_StrPosition(((Str){42, (i8*)"Expected expression following for expr .. "}),At__ref_Lexeri64(lexer,0).at);
				return (Expr*)0;
			};
		};
		(*self).block=ParseBasicBlock__ref_Lexer(lexer);
		return (&(*self).super);
	};
	if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBreak)||_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kContinue)))	{
		Branch* self=New_typeofBranch17();
		(*self).token=At__ref_Lexeri64(lexer,0).Type;
		Eat__ref_Lexeri64(lexer,1);
		return (&(*self).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIf))	{
		If* self=New_typeofIf18();
		(*self).super.at=At__ref_Lexeri64(lexer,0).at;
		Eat__ref_Lexeri64(lexer,1);
		(*self).condition=ParseExpression__ref_Lexeri32(lexer,0);
		(*self).trueBranch=ParseBasicBlock__ref_Lexer(lexer);
		If* current=self;
		while(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kElse))		{
			Eat__ref_Lexeri64(lexer,1);
			if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBracketOpen))			{
				(*current).falseBranch=ParseBasicBlock__ref_Lexer(lexer);
			}else			{
				(*current).falseCondition=New_typeofIf19();
				(*(*current).falseCondition).super.at=At__ref_Lexeri64(lexer,0).at;
				(*(*current).falseCondition).condition=ParseExpression__ref_Lexeri32(lexer,0);
				(*(*current).falseCondition).trueBranch=ParseBasicBlock__ref_Lexer(lexer);
				current=(*current).falseCondition;
			};
		};
		return (&(*self).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kReturn))	{
		Return* self=New_typeofReturn20();
		(*self).super.at=At__ref_Lexeri64(lexer,0).at;
		Eat__ref_Lexeri64(lexer,1);
		(*self).expr=ParseExpression__ref_Lexer(lexer);
		return (&(*self).super);
	};
	return (Expr*)0;
}
Expr* ParseOperand__ref_Lexeri32(Lexer* lexer, i32 precedence){
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier))	{
		Identifier* operand=New_typeofIdentifier21();
		(*operand).super.at=At__ref_Lexeri64(lexer,0).at;
		(*operand).ident=At__ref_Lexeri64(lexer,0).value;
		Eat__ref_Lexeri64(lexer,1);
		return (&(*operand).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kNumber))	{
		NumberConstant* operand=New_typeofNumberConstant22();
		(*operand).super.at=At__ref_Lexeri64(lexer,0).at;
		(*operand).value=At__ref_Lexeri64(lexer,0).value;
		Eat__ref_Lexeri64(lexer,1);
		return (&(*operand).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kString))	{
		StringConstant* operand=New_typeofStringConstant23();
		(*operand).super.at=At__ref_Lexeri64(lexer,0).at;
		(*operand).value=At__ref_Lexeri64(lexer,0).value;
		Eat__ref_Lexeri64(lexer,1);
		return (&(*operand).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kAnd))	{
		Call* op=New_typeofCall24();
		Identifier* identifier=New_typeofIdentifier25();
		(*op).super.at=At__ref_Lexeri64(lexer,0).at;
		(*identifier).ident=((Str){1, (i8*)"&"});
		(*op).operand=(&(*identifier).super);
		Eat__ref_Lexeri64(lexer,1);
		Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
		if(_eq__ref_Expr_typeofNil1(expr))		{
			Error_StrPosition(((Str){31, (i8*)"Expected expression following &"}),At__ref_Lexeri64(lexer,0).at);
		}else		{
			Add__ref_ExpressionList_ref_Expr((&(*op).params),expr);
		};
		return (&(*op).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kNot))	{
		Call* op=New_typeofCall26();
		Identifier* identifier=New_typeofIdentifier27();
		(*op).super.at=At__ref_Lexeri64(lexer,0).at;
		(*identifier).ident=((Str){1, (i8*)"!"});
		(*op).operand=(&(*identifier).super);
		Eat__ref_Lexeri64(lexer,1);
		Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
		if(_eq__ref_Expr_typeofNil1(expr))		{
			Error_StrPosition(((Str){31, (i8*)"Expected expression following !"}),At__ref_Lexeri64(lexer,0).at);
		}else		{
			Add__ref_ExpressionList_ref_Expr((&(*op).params),expr);
		};
		return (&(*op).super);
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kParenOpen))	{
		Eat__ref_Lexeri64(lexer,1);
		Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
		if(_eq__ref_Expr_typeofNil1(expr))		{
			Error_StrPosition(((Str){31, (i8*)"Expected expression following ("}),At__ref_Lexeri64(lexer,0).at);
		};
		Expect__ref_Lexeri32(lexer,kParenClose);
		return expr;
	};
	if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBraceOpen))	{
		ExpressionList* operand=New_typeofExpressionList28();
		(*operand).super.at=At__ref_Lexeri64(lexer,0).at;
		Eat__ref_Lexeri64(lexer,1);
		while(true)		{
			Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
			if(_notEq__ref_Expr_typeofNil1(expr))			{
				Push_ref_Array__ref_Expr_ref_Expr5((&(*operand).list),expr);
				if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kComma))				{
					Eat__ref_Lexeri64(lexer,1);
				}else				{
					Expect__ref_Lexeri32(lexer,kBraceClose);
					return (&(*operand).super);
				};
			}else			{
				Expect__ref_Lexeri32(lexer,kBraceClose);
				return (&(*operand).super);
			};
		};
		return (&(*operand).super);
	};
	Type* typ=ParseType__ref_Lexer(lexer);
	if(_notEq__ref_Type_typeofNil3(typ))	{
		Identifier* ident=New_typeofIdentifier29();
		TypeType* as=New_typeofTypeType30();
		(*as).reference=typ;
		(*ident).super.typ=(&(*as).super);
		return (&(*ident).super);
	};
	return (Expr*)0;
}
i8 IsOperator_Token(Token token){
	return ((((_eq__Tokeni64(token,kPlus)||_eq__Tokeni64(token,kMinus))||_eq__Tokeni64(token,kMultiply))||_eq__Tokeni64(token,kDivide))||_eq__Tokeni64(token,kMod));
}
i32 Precedence_Token(Token token){
	if((_eq__Tokeni64(token,kPlus)||_eq__Tokeni64(token,kMinus)))	{
		return 4;
	};
	if(((_eq__Tokeni64(token,kMultiply)||_eq__Tokeni64(token,kDivide))||_eq__Tokeni64(token,kMod)))	{
		return 5;
	};
	assert_i8Str(0,_add__StrStr(((Str){29, (i8*)"Uknown precedence for token, "}),TokenString_i32(token.Type)));
	return 0;
}
Expr* CreateCall_Str_ref_Expr_ref_Expr(Str ident, Expr* left, Expr* right){
	if(_eq__ref_Expr_typeofNil1(right))	{
		Error_StrPosition(_add__StrStr(((Str){30, (i8*)"Expected expression following "}),ident),(*left).at);
		return (Expr*)0;
	};
	Call* op=New_typeofCall31();
	(*op).super.at=(*left).at;
	Identifier* identifier=New_typeofIdentifier32();
	(*identifier).ident=ident;
	(*op).operand=(&(*identifier).super);
	Add__ref_ExpressionList_ref_Expr((&(*op).params),left);
	Add__ref_ExpressionList_ref_Expr((&(*op).params),right);
	return (&(*op).super);
}
Expr* ParseExpression__ref_Lexeri32(Lexer* lexer, i32 precedence){
	Expr* left=ParseOperand__ref_Lexeri32(lexer,precedence);
	while(left)	{
		if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kDot)&&_notEq__Tokeni64(At__ref_Lexeri64(lexer,1),kDot)))		{
			Eat__ref_Lexeri64(lexer,1);
			Access* access=New_typeofAccess33();
			(*access).super.at=At__ref_Lexeri64(lexer,0).at;
			(*access).operand=left;
			if(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kIdentifier))			{
				assert_i8Str(0,((Str){31, (i8*)"Expected identifier following ."}));
			};
			(*access).field=At__ref_Lexeri64(lexer,0).value;
			Eat__ref_Lexeri64(lexer,1);
			left=(&(*access).super);
		}else if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual)&&_notEq__Tokeni64(At__ref_Lexeri64(lexer,1),kEqual)))		{
			Assign* assign=New_typeofAssign34();
			(*assign).super.at=At__ref_Lexeri64(lexer,0).at;
			Eat__ref_Lexeri64(lexer,1);
			(*assign).left=left;
			(*assign).right=ParseExpression__ref_Lexeri32(lexer,0);
			if(_eq__ref_Expr_typeofNil1((*assign).right))			{
				Error_StrPosition(((Str){31, (i8*)"Expected expression following ="}),At__ref_Lexeri64(lexer,0).at);
			};
			left=(&(*assign).super);
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual))		{
			if((3<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,2);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)"=="}),left,ParseExpression__ref_Lexeri32(lexer,(3+1)));
		}else if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kNot)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kEqual)))		{
			if((3<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,2);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)"!="}),left,ParseExpression__ref_Lexeri32(lexer,(3+1)));
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kBraceOpen))		{
			Eat__ref_Lexeri64(lexer,1);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)"[]"}),left,ParseExpression__ref_Lexeri32(lexer,0));
			Expect__ref_Lexeri32(lexer,kBraceClose);
		}else if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kGreater)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kEqual)))		{
			if((3<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,2);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)">="}),left,ParseExpression__ref_Lexeri32(lexer,(3+1)));
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kGreater))		{
			if((3<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,1);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){1, (i8*)">"}),left,ParseExpression__ref_Lexeri32(lexer,(3+1)));
		}else if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kLess)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kEqual)))		{
			if((3<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,2);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)"<="}),left,ParseExpression__ref_Lexeri32(lexer,(3+1)));
		}else if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kAnd)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kAnd)))		{
			if((2<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,2);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)"&&"}),left,ParseExpression__ref_Lexeri32(lexer,(2+1)));
		}else if((_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kOr)&&_eq__Tokeni64(At__ref_Lexeri64(lexer,1),kOr)))		{
			if((1<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,2);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){2, (i8*)"||"}),left,ParseExpression__ref_Lexeri32(lexer,(1+1)));
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kLess))		{
			if((3<precedence))			{
				return left;
			};
			Eat__ref_Lexeri64(lexer,1);
			left=CreateCall_Str_ref_Expr_ref_Expr(((Str){1, (i8*)"<"}),left,ParseExpression__ref_Lexeri32(lexer,(3+1)));
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kEqual))		{
			Eat__ref_Lexeri64(lexer,2);
			Call* op=New_typeofCall35();
			(*op).super.at=At__ref_Lexeri64(lexer,0).at;
			Identifier* identifier=New_typeofIdentifier36();
			(*identifier).ident=((Str){2, (i8*)"=="});
			(*op).operand=(&(*identifier).super);
			Add__ref_ExpressionList_ref_Expr((&(*op).params),left);
			left=(&(*op).super);
		}else if(IsOperator_Token(At__ref_Lexeri64(lexer,0)))		{
			i32 nextPrecedence=Precedence_Token(At__ref_Lexeri64(lexer,0));
			if((nextPrecedence<precedence))			{
				return left;
			};
			Call* op=New_typeofCall37();
			(*op).super.at=At__ref_Lexeri64(lexer,0).at;
			Identifier* identifier=New_typeofIdentifier38();
			(*identifier).ident=TokenString_i32(At__ref_Lexeri64(lexer,0).Type);
			(*op).operand=(&(*identifier).super);
			Eat__ref_Lexeri64(lexer,1);
			Expr* right=ParseExpression__ref_Lexeri32(lexer,(nextPrecedence+1));
			assert_ref_ExprStr1(left,((Str){13, (i8*)"Expected left"}));
			assert_ref_ExprStr1(right,((Str){14, (i8*)"Expected right"}));
			Add__ref_ExpressionList_ref_Expr((&(*op).params),left);
			Add__ref_ExpressionList_ref_Expr((&(*op).params),right);
			left=(&(*op).super);
		}else if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kParenOpen))		{
			Call* call=New_typeofCall39();
			(*call).operand=left;
			(*call).super.at=At__ref_Lexeri64(lexer,0).at;
			Eat__ref_Lexeri64(lexer,1);
			while(_notEq__Tokeni64(At__ref_Lexeri64(lexer,0),kParenClose))			{
				Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
				if(_eq__ref_Expr_typeofNil1(expr))				{
					Error_StrPosition(((Str){10, (i8*)"Expected )"}),At__ref_Lexeri64(lexer,(0-1)).at);
					return left;
				};
				Add__ref_ExpressionList_ref_Expr((&(*call).params),expr);
				if(_eq__Tokeni64(At__ref_Lexeri64(lexer,0),kComma))				{
					Eat__ref_Lexeri64(lexer,1);
				};
			};
			Expect__ref_Lexeri32(lexer,kParenClose);
			left=(&(*call).super);
		}else		{
			return left;
		};
	};
	return left;
}
Expr* ParseExpression__ref_Lexer(Lexer* lexer){
	Expr* expr=ParseExpression__ref_Lexeri32(lexer,0);
	if(_notEq__ref_Expr_typeofNil1(expr))	{
		ExpectEndStatement__ref_Lexer(lexer);
	};
	return expr;
}
void Parse__ref_BlockStr(Block* block, Str file){
	Module* module=AddFile__ref_ProjectStr((&project),file);
	Lexer lexer=Lexer_Stri64(file,project.files.length);
	while(true)	{
		ParseDirective__ref_Lexer_ref_Block((&lexer),block);
		Expr* expr={0};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=(&(*ParseStructure__ref_Lexer((&lexer))).super);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=(&(*ParseFunction__ref_Lexer((&lexer))).super);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=(&(*ParseTrait__ref_Lexer((&lexer))).super);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			expr=(&(*ParseVariable__ref_Lexer((&lexer))).super);
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			if(_notEq__Tokeni64(At__ref_Lexeri64((&lexer),0),kEnd))			{
				Error_StrPosition(((Str){52, (i8*)"Expected fn, struct, trait, or variable at top level"}),At__ref_Lexeri64((&lexer),0).at);
			};
			return ;
		};
		Add__ref_Block_ref_Expr(block,expr);
	};
}
Block* Compile_Str(Str file){
	Block* block=New_typeofBlock40();
	Push_ref_Array_StrStr6((&filesToParse),file);
	while(filesToParse.length)	{
		Str theFile=*Last_ref_Array_Str1((&filesToParse));
		Pop_ref_Array_Str1((&filesToParse));
		Println_Str(_add__StrStr(((Str){7, (i8*)"Parse: "}),theFile));
		if(_eq__ref_Module_typeofNil3(GetFile__ref_ProjectStr((&project),theFile)))		{
			AddFile__ref_ProjectStr((&project),theFile);
			Parse__ref_BlockStr(block,theFile);
			if((errors.length!=0))			{
				return block;
			};
		};
	};
	Print__ref_Expr((&(*block).super));
	return block;
}
void PrintError_PositionStr(Position at, Str message){
	Str f={0};
	if((at.file==0))	{
		f=((Str){0, (i8*)""});
	}else	{
		f=_add__StrStr(directory,(*(*_bracket__ref_Array__ref_Modulei642((&project.files),(at.file-1)))).path);
	};
	Println_Str(((Str){294, (i8*)"••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"}));
	Println_Str(_add__StrStr(_add__StrStr(_add__StrStr(_add__StrStr(_add__StrStr(_add__StrStr(f,((Str){1, (i8*)":"})),String_i64(at.line)),((Str){1, (i8*)":"})),String_i64(at.column)),((Str){9, (i8*)": error: "})),message));
	PrintLines__ref_ProjectPositioni64((&project),at,6);
	Println_Str(((Str){294, (i8*)"••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••"}));
}
void Run_(){
	Println_Str(((Str){17, (i8*)"Running c backend"}));
	Str link=((Str){138, (i8*)"-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo /Users/David/Desktop/Projects/glfw/src/libglfw.3.3.dylib libstb.a"});
	Str call=_add__StrStr(_add__StrStr(((Str){95, (i8*)"clang++ -std=c++11 -stdlib=libc++ -Wno-parentheses-equality build/strap.cpp -o build/strap -O0 "}),link),((Str){16, (i8*)" && build/strap"}));
	Println_Str(call);
}
void Main_(){
	Println_Str(((Str){7, (i8*)"RUNNING"}));
	Block* block=Compile_Str(((Str){7, (i8*)"Main.dl"}));
	if((errors.length!=0))	{
		PrintError_PositionStr((*_bracket__ref_Array_Errori643((&errors),0)).at,(*_bracket__ref_Array_Errori644((&errors),0)).message);
	};
	if((errors.length==0))	{
		Semantic semantic={0};
		Init__ref_Semantic_ref_Block((&semantic),block);
		if((errors.length==0))		{
			GenerateBasic generate={0};
			Init__ref_GenerateBasic_ref_Semantic_ref_Block((&generate),(&semantic),block);
		}else		{
			Println_Str(((Str){14, (i8*)"Semantic error"}));
		};
	};
}
void Indent__ref_GenerateBasic(GenerateBasic* self){
	for(i32 it=(i32)0; (it<(*self).indent); it=(it+1))	{
		Write__ref_FileHandleStr((*self).impl,((Str){1, (i8*)"	"}));
	};
}
Str Mangle__ref_Type(Type* self){
	Type* t=Resolved__ref_Type(self);
	if(Is_ref_Type_typeofTypeTrait1(t))	{
		return ((Str){11, (i8*)"<typeTrait>"});
	};
	if(Is_ref_Type_typeofTypeAny2(t))	{
		return ((Str){9, (i8*)"<TypeAny>"});
	};
	if(Is_ref_Type_typeofTypeType3(t))	{
		return _add__StrStr(((Str){7, (i8*)"_typeof"}),Mangle__ref_Type((*As_ref_Type_typeofTypeType1(t)).reference));
	};
	if(Is_ref_Type_typeofTypeRef4(t))	{
		return _add__StrStr(((Str){5, (i8*)"_ref_"}),Mangle__ref_Type((*As_ref_Type_typeofTypeRef2(t)).reference));
	};
	if(Is_ref_Type_typeofTypeIdentifier5(t))	{
		TypeIdentifier* ident=As_ref_Type_typeofTypeIdentifier3(t);
		if(_eq__ref_Expr_typeofNil1((*ident).spec))		{
			return ((Str){5, (i8*)"_nil_"});
		}else if(Is_ref_Expr_typeofStructure2((*ident).spec))		{
			return Name__ref_Structure(As_ref_Expr_typeofStructure3((*ident).spec));
		}else		{
			return ((Str){3, (i8*)"_t_"});
		};
	};
	if(Is_ref_Type_typeofTypeGeneric6(t))	{
		TypeGeneric* gen=As_ref_Type_typeofTypeGeneric4(t);
		return Mangle__ref_Type((&(*(*gen).referenced).super));
	};
	if(Is_ref_Type_typeofTypeStructure7(t))	{
		TypeStructure* self=As_ref_Type_typeofTypeStructure5(t);
		Str out=(*(*self).parent).ident;
		if(((*self).constraints.length!=0))		{
			out=_add__StrStr(out,((Str){1, (i8*)"_"}));
		};
		if((*self).incomplete)		{
			out=_add__StrStr(_add__StrStr(((Str){5, (i8*)"<inc>"}),out),((Str){5, (i8*)"<inc>"}));
		};
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			out=_add__StrStr(out,Mangle__ref_Type((*_bracket__ref_Array__ref_Typei645((&(*self).constraints),it))));
		};
		return out;
	};
	if(Is_ref_Type_typeofTypeNumber8(t))	{
		TypeNumber* self=As_ref_Type_typeofTypeNumber6(t);
		if(((*self).kind==TypeNumberInteger))		{
			return _add__StrStr(((Str){1, (i8*)"i"}),String_i64(((*self).size*8)));
		}else if(((*self).kind==TypeNumberUnsigned))		{
			return _add__StrStr(((Str){1, (i8*)"u"}),String_i64(((*self).size*8)));
		}else if(((*self).kind==TypeNumberFloat))		{
			return _add__StrStr(((Str){1, (i8*)"f"}),String_i64(((*self).size*8)));
		}else		{
			assert_i8(0);
		};
		return ((Str){0, (i8*)""});
	};
	return ((Str){0, (i8*)""});
}
Str Name__ref_Structure(Structure* self){
	Str out=(*self).ident;
	for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))	{
		out=_add__StrStr(_add__StrStr(out,Mangle__ref_Type((*_bracket__ref_Array__ref_Typei646((&(*self).constraints),it)))),((Str){12, (i8*)"_incomplete_"}));
	};
	return out;
}
Str Name__ref_Function(Function* self){
	Str out=*_bracket__ref_Table_StrStrStr1((&remapped),(*self).ident);
	if((out.length==0))	{
		out=(*self).ident;
	};
	if(_notEq__ref_FunctionSpec_typeofNil4((*self).spec))	{
		return Name__ref_FunctionSpec((*self).spec);
	}else if(_notEq__ref_Block_typeofNil5((*self).block))	{
		out=_add__StrStr(out,((Str){1, (i8*)"_"}));
		for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))		{
			out=_add__StrStr(out,Mangle__ref_Type((**_bracket__ref_Array__ref_Expri647((&(*self).params.list),it)).typ));
		};
	};
	return out;
}
Str Name__ref_FunctionSpec(FunctionSpec* self){
	Str out=*_bracket__ref_Table_StrStrStr2((&remapped),(*(*self).function).ident);
	if((out.length==0))	{
		out=(*(*self).function).ident;
	};
	for(i64 it=(i64)0; (it<(*self).params.length); it=(it+1))	{
		out=_add__StrStr(out,Mangle__ref_Type((*_bracket__ref_Array__ref_Typei648((&(*self).params),it))));
	};
	return out;
}
void Init__ref_GenerateBasic_ref_Semantic_ref_Block(GenerateBasic* generate, Semantic* semantic, Block* ast){
	(*generate).semantic=semantic;
	(*generate).header=FileOpen(((Str){10, (i8*)"build/dl.h"}).chars,((Str){1, (i8*)"w"}).chars);
	(*generate).impl=FileOpen(((Str){12, (i8*)"build/dl.cpp"}).chars,((Str){1, (i8*)"w"}).chars);
	(*generate).types=FileOpen(((Str){15, (i8*)"build/dltypes.h"}).chars,((Str){1, (i8*)"w"}).chars);
	assert_i8Str(((i64)(*generate).header!=0),((Str){8, (i8*)"Bad file"}));
	assert_i8Str(((i64)(*generate).impl!=0),((Str){8, (i8*)"Bad file"}));
	Init_ref_Table_StrStr1((&remapped));
	*_bracket__ref_Table_StrStrStr3((&remapped),((Str){1, (i8*)"*"}))=((Str){5, (i8*)"_mul_"});
	*_bracket__ref_Table_StrStrStr4((&remapped),((Str){1, (i8*)"+"}))=((Str){5, (i8*)"_add_"});
	*_bracket__ref_Table_StrStrStr5((&remapped),((Str){1, (i8*)"-"}))=((Str){5, (i8*)"_sub_"});
	*_bracket__ref_Table_StrStrStr6((&remapped),((Str){1, (i8*)"/"}))=((Str){5, (i8*)"_div_"});
	*_bracket__ref_Table_StrStrStr7((&remapped),((Str){2, (i8*)"[]"}))=((Str){9, (i8*)"_bracket_"});
	*_bracket__ref_Table_StrStrStr8((&remapped),((Str){1, (i8*)"<"}))=((Str){6, (i8*)"_less_"});
	*_bracket__ref_Table_StrStrStr9((&remapped),((Str){2, (i8*)"<="}))=((Str){8, (i8*)"_lessEq_"});
	*_bracket__ref_Table_StrStrStr10((&remapped),((Str){1, (i8*)">"}))=((Str){9, (i8*)"_greater_"});
	*_bracket__ref_Table_StrStrStr11((&remapped),((Str){2, (i8*)">="}))=((Str){11, (i8*)"_greaterEq_"});
	*_bracket__ref_Table_StrStrStr12((&remapped),((Str){2, (i8*)"=="}))=((Str){4, (i8*)"_eq_"});
	*_bracket__ref_Table_StrStrStr13((&remapped),((Str){2, (i8*)"!="}))=((Str){7, (i8*)"_notEq_"});
	Write__ref_FileHandleStr((*generate).impl,((Str){16, (i8*)"#include \"dl.h\"\n"}));
	Write__ref_FileHandleStr((*generate).types,((Str){20, (i8*)"#include \"header.h\"\n"}));
	Write__ref_FileHandleStr((*generate).header,((Str){21, (i8*)"#include \"dltypes.h\"\n"}));
	for(i64 it=(i64)0; (it<(*ast).expressions.length); it=(it+1))	{
		Expr* expr=*_bracket__ref_Array__ref_Expri649((&(*ast).expressions),it);
		if(Is_ref_Expr_typeofVariable3(expr))		{
			Visit__ref_GenerateBasic_ref_Expr(generate,expr);
			Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)";\n"}));
		};
	};
	for(i64 it=(i64)0; (it<(*ast).expressions.length); it=(it+1))	{
		Expr* expr=*_bracket__ref_Array__ref_Expri6410((&(*ast).expressions),it);
		if(Is_ref_Expr_typeofStructure2(expr))		{
		}else if(Is_ref_Expr_typeofVariable3(expr))		{
		}else		{
			Visit__ref_GenerateBasic_ref_Expr(generate,expr);
		};
	};
	Print_Str(_add__StrStr(((Str){24, (i8*)"gSpecializations.length "}),String_i64(gSpecializations.length)));
	for(i64 it=(i64)0; (it<gSpecializations.length); it=(it+1))	{
		FunctionSpec* spec=*_bracket__ref_Array__ref_FunctionSpeci6411((&gSpecializations),it);
		if(!(*spec).incomplete)		{
			if(!(*spec).incomplete)			{
				for(i64 it=(i64)0; (it<(*spec).known.length); it=(it+1))				{
					TypeAnyResolved t=*_bracket__ref_Array_TypeAnyResolvedi6412((&(*spec).known),it);
					assert_i8(!ContainsAny__ref_Type(t.typ));
				};
			};
			Apply__ref_FunctionSpec(spec);
			Visit__ref_Semantic_ref_Expr((*generate).semantic,(&(*(*spec).function).super));
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*spec).function).super));
			Clear__ref_FunctionSpec(spec);
		};
	};
	Print_Str(_add__StrStr(((Str){24, (i8*)"gSpecializations.length "}),String_i64(gSpecializations.length)));
	for(i64 it=(i64)0; (it<structures.length); it=(it+1))	{
		TypeStructure* spec=*_bracket__ref_Array__ref_TypeStructurei6413((&structures),it);
		i8 hide=(PtrEqual_ref_Structure_ref_Structure1((*spec).parent,(&(*(*generate).semantic).intrinsic.voidptr_))||(*spec).incomplete);
		if(!hide)		{
			Str name=Mangle__ref_Type((&(*spec).super));
			Write__ref_FileHandleStr((*generate).types,((Str){7, (i8*)"struct "}));
			Write__ref_FileHandleStr((*generate).types,name);
			Write__ref_FileHandleStr((*generate).types,((Str){2, (i8*)";\n"}));
		};
	};
	for(i64 it=(i64)0; (it<structures.length); it=(it+1))	{
		TypeStructure* spec=*_bracket__ref_Array__ref_TypeStructurei6414((&structures),it);
		i8 hide=(PtrEqual_ref_Structure_ref_Structure1((*spec).parent,(&(*(*generate).semantic).intrinsic.voidptr_))||(*spec).incomplete);
		if(hide)		{
			Write__ref_FileHandleStr((*generate).types,((Str){2, (i8*)"/*"}));
		};
		Str name=Mangle__ref_Type((&(*spec).super));
		Write__ref_FileHandleStr((*generate).types,((Str){7, (i8*)"struct "}));
		Write__ref_FileHandleStr((*generate).types,name);
		Write__ref_FileHandleStr((*generate).types,((Str){3, (i8*)" {\n"}));
		for(i64 it=(i64)0; (it<(*spec).fields.length); it=(it+1))		{
			Visit__ref_FileHandle_ref_Type((*generate).types,(*_bracket__ref_Array__ref_Typei6415((&(*spec).fields),it)));
			Write__ref_FileHandleStr((*generate).types,((Str){1, (i8*)" "}));
			Write__ref_FileHandleStr((*generate).types,(**_bracket__ref_Array__ref_Variablei6416((&(*(*spec).parent).fields),it)).ident);
			Write__ref_FileHandleStr((*generate).types,((Str){2, (i8*)";\n"}));
		};
		Write__ref_FileHandleStr((*generate).types,((Str){3, (i8*)"};\n"}));
		if(hide)		{
			Write__ref_FileHandleStr((*generate).types,((Str){2, (i8*)"*/"}));
		};
	};
	FileClose((*generate).header);
	FileClose((*generate).impl);
	FileClose((*generate).types);
}
void Write__ref_FileHandleStr(FileHandle* file, Str s){
	FilePut((*(&file)),s.chars);
}
void Visit__ref_FileHandle_ref_Type(FileHandle* file, Type* t){
	Type* typ=Resolved__ref_Type(t);
	if(Is_ref_Type_typeofTypeOption9(typ))	{
		TypeOption* self=As_ref_Type_typeofTypeOption7(typ);
		if(Is_ref_Type_typeofTypeRef4((*self).reference))		{
			Visit__ref_FileHandle_ref_Type(file,(*self).reference);
		}else		{
			Write__ref_FileHandleStr(file,((Str){6, (i8*)"OPTION"}));
		};
		return ;
	};
	if(Is_ref_Type_typeofTypeRef4(typ))	{
		TypeRef* self=As_ref_Type_typeofTypeRef8(typ);
		Visit__ref_FileHandle_ref_Type(file,(*self).reference);
		Write__ref_FileHandleStr(file,((Str){1, (i8*)"*"}));
		return ;
	};
	if(Is_ref_Type_typeofTypeIdentifier5(typ))	{
		TypeIdentifier* self=As_ref_Type_typeofTypeIdentifier9(typ);
		Write__ref_FileHandleStr(file,Name__ref_Structure(As_ref_Expr_typeofStructure5((*self).spec)));
		return ;
	};
	if(Is_ref_Type_typeofTypeGeneric6(typ))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric10(typ);
		Write__ref_FileHandleStr(file,Mangle__ref_Type(typ));
		return ;
	};
	if(Is_ref_Type_typeofTypeNumber8(typ))	{
		TypeNumber* self=As_ref_Type_typeofTypeNumber11(typ);
		if(((*self).kind==TypeNumberInteger))		{
			Write__ref_FileHandleStr(file,((Str){1, (i8*)"i"}));
		}else if(((*self).kind==TypeNumberUnsigned))		{
			Write__ref_FileHandleStr(file,((Str){1, (i8*)"u"}));
		}else if(((*self).kind==TypeNumberFloat))		{
			Write__ref_FileHandleStr(file,((Str){1, (i8*)"f"}));
		}else		{
			assert_i8(0);
		};
		Write__ref_FileHandleStr(file,String_i64(((*self).size*8)));
		return ;
	};
	Write__ref_FileHandleStr(file,_add__StrStr(((Str){15, (i8*)"unknown type - "}),String_i64((*typ).kind)));
}
void Visit__ref_GenerateBasic_ref_Expr(GenerateBasic* generate, Expr* expr){
	if(Is_ref_Expr_typeofBlock4(expr))	{
		Indent__ref_GenerateBasic(generate);
		Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"{\n"}));
		Block* self=As_ref_Expr_typeofBlock6(expr);
		(*generate).indent=((*generate).indent+1);
		for(i64 it=(i64)0; (it<(*self).expressions.length); it=(it+1))		{
			Expr* expr=*_bracket__ref_Array__ref_Expri6417((&(*self).expressions),it);
			Indent__ref_GenerateBasic(generate);
			Visit__ref_GenerateBasic_ref_Expr(generate,expr);
			Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)";\n"}));
		};
		(*generate).indent=((*generate).indent-1);
		Indent__ref_GenerateBasic(generate);
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"}"}));
		return ;
	};
	if(Is_ref_Expr_typeofStructure2(expr))	{
		return ;
	};
	if(Is_ref_Expr_typeofFunction5(expr))	{
		Function* self=As_ref_Expr_typeofFunction7(expr);
		if(IsIntrinsic__ref_Intrinsics_ref_Function((&(*(*generate).semantic).intrinsic),self))		{
			return ;
		};
		Str ident=Name__ref_Function(self);
		if((((*self).any.length==0)||((i64)(*self).spec!=0)))		{
			assert_i8Str(((((*self).any.length!=0)||((i64)(*self).spec==0))!=0),((Str){34, (i8*)"Expected just one of these to pass"}));
			if(_notEq__ref_FunctionSpec_typeofNil4((*self).spec))			{
				assert_i8(!(*(*self).spec).incomplete);
			};
			if(_eq__ref_Block_typeofNil4((*self).block))			{
				Write__ref_FileHandleStr((*generate).header,((Str){11, (i8*)"extern \"C\" "}));
			};
			if(_notEq__ref_Type_typeofNil3((*self).result))			{
				Visit__ref_FileHandle_ref_Type((*generate).header,(*self).result);
				Write__ref_FileHandleStr((*generate).header,((Str){1, (i8*)" "}));
			}else			{
				Write__ref_FileHandleStr((*generate).header,((Str){5, (i8*)"void "}));
			};
			Write__ref_FileHandleStr((*generate).header,ident);
			if(_notEq__ref_FunctionSpec_typeofNil4((*self).spec))			{
				Write__ref_FileHandleStr((*generate).header,String_i64((*(*self).spec).index));
			};
			Write__ref_FileHandleStr((*generate).header,((Str){1, (i8*)"("}));
			i64 last=((*self).params.list.length-1);
			while(((last>0)&&Is_ref_Type_typeofTypeType3((**_bracket__ref_Array__ref_Expri6419((&(*self).params.list),last)).typ)))			{
				last=(last-1);
			};
			for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))			{
				if(!Is_ref_Type_typeofTypeType3((**_bracket__ref_Array__ref_Expri6421((&(*self).params.list),it)).typ))				{
					Visit__ref_FileHandle_ref_Type((*generate).header,(**_bracket__ref_Array__ref_Expri6422((&(*self).params.list),it)).typ);
					Write__ref_FileHandleStr((*generate).header,((Str){1, (i8*)" "}));
					Write__ref_FileHandleStr((*generate).header,(*As_ref_Expr_typeofVariable8((*_bracket__ref_Array__ref_Expri6424((&(*self).params.list),it)))).ident);
					if((it!=last))					{
						Write__ref_FileHandleStr((*generate).header,((Str){2, (i8*)", "}));
					};
				};
			};
			Write__ref_FileHandleStr((*generate).header,((Str){3, (i8*)");\n"}));
			if(_notEq__ref_Block_typeofNil5((*self).block))			{
				if(_notEq__ref_Type_typeofNil3((*self).result))				{
					Visit__ref_FileHandle_ref_Type((*generate).impl,(*self).result);
					Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)" "}));
				}else				{
					Write__ref_FileHandleStr((*generate).impl,((Str){5, (i8*)"void "}));
				};
				Write__ref_FileHandleStr((*generate).impl,ident);
				if(_notEq__ref_FunctionSpec_typeofNil4((*self).spec))				{
					Write__ref_FileHandleStr((*generate).impl,String_i64((*(*self).spec).index));
				};
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
				for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))				{
					if(!Is_ref_Type_typeofTypeType3((**_bracket__ref_Array__ref_Expri6426((&(*self).params.list),it)).typ))					{
						Visit__ref_FileHandle_ref_Type((*generate).impl,(**_bracket__ref_Array__ref_Expri6427((&(*self).params.list),it)).typ);
						Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)" "}));
						Write__ref_FileHandleStr((*generate).impl,(*As_ref_Expr_typeofVariable9((*_bracket__ref_Array__ref_Expri6429((&(*self).params.list),it)))).ident);
						if((it!=last))						{
							Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)", "}));
						};
					};
				};
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
				Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).block).super));
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"\n"}));
			};
		};
		return ;
	};
	if(Is_ref_Expr_typeofCall6(expr))	{
		Call* self=As_ref_Expr_typeofCall10(expr);
		i64 last=((*self).params.list.length-1);
		while(((last>0)&&(Is_ref_Type_typeofTypeType3((**_bracket__ref_Array__ref_Expri6431((&(*self).params.list),last)).typ)||Is_ref_Expr_typeofTypeAs7((*_bracket__ref_Array__ref_Expri6433((&(*self).params.list),last))))))		{
			last=(last-1);
		};
		if(Is_ref_Expr_typeofFunction5((*self).func))		{
			Function* function=As_ref_Expr_typeofFunction11((*self).func);
			if(IsIntrinsic__ref_Intrinsics_ref_Function((&(*(*generate).semantic).intrinsic),function))			{
				GenerateBasicIntrinsic__ref_GenerateBasic_ref_Function_ref_Call(generate,function,self);
			}else			{
				Str name=Name__ref_Function(function);
				Write__ref_FileHandleStr((*generate).impl,name);
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
				for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))				{
					if(!(Is_ref_Type_typeofTypeType3((**_bracket__ref_Array__ref_Expri6435((&(*self).params.list),it)).typ)&&!Is_ref_Expr_typeofTypeAs7((*_bracket__ref_Array__ref_Expri6437((&(*self).params.list),it)))))					{
						PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6438((&(*self).params.list),it)),(i64)(*_bracket__ref_Array_i8i6439((&(*self).drefCount),it)));
						if((it!=last))						{
							Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)","}));
						};
					};
				};
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
			};
		}else if(Is_ref_Expr_typeofFunctionSpec8((*self).func))		{
			FunctionSpec* spec=As_ref_Expr_typeofFunctionSpec12((*self).func);
			if(IsIntrinsic__ref_Intrinsics_ref_Function((&(*(*generate).semantic).intrinsic),(*spec).function))			{
				GenerateBasicIntrinsic__ref_GenerateBasic_ref_Function_ref_Call(generate,(*spec).function,self);
			}else			{
				Str name=Name__ref_FunctionSpec(spec);
				Write__ref_FileHandleStr((*generate).impl,name);
				Write__ref_FileHandleStr((*generate).impl,String_i64((*spec).index));
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
				for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))				{
					if(!(Is_ref_Type_typeofTypeType3((**_bracket__ref_Array__ref_Expri6441((&(*self).params.list),it)).typ)&&!Is_ref_Expr_typeofTypeAs7((*_bracket__ref_Array__ref_Expri6443((&(*self).params.list),it)))))					{
						PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6444((&(*self).params.list),it)),(i64)(*_bracket__ref_Array_i8i6445((&(*self).drefCount),it)));
						if((it!=last))						{
							Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)","}));
						};
					};
				};
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
			};
			Clear__ref_FunctionSpec(spec);
		}else		{
			assert_i8Str(0,_add__StrStr(((Str){23, (i8*)"Expected fn or fn spec "}),String_i64((*(*self).operand).kind)));
		};
		return ;
	};
	if(Is_ref_Expr_typeofVariable3(expr))	{
		Variable* self=As_ref_Expr_typeofVariable13(expr);
		if(!Is_ref_Type_typeofTypeType3((*self).super.typ))		{
			Visit__ref_FileHandle_ref_Type((*generate).impl,(*self).super.typ);
			Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)" "}));
			Write__ref_FileHandleStr((*generate).impl,(*self).ident);
			if(_notEq__ref_Expr_typeofNil1((*self).assign))			{
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"="}));
				for(i64 it=(i64)0; (it<(*self).drefCount); it=(it+1))				{
					Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"*"}));
				};
				Visit__ref_GenerateBasic_ref_Expr(generate,(*self).assign);
			}else			{
				Write__ref_FileHandleStr((*generate).impl,((Str){4, (i8*)"={0}"}));
			};
		};
		return ;
	};
	if(Is_ref_Expr_typeofForList9(expr))	{
		ForList* self=As_ref_Expr_typeofForList14(expr);
		for(i64 it=(i64)0; (it<(*(*self).list).list.length); it=(it+1))		{
			(*(*self).it).super.typ=(**_bracket__ref_Array__ref_Expri6446((&(*(*self).list).list),it)).typ;
			Visit__ref_Semantic_ref_Expr((*generate).semantic,(&(*(*self).block).super));
			assert_ref_Type1((*(*self).it).super.typ);
			Write__ref_FileHandleStr((*generate).impl,_add__StrStr(_add__StrStr(((Str){10, (i8*)"/*ForList "}),String_i64(it)),((Str){2, (i8*)"*/"})));
			(*(*self).it).assign=(*_bracket__ref_Array__ref_Expri6448((&(*(*self).list).list),it));
			(*(*self).it).super.typ=(**_bracket__ref_Array__ref_Expri6449((&(*(*self).list).list),it)).typ;
			assert_ref_Type1((*(*self).it).super.typ);
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).block).super));
		};
		return ;
	};
	if(Is_ref_Expr_typeofFor10(expr))	{
		For* self=As_ref_Expr_typeofFor15(expr);
		if(_notEq__ref_Expr_typeofNil1((*self).to))		{
			Write__ref_FileHandleStr((*generate).impl,((Str){4, (i8*)"for("}));
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).it).super));
			Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"; "}));
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).test).super));
			Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"; "}));
			Visit__ref_GenerateBasic_ref_Expr(generate,(*self).inc);
			Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		}else		{
			Write__ref_FileHandleStr((*generate).impl,((Str){6, (i8*)"while("}));
			Visit__ref_GenerateBasic_ref_Expr(generate,(*self).from);
			Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		};
		Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).block).super));
		return ;
	};
	if(Is_ref_Expr_typeofIf11(expr))	{
		If* self=As_ref_Expr_typeofIf16(expr);
		Write__ref_FileHandleStr((*generate).impl,((Str){3, (i8*)"if("}));
		Visit__ref_GenerateBasic_ref_Expr(generate,(*self).condition);
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).trueBranch).super));
		if(_notEq__ref_If_typeofNil6((*self).falseCondition))		{
			Write__ref_FileHandleStr((*generate).impl,((Str){5, (i8*)"else "}));
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).falseCondition).super));
		};
		if(_notEq__ref_Block_typeofNil5((*self).falseBranch))		{
			Write__ref_FileHandleStr((*generate).impl,((Str){4, (i8*)"else"}));
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).falseBranch).super));
		};
		return ;
	};
	if(Is_ref_Expr_typeofIdentifier12(expr))	{
		Identifier* self=As_ref_Expr_typeofIdentifier17(expr);
		Write__ref_FileHandleStr((*generate).impl,(*self).ident);
		return ;
	};
	if(Is_ref_Expr_typeofAccess13(expr))	{
		Access* self=As_ref_Expr_typeofAccess18(expr);
		if(_notEq__ref_Call_typeofNil7((*self).call))		{
			Visit__ref_GenerateBasic_ref_Expr(generate,(&(*(*self).call).super));
			return ;
		};
		Type* typ=Resolved__ref_Type((*(*self).operand).typ);
		if(Is_ref_Type_typeofTypeRef4(typ))		{
			Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
			while(Is_ref_Type_typeofTypeRef4(typ))			{
				typ=Resolved__ref_Type((*As_ref_Type_typeofTypeRef13(typ)).reference);
				Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"*"}));
			};
			Visit__ref_GenerateBasic_ref_Expr(generate,(*self).operand);
			Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		}else		{
			Visit__ref_GenerateBasic_ref_Expr(generate,(*self).operand);
		};
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"."}));
		Write__ref_FileHandleStr((*generate).impl,(*self).field);
		return ;
	};
	if(Is_ref_Expr_typeofAssign14(expr))	{
		Assign* self=As_ref_Expr_typeofAssign19(expr);
		for(i32 it=(i32)0; (it<(0-(*self).drefCount)); it=(it+1))		{
			Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"*"}));
		};
		Visit__ref_GenerateBasic_ref_Expr(generate,(*self).left);
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"="}));
		Visit__ref_GenerateBasic_ref_Expr(generate,(*self).right);
		return ;
	};
	if(Is_ref_Expr_typeofTrait15(expr))	{
		Trait* self=As_ref_Expr_typeofTrait20(expr);
		return ;
	};
	if(Is_ref_Expr_typeofNumberConstant16(expr))	{
		NumberConstant* self=As_ref_Expr_typeofNumberConstant21(expr);
		Write__ref_FileHandleStr((*generate).impl,(*self).value);
		return ;
	};
	if(Is_ref_Expr_typeofStringConstant17(expr))	{
		StringConstant* self=As_ref_Expr_typeofStringConstant22(expr);
		Write__ref_FileHandleStr((*generate).impl,((Str){7, (i8*)"((Str){"}));
		Str s=((Str){1, (i8*)"0"});
		Write__ref_FileHandleStr((*generate).impl,String_i64((*self).value.length));
		Write__ref_FileHandleStr((*generate).impl,((Str){8, (i8*)", (i8*)\""}));
		for(i64 it=(i64)0; (it<(*self).value.length); it=(it+1))		{
			Str v=StringFromChar_i8((*((*self).value.chars+it)));
			if(_eq__StrStr(v,((Str){1, (i8*)"\n"})))			{
				Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"\\n"}));
			}else if(_eq__StrStr(v,((Str){1, (i8*)"\""})))			{
				Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"\\\""}));
			}else if(_eq__StrStr(v,((Str){1, (i8*)"\\"})))			{
				Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"\\\\"}));
			}else			{
				Write__ref_FileHandleStr((*generate).impl,v);
			};
		};
		Write__ref_FileHandleStr((*generate).impl,((Str){3, (i8*)"\"})"}));
		return ;
	};
	if(Is_ref_Expr_typeofReturn18(expr))	{
		Return* self=As_ref_Expr_typeofReturn23(expr);
		Write__ref_FileHandleStr((*generate).impl,((Str){7, (i8*)"return "}));
		if(_notEq__ref_Expr_typeofNil1((*self).expr))		{
			PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*self).expr,(*self).drefCount);
		};
		return ;
	};
	Write__ref_FileHandleStr((*generate).impl,_add__StrStr(_add__StrStr(((Str){20, (i8*)"---- unhandled node "}),String_i64((*expr).kind)),((Str){6, (i8*)"---- \n"})));
}
void PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(GenerateBasic* self, Expr* expr, i64 count){
	if((count<0))	{
		PerformReference__ref_GenerateBasic_ref_Expri64(self,expr,(0-count));
		return ;
	}else if((count>0))	{
		PerformDereference__ref_GenerateBasic_ref_Expri64(self,expr,count);
		return ;
	};
	assert_i8Str((count==0),((Str){29, (i8*)"Internal: expected count == 0"}));
	Visit__ref_GenerateBasic_ref_Expr(self,expr);
}
void PerformReference__ref_GenerateBasic_ref_Expri64(GenerateBasic* self, Expr* expr, i64 count){
	assert_i8Str((count==1),((Str){44, (i8*)"Internal: expected dref count greater than 0"}));
	Write__ref_FileHandleStr((*self).impl,((Str){2, (i8*)"(&"}));
	Visit__ref_GenerateBasic_ref_Expr(self,expr);
	Write__ref_FileHandleStr((*self).impl,((Str){1, (i8*)")"}));
}
void PerformDereference__ref_GenerateBasic_ref_Expri64(GenerateBasic* self, Expr* expr, i64 count){
	assert_i8Str((count>0),((Str){44, (i8*)"Internal: expected dref count greater than 0"}));
	Write__ref_FileHandleStr((*self).impl,((Str){2, (i8*)"(*"}));
	Visit__ref_GenerateBasic_ref_Expr(self,expr);
	Write__ref_FileHandleStr((*self).impl,((Str){1, (i8*)")"}));
}
void GenerateBasicIntrinsic__ref_GenerateBasic_ref_Function_ref_Call(GenerateBasic* generate, Function* function, Call* call){
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*(*generate).semantic).intrinsic.abortFn)))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){8, (i8*)"abort();"}));
		return ;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*(*generate).semantic).intrinsic.invert)))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"!"}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6450((&(*call).params.list),0)),(i64)(*_bracket__ref_Array_i8i6451((&(*call).drefCount),0)));
		return ;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*(*generate).semantic).intrinsic.ptr_add)))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6452((&(*call).params.list),0)),(i64)(*_bracket__ref_Array_i8i6453((&(*call).drefCount),0)));
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"+"}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6454((&(*call).params.list),1)),(i64)(*_bracket__ref_Array_i8i6455((&(*call).drefCount),1)));
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		return ;
	};
	if(((i64)(&(*(*generate).semantic).intrinsic.reference)==(i64)function))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"(&"}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6456((&(*call).params.list),0)),(i64)(*_bracket__ref_Array_i8i6457((&(*call).drefCount),0)));
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		return ;
	};
	if(((i64)(&(*(*generate).semantic).intrinsic.dereference)==(i64)function))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){2, (i8*)"(*"}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6458((&(*call).params.list),0)),(i64)(*_bracket__ref_Array_i8i6459((&(*call).drefCount),0)));
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		return ;
	};
	if(((i64)(&(*(*generate).semantic).intrinsic.castOp)==(i64)function))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
		Visit__ref_FileHandle_ref_Type((*generate).impl,(*call).super.typ);
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6460((&(*call).params.list),1)),(i64)(*_bracket__ref_Array_i8i6461((&(*call).drefCount),1)));
		return ;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*(*generate).semantic).intrinsic.sizeFn)))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){7, (i8*)"sizeof("}));
		Visit__ref_FileHandle_ref_Type((*generate).impl,(*As_ref_Type_typeofTypeType14((**_bracket__ref_Array__ref_Expri6463((&(*call).params.list),0)).typ)).reference);
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		return ;
	};
	if(((*call).params.list.length==1))	{
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
		Write__ref_FileHandleStr((*generate).impl,(*function).ident);
		Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
		PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6464((&(*call).params.list),0)),(i64)(*_bracket__ref_Array_i8i6465((&(*call).drefCount),0)));
		return ;
	};
	Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)"("}));
	PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6466((&(*call).params.list),0)),(i64)(*_bracket__ref_Array_i8i6467((&(*call).drefCount),0)));
	Write__ref_FileHandleStr((*generate).impl,(*function).ident);
	PerformVisitAutoReference__ref_GenerateBasic_ref_Expri64(generate,(*_bracket__ref_Array__ref_Expri6468((&(*call).params.list),1)),(i64)(*_bracket__ref_Array_i8i6469((&(*call).drefCount),1)));
	Write__ref_FileHandleStr((*generate).impl,((Str){1, (i8*)")"}));
	return ;
}
void Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(Intrinsics* self, Function* func, Semantic* semantic, Str ident, Type* t, Type* r){
	Init__ref_Function(func);
	Variable* field=New_typeofVariable41();
	(*field).super.typ=t;
	(*func).ident=ident;
	Add__ref_ExpressionList_ref_Expr((&(*func).params),(&(*field).super));
	Add__ref_ExpressionList_ref_Expr((&(*func).params),(&(*field).super));
	(*func).result=r;
	Declare__ref_Semantic_ref_Expr(semantic,(&(*func).super));
}
void Convert__ref_Intrinsics_ref_Semantic_ref_Function_ref_Structure_ref_Structure(Intrinsics* self, Semantic* semantic, Function* func, Structure* from, Structure* to){
	Variable* field=New_typeofVariable42();
	(*field).super.typ=(*from).typeIdent;
	assert_ref_TypeStr2((*from).typeIdent,(*from).ident);
	Init__ref_Function(func);
	(*func).ident=(*to).ident;
	Add__ref_ExpressionList_ref_Expr((&(*func).params),(&(*field).super));
	(*func).result=(*to).typeIdent;
	Declare__ref_Semantic_ref_Expr(semantic,(&(*func).super));
}
void Init__ref_Intrinsics_ref_Semantic_ref_Block(Intrinsics* self, Semantic* semantic, Block* ast){
	Init__ref_Structure((&(*self).voidptr_));
	(*self).voidptr_.ident=((Str){7, (i8*)"voidptr"});
	Declare__ref_Semantic_ref_Expr(semantic,(&(*self).voidptr_.super));
	(*self).voidptr_.incomplete=true;
		{
		TypeAs* as=New_typeofTypeAs43();
		(*as).ident=((Str){2, (i8*)"i8"});
		(*as).super.typ=(&(*i8Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs44();
		(*as).ident=((Str){3, (i8*)"i16"});
		(*as).super.typ=(&(*i16Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs45();
		(*as).ident=((Str){3, (i8*)"i32"});
		(*as).super.typ=(&(*i32Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs46();
		(*as).ident=((Str){3, (i8*)"i64"});
		(*as).super.typ=(&(*i64Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs47();
		(*as).ident=((Str){2, (i8*)"u8"});
		(*as).super.typ=(&(*u8Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs48();
		(*as).ident=((Str){3, (i8*)"u16"});
		(*as).super.typ=(&(*u16Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs49();
		(*as).ident=((Str){3, (i8*)"u32"});
		(*as).super.typ=(&(*u32Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs50();
		(*as).ident=((Str){3, (i8*)"u64"});
		(*as).super.typ=(&(*u64Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs51();
		(*as).ident=((Str){3, (i8*)"f32"});
		(*as).super.typ=(&(*f32Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
		{
		TypeAs* as=New_typeofTypeAs52();
		(*as).ident=((Str){3, (i8*)"f64"});
		(*as).super.typ=(&(*f64Type).super);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
	};
	TypeAny* any=New_typeofTypeAny53();
	(*any).ident=((Str){1, (i8*)"T"});
	Variable* any_field=New_typeofVariable54();
	(*any_field).super.typ=(&(*any).super);
	Variable* i64_field=New_typeofVariable55();
	(*i64_field).super.typ=(&(*i64Type).super);
	Init__ref_Function((&(*self).ptr_add));
	(*self).ptr_add.ident=((Str){6, (i8*)"PtrAdd"});
	Add__ref_ExpressionList_ref_Expr((&(*self).ptr_add.params),(&(*any_field).super));
	Add__ref_ExpressionList_ref_Expr((&(*self).ptr_add.params),(&(*i64_field).super));
	(*self).ptr_add.result=(&(*any).super);
	Add__ref_Block_ref_Expr(ast,(&(*self).ptr_add.super));
		{
		TypeAny* any=New_typeofTypeAny56();
		(*any).ident=((Str){1, (i8*)"T"});
		Variable* any_field=New_typeofVariable57();
		(*any_field).super.typ=(&(*any).super);
		TypeRef* refer=New_typeofTypeRef58();
		(*refer).reference=(&(*any).super);
		Init__ref_Function((&(*self).reference));
		(*self).reference.ident=((Str){1, (i8*)"&"});
		Add__ref_ExpressionList_ref_Expr((&(*self).reference.params),(&(*any_field).super));
		(*self).reference.result=(&(*refer).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).reference.super));
	};
		{
		TypeAny* any=New_typeofTypeAny59();
		(*any).ident=((Str){1, (i8*)"T"});
		TypeRef* refer=New_typeofTypeRef60();
		(*refer).reference=(&(*any).super);
		Variable* param=New_typeofVariable61();
		(*param).super.typ=(&(*refer).super);
		TypeIdentifier* ident=New_typeofTypeIdentifier62();
		(*ident).ident=((Str){1, (i8*)"T"});
		Init__ref_Function((&(*self).dereference));
		(*self).dereference.ident=((Str){4, (i8*)"dref"});
		Add__ref_ExpressionList_ref_Expr((&(*self).dereference.params),(&(*param).super));
		(*self).dereference.result=(&(*any).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).dereference.super));
	};
		{
		TypeAny* in=New_typeofTypeAny63();
		(*in).ident=((Str){2, (i8*)"To"});
		TypeType* inOf=New_typeofTypeType64();
		(*inOf).reference=(&(*in).super);
		Variable* toParam=New_typeofVariable65();
		(*toParam).super.typ=(&(*inOf).super);
		TypeAny* out=New_typeofTypeAny66();
		(*out).ident=((Str){4, (i8*)"From"});
		Variable* fromParam=New_typeofVariable67();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).castOp));
		(*self).castOp.ident=((Str){4, (i8*)"cast"});
		Add__ref_ExpressionList_ref_Expr((&(*self).castOp.params),(&(*toParam).super));
		Add__ref_ExpressionList_ref_Expr((&(*self).castOp.params),(&(*fromParam).super));
		(*self).castOp.result=(&(*in).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).castOp.super));
	};
		{
		TypeAny* in=New_typeofTypeAny68();
		(*in).ident=((Str){1, (i8*)"T"});
		TypeType* inOf=New_typeofTypeType69();
		(*inOf).reference=(&(*in).super);
		Variable* toParam=New_typeofVariable70();
		(*toParam).super.typ=(&(*inOf).super);
		Init__ref_Function((&(*self).sizeFn));
		(*self).sizeFn.ident=((Str){4, (i8*)"Size"});
		Add__ref_ExpressionList_ref_Expr((&(*self).sizeFn.params),(&(*toParam).super));
		(*self).sizeFn.result=(&(*i64Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).sizeFn.super));
	};
	Init__ref_Function((&(*self).abortFn));
	(*self).abortFn.ident=((Str){5, (i8*)"abort"});
	Declare__ref_Semantic_ref_Expr(semantic,(&(*self).abortFn.super));
		{
		TypeAny* out=New_typeofTypeAny71();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable72();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_i8));
		(*self).to_i8.ident=((Str){2, (i8*)"i8"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_i8.params),(&(*fromParam).super));
		(*self).to_i8.result=(&(*i8Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_i8.super));
	};
		{
		TypeAny* out=New_typeofTypeAny73();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable74();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_i16));
		(*self).to_i16.ident=((Str){3, (i8*)"i16"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_i16.params),(&(*fromParam).super));
		(*self).to_i16.result=(&(*i16Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_i16.super));
	};
		{
		TypeAny* out=New_typeofTypeAny75();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable76();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_i32));
		(*self).to_i32.ident=((Str){3, (i8*)"i32"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_i32.params),(&(*fromParam).super));
		(*self).to_i32.result=(&(*i32Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_i32.super));
	};
		{
		TypeAny* out=New_typeofTypeAny77();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable78();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_i64));
		(*self).to_i64.ident=((Str){3, (i8*)"i64"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_i64.params),(&(*fromParam).super));
		(*self).to_i64.result=(&(*i64Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_i64.super));
	};
		{
		TypeAny* out=New_typeofTypeAny79();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable80();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_u8));
		(*self).to_u8.ident=((Str){2, (i8*)"u8"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_u8.params),(&(*fromParam).super));
		(*self).to_u8.result=(&(*u8Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_u8.super));
	};
		{
		TypeAny* out=New_typeofTypeAny81();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable82();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_u16));
		(*self).to_u16.ident=((Str){3, (i8*)"u16"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_u16.params),(&(*fromParam).super));
		(*self).to_u16.result=(&(*u16Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_u16.super));
	};
		{
		TypeAny* out=New_typeofTypeAny83();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable84();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_u32));
		(*self).to_u32.ident=((Str){3, (i8*)"u32"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_u32.params),(&(*fromParam).super));
		(*self).to_u32.result=(&(*u32Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_u32.super));
	};
		{
		TypeAny* out=New_typeofTypeAny85();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable86();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_u64));
		(*self).to_u64.ident=((Str){3, (i8*)"u64"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_u64.params),(&(*fromParam).super));
		(*self).to_u64.result=(&(*u64Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_u64.super));
	};
		{
		TypeAny* out=New_typeofTypeAny87();
		(*out).ident=((Str){4, (i8*)"From"});
		(*out).required=Id__typeofTypeNumber();
		Variable* fromParam=New_typeofVariable88();
		(*fromParam).super.typ=(&(*out).super);
		Init__ref_Function((&(*self).to_f32));
		(*self).to_f32.ident=((Str){3, (i8*)"f32"});
		Add__ref_ExpressionList_ref_Expr((&(*self).to_f32.params),(&(*fromParam).super));
		(*self).to_f32.result=(&(*f32Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).to_f32.super));
	};
		{
		Variable* fromParam=New_typeofVariable89();
		(*fromParam).super.typ=(&(*i8Type).super);
		Init__ref_Function((&(*self).invert));
		(*self).invert.ident=((Str){1, (i8*)"!"});
		Add__ref_ExpressionList_ref_Expr((&(*self).invert.params),(&(*fromParam).super));
		(*self).invert.result=(&(*i8Type).super);
		Add__ref_Block_ref_Expr(ast,(&(*self).invert.super));
	};
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).mul_f32),semantic,((Str){1, (i8*)"*"}),(&(*f32Type).super),(&(*f32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).add_f32),semantic,((Str){1, (i8*)"+"}),(&(*f32Type).super),(&(*f32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).sub_f32),semantic,((Str){1, (i8*)"-"}),(&(*f32Type).super),(&(*f32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).div_f32),semantic,((Str){1, (i8*)"/"}),(&(*f32Type).super),(&(*f32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).mod_f32),semantic,((Str){1, (i8*)"%"}),(&(*f32Type).super),(&(*f32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).mul_i64),semantic,((Str){1, (i8*)"*"}),(&(*i64Type).super),(&(*i64Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).add_i64),semantic,((Str){1, (i8*)"+"}),(&(*i64Type).super),(&(*i64Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).sub_i64),semantic,((Str){1, (i8*)"-"}),(&(*i64Type).super),(&(*i64Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).div_i64),semantic,((Str){1, (i8*)"/"}),(&(*i64Type).super),(&(*i64Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).mod_i64),semantic,((Str){1, (i8*)"%"}),(&(*i64Type).super),(&(*i64Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).mul_i32),semantic,((Str){1, (i8*)"*"}),(&(*i32Type).super),(&(*i32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).add_i32),semantic,((Str){1, (i8*)"+"}),(&(*i32Type).super),(&(*i32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).sub_i32),semantic,((Str){1, (i8*)"-"}),(&(*i32Type).super),(&(*i32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).div_i32),semantic,((Str){1, (i8*)"/"}),(&(*i32Type).super),(&(*i32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).mod_i32),semantic,((Str){1, (i8*)"%"}),(&(*i32Type).super),(&(*i32Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).notEq),semantic,((Str){2, (i8*)"!="}),(&(*i64Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).isEq),semantic,((Str){2, (i8*)"=="}),(&(*i64Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).less),semantic,((Str){1, (i8*)"<"}),(&(*i64Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).lessEq),semantic,((Str){2, (i8*)"<="}),(&(*i64Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).greater),semantic,((Str){1, (i8*)">"}),(&(*i64Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).greaterEq),semantic,((Str){2, (i8*)">="}),(&(*i64Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).and_),semantic,((Str){2, (i8*)"&&"}),(&(*i8Type).super),(&(*i8Type).super));
	Create__ref_Intrinsics_ref_Function_ref_SemanticStr_ref_Type_ref_Type(self,(&(*self).or_),semantic,((Str){2, (i8*)"||"}),(&(*i8Type).super),(&(*i8Type).super));
	Array__ref_TypeNumber types={0};
	Init_ref_Array__ref_TypeNumberi641((&types),10);
	*_bracket__ref_Array__ref_TypeNumberi6470((&types),0)=u8Type;
	*_bracket__ref_Array__ref_TypeNumberi6471((&types),1)=u16Type;
	*_bracket__ref_Array__ref_TypeNumberi6472((&types),2)=u32Type;
	*_bracket__ref_Array__ref_TypeNumberi6473((&types),3)=u64Type;
	*_bracket__ref_Array__ref_TypeNumberi6474((&types),4)=i8Type;
	*_bracket__ref_Array__ref_TypeNumberi6475((&types),5)=i16Type;
	*_bracket__ref_Array__ref_TypeNumberi6476((&types),6)=i32Type;
	*_bracket__ref_Array__ref_TypeNumberi6477((&types),7)=i64Type;
	*_bracket__ref_Array__ref_TypeNumberi6478((&types),8)=f32Type;
	*_bracket__ref_Array__ref_TypeNumberi6479((&types),9)=f64Type;
	Init_ref_Array_Functioni642((&(*self).to_),(10*10));
	i64 at={0};
	for(i64 it=(i64)0; (it<10); it=(it+1))	{
		TypeNumber* to=*_bracket__ref_Array__ref_TypeNumberi6480((&types),it);
		Str name=(*to).ident;
		for(i64 it=(i64)0; (it<10); it=(it+1))		{
			TypeNumber* from=*_bracket__ref_Array__ref_TypeNumberi6481((&types),it);
			Variable* fromParam=New_typeofVariable90();
			(*fromParam).super.typ=(&(*from).super);
			Init__ref_Function(_bracket__ref_Array_Functioni6483((&(*self).to_),at));
			(*_bracket__ref_Array_Functioni6484((&(*self).to_),at)).ident=name;
			Add__ref_ExpressionList_ref_Expr((&(*_bracket__ref_Array_Functioni6486((&(*self).to_),at)).params),(&(*fromParam).super));
			(*_bracket__ref_Array_Functioni6487((&(*self).to_),at)).result=(&(*to).super);
			Add__ref_Block_ref_Expr(ast,(&(*_bracket__ref_Array_Functioni6488((&(*self).to_),at)).super));
			at=(at+1);
		};
	};
}
i8 IsIntrinsic__ref_Intrinsics_ref_Function(Intrinsics* intrinsics, Function* function){
	if((((i64)function>(i64)(&(*intrinsics).fnBegin))&&((i64)function<(i64)(&(*intrinsics).fnEnd))))	{
		return true;
	};
	if((((i64)function>=(i64)_bracket__ref_Array_Functioni6489((&(*intrinsics).to_),0))&&((i64)function<=(i64)_bracket__ref_Array_Functioni6490((&(*intrinsics).to_),99))))	{
		return true;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*intrinsics).notEq)))	{
		return true;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*intrinsics).isEq)))	{
		return true;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*intrinsics).less)))	{
		return true;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*intrinsics).lessEq)))	{
		return true;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*intrinsics).greater)))	{
		return true;
	};
	if(PtrEqual_ref_Function_ref_Function2(function,(&(*intrinsics).greaterEq)))	{
		return true;
	};
	return false;
}
void Error__ref_ExprStr(Expr* node, Str message){
	PrintError_PositionStr((*node).at,message);
	assert_i8(0);
}
void Error_PositionStr(Position at, Str message){
	PrintError_PositionStr(at,message);
	assert_i8(0);
}
void Init__ref_Semantic_ref_Block(Semantic* semantic, Block* ast){
	Push_ref_Array__ref_Block_ref_Block7((&(*semantic).scopes),ast);
	Init__ref_Intrinsics_ref_Semantic_ref_Block((&(*semantic).intrinsic),semantic,ast);
	for(i64 it=(i64)0; (it<(*ast).expressions.length); it=(it+1))	{
		Expr* expr=*_bracket__ref_Array__ref_Expri6491((&(*ast).expressions),it);
		Declare__ref_Semantic_ref_Expr(semantic,expr);
	};
	for(i64 it=(i64)0; (it<(*ast).expressions.length); it=(it+1))	{
		Expr* expr=*_bracket__ref_Array__ref_Expri6492((&(*ast).expressions),it);
		if(Is_ref_Expr_typeofStructure2(expr))		{
			Visit__ref_Semantic_ref_Expr(semantic,expr);
		}else if(Is_ref_Expr_typeofVariable3(expr))		{
			(*As_ref_Expr_typeofVariable24(expr)).global=true;
		};
	};
	for(i64 it=(i64)0; (it<(*ast).expressions.length); it=(it+1))	{
		Expr* expr=*_bracket__ref_Array__ref_Expri6493((&(*ast).expressions),it);
		if(Is_ref_Expr_typeofFunction5(expr))		{
			Function* self=As_ref_Expr_typeofFunction25(expr);
			if(_notEq__ref_Block_typeofNil5((*self).block))			{
				(*(*self).block).parent=self;
				if(_eq__ref_Block_typeofNil4((*(*self).block).outer))				{
					(*(*self).block).outer=(*Last_ref_Array__ref_Block3((&(*semantic).scopes)));
					assert_i8(((i64)(&(*self).block)!=(i64)(*(*self).block).outer));
				};
				Push_ref_Array__ref_Block_ref_Block8((&(*semantic).scopes),(*self).block);
				for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))				{
					Variable* variable=As_ref_Expr_typeofVariable26((*_bracket__ref_Array__ref_Expri6495((&(*self).params.list),it)));
					if(!Is_ref_Type_typeofTypeType3((*variable).super.typ))					{
						Declare__ref_Semantic_ref_Expr(semantic,(&(*variable).super));
					};
					AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*variable).super.typ,self);
				};
				if(_notEq__ref_Type_typeofNil3((*self).result))				{
					AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*self).result,self);
				};
				Pop_ref_Array__ref_Block2((&(*semantic).scopes));
			}else			{
				for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))				{
					Variable* variable=As_ref_Expr_typeofVariable27((*_bracket__ref_Array__ref_Expri6497((&(*self).params.list),it)));
					AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*variable).super.typ,self);
				};
				if(_notEq__ref_Type_typeofNil3((*self).result))				{
					AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*self).result,self);
				};
			};
		};
	};
	for(i64 it=(i64)0; (it<(*ast).expressions.length); it=(it+1))	{
		Expr* expr=*_bracket__ref_Array__ref_Expri6498((&(*ast).expressions),it);
		if(Is_ref_Expr_typeofVariable3(expr))		{
			Visit__ref_Semantic_ref_Expr(semantic,expr);
		};
	};
	Pop_ref_Array__ref_Block2((&(*semantic).scopes));
	Visit__ref_Semantic_ref_Expr(semantic,(&(*ast).super));
	Push_ref_Array__ref_Block_ref_Block9((&(*semantic).scopes),ast);
	Println_Str(((Str){22, (i8*)"Finished semantic pass"}));
}
i8 Implements__ref_Semantic_ref_Trait_ref_Type(Semantic* semantic, Trait* trai, Type* typ){
	(*trai).typeTrait.reference=typ;
	i8 implements=true;
	for(i64 it=(i64)0; (it<(*trai).required.length); it=(it+1))	{
		Function* function=*_bracket__ref_Array__ref_Functioni6499((&(*trai).required),it);
		if(_eq__ref_Function_typeofNil5(FindMatch__ref_Semantic_ref_ExprStr_ref_ExpressionList(semantic,(&(*trai).super),(*function).ident,(&(*function).params))))		{
			implements=false;
		};
	};
	(*trai).typeTrait.reference=(Type*)0;
	return implements;
}
TypeFunctions* FindMatches__ref_Semantic_ref_ExprStr_ref_ExpressionList(Semantic* semantic, Expr* self, Str ident, ExpressionList* args){
	Block* scope=*Last_ref_Array__ref_Block4((&(*semantic).scopes));
	while(scope)	{
		TypeFunctions* expr=LookupFns__ref_BlockStr(scope,ident);
		if(_notEq__ref_TypeFunctions_typeofNil8(expr))		{
			return expr;
		};
		scope=(*scope).outer;
	};
	Error__ref_ExprStr(self,_add__StrStr(((Str){24, (i8*)"No known function named "}),ident));
	return (TypeFunctions*)0;
}
Function* FindMatch__ref_Semantic_ref_ExprStr_ref_ExpressionList(Semantic* semantic, Expr* self, Str ident, ExpressionList* args){
	TypeFunctions* funcs=FindMatches__ref_Semantic_ref_ExprStr_ref_ExpressionList(semantic,self,ident,args);
	Function* found={0};
	Known foundKnown={0};
	for(i64 it=(i64)0; (it<(*funcs).functions.length); it=(it+1))	{
		Function* f=*_bracket__ref_Array__ref_Functioni64100((&(*funcs).functions),it);
		if((((*f).params.list.length==(*args).list.length)&&!(*f).traitFunction))		{
			i8 matched=1;
			Known known={0};
			Init_ref_Array_i8i643((&known.drefCount),(*args).list.length);
			for(i64 it=(i64)0; (it<(*f).params.list.length); it=(it+1))			{
				if((Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(**_bracket__ref_Array__ref_Expri64101((&(*args).list),it)).typ,(**_bracket__ref_Array__ref_Expri64102((&(*f).params.list),it)).typ,(&known),it)==0))				{
					if((Coerce__ref_Expr_ref_Expri8((*_bracket__ref_Array__ref_Expri64103((&(*f).params.list),it)),(*_bracket__ref_Array__ref_Expri64104((&(*args).list),it)),false)==0))					{
						matched=0;
					};
				};
			};
			if(matched)			{
				found=f;
				foundKnown=known;
			};
		};
	};
	return found;
}
Expr* FindType__ref_SemanticStrPosition(Semantic* semantic, Str ident, Position at){
	Expr* expr=FindPrivate__ref_SemanticStr(semantic,ident);
	if(_eq__ref_Expr_typeofNil1(expr))	{
		Error_PositionStr(at,_add__StrStr(((Str){20, (i8*)"No known type named "}),ident));
	};
	return expr;
}
Expr* FindVariable__ref_SemanticStrPosition(Semantic* semantic, Str ident, Position at){
	Expr* expr=FindPrivate__ref_SemanticStr(semantic,ident);
	if(_eq__ref_Expr_typeofNil1(expr))	{
		Error_PositionStr(at,_add__StrStr(((Str){24, (i8*)"No known variable named "}),ident));
	};
	return expr;
}
Expr* FindPrivate__ref_SemanticStr(Semantic* semantic, Str ident){
	Block* scope=*Last_ref_Array__ref_Block5((&(*semantic).scopes));
	while(scope)	{
		if(_notEq__ref_Function_typeofNil2((*scope).parent))		{
			Print_Str((*(*scope).parent).ident);
		};
		Println_Str(_add__StrStr(_add__StrStr(_add__StrStr(((Str){2, (i8*)"--"}),ident),((Str){2, (i8*)"--"})),String_i64((*scope).variables.length)));
		Expr* expr=*_bracket__ref_Table_Str_ref_ExprStr14((&(*scope).variables),ident);
		if(_notEq__ref_Expr_typeofNil1(expr))		{
			return expr;
		};
		if(_eq__ref_Expr_typeofNil1(expr))		{
			assert_i8(_eq__ref_Expr_typeofNil1((*_bracket__ref_Table_Str_ref_ExprStr16((&(*scope).variables),ident))));
		};
		scope=(*scope).outer;
	};
	return (Expr*)0;
}
void Declare__ref_Block_ref_Expr(Block* block, Expr* expr){
	if(Is_ref_Expr_typeofStructure2(expr))	{
		Structure* self=As_ref_Expr_typeofStructure28(expr);
		(*As_ref_Type_typeofTypeIdentifier15((*self).typeIdent)).ident=(*self).ident;
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		Println_Str((*self).ident);
		Insert__ref_BlockStr_ref_Expr(block,(*self).ident,expr);
	}else if(Is_ref_Expr_typeofFunction5(expr))	{
		Function* self=As_ref_Expr_typeofFunction29(expr);
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		InsertFn__ref_BlockStr_ref_Function(block,(*self).ident,self);
	}else if(Is_ref_Expr_typeofVariable3(expr))	{
		Variable* self=As_ref_Expr_typeofVariable30(expr);
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		Insert__ref_BlockStr_ref_Expr(block,(*self).ident,expr);
	}else if(Is_ref_Expr_typeofTrait15(expr))	{
		Trait* self=As_ref_Expr_typeofTrait31(expr);
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		Insert__ref_BlockStr_ref_Expr(block,(*self).ident,expr);
		for(i64 it=(i64)0; (it<(*self).required.length); it=(it+1))		{
			Add__ref_Block_ref_Expr(block,(&(**_bracket__ref_Array__ref_Functioni64105((&(*self).required),it)).super));
		};
	}else if(Is_ref_Expr_typeofTypeAs7(expr))	{
		TypeAs* self=As_ref_Expr_typeofTypeAs32(expr);
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		Insert__ref_BlockStr_ref_Expr(block,(*self).ident,expr);
	}else	{
		assert_i8Str(0,((Str){48, (i8*)"Expected Structure, Function, Trait, or Variable"}));
	};
}
void Declare__ref_Semantic_ref_Expr(Semantic* semantic, Expr* expr){
	Declare__ref_Block_ref_Expr((*Last_ref_Array__ref_Block7((&(*semantic).scopes))),expr);
}
i64 DrefCount__ref_Type_ref_Type(Type* desired, Type* from){
	Type* typeLeft=Resolved__ref_Type(desired);
	Type* typeRight=Resolved__ref_Type(from);
	i32 count={0};
	if(!Equal__ref_Type_ref_Typei8(typeRight,typeLeft,false))	{
		if(Is_ref_Type_typeofTypeRef4(typeLeft))		{
			typeLeft=Resolved__ref_Type((*As_ref_Type_typeofTypeRef17(typeLeft)).reference);
			count=(count-1);
		};
	};
	return count;
}
i64 CheckAssignment__ref_Expr_ref_Type_ref_Expr(Expr* self, Type* desired, Expr* from){
	if(_eq__ref_Expr_typeofNil1(from))	{
		if(_notEq__ref_Type_typeofNil3(desired))		{
			Error__ref_ExprStr(self,_add__StrStr(((Str){75, (i8*)"Cannot return a value of () from a from a function that requires return of "}),String__ref_Type(desired)));
		};
		return 0;
	};
	if(_eq__ref_Type_typeofNil2(desired))	{
		Error__ref_ExprStr(self,((Str){67, (i8*)"Cannot return a value from a from a function without a return value"}));
	};
	Type* typeRight=Resolved__ref_Type((*from).typ);
	Type* typeLeft=Resolved__ref_Type(desired);
	i32 count={0};
	if(!Equal__ref_Type_ref_Typei8(typeRight,typeLeft,false))	{
		if(Is_ref_Type_typeofTypeRef4(typeRight))		{
			typeRight=Resolved__ref_Type((*As_ref_Type_typeofTypeRef19(typeRight)).reference);
			count=(count-1);
		};
	}else	{
		return 0;
	};
	if(!Equal__ref_Type_ref_Typei8(typeRight,typeLeft,false))	{
		i32 value=Coerce__ref_Type_ref_Expri8(typeLeft,from,true);
		if((value==0))		{
			Error__ref_ExprStr(self,_add__StrStr(_add__StrStr(String__ref_Type(desired),((Str){30, (i8*)" cannot be assigned a type of "})),String__ref_Type((*from).typ)));
		};
	};
	return count;
}
void Visit__ref_Semantic_ref_Expr(Semantic* semantic, Expr* expr){
	if(Is_ref_Expr_typeofBlock4(expr))	{
		Block* self=As_ref_Expr_typeofBlock33(expr);
		if(((*semantic).scopes.length>0))		{
			if(_eq__ref_Block_typeofNil4((*self).outer))			{
				(*self).outer=(*Last_ref_Array__ref_Block9((&(*semantic).scopes)));
				assert_i8(((i64)self!=(i64)(*self).outer));
			};
		};
		Push_ref_Array__ref_Block_ref_Block10((&(*semantic).scopes),self);
		for(i64 it=(i64)0; (it<(*self).expressions.length); it=(it+1))		{
			Expr* expr=*_bracket__ref_Array__ref_Expri64106((&(*self).expressions),it);
			Visit__ref_Semantic_ref_Expr(semantic,expr);
		};
		Pop_ref_Array__ref_Block2((&(*semantic).scopes));
		return ;
	};
	if(Is_ref_Expr_typeofStructure2(expr))	{
		Structure* self=As_ref_Expr_typeofStructure34(expr);
		if((((*self).state==Visiting)||((*self).state==Visited)))		{
			return ;
		};
		i32 isNew=(*self).state;
		(*self).state=Visiting;
		(*self).block.outer=(*Last_ref_Array__ref_Block11((&(*semantic).scopes)));
		assert_i8(((i64)(&(*self).block)!=(i64)(*self).block.outer));
		Push_ref_Array__ref_Block_ref_Block11((&(*semantic).scopes),(&(*self).block));
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			TypeAny* any=As_ref_Type_typeofTypeAny20((*_bracket__ref_Array__ref_Typei64108((&(*self).constraints),it)));
			TypeAs* as=New_typeofTypeAs91();
			(*as).super.typ=(&(*any).super);
			(*as).ident=(*any).ident;
			Declare__ref_Semantic_ref_Expr(semantic,(&(*as).super));
		};
		for(i64 it=(i64)0; (it<(*self).fields.length); it=(it+1))		{
			Push_ref_Array__ref_Type_ref_Type12((&(*self).typeStructure.fields),(**_bracket__ref_Array__ref_Variablei64109((&(*self).fields),it)).super.typ);
		};
		(*self).typeStructure.constraints=(*self).constraints;
		for(i64 it=(i64)0; (it<(*self).fields.length); it=(it+1))		{
			Visit__ref_Semantic_ref_Expr(semantic,(&(**_bracket__ref_Array__ref_Variablei64110((&(*self).fields),it)).super));
		};
		Pop_ref_Array__ref_Block2((&(*semantic).scopes));
		if((isNew==Declared))		{
			Push_ref_Array__ref_Structure_ref_Structure13((&(*semantic).structures),self);
			if(((*self).constraints.length==0))			{
				Push_ref_Array__ref_TypeStructure_ref_TypeStructure14((&structures),(&(*self).typeStructure));
			};
			Println_Str((*self).ident);
		};
		(*self).state=Visited;
		return ;
	};
	if(Is_ref_Expr_typeofFunction5(expr))	{
		Function* self=As_ref_Expr_typeofFunction35(expr);
		if(_notEq__ref_Block_typeofNil5((*self).block))		{
			(*(*self).block).parent=self;
			if(_eq__ref_Block_typeofNil4((*(*self).block).outer))			{
				(*(*self).block).outer=(*Last_ref_Array__ref_Block13((&(*semantic).scopes)));
				assert_i8(((i64)(&(*self).block)!=(i64)(*(*self).block).outer));
			};
			Push_ref_Array__ref_Block_ref_Block15((&(*semantic).scopes),(*self).block);
			for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))			{
				Variable* variable=As_ref_Expr_typeofVariable36((*_bracket__ref_Array__ref_Expri64112((&(*self).params.list),it)));
				Annotate__ref_Semantic_ref_Type(semantic,(*variable).super.typ);
			};
			if(_notEq__ref_Type_typeofNil3((*self).result))			{
				Annotate__ref_Semantic_ref_Type(semantic,(*self).result);
			};
			Pop_ref_Array__ref_Block2((&(*semantic).scopes));
			Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).block).super));
		}else		{
			for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))			{
				Variable* variable=As_ref_Expr_typeofVariable37((*_bracket__ref_Array__ref_Expri64114((&(*self).params.list),it)));
				Annotate__ref_Semantic_ref_Type(semantic,(*variable).super.typ);
			};
			if(_notEq__ref_Type_typeofNil3((*self).result))			{
				Annotate__ref_Semantic_ref_Type(semantic,(*self).result);
			};
		};
		return ;
	};
	if(Is_ref_Expr_typeofVariable3(expr))	{
		Variable* self=As_ref_Expr_typeofVariable38(expr);
		Declare__ref_Semantic_ref_Expr(semantic,(&(*self).super));
		Annotate__ref_Semantic_ref_Type(semantic,(*self).super.typ);
		if(_notEq__ref_Expr_typeofNil1((*self).assign))		{
			Visit__ref_Semantic_ref_Expr(semantic,(*self).assign);
			(*self).drefCount=(0-CheckAssignment__ref_Expr_ref_Type_ref_Expr((&(*self).super),(*self).super.typ,(*self).assign));
		};
		return ;
	};
	if(Is_ref_Expr_typeofIdentifier12(expr))	{
		Identifier* self=As_ref_Expr_typeofIdentifier39(expr);
		if(_eq__StrStr((*self).ident,((Str){0, (i8*)""})))		{
			assert_ref_Type1((*self).super.typ);
			Annotate__ref_Semantic_ref_Type(semantic,(*self).super.typ);
			return ;
		};
		Expr* referenced=FindVariable__ref_SemanticStrPosition(semantic,(*self).ident,(*self).super.at);
		(*self).reference=referenced;
		if(Is_ref_Expr_typeofTypeAs7(referenced))		{
			TypeType* t=New_typeofTypeType92();
			(*t).reference=(*referenced).typ;
			(*self).super.typ=(&(*t).super);
		}else		{
			(*self).super.typ=(*referenced).typ;
		};
		assert_ref_TypeStr2((*self).super.typ,((Str){25, (i8*)"Expect type to be non nil"}));
		return ;
	};
	if(Is_ref_Expr_typeofAccess13(expr))	{
		Access* self=As_ref_Expr_typeofAccess40(expr);
		Visit__ref_Semantic_ref_Expr(semantic,(*self).operand);
		Type* typ=Resolved__ref_Type((*(*self).operand).typ);
		while(Is_ref_Type_typeofTypeRef4(typ))		{
			typ=(*As_ref_Type_typeofTypeRef21(typ)).reference;
		};
		TypeStructure* spec=ResolveSpec__ref_Type(typ);
		if((Is_ref_Type_typeofTypeIdentifier5(typ)&&Is_ref_Expr_typeofStructure2((*As_ref_Type_typeofTypeIdentifier23(typ)).spec)))		{
			Structure* structure=As_ref_Expr_typeofStructure41((*As_ref_Type_typeofTypeIdentifier25(typ)).spec);
			Variable* variable=Lookup__ref_StructureStr(structure,(*self).field);
			if(_notEq__ref_Variable_typeofNil9(variable))			{
				(*self).super.typ=Clone__ref_Type((*variable).super.typ);
			};
		};
		if(_notEq__ref_TypeStructure_typeofNil10(spec))		{
			TypeStructure* typeStructure=spec;
			(*self).super.typ=Lookup__ref_TypeStructureStr(typeStructure,(*self).field);
		};
		if(_eq__ref_Type_typeofNil2((*self).super.typ))		{
			Identifier* ident=New_typeofIdentifier93();
			(*ident).super.at=(*self).super.at;
			(*ident).ident=(*self).field;
			(*self).call=New_typeofCall94();
			(*(*self).call).super.at=(*self).super.at;
			(*(*self).call).operand=(&(*ident).super);
			Add__ref_ExpressionList_ref_Expr((&(*(*self).call).params),(*self).operand);
			Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).call).super));
			(*self).super.typ=(*(*self).call).super.typ;
			return ;
		};
		assert_ref_TypeStr2((*self).super.typ,_add__StrStr(((Str){27, (i8*)"Could not find field named "}),(*self).field));
		return ;
	};
	if(Is_ref_Expr_typeofCall6(expr))	{
		Call* self=As_ref_Expr_typeofCall42(expr);
		if(Is_ref_Expr_typeofAccess13((*self).operand))		{
			Access* access=As_ref_Expr_typeofAccess43((*self).operand);
			Visit__ref_Semantic_ref_Expr(semantic,(*access).operand);
			Type* typ=Resolved__ref_Type((*(*access).operand).typ);
			TypeStructure* spec=ResolveSpec__ref_Type(typ);
			if(Is_ref_Type_typeofTypeIdentifier5(Resolved__ref_Type((*(*access).operand).typ)))			{
				Structure* structure=As_ref_Expr_typeofStructure44((*As_ref_Type_typeofTypeIdentifier27(Resolved__ref_Type((*(*access).operand).typ))).spec);
				Variable* variable=Lookup__ref_StructureStr(structure,(*access).field);
				if(_notEq__ref_Variable_typeofNil9(variable))				{
					(*access).super.typ=(*variable).super.typ;
				};
			}else if(_notEq__ref_TypeStructure_typeofNil10(spec))			{
				TypeStructure* typeStructure=spec;
				(*self).super.typ=Lookup__ref_TypeStructureStr(typeStructure,(*access).field);
			};
			if(_notEq__ref_Type_typeofNil3((*access).super.typ))			{
				return ;
			};
			Insert_ref_Array__ref_Expri64_ref_Expr1((&(*self).params.list),0,(*access).operand);
			Identifier* ident=New_typeofIdentifier95();
			(*ident).ident=(*access).field;
			(*self).operand=(&(*ident).super);
		};
		if(Is_ref_Expr_typeofIdentifier12((*self).operand))		{
			Visit__ref_Semantic_ref_Expr(semantic,(&(*self).params.super));
			TypeFunctions* funcs=FindMatches__ref_Semantic_ref_ExprStr_ref_ExpressionList(semantic,(&(*self).super),(*As_ref_Expr_typeofIdentifier45((*self).operand)).ident,(&(*self).params));
			Function* found={0};
			Known foundKnown={0};
			i32 foundCount={0};
			for(i64 it=(i64)0; (it<(*funcs).functions.length); it=(it+1))			{
				Function* f=*_bracket__ref_Array__ref_Functioni64115((&(*funcs).functions),it);
				Function* parent=ParentFunction__ref_Block((*Last_ref_Array__ref_Block14((&(*semantic).scopes))));
				i8 ignore=((*f).traitFunction&&!((i64)found==0));
				if((((*f).params.list.length==(*self).params.list.length)&&!ignore))				{
					i8 matched=1;
					Known known={0};
					Init_ref_Array_i8i643((&known.drefCount),(*self).params.list.length);
					for(i64 it=(i64)0; (it<(*f).params.list.length); it=(it+1))					{
						if((Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(**_bracket__ref_Array__ref_Expri64116((&(*self).params.list),it)).typ,(**_bracket__ref_Array__ref_Expri64117((&(*f).params.list),it)).typ,(&known),it)==0))						{
							if((Coerce__ref_Expr_ref_Expri8((*_bracket__ref_Array__ref_Expri64118((&(*f).params.list),it)),(*_bracket__ref_Array__ref_Expri64119((&(*self).params.list),it)),false)==0))							{
								matched=0;
							};
						};
					};
					if(matched)					{
						if((!(*f).traitFunction||((i64)found==0)))						{
							found=f;
							foundKnown=known;
							foundCount=(foundCount+1);
						};
					};
				};
			};
			if(_eq__ref_Function_typeofNil5(found))			{
				Println_Str(((Str){45, (i8*)"---------------------------------------------"}));
				Print_Str((*As_ref_Expr_typeofIdentifier46((*self).operand)).ident);
				Print_Str(((Str){4, (i8*)" fn "}));
				for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))				{
					Print__ref_Type((**_bracket__ref_Array__ref_Expri64120((&(*self).params.list),it)).typ);
					if((it!=((*self).params.list.length-1)))					{
						Print_Str(((Str){2, (i8*)", "}));
					};
				};
				Println_Str(((Str){1, (i8*)")"}));
				Println_Str(((Str){45, (i8*)"-------------------matches-------------------"}));
				for(i64 it=(i64)0; (it<(*funcs).functions.length); it=(it+1))				{
					Print__ref_Expr((&(**_bracket__ref_Array__ref_Functioni64121((&(*funcs).functions),it)).super));
					Println_Str(((Str){0, (i8*)""}));
				};
				Println_Str(((Str){45, (i8*)"---------------------------------------------"}));
				Error__ref_ExprStr((&(*self).super),_add__StrStr(((Str){23, (i8*)"No match for function: "}),(*As_ref_Expr_typeofIdentifier47((*self).operand)).ident));
			};
			for(i64 it=(i64)0; (it<(*found).params.list.length); it=(it+1))			{
				Coerce__ref_Expr_ref_Expri8((*_bracket__ref_Array__ref_Expri64122((&(*found).params.list),it)),(*_bracket__ref_Array__ref_Expri64123((&(*self).params.list),it)),false);
			};
			(*self).drefCount=foundKnown.drefCount;
			if((foundKnown.known.length!=0))			{
				FunctionSpec* spec=Specialize__ref_Function_ref_Semantic_ref_Call_ref_Function_ref_Known(found,semantic,self,(**Last_ref_Array__ref_Block15((&(*semantic).scopes))).parent,(&foundKnown));
				if(_notEq__ref_Function_typeofNil2((**Last_ref_Array__ref_Block16((&(*semantic).scopes))).parent))				{
					if(_notEq__ref_FunctionSpec_typeofNil4((*(**Last_ref_Array__ref_Block17((&(*semantic).scopes))).parent).spec))					{
						if(((*(*(**Last_ref_Array__ref_Block18((&(*semantic).scopes))).parent).spec).incomplete==false))						{
							if(!IsIntrinsic__ref_Intrinsics_ref_Function((&(*semantic).intrinsic),found))							{
								Println_Str(_add__StrStr(_add__StrStr(_add__StrStr(((Str){15, (i8*)"Mismatched inc "}),(*found).ident),((Str){3, (i8*)"   "})),String_i64(foundCount)));
							};
						};
					};
				};
				assert_ref_FunctionSpec2(spec);
				(*self).func=(&(*spec).super);
				FunctionSpec* prev=(*found).spec;
				Apply__ref_FunctionSpec(spec);
				if(_notEq__ref_Type_typeofNil3((*found).result))				{
					(*self).super.typ=Clone__ref_Type(Resolved__ref_Type((*found).result));
				};
				if(_notEq__ref_FunctionSpec_typeofNil4(prev))				{
					Apply__ref_FunctionSpec(prev);
				}else				{
					Clear__ref_FunctionSpec(spec);
				};
				if(!(*spec).incomplete)				{
					for(i64 it=(i64)0; (it<(*spec).known.length); it=(it+1))					{
						TypeAnyResolved t=*_bracket__ref_Array_TypeAnyResolvedi64124((&(*spec).known),it);
						assert_i8((ContainsUnknown__ref_Type(t.typ)==false));
					};
				};
			}else			{
				(*self).func=(&(*found).super);
				(*self).super.typ=(*found).result;
				if(_notEq__ref_Type_typeofNil3((*found).result))				{
					(*self).super.typ=Clone__ref_Type(Resolved__ref_Type((*found).result));
				};
			};
		}else		{
			assert_i8Str(0,((Str){34, (i8*)"Call without identifier as operand"}));
		};
		return ;
	};
	if(Is_ref_Expr_typeofExpressionList1(expr))	{
		ExpressionList* self=As_ref_Expr_typeofExpressionList48(expr);
		assert_ref_ExpressionListStr3(self,((Str){3, (i8*)"nil"}));
		for(i64 it=(i64)0; (it<(*self).list.length); it=(it+1))		{
			assert_ref__ref_ExprStr4(_bracket__ref_Array__ref_Expri64125((&(*self).list),it),((Str){16, (i8*)"nil item in list"}));
			Visit__ref_Semantic_ref_Expr(semantic,(*_bracket__ref_Array__ref_Expri64126((&(*self).list),it)));
			assert_ref_TypeStr2((**_bracket__ref_Array__ref_Expri64127((&(*self).list),it)).typ,((Str){22, (i8*)"Type should be non nil"}));
		};
		return ;
	};
	if(Is_ref_Expr_typeofTrait15(expr))	{
		Trait* self=As_ref_Expr_typeofTrait49(expr);
		return ;
	};
	if(Is_ref_Expr_typeofNumberConstant16(expr))	{
		NumberConstant* self=As_ref_Expr_typeofNumberConstant50(expr);
		for(i64 it=(i64)0; (it<(*self).value.length); it=(it+1))		{
			if(((*((*self).value.chars+it))==Char_Str(((Str){1, (i8*)"."}))))			{
				(*self).super.typ=(&(*i64Type).super);
				return ;
			};
		};
		i64 num=i64FromString_Str((*self).value);
		if(((num<=127)&&(num>=(0-127))))		{
			(*self).super.typ=(&(*i8Type).super);
		}else if(((num<=32767)&&(num>=(0-32767))))		{
			(*self).super.typ=(&(*i16Type).super);
		}else if(((num<=2147483647)&&(num>=(0-2147483647))))		{
			(*self).super.typ=(&(*i32Type).super);
		}else		{
			(*self).super.typ=(&(*i64Type).super);
		};
		assert_ref_Type1((*self).super.typ);
		return ;
	};
	if(Is_ref_Expr_typeofStringConstant17(expr))	{
		StringConstant* self=As_ref_Expr_typeofStringConstant51(expr);
		Type* t=(*As_ref_Type_typeofTypeType28((*FindType__ref_SemanticStrPosition(semantic,((Str){3, (i8*)"Str"}),(*self).super.at)).typ)).reference;
		(*self).super.typ=t;
		return ;
	};
	if(Is_ref_Expr_typeofForList9(expr))	{
		ForList* self=As_ref_Expr_typeofForList52(expr);
		Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).list).super));
		if(_eq__ref_Variable_typeofNil6((*self).it))		{
			Variable* variable=New_typeofVariable96();
			(*variable).ident=((Str){2, (i8*)"it"});
			(*variable).super.typ=(**_bracket__ref_Array__ref_Expri64128((&(*(*self).list).list),0)).typ;
			(*self).it=variable;
			Insert_ref_Array__ref_Expri64_ref_Expr2((&(*(*self).block).expressions),0,(&(*variable).super));
		};
		Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).block).super));
		return ;
	};
	if(Is_ref_Expr_typeofFor10(expr))	{
		For* self=As_ref_Expr_typeofFor53(expr);
		Visit__ref_Semantic_ref_Expr(semantic,(*self).from);
		if(_eq__ref_Variable_typeofNil6((*self).it))		{
			Variable* variable=New_typeofVariable97();
			(*variable).ident=((Str){2, (i8*)"it"});
			(*variable).super.typ=(*(*self).from).typ;
			(*self).it=variable;
			Declare__ref_Block_ref_Expr((*self).block,(&(*variable).super));
			(*(*self).it).assign=(*self).from;
		};
		if(_notEq__ref_Expr_typeofNil1((*self).to))		{
			(*(*self).block).outer=(*Last_ref_Array__ref_Block20((&(*semantic).scopes)));
			Push_ref_Array__ref_Block_ref_Block16((&(*semantic).scopes),(*self).block);
			Visit__ref_Semantic_ref_Expr(semantic,(*self).to);
			if(_eq__ref_Call_typeofNil7((*self).test))			{
				Identifier* it=New_typeofIdentifier98();
				(*it).ident=((Str){2, (i8*)"it"});
				(*self).test=New_typeofCall99();
				Identifier* ident=New_typeofIdentifier100();
				(*ident).ident=((Str){1, (i8*)"<"});
				(*(*self).test).operand=(&(*ident).super);
				Push_ref_Array__ref_Expr_ref_Expr17((&(*(*self).test).params.list),(&(*it).super));
				Push_ref_Array__ref_Expr_ref_Expr18((&(*(*self).test).params.list),(*self).to);
			};
			if(_eq__ref_Expr_typeofNil1((*self).inc))			{
				Identifier* ident=New_typeofIdentifier101();
				(*ident).ident=((Str){2, (i8*)"it"});
				NumberConstant* constant=New_typeofNumberConstant102();
				(*constant).value=((Str){1, (i8*)"1"});
				Identifier* add=New_typeofIdentifier103();
				(*add).ident=((Str){1, (i8*)"+"});
				Call* call=New_typeofCall104();
				(*call).operand=(&(*add).super);
				Push_ref_Array__ref_Expr_ref_Expr19((&(*call).params.list),(&(*ident).super));
				Push_ref_Array__ref_Expr_ref_Expr20((&(*call).params.list),(&(*constant).super));
				Assign* assign=New_typeofAssign105();
				(*assign).super.at=(*self).super.at;
				(*assign).left=(&(*ident).super);
				(*assign).right=(&(*call).super);
				(*self).inc=(&(*assign).super);
			};
			Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).test).super));
			Visit__ref_Semantic_ref_Expr(semantic,(*self).inc);
			Pop_ref_Array__ref_Block2((&(*semantic).scopes));
		};
		Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).block).super));
		return ;
	};
	if(Is_ref_Expr_typeofAssign14(expr))	{
		Assign* self=As_ref_Expr_typeofAssign54(expr);
		Visit__ref_Semantic_ref_Expr(semantic,(*self).left);
		Visit__ref_Semantic_ref_Expr(semantic,(*self).right);
		Type* typeLeft=Resolved__ref_Type((*(*self).left).typ);
		Type* typeRight=Resolved__ref_Type((*(*self).right).typ);
		i32 count={0};
		if(!Equal__ref_Type_ref_Typei8(typeRight,typeLeft,false))		{
			if(Is_ref_Type_typeofTypeRef4(typeLeft))			{
				typeLeft=Resolved__ref_Type((*As_ref_Type_typeofTypeRef30(typeLeft)).reference);
				count=(count-1);
			};
		};
		(*self).drefCount=count;
		if(!Equal__ref_Type_ref_Typei8(typeRight,typeLeft,false))		{
			i32 value=Coerce__ref_Type_ref_Expri8(typeLeft,(*self).right,false);
			if((value==0))			{
				Error__ref_ExprStr((&(*self).super),_add__StrStr(_add__StrStr(String__ref_Type((*(*self).left).typ),((Str){30, (i8*)" cannot be assigned a type of "})),String__ref_Type((*(*self).right).typ)));
				(*semantic).error=true;
			};
		};
		return ;
	};
	if(Is_ref_Expr_typeofIf11(expr))	{
		If* self=As_ref_Expr_typeofIf55(expr);
		Visit__ref_Semantic_ref_Expr(semantic,(*self).condition);
		if(!Equal__ref_Type_ref_Type((*(*self).condition).typ,(&(*i8Type).super)))		{
			Error__ref_ExprStr((&(*self).super),((Str){63, (i8*)"Expected condition to be of type Bool, did you mean to use \"==\""}));
		};
		Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).trueBranch).super));
		if(_notEq__ref_Block_typeofNil5((*self).falseBranch))		{
			Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).falseBranch).super));
		};
		if(_notEq__ref_If_typeofNil6((*self).falseCondition))		{
			Visit__ref_Semantic_ref_Expr(semantic,(&(*(*self).falseCondition).super));
		};
		return ;
	};
	if(Is_ref_Expr_typeofBranch19(expr))	{
		return ;
	};
	if(Is_ref_Expr_typeofReturn18(expr))	{
		Return* self=As_ref_Expr_typeofReturn56(expr);
		Type* result=(*ParentFunction__ref_Block((*Last_ref_Array__ref_Block21((&(*semantic).scopes))))).result;
		if(_notEq__ref_Expr_typeofNil1((*self).expr))		{
			Visit__ref_Semantic_ref_Expr(semantic,(*self).expr);
		};
		(*self).drefCount=(0-CheckAssignment__ref_Expr_ref_Type_ref_Expr((&(*self).super),result,(*self).expr));
		return ;
	};
	Println_Str(_add__StrStr(((Str){16, (i8*)"Unhandled visit "}),String_i64((*expr).kind)));
}
Function* ParentFunction__ref_Block(Block* block){
	Block* cursor=block;
	while((*cursor).outer)	{
		if(_notEq__ref_Function_typeofNil2((*cursor).parent))		{
			return (*cursor).parent;
		};
		cursor=(*cursor).outer;
	};
	return (*cursor).parent;
}
void AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(Semantic* semantic, Type* t, Function* spec){
	Type* typ=Resolved__ref_Type(t);
	if(Is_ref_Type_typeofTypeAny2(typ))	{
		AddAny__ref_Function_ref_Type(spec,typ);
		return ;
	};
	if(Is_ref_Type_typeofTypeTrait1(typ))	{
		AddAny__ref_Function_ref_Type(spec,typ);
		(*spec).traitFunction=true;
		return ;
	};
	if(Is_ref_Type_typeofTypeRef4(typ))	{
		TypeRef* self=As_ref_Type_typeofTypeRef31(typ);
		AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*self).reference,spec);
		return ;
	};
	if(Is_ref_Type_typeofTypeOption9(typ))	{
		TypeOption* self=As_ref_Type_typeofTypeOption32(typ);
		AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*self).reference,spec);
		return ;
	};
	if(Is_ref_Type_typeofTypeIdentifier5(typ))	{
		TypeIdentifier* self=As_ref_Type_typeofTypeIdentifier33(typ);
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		(*self).spec=FindType__ref_SemanticStrPosition(semantic,(*self).ident,(*spec).super.at);
		if((Is_ref_Expr_typeofStructure2((*self).spec)&&((*As_ref_Expr_typeofStructure57((*self).spec)).state!=Visited)))		{
			Visit__ref_Semantic_ref_Expr(semantic,(*self).spec);
		};
		Type* t=Resolved__ref_Type(typ);
		if(!PtrEqual_ref_Type_ref_Type3(t,typ))		{
			AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,t,spec);
		};
		return ;
	};
	if(Is_ref_Type_typeofTypeGeneric6(typ))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric34(typ);
		AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(&(*(*self).ident).super),spec);
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*_bracket__ref_Array__ref_Typei64129((&(*self).constraints),it)),spec);
		};
		Structure* structure=As_ref_Expr_typeofStructure58((*(*self).ident).spec);
		(*self).referenced=SpecializeStructure__ref_Semantic_ref_TypeStructure_ref_Array__ref_Type(semantic,(&(*structure).typeStructure),(&(*self).constraints));
		return ;
	};
	if(Is_ref_Type_typeofTypeType3(typ))	{
		TypeType* self=As_ref_Type_typeofTypeType35(typ);
		AnnotateGeneric__ref_Semantic_ref_Type_ref_Function(semantic,(*self).reference,spec);
		return ;
	};
	if(Is_ref_Type_typeofTypeNumber8(typ))	{
		return ;
	};
	assert_i8Str(0,_add__StrStr(((Str){29, (i8*)"No annotate generic for type "}),String_i64((*typ).kind)));
}
void Annotate__ref_Semantic_ref_Type(Semantic* semantic, Type* t){
	Annotate__ref_Semantic_ref_Typei8(semantic,t,false);
}
void Annotate__ref_Semantic_ref_Typei8(Semantic* semantic, Type* t, i8 reference){
	Type* typ=Resolved__ref_Type(t);
	if(Is_ref_Type_typeofTypeRef4(typ))	{
		TypeRef* self=As_ref_Type_typeofTypeRef36(typ);
		Annotate__ref_Semantic_ref_Typei8(semantic,(*self).reference,true);
		return ;
	};
	if(Is_ref_Type_typeofTypeIdentifier5(typ))	{
		TypeIdentifier* self=As_ref_Type_typeofTypeIdentifier37(typ);
		assert_i8Str((*(*self).ident.chars),((Str){17, (i8*)"failed in declare"}));
		if(_eq__ref_Expr_typeofNil1((*self).spec))		{
			Position a={0};
			(*self).spec=FindType__ref_SemanticStrPosition(semantic,(*self).ident,a);
			if(!((reference&&Is_ref_Expr_typeofStructure2((*self).spec))&&((*As_ref_Expr_typeofStructure59((*self).spec)).state!=Visited)))			{
				Visit__ref_Semantic_ref_Expr(semantic,(*self).spec);
			};
		};
		return ;
	};
	if(Is_ref_Type_typeofTypeGeneric6(typ))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric38(typ);
		Annotate__ref_Semantic_ref_Type(semantic,(&(*(*self).ident).super));
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			Annotate__ref_Semantic_ref_Typei8(semantic,(*_bracket__ref_Array__ref_Typei64130((&(*self).constraints),it)),reference);
		};
		Structure* structure=As_ref_Expr_typeofStructure60((*(*self).ident).spec);
		(*self).referenced=SpecializeStructure__ref_Semantic_ref_TypeStructure_ref_Array__ref_Type(semantic,(&(*structure).typeStructure),(&(*self).constraints));
		return ;
	};
	if(Is_ref_Type_typeofTypeType3(typ))	{
		TypeType* self=As_ref_Type_typeofTypeType39(typ);
		Annotate__ref_Semantic_ref_Typei8(semantic,(*self).reference,reference);
		return ;
	};
	if(Is_ref_Type_typeofTypeOption9(typ))	{
		TypeOption* self=As_ref_Type_typeofTypeOption40(typ);
		Annotate__ref_Semantic_ref_Typei8(semantic,(*self).reference,reference);
		return ;
	};
	if(Is_ref_Type_typeofTypeNumber8(typ))	{
		return ;
	};
	if(Is_ref_Type_typeofTypeAny2(typ))	{
		return ;
	};
	if(Is_ref_Type_typeofTypeTrait1(typ))	{
		return ;
	};
	if(Is_ref_Type_typeofTypeStructure7(typ))	{
		return ;
	};
	assert_i8Str(0,_add__StrStr(((Str){30, (i8*)"No semantic annotate for type "}),String_i64((*typ).kind)));
}
Type* Clone__ref_Type(Type* t){
	Type* expr=Resolved__ref_Type(t);
	if(Is_ref_Type_typeofTypeRef4(expr))	{
		TypeRef* self=As_ref_Type_typeofTypeRef41(expr);
		TypeRef* out=New_typeofTypeRef106();
		(*out).reference=Clone__ref_Type((*self).reference);
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeIdentifier5(expr))	{
		TypeIdentifier* self=As_ref_Type_typeofTypeIdentifier42(expr);
		if(Is_ref_Expr_typeofTypeAs7((*self).spec))		{
			assert_i8(0);
			return Clone__ref_Type((*As_ref_Expr_typeofTypeAs62((*self).spec)).super.typ);
		};
		if(Is_ref_Expr_typeofTrait15((*self).spec))		{
			assert_i8(0);
			return Clone__ref_Type((*As_ref_Expr_typeofTrait64((*self).spec)).super.typ);
		};
		TypeIdentifier* out=New_typeofTypeIdentifier107();
		(*out).ident=(*self).ident;
		(*out).spec=(*self).spec;
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeAny2(expr))	{
		TypeAny* self=As_ref_Type_typeofTypeAny43(expr);
		if(_eq__ref_Type_typeofNil2((*self).reference))		{
			TypeAny* out=New_typeofTypeAny108();
			(*out).parent=(*self).parent;
			return (&(*out).super);
		};
		assert_i8(0);
		return Clone__ref_Type((*self).reference);
	};
	if(Is_ref_Type_typeofTypeTrait1(expr))	{
		TypeTrait* self=As_ref_Type_typeofTypeTrait44(expr);
		if(_eq__ref_Type_typeofNil2((*self).reference))		{
			TypeTrait* out=New_typeofTypeTrait109();
			(*out).parent=(*self).parent;
			return (&(*out).super);
		};
		assert_i8(0);
		return Clone__ref_Type((*self).reference);
	};
	if(Is_ref_Type_typeofTypeOption9(expr))	{
		TypeOption* self=As_ref_Type_typeofTypeOption45(expr);
		TypeOption* out=New_typeofTypeOption110();
		(*out).reference=Clone__ref_Type((*self).reference);
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeType3(expr))	{
		TypeType* self=As_ref_Type_typeofTypeType46(expr);
		TypeType* out=New_typeofTypeType111();
		(*out).reference=Clone__ref_Type((*self).reference);
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeGeneric6(expr))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric47(expr);
		TypeGeneric* out=New_typeofTypeGeneric112();
		(*out).ident=(*self).ident;
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			Push_ref_Array__ref_Type_ref_Type21((&(*out).constraints),Clone__ref_Type((*_bracket__ref_Array__ref_Typei64132((&(*self).constraints),it))));
		};
		(*out).referenced=(*self).referenced;
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeNumber8(expr))	{
		return expr;
	};
	if(Is_ref_Type_typeofTypeStructure7(expr))	{
		return expr;
	};
	Println_Str(((Str){20, (i8*)"Unhandled type visit"}));
	assert_i8(0);
	return (Type*)0;
}
Type* CloneAny__ref_Type_ref__ref_Type(Type* t, Type** any){
	Type* expr=Resolved__ref_Type(t);
	if(Is_ref_Type_typeofTypeRef4(expr))	{
		TypeRef* self=As_ref_Type_typeofTypeRef48(expr);
		TypeRef* out=New_typeofTypeRef113();
		(*out).reference=CloneAny__ref_Type_ref__ref_Type((*self).reference,any);
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeIdentifier5(expr))	{
		TypeIdentifier* self=As_ref_Type_typeofTypeIdentifier49(expr);
		if(Is_ref_Expr_typeofTypeAs7((*self).spec))		{
			assert_i8(0);
			return CloneAny__ref_Type_ref__ref_Type((*As_ref_Expr_typeofTypeAs66((*self).spec)).super.typ,any);
		};
		if(Is_ref_Expr_typeofTrait15((*self).spec))		{
			assert_i8(0);
			return CloneAny__ref_Type_ref__ref_Type((*As_ref_Expr_typeofTrait68((*self).spec)).super.typ,any);
		};
		TypeIdentifier* out=New_typeofTypeIdentifier114();
		(*out).ident=(*self).ident;
		(*out).spec=(*self).spec;
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeAny2(expr))	{
		TypeAny* self=As_ref_Type_typeofTypeAny50(expr);
		if(_eq__ref_Type_typeofNil2((*self).reference))		{
			TypeAny* out=New_typeofTypeAny115();
			(*out).parent=(*self).parent;
			*any=expr;
			return (&(*out).super);
		};
		assert_i8(0);
		return CloneAny__ref_Type_ref__ref_Type((*self).reference,any);
	};
	if(Is_ref_Type_typeofTypeTrait1(expr))	{
		TypeTrait* self=As_ref_Type_typeofTypeTrait51(expr);
		if(_eq__ref_Type_typeofNil2((*self).reference))		{
			TypeTrait* out=New_typeofTypeTrait116();
			(*out).parent=(*self).parent;
			(*out).trai=(*self).trai;
			*any=expr;
			return (&(*out).super);
		};
		assert_i8(0);
		return CloneAny__ref_Type_ref__ref_Type((*self).reference,any);
	};
	if(Is_ref_Type_typeofTypeOption9(expr))	{
		TypeOption* self=As_ref_Type_typeofTypeOption52(expr);
		TypeOption* out=New_typeofTypeOption117();
		(*out).reference=CloneAny__ref_Type_ref__ref_Type((*self).reference,any);
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeType3(expr))	{
		TypeType* self=As_ref_Type_typeofTypeType53(expr);
		TypeType* out=New_typeofTypeType118();
		(*out).reference=CloneAny__ref_Type_ref__ref_Type((*self).reference,any);
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeGeneric6(expr))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric54(expr);
		TypeGeneric* out=New_typeofTypeGeneric119();
		(*out).ident=(*self).ident;
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			Push_ref_Array__ref_Type_ref_Type22((&(*out).constraints),CloneAny__ref_Type_ref__ref_Type((*_bracket__ref_Array__ref_Typei64134((&(*self).constraints),it)),any));
		};
		(*out).referenced=(*self).referenced;
		return (&(*out).super);
	};
	if(Is_ref_Type_typeofTypeNumber8(expr))	{
		return expr;
	};
	if(Is_ref_Type_typeofTypeStructure7(expr))	{
		return expr;
	};
	Println_Str(((Str){20, (i8*)"Unhandled type visit"}));
	assert_i8(0);
	return (Type*)0;
}
i32 Convert__ref_Expr_ref_Expri8(Expr* desired, Expr* from, i8 reportError){
	if(Equal__ref_Type_ref_Typei8((*desired).typ,(*from).typ,true))	{
		return 1;
	};
	i32 value=Coerce__ref_Expr_ref_Expri8(desired,from,reportError);
	if((value!=0))	{
		return (value+1);
	};
	return 0;
}
i32 Coerce__ref_Expr_ref_Expri8(Expr* desired, Expr* from, i8 reportError){
	return Coerce__ref_Type_ref_Expri8(Resolved__ref_Type((*desired).typ),from,reportError);
}
i32 Coerce__ref_Type_ref_Expri8(Type* desiredType, Expr* from, i8 reportError){
	Type* fromType=Resolved__ref_Type((*from).typ);
	if(Is_ref_Expr_typeofNumberConstant16(from))	{
		if(Is_ref_Type_typeofTypeNumber8(desiredType))		{
			(*As_ref_Expr_typeofNumberConstant69(from)).super.typ=desiredType;
		}else		{
			return 0;
		};
		return 1;
	};
	if(Is_ref_Type_typeofTypeNumber8(desiredType))	{
		if(Is_ref_Type_typeofTypeNumber8(fromType))		{
			TypeNumber* f=As_ref_Type_typeofTypeNumber55(fromType);
			TypeNumber* d=As_ref_Type_typeofTypeNumber56(desiredType);
			if(((*d).kind==(*f).kind))			{
				if(((*d).size<(*f).size))				{
					Println_Str(((Str){44, (i8*)"conversion would result in loss of precision"}));
					return 0;
				};
			}else if(((((*d).kind==TypeNumberInteger)&&((*f).kind==TypeNumberUnsigned))||(((*f).kind==TypeNumberInteger)&&((*d).kind==TypeNumberUnsigned))))			{
				if(((*d).size<(*f).size))				{
					Println_Str(((Str){44, (i8*)"conversion would result in loss of precision"}));
					return 0;
				};
			}else			{
				return 0;
			};
			return 1;
		};
	};
	if(reportError)	{
		Error__ref_ExprStr(from,_add__StrStr(_add__StrStr(_add__StrStr(((Str){8, (i8*)"type of "}),String__ref_Type(desiredType)),((Str){30, (i8*)" cannot be assigned a type of "})),String__ref_Type(fromType)));
		assert_i8(0);
	};
	return 0;
}
i8 Equal_Array__ref_TypeArray__ref_Type(Array__ref_Type left, Array__ref_Type right){
	if((left.length!=right.length))	{
		return false;
	};
	for(i64 it=(i64)0; (it<left.length); it=(it+1))	{
		if(!Equal__ref_Type_ref_Type((*_bracket__ref_Array__ref_Typei64135((&left),it)),(*_bracket__ref_Array__ref_Typei64136((&right),it))))		{
			return false;
		};
	};
	return true;
}
i8 Equal__ref_Type_ref_Type(Type* from, Type* to){
	return Equal__ref_Type_ref_Typei8(from,to,false);
}
i8 Equal__ref_Type_ref_Typei8(Type* from, Type* to, i8 allowConversions){
	i8 fromNil=_eq__ref_Type_typeofNil2(from);
	i8 toNil=_eq__ref_Type_typeofNil2(to);
	if((fromNil||toNil))	{
		return (fromNil==toNil);
	};
	Type* f=Resolved__ref_Type(from);
	Type* t=Resolved__ref_Type(to);
	if(((*f).kind!=(*t).kind))	{
		return false;
	};
	if(Is_ref_Type_typeofTypeRef4(f))	{
		TypeRef* fPtr=As_ref_Type_typeofTypeRef57(f);
		TypeRef* tPtr=As_ref_Type_typeofTypeRef58(t);
		return Equal__ref_Type_ref_Type((*fPtr).reference,(*tPtr).reference);
	};
	if(Is_ref_Type_typeofTypeIdentifier5(f))	{
		TypeIdentifier* fIdent=As_ref_Type_typeofTypeIdentifier59(f);
		TypeIdentifier* tIdent=As_ref_Type_typeofTypeIdentifier60(t);
		assert_ref_ExprStr1((*fIdent).spec,((Str){10, (i8*)"f spec nil"}));
		assert_ref_ExprStr1((*tIdent).spec,((Str){10, (i8*)"t spec nil"}));
		return ((i64)(*fIdent).spec==(i64)(*tIdent).spec);
	};
	if(Is_ref_Type_typeofTypeAny2(f))	{
		TypeAny* fAny=As_ref_Type_typeofTypeAny61(f);
		TypeAny* tAny=As_ref_Type_typeofTypeAny62(t);
		return ((i64)(*fAny).parent==(i64)(*tAny).parent);
	};
	if(Is_ref_Type_typeofTypeTrait1(f))	{
		TypeTrait* fAny=As_ref_Type_typeofTypeTrait63(f);
		TypeTrait* tAny=As_ref_Type_typeofTypeTrait64(t);
		return ((i64)(*fAny).parent==(i64)(*tAny).parent);
	};
	if(Is_ref_Type_typeofTypeType3(f))	{
		TypeType* fType=As_ref_Type_typeofTypeType65(f);
		TypeType* tType=As_ref_Type_typeofTypeType66(t);
		return Equal__ref_Type_ref_Type((*fType).reference,(*tType).reference);
	};
	if(Is_ref_Type_typeofTypeOption9(f))	{
		TypeOption* fType=As_ref_Type_typeofTypeOption67(f);
		TypeOption* tType=As_ref_Type_typeofTypeOption68(t);
		return Equal__ref_Type_ref_Type((*fType).reference,(*tType).reference);
	};
	if(Is_ref_Type_typeofTypeGeneric6(f))	{
		TypeGeneric* fGen=As_ref_Type_typeofTypeGeneric69(f);
		TypeGeneric* tGen=As_ref_Type_typeofTypeGeneric70(t);
		assert_ref_TypeStructure3((*tGen).referenced);
		assert_ref_TypeStructure3((*fGen).referenced);
		if(PtrEqual_ref_TypeStructure_ref_TypeStructure4((*tGen).referenced,(*fGen).referenced))		{
			return true;
		};
		return false;
	};
	if(Is_ref_Type_typeofTypeNumber8(f))	{
		TypeNumber* fType=As_ref_Type_typeofTypeNumber71(f);
		TypeNumber* tType=As_ref_Type_typeofTypeNumber72(t);
		return PtrEqual_ref_TypeNumber_ref_TypeNumber5(fType,tType);
	};
	assert_i8Str(0,_add__StrStr(((Str){24, (i8*)"Unhandled type in Equal "}),String_i64((*from).kind)));
	return false;
}
i8 Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(Semantic* semantic, Type* argument, Type* parameter, Known* known, i64 index){
	Type* arg=Resolved__ref_Type(argument);
	Type* param=Resolved__ref_Type(parameter);
	i8 verbose=false;
	if(((*arg).kind==(*param).kind))	{
		if(Is_ref_Type_typeofTypeRef4(arg))		{
			TypeRef* argPtr=As_ref_Type_typeofTypeRef73(arg);
			TypeRef* paramPtr=As_ref_Type_typeofTypeRef74(param);
			return Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(*argPtr).reference,(*paramPtr).reference,known,index);
		};
		if(Is_ref_Type_typeofTypeOption9(arg))		{
			TypeOption* argPtr=As_ref_Type_typeofTypeOption75(arg);
			TypeOption* paramPtr=As_ref_Type_typeofTypeOption76(param);
			return Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(*argPtr).reference,(*paramPtr).reference,known,index);
		};
		if(Is_ref_Type_typeofTypeIdentifier5(arg))		{
			TypeIdentifier* argIdent=As_ref_Type_typeofTypeIdentifier77(arg);
			TypeIdentifier* paramIdent=As_ref_Type_typeofTypeIdentifier78(param);
			if(((i64)(*argIdent).spec!=(i64)(*paramIdent).spec))			{
				if(verbose)				{
					Println_Str(((Str){15, (i8*)"Failed in ident"}));
				};
			};
			return ((i64)(*argIdent).spec==(i64)(*paramIdent).spec);
		};
		if(Is_ref_Type_typeofTypeGeneric6(arg))		{
			TypeGeneric* argGen=As_ref_Type_typeofTypeGeneric79(arg);
			TypeGeneric* paramGen=As_ref_Type_typeofTypeGeneric80(param);
			if(!Equal__ref_Type_ref_Type((&(*(*argGen).ident).super),(&(*(*paramGen).ident).super)))			{
				if(verbose)				{
					Println_Str(((Str){23, (i8*)"Failed in type gen spec"}));
				};
				return false;
			};
			if(((*argGen).constraints.length!=(*paramGen).constraints.length))			{
				if(verbose)				{
					Println_Str(((Str){17, (i8*)"Fauiled in length"}));
				};
				return false;
			};
			for(i64 it=(i64)0; (it<(*argGen).constraints.length); it=(it+1))			{
				if(!Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(*_bracket__ref_Array__ref_Typei64137((&(*argGen).constraints),it)),(*_bracket__ref_Array__ref_Typei64138((&(*paramGen).constraints),it)),known,index))				{
					if(verbose)					{
						Println_Str(((Str){13, (i8*)"Failed in gen"}));
					};
					return false;
				};
			};
			return true;
		};
		if(Is_ref_Type_typeofTypeType3(arg))		{
			TypeType* a=As_ref_Type_typeofTypeType81(arg);
			TypeType* p=As_ref_Type_typeofTypeType82(param);
			return Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(*a).reference,(*p).reference,known,index);
		};
		if(Is_ref_Type_typeofTypeNumber8(arg))		{
			TypeNumber* a=As_ref_Type_typeofTypeNumber83(arg);
			TypeNumber* p=As_ref_Type_typeofTypeNumber84(param);
			if(((*a).kind!=(*p).kind))			{
				if(((*a).kind==TypeNumberFloat))				{
					return false;
				};
				if(((*p).kind==TypeNumberFloat))				{
					return false;
				};
			};
			return ((*p).size>=(*a).size);
		};
	};
	if(Is_ref_Type_typeofTypeAny2(param))	{
		if(verbose)		{
			Print_Str(((Str){18, (i8*)"Resolved type is: "}));
			Print__ref_Type(arg);
			Print_Str(((Str){7, (i8*)" ----- "}));
		};
		if(Is_ref_Type_typeofTypeType3(arg))		{
			return false;
		};
		Add__ref_Known_ref_Type_ref_Type(known,param,arg);
		if(verbose)		{
			Print__ref_Type(param);
			Println_Str(((Str){0, (i8*)""}));
		};
		return true;
	};
	if(Is_ref_Type_typeofTypeRef4(arg))	{
		*_bracket__ref_Array_i8i64139((&(*known).drefCount),index)=(i8)((*_bracket__ref_Array_i8i64140((&(*known).drefCount),index))+1);
		return Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,(*As_ref_Type_typeofTypeRef85(arg)).reference,param,known,index);
		if(Is_ref_Type_typeofTypeType3(arg))		{
			return false;
		};
		if(verbose)		{
			Println_Str(((Str){5, (i8*)"dref."}));
		};
	};
	if(Is_ref_Type_typeofTypeRef4(param))	{
		*_bracket__ref_Array_i8i64141((&(*known).drefCount),index)=(i8)((*_bracket__ref_Array_i8i64142((&(*known).drefCount),index))-1);
		if(verbose)		{
			Println_Str(((Str){4, (i8*)"ref."}));
		};
		return Apply__ref_Semantic_ref_Type_ref_Type_ref_Knowni64(semantic,arg,(*As_ref_Type_typeofTypeRef86(param)).reference,known,index);
	};
	if(PtrEqual_ref_Type_ref_Type3(param,arg))	{
		if(Is_ref_Type_typeofTypeTrait1(param))		{
			assert_i8(((i64)(*As_ref_Type_typeofTypeTrait87(param)).reference==0));
		};
		if(Is_ref_Type_typeofTypeTrait1(arg))		{
			assert_i8(((i64)(*As_ref_Type_typeofTypeTrait88(arg)).reference==0));
		};
		return true;
	};
	if(Is_ref_Type_typeofTypeTrait1(param))	{
		if(Is_ref_Type_typeofTypeTrait1(arg))		{
			TypeTrait* paramTrait=As_ref_Type_typeofTypeTrait89(param);
			TypeTrait* argTrait=As_ref_Type_typeofTypeTrait90(arg);
			if(PtrEqual_ref_TypeTrait_ref_TypeTrait6((*argTrait).parent,(*paramTrait).parent))			{
				return true;
			};
		};
		Trait* trai=(*As_ref_Type_typeofTypeTrait91(param)).trai;
		if(!PtrEqual_ref_Type_ref_Type3((&(*trai).typeTrait.super),arg))		{
			if(Implements__ref_Semantic_ref_Trait_ref_Type(semantic,trai,arg))			{
				Add__ref_Known_ref_Type_ref_Type(known,param,arg);
				return true;
			};
		};
	};
	if(verbose)	{
		Println_Str(((Str){23, (i8*)"Failed a bottom apply :"}));
	};
	return false;
}
TypeStructure* ResolveSpec__ref_Type(Type* typ){
	Type* t=Resolved__ref_Type(typ);
	if(Is_ref_Type_typeofTypeGeneric6(typ))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric92(t);
		assert_ref_TypeStructureStr5((*self).referenced,((Str){26, (i8*)"Generic type not annotated"}));
		return (*self).referenced;
	};
	return (TypeStructure*)0;
}
Type* Resolved__ref_Type(Type* typ){
	if(Is_ref_Type_typeofTypeAny2(typ))	{
		TypeAny* any=As_ref_Type_typeofTypeAny93(typ);
		if(_notEq__ref_Type_typeofNil3((*any).reference))		{
			return Resolved__ref_Type((*any).reference);
		};
	};
	if(Is_ref_Type_typeofTypeTrait1(typ))	{
		TypeTrait* trai=As_ref_Type_typeofTypeTrait94(typ);
		if(_notEq__ref_Type_typeofNil3((*trai).reference))		{
			return Resolved__ref_Type((*trai).reference);
		};
	};
	if(Is_ref_Type_typeofTypeIdentifier5(typ))	{
		TypeIdentifier* ident=As_ref_Type_typeofTypeIdentifier95(typ);
		assert_i8Str((*(*ident).ident.chars),((Str){17, (i8*)"failed in resolve"}));
		if(_eq__ref_Expr_typeofNil1((*ident).spec))		{
		}else if(Is_ref_Expr_typeofTypeAs7((*ident).spec))		{
			return Resolved__ref_Type((*(*ident).spec).typ);
		}else if(Is_ref_Expr_typeofTrait15((*ident).spec))		{
			return Resolved__ref_Type((*(*ident).spec).typ);
		};
	};
	return (*(&typ));
}
void PrintIndent__ref_PrintVisitor(PrintVisitor* visitor){
	for(i64 it=(i64)1; (it<(*visitor).indent); it=(it+1))	{
		Print_Str(((Str){1, (i8*)"	"}));
	};
}
void PrintTabs_i32(i32 count){
	for(i32 it=(i32)0; (it<count); it=(it+1))	{
		Print_Str(((Str){1, (i8*)"	"}));
	};
}
void Print__ref_Expr(Expr* expr){
	PrintVisitor printer={0};
	Visit__ref_Expr_ref_PrintVisitor(expr,(&printer));
}
void Print_Type(Type expr){
	PrintVisitor printer={0};
	Visit__ref_Type_ref_PrintVisitor((&expr),(&printer));
}
void Print__ref_Type(Type* expr){
	if(_eq__ref_Type_typeofNil2(expr))	{
		Print_Str(((Str){2, (i8*)"()"}));
		return ;
	};
	PrintVisitor printer={0};
	Visit__ref_Type_ref_PrintVisitor(expr,(&printer));
}
void Visit__ref_Expr_ref_PrintVisitor(Expr* expr, PrintVisitor* visitor){
	if(_eq__ref_Expr_typeofNil1(expr))	{
		return ;
	};
	if(Is_ref_Expr_typeofBlock4(expr))	{
		Block* self=As_ref_Expr_typeofBlock70(expr);
		if(((*visitor).indent!=0))		{
			Println_Str(((Str){1, (i8*)"{"}));
		};
		(*visitor).indent=((*visitor).indent+1);
		for(i64 it=(i64)0; (it<(*self).expressions.length); it=(it+1))		{
			PrintIndent__ref_PrintVisitor(visitor);
			Visit__ref_Expr_ref_PrintVisitor((*_bracket__ref_Array__ref_Expri64145((&(*self).expressions),it)),visitor);
			Println_Str(((Str){0, (i8*)""}));
		};
		(*visitor).indent=((*visitor).indent-1);
		if(((*visitor).indent!=0))		{
			Println_Str(((Str){1, (i8*)"}"}));
		};
		return ;
	};
	if(Is_ref_Expr_typeofStructure2(expr))	{
		Structure* self=As_ref_Expr_typeofStructure71(expr);
		Print_Str((*self).ident);
		Print_Str(((Str){7, (i8*)" struct"}));
		if(!(*self).incomplete)		{
			Println_Str(((Str){2, (i8*)" {"}));
			(*visitor).indent=((*visitor).indent+1);
			for(i64 it=(i64)0; (it<(*self).fields.length); it=(it+1))			{
				PrintIndent__ref_PrintVisitor(visitor);
				Print_Str((**_bracket__ref_Array__ref_Variablei64146((&(*self).fields),it)).ident);
				Print_Str(((Str){1, (i8*)" "}));
				Visit__ref_Type_ref_PrintVisitor((**_bracket__ref_Array__ref_Variablei64148((&(*self).fields),it)).super.typ,visitor);
				Println_Str(((Str){0, (i8*)""}));
			};
			(*visitor).indent=((*visitor).indent-1);
			Println_Str(((Str){1, (i8*)"}"}));
		}else		{
			Println_Str(((Str){0, (i8*)""}));
		};
		return ;
	};
	if(Is_ref_Expr_typeofFunction5(expr))	{
		Function* self=As_ref_Expr_typeofFunction72(expr);
		Print_Str((*self).ident);
		Print_Str(((Str){4, (i8*)" fn "}));
		Print__ref_Expr((&(*self).params.super));
		Print_Str(((Str){1, (i8*)" "}));
		Print__ref_Type((*self).result);
		return ;
	};
	if(Is_ref_Expr_typeofIdentifier12(expr))	{
		Identifier* self=As_ref_Expr_typeofIdentifier73(expr);
		Print_Str((*self).ident);
		return ;
	};
	if(Is_ref_Expr_typeofCall6(expr))	{
		Call* self=As_ref_Expr_typeofCall74(expr);
		Visit__ref_Expr_ref_PrintVisitor((*self).operand,visitor);
		Visit__ref_Expr_ref_PrintVisitor((&(*self).params.super),visitor);
		return ;
	};
	if(Is_ref_Expr_typeofAccess13(expr))	{
		Access* self=As_ref_Expr_typeofAccess75(expr);
		Visit__ref_Expr_ref_PrintVisitor((*self).operand,visitor);
		Print_Str(((Str){1, (i8*)"."}));
		Print_Str((*self).field);
		return ;
	};
	if(Is_ref_Expr_typeofExpressionList1(expr))	{
		ExpressionList* self=As_ref_Expr_typeofExpressionList76(expr);
		Print_Str(((Str){1, (i8*)"("}));
		for(i64 it=(i64)0; (it<(*self).list.length); it=(it+1))		{
			Visit__ref_Expr_ref_PrintVisitor((*_bracket__ref_Array__ref_Expri64150((&(*self).list),it)),visitor);
			if((it!=((*self).list.length-1)))			{
				Print_Str(((Str){2, (i8*)", "}));
			};
		};
		Print_Str(((Str){1, (i8*)")"}));
		return ;
	};
	if(Is_ref_Expr_typeofVariable3(expr))	{
		Variable* self=As_ref_Expr_typeofVariable77(expr);
		Print_Str((*self).ident);
		Print_Str(((Str){1, (i8*)" "}));
		Visit__ref_Type_ref_PrintVisitor((*expr).typ,visitor);
		return ;
	};
	if(Is_ref_Expr_typeofTrait15(expr))	{
		Trait* self=As_ref_Expr_typeofTrait78(expr);
		Print_Str((*self).ident);
		Print_Str(((Str){6, (i8*)" trait"}));
		(*visitor).indent=((*visitor).indent+1);
		Println_Str(((Str){2, (i8*)" {"}));
		(*visitor).indent=((*visitor).indent-1);
		Println_Str(((Str){1, (i8*)"}"}));
		return ;
	};
	Println_Str(_add__StrStr(((Str){28, (i8*)"Unhandled print expr visit: "}),String_i64((*expr).kind)));
}
void Visit__ref_Type_ref_PrintVisitor(Type* t, PrintVisitor* visitor){
	Type* expr=*(&t);
	Print_Str(String__ref_Type(t));
}
void PrettyPrint__ref_Type(Type* expr){
	if(_eq__ref_Type_typeofNil2(expr))	{
		Print_Str(((Str){2, (i8*)"()"}));
	}else	{
		PrettyPrint_Type((*expr));
	};
}
void PrettyPrint__ref_Expr(Expr* expr){
	if(Is_ref_Expr_typeofStructure2(expr))	{
		Structure* self=As_ref_Expr_typeofStructure79(expr);
		Print_Str((*self).ident);
		return ;
	};
	if(Is_ref_Expr_typeofFunction5(expr))	{
		Function* self=As_ref_Expr_typeofFunction80(expr);
		Print_Str((*self).ident);
		return ;
	};
	if(Is_ref_Expr_typeofTypeAs7(expr))	{
		TypeAs* self=As_ref_Expr_typeofTypeAs81(expr);
		PrettyPrint_Type((*(*self).super.typ));
		return ;
	};
	if(Is_ref_Expr_typeofTrait15(expr))	{
		Trait* self=As_ref_Expr_typeofTrait82(expr);
		Print_Str(((Str){4, (i8*)"huh?"}));
		return ;
	};
	Print_Str(_add__StrStr(((Str){5, (i8*)"none "}),String_i64((*expr).kind)));
}
void PrettyPrint_Type(Type expr){
	Print_Str(String__ref_Type((&expr)));
}
Str String__ref_Expr(Expr* expr){
	if(_eq__ref_Expr_typeofNil1(expr))	{
		return ((Str){2, (i8*)"()"});
	};
	if(Is_ref_Expr_typeofStructure2(expr))	{
		Structure* self=As_ref_Expr_typeofStructure83(expr);
		return (*self).ident;
	};
	if(Is_ref_Expr_typeofFunction5(expr))	{
		Function* self=As_ref_Expr_typeofFunction84(expr);
		return (*self).ident;
	};
	if(Is_ref_Expr_typeofTypeAs7(expr))	{
		TypeAs* self=As_ref_Expr_typeofTypeAs85(expr);
		return _add__StrStr(((Str){2, (i8*)"as"}),String__ref_Type((*self).super.typ));
	};
	if(Is_ref_Expr_typeofTrait15(expr))	{
		Trait* self=As_ref_Expr_typeofTrait86(expr);
		return (*self).ident;
	};
	return _add__StrStr(((Str){5, (i8*)"none "}),String_i64((*expr).kind));
}
Str String__ref_Type(Type* expr){
	if(_eq__ref_Type_typeofNil2(expr))	{
		return ((Str){2, (i8*)"()"});
	};
	assert_ref__ref_TypeStr6((&expr),((Str){9, (i8*)"nil value"}));
	if(Is_ref_Type_typeofTypeRef4(expr))	{
		TypeRef* self=As_ref_Type_typeofTypeRef96(expr);
		return _add__StrStr(((Str){4, (i8*)"ref "}),String__ref_Type((*self).reference));
	};
	if(Is_ref_Type_typeofTypeIdentifier5(expr))	{
		TypeIdentifier* self=As_ref_Type_typeofTypeIdentifier97(expr);
		if(_notEq__ref_Expr_typeofNil1((*self).spec))		{
			return _add__StrStr(String__ref_Expr((*self).spec),String_i64((i64)(*self).spec));
		}else		{
			return _add__StrStr(_add__StrStr(((Str){8, (i8*)"untyped<"}),(*self).ident),((Str){1, (i8*)">"}));
		};
	};
	if(Is_ref_Type_typeofTypeAny2(expr))	{
		TypeAny* self=As_ref_Type_typeofTypeAny98(expr);
		if(_notEq__ref_Type_typeofNil3((*self).reference))		{
			return _add__StrStr(_add__StrStr(_add__StrStr(((Str){1, (i8*)"$"}),(*self).ident),((Str){2, (i8*)"->"})),String__ref_Type((*self).reference));
		};
		return _add__StrStr(_add__StrStr(((Str){1, (i8*)"$"}),(*self).ident),String_i64((i64)self));
	};
	if(Is_ref_Type_typeofTypeTrait1(expr))	{
		TypeTrait* self=As_ref_Type_typeofTypeTrait99(expr);
		if(_notEq__ref_Type_typeofNil3((*self).reference))		{
			return _add__StrStr(_add__StrStr(_add__StrStr(((Str){1, (i8*)"$"}),(*(*self).trai).ident),((Str){2, (i8*)"->"})),String__ref_Type((*self).reference));
		};
		return _add__StrStr(((Str){1, (i8*)"$"}),(*(*self).trai).ident);
	};
	if(Is_ref_Type_typeofTypeOption9(expr))	{
		TypeOption* self=As_ref_Type_typeofTypeOption100(expr);
		assert_ref_TypeStr2((*self).reference,((Str){11, (i8*)"Require ref"}));
		Str value={0};
		if(Is_ref_Type_typeofTypeRef4(Resolved__ref_Type((*self).reference)))		{
			return _add__StrStr(((Str){5, (i8*)"ref? "}),String__ref_Type((*As_ref_Type_typeofTypeRef102(Resolved__ref_Type((*self).reference))).reference));
		}else		{
			return _add__StrStr(String__ref_Type((*self).reference),((Str){1, (i8*)"?"}));
		};
	};
	if(Is_ref_Type_typeofTypeType3(expr))	{
		TypeType* self=As_ref_Type_typeofTypeType103(expr);
		Print_Str(((Str){7, (i8*)"typeof "}));
		return _add__StrStr(((Str){7, (i8*)"type of"}),String__ref_Type((*self).reference));
	};
	if(Is_ref_Type_typeofTypeGeneric6(expr))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric104(expr);
		Str value=_add__StrStr(_add__StrStr(_add__StrStr(String__ref_Type((&(*(*self).ident).super)),((Str){2, (i8*)"->"})),String_i64((i64)(*self).spec)),((Str){1, (i8*)"("}));
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			value=_add__StrStr(value,String__ref_Type((*_bracket__ref_Array__ref_Typei64151((&(*self).constraints),it))));
			if((it!=((*self).constraints.length-1)))			{
				value=_add__StrStr(value,((Str){2, (i8*)", "}));
			};
		};
		return _add__StrStr(value,((Str){1, (i8*)")"}));
	};
	if(Is_ref_Type_typeofTypeNumber8(expr))	{
		TypeNumber* self=As_ref_Type_typeofTypeNumber105(expr);
		if(((*self).kind==TypeNumberInteger))		{
			return _add__StrStr(((Str){1, (i8*)"i"}),String_i64(((*self).size*8)));
		}else if(((*self).kind==TypeNumberUnsigned))		{
			return _add__StrStr(((Str){1, (i8*)"u"}),String_i64(((*self).size*8)));
		}else if(((*self).kind==TypeNumberFloat))		{
			return _add__StrStr(((Str){1, (i8*)"f"}),String_i64(((*self).size*8)));
		}else		{
			assert_i8(0);
		};
		return ((Str){0, (i8*)""});
	};
	Println_Str(((Str){20, (i8*)"Unhandled type visit"}));
	return ((Str){0, (i8*)""});
}
Module* GetFile__ref_ProjectStr(Project* self, Str path){
	for(i64 it=(i64)0; (it<(*self).files.length); it=(it+1))	{
		if(_eq__StrStr((**_bracket__ref_Array__ref_Modulei64152((&(*self).files),it)).path,path))		{
			return (*_bracket__ref_Array__ref_Modulei64153((&(*self).files),it));
		};
	};
	return (Module*)0;
}
Module* AddFile__ref_ProjectStr(Project* self, Str path){
	Module* hasFile=GetFile__ref_ProjectStr(self,path);
	if(_notEq__ref_Module_typeofNil11(hasFile))	{
		return hasFile;
	};
	Module* file=Alloc_typeofModulei641(1);
	(*file).path=path;
	Push_ref_Array__ref_Module_ref_Module23((&(*self).files),file);
	return file;
}
void PrintLines__ref_ProjectPositioni64(Project* self, Position position, i64 lines){
	if((position.file==0))	{
		Println_Str(_add__StrStr(_add__StrStr(_add__StrStr(_add__StrStr(((Str){20, (i8*)"Internal position: ("}),String_i64(position.line)),((Str){2, (i8*)", "})),String_i64(position.line)),((Str){1, (i8*)")"})));
		return ;
	};
	FileHandle* file=FileOpen((**_bracket__ref_Array__ref_Modulei64154((&(*self).files),(position.file-1))).path.chars,((Str){1, (i8*)"r"}).chars);
	i8* buffer=Alloc_typeofi8i642(1024);
	for(i64 it=(i64)1; (it<(position.line+lines)); it=(it+1))	{
		i8* ret=GetLine(file,buffer,1024);
		if((it==position.line))		{
			i64 len=String_i64(it).length;
			for(i64 it=(i64)0; (it<len); it=(it+1))			{
				Print_Str(((Str){3, (i8*)"•"}));
			};
			for(i64 it=(i64)0; (it<(position.column-1)); it=(it+1))			{
				if(((*(ret+it))==Char_Str(((Str){1, (i8*)"	"}))))				{
					Print_Str(((Str){9, (i8*)"•••"}));
					len=(len+3);
				}else				{
					Print_Str(((Str){3, (i8*)"•"}));
					len=(len+1);
				};
			};
			Print_Str(((Str){7, (i8*)"  ▼  "}));
			for(i64 it=(i64)0; (it<(93-len)); it=(it+1))			{
				Print_Str(((Str){3, (i8*)"•"}));
			};
			Println_Str(((Str){0, (i8*)""}));
		};
		if(((it>=position.line)&&_notEq__ref_i8_typeofNil12(ret)))		{
			Print_Str(_add__StrStr(String_i64(it),((Str){2, (i8*)"  "})));
			Print_Str(String_i64((*buffer)));
		};
	};
}
void Init__ref_TypeIdentifier(TypeIdentifier* self){
	(*self).super.kind=Id__typeofTypeIdentifier();
}
void Init__ref_TypeRef(TypeRef* self){
	(*self).super.kind=Id__typeofTypeRef();
}
void Init__ref_TypeOption(TypeOption* self){
	(*self).super.kind=Id__typeofTypeOption();
}
void Init__ref_TypeGeneric(TypeGeneric* self){
	Init_ref_Array__ref_Type1((&(*self).constraints));
	(*self).super.kind=Id__typeofTypeGeneric();
}
void Init__ref_TypeAny(TypeAny* self){
	(*self).super.kind=Id__typeofTypeAny();
	(*self).parent=self;
}
void Init__ref_TypeType(TypeType* self){
	(*self).super.kind=Id__typeofTypeType();
}
void Init__ref_TypeTrait(TypeTrait* self){
	(*self).super.kind=Id__typeofTypeTrait();
	(*self).parent=self;
}
void Init__ref_TypeStructure(TypeStructure* self){
	(*self).super.kind=Id__typeofTypeStructure();
}
void Init__ref_TypeNumber(TypeNumber* self){
	(*self).super.kind=Id__typeofTypeNumber();
}
TypeNumber* New__typeofTypeNumberi8i64Str(i8 kind, i64 size, Str ident){
	TypeNumber* r=New_typeofTypeNumber120();
	(*r).kind=kind;
	(*r).size=size;
	(*r).ident=ident;
	return r;
}
i32 Id__typeofTypeRef(){
	return 1;
}
i32 Id__typeofTypeIdentifier(){
	return 2;
}
i32 Id__typeofTypeFunctions(){
	return 3;
}
i32 Id__typeofTypeGeneric(){
	return 4;
}
i32 Id__typeofTypeAny(){
	return 5;
}
i32 Id__typeofTypeType(){
	return 6;
}
i32 Id__typeofTypeOption(){
	return 7;
}
i32 Id__typeofTypeNumber(){
	return 8;
}
i32 Id__typeofTypeTrait(){
	return 9;
}
i32 Id__typeofTypeStructure(){
	return 10;
}
void Init__ref_Block(Block* self){
	(*self).super.kind=Id__typeofBlock();
	Init_ref_Array__ref_Expr2((&(*self).expressions));
	Init_ref_Table_Str_ref_Expr2((&(*self).variables));
	Init_ref_Table_Str_ref_TypeFunctions3((&(*self).functions));
}
Expr* Lookup__ref_BlockStr(Block* self, Str ident){
	return (*_bracket__ref_Table_Str_ref_ExprStr17((&(*self).variables),ident));
}
TypeFunctions* LookupFns__ref_BlockStr(Block* self, Str ident){
	return (*_bracket__ref_Table_Str_ref_TypeFunctionsStr18((&(*self).functions),ident));
}
void InsertFn__ref_BlockStr_ref_Function(Block* self, Str ident, Function* function){
	TypeFunctions** fns=_bracket__ref_Table_Str_ref_TypeFunctionsStr19((&(*self).functions),ident);
	TypeFunctions* funcs=*fns;
	if(_eq__ref_TypeFunctions_typeofNil8(funcs))	{
		funcs=Alloc_typeofTypeFunctionsi643(1);
		*fns=funcs;
	};
	Push_ref_Array__ref_Function_ref_Function24((&(*funcs).functions),function);
}
void Insert__ref_BlockStr_ref_Expr(Block* self, Str ident, Expr* expr){
	*_bracket__ref_Table_Str_ref_ExprStr20((&(*self).variables),ident)=expr;
}
void Add__ref_Block_ref_Expr(Block* self, Expr* expr){
	assert_ref_ExprStr1(expr,((Str){30, (i8*)"add to block should be non nil"}));
	Push_ref_Array__ref_Expr_ref_Expr25((&(*self).expressions),expr);
}
void Init__ref_Call(Call* self){
	(*self).super.kind=Id__typeofCall();
	Init__ref_ExpressionList((&(*self).params));
}
void Init__ref_Access(Access* self){
	(*self).super.kind=Id__typeofAccess();
}
void Init__ref_NumberConstant(NumberConstant* self){
	(*self).super.kind=Id__typeofNumberConstant();
	Init__ref_TypeNumber((&(*self).internalType));
}
void Init__ref_StringConstant(StringConstant* self){
	(*self).super.kind=Id__typeofStringConstant();
}
void Init__ref_If(If* self){
	(*self).super.kind=Id__typeofIf();
}
void Init__ref_For(For* self){
	(*self).super.kind=Id__typeofFor();
}
void Init__ref_ForList(ForList* self){
	(*self).super.kind=Id__typeofForList();
}
void Init__ref_Branch(Branch* self){
	(*self).super.kind=Id__typeofBranch();
}
void Init__ref_Return(Return* self){
	(*self).super.kind=Id__typeofReturn();
}
void Init__ref_Function(Function* self){
	(*self).super.kind=Id__typeofFunction();
	Init__ref_ExpressionList((&(*self).params));
	Init_ref_Array__ref_Type1((&(*self).any));
}
void Init__ref_FunctionSpec(FunctionSpec* self){
	(*self).super.kind=Id__typeofFunctionSpec();
	Init_ref_Array_TypeAnyResolved3((&(*self).known));
}
void AddAny__ref_Function_ref_Type(Function* self, Type* typ){
	Push_ref_Array__ref_Type_ref_Type26((&(*self).any),typ);
	if(Is_ref_Type_typeofTypeAny2(typ))	{
		TypeAny* any=As_ref_Type_typeofTypeAny106(typ);
		if(_notEq__ref_Block_typeofNil5((*self).block))		{
			TypeAs* as=New_typeofTypeAs121();
			(*as).super.typ=typ;
			(*as).ident=(*any).ident;
			Declare__ref_Block_ref_Expr((*self).block,(&(*as).super));
		};
	};
	if(Is_ref_Type_typeofTypeTrait1(typ))	{
		TypeTrait* any=As_ref_Type_typeofTypeTrait107(typ);
		if(_notEq__ref_Block_typeofNil5((*self).block))		{
			TypeAs* as=New_typeofTypeAs122();
			(*as).super.typ=typ;
			(*as).ident=(*(*any).trai).ident;
			Declare__ref_Block_ref_Expr((*self).block,(&(*as).super));
		};
	};
}
FunctionSpec* Specialize__ref_Function_ref_Semantic_ref_Call_ref_Function_ref_Known(Function* self, Semantic* semantic, Call* call, Function* parent, Known* known){
	return Specialize__ref_Function_ref_Semantic_ref_Call_ref_Function_ref_Knowni32(self,semantic,call,parent,known,1);
}
i8 ContainsUnknown__ref_Type(Type* t){
	Type* typ=*(&t);
	if(Is_ref_Type_typeofTypeRef4(typ))	{
		return ContainsUnknown__ref_Type((*As_ref_Type_typeofTypeRef109(typ)).reference);
	};
	if(Is_ref_Type_typeofTypeType3(typ))	{
		return ContainsUnknown__ref_Type((*As_ref_Type_typeofTypeType111(typ)).reference);
	};
	if((Is_ref_Type_typeofTypeAny2(typ)||Is_ref_Type_typeofTypeTrait1(typ)))	{
		return true;
	};
	if(Is_ref_Type_typeofTypeGeneric6(typ))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric112(typ);
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			if(ContainsUnknown__ref_Type((*_bracket__ref_Array__ref_Typei64156((&(*self).constraints),it))))			{
				return true;
			};
		};
		return false;
	};
	if(Is_ref_Type_typeofTypeIdentifier5(typ))	{
		if(Is_ref_Expr_typeofTypeAs7((*As_ref_Type_typeofTypeIdentifier114(typ)).spec))		{
			return ContainsUnknown__ref_Type((*As_ref_Expr_typeofTypeAs88((*As_ref_Type_typeofTypeIdentifier117(typ)).spec)).super.typ);
		};
		if(Is_ref_Expr_typeofTrait15((*As_ref_Type_typeofTypeIdentifier119(typ)).spec))		{
			return ContainsUnknown__ref_Type((*As_ref_Expr_typeofTrait90((*As_ref_Type_typeofTypeIdentifier122(typ)).spec)).super.typ);
		};
		return false;
	};
	if(Is_ref_Type_typeofTypeNumber8(typ))	{
		return false;
	};
	assert_i8(0);
	return false;
}
i8 ContainsAny__ref_Type(Type* t){
	Type* typ=t;
	if(Is_ref_Type_typeofTypeRef4(typ))	{
		return ContainsAny__ref_Type((*As_ref_Type_typeofTypeRef124(typ)).reference);
	};
	if(Is_ref_Type_typeofTypeType3(typ))	{
		return ContainsAny__ref_Type((*As_ref_Type_typeofTypeType126(typ)).reference);
	};
	if((Is_ref_Type_typeofTypeAny2(typ)||Is_ref_Type_typeofTypeTrait1(typ)))	{
		assert_i8Str(((i64)(*As_ref_Type_typeofTypeAny127(typ)).reference==0),((Str){27, (i8*)"found any wither reference?"}));
		assert_i8(0);
		return true;
	};
	if(Is_ref_Type_typeofTypeGeneric6(typ))	{
		TypeGeneric* self=As_ref_Type_typeofTypeGeneric128(typ);
		for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))		{
			if(ContainsAny__ref_Type((*_bracket__ref_Array__ref_Typei64158((&(*self).constraints),it))))			{
				assert_i8(0);
				return true;
			};
		};
		return false;
	};
	if(Is_ref_Type_typeofTypeIdentifier5(typ))	{
		if(Is_ref_Expr_typeofTypeAs7((*As_ref_Type_typeofTypeIdentifier130(typ)).spec))		{
			return ContainsAny__ref_Type((*As_ref_Expr_typeofTypeAs92((*As_ref_Type_typeofTypeIdentifier133(typ)).spec)).super.typ);
		};
		if(Is_ref_Expr_typeofTrait15((*As_ref_Type_typeofTypeIdentifier135(typ)).spec))		{
			return ContainsAny__ref_Type((*As_ref_Expr_typeofTrait94((*As_ref_Type_typeofTypeIdentifier138(typ)).spec)).super.typ);
		};
		return false;
	};
	if(Is_ref_Type_typeofTypeNumber8(typ))	{
		return false;
	};
	assert_i8(0);
	return false;
}
FunctionSpec* Specialize__ref_Function_ref_Semantic_ref_Call_ref_Function_ref_Knowni32(Function* self, Semantic* semantic, Call* call, Function* parent, Known* known, i32 level){
	i8 verbose={0};
	for(i64 it=(i64)0; (it<(*self).specializations.length); it=(it+1))	{
		FunctionSpec* spec=*_bracket__ref_Array__ref_FunctionSpeci64159((&(*self).specializations),it);
		if(((*spec).known.length==(*known).known.length))		{
			i64 found=1;
			for(i64 it=(i64)0; (it<(*known).known.length); it=(it+1))			{
				if(!Equal__ref_Type_ref_Type((*_bracket__ref_Array_TypeAnyResolvedi64160((&(*spec).known),it)).typ,(*_bracket__ref_Array_TypeAnyResolvedi64161((&(*known).known),it)).typ))				{
					found=0;
				};
			};
			if((found!=0))			{
				Print_Str(((Str){12, (i8*)"FOUADasfsadf"}));
				return spec;
			};
		};
	};
	FunctionSpec* spec=New_typeofFunctionSpec123();
	Push_ref_Array__ref_FunctionSpec_ref_FunctionSpec27((&(*self).specializations),spec);
	Push_ref_Array__ref_FunctionSpec_ref_FunctionSpec28((&gSpecializations),spec);
	(*spec).function=self;
	(*spec).index=(*self).specializations.length;
	for(i64 it=(i64)0; (it<(*known).known.length); it=(it+1))	{
		TypeAnyResolved t=*_bracket__ref_Array_TypeAnyResolvedi64162((&(*known).known),it);
	};
	if(verbose)	{
		if((level==1))		{
			Print_Str(((Str){17, (i8*)"Specializing: in "}));
			Println_Str((*parent).ident);
		};
		PrintTabs_i32(level);
		Print_Str((*self).ident);
		Print_Str(((Str){3, (i8*)" fn"}));
		Print__ref_Expr((&(*self).params.super));
		PrintTabs_i32(1);
	};
	for(i64 it=(i64)0; (it<(*known).known.length); it=(it+1))	{
		TypeAnyResolved t=*_bracket__ref_Array_TypeAnyResolvedi64163((&(*known).known),it);
		for(i64 it=(i64)0; (it<(*self).any.length); it=(it+1))		{
			Type* any=*_bracket__ref_Array__ref_Typei64164((&(*self).any),it);
			if(PtrEqual_ref_Type_ref_Type3(any,t.any))			{
				TypeAnyResolved tt={0};
				tt.any=any;
				tt.typ=Clone__ref_Type(t.typ);
				Push_ref_Array_TypeAnyResolvedTypeAnyResolved29((&(*spec).known),tt);
				Annotate__ref_Semantic_ref_Type(semantic,tt.typ);
				if(ContainsUnknown__ref_Type(tt.typ))				{
					(*spec).incomplete=true;
				};
			};
		};
	};
	if(!(*spec).incomplete)	{
		for(i64 it=(i64)0; (it<(*spec).known.length); it=(it+1))		{
			assert_i8(!ContainsAny__ref_Type((*_bracket__ref_Array_TypeAnyResolvedi64165((&(*spec).known),it)).typ));
		};
	};
	FunctionSpec* prev=(*self).spec;
	Apply__ref_FunctionSpec(spec);
	for(i64 it=(i64)0; (it<(*self).params.list.length); it=(it+1))	{
		Type* typ=Clone__ref_Type((**_bracket__ref_Array__ref_Expri64167((&(*self).params.list),it)).typ);
		Push_ref_Array__ref_Type_ref_Type30((&(*spec).params),typ);
		Annotate__ref_Semantic_ref_Type(semantic,typ);
	};
	if(_notEq__ref_FunctionSpec_typeofNil4(prev))	{
		Apply__ref_FunctionSpec(prev);
	}else	{
		Clear__ref_FunctionSpec(spec);
	};
	return spec;
}
void Apply__ref_FunctionSpec(FunctionSpec* self){
	(*(*self).function).spec=self;
	for(i64 it=(i64)0; (it<(*self).known.length); it=(it+1))	{
		TypeAnyResolved t=*_bracket__ref_Array_TypeAnyResolvedi64168((&(*self).known),it);
		if(Is_ref_Type_typeofTypeAny2(t.any))		{
			(*As_ref_Type_typeofTypeAny139(t.any)).reference=t.typ;
		}else if(Is_ref_Type_typeofTypeTrait1(t.any))		{
			(*As_ref_Type_typeofTypeTrait140(t.any)).reference=t.typ;
		}else		{
			assert_i8(0);
		};
	};
}
void Clear__ref_FunctionSpec(FunctionSpec* self){
	(*(*self).function).spec=(FunctionSpec*)0;
	for(i64 it=(i64)0; (it<(*self).known.length); it=(it+1))	{
		TypeAnyResolved t=*_bracket__ref_Array_TypeAnyResolvedi64169((&(*self).known),it);
		if(Is_ref_Type_typeofTypeAny2(t.any))		{
			(*As_ref_Type_typeofTypeAny141(t.any)).reference=(Type*)0;
		}else if(Is_ref_Type_typeofTypeTrait1(t.any))		{
			(*As_ref_Type_typeofTypeTrait142(t.any)).reference=(Type*)0;
		}else		{
			assert_i8(0);
		};
	};
}
i8 Add__ref_Known_ref_Type_ref_Type(Known* self, Type* any, Type* typ){
	TypeAnyResolved t={0};
	t.any=any;
	t.typ=typ;
	for(i64 it=(i64)0; (it<(*self).known.length); it=(it+1))	{
		if(PtrEqual_ref_Type_ref_Type3((*_bracket__ref_Array_TypeAnyResolvedi64171((&(*self).known),it)).any,any))		{
			if(!Equal__ref_Type_ref_Type((*_bracket__ref_Array_TypeAnyResolvedi64172((&(*self).known),it)).typ,typ))			{
				return false;
			};
		};
	};
	Push_ref_Array_TypeAnyResolvedTypeAnyResolved31((&(*self).known),t);
	return true;
}
void Init__ref_Structure(Structure* self){
	(*self).super.kind=Id__typeofStructure();
	Init__ref_Block((&(*self).block));
	TypeType* typetype=New_typeofTypeType124();
	TypeIdentifier* ident=New_typeofTypeIdentifier125();
	(*ident).spec=(&(*self).super);
	(*typetype).reference=(&(*ident).super);
	(*self).super.typ=(&(*typetype).super);
	(*self).typeIdent=(&(*ident).super);
	Init__ref_TypeStructure((&(*self).typeStructure));
	(*self).typeStructure.parent=self;
}
void Add__ref_Structure_ref_Variable(Structure* structure, Variable* field){
	assert_ref_VariableStr7(field,((Str){21, (i8*)"Field must be non nil"}));
	Push_ref_Array__ref_Variable_ref_Variable32((&(*structure).fields),field);
}
Variable* Lookup__ref_StructureStr(Structure* structure, Str ident){
	for(i64 it=(i64)0; (it<(*structure).fields.length); it=(it+1))	{
		if(_eq__StrStr((**_bracket__ref_Array__ref_Variablei64173((&(*structure).fields),it)).ident,ident))		{
			return (*_bracket__ref_Array__ref_Variablei64174((&(*structure).fields),it));
		};
	};
	return (Variable*)0;
}
Type* Lookup__ref_TypeStructureStr(TypeStructure* spec, Str ident){
	for(i64 it=(i64)0; (it<(*spec).fields.length); it=(it+1))	{
		if(_eq__StrStr((**_bracket__ref_Array__ref_Variablei64175((&(*(*spec).parent).fields),it)).ident,ident))		{
			return (*_bracket__ref_Array__ref_Typei64176((&(*spec).fields),it));
		};
	};
	return (Type*)0;
}
void ApplyConstraints__ref_Array__ref_Type_ref_Array__ref_Type(Array__ref_Type* anythings, Array__ref_Type* constraints){
	assert_i8Str(((*anythings).length==(*constraints).length),((Str){46, (i8*)"Internal: Expected constraints length to match"}));
	for(i64 it=(i64)0; (it<(*anythings).length); it=(it+1))	{
		Type* any=*_bracket__ref_Array__ref_Typei64177(anythings,it);
		Type* constraint=*_bracket__ref_Array__ref_Typei64178(constraints,it);
		if(Is_ref_Type_typeofTypeAny2(any))		{
			(*As_ref_Type_typeofTypeAny143(any)).reference=constraint;
		}else if(Is_ref_Type_typeofTypeTrait1(any))		{
			(*As_ref_Type_typeofTypeTrait144(any)).reference=constraint;
		}else		{
			assert_i8Str(0,((Str){18, (i8*)"Unhandled any type"}));
		};
	};
}
void ClearConstraints__ref_Array__ref_Type(Array__ref_Type* anythings){
	for(i64 it=(i64)0; (it<(*anythings).length); it=(it+1))	{
		Type* any=*_bracket__ref_Array__ref_Typei64179(anythings,it);
		if(Is_ref_Type_typeofTypeAny2(any))		{
			(*As_ref_Type_typeofTypeAny145(any)).reference=(Type*)0;
		}else if(Is_ref_Type_typeofTypeTrait1(any))		{
			(*As_ref_Type_typeofTypeTrait146(any)).reference=(Type*)0;
		}else		{
			assert_i8Str(0,((Str){18, (i8*)"Unhandled any type"}));
		};
	};
}
TypeStructure* SpecializeStructure__ref_Semantic_ref_TypeStructure_ref_Array__ref_Type(Semantic* semantic, TypeStructure* self, Array__ref_Type* constraints){
	Structure* structure=(*self).parent;
	for(i64 it=(i64)0; (it<(*structure).typeSpecialized.length); it=(it+1))	{
		if(Equal_Array__ref_TypeArray__ref_Type((**_bracket__ref_Array__ref_TypeStructurei64180((&(*structure).typeSpecialized),it)).constraints,(*constraints)))		{
			TypeStructure* spec=*_bracket__ref_Array__ref_TypeStructurei64181((&(*structure).typeSpecialized),it);
			return spec;
		};
	};
	TypeStructure* spec=New_typeofTypeStructure126();
	(*spec).parent=(*self).parent;
	ApplyConstraints__ref_Array__ref_Type_ref_Array__ref_Type((&(*self).constraints),constraints);
	for(i64 it=(i64)0; (it<(*self).fields.length); it=(it+1))	{
		Type* any=(Type*)0;
		Type* field=CloneAny__ref_Type_ref__ref_Type((*_bracket__ref_Array__ref_Typei64183((&(*self).fields),it)),(&any));
		Push_ref_Array__ref_Type_ref_Type33((&(*spec).fields),field);
		if(_notEq__ref_Type_typeofNil3(any))		{
			(*spec).incomplete=true;
		};
	};
	for(i64 it=(i64)0; (it<(*self).constraints.length); it=(it+1))	{
		Push_ref_Array__ref_Type_ref_Type34((&(*spec).constraints),Clone__ref_Type((*_bracket__ref_Array__ref_Typei64185((&(*self).constraints),it))));
	};
	ClearConstraints__ref_Array__ref_Type((&(*self).constraints));
	for(i64 it=(i64)0; (it<(*spec).fields.length); it=(it+1))	{
		Type* field=*_bracket__ref_Array__ref_Typei64186((&(*spec).fields),it);
		Annotate__ref_Semantic_ref_Type(semantic,field);
	};
	Push_ref_Array__ref_TypeStructure_ref_TypeStructure35((&(*structure).typeSpecialized),spec);
	Push_ref_Array__ref_TypeStructure_ref_TypeStructure36((&structures),spec);
	return spec;
}
void Init__ref_Trait(Trait* self){
	(*self).super.kind=Id__typeofTrait();
	Init__ref_TypeTrait((&(*self).typeTrait));
	(*self).typeTrait.trai=self;
	(*self).super.typ=(&(*self).typeTrait.super);
}
void AddFunction__ref_Trait_ref_Function(Trait* self, Function* function){
	Push_ref_Array__ref_Function_ref_Function37((&(*self).required),function);
}
void Init__ref_Identifier(Identifier* self){
	(*self).super.kind=Id__typeofIdentifier();
}
void Init__ref_Variable(Variable* self){
	(*self).super.kind=Id__typeofVariable();
}
void Init__ref_Assign(Assign* self){
	(*self).super.kind=Id__typeofAssign();
}
void Init__ref_TypeAs(TypeAs* self){
	(*self).super.kind=Id__typeofTypeAs();
}
void Init__ref_ExpressionList(ExpressionList* self){
	Init_ref_Array__ref_Expr2((&(*self).list));
	(*self).super.kind=Id__typeofExpressionList();
}
void Add__ref_ExpressionList_ref_Expr(ExpressionList* list, Expr* expr){
	assert_ref_ExprStr1(expr,((Str){37, (i8*)"Cannot add nil item to ExpressionList"}));
	Push_ref_Array__ref_Expr_ref_Expr38((&(*list).list),expr);
}
i32 Id__typeofFunction(){
	return 1;
}
i32 Id__typeofStructure(){
	return 2;
}
i32 Id__typeofVariable(){
	return 3;
}
i32 Id__typeofBlock(){
	return 4;
}
i32 Id__typeofIdentifier(){
	return 5;
}
i32 Id__typeofCall(){
	return 7;
}
i32 Id__typeofExpressionList(){
	return 8;
}
i32 Id__typeofIf(){
	return 9;
}
i32 Id__typeofFor(){
	return 10;
}
i32 Id__typeofTrait(){
	return 11;
}
i32 Id__typeofFunctionSpec(){
	return 14;
}
i32 Id__typeofAccess(){
	return 15;
}
i32 Id__typeofTypeAs(){
	return 16;
}
i32 Id__typeofAssign(){
	return 17;
}
i32 Id__typeofForList(){
	return 19;
}
i32 Id__typeofStringConstant(){
	return 20;
}
i32 Id__typeofNumberConstant(){
	return 21;
}
i32 Id__typeofBranch(){
	return 23;
}
i32 Id__typeofReturn(){
	return 24;
}
Str TokenString_i32(i32 token){
	if((token==kNumber))	{
		return ((Str){6, (i8*)"number"});
	};
	if((token==kStruct))	{
		return ((Str){6, (i8*)"struct"});
	};
	if((token==kIdentifier))	{
		return ((Str){10, (i8*)"identifier"});
	};
	if((token==kString))	{
		return ((Str){6, (i8*)"string"});
	};
	if((token==kRef))	{
		return ((Str){3, (i8*)"ref"});
	};
	if((token==kFunction))	{
		return ((Str){2, (i8*)"fn"});
	};
	if((token==kTrait))	{
		return ((Str){5, (i8*)"trait"});
	};
	if((token==kEndLine))	{
		return ((Str){11, (i8*)"end of line"});
	};
	if((token==kIf))	{
		return ((Str){2, (i8*)"if"});
	};
	if((token==kElse))	{
		return ((Str){4, (i8*)"else"});
	};
	return StringFromChar_i8((i8)token);
}
i8 _eq__Tokeni64(Token token, i64 kind){
	return (token.Type==kind);
}
i8 _notEq__Tokeni64(Token token, i64 kind){
	return (token.Type!=kind);
}
Lexer Lexer_Stri64(Str file, i64 fileNumber){
	Lexer self={0};
	self.currentLine=1;
	self.currentColumn=0;
	self.currentFile=fileNumber;
	self.file=FileOpen(file.chars,((Str){1, (i8*)"r"}).chars);
	if(_eq__ref_FileHandle_typeofNil9(self.file))	{
		Print_Str(_add__StrStr(_add__StrStr(((Str){21, (i8*)"Failed to open file '"}),file),((Str){1, (i8*)"'"})));
		return self;
	};
	self.data=Alloc_typeofi8i645(100000);
	u64 newLen=FileRead(self.data,1,100000,self.file);
	Token token=Next__ref_Lexer((&self));
	while(((token.Type!=0)&&(token.Type!=(0-1))))	{
		Push_ref_Array_TokenToken39((&self.tokens),token);
		token=Next__ref_Lexer((&self));
	};
	Token none={0};
	Push_ref_Array_TokenToken40((&self.tokens),none);
	Push_ref_Array_TokenToken41((&self.tokens),none);
	Push_ref_Array_TokenToken42((&self.tokens),none);
	return self;
}
i32 Peek__ref_Lexer(Lexer* self){
	return (i32)(*((*self).data+(*self).dataIndex));
}
i32 Peek__ref_Lexeri64(Lexer* self, i64 at){
	return (i32)(*((*self).data+((*self).dataIndex+at)));
}
i32 Get__ref_Lexer(Lexer* self){
	i32 character=Peek__ref_Lexer(self);
	(*self).dataIndex=((*self).dataIndex+1);
	(*self).currentColumn=((*self).currentColumn+1);
	return character;
}
Token At__ref_Lexeri64(Lexer* self, i64 i){
	return (*_bracket__ref_Array_Tokeni64187((&(*self).tokens),((*self).at+i)));
}
void Eat__ref_Lexer(Lexer* self){
	(*self).at=((*self).at+1);
}
void Eat__ref_Lexeri64(Lexer* self, i64 count){
	(*self).at=((*self).at+count);
}
Token Next__ref_Lexer(Lexer* self){
	i8 insertNewLine={0};
	while(isspace(Peek__ref_Lexer(self)))	{
		if((Get__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"\n"}))))		{
			(*self).currentLine=((*self).currentLine+1);
			(*self).currentColumn=0;
			insertNewLine=1;
		};
	};
	if((((insertNewLine&&((*self).tokens.length>0))&&(Peek__ref_Lexer(self)!=Char_Str(((Str){1, (i8*)"{"}))))&&(Peek__ref_Lexer(self)!=Char_Str(((Str){1, (i8*)"}"})))))	{
		i32 t=(*_bracket__ref_Array_Tokeni64188((&(*self).tokens),((*self).tokens.length-1))).Type;
		if(((((((t==kParenClose)||(t==kBraceClose))||(t==kIdentifier))||(t==kNumber))||(t==kString))||((t>=kKeywordsBegin)&&(t<kKeywordsEnd))))		{
			Token t={0};
			t.Type=kEndLine;
			t.at.line=(i32)(*self).currentLine;
			t.at.file=(i16)(*self).currentFile;
			t.at.column=(i16)(*self).currentColumn;
			Push_ref_Array_TokenToken43((&(*self).tokens),t);
		};
	};
	if(((isalpha(Peek__ref_Lexer(self))==true)||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"_"})))))	{
		Token t={0};
		t.at.line=(i32)(*self).currentLine;
		t.at.file=(i16)(*self).currentFile;
		t.at.column=(i16)(*self).currentColumn;
		Array_i8 data={0};
		Init_ref_Array_i84((&data));
		while(((isalnum(Peek__ref_Lexer(self))==true)||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"_"})))))		{
			Push_ref_Array_i8i844((&data),(i8)Get__ref_Lexer(self));
		};
		Push_ref_Array_i8i845((&data),0);
		t.Type=kIdentifier;
		t.value.chars=data.elements;
		t.value.length=(data.length-1);
		if(_eq__StrStr(t.value,((Str){6, (i8*)"struct"})))		{
			t.Type=kStruct;
		}else if(_eq__StrStr(t.value,((Str){2, (i8*)"fn"})))		{
			t.Type=kFunction;
		}else if(_eq__StrStr(t.value,((Str){3, (i8*)"ref"})))		{
			t.Type=kRef;
		}else if(_eq__StrStr(t.value,((Str){5, (i8*)"trait"})))		{
			t.Type=kTrait;
		}else if(_eq__StrStr(t.value,((Str){7, (i8*)"require"})))		{
			t.Type=kRequire;
		}else if(_eq__StrStr(t.value,((Str){3, (i8*)"for"})))		{
			t.Type=kFor;
		}else if(_eq__StrStr(t.value,((Str){5, (i8*)"break"})))		{
			t.Type=kBreak;
		}else if(_eq__StrStr(t.value,((Str){8, (i8*)"continue"})))		{
			t.Type=kContinue;
		}else if(_eq__StrStr(t.value,((Str){2, (i8*)"if"})))		{
			t.Type=kIf;
		}else if(_eq__StrStr(t.value,((Str){4, (i8*)"else"})))		{
			t.Type=kElse;
		}else if(_eq__StrStr(t.value,((Str){6, (i8*)"return"})))		{
			t.Type=kReturn;
		};
		return t;
	};
	if((isdigit(Peek__ref_Lexer(self))==true))	{
		Array_i8 data={0};
		Init_ref_Array_i84((&data));
		if(((Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"0"})))&&(Peek__ref_Lexeri64(self,1)==Char_Str(((Str){1, (i8*)"x"})))))		{
			Push_ref_Array_i8i846((&data),(i8)Get__ref_Lexer(self));
			Push_ref_Array_i8i847((&data),(i8)Get__ref_Lexer(self));
			while((((((((isdigit(Peek__ref_Lexer(self))==true)||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"A"}))))||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"B"}))))||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"C"}))))||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"D"}))))||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"E"}))))||(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"F"})))))			{
				Push_ref_Array_i8i848((&data),(i8)Get__ref_Lexer(self));
			};
		}else		{
			f64 num=0;
			f64 m=10;
			while((isdigit(Peek__ref_Lexer(self))==true))			{
				Push_ref_Array_i8i849((&data),(i8)Get__ref_Lexer(self));
			};
			if(((Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"."})))&&(isdigit(Peek__ref_Lexeri64(self,1))==true)))			{
				Push_ref_Array_i8i850((&data),(i8)Get__ref_Lexer(self));
				while(isdigit(Peek__ref_Lexer(self)))				{
					Push_ref_Array_i8i851((&data),(i8)Get__ref_Lexer(self));
				};
			};
		};
		Push_ref_Array_i8i852((&data),0);
		Token t={0};
		t.Type=kNumber;
		t.value.chars=data.elements;
		t.value.length=(data.length-1);
		t.at.line=(i32)(*self).currentLine;
		t.at.file=(i16)(*self).currentFile;
		t.at.column=(i16)(*self).currentColumn;
		return t;
	};
	if((Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"'"}))))	{
		Get__ref_Lexer(self);
		Array_i8 data={0};
		Init_ref_Array_i84((&data));
		while((Peek__ref_Lexer(self)!=Char_Str(((Str){1, (i8*)"'"}))))		{
			i32 char=Get__ref_Lexer(self);
			if((char==92))			{
				i32 next=Get__ref_Lexer(self);
				if((next==Char_Str(((Str){1, (i8*)"t"}))))				{
					Push_ref_Array_i8i853((&data),(i8)9);
				}else if((next==Char_Str(((Str){1, (i8*)"n"}))))				{
					Push_ref_Array_i8i854((&data),(i8)Char_Str(((Str){1, (i8*)"\n"})));
				}else if((next==Char_Str(((Str){1, (i8*)"0"}))))				{
					Push_ref_Array_i8i855((&data),(i8)0);
				}else if((next==Char_Str(((Str){1, (i8*)"'"}))))				{
					Push_ref_Array_i8i856((&data),(i8)Char_Str(((Str){1, (i8*)"'"})));
				}else if((next==92))				{
					Push_ref_Array_i8i857((&data),(i8)92);
				};
			}else			{
				Push_ref_Array_i8i858((&data),char);
			};
		};
		Push_ref_Array_i8i858((&data),0);
		i32 char=Get__ref_Lexer(self);
		assert_i8((char==Char_Str(((Str){1, (i8*)"'"}))));
		Token t={0};
		t.Type=kString;
		t.value.chars=data.elements;
		t.value.length=(data.length-1);
		t.at.line=(i32)(*self).currentLine;
		t.at.file=(i16)(*self).currentFile;
		t.at.column=(i16)(*self).currentColumn;
		return t;
	};
	Token t={0};
	t.Type=Get__ref_Lexer(self);
	if(((t.Type==Char_Str(((Str){1, (i8*)"/"})))&&(Peek__ref_Lexer(self)==Char_Str(((Str){1, (i8*)"/"})))))	{
		Get__ref_Lexer(self);
		while(((Peek__ref_Lexer(self)!=Char_Str(((Str){1, (i8*)"\n"})))&&(Peek__ref_Lexer(self)!=0)))		{
			Get__ref_Lexer(self);
		};
		return Next__ref_Lexer(self);
	};
	i8* chars=Alloc_typeofi8i646(2);
	(*(chars+0))=(i8)t.Type;
	(*(chars+1))=0;
	t.value=String_i64((*chars));
	t.at.line=(i32)(*self).currentLine;
	t.at.file=(i16)(*self).currentFile;
	t.at.column=(i16)(*self).currentColumn;
	return t;
}
i32 i32FromString_Str(Str string){
	return (i32)dlStringToI64(string.chars);
}
i64 i64FromString_Str(Str string){
	return dlStringToI64(string.chars);
}
f64 f64FromString_Str(Str string){
	f64 value=dlStringToF64(string.chars);
	return value;
}
i32 cstrlen__ref_i8(i8* chars){
	i32 size={0};
	while(((i32)(*(chars+size))!=(i32)0))	{
		size=(i32)(size+1);
	};
	return size;
}
Str String__ref_i8(i8* chars){
	Str string={0};
	string.chars=chars;
	string.length=cstrlen__ref_i8(chars);
	return string;
}
i8 _eq__StrStr(Str l, Str r){
	if((l.length!=r.length))	{
		return false;
	};
	for(i64 it=(i64)0; (it<l.length); it=(it+1))	{
		i8 ll=(*(l.chars+it));
		i8 rr=(*(r.chars+it));
		if(((i64)ll!=(i64)rr))		{
			return false;
		};
	};
	return true;
}
void Print_Str(Str value){
	for(i64 it=(i64)0; (it<value.length); it=(it+1))	{
		putchar((i32)(*(value.chars+it)));
	};
}
i32 Char_Str(Str char){
	assert_i8Str((char.length==1),((Str){24, (i8*)"Exepcted Str of length 1"}));
	return (i32)(*char.chars);
}
Str StringFromChar_i8(i8 char){
	Str out={0};
	out.length=1;
	out.chars=Alloc_typeofi8i647((out.length+1));
	(*out.chars)=char;
	return out;
}
void Println_Str(Str string){
	Print_Str(_add__StrStr(string,((Str){1, (i8*)"\n"})));
}
Str _add__StrStr(Str a, Str b){
	Str v={0};
	v.chars=Alloc_typeofi8i648(((a.length+b.length)+1));
	CopyPtr_ref_i8_ref_i8i641(a.chars,v.chars,a.length);
	CopyPtr_ref_i8_ref_i8i641(b.chars,(v.chars+a.length),b.length);
	v.length=(a.length+b.length);
	(*(v.chars+v.length))=(i8)0;
	return v;
}
Str String_i64(i64 number){
	i64 negative=0;
	i64 n={0};
	i64 count=0;
	if((number==0))	{
		return ((Str){1, (i8*)"0"});
	};
	if((number<0))	{
		negative=true;
		number=(0-number);
	};
	n=number;
	while((n!=0))	{
		n=(n/10);
		count=(count+1);
	};
	assert_i8((count>=1));
	Array_i8 characters={0};
	Init_ref_Array_i8i643((&characters),(count+1));
	i64 a={0};
	a=number;
	for(i64 it=(i64)0; (it<count); it=(it+1))	{
		*_bracket__ref_Array_i8i64189((&characters),((count-it)-1))=(i8)((a%10)+48);
		a=(a/10);
	};
	*_bracket__ref_Array_i8i64190((&characters),count)=(i8)0;
	Str r={0};
	r.length=count;
	r.chars=characters.elements;
	if((negative!=0))	{
		return _add__StrStr(((Str){1, (i8*)"-"}),r);
	};
	return r;
}
Str String_f32(f32 number){
	i64 top=(i64)number;
	f32 fnumber=number;
	if((top<0))	{
		fnumber=(0.0-fnumber);
	};
	i64 bottom=(i64)((fnumber-(f32)(i64)fnumber)*1000);
	Str r=String_i64(top);
	if((bottom!=0))	{
		r=_add__StrStr(_add__StrStr(r,((Str){1, (i8*)"."})),String_i64(bottom));
	};
	return r;
}
void assert_i8Str(i8 condition, Str reason){
	if((condition==(i8)0))	{
		Print_Str(_add__StrStr(_add__StrStr(((Str){10, (i8*)"Aborting: "}),reason),((Str){1, (i8*)"\n"})));
		Backtrace();
		abort();
	};
}
void assert_i8(i8 condition){
	if((condition==(i8)0))	{
		Backtrace();
		abort();
	};
}
i64 Hash_i64(i64 p){
	return p;
}
i64 Hash_Str(Str string){
	i64 hash=5381;
	for(i64 it=(i64)0; (it<string.length); it=(it+1))	{
		hash=(((hash+5)+hash)+(i64)(*(string.chars+it)));
	};
	return hash;
}
i8 HashEqual_StrStr(Str a, Str b){
	return _eq__StrStr(a,b);
}
void Push_ref_Array_ErrorError1(Array_Error* array, Error value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Errori645(array,100);
		}else		{
			Reserve_ref_Array_Errori645(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Block* New_typeofBlock1(){
	Block* t=Alloc_typeofBlocki649(1);
	Init__ref_Block(t);
	return t;
}
i8 _eq__ref_Expr_typeofNil1(Expr* value){
	return ((i64)value==0);
}
i8 _notEq__ref_Expr_typeofNil1(Expr* value){
	return ((i64)value!=0);
}
void Push_ref_Array_StrStr2(Array_Str* array, Str value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Stri646(array,100);
		}else		{
			Reserve_ref_Array_Stri646(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Function* New_typeofFunction2(){
	Function* t=Alloc_typeofFunctioni6410(1);
	Init__ref_Function(t);
	return t;
}
Function* New_typeofFunction3(){
	Function* t=Alloc_typeofFunctioni6411(1);
	Init__ref_Function(t);
	return t;
}
Structure* New_typeofStructure4(){
	Structure* t=Alloc_typeofStructurei6412(1);
	Init__ref_Structure(t);
	return t;
}
i8 _eq__ref_Type_typeofNil2(Type* value){
	return ((i64)value==0);
}
void Push_ref_Array__ref_Type_ref_Type3(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Trait* New_typeofTrait5(){
	Trait* t=Alloc_typeofTraiti6413(1);
	Init__ref_Trait(t);
	return t;
}
i8 _notEq__ref_Function_typeofNil2(Function* value){
	return ((i64)value!=0);
}
TypeOption* New_typeofTypeOption6(){
	TypeOption* t=Alloc_typeofTypeOptioni6414(1);
	Init__ref_TypeOption(t);
	return t;
}
TypeType* New_typeofTypeType7(){
	TypeType* t=Alloc_typeofTypeTypei6415(1);
	Init__ref_TypeType(t);
	return t;
}
TypeIdentifier* New_typeofTypeIdentifier8(){
	TypeIdentifier* t=Alloc_typeofTypeIdentifieri6416(1);
	Init__ref_TypeIdentifier(t);
	return t;
}
TypeGeneric* New_typeofTypeGeneric9(){
	TypeGeneric* t=Alloc_typeofTypeGenerici6417(1);
	Init__ref_TypeGeneric(t);
	return t;
}
void Push_ref_Array__ref_Type_ref_Type4(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeRef* New_typeofTypeRef10(){
	TypeRef* t=Alloc_typeofTypeRefi6418(1);
	Init__ref_TypeRef(t);
	return t;
}
TypeAny* New_typeofTypeAny11(){
	TypeAny* t=Alloc_typeofTypeAnyi6419(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable12(){
	Variable* t=Alloc_typeofVariablei6420(1);
	Init__ref_Variable(t);
	return t;
}
Variable* New_typeofVariable13(){
	Variable* t=Alloc_typeofVariablei6421(1);
	Init__ref_Variable(t);
	return t;
}
Variable* New_typeofVariable14(){
	Variable* t=Alloc_typeofVariablei6422(1);
	Init__ref_Variable(t);
	return t;
}
i8 Is_ref_Expr_typeofExpressionList1(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofExpressionList());
}
ForList* New_typeofForList15(){
	ForList* t=Alloc_typeofForListi6423(1);
	Init__ref_ForList(t);
	return t;
}
ExpressionList* As_ref_Expr_typeofExpressionList1(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofExpressionList()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (ExpressionList*)expr;
}
For* New_typeofFor16(){
	For* t=Alloc_typeofFori6424(1);
	Init__ref_For(t);
	return t;
}
Branch* New_typeofBranch17(){
	Branch* t=Alloc_typeofBranchi6425(1);
	Init__ref_Branch(t);
	return t;
}
If* New_typeofIf18(){
	If* t=Alloc_typeofIfi6426(1);
	Init__ref_If(t);
	return t;
}
If* New_typeofIf19(){
	If* t=Alloc_typeofIfi6427(1);
	Init__ref_If(t);
	return t;
}
Return* New_typeofReturn20(){
	Return* t=Alloc_typeofReturni6428(1);
	Init__ref_Return(t);
	return t;
}
Identifier* New_typeofIdentifier21(){
	Identifier* t=Alloc_typeofIdentifieri6429(1);
	Init__ref_Identifier(t);
	return t;
}
NumberConstant* New_typeofNumberConstant22(){
	NumberConstant* t=Alloc_typeofNumberConstanti6430(1);
	Init__ref_NumberConstant(t);
	return t;
}
StringConstant* New_typeofStringConstant23(){
	StringConstant* t=Alloc_typeofStringConstanti6431(1);
	Init__ref_StringConstant(t);
	return t;
}
Call* New_typeofCall24(){
	Call* t=Alloc_typeofCalli6432(1);
	Init__ref_Call(t);
	return t;
}
Identifier* New_typeofIdentifier25(){
	Identifier* t=Alloc_typeofIdentifieri6433(1);
	Init__ref_Identifier(t);
	return t;
}
Call* New_typeofCall26(){
	Call* t=Alloc_typeofCalli6434(1);
	Init__ref_Call(t);
	return t;
}
Identifier* New_typeofIdentifier27(){
	Identifier* t=Alloc_typeofIdentifieri6435(1);
	Init__ref_Identifier(t);
	return t;
}
ExpressionList* New_typeofExpressionList28(){
	ExpressionList* t=Alloc_typeofExpressionListi6436(1);
	Init__ref_ExpressionList(t);
	return t;
}
void Push_ref_Array__ref_Expr_ref_Expr5(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
i8 _notEq__ref_Type_typeofNil3(Type* value){
	return ((i64)value!=0);
}
Identifier* New_typeofIdentifier29(){
	Identifier* t=Alloc_typeofIdentifieri6437(1);
	Init__ref_Identifier(t);
	return t;
}
TypeType* New_typeofTypeType30(){
	TypeType* t=Alloc_typeofTypeTypei6438(1);
	Init__ref_TypeType(t);
	return t;
}
Call* New_typeofCall31(){
	Call* t=Alloc_typeofCalli6439(1);
	Init__ref_Call(t);
	return t;
}
Identifier* New_typeofIdentifier32(){
	Identifier* t=Alloc_typeofIdentifieri6440(1);
	Init__ref_Identifier(t);
	return t;
}
Access* New_typeofAccess33(){
	Access* t=Alloc_typeofAccessi6441(1);
	Init__ref_Access(t);
	return t;
}
Assign* New_typeofAssign34(){
	Assign* t=Alloc_typeofAssigni6442(1);
	Init__ref_Assign(t);
	return t;
}
Call* New_typeofCall35(){
	Call* t=Alloc_typeofCalli6443(1);
	Init__ref_Call(t);
	return t;
}
Identifier* New_typeofIdentifier36(){
	Identifier* t=Alloc_typeofIdentifieri6444(1);
	Init__ref_Identifier(t);
	return t;
}
Call* New_typeofCall37(){
	Call* t=Alloc_typeofCalli6445(1);
	Init__ref_Call(t);
	return t;
}
Identifier* New_typeofIdentifier38(){
	Identifier* t=Alloc_typeofIdentifieri6446(1);
	Init__ref_Identifier(t);
	return t;
}
void assert_ref_ExprStr1(Expr* condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
Call* New_typeofCall39(){
	Call* t=Alloc_typeofCalli6447(1);
	Init__ref_Call(t);
	return t;
}
Block* New_typeofBlock40(){
	Block* t=Alloc_typeofBlocki6448(1);
	Init__ref_Block(t);
	return t;
}
void Push_ref_Array_StrStr6(Array_Str* array, Str value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Stri646(array,100);
		}else		{
			Reserve_ref_Array_Stri646(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Str* Last_ref_Array_Str1(Array_Str* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array_Stri64216(array,((*array).length-1));
}
void Pop_ref_Array_Str1(Array_Str* array){
	(*array).length=((*array).length-1);
}
i8 _eq__ref_Module_typeofNil3(Module* value){
	return ((i64)value==0);
}
Module** _bracket__ref_Array__ref_Modulei641(Array__ref_Module* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Module** _bracket__ref_Array__ref_Modulei642(Array__ref_Module* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Error* _bracket__ref_Array_Errori643(Array_Error* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Error* _bracket__ref_Array_Errori644(Array_Error* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Type_typeofTypeTrait1(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeTrait());
}
i8 Is_ref_Type_typeofTypeAny2(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeAny());
}
i8 Is_ref_Type_typeofTypeType3(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeType());
}
TypeType* As_ref_Type_typeofTypeType1(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
i8 Is_ref_Type_typeofTypeRef4(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeRef());
}
TypeRef* As_ref_Type_typeofTypeRef2(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
i8 Is_ref_Type_typeofTypeIdentifier5(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeIdentifier());
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier3(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
i8 Is_ref_Expr_typeofStructure2(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofStructure());
}
Structure* As_ref_Expr_typeofStructure2(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
Structure* As_ref_Expr_typeofStructure3(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
i8 Is_ref_Type_typeofTypeGeneric6(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeGeneric());
}
TypeGeneric* As_ref_Type_typeofTypeGeneric4(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
i8 Is_ref_Type_typeofTypeStructure7(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeStructure());
}
TypeStructure* As_ref_Type_typeofTypeStructure5(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeStructure()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeStructure()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeStructure())));
	return (TypeStructure*)typ;
}
Type** _bracket__ref_Array__ref_Typei645(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Type_typeofTypeNumber8(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeNumber());
}
TypeNumber* As_ref_Type_typeofTypeNumber6(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
Type** _bracket__ref_Array__ref_Typei646(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Str* _bracket__ref_Table_StrStrStr1(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64217((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64218((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64219((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64220((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64221((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64222((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
i8 _notEq__ref_FunctionSpec_typeofNil4(FunctionSpec* value){
	return ((i64)value!=0);
}
i8 _notEq__ref_Block_typeofNil5(Block* value){
	return ((i64)value!=0);
}
Expr** _bracket__ref_Array__ref_Expri647(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Str* _bracket__ref_Table_StrStrStr2(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64223((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64224((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64225((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64226((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64227((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64228((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Type** _bracket__ref_Array__ref_Typei648(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Init_ref_Table_StrStr1(Table_StrStr* table){
	(*table).length=0;
	(*table).capacity=16;
	Init_ref_Array_TableNode_StrStr7((&(*table).data));
	Resize_ref_Array_TableNode_StrStri643((&(*table).data),16);
}
Str* _bracket__ref_Table_StrStrStr3(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64229((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64230((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64231((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64232((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64233((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64234((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr4(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64235((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64236((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64237((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64238((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64239((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64240((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr5(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64241((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64242((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64243((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64244((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64245((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64246((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr6(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64247((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64248((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64249((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64250((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64251((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64252((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr7(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64253((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64254((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64255((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64256((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64257((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64258((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr8(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64259((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64260((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64261((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64262((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64263((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64264((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr9(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64265((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64266((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64267((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64268((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64269((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64270((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr10(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64271((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64272((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64273((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64274((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64275((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64276((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr11(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64277((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64278((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64279((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64280((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64281((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64282((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr12(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64283((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64284((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64285((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64286((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64287((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64288((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Str* _bracket__ref_Table_StrStrStr13(Table_StrStr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_StrStr2(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_StrStri64289((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_StrStri64290((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_StrStri64291((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_StrStri64292((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_StrStri64293((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_StrStri64294((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Expr** _bracket__ref_Array__ref_Expri649(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Expr_typeofVariable3(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofVariable());
}
Expr** _bracket__ref_Array__ref_Expri6410(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
FunctionSpec** _bracket__ref_Array__ref_FunctionSpeci6411(Array__ref_FunctionSpec* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi6412(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeStructure** _bracket__ref_Array__ref_TypeStructurei6413(Array__ref_TypeStructure* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 PtrEqual_ref_Structure_ref_Structure1(Structure* lhs, Structure* rhs){
	return ((i64)lhs==(i64)rhs);
}
TypeStructure** _bracket__ref_Array__ref_TypeStructurei6414(Array__ref_TypeStructure* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei6415(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable** _bracket__ref_Array__ref_Variablei6416(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Type_typeofTypeOption9(Type* typ){
	assert_ref_TypeStr2(typ,((Str){34, (i8*)"Is typeof: Expected non nil typeof"}));
	return ((*typ).kind==Id__typeofTypeOption());
}
TypeOption* As_ref_Type_typeofTypeOption7(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef8(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier9(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Structure* As_ref_Expr_typeofStructure4(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
Structure* As_ref_Expr_typeofStructure5(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric10(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
TypeNumber* As_ref_Type_typeofTypeNumber11(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
i8 Is_ref_Expr_typeofBlock4(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofBlock());
}
Block* As_ref_Expr_typeofBlock6(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofBlock()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Block*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6417(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Expr_typeofFunction5(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofFunction());
}
Function* As_ref_Expr_typeofFunction7(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
i8 _eq__ref_Block_typeofNil4(Block* value){
	return ((i64)value==0);
}
Expr** _bracket__ref_Array__ref_Expri6418(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6419(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6420(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6421(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6422(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6423(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6424(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable8(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6425(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6426(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6427(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6428(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6429(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable9(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
i8 Is_ref_Expr_typeofCall6(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofCall());
}
Call* As_ref_Expr_typeofCall10(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofCall()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Call*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6430(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6431(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6432(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6433(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Expr_typeofTypeAs7(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofTypeAs());
}
Function* As_ref_Expr_typeofFunction11(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6434(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6435(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6436(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6437(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6438(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6439(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Expr_typeofFunctionSpec8(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofFunctionSpec());
}
FunctionSpec* As_ref_Expr_typeofFunctionSpec12(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunctionSpec()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (FunctionSpec*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6440(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6441(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6442(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6443(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6444(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6445(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable13(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
i8 Is_ref_Expr_typeofForList9(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofForList());
}
ForList* As_ref_Expr_typeofForList14(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofForList()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (ForList*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6446(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void assert_ref_Type1(Type* condition){
	assert_i8(((i64)condition!=0));
}
Expr** _bracket__ref_Array__ref_Expri6447(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6448(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6449(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 Is_ref_Expr_typeofFor10(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofFor());
}
For* As_ref_Expr_typeofFor15(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFor()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (For*)expr;
}
i8 Is_ref_Expr_typeofIf11(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofIf());
}
If* As_ref_Expr_typeofIf16(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIf()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (If*)expr;
}
i8 _notEq__ref_If_typeofNil6(If* value){
	return ((i64)value!=0);
}
i8 Is_ref_Expr_typeofIdentifier12(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofIdentifier());
}
Identifier* As_ref_Expr_typeofIdentifier17(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIdentifier()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Identifier*)expr;
}
i8 Is_ref_Expr_typeofAccess13(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofAccess());
}
Access* As_ref_Expr_typeofAccess18(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofAccess()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Access*)expr;
}
i8 _notEq__ref_Call_typeofNil7(Call* value){
	return ((i64)value!=0);
}
TypeRef* As_ref_Type_typeofTypeRef12(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef13(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
i8 Is_ref_Expr_typeofAssign14(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofAssign());
}
Assign* As_ref_Expr_typeofAssign19(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofAssign()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Assign*)expr;
}
i8 Is_ref_Expr_typeofTrait15(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofTrait());
}
Trait* As_ref_Expr_typeofTrait20(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
i8 Is_ref_Expr_typeofNumberConstant16(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofNumberConstant());
}
NumberConstant* As_ref_Expr_typeofNumberConstant21(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofNumberConstant()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (NumberConstant*)expr;
}
i8 Is_ref_Expr_typeofStringConstant17(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofStringConstant());
}
StringConstant* As_ref_Expr_typeofStringConstant22(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStringConstant()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (StringConstant*)expr;
}
i8 Is_ref_Expr_typeofReturn18(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofReturn());
}
Return* As_ref_Expr_typeofReturn23(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofReturn()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Return*)expr;
}
i8 PtrEqual_ref_Function_ref_Function2(Function* lhs, Function* rhs){
	return ((i64)lhs==(i64)rhs);
}
Expr** _bracket__ref_Array__ref_Expri6450(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6451(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6452(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6453(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6454(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6455(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6456(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6457(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6458(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6459(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6460(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6461(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6462(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6463(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeType* As_ref_Type_typeofTypeType14(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
Expr** _bracket__ref_Array__ref_Expri6464(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6465(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6466(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6467(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6468(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i6469(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* New_typeofVariable41(){
	Variable* t=Alloc_typeofVariablei6449(1);
	Init__ref_Variable(t);
	return t;
}
Variable* New_typeofVariable42(){
	Variable* t=Alloc_typeofVariablei6450(1);
	Init__ref_Variable(t);
	return t;
}
void assert_ref_TypeStr2(Type* condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
TypeAs* New_typeofTypeAs43(){
	TypeAs* t=Alloc_typeofTypeAsi6451(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs44(){
	TypeAs* t=Alloc_typeofTypeAsi6452(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs45(){
	TypeAs* t=Alloc_typeofTypeAsi6453(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs46(){
	TypeAs* t=Alloc_typeofTypeAsi6454(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs47(){
	TypeAs* t=Alloc_typeofTypeAsi6455(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs48(){
	TypeAs* t=Alloc_typeofTypeAsi6456(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs49(){
	TypeAs* t=Alloc_typeofTypeAsi6457(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs50(){
	TypeAs* t=Alloc_typeofTypeAsi6458(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs51(){
	TypeAs* t=Alloc_typeofTypeAsi6459(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAs* New_typeofTypeAs52(){
	TypeAs* t=Alloc_typeofTypeAsi6460(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeAny* New_typeofTypeAny53(){
	TypeAny* t=Alloc_typeofTypeAnyi6461(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable54(){
	Variable* t=Alloc_typeofVariablei6462(1);
	Init__ref_Variable(t);
	return t;
}
Variable* New_typeofVariable55(){
	Variable* t=Alloc_typeofVariablei6463(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny56(){
	TypeAny* t=Alloc_typeofTypeAnyi6464(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable57(){
	Variable* t=Alloc_typeofVariablei6465(1);
	Init__ref_Variable(t);
	return t;
}
TypeRef* New_typeofTypeRef58(){
	TypeRef* t=Alloc_typeofTypeRefi6466(1);
	Init__ref_TypeRef(t);
	return t;
}
TypeAny* New_typeofTypeAny59(){
	TypeAny* t=Alloc_typeofTypeAnyi6467(1);
	Init__ref_TypeAny(t);
	return t;
}
TypeRef* New_typeofTypeRef60(){
	TypeRef* t=Alloc_typeofTypeRefi6468(1);
	Init__ref_TypeRef(t);
	return t;
}
Variable* New_typeofVariable61(){
	Variable* t=Alloc_typeofVariablei6469(1);
	Init__ref_Variable(t);
	return t;
}
TypeIdentifier* New_typeofTypeIdentifier62(){
	TypeIdentifier* t=Alloc_typeofTypeIdentifieri6470(1);
	Init__ref_TypeIdentifier(t);
	return t;
}
TypeAny* New_typeofTypeAny63(){
	TypeAny* t=Alloc_typeofTypeAnyi6471(1);
	Init__ref_TypeAny(t);
	return t;
}
TypeType* New_typeofTypeType64(){
	TypeType* t=Alloc_typeofTypeTypei6472(1);
	Init__ref_TypeType(t);
	return t;
}
Variable* New_typeofVariable65(){
	Variable* t=Alloc_typeofVariablei6473(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny66(){
	TypeAny* t=Alloc_typeofTypeAnyi6474(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable67(){
	Variable* t=Alloc_typeofVariablei6475(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny68(){
	TypeAny* t=Alloc_typeofTypeAnyi6476(1);
	Init__ref_TypeAny(t);
	return t;
}
TypeType* New_typeofTypeType69(){
	TypeType* t=Alloc_typeofTypeTypei6477(1);
	Init__ref_TypeType(t);
	return t;
}
Variable* New_typeofVariable70(){
	Variable* t=Alloc_typeofVariablei6478(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny71(){
	TypeAny* t=Alloc_typeofTypeAnyi6479(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable72(){
	Variable* t=Alloc_typeofVariablei6480(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny73(){
	TypeAny* t=Alloc_typeofTypeAnyi6481(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable74(){
	Variable* t=Alloc_typeofVariablei6482(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny75(){
	TypeAny* t=Alloc_typeofTypeAnyi6483(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable76(){
	Variable* t=Alloc_typeofVariablei6484(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny77(){
	TypeAny* t=Alloc_typeofTypeAnyi6485(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable78(){
	Variable* t=Alloc_typeofVariablei6486(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny79(){
	TypeAny* t=Alloc_typeofTypeAnyi6487(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable80(){
	Variable* t=Alloc_typeofVariablei6488(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny81(){
	TypeAny* t=Alloc_typeofTypeAnyi6489(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable82(){
	Variable* t=Alloc_typeofVariablei6490(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny83(){
	TypeAny* t=Alloc_typeofTypeAnyi6491(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable84(){
	Variable* t=Alloc_typeofVariablei6492(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny85(){
	TypeAny* t=Alloc_typeofTypeAnyi6493(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable86(){
	Variable* t=Alloc_typeofVariablei6494(1);
	Init__ref_Variable(t);
	return t;
}
TypeAny* New_typeofTypeAny87(){
	TypeAny* t=Alloc_typeofTypeAnyi6495(1);
	Init__ref_TypeAny(t);
	return t;
}
Variable* New_typeofVariable88(){
	Variable* t=Alloc_typeofVariablei6496(1);
	Init__ref_Variable(t);
	return t;
}
Variable* New_typeofVariable89(){
	Variable* t=Alloc_typeofVariablei6497(1);
	Init__ref_Variable(t);
	return t;
}
void Init_ref_Array__ref_TypeNumberi641(Array__ref_TypeNumber* array, i64 length){
	Reserve_ref_Array__ref_TypeNumberi649(array,length);
	(*array).length=length;
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6470(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6471(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6472(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6473(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6474(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6475(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6476(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6477(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6478(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6479(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Init_ref_Array_Functioni642(Array_Function* array, i64 length){
	Reserve_ref_Array_Functioni6410(array,length);
	(*array).length=length;
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6480(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber** _bracket__ref_Array__ref_TypeNumberi6481(Array__ref_TypeNumber* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* New_typeofVariable90(){
	Variable* t=Alloc_typeofVariablei6498(1);
	Init__ref_Variable(t);
	return t;
}
Function* _bracket__ref_Array_Functioni6482(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6483(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6484(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6485(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6486(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6487(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6488(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6489(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* _bracket__ref_Array_Functioni6490(Array_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Block_ref_Block7(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Expr** _bracket__ref_Array__ref_Expri6491(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6492(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable24(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6493(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* As_ref_Expr_typeofFunction25(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
Block** Last_ref_Array__ref_Block2(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64295(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block3(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64296(array,((*array).length-1));
}
void Push_ref_Array__ref_Block_ref_Block8(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Expr** _bracket__ref_Array__ref_Expri6494(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6495(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable26(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
void Pop_ref_Array__ref_Block2(Array__ref_Block* array){
	(*array).length=((*array).length-1);
}
Expr** _bracket__ref_Array__ref_Expri6496(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri6497(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable27(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Expr** _bracket__ref_Array__ref_Expri6498(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Block_ref_Block9(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Function** _bracket__ref_Array__ref_Functioni6499(Array__ref_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 _eq__ref_Function_typeofNil5(Function* value){
	return ((i64)value==0);
}
Block** Last_ref_Array__ref_Block4(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64297(array,((*array).length-1));
}
i8 _notEq__ref_TypeFunctions_typeofNil8(TypeFunctions* value){
	return ((i64)value!=0);
}
Function** _bracket__ref_Array__ref_Functioni64100(Array__ref_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Init_ref_Array_i8i643(Array_i8* array, i64 length){
	Reserve_ref_Array_i8i6412(array,length);
	(*array).length=length;
}
Expr** _bracket__ref_Array__ref_Expri64101(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64102(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64103(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64104(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** Last_ref_Array__ref_Block5(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64298(array,((*array).length-1));
}
Expr** _bracket__ref_Table_Str_ref_ExprStr14(Table_Str_ref_Expr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_Expr3(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64299((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64300((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64301((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64302((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_Expri64303((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64304((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Expr** _bracket__ref_Table_Str_ref_ExprStr15(Table_Str_ref_Expr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_Expr3(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64305((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64306((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64307((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64308((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_Expri64309((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64310((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Expr** _bracket__ref_Table_Str_ref_ExprStr16(Table_Str_ref_Expr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_Expr3(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64311((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64312((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64313((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64314((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_Expri64315((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64316((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
Structure* As_ref_Expr_typeofStructure28(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier15(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Function* As_ref_Expr_typeofFunction29(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
Variable* As_ref_Expr_typeofVariable30(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Trait* As_ref_Expr_typeofTrait31(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
Function** _bracket__ref_Array__ref_Functioni64105(Array__ref_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAs* As_ref_Expr_typeofTypeAs32(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
Block** Last_ref_Array__ref_Block6(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64317(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block7(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64318(array,((*array).length-1));
}
TypeRef* As_ref_Type_typeofTypeRef16(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef17(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef18(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef19(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
Block* As_ref_Expr_typeofBlock33(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofBlock()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Block*)expr;
}
Block** Last_ref_Array__ref_Block8(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64319(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block9(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64320(array,((*array).length-1));
}
void Push_ref_Array__ref_Block_ref_Block10(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Expr** _bracket__ref_Array__ref_Expri64106(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Structure* As_ref_Expr_typeofStructure34(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
Block** Last_ref_Array__ref_Block10(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64321(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block11(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64322(array,((*array).length-1));
}
void Push_ref_Array__ref_Block_ref_Block11(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Type** _bracket__ref_Array__ref_Typei64107(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64108(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAny* As_ref_Type_typeofTypeAny20(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeAs* New_typeofTypeAs91(){
	TypeAs* t=Alloc_typeofTypeAsi6499(1);
	Init__ref_TypeAs(t);
	return t;
}
Variable** _bracket__ref_Array__ref_Variablei64109(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Type_ref_Type12(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Variable** _bracket__ref_Array__ref_Variablei64110(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Structure_ref_Structure13(Array__ref_Structure* array, Structure* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Structurei6413(array,100);
		}else		{
			Reserve_ref_Array__ref_Structurei6413(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_TypeStructure_ref_TypeStructure14(Array__ref_TypeStructure* array, TypeStructure* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_TypeStructurei6414(array,100);
		}else		{
			Reserve_ref_Array__ref_TypeStructurei6414(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Function* As_ref_Expr_typeofFunction35(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
Block** Last_ref_Array__ref_Block12(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64323(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block13(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64324(array,((*array).length-1));
}
void Push_ref_Array__ref_Block_ref_Block15(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Expr** _bracket__ref_Array__ref_Expri64111(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64112(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable36(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Expr** _bracket__ref_Array__ref_Expri64113(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64114(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable37(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Variable* As_ref_Expr_typeofVariable38(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Identifier* As_ref_Expr_typeofIdentifier39(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIdentifier()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Identifier*)expr;
}
TypeType* New_typeofTypeType92(){
	TypeType* t=Alloc_typeofTypeTypei64100(1);
	Init__ref_TypeType(t);
	return t;
}
Access* As_ref_Expr_typeofAccess40(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofAccess()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Access*)expr;
}
TypeRef* As_ref_Type_typeofTypeRef21(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier22(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier23(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier24(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier25(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Structure* As_ref_Expr_typeofStructure41(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
i8 _notEq__ref_Variable_typeofNil9(Variable* value){
	return ((i64)value!=0);
}
i8 _notEq__ref_TypeStructure_typeofNil10(TypeStructure* value){
	return ((i64)value!=0);
}
Identifier* New_typeofIdentifier93(){
	Identifier* t=Alloc_typeofIdentifieri64101(1);
	Init__ref_Identifier(t);
	return t;
}
Call* New_typeofCall94(){
	Call* t=Alloc_typeofCalli64102(1);
	Init__ref_Call(t);
	return t;
}
Call* As_ref_Expr_typeofCall42(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofCall()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Call*)expr;
}
Access* As_ref_Expr_typeofAccess43(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofAccess()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Access*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier26(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier27(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Structure* As_ref_Expr_typeofStructure44(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
void Insert_ref_Array__ref_Expri64_ref_Expr1(Array__ref_Expr* array, i64 index, Expr* value){
	assert_i8Str((index>=0),((Str){28, (i8*)"Cant insert outside of range"}));
	assert_i8Str((index<((*array).length+1)),((Str){28, (i8*)"Cant insert outside of range"}));
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	(*array).length=((*array).length+1);
	for(i64 it=(i64)index; (it<((*array).length-1)); it=(it+1))	{
		i64 at=(((*array).length-1)-it);
		(*_bracket__ref_Array__ref_Expri64325(array,at))=(*_bracket__ref_Array__ref_Expri64326(array,(at-1)));
	};
	*_bracket__ref_Array__ref_Expri64327(array,index)=value;
}
Identifier* New_typeofIdentifier95(){
	Identifier* t=Alloc_typeofIdentifieri64103(1);
	Init__ref_Identifier(t);
	return t;
}
Identifier* As_ref_Expr_typeofIdentifier45(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIdentifier()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Identifier*)expr;
}
Function** _bracket__ref_Array__ref_Functioni64115(Array__ref_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** Last_ref_Array__ref_Block14(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64328(array,((*array).length-1));
}
Expr** _bracket__ref_Array__ref_Expri64116(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64117(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64118(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64119(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Identifier* As_ref_Expr_typeofIdentifier46(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIdentifier()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Identifier*)expr;
}
Expr** _bracket__ref_Array__ref_Expri64120(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function** _bracket__ref_Array__ref_Functioni64121(Array__ref_Function* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Identifier* As_ref_Expr_typeofIdentifier47(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIdentifier()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Identifier*)expr;
}
Expr** _bracket__ref_Array__ref_Expri64122(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64123(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** Last_ref_Array__ref_Block15(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64329(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block16(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64330(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block17(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64331(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block18(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64332(array,((*array).length-1));
}
void assert_ref_FunctionSpec2(FunctionSpec* condition){
	assert_i8(((i64)condition!=0));
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64124(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
ExpressionList* As_ref_Expr_typeofExpressionList48(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofExpressionList()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (ExpressionList*)expr;
}
void assert_ref_ExpressionListStr3(ExpressionList* condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
Expr** _bracket__ref_Array__ref_Expri64125(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void assert_ref__ref_ExprStr4(Expr** condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
Expr** _bracket__ref_Array__ref_Expri64126(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64127(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Trait* As_ref_Expr_typeofTrait49(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
NumberConstant* As_ref_Expr_typeofNumberConstant50(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofNumberConstant()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (NumberConstant*)expr;
}
StringConstant* As_ref_Expr_typeofStringConstant51(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStringConstant()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (StringConstant*)expr;
}
TypeType* As_ref_Type_typeofTypeType28(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
ForList* As_ref_Expr_typeofForList52(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofForList()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (ForList*)expr;
}
i8 _eq__ref_Variable_typeofNil6(Variable* value){
	return ((i64)value==0);
}
Variable* New_typeofVariable96(){
	Variable* t=Alloc_typeofVariablei64104(1);
	Init__ref_Variable(t);
	return t;
}
Expr** _bracket__ref_Array__ref_Expri64128(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Insert_ref_Array__ref_Expri64_ref_Expr2(Array__ref_Expr* array, i64 index, Expr* value){
	assert_i8Str((index>=0),((Str){28, (i8*)"Cant insert outside of range"}));
	assert_i8Str((index<((*array).length+1)),((Str){28, (i8*)"Cant insert outside of range"}));
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	(*array).length=((*array).length+1);
	for(i64 it=(i64)index; (it<((*array).length-1)); it=(it+1))	{
		i64 at=(((*array).length-1)-it);
		(*_bracket__ref_Array__ref_Expri64333(array,at))=(*_bracket__ref_Array__ref_Expri64334(array,(at-1)));
	};
	*_bracket__ref_Array__ref_Expri64335(array,index)=value;
}
For* As_ref_Expr_typeofFor53(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFor()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (For*)expr;
}
Variable* New_typeofVariable97(){
	Variable* t=Alloc_typeofVariablei64105(1);
	Init__ref_Variable(t);
	return t;
}
Block** Last_ref_Array__ref_Block19(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64336(array,((*array).length-1));
}
Block** Last_ref_Array__ref_Block20(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64337(array,((*array).length-1));
}
void Push_ref_Array__ref_Block_ref_Block16(Array__ref_Block* array, Block* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Blocki6411(array,100);
		}else		{
			Reserve_ref_Array__ref_Blocki6411(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
i8 _eq__ref_Call_typeofNil7(Call* value){
	return ((i64)value==0);
}
Identifier* New_typeofIdentifier98(){
	Identifier* t=Alloc_typeofIdentifieri64106(1);
	Init__ref_Identifier(t);
	return t;
}
Call* New_typeofCall99(){
	Call* t=Alloc_typeofCalli64107(1);
	Init__ref_Call(t);
	return t;
}
Identifier* New_typeofIdentifier100(){
	Identifier* t=Alloc_typeofIdentifieri64108(1);
	Init__ref_Identifier(t);
	return t;
}
void Push_ref_Array__ref_Expr_ref_Expr17(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_Expr_ref_Expr18(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Identifier* New_typeofIdentifier101(){
	Identifier* t=Alloc_typeofIdentifieri64109(1);
	Init__ref_Identifier(t);
	return t;
}
NumberConstant* New_typeofNumberConstant102(){
	NumberConstant* t=Alloc_typeofNumberConstanti64110(1);
	Init__ref_NumberConstant(t);
	return t;
}
Identifier* New_typeofIdentifier103(){
	Identifier* t=Alloc_typeofIdentifieri64111(1);
	Init__ref_Identifier(t);
	return t;
}
Call* New_typeofCall104(){
	Call* t=Alloc_typeofCalli64112(1);
	Init__ref_Call(t);
	return t;
}
void Push_ref_Array__ref_Expr_ref_Expr19(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_Expr_ref_Expr20(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Assign* New_typeofAssign105(){
	Assign* t=Alloc_typeofAssigni64113(1);
	Init__ref_Assign(t);
	return t;
}
Assign* As_ref_Expr_typeofAssign54(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofAssign()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Assign*)expr;
}
TypeRef* As_ref_Type_typeofTypeRef29(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef30(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
If* As_ref_Expr_typeofIf55(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIf()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (If*)expr;
}
i8 Is_ref_Expr_typeofBranch19(Expr* expr){
	assert_ref_ExprStr1(expr,((Str){36, (i8*)"Is expr: Expected non nil expression"}));
	return ((*expr).kind==Id__typeofBranch());
}
Return* As_ref_Expr_typeofReturn56(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofReturn()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Return*)expr;
}
Block** Last_ref_Array__ref_Block21(Array__ref_Block* array){
	assert_i8Str(((*array).length>0),((Str){30, (i8*)"Array needs at least 1 element"}));
	return _bracket__ref_Array__ref_Blocki64338(array,((*array).length-1));
}
TypeRef* As_ref_Type_typeofTypeRef31(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption32(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier33(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Structure* As_ref_Expr_typeofStructure57(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
i8 PtrEqual_ref_Type_ref_Type3(Type* lhs, Type* rhs){
	return ((i64)lhs==(i64)rhs);
}
TypeGeneric* As_ref_Type_typeofTypeGeneric34(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
Type** _bracket__ref_Array__ref_Typei64129(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Structure* As_ref_Expr_typeofStructure58(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
TypeType* As_ref_Type_typeofTypeType35(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef36(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier37(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Structure* As_ref_Expr_typeofStructure59(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric38(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
Type** _bracket__ref_Array__ref_Typei64130(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Structure* As_ref_Expr_typeofStructure60(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
TypeType* As_ref_Type_typeofTypeType39(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption40(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef41(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* New_typeofTypeRef106(){
	TypeRef* t=Alloc_typeofTypeRefi64114(1);
	Init__ref_TypeRef(t);
	return t;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier42(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAs* As_ref_Expr_typeofTypeAs61(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
TypeAs* As_ref_Expr_typeofTypeAs62(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
Trait* As_ref_Expr_typeofTrait63(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
Trait* As_ref_Expr_typeofTrait64(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
TypeIdentifier* New_typeofTypeIdentifier107(){
	TypeIdentifier* t=Alloc_typeofTypeIdentifieri64115(1);
	Init__ref_TypeIdentifier(t);
	return t;
}
TypeAny* As_ref_Type_typeofTypeAny43(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeAny* New_typeofTypeAny108(){
	TypeAny* t=Alloc_typeofTypeAnyi64116(1);
	Init__ref_TypeAny(t);
	return t;
}
TypeTrait* As_ref_Type_typeofTypeTrait44(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeTrait* New_typeofTypeTrait109(){
	TypeTrait* t=Alloc_typeofTypeTraiti64117(1);
	Init__ref_TypeTrait(t);
	return t;
}
TypeOption* As_ref_Type_typeofTypeOption45(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeOption* New_typeofTypeOption110(){
	TypeOption* t=Alloc_typeofTypeOptioni64118(1);
	Init__ref_TypeOption(t);
	return t;
}
TypeType* As_ref_Type_typeofTypeType46(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeType* New_typeofTypeType111(){
	TypeType* t=Alloc_typeofTypeTypei64119(1);
	Init__ref_TypeType(t);
	return t;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric47(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
TypeGeneric* New_typeofTypeGeneric112(){
	TypeGeneric* t=Alloc_typeofTypeGenerici64120(1);
	Init__ref_TypeGeneric(t);
	return t;
}
Type** _bracket__ref_Array__ref_Typei64131(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64132(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Type_ref_Type21(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeRef* As_ref_Type_typeofTypeRef48(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* New_typeofTypeRef113(){
	TypeRef* t=Alloc_typeofTypeRefi64121(1);
	Init__ref_TypeRef(t);
	return t;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier49(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAs* As_ref_Expr_typeofTypeAs65(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
TypeAs* As_ref_Expr_typeofTypeAs66(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
Trait* As_ref_Expr_typeofTrait67(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
Trait* As_ref_Expr_typeofTrait68(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
TypeIdentifier* New_typeofTypeIdentifier114(){
	TypeIdentifier* t=Alloc_typeofTypeIdentifieri64122(1);
	Init__ref_TypeIdentifier(t);
	return t;
}
TypeAny* As_ref_Type_typeofTypeAny50(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeAny* New_typeofTypeAny115(){
	TypeAny* t=Alloc_typeofTypeAnyi64123(1);
	Init__ref_TypeAny(t);
	return t;
}
TypeTrait* As_ref_Type_typeofTypeTrait51(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeTrait* New_typeofTypeTrait116(){
	TypeTrait* t=Alloc_typeofTypeTraiti64124(1);
	Init__ref_TypeTrait(t);
	return t;
}
TypeOption* As_ref_Type_typeofTypeOption52(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeOption* New_typeofTypeOption117(){
	TypeOption* t=Alloc_typeofTypeOptioni64125(1);
	Init__ref_TypeOption(t);
	return t;
}
TypeType* As_ref_Type_typeofTypeType53(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeType* New_typeofTypeType118(){
	TypeType* t=Alloc_typeofTypeTypei64126(1);
	Init__ref_TypeType(t);
	return t;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric54(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
TypeGeneric* New_typeofTypeGeneric119(){
	TypeGeneric* t=Alloc_typeofTypeGenerici64127(1);
	Init__ref_TypeGeneric(t);
	return t;
}
Type** _bracket__ref_Array__ref_Typei64133(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64134(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Type_ref_Type22(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
NumberConstant* As_ref_Expr_typeofNumberConstant69(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofNumberConstant()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (NumberConstant*)expr;
}
TypeNumber* As_ref_Type_typeofTypeNumber55(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
TypeNumber* As_ref_Type_typeofTypeNumber56(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
Type** _bracket__ref_Array__ref_Typei64135(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64136(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeRef* As_ref_Type_typeofTypeRef57(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef58(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier59(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier60(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAny* As_ref_Type_typeofTypeAny61(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeAny* As_ref_Type_typeofTypeAny62(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait63(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait64(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeType* As_ref_Type_typeofTypeType65(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeType* As_ref_Type_typeofTypeType66(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption67(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption68(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric69(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric70(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
void assert_ref_TypeStructure3(TypeStructure* condition){
	assert_i8(((i64)condition!=0));
}
i8 PtrEqual_ref_TypeStructure_ref_TypeStructure4(TypeStructure* lhs, TypeStructure* rhs){
	return ((i64)lhs==(i64)rhs);
}
TypeNumber* As_ref_Type_typeofTypeNumber71(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
TypeNumber* As_ref_Type_typeofTypeNumber72(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
i8 PtrEqual_ref_TypeNumber_ref_TypeNumber5(TypeNumber* lhs, TypeNumber* rhs){
	return ((i64)lhs==(i64)rhs);
}
TypeRef* As_ref_Type_typeofTypeRef73(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef74(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption75(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption76(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier77(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier78(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric79(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric80(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
Type** _bracket__ref_Array__ref_Typei64137(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64138(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeType* As_ref_Type_typeofTypeType81(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeType* As_ref_Type_typeofTypeType82(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeNumber* As_ref_Type_typeofTypeNumber83(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
TypeNumber* As_ref_Type_typeofTypeNumber84(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
i8* _bracket__ref_Array_i8i64139(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i64140(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeRef* As_ref_Type_typeofTypeRef85(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
i8* _bracket__ref_Array_i8i64141(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i64142(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeRef* As_ref_Type_typeofTypeRef86(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait87(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait88(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait89(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait90(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
i8 PtrEqual_ref_TypeTrait_ref_TypeTrait6(TypeTrait* lhs, TypeTrait* rhs){
	return ((i64)lhs==(i64)rhs);
}
TypeTrait* As_ref_Type_typeofTypeTrait91(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric92(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
void assert_ref_TypeStructureStr5(TypeStructure* condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
TypeAny* As_ref_Type_typeofTypeAny93(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait94(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier95(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Block* As_ref_Expr_typeofBlock70(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofBlock()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Block*)expr;
}
Expr** _bracket__ref_Array__ref_Expri64144(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64145(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Structure* As_ref_Expr_typeofStructure71(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
Variable** _bracket__ref_Array__ref_Variablei64146(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable** _bracket__ref_Array__ref_Variablei64147(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable** _bracket__ref_Array__ref_Variablei64148(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function* As_ref_Expr_typeofFunction72(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
Identifier* As_ref_Expr_typeofIdentifier73(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofIdentifier()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Identifier*)expr;
}
Call* As_ref_Expr_typeofCall74(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofCall()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Call*)expr;
}
Access* As_ref_Expr_typeofAccess75(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofAccess()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Access*)expr;
}
ExpressionList* As_ref_Expr_typeofExpressionList76(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofExpressionList()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (ExpressionList*)expr;
}
Expr** _bracket__ref_Array__ref_Expri64149(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64150(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* As_ref_Expr_typeofVariable77(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofVariable()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Variable*)expr;
}
Trait* As_ref_Expr_typeofTrait78(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
Structure* As_ref_Expr_typeofStructure79(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
Function* As_ref_Expr_typeofFunction80(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
TypeAs* As_ref_Expr_typeofTypeAs81(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
Trait* As_ref_Expr_typeofTrait82(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
Structure* As_ref_Expr_typeofStructure83(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofStructure()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Structure*)expr;
}
Function* As_ref_Expr_typeofFunction84(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofFunction()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Function*)expr;
}
TypeAs* As_ref_Expr_typeofTypeAs85(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
Trait* As_ref_Expr_typeofTrait86(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
void assert_ref__ref_TypeStr6(Type** condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
TypeRef* As_ref_Type_typeofTypeRef96(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier97(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAny* As_ref_Type_typeofTypeAny98(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait99(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeOption* As_ref_Type_typeofTypeOption100(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeOption()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeOption()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeOption())));
	return (TypeOption*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef101(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef102(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeType* As_ref_Type_typeofTypeType103(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric104(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
Type** _bracket__ref_Array__ref_Typei64151(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeNumber* As_ref_Type_typeofTypeNumber105(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeNumber()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeNumber()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeNumber())));
	return (TypeNumber*)typ;
}
Module** _bracket__ref_Array__ref_Modulei64152(Array__ref_Module* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Module** _bracket__ref_Array__ref_Modulei64153(Array__ref_Module* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8 _notEq__ref_Module_typeofNil11(Module* value){
	return ((i64)value!=0);
}
Module* Alloc_typeofModulei641(i64 count){
	i64 size=(sizeof(Module)*count);
	return (Module*)dlMallocZero(size);
}
void Push_ref_Array__ref_Module_ref_Module23(Array__ref_Module* array, Module* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Modulei6415(array,100);
		}else		{
			Reserve_ref_Array__ref_Modulei6415(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Module** _bracket__ref_Array__ref_Modulei64154(Array__ref_Module* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* Alloc_typeofi8i642(i64 count){
	i64 size=(sizeof(i8)*count);
	return (i8*)dlMallocZero(size);
}
i8 _notEq__ref_i8_typeofNil12(i8* value){
	return ((i64)value!=0);
}
void Init_ref_Array__ref_Type1(Array__ref_Type* array){
}
TypeNumber* New_typeofTypeNumber120(){
	TypeNumber* t=Alloc_typeofTypeNumberi64128(1);
	Init__ref_TypeNumber(t);
	return t;
}
void Init_ref_Array__ref_Expr2(Array__ref_Expr* array){
}
void Init_ref_Table_Str_ref_Expr2(Table_Str_ref_Expr* table){
	(*table).length=0;
	(*table).capacity=16;
	Init_ref_Array_TableNode_Str_ref_Expr8((&(*table).data));
	Resize_ref_Array_TableNode_Str_ref_Expri644((&(*table).data),16);
}
void Init_ref_Table_Str_ref_TypeFunctions3(Table_Str_ref_TypeFunctions* table){
	(*table).length=0;
	(*table).capacity=16;
	Init_ref_Array_TableNode_Str_ref_TypeFunctions9((&(*table).data));
	Resize_ref_Array_TableNode_Str_ref_TypeFunctionsi645((&(*table).data),16);
}
Expr** _bracket__ref_Table_Str_ref_ExprStr17(Table_Str_ref_Expr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_Expr3(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64339((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64340((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64341((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64342((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_Expri64343((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64344((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
TypeFunctions** _bracket__ref_Table_Str_ref_TypeFunctionsStr18(Table_Str_ref_TypeFunctions* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_TypeFunctions4(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64345((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64346((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64347((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64348((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64349((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64350((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
TypeFunctions** _bracket__ref_Table_Str_ref_TypeFunctionsStr19(Table_Str_ref_TypeFunctions* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_TypeFunctions4(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64351((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64352((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64353((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64354((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64355((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64356((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
i8 _eq__ref_TypeFunctions_typeofNil8(TypeFunctions* value){
	return ((i64)value==0);
}
TypeFunctions* Alloc_typeofTypeFunctionsi643(i64 count){
	i64 size=(sizeof(TypeFunctions)*count);
	return (TypeFunctions*)dlMallocZero(size);
}
void Push_ref_Array__ref_Function_ref_Function24(Array__ref_Function* array, Function* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Functioni6416(array,100);
		}else		{
			Reserve_ref_Array__ref_Functioni6416(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Expr** _bracket__ref_Table_Str_ref_ExprStr20(Table_Str_ref_Expr* table, Str key){
	assert_i8Str(((*table).capacity!=0),((Str){19, (i8*)"Table requires Init"}));
	if((((*table).length*2)>(*table).capacity))	{
		Resize_ref_Table_Str_ref_Expr3(table);
	};
	i64 length=(*table).capacity;
	i64 hash=Hash_Str(key);
	i64 at=((hash%(length-1))+1);
	(*table).length=((*table).length+1);
	while(1)	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64357((&(*table).data),at)).hash==0))		{
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64358((&(*table).data),at)).key=key;
			(*_bracket__ref_Array_TableNode_Str_ref_Expri64359((&(*table).data),at)).hash=1;
			return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64360((&(*table).data),at)).value);
		}else		{
			if(HashEqual_StrStr(key,(*_bracket__ref_Array_TableNode_Str_ref_Expri64361((&(*table).data),at)).key))			{
				return (&(*_bracket__ref_Array_TableNode_Str_ref_Expri64362((&(*table).data),at)).value);
			};
			at=((at+1)%length);
		};
	};
}
void Push_ref_Array__ref_Expr_ref_Expr25(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Init_ref_Array_TypeAnyResolved3(Array_TypeAnyResolved* array){
}
void Push_ref_Array__ref_Type_ref_Type26(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeAny* As_ref_Type_typeofTypeAny106(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeAs* New_typeofTypeAs121(){
	TypeAs* t=Alloc_typeofTypeAsi64129(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeTrait* As_ref_Type_typeofTypeTrait107(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeAs* New_typeofTypeAs122(){
	TypeAs* t=Alloc_typeofTypeAsi64130(1);
	Init__ref_TypeAs(t);
	return t;
}
TypeRef* As_ref_Type_typeofTypeRef108(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef109(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeType* As_ref_Type_typeofTypeType110(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeType* As_ref_Type_typeofTypeType111(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric112(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
Type** _bracket__ref_Array__ref_Typei64155(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64156(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier113(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier114(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier115(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier116(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAs* As_ref_Expr_typeofTypeAs87(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier117(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAs* As_ref_Expr_typeofTypeAs88(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier118(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier119(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier120(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier121(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Trait* As_ref_Expr_typeofTrait89(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier122(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Trait* As_ref_Expr_typeofTrait90(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
TypeRef* As_ref_Type_typeofTypeRef123(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeRef* As_ref_Type_typeofTypeRef124(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeRef()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeRef()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeRef())));
	return (TypeRef*)typ;
}
TypeType* As_ref_Type_typeofTypeType125(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeType* As_ref_Type_typeofTypeType126(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeType()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeType()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeType())));
	return (TypeType*)typ;
}
TypeAny* As_ref_Type_typeofTypeAny127(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeGeneric* As_ref_Type_typeofTypeGeneric128(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeGeneric()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeGeneric()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeGeneric())));
	return (TypeGeneric*)typ;
}
Type** _bracket__ref_Array__ref_Typei64157(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64158(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier129(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier130(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier131(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier132(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAs* As_ref_Expr_typeofTypeAs91(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier133(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeAs* As_ref_Expr_typeofTypeAs92(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTypeAs()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (TypeAs*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier134(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier135(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier136(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier137(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Trait* As_ref_Expr_typeofTrait93(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
TypeIdentifier* As_ref_Type_typeofTypeIdentifier138(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeIdentifier()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeIdentifier()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeIdentifier())));
	return (TypeIdentifier*)typ;
}
Trait* As_ref_Expr_typeofTrait94(Expr* expr){
	assert_i8Str(((*expr).kind==Id__typeofTrait()),((Str){23, (i8*)"As typeof Type mismatch"}));
	return (Trait*)expr;
}
FunctionSpec** _bracket__ref_Array__ref_FunctionSpeci64159(Array__ref_FunctionSpec* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64160(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64161(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
FunctionSpec* New_typeofFunctionSpec123(){
	FunctionSpec* t=Alloc_typeofFunctionSpeci64131(1);
	Init__ref_FunctionSpec(t);
	return t;
}
void Push_ref_Array__ref_FunctionSpec_ref_FunctionSpec27(Array__ref_FunctionSpec* array, FunctionSpec* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_FunctionSpeci6417(array,100);
		}else		{
			Reserve_ref_Array__ref_FunctionSpeci6417(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_FunctionSpec_ref_FunctionSpec28(Array__ref_FunctionSpec* array, FunctionSpec* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_FunctionSpeci6417(array,100);
		}else		{
			Reserve_ref_Array__ref_FunctionSpeci6417(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64162(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64163(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64164(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array_TypeAnyResolvedTypeAnyResolved29(Array_TypeAnyResolved* array, TypeAnyResolved value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_TypeAnyResolvedi6418(array,100);
		}else		{
			Reserve_ref_Array_TypeAnyResolvedi6418(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64165(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64166(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64167(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Type_ref_Type30(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64168(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAny* As_ref_Type_typeofTypeAny139(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait140(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64169(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAny* As_ref_Type_typeofTypeAny141(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait142(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64170(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64171(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAnyResolved* _bracket__ref_Array_TypeAnyResolvedi64172(Array_TypeAnyResolved* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array_TypeAnyResolvedTypeAnyResolved31(Array_TypeAnyResolved* array, TypeAnyResolved value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_TypeAnyResolvedi6418(array,100);
		}else		{
			Reserve_ref_Array_TypeAnyResolvedi6418(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
TypeType* New_typeofTypeType124(){
	TypeType* t=Alloc_typeofTypeTypei64132(1);
	Init__ref_TypeType(t);
	return t;
}
TypeIdentifier* New_typeofTypeIdentifier125(){
	TypeIdentifier* t=Alloc_typeofTypeIdentifieri64133(1);
	Init__ref_TypeIdentifier(t);
	return t;
}
void assert_ref_VariableStr7(Variable* condition, Str reason){
	assert_i8Str(((i64)condition!=0),reason);
}
void Push_ref_Array__ref_Variable_ref_Variable32(Array__ref_Variable* array, Variable* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Variablei6419(array,100);
		}else		{
			Reserve_ref_Array__ref_Variablei6419(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Variable** _bracket__ref_Array__ref_Variablei64173(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable** _bracket__ref_Array__ref_Variablei64174(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable** _bracket__ref_Array__ref_Variablei64175(Array__ref_Variable* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64176(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64177(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64178(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAny* As_ref_Type_typeofTypeAny143(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait144(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
Type** _bracket__ref_Array__ref_Typei64179(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAny* As_ref_Type_typeofTypeAny145(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeAny()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeAny()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeAny())));
	return (TypeAny*)typ;
}
TypeTrait* As_ref_Type_typeofTypeTrait146(Type* typ){
	assert_ref_TypeStr2(typ,((Str){31, (i8*)"As tpe: Expected non nil typeof"}));
	if(((*typ).kind!=Id__typeofTypeTrait()))	{
	};
	assert_i8Str(((*typ).kind==Id__typeofTypeTrait()),_add__StrStr(_add__StrStr(_add__StrStr(((Str){14, (i8*)"Type mismatch "}),String_i64((*typ).kind)),((Str){8, (i8*)" is not "})),String_i64(Id__typeofTypeTrait())));
	return (TypeTrait*)typ;
}
TypeStructure** _bracket__ref_Array__ref_TypeStructurei64180(Array__ref_TypeStructure* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeStructure** _bracket__ref_Array__ref_TypeStructurei64181(Array__ref_TypeStructure* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeStructure* New_typeofTypeStructure126(){
	TypeStructure* t=Alloc_typeofTypeStructurei64134(1);
	Init__ref_TypeStructure(t);
	return t;
}
Type** _bracket__ref_Array__ref_Typei64182(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64183(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Type_ref_Type33(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Type** _bracket__ref_Array__ref_Typei64184(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Type** _bracket__ref_Array__ref_Typei64185(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_Type_ref_Type34(Array__ref_Type* array, Type* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Typei647(array,100);
		}else		{
			Reserve_ref_Array__ref_Typei647(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Type** _bracket__ref_Array__ref_Typei64186(Array__ref_Type* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array__ref_TypeStructure_ref_TypeStructure35(Array__ref_TypeStructure* array, TypeStructure* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_TypeStructurei6414(array,100);
		}else		{
			Reserve_ref_Array__ref_TypeStructurei6414(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_TypeStructure_ref_TypeStructure36(Array__ref_TypeStructure* array, TypeStructure* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_TypeStructurei6414(array,100);
		}else		{
			Reserve_ref_Array__ref_TypeStructurei6414(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_Function_ref_Function37(Array__ref_Function* array, Function* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Functioni6416(array,100);
		}else		{
			Reserve_ref_Array__ref_Functioni6416(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array__ref_Expr_ref_Expr38(Array__ref_Expr* array, Expr* value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array__ref_Expri648(array,100);
		}else		{
			Reserve_ref_Array__ref_Expri648(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
i8 _eq__ref_FileHandle_typeofNil9(FileHandle* value){
	return ((i64)value==0);
}
i8* Alloc_typeofi8i645(i64 count){
	i64 size=(sizeof(i8)*count);
	return (i8*)dlMallocZero(size);
}
void Push_ref_Array_TokenToken39(Array_Token* array, Token value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Tokeni6420(array,100);
		}else		{
			Reserve_ref_Array_Tokeni6420(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_TokenToken40(Array_Token* array, Token value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Tokeni6420(array,100);
		}else		{
			Reserve_ref_Array_Tokeni6420(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_TokenToken41(Array_Token* array, Token value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Tokeni6420(array,100);
		}else		{
			Reserve_ref_Array_Tokeni6420(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_TokenToken42(Array_Token* array, Token value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Tokeni6420(array,100);
		}else		{
			Reserve_ref_Array_Tokeni6420(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
Token* _bracket__ref_Array_Tokeni64187(Array_Token* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Token* _bracket__ref_Array_Tokeni64188(Array_Token* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Push_ref_Array_TokenToken43(Array_Token* array, Token value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_Tokeni6420(array,100);
		}else		{
			Reserve_ref_Array_Tokeni6420(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Init_ref_Array_i84(Array_i8* array){
}
void Push_ref_Array_i8i844(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i845(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i846(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i847(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i848(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i849(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i850(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i851(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i852(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i853(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i854(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i855(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i856(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i857(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
void Push_ref_Array_i8i858(Array_i8* array, i8 value){
	if(((*array).capacity<((*array).length+1)))	{
		i64 capacity=((*array).capacity*2);
		if((capacity<100))		{
			Reserve_ref_Array_i8i6412(array,100);
		}else		{
			Reserve_ref_Array_i8i6412(array,capacity);
		};
	};
	*((*array).elements+(*array).length)=value;
	(*array).length=((*array).length+1);
}
i8* Alloc_typeofi8i646(i64 count){
	i64 size=(sizeof(i8)*count);
	return (i8*)dlMallocZero(size);
}
i8* Alloc_typeofi8i647(i64 count){
	i64 size=(sizeof(i8)*count);
	return (i8*)dlMallocZero(size);
}
i8* Alloc_typeofi8i648(i64 count){
	i64 size=(sizeof(i8)*count);
	return (i8*)dlMallocZero(size);
}
void CopyPtr_ref_i8_ref_i8i641(i8* from, i8* to, i64 len){
	i64 size=(sizeof(i8)*len);
	dlMemcpy((i8*)to,(i8*)from,size);
}
i8* _bracket__ref_Array_i8i64189(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
i8* _bracket__ref_Array_i8i64190(Array_i8* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Reserve_ref_Array_Errori645(Array_Error* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_Errori642((*array).elements,count);
		Memset_ref_Errori64i642(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Block* Alloc_typeofBlocki649(i64 count){
	i64 size=(sizeof(Block)*count);
	return (Block*)dlMallocZero(size);
}
void Reserve_ref_Array_Stri646(Array_Str* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_Stri643((*array).elements,count);
		Memset_ref_Stri64i643(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Function* Alloc_typeofFunctioni6410(i64 count){
	i64 size=(sizeof(Function)*count);
	return (Function*)dlMallocZero(size);
}
Function* Alloc_typeofFunctioni6411(i64 count){
	i64 size=(sizeof(Function)*count);
	return (Function*)dlMallocZero(size);
}
Structure* Alloc_typeofStructurei6412(i64 count){
	i64 size=(sizeof(Structure)*count);
	return (Structure*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_Typei647(Array__ref_Type* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Typei644((*array).elements,count);
		Memset_ref__ref_Typei64i644(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Trait* Alloc_typeofTraiti6413(i64 count){
	i64 size=(sizeof(Trait)*count);
	return (Trait*)dlMallocZero(size);
}
TypeOption* Alloc_typeofTypeOptioni6414(i64 count){
	i64 size=(sizeof(TypeOption)*count);
	return (TypeOption*)dlMallocZero(size);
}
TypeType* Alloc_typeofTypeTypei6415(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
TypeIdentifier* Alloc_typeofTypeIdentifieri6416(i64 count){
	i64 size=(sizeof(TypeIdentifier)*count);
	return (TypeIdentifier*)dlMallocZero(size);
}
TypeGeneric* Alloc_typeofTypeGenerici6417(i64 count){
	i64 size=(sizeof(TypeGeneric)*count);
	return (TypeGeneric*)dlMallocZero(size);
}
TypeRef* Alloc_typeofTypeRefi6418(i64 count){
	i64 size=(sizeof(TypeRef)*count);
	return (TypeRef*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6419(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6420(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6421(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6422(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
ForList* Alloc_typeofForListi6423(i64 count){
	i64 size=(sizeof(ForList)*count);
	return (ForList*)dlMallocZero(size);
}
For* Alloc_typeofFori6424(i64 count){
	i64 size=(sizeof(For)*count);
	return (For*)dlMallocZero(size);
}
Branch* Alloc_typeofBranchi6425(i64 count){
	i64 size=(sizeof(Branch)*count);
	return (Branch*)dlMallocZero(size);
}
If* Alloc_typeofIfi6426(i64 count){
	i64 size=(sizeof(If)*count);
	return (If*)dlMallocZero(size);
}
If* Alloc_typeofIfi6427(i64 count){
	i64 size=(sizeof(If)*count);
	return (If*)dlMallocZero(size);
}
Return* Alloc_typeofReturni6428(i64 count){
	i64 size=(sizeof(Return)*count);
	return (Return*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri6429(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
NumberConstant* Alloc_typeofNumberConstanti6430(i64 count){
	i64 size=(sizeof(NumberConstant)*count);
	return (NumberConstant*)dlMallocZero(size);
}
StringConstant* Alloc_typeofStringConstanti6431(i64 count){
	i64 size=(sizeof(StringConstant)*count);
	return (StringConstant*)dlMallocZero(size);
}
Call* Alloc_typeofCalli6432(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri6433(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Call* Alloc_typeofCalli6434(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri6435(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
ExpressionList* Alloc_typeofExpressionListi6436(i64 count){
	i64 size=(sizeof(ExpressionList)*count);
	return (ExpressionList*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_Expri648(Array__ref_Expr* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Expri645((*array).elements,count);
		Memset_ref__ref_Expri64i645(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Identifier* Alloc_typeofIdentifieri6437(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
TypeType* Alloc_typeofTypeTypei6438(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
Call* Alloc_typeofCalli6439(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri6440(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Access* Alloc_typeofAccessi6441(i64 count){
	i64 size=(sizeof(Access)*count);
	return (Access*)dlMallocZero(size);
}
Assign* Alloc_typeofAssigni6442(i64 count){
	i64 size=(sizeof(Assign)*count);
	return (Assign*)dlMallocZero(size);
}
Call* Alloc_typeofCalli6443(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri6444(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Call* Alloc_typeofCalli6445(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri6446(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Call* Alloc_typeofCalli6447(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Block* Alloc_typeofBlocki6448(i64 count){
	i64 size=(sizeof(Block)*count);
	return (Block*)dlMallocZero(size);
}
Str* _bracket__ref_Array_Stri64216(Array_Str* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Resize_ref_Table_StrStr2(Table_StrStr* table){
	Array_TableNode_StrStr data={0};
	Init_ref_Array_TableNode_StrStr7((&data));
	Resize_ref_Array_TableNode_StrStri643((&data),((*table).capacity*2));
	for(i64 it=(i64)0; (it<(*table).data.length); it=(it+1))	{
		if(((*_bracket__ref_Array_TableNode_StrStri64363((&(*table).data),it)).hash!=0))		{
			i64 hash=Hash_Str((*_bracket__ref_Array_TableNode_StrStri64364((&(*table).data),it)).key);
			i64 at=((hash%(data.length-1))+1);
			i8 done=false;
			while((done==false))			{
				if(((*_bracket__ref_Array_TableNode_StrStri64365((&data),at)).hash==0))				{
					(*_bracket__ref_Array_TableNode_StrStri64367((&data),at))=(*_bracket__ref_Array_TableNode_StrStri64369((&(*table).data),it));
					done=true;
				}else				{
					if(HashEqual_StrStr((*_bracket__ref_Array_TableNode_StrStri64370((&(*table).data),it)).key,(*_bracket__ref_Array_TableNode_StrStri64371((&data),at)).key))					{
						(*_bracket__ref_Array_TableNode_StrStri64373((&data),at))=(*_bracket__ref_Array_TableNode_StrStri64375((&(*table).data),it));
						done=true;
					};
					at=((at+1)%data.length);
				};
			};
		};
	};
	(*table).data=data;
	(*table).capacity=((*table).capacity*2);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64217(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64218(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64219(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64220(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64221(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64222(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64223(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64224(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64225(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64226(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64227(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64228(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Init_ref_Array_TableNode_StrStr7(Array_TableNode_StrStr* array){
}
void Resize_ref_Array_TableNode_StrStri643(Array_TableNode_StrStr* array, i64 size){
	if(((*array).capacity<size))	{
		Reserve_ref_Array_TableNode_StrStri6421(array,size);
	};
	(*array).length=size;
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64229(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64230(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64231(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64232(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64233(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64234(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64235(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64236(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64237(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64238(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64239(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64240(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64241(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64242(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64243(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64244(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64245(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64246(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64247(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64248(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64249(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64250(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64251(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64252(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64253(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64254(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64255(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64256(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64257(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64258(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64259(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64260(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64261(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64262(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64263(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64264(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64265(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64266(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64267(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64268(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64269(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64270(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64271(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64272(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64273(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64274(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64275(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64276(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64277(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64278(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64279(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64280(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64281(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64282(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64283(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64284(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64285(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64286(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64287(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64288(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64289(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64290(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64291(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64292(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64293(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64294(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* Alloc_typeofVariablei6449(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6450(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6451(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6452(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6453(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6454(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6455(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6456(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6457(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6458(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6459(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi6460(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6461(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6462(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6463(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6464(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6465(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeRef* Alloc_typeofTypeRefi6466(i64 count){
	i64 size=(sizeof(TypeRef)*count);
	return (TypeRef*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6467(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
TypeRef* Alloc_typeofTypeRefi6468(i64 count){
	i64 size=(sizeof(TypeRef)*count);
	return (TypeRef*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6469(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeIdentifier* Alloc_typeofTypeIdentifieri6470(i64 count){
	i64 size=(sizeof(TypeIdentifier)*count);
	return (TypeIdentifier*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6471(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
TypeType* Alloc_typeofTypeTypei6472(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6473(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6474(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6475(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6476(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
TypeType* Alloc_typeofTypeTypei6477(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6478(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6479(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6480(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6481(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6482(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6483(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6484(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6485(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6486(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6487(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6488(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6489(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6490(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6491(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6492(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6493(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6494(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi6495(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6496(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Variable* Alloc_typeofVariablei6497(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_TypeNumberi649(Array__ref_TypeNumber* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_TypeNumberi646((*array).elements,count);
		Memset_ref__ref_TypeNumberi64i646(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
void Reserve_ref_Array_Functioni6410(Array_Function* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_Functioni647((*array).elements,count);
		Memset_ref_Functioni64i647(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Variable* Alloc_typeofVariablei6498(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_Blocki6411(Array__ref_Block* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Blocki648((*array).elements,count);
		Memset_ref__ref_Blocki64i648(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Block** _bracket__ref_Array__ref_Blocki64295(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64296(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64297(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Reserve_ref_Array_i8i6412(Array_i8* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_i8i649((*array).elements,count);
		Memset_ref_i8i64i649(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Block** _bracket__ref_Array__ref_Blocki64298(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Resize_ref_Table_Str_ref_Expr3(Table_Str_ref_Expr* table){
	Array_TableNode_Str_ref_Expr data={0};
	Init_ref_Array_TableNode_Str_ref_Expr8((&data));
	Resize_ref_Array_TableNode_Str_ref_Expri644((&data),((*table).capacity*2));
	for(i64 it=(i64)0; (it<(*table).data.length); it=(it+1))	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64376((&(*table).data),it)).hash!=0))		{
			i64 hash=Hash_Str((*_bracket__ref_Array_TableNode_Str_ref_Expri64377((&(*table).data),it)).key);
			i64 at=((hash%(data.length-1))+1);
			i8 done=false;
			while((done==false))			{
				if(((*_bracket__ref_Array_TableNode_Str_ref_Expri64378((&data),at)).hash==0))				{
					(*_bracket__ref_Array_TableNode_Str_ref_Expri64380((&data),at))=(*_bracket__ref_Array_TableNode_Str_ref_Expri64382((&(*table).data),it));
					done=true;
				}else				{
					if(HashEqual_StrStr((*_bracket__ref_Array_TableNode_Str_ref_Expri64383((&(*table).data),it)).key,(*_bracket__ref_Array_TableNode_Str_ref_Expri64384((&data),at)).key))					{
						(*_bracket__ref_Array_TableNode_Str_ref_Expri64386((&data),at))=(*_bracket__ref_Array_TableNode_Str_ref_Expri64388((&(*table).data),it));
						done=true;
					};
					at=((at+1)%data.length);
				};
			};
		};
	};
	(*table).data=data;
	(*table).capacity=((*table).capacity*2);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64299(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64300(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64301(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64302(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64303(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64304(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64305(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64306(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64307(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64308(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64309(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64310(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64311(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64312(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64313(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64314(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64315(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64316(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64317(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64318(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64319(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64320(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64321(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64322(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAs* Alloc_typeofTypeAsi6499(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_Structurei6413(Array__ref_Structure* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Structurei6410((*array).elements,count);
		Memset_ref__ref_Structurei64i6410(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
void Reserve_ref_Array__ref_TypeStructurei6414(Array__ref_TypeStructure* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_TypeStructurei6411((*array).elements,count);
		Memset_ref__ref_TypeStructurei64i6411(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Block** _bracket__ref_Array__ref_Blocki64323(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64324(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeType* Alloc_typeofTypeTypei64100(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri64101(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Call* Alloc_typeofCalli64102(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Expr** _bracket__ref_Array__ref_Expri64325(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64326(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64327(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Identifier* Alloc_typeofIdentifieri64103(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Block** _bracket__ref_Array__ref_Blocki64328(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64329(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64330(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64331(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64332(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* Alloc_typeofVariablei64104(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Expr** _bracket__ref_Array__ref_Expri64333(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64334(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Expr** _bracket__ref_Array__ref_Expri64335(Array__ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Variable* Alloc_typeofVariablei64105(i64 count){
	i64 size=(sizeof(Variable)*count);
	return (Variable*)dlMallocZero(size);
}
Block** _bracket__ref_Array__ref_Blocki64336(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Block** _bracket__ref_Array__ref_Blocki64337(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Identifier* Alloc_typeofIdentifieri64106(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Call* Alloc_typeofCalli64107(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri64108(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri64109(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
NumberConstant* Alloc_typeofNumberConstanti64110(i64 count){
	i64 size=(sizeof(NumberConstant)*count);
	return (NumberConstant*)dlMallocZero(size);
}
Identifier* Alloc_typeofIdentifieri64111(i64 count){
	i64 size=(sizeof(Identifier)*count);
	return (Identifier*)dlMallocZero(size);
}
Call* Alloc_typeofCalli64112(i64 count){
	i64 size=(sizeof(Call)*count);
	return (Call*)dlMallocZero(size);
}
Assign* Alloc_typeofAssigni64113(i64 count){
	i64 size=(sizeof(Assign)*count);
	return (Assign*)dlMallocZero(size);
}
Block** _bracket__ref_Array__ref_Blocki64338(Array__ref_Block* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeRef* Alloc_typeofTypeRefi64114(i64 count){
	i64 size=(sizeof(TypeRef)*count);
	return (TypeRef*)dlMallocZero(size);
}
TypeIdentifier* Alloc_typeofTypeIdentifieri64115(i64 count){
	i64 size=(sizeof(TypeIdentifier)*count);
	return (TypeIdentifier*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi64116(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
TypeTrait* Alloc_typeofTypeTraiti64117(i64 count){
	i64 size=(sizeof(TypeTrait)*count);
	return (TypeTrait*)dlMallocZero(size);
}
TypeOption* Alloc_typeofTypeOptioni64118(i64 count){
	i64 size=(sizeof(TypeOption)*count);
	return (TypeOption*)dlMallocZero(size);
}
TypeType* Alloc_typeofTypeTypei64119(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
TypeGeneric* Alloc_typeofTypeGenerici64120(i64 count){
	i64 size=(sizeof(TypeGeneric)*count);
	return (TypeGeneric*)dlMallocZero(size);
}
TypeRef* Alloc_typeofTypeRefi64121(i64 count){
	i64 size=(sizeof(TypeRef)*count);
	return (TypeRef*)dlMallocZero(size);
}
TypeIdentifier* Alloc_typeofTypeIdentifieri64122(i64 count){
	i64 size=(sizeof(TypeIdentifier)*count);
	return (TypeIdentifier*)dlMallocZero(size);
}
TypeAny* Alloc_typeofTypeAnyi64123(i64 count){
	i64 size=(sizeof(TypeAny)*count);
	return (TypeAny*)dlMallocZero(size);
}
TypeTrait* Alloc_typeofTypeTraiti64124(i64 count){
	i64 size=(sizeof(TypeTrait)*count);
	return (TypeTrait*)dlMallocZero(size);
}
TypeOption* Alloc_typeofTypeOptioni64125(i64 count){
	i64 size=(sizeof(TypeOption)*count);
	return (TypeOption*)dlMallocZero(size);
}
TypeType* Alloc_typeofTypeTypei64126(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
TypeGeneric* Alloc_typeofTypeGenerici64127(i64 count){
	i64 size=(sizeof(TypeGeneric)*count);
	return (TypeGeneric*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_Modulei6415(Array__ref_Module* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Modulei6412((*array).elements,count);
		Memset_ref__ref_Modulei64i6412(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
TypeNumber* Alloc_typeofTypeNumberi64128(i64 count){
	i64 size=(sizeof(TypeNumber)*count);
	return (TypeNumber*)dlMallocZero(size);
}
void Init_ref_Array_TableNode_Str_ref_Expr8(Array_TableNode_Str_ref_Expr* array){
}
void Resize_ref_Array_TableNode_Str_ref_Expri644(Array_TableNode_Str_ref_Expr* array, i64 size){
	if(((*array).capacity<size))	{
		Reserve_ref_Array_TableNode_Str_ref_Expri6422(array,size);
	};
	(*array).length=size;
}
void Init_ref_Array_TableNode_Str_ref_TypeFunctions9(Array_TableNode_Str_ref_TypeFunctions* array){
}
void Resize_ref_Array_TableNode_Str_ref_TypeFunctionsi645(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	if(((*array).capacity<size))	{
		Reserve_ref_Array_TableNode_Str_ref_TypeFunctionsi6423(array,size);
	};
	(*array).length=size;
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64339(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64340(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64341(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64342(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64343(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64344(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Resize_ref_Table_Str_ref_TypeFunctions4(Table_Str_ref_TypeFunctions* table){
	Array_TableNode_Str_ref_TypeFunctions data={0};
	Init_ref_Array_TableNode_Str_ref_TypeFunctions9((&data));
	Resize_ref_Array_TableNode_Str_ref_TypeFunctionsi645((&data),((*table).capacity*2));
	for(i64 it=(i64)0; (it<(*table).data.length); it=(it+1))	{
		if(((*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64389((&(*table).data),it)).hash!=0))		{
			i64 hash=Hash_Str((*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64390((&(*table).data),it)).key);
			i64 at=((hash%(data.length-1))+1);
			i8 done=false;
			while((done==false))			{
				if(((*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64391((&data),at)).hash==0))				{
					(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64393((&data),at))=(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64395((&(*table).data),it));
					done=true;
				}else				{
					if(HashEqual_StrStr((*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64396((&(*table).data),it)).key,(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64397((&data),at)).key))					{
						(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64399((&data),at))=(*_bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64401((&(*table).data),it));
						done=true;
					};
					at=((at+1)%data.length);
				};
			};
		};
	};
	(*table).data=data;
	(*table).capacity=((*table).capacity*2);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64345(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64346(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64347(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64348(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64349(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64350(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64351(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64352(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64353(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64354(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64355(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64356(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Reserve_ref_Array__ref_Functioni6416(Array__ref_Function* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Functioni6413((*array).elements,count);
		Memset_ref__ref_Functioni64i6413(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64357(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64358(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64359(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64360(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64361(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64362(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TypeAs* Alloc_typeofTypeAsi64129(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
TypeAs* Alloc_typeofTypeAsi64130(i64 count){
	i64 size=(sizeof(TypeAs)*count);
	return (TypeAs*)dlMallocZero(size);
}
FunctionSpec* Alloc_typeofFunctionSpeci64131(i64 count){
	i64 size=(sizeof(FunctionSpec)*count);
	return (FunctionSpec*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_FunctionSpeci6417(Array__ref_FunctionSpec* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_FunctionSpeci6414((*array).elements,count);
		Memset_ref__ref_FunctionSpeci64i6414(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
void Reserve_ref_Array_TypeAnyResolvedi6418(Array_TypeAnyResolved* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_TypeAnyResolvedi6415((*array).elements,count);
		Memset_ref_TypeAnyResolvedi64i6415(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
TypeType* Alloc_typeofTypeTypei64132(i64 count){
	i64 size=(sizeof(TypeType)*count);
	return (TypeType*)dlMallocZero(size);
}
TypeIdentifier* Alloc_typeofTypeIdentifieri64133(i64 count){
	i64 size=(sizeof(TypeIdentifier)*count);
	return (TypeIdentifier*)dlMallocZero(size);
}
void Reserve_ref_Array__ref_Variablei6419(Array__ref_Variable* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref__ref_Variablei6416((*array).elements,count);
		Memset_ref__ref_Variablei64i6416(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
TypeStructure* Alloc_typeofTypeStructurei64134(i64 count){
	i64 size=(sizeof(TypeStructure)*count);
	return (TypeStructure*)dlMallocZero(size);
}
void Reserve_ref_Array_Tokeni6420(Array_Token* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_Tokeni6417((*array).elements,count);
		Memset_ref_Tokeni64i6417(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
Error* Realloc_ref_Errori642(Error* previous, i64 count){
	u64 size={0};
	size=(sizeof(Error)*count);
	return (Error*)dlRealloc((i8*)previous,size);
}
void Memset_ref_Errori64i642(Error* start, i64 value, i64 count){
	i64 size=(sizeof(Error)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Str* Realloc_ref_Stri643(Str* previous, i64 count){
	u64 size={0};
	size=(sizeof(Str)*count);
	return (Str*)dlRealloc((i8*)previous,size);
}
void Memset_ref_Stri64i643(Str* start, i64 value, i64 count){
	i64 size=(sizeof(Str)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Type** Realloc_ref__ref_Typei644(Type** previous, i64 count){
	u64 size={0};
	size=(sizeof(Type*)*count);
	return (Type**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Typei64i644(Type** start, i64 value, i64 count){
	i64 size=(sizeof(Type*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Expr** Realloc_ref__ref_Expri645(Expr** previous, i64 count){
	u64 size={0};
	size=(sizeof(Expr*)*count);
	return (Expr**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Expri64i645(Expr** start, i64 value, i64 count){
	i64 size=(sizeof(Expr*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64363(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64364(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64365(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64366(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64367(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64368(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64369(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64370(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64371(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64372(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64373(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64374(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_StrStr* _bracket__ref_Array_TableNode_StrStri64375(Array_TableNode_StrStr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
void Reserve_ref_Array_TableNode_StrStri6421(Array_TableNode_StrStr* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_TableNode_StrStri6418((*array).elements,count);
		Memset_ref_TableNode_StrStri64i6418(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
TypeNumber** Realloc_ref__ref_TypeNumberi646(TypeNumber** previous, i64 count){
	u64 size={0};
	size=(sizeof(TypeNumber*)*count);
	return (TypeNumber**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_TypeNumberi64i646(TypeNumber** start, i64 value, i64 count){
	i64 size=(sizeof(TypeNumber*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Function* Realloc_ref_Functioni647(Function* previous, i64 count){
	u64 size={0};
	size=(sizeof(Function)*count);
	return (Function*)dlRealloc((i8*)previous,size);
}
void Memset_ref_Functioni64i647(Function* start, i64 value, i64 count){
	i64 size=(sizeof(Function)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Block** Realloc_ref__ref_Blocki648(Block** previous, i64 count){
	u64 size={0};
	size=(sizeof(Block*)*count);
	return (Block**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Blocki64i648(Block** start, i64 value, i64 count){
	i64 size=(sizeof(Block*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
i8* Realloc_ref_i8i649(i8* previous, i64 count){
	u64 size={0};
	size=(sizeof(i8)*count);
	return (i8*)dlRealloc((i8*)previous,size);
}
void Memset_ref_i8i64i649(i8* start, i64 value, i64 count){
	i64 size=(sizeof(i8)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64376(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64377(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64378(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64379(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64380(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64381(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64382(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64383(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64384(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64385(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64386(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64387(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_Expr* _bracket__ref_Array_TableNode_Str_ref_Expri64388(Array_TableNode_Str_ref_Expr* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Structure** Realloc_ref__ref_Structurei6410(Structure** previous, i64 count){
	u64 size={0};
	size=(sizeof(Structure*)*count);
	return (Structure**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Structurei64i6410(Structure** start, i64 value, i64 count){
	i64 size=(sizeof(Structure*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TypeStructure** Realloc_ref__ref_TypeStructurei6411(TypeStructure** previous, i64 count){
	u64 size={0};
	size=(sizeof(TypeStructure*)*count);
	return (TypeStructure**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_TypeStructurei64i6411(TypeStructure** start, i64 value, i64 count){
	i64 size=(sizeof(TypeStructure*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Module** Realloc_ref__ref_Modulei6412(Module** previous, i64 count){
	u64 size={0};
	size=(sizeof(Module*)*count);
	return (Module**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Modulei64i6412(Module** start, i64 value, i64 count){
	i64 size=(sizeof(Module*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
void Reserve_ref_Array_TableNode_Str_ref_Expri6422(Array_TableNode_Str_ref_Expr* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_TableNode_Str_ref_Expri6419((*array).elements,count);
		Memset_ref_TableNode_Str_ref_Expri64i6419(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
void Reserve_ref_Array_TableNode_Str_ref_TypeFunctionsi6423(Array_TableNode_Str_ref_TypeFunctions* array, i64 count){
	if(((*array).capacity<count))	{
		(*array).elements=Realloc_ref_TableNode_Str_ref_TypeFunctionsi6420((*array).elements,count);
		Memset_ref_TableNode_Str_ref_TypeFunctionsi64i6420(((*array).elements+(*array).capacity),0,(count-(*array).capacity));
		(*array).capacity=count;
	};
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64389(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64390(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64391(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64392(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64393(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64394(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64395(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64396(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64397(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64398(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64399(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64400(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
TableNode_Str_ref_TypeFunctions* _bracket__ref_Array_TableNode_Str_ref_TypeFunctionsi64401(Array_TableNode_Str_ref_TypeFunctions* array, i64 size){
	assert_i8Str(((*array).length>size),((Str){26, (i8*)"Array out of bounds > size"}));
	assert_i8Str(((*array).length>=0),((Str){28, (i8*)"Array out of bounds size < 0"}));
	return ((*array).elements+size);
}
Function** Realloc_ref__ref_Functioni6413(Function** previous, i64 count){
	u64 size={0};
	size=(sizeof(Function*)*count);
	return (Function**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Functioni64i6413(Function** start, i64 value, i64 count){
	i64 size=(sizeof(Function*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
FunctionSpec** Realloc_ref__ref_FunctionSpeci6414(FunctionSpec** previous, i64 count){
	u64 size={0};
	size=(sizeof(FunctionSpec*)*count);
	return (FunctionSpec**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_FunctionSpeci64i6414(FunctionSpec** start, i64 value, i64 count){
	i64 size=(sizeof(FunctionSpec*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TypeAnyResolved* Realloc_ref_TypeAnyResolvedi6415(TypeAnyResolved* previous, i64 count){
	u64 size={0};
	size=(sizeof(TypeAnyResolved)*count);
	return (TypeAnyResolved*)dlRealloc((i8*)previous,size);
}
void Memset_ref_TypeAnyResolvedi64i6415(TypeAnyResolved* start, i64 value, i64 count){
	i64 size=(sizeof(TypeAnyResolved)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Variable** Realloc_ref__ref_Variablei6416(Variable** previous, i64 count){
	u64 size={0};
	size=(sizeof(Variable*)*count);
	return (Variable**)dlRealloc((i8*)previous,size);
}
void Memset_ref__ref_Variablei64i6416(Variable** start, i64 value, i64 count){
	i64 size=(sizeof(Variable*)*count);
	dlMemset((i8*)start,(i32)0,size);
}
Token* Realloc_ref_Tokeni6417(Token* previous, i64 count){
	u64 size={0};
	size=(sizeof(Token)*count);
	return (Token*)dlRealloc((i8*)previous,size);
}
void Memset_ref_Tokeni64i6417(Token* start, i64 value, i64 count){
	i64 size=(sizeof(Token)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TableNode_StrStr* Realloc_ref_TableNode_StrStri6418(TableNode_StrStr* previous, i64 count){
	u64 size={0};
	size=(sizeof(TableNode_StrStr)*count);
	return (TableNode_StrStr*)dlRealloc((i8*)previous,size);
}
void Memset_ref_TableNode_StrStri64i6418(TableNode_StrStr* start, i64 value, i64 count){
	i64 size=(sizeof(TableNode_StrStr)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TableNode_Str_ref_Expr* Realloc_ref_TableNode_Str_ref_Expri6419(TableNode_Str_ref_Expr* previous, i64 count){
	u64 size={0};
	size=(sizeof(TableNode_Str_ref_Expr)*count);
	return (TableNode_Str_ref_Expr*)dlRealloc((i8*)previous,size);
}
void Memset_ref_TableNode_Str_ref_Expri64i6419(TableNode_Str_ref_Expr* start, i64 value, i64 count){
	i64 size=(sizeof(TableNode_Str_ref_Expr)*count);
	dlMemset((i8*)start,(i32)0,size);
}
TableNode_Str_ref_TypeFunctions* Realloc_ref_TableNode_Str_ref_TypeFunctionsi6420(TableNode_Str_ref_TypeFunctions* previous, i64 count){
	u64 size={0};
	size=(sizeof(TableNode_Str_ref_TypeFunctions)*count);
	return (TableNode_Str_ref_TypeFunctions*)dlRealloc((i8*)previous,size);
}
void Memset_ref_TableNode_Str_ref_TypeFunctionsi64i6420(TableNode_Str_ref_TypeFunctions* start, i64 value, i64 count){
	i64 size=(sizeof(TableNode_Str_ref_TypeFunctions)*count);
	dlMemset((i8*)start,(i32)0,size);
}
