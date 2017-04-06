#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
            digits[i] = 0;
        else
        {
            digits[i]++;
            return digits;
        }
    }
    // when program reaches here, it means all the previous digits are 9
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}

// newton interpolation for the square root calculation
int sqrt(int x)
{
    double ans = x;
    double offset = 0.00001;
    while (fabs(ans * ans - x) > offset)
        ans = (ans + x/ans) / 2;
    return ans;
}

int searchInsert(vector<int>& nums, int target) 
{
    int l = nums.size();
    int po = 0;
    for (int i = 0; i < l; i++)
        if (nums[i] == target)
            return i;
    nums.push_back(target);
    for (int i = l; i >= 1; i--)
        if (nums[i - 1] > nums[i])
            {
                swap(nums[i - 1], nums[i]);
                po++;
            }
    return l - po;
}

void PrintVector(vector<int> arr)
{   
    int n = sizeof(arr)/sizeof(int);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    vector<int> a = {1,2,3,9};
    //vector<int> result = plusOne(a);
    int s = searchInsert(a, 60);
    //PrintVector(result);
    cout << s << endl;

}