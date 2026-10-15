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

int binarySearchByKey(const vector<pair<lli, lli>>& ind, lli key) {
    int left = 0, right = (int)ind.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ind[mid].first == key)
            return mid;  // found the key
        else if (ind[mid].first < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
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
        vll a(n),b(n);
        vp ind,initial;
        f(i,n){ cin>>a[i]; b[i]=a[i]; initial.emplace_back(a[i],i);}
        sort(a.begin(),a.end());
        lli x0=0;
        lli a1=n/2;
        lli b1=n-n/2;
        lli ans=0;
        for(lli i=1,j=-a1;i<n,j<0;i+=2,j++){
            ind.emplace_back(a[i],j);
        }
        for(lli i=0,j=b1;i<n,j>=1;i+=2,j--){
            ind.emplace_back(a[i],j);
        }
        for(auto &it:ind){
            if(it.second<0){
                ans+=it.first*it.second*(-1)*2;
            }
            else ans+=it.first*it.second*2;
        }
        sort(initial.rbegin(),initial.rend());
        cout<<ans<<endl;
        cout<<0<<" ";
        vll final(n,0);
        lli cord=1;
        f(i,n){
            final[initial[i].second]=cord;
            if(cord>0) cord=-1*cord;
            else cord=-1*cord+1;

        }
        f(i,n) cout<<final[i]<<" ";
        cout<<endl;
    }
    return 0;
}