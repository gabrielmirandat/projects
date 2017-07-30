import java.io.*;

import java.math.BigInteger;



public class InputStreamFile {

	public String getData(String path) {

		final String filename = path.substring(0, path.indexOf("."));

		final String dot = path.substring(path.indexOf(".") + 1);

		System.out.println(filename + "." + dot);

		try {

			File f = new File("outFile." + dot);

			File fout = new File("outFile.out");

			File facii = new File("outAcii.out");

			InputStream inputStream = new FileInputStream(filename + "." + dot);

			byte buf[] = new byte[5000];

			int len;

			String data = "";

			while ((len = inputStream.read(buf)) > 0) {

				data += Str2H(buf, len);

			}



			inputStream.close();



			return data;

		} catch (IOException e) {

			e.printStackTrace();

		}



		return "";

	}



	public String Str2H(byte[] str, int len)

			throws UnsupportedEncodingException {

		// byte n = str.getBytes("UTF-8");

		Object[] arg = { new BigInteger(str) };

		String buff = String.format("%x", arg);

		return buff.substring(0, len * 2);

	}



	/*

	 * change integer to hex base

	 */

	public String Int2H(String src) {



		Object[] arg = { src };

		return String.format("%x", arg);

	}



	public void fileWriter(String src, String filename) throws IOException {



		System.out.println(filename);

		int len;

		byte[] buf = new byte[5000];

		buf = src.getBytes();

		InputStream in = new StringBufferInputStream(src);

		File facii = new File(filename);

		OutputStream out2 = new FileOutputStream(facii);

		while ((len = in.read(buf)) > 0) {

			out2.write(buf, 0, len);

		}

		out2.close();

		in.close();

	}

}