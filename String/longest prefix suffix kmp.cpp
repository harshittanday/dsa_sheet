#include <bits/stdc++.h>
using namespace std;
int lps(string s)
{
    int n = s.size();
    vector<int> v(n, 0);
    int i = 0;
    int j = 1;
    while (j < n)
    {
        cout << s[j - 1] << " " << j << " " << i << " " << v[j - 1] << endl;
        if (s[j] == s[i])
        {
            i++;
            v[j] = i;
            j++;
        }
        else
        {
            if (i)
            {
                i = v[i - 1];
            }
            else
            {
                v[j] = 0;
                j++;
            }
        }
    }
    cout << s[j - 1] << " " << j << " " << i << " " << v[j - 1] << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return v.back();
}
int main()
{
    string s = "accbaaaaccbaac";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    int n = lps(s);
    cout << n;
    return 0;
}