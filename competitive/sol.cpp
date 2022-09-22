
#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>      //  created by
using namespace std;          //   ________             __ __         __
                              //   \______ \           /  |  | ___  _|  | __
#define int long long int     //    |    |  \         /   |  |_\  \/ /  |/ /
#define ll long long          //    |    `   \       /    ^   / \   /|    <
#define deb(...) 69           //   /_______  /  (_)  \____   |   \_/ |__|_ \ 
                              //           \/             |__|            \/
#else
#include "headers.h"
#endif

#define fix(x) cout << setprecision(x) << fixed;
#define testCase 678

void solve(int case_num){
    int n, quer;cin>> n;
    unordered_map<int , int > a, b;
    for(int i=0;i<n;i++) {int x; cin>> x ; a[x]++ ;}
    for(int i=0;i<n;i++) {int x; cin>> x ; b[x]++ ;}
    int ans =0;
    for(auto x:a){
        if(b.find(x.first) != b.end() and b[x.first] > 0) {
            b[x.first]--;
            continue;
        }
        int k = ceil(log10(x.first));
        a[x.first]--;
        a[k]++;
        ans++;
        if(b[k] > 0) b[k]--;
        
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
    if(testCase){
    cin>>t; while(t--) 
	solve(t+1);
    }
    else solve(0);
    return 0;
}

