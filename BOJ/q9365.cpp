#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int arr[11][11] = {0};
int T,R,C,A,B,ans;
void solve(int x, int y) {	
	bool visited[11][11] = {false};
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = true;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		int n = arr[x][y];
		if(x == 1 || x == R || y == 1 || y == C) {
			ans++;
		}
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= R && 0 < dy && dy <= C
			   && !visited[dx][dy] && n <= arr[dx][dy]) {
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
	cin>>T;
	for(int t=1;t<=T;t++) {
		fill(&arr[0][0],&arr[10][11],0);
		cin>>R>>C;
		cin>>A>>B;
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				cin>>arr[i][j];	
			}
		}
		ans = 0;
		solve(A,B);
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}