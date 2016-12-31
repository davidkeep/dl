//
//  main.cpp
//  Created by David on 11/3/14.
//

#include <stdio.h>
#include <stdlib.h>

#include "Compiler.h"
#include "Project.h"
#include <unistd.h>
#include "Completetion.h"

void Run(const string& program)
{
    printf("\nRunning program:\n");
    auto path = "./" + (program);
    path.c_str();
    char buffer[250005];
    strcpy(buffer, path.c_str());
    
   // char* paramList[] = { buffer, buffer, NULL };
   // system(paramList[0]);
    execl(buffer, buffer, NULL);
}
Project project;

void ProccessCommand(const string& command);
void ProccessArgument(Config &config, int& i, int max, const char* args[])
{
    if(strcmp(args[i], "-b") == 0)
    {
        config.run = false;
        config.generateC = false;
    }
    else if(strcmp(args[i], "-p") == 0)
    {
        config.printAST = true;
    }
    else if(strcmp(args[i], "-t") == 0)
    {
        config.runTests = true;
    }
    else if(strcmp(args[i], "-r") == 0)
    {
        config.run = true;
    }
    else if(strcmp(args[i], "-i") == 0)
    {
        config.interactive = true;
    }
    else if(strcmp(args[i], "-map") == 0)
    {
        string fileName = args[i+1];
        fileAsStrings[fileName] = args[i+2];
        i += 3;
        Println("Mapped file ", fileName);
        return;
    }
    else
    {
        ProccessCommand(args[i]);
    }
    i++;
}

struct CompleteCommand
{
    string file;
    int line;
    int column;
    bool dot;
};
vector<CompleteCommand> completions;

void ProccessCommand(const string& command)
{
    ParserInput input;
    input.FromString(command.c_str());
    
    Lex lexer;
    lexer.Tokenize(input, 0);
    
    if (lexer.GetToken(0) == Lexer::Identifier) {
        if (lexer.GetToken(0).value == "completionsAt" || lexer.GetToken(0).value == "completionsDot")
        {
            bool dot = (lexer.GetToken(0).value == "completionsDot");
            
            if (lexer.GetToken(1) != Lexer::String) {
                printf("Expected 'file name'");
            }
            if (lexer.GetToken(2) != Lexer::Number) {
                printf("Expected line number");
            }
            if (lexer.GetToken(3) != Lexer::Number) {
                printf("Expected column number");
            }
            
            string file = lexer.GetToken(1).value;
            int line = atoi(lexer.GetToken(2).value.c_str());
            int column = atoi(lexer.GetToken(3).value.c_str());
            completions.push_back({file, line, column, dot});
            Println("Adding completion: ", file, line, column, dot);
        }
    }
}
void PrintSuggestions()
{
    Println("Completions: ", int(completions.size()));
    for (auto completion : completions) {
        Completions completions;
        for (auto file : project.Files()) {
            completions.Visit(file->ast);
        }
        
        auto theFile = project.FileFromPath(completion.file);
        if (!theFile) {
            Println("No file named ", completion.file);
            continue;
        }
        
        FindExpressionAt findExpression(theFile->ast, completion.line, completion.column);
        if(findExpression.expressions.length){
            for (int i = completion.dot ? findExpression.expressions.length - 1 : 0; i < findExpression.expressions.length; i++) {
                completions.PrintFunctionSuggestionsForExpr(findExpression.expressions[i]);
            }
        }
        else{
            Println("Failed to find expression at ", completion.line,":",completion.column);
        }
    }
}
int main(int argc, const char *argv[])
{
    if (argc < 2) {
        printf("Expected file for argument 1\n");
        return argc;
    }
    Config config;
    string file = argv[1];
    int i = 2;
    while(i < argc)
    {
        ProccessArgument(config, i, argc, argv);
    }
    
    Array<int&> asdf;
    asdf.Push(*new int);
    
    int build = Build(project, config, file);
    if (build != 0) {

        PrintSuggestions();
        return build;
    }
    
    int compiled = 0;
    string program = "build/out";
    
    if (config.generateC || config.run) {
        compiled = Compile(project, program, project.settings.linkerFlags);
    }
    if(compiled != 0)
    {
        Println("Failed to compile");
        return compiled;
    }

    if(config.run){
        Run(program);
    }
    
    PrintSuggestions();
    
    while (config.interactive) {
        std::string command;
        std::getline (std::cin, command);
        ProccessCommand(command);
    }
    
    Println("Complete!");

    return 0;
}
