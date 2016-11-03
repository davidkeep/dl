
//
//  Error.cpp
//  lan
//
//  Created by David on 5/21/16.
//  Copyright © 2016 David Leroy Futscher. All rights reserved.
//

#include "Error.h"
#include "Node.h"
#include <fstream>
#include <math.h>
std::vector<FileDescription> g_files;

void Assert(bool cond, const Node &node, const std::string&str)
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
    
    fprintf(stderr,"%s:%d:%d %s\n",
           (g_files[line.file].directory + g_files[line.file].name).c_str(),
           line.line,
           line.column,
           error.c_str());
    
    std::string string;
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
    
    
    std::ifstream stream(g_files[line.file].directory + g_files[line.file].name);
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
