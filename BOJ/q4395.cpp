#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,X,Y,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
    	cin>>X>>Y;
    	if(X == Y) {
    		ans = 0;
    	}
    	else {
    		N = sqrt(Y-X);
    		ans = 2*N-1;
    		if(0 < Y-X-N*N && Y-X-N*N <= N) {
    			ans++;
    		}
    		if(N < Y-X-N*N && Y-X-N*N <= 2*N) {
    			ans+=2;
    		}
    	}
    	cout<<ans<<"\n";
	}
	return 0;	
}