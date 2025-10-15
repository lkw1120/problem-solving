#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    v.resize(K);
    int sum = 0;
    for(int i=0;i<K;i++) {
        cin>>v[i];
        sum+=v[i];
    }
    int x = sum+1;
    bool flag = true;
    if((x & (x-1)) != 0) {
        flag = false;
    }
    for(int i=0;i<K && flag;i++) {
        for(int j=i+1;j<K;j++) {
            if((v[i] & v[j]) != 0) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        cout<<"Yes"<<"\n";
    }
    else {
        cout<<"No"<<"\n";
    }
    return 0;
}