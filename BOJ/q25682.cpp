#include<bits/stdc++.h>
using namespace std;
int cache[2001][2001][2];
vector<string> v;
int N,M,K,ans;
void solve() {
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if((i+j)%2 == 0) {
				if(v[i][j] == 'B') {
					cache[i+1][j+1][0] = 1;
				}
				else {
					cache[i+1][j+1][1] = 1;	
				}
			}
			else {
				if(v[i][j] == 'W') {
					cache[i+1][j+1][0] = 1;
				}
				else {
					cache[i+1][j+1][1] = 1;	
				}
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cache[i][j][0]+=(cache[i-1][j][0]+cache[i][j-1][0]-cache[i-1][j-1][0]);
			cache[i][j][1]+=(cache[i-1][j][1]+cache[i][j-1][1]-cache[i-1][j-1][1]);
		}
	}
	int tmp = 0;
	for(int i=K;i<=N;i++) {
		for(int j=K;j<=M;j++) {
			tmp = cache[i][j][0]-cache[i-K][j][0]-cache[i][j-K][0]+cache[i-K][j-K][0];
			ans = min(ans,tmp);
			tmp = cache[i][j][1]-cache[i-K][j][1]-cache[i][j-K][1]+cache[i-K][j-K][1];
			ans = min(ans,tmp);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	ans = INT_MAX;
	solve();
	cout<<ans<<"\n";
	return 0;	
}