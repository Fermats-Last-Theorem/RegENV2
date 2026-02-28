#include "matcher.h"

using namespace std;

set<int> ec(set<int> s) {
    ll sz = 0;
    while (s.size() != sz) {
        sz = s.size();
        vector<int> tmp(s.begin(), s.end()); 
        for (int u : tmp) {
            for (auto e : g[u].ed) {
                if (e.first == 0) {
                    s.insert(e.second);
                }
            }
        }
    }
    return s;
}

bool match_nfa(pair<int, int> nfa, string s) {
    set<int> cr = ec({nfa.first});

    for (ll i = 0; i < s.length(); i++) {
        char c = s[i];
        set<int> nx;
        
        for (int u : cr) {
            for (auto ed : g[u].ed) {
                if (ed.first == c) {
                    nx.insert(ed.second);
                }
            }
        }
        cr = ec(nx);
    }

    if (cr.count(nfa.second)) {
        return true;
    }
    return false;
}