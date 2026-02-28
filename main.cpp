#include <iostream>
#include "parser.h"
#include "nfa.h"
#include "matcher.h"

using namespace std;

int main() {
    string p;
    cout << "Enter ex";
    cin >> p;
    
    string s;
    cout << "Enter str";
    cin >> s;

    nd* ast = parse_regex(p);
    auto nfa = bd(ast);
    
    bool res = match_nfa(nfa, s);

    if (res) {
        cout << "you got it!\n";
    } else {
        cout << "No way\n";
    }

    return 0;
}