// Leetcode 47 Permutations
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void printvec(vector<vector<int>> s)
{
	int m = s.size();    // row index
	int n = s[0].size(); // col index
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << s[i][j] << ' ';
		cout << endl;
	}
}
void DFS(vector<vector<int>> &res, vector<int> &tmp, int layer, vector<int> &visited, vector<int> &nums);

vector<vector<int>> permutate(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	vector<int> tmp;
	vector<int> visited(nums.size(), 0);
	if (nums.empty())
		return res;
	DFS(res, tmp, 0, visited, nums);
	return res;
}

void DFS(vector<vector<int>> &res, vector<int> &tmp, int layer, vector<int> &visited, vector<int> &nums)
{
	if (layer == nums.size())
	{
		res.push_back(tmp);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (visited[i])
			continue;
		if (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 1)
			continue;
		visited[i] = 1;
		tmp.push_back(nums[i]);
		DFS(res, tmp, layer + 1, visited, nums);
		visited[i] = 0;
		tmp.pop_back();
	}
}

// a cleaner solution from Leetcode Solution
void recursion(vector<int> num, int i, int j, vector<vector<int>> &res)
{
	if (i == j - 1)
	{
		res.push_back(num);
		return;
	}
	for (int k = i; k < j; k++)
	{
		if (i != k && num[i] == num[k])
			continue;
		swap(num[i], num[k]);
		recursion(num, i + 1, j, res);
	}
	printvec(res);
}

vector<vector<int>> pemuteUnique(vector<int> &num)
{
	sort(num.begin(), num.end());
	vector<vector<int>> res;
	recursion(num, 0, num.size(), res);
	return res;
}

int main ()
{
	vector<int> nums = {1,2,3};
	vector<vector<int>> res = pemuteUnique(nums);
	//printvec(res);
}



