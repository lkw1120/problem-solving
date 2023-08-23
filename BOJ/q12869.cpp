#include<bits/stdc++.h>
using namespace std;
int dp[61][61][61] = {0};
int arr[4] = {0};
int N,ans;
int bfs(int a,int b,int c) {
	queue<pair<tuple<int,int,int>,int>> q;
	q.push({{a,b,c},0});
	int res = 0;
	while(!q.empty()) {
		a = get<0>(q.front().first);
		b = get<1>(q.front().first);
		c = get<2>(q.front().first);
		int d = q.front().second;
		q.pop();
		if(a < 0) a = 0;
		if(b < 0) b = 0;
		if(c < 0) c = 0;
		if(dp[a][b][c] != -1) continue;
		dp[a][b][c] = d;
		if(a == 0 && b == 0 && c == 0) {
			res = d;
			break;
		}
		q.push({{a-9,b-3,c-1},d+1});
		q.push({{a-9,b-1,c-3},d+1});
		q.push({{a-3,b-9,c-1},d+1});
		q.push({{a-3,b-1,c-9},d+1});
		q.push({{a-1,b-9,c-3},d+1});
		q.push({{a-1,b-3,c-9},d+1});
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	fill(&dp[0][0][0],&dp[60][60][61],-1);
	ans = bfs(arr[1],arr[2],arr[3]);
	cout<<ans<<"\n";
	return 0;
}