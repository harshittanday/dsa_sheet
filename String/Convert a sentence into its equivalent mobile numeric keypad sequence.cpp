#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "HELLO WORLD";
    string res = "";
    string v[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444",
                  "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777",
                  "8", "88", "888", "9", "99", "999", "9999"};
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            res += "0";
        }
        else
        {
            int pos = s[i] - 'A';
            res += v[pos];
        }
    }
    cout << res;

    return 0;
}
