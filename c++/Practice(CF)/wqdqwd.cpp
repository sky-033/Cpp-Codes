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
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        lli ct0=0,ct1=0;
        string s;
        cin>>s;
        f(i,n){
            if(s[i]=='0') ct0++;
            else ct1++;
        }
        lli pairs=n/2;
        lli noNeed=pairs-k;
        if(ct0<noNeed || ct1<noNeed){
            cout<<-1<<endl;
        }
        else{
            ct0-=noNeed;
            ct1-=noNeed;
            lli palindrome=ct0/2+ct1/2;
            if(palindrome==k) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}