#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli C;
    cin>>C;
    lli size=log2(C)+1;
    lli a=0,b=0;
    vll set_bits;
    f(i,size){
        if((C&(1<<i))==0){
            a|=1<<i;
            b|=1<<i;
        }
        else{
            set_bits.push_back(i);
        }
    }
    lli ans=-1;
    lli size1=1<<set_bits.size();
    f(i,size1){
        lli a_copy=a,b_copy=b;
        g(j,set_bits.size()){
            if(i&(1<<j)){
                a_copy|=(1<<set_bits[j]);
            }
            else{
                b_copy|=(1<<set_bits[j]);
            }
        }
        ans=max(ans,a_copy*b_copy);
    }
    cout<<ans<<endl;
    return 0;
}