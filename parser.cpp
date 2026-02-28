#include "parser.h"

using namespace std;

nd* E(string& p, ll& ix) {
    nd* a = T(p, ix);
    while (ix < p.size() && p[ix] == '|') {
        ix++;
        nd* b = new nd{2, 0, a, T(p, ix)};
        a = b;
    }
    return a;
}

nd* T(string& p, ll& ix) {
    nd* a = F(p, ix);
    while (ix < p.size() && p[ix] != '|' && p[ix] != ')') {
        nd* b = new nd{3, 0, a, F(p, ix)};
        a = b;
    }
    return a;
}

nd* F(string& p, ll& ix) {
    nd* a = nullptr;
    if (ix < p.size() && p[ix] == '(') {
        ix++;
        a = E(p, ix);
        ix++;
    } else {
        a = new nd{0, p[ix], nullptr, nullptr};
        ix++;
    }
    if (ix < p.size() && p[ix] == '*') {
        ix++;
        a = new nd{1, 0, a, nullptr};
    }
    return a;
}

nd* parse_regex(string p) {
    ll ix = 0;
    return E(p, ix);
}