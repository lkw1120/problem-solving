#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string input;
ll T,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>input;
		int size = input.size();
		bool flag = true;
		for(int i=1;i<size;i++) {
			if(input[i-1] > input[i]) {
				flag = false;
			}
		}
		if(!flag) {
			for(int i=size-1;i>0;i--) {
				if(input[i] < input[i-1]) {
					for(int j=i;j<size;j++) {
						input[j] = '9';	
					}
					input[i-1] = (input[i-1]-'0'-1)%10+'0';
				}
			}
		}
		ans = stoll(input);
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}