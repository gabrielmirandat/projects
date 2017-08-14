import java.io.FileFilter;



import javax.swing.JFileChooser;



import java.io.File;



public class WaitTime extends Thread implements Runnable {

	CommPortOpen commPort;



	public void run() {

		// while(true){

		try {

			// Sleep for wait time follow user select and by 1000

			// This is get value from index of Selection because we can get

			// Integer

			

			Thread.sleep(1000 * (commPort.layout.timewait.getSelectedIndex() + 1));

			//System.out.println("Send Repeat");

			commPort.stopAndwait();

		} catch (InterruptedException e) {

			this.stop();

			return;

		}

		// }

	}



	public WaitTime(CommPortOpen commPort) {

		this.commPort = commPort;

		
		this.start();

	}

}