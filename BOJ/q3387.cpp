#include<bits/stdc++.h>
using namespace std;
int arr[10];
int K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>K;
    int a,b;
    bool flag = false;
    for(int k=1;k<=K && !flag;k++) {
        for(int i=1;i<=9;i++) {
            arr[i] = (arr[i]*10+i)%K;
            if(arr[i] == 0) {
                a = i,b = k;
                flag = true;
                break;
            }
        }
    }
    if(flag) {
        cout<<a<<" "<<b<<"\n";   
    }
    else {
        cout<<"Impossible"<<"\n";
    }
    return 0;
}