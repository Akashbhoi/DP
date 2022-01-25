#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    int dp[sum + 1];
    for (int i = 0; i <= sum; i++)
        dp[i] = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        dp[0] = 0;
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[j] = max(dp[j], 1 + dp[j - arr[i - 1]]); // dp[j] is storing for i-1 iteration and dp[j-arr[i-1]] of this
        }
    }

    for (int i = 0; i <= sum; i++)
        cout << "sum = " << i << " " << dp[i] << endl;
}