#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) 
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        cout << dict[s[i]] << endl;
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

string convert(string s, int nRows) 
{
    int l = s.size();
    if (l <= 1) return s;
    int row = 0;
    int step = 1;
    string* str = new string[nRows];
    for (int i = 0; i < l; i++)
    {
        str[row].push_back(s[i]);
        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;
        row += step;
    }
    s.clear();
    for (int j = 0; j < nRows; j++)
        s.append(str[j]);
    delete[] str;
    return s;
}

int main()
{
	string s = "wangryan";
	vector<int> dict(256, -1);
	//int a = lengthOfLongestSubstring(s);
    string m = convert(s, 3);
	cout << m << endl;
}
