
public class Prob87 {
	public static void main(String[] args) {
		try {
			int price = Integer.valueOf(args[0]);
			int sum = 0;
			int remainingA, remainingB, remainingC, remainingD, remainingE, remainingF;
			int counter = 0;
			int a, b, c, d, e, f;
			
			remainingA = price;
			for(a = 0; a <= remainingA / 500; a++) {
				remainingB = price - 500 * a;
				for(b = 0; b <= remainingB / 100; b++) {
					remainingC = price - (500 * a + 100 * b);
					for(c = 0; c <= remainingC / 50; c++) {
						remainingD = price - (500 * a + 100 * b + 50 * c);
						for(d = 0; d <= remainingD / 10; d++) {
							remainingE = price - (500 * a + 100 * b + 50 * c + 10 * d);
							for(e = 0; e <= remainingE / 5; e++) {
								remainingF = price - (500 * a + 100 * b + 50 * c + 10 * d + 5 * e);
								for(f = 0; f <= remainingF; f++) {
									sum = 500 * a + 100 * b + 50 * c + 10 * d + 5 * e + 1 * f;
									if(sum == price) {
										counter++;
									} 
								}
							}
						}
					}
				}
			}
			
			System.out.println(counter);
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("No amount specified");
		} catch(NumberFormatException e) {
			System.out.println("Please input Integers.");
		}
	}
}
