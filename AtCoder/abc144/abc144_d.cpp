#include<bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535;
double A,B,X,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>A>>B>>X;
	if(A*A*B/2 < X) {
		ans = atan(2*(A*A*B-X)/(A*A*A));	
	}
	else {
		ans = atan((A*B*B)/(2*X));
	}
	ans = ans*180/PI;
	cout<<fixed<<setprecision(10)<<ans<<"\n";
	return 0;
}