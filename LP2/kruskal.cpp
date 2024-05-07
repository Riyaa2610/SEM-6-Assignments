#include<iostream>
#include<vector>
using namespace std;
#define v 5
class graph
{
    public:
    int par[v+1];
    int findpar(int x)
    {
        if(par[x]==x)return x;
        return par[x]=findpar(par[x]);
    }
    int union_Set(int x,int y)
    {
        int p=findpar(x);
        int q=findpar(y);
        par[p]=q;
    }
    void kruskals(int adj[v][v])
    {
        for(int i=0;i<v+1;i++)
        {
            par[i]=i;
        }
        int ans=0;
        int edge=0;
        while(edge<v-1)
        {
            int mx=1e9;
            int x=0,y=0;
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(findpar(i)!=findpar(j) && adj[i][j] && mx>adj[i][j])
                    {
                        x=i;
                        y=j;
                        mx=adj[i][j];
                    }
                }
            }
            cout<<x<< ' '<<y<<endl;
            edge++;
            ans+=mx;
            union_Set(x,y);
        }
        cout<<"The cost is "<<ans<<endl;
    }

};
int main()
{
    int g[5][5]={
        { 0, 1, 0, 0, 0 },
        { 0, 0, 3, 0, 2},
        { 1, 0, 0, 0, 0 },
        { 0, 0, 3, 0, 5},
        { 0, 0, 0, 0, 0 } 
    };
    graph obj;
    obj.kruskals(g);

}