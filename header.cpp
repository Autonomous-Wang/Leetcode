#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	vector<int> vec(a, a+sizeof(a)/sizeof(int));
	for (int i = 0; i < vec.size(); i++)
		vec[i] = a[i];
	int upper;
	upper =  *max_element(vec.begin(), vec.end());
	cout << upper << endl;
}