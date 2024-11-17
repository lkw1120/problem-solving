#include<bits/stdc++.h>
using namespace std;
int arr[30001];
bool check[30001];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ans = 0;
    for(int i=1;i<=N;i++) {
        if(!check[i]) {
            int n = i;
            while(!check[n]) {
                check[n] = true;
                n = arr[n];
            }
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}