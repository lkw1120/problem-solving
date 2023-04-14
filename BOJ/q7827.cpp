#include<bits/stdc++.h>
using namespace std;
int T,N,M,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<int> v[2501];
		for(int i=0;i<M;i++) {
			cin>>A>>B;
			v[A].push_back(B);
		}
		ans = 0;
		for(int i=1;i<=N;i++) {
			vector<bool> checked(N+1);
			queue<int> q;
			q.push(i);
			checked[i] = true;
			while(!q.empty()) {
				int now = q.front();
				q.pop();
				for(auto next: v[now]) {
					if(checked[next]) continue;
					checked[next] = true;
					ans++;
					q.push(next);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}