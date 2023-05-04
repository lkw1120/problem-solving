#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {-1,-1,0,1,1,1,0,-1};
int arr[701][701] = {0};
bool visited[701][701] = {false};
int N,M,H,ans;
bool bfs(int x, int y, int h) {
	queue<pair<int, int>> q;
	q.push({x,y});
	visited[x][y] = true;
	bool flag = true;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M) {
				if(arr[dx][dy] > h) {
					flag = false;
				}
				else if(arr[dx][dy] == h && !visited[dx][dy]) {
					visited[dx][dy] = true;
					q.push({dx,dy});
				}
			}
		}
	}
	return flag;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	H = INT_MAX;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>arr[i][j];
			H = min(H,arr[i][j]);
		}
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(!visited[i][j]) {
				if(bfs(i,j,arr[i][j]) && arr[i][j] > H) {
					ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}