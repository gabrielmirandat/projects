public class TesteTiposOperadores{
  public static void main(String[] args){
    //a. primeiro atrbui e depois incrementa
      //int a = 2; int b = a++; System.out.println(b);
    //b. incrementa e depois atribui
      //int c = 2; int d = (++c); System.out.println(d);
    //c. pré-incrementar numa função incrementa mesmo. Espressão lógica resulta em false, pois false && true == false
      //int e = 0; boolean bol1 = (2<0) && (++e<3); System.out.println(bol1);
    //d. poś-incrementar numa função incrementa mesmo. NÃO ENTENDI
      //int f = 1; boolean bol2 = (2<1) && (f++>4); System.out.println(bol2);
    //e. ok
      int g = 3; int h= (g++== 4) ? 2:1; System.out.println(h);
  }
}