class Solution {
private:
    bool isPossible(vector<int>& nums , int k , long long sum){
        int intCnt = 1;
        int subarraySum = 0;
        for(int i=0; i<nums.size(); i++){
            if(subarraySum+nums[i] <= sum){
                subarraySum += nums[i];
            }else{
                intCnt++;
                subarraySum = nums[i];
            }
        }
        return (intCnt <= k);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if( k > nums.size()){
            return -1;
        }
        long long low = *max_element(nums.begin() , nums.end());
        long long high = 0;
        for(int i=0; i<nums.size(); i++){
            high += nums[i];
        }

        int ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;

            if(isPossible(nums , k , mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};