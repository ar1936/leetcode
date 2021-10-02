class ParkingSystem {
    int a, b, c;
    
public:
    ParkingSystem(int big, int medium, int small) {
        this->a=big;
        this->b=medium;
        this->c=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(a==0)
                return false;
            else
                a--;
        }
        else if(carType==2){
            if(b==0)
                return false;
            else
                b--;
        }
        else if(carType==3){
            if(c==0)
                return false;
            else
                c--;
        }
        return true;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */