#include<bits/stdc++.h>
using namespace std;
int arr[3001][3001] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<string> v;
int N,M,X,Y,ans;
void solve(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(v[x][y] == '3' || v[x][y] == '4' || v[x][y] == '5') {
			ans = arr[x][y];
			break;
		}
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && v[dx][dy] != '1' && v[dx][dy] != '2') {
				if(v[dx][dy] == '0') {
					v[dx][dy] = '2';
				}
				arr[dx][dy] = arr[x][y]+1;
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
		for(int j=0;j<M;j++) {
			if(v[i][j] == '2') {
				X = i,Y = j;
			}
		}
	}
	ans = 0;
	solve(X,Y);
	if(!ans) {
		cout<<"NIE"<<"\n";
	}
	else {
		cout<<"TAK"<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}