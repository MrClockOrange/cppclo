//
// Created by sylva on 12-Nov-18.
//

#include "ClojExp.h"
/**
 * \brief parse a clojure expression
 * \param clexpr
 * \return
 */
vector<string> parse_clexpr(const string& clexpr)
{
    vector<string> v;
    if (clexpr.back() != ')') return v;

    string s;
    string no_para = clexpr.substr(1, clexpr.length() - 1);
    no_para.pop_back();
    no_para.push_back(' ');
    unsigned open_para_nb(0);
    for_each(no_para.begin(), no_para.end(),
             [&v, &s, &open_para_nb](auto c)
             {
                 if (c == '(')
                 {
                     ++open_para_nb;
                     s.push_back(c);
                 }
                 else if (c == ')')
                 {
                     --open_para_nb;
                     s.push_back(c);
                 }
                 else if (c == ' ' && open_para_nb == 0)
                 {
                     if (!s.empty()) v.push_back(s);
                     s.clear();
                 }
                 else
                 {
                     s.push_back(c);
                 }
             });
    return v;
}

void Cloj_Exp::eval() {
    cout << "evaluating " << string_exp << "\n";
    if (!evaluated) {
        for (const string s : parse_clexpr(string_exp)) {
            exps.push_back(Cloj_Exp(s));
        }
        string function = exps[0].string_exp;
        //Evaluate all the expressions except the first one.
        for_each(++exps.begin(), exps.end(), [](Cloj_Exp &e) { e.eval(); });

        if (!isKnown(function)) {
            cout << "Eception: unknown function :" << function;
            //                throw std::exception("Unknown operation");
        } else {
            int acc(0);
            for_each(++exps.cbegin(), exps.cend(), [&acc](auto e) { acc += e.get_result(); });
            result = acc;

            //result = (exps[1].get_result() + exps[0].get_result());
        }
    } else {
        result = std::stoi(string_exp);
        cout << " result : " << result << "\n";
    }
}



ostream& operator<<(ostream& o, const Cloj_Exp& exp)
{
    o << "[" << exp.string_exp << "]\n";
    for_each(exp.exps.begin(),
             exp.exps.end(),
             [&o](auto e)
             {
                 o << e;
             });
    return o;
}

int Cloj_Exp::get_result() const {
    return result;
}

string eval_clexpr(const string& cexpr)
{
    vector<string> elements = parse_clexpr(cexpr);
    for_each(elements.begin(), elements.end(), [](auto e) { cout << e << endl; });
    return "resu";
}



