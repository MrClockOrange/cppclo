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
    ClojExp exp("(+ (+2 3) 1 2 (* 3 (+ 4 2)))");
    ClojExp exp2("(* 3 (+ 4 2))");
    ClojExp exp3("(+ 4 (+ 5 4 (* 6 7)) 2)");


    ClojExp exp4("(def a = 10)");

    //exp.eval();
    exp4.eval();
    cout << exp4 << endl;
    ClojExp::print_table();
    //cout << "=x`==========================\n";
    //cout << exp2 << endl;

    //cout << result;
    //cin.get();
}
