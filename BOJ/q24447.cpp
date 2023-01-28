#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<ll> res1,res2;
ll N,M,R,U,V,ans;
int main() {
	ios_base::sync_with_stdio(0);
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
	for(int i=1;i<=N;i++) {
		sort(v[i].begin(),v[i].end());	
	}
	fill(res1.begin(),res1.end(),0);
	fill(res2.begin(),res2.end(),-1);
	queue<pair<pair<int,int>,int>> q;
	int t = 1;
	q.push({{R,0},t});
	visited[R] = true;
	while(!q.empty()) {
		int now = q.front().first.first;
		int depth = q.front().first.second;
		res1[now] = q.front().second;
		res2[now] = depth;
		q.pop();
		for(auto next: v[now]) {
			if(visited[next]) continue;
			visited[next] = true;
			q.push({{next,depth+1},++t});
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans+=res1[i]*res2[i];
	}
	cout<<ans<<"\n";
	return 0;	
}