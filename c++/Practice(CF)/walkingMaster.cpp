#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,x,A,ans;
        cin>>a>>b>>c>>d;
        if(d-b>=0){
            x=d-b;
            A=a+x;
            ans=A-c;
            x+=ans;
        // cout<<c<<" "<<A<<endl;
            if(A<c) cout<<-1<<endl;
            else{
                cout<<x<<endl;
            } 
        }
        else cout<<-1<<endl;
    }
    return 0;
}