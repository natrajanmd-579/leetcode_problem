class Solution {
public:
    bool canmake(vector<int>& bloomDay,int day,int m, int k){
        int bouquet=0;
        int flower=0;

        for(int bloom:bloomDay){
            if(bloom<=day){
                flower++;
                if(flower==k){
                    bouquet++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       long long need=1LL*m*k;
       if(need > bloomDay.size()) return -1;

       int low = *min_element(bloomDay.begin(), bloomDay.end());
       int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low < high){
            int mid=low+(high-low)/2;
            if(canmake(bloomDay,mid,m,k)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};