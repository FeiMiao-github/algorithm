import java.util.Arrays;

//旋转数组
public class Demo4 {
    public static void rotate(int[] nums, int k) {
    	k %= nums.length;
        int[] flag = new int[k];

        for (int i = nums.length; i > 0; i--) {
    		if (nums.length - i < k) {
    			flag[k - nums.length + i - 1] = nums[i - 1]; 
    		}
    		
        	if (i > k) {
        		nums[i - 1] = nums[i - 1 - k];
        	} else {
        		nums[i - 1] = flag[i - 1];
        	}
		}
        
        System.out.println(Arrays.toString(nums));
    }
}

// 1 2 3 4    |        5 6 --> 5 6 | 1 2 3 4 