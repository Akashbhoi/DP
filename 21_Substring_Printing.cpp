#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    int ans = 0;
    int pos1 = -1, pos2 = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    pos1 = i - 1;
                    pos2 = j - 1;
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << ans << endl;
    string str = "";
    for (int i = ans - 1; i >= 0; i--)
    {
        str += a[pos1 - i];
    }

    cout << str << endl;
}