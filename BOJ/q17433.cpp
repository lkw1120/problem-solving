#include<bits/stdc++.h>
using namespace std;
const int MAX = 2001;
int arr[MAX];
vector<int> v;
int T,N,ans;
int gcd(int a, int b) {
    return b == 0? a:gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        fill(arr,arr+MAX,0);
        v.clear();
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        sort(arr+1,arr+N+1);
        for(int i=2;i<=N;i++) {
            v.push_back(arr[i]-arr[i-1]);
        }
        ans = v[0];
        int size = v.size();
        for(int i=1;i<size;i++) {
            ans = gcd(ans,v[i]);
        }
        if(ans) {
            cout<<ans<<"\n";
        }
        else {
            cout<<"INFINITY"<<"\n";
        }
    }
    return 0;
}