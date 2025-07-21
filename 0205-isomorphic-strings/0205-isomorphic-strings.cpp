class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){return false;}
        unordered_map<char,char>mapS,mapT;
        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];
        if(mapS.count(c1)){
            if(mapS[c1]!=c2){return false;}
        }else{
            mapS[c1]=c2;
        }

        if(mapT.count(c2)){
            if(mapT[c2]!=c1){return false;}
        }else{
            mapT[c2]=c1;
        }
    }
    return true;
    }
};