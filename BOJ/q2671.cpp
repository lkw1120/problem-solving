#include<bits/stdc++.h>
using namespace std;
bool isSignal(string str) {
	for(int i=0;i<str.size();i++) {
		if(str[i] == '0') {
			if(str.size() < i+2) {
				return false;
			}
			if(str[i+1] == '0') {
				return false;
			}
			i++;
		}
		else {
			if(str.size() < i+4) return false;
			if(str[i+1] == '1' || str[i+2] == '1') {
				return false;
			}
			i++;
			while(i < str.size() && str[i] == '0') i++;
			if(i == str.size()) {
				return false;
			}
			i++;
			while(i < str.size() && str[i] == '1') {
				if(i+2 < str.size() && str[i+1] == '0' && str[i+2] == '0') {
					break;
				}
				i++;
			}
			i--;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin>>str;
	if(isSignal(str)) {
		cout<<"SUBMARINE"<<"\n";
	}
	else {
		cout<<"NOISE"<<"\n";
	}
	return 0;	
}