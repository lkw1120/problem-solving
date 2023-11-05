#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> top,bot,h;
ll N,A,B,Q,W,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>A;
		top.push_back(A);
	}
	for(int i=0;i<N;i++) {
		cin>>B;
		bot.push_back(B);
	}
	h.push_back(top[0]-bot[0]);
	for(int i=1;i<N;i++) {
		h.push_back(min(top[i]-bot[i],h[i-1]));	
	}
	reverse(h.begin(),h.end());
	cin>>Q;
	for(int i=0;i<Q;i++) {
		cin>>W;
		auto idx = lower_bound(h.begin(),h.end(),W)-h.begin();
		ans = N-idx;
		cout<<ans<<"\n";
	}
	return 0;
}