class Solution {
public:
//we will use slow an dfast pinter ...Why and how as it is not a LL
//ponter will point to val anf the val to the ind this way 
//and when we get cycle and s==f then just put slow again at start and move the intersection point and slow by one place each once they meet that is the ans 
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast =nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast ==slow) break;
        }
        int new_slow = nums[0];
        while(slow != new_slow){
            slow = nums[slow];
            new_slow = nums[new_slow];
        }
        return slow;
    }
};