#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 4e6+1;
int dist[MAX] = {0};
int T,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		fill(dist,dist+MAX,INF);
		cin>>K;
		queue<pair<int,int>> q;
		q.push({1,0});
		dist[1] = 0;
		ans = -1;
		while(!q.empty()) {
			int k = q.front().first;
			int d = q.front().second;
			q.pop();
			if(k == K) {
				ans = d;
				break;
			}
			if(k*2 < MAX && d+1 < dist[k*2]) {
				dist[k*2] = d+1;
				q.push({k*2,d+1});
			}
			if(0 < K-1 && d+1 < dist[k-1]) {
				dist[k-1] = d+1;
				q.push({k-1,d+1});
			}
		}
		if(0 <= ans) {
			cout<<ans<<"\n";
		}
		else {
			cout<<"Wrong proof!"<<"\n";
		}
	}
	return 0;
}