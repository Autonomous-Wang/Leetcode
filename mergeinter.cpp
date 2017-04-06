// Leetcode 56 Merge Intervals
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }
    
    vector<pair<int, int>> merge(vector<pair<int, int>> &intervals) 
    {
        int n = intervals.size();
        if (n <= 1)
            return intervals;
            
        sort(intervals.begin(), intervals.end(), comp);
        vector<pair<int, int>> res;
        
        int first = intervals[0].first;
        int second = intervals[0].second;
        pair<int, int> s(first, second);
        
        for (int i = 1; i < n; i++)
        {
            if (intervals[i].first <= s.second)
                s.second = max(intervals[i].second, second);
            
            else
            {
                res.push_back(s);
                s.first = intervals[i].first;
                s.second = intervals[i].second;
            }
            if (i == n - 1)
                    res.push_back(s);
        }
        return res;
    }

    vector<pair<int, int>> mergee(vector<pair<int, int>> &intervals) 
    {
    	int n = intervals.size();
    	if (n <= 1)
    		return intervals;
    	sort(intervals.begin(), intervals.end(), comp);
    	vector<pair<int, int>> res;
    	res.push_back(intervals[0]);

    	// first push back the first pair then, just need to compare the 
    	// last item with the new coming item.
    	for (int i = 1; i < n; i++)
    	{
    		if (intervals[i].first <= res[res.size() - 1].second)
    			res[res.size() - 1].second = max(res[res.size() - 1].second, intervals[i].second);
    		else
    			res.push_back(intervals[i]);
    	}
    	return res;
    }

    void printvec(vector<pair<int, int>> vec)
    {
        int n = vec.size();
        for (auto i : vec)
            cout << i.first << ' ' << i.second << endl;
    }
};

int main()
{
    vector<pair<int, int>> vec = {
        {1, 4}, {2, 5}
    };

    Solution s;
    vector<pair<int, int>> res = s.merge(vec);
    s.printvec(res);
}





