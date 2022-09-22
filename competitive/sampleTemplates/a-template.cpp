#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <chrono>
#include <ratio>
#include <thread>
#include <ostream>
#include <cstdio>
#include <unordered_map>
#pragma GCC optimize ("-O3")

using namespace std;
#define debug(...) void(0)
#define int long long
#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define lop(i,n) for(int i=0;i<n;i++)
#define lop1(i,n) for(int i=1;i<=n;i++)
#define lopr(i,n) for(int i=n-1;i>=0;i--)
#define F first
#define S second
#define pb push_back
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)

const int M = 1e9+7, MAX = 1<<21;
const int inf = 1e18+5;
vector<int> prime(1e6+1,1);

// modular arithmetic


void init_code(){
	FIO; 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("deb.txt", "w", stderr);
	#endif 
    for (int p1=2; p1*p1<=1e6; p1++){
        if (prime[p1] == true){
            for (int i=p1*2; i<=1e6; i += p1)
            prime[i] = 0;
        }
    }
}

void solve(){
	
}
int main(){
	auto begin1 = chrono::system_clock::now();
	init_code();
    
	int t; cin>>t; while(t--) 
	solve();

	#ifndef ONLINE_JUDGE
    auto end1 = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(end1);
    cerr << "Executed at: " << ctime(&end_time) << endl;
    cerr << "Execution time: " << chrono::duration_cast<chrono::duration<double > >(end1 - begin1).count() << " seconds" << endl;
	#endif
}
//—————————————
