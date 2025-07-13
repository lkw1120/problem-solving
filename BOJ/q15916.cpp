#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001];
ll N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    cin>>K;
    ll prev,cur;
    prev = cur = 0;
    bool flag = false;
    for(int i=1;i<=N;i++) {
        cur = arr[i]-K*i;
        if(cur == 0 || (prev < 0 && 0 < cur) || (cur < 0 && 0 < prev)) {
            flag = true;
            break;
        }
        prev = cur;
    }
    if(flag) {
        cout<<"T"<<"\n";
    }
    else {
        cout<<"F"<<"\n";
    }
    return 0;
}