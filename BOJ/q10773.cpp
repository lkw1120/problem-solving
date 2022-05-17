#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
stack<ll> s;
ll t,n,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t > 0) {
		cin>>n;
		if(n != 0) {
			s.push(n);
		}
		else {
			s.pop();
		}
		t--;
	}
	ans = 0;
	while(!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout<<ans<<"\n";
	return 0;
}