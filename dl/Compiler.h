//
//  Compiler.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Symbol.h"

struct Blck;
struct Project;

struct Config {
    bool run = false;
    bool generateC = true;
    bool printAST = false;
    bool release = false;
    bool runTests = false;
    bool interactive = false;
};

const string buildDirectory = "Build";
const string cbuildFile = "build";
const string cheaderFile = "Header.h";

int Run(const string &path, bool noreturn);
int Build(Project& project, Config& config, const string &file);
int Compile(Project& project, const string& program, const vector<string>& flags);
