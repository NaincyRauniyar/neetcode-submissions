class Solution {
public:
   int trap(vector<int>& height) {
        int n = height.size();
        //two pinters
        int left =0;
        int right = n-1;
        //to track the max of both sides
        int l_max = height[left];
        int r_max = height[right];
        int water =0;
        while(left < right){
            if(l_max < r_max){
                left++;
                l_max = max(l_max, height[left]);
                water += l_max -height[left];
            }
            else{
                right--;
                r_max = max(r_max , height[right]);
                water += r_max - height[right];
            }
        }
        return water;
    }
};