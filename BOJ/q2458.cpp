#include<bits/stdc++.h>
using namespace std;
const int MAX = 501;
int adj[MAX][MAX] = {0};
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	int a,b;
	for(int i=0;i<M;i++) {
		cin>>a>>b;
		adj[a][b] = 1;
	}
	for(int j=1;j<=N;j++) {
		for(int i=1;i<=N;i++) {
			if(j == i) continue;
			for(int k=1;k<=N;k++) {
				if(k == i || k == j) continue;
				if(adj[i][j]+adj[j][k] == 2) {
					adj[i][k] = 1;
				}
			}
		}
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		bool flag = true;
		for(int j=1;j<=N;j++) {
			if(i == j) continue;
			if(adj[i][j] + adj[j][i] == 0) {
				flag = false;
				break;
			}
		}
		if(flag) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}