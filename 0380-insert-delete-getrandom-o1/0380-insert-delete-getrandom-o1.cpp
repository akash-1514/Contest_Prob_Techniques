class RandomizedSet {
public:
    unordered_map<int, int>mp;
    vector<int> vec;
    int idx = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        mp[val] = idx++;
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            int idx2 = mp[val];
            mp[vec[idx - 1]] = idx2;
            swap(vec[idx - 1], vec[idx2]);
            mp.erase(val);
            vec.pop_back();
            idx--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randIdx = rand() % idx;
        return vec[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */