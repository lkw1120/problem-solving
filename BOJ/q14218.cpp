#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
vector<int> v[MAX];
int N,M,Q,A,B,sum;
void solve() {
	bool visited[MAX] = {false};
	int dp[MAX] = {0};
	fill(dp,dp+MAX,-1);
	queue<pair<pair<int,int>,int>> q;
	dp[1] = 0;
	visited[1] = true;
	for(auto& node: v[1]) {
		q.push({{1,node},1});
		visited[node] = true;
	}
	while(!q.empty()) {
		int prev = q.front().first.first;
		int next = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		dp[next] = dp[next] < 0? cnt:min(dp[next],cnt);
		for(auto& node: v[next]) {
			if(!visited[node]) {
				visited[node] = true;
				q.push({{next,node},cnt+1});
			}
		}
	}
	for(int i=1;i<=N;i++) {
		cout<<dp[i]<<" ";	
	}
	cout<<"\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	cin>>Q;
	for(int i=0;i<Q;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
		solve();
	}
	return 0;	
}