class Solution {
    public int[] twoSum(int[] nums, int target) {

        Map<Integer, Integer> res = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];

            if (res.containsKey(diff)) {
                return new int[] { res.get(diff), i };
            }

            res.put(nums[i], i);
        }

        return new int[] { -1, -1 }; // No solution.
    }
}