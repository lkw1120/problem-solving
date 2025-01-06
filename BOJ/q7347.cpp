#include<bits/stdc++.h>
using namespace std;
bool arr[31];
int T,N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=0;i<N;i++) {
            cin>>arr[i];
        }
        ans = "NO";
        if(N%2 == 1) {
           ans = "YES"; 
        }
        else {
            int a,b;
            a = b = 0;
            for(int i=0;i<N;i++) {
                if(arr[i] && i%2 == 1) a++;
                if(arr[i] && i%2 == 0) b++;
            }
            if(abs(a-b) <= 1) {
                ans = "YES";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}