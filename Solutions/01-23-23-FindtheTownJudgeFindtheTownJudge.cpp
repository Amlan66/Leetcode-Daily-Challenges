class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> judge(n+1,0);
        vector<bool> trustSome(n+1,false);
        for(int i=0;i<trust.size();i++){
            judge[trust[i][1]]++;
            trustSome[trust[i][0]]=true;
        }
        
        for(int i=1;i<n+1;i++){
            if(judge[i]==n-1 && !trustSome[i])
                return i;
        }

        return -1;
    }
};