#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << "Vec[" << i << "] = " << vec[i] << endl;
	}
}

void iterprint(vector<int> vec)
{
	vector<int> :: iterator Iter;
	for (Iter = vec.begin(); Iter != vec.end(); Iter++)
	{
		cout << *Iter << ' ';
	}
	cout << endl;
}

vector<int> removeElement(vector<int>& nums, int val) 
{
	vector<int> num(0);
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			num.push_back(nums[i]);
		}
	}
    return num;
}

int main()
{
	const int size = 10;
	vector<int> vec(size);
	//cout << vec.size() << endl;
	vector<int> :: iterator Iter;
	Iter = vec.begin();
	for (int i = 0; i < size; i++)
	{
		*Iter = i;
		Iter++;
	}
	//iterprint(vec);
	//vec.pop_back();
	//vec.erase(vec.begin(), vec.begin() + 2);
	//iter(vec);
	vector<int> vecc;
	vecc.push_back(3);
	vecc.push_back(2);
	vecc.push_back(2);
	vecc.push_back(3);
	iterprint(vecc);
	vector<int> s;
	s = removeElement(vecc, 3);
	iterprint(s);
	cout << s.size() <<endl;









}