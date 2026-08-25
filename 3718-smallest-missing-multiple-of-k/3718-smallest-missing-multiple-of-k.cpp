class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int num:nums){
            st.insert(num);
        }
        int i =1;
        while(st.find(i*k)!=st.end()){
            i++;
        }
        return i*k;
    }
};