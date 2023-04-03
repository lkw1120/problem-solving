#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[10001];
bool visited[10001] = {false};
bool checked[10001] = {false};
int N,A,B,C,ans;
int dfs(int start, int now, int dist) {
	int res = now;
	ans = max(ans,dist);
	for(auto next: v[now]) {
		if(visited[next.first]) continue;
		visited[next.first] = true;
		res = dfs(start,next.first,dist+next.second);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	N = 0;
	while(!cin.eof()) {
		cin>>A>>B>>C;
		v[A].push_back({B,C});
		v[B].push_back({A,C});
		N++;
	}
	N++;
	ans = 0;
	for(int i=1;i<=N;i++) {
		if(checked[i]) continue;
		fill(visited,visited+10001,false);
		visited[i] = true;
		int j = dfs(i,i,0);
		checked[i] = checked[j] = true;
	}
	cout<<ans<<"\n";
	return 0;
}