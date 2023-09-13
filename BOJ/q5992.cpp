#include<bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visited[1001];
queue<pair<int,int>> q;
int P,C,D1,D2,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>P;
	for(int i=1;i<P;i++) {
		cin>>C>>D1>>D2;
		v[C].push_back(D1);
		v[C].push_back(D2);
	}
	q.push({1,1});
	visited[0] = visited[1] = true;
	ans = 0;
	while(!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		ans = max(ans,dist);
		for(auto next: v[now]) {
			if(!visited[next]) {
				visited[next] = true;
				q.push({next,dist+1});
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}