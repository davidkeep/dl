//
//  main.cpp
//  Created by David on 11/3/14.
//

#include <stdio.h>
#include <stdlib.h>

#include "Compiler.h"
#include "Project.h"
#include <unistd.h>

int Compile(const string& file, const string& program, const vector<string>& flags)
{
    //@TODO remove all this hard coded stuff once link flags can be parsed
    string cflags;
    for (const auto& flag : flags) {
        cflags += " ";
        cflags += flag;
    }
    setbuf(stdout, NULL);
    auto compiled = system(("clang -g -fsanitize=address -O0 -o "+ program+ " " + string(file) + " -std=c++14 -Wno-parentheses-equality -Wno-c++11-compat" + cflags).c_str());
    return compiled;
}

void Run(const string& program)
{
    printf("\nRunning program:\n");
    auto path = "./" + (program);
    path.c_str();
    char buffer[250005];
    strcpy(buffer, path.c_str());
    
    char* paramList[] = { buffer, buffer, NULL };
    system(paramList[0]);
    //execl(buffer, buffer, NULL);
}

void ProccessArgument(Config &config, const char* arg)
{
    if(strcmp(arg, "-b") == 0)
    {
        config.run = false;
        config.generateC = false;
    }
    else if(strcmp(arg, "-p") == 0)
    {
        config.printAST = true;
    }
    else if(strcmp(arg, "-t") == 0)
    {
        config.runTests = true;
    }
    else if(strcmp(arg, "-r") == 0)
    {
        config.run = true;
    }
}

int main(int argc, const char *argv[])
{
    if (argc < 2) {
        printf("Expected file for argument 1\n");
        return argc;
    }
    Project project;
    Config config;
    string file = argv[1];
    for (int i = 2; i < argc; i++) {
        ProccessArgument(config, argv[i]);
    }
    
    Array<int&> asdf;
    asdf.Push(*new int);
    
    int build = Build(project, config, file);
    if (build != 0) {
        return build;
    }
    
    int compiled = 0;
    string program = "out";
    if (config.generateC || config.run) {
        compiled = Compile("Tests/build.cc", program, project.settings.linkerFlags);
    }
    if(compiled != 0) return compiled;

    if(config.run){
        Run(program);
    }

    return 0;
}
