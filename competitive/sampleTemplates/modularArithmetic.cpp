#include "headers.h"

constexpr int M =
1e9+7;
// 998244353;
constexpr int MAX = 1<<21; // maximun memory assigned
constexpr int inf = 1e18+5;
bitset < MAX > prime;
int fact[MAX],ifact[MAX];

int mod(int x){
    if(x<M)
    return x;
return ((x%M + M)%M);
}
int madd(int a,int b){
return mod(mod(a)+mod(b));
}
int mmul(int a,int b){
return mod(mod(a)*mod(b));
}
int mpow(int a, int b){
	int res = 1;
	while(b){
		if(b&1) res *= a,res %= M;
		a *= a;
		a %= M;
		b >>= 1;
	}
	return res;
}
int mncr(int a,int b){
	int ans = (fact[a]*ifact[b])%M;
	ans *= ifact[a - b];
	ans %= M;
	return ans;
}


void presolve(){
    prime.set();
    for (int p1=2; p1*p1<=MAX; p1++){
        if (prime[p1] == 1){
            for (int i=p1*2; i<=MAX; i += p1)
            prime[i] = 0;
        }
    }
    fact[0]  = fact[1] = ifact[0]  = ifact[1] = 1;
	for(int i = 2;i < MAX;i++){
		fact[i] = (fact[i - 1]*i)%M;
		ifact[i] = mpow(fact[i],M - 2);
	}
    // w[1] = 0;
	// for (int i = 2; i <= N; i++)
	// {
	// 	for (int j = 1; j < i; j++)
	// 	{
	// 		int d = i - j;
	// 		int x = j / d;
	// 		if (!x) continue;
	// 		if (j / x != d) continue;
	// 		w[i] = min(w[i], w[j] + 1);
	// 	}
	// }
}
