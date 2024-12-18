#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,ans;
ll find(ll n) {
	ll tmp,sum;
	tmp = 1;
	sum = 0;
	while(n) {
		if(n%2) {
		    sum+=((n/2)+1)*tmp;
		}
		else {
		    sum+=(n/2)*tmp;
		}
		n/=2;
		tmp*=2;
	}
	return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B;
    ans = find(B)-find(A-1);
    cout<<ans<<"\n";
    return 0;
}