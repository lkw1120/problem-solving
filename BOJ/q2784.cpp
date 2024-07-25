#include<bits/stdc++.h>
using namespace std;
vector<string> v,vv;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    v.resize(6);
    for(int i=0;i<6;i++) {
        cin>>v[i];
    }
	do {
	    string str[3];
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				str[j] += v[i][j];
			}
		}
	    bool flag = true;
		for(int i=0;i<3;i++) {
			if(str[i] != v[i+3]) {
				flag = false;
			}
		}
        if(flag) {
            vv.push_back(str[0]+str[1]+str[2]);
		}
	} while(next_permutation(v.begin(),v.end()));
	if(vv.size()) {
	    sort(vv.begin(),vv.end());
	    cout<<vv[0].substr(0,3)<<"\n";
	    cout<<vv[0].substr(3,3)<<"\n";
	    cout<<vv[0].substr(6,3)<<"\n";
	}
	else {
	    cout<<"0"<<"\n";
	}
	return 0;
}