class LFUCache {
public:
    int cap, minFreq;
    
    unordered_map<int, pair<int,int>> keyValFreq; 
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIter;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cap == 0 || keyValFreq.find(key) == keyValFreq.end())
            return -1;

        int value = keyValFreq[key].first;
        int freq  = keyValFreq[key].second;

        // Remove key from old frequency list
        freqList[freq].erase(keyIter[key]);

        // If this was the last key with minFreq, update minFreq
        if (freqList[freq].empty() && freq == minFreq)
            minFreq++;

        // Increase frequency
        freq++;
        keyValFreq[key].second = freq;

        // Add key to new frequency list
        freqList[freq].push_front(key);
        keyIter[key] = freqList[freq].begin();

        return value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // If key already exists → update value + frequency
        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            get(key); // reuse get() to update frequency
            return;
        }

        // If cache is full → remove LFU key
        if (keyValFreq.size() == cap) {
            int lfuKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValFreq.erase(lfuKey);
            keyIter.erase(lfuKey);
        }

        // Insert new key with frequency = 1
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};
