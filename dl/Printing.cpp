//
//  Printing.cpp
//  Created by David on 6/30/16.
//

#include "Printing.h"
#include "AstNode.h"
#include <cxxabi.h>
string DemangleCppAbi(const char* abiName)
{
    string retval;
    int status;
    char *ret = abi::__cxa_demangle(abiName, 0, 0, &status);
    retval = string(ret);
    free(ret);
    return retval;
}

struct Stringify {
    string value;
    int indent = 0;
    void Indent()
    {
        value += '\n';
        for(int i = 0; i < indent; i++)
            value += "   ";
    }
};

