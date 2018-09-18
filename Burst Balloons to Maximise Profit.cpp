class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int length = nums.size(); 
        vector<int> nums_t(length + 2, 1);
        vector<vector<int>> dp(length + 2, vector<int>(length + 2, 0));
        
        for(int i = 1; i <= length; ++i)
            nums_t[i] = nums[i-1];
        
        for(int l = 1; l <= length; ++l) {
            for(int i = 1; i <= length - l + 1; ++i) {
                int j = i + l - 1;
                int max_ans = max(nums_t[i-1] * nums_t[i] * nums_t[j+1] + dp[i+1][j], nums_t[i-1] * nums_t[j] * nums_t[j+1] + dp[i][j-1]);
                
                for(int k = i + 1; k < j; ++k)
                    max_ans = max(max_ans, nums_t[i-1] * nums_t[k] * nums_t[j+1] + dp[i][k-1] + dp[k+1][j]);
            
                dp[i][j] = max_ans;
            }
        }
    
        return dp[1][length];
    }
};
