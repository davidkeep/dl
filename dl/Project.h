//
//  Project.h
//  Created by David on 11/20/16.
//

#pragma once
#include "Symbol.h"
#include "Token.h"
#include "Parser.h"
#include "Intrinsics.h"

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
        
        File* &file = fileForPath[path];
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
    
    void Parse(){
        while(filesToParse.size()){
            auto file = filesToParse.front();
            files.push_back(file);
            
            ParserInput *input = new ParserFileInput(file->directory + file->name);
            
            if(!input->Current())
            {
                throw ParseError("File failed to open '" + file->directory + file->name + "'", {});
            }
            Lex lexer(*input, (int)g_files.size());
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
