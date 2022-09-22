
/*
https://codeforces.com/contest/1637/problem/D
https://codeforces.com/blog/entry/99883
*/

#include "headers.h"
using namespace std;
 
constexpr int MAXSUM = 100 * 100 + 10;
 
int sqr(int x) {
    return x * x;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& u : a)
        cin >> u;
 
    for (auto& u : b)
        cin >> u;
 
    int sumMin = 0, sumMax = 0, sumSq = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            swap(a[i], b[i]);
 
        sumSq += sqr(a[i]) + sqr(b[i]);
        sumMin += a[i];
        sumMax += b[i];
    }
{ // same as knapsack problem application
    bitset<MAXSUM> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        dp |= dp << (b[i] - a[i]);
 
    int ans = sqr(sumMin) + sqr(sumMax);
    for (int i = 0; i <= sumMax - sumMin; i++)
        if (dp[i])
            ans = min(ans, sqr(sumMin + i) + sqr(sumMax - i));
 
    cout << sumSq * (n - 2) + ans << '\n';
}
}
 
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}