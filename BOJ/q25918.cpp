#include<bits/stdc++.h>
using namespace std;
string str;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>str;
	stack<char> s;
	ans = 0;
	for(int i=0;i<N;i++) {
		if(s.empty()) {
			s.push(str[i]);
		}
		else {
			if(s.top() != str[i]) {
			    int size = s.size();
				ans = max(ans,size);
				s.pop();
			}
			else {
				s.push(str[i]);
			}
		}
	}
	if(!s.empty()) {
		ans = -1;
	}
	cout<<ans<<"\n";
	return 0;
}