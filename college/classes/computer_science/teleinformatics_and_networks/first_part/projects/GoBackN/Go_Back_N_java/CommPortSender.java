import java.io.IOException;

import java.io.OutputStream;



public class CommPortSender {



	static OutputStream out;



	public static void setWriterStream(OutputStream out) {

		CommPortSender.out = out;

	}



	public static void send(byte[] bytes) {

		try {

			if (out != null) {

				out.write(bytes);

				out.flush();

			}

		} catch (IOException e) {

			// e.printStackTrace();

		}

	}

}