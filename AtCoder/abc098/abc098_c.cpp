#include<bits/stdc++.h>
using namespace std;
string input;
int N,E,W,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	cin>>input;
	E = W = 0;
	for(int i=0;i<N;i++) {
		if(input[i] == 'E') E++;
		else W++;
	}
	int e,w;
	e = w = 0;
	ans = INT_MAX;
	for(int i=0;i<N;i++) {
		if(input[i] == 'E') {
			ans = min(ans,w+(E-e-1));
			e++;
		}
		else {
			ans = min(ans,w+(E-e));
			w++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}