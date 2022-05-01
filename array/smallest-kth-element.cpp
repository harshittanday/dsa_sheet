#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }
    while (k - 1)
    {
        pq.pop();
        k--;
    }
    cout << pq.top();
    return 0;
}