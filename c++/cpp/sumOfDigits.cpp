#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int c=0,rem;
        while(N){
            rem=N%10;
            c+=rem;
            N/=10;
        }
        cout<<c<<endl;
    }
    return 0;
}