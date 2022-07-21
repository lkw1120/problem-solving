#include<bits/stdc++.h>
using namespace std;
string input,ans;
void solve() {
	for(int i=1;i<input.size();i++) {
		if(input[i] > input[i-1]) {
			reverse(input.begin(),input.begin()+i);
			reverse(input.begin(),input.begin()+i+1);
		}
	}
	reverse(input.begin(),input.end());
	ans = input;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>input;
	solve();
	cout<<ans<<"\n";
	return 0;	
}