#include "headers.h"
// 		https://codeforces.com/contest/1594/problem/D
int n,m;
constexpr int MAX = 1<<21; // maximun memory assigned
int p[MAX],s[MAX];

int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
void merge(int a,int b){ // merged to b's parent
	int aa=find(a),bb=find(b);
	if(aa==bb)return;
	p[aa]=bb,s[bb]+=s[aa],s[aa]=0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i,s[i]=0;
	for(int i=n+1;i<=2*n;i++)p[i]=i,s[i]=1;
	while(m--){
		int a,b;
		string s;
		cin>>a>>b>>s;
		if(s=="crewmate"){
			merge(a,b);
			merge(a+n,b+n);
		}
		else{
			merge(a,b+n);
			merge(a+n,b);
		}	
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int a=find(i),b=find(i+n);
		if(a==b){
			cout<<-1<<endl;
			return;
		}
		if(a==i)res+=max(s[a],s[b]);
	}
	
	cout<<res<<endl;
}
 
int32_t main(){
	int T;
	cin>>T;
	while(T--)solve();	
}