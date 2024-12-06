#include<bits/stdc++.h>
using namespace std;
int arr[13];
int N,T;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    sort(arr+1,arr+N+1);
    cin>>T;
    ans = 0;
    for(int i=1;i<N;i++) {
        for(int j=i+1;j<=N;j++) {
            if(arr[j]-arr[i] <= 2*T) {
                ans+=0.25;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}