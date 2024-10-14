#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,R,ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>N>>R;
	N-=R;
	for(ll i=1;i*i<=N;i++) {
		if(N%i == 0) {
    		if(R < i) ans+=i;
    		if(i*i != N && R < N/i) ans+=N/i;
		}
	}
    cout<<ans<<"\n";
    return 0;
}