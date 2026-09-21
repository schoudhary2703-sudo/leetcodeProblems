class Solution {

   
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int parentX=find(x);
        int parentY=find(y);
        if(parentX==parentY) return;
        if(rank[parentX]>rank[parentY]){
            parent[parentY]=parentX;
        }else if(rank[parentX]<rank[parentY]){
            parent[parentX]=parentY;
        }else{
            parent[parentY]=parentX;
            rank[parentX]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=1;
        }
        for(string &s:equations){
            if(s[1]=='='){
                unite(s[0]-'a',s[3]-'a');
            }
        }
        for(string &s:equations){
            if(s[1]=='!'){
                int  first=s[0]-'a';
                int second=s[3]-'a';
                if(find(first)==find(second)){
                    return false;
                }
            }
        }
        return true;
    }
};