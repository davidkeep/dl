//
//  Error.cpp
//  Created by David on 5/21/16.
//

#include "Error.h"
#include "Node.h"
#include <fstream>
#include <math.h>
#include "Project.h"

std::vector<File*> g_files;

void Assert(bool cond, const Node &node, const string&str)
{
    if(!cond)
    {
        ParseError(str, node.coord).Print();
        assert(false);
    }
}


void ParseError::Print(){
    if(!line){
    
        fprintf(stderr, "Error: %s\n", error.c_str());
         return;
    }
    
    if(line.file >= g_files.size()){

        fprintf(stderr, "Error: %s\n", error.c_str());
        return;
    }

    fprintf(stderr,"%s:%d:%d: error: %s\n",
           (g_files[line.file]->directory + g_files[line.file]->name).c_str(),
           line.line,
           line.column,
           error.c_str());
    
    string string;
    int l = 0;
    int digits = 0;
    
    if(line.line != 0)
        digits = floor(log10(line.line)) + 1;
    
    
    for(auto i = 0; i < line.column + digits; i++)
    {
        printf("-");
    }
    
    printf("v");
    printf("\n");
    
    
    std::ifstream stream(g_files[line.file]->directory + g_files[line.file]->name);
    while (stream.good())
    {
        getline(stream, string);
        l++;
        
        if(l >= line.line + 6) break;
        else if(l >= line.line)
        {
            printf("%d:%s\n", l, string.c_str());
        }
    }
}


void Print(const Coord& coord)
{
    if(!coord.line){
        
        fprintf(stderr, "Coord: %d:%d:%d\n", coord.file, coord.line, coord.column);
        return;
    }
    
    if(coord.file >= g_files.size()){
        
        assert(false);
        return;
    }
    
    fprintf(stderr,"%s:%d:%d:\n",
            (g_files[coord.file]->directory + g_files[coord.file]->name).c_str(),
            coord.line,
            coord.column);
    
    string string;
    int l = 0;
    int digits = 0;
    
    if(coord.line != 0)
        digits = floor(log10(coord.line)) + 1;
    
    
    for(auto i = 0; i < coord.column + digits; i++)
    {
        printf("-");
    }
    
    printf("v");
    printf("\n");
    
    
    std::ifstream stream(g_files[coord.file]->directory + g_files[coord.file]->name);
    while (stream.good())
    {
        getline(stream, string);
        l++;
        
        if(l >= coord.line + 6) break;
        else if(l >= coord.line)
        {
            printf("%d:%s\n", l, string.c_str());
        }
    }
}

