/*
    https://www.codechef.com/COOK138A/problems/SLING
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll INF = 1000000000000000;
struct segment_tree{
    int n; vector<ll> seg;
    segment_tree(){}
    segment_tree(int sz){n = sz; seg.resize(2*n);}
    segment_tree(vector<ll> v){
        n = v.size(); seg.resize(2*n);
        for(int i=0;i<n;i++) seg[i + n] = v[i];
        for(int i=n - 1;i>0;i--) seg[i] = max(seg[i<<1],seg[i<<1|1]);
    }
    void init(int sz){n = sz; seg.resize(2*n);}
    void update(int p,ll val){
        if(val<seg[p + n]) return;
        for(seg[p += n] = val;p>1;p>>=1) seg[p>>1] = max(seg[p],seg[p^1]);
    }
    ll query(int l,int r){
        ll res = -INF;
        for(l += n,r += n; l<r;l>>=1,r>>=1){
            if(l&1) res = max(res,seg[l++]);
            if(r&1) res = max(res,seg[--r]);
        }
        return res;
    }
    void clear(){for(int i=0;i<2*n;i++) seg[i] = 0;}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t){
        t--;
        int i,j,n,m,s; cin >> n >> m >> s;
        vector<pair<ll,pair<int,int>>> v;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ll x; cin >> x;
                v.push_back({x,{i + j,i - j + m}});
            }
        }
        segment_tree seg1(n + m),seg2(n + m);
        sort(v.begin(),v.end());
        for(auto p:v){
            ll val = p.first;
            int x = p.second.first,y = p.second.second;
            ll mx = 0;
            if(0<-s + x) mx = max(mx,seg1.query(0,-s + x));
            if(s + x + 1<n + m) mx = max(mx,seg1.query(s + x + 1,n + m));
            if(0<-s + y) mx = max(mx,seg2.query(0,-s + y));
            if(s + y + 1<n + m) mx = max(mx,seg2.query(s + y + 1,n + m));
            val += mx;
            seg1.update(x,val); seg2.update(y,val);
        }
        cout << seg1.query(0,n + m) << "\n";
    }
}