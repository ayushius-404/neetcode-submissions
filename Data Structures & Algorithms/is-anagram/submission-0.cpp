class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);

        for(char x : s){
            freq[x - 'a']++;
        }

        for(char x : t){
            freq[x - 'a']--;
        }

        for(int f : freq){
            if(f != 0)
                return false;
        }
        return true;
    }
};
