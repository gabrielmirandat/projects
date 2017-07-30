import java.io.ByteArrayInputStream;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.zip.Adler32;
import java.util.zip.CheckedInputStream;
import java.util.*;

public class Packet {

	/**
	 * @param args
	 */
	final static String OPCODE = "7E";
	static private BigInteger _RUNN;
	static private BigInteger _LENGTH;
	static private BigInteger _CRC;
	static private String MLSB;
	static private String _MSB;
	static private String _LSB;
	static private String _LENG;
	static private String _DATA = "";
	static private String _CRCDATA;

	static private String Sep_ = "";
	static private StringBuilder _PACKET;

	public Packet() {
		_RUNN = new BigInteger("0");
		_LENGTH = new BigInteger("148");
		_CRC = new BigInteger("0");
		_PACKET = new StringBuilder();
	}

	public ArrayList<String> getPacket(String SRCh) {

		ArrayList<String> datapacket = new ArrayList<String>();
		while (true) {

			try {
				// Start create packet
				_PACKET.append(OPCODE); // Add opcode to head

				if (SRCh.length() < _LENGTH.intValue() * 2)
					_LENGTH = new BigInteger(
							Integer.toString(SRCh.length() / 2));

				// Section of data
				_DATA = SRCh.substring(0, _LENGTH.intValue() * 2);

				// Check for data
				if (_DATA.length() <= 0)
					break;

				// Set MSB and LSB
				MLSB = Int2H(_RUNN).toString();

				// Check for length and add digits to msb/lsb
				switch (MLSB.length()) {
				case 1:
					MLSB = "000" + MLSB;
					break;
				case 2:
					MLSB = "00" + MLSB;
					break;
				case 3:
					MLSB = "0" + MLSB;
					break;
				}
				// Check for digits of Length data
				_LENG = Int2H(_LENGTH).toString();
				if (_LENG.length() == 1)
					_LENG = "0" + _LENG;

				// Select MSB/LSB and add to frame
				_MSB = MLSB.substring(0, 2);
				_LSB = MLSB.substring(2);
				_PACKET.append(Sep_ + _MSB + _LSB);

				// Update MSB/LSB Length packet
				_RUNN = _RUNN.add(new BigInteger("1"));

				// Cal CRC
				// _CRC = getCRC(_DATA,Bi2Dec(GenCode));
				try {

					_PACKET.append(Sep_ + _LENG); // Add length of data
					_PACKET.append(Sep_ + _DATA); // Add Data to packet
					_CRC = new BigInteger(chkSum(_DATA));
					_CRCDATA = Int2H(_CRC);

					int tm = _CRCDATA.length();

					tm = 8 - tm;
					while (true) {
						if (tm < 1)
							break;
						_CRCDATA = "0" + _CRCDATA;
						tm--;
					}

					_PACKET.append(Sep_ + _CRCDATA); // Add CRC

					// Update Data tmp
					SRCh = SRCh.substring(_LENGTH.intValue() * 2);

					datapacket.add(_PACKET.toString());

				} catch (Exception e) {
					System.out.println("ERROR");
					e.printStackTrace();
					break;
				}
				// System.out.println(Hex2Str(getData(_PACKET.toString())));
				_PACKET = new StringBuilder();
			} catch (Exception e) {
				System.out.println("ERROR1");
				e.printStackTrace();
			}
		}

		return datapacket;

	}

	public static String Str2H(String str) throws UnsupportedEncodingException {
		Object[] arg = { new BigInteger(str.getBytes("UTF-8")) };
		return String.format("%x", arg);
	}

	/*
	 * change integer to hex base
	 */
	public static String Int2H(BigInteger src) {
		Object[] arg = { src };
		return String.format("%x", arg);
	}

	public static String Hex2Dec(String src) {
		return Integer.toString(Integer.parseInt(src, 16));
	}

	public static String Hex2Bi(String src) {

		return Integer.toString(Integer.parseInt(src, 16));
	}

	public static String Dec2Bi(String src) {
		return Integer.toBinaryString(Integer.parseInt(src));
	}

	public static String Bi2Dec(String src) {
		return Integer.toString(Integer.parseInt(src, 2));
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

	public static String getData(String src) {
		// Keep data
		StringBuilder str = new StringBuilder();
		// Get length of data string.
		int lengthOfData = Integer.parseInt(src.substring(6, 8), 16);
		// get data from packet
		// System.out.println("AA"+lengthOfData*2+"AA"+src.length());

		// Double to get in half byte
		lengthOfData *= 2;

		src = src.substring(8, 8 + lengthOfData);
		// System.out.println("<< "+lengthOfData+">>"+src.length());

		// Loop for get the data
		// Must divide 4 because real length unit in byte
		for (int i = 0; i < lengthOfData; i++) {
			str.append(src.charAt(i));
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
		return chk;
	}

	public String packageFilename(String src) {
		String str = "";
		String tm;
		str += "1111111111FF";
		str += Int2H(new BigInteger(Integer.toString(src.length())));
		try {
			str += Str2H(src);
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return str;
	}
}