#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int arr[51][51] = {0};
int N,M,dist,ans;
void solve(int n, int m) {
	queue<pair<pair<int,int>,int>> q;
	bool visited[51][51] = {false};
	q.push({{n,m},0});
	visited[n][m] = true;
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(dist <= d) {
			if(dist == d) {
				ans = max(ans,arr[x][y]+arr[n][m]);
			}
			else {
				dist = d;
				ans = arr[x][y]+arr[n][m];
			}
		}
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M 
			   && arr[dx][dy] && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push({{dx,dy},d+1});
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
	dist = ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(arr[i][j]) {
				solve(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}