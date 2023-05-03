
public class Prob74 {
	public static void main(String[] args) {
		if(args.length == 0) {
			System.out.println("No numbers!");
			return;
		}
		
		for(int i = 0; i < args.length; i++) {
			String s = "";
			int s1 = 0;
			int s2 = 0;
			int tmp = 0;
			
			for(int j = args[i].length() - 1; j >= 0; j--) {
				char element = args[i].charAt(j);
				s += element;
			}
			
			for(int k = 0; k < s.length(); k++) {
				if(k % 2 == 0) {
					// if odd number
					s1 += Integer.valueOf(s.substring(k, k+1));
				} else {
					// if even number
					tmp = 2 * Integer.valueOf(s.substring(k, k+1));
					if(tmp < 10) {
						s2 += tmp;
					} else {
						s2 += 1 + tmp % 10;
					}
				}
			}
			System.out.print(args[i] + " ");
			System.out.print(s1 + s2 + " ");
			if((s1 + s2) % 10 == 0) {
				System.out.println("Good");
			} else {
				System.out.println("Bad");
			}
		}
		
		return;
	}
}
