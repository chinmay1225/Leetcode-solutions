class Solution {
private:
    bool isPossible(int capacity, vector<int>& weights, int days){
        int daysUsed = 1;
        int currentLoad = 0;

        for(int i=0; i<weights.size(); i++){
            if(currentLoad + weights[i] <= capacity){
                currentLoad += weights[i];
            }else{
                daysUsed++;
                currentLoad = weights[i];
            }
        }
        return (daysUsed <= days);
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin() , weights.end());
        int high = 0;
        for(int i=0; i<weights.size(); i++){
            high += weights[i];
        }

        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(mid , weights , days)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};