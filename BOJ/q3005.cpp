#include<bits/stdc++.h>
using namespace std;
vector<string> v1,v2,v;
int R,C;
string ans;
vector<string> split(string str, char delimiter) {
    vector<string> res;
    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, delimiter)) {
        res.push_back(tmp);
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	v1.resize(R);
	for(int i=0;i<R;i++) {
		cin>>v1[i];
	}
	v2.resize(C);
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			v2[j]+=string(1,v1[i][j]);	
		}
	}
	for(int i=0;i<R;i++) {
		for(auto item: split(v1[i],'#')) {
			if(1 < item.size()) {
				v.push_back(item);	
			}
		}
	}
	for(int j=0;j<C;j++) {
		for(auto item: split(v2[j],'#')) {
			if(1 < item.size()) {
				v.push_back(item);	
			}
		}
	}
	sort(v.begin(),v.end());
	ans = v[0];
	cout<<ans<<"\n";
	return 0;
}