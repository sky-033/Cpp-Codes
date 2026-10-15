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
        lli n;
        cin>>n;
        lli ct2=0,ct3=0;
        bool flag=true;
        while(n>1){
            if(n%2==0){
                ct2++;
                n=n/2;
            }
            else if(n%3==0){
                ct3++;
                n=n/3;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            if(ct3>=ct2) cout<<2*ct3-ct2<<endl;
            else cout<<-1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}