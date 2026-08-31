/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ListNode* prevNode=NULL;
        int i=0;
        while(head != NULL){
            if(prevNode !=NULL && head->next != NULL){
                if(prevNode->val > head->val && head->next->val > head->val || prevNode->val < head->val && head->next->val < head->val){
                    ans.push_back(i);
                }
            }
            i++;
            prevNode=head;
            head=head->next;

        }
        int n=ans.size();
        if(n<2)return {-1,-1};
        int minDist=INT_MAX;
        for (int j = 1; j < n; j++) {
            minDist = min(minDist, ans[j] - ans[j - 1]);
        }
        int maxDist=ans[n-1]-ans[0];
        return {minDist,maxDist};
    }
};