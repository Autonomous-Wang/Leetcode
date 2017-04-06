// Leetcode 179 form the largest number from a vector
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:

	// the key point of this problem is to sort the vector
	// string, the sorting method is so briliant!
	static bool comp(const string &a, const string &b)
	{
		return (a + b) > (b + a);
	}

	string largestNumber(vector<int> &nums)
	{
		vector<string> res;
		string s;
		int n = nums.size();

		for (auto i:nums)  
			res.push_back(to_string(i));

		sort(res.begin(), res.end(), comp);

		for (auto i:res)
			s.append(i);

		if (s[0] == '0')
			return "0";
		return s;
	}
};

int main()
{
	vector<int> vec = {10, 50, 2, 9, 7};
	Solution s;
	cout << s.largestNumber(vec) << endl;
}