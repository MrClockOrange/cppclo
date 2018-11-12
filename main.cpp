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

int main()
{
	//string result = eval_clexpr("(+ (+2 3) 1 2)");
	Cloj_Exp exp("(+ (+2 3) 1 2 (* 3 (+ 4 2)))");
	Cloj_Exp exp2("(* 3 (+ 4 2))");
	Cloj_Exp exp3("(+ 4 (+ 5 4 (+ 6 7)) 2)");
	//exp.eval();
	exp3.eval();
	cout << exp3 << endl;
	cout << exp3.get_result() << endl;
	//cout << "===========================\n";
	//cout << exp2 << endl;

	//cout << result;
	//cin.get();
}
