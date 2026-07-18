class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days){
        int dayused=1;
        int load=0;
        for(int weight:weights){
            if(load+weight > capacity){
                dayused++;
                load=weight;
            }
            else{
                load+=weight;
            }
        }
       return dayused <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int low = *max_element(weights.begin(), weights.end());
         int high = accumulate(weights.begin(), weights.end(), 0);
         while(low < high){
            int mid=low+(high-low)/2;
            if(canShip(weights,mid,days)){
                high=mid;
            }
            else{
                low=mid+1;
            }
         }  
         return low;
    }
};