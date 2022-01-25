#include <bits/stdc++.h>
using namespace std;

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
}