#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int w[n];
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int c;
    cin >> c;

    int dp[n + 1][c + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][c];
}