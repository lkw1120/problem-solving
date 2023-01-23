#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
queue<pair<int,int>> q;
vector<bool> visited;
int N,M,S,E,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N+1);
	visited.resize(N+1);
	cin>>S>>E;
	for(int i=0;i<M;i++) {
		cin>>X>>Y;
		v[X].push_back(Y);
		v[Y].push_back(X);
	}
	v[1].push_back(2);
	v[N].push_back(N-1);
	for(int i=2;i<N;i++) {
		v[i].push_back(i+1);
		v[i].push_back(i-1);
	}
	q.push({S,0});
	visited[S] = true;
	while(!q.empty()) {
		int now = q.front().first;
		int t = q.front().second;
		q.pop();
		if(now == E) {
			ans = t;
			break;
		}
		for(auto next: v[now]) {
			if(visited[next]) continue;
			visited[next] = true;
			q.push({next,t+1});
		}
	}
	cout<<ans<<"\n";
	return 0;	
}