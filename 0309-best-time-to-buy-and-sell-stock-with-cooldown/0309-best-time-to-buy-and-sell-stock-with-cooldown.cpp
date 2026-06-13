class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;

        int buy=-prices[0];
        int sell=0;
        int cooldown=0;

        for(int i=1;i<n;i++){
            int prevbuy=buy;
            int prevsell=sell;
            int prevcool=cooldown;

            buy=max(prevbuy,prevcool-prices[i]);
            sell=buy+prices[i];
            cooldown=max(prevcool,prevsell);
        }
        return max(sell,cooldown);
    }
};