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

Blck* AstCreate(const std::string &file)
{
    auto ast = new Blck;
    InsertBuiltin(ast);
    {
        ParserInput *input = new ParserFileInput(dlLangFile);
        if(!input->Peek())
        {
            throw ParseError("", {});
        }
        Parser parser(*input);
        parser.file = -1;
        parser.Advance(0); //grab new shit
        Parse(parser, ast);
    }
    
    FileDescription filed;
    auto end = file.find_last_of('/');
    if(end != std::string::npos){
        filed.directory =  file.substr(0, end + 1);
        filed.name =  file.substr(end+1, file.size());
    }
    else{
        filed.name = file;
    }
    filed.file = int(g_importedFiles.size());
    filed.fileparent = -1;
    g_importedFiles.push_back(filed);
    
    for(int i = 0; i < g_importedFiles.size(); i++)
    {
        string file = g_importedFiles[i].directory + g_importedFiles[i].name;
        
        if(g_complete.find(file) == g_complete.end())
        {
            g_files.push_back(g_importedFiles[i]);
            
            g_complete.insert(file);
            
            ParserInput *input;
            input = new ParserFileInput(file);
            if(!input->Peek())
            {
                throw ParseError("File failed to open '" + file + "' parent file " + g_importedFiles[g_importedFiles[i].fileparent].name, {});
            }
            Parser parser(*input);
            parser.file = (int)g_files.size()-1;
            
            parser.Advance(0); //grab new shit
            Parse(parser, ast);
        }
    }
    
    return ast;
}

int Build(Config& config, const std::string &file)
{
    try
    {
        auto start = std::chrono::steady_clock::now();
        
        Blck* ast = AstCreate(file);
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        
        Print("Creating ast: ");
        Print(duration.count());
        Print("ms\n");
        
        if(config.printAST)
        {
            Print("-----------AST-Print-----------\n");
            AstPrinter print;
            print.Visit(*ast);
        }
        Semantic sematic;
        
        {
            auto start = std::chrono::steady_clock::now();
            
            sematic.Visit(*ast);        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
            
            Print("Semantic Pass: ");
            Print(duration.count());
            Print("ms\n");
        }
        
        if(config.printAST)
        {
            Print("-----------AST-Annotated-----------\n");
            AstPrinter print;
            print.Visit(*ast);
        }
        
        {
            auto start = std::chrono::steady_clock::now();
            
            CodeGen code(cbuildFile, sematic);
            code.Visit(*ast);
            
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
            
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

int Run(const std::string &path, bool noreturn)
{
    if(noreturn){
        //This doesn't return to our proccess after running
        return execl(path.c_str(), path.c_str(), NULL);
    }
    
    return system(path.c_str());
}
