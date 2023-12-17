#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int T,N,M,L,X,Y,Z,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>M>>L;
		bool dominos[MAX] = {false};
		vector<int> v[MAX];
		queue<int> q;
		for(int i=1;i<=M;i++) {
			cin>>X>>Y;
			v[X].push_back(Y);
		}
		for(int i=1;i<=L;i++) {
			cin>>Z;
			q.push(Z);
		}
		ans = 0;
		while(!q.empty()) {
			int now = q.front();
			if(!dominos[now]) {
				dominos[now] = true;
				ans++;
			}
			q.pop();
			for(auto next: v[now]) {
				if(dominos[next]) continue ;
				q.push(next);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}