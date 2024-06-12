// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
// Return the maximum possible frequency of an element after performing at most k operations.

// New concept used: Sliding Window
// Fundamentally: 1. first sort the array; 2. use a condition on maximizing the size of the window (which covers the same elements) keeping in consideration k.
// Neetcode solution: https://youtu.be/vgBrQ0NM5vE?si=TnPuNwFch_xi1Y_6

int maxFrequency(vector<int>& nums, int k) {
    
    sort(nums.begin(), nums.end());

    // left and right pointers
    // maxFreq (to be returned) and total of the numbers inside the sliding window
    long long int l = 0, r = 0;
    long long int maxFreq = 0, total = 0;

    while(r < nums.size()){
        total += nums[r];
        while(nums[r]*(r-l+1) > total+k){
            total-=nums[l];
            l++;
        }
        maxFreq = max(maxFreq, r-l+1);
        r++;
    }
    return maxFreq;
}
