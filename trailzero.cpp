#include <iostream>
using namespace std;

int trailingzeros(int n)
{
    int result = 0;
    while (n)
    {
        result += n / 5;
        n = n / 5;
    }
    return result;
}

int main()
{
    cout << trailingzeros(10) << endl;
}




