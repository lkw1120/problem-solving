#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll W,H,F,C,X1,Y1,X2,Y2,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>W>>H>>F>>C>>X1>>Y1>>X2>>Y2;
	ll paint = 0;
	paint+=(X2-X1)*(Y2-Y1);
	if(F != 0) {
		paint+=max(0LL,(min(min(F,W-F),X2)-X1)*(Y2-Y1));
	}
	ans = W*H-paint*(C+1);
	cout<<ans<<"\n";
	return 0;
}