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
        vector<int> ans = {-1,-1};
        ListNode* p = head;
        ListNode* c = head->next;
        int i = 1;
        vector<int> arr;
        while(c && c->next){
            ListNode* n = c->next;
            if((c->val > p->val && c-> val > n->val)||(c->val < p->val && c-> val < n->val)){
                arr.push_back(i);
            }
            p = c;
            c = c->next;
            i++;
        }
        sort(arr.begin(),arr.end());
        if(arr.size() < 2)
        return ans;

        int mini = INT_MAX;
        for(int i = 0; i < arr.size()-1;i++){
            if(arr[i+1]-arr[i] <= mini)
            mini = arr[i+1]-arr[i];
        }
        int maxi = arr[arr.size()-1]-arr[0];
        ans[0] = mini;
        ans[1] = maxi;
        return ans;
        
    }
};



// Second approach

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
        vector<int> ans = {-1,-1};
        ListNode* p = head;
        ListNode* c = head->next;
        int i = 1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int si = -1;
        int pi = -1;
        while(c && c->next){
            ListNode* n = c->next;
            if((c->val > p->val && c-> val > n->val)||(c->val < p->val && c-> val < n->val)){
                if(si == -1)
                si = i;

                if(pi != -1){
                    mini = min(mini,i-pi);
                }

                pi = i;
            }
            p = c;
            c = c->next;
            i++;
        }
        if(si != -1)
        maxi = pi-si;
        if(si != pi){
            ans[0] = mini;
            ans[1] = maxi;
        }
        return ans;
    }
};