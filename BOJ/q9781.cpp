#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int arr[101][101] = {0};
int dX[8] = {-2,-2,2,2,-1,1,-1,1};
int dY[8] = {-1,1,-1,1,-2,-2,2,2};
int N,M,ans;
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(v[x][y] == 'X') {
			ans = arr[x][y];
			break;
		}
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M
			   && v[dx][dy] != '#' && !arr[dx][dy]) {
				arr[dx][dy] = arr[x][y]+1;
				q.push({dx,dy});
			}
		}
	}
	return ;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	ans = -1;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(v[i][j] == 'K') {
				bfs(i,j);	
			}
		}
	}
	cout<<ans<<"\n";
    return 0;
}