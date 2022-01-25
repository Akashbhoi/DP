#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n, int W[], int V[], int cap)
{
    if (n == 0 || cap == 0)
        return 0;

    if (W[n - 1] <= cap)
        return max(V[n - 1] + maxProfit(n - 1, W, V, cap - W[n - 1]), maxProfit(n - 1, W, V, cap));
    else
        return maxProfit(n - 1, W, V, cap);
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

    cout << maxProfit(n, W, V, cap);
}