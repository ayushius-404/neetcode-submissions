class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }

        for(auto x : mp){
            if(x.second >= 2)
                return true;
        }

        return false;
    }
};