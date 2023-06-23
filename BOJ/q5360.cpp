#include<bits/stdc++.h>
using namespace std;
string input;
int T;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>input;
		if(next_permutation(input.begin(),input.end())) {
			cout<<input<<"\n";
		}
		else {
			cout<<"USELESS"<<"\n";	
		}
	}
	return 0;
}