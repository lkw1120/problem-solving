#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v1.resize(N);
	v2.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v1[i];
	}
	for(int i=0;i<N;i++) {
		cin>>v2[i];	
	}
	bool flag = true;
	if(3 < N) {
		int l = 0;
		while(v1[l] != v2[0]) l++;
		if(v1[(l+1)%N] != v2[1]) {
			reverse(v1.begin(),v1.end());
			l = N-(l+1);
		}
		for(int i=0;i<N;i++) {
			if(v1[(l+i)%N] != v2[i]) {
				flag = false;
				break;
			}
		}
	}
	if(flag) {
		cout<<"good puzzle"<<"\n";	
	}
	else {
		cout<<"bad puzzle"<<"\n";	
	}
	return 0;
}