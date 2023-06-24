#include<bits/stdc++.h>
using namespace std;
stack<int> s;
string input;
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	int size = input.size();
	for(int i=0;i<size;i++) {
		if(input[i] != ')') {
			if('2' <= input[i] && input[i] <= '9') {
				int n = s.top();
				int m = input[i]-'0';
				s.pop();
				s.push(n*m);
			}
			else {
				if(input[i] == 'H') s.push(1);
				if(input[i] == 'C') s.push(12);
				if(input[i] == 'O') s.push(16);
				if(input[i] == '(') s.push(0);
			}
		}
		else {
			int sum = 0;
			while(s.top()) {
				sum+=s.top();
				s.pop();
			}
			s.pop();
			s.push(sum);
		}
	}
	ans = 0;
	while(!s.empty()) {
		ans+=s.top();
		s.pop();
	}
	cout<<ans<<"\n";
	return 0;
}