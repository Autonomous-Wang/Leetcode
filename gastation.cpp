// Leetcode 134 gas station
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
private:
    vector<int> gas = {1,1,6,3,7};
    vector<int> cost = {1,2,9,4,2};

public:
    // return the index of starting point of the path
    // if total is greater than 0, there must be a starting point
    // the method is to find the minimum sum of sequence i, and the
    // starting point is i + 1
    int ref()
    {
        int n = gas.size();
        int total = 0;
        int subsum = INT_MAX;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            if (total < subsum)
            {
                subsum = total;
                start = i + 1;
            }
        }
        return (total < 0) ? -1 : (start % n);
    }
};

int main()
{
    Solution s;
    cout << s.ref() << endl;
}
