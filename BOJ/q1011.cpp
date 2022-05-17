#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,x,y;
int n,m,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t > 0) {
		cin>>x>>y;
		n = y-x;
		m = (int)sqrt(n);
		if(n > m*m) {
			if(m*m+m < n) {
				ans = m*2+1;
			}
			else {
				ans = m*2;
			}
		}
		else {
			ans = m*2-1;
		}
		cout<<ans<<"\n";
		t--;
	}
	return 0;
}