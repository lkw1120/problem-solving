#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll M,ans;
ll find(ll mid) {
	ll cnt = 0;
    for(int i=5;i<=mid;i*=5){
        cnt+=mid/i;
    }
    return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>M;
	ll l,r;
	l = 0;
	r = M*5;
	bool flag = false;
	while(l <= r) {
		ll mid = (l+r)/2;
		ll cnt = find(mid);
		if(cnt < M) {
			l = mid+1;
		} 
		else if(M < cnt) {
			r = mid-1;
		}
		else {
			r = mid-1;
			flag = true;
		}
	}
	ans = -1;
	if(flag) {
		ans = l;
	}
	cout<<ans<<"\n";
	return 0;
}