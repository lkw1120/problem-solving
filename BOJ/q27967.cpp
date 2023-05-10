#include<bits/stdc++.h>
using namespace std;
string input,ans;
int N;
bool isValid(string str) {
	stack<char> stk;
	for(int i=0;i<N;i++) {
		if(stk.empty()) {
			stk.push(str[i]);
		}
		else {
			if(stk.top() == '(' && str[i] == ')') {
				stk.pop();
			}
			else {
				stk.push(str[i]);
			}
		}
	}
	return stk.empty();
}
void solve(string str, int n) {
	if(ans.size() == N) {
		return ;
	}
	if(n == N) {
		ans = isValid(str)? str: ans;
		return ;
	}
	if(input[n] == 'G') {
		solve(str+"(",n+1);
		solve(str+")",n+1);
	}
	else {
		solve(str+input[n],n+1);	
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>input;
	ans = "";
	solve("",0);
	cout<<ans<<"\n";
	return 0;
}