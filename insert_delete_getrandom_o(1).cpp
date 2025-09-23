class RandomizedSet {
    unordered_map<int, int> table;
    vector<int> data;
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(table.count(val))
            return false;

        table[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(table.count(val) == 0)
            return false;
        
        int idx = table[val];
        int last = data.size() - 1;
        swap(data[idx], data[last]);
        table[data[idx]] = idx;
        data.pop_back();
        table.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % data.size();
        return data[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
