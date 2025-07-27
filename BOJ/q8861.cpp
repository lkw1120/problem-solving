#include <bits/stdc++.h>
using namespace std;
string str1,str2;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>str1>>str2;
    ans = 0;
    for(int i=0;i<N;i++) {
        if(str1[i] == str2[i]) continue;
        int l = i;
        while(i+1 < N && str1[i+1] != str2[i+1]) {
            i++;
        }
        int r = i;
        if(l == 0 || r == N-1) {
            ans+=1;
        }
        else {
            ans+=2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}