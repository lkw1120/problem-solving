#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6+1;
int arr[51];
bool win[MAX_N];
int K,L,N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>K>>L;
    cin>>m;
    N = 0;
    for(int i=0;i<m;i++) {
        cin>>arr[i];
        N = max(N,arr[i]);
    }
    fill(win,win+MAX_N,false);
    for(int i=1;i<=N;i++) {
        if(0 <= i-1 && !win[i-1]) {
            win[i] = true;
        }
        if(0 <= i-K && !win[i-K]) {
            win[i] = true;
        }
        if(0 <= i-L && !win[i-L]) {
            win[i] = true;
        }
    }
    ans = "";
    for(int i=0;i<m;i++) {
        ans+=win[arr[i]]? "A": "B";
    }
    cout<<ans<<"\n";
    return 0;
}