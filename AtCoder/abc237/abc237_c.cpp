#include<bits/stdc++.h>
using namespace std;
string S;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S;
    int size = S.size();
    int l,r;
    l = r = 0;
    while(l < size && S[l] == 'a') {
        l++;
    }
    while(r < size && S[size-1-r] == 'a') {
        r++;
    }
    bool flag = true;
    if(l > r) {
        flag = false;
    }
    else {
        int left = l;
        int right = size-1-r;
        while(left < right) {
            if(S[left] != S[right]) {
                flag = false;
                break;
            }
            left++;
            right--;
        }
    }
    cout<<(flag? "Yes": "No")<<"\n";
    return 0;
}