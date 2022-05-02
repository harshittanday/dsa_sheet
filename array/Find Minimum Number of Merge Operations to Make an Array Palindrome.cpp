// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Write C++ code here
    vector<int> nums;
    nums = {11, 14, 15, 99};
    int start = 0;
    int end = nums.size() - 1;
    int ans = 0;
    while (start < end)
    {
        if (nums[start] == nums[end])
        {
            start++;
            end--;
        }
        else if (nums[start] < nums[end])
        {
            ans++;
            start++;
            nums[start] = nums[start] + nums[start - 1];
        }
        else
        {
            ans++;
            end--;
            nums[end] = nums[end] + nums[end + 1];
        }
    }
    cout << ans;

    return 0;
}