// Leetcode 324 Wiggle sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void wigglesort(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> copy = nums;
		
		int n = nums.size();
		int i = 1;
		int k = 0;
		int j = n - 1;

		while (i < n)
		{
			nums[i] = copy[j];
			i += 2;
			j--;
		}

		while (j >= 0)
		{
			nums[k] = copy[j];
			k += 2;
			j--;
		}

		if (nums[n - 1] == nums[n - 2])
			swap(nums[n - 1], nums[0]);
	}

	void wiggleSort(vector<int> &nums)
	{
		int n = nums.size();

		// find a median
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());

		int mid = *midptr;

		#define A(i) nums[(1 + 2 * i) % (n | 1)]

		int i = 0, j = 0, k = n - 1;
		
		while (j <= k)
		{
			if (A(j) > mid)
				swap(A(i++), A(j++));
			
			else if (A(j) < mid)
            	swap(A(j), A(k--));
        	
        	else
            	j++;
        }
	}

	void printvec(vector<int> vec)
	{
		int n = vec.size();
		for (int i = 0; i < n; i++)
			cout << vec[i] << ' ';
		cout << endl;
	}
};

int main()
{
	Solution s;
	vector<int> vec = {1, 4, 2, 10, 5, 4};
	s.wigglesort(vec);
	s.printvec(vec);
}











