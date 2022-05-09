/*
Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)
*/

#include <bits/stdc++.h>

using namespace std;
void solve(vector<int> &nums, int tar, vector<vector<int>> &res, vector<int> &ans, int ind)
{
    // if(ind<)
    if (ind == nums.size())
    {
        if (tar == 0)
        {
            res.push_back(ans);
        }
        return;
    }
    if (nums[ind] <= tar)
    {
        ans.push_back(nums[ind]);
        solve(nums, tar - nums[ind], res, ans, ind);
        ans.pop_back();
    }

    solve(nums, tar, res, ans, ind + 1);
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    // Your code here
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vector<int>> res;
    vector<int> ans;
    solve(A, B, res, ans, 0);
    return res;
}

int main()
{
    int n = 11;
    int B = 6;
    vector<int> v = {6, 5, 7, 1, 8, 2, 9, 9, 7, 7, 9};
    vector<vector<int>> answer = combinationSum(v, B);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
