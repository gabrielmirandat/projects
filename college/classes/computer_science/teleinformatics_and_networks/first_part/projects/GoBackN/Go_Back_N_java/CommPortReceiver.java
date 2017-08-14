import java.io.ByteArrayInputStream;

import java.io.IOException;

import java.io.InputStream;

import java.math.BigInteger;

import java.util.ArrayList;

import java.util.zip.Adler32;

import java.util.zip.CheckedInputStream;



public class CommPortReceiver extends Thread {



	InputStream in;

	String dataPacket = "";

	String dataBuff, StrchkSUM, datafilename, mode;

	StringBuilder dataComplate = new StringBuilder();



	CommPortOpen commPort;

	Protocol protocol = new ProtocolImpl();

	int packetNo = 0;

	int cntPN = 4;

	int cntPL = 2;

	int timeCnt = 0;

	int cntSum = 8;

	int cntdot = 0;

	int filenameL;



	int packetNO, dataLength;

	boolean chkH = false;

	boolean chkPN = false;

	boolean chkPL = false;

	boolean chkData = false;

	boolean chkSum = false;

	boolean chkdot = false;

	boolean chkfilename = false;

	boolean chkfilename_ = false;



	char Tmode, chBuff;



	public CommPortReceiver(InputStream in, CommPortOpen commPort, char Tmode,

			String mode) {

		this.in = in;

		this.commPort = commPort;

		this.Tmode = Tmode;

		this.mode = mode;

	}



	public void run() {



		try {

			int b;

			while (true) {

				// if stream is not bound in.read() method returns -1

				while ((b = in.read()) != -1) {

					protocol.onReceive((byte) b);

					chBuff = ((char) (byte) b);

					if (mode.equals(commPort.SW)) {

						if (Tmode == commPort.RECEIV_) {

							readReceiver(chBuff);

						} else if (Tmode == commPort.SEND_) {

							// System.out.println("buffer "+chBuff);

							readSendSW(chBuff);

						}

					} else if (mode.equals(commPort.SR)) {



						if (Tmode == commPort.RECEIV_) {

							readReceiver(chBuff);

						} else if (Tmode == commPort.SEND_) {

							// System.out.println(chBuff+"SEND");

							// System.out.println("buffer "+chBuff);

							readSendSR(chBuff);

						}

					}

				}



				// commPort.stopAndwait(Integer.parseInt(strTm));

				protocol.onStreamClosed();



				// wait 10ms when stream is broken and check again

				sleep(10);

			}

		} catch (IOException e) {

			e.printStackTrace();

		} catch (InterruptedException e) {

			e.printStackTrace();

		}

	}



	public boolean readSendSR(char cBuff) {



		dataPacket += cBuff;



		if (commPort.currentSuc < 9) {

			commPort.intSend.interrupt();

			commPort.intSend.stop();



			commPort.selectiveRepeat(dataPacket);

			// Update status

			commPort.layout.statusTxt = commPort.chkRemove(

					commPort.layout.statusTxt, "Send Package number: "

							+ dataPacket, Integer.parseInt(dataPacket));

			commPort.updateStatus();

			dataPacket = "";



		} else if ((commPort.currentSuc >= 9) && dataPacket.length() == 2) {

			System.out.println(dataPacket + "Send");



			// Set interrupt for receive

			commPort.intSend.interrupt();



			// Update status

			commPort.layout.statusTxt = commPort.chkRemove(

					commPort.layout.statusTxt, "Send Package number: "

							+ dataPacket, Integer.parseInt(dataPacket));

			commPort.updateStatus();



			if (Integer.parseInt(dataPacket) == commPort.datapacket.size() - 1) {

				commPort.layout.statusTxt.clear();

				commPort.layout.statusTxt.add("Send is finish");

				commPort.updateStatus();



				String tm = new Packet()

						.packageFilename(commPort.layout.filename);

				try {

					commPort.write(tm);

				} catch (IOException e) {

					// TODO Auto-generated catch block

					e.printStackTrace();

				}

				commPort.layout.setEnableLayout();



				commPort.myPort.close();

				commPort.thePort.close();

				this.stop();

			}

			dataPacket = "";

		} else {

			commPort.selectiveRepeat("");

		}

		// System.out.println(chBuff);

		return true;

	}



	public void readSendSW(char str) {

		// System.out.println(str + "" + commPort.currentPackNo

		// + commPort.datapacket.size());

		if (str == commPort.ACK_) {

			// Set Interrupt for read ACK.

			commPort.initWaitTime.interrupt();



			if (commPort.datapacket.size() != 0) {

				commPort.datapacket.remove(0);

				commPort.layout.statusTxt.remove(0);

				commPort.updateStatus();

				commPort.stopAndwait();



				if (commPort.layout.statusTxt.isEmpty()) {

					commPort.layout.statusTxt.add("Send is finish.");

					commPort.updateStatus();

					try {

						// Write for end data

						String tm = new Packet()

								.packageFilename(commPort.layout.filename);

						commPort.write(tm);

						commPort.layout.setEnableLayout();



						commPort.myPort.close();

						commPort.thePort.close();

						this.stop();



					} catch (IOException e) {

						// TODO Auto-generated catch block

						e.printStackTrace();

					}

				}

			}

		} else if (str == commPort.NAK_) {

			commPort.stopAndwait();

		} else {



		}



	}



