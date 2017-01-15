//
//  Project.h
//  Created by David on 11/20/16.
//

#pragma once
#include "Symbol.h"
#include "Token.h"
#include "Parser.h"
#include "Intrinsics.h"
#include <queue>
#include "Lexer.h"
#include <string>

struct Project;

struct File {
    string directory;
    string name;
    
    Project *project = nullptr;
    Blck ast;
    void AddImported(File& file){
        imported.push_back(&file);
    }
    const vector<File*> Imported() const { return imported; }
private:
    vector<File*> imported;
};

struct Settings {
    Coord coord;
    vector<string> linkerFlags;
    int optimization = 0;
    bool debug = true;
};

struct Project {
    Settings settings;
    
    Project(){
        //base.ast.children
        InsertBuiltin(&base.ast);
        files.push_back(&base);
        g_files.push_back(&base);
    }
    File& ImportFile(const string& path){
        string dir;
        string name;
        auto end = path.find_last_of('/');
        if(end != string::npos){
            dir = path.substr(0, end + 1);
            name = path.substr(end + 1, path.size());
        }
        else{
            name = path;
        }
        
        //Remove all .. from directory names
        while (true) {
        
            auto end = dir.find("/../");
            if(end == string::npos)
                break;
            
            auto start = dir.find_last_of('/', end-1);
            dir.erase (start + 1,end-start + 3);
        }
        
        
        
        File* &file = fileForPath[dir + name];
        Println(dir + name);
        
        if(!file)
        {
            file = new File;
            file->project = this;
            file->name = name;
            file->directory = dir;
            filesToParse.push(file);
        }
        return *file;
    }
    File* FileFromPath(const string& file)
    {
        return fileForPath[file];
    }
    string GetDirectory()
    {
        return files[1]->directory;
    }
    void Parse(){
        Lex lexer;
        ParserInput input;

        while(filesToParse.size()){
            auto file = filesToParse.front();
            files.push_back(file);
        
            auto path = file->directory + file->name;
            if(fileAsStrings.count(path))
            {
                input.FromString(fileAsStrings[path]);
            }
            else if(!input.FromFile(path))
            {
                throw ParseError("File failed to open '" + file->directory + file->name + "'", {});
            }
            lexer.Tokenize(input, (int)g_files.size());
            g_files.push_back(file);
            ::Parse(lexer, *file);
            filesToParse.pop();
        }
    }
    const vector<File*>& Files() {
        return files;
    }
    File base;
private:
    vector<File*> files;
    std::queue<File*> filesToParse;
    table<string, File*> fileForPath;
};
