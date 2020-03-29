/*
Google kickstart Round A 2020
Plates - Recursive solution
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll takePlates(vector<vector<ll>>v,ll i, ll p){
    if(p<=0 || i>=v.size()) return 0;
    ll ans=INT_MIN;
    for(ll j=0;j<v[i].size();j++){
        if(p-j>=0){
            ll sum=v[i][j]+takePlates(v,i+1,p-j);
            if(sum>ans){
                ans=sum;
            }
        }
        
    }
    return ans;
}

int main() {
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++){
        ll n,m,p;
        cin>>n>>m>>p;
        vector<vector<ll> > vec( n);
        for(ll i=0;i<n;i++){
            vec[i].push_back(0);
            for(ll j=0;j<m;j++){
                ll x;
                cin>>x;
                vec[i].push_back(x);
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=1;j<=m;j++){
                vec[i][j]=vec[i][j]+vec[i][j-1];
            }
        }
        cout<<"Case #"<<t<<": "<<takePlates(vec,0,p)<<"\n";
    }
    return 0;
}
