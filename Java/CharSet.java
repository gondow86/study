
public class CharSet {
	private char[] array;
	
	void init() {
		array = new char[] {'0', '0', '0', '0'};
	}
	
	int count() {
		int count = array.length;
		for (int i = 0; i < array.length; i++) {
			if (array[i] == '0') {
				count--;
			}
		}
		
		return count;
	}
	
	boolean search(char x) {
		for (int i = 0; i < array.length; i++) {
			if (x == array[i]) {
				return true;
			}
		}
		
		return false;
	}
	
	void add(char x) {
		if (search(x) == true) {
			return;
		} else if (count() == array.length) {
			char[] b = new char[array.length + 1]; // increase array size
			for (int i = 1; i < array.length + 1; i++) {
				b[i] = array[i - 1]; // copy
			}
			b[0] = x; // add x
			array = b;
			return;
		} else if (count() != array.length) {
			for (int i = 0; i < array.length; i++) {
				if (array[i] == '0') {
					array[i] = x;
					return;
				}
			}
		}
	}
	
	void remove(char x) {
		for (int i = 0; i < array.length; i++) {
			if (array[i] == x) {
				array[i] = '0';
			}
		}
	}
}
