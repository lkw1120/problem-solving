#include<bits/stdc++.h>
using namespace std;
stack<char> s;
string input;
int len,cnt,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag = true;
	int t = 0;
	while(flag) {
		cin>>input;
		len = input.size();
		for(int i=0;i<len;i++) {
			if(input[i] == '-') flag = false;
		}
		if(flag) {
			s.push(input[0]);
			for(int i=1;i<len;i++) {
				if(!s.empty() && s.top() == '{' && input[i] == '}') {
					s.pop();
				}
				else {
					s.push(input[i]);	
				}
			}
			ans = 0;
			while(!s.empty()) {
				char ch = s.top();
				s.pop();
				if(ch == s.top()) ans++;
				else ans+=2;
				s.pop();
			}
			cout<<++t<<". "<<ans<<"\n";
		}
	}
	return 0;
}