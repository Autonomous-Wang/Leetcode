#include <iostream>
using namespace std;

int reverse(int x) 
{
	long res = 0;
    while(x) 
    {
    	res = res*10 + x%10;
    	printf("%ld %d\n", res, x);
        x /= 10;
    }
    return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}

int main()
{
	int a, b;
	a = -12345;
	b = reverse(a);
	cout << b << endl;
    cout << INT_MIN << endl;
}