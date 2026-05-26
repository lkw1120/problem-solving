#include<bits/stdc++.h>
using namespace std;
string N;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int sum = 0;
    int cnt[3] = {};
    for(char ch: N) {
        int n = ch-'0';
        sum+=n;
        cnt[n%3]++;
    }
    int size = N.size();
    int r = sum%3;
    if(r == 0) {
        ans = 0;
    }
    else if(r == 1) {
        if(cnt[1] >= 1 && size > 1) {
            ans = 1;
        }
        else if(cnt[2] >= 2 && size > 2) {
            ans = 2;
        }
        else {
            ans = -1;
        }
    }
    else {
        if(cnt[2] >= 1 && size > 1) {
            ans = 1;
        }
        else if(cnt[1] >= 2 && size > 2) {
            ans = 2;
        }
        else {
            ans = -1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}