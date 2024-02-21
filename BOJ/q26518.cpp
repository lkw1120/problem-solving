#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A1,A2,B,C;
double ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>B>>C>>A1>>A2;
	ans = (B+sqrt(B*B+4*C))/2.0;
	cout<<fixed;
	cout.precision(10);
	cout<<ans<<"\n";
	return 0;
}