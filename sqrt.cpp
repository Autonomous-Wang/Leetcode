#include <iostream>
using namespace std;

int msqrt(int x) 
{
    if (x == 0)
        return x;
        
    // find the closest pair
    int i = 1;
    while (i <= INT_MAX / i)
    {
        i++;
        //cout << i - 1 << ' ';
    }
    return i - 1;        
}

int sqrt_ref(int x)
{
    if (x == 0)
        return 0;

    int left = 1, right = INT_MAX;
    
    while(true)
    {
        int mid = left + (right - left) / 2;
        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        cout << "mid: " << mid << endl;
        if (mid > x/mid)
            right = mid - 1;
        else 
        {
            if (mid + 1 > x/(mid + 1))
                return mid;
            left = mid + 1;
        }
        cout << "mid: " << mid << endl;
    }
}

int main()
{
    int x = 210;
    int b = sqrt_ref(x);
    cout << endl;
    cout << "The square root of X is: " << b << endl; 
    cout << b*b << ' ' << x << ' '<< (b+1) * (b+1) << endl;
}


















