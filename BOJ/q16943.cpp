#include<bits/stdc++.h>
using namespace std;
string A,B,C;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	C = "-1";
	if(A.size() <= B.size()) {
		sort(A.begin(),A.end());
		do {
			if(stoi(A) >= stoi(B)) {
				break;
			}
			if(A[0] > '0') {
				C = A;
			}
		} while(next_permutation(A.begin(),A.end()));
	}
	cout<<C<<"\n";
	return 0;	
}