// Leetcode 300 Longest Increasing substring, don't need to be consecutive
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    // the idea is to calculate the length of increasing substring ended in 
    // each number
    int lengthOfLIS(vector<int>& nums) 
    {
        const int n = nums.size();
        vector<int> dp(n, 1);
        int res = 0;

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
                res = max(dp[i], res);
            }

        return res;
    }
};

int main()
{
	Solution s;
    int a[] = {1, 2, 6, 4, 5, 1};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    int re = s.lengthOfLIS(arr);
    cout << re << endl;
}





