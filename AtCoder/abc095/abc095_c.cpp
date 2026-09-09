#include<bits/stdc++.h>
using namespace std;
int A,B,C,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>A>>B>>C>>X>>Y;
	if(2*C < A+B) {
		ans = 2*C*min(X,Y);
		if(X < Y) {
			ans+=B*abs(X-Y);
		}
		if(Y < X) {
			ans+=A*abs(X-Y);
		}
		ans = min(ans,2*C*max(X,Y));
	}
	else {
		ans = A*X+B*Y;
	}
	cout<<ans<<"\n";
	return 0;
}