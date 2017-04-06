#include <iostream>
#include <random>
using namespace std;

int main()
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,6);
	int dice = bind(distribution, generator);
	int wisdom = dice()+dice()+dice();
	cout << wisdom << endl;
}

