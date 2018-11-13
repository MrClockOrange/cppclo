//
// Created by sylva on 12-Nov-18.
//
#pragma  once
#ifndef CPPCLO_CLOJEXP_H
#define CPPCLO_CLOJEXP_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <map>
#include <functional>

using namespace std;


class ClojExp {

    const string string_exp;
    vector<ClojExp> exps;
    bool evaluated;
    int result;
    map<const string, std::function<int(int, ClojExp)>> functions{
            {"+", [](int i, const ClojExp &e) { return i + e.get_result(); }},
            {"*", [](int i, const ClojExp &e) { return i * e.get_result(); }}
    };

    bool isKnown(const string &name) {
        return functions.find(name) != functions.end();
    }

    static map<string, int> symbol_table;

public:
    static int get_symbol_value(string key);

    explicit ClojExp(string exp) : string_exp(exp), evaluated(false), result(0) {
        evaluated = string_exp.back() != ')';
    };

    int get_result() const;

    void eval();

    static void print_table();

    friend ostream &operator<<(ostream &o, const ClojExp &exp);

};


#endif //CPPCLO_CLOJEXP_H
