#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int M,N;
string ans;
bool solve(int m, int n) {
	bool visited[M][N] = {false};
	stack<pair<int,int>> s;
	s.push({m,n});
	visited[m][n] = true;
	while(!s.empty()) {
		m = s.top().first;
		n = s.top().second;
		s.pop();
		for(int i=0;i<4;i++) {
			int dm = m+dX[i];
			int dn = n+dY[i];
			if(0 <= dm && dm < M && 0 <= dn && dn < N
			   && v[dm][dn] == '0' && !visited[dm][dn]) {
				visited[dm][dn] = true;
				s.push({dm,dn});
			}
		}
	}
	for(int j=0;j<N;j++) {
		if(visited[M-1][j]) {
			return true;	
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>M>>N;
	v.resize(M);
	for(int i=0;i<M;i++) {
		cin>>v[i];
	}
	ans = "NO";
	for(int j=0;j<N;j++) {
		if(v[0][j] == '0') {
			if(solve(0,j)) {
				ans = "YES";
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}