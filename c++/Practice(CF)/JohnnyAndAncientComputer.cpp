#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,b) for(lli i=a;i<b;i++)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli a,b;
        cin>>a>>b;
        if(b>a) swap(a,b);
        if(a>b){
            if(a%b!=0) cout<<-1<<endl;
            else{
                lli temp=a/b;
                lli ct=0;
                bool flag=true;
                while(temp>0){
                    temp/=2;
                    ct++;
                    if(temp!=1 && temp%2!=0){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    lli a=0,b=0,c=0,ans=0;
                    a+=ct/3;
                    ct-=a*3;
                    b=ct/2;
                    ct-=b*2;
                    c=ct;
                    ct-=c;
                    ans=a+b+c;
                    cout<<ans<<endl;
                }
                else cout<<-1<<endl;
            }
        }
    }
    return 0;
}