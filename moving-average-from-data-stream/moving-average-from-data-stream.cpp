class MovingAverage {
    vector<int>v;
    int Total_size=0;
    double sum;
public:
    MovingAverage(int size) {
        this->Total_size=size;
    }
    
    double next(int val) {
        v.push_back(val);
        sum+=v.back();
        if(Total_size<v.size()){
            sum-=v[v.size()-Total_size-1];
            return double(sum/Total_size);
        }        
        return double(sum/v.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */