class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    static bool compare(string a, string b)
    {
        return a + b > b + a;
    }
    string printLargest(vector<string> &arr)
    {
        // code here
        string res = "";
        sort(arr.begin(), arr.end(), compare);
        for (int i = 0; i < arr.size(); i++)
        {
            res += arr[i];
        }
        return res;
    }
};