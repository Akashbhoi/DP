#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    int sum = 0;
    for (int x : arr)
        sum += x;

    int s = (sum - target) / 2;
    if (2 * s + target != sum)
    {
        cout << -1 << endl;
        return 0;
    }
    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][s];
}