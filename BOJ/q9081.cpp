#include<bits/stdc++.h>
using namespace std;
string input,str;
int T;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {
		cin>>input;
		str = input;
		next_permutation(str.begin(),str.end());
		if(input.compare(str) < 0) {
			cout<<str<<"\n";
		}
		else {
			cout<<input<<"\n";
		}
	}
	return 0;
}