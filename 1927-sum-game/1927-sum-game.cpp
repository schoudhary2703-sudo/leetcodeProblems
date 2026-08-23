class Solution {
public:
    bool sumGame(string num) {
        int q_diff=0;
        int sum_diff=0;
        for(int i =0;i<(num.size()/2);i++){
            if(num[i]=='?')q_diff++;
            else{
                sum_diff-=(num[i] -'0');
            }
        }
        for(int i=num.size()/2;i<num.size();i++){
            if(num[i]=='?')q_diff--;
            else{
                sum_diff+=(num[i] -'0');
            }
        }
        if(q_diff%2!=0)return true;
        return (q_diff/2)*9==sum_diff?false:true;

    }
};