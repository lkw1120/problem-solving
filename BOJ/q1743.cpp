#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
bool visit[MAX][MAX] = {false};
int corridor[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,K,R,C,ans;
int bfs(int y, int x) {
	int cnt = 1;
	queue<pair<int,int>> q;
	visit[y][x] = true;
	q.push({y,x});
	int nX,nY;
	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			nY = dY[i]+y;
			nX = dX[i]+x;
			if(0 < nY && nY <= N && 0 < nX && nX <= M
			&& corridor[nY][nX] == 1 && !visit[nY][nX]) {
				visit[nY][nX] = true;
				cnt++;
				q.push({nY,nX});
			}	
		}
	}
	return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M>>K;
	for(int i=0;i<K;i++) {
		cin>>R>>C;
		corridor[R][C] = 1;
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(!visit[i][j] && corridor[i][j] != 0) {
				ans = max(ans,bfs(i,j));
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}