#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v;
	int a[] = {1,4,2,1,5,6,2,4,6,7,8,4,7};
	cout << "origianl vecetor" << endl;
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		v.push_back(a[i]);
		cout << v[i] << ' ';
	}
	
	cout << endl;
	cout << "sorted vecetor" << endl;
	sort(v.begin(), v.end());
	for (int j = 0; j < v.size(); j++)
		cout << v[j] << ' ';
	cout << endl;
	
	int l = v.size();
	vector<int> v1(l);
	copy (a, a + l, v1.begin() );
	sort(v1.begin(), v1.end());
	cout << "unique vecetor" << endl;
	unique(v1.begin(), v1.end());
	for (int j = 0; j < v1.size(); j++)
		cout << v1[j] << ' ';
	// erase the unique element
	cout << endl;
	
	cout << "unique vecetor without repeat" << endl;
	v.erase(unique(v.begin(), v.end()), v.end() );//

	vector<int> :: iterator it;
	it = unique(v.begin(), v.end());
	v.erase(it, v.end());
	for (int j = 0; j < v.size(); j++)
		cout << v[j] << ' ';
	cout << endl;
	
}