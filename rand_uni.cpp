# include <iostream>
# include <random>
#include <algorithm> 
using namespace std;

vector<int> randn(int min, int max, int num)
{
	vector<int> vec;
	int i, l;
	for (i = min; i < max + 1; i++)
	{
		vec.push_back(i);
	}

	l = vec.size();
	cout << l << endl;
	random_shuffle(vec.begin(), vec.end());
	vec.resize(num);
	return vec;
}



int main()
{
	vector<int> vec = randn(0, 8, 7);
	for (int i = 0; i < 7; i++)
		cout << vec[i] << ' ';
}