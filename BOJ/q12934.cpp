#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X,Y,sum,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>X>>Y;
	ll n = 0;
	sum = 0;
	while(sum < X+Y) {
        n++;
        sum+=n;
	}
	if(X+Y < sum) {
        ans = -1;
	}
	else {
	    ans = 0;
        while(0 < X) {
            X-=n;
            n--;
            ans++;
        }
	}
	cout<<ans<<"\n";
	return 0;
}