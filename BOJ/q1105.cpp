#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>str1>>str2;
	ans = 0;
	if(str1.size() == str2.size()) {
		for(int i=0;i<str1.size();i++) {
			if(str1[i] == str2[i] && str1[i] == '8') {
				ans++;	
			}
			else if(str1[i] != str2[i]) {
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}