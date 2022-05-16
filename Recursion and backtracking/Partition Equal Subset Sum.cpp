int solve(int target, int arr[], int N, int ind, vector<vector<int>> &dp)
{
    if (ind > N)
        return 0;
    if (ind == N)
    {
        if (target == 0)
        {
            return 1;
        }
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    if (arr[ind] <= target)
    {
        return dp[ind][target] = solve(target - arr[ind], arr, N, ind + 1, dp) || solve(target, arr, N, ind + 1, dp);
    }
    return dp[ind][target] = solve(target, arr, N, ind + 1, dp);

    // return 0;
}
int equalPartition(int N, int arr[])
{
    // code here

    int target = 0;
    for (int i = 0; i < N; i++)
    {
        target += arr[i];
    }
    if (target % 2 == 1)
        return 0;
    vector<vector<int>> dp(N + 1, vector<int>((target / 2) + 1, -1));
    return solve(target / 2, arr, N, 0, dp);
}