#include<bits/stdc++.h>
using namespace std;
int A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	int left,right;
	left = right = 0;
	while(1 < A && 1 < B) {
		if(A > B) {
			A-=B;
			left++;
		}
		else {
			B-=A;
			right++;
		}
	}
	left+=A-1;
	right+=B-1;
	cout<<left<<" "<<right<<"\n";
	return 0;
}