#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        lli n=s.size();
        lli l=0,h=0,maxlen=0;
        while(h<n){
            if(s[h]=='1'){
                maxlen=max(maxlen,h-l+1);
                h++;
            }
            else{
                h++;
                l=h;
            }
        } 
        lli x=0,y=0;
        f(i,n){
            if(s[i]=='1') x++;
            else break;
        }
        rf(i,n){
            if(s[i]=='1') y++;
            else break;
        }
        if(x+y<=n) maxlen=max(maxlen,x+y);
        lli ans=0;
        if(maxlen==n) ans=n*n;
        else if(maxlen==0) ans=0;
        else if(n!=1 && maxlen==1 && s[0]=='1' && s[n-1]=='1') ans=2;
        else if(n==1 && maxlen==1) ans=1;
        else if(maxlen&1) ans=(maxlen/2 +1)*(maxlen/2 +1);
        else ans=(maxlen/2)*(maxlen/2+1);
        cout<<ans<<endl;
    }
    return 0;
}