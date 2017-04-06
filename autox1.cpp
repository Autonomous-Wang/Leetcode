
#include <iostream>
using namespace std;

const char *test = "103*2+1+1*1*6";

char pick()
{
    return *test;
}

char Nget()
{
    return *test++;
}

// extact the number like 10, 103
int number()
{
    int result = Nget() - '0';
    while (pick() >= '0' && pick() <= '9')
    {
        result = 10 * result + Nget() - '0';
    }
    return result;
}

int term()
{
    int result = number();
    while (pick() == '*')
    {
        if (Nget() == '*')
            result *= number();
    }
    return result;
}

int expression()
{
    int result = term();
    while (pick() == '+')
    {   
        if (Nget() == '+')
            result += term();
    }
    return result;
}

int main()
{
    int result = expression();
    cout << "Output: "<< result << endl;
}








