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
        lli n;
        cin>>n;
        vll a(n),A(n),prefix(n-1,0);
        unordered_map<lli,lli> mpp;
        f(i,n){
            cin>>a[i];
            A[i]=a[i];
        }
        if(n==1){
            cout<<0<<endl;
        }
        else{
            sort(A.begin(),A.end());
            mpp.insert({A[n-1],n-1});
            prefix[0]=A[0];
            ff(1,n-1,1) prefix[i]=prefix[i-1]+A[i];
            lli x=n-1;
            fb(n-1,0,1){
                if(A[i+1]<=prefix[i]){
                    //l=kuch nhi hoga
                }
                else{
                    x=i;
                }
                mpp.insert({A[i],x});
            }
            f(i,n){
                cout<<mpp[a[i]]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}