#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int T,N,M,X,Y;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<int> v[MAX];
		for(int i=0;i<M;i++) {
			cin>>X>>Y;
			v[X].push_back(Y);
			v[Y].push_back(X);
		}
		vector<int> painted(N+1);
		fill(painted.begin(),painted.end(),-1);
		ans = "possible";
		for(int i=1;i<=N;i++) {
			if(painted[i] != -1) continue;
			queue<pair<int,int>> q;
			q.push({i,0});
			painted[i] = 0;
			while(!q.empty()) {
				int node = q.front().first;
				int color = q.front().second;
				q.pop();
				for(auto next: v[node]) {
					if(painted[next] < 0) {
						painted[next] = color == 1? 0:1;
						q.push({next,painted[next]});
					}
					else {
						if(painted[next] == color) {
							ans = "impossible";	
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}