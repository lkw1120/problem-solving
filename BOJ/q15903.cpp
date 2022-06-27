#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
priority_queue<ll,vector<ll>,greater<ll>> pq;
ll N,M,tmp,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>tmp;
		pq.push(tmp);
	}
	for(int i=0;i<M;i++) {
		tmp = pq.top();
		pq.pop();
		tmp+= pq.top();
		pq.pop();
		pq.push(tmp);
		pq.push(tmp);
	}
	ans = 0;
	while(!pq.empty()) {
		ans+=pq.top();
		pq.pop();
	}
	cout<<ans<<"\n";
	return 0;
}