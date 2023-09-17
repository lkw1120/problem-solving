#include<bits/stdc++.h>
using namespace std;
bool arr[101][101] = {false};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,K,L,ans;
void dfs(int x, int y) {
	if(L == 0) {
		return ;
	}
	L--;
	arr[x][y] = true;
	for(int i=0;i<4;i++) {
		int dx = x+dX[i];
		int dy = y+dY[i];
		if(0 < dx && dx <= N && 0 < dy && dy <= N && !arr[dx][dy]) {
			dfs(dx,dy);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
		}
	}
	int cnt = M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(!arr[i][j]) {
				L = K;
				dfs(i,j);
				cnt--;
			}
		}
	}
	if(cnt < 0 || cnt == M) {
		cout<<"IMPOSSIBLE"<<"\n";	
	}
	else {
		cout<<"POSSIBLE"<<"\n";
		cout<<cnt<<"\n";
	}
	return 0;
}