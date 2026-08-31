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
        ListNode* prev=head;
        ListNode* curr=head->next;
        int firstcrit=0;
        int prevcrit=0;
        int mindist=INT_MAX;
        int maxdist=INT_MIN;
        int i=1;
        while(curr->next!=NULL){
            if(curr->val>prev->val && curr->val>curr->next->val ||
               curr->val<prev->val && curr->val<curr->next->val){
                if(prevcrit==0){
                    prevcrit=i;
                    firstcrit=i;
                }
                else{
                    mindist=min(mindist,i-prevcrit);
                    maxdist=max(maxdist,i-firstcrit);
                    prevcrit=i;
                }
            }
            i++;
            prev=curr;
            curr=curr->next;
        }
        if(mindist==INT_MAX || maxdist==INT_MIN){
            return {-1,-1};
        }
        return {mindist,maxdist};
    }
};