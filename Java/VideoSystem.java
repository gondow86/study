import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;


public class VideoSystem {
	private JTextField[] fields;
	private JTextArea[] areas;
	private ArrayList<Member> members = new ArrayList<Member>();
	private ArrayList<Video> videos = new ArrayList<Video>();
	
	private DefaultListModel<String> memberNameModel;
	private DefaultListModel<Integer> memberIdModel;
	private JList<String> memberNameList;
	private JList<Integer> memberIdList;
	
	private DefaultListModel<String> videoNameModel;
	private DefaultListModel<Integer> videoRestNumModel;
	private DefaultListModel<Integer> videoBorNumModel;
	private JList<String> videoNameList;
	private JList<String> videoNameList2;
	private JList<Integer> videoRestNumList;
	private JList<Integer> videoRestNumList2;
	private JList<Integer> videoBorNumList;
	private JList<Integer> videoBorNumList2;

	// for card.show() in each actionPerformed()
	private CardLayout card;
	private JPanel controlPane;
	private JPanel homePane;
	private JPanel memberInfoPane;
	private JPanel videoInfoPane;
	private JPanel rentPane;
	private JPanel checkPane;

	
	public Component createComponents() {
		// set Text field and area
		fields = new JTextField[6];
		for(int i = 0; i < 6; i++) {
			fields[i] = new JTextField();
		}
		fields[0].setText("Input member's name"); // member info
		fields[1].setText("Input video's title"); // video info
		fields[2].setText("Input video's number"); // video info
		fields[3].setText("Input member's ID");
		fields[4].setText("Input video's title");
		fields[5].setText("Input member's ID");
		fields[1].setPreferredSize(new Dimension(280, 20));
		fields[2].setPreferredSize(new Dimension(280, 20));
		fields[4].setPreferredSize(new Dimension(280, 20));
		fields[5].setPreferredSize(new Dimension(280, 20));
		
		areas = new JTextArea[2];
		for(int i = 0; i < 2; i++) {
			areas[i] = new JTextArea();
			areas[i].setLineWrap(true);
		}
		
		
		// control panel setting
		card = new CardLayout();
		controlPane = new JPanel();
		controlPane.setLayout(card);

		// home panel setting
		homePane = new JPanel();
		homePane.setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));
		GridLayout grid = new GridLayout(2, 2);
		homePane.setLayout(grid);

		// sub panels setting
		memberInfoPane = new JPanel();
		memberInfoPane.setBorder(BorderFactory.createEmptyBorder(30, 10, 30, 10));
		memberInfoPane.setLayout(new BoxLayout(memberInfoPane, BoxLayout.Y_AXIS));
		JPanel labelPane1 = new JPanel();
		JPanel subPane1 = new JPanel();
		JPanel subPane2 = new JPanel();
		JPanel subPane3 = new JPanel();
		labelPane1.setBorder(BorderFactory.createEmptyBorder(20, 20, 0, 20));
		subPane1.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane1.setLayout(new BoxLayout(subPane1, BoxLayout.X_AXIS));
		subPane2.setBorder(BorderFactory.createEmptyBorder(0, 20, 20, 20));
		subPane2.setLayout(new BoxLayout(subPane2, BoxLayout.X_AXIS));
		subPane3.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane3.setLayout(new BoxLayout(subPane3, BoxLayout.X_AXIS));
		
		videoInfoPane = new JPanel();
		videoInfoPane.setBorder(BorderFactory.createEmptyBorder(30, 10, 30, 10));
		videoInfoPane.setLayout(new BoxLayout(videoInfoPane, BoxLayout.Y_AXIS));
		JPanel labelPane2 = new JPanel();
		JPanel subPane4 = new JPanel();
		JPanel subPane5 = new JPanel();
		JPanel subPane6 = new JPanel();
		JPanel subPane7 = new JPanel();
		labelPane2.setBorder(BorderFactory.createEmptyBorder(20, 0, 0, 20));
		subPane4.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane4.setLayout(new BoxLayout(subPane4, BoxLayout.X_AXIS));
		subPane5.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane6.setBorder(BorderFactory.createEmptyBorder(0, 20, 20, 20));
		subPane6.setLayout(new BoxLayout(subPane6, BoxLayout.X_AXIS));
		subPane7.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane7.setLayout(new BoxLayout(subPane7, BoxLayout.X_AXIS));
		
		
		rentPane = new JPanel();
		rentPane.setBorder(BorderFactory.createEmptyBorder(30, 10, 30, 10));
		rentPane.setLayout(new BoxLayout(rentPane, BoxLayout.Y_AXIS));
		JPanel subPane8 = new JPanel();
		JPanel subPane9 = new JPanel();
		JPanel subPane10 = new JPanel();
		subPane8.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane8.setLayout(new BoxLayout(subPane8, BoxLayout.X_AXIS));
		subPane9.setBorder(BorderFactory.createEmptyBorder(20, 20, 0, 20));
		subPane10.setBorder(BorderFactory.createEmptyBorder(5, 20, 20, 20));
		subPane10.setLayout(new BoxLayout(subPane10, BoxLayout.X_AXIS));
		
		checkPane = new JPanel();
		checkPane.setBorder(BorderFactory.createEmptyBorder(30, 10, 30, 10));
		checkPane.setLayout(new BoxLayout(checkPane, BoxLayout.Y_AXIS));
		JPanel labelPane3 = new JPanel();
		JPanel subPane11 = new JPanel();
		JPanel subPane12 = new JPanel();
		JPanel subPane13 = new JPanel();
		labelPane3.setBorder(BorderFactory.createEmptyBorder(20, 0, 0, 0));
		subPane11.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane11.setLayout(new BoxLayout(subPane11, BoxLayout.X_AXIS));
		subPane12.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
		subPane13.setBorder(BorderFactory.createEmptyBorder(0, 20, 20, 20));
		subPane13.setLayout(new BoxLayout(subPane13, BoxLayout.X_AXIS));

		// control panel add
		controlPane.add(homePane);
		controlPane.add(memberInfoPane);
		controlPane.add(videoInfoPane);
		controlPane.add(rentPane);
		controlPane.add(checkPane);

		card.addLayoutComponent(memberInfoPane, "memberInfo");
		card.addLayoutComponent(videoInfoPane, "videoInfo");
		card.addLayoutComponent(rentPane, "rent");
		card.addLayoutComponent(checkPane, "check");
		card.addLayoutComponent(homePane, "home");

		
		// button setting
		JButton memInfoButton = new JButton("Member Info");
		MemInfoBtnAction memInfoBtnListener = new MemInfoBtnAction();
		memInfoButton.addActionListener(memInfoBtnListener);
		
		JButton registButton = new JButton("Register");
		RegistBtnAction registBtnListener = new RegistBtnAction();
		registButton.addActionListener(registBtnListener);
		registButton.setAlignmentX(0.1f);
		
		JButton deleteButton = new JButton("Delete");
		DeleteBtnAction deleteBtnListener = new DeleteBtnAction();
		deleteButton.addActionListener(deleteBtnListener);
		deleteButton.setAlignmentX(0.5f);
		
		JButton modifyButton = new JButton("Modify");
		ModifyBtnAction modifyBtnListener = new ModifyBtnAction();
		modifyButton.addActionListener(modifyBtnListener);
		modifyButton.setAlignmentX(0.9f);
		
		
		JButton videoInfoButton = new JButton("Video Info");
		VideoInfoBtnAction videoInfoBtnListener = new VideoInfoBtnAction();
		videoInfoButton.addActionListener(videoInfoBtnListener);
		
		JButton addButton = new JButton("Add");
		AddBtnAction addBtnListener = new AddBtnAction();
		addButton.addActionListener(addBtnListener);
		addButton.setAlignmentX(Box.LEFT_ALIGNMENT);
		
		JButton removeButton = new JButton("Remove");
		RemoveBtnAction removeBtnListener = new RemoveBtnAction();
		removeButton.addActionListener(removeBtnListener);
		removeButton.setAlignmentX(Box.RIGHT_ALIGNMENT);
		
		JButton modifyTitleButton = new JButton("Modify Title");
		ModifyTitleBtnAction modifyTitleBtnListener = new ModifyTitleBtnAction();
		modifyTitleButton.addActionListener(modifyTitleBtnListener);
		
		JButton modifyRestButton = new JButton("Modify Rest");
		ModifyRestBtnAction modifyRestBtnListener = new ModifyRestBtnAction();
		modifyRestButton.addActionListener(modifyRestBtnListener);
		
		
		JButton rentReturnButton = new JButton("Rent/Return");
		RentReturnBtnAction rentReturnBtnListener = new RentReturnBtnAction();
		rentReturnButton.addActionListener(rentReturnBtnListener);
		
		JButton rentButton = new JButton("Rent");
		RentBtnAction rentBtnListener = new RentBtnAction();
		rentButton.addActionListener(rentBtnListener);
		
		JButton returnButton = new JButton("Return");
		ReturnBtnAction returnBtnListener = new ReturnBtnAction();
		returnButton.addActionListener(returnBtnListener);

		
		JButton checkButton = new JButton("Check");
	    CheckBtnAction checkBtnListener = new CheckBtnAction();
		checkButton.addActionListener(checkBtnListener);
		
		JButton checkWhoButton = new JButton("Who rents?");
		CheckWhoBtnAction checkWhoBtnListener = new CheckWhoBtnAction();
		checkWhoButton.addActionListener(checkWhoBtnListener);
		
		JButton checkWhatButton = new JButton("Rents what?");
		CheckWhatBtnAction checkWhatBtnListener = new CheckWhatBtnAction();
		checkWhatButton.addActionListener(checkWhatBtnListener);
		

		JButton[] goHomeButtons = new JButton[6];
		for (int i = 0; i < 6; i++) {
			goHomeButtons[i] = new JButton("Home");
			GoHomeBtnAction goHomeBtnListener = new GoHomeBtnAction();
			goHomeButtons[i].addActionListener(goHomeBtnListener);
		}
		goHomeButtons[4].setAlignmentX(0.5f);
		goHomeButtons[5].setAlignmentX(0.5f);
		
		// label setting 
		JLabel memInfoLabel = new JLabel("Member Info"); 
		memInfoLabel.setAlignmentX(0.5f);
		
		JLabel memIdLabel = new JLabel("ID");
		memIdLabel.setPreferredSize(new Dimension(200, 20));
		JLabel memNameLabel = new JLabel("Members' Name"); 
		memNameLabel.setPreferredSize(new Dimension(350, 20));
		
		JLabel vidInfoLabel = new JLabel("Video Info");
		vidInfoLabel.setAlignmentX(0.5f);
		
		JLabel vidNameLabel = new JLabel("Videos' Title");
		vidNameLabel.setPreferredSize(new Dimension(360, 20));
		JLabel vidRestNumLabel = new JLabel("Rest");
		vidRestNumLabel.setPreferredSize(new Dimension(100, 20));
		JLabel vidBorNumLabel = new JLabel("Rented");
		vidBorNumLabel.setPreferredSize(new Dimension(70, 20));
		
		JLabel rentReturnLabel = new JLabel("Rent/Return");
		rentReturnLabel.setAlignmentX(0.5f);
		JLabel vidNameLabel2 = new JLabel("Videos' Title");
		vidNameLabel2.setPreferredSize(new Dimension(360, 20));
		JLabel vidRestNumLabel2 = new JLabel("Rest");
		vidRestNumLabel2.setPreferredSize(new Dimension(100, 20));
		JLabel vidBorNumLabel2 = new JLabel("Rented");
		vidBorNumLabel2.setPreferredSize(new Dimension(70, 20));
		
		JLabel checkLabel = new JLabel("Check");
		JLabel checkWhoLabel = new JLabel("Members who have rented the above videos");
		JLabel dummyLabel = new JLabel("   ");
		JLabel checkWhatLabel = new JLabel("Videos rented by members with the above ID");
		checkLabel.setAlignmentX(Box.CENTER_ALIGNMENT);
		
		
		// scroll panel setting
		memberNameModel = new DefaultListModel<String>();
		memberNameList = new JList<String>(memberNameModel);
		memberNameList.setVisibleRowCount(10);
		memberNameList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane mNameScrollPane = new JScrollPane(memberNameList);
		mNameScrollPane.createVerticalScrollBar();
		mNameScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		mNameScrollPane.setPreferredSize(new Dimension(200, 200));
		
		memberIdModel = new DefaultListModel<Integer>();
		memberIdList = new JList<Integer>(memberIdModel);
		memberIdList.setVisibleRowCount(10);
		JScrollPane mIdScrollPane = new JScrollPane(memberIdList);
		mIdScrollPane.createVerticalScrollBar();
		mIdScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		mIdScrollPane.setPreferredSize(new Dimension(30, 200));
		
		videoNameModel = new DefaultListModel<String>();
		videoNameList = new JList<String>(videoNameModel);
		videoNameList.setVisibleRowCount(10);
		videoNameList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane vScrollPane = new JScrollPane(videoNameList);
		vScrollPane.createVerticalScrollBar();
		vScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		vScrollPane.setPreferredSize(new Dimension(280, 200));
		
		videoRestNumModel = new DefaultListModel<Integer>();
		videoRestNumList = new JList<Integer>(videoRestNumModel);
		videoRestNumList.setVisibleRowCount(10);
		videoRestNumList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane vRestNumScrollPane = new JScrollPane(videoRestNumList);
		vRestNumScrollPane.createVerticalScrollBar();
		vRestNumScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		vRestNumScrollPane.setPreferredSize(new Dimension(20, 200));
		
		videoBorNumModel = new DefaultListModel<Integer>();
		videoBorNumList = new JList<Integer>(videoBorNumModel);
		videoBorNumList.setVisibleRowCount(10);
		JScrollPane vBorNumScrollPane = new JScrollPane(videoBorNumList);
		vBorNumScrollPane.createVerticalScrollBar();
		vBorNumScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		vBorNumScrollPane.setPreferredSize(new Dimension(20, 200));
		
		videoNameList2 = new JList<String>(videoNameModel);
		videoNameList2.setVisibleRowCount(10);
		videoNameList2.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		JScrollPane vScrollPane2 = new JScrollPane(videoNameList2);
		vScrollPane2.createVerticalScrollBar();
		vScrollPane2.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		vScrollPane2.setPreferredSize(new Dimension(290, 200));
		
		videoRestNumList2 = new JList<Integer>(videoRestNumModel);
		videoRestNumList2.setVisibleRowCount(10);
		JScrollPane vRestNumScrollPane2 = new JScrollPane(videoRestNumList2);
		vRestNumScrollPane2.createVerticalScrollBar();
		vRestNumScrollPane2.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		vRestNumScrollPane2.setPreferredSize(new Dimension(20, 200));
		
		videoBorNumList2 = new JList<Integer>(videoBorNumModel);
		videoBorNumList2.setVisibleRowCount(10);
		JScrollPane vBorNumScrollPane2 = new JScrollPane(videoBorNumList2);
		vBorNumScrollPane2.createVerticalScrollBar();
		vBorNumScrollPane2.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		vBorNumScrollPane2.setPreferredSize(new Dimension(20, 200));
		
		
		// sub panel add
		homePane.add(memInfoButton);
		homePane.add(videoInfoButton);
		homePane.add(rentReturnButton);
		homePane.add(checkButton);

		
		memberInfoPane.add(memInfoLabel);
		subPane1.add(registButton);
		subPane1.add(Box.createRigidArea(new Dimension(20, 10)));
		subPane1.add(deleteButton);
		memberInfoPane.add(subPane1);
		memberInfoPane.add(fields[0]);
		labelPane1.add(memIdLabel);
		labelPane1.add(memNameLabel);
		memberInfoPane.add(labelPane1);
		subPane2.add(mIdScrollPane);
		subPane2.add(mNameScrollPane);
		memberInfoPane.add(subPane2);
		subPane3.add(modifyButton);
		subPane3.add(Box.createRigidArea(new Dimension(20, 10)));
		subPane3.add(goHomeButtons[0]);
		memberInfoPane.add(subPane3);
		
		
		videoInfoPane.add(vidInfoLabel);
		subPane4.add(addButton);
		subPane4.add(removeButton);
		videoInfoPane.add(subPane4);
		subPane5.add(fields[1]);
		subPane5.add(fields[2]);
		videoInfoPane.add(subPane5);
		labelPane2.add(vidNameLabel);
		labelPane2.add(vidRestNumLabel);
		labelPane2.add(vidBorNumLabel);
		videoInfoPane.add(labelPane2);
		subPane6.add(vScrollPane);
		subPane6.add(vRestNumScrollPane);
		subPane6.add(vBorNumScrollPane);
		videoInfoPane.add(subPane6);
		subPane7.add(modifyTitleButton);
		subPane7.add(modifyRestButton);
		subPane7.add(goHomeButtons[1]);
		videoInfoPane.add(subPane7);
		

		rentPane.add(rentReturnLabel);
		subPane8.add(rentButton);
		subPane8.add(returnButton);
		rentPane.add(subPane8);
		rentPane.add(fields[3]);
		subPane9.add(vidNameLabel2);
		subPane9.add(vidRestNumLabel2);
		subPane9.add(vidBorNumLabel2);
		rentPane.add(subPane9);
		subPane10.add(vScrollPane2);
		subPane10.add(vRestNumScrollPane2);
		subPane10.add(vBorNumScrollPane2);
		rentPane.add(subPane10);
		rentPane.add(goHomeButtons[4]);
		
		
		checkPane.add(checkLabel);
		subPane11.add(checkWhoButton);
		subPane11.add(Box.createRigidArea(new Dimension(150, 50)));
		subPane11.add(checkWhatButton);
		checkPane.add(subPane11);
		subPane12.add(fields[4]);
		subPane12.add(fields[5]);
		checkPane.add(subPane12);
		labelPane3.add(checkWhoLabel);
		labelPane3.add(dummyLabel);
		labelPane3.add(checkWhatLabel);
		checkPane.add(labelPane3);
		subPane13.add(areas[0]);
		subPane13.add(Box.createRigidArea(new Dimension(20, 50)));
		subPane13.add(areas[1]);
		checkPane.add(subPane13);
		checkPane.add(goHomeButtons[5]);


		return controlPane;
	}

	
	class RegistBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String tmp = fields[0].getText();
			if (!(tmp.isBlank())) {
				Member m = new Member(tmp);
				members.add(m);
				memberNameModel.addElement(m.getName());
				memberIdModel.addElement(m.getId());
			} else {
				JOptionPane.showMessageDialog(memberInfoPane, "Input any Name", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	class DeleteBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int i = memberNameList.getSelectedIndex();
			if (i != -1) {
				memberNameModel.remove(i);
				memberIdModel.remove(i);
				members.remove(i);
			} else {
				JOptionPane.showMessageDialog(memberInfoPane, "Please select any name!", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	class ModifyBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int i = memberNameList.getSelectedIndex();
			String tmp = fields[0].getText();
			if (i != -1 && !(tmp.isBlank())) {
				memberNameModel.set(i, tmp);
				members.get(i).setName(tmp);
			} else if (i == -1){
				JOptionPane.showMessageDialog(memberInfoPane, "Select any name to modify", "Error", JOptionPane.ERROR_MESSAGE);
			} else {
				JOptionPane.showMessageDialog(memberInfoPane, "Input any new Name", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	class MemInfoBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			card.show(controlPane, "memberInfo");
		}
	}
	

	class VideoInfoBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			card.show(controlPane, "videoInfo");
		}
	}
	
	class AddBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			String tmpTitle = fields[1].getText();
			String tmpRest = fields[2].getText();
			if (tmpTitle.isBlank()) {
				JOptionPane.showMessageDialog(videoInfoPane, "Input video's title in left field", "Error", JOptionPane.ERROR_MESSAGE);
			} else if (tmpRest.isBlank()) {
				JOptionPane.showMessageDialog(videoInfoPane, "Input video's number in right field", "Error", JOptionPane.ERROR_MESSAGE);
			} else if (videoNameModel.indexOf(tmpTitle) != -1) {
				JOptionPane.showMessageDialog(videoInfoPane, "This video's title has already existed", "Error", JOptionPane.ERROR_MESSAGE);
			} else {
				try {
					int tmpRestNum = Integer.valueOf(fields[2].getText());
					if (tmpRestNum < 0) {
						JOptionPane.showMessageDialog(videoInfoPane, "Input positive number in right field", "Error", JOptionPane.ERROR_MESSAGE);
					} else {
						Video v = new Video(tmpTitle, tmpRestNum);
						videos.add(v);
						videoNameModel.addElement(v.getTitle());
						videoRestNumModel.addElement(v.getRestNum());
						videoBorNumModel.addElement(v.getBorrowedNum());
					}
				} catch (NumberFormatException ex) {
					JOptionPane.showMessageDialog(videoInfoPane, "Input positive number in right field (Don't start with space)", "Error", JOptionPane.ERROR_MESSAGE);
				}
			}
		}
	}
	
	class RemoveBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int i = videoNameList.getSelectedIndex();
			if (i != -1) {
				videoNameModel.remove(i);
				videoRestNumModel.remove(i);
				videoBorNumModel.remove(i);
				videos.remove(i);
			} else {
				JOptionPane.showMessageDialog(videoInfoPane, "Select any title to remove", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	class ModifyTitleBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int i = videoNameList.getSelectedIndex();
			String tmpTitle = fields[1].getText();
			
			if (i != -1 && !(tmpTitle.isBlank()) && videoNameModel.indexOf(tmpTitle) == -1) {
				videoNameModel.set(i, tmpTitle);
				videos.get(i).setTitle(tmpTitle);
			} else if (i == -1){
				JOptionPane.showMessageDialog(videoInfoPane, "Select any name to modify", "Error", JOptionPane.ERROR_MESSAGE);
			} else if (videoNameModel.indexOf(tmpTitle) != -1) {
				JOptionPane.showMessageDialog(videoInfoPane, "This video's title has already existed", "Error", JOptionPane.ERROR_MESSAGE);
			} else {
				JOptionPane.showMessageDialog(videoInfoPane, "Input any new Name", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	class ModifyRestBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			int i = videoRestNumList.getSelectedIndex();
			String tmpRest = fields[2].getText();
			
			if (i != -1 && !(tmpRest.isBlank())) {

				try {
					int restNum = Integer.valueOf(tmpRest);
					if (restNum >= 0) {
						videoRestNumModel.set(i, restNum);
						videos.get(i).setRest(restNum);
					} else {
						JOptionPane.showMessageDialog(videoInfoPane, "Input positive number");
					}
				} catch (NumberFormatException ex) {
					JOptionPane.showMessageDialog(videoInfoPane, "Input positive number in right field (Don't start with space)", "Error", JOptionPane.ERROR_MESSAGE);
				}
			} else if (i == -1){
				JOptionPane.showMessageDialog(videoInfoPane, "Select any Rest Number to modify", "Error", JOptionPane.ERROR_MESSAGE);
			} else {
				JOptionPane.showMessageDialog(videoInfoPane, "Input any new Rest", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}


	class RentReturnBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			card.show(controlPane, "rent");
		}
	}
	
	class RentBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			try {
				int videoIndex = videoNameList2.getSelectedIndex();
				String tmp = fields[3].getText();
				int id = Integer.valueOf(tmp);
				int memberIndex = memberIdModel.indexOf(id);
				if (videoIndex == -1) {
					JOptionPane.showMessageDialog(rentPane, "Select any video's title", "Error", JOptionPane.ERROR_MESSAGE);
				} else if ((tmp.isBlank())) {
					JOptionPane.showMessageDialog(rentPane, "Something wrong with Video List", "Error", JOptionPane.ERROR_MESSAGE);
				} else if (memberIndex == -1) {
					JOptionPane.showMessageDialog(rentPane, "There isn't such member whose ID is " + id, "Error", JOptionPane.ERROR_MESSAGE);
				} else {
					String title = videoNameModel.get(videoIndex);
					// Rest video--, Borrowed video++
					if (videos.get(videoIndex).getRestNum() > 0) {
						videos.get(videoIndex).rentCalc();
						videoRestNumModel.set(videoIndex, videos.get(videoIndex).getRestNum());
						videoBorNumModel.set(videoIndex, videos.get(videoIndex).getBorrowedNum());
						
						// add title and name to arraylist
						members.get(memberIndex).addBorrowing(title);
						String name = members.get(memberIndex).getName();
						videos.get(videoIndex).addBorrowed(name);
					} else {
						JOptionPane.showMessageDialog(rentPane, "This video is no longer available", "Error", JOptionPane.ERROR_MESSAGE);
					}
					
					
				}
			} catch (NumberFormatException ex) {
				JOptionPane.showMessageDialog(rentPane, "Input number (Don't start with space)", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	class ReturnBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			try {
				int videoIndex = videoNameList2.getSelectedIndex();
				String tmp = fields[3].getText();
				int id = Integer.valueOf(tmp);
				int memberIndex = memberIdModel.indexOf(id);
				if (videoIndex == -1) {
					JOptionPane.showMessageDialog(rentPane, "Please select title or add video's title", "Error", JOptionPane.ERROR_MESSAGE);
				} else if (memberIndex == -1) {
					JOptionPane.showMessageDialog(rentPane, "There isn't such member whose ID is " + id, "Error", JOptionPane.ERROR_MESSAGE);
				} else if (tmp.isBlank()) {
					JOptionPane.showMessageDialog(rentPane, "Input registerd ID", "Error", JOptionPane.ERROR_MESSAGE);
				} else {
					String title = videoNameModel.get(videoIndex);
					Iterator<String> itr = members.get(memberIndex).getBorrowing();
					// check member hasVideo
					while (itr.hasNext()) {
						String str = itr.next();
						if (str.equals(title)) {
							// Rest video++, Borrowed video--
							videos.get(videoIndex).returnCalc();
							videoRestNumModel.set(videoIndex, videos.get(videoIndex).getRestNum());
							videoBorNumModel.set(videoIndex, videos.get(videoIndex).getBorrowedNum());
							
							// remove title and name
							members.get(memberIndex).removeBorrowing(title);
							String name = members.get(memberIndex).getName();
							videos.get(videoIndex).removeBorrowed(name);
							
							return;
						}
					}
					JOptionPane.showMessageDialog(rentPane, "This member does'nt rent this video", "Error", JOptionPane.ERROR_MESSAGE);	
				}
			} catch (NumberFormatException ex) {
				JOptionPane.showMessageDialog(rentPane, "Input registerd ID", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}

	
	class CheckBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			card.show(controlPane, "check");
		}
	}
	
	class CheckWhoBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			areas[0].setText(""); // clear
			String title = fields[4].getText();
			int vIndex = videoNameModel.indexOf(title);
			if (vIndex == -1) {
				JOptionPane.showMessageDialog(checkPane, "There isn't such video whose title is " + title, "Error", JOptionPane.ERROR_MESSAGE);
			} else {
				Iterator<String> itr = videos.get(vIndex).getBorrowed();
				while (itr.hasNext() ) {
					String tmp = itr.next();
					areas[0].append(tmp + "\n");
				}
			}
		}
	}
	
	class CheckWhatBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			areas[1].setText("");
			String idStr = fields[5].getText();
			try {
				int id = Integer.valueOf(idStr);
				int memberId = memberIdModel.indexOf(id);
				if (memberId == -1) {
					JOptionPane.showMessageDialog(checkPane, "There isn't such member whose ID is " + id, "Error", JOptionPane.ERROR_MESSAGE);
				} else {
					Iterator<String> itr = members.get(memberId).getBorrowing();
					while (itr.hasNext()) {
						String tmp = itr.next();
						areas[1].append(tmp + "\n");
					}
				}
			} catch (NumberFormatException ex){
				JOptionPane.showMessageDialog(checkPane, "Input registered ID", "Error", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	

	class GoHomeBtnAction implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			card.show(controlPane, "home");
		}
	}


	public static void main(String[] args) {
		JFrame frame = new JFrame("RentalVideoSystem");
		VideoSystem app = new VideoSystem();
		Component contents = app.createComponents();
		frame.getContentPane().add(contents, BorderLayout.CENTER);

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(640, 480);
//		frame.pack();
		frame.setVisible(true);
	}
}