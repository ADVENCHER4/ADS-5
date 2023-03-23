// Copyright 2021 NNTU-CS
#include <ctype.h>
#include <string>
#include <map>
#include "tstack.h"
int getPr(char c) {
    switch (c) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    }
    return -1;
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> ops;
    std::string res, num;
    for (int i = 0; i < inf.length(); i++) {
        if (isdigit(inf[i])) {
            num += inf[i];
        } else { // операция
            if (num.length() > 0) {
                res += num;
                res += " ";
                num = "";
            }
            if (inf[i] == '(' ||
                ops.IsEmpty() ||
                getPr(inf[i]) > getPr(ops.Get())) {
                ops.Push(inf[i]);
            } else if (inf[i] == ')') {
                char sim = ops.Pop();
                while (sim != '(') {
                    res += sim;
                    res += " ";
                    sim = ops.Pop();
                }
            } else {
                while (!ops.IsEmpty() && getPr(inf[i]) <= getPr(ops.Get())) {
                    res += ops.Pop();
                    res += " ";
                }
                ops.Push(inf[i]);
            }
        }
    }
    if (num.length() > 0) {
        res += num;
        res += " ";
        num = "";
    }
    while (!ops.IsEmpty()) {
        res += ops.Pop();
        if(!ops.IsEmpty()) res += " ";
    }
    return res;
}

int eval(std::string pref) {
    int first = 0, second = 0;
    std::string num;
    TStack<int, 100> nums;
    for (int i = 0; i < pref.length(); i++) {
        if (isdigit(pref[i])) {
            num += pref[i];
        } else if (pref[i] == ' ') {
            if (num.length() > 0) {
                nums.Push(stoi(num));
                num = "";
            }
        } else {
            int semiRes = 0;
            second = nums.Pop();
            first = nums.Pop();
            switch (pref[i]) {
            case '+':
                semiRes = first + second;
                break;
            case '-':
                semiRes = first - second;
                break;
            case '*':
                semiRes = first * second;
                break;
            case '/':
                semiRes = first / second;
                break;
            }
            nums.Push(semiRes);
        }
    }
    return nums.Pop();
}
