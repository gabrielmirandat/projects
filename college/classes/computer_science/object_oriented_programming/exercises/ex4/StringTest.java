

class StringTest {

  public static void main(String args[]){
    String s1 = new String("Klio");
    String s2 =new String("Klio");
     int t = s1.length()+s2.length();
    System.out.println(" tamanho = "+t);
    System.out.println("o conteudo s1 e s2 sao iguais? "+s1.equals(s2));
     System.out.println("os obejtos s1 e s2 sao iguais? "+(s1 ==s2));

	String s3 = "Klio";
	String s4 = "Klio";
	System.out.println("o conteudo s3 e s4 sao iguais? "+s3.equals(s4));
	System.out.println("os obejtos s3 e s4 sao iguais? "+(s3 ==s4));

    s3 = "K";
     System.out.println("o conteudo s1 e s2 sao iguais? "+s3.equals(s4));
     System.out.println("os obejtos s1 e s2 sao iguais? "+(s3 ==s4));
  }
}