#include<bits/stdc++.h>
using namespace std;
string before,after;
int ans;
void solve(string str1, string str2) {
	if(str1.compare(str2) == 0) {
		ans = 1;
		return ;
	}
	else {
		if(str1.size() < str2.size()) {
			if(str2[str2.size()-1] == 'A') {
				string str = str2;
				str.erase(str.size()-1);
				solve(str1,str);
			}
			if(str2[0] == 'B') {
				string str= str2;
				reverse(str.begin(),str.end());
				str.erase(str.size()-1);
				solve(str1,str);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>before>>after;
	ans = 0;
	solve(before,after);
	cout<<ans<<"\n";
	return 0;	
}