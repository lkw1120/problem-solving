#include<bits/stdc++.h>
using namespace std;
const int MAX = 200007;
int arr[MAX];
int N,Q;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    while(Q--) {
        int l,r;
        cin>>l>>r;
        arr[l]^=1;
        arr[r+1]^=1;
    }
    int tmp = 0;
    for(int i=1;i<=N;i++) {
        tmp^=arr[i];
        ans+=('0'+tmp);
    }
    cout<<ans<<"\n";
    return 0;
}