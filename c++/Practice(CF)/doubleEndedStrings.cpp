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
        string a,b;
        cin>>a>>b;
        int ct=0;
        int a1=a.size(),b1=b.size();
        if(a1<=b1){
            for(int i=0;i<a1;i++){
                int j=i,low=i;
                while(j<a1){
                    string temp="";
                    for(int x=low;x<=j;x++){
                        temp.push_back(a[x]);
                    }
                    // cout<<temp<<endl;
                    size_t pos = b.find(temp);
                    if(pos==string::npos) j=a1;
                    else {
                        if(temp.size()>ct) ct=temp.size();
                        j++;
                    }
                }
            }
        }
        else{
            for(int i=0;i<b1;i++){
                int j=i,low=i;
                while(j<b1){
                    string temp="";
                    for(int x=low;x<=j;x++){
                        temp.push_back(b[x]);
                    }
                    // cout<<temp<<endl;
                    size_t pos = a.find(temp);
                    if(pos==string::npos) j=b1;
                    else {
                        if(temp.size()>ct) ct=temp.size();
                        j++;
                    }
                }
            }
        }
        cout<<a1+b1-2*ct<<endl;
    }
    return 0;
}