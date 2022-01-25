#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int dp[n + 1][1 + (sum / 2)];
    for (int i = 0; i < 1 + (sum / 2); i++)
        dp[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum / 2; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int s = 0;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            s = i;
            break;
        }
    }

    cout << sum - 2 * s << endl;
    return 0;
}