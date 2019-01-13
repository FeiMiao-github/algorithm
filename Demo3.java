//卖股票的最佳时机 II
public class Demo3 {
    public static int maxProfit(int[] prices) {
    	int ret = 0;
    	
    	for (int i = 1; i < prices.length; i++) {
    		if (prices[i-1] < prices[i]) {
    			ret += (prices[i] - prices[i-1]); 
    		}
    	}
    	
    	return ret;
    }
}
