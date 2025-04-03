#include<bits/stdc++.h>
using namespace std;
const int MAX = 50001;
int arr[MAX][26];
string str;
int Q,A,B,C,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int size = str.size();
    for(int i=1;i<=size;i++) {
        for(int j=0;j<26;j++) {
            arr[i][j] = arr[i-1][j];
        }
        arr[i][str[i-1]-'a']++;
    }
    cin>>Q;
    while(Q--) {
        cin>>A>>B>>C>>D;
        if(B-A != D-C) {
            cout<<"NE"<<"\n";
            continue;
        }
        bool flag = true;
        for(int i=0;i<26;i++) {
            int x = arr[B][i]-arr[A-1][i];
            int y = arr[D][i]-arr[C-1][i];
            if(x != y) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout<<"DA"<<"\n";
        }
        else {
            cout<<"NE"<<"\n";
        }
    }
    return 0;
}