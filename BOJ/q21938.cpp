#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,R,G,B,T,ans;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	arr[x][y] = 0;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && arr[dx][dy]) {
				arr[dx][dy] = 0;
				q.push({dx,dy});
			}
		}
	}
	ans++;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cin>>R>>G>>B;
			int avg = (R+G+B)/3;
			arr[i][j] = avg;
		}
	}
	cin>>T;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(arr[i][j] < T) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 255;	
			}
		}
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(arr[i][j]) {
				bfs(i,j);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}