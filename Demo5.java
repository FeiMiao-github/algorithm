//  存在重复
public class Demo5 {
    public static boolean containsDuplicate(int[] nums) {
    	if (nums.length < 2) return false;
        for (int i = 0; i < nums.length; i++) {
        	for (var j = i + 1; j < nums.length; j++) {
        		if (nums[i] == nums[j]) return true;
        	}
        }
        
        return false;
    }// 443ms O(n^2)
    
    public static boolean containsDuplicate2(int[] nums) {
         for (int i = 1; i < nums.length;i++){
            int j = i - 1; // 0 // 从i-1 -> 
            int temp = nums[j+1]; // num[i] > num[j+1] [交换位置]
            while (j >= 0 && nums[j] > temp){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = temp;
            if (j >= 0 && nums[j] == nums[j+1]){
                return true;
            }
        }
        return false;
    }// 8ms
}
