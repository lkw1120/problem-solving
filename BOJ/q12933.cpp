#include<bits/stdc++.h>
using namespace std;
vector<bool> check;
string str;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	N = str.size();
	check.resize(N);
	fill(check.begin(),check.end(),false);
	ans = 0;
	for(int i=0;i<N;i++) {
		if(!check[i] && str[i] == 'q') {
			bool flag = false;
			stack<int> st;
			for(int j=i;j<N;j++) {
				if(check[j]) continue ;
				if(st.empty() && str[j] == 'q') {
					st.push(j);
				}
				else if(st.size() == 1 && str[j] == 'u') {
					st.push(j);
				}
				else if(st.size() == 2 && str[j] == 'a') {
					st.push(j);
				}
				else if(st.size() == 3 && str[j] == 'c') {
					st.push(j);
				}
				else if(st.size() == 4 && str[j] == 'k') {
					check[j] = true;
					while(!st.empty()) {
						check[st.top()] = true;
						st.pop();
					}
					flag = true;
				}
			}
			if(flag) ans++;
		}
	}
	for(int i=0;i<N;i++) {
		if(!check[i]) ans = -1;
	}
	cout<<ans<<"\n";
	return 0;
}