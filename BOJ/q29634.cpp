#include<bits/stdc++.h>
using namespace std;
char arr[31][31];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int find(int x, int y) {
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push({x,y});
	arr[x][y] = '*';
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= M && arr[dx][dy] == '.') {
				arr[dx][dy] = '*';
				q.push({dx,dy});
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = -1;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(arr[i][j] == '.') {
				ans = max(ans,find(i,j));	
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}