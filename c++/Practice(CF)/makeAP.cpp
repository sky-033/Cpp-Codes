#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    int t;
    cin>>t;
    while(t--){
        lli a,b,c;
        cin>>a>>b>>c;
        lli d1=b-a;
        lli d2=c-b;
        lli D=c+a;
        bool flag=false;
        if(d1==d2) cout<<"YES"<<endl;
        // else if(a==1LL && b==1LL){
        //     if(c%2==0) cout<<"NO"<<endl;
        //     else cout<<"YES"<<endl;
        // }
        // else if(a==1LL && c==1LL){
        //     cout<<"YES"<<endl;
        // }
        // else if(b==1LL && c==1LL){
        //     if(a%2==0) cout<<"NO"<<endl;
        //     else cout<<"YES"<<endl;
        // }
        else{
            if(D%2==0 && (D/2)%b==0) flag=true; 
            if(((b-d2)>0) && (abs(b-d2))%a==0) flag=true;
            if(((b+d1)>0) && (abs(b+d1))%c==0) flag=true;
            if(flag==true) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}