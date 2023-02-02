#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<ll> res1,res2;
ll N,M,R,U,V,s,ans;
void dfs(int now, int t) {
	res1[now] = s++;
	res2[now] = t;
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
	res1.resize(N+1);
	res2.resize(N+1);
	for(int i=0;i<M;i++) {
		cin>>U>>V;
		v[U].push_back(V);
		v[V].push_back(U);
	}
	fill(res1.begin(),res1.end(),0);
	fill(res2.begin(),res2.end(),-1);
	for(int i=1;i<=N;i++) {
		sort(v[i].begin(),v[i].end());	
	}
	s = 1;
	dfs(R,0);
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans+=res1[i]*res2[i];
	}
	cout<<ans<<"\n";
	return 0;
}