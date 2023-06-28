#include<bits/stdc++.h>
using namespace std;
string arr[13] = {""};
string input;
int ans;
void preload() {
	string w,o,l,f;
	for(int i=1;i<=12;i++) {
		w+="w";
		o+="o";
		l+="l";
		f+="f";
		arr[i] = w+o+l+f;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>input;
	int size = input.size();
	ans = 1;
	for(int i=0;i<size;i++) {
		bool flag = true;
		for(int j=1;j<13;j++) {
			if(size < i+j*4) break;
			if(input.substr(i,j*4) == arr[j]) {
				i+=(j*4-1);
				flag = false;
				break;
			}
		}
		if(flag) {
			ans = 0;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}