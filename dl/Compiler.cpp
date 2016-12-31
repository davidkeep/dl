//
//  Compiler.cpp
//  Created by David on 8/18/16.
//

#include <fstream>

#include "Compiler.h"
#include "Printing.h"
#include "Parser.h"
#include "Semantic.h"
#include "CodeGen.h"
#include "Project.h"
#include "Completetion.h"

int Build(Project& project, Config& config, const string &file)
{
    try
    {
        using namespace std::chrono;
        auto start = steady_clock::now();
        
        if (file[0] == '/') {
            project.ImportFile(file);
        }
        else{
            project.ImportFile(WorkingDirectory() + "/" +  file);
        }
        project.Parse();
        
        auto duration = duration_cast<milliseconds>(steady_clock::now() - start);
        
        Print("Creating ast: " + String(duration.count()) + "ms Total lines: " + String(totalLinesParsed) + "\n");
        
        if(config.printAST)
        {
            Print("-----------AST-Print-----------\n");
            AstPrint print;
            for (auto file : project.Files()) {
                print.Visit(file->ast);
            }
        }
        Semantic sematic(project);
        {
            auto start = steady_clock::now();
            
            for (auto file : project.Files()) {
                sematic.Visit(file->ast);
            }
            auto duration = duration_cast<milliseconds>(steady_clock::now() - start);
            
            Print("Semantic Pass: ");
            Print(duration.count());
            Print("ms\n");
        }
        
        if(config.printAST)
        {
            Print("-----------AST-Annotated-----------\n");
            AstPrint print;
            for (auto file : project.Files()) {
                print.Visit(file->ast);
            }
        }
        
        if (config.run || config.generateC) {
            auto start = steady_clock::now();
            
            CodeGen code(project, sematic);
 
            auto duration = duration_cast<milliseconds>(steady_clock::now() - start);
            
            Print("CodeGen Pass: ");
            Print(duration.count());
            Print("ms\n");
        }
    }
    catch (ParseError error)
    {
        error.Print();
        return 255;
    }
    return 0;
}

int Run(const string &path, bool noreturn)
{
    if(noreturn){
        //This doesn't return to our proccess after running
        return execl(path.c_str(), path.c_str(), NULL);
    }
    
    return system(path.c_str());
}

int Compile(Project& project, const string& program, const vector<string>& flags)
{
    using namespace std::chrono;
    string file = project.GetDirectory() + "build/build.cc";
    string lflags = " -L" + project.GetDirectory() + "build/ ";
    string cflags;
    for (const auto& flag : flags) {
        cflags += " ";
        if(flag.length() && flag[0] != '/')
            cflags += flag;
        else
            cflags += flag;
    }
    setbuf(stdout, NULL);
    auto start = steady_clock::now();
    
    string command = "clang " + string(file) + " -g -fsanitize=address -O0 -std=c++14 -Wno-parentheses-equality -Wno-c++11-compat -Wno-int-to-void-pointer-cast" + lflags + cflags+ " -o " + program;
    Println(command);
    auto compiled = system(command.c_str());
    
    auto duration = duration_cast<milliseconds>(steady_clock::now() - start);
    
    Print("C Compiler: ");
    Print(duration.count());
    Print("ms\n");
    
    return compiled;
}

