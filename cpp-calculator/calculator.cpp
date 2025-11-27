// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "calculator.h"


Number numberCalculation(Number& num1, const Number& num2, const string& op) {
    if (op == "+") {
        num1 += num2;
    } else if (op == "-") {
        num1 -= num2;
    } else if (op == "/"){
        num1 /= num2;
    } else if (op == "**"){
        num1 = pow(num1, num2);
    } else if (op == "*"){
       num1 *= num2;
    } else if (op == ":"){
        num1 = num2;
    } 
    return num1;
}


bool ReadNumber(Number& result){
    cin >> result;
    if (cin.fail()) {
        cerr << "Error: Numeric operand expected" << endl;
        return false;
    }  
    return true;
}


bool ReadOperator(string& op) {
    cin >> op;
    // all  of possible  ops
    vector<string> ops = {"+", "-", ":", "/", "*", "**", "c", "=", "q", "s", "l"};
    auto it = find(ops.begin(), ops.end(), op);
    if (it == ops.end()) {
        cerr << "Error: Unknown token " << op << endl;
        return false;
     }
     return true;
}


bool RunCalculatorCycle() {
    vector<Number> memorizedNumber;
    Number number, result;
    string op;

    if (ReadNumber(number)) {
        result = number;

        while(true) {
            if (ReadOperator(op)) {
                if (op == "=") {
                    cout << result << endl;
                } else if (op == "q") {
                    break;
                } else if (op == "s") {
                    memorizedNumber.push_back(result);
                    continue;
                } else if (op == "c") {
                    result = 0;
                    continue;
                } else if (op == "l") {
                    if (memorizedNumber.empty()) {
                        cerr << "Error: Memory is empty" << endl;
                        return false;
                    } else {
                        result = memorizedNumber.back();
                    }
                } else if (ReadNumber(number)) {
                        numberCalculation(result, number, op);
                } else {
                        break;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}
