#include<bits/stdc++.h>
using namespace std;
stack<char> s;
string input;
int tmp,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>input;
	ans = 0;
	tmp = 1;
	for(int i=0;i<input.length();i++) {
		if(input[i] == '(') {
            tmp *= 2;
            s.push('(');
        }
        else if(input[i] == '[') {
            tmp *= 3;
            s.push('[');
        }
        else if(input[i] == ')') {
            if(s.empty() || s.top() != '(') {
                ans = 0;
                break;
            }
            if(input[i-1] == '(') {
                ans += tmp;
            }
			tmp /= 2;
			s.pop();
        }
        else if(input[i] == ']') {
            if(s.empty() || s.top() != '[') {
                ans = 0;
                break;
            }
            if(input[i-1] == '[') {
                ans += tmp;
            }
			tmp /= 3;
			s.pop();
        }
	}
	if(!s.empty()) ans = 0;
	cout<<ans<<"\n";
	return 0;
}