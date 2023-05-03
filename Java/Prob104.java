import javax.swing.*; 
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Prob104 {
  private JLabel label;
  private String str = "";
  private ArrayList<String> list = new ArrayList<String>();
  private int ans = 0;
  
  void clear() { // initialize variables
	  str = "";
	  list.clear();
	  ans = 0;
  }
  
  void calc() {
	  String s = "";
	  try {
		  for (int i = 0; i < list.size(); i++) {
			  s = list.get(i);
			  if (i == 0) {
				  ans = Integer.valueOf(s);
			  }
			  if (s.equals("+")) {
				  ans += Integer.valueOf(list.get(i+1));
			  } else if (s.equals("-")) {
				  ans -= Integer.valueOf(list.get(i+1));
			  } else if (s.equals("*")) {
				  ans *= Integer.valueOf(list.get(i+1));
			  } else if (s.equals("/")) {
				  ans /= Integer.valueOf(list.get(i+1));
			  }
		  }
	  } catch (NumberFormatException e) {
		  System.err.println(e.toString());
	  } catch (ArithmeticException e) {
		  System.err.println(e.toString());
	  }
	  
	  label.setText(Integer.toString(ans));
  }
  
  
  class ButtonAction implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      String temp = e.getActionCommand();
      if (!(temp.equals("="))) {
    	  str += e.getActionCommand(); //get string of button!
      }
      if (temp.equals("=")) {
    	  calc();
//    	  clear();
    	  return;
      } else if (temp.equals("C")) {
    	  clear();
    	  label.setText("0");
    	  return;
      } else if (temp.equals("-")) {
    	  if (list.size() == 0) { // ex. -1 + 2
    		  label.setText(temp);
    		  return;
    	  } else if(list.get(list.size() - 1).equals("+")) { // ex. 1 + -2
    		  label.setText(temp);
    		  return;
		  } else if(list.get(list.size() - 1).equals("-")) { // ex. 1 - -2
			  label.setText(temp);
    		  return;
		  } else if(list.get(list.size() - 1).equals("*")) { // ex. 1 * -2
			  label.setText(temp);
    		  return;
		  } else if(list.get(list.size() - 1).equals("/")) { // ex. 1 / -2
			  label.setText(temp);
    		  return;
		  } else {
			  list.add(str);
		      label.setText(temp);
		      str = "";
		      return;
		  }
      } else if (temp.equals("+")) {
    	  if (list.size() == 0) { // ex. +1 + 2
    		  label.setText(temp);
    		  return;
    	  } else if(list.get(list.size() - 1).equals("+")) { // ex. 1 + +2
    		  label.setText(temp);
    		  return;
		  } else if(list.get(list.size() - 1).equals("-")) { // ex. 1 - +2
			  label.setText(temp);
    		  return;
		  } else if(list.get(list.size() - 1).equals("*")) { // ex. 1 * +2
			  label.setText(temp);
    		  return;
		  } else if(list.get(list.size() - 1).equals("/")) { // ex. 1 / +2
			  label.setText(temp);
    		  return;
		  } else {
			  list.add(str);
		      label.setText(temp);
		      str = "";
		      return;
		  }
      } else {
	      list.add(str);
	      label.setText(temp);
	      str = "";
	      return;
      }
    }
  }

  public Component createComponents() {
    JButton button7 = new JButton("7");
    JButton button8 = new JButton("8");
    JButton button9 = new JButton("9");
    JButton buttonDiv = new JButton("/");
    JButton button4 = new JButton("4");
    JButton button5 = new JButton("5");
    JButton button6 = new JButton("6");
    JButton buttonMulti = new JButton("*");
    JButton button1 = new JButton("1");
    JButton button2 = new JButton("2");
    JButton button3 = new JButton("3");
    JButton buttonMinus = new JButton("-");
    JButton button0 = new JButton("0");
    JButton buttonC = new JButton("C");
    JButton buttonEqual = new JButton("=");
    JButton buttonPlus = new JButton("+");

    ButtonAction buttonListener = new ButtonAction();
    button7.addActionListener( buttonListener );
    button8.addActionListener( buttonListener );
    button9.addActionListener( buttonListener );
    buttonDiv.addActionListener( buttonListener );
    button4.addActionListener( buttonListener );
    button5.addActionListener( buttonListener );
    button6.addActionListener( buttonListener );
    buttonMulti.addActionListener( buttonListener );
    button1.addActionListener( buttonListener );
    button2.addActionListener( buttonListener );
    button3.addActionListener( buttonListener );
    buttonMinus.addActionListener( buttonListener );
    button0.addActionListener( buttonListener );
    buttonC.addActionListener( buttonListener );
    buttonEqual.addActionListener( buttonListener );
    buttonPlus.addActionListener( buttonListener );
    
    JPanel metaPane = new JPanel();
    metaPane.setBorder(BorderFactory.createEmptyBorder( 30, 30, 10, 30 ));
    metaPane.setLayout(new GridLayout(0, 1));
    label = new JLabel("Please push buttons!");
    label.setBackground(Color.white);
    label.setOpaque(true);
    metaPane.add(label);
    
    JPanel pane = new JPanel();
    pane.setLayout(new GridLayout(4, 4));
    pane.add(button7);
    pane.add(button8);
    pane.add(button9);
    pane.add(buttonDiv);
    pane.add(button4);
    pane.add(button5);
    pane.add(button6);
    pane.add(buttonMulti);
    pane.add(button1);
    pane.add(button2);
    pane.add(button3);
    pane.add(buttonMinus);
    pane.add(button0);
    pane.add(buttonC);
    pane.add(buttonEqual);
    pane.add(buttonPlus);
    
    metaPane.add(pane);
    
    return metaPane;
  }

  public static void main(String[] args) {
    JFrame frame = new JFrame("Caluculator");
    Prob104 app = new Prob104();
    Component contents = app.createComponents();

    frame.getContentPane().add(contents);

    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.pack();
    frame.setVisible(true);
  }
}
