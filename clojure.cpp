//
// Created by sylva on 10-Nov-18.
//
//
// Created by sylva on 10-Nov-18.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <numeric>


using namespace std;


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

class Cloj_Exp {
    const string string_exp;
    vector<Cloj_Exp> exps;
    bool evaluated;
    int result;

    bool isKnown(string name) {
        return (name == "+");
    }

public:
    explicit Cloj_Exp(string exp) : string_exp(exp), evaluated(false), result(0) {
        evaluated = string_exp.back() != ')';

    };

    int get_result() const { return result; }

    void eval() {

        cout << "evaluating " << string_exp << "\n";
        for (const string s : parse_clexpr(string_exp)) {
            exps.push_back(Cloj_Exp(s));
        }
        if (!evaluated) {
            string function = exps[0].string_exp;
            //Evaluate all the expressions except the first one.
            for_each(++exps.begin(), exps.end(), [](Cloj_Exp &e) { e.eval(); });

            if (!isKnown(function)) {
                cout << "Eception: unknown function :" << function;
//                throw std::exception("Unknown operation");
            } else {
                int acc(0);
                for_each(++exps.cbegin(), exps.cend(), [&acc](auto e){acc+=e.get_result();});
                result = acc;

                //result = (exps[1].get_result() + exps[0].get_result());
            }
        } else {
            result = std::stoi(string_exp);
            cout << " result : " << result << "\n";
        }
    };

    friend ostream &operator<<(ostream &o, const Cloj_Exp &exp);


};

ostream &operator<<(ostream &o, const Cloj_Exp &exp) {
    o << "[" << exp.string_exp << "]\n";
    for_each(exp.exps.begin(),
             exp.exps.end(),
             [&o](auto e) {
                 o << e;
             });
    return o;
}


string eval_clexpr(const string &cexpr) {
    vector<string> elements = parse_clexpr(cexpr);
    for_each(elements.begin(), elements.end(), [](auto e) { cout << e << endl; });
    return "resu";
}


int main() {
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