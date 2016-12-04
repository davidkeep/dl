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
};

const string cbuildFile = "build";
const string cheaderFile = "../lang/Header.h";
const string dlLangFile = "lang/dl.dl";

int Run(const string &path, bool noreturn);
int Build(Project& project, Config& config, const string &file);
