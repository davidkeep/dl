//
//  main.c
//  Lan
//
//  Created by David on 11/3/14.
//  Copyright (c) 2014 David Leroy Futscher. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "Parser.h"
#include "Printing.h"
#include "Compiler.h"
#include "Testing.h"

namespace CommandsArgs {
    const char* build = "-b";
    const char* release = "-r";
    const char* print = "-p";

}
void CompileAndRunC(const string& file, const string& program)
{
    //@TODO remove all this hard coded stuff once link flags can be parsed
    auto compiled = system(("clang -o "+ program+ " " + string(file) + " -std=c++14 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo libglfw3.a libstb.a libchipmunk.a libspine.a -Wno-parentheses-equality -Wno-c++11-compat -g -fsanitize=address -O0").c_str());
    
    if(compiled == 0)
    {
        printf("\nRunning program:\n");
        
        
        auto path = "./" + (program);
        path.c_str();
        char buffer[250005];
        strcpy(buffer, path.c_str());
        
        char* paramList[] = { buffer, NULL };
        system(paramList[0]);
    }
}

void ProccessArgument(Config &config, const char* arg)
{
    using namespace CommandsArgs;
    if(strcmp(arg, build) == 0)
    {
        config.run = false;
        config.generateC = false;
    }
    else if(strcmp(arg, release) == 0)
    {
        config.release = true;
    }
    else if(strcmp(arg, print) == 0)
    {
        config.printAST = true;
    }
    else if(strcmp(arg, "-t") == 0)
    {
        config.runTests = true;
    }
}

int main(int argc, const char *argv[])
{
    string file;
    if(argc < 2)
    {
        printf("Expected file for argument 1\n");
        return argc;
    }
    Config config;

    file = argv[1];
    for (int i = 2; i < argc; i++) {
        ProccessArgument(config, argv[i]);
    }
    
    auto build = Build(config, file);
    if(build != 0) return build;
    
    if(config.run)
    {
        string program = "out";
       // CompileAndRunC("build.cc", program);
    }

    return 0;
}