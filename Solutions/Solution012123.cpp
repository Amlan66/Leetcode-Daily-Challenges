class Solution {
public:
    bool valid(const string& s, int ind, int length){
        return length==1 || (s[ind]!='0'&& (length<3 || s.substr(ind,length) <= "255"));
    }
    void backtrack(const string& s, int ind, vector<string>& ans, vector<int>& dots){
        const int remaininglength = s.length()-ind;
        const int remainingdots = 4-dots.size();

            if(remaininglength > 3*remainingdots || remaininglength < remainingdots)
                return;

            if(dots.size()==3){
                if(valid(s,ind,remaininglength)){
                    string temp;
                    int last=0;
                    for(int dot:dots){
                        temp.append(s.substr(last,dot));
                        last+=dot;
                        temp.append(".");
                    }
                    temp.append(s.substr(ind));
                    ans.push_back(temp);

                }
                return;
            }

            for(int curr=1; curr<=3 && curr<=remaininglength; curr++){
                dots.push_back(curr);
                if(valid(s,ind,curr)){
                    backtrack(s,ind+curr,ans,dots);
                }
                dots.pop_back();
            }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int>dots;

        backtrack(s,0,ans,dots);

        return ans;
    }
};