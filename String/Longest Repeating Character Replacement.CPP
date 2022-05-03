/*
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
s="ACBEFBCDAAFLKMKADAG"
K=3
OUTPUT=6
*/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> mp;
        int i = 0; // start
        int j = 0; // end
        int res = 0;
        int maxi = 0;
        while (j < s.size())
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if (j - i - maxi >= k) // sliding window
            {
                mp[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};