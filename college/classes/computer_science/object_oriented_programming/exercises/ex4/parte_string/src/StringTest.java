public class StringTest {

	  public static void main(String args[]){
		  String s1 = new String("Jos�");
		  String s2 = new String("Jos�");

		  String s3 = "Jo�o";
		  String s4 = "Jo�o";

		  System.out.println("Tamanho de s1+s2:"+ (s1.length() + s2.length()));
		  System.out.println("s1 e s2 s�o iguais?:"+ s1.equals(s2));
		  System.out.println("s1 e s2 se referem ao mesmo objeto?:"+(s1==s2));

		  System.out.println("\ns3 e s4 s�o iguais?:"+ s3.equals(s4));
		  System.out.println("s3 e s4 se referem ao mesmo objeto?:"+(s3==s4));

		  s3 = "Maria";

		  System.out.println("\ns3 e s4 s�o iguais?:"+ s3.equals(s4));
		  System.out.println("s3 e s4 se referem ao mesmo objeto?:"+(s3==s4));
	  }

}
