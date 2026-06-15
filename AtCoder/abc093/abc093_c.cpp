#include<bits/stdc++.h>
using namespace std;
vector<int> v(3);
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<3;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ans = 0;
	ans+=(v[2]-v[1]);
	v[0]+=(v[2]-v[1]);
	v[1] = v[2];
	if((v[2]-v[0])%2) {
		ans+=(v[2]-v[0]+1)/2;
		ans++;
	}
	else {
		ans+=(v[2]-v[0])/2;	
	}
	cout<<ans<<"\n";
	return 0;
}