#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> numbers, int target)
{
	map<int, int> mapping;
	vector<int> result;

	for (int i = 0; i < numbers.size(); i++)
	{
		mapping[numbers[i]] = i;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		int searched = target - numbers[i];
		if (mapping.find(searched) != mapping.end() && mapping[searched] != i)
		{
			result.push_back(i);
			result.push_back(mapping[searched]);
			break;
		}
	}
	return result;
}

int main()
{
	int a = 8;
	int b = 10;
	int c = 8;
	int m = c % 10;
	int n = a /c;
	cout << n;

}