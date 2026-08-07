class Solution {
  public:
  int findParent(int node, vector<int> &parent) {
        if (node == parent[node]) 
            return node;
        return parent[node] = findParent(parent[node], parent);
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        int m = profit.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++){
            idx[i] = i;
        }
        
        sort(idx.begin(),idx.end(),[&](int i, int  j){
            return profit[i] > profit[j];
        });
        
        int max_dl = 0;
        
        for(int i = 0 ; i < n; i++){
            max_dl = max(max_dl,deadline[i]);
        }
        vector<int> parent(max_dl+1);
        for(int i = 0; i <= max_dl; i++){
            parent[i] = i;
        }
        int max_pr = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int slot = findParent(deadline[idx[i]],parent);
            if(slot > 0){
                cnt++;
                max_pr += profit[idx[i]];
                parent[slot] = findParent(slot - 1, parent);
            }
        }
        vector<int> ans = {cnt,max_pr};
        return ans;
        
    }
};