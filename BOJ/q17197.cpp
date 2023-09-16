#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<pair<int,int>> cow;
vector<int> v[MAX];
bool checked[MAX];
int N,M,X,Y,A,B,ans;
vector<int> bfs(int n) {
	vector<int> vv;
	queue<int> q;
	q.push(n);
	checked[n] = true;
	while(!q.empty()) { 
		int now = q.front();
		q.pop();
		vv.push_back(now);
		for(auto next: v[now]) {
			if(!checked[next]) {
				checked[next] = true;
				q.push(next);
			}
		}
	}
	return vv;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cow.resize(N+1);
	for(int i=1;i<=N;i++) {
		cin>>X>>Y;
		cow[i] = {X,Y};
	}
	for(int i=1;i<=M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	ans = INT_MAX;
	for(int i=1;i<=N;i++) {
		if(!checked[i]) {
			auto vv = bfs(i);
			int a,b,c,d;
			a = b = INT_MAX;
			c = d = INT_MIN;
			for(auto idx: vv) {
				a = min(a,cow[idx].first);
				b = min(b,cow[idx].second);
				c = max(c,cow[idx].first);
				d = max(d,cow[idx].second);
			}
			ans = min(ans,2*(c-a)+2*(d-b));
		}
	}
	cout<<ans<<"\n";
	return 0;
}