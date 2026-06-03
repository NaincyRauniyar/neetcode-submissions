class KthLargest {
public:
int n;
priority_queue<int,vector<int>,greater<int>> minh;

    KthLargest(int k, vector<int>& nums) {
        n =k;
        for(auto x:nums){
        minh.push(x);
        if(minh.size()>k){
            minh.pop();
        }
        }
    }
    
    int add(int val) {
     minh.push(val);
     if(minh.size()>n){
        minh.pop();
     }   
     return minh.top();
    }
};
