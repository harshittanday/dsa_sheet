int findMaxLen(string s)
{
    // code here
    int maxi = 0;
    int open = 0;
    int close = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            open++;
        }
        else
        {
            close++;
        }
        if (open == close)
        {
            int a = open + close;
            maxi = max(maxi, a);
        }
        if (open < close)
        {
            open = 0;
            close = 0;
        }
    }
    open = 0;
    close = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
        {
            open++;
        }
        else
        {
            close++;
        }
        if (open == close)
        {
            int a = open + close;
            maxi = max(maxi, a);
        }
        if (open > close)
        {
            open = 0;
            close = 0;
        }
    }
    return maxi;
}