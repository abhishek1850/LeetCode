class Solution {

    void count(vector<int>& s, string str) {
        for (auto i : str) {
            s[i - 'a']++;
        }
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map<vector<int>,vector<string>>mp;
        // for(auto i:strs){
        //   vector<int>freq(26,0);
        //   count(freq,i);
        //   mp[freq].push_back(i);
        // }

        // vector<vector<string>>ans;
        // for(auto i:mp){
        //   ans.push_back(i.second);
        // }
        // return ans;
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            vector<int> freq(26, 0);
            count(freq, s);

            string key = "";
            for (int i : freq) {
                key += to_string(i) + "#";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};