#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,M,A,B,ans;
bool solve(int idx) {
	vector<int> node[51];
	for(int i=0;i<M;i++) {
		if(i == idx) continue;
		A = v[i].first;
		B = v[i].second;
		node[A].push_back(B);
		node[B].push_back(A);
	}
	queue<int> q;
	bool visited[51] = {false};
	q.push(1);
	visited[1] = true;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(auto next: node[now]) {
			if(!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	for(int i=1;i<=N;i++) {
		if(!visited[i]) {
			return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	ans = 0;
	for(int i=0;i<M;i++) {
		if(solve(i)) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}