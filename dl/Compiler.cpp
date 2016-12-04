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


int Build(Project& project, Config& config, const string &file)
{
    try
    {
        using namespace std::chrono;
        auto start = steady_clock::now();
                
        project.ImportFile(file);
        project.Parse();
        
        auto duration = duration_cast<milliseconds>(steady_clock::now() - start);
        
        Print("Creating ast: ");
        Print(duration.count());
        Print("ms\n");
        
        if(config.printAST)
        {
            Print("-----------AST-Print-----------\n");
            AstPrinter print;
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
            AstPrinter print;
            for (auto file : project.Files()) {
                print.Visit(file->ast);
            }
        }
        
        {
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
