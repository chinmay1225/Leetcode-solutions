class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int high = *max_element(nums.begin() , nums.end());

        while(left < high){
            int mid = left + (high-left)/2;

            int sum=0;
            for(int num: nums){
                sum += ceil((double)num/mid);
            }

            if(sum <= threshold){
                high = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};