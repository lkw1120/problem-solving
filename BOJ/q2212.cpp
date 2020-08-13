#include<bits/stdc++.h>
using namespace std;
vector<int> v;
priority_queue<int> pq;
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	v = vector<int>(N);
	for(int i=0;i<N;i++) cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=1;i<N;i++) pq.push(v[i]-v[i-1]);
	if(K < pq.size()) {
		ans = v[N-1]-v[0];
		while(--K) {
			ans-=pq.top();
			pq.pop();
		}
	}
	cout<<ans<<"\n";
	return 0;
}