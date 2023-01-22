class Solution {
public:
     void backtrack(set<vector<int>>&st, vector<int>& sequence,int ind, vector<int>& nums){
        if(ind == nums.size()){
            if(sequence.size()>=2)
                st.insert(sequence);
            return;
        }

        if(sequence.empty()||sequence.back()<=nums[ind]){
            sequence.push_back(nums[ind]);
            backtrack(st,sequence,ind+1,nums);
            sequence.pop_back();
        }
        backtrack(st,sequence,ind+1,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> sequence;
        backtrack(st,sequence,0,nums);
        return(vector(st.begin(),st.end()));
    }
};