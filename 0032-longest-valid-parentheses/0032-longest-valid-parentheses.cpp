class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> st;
        st.push(-1);
        int left=0;
        int maxi=0;
        int count=0;
        if(n==0 || n==1)return 0;
        for(int right=0;right<n;right++){
            if(s[right]=='(') st.push(right);
            if( s[right]==')'){
                st.pop();
                if(st.empty()){
                    st.push(right);
                }else{
                    maxi=max(maxi,right-st.top());
                }
            }
            
        }
        return maxi;
    }
};