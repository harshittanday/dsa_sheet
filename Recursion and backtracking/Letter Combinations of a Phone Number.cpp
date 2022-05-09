#include <bits/stdc++.h>
using namespace std;

void solve(string digits, vector<string> &s, int ind, vector<string> &res, string ans)
{
    if (ind > digits.size())
    {
        return;
    }
    if (ind == digits.size())
    {
        res.push_back(ans);
        return;
    }
    for (char ch : s[digits[ind] - '0'])
    {
        solve(digits, s, ind + 1, res, ans + ch);
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
        return {};
    vector<string> s, res;
    s.push_back({});
    s.push_back({});
    s.push_back({"abc"});
    s.push_back({"def"});
    s.push_back({"ghi"});
    s.push_back({"jkl"});
    s.push_back({"mno"});
    s.push_back({"pqrs"});
    s.push_back({"tuv"});
    s.push_back({"wxyz"});
    solve(digits, s, 0, res, "");
    return res;
}
int main()
{
    // Write C++ code here
    string digits = "234";
    vector<string> answer = letterCombinations(digits);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "'" << answer[i] << "'"
             << " ";
    }
    return 0;
}