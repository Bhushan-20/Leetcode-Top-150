#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>  // For rand()

using namespace std;

class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> map;

    RandomizedSet() {
        v.clear();
        map.clear();
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        int i = map[val];
        int lastElement = v.back();
        v[i] = lastElement;
        map[lastElement] = i;
        v.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int i = rand() % v.size();
        return v[i];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << endl;    // Output: 1 (true)
    cout << obj->insert(2) << endl;    // Output: 1 (true)
    cout << obj->remove(1) << endl;    // Output: 1 (true)
    cout << obj->insert(2) << endl;    // Output: 0 (false)
    cout << obj->getRandom() << endl;  // Output: 2 (since only 2 is in the set)
    
    delete obj;
    return 0;
}
