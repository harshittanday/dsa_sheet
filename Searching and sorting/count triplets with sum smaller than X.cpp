long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        int target = sum - arr[i];
        int s = i + 1;
        int e = n - 1;
        while (s < e)
        {
            if (arr[s] + arr[e] < target)
            {
                count += e - s;
                s++;
            }
            else
            {
                e--;
            }
        }
    }
    return count;
}