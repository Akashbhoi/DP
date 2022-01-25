#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
  //  cout << dp[n][m] << endl;
    string ans = "";

    int i = n, j = m;

    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }
    }
  //  cout << i << " " << j << endl;

    for (int k = j - 1; k >= 0; k--)
        ans += s2[k];
    for (int k = i - 1; k >= 0; k--)
        ans += s1[k];

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}