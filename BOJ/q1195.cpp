#include<bits/stdc++.h>
using namespace std;
int arr[300][2];
string s1,s2;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2;
    int L1,L2;
    L1 = s1.size();
    L2 = s2.size();
    if(L1 < L2) {
        swap(s1,s2);
        swap(L1,L2);
    }
    for(int i=0;i<L1;i++) {
        arr[100+i][0] = s1[i]-'0';
    }
    for(int i=0;i<L2;i++) {
        arr[100+i][1] = s2[i]-'0';
    }
    ans = INT_MAX;
    for(int i=-L2;i<L1;i++) {
        bool flag = true;
        for(int j=0;j<L2;j++) {
            if(3 < arr[100+i+j][0]+arr[100+j][1]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(0 <= i) {
                ans = min(max(L1,i+L2),ans);
            }
            else {
                ans = min(abs(i)+L1,ans);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}