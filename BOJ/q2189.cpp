#include<bits/stdc++.h>
using namespace std;
int arr[9][9];
int N;
string check(int sum) {
    int tmp1,tmp2;
    for(int i=1;i<=N;i++) {
        tmp1 = tmp2 = 0;
        for(int j=1;j<=N;j++) {
            tmp1+=arr[i][j];
            tmp2+=arr[j][i];
        }
        if(sum != tmp1 || sum != tmp2) {
            return "Not a Magick Square";
        }
    }
    tmp1 = tmp2 = 0;
    for(int i=1;i<=N;i++) {
        tmp1+=arr[i][i];
        tmp2+=arr[N-i+1][i];
    }
    if(sum != tmp1 || sum != tmp2) {
        return "Semi-Magick Square";
    }
    vector<int> v;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            v.push_back(arr[i][j]);
        }
    }
    sort(v.begin(),v.end());
    int size = v.size();
    for(int i=1;i<size;i++) {
        if(v[i-1] == v[i]) {
            return "Weakly-Magick Square";
        }
    }
    for(int i=1;i<size;i++) {
        if(v[i-1]+1 != v[i]) {
            return "Strongly-Magick Square";
        }
    }
    return "Magically-Magick Square";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int t=1;;t++) {
        cin>>N;
        if(!N) break;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                cin>>arr[i][j];
            }
        }
        int sum = 0;
        for(int i=1;i<=N;i++) {
            sum+=arr[i][1];
        }
        cout<<"Square "<<t<<": "<<check(sum)<<"\n";
    }
    return 0;
}