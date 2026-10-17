class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int,int>>
            > minHeap;
        
        for(auto x : freq){
            int n = x.first;
            int f = x.second;

            if(minHeap.size() < k)
                minHeap.push({f, n});

            else{
                auto top = minHeap.top();
                if(top.first < f){
                    minHeap.pop();
                    minHeap.push({f, n});
                }
            } 
        }

        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
