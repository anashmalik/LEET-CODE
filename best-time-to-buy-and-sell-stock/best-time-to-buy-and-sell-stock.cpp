class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int ans=0,by=INT_MAX;
        for(int i=0;i<prices.size();i++){
            by=min(by,prices[i]);
            ans=max(ans,prices[i]-by);
        }
        return ans;
    }
};