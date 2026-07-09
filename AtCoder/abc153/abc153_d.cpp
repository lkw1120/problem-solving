#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll H,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>H;
	for(int i=0;i<64;i++) {
		if(H < pow(2,i)) {
			ans = pow(2,i)-1;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}