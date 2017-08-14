package unb.banco.dados.cliente;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class RepositorioClientesFactory {

	public static RepositorioClientes create() {
		String nomeArqConfiguracao = System.getProperty("user.dir") + File.separator + "configuracao";
		Properties prop = new Properties();
		try {
			prop.load(new FileInputStream(nomeArqConfiguracao));
		} catch (IOException ioe) {
			
		}

		String nomeClassePersistencia = prop.getProperty("PERSISTENCIA-CLASSE-CLIENTES");
		RepositorioClientes repClientes = null;
		try {
			Class cRep = Class.forName(nomeClassePersistencia);
			try {
				repClientes = (RepositorioClientes) cRep.newInstance();
			} catch (InstantiationException | IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return repClientes;
	}
}
