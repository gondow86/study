
public class Prob64 {
	public static void main(String[] args) {
		int ans = 1;
		
		for(int i = 0; i < args.length; i++) {
			ans *= Integer.valueOf(args[i]);
		}
		
		System.out.println(ans);
	}
}
