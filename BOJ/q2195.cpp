#include<bits/stdc++.h>
using namespace std;
string str1, str2;
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str1>>str2;
	ans = 0;
	for(int i=0;i<str2.size();i++) {
		for(int j=0;i+j<=str2.size();j++) {
			if(str1.find(str2.substr(i,j)) == string::npos) {
				ans++;
				i+=(j-2);
				break;
			}
		}
	}
	ans++;
	cout<<ans<<"\n";
	return 0;	
}