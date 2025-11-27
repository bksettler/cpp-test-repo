// В этом файле объявления функций.
#pragma once
#include <string>

using namespace std;
using Number = double;

double MathOperationBetweenTwoNumbers(double& num1, double& num2, string& oper);
bool ReadNumber(Number& result);
bool ReadOperator(string& operation);
bool RunCalculatorCycle();
