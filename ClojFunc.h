//
// Created by sylva on 13-Nov-18.
//

#ifndef CPPCLO_CLOJFUNC_H
#define CPPCLO_CLOJFUNC_H

#include "ClojExp.h"


class ClojFunc : ClojExp{
    map<string, int> parameters;
public:
    ClojFunc(string exp, string params) : ClojExp::ClojExp(exp) {

    };
    void set_param(string param, int value);
    void eval();
};


#endif //CPPCLO_CLOJFUNC_H
