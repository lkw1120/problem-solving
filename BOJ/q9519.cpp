#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int X;
string input,ans;
void solve(string str) {
	if(find(v.begin(),v.end(),str) == v.end()) {
		v.push_back(str);
		string tmp = "";
		for(int i=0;i<str.size();i+=2) {
			tmp+=str[i];
		}
		if(str.size()%2) {
			for(int i=str.size()-2;i>0;i-=2) {
				tmp+=str[i];
			}
		}
		else {
			for(int i=str.size()-1;i>0;i-=2) {
				tmp+=str[i];	
			}
		}
		solve(tmp);
	}
	else {
		ans = v[X%v.size()];
		return ;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>X;
	cin>>input;
	solve(input);
	cout<<ans<<"\n";
	return 0;	
}