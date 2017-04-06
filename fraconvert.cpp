#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) 
{
    string res = "";
    // in case of overflow
    long long num = numerator;
    long long den = denominator;

    if (num == 0 || den == 0)
        return "0";
    if (num * den < 0) 
        res += "-";

    num = abs(num);
    den = abs(den);
    res += to_string(num / den);
    int remainder = num % den;
    
    if (remainder == 0)
        return res;
    else
        res += ".";

    num = remainder;
    unordered_map<int, int> remainder_strlen;
    remainder_strlen[num] = (int)res.size();
        
    while(1)
    {
        num *= 10;
        res += to_string(num / den);
        num %= den;
        if (remainder_strlen.count(num) > 0)
        {
            res.insert(remainder_strlen[num], "(");
            res += ")";
            return res;
        }
        remainder_strlen[num] = (int)res.size();
        if (num == 0)
            return res;
    }
}

int main()
{
    int a = 11;
    int b = 7;
    cout << fractionToDecimal(a, b) << endl;
}




