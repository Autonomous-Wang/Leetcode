#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	srand(static_cast<unsigned int> (time(0)));
	//cout << getRandomNumber(1,10);

	for (int count = 0; count < 100; ++count)
	{
		cout << getRandomNumber(1,10) << '\t';
		if ((cout + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
}