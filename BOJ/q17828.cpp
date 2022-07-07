#include<bits/stdc++.h>
using namespace std;
int N,X;
string ans;
void solve() {
	for(int i=0;i<N;i++) {
		ans+='A';
	}
	X-=N;
	for(int i=N-1;i>=0 && X>0;i--) {
		int temp = min(X, 25);
		ans[i] += temp;
		X -= temp;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>X;
	if(26*N < X || N > X) {
		ans = "!";
	}
	else {
		ans = "";
		solve();
	}
	cout<<ans<<"\n";
	return 0;	
}