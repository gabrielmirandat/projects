import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JTextArea;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.EventQueue;
import java.awt.Image;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.File;

import java.io.FileReader;

public class GuiNossoTocador{
	 
	/**
	 * 
	 */
	private JFrame frame;
	private JTextField textField;
	int duracao;
	int tempo_atual;

	/**
	 * Lanca a aplicacao.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GuiNossoTocador window = new GuiNossoTocador();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Cria a aplicacao.
	 */
	public GuiNossoTocador() {
		initialize();
	}

	/**
	 * Inicializa conteudo do frame.
	 */
	private void initialize() {
		final NossoTocador tocador = new NossoTocador();
		frame = new JFrame("NossoTocador");
		textField = new JTextField();
		final JLabel label = new JLabel();
		
		final JButton btnCarregar = new JButton("Carregar");
		final JButton btnConverter = new JButton("Converter");
		final JButton btnMidis = new JButton("Dados MIDI");
		final JButton btnSintese = new JButton("Dados Sintese");
		final JButton btnInstrumentos = new JButton("Dados instrumentos");
		JTextArea textArea = new JTextArea();
		//JTextArea textArea = new JTextArea(20, 20);

		ImageIcon logo = new javax.swing.ImageIcon(getClass().getResource("evanesc.png"));
		frame.setIconImage(logo.getImage()); 

		//-- janela principal 
		frame.setBounds(100, 100, 381, 221);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setResizable(false);
		
		//-- campo texto para musica carregada
		textField.setBounds(129, 12, 157, 20);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		textField.setEditable(false);
		
		//-- botao carregar musica
		btnCarregar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try{
					//-- interface para carregar um arquivo midi
					JFileChooser escolha = new JFileChooser(".");
					escolha.setFileSelectionMode(JFileChooser.FILES_ONLY);              
		            escolha.setFileFilter(new FileFilter()
		            {
		                public boolean accept(File f)
		                {
		                    if (!f.isFile()) return true;
		                    String name = f.getName().toLowerCase();
		                    if (name.endsWith(".mid"))  return true;
		                    if (name.endsWith(".midi")) return true;
		                    return false;
		                }

		                public String getDescription()
		                { return "Arquivo Midi (*.mid,*.midi)";
		                }
		            });
		            
					int retorno = escolha.showOpenDialog(frame);
					
					if(retorno == JFileChooser.APPROVE_OPTION) {
					    textField.setText(escolha.getSelectedFile().getName());
					    InputStream caminho = new BufferedInputStream(new FileInputStream(escolha.getSelectedFile().getAbsolutePath()));
				    	tocador.carregar_musica(caminho);
						tocador.get_valores();
						tocador.espera(1000);
						btnConverter.setEnabled(true);
						btnMidis.setEnabled(false);
						btnSintese.setEnabled(false);
						btnInstrumentos.setEnabled(false);
					}
				}catch (Exception ex) {}
			}
		});
		btnCarregar.setBounds(10, 11, 111, 23);
		frame.getContentPane().add(btnCarregar);
		
		//-- botao converter
 		btnConverter.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				tocador.cria_arquivo();
				btnConverter.setEnabled(false);
				btnMidis.setEnabled(true);
				btnSintese.setEnabled(true);
				btnInstrumentos.setEnabled(true);
				tocador.espera(1000);
			}
		});
		btnConverter.setBounds(10, 42, 111, 23);
		frame.getContentPane().add(btnConverter);
		//btnConverter.setEnabled(false);
		
		//-- botao dados MIDI
		btnMidis.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try{
					BufferedReader in = new BufferedReader(new FileReader("dados_midi.txt"));
					String line = in.readLine();
					textArea.setText(null);
					while(line != null){
					  textArea.append(line + "\n");
					  line = in.readLine();
					}
					in.close();
				}catch (Exception ex) {}
			}
		});
		btnMidis.setBounds(10, 76, 111, 23);
		frame.getContentPane().add(btnMidis);
		btnMidis.setEnabled(false);
		
		//-- botão dados Sintese
		btnSintese.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try{
					BufferedReader in = new BufferedReader(new FileReader("dados_sintese.txt"));
					String line = in.readLine();
					textArea.setText(null);
					while(line != null){
					  textArea.append(line + "\n");
					  line = in.readLine();
					}
					in.close();
				}catch (Exception ex) {}
			}
		});
		btnSintese.setBounds(10, 110, 111, 23);
		frame.getContentPane().add(btnSintese);
		btnSintese.setEnabled(false);
		
		//-- botao dados instrumentos
		btnInstrumentos.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try{
					BufferedReader in = new BufferedReader(new FileReader("dados_inst.txt"));
					String line = in.readLine();
					textArea.setText(null);
					while(line != null){
					  textArea.append(line + "\n");
					  line = in.readLine();
					}
					in.close();
				}catch (Exception ex) {}
			}
		});
		btnInstrumentos.setBounds(10, 144, 111, 23);
		frame.getContentPane().add(btnInstrumentos);
		btnInstrumentos.setEnabled(false);

		// Área de texto
		JScrollPane scr = new JScrollPane(textArea,
                JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
                JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);// Add your text area to scroll pane 
        textArea.setBounds(5, 35, 385, 385);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setEditable(false);
        scr.setBounds(139, 43, 213, 139);// You have to set bounds for all the controls and containers incas eof null layout
        frame.getContentPane().add(scr);// Add you scroll pane to container
		
		
		//-- Imagem no JFrame
		Image piano_im = new ImageIcon(this.getClass().getResource("piano_2.png")).getImage();
		label.setIcon(new ImageIcon(piano_im));
		label.setBounds(-34, 0, 411, 221);
		frame.getContentPane().add(label);


	}
}
