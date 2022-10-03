#include<bits/stdc++.h>
using namespace std;
string a_str,b_str;
int T;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>a_str>>b_str;
		int a,b,ans;
		if(a_str.size() != b_str.size()) {
			ans = -1;
		}
		else {
			a = b = 0;
			for(int i=0;i<a_str.size();i++) {
				a_str[i] == 'a'? a++:b++;
				b_str[i] == 'a'? a--:b--;
			}
			if(a != 0 || b != 0) {
				ans = -1;	
			}
			else {
				ans = 0;
				a = a_str.size()-1;
				b = b_str.size()-1;
				while(0 <= a && 0 <= b && a <= b) {
					if(a_str[a] == b_str[b]) {
						a--,b--;	
					}
					else {
						while(a_str[a] != b_str[b]) a--;
						for(;a<b;a++) {
							ans++;
							char tmp = a_str[a+1];
							a_str[a+1] = a_str[a];
							a_str[a] = tmp;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}