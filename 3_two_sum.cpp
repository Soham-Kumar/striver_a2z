// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Brute force solution
// Traverses every element for every element and checks if the sum matches
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v(2);
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i]+nums[j] == target){
                v[0] = i;
                v[1] = j;
            }
        }
    }
    return v;
}


// Better solution
// Creating a hashmap, then checking if the (sum - current element) is present
vector<int> twoSum(vector<int>& nums, int target) {

}
// Best Solution
// Previous solution, but you don't need to initialise the hashmap at once in starting
