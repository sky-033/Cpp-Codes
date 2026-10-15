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
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,indx;
        cin>>n>>indx;
        indx--;
        string s;
        cin>>s;
        lli ct1=0,ct2=0;
        for(lli i=0;i<indx;i++){
            if(s[i]=='#') ct1++;
        }
        for(lli i=indx+1;i<n;i++){
            if(s[i]=='#') ct2++;
        }
        
        if(ct1==0 && ct2==0) cout<<1<<endl;
        else{
            lli i1=-1,i2=-1;
            for(lli i=indx;i>=0;i--){
                if(s[i]=='#'){
                    i1=i+1;
                    break;
                }
            }
            for(lli i=indx;i<n;i++){
                if(s[i]=='#'){
                    i2=i-1;
                    break;
                }
                
            }
            lli day1=indx+1;
            lli day2=n-indx;
            if(ct1==0){
                day2=n-i2;
                cout<<min(day1,day2)<<endl;
            }
            else if(ct2==0){
                day1=i1+1;
                cout<<min(day1,day2)<<endl;
            }
            else{
                lli case1=1e9,case2=1e9;
                case1=min(i1+1,n-indx);
                case2=min(indx+1,n-i2);
                cout<<max(case1,case2)<<endl;
            }  
        }
    }
    return 0;
}