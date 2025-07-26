#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int M,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str1>>str2;
    M = str1.size();
    N = str2.size();
    bool flag = false;
    if((M%2) == (N%2)) {
        int p = 0;
        int need = 1;
        for(int i=1;i <= N && p < M;i++) {
            if(i%2 == need && str1[p] == str2[i-1]) {
                p++;
                need^=1;
            }
        }
        if(p == M) {
            flag = true;
        }
    }
    if(flag) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}