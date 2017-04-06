// Leetcode 349 intersection fo two arrays
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public: 
    // the main idea is to use unordered map to mark the identical elements
    // between the two arrays. Noted that for the unique requirement, map--
    // should be implemented
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{
    	vector<int> re;
    	unordered_map<int, int> map;
    	
    	for (int i : nums1)
    		map[i] = 1;

    	for (int i : nums2)
    		if (map[i] == 1)
    		{	
    			map[i]--; // to cancel the repeated elements in the result
    			re.push_back(i);
    		}
    	return re;
    }

    void printvec(vector<int> a)
    {
    	for (int i : a)
    		cout << i << ' ';
    	cout << endl;
    }
};

int main()
{
	Solution s;
	vector<int> a = {1, 2, 3, 4, 4, 5, 5};
	vector<int> b = {2, 4, 5, 6, 1};
	s.printvec(s.intersection(b, a));
}








