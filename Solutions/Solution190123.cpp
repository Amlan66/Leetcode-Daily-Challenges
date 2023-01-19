class Solution190123 {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> modGroups(k);
        modGroups[0] = 1;

        int result=0,prefixMod=0;
    
        for(int i=0;i<n;i++){
            
            prefixMod = (prefixMod + nums[i] % k + k) % k;

            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        return result;
    }
};