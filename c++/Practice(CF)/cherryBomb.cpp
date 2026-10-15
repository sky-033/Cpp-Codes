#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
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
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        bool flag=true;
        f(i,n){
            if(b[i]!=-1){
                flag=false;
                break;
            }
        }
        if(flag){
            sort(a.begin(),a.end());
            if(a[0]+k>=a[n-1]){
                cout<<1+a[0]+k-a[n-1]<<endl;
            }
            else cout<<0<<endl;
        }
        else{
            vll A;
            vp B;
            f(i,n){
                if(b[i]!=-1){
                    A.push_back(a[i]+b[i]);
                }
                else{
                    B.emplace_back(a[i],a[i]+k);
                }
            }
            bool flag1=true,flag2=true;;
            f(i,A.size()-1){
                if(A[i]!=A[i+1]){
                    flag1=false;
                    break;
                }
            }
            if(flag1){
                for(auto &it:B){
                    if(it.first>A[0] || it.second<A[0]){
                        flag2=false;
                        break;
                    }
                }
                if(flag2) cout<<1<<endl;
                else cout<<0<<endl;
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}