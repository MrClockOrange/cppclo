//
// Created by sylva on 12-Nov-18.
//

#ifndef CPPCLO_CLOJEXP_H
#define CPPCLO_CLOJEXP_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

class Cloj_Exp
{
    const string string_exp;
    vector<Cloj_Exp> exps;
    bool evaluated;
    int result;

    static bool isKnown(string name)
    {
        return (name == "+");
    }

public:
    explicit Cloj_Exp(string exp) : string_exp(exp), evaluated(false), result(0)
    {
        evaluated = string_exp.back() != ')';
    };
    int get_result() const;

    void eval();
    friend ostream& operator<<(ostream& o, const Cloj_Exp& exp);
};



#endif //CPPCLO_CLOJEXP_H
