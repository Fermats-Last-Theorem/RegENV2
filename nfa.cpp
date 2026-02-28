#include "nfa.h"

using namespace std;

vector<st> g;

int ns() {
    g.push_back({});
    return g.size() - 1;
}

pair<int, int> bd(nd* a) {
    if (a->t == 0) {
        int u = ns();
        int v = ns();
        g[u].ed.push_back({a->c, v});
        return {u, v};
    }
    
    if (a->t == 3) {
        auto x = bd(a->l);
        auto y = bd(a->r);
        g[x.second].ed.push_back({0, y.first});
        return {x.first, y.second};
    }
    
    if (a->t == 2) {
        int u = ns();
        int v = ns();
        auto x = bd(a->l);
        auto y = bd(a->r);
        g[u].ed.push_back({0, x.first});
        g[u].ed.push_back({0, y.first});
        g[x.second].ed.push_back({0, v});
        g[y.second].ed.push_back({0, v});
        return {u, v};
    }
    
    int u = ns();
    int v = ns();
    auto x = bd(a->l);
    g[u].ed.push_back({0, x.first});
    g[u].ed.push_back({0, v});
    g[x.second].ed.push_back({0, x.first});
    g[x.second].ed.push_back({0, v});
    return {u, v};
}