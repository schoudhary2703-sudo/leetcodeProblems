class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long , int> freq;
        for(int num : nums){
            freq[num]++;
        }
        int max_len=1;
        if(freq.count(1)){
            int one = freq[1];
            if(one%2==0)one--;
            max_len=max(max_len,one);
        }
    
        for(auto const&[val,count]:freq){
            long long x=val;
            if(x==1)continue;
            int curr=0;
            while(freq.count(x)&&freq[x]>=2){
                curr+=2;
                x=x*x;
            }
            if(freq.count(x)&&freq[x]>=1){
                curr+=1;
            }
            else{
                curr-=1;
            }
            max_len=max(max_len,curr);
        }
        return max_len;
    }
};