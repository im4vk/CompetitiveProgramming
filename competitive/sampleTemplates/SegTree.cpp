#include "headers.h"
#define pcnt(x) __builtin_popcountll(x)

constexpr int inf = 1e18+5;
int n, q, a[200005], zan[200005], fr[200005], cur[200005];
vector<int>pos[200005];
struct seg{
	#define szz (1<<18)
	int minfr[szz * 2];
	int mincur[szz * 2];
	int genlazy[szz * 2];
	bool alllazy[szz * 2];
	
	void init(){
		lop(i, szz * 2){
			minfr[i] = inf;
			mincur[i] = inf;
		}
	}
	void update0(int pos, int v){
		pos += szz - 1;
		mincur[pos] = v;
		minfr[pos] = (v == inf? v: 0);
	}
	void recalc(int k){
		mincur[k] = min(mincur[k*2+1], mincur[k*2+2]);
		minfr[k] = min(minfr[k*2+1], minfr[k*2+2]);
	}
	void make(){
		for(int i=szz-2;i>=0;i--) recalc(i);
	}
	void push(int k){
		for(int x=k*2+1;x<=k*2+2;x++){
			if(alllazy[k]){
				alllazy[x] = 1;
				genlazy[x] = genlazy[k];
				minfr[x] = mincur[x] - genlazy[k];
			}
			else{
				genlazy[x] += genlazy[k];
				minfr[x] -= genlazy[k];
			}
		}
		genlazy[k] = 0;
		alllazy[k] = 0;
	}
	void fill(int a, int b, int k, int l, int r){
		if(r < a or b < l or a > b) return;
		if(a <= l and r <= b){
			alllazy[k] = 1;
			genlazy[k] = 0;
			minfr[k] = mincur[k];
			return;
		}
		push(k);
		fill(a, b, k*2+1, l, (l+r)/2);
		fill(a, b, k*2+2, (l+r)/2+1, r);
		recalc(k);
	}
	void fill(int a, int b){
		fill(a, b, 0, 0, szz-1);
	}
	void minus(int a, int b, int k, int l, int r){
		if(r < a or b < l or a > b) return;
		if(a <= l and r <= b){
			if(minfr[k] > 0){
				minfr[k] --;
				genlazy[k] ++;
				return;
			}
		}
		if(l == r){
		    //cout<<l<<" d "<<r<<endl;
			//erase original bit
			pos[l].pop_back();
			if(pos[l].empty()){
				minfr[k] = inf;
				mincur[k] = inf;
			}
			else{
				minfr[k] = 0;
				mincur[k] = pos[l].back();
			}
			//cout<<minfr[k]<<" "<<mincur[k]<<endl;
			return;
		}
		push(k);
		minus(a, b, k*2+1, l, (l+r)/2);
		minus(a, b, k*2+2, (l+r)/2+1, r);
		recalc(k);
	}
	void minus(int a, int b){
		minus(a, b, 0, 0, szz-1);
	}
	
	void get(int a, int k=0,int l=0,int r=szz-1){
		if(l == r){
		    //cout<<l<<" "<<pos[l].size()<<" "<<minfr[k]<<endl;
			if(pos[l].empty()){
				cout << 0 << endl;
				return;
			}
			else{
				int ret = 0;
				for(auto x:pos[l]) ret += (1<<x);
				//o(pos[l]);
				//o(minfr[k]);
				int las = pos[l].back();
				lop1(i, minfr[k]){
					ret += (1<<(las-i));
				}
				cout<< ret << endl;
				return;
			}
		}
		//cout<<l<<" "<<r<<" "<<k<<" "<<alllazy[k]<<" "<<genlazy[k]<<endl;
		push(k);
		if(l <= a and a <= (l+r)/2) get(a, k*2+1, l, (l+r)/2);
		else get(a, k*2+2, (l+r)/2+1, r);
	}
}fuyuko;


void solve(int case_num){
	cin >> n >> q;
	fuyuko.init();
	lop(i, n){
		cin >> a[i];
		{
			zan[i] = pcnt(a[i]);
			fr[i] = 0;
			lop(ii, 30){
				if(((a[i]>>ii)&1)){
					pos[i].pb(ii);
				}
			}
			reverse(all(pos[i]));
			cur[i] = (pos[i].empty() ? inf :pos[i].back());
		}
		fuyuko.update0(i, cur[i]);
	}
	fuyuko.make();
	lop(di, q){
		int ty; cin >> ty;
		int le, ri;
		if(ty <= 2){
			cin>>le>>ri;
			le--; ri--;
		}
		if(ty == 3){
			int x; cin >> x; x--;
			fuyuko.get(x);
		}
		else if(ty == 1){
			fuyuko.fill(le, ri);
		}
		else{
			fuyuko.minus(le, ri);
		}
	}
}
