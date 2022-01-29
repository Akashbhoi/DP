#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s, int i, int j)
{
    int pos1 = i, pos2 = j;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i <= n - L; i++)
        {
            int j = i + L - 1;
            if (ispalindrome(s, i, j))
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + 1 + dp[k + 1][j]);
                }
            }
        }
    }

    cout << dp[0][n - 1];
}