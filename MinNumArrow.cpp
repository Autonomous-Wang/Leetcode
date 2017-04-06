// 452. Minimum Number of Arrows to Burst Balloons
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

bool mysort(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

// the main idea is to sort the vector based on the second element
// noted that in the mysort function should used const 
int findminArrow(vector<pair<int, int>> &points)
{
	int count = 1;
	sort(points.begin(), points.end(), mysort);

	// we initially locate the arrow at the second point of first pair 
	int arrow = points[0].second; 
	int n = points.size();
	for (int i = 1; i < n; i++)
    {
		if (points[i].first <= arrow)
			continue;

		// when the next start point is greater than the previous end point
		// we aim the arrow at the  
		arrow = points[i].second;
		count ++;
	}
	return count;
}

int main()
{
	vector<pair<int, int>> vec = { {6, 13}, {2, 5}, {3, 10} };
	cout << findminArrow(vec) << endl;
}




