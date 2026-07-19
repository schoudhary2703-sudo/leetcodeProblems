class Solution {
public:
    string removeDuplicateLetters(string s) {
        //only me and god know how this code works
        int n =s.length();
        vector<int> last(26,0);
        vector<bool> seen(26,false);
        string res="";
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        for(int i = 0 ; i < n; i++){
            char current=s[i];
            if(seen[current-'a'])continue;
            while(!res.empty() && current<res.back() && i<last[res.back()-'a']){
                seen[res.back()-'a']=false;
                res.pop_back();

            }
            res.push_back(current);
            seen[current-'a']=true;
        }
        return res;
        //now only god knows
    }
};