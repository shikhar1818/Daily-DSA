class Solution {
	public:
	struct meeting {
		int start;
		int finish;
		int idx;
	};
	static bool compare(meeting a , meeting b){
		   if(a.finish == b.finish){
		        return (a.idx < b.idx);
		    }
		    else
		    return (a.finish < b.finish);
		}
		
	vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
		int n = s.size();
		vector<meeting> arr(n);
		for (int i = 0; i < n; i++) {
			arr[i].start = s[i];
			arr[i].finish = f[i];
			arr[i].idx = i+1;
		}
		sort(arr.begin(),arr.end(),compare);
		int last = -1;
		vector<int> ans;
		
		for(int i = 0; i < n; i++){
		    if(arr[i].start > last){
		        ans.push_back(arr[i].idx);
		        last = arr[i].finish;
		    }
		}
		sort(ans.begin(),ans.end());
		return ans;
		
		
	}
};
