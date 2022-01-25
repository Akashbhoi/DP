#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    // a-L + b -L

    // Think about edit distance(problem)

    int n = a.size(), m = b.size();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    // m + n -2*L

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << n + m - 2 * dp[n][m] << endl;
}