#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long int ll;


using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007



ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}


ll binExp(ll a,ll b)
{
    if(b==0)
        return 1;

    ll res=binExp(a,b/2);

    if(b&1)
    {
        return (a*res*res)%mod;

    }
    else
    {
        return (res*res)%mod;
    }
}


bool isPrime(long long  n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

class DisjointSet
{

public:
    vector<ll> parent,rnk,sz;
    DisjointSet(ll n)
    {
        rnk.resize(n+1,0);
        parent.resize(n+1);
        sz.resize(n+1);

        for(ll i=0; i<=n; i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
    }

    ll findUPar(ll node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    bool unionByRank(ll u,ll v)
    {
        ll ulp_u=findUPar(u);
        ll ulp_v=findUPar(v);

        if(ulp_u==ulp_v)
        {
            return false;
        }
        if(rnk[ulp_u]==rnk[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            rnk[ulp_v]++;
        }
        else if(rnk[ulp_u]<rnk[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rnk[ulp_v]<rnk[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        return true;
    }

    bool unionBYSize(ll u,ll v)
    {
        ll ulp_u=findUPar(u);
        ll ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return false;

        if(sz[ulp_u]<sz[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            sz[ulp_v]+=sz[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            sz[ulp_v]+=sz[ulp_u];
        }
        return true;
    }




};

class segmentTree
{

    vector<ll> segArray;

public:
    segmentTree(ll n)
    {
        segArray.resize(4*n);
    }

    void build(ll index,ll low,ll high,vector<ll> &arr)
    {
        if(low==high)
        {
            segArray[index]=arr[low];
            return;
        }

        ll mid = (low+high)/2;

        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);

        segArray[index] = min(segArray[2*index+1],segArray[2*index+2]);
    }

    ll query(ll index,ll low,ll high,ll l,ll r)
    {
        // no overlap
        ///[low high l r] or [l r low high]

        if(high<l || low>r)
        {
            return LONG_MAX;
        }


        // Complete Overlap
        /// [l low high r]

        if(low>=l && high<=r)
        {
            return segArray[index];
        }

        /// Partial overlap

        ll mid = (low+high)/2;

        ll left=query(2*index+1,low,mid,l,r);
        ll right=query(2*index+2,mid+1,high,l,r);

        return min(left,right);


    }

    void update(ll index,ll low,ll high,ll updateIndex,ll value)
    {
        if(low==high)
        {
            segArray[index]=value;
            return;
        }

        ll mid=(low+high)/2;

        if(updateIndex<=mid)
            update(2*index+1,low,mid,updateIndex,value);
        else
            update(2*index+2,mid+1,high,updateIndex,value);

        segArray[index]=min(segArray[2*index+1],segArray[2*index+2]);
    }

    void display()
    {
        for(auto s:segArray)
        {
            cout<<s<<" ";
        }
        cout<<endl;
    }


};





void solve()
{
   ll n,m;
   cin>>n>>m;

   char arr[n+2][m+2];

   for(ll i=0; i<n; i++)
   {
       for(ll j=0; j<m; j++)
       {
           cin>>arr[i][j];
       }
   }

   ll row=-1,col=-1;


   for(ll i=0; i<n; i++)
   {
       for(ll j=0; j<m; j++)
       {
           if(arr[i][j]=='B')
           {
               row=i;
               col=j;
               break;
           }
       }
       if(row!=-1)
       {
           break;
       }
   }



   vector<pair<ll,ll>> pr;
   while(1)
   {
       if(arr[row][col]=='B' && row<n && col<m)
       {
           pr.push_back({row,col});
           row++;
           col++;
       }
       else
       {
           break;
       }
   }

   ll x=pr.size();
   x=(x/2);

   cout<<pr[x].first+1<<" "<<pr[x].second+1<<endl;

}





















int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);





    ll t;
   // cin>>t;
    t=1;








    ll caseNo=1;



    while(t--)
    {
        // cout<<"Case "<<caseNo<<": ";
        // caseNo++;


        solve();


    }
    return 0;




}







