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
    for (int i : arr)
        sum += i;

    if (sum & 1)
    {
        cout << "False" << endl;
        return 0;
    }

    sum /= 2;

    int dp[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i] <= j)
                dp[i + 1][j] = dp[i][j] || dp[i][j - arr[i]];
            else
                dp[i + 1][j] = dp[i][j];
        }
    }

    cout << dp[n][sum];
}