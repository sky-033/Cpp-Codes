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
        lli n,k,x;
        cin>>n>>k>>x;
        if(k==1) cout<<"NO"<<endl;
        else if(k==2){
            if(x==1 && n%2==1) cout<<"NO"<<endl;
            else{
                if(x==2){
                    cout<<"YES"<<endl;
                    cout<<n<<endl;
                    f(i,n) cout<<1<<" ";
                    cout<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                    cout<<n/2<<endl;
                    f(i,n/2) cout<<2<<" ";
                    cout<<endl;
                }
            }
        }
        else{
            if(x!=1){
                cout<<"YES"<<endl;
                cout<<n<<endl;
                f(i,n) cout<<1<<" ";
                cout<<endl;
            }
            else{
                if(n%2==0){
                    cout<<"YES"<<endl;
                    cout<<n/2<<endl;
                    f(i,n/2) cout<<2<<" ";
                    cout<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                    cout<<((n-3)/2 + 1)<<endl;
                    cout<<3<<" ";
                    f(i,(n-3)/2) cout<<2<<" ";
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}