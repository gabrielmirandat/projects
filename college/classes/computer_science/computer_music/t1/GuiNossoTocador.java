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

public class GuiNossoTocador{
	 
	/**
	 * 
	 */
	private static JFrame frame;
	private static JTextField textField;
	private static JTextField textField_2;
	private static String filePath, iconPath, midiPath, bankPath, imagePath ;
	private int duracao;
	private int tempo_atual1, tempo_atual2;

	/**
	 * Lanca a aplicacao.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					 filePath = new File("").getAbsolutePath();
					 iconPath = (filePath.substring(0, filePath.length() - 13)).concat("/content/images/evanesc.png");
					 midiPath = filePath.concat("/../../content/midi_music/");
					 bankPath = filePath.concat("/../../content/midi_bank/");
					imagePath = (filePath.substring(0, filePath.length() - 13)).concat("/content/images/piano_2.png");
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
		textField_2 = new JTextField();
		final JLabel lblDurao = new JLabel("Dura\u00E7\u00E3o:");
		final JLabel lblFcompasso = new JLabel("F.Compasso:");
		final JLabel lblMetro = new JLabel("Metro:");
		final JLabel lblAndamento = new JLabel("Andamento:");
		final JLabel lblAtonalidade = new JLabel("A.Tonalidade:");
		final JLabel label_1 = new JLabel("   --------   ");
		final JLabel label_2 = new JLabel("   --------   ");
		final JLabel label_3 = new JLabel("   --------   ");
		final JLabel label_4 = new JLabel("   --------   ");
		final JLabel label_5 = new JLabel("   --------   ");
		final JLabel label = new JLabel();
		
		final JButton btnMusica = new JButton("\u274F"); //botao abrir
		final JButton btnOrquestra = new JButton("\u266B"); //botao selecionar banco
		final JButton btnTocar = new JButton("\u25BA"); 	//botao tocar
		final JButton btnPausar = new JButton("\u25ae"+"\u25ae");	//botao pausar
		final JButton btnParar = new JButton("\u25A0");	//botao parar
		final JButton btnAndam = new JButton("\u2190");	//botao diminuir andamento em -5
		final JButton btnAndamm = new JButton("\u21C7");	//botao diminuir andamento em -25
		final JButton btnAndaM = new JButton("\u2192");	//botao aumentar andamento em +5
		final JButton btnAndaMM = new JButton("\u21C9");	//botao aumentar andamento em +25
		final JButton btnAndaN = new JButton("\u21C4");	//botao setar andamento inicial
		final JButton btnVol = new JButton();				//botao setar porcentagem do volume
		final JSlider slider = new JSlider();				//slider setar de onde comecar musica
		final JSlider slider_2 = new JSlider();			//slider do volume
		final JProgressBar progressBar = new JProgressBar();	//barra de progresso da musica

		ImageIcon logo = new ImageIcon("/home/gabriel/Documentos/projects/Programs/undergraduate/computer_music/content/images/evanesc.png");
		frame.setIconImage(logo.getImage()); 

		//-- janela principal 
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setResizable(false);
		
		//-- campo texto para musica carregada
		textField.setBounds(86, 64, 157, 20);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		textField.setEditable(false);
		
		//-- campo texto para banco carregada
		textField_2.setBounds(86, 96, 157, 20);
		frame.getContentPane().add(textField_2);
		textField_2.setColumns(10);
		textField_2.setEditable(false);
		
		//-- botao carregar musica
		btnMusica.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try{
					//-- interface para carregar um arquivo midi
					JFileChooser escolha = new JFileChooser(midiPath);
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
						duracao = tocador.obterDuracaoSegundos();
						progressBar.setMaximum((int)tocador.obterTicksTotal());
						label_1.setText(tocador.saidaTempoFormatado(duracao));
						label_2.setText(tocador.getFormulaDeCompasso());
						label_3.setText(tocador.getMetro());
						label_4.setText(tocador.getAndamento());
						label_5.setText(tocador.getTonalidade());
				    	btnTocar.setEnabled(true);
						btnPausar.setEnabled(false);
						btnParar.setEnabled(false);
						progressBar.setValue(0);
						slider_2.setValue(65);
						btnVol.setText("50%");
						tocador.mudarVolume(slider_2.getValue());
						tocador.espera(1000);
					}
				}catch (Exception ex) {}
			}
		});
		btnMusica.setBounds(24, 63, 52, 23);
		frame.getContentPane().add(btnMusica);
		
		//-- botao selecionar orquestra
		btnOrquestra.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try{
					//-- interface para carregar um banco midi
					JFileChooser escolha = new JFileChooser(bankPath);
					escolha.setFileSelectionMode(JFileChooser.FILES_ONLY);              
		            escolha.setFileFilter(new FileFilter()
		            {
		                public boolean accept(File f)
		                {
		                    if (!f.isFile()) return true;
		                    String name = f.getName().toLowerCase();
		                    if (name.endsWith(".sf2"))  return true;
		                    if (name.endsWith(".gm"))  return true;
		                    return false;
		                }

		                public String getDescription()
		                { return "Arquivo Midi (*.sf2, *.gm)";
		                }
		            });
		            
					int retorno = escolha.showOpenDialog(frame);
					
					if(retorno == JFileChooser.APPROVE_OPTION) {
					    textField_2.setText(escolha.getSelectedFile().getName());
						System.out.println(escolha.getSelectedFile().getName());
					    InputStream caminho = new BufferedInputStream(new FileInputStream(escolha.getSelectedFile().getAbsolutePath()));
				    	tocador.carregar_soundbank(caminho,escolha.getSelectedFile().getName());
						btnTocar.setEnabled(true);
						btnPausar.setEnabled(false);
						btnParar.setEnabled(false);
						tocador.espera(1000);
					}
				}catch (Exception ex) {}
			}
		});
		btnOrquestra.setBounds(24, 95, 52, 23);
		frame.getContentPane().add(btnOrquestra);
		
		//-- botao tocar musica
 		btnTocar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				tocador.tocar(slider_2.getValue());
				btnTocar.setEnabled(false);
				btnMusica.setEnabled(false);
				btnOrquestra.setEnabled(false);
				btnPausar.setEnabled(true);
				btnParar.setEnabled(true);
				Thread t1 = new Thread(new Runnable() {
				     public void run() {
				    	 while(true){
				 				progressBar.setStringPainted(true);
				 				tempo_atual1 = tocador.obterDecorridoSegundos();
				 				String tempo_formatado = tocador.saidaTempoFormatado(tempo_atual1);
				 				progressBar.setIndeterminate(false);
				 				progressBar.setValue((int)tocador.obterTickAtual());
				 				progressBar.setString(tempo_formatado);
				 				tempo_atual2 = tocador.obterDecorridoSegundos();
				 				while(tempo_atual2== tempo_atual1)
				 					tempo_atual2 = tocador.obterDecorridoSegundos();
				 				if(!tocador.estaTocando())
				 					break;
				 		 }
				     }
				});  
				t1.start();
			}
		});
		btnTocar.setBounds(24, 129, 52, 23);
		frame.getContentPane().add(btnTocar);
		
		//-- botao pausar musica
		btnPausar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tocador.pausar();
				btnTocar.setEnabled(true);
				btnPausar.setEnabled(false);
			}
		});
		btnPausar.setBounds(24, 163, 52, 23);
		frame.getContentPane().add(btnPausar);
		
		//-- botao parar musica
		btnParar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(tocador.obterDecorridoSegundos() != 0){
					progressBar.setString("0:00:00");
					progressBar.setValue(0);
				}
				tocador.parar();
				btnMusica.setEnabled(true);
				btnOrquestra.setEnabled(true);
				btnTocar.setEnabled(true);
				btnPausar.setEnabled(false);
				btnParar.setEnabled(false);
			}
		});
		btnParar.setBounds(24, 197, 52, 23);
		frame.getContentPane().add(btnParar);
		
		//-- slider de setar inicio
		slider.setValue(0);
		slider.addMouseListener(new MouseAdapter() {
			public void mouseReleased(MouseEvent e) {
				tocador.iniciarDe(slider.getValue(), slider.getMaximum(), slider_2.getValue());
			}
		});
		slider.setMaximum(10000);
		slider.setBounds(253, 93, 181, 23);
		frame.getContentPane().add(slider);
		
		//--slider de volume
		slider_2.addMouseListener(new MouseAdapter() {
			public void mouseReleased(MouseEvent e) {
				tocador.mudarVolume(slider_2.getValue());
				btnVol.setText((int)(((double)slider_2.getValue()/slider_2.getMaximum())*100) + "%");
			}
		});
		slider_2.setMaximum(127);
		slider_2.setBounds(24, 231, 157, 23);
		slider_2.setValue(65);
		frame.getContentPane().add(slider_2);
		
		
		//-- Barra de progresso da musica
		progressBar.setBounds(253, 64, 181, 20);
		progressBar.setIndeterminate(true);
		frame.getContentPane().add(progressBar);
		
		//-- Label para mostrar duracao
		lblDurao.setBounds(253, 132, 72, 14);
		frame.getContentPane().add(lblDurao);
		
		//-- Label para mostrar formula de compasso
		lblFcompasso.setBounds(253, 150, 72, 14);
		frame.getContentPane().add(lblFcompasso);
		
		//-- Label para mostrar metro
		lblMetro.setBounds(253, 168, 72, 14);
		frame.getContentPane().add(lblMetro);
		
		//-- Label para mostrar andamento
		lblAndamento.setBounds(253, 186, 72, 14);
		frame.getContentPane().add(lblAndamento);
		
		//-- Label para mostrar armadura de tonalidade
		lblAtonalidade.setBounds(253, 204, 72, 14);
		frame.getContentPane().add(lblAtonalidade);
		
		//-- label duracao
		label_1.setBounds(335, 132, 99, 14);
		frame.getContentPane().add(label_1);
		
		//-- label formula de compasso
		label_2.setBounds(335, 150, 99, 14);
		frame.getContentPane().add(label_2);
		
		//-- label metro
		label_3.setBounds(335, 168, 99, 14);
		frame.getContentPane().add(label_3);
		
		//-- label andamento
		label_4.setBounds(335, 186, 99, 14);
		frame.getContentPane().add(label_4);
		
		//-- label armadura de tonalidade
		label_5.setBounds(335, 204, 99, 14);
		frame.getContentPane().add(label_5);
		
		
		//-- diminuir andamento em -5
		btnAndam.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					tocador.setAndamento(-5);
					progressBar.setValue((int)(tocador.obterTickAtual()));
					label_4.setText(tocador.getNovoAndamento());
				} catch (InvalidMidiDataException e1) {};
			}	
		});
		btnAndam.setBounds(115, 129, 46, 23);
		frame.getContentPane().add(btnAndam);
		
		//-- diminuir andamento em -25
		btnAndamm.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					tocador.setAndamento(-25);
					progressBar.setValue((int)(tocador.obterTickAtual()));
					label_4.setText(tocador.getNovoAndamento());
				} catch (InvalidMidiDataException e1) {};
			}	
		});
		btnAndamm.setBounds(115, 163, 46, 23);
		frame.getContentPane().add(btnAndamm);
		
		//-- aumentar andamento em +5
		btnAndaM.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					tocador.setAndamento(5);
					progressBar.setValue((int)(tocador.obterTickAtual()));
					label_4.setText(tocador.getNovoAndamento());
				} catch (InvalidMidiDataException e1) {};
			}	
		});
		btnAndaM.setBounds(171, 129, 46, 23);
		frame.getContentPane().add(btnAndaM);
		
		//-- aumentar andamento em +25
		btnAndaMM.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					tocador.setAndamento(25);
					progressBar.setValue((int)(tocador.obterTickAtual()));
					label_4.setText(tocador.getNovoAndamento());
				} catch (InvalidMidiDataException e1) {};
			}	
		});
		btnAndaMM.setBounds(171, 163, 46, 23);
		frame.getContentPane().add(btnAndaMM);
		
		//-- coloca andamento padrão
		btnAndaN.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					tocador.setAndamento(0);
					progressBar.setValue((int)(tocador.obterTickAtual()));
					label_4.setText(tocador.getNovoAndamento());
				} catch (InvalidMidiDataException e1) {};
			}	
		});
		btnAndaN.setBounds(171, 197, 46, 23);
		frame.getContentPane().add(btnAndaN);

		
		//-- botao porcentagem do volume
		btnVol.setBounds(86, 197, 75, 23);
		frame.getContentPane().add(btnVol);
		btnVol.setEnabled(false);
		btnVol.setText("50%");
		
		
		//-- Imagem no JFrame
		ImageIcon piano_im = new ImageIcon("/home/gabriel/Documentos/projects/Programs/undergraduate/computer_music/content/images/piano_2.png");
		label.setIcon(piano_im);
		label.setBounds(0, 0, 450, 300);
		frame.getContentPane().add(label);
		
	}
}
