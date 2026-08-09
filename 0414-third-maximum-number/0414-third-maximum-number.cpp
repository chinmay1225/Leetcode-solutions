class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = 0;
        long long second = 0;
        long long third = 0;

        int count = 0;

        for (int x : nums) {
            long long num = x;

            if (count == 0) {
                first = num;
                count = 1;
            }
            else if (num == first) {
                continue;
            }
            else if (count == 1) {
                if (num > first) {
                    second = first;
                    first = num;
                } else {
                    second = num;
                }
                count = 2;
            }
            else if (num == second) {
                continue;
            }
            else if (count == 2) {
                if (num > first) {
                    third = second;
                    second = first;
                    first = num;
                }
                else if (num > second) {
                    third = second;
                    second = num;
                }
                else {
                    third = num;
                }
                count = 3;
            }
            else {
                if (num == third) {
                    continue;
                }

                if (num > first) {
                    third = second;
                    second = first;
                    first = num;
                }
                else if (num > second) {
                    third = second;
                    second = num;
                }
                else if (num > third) {
                    third = num;
                }
            }
        }

        return count < 3 ? first : third;
    }
};