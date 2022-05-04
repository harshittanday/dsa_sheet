/*
S = "timetopractice"
P = "toc"
Output:
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
*/
string smallestWindow(string s, string p)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < p.size(); i++)
    {
        mp[p[i]]++;
    }
    int i = 0;
    int j = 0;
    int res = INT_MAX;
    int start_index = 0;
    int size = mp.size();
    while (j < s.size())
    {
        if (mp.find(s[j]) != mp.end())
        {

            if (--mp[s[j]] == 0)
            {
                size--;
            }
            // cout<<"before del"<<" "<<s[j]<<" "<<mp[s[j]]<<endl;
        }
        while (size == 0)
        {
            if (res > j - i + 1)
            {
                res = j - i + 1;
                start_index = i;
            }
            if (size == 0)
            {
                if (mp.find(s[i]) != mp.end())
                {
                    if (++mp[s[i]] > 0)
                    {
                        // cout<<"after del"<<" "<<s[i]<<" "<<mp[s[i]]<<endl;
                        size++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    if (res != INT_MAX)
    {
        return s.substr(start_index, res);
    }
    return "-1";
}