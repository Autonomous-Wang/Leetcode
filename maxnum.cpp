// Leetcode 321 Creat Maximum Number
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstring>
using namespace std;

class Solution 
{
public:

	#define MIN(a, b) (a < b ? a : b)
	#define MAX(a, b) (a > b ? a : b)
	// create max number of length of t from single non-empty vector
	// num is the original array, result[] is the final array
	// 
	void getMax(int *num, int &len, int *result, int &t, int &sortedLen)
	{
		int n, top = 0;
		result[0] = num[0];
		const int need2drop = len - t; // len is the length of the array

		for (int i = 1; i < len; i++)
		{
			n = num[i];

			while (top >= 0 && result[top] < n && (i - top) <= need2drop)
				top--;

			if (i - top > need2drop)
			{
				sortedLen = MAX(1, top);
				while (++top < t)
					result[top] = num[i++];
				return;
			}

			if (++top < t)
				result[top] = n;
			
			else
				top = t - 1;
		}
	}

	void dp(int *num, int len, int &sortedLen, int &minL, int &maxL, int *res, int &k)
	{
		int j, *head, *prevhead = res;
		const int soi = sizeof(int);
		getMax(num, len, res, maxL, sortedLen);
		for (int l = maxL; l > MAX(minL, 1); l--)
		{
			head = prevhead + k;
			memcpy(head, prevhead, l*soi);
			for (j = sortedLen; j < l; j++)
			{
				if (head[j] > head[j - 1])
				{
					sortedLen = MAX(1, j - 1);
					memcpy(head + j - 1, prevhead + j, soi*(l - j));
					break;
				}
			}
			if (j == l)
				sortedLen = l;
			prevhead = head;
		}
	}

	void merge(int *num1, int len1, int *num2, int len2, int *result, int &resSize)
	{
		int i = 0, j = 0, k = 0;
		while ( i < resSize)
		{
			if (j < len1 && k < len2)
			{
				if (num1[j] > num2[k])
					result[i++] = num1[j++];
				else if (num1[j] < num2[k])
					result[i++] = num2[k++];
				else
				{
					int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
					int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
					flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
    				int * num = flag > 0 ? num1 : num2;
    				int & cnt = flag > 0 ? j : k;
    				int len = flag > 0 ? len1 : len2;
    				while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
    			}
    		}
    		else if (j < len1) result[i++] = num1[j++];
    		else result[i++] = num2[k++];
    	}
    }
					

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
    	int soi = sizeof(int), len1 = nums1.size(), len2 = nums2.size(), step = k*soi;
    	int minL1 = MAX(0, k - len2), maxL1 = MIN(k, len1), minL2 = k - maxL1, maxL2 = k - minL1, range = maxL1 - minL1 + 1;
    	int * res = new int[range * k * 2 + 2 * k], *dp1 = res + k, *dp2 = res + range*k+k, *tmp=res+range*2*k+k;
    	memset(res, 0, step);
    	int sortedLen1 = 1, sortedLen2 = 1;
    	if (len1 == 0 && len2 > 0) getMax(&nums2[0], len2, res, k, sortedLen2);
    	else if (len1 > 0 && len2 == 0) getMax(&nums1[0], len1, res, k, sortedLen2);
    	else if (len1 > 0 && len2 > 0){
    		dp(&nums1[0], len1, sortedLen1, minL1, maxL1, dp1,k);
    		dp(&nums2[0], len2, sortedLen2, minL2, maxL2, dp2,k);
    		if (sortedLen1 + sortedLen2 > k){
    			merge(dp1 + k*(maxL1 - sortedLen1), sortedLen1, dp2 + k*(maxL2 - sortedLen2), sortedLen2, tmp, k);
    			vector<int> resv(tmp, tmp + k);
    			delete[] res;
    			return resv;
    		}
    		for (int i = minL1; i <= maxL1; ++i){
    			merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp,k);
    			if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
    		}
    	}
    	vector<int> resv(res, res + k);
    	delete[] res;
    	return resv;
    }

    void printvec(vector<int> a)
    {
    	int n = a.size();
    	for (int i = 0; i < n; i++)
    		cout << a[i] << ' ';
    	cout << endl;
    }
};

int main()
{
	Solution s;
	vector<int> a = {3, 4, 6, 5};
	vector<int> b = {9, 1, 2 ,5, 8, 3};
	int k = 5;
	s.printvec(s.maxNumber(a, b, k));
}



