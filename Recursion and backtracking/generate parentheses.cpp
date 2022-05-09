/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
there are two functions
solve1 and solve
solve is having high space and high time complexity
solve1 is optimal
*/
#include <bits/stdc++.h>
using namespace std;
bool isvalid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if (ch == ')' and top == '(')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
void solve(int n, vector<string> &res, int ind, string ans)
{
    if (ind > n * 2)
    {
        return;
    }
    if (ind == n * 2)
    {
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == '(')
                count1++;
            else
                count2++;
        }
        if (count1 != count2 and ans[0] == ')' or ans[ind - 1] != ')')
            return;
        else if (isvalid(ans))
        {
            res.push_back(ans);
        }
    }

    solve(n, res, ind + 1, ans + '(');
    solve(n, res, ind + 1, ans + ')');
}
void solve1(int n, vector<string> &res, int m, string ans)
{
    if (m == 0 and n == 0)
    {
        res.push_back(ans);
        return;
    }
    if (m > 0)
        solve1(n, res, m - 1, ans + ")");
    if (n > 0)
        solve1(n - 1, res, m + 1, ans + "(");
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    solve1(n, res, 0, "");
    return res;
}
int main()
{
    int n = 5;
    vector<string> answer = generateParenthesis(n);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "'" << answer[i] << "'"
             << " , ";
    }
    return 0;
}