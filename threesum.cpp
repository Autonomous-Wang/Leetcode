#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > triples;
    sort(nums.begin(), nums.end());
    int i = 0, last = nums.size() - 1;
    while (i < last) {
        int a = nums[i], j = i + 1, k = last;
        while (j < k) {
            int b = nums[j], c = nums[k], sum = a+b+c;
            if (sum == 0) triples.push_back({a, b, c});
            if (sum <= 0) while (nums[j] == b && j < k) j++;
            if (sum >= 0) while (nums[k] == c && j < k) k--;
        }
        while (nums[i] == a && i < last) i++;
    }
    return triples;
}

int main()
{
    int a[] = {1,2,3, -4, -8, 7, 6};
    int size = sizeof(a)/sizeof(int);
    vector <int> vec(size);
    for (int i = 0; i < size; i++)
        vec[i] = a[i];
    threeSum(vec);

}