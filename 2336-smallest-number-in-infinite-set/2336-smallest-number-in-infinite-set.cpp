class SmallestInfiniteSet {
public:
    set<int>popped;
    int pointer;
    SmallestInfiniteSet() {
        pointer = 1;
    }
    
    int popSmallest() {
        int  p = pointer;
        popped.insert(p);
        pointer++;
        while(popped.count(pointer)){
            pointer++;
        }
        return p;
    }
    
    void addBack(int num) {
        if(popped.count(num)){
            if(num < pointer){
                pointer = num;
            }
            popped.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */