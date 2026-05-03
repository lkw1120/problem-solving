#include<bits/stdc++.h>
using namespace std;
string S,T;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>T;
    int p1,p2,cnt;
    p1 = p2 = cnt = 0;
    int size1 = S.size();
    int size2 = T.size();
    bool flag = true;
    while(p1 < size1 && p2 < size2) {
        if(S[p1] == T[p2]) {
            p1++,p2++;
        }
        else {
            if(S[p1] != 'A' && T[p2] == 'A') {
                p2++;
                cnt++;
                
            }
            else if(S[p1] == 'A' && T[p2] != 'A') {
                p1++;
                cnt++;
            }
            else {
                flag = false;
                break;
            }
        }
    }
    while(p1 < size1) {
        if(S[p1] != 'A') {
            flag = false;
            break;
        }
        p1++;
        cnt++;
    }
    while(p2 < size2) {
        if(T[p2] != 'A') {
            flag = false;
            break;
        }
        p2++;
        cnt++;
    }
    ans = flag? cnt: -1;
    cout<<ans<<"\n";
    return 0;
}