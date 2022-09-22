
/*
    https://discuss.codechef.com/t/arrpart-editorial/98503
    PROBLEM:
    You are given an array A of N integers, and an integer X. 
    For each K in the range [1,N] determine the number of ways to partition the array 
    into exactly K non-empty subarrays such that the maxima of each of the subarrays are at least X.

    The number of ways can be large, so output it modulo 998244353.
*/
#include "headers.h"
const int N = 1e6 + 1;
const int proot = 3LL;
const int mod = 998244353;
int sum,fact[N], invfact[N];

int binpow(int b, int p){
    int r = 1;
    while (p)
    {
        if (p & 1)
            r = (r * b) % mod;
        b = (b * b) % mod;
        p /= 2;
    }
    return r;
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)fact[i] = (fact[i - 1] * i) % mod;
    for (int i = 0; i < N; i++)invfact[i] = binpow(fact[i], mod - 2);
}

int ncr(int n, int x)
{
    int r = fact[n];
    r = (r * invfact[x]) % mod;
    r = (r * invfact[n - x]) % mod;
    return r;
}

void fft(vector<int>&a, int n, bool invert, int m, int x){
    for (int i = 0; i < n; i++)
    {
        int y = 0;
        for (int j = 0; j < __builtin_ctzll(n); j++)
        {
            if ((1LL << j)&i)
                y |= (1LL << (__builtin_ctzll(n) - j - 1));
        }
        if (y > i)swap(a[y], a[i]);
    }
    if (invert)x = binpow(x, mod - 2);
    for (int s = 1; s < __builtin_ctzll(n) + 1; s++)
    {
        int y = binpow(x, n / (1LL << s));
        for (int j = 0; j < (n / (1LL << s)); j++)
        {
            int r = 1;
            for (int i = 0; i < (1LL << (s - 1)); i++)
            {
                int u = a[i + j * (1LL << s)];
                int v = (r * a[i + j * (1LL << s) + (1LL << (s - 1))]) % m;
                a[i + j * (1LL << s)] = u + v;
                if (a[i + j * (1LL << s)] > m)a[i + j * (1LL << s)] -= m;
                a[i + j * (1LL << s) + (1LL << (s - 1))] = u - v;
                if (a[i + j * (1LL << s) + (1LL << (s - 1))] < m)a[i + j * (1LL << s) + (1LL << (s - 1))] += m;
                r *= y;
                r %= m;
            }
        }
    }
    if (invert)
    {
        int invn = binpow(n, mod - 2);
        for (int i = 0; i < n; i++)a[i] = (a[i] * invn) % m;
    }
    return;
}

void PolyMult(vector<int>&a, vector<int>&b, vector<int>&v, int m, int x){
    int n = 1, sz = a.size() + b.size();
    while (n < sz)n <<= 1;
    vector<int>fa(a.begin(), a.end());
    fa.resize(n, 0LL);
    vector<int>fb(b.begin(), b.end());
    fb.resize(n, 0LL);
    int y = binpow(x, (m - 1) / n);
    fft(fa, n, false, m, y);
    fft(fb, n, false, m, y);
    v.resize(n, 0LL);
    for (int i = 0; i < n; i++)v[i] = (fa[i] * fb[i]) % m;
    fft(v, n, true, m, y);
    v.resize(sz - 1, 0LL);
    return;
}

vector<int> solve1(int n, int x, vector<int>a){
    vector<int>ans, arr;
    int f[n + 1], cc = 0;
    vector<vector<int>>vec;
    priority_queue<pair<int, int>>pq;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= x)a[i] = 1LL, cc++;
        else a[i] = 0LL;
    }
    if (!cc)
    {
        for (int i = 1; i <= n; i++)ans.push_back(0LL);
        return ans;
    }
    if (cc == 1)
    {
        ans.push_back(1LL);
        for (int i = 1; i <= n; i++)ans.push_back(0LL);
        return ans;
    }
    int prv = -1;
    for(int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            if (prv != -1)
                f[i - prv]++;
            prv = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!f[i])continue;
        vector<int>v;
        for (int j = 0; j <= f[i]; j++)
        {
            int z = (binpow(i, j) * ncr(f[i], j)) % mod;
            v.push_back(z);
        }
        arr = v;
        vec.push_back(v);
        pq.push({ -v.size(), vec.size() - 1});
    }
    while (pq.size() > 1)
    {
        int idx1 = pq.top().second;
        pq.pop();
        int idx2 = pq.top().second;
        pq.pop();
        if (idx1 > idx2)swap(idx1, idx2);
        vector<int>v1 = vec[idx1];
        vector<int>v2 = vec[idx2];
        PolyMult(v1, v2, arr, mod, proot);
        vec[idx1] = arr;
        pq.push({ -ans.size(), idx1});
    }
    int sz = arr.size();
    for (int i = 0; i < sz; i++){
        if (i + 1 <= n)
            ans.push_back(arr[i]);
    }
    for (int i = sz + 1; i <= n; i++)ans.push_back(0LL);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    precompute();
    int t;
    cin>>t;
    assert(t >= 1 && t <= 70000);
    while (t--)
    {
        int n, x;
        cin>>n>>x;
        assert(n >= 1 && n <= 1e6);
        assert(x >= 1 && x <= 1e9);
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
            assert(a[i] >= 1 && a[i] <= 1e9);
        }
        vector<int>ans1 = solve1(n, x, a);
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)cout<< ans1[i] << "\n";
            else cout << ans1[i] << " ";
        }
        sum += n;
        assert(sum >= 1 && sum <= 1e6);
    }
    return 0;
}