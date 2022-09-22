// #include<bits/stdc++.h>
#include "./headers.h"
using namespace std;
using ll=long long;

struct edge{
	int to,cost,idx;
};

vector<int> dijkstra(int s,vector<vector<edge>>&G){
	vector<ll>dist(G.size(),1LL<<60);
	vector<int>idx(G.size());
	dist[s]=0;
	using P=pair<ll,int>;
	priority_queue<P,vector<P>,greater<P>> pq;
	pq.push({0,s});

	while(!pq.empty()){
		auto[d,v]=pq.top();
		pq.pop();
		if(dist[v]!=d)continue;
		for(auto[vv,c,i]:G[v]){
			if(dist[vv]>dist[v]+c){
				dist[vv]=dist[v]+c;
				pq.push({dist[vv],vv});
				idx[vv]=i;  //  <- index 
			}
		}
	}
	return idx;
}

int main(){
	int N,M;
	cin >> N >> M;
	vector<vector<edge>>G(N);
	for(int i=0;i<M;i++){
		int a,b,c;
		cin >> a >> b >> c;
		G[a-1].push_back({b-1,c,i});
		G[b-1].push_back({a-1,c,i});
	}
	vector<int> idx=dijkstra(0,G);
	for(int i=1;i<N;i++)cout << idx[i]+1 << ' ';
}