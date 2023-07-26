#include<bits/stdc++.h>
using namespace std;
string input;
int ans;
bool check(string str) {
	int size = str.size();
	for(int i=0;i<size/2;i++) {
		if(str[i] != str[size-i-1]) {
			return false;	
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	ans = input.size();
	if(check(input)) {
		if(check(input.substr(1))) {
			ans = -1;	
		}
		else {
			ans--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}