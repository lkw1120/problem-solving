#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
vector<int> v;
vector<int>::iterator iter;
int N,A,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
    for(int i=0;i<N;i++) {
		cin>>A;
        if (i == 0) {
			v.push_back(A);
		}
        if (v.back() < A) {
			v.push_back(A);
		}
        else {
            iter = lower_bound(v.begin(), v.end(), A);
            *iter = A;
        }
    }
	ans = v.size();
	cout<<ans<<"\n";
	return 0;
}