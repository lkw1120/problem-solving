#include<bits/stdc++.h>
using namespace std;
string str;
bool flag;
int num,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>str;
	for (int i=0;i<=str.size();i++) {
		if (str[i] == '+' || str[i] == '-' || i == str.size()) {
			if (!flag) {
				ans += num;
				num = 0;
			}
			else {
				ans -= num;
				num = 0;
			}
			if (str[i] == '-') {
				flag = true;
			}	
		}
		else {
			num *= 10;
			num += str[i] - '0';
		}
	}
	cout<<ans<<"\n";
}