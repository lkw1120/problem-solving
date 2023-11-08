#include<bits/stdc++.h>
using namespace std;
char arr[1010][1010];
bool visited[1010][1010];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int N,M,ans;
int solve() {
	queue<pair<int,int>> q;
	q.push({0,0});
	visited[0][0] = true;
	int cnt = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx <= N+1 && 0 <= dy && dy <= M+1) {
				if(visited[dx][dy]) continue ;
				if(arr[dx][dy] == '1') {
					cnt++;	
				}
				else {
					visited[dx][dy] = true;
					q.push({dx,dy});
				}
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&arr[0][0],&arr[1009][1010],'0');
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = solve();
	cout<<ans<<"\n";
	return 0;
}