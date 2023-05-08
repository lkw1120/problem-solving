#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
bool check[100001] = {false};
int N,M,A,B,L,R,ans;
void solve() {
	queue<pair<int,int>> q;
	q.push({0,0});
	check[0] = true;
	while(!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(n == N) {
			ans = cnt;
			break;
		}
		if(n+A <= N	&& !check[n+A]) {
			bool flag = true;
			for(auto item: v) {
				if(item.first <= n+A && n+A <= item.second) {
					flag = false;
				}
			}
			if(flag) {
				check[n+A] = true;
				q.push({n+A,cnt+1});
			}
		}
		if(n+B <= N	&& !check[n+B]) {
			bool flag = true;
			for(auto item: v) {
				if(item.first <= n+B && n+B <= item.second) {
					flag = false;
				}
			}
			if(flag) {
				check[n+B] = true;
				q.push({n+B,cnt+1});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>A>>B;
	for(int i=0;i<M;i++) {
		cin>>L>>R;
		v.push_back({L,R});
	}
	ans = -1;
	solve();
	cout<<ans<<"\n";
	return 0;
}