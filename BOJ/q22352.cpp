#include<bits/stdc++.h>
#define MAX 31
using namespace std;
int before[MAX][MAX] = {0};
int after[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,cnt;
void dfs(int x, int y, int n, int m) {
	visited[x][y] = true;
	before[x][y] = m;
	for(int i=0;i<4;i++) {
		if((0 < x+dX[i] && x+dX[i] <= N) &&
		   (0 < y+dY[i] && y+dY[i] <= M) &&
		   !visited[x+dX[i]][y+dY[i]] && before[x+dX[i]][y+dY[i]] == n) {
			dfs(x+dX[i],y+dY[i],n,m);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>before[i][j];	
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>after[i][j];	
		}
	}
	cnt = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(before[i][j] != after[i][j]) {
				cnt++;
				dfs(i,j,before[i][j],after[i][j]);
			}
		}
	}
	bool flag = true;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(before[i][j] != after[i][j]) {
				flag = false;	
			}
		}
	}
	if(cnt < 2 && flag) {
		cout<<"YES"<<"\n";	
	}
	else {
		cout<<"NO"<<"\n";
	}
	return 0;
}