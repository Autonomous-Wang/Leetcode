#include <iostream>
using namespace std;

double pow(double x, int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
	{
		if (n == INT_MIN)  // when n == INT_MIN, -n will be greater than INT_MAX
			return 1.0 / (pow(x, INT_MAX) * x);
		else 
			return 1.0 / pow(x, -n);
	}
	if (x == 0)
		return 0;
	return (n % 2 == 0) ? pow(x * x, n/2) : x * pow(x * x, n/2);
}

int main()
{
	double a = 123.42;
	int n = -5;
	double ans = pow(a, n);
	cout << ans << endl;
}