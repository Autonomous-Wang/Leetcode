#include <iostream>
using namespace std;

// use the generic data type for multi-type data
template <class T>
class Bucky
{
	T first, second;
	public:
		Bucky(T a, T b)
		{
			first = a;
			second = b;
		}
		T bigger()
		{
			return (first > second ? first : second);
		}

};

int main()
{
	double x = 77;
	int y = 83;
	Bucky <int> b(x, y);
	cout << b.bigger() << endl;
}