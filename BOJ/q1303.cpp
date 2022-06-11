#include<bits/stdc++.h>
#define MAX 101
using namespace std;
char war[MAX][MAX] = {};
bool visited[MAX][MAX] = {false};
int dX[4] = {1,0,-1,0};
int dY[4] = {0,1,0,-1};
int N,M,W,B;
int bfs(char c, int x, int y) {
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(!visited[x][y]) {
			cnt++;
			visited[x][y] = true;
			int dx,dy;
			for(int i=0;i<4;i++) {
				dx = x+dX[i];
				dy = y+dY[i];
				if((dx > 0 && dx <= N) && (dy > 0 && dy <= M)
				   && !visited[dx][dy] && c == war[dx][dy]) {
					q.push({dx,dy});
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int j=1;j<=M;j++) {
		for(int i=1;i<=N;i++) {
			cin>>war[i][j];
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(!visited[i][j]) {
				if(war[i][j] == 'W') {
					W+=pow(bfs('W',i,j),2);
				}
				if(war[i][j] == 'B') {
					B+=pow(bfs('B',i,j),2);	
				}
			}
		}
	}
	cout<<W<<" "<<B<<"\n";
	return 0;	
}