#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<bool> visited;
vector<int> res;
int N,M,R,U,V;
int main() {
	ios_base::sync_with_stdio(0);
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
	queue<pair<int,int>> q;
	q.push({R,0});
	visited[R] = true;
	while(!q.empty()) {
		int now = q.front().first;
		int depth = q.front().second;
		res[now] = depth;
		q.pop();
		for(auto next: v[now]) {
			if(visited[next]) continue;
			visited[next] = true;
			q.push({next,depth+1});
		}
	}
	for(int i=1;i<=N;i++) {
		cout<<res[i]<<"\n";	
	}
	return 0;	
}