#include <iostream>
using namespace std;

// dynamic programming for sum made of 1, 3, 4. n stands for the number integers
int Dp(int n)
{
	int d[n + 1];
	d[0] = 1;
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;

	for(int i = 4; i <= n; i++)
		d[i] = d[i - 1] + d[i - 3] + d[i - 4];
	return d[n];
}

// find greatest common divisor, GCD(a, b) = GCD(r, a). at + r =  b
int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

// factorial, the classical dynamic programming
int factorial(int N)
{
	if (N == 1)
		return 1;
	else
		return N*factorial(N - 1);
}

// fibonaci not good example
int fibb(int a)
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	return fibb(a - 1) + fibb(a - 2);
}

int fib(int n)
{
	// we constrct an array to store the element
	if (n < 2) return n;
	int fib[n + 1];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	return fib[n];
}

int main()
{
	int a = 25;
	int b = 12;
	int c = max(a, b);
	int x[] = {1,2,3,4,5,6};
	//cout << c << endl;
	//cout << Dp(a) << endl;
	//cout << factorial(a) << endl;
	cout << fib(5) << endl;
}














