#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> v;
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(int i=0;i<N;i++) {
		int l,r;
		l = 0;
		r = N-1;
		while(l < r) {
			if(v[l]+v[r] == v[i]) {
				if(l == i) {
					l++;
				}
				else if(r == i) {
					r--;
				}
				else {
					ans++;
					break;
				}
			}
			else {
				if(v[l]+v[r] < v[i]) {
					l++;	
				}
				else {
					r--;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}