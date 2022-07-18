#include<bits/stdc++.h>
using namespace std;
stack<char> s1,s2;
string input;
int X,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>X>>input;
	ans = 0;
	for(int i=0;i<input.size();i++) {
		if(input[i] == 'W') {
			s1.push(input[i]);
		}
		else {
			s2.push(input[i]);
		}
		if(X+1 == abs((int)s1.size()-(int)s2.size())) {
			if(i+1<input.size() && input[i] == input[i+1]) {
				if(input[i] == 'W') s1.pop();
				else s2.pop();
				break;
			}
		}
	}
	if(X < abs((int)s1.size()-(int)s2.size())) {
		if(s1.size() > s2.size()) s1.pop();	
		else s2.pop();
	}
	ans = s1.size()+s2.size();
	cout<<ans<<"\n";
	return 0;	
}