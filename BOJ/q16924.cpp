#include<bits/stdc++.h>
using namespace std;
char arr[101][101];
int len[101][101];
bool visited[101][101];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
bool check(int x, int y, int k) {
	for(int i=0;i<4;i++) {
		int dx = x+dX[i]*k;
		int dy = y+dY[i]*k;
		if(!(0 < dx && dx <= N && 0 < dy && dy <= M)) {
			return false;
		}
		for(int j=1;j<=k;j++) {
			int dx = x+dX[i]*j;
			int dy = y+dY[i]*j;
			if(arr[dx][dy] != '*') {
				return false;
			}
		}
	}
	visited[x][y] = true;
	for(int i=0;i<4;i++) {
		for(int j=1;j<=k;j++) {
			int dx = x+dX[i]*j;
			int dy = y+dY[i]*j;
			visited[dx][dy] = true;
		}
	}
	return true;
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
	ans = 0;
	for(int k=min(N,M);k>0;k--) {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				if(arr[i][j] == '*') {
					if(!len[i][j] && check(i,j,k)) {
						len[i][j] = k;
						ans++;
					}
				}
			}
		}
	}
	if(ans == 0) {
		cout<<-1<<"\n";	
	}
	else {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				if(visited[i][j]) {
					arr[i][j] = '.';	
				}
			}
		}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				if(arr[i][j] == '*') {
					cout<<-1<<"\n";
					exit(0);
				}
			}
		}
		vector<pair<int,pair<int,int>>> res;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				if(len[i][j]) {
					res.push_back({len[i][j],{i,j}});
				}
			}
		}
		cout<<res.size()<<"\n";
		for(auto item: res) {
			cout<<item.second.first<<" "<<item.second.second<<" "<<item.first<<"\n";
		}
	}
	return 0;
}