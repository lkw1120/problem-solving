#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	int l,r;
	l = r = 0;
	int even,odd;
	even = odd = 0;
	if(v[r]%2) {
		odd++;
	}
	else {
		even++;	
	}
	ans = even;
	while(l <= r) {
		if(K < odd) {
			if(v[l]%2) {
				odd--;
			}
			else {
				even--;	
			}
			l++;
		}
		else {
			r++;
			if(N <= r) break;
			if(v[r]%2) {
				odd++;
			}
			else {
				even++;	
			}
			ans = max(ans,even);
		}
	}
	cout<<ans<<"\n";
	return 0;
}