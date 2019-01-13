	public class Demo1 {
		public static int gcd(int a, int b) {
			if (b == 0) return a;
			System.out.println("b\t" + b + ", a:" + a);
			return gcd(b, (a % b));
		}
	}