	public void readReceiver(char str) {

		// System.out.println(str);

		if (dataPacket.toString().equals("7E") && !(chkPL)) {

			chkH = true;

			dataPacket = "";

		}

		if (chkH) {

			dataPacket += str;

			if (dataPacket.length() == 4) {

				packetNo = Integer.parseInt(dataPacket, 16);

				dataPacket = "";

				chkPN = true;

				chkH = false;

			}

		} else if (chkPN) {

			dataPacket += str;

			if (dataPacket.length() == 2) {

				dataLength = Integer.parseInt(dataPacket, 16);

				dataPacket = "";

				chkPL = true;

				chkPN = false;

			}



		} else if (chkPL) { // Check packet length

			dataPacket += str;



			if (dataPacket.length() == dataLength * 2) {

				dataBuff = dataPacket;

				dataPacket = "";

				chkData = true;

				chkPL = false;

			}

		} else if (chkData) { // Check data from packet

			dataPacket += str;

			if (dataPacket.length() == 8) {

				StrchkSUM = dataPacket;

				dataPacket = "";

				chkData = false;

				showDataPacket();

			}

		} else {

			// System.out.println(dataPacket);

			dataPacket += str;

		}



		if (dataPacket.equals(commPort.ChkEnd)) { // Check end of packet

			// Decode filename

			chkfilename = true;

			dataPacket = "";

		} else if (chkfilename && dataPacket.length() == 1) {

			// Decode filename length

			filenameL = Integer.parseInt(dataPacket, 16);

			chkfilename_ = true;

			chkfilename = false;

			dataPacket = "";



		} else if (chkfilename_ && dataPacket.length() == (filenameL * 2)) {



			datafilename = Hex2Str(dataPacket);



			// Tempt for keep filename

			String temp = commPort.layout.path_;

			boolean isHasDot = false;

			if (!temp.isEmpty()) {

				if (temp.contains("."))

					datafilename = temp;

				else {

					datafilename = temp

							+ datafilename.substring(datafilename.indexOf("."));

				}

			}



			try {

				new InputStreamFile().fileWriter(builFile(), datafilename);



				// System.out.println(datafilename);

			} catch (IOException e) {

				// TODO Auto-generated catch block

				e.printStackTrace();

			}

			commPort.layout.setEnableLayout();

			commPort.layout.timewait.setEnabled(false);



			commPort.myPort.close();

			commPort.thePort.close();

			this.stop();

		}



	}



	public String builFile() {

		String buil = Hex2Str(dataComplate.toString());



		return buil;

	}



	public void showDataPacket() {



		String chkSum = chkSum(dataBuff);

		int tm = chkSum.length();



		tm = 8 - tm;

		while (true) {

			if (tm < 1)

				break;

			chkSum = "0" + chkSum;

			tm--;

		}

		if (chkSum.equals(StrchkSUM)) {

			// System.out.println(dataBuff);

			dataComplate.append(dataBuff);

			try {

				commPort.layout.statusTxt.add("Receive package number:"

						+ packetNo);

				commPort.updateStatus();

				if (mode.equals(commPort.SW)) {

					commPort.write("A");

				} else if (mode.equals(commPort.SR)) {

					// System.out.println("packetNo"+Integer.toString(packetNo));

					commPort.write(Integer.toString(packetNo));

				}



			} catch (Exception e) {

				// TODO Auto-generated catch block

				e.printStackTrace();

			}



		} else {

			try {

				commPort.write("N");

			} catch (IOException e) {

				// TODO Auto-generated catch block

				e.printStackTrace();

			}

		}



	}



	public static String Hex2Str(String src) {

		StringBuilder str = new StringBuilder();

		int lengthOfStr = src.length();

		String tm;

		for (int i = 0; i < lengthOfStr; i += 2) {

			tm = src.substring(0, 2);

			if (src.length() > 0) {

				src = src.substring(2);

			}

			// Convert hex to character

			str.append((char) (Integer.parseInt(tm, 16)));

		}

		return str.toString();

	}



	public static String chkSum(String data) {

		String chk = "";

		try {

			String string = new String(data);

			byte buffer[] = string.getBytes();

			ByteArrayInputStream bais = new ByteArrayInputStream(buffer);

			CheckedInputStream cis = new CheckedInputStream(bais, new Adler32());

			byte readBuffer[] = new byte[5];

			while (cis.read(readBuffer) >= 0) {

				long value = cis.getChecksum().getValue();

				chk = Long.toString(value);

			}

		} catch (Exception e) {

			System.out.println("Exception has been caught" + e);

			return null;

		}



		Object[] arg = { new BigInteger(chk) };

		return String.format("%x", arg);

	}

}