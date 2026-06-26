class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m = nums2.size();
        int i=0,j=0,cnt=0;
        int p =n+m;
        int ind2=p/2;
        int ind1=ind2-1;
        int indel1=-1,indel2=-1;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) indel1 = nums1[i];
                if(cnt==ind2) indel2 = nums1[i];
                cnt++;i++;

            }
            else{
                 if(cnt==ind1) indel1 = nums2[j];
                if(cnt==ind2) indel2 = nums2[j];
                cnt++;j++;
            }
        }
        while(i<n){
             if(cnt==ind1) indel1 = nums1[i];
                if(cnt==ind2) indel2 = nums1[i];
                cnt++;i++;
        }
        while(j<m){
             if(cnt==ind1) indel1 = nums2[j];
                if(cnt==ind2) indel2 = nums2[j];
                cnt++;j++;
        }
        if (p%2==1){
            return indel2;
        }
        else
        return (double)((double)(indel1+indel2))/2.0;
    }
};