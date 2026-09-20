#include<bits/stdc++.h>
using namespace std;
int W,H,X,Y,cnt;
double ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>W>>H>>X>>Y;
	ans = 1.0*W*H/2;
	cnt = 0;
	if(X*2 == W && Y*2 == H) cnt = 1;
	cout<<fixed;
	cout.precision(10);
	cout<<ans<<" "<<cnt<<"\n";
	return 0;
}