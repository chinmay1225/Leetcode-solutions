class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int curr = 1;
        int i = 0;

        while(k > 0){
            if(i < n && arr[i] == curr){
                i++;
            }else{
                k--;
            }
            curr++;
        }
        return curr-1;
    }
};