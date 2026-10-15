#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int l,r;
        cin>>l>>r;
        if(l==1 && r==1) cout<<1<<endl;
        else if(l==r) cout<<0<<endl;
        else cout<<r-l<<endl;
    }
    
    return 0;
}