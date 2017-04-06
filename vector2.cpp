#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec(10);
	int n = 100; // the size of vector to be test
	for (int i = 0; i < n; i++)
		vec.at(i) = i;

	//vec.assign(7, 1);

	// vec.clear();
	//vec.resize(12);
	for (int i = 0; i < n; i++)
		cout << vec[i] << ' ';
	cout << endl;

	cout << "For the iterator case" << endl;
	vector<int> :: iterator v = vec.begin();
	while (v != vec.end())
	{
		cout << *v << ' ';
		v++;
	}
	cout << endl;
	cout << vec.back() << endl;
	cout << *(vec.end()-1) << endl;
}