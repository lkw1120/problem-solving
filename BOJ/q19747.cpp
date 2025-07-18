#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 200001;
int arr[MAX_N];
bool check[MAX_N];
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    fill(check,check+MAX_N,false);
    for(int i=1;i<=N;i++) {
        int tmp = (i-arr[i])%N;
        if(tmp < 0) tmp+=N;
        check[tmp] = true;
    }
    ans = -1;
    for(int i=0;i<N;i++) {
        if(!check[i]) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}