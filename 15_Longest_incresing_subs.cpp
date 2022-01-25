#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &e : v)
        cin >> e;

    vector<int> v1(v.begin(), v.end());
    sort(v1.begin(), v1.end());

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v[i - 1] == v1[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> ans;
    int i = n, j = n;

    while (i > 0 and j > 0)
    {
        if (v[i - 1] == v1[j - 1])
        {
            ans.push_back(v[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int x : ans)
        cout << x << " ";
}