#include<bits/stdc++.h>
using namespace std;
string input,ans;
bool solve(string str) {
	int len = str.size();
	if(len == 1) {
        return true;
    }
	string left, right;
	for(int i=0;i<len/2;i++) {
		left+=str[i];
	}
	for(int i=0;i<len/2;i++) {
		if(len%2 == 1) {
			right+=str[i+len/2+1];
		}
		else {
			right+=str[i+len/2];
		}
	}
	if(left != right) {
		return false;
	}
	if(solve(left) && solve(right)) {
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	if(solve(input)) {
		ans = "AKARAKA";
	}
	else {
		ans = "IPSELENTI";
	}
	cout<<ans<<"\n";
	return 0;
}