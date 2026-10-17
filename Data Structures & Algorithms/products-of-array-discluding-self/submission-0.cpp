class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++){
            if(i == 0) 
                f[i] = nums[i];
            else
                f[i] = nums[i] * f[i-1];
        }

        for(int j = n-1; j >= 0; j--){
            if(j == n-1) 
                b[j] = nums[j];
            else
                b[j] = nums[j] * b[j+1];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if(i == 0){
                ans[i] = b[i+1];
            }
            else if(i == n-1){
                ans[i] = f[n-2];
            }
            else
                ans[i] = f[i-1] * b[i+1];
        }

        return ans;
    }
};
