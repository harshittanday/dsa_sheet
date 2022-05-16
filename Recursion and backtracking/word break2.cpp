void solve(int ind, int c, int i, vector<string> &dict, string s, vector<string> &res, string &str)
{
    if (c > s.size())
    {
        return;
    }
    if (c == s.size())
    {
        res.push_back(str);
        return;
    }
    if (ind == dict[i].size())
    {
        str += dict[i];
        str += " ";
        return;
    }
    if (dict[i][ind] == s[c])
    {
        solve(ind + 1, c + 1, i, dict, s, res, str);
    }
    else
    {
        solve(ind, c, i + 1, dict, s, res, str);
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    // code here
    vector<string> res;
    for (int i = 0; i < dict.size(); i++)
    {
        int j = 0;
        int c = 0;
        bool ok = true;

        while (c < s.size() and j < dict[i].size())
        {
            if (s[c] == dict[i][j])
            {
                j++;
                c++;
            }
            else
            {
                ok = false;
            }
        }
        if (ok == true)
        {
            string str = "";
            str += dict[i];
            str += " ";
            solve(0, c, i, dict, s, res, str);
        }
    }
    return res;
}