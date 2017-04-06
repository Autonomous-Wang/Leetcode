// 79 Leetcode word search
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
private:
	int m;
	int n;
	vector<vector<char> >board;

public:
	void printboard()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << board[i][j] << ' ';
			cout << endl;
		}
	}

	void setboard()
	{
		vector<vector<char> >b(m, vector<char>(n));
		board = b;
		char ref = 'a';
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board[i][j] = ref;
				ref += 1;
			}
		}
	}

	void set(int m_val, int n_val)
	{
		m = m_val;
		n = n_val;
	}

	bool exist(string word)
	{
		
		if (m == 0 || n == 0)
			return true;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (check(word, i, j))
					return true;
		return false;
	}

	bool check(string word, int i, int j)
	{	
		if (word.length() == 0)
			return true;
		if (i < 0 || i >= m || j < 0 || j >= n)
			return false;
		if (board[i][j] == word[0])
		{
			char c = board[i][j];
			board[i][j] = '\0';

			if (check(word.substr(1), i - 1, j) || check(word.substr(1), i + 1, j)
				|| check(word.substr(1), i, j + 1) || check(word.substr(1), i, j - 1))
				return true;
			board[i][j] = c;
		}
		return false;
	}
};

int main()
{
	Solution a;
	string word = "ababa";
	a.set(3, 4);
	a.setboard();
	a.printboard();
	if (a.exist(word))
		cout << "The word exists" << endl;
	else
		cout << "The word does not exists" << endl;
	a.printboard();
}




