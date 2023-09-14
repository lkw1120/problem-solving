#include<bits/stdc++.h>
using namespace std;
vector<int> v[101];
int N,A,B,ans;
bool bfs(int n) {
	queue<int> q;
	bool visited[101] = {0};
	q.push(n);
	visited[n] = true;
	while(!q.empty()) {
		int now = q.front();	
		q.pop();
		for(auto next: v[now]) {
			visited[next] = true;
			q.push(next);
		}
	}
	for(int i=1;i<=N;i++) {
		if(!visited[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>A>>B;
		v[B].push_back(A);
	}
	ans = -1;
	for(int i=1;i<=N;i++) {
		if(bfs(i)) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}