#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[1001];
int N,Q,A,B,L,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=0;i<N-1;i++) {
		cin>>A>>B>>L;
		v[A].push_back({B,L});
		v[B].push_back({A,L});
	}
	while(Q--) {
		cin>>A>>B;
		queue<pair<int,int>> q;
		q.push({A,0});
		vector<bool> visited(N+1);
		visited[A] = true;
		ans = 0;
		while(!q.empty()) {
			int now = q.front().first;
			int len = q.front().second;
			q.pop();
			if(now == B) {
				ans = len;
				break;	
			}
			for(auto next:v[now]) {
				if(visited[next.first]) continue;
				visited[next.first] = true;
				q.push({next.first,len+next.second});
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}