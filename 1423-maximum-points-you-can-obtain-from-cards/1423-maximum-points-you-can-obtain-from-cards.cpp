class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0,right=0;
        int minpt=INT_MAX;
        int n=cardPoints.size();
        int sum=0;
        for(int x:cardPoints){
                sum+=x;
        }
        if(k==n) return sum;
        int winsize=n-k;
        int winsum=0;
        while(right<n){
            winsum+=cardPoints[right];
            if(right-left+1>winsize){
                winsum-=cardPoints[left];
                left++;
            }
            if(right-left+1==winsize){
                minpt=min(minpt,winsum);
            }
            right++;
            }
            return sum-minpt;
        }
};