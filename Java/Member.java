import java.util.*;

public class Member {
	private String name;
	private int id;
	private static int id_count;
	private ArrayList<String> borrowing = new ArrayList<String>();
	
	public Member(String name) {
		this.name = name;
		Member.id_count++;
		this.id = Member.id_count;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String str) {
		this.name = str;
	}
	
	public int getId() {
		return this.id;
	}
	
	public void setId(int num) {
		this.id = num;
	}
	
	public Iterator<String> getBorrowing() {
		return this.borrowing.listIterator();
	}
	
	public void addBorrowing(String title) {
		this.borrowing.add(title);
	}
	
	public void removeBorrowing(String title) {
		this.borrowing.remove(borrowing.indexOf(title));
	}
}
