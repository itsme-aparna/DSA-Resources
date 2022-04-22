class MyHashMap {
    list< pair<int, int> > *l;
    int size;
    
    int calcHash(int key)
    {
        return (key % size);
    }
public:
    
    MyHashMap() {
        size = 100;
        l = new list< pair<int, int> >[size];
    }

    
    void put(int key, int value) {
    
            int k = calcHash(key);
        
            auto it = l[k].begin();
        
            while(it != l[k].end())
            {
                if(it->first == key)
                {
                    it->second = value;
                    return;
                }
                it++;
            }
        
            l[k].push_back({key, value});
        
    }
   
    int get(int key) {
        
        int k = calcHash(key);
        
        auto it = l[k].begin();
        
        while(it != l[k].end())
        {
            if(it->first == key)
                return it->second;
            it++;
        }
    
        return -1;
        
    }
    
    void remove(int key) {
        int k = calcHash(key);
        auto it = l[k].begin();
        while(it != l[k].end())
        {
            if(it->first == key)
            {
               l[k].erase(it);
               break;
            }
            
            it++;
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */