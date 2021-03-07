class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int count = 0;
        for (int i = 0; i < stones.length(); i++) {
            String cur_stone = String.valueOf(stones.charAt(i));
            if (jewels.contains(cur_stone)) {
                count += 1;
            }
        }
        return count;
    }
}
