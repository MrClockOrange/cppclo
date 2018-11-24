//
// Created by sylva on 10-Nov-18.
//
#include <string>
#include <iostream>
#include "ClojExp.h"


using namespace std;


class EXP {
    const string s_string;
    bool evaluated;
};

int main() {
    //string result = eval_clexpr("(+ (+2 3) 1 2)");
    ClojExp exp5("((defn f [a] (+ a 10)) (f a))");
    exp5.eval();
}
