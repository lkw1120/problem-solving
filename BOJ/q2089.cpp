#include<bits/stdc++.h>
using namespace std;
int N;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	if(N == 0) {
		ans = "0";
    }
	else {
		while(N) {
			if(N%(-2)) {
				ans+="1";
				N = (N-1)/(-2);
			}
			else {
				ans+="0";
				N/=(-2);
			}
		}
		reverse(ans.begin(),ans.end());
	}
	cout<<ans<<"\n";
	return 0;
}