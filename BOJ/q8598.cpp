#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
char arr[MAX][MAX] = {0};
int dist[MAX][MAX] = {0};
int dX[8] = {1,1,-1,-1,2,2,-2,-2};
int dY[8] = {2,-2,2,-2,1,-1,1,-1};
int N,M,A,B,X,Y,ans;
int bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	dist[x][y] = 0;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(x == X && y == Y) break;
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= M && 
			   arr[dx][dy] != 'x' && dist[dx][dy] == INT_MAX) {
				dist[dx][dy] = dist[x][y]+1;
				q.push({dx,dy});
			}
		}
	}
	return dist[X][Y];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];
			if(arr[i][j] == 'z') {
				A=i,B=j;
			}
			if(arr[i][j] == 'n') {
				X=i,Y=j;
			}
		}
	}
	fill(&dist[0][0],&dist[MAX-1][MAX],INT_MAX);
	ans = bfs(A,B);
	if(ans == INT_MAX) {
		cout<<"NIE"<<"\n";	
	}
	else {
		cout<<ans<<"\n";
	}
	return 0;
}