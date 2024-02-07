#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1) {
		cin>>N;
		if(!N) break;
		vector<char> v(N);
		for(int i=0;i<N;i++) {
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		if(v[0] == '0') {
			int idx = 0;
			while(v[idx] == '0') idx++;
			swap(v[0],v[idx]);
			swap(v[1],v[idx+1]);
		}
		string str1,str2;
		str1 = "";
		str2 = "";
		for(int i=0;i<N;i++) {
			if(i%2) {
				str2+=v[i];
			}
			else {
				str1+=v[i];
			}
		}
		ans = stoi(str1)+stoi(str2);
		cout<<ans<<"\n";
	}
	return 0;
}