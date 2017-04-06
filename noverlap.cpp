// Leetcode 435 Non-overlapping Intervals
// return the minimum number should be removed, in order for no overlay
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution
{
public:
	static bool comp(const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.second < b.second;
	}

	// noted when we sort the vector, the bool function should be in static form
	int Nonoverlapping(vector<pair<int, int>> &list)
	{
		int n = list.size();
		if (n <= 1)
			return 0;
		
		sort(list.begin(), list.end(), comp);

		// it is normal to introduce another variable for recursively compare
		int re = 0;
		int end = list[0].second;

		for (int i = 1; i < n; ++i)
		{
			if (list[i].first < end)
				re++;
			else
				end = list[i].second;
		}
		return re;
	}
};

int main()
{
	vector<pair<int, int>> s = {
		{1, 2}, {2, 4}, {4, 5}, {3, 8}
	};
	
	Solution a;
	cout << a.Nonoverlapping(s) << endl;
}











