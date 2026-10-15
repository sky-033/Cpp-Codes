#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

vll factor(lli n){
    vll ans;
    for(lli i=2;i*i<=n;i++){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    if(n>1) ans.push_back(n);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll factors=factor(n);
        set<lli> unique;
        fa(factors){
            unique.insert(it);
        }
        sor(factors);
        if(unique.size()>=3){
            cout<<"YES"<<endl;
            lli a=1,b=1,c=1;
            lli indx,indx1;
            a=factors[0];
            ff(1,factors.size(),1){
                if(factors[i]==factors[i-1]) a*=factors[i];
                else{
                    indx=i;
                    break;
                }
            }
            b=factors[indx];
            ff(indx+1,factors.size(),1){
                if(factors[i]==factors[i-1]) b*=factors[i];
                else{
                    indx1=i;
                    break;
                }
            }
            ff(indx1,factors.size(),1){
                c*=factors[i];
            }
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else if(unique.size()==2){
            lli a=factors[0];
            lli b=factors[factors.size()-1];
            lli c=1;
            ff(1,factors.size()-1,1) c*=factors[i];
            if(c!=1 && (a!=b && b!=c && a!=c)){
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl; 
            }
            else cout<<"NO"<<endl;
        }
        else{
            lli x=factors.size();
            if(x>=6){
                cout<<"YES"<<endl;
                lli a=factors[0];
                lli b=a*a;
                lli c=pow(factors[0],x-3);
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
            else cout<<"NO"<<endl;
        }

    }
    return 0;
}