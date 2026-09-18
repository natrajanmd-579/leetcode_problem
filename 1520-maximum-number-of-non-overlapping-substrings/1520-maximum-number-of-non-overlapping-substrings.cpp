class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int size=s.length();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<size;i++){
            mp[s[i]].push_back(i);
        }
        vector<pair<int,int>>intervals;
        for(auto &it:mp){
            char ch=it.first;

            int l=mp[ch][0];
            int r=mp[ch].back();

            bool valid=true;

            for(int i=l;i<r;i++){
                char cur=s[i];
                if(mp[cur][0]<l){
                    valid=false;
                    break;
                }

                r=max(r,mp[cur].back());
            }

            if(valid){
                intervals.push_back({l,r});
            }
        }
        sort(intervals.begin(),intervals.end(),
        [](auto &a,auto &b) 
        {return a.second <b.second;});
        int lastend=-1;
        vector<string>ans;
        for(auto &interval:intervals){
            int l=interval.first;
            int r=interval.second;

            if(l>lastend){
                ans.push_back(s.substr(l,r-l+1));
                lastend=r;
            }
        }
        return ans;
    }
};