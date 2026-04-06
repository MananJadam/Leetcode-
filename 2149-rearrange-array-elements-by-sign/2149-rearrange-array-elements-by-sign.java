class Solution {
    public int[] rearrangeArray(int[] nums) {
        Queue<Integer> pos = new LinkedList<>();
        Queue<Integer> neg = new LinkedList<>();
        for (int i : nums) {
            if (i > 0) {
                pos.add(i);
            } else {
                neg.add(i);
            }
        }
        for(int i=0;i<nums.length;i++){
            if(!pos.isEmpty() && i%2==0){
                nums[i]=pos.poll();
            }
            else if(!neg.isEmpty()){
                nums[i]=neg.poll();
            }
        }
        return nums;
    }
}