import java.io.IOException;

import java.util.ArrayList;



public class InterrupSender extends Thread implements Runnable {

	CommPortOpen commPort;



	public void run() {

		while (commPort.currentSendPacket < commPort.datapacket.size()) {

			try {

				Thread.sleep(1);

				try {

					commPort.write(commPort.datapacket

							.get(commPort.currentSendPacket++));

				} catch (IOException e) {

					// TODO Auto-generated catch block

					e.printStackTrace();

				}

			} catch (InterruptedException x) {

				this.stop();

				return;

			}

		}

		// System.out.println("in run() - leaving normally");

	}



	public InterrupSender(CommPortOpen commPort) {

		this.commPort = commPort;

		this.start();

	}

}