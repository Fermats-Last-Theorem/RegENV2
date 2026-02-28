#pragma once
#include "nfa.h"
#include <string>
#include <set>

using namespace std;

set<int> ec(set<int> s);
bool match_nfa(pair<int, int> nfa, string s);