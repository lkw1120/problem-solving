#include<bits/stdc++.h>
using namespace std;
int arr[501][501];
bool visited[501][501];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,K,ans;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	visited[x][y] = true;
	q.push({x,y});
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= M &&
			   abs(arr[dx][dy]-arr[x][y]) <= K && !visited[dx][dy]) {
				visited[dx][dy] = true;
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(!visited[i][j]) {
				bfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}