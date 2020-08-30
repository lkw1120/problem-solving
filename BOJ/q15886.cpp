#include<bits/stdc++.h>
using namespace std;
string S;
int N,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N>>S;
    for(int i=0;i<N-1;i++) {
        if (S[i] == 'E' && S[i+1] == 'W') {
            ans++;
            i++;
        }
    }
    cout<<ans<<"\n";
	return 0;
}