#pragma once
#include "ast.h"

using namespace std;

nd* E(string& p, ll& ix);
nd* T(string& p, ll& ix);
nd* F(string& p, ll& ix);
nd* parse_regex(string p);