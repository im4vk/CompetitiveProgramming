/*
    https://discuss.codechef.com/t/plyarsm-editorial/99180

*/

#include "headers.h"
using namespace std;
const int MOD = 998244353;
#define LL long long

const int MAX = (int)1e6 + 1;

int x[MAX + 1], y[MAX + 1], n;
LL ai[MAX + 1], bi[MAX + 1], ci[MAX + 1], A[MAX + 1], B[MAX + 1], C[MAX + 1], SA[MAX + 1], SB[MAX + 1], SC[MAX + 1];

// Find area of triangle v_a, v_b, v_c
LL area(int a, int b, int c) {
    assert(a >= 1 && a <= n); assert(b >= 1 && b <= n); assert(c >= 1 && c <= n);
    LL ret = x[a] * 1LL * (y[b] - y[c]) + x[b] * 1LL * (y[c] - y[a]) + x[c] * 1LL * (y[a] - y[b]);
    if (ret < 0) ret = -ret;
    return ret;
}
// sum of delta_ij over j = i to r
LL prefsumdelta_mod(int i, int r) {
    assert(r >= i);
    if (r < i + 2) return 0;
    LL ret = ((x[i] * 1LL * (SA[r-1] - SA[i]) + y[i] * 1LL * (SB[r-1] - SB[i]) + SC[r-1] - SC[i]) % MOD) - ((r - i - 1) * 1LL * ((x[i] * 1LL * A[i] + y[i] * 1LL * B[i] + C[i]) % MOD)) % MOD;
    ret %= MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

// O(n^3) solution
LL solve_ncube() {
    LL delta = 0, ans = 0;
    for (int i=1;i<n;++i) {
        delta += area(1, i, i+1);
    }
    for (int i=1;i<=n;++i) {
        for (int j=i+2;j<=n;++j) {
            LL now = 0;
            for (int k=i+1;k<j;++k) {
                now += area(i, k, k + 1);
            }
            ans += min(now, delta - now);
            ans %= MOD;
        }
    }
    return ans;
}

// O(n^2) solution
LL solve_nsquare() {
    LL delta = 0, ans = 0;
    for (int i=1;i<n;++i) delta += area(1, i, i+1);
    for (int i=1;i<=n;++i) {
        LL now = 0;
        for (int j=i+1;j<=n;++j) {
            now += area(i, j-1, j);
            ans += min(now, delta - now);
            ans %= MOD;
        }
    }
    return ans;
}

// read input for one testcase
void read() {
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> x[i] >> y[i];
    }
}

// O(n) solution
LL solve_linear() {
    LL ans = 0, delta = 0;
    A[0] = B[0] = C[0] = 0;
    SA[0] = SB[0] = SC[0] = 0;
    for (int i=1;i<=n;++i) {
        ai[i] = A[i] = SA[i] = 0;
        bi[i] = B[i] = SB[i] = 0;
        ci[i] = C[i] = SC[i] = 0;
    }
    for (int j=1;j<=n;++j) {
        int k = (j == n ? 1 : j + 1);
        LL a, b, c;
        a = y[j] - y[k]; b = x[k] - x[j]; c = x[j] * 1LL * y[k] - x[k] * 1LL * y[j];
        for (int p = 1; p <= 3; ++p) {
            if (a * 1LL * x[p] + b * 1LL * y[p] + c < 0) {
                a *= -1; b *= -1; c *= -1;
            }
        }
        for (int p = 1; p <= 3; ++p) {
            assert(a * 1LL * x[p] + b * 1LL * y[p] + c >= 0);
        }
        ai[j] = a; bi[j] = b; ci[j] = c;
        A[j] = A[j-1] + a; B[j] = B[j-1] + b; C[j] = C[j-1] + c;
        A[j] %= MOD; B[j] %= MOD; C[j] %= MOD;
        SA[j] = SA[j-1] + A[j]; SB[j] = SB[j-1] + B[j]; SC[j] = SC[j-1] + C[j];
        SA[j] %= MOD; SB[j] %= MOD; SC[j] %= MOD;
        if (j < n) delta += area(1, j, j + 1);
    }
    int k = 1;
    LL delta_ik = 0;
    for (int i=1;i<=n-2;++i) {
        while (k <= n && delta_ik * 2 < delta) {
            k++;
            if (k > n) break;
            delta_ik += area(i, k-1, k);
        }
        ans += ((n - k + 1) * 1LL * (delta % MOD) - prefsumdelta_mod(i, n) % MOD + 2LL * prefsumdelta_mod(i, k-1) % MOD) % MOD;
        if (ans >= MOD) ans -= MOD;
        if (ans < 0) ans += MOD;
        if (k <= n) delta_ik -= area(i, i+1, k);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        read();
        LL A = solve_linear();
        cout << A << '\n';
    } 
    return 0;
}