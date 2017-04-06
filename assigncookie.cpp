// the Leetcode in 455
// output the maximum children you can satisfy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
	vector<int> g;
	vector<int> s;

public:
	// g is the greedy factor of each child, s is the cookie you have
	Solution(): g {1,15,6,10,11}, s {1,12,7,13} {}

	Solution(vector<int> gg, vector<int> ss): g {gg}, s {ss} {}

	int findContentChildren()
	{
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int re = 0;
		int i = 0;
		int j = 0;
		int lg = g.size();
		int ls = s.size();

		while (i < ls && j < lg)
		{
			if (s[i] >= g[j])
			{
				i++;
				j++;
				re++;
			}
			else
				i++;
		}
		return re;
	}
};

int main()
{
	Solution s;
	cout << s.findContentChildren() << endl;
}








