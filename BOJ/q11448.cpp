#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
char arr[101][101];
int T,N,ans;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= N && 0 < dy && dy <= N && arr[dx][dy] == '-') {
				arr[dx][dy] = '$';
				q.push({dx,dy});
			}
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;
		fill(&arr[0][0],&arr[100][101],'#');
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				cin>>arr[i][j];	
			}
		}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				if(arr[i][j] == 'w') {
					bfs(i,j);
				}
			}
		}
		ans = 0;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				if(arr[i][j] == '$') {
					ans++;	
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}