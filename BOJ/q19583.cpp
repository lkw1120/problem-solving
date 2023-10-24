#include<bits/stdc++.h>
using namespace std;
map<string,string> mp1,mp2;
set<string> st;
string S,E,Q;
string str1,str2;
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>S>>E>>Q;
	while(true) {
		cin>>str1;
		if(cin.eof()) break;
		cin>>str2;
		st.insert(str2);
		if(str1 <= S) {
			mp1[str2] = str1;
		}
		if(E <= str1 && str1 <= Q) {
			mp2[str2] = str1;	
		}
	}
	ans = 0;
	for(auto item: st) {
		if(mp1.count(item) && mp2.count(item)) {
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}