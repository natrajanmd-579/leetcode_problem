class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        const int INF=1e9;
        int left=0;
        int right=0;
        int answer=INF;
        int sum=0;
        vector<int>best(n,INF);
        for(int right=0;right<n;right++){
             sum += arr[right];
            while(sum > target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int len=right-left+1;
                if(left>0 && best[left-1]!=INF){
                    answer=min(answer,len+best[left-1]);
                }
                if(right==0){
                    best[right]=len;}
                else{
                      best[right]=min(len,best[right-1]);}
            }
            else{
                if(right>0){
                    best[right]=best[right-1];
                }
            }
        }
        return answer==INF?-1:answer;
        }
};