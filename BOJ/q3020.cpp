#include<bits/stdc++.h>
using namespace std;
vector<int> v,h;
int N,H,ans,cnt;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>H;
	v.resize(N);
	h.resize(H);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	for(int i=0;i<N;i++) {
		if(i%2) {
			h[H-v[i]]++;
			h[H]--;
		}
		else {
			h[0]++;
			h[v[i]]--;
		}
	}
	int now = 0;
	for(int i=0;i<H;i++) {
		now+=h[i];
		h[i] = now;
	}
	ans = *min_element(h.begin(),h.end());
	cnt = count(h.begin(),h.end(),ans);
	cout<<ans<<" "<<cnt<<"\n";
	return 0;
}