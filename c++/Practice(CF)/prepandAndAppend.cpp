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
        string s;
        cin>>s;
        if(s[0]=='1' && s[n-1]=='1') cout<<n<<endl;
        else if(s[0]=='0' && s[n-1]=='0') cout<<n<<endl;
        else{
            lli i=0,j=n-1;
            while(i<j){
                if(s[i]!=s[j]){
                    n-=2;
                    i++;
                    j--;
                }
                else{
                    break;
                }
            }
            cout<<n<<endl;
        }
    }
    return 0;
}