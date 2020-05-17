#pragma once
#include "Stack.h"
#include <string>
using namespace std;
#include<iostream>

string infix2prefix(const string exp);
double evaluatePrefix(const string exp);
string reverseExp(const string exp);
int precedenceFunc(const char c);

