//
//  Testing.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Compiler.h"
#include <unistd.h>
struct Testing {
    Config config;
    
    Testing(){
        config.run = false;
        config.printAST = false;
    }
    void Run(const string& file)
    {
        if(Build(config, file) == 0){
     
            //@TODO remove all this hard coded stuff once link flags can be parsed
            auto libs = "-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo libglfw3.a libstb.a libchipmunk.a libspine.a";
            auto compiled = system((string("clang -o ")+ "test"+ " " + string(file + ".cc") + " -std=c++11 libglfw3.a -Wno-parentheses-equality -g -fsanitize=address -O0 " + libs).c_str());
            assert(compiled == 0);
            
            printf("\nRunning Test:\n");
            
            char cwd[512];
            getcwd(cwd, 512);
            
            auto ran = system("./test");
            
           // execl(path, path,NULL);
            printf("Done %d\n", ran);
        }
    }
};

