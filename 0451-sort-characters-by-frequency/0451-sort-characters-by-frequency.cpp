class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>freq;
       for(char c : s){
          freq[c]++;
       } 

       vector<string>buckets(s.length()+1);
       for(auto &p:freq){
        buckets[p.second].append(p.second,p.first);
       }

       string res="";
       for(int i=buckets.size()-1;i>=0;i--){
         res+=buckets[i];
       }
       return res;
    }
};