#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	arr[x][y] = 1;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = (x+dX[i])%N;
			int dy = (y+dY[i])%M;
			if(dx < 0) dx+=N;
			if(dy < 0) dy+=M;
			if(!arr[dx][dy]) {
				arr[dx][dy] = 1;
				q.push({dx,dy});
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
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(!arr[i][j]) {
	            ans++;
				bfs(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}