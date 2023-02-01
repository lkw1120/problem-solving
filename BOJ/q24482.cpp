#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<int> res;
int N,M,R,U,V;
void dfs(int now, int t) {
	res[now] = t;
	visited[now] = true;
	for(auto next: v[now]) {
		if(visited[next]) continue;
		dfs(next,t+1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>R;
	v.resize(N+1);
	visited.resize(N+1);
	res.resize(N+1);
	for(int i=0;i<M;i++) {
		cin>>U>>V;
		v[U].push_back(V);
		v[V].push_back(U);
	}
	fill(res.begin(),res.end(),-1);
	for(int i=1;i<=N;i++) {
		sort(v[i].begin(),v[i].end(),greater<>());	
	}
	dfs(R,0);
	for(int i=1;i<=N;i++) {
		cout<<res[i]<<"\n";	
	}
	return 0;
}