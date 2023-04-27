#include<bits/stdc++.h>
using namespace std;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {1,1,0,-1,-1,-1,0,1};
vector<string> v;
int N,M,ans;
void solve(int n, int m) {
	queue<pair<int,int>> q;
	q.push({n,m});
	v[n][m] = '*';
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<8;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 <= dx && dx < N && 0 <= dy && dy < M && v[dx][dy] == '@') {
				v[dx][dy] = '*';
				q.push({dx,dy});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		cin>>N>>M;
		if(!N && !M) break;
		v.resize(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];
		}
		ans = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(v[i][j] == '@') {
					ans++;
					solve(i,j);
				}
			}
		}
		v.clear();
		cout<<ans<<"\n";
	}
	return 0;
}