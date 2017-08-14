import java.awt.BorderLayout;

import java.awt.Color;

import java.awt.Container;

import java.awt.GridLayout;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

import java.awt.event.ItemEvent;

import java.awt.event.ItemListener;

import java.io.BufferedReader;

import java.io.File;

import java.io.IOException;

import java.io.InputStream;

import java.io.InputStreamReader;

import java.io.PrintStream;

import java.util.Enumeration;

import java.util.HashMap;

import java.util.ArrayList;



import javax.comm.*;



import javax.swing.JButton;

import javax.swing.JComboBox;

import javax.swing.JDialog;

import javax.swing.JFileChooser;

import javax.swing.JFrame;

import javax.swing.JLabel;

import javax.swing.JList;

import javax.swing.JOptionPane;

import javax.swing.JPanel;

import javax.swing.JScrollBar;

import javax.swing.JScrollPane;

import javax.swing.event.AncestorEvent;

import javax.swing.event.AncestorListener;



/**

 * Open a serial port using Java Communications.

 * 

 * @author Ian F. Darwin, http://www.darwinsys.com/

 */



/*

 * Define ArrayList for keep data packet

 */



public class CommPortOpen {

	/** How long to wait for the open to finish up. */

	public static final int TIMEOUTSECONDS = 30;



	/** The baud rate to use. */

	public static final int BAUD = 9600;



	/** The parent JFrame, for the chooser. */

	protected JFrame parent;



	/** The input stream */

	protected BufferedReader is;



	/** The output stream */

	protected PrintStream os;



	/** The interrupt send files */

	protected InterrupSender intSend;



	/** The interrupt wait-time for re-send packet */

	protected WaitTime initWaitTime;

	/**/

	protected static PortChooser layout;



	/** The chosen Port Identifier */

	CommPortIdentifier thePortID;



	/** The process receive event */

	CommPortReceiver comProReceive;



	/** The chosen Port itself */

	CommPort thePort;



	SerialPort myPort;

	CommPortReceiver comreciever;



	/** Transfer mode */

	protected char Tmode;



	final static char RECEIV_ = 'R';

	final static char SEND_ = 'S';

	final static char ACK_ = 'A';

	final static char NAK_ = 'N';

	final static String ChkEnd = "1111111111FF";

	final static String SW = "Stop And Wait";

	final static String SR = "Selective Repeat";



	protected static ArrayList<String> datapacket;

	protected static ArrayList<String> datapacketBuff;

	protected int currentPackNo = 0, currentDiff = 0, currentSuc = -1,

			currentSendPacket = 0;

	protected static boolean[] packetStatus = new boolean[5000];



	public static void main(String[] argv) throws IOException,

			NoSuchPortException, PortInUseException,

			UnsupportedCommOperationException {

		// Clear packet

		datapacket = new ArrayList<String>();

		// new CommPortOpen(null).converse();

		CommPortOpen app = new CommPortOpen();



		layout = new PortChooser();

		datapacket = layout.datapacket;

		layout.setVisible(true);

		app.updateStatus();



	}



	public void updateStatus() {

		layout.status.setListData(layout.statusTxt.toArray());

	}



	public void createCrateEvent(PortChooser c) throws IOException,

			NoSuchPortException, PortInUseException,

