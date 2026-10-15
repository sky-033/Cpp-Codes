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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n+1,0);
        ff(1,n+1,1){
            a[i]=i;
        }
        if(k&1) cout<<"NO"<<endl;
        
        else{
            vll v1;
            lli l=1,h=n;
            while(l<h){
                v1.push_back(2*(h-l));
                l++;
                h--;
            }
            lli size=v1.size();
            lli sum=0;
            f(i,size){
                sum+=v1[i];
            }
            if(k>sum) cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                lli ct=0;
                f(i,size){
                    if(v1[i]<=k){
                        k-=v1[i];
                        ct++;
                    }
                    else break;
                }
                if(k==0){
                    lli l=1,h=n;
                    while(ct>0){
                        swap(a[l],a[h]);
                        ct--;
                        l++,h--;
                    }
                }
                else{
                    lli l=1,h=n;
                    while(ct>0){
                        swap(a[l],a[h]);
                        ct--;
                        l++,h--;
                    }
                    k/=2;
                    lli x=k+a[l];
                    swap(a[l],a[x]);
                }
                ff(1,n+1,1) cout<<a[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}