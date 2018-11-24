//
// Created by sylva on 13-Nov-18.
//

#include "ClojFunc.h"

void ClojFunc::eval() {

    ClojExp::eval();
}

void ClojFunc::set_param(string param, int value) {
    parameters[param] = value;
}
