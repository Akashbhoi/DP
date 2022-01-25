#include <bits/stdc++.h>
using namespace std;

int **dp;

int profit(int n, int W[], int V[], int cap)
{
    if (n == 0 || cap == 0)
    {
        return 0;
    }
    if (dp[n][cap] != -1)
        return dp[n][cap];
    if (W[n - 1] <= cap)
    {
        dp[n][cap] = max(V[n - 1] + profit(n - 1, W, V, cap - W[n - 1]), profit(n - 1, W, V, cap));
        return dp[n][cap];
    }
    else
    {
        dp[n][cap] = profit(n - 1, W, V, cap);
        return dp[n][cap];
    }
}
int main()
{
    int n;
    cin >> n;

    int W[n];
    int V[n];

    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
    }
    int cap;
    cin >> cap;
    // int dp[n + 1][cap + 1];
    dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((cap + 1) * sizeof(int));
        memset(dp[i], -1, (cap + 1) * sizeof(int));
    }

    cout << profit(n, W, V, cap) << endl;
}