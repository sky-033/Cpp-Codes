#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            vector<int>v(m);
            for(int j=0;j<m;j++){
                cin>>v[m];
            }
            vec.push_back(v);
        }
        for(int i=0;i<n;i++){
            sort(vec[i].begin(),vec[i].end());
        }
        bool flag=true;
        int max=-1;
        for(int i=0;i<n;i++){
            if(vec[i][0]>max) max=vec[i][0];
        }

        
    }
    return 0;
}