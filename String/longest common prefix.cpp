class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = strs[0];
        string a = "";
        for (int i = 1; i < strs.size(); i++)
        {
            string n = strs[i];
            string m = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != n[i])
                    break;
                else
                    m += s[i];
            }
            s = m;
        }
        return s;
    }
};