#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> v;
vector<bool> visited;
int T,C,M,A,B,D,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		v.clear();
		visited.clear();
		cin>>C>>M;
		v.resize(C+1);
		visited.resize(C+1);
		for(int i=1;i<C;i++) {
			cin>>A>>B>>D;
			v[A].push_back({B,D});
		}
		queue<pair<int,int>> q;
		q.push({1,0});
		visited[1] = true;
		ans = -1;
		while(!q.empty()) {
			int now = q.front().first;
			int d = q.front().second;
			q.pop();
			if(M <= d) {
				ans = max(ans,d);
			}
			for(auto next: v[now]) {
				if(visited[next.first]) continue ;
				visited[next.first] = true;
				q.push({next.first,next.second+d});
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}