public class Demo2 {
//	 从排序数组中删除重复项
    public static int removeDuplicates(int[] nums) {
    	int index = 0;
        for (int i = 1; i < nums.length; i++) {
        	if (nums[i] != nums[index]) {
        		nums[++index] = nums[i];
        	}
        }
        
        return index + 1;
    }
}
