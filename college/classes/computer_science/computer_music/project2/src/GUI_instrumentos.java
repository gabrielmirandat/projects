import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JSlider;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

import sintese.*;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.EventQueue;
import java.awt.Image;
import javax.swing.JTextField;


public class GUI_instrumentos{
	private float seletividade = 0.000000f;
	private float andamento = 1.0f;
	Envoltoria   env1,env2,env3;   
	Curva        curva1,curva2, curva3;      
	private JFrame frame;
	Dispositivo inst = new Dispositivo();
	Melodia mel = new Melodia();
    Som som;
    private JTextField textField;

	/**
	 * Lanca a aplicacao.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI_instrumentos window = new GUI_instrumentos();
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
	public GUI_instrumentos() {
		env1   = new Envoltoria(); 
		env2	= new Envoltoria();
		env3	= new Envoltoria();
	    curva1 = new Curva(720);  
	    curva2 = new Curva(720);
	    curva3 = new Curva(720);

	    curva1.addPonto(  0f,   0f);
	    curva1.addPonto( 30f, 400f);
	    curva1.addPonto(240f, 300f);
	    curva1.addPonto(720f,   0f);
	     
	    curva2.addPonto(  0f,   1000f);
	    curva2.addPonto( 720f,  1000f);
	    
	    curva3.addPonto(  0f,   350f);
	    curva3.addPonto( 720f,  350f);
	    
	    
	    env1.setCURVA(curva1);
	    env2.setCURVA(curva2);
	    env3.setCURVA(curva3);
	    
		initialize();
	}

	/**
	 * Inicializa conteudo do frame.
	 */
	private void initialize() {
		frame = new JFrame("Trabalho 2: Instrumentos");
		final JLabel label = new JLabel();
		
		JButton btnInst1 = new JButton("Inst.1");
		JButton btnInst2 = new JButton("Inst.2");
		JButton btnInst3 = new JButton("Inst.3");
		JButton btnMel1 = new JButton("Mel.1");
		JButton btnMel2 = new JButton("Mel.2");
		JButton btnMel3 = new JButton("Mel.3");
		JSlider slider = new JSlider();
		JButton btnTocar = new JButton("\u25BA");
		JButton btnOnda = new JButton("Onda");


		ImageIcon logo = new javax.swing.ImageIcon(getClass().getResource("evanesc.png"));
		frame.setIconImage(logo.getImage()); 

		//-- janela principal 
		frame.setBounds(100, 100, 367, 198);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setResizable(false);
		

		//-- seleciona instrumento 1
		btnInst1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				inst = null;
				inst  = new InstrumentoT2A(seletividade);
				((InstrumentoT2A) inst).setEnvoltoria(env1);
			    ((InstrumentoT2A) inst).setLambda(0.5f);
			    ((InstrumentoT2A) inst).setFase(0f);
			    ((InstrumentoT2A) inst).setGanho(103);
			    btnMel1.setEnabled(true);
			    btnMel2.setEnabled(true);
			    btnMel3.setEnabled(true);
			    btnInst1.setEnabled(false);
			    btnInst2.setEnabled(true);
			    btnInst3.setEnabled(true);
			}
		});
		btnInst1.setBounds(10, 11, 65, 23);
		frame.getContentPane().add(btnInst1);
		
		//-- seleciona instrumento 2
		btnInst2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				inst = null;
				inst  = new InstrumentoT2B(seletividade);
				((InstrumentoT2B) inst).setEnvoltoria(env1,env2, env3);
			    ((InstrumentoT2B) inst).setLambda(0.5f);
			    ((InstrumentoT2B) inst).setFase(0f);
			    ((InstrumentoT2B) inst).setGanho(103);
			    btnMel1.setEnabled(true);
			    btnMel2.setEnabled(true);
			    btnMel3.setEnabled(true);
			    btnInst2.setEnabled(false);
			    btnInst1.setEnabled(true);
			    btnInst3.setEnabled(true);
			}
		});
		btnInst2.setBounds(10, 45, 65, 23);
		frame.getContentPane().add(btnInst2);
		
		//-- seleciona instrumento 3
		btnInst3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				inst = null;
				inst  = new InstrumentoT2C(seletividade);
			    ((InstrumentoT2C) inst).setEnvoltoria(env1,env2, env3, env3);
			    ((InstrumentoT2C) inst).setLambda(0.5f);
			    ((InstrumentoT2C) inst).setFase(0f);
			    ((InstrumentoT2C) inst).setGanho(103);
			    btnMel1.setEnabled(true);
			    btnMel2.setEnabled(true);
			    btnMel3.setEnabled(true);
			    btnInst3.setEnabled(false);
			    btnInst1.setEnabled(true);
			    btnInst2.setEnabled(true);
			}
		});
		btnInst3.setBounds(10, 79, 65, 23);
		frame.getContentPane().add(btnInst3);
		
		//-- seleciona melodia 1
		btnMel1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				mel = null;
				mel = Melodia1.prepara(inst);
				btnMel1.setEnabled(false);
				btnTocar.setEnabled(true);
				btnOnda.setEnabled(true);
				btnMel2.setEnabled(true);
				btnMel3.setEnabled(true);
			}
		});
		btnMel1.setBounds(85, 11, 65, 23);
		frame.getContentPane().add(btnMel1);
		btnMel1.setEnabled(false);
		
		//-- seleciona melodia 2
		btnMel2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				mel = null;
				mel = Melodia2.prepara(inst);
				btnMel2.setEnabled(false);
				btnTocar.setEnabled(true);
				btnOnda.setEnabled(true);
				btnMel1.setEnabled(true);
				btnMel3.setEnabled(true);
			}
		});
		btnMel2.setBounds(85, 45, 65, 23);
		frame.getContentPane().add(btnMel2);
		btnMel2.setEnabled(false);
		
		
		//-- seleciona melodia 3
		btnMel3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				mel = null;
				mel = Melodia3.prepara(inst);
				btnMel3.setEnabled(false);
				btnTocar.setEnabled(true);
				btnOnda.setEnabled(true);
				btnMel1.setEnabled(true);
				btnMel2.setEnabled(true);
			}
		});
		btnMel3.setBounds(85, 79, 65, 23);
		frame.getContentPane().add(btnMel3);
		btnMel3.setEnabled(false);
		
		
		JLabel lblAndamento = new JLabel("Andamento:0.95~1.05");
		lblAndamento.setBounds(160, 11, 140, 14);
		frame.getContentPane().add(lblAndamento);
		
		JLabel lblSeletividade = new JLabel("Seletividade:        0~1");
		lblSeletividade.setBounds(160, 60, 191, 14);
		frame.getContentPane().add(lblSeletividade);
		
		//-- slider do andamento
		slider.addMouseListener(new MouseAdapter() {
			public void mouseReleased(MouseEvent e) {
				andamento = (float) (slider.getValue()/1000.0);
				mel.setAndamento(andamento);
				lblAndamento.setText("Andamento: " + String.valueOf(andamento));
			}
		});
		slider.setMinimum(950);
		slider.setMaximum(1050);
		slider.setBounds(160, 26, 191, 23);
		frame.getContentPane().add(slider);
		slider.setValue(100);
		
		
		//-- texto da seletividade
		textField = new JTextField();
		textField.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try { 
					seletividade = Float.valueOf(textField.getText());
					mel.setAndamento(andamento);
					lblSeletividade.setText("Seletividade: " + seletividade);
				}catch(Exception ex){
					lblSeletividade.setText("Valor n\u00E1o v\u00E1lido!");
				}
			}
		});
		textField.setBounds(160, 80, 191, 20);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		textField.setText(String.valueOf(seletividade));

		
		//-- botao tocar
		btnTocar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				mel.setAndamento(andamento);
				som = mel.getSom(inst);
				som.salvawave();
			    som.tocawave();
			}
		});
		btnTocar.setBounds(106, 125, 65, 23);
		frame.getContentPane().add(btnTocar);
		btnTocar.setEnabled(false);
		
		
		//-- forma da onda
		btnOnda.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				mel.setAndamento(andamento);
				som = mel.getSom(inst);
			    som.salvawave();
			    som.visualiza();
			}
		});
		btnOnda.setBounds(195, 125, 65, 23);
		frame.getContentPane().add(btnOnda);
		btnOnda.setEnabled(false);



		//-- Imagem no JFrame
		Image piano_im = new ImageIcon(this.getClass().getResource("piano_2.png")).getImage();
		label.setIcon(new ImageIcon(piano_im));
		label.setBounds(0, 0, 361, 174);
		frame.getContentPane().add(label);
	}
}
