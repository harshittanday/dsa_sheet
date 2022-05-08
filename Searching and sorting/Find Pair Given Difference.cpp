bool findPair(int arr[], int size, int n)
{
    // code
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < size and j < size)
    {
        if (arr[j] - arr[i] == n and i != j)
        {
            return true;
        }
        else if (arr[j] - arr[i] < n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}