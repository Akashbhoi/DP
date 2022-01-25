#include <bits/stdc++.h>
using namespace std;

vector<int> getArray()
{
    string s;
    getline(cin, s);

    stringstream ss;
    ss << s;
    vector<int> ans;
    while (!ss.eof())
    {
        int x;
        string str;
        ss >> str;
        if (stringstream(str) >> x)
            ans.push_back(x);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &e : arr)
        cin >> e;

    vector<int> val(n);
    for (int &e : val)
        cin >> e;

    int L;
    cin >> L;
    int dp[L + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (arr[i - 1] <= j)
                dp[j] = max(dp[j], dp[j - arr[i - 1]] + val[i - 1]);
            //          (dp[j]--> previous(i-1), [j-arr[i-1]-->(this of current(i))])
        }
    }

    cout << dp[L] << endl;
    return 0;
}