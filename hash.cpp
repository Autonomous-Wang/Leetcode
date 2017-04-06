// hash table practice and string matching of karp rabin algorithm
// delete the first element and insert one element at end
// the complexity is O(n)
#include <iostream>
#include <cstring>
using namespace std;

#define d 256

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;
	int i, j;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// calculate the hash value for pattern and window of text
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// slide the window over text one by one
	// the number of all the steps are N - M + 1
	for (i = 0; i <= N - M; i++)
	{
		if (p == t)
		{
			// check each entry in the array
			for (j = 0; j < M; j++)
				if (txt[i + j] != pat[j])
					break; // skip one level of the loop
			
			// after the for loop, the i will become M, should be noted!
			if (j == M)
				cout << "Pattern found at index: " << i << endl;
		}

		// calculate hash value for next window of text: remove leading
		// digit and adding trailing digits 
		if (i < N - M)
		{
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;
			// in case the q is negative
			if (t < 0)
				t = t + q;
		}
	}
}

int main()
{
    char txt[] = "abaab";
    char pat[] = "ab";
    int q = 101; // A prime number
    search(pat, txt, q);
}














