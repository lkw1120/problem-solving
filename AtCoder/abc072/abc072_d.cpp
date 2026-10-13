#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int arr[MAX];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];	
    }
    ans = 0;
    for(int i=N;i>1;i--) {
        if(arr[i] == i) {
            swap(arr[i],arr[i-1]);
            ans++;
        }
    }
    if(arr[1] == 1) ans++;
    cout<<ans<<"\n";
    return 0;
}