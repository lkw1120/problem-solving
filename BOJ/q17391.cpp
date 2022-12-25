#include<bits/stdc++.h>
#define MAX 300
using namespace std;
int arr[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};
int N,M,ans;
void solve() {
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},0});
	visited[0][0] = true;
	while(!q.empty()) {
		int n = q.front().first.first;
		int m = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(n+1 == N && m+1 == M) {
			ans = min(ans,d);
		}
		for(int i=1;i<=arr[n][m];i++) {
			if(n+i < N && !visited[n+i][m]) {
				visited[n+i][m] = true;
				q.push({{n+i,m},d+1});
			}
			if(m+i < M && !visited[n][m+i]) {
				visited[n][m+i] = true;
				q.push({{n,m+i},d+1});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>arr[i][j];
		}
	}
	ans = INT_MAX;
	solve();
	cout<<ans<<"\n";
	return 0;	
}