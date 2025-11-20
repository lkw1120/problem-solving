#include<bits/stdc++.h>
using namespace std;
bool reachable[26][26];
int M,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<26;i++) {
        reachable[i][i] = true;
    }
    cin>>M>>N;
    for(int i=0;i<M;i++) {
        char c1,c2;
        cin>>c1>>c2;
        reachable[c1-'a'][c2-'a'] = true;
    }
    for(int j=0;j<26;j++) {
        for(int i=0;i<26;i++) {
            for(int k=0;k<26;k++) {
                if(reachable[i][j] && reachable[j][k]) {
                    reachable[i][k] = true;
                }
            }
        }
    }
    for(int i=0;i<N;i++) {
        string str1,str2;
        cin>>str1>>str2;
        bool flag = true;
        if(str1.size() != str2.size()) {
            flag = false;
        }
        else {
            int size = str1.size();
            for(int j=0;j<size;j++) {
                int a,b;
                a = str1[j]-'a';
                b = str2[j]-'a';
                if(!reachable[a][b]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"yes"<<"\n";
        }
        else {
            cout<<"no"<<"\n";
        }
    }
    return 0;
}