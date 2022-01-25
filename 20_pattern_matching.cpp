#include <bits/stdc++.h>
using namespace std;

bool ismatching(string s1, string s2)
{
    int i = 0, j = 0;
    bool cond = 0;

    while (i < s1.size())
    {
        int found = 0;
        while (j < s2.size())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
                found = 1;
                break;
            }
            else
            {
                j++;
            }
        }

        if (!found)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    int dp[m + 1][n - 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    cout << dp[m][n] << endl;
    cout << ismatching(a, b) << endl;
}