#include <bits/stdc++.h>
using namespace std;
int N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M;
    while(M--) {
        cin>>N;
        vector<int> v(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        int a,b;
        a = b = -1;
        for(int i=0;i<N;i++) {
            if(v[i] != v[N-1]) { 
                a = N-i-1; 
                break;
            }
        }
        for(int j=N-1;j>=0;j--) {
            if(v[j] != v[0]) { 
                b = j; 
                break; 
            }
        }
        ans = max(a,b);
        if(ans < 0) {
            cout<<"BRAK"<<"\n";
        } 
        else {
            cout<<ans<<"\n";
        }
    }
    return 0;
}