
public class Prob19 {
	public static void main(String[] args) {
		int num = 210409; // numは残しておきたいprintもする
		int tmp = num;
		int sum = 0;
		while (tmp > 0) {
			sum += (tmp % 10);
			tmp /= 10;
		}
		
		if (num % sum == 0) {
			System.out.println("This num is a Harshad number.");
		} else {
			System.out.println("This num isn't a Harshad number.");
		}
	}

}
