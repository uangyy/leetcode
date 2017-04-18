ass Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, vector<int>> store;
        int r1, r2;
        for (int i = 0; i < nums.size(); ++i)
        {
            store[nums[i]].push_back(i);
            if (store[nums[i]].size() == 2 && nums[i] * 2 == target)
            {
                res.push_back(store[nums[i]][0]);
                res.push_back(store[nums[i]][1]);
                return res;
            }
        }

        for (unordered_map<int, vector<int>>::iterator it = store.begin(); it != store.end(); ++it)
        {
            if (store.find(target - it->first) != store.end() && store.find(target - it->first) != it)
            {
                r1 = it->second[0];
                r2 = store.find(target - it->first)->second[0];
                break;
            }
        }
        res.push_back(min(r1, r2));
        res.push_back(max(r1, r2));
        return res;
    }
};
