import javax.sound.midi.InvalidMidiDataException;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.JProgressBar;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.EventQueue;
import java.awt.Image;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.File;

public class Test
{
	public static void main(String[] args) {
		String filePath, iconPath;
		filePath = new File("").getAbsolutePath();
		iconPath = filePath.concat("/../../content/images/evanesc.png");
		System.out.println(iconPath);
	}
}
