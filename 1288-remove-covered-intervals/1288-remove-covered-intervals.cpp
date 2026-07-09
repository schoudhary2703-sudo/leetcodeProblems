class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            if (a[0] != b[0]) {
            return a[0] < b[0]; 
        }
        return a[1] > b[1]; 
        });
        int ans=0;
        int maxEnd=0;
        for(const auto& inter:intervals){
            if(inter[1]<=maxEnd){
                ans++;
            }
            else{
                maxEnd=inter[1];
            }
        }
        return n-ans;
    }
};