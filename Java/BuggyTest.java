import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class BuggyTest {
	private Buggy bug = new Buggy();

	@Test
	void isTrue() {
		int[] primeNum = new int[] {2, 3, 5, 7, 11};
		boolean result;
		for(int i = 0; i < primeNum.length; i++) {
			result = bug.isPrime(primeNum[i]);
			assertTrue(result);
		}
	}

	@Test
	void isFalse() {
		int[] nonPrimeNum = new int[] {-3, -2, -1, 0, 1, 4, 6, 8, 9, 10};
		boolean result;
		for (int i = 0; i < nonPrimeNum.length; i++) {
			result = bug.isPrime(nonPrimeNum[i]);
			assertFalse(result);
		}

	}

}
