package unb.banco.interfaceUsuario;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;



public class UIFactory {

	public static UI create() {
		String nomeArqConfiguracao = System.getProperty("user.dir") + File.separator + "configuracao";
		Properties prop = new Properties();
		try {
			prop.load(new FileInputStream(nomeArqConfiguracao));
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}

		String nomeClasseUI = prop.getProperty("INTERFACE-USUARIO");
		UI interfaceUsuario = null;
		try {
			Class cRep = Class.forName(nomeClasseUI);
			interfaceUsuario = (UI) cRep.newInstance();
			} catch (InstantiationException | IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		 catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return interfaceUsuario;
	}
}
