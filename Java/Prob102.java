
public class Prob102 {
	public static void main(String[] args) {
		(new Object() {
			void turnOn() {
				System.out.println("Let's watch!");
			}
		}).turnOn();
	}
}
