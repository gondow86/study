import java.util.ArrayList;
import java.util.Random;
public class Prob75 {
	public static void main(String[] args) {
		Random rand = new Random();
		ArrayList<Integer> list = new ArrayList<Integer>();
		int a = 0;
		int b = 0;
		
		if(args.length == 0) {
			System.out.println("No numbers!");
			
			return;
		}
		
		if(args[0].equals("0")) {
			System.out.println("Not valid!");
			
			return;
		}
		
		for(int i = 0; i < Integer.valueOf(args[0]); i++) {
			int num = rand.nextInt(10);
			list.add(num);
			System.out.print(num);
		}
		System.out.println();
		
		if(list.size() % 2 != 0) {
			list.remove(list.size() - 1);
		}
		
		// list size is already even num
		for(int i = 0; i < (list.size() / 2); i++) {
			a = list.get(2 * i);
			b = list.get(2 * i + 1);
			
			if(a >= b) {
				list.set(2 * i, -1);
				list.set(2 * i + 1, -1);
			}
		}
		
		// remove from tail
		for(int i = list.size() - 1; i >= 0; i--) {
			a = list.get(i);
			if(a == -1) {
				list.remove(i);
			}
		}
		
		for(int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i));
		}
		
		return;
	}
}
