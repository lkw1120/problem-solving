#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
const int INF = 100000000;
int adj[MAX][MAX] = {0};
int score[MAX] = {0};
int N,a,b,cnt,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&adj[0][0],&adj[MAX-1][MAX],INF);
	cin>>N;
	while(true) {
		cin>>a>>b;
		if(a == -1 && b == -1) break;
		adj[a][b] = adj[b][a] = 1;
	}
	for(int j=1;j<=N;j++) {
		for(int i=1;i<=N;i++) {
			if(i == j) continue;
			for(int k=1;k<=N;k++) {
				if(i == k || j == k) continue;
				if(adj[i][k] > adj[i][j] + adj[j][k]) {
					adj[i][k] = adj[i][j] + adj[j][k];
				}
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			if(i == j) continue;
			score[i] = max(score[i],adj[i][j]);
		}
	}
	ans = *min_element(score+1,score+N+1);
	cnt = 0;
	for(int i=1;i<=N;i++) {
		if(score[i] == ans) cnt++;
	}
	cout<<ans<<" "<<cnt<<"\n";
	for(int i=1;i<=N;i++) {
		if(score[i] == ans) cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}