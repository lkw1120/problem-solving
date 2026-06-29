#include<bits/stdc++.h>
using namespace std;
vector<int> v[2001];
int N,M,A,B,ans;
int bfs(int p) {
	int cnt = 0;
	bool visited[2001] = {false};
	queue<int> q;
	q.push(p);
	visited[p] = true;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		cnt++;
		for(auto child: v[now]) {
			if(!visited[child]) {
				visited[child] = true;
				q.push(child);
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
	}
	for(int i=1;i<=N;i++) {
		ans+=bfs(i);
	}
	cout<<ans<<"\n";
	return 0;
}