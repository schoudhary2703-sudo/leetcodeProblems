class Solution {
private:
    vector<int> parent,rnk;
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return ;
        if(rnk[px]>rnk[py]){
            parent[py]=px;
        }else if(rnk[px]<rnk[py]){
            parent[px]=py;
        }else{
            parent[py]=px;
            rnk[px]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int y=connections.size();
        if(n-1>y) return -1;
        parent.resize(n);
        rnk.assign(n,0);
        iota(parent.begin(),parent.end(),0);
        int comp=0;
        for(auto& c:connections){
            unite(c[0],c[1]);
        }
        for(int i=0;i<n;i++){
            if(find(i)==i) comp++;
        }
        return comp-1;
    }
};