			UnsupportedCommOperationException {

		String portName = null;

		// Dialog done. Get the port name.

		portName = c.getSelectedName();

		if (portName == null) {

			System.out.println("No port selected. Try again.\n");



		} else {

			thePortID = c.getSelectedIdentifier();



			switch (thePortID.getPortType()) {

			case CommPortIdentifier.PORT_SERIAL:

				thePort = thePortID.open("DarwinSys DataComm",

						TIMEOUTSECONDS * 1000);

				myPort = (SerialPort) thePort;



				// set up the serial port

				myPort.setSerialPortParams(BAUD, SerialPort.DATABITS_8,

						SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);

				break;

			default: // Neither parallel nor serial??

				throw new IllegalStateException("Unknown port type "

						+ thePortID);

			}

		}

		// System.exit(0);

		if (c.actionChoice.getSelectedItem().equals("Sender")

				&& c.mode.getSelectedItem().equals(SW)) {



			try {

				Packet packet = new Packet();

				datapacket = packet.getPacket(new InputStreamFile()

						.getData(c.path_));



				layout.statusTxt.clear();



				for (int i = 0; i < datapacket.size(); i++) {

					layout.statusTxt.add("Send Package number: " + i);

					// System.out.println(datapacket.get(i)+"["+datapacket.get(i).length()+"]");

				}

				updateStatus();



				stopAndwait();

				try {

					Tmode = SEND_;

					comProReceive = new CommPortReceiver(

							myPort.getInputStream(), this, Tmode, layout.mode

									.getSelectedItem().toString());

					comProReceive.start();

				} catch (Exception e) {



				}



			} catch (Exception ee) {

				ee.printStackTrace();

			}



		} else if (c.actionChoice.getSelectedItem().equals("Receiver")) {

			layout.statusTxt.clear();

			layout.statusTxt.add("Receiving.....");

			updateStatus();

			try {

				Tmode = RECEIV_;

				comProReceive = new CommPortReceiver(myPort.getInputStream(),

						this, Tmode, layout.mode.getSelectedItem().toString());

				comProReceive.start();

			} catch (Exception e) {



			}

		} else if (c.actionChoice.getSelectedItem().equals("Sender")

				&& c.mode.getSelectedItem().equals(SR)) {

			try {



				datapacket = new Packet().getPacket(new InputStreamFile()

						.getData(c.path_));



				layout.statusTxt.clear();



				for (int i = 0; i < datapacket.size(); i++) {

					layout.statusTxt.add("Send Package number: " + i);

					// System.out.println(datapacket.get(i)+"["+datapacket.get(i).length()+"]");

				}

				updateStatus();



				// selectiveRepeat("");

				intSend = new InterrupSender(this);

				try {



					Tmode = SEND_;

					new CommPortReceiver(myPort.getInputStream(), this, Tmode,

							layout.mode.getSelectedItem().toString()).start();

				} catch (Exception e) {



				}

				// selectiveRepeat("");



			} catch (Exception ee) {

				ee.printStackTrace();

			}



		}



	}



	/* Constructor */

	public void getCommPortOpen(JFrame f) throws IOException,

			NoSuchPortException, PortInUseException,

			UnsupportedCommOperationException {

	}



	/**

	 * This method will be overridden by non-trivial subclasses to hold a

	 * conversation.

	 */

	protected void converse() throws IOException {



		System.out.println("Ready to read and write port.");



		// Input/Output code not written -- must subclass.



		// Finally, clean up.

		if (is != null)

			is.close();

		os.close();

	}



	public boolean stopAndwait() {

		if (datapacket.isEmpty())

			return false;



		try {



			write(datapacket.get(0));

			// Set new interrupt for wait time

			initWaitTime = new WaitTime(this);



		} catch (IOException e) {

			e.printStackTrace();

		}



		return true;

	}



	public boolean selectiveRepeat(String strIndex) {

		int index = 0;

		if (!strIndex.isEmpty()) {

			index = Integer.parseInt(strIndex);

			// if(datapacket.isEmpty()) return false;

			if (index == datapacket.size() - 1)

				return false;

		}

		try {

			for (int i = 0; i < index; i++) {

				if (!packetStatus[i]) {

					write(datapacket.get(i));

				}

			}

			// /datapacket.remove(Integer.parseInt(strIndex));

			packetStatus[index] = true;

			if (currentSuc < index)

				currentSuc = index;

			intSend = new InterrupSender(this);

			// currentPackNo--;

		} catch (Exception e) {

			// TODO Auto-generated catch block

			e.printStackTrace();

		}



		return true;

	}



	protected ArrayList<String> chkRemove(ArrayList<String> src, String key,

			int init) {

		if (init > src.size() - 1) {

			init = src.size() - 1;

		}

		for (int i = init; i >= 0; i--) {

			if (src.get(i).equals(key)) {

				src.remove(i);

			}

		}

		return src;

	}



	protected void write(String src) throws IOException {

		// TEST FOR SEND

		CommPortSender.setWriterStream(myPort.getOutputStream());

		CommPortSender.send(src.getBytes());



	}

}



class PortChooser extends JFrame implements ItemListener {

	final static String Appname = "RS232 NetWork Proj. V 1.0";

	/** A mapping from names to CommPortIdentifiers. */

	protected HashMap map = new HashMap();



	/** The name of the choice the user made. */

	protected String selectedPortName;



	/** The CommPortIdentifier the user chose. */

	protected CommPortIdentifier selectedPortIdentifier;



	/** The JComboBox for serial ports */

	protected JComboBox serialPortsChoice;



	/** The JComboBox for parallel ports */

	protected JComboBox actionChoice;



	/** The JComboBox for anything else */

	protected JComboBox mode;

	/**

	 * The time for wail send/

	 */

	protected JComboBox timewait;



	/** The file chose */

	protected JFileChooser fileselect;



	/** The SerialPort object */

	protected SerialPort ttya;



	/** To display the chosen */

	protected JLabel choice;



	/*

	 * For button choose file

	 */

	protected JButton Choosefile;

	/* The status send and receive */



	protected JButton processButton, about;



	protected JList status;



	/** Scrollbar */

	protected JScrollPane jscollBar;



	protected JLabel aboutl;



	/**

	 * Status contain/

	 * 

	 */

	protected ArrayList<String> statusTxt = new ArrayList<String>();



	protected ArrayList<String> datapacket;



	/** Padding in the GUI */

	protected final int PAD = 5;



	// Path file from select

	protected String path_ = "", filename = "";



	protected Object oj;

	protected CommPortOpen commportOpen;



	/**

	 * This will be called from either of the JComboBoxen when the user selects

	 * any given item.

	 */

	public void itemStateChanged(ItemEvent e) {

		String choose = (String) ((JComboBox) e.getSource()).getSelectedItem();

		// Get the name

		if (choose.contains("COM")) {

			selectedPortName = choose;

			// Get the given CommPortIdentifier

			selectedPortIdentifier = (CommPortIdentifier) map

					.get(selectedPortName);



		}

		if (actionChoice.getSelectedItem().equals("Receiver")

				|| mode.getSelectedItem().equals(commportOpen.SR)) {

			timewait.setEnabled(false);

		} else {

			timewait.setEnabled(true);

		}

	}



	/* The public "getter" to retrieve the chosen port by name. */

	public String getSelectedName() {

		return selectedPortName;

	}



	/* The public "getter" to retrieve the selection by CommPortIdentifier. */

	public CommPortIdentifier getSelectedIdentifier() {

		return selectedPortIdentifier;

	}



	/**

	 * Construct a PortChooser --make the GUI and populate the ComboBoxes.

	 */

	public PortChooser() {

		super(Appname);

		makeGUI();

		populate();

		finishGUI();

		commportOpen = new CommPortOpen();

		oj = this;

	}



	/**

	 * Build the GUI. You can ignore this for now if you have not yet worked

	 * through the GUI chapter. Your mileage may vary.

	 */

	protected void makeGUI() {

		Container cp = getContentPane();



		JPanel northPanel = new JPanel();

		JPanel bottom = new JPanel();

		JPanel center = new JPanel();

		cp.add(BorderLayout.NORTH, northPanel);

		cp.add(BorderLayout.CENTER, center);

		cp.add(BorderLayout.SOUTH, bottom);



		northPanel.setLayout(new GridLayout(0, 2, PAD, PAD));

		bottom.setLayout(new GridLayout(0, 1, PAD, PAD));

		center.setLayout(new GridLayout(0, 1, PAD, PAD));



		northPanel.add(new JLabel("Serial Ports", JLabel.RIGHT));

		serialPortsChoice = new JComboBox();

		serialPortsChoice.addItem("");

		northPanel.add(serialPortsChoice);



		northPanel.add(new JLabel("Action", JLabel.RIGHT));

		actionChoice = new JComboBox();

		actionChoice.addItem("Sender");

		actionChoice.addItem("Receiver");

		northPanel.add(actionChoice);



		northPanel.add(about = new JButton("ABOUT"));

		about.addActionListener(new ActionListener() {



			@Override

			public void actionPerformed(ActionEvent arg0) {

				// TODO Auto-generated method stub

				JOptionPane

						.showMessageDialog(

								new JFrame(),

								"DEVELOPER\n\tMr.Narong Intiruk\n\n"

										+ Appname

										+ "\n2012@copyrigth \n\nwww.facebook.com/dotnetz",

								"About of Applications",

								JOptionPane.INFORMATION_MESSAGE);

			}

		});



		fileselect = new JFileChooser();

		fileselect.setCurrentDirectory(new File("."));



		northPanel.add(Choosefile = new JButton("Choose File Location"));

		Choosefile.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent e) {

				int select;

				if (actionChoice.getSelectedItem().equals("Receiver")) {

					select = fileselect.showSaveDialog(new JFrame());

				} else {

					select = fileselect.showOpenDialog(new JFrame());

				}

				if (select == JFileChooser.APPROVE_OPTION) {

					// fileselect

					File path = fileselect.getSelectedFile();

					path_ = path.getAbsolutePath();

					filename = path.getName();



				}

			}

		});

		// Select Mode

		northPanel.add(new JLabel("Use Mode:", JLabel.RIGHT));

		mode = new JComboBox();

		mode.addItem("Stop And Wait");

		mode.addItem("Selective Repeat");

		northPanel.add(mode);



		// Time wait selection

		northPanel.add(new JLabel("Time Wait(Sec.)", JLabel.RIGHT));

		timewait = new JComboBox();

		for (int i = 1; i < 10; i++) {

			timewait.addItem(i);

		}

		northPanel.add(timewait);



		center.add(BorderLayout.NORTH, processButton = new JButton(

				" <<  Processes  >> "));



		processButton.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent e) {

				if (checkError()) {

					if (processButton.getText().equals(" <<  Processes  >> ")) {



						try {

							commportOpen.createCrateEvent((PortChooser) oj);

						} catch (IOException e1) {

							// TODO Auto-generated catch block

							e1.printStackTrace();

						} catch (NoSuchPortException e1) {

							// TODO Auto-generated catch block

							e1.printStackTrace();

						} catch (PortInUseException e1) {

							// TODO Auto-generated catch block

							e1.printStackTrace();

						} catch (UnsupportedCommOperationException e1) {

							// TODO Auto-generated catch block

							e1.printStackTrace();

						}

						setDisableLayout();



						processButton.setText("  <<  Stop  >>  ");

					} else if (processButton.getText().equals(

							"  <<  Stop  >>  ")) {



						try {

							// Clear interrupt and close port.

							commportOpen.myPort.close();

							commportOpen.thePort.close();



							if (commportOpen.comProReceive != null) {

								commportOpen.comProReceive.stop();

							}

							if (commportOpen.initWaitTime != null) {

								commportOpen.initWaitTime.stop();

							}

							if (commportOpen.intSend != null) {

								commportOpen.intSend.stop();

							}

						} catch (Exception e1) {

							e1.printStackTrace();

						}

						// Enable menu

						setEnableLayout();

						processButton.setText(" <<  Processes  >> ");



						if (actionChoice.getSelectedItem().equals("Receiver")

								|| mode.getSelectedItem().equals(

										commportOpen.SR)) {

							timewait.setEnabled(false);

							statusTxt.clear();

							commportOpen.updateStatus();

						}

					}

				}

			}

		});

		center.add(BorderLayout.CENTER, new JLabel("{ Package Status }"));



		status = new JList(statusTxt.toArray());

		status.setBackground(Color.black);

		status.setSelectionBackground(Color.YELLOW);

		status.setForeground(Color.BLUE);

		status.setVisibleRowCount(17);

		jscollBar = new JScrollPane(status);

		bottom.add(BorderLayout.CENTER, jscollBar);

	}



	public void setDisableLayout() {

		serialPortsChoice.setEnabled(false);

		actionChoice.setEnabled(false);

		mode.setEnabled(false);

		timewait.setEnabled(false);

		Choosefile.setEnabled(false);

		// processButton.setEnabled(false);



	}



	public void setEnableLayout() {

		serialPortsChoice.setEnabled(true);

		actionChoice.setEnabled(true);

		mode.setEnabled(true);

		timewait.setEnabled(true);

		Choosefile.setEnabled(true);

		processButton.setEnabled(true);

		processButton.setText(" <<  Processes  >> ");



	}



	/**

	 * Populate the ComboBoxes by asking the Java Communications API what ports

	 * it has. Since the initial information comes from a Properties file, it

	 * may not exactly reflect your hardware.

	 */

	protected void populate() {

		// get list of ports available on this particular computer,

		// by calling static method in CommPortIdentifier.

		Enumeration pList = CommPortIdentifier.getPortIdentifiers();



		// Process the list, putting serial and parallel into ComboBoxes

		while (pList.hasMoreElements()) {

			CommPortIdentifier cpi = (CommPortIdentifier) pList.nextElement();

			// System.out.println("Port " + cpi.getName());

			map.put(cpi.getName(), cpi);

			if (cpi.getPortType() == CommPortIdentifier.PORT_SERIAL) {

				serialPortsChoice.setEnabled(true);

				serialPortsChoice.addItem(cpi.getName());

			}

		}

	}



	protected void finishGUI() {

		serialPortsChoice.addItemListener(this);

		actionChoice.addItemListener(this);

		mode.addItemListener(this);

		pack();

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	}



	public boolean checkError() {

		if (serialPortsChoice.getSelectedIndex() < 1) {

			JOptionPane.showMessageDialog(this,

					"Plaese select the Serialport number.", "Error Checking",

					JOptionPane.ERROR_MESSAGE);

			return false;

		} else if (path_.isEmpty()) {

			if (actionChoice.getSelectedItem().equals("Sender")) {

				JOptionPane.showMessageDialog(this,

						"Plaese select your file to send.", "Error Checking",

						JOptionPane.ERROR_MESSAGE);

				return false;

			}

		}



		return true;

	}

}