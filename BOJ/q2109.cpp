#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
priority_queue<pair<int,int>> pq;
bool dp[MAX] = {false};
int N,p,d,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>p>>d;
		pq.push({p,d});
	}
	ans = 0;
	while(!pq.empty()) {
		p = pq.top().first;
		d = pq.top().second;
		for(int i=d;i>0;i--) {
			if(!dp[i]) {
				dp[i] = true;
				ans+=p;
				break;
			}
		}
		pq.pop();
	}
	cout<<ans<<"\n";
	return 0;
}