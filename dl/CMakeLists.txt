cmake_minimum_required(VERSION 2.8.9)

set(sources 
	Ast.cpp
	CodeGen.cpp
	Compiler.cpp
	Decl.cpp
	Def.cpp
	Error.cpp
	Ident.cpp
	Lexer.cpp
	main.cpp
	Node.cpp
	Parser.cpp
	Printing.cpp
	Semantic.cpp
	Symbol.cpp
	Intrinsics.cpp
)

project (dl)
add_executable(dl ${sources})
target_compile_options(dl PUBLIC -std=c++14)
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../lang)
