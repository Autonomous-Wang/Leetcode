// Leetcode 406 Permutations
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<pair<int, int>> people;

public:
	Solution(): people {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}} {}

	void printvec(vector<pair<int, int>> people)
	{
		for (int i = 0; i < people.size(); i++)
			cout << people[i].first << ' ' << people[i].second << endl;
	}

	static bool comp(pair<int, int>& p1, pair<int, int>& p2)
    {
        return (p1.first == p2.first ? p1.second < p2.second:p1.first > p2.first);
    }

    vector<pair<int, int>> reconstructQueue() 
    {
    	sort(people.begin(), people.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){return (p1.first == p2.first ? p1.second < p2.second:p1.first > p2.first);});
    	vector<pair<int, int>> res;
    	for (auto& p : people) 
        	res.insert(res.begin() + p.second, p);
    	return res;
	}
};

int main()
{
	//vector<pair<int, int>> s = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
	Solution a;
	vector<pair<int, int>> output = a.reconstructQueue();
	a.printvec(output);
}


