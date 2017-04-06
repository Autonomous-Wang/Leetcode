#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	vector<int> v2(2); 
    vector<vector<int> > vector(5,v2);
    cout << vector.size() << endl;

	return 0;
}