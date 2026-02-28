#pragma once
#include "ast.h"
#include <vector>

using namespace std;

struct st {
    vector<pair<char, int>> ed;
};

extern vector<st> g;

int ns();
pair<int, int> bd(nd* a);