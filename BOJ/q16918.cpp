#include<bits/stdc++.h>
using namespace std;
char arr[201][201] = {0};
int dp[201][201] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,N;
void bomb(int n) {
	if(n%2) {
		queue<pair<int,int>> q;
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				if(0 <= dp[i][j] && n-3 == dp[i][j]) {
					q.push({i,j});
				}
			}
		}
		while(!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			dp[x][y] = -1;
			q.pop();
			for(int i=0;i<4;i++) {
				int dx = x+dX[i];
				int dy = y+dY[i];
				if(0 < dx && dx <= R && 0 < dy && dy <= C) {
					dp[dx][dy] = -1;	
				}
			}
		}
	}
	else {
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				if(dp[i][j] == -1) {
					dp[i][j] = n;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>N;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			cin>>arr[i][j];
		}
	}
	if((N%4)%2) {
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				if(arr[i][j] == '.') {
					dp[i][j] = -1;	
				}
			}
		}
		if(1 < N) {
			for(int i=2;i<=N;i++) {
				bomb(i);
			}
		}
	}
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			if(dp[i][j] < 0) {
				cout<<'.';	
			}
			else {
				cout<<'O';
			}
		}
		cout<<"\n";
	}
	return 0;
}