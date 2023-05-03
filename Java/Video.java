import java.util.*;

public class Video {
	
	private String title;
	private int restNum;
	private int borrowedNum;
	private ArrayList<String> borrowed = new ArrayList<String>();
	
	
	public Video(String title, int rest) {
		this.title = title;
		this.restNum = rest;
		this.borrowedNum = 0;
	}
	
	public String getTitle() {
		return this.title;
	}
	
	public void setTitle(String str) {
		this.title = str;
	}
	
	public int getRestNum() {
		return this.restNum;
	}
	
	public void setRest(int num) {
		this.restNum = num;
	}
	
	public int getBorrowedNum() {
		return this.borrowedNum;
	}
	
	public void rentCalc() {
		this.restNum--;
		this.borrowedNum++;
	}
	
	public void returnCalc() {
		this.restNum++;
		this.borrowedNum--;
	}
	
	
	public Iterator<String> getBorrowed() {
		return this.borrowed.listIterator();
	}
	
	public void addBorrowed(String name) {
		this.borrowed.add(name);
	}
	
	public void removeBorrowed(String name) {
		this.borrowed.remove(name);
	}
}
