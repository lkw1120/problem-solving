#include<bits/stdc++.h>
using namespace std;
int T,L,N,P,fast,late;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>T;
	while(T--) {
		cin>>L>>N;
        fast = late = 0;
        for(int i=0;i<N;i++) {
			cin>>P;
            int a = min(P, L-P);
            int b = max(P, L-P);
            fast = max(fast, a);
            late = max(late, b);
        }
        cout<<fast<<" "<<late<<"\n";
    }
    return 0;
}