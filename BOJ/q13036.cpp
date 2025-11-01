#include<bits/stdc++.h>
using namespace std;
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        string str1,str2;
        cin>>str1>>str2;
        vector<int> v;
        for(int i=0;i<N;i++) {
            if((str1[i]^str2[i]) == 1) {
                v.push_back(i);
            }
        }
        int size = v.size();
        if(size%2 == 1) {
            ans = -1;
        }
        else {
            ans = 0;
            for(int i=0;i<size;i+=2) {
                ans+=(v[i+1]-v[i]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}