//
// Created by sylva on 12-Nov-18.
//

#include "ClojExp.h"
#include <numeric>

map<string, int> ClojExp::global_symbol_table{};

/**
 * \brief parse a clojure expression
 * \param clexpr
 * \return
 */
vector<string> parse_clexpr(const string &clexpr) {
    vector<string> v;
    if (clexpr.back() != ')') return v;

    string s;
    string no_para = clexpr.substr(1, clexpr.length() - 1);
    no_para.pop_back();
    no_para.push_back(' ');
    unsigned open_para_nb(0);
    for_each(no_para.begin(), no_para.end(),
             [&v, &s, &open_para_nb](auto c) {
                 if (c == '(') {
                     ++open_para_nb;
                     s.push_back(c);
                 } else if (c == ')') {
                     --open_para_nb;
                     s.push_back(c);
                 } else if (c == ' ' && open_para_nb == 0) {
                     if (!s.empty()) v.push_back(s);
                     s.clear();
                 } else {
                     s.push_back(c);
                 }
             });
    return v;
}


void ClojExp::eval() {
    cout << "evaluating " << string_exp << "\n";
    if (expression) {
        for (const string s : parse_clexpr(string_exp)) {
            exps.push_back(ClojExp(s));
        }
        string function = exps[0].string_exp;
        //Evaluate all the expressions except the first one.
        for_each(++exps.begin(), exps.end(), [](ClojExp &e) { e.eval(); });

        if (isKnown(function)) {
            //auto sum = [&acc](auto e) { acc += e.get_result(); };
            //for_each(++exps.cbegin(), exps.cend(), sum);
            int seed = function == "+" ? 0 : 1;
            result = accumulate(++exps.cbegin(), exps.cend(), seed, functions.at(function));
        } else if (function == "def") {
            // add symbol in the table
            string symbol = exps[1].string_exp;
            int value = std::stoi(exps[3].string_exp);
            global_symbol_table[symbol] = value;{}
        } else if (function == "defn") {
            // add function in the table
            // TODO check if this can be refactor with deconstruction
            string name = exps[1].string_exp;
            string params = exps[2].string_exp;
            string expression = exps[3].string_exp;


            cout << "Function " << name << " params " << params << " expression " << expression << "\n";


        } else {
            cout << "Exception: unknown function :" << function;
        }
    } else {
        // it's a symbol
        try {
            result = std::stoi(string_exp);
            cout << " result : " << result << "\n";
        } catch (invalid_argument argument) {
            cout << "Can't convert " << string_exp << endl;
        }
    }
}


ostream &operator<<(ostream &o, const ClojExp &exp) {
    o << "[" << exp.string_exp << "]\n";
    for_each(exp.exps.begin(),
             exp.exps.end(),
             [&o](auto e) {
                 o << e;
             });
    return o;
}

int ClojExp::get_result() const {
    return result;
}

void ClojExp::print_table() {
    for_each(global_symbol_table.begin(), global_symbol_table.end(), [](auto p) { cout << "key" << p.first << endl; });
}

int ClojExp::get_symbol_value(string key) {
    return global_symbol_table[key];
}

string eval_clexpr(const string &cexpr) {
    vector<string> elements = parse_clexpr(cexpr);
    for_each(elements.begin(), elements.end(), [](auto e) { cout << e << endl; });
    return "resu";
}



