#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<pair<ll,ll>> v[5001];
stack<pair<ll,ll>> s;
bool visited[5001] = {false};
ll N,A,B,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N-1;i++) {
		cin>>A>>B>>C;
		v[A].push_back({B,C});
		v[B].push_back({A,C});
	}
	ans = 0;
	s.push({1,0});
	visited[1] = true;
	while(!s.empty()) {
		ll now = s.top().first;
		ll dist = s.top().second;
		s.pop();
		ans = max(ans,dist);
		for(auto item: v[now]) {
			ll next = item.first;
			ll step = item.second;
			if(visited[next]) continue;
			visited[next] = true;
			s.push({next,dist+step});
		}
	}
	cout<<ans<<"\n";
	return 0;	
}