#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int &e : v)
        cin >> e;

    int dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
}