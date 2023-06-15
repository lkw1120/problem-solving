#include<bits/stdc++.h>
using namespace std;
vector<queue<string>> v;
queue<string> q;
string input, ans;
int N;
vector<string> split(string str, char dlim) {
    vector<string> res;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, dlim)) {
		res.push_back(buffer);
	}
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin.ignore();
	v.resize(N);
	for(int i=0;i<N;i++) {
		getline(cin,input);
		for(auto item: split(input,' ')) {
			v[i].push(item);	
		}
	}
	getline(cin,input);
	for(auto item: split(input,' ')) {
		q.push(item);
	}
	ans = "Possible";
	while(!q.empty()) {
		bool flag = false;
		for(int i=0;i<N;i++) {
			if(!v[i].empty() && v[i].front() == q.front()) {
				v[i].pop();
				q.pop();
				flag = true;
				break;
			}
		}
		if(!flag) {
			ans = "Impossible";
			break;
		}
	}
	for(auto item: v) {
		if(!item.empty()) {
			ans = "Impossible";
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}