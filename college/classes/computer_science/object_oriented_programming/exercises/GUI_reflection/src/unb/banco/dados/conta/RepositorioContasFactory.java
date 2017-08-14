package unb.banco.dados.conta;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class RepositorioContasFactory {

	public static RepositorioContas create() {

		String nomeArqConfiguracao = System.getProperty("user.dir") + File.separator + "configuracao";
		Properties prop = new Properties();
		try {
			prop.load(new FileInputStream(nomeArqConfiguracao));
		} catch (IOException ioe) {
			
		}

		String nomeClassePersistencia = prop.getProperty("PERSISTENCIA-CLASSE-CONTAS");
		RepositorioContas repContas = null;
		try {
			Class cRep = Class.forName(nomeClassePersistencia);
			try {
				repContas = (RepositorioContas) cRep.newInstance();
			} catch (InstantiationException | IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return repContas;
		
	}


}
