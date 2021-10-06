class MyHashMap {
    int arr[]=new int[1000000+1];
    public MyHashMap() {
        for(int i=0;i<=1000000;i++){
            arr[i]=-1;
        }
    }
    
    public void put(int key, int value) {
        arr[key]=value;
    }
    
    public int get(int key) {
        if(arr[key]==-1)
            return -1;
        return arr[key];
    }
    
    public void remove(int key) {
        arr[key]=-1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */