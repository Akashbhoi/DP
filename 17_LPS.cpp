#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s[n - j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";

    int i = n, j = n;

    while (i > 0 and j > 0)
    {
        if (s[i - 1] == s[n - j])
        {
            ans += s[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j]) // > and >= will show valid but different output
                j--;
            else
                i--;
        }
    }

    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}