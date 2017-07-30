  "Classes envelopadas(Integer, Long, Byte, Double, Float, Short) subclasses da classe abstrata Number(pacote java.lang)".
	Integer x =5; // boxes int to an Integer object
	x = x + 10;// unboxes the Integer to a int
	
1 xxxValue() Converts the value of this Number object to the xxx data type and returned it.
	Integer x=5;
	// Returns byte primitive data type
	System.out.println(x.byteValue());//5
	// Returns double primitive data type
	System.out.println(x.doubleValue());//5.0
	// Returns long primitive data type
	System.out.println(x.longValue());//5
2 compareTo() Compares this Number object to the argument.
	Integer x = 5;
	System.out.println(x.compareTo(3));//1
	System.out.println(x.compareTo(5));//0
	System.out.println(x.compareTo(8));//-1
3 equals() Determines whether this number object is equal to the argument.
	Integer x = 5;
	Integer y = 10;
	Integer z = 5; 
	Short a = 5; 
	System.out.println(x.equals(y));//false
	System.out.println(x.equals(z));//true
	System.out.println(x.equals(a));//false
4 valueOf() Returns an Integer object holding the value of the specified primitive.
	Integer x = Integer.valueOf(9);
	Double c = Double.valueOf(5);
	Float a = Float.valueOf("80");
	Integer b = Integer.valueOf("444",16);
	System.out.println(x);//9
	System.out.println(c);//5.0
	System.out.println(a);//80.0
	System.out.println(b);//1092
5 toString() Returns a String object representing the value of specified int or Integer.
	Integer x = 5;
	System.out.println(x.toString());//5
	System.out.println(Integer.toString(12));//12
6 parseInt() This method is used to get the primitive data type of a certain String.
	int x = Integer.parseInt("9");
	double c =Double.parseDouble("5");
	int b =Integer.parseInt("444",16);
	System.out.println(x);//9
	System.out.println(c);//5.0
	System.out.println(b)//1092
7 abs() Returns the absolute value of the argument.
	Integer a =-8;
	double d =-100;
	float f =-90;
	System.out.println(Math.abs(a));//8
	System.out.println(Math.abs(d));//100.0
	System.out.println(Math.abs(f));//90.0
8 ceil() Returns the smallest integer that is greater than or equal to the argument. Returned as a double.
9 floor() Returns the largest integer that is less than or equal to the argument. Returned as a double.	
	double d =-100.675;
	float f =-90;
	System.out.println(Math.ceil(d));//-100.0
	System.out.println(Math.ceil(f));//-90.0
	System.out.println(Math.floor(d));//-101.0
	System.out.println(Math.floor(f));//-90.0
10 rint() Returns the integer that is closest in value to the argument. Returned as a double.
	double d =100.675;
	double e =100.500;
	double f =100.200;
	System.out.println(Math.rint(d));//101.0
	System.out.println(Math.rint(e));//100.0
	System.out.println(Math.rint(f));//100.0
11 round() Returns the closest long or int, as indicated by the method's return type, to the argument.
	double d =100.675;	//long
	double e =100.500;	//long
	float f =100;		//int
	float g =90f;		//int
	System.out.println(Math.round(d));//101
	System.out.println(Math.round(e));//101
	System.out.println(Math.round(f));//100
	System.out.println(Math.round(g));//90
12 min() Returns the smaller of the two arguments.
	System.out.println(Math.min(12.123,12.456));//12.123
	System.out.println(Math.min(23.12,23.0));//23.0
13 max() Returns the larger of the two arguments.
	System.out.println(Math.max(12.123,12.456));//12.456
	System.out.println(Math.max(23.12,23.0));//23.12
14 exp() Returns the base of the natural logarithms, e, to the power of the argument.
	double x =11.635;
	double y =2.76;
	System.out.printf("The value of e is %.4f%n",Math.E);//The value of e is 2.7183
	System.out.printf("exp(%.3f) is %.3f%n",x,Math.exp(x));//exp(11.635) is 112983.831
15 log() Returns the natural logarithm of the argument.
	double x =11.635;
	double y =2.76;
	System.out.printf("The value of e is %.4f%n",Math.E);//The value of e is 2.7183
	System.out.printf("log(%.3f) is %.3f%n",x,Math.log(x));//log(11.635) is 2.454
16 pow() Returns the value of the first argument raised to the power of the second argument.
	double x =11.635;
	double y =2.76;
	System.out.printf("The value of e is%.4f%n",Math.E);//The value of e is 2.7183
	System.out.printf("pow(%.3f,%.3f) is %.3f%n",x,y,Math.pow(x, y));//pow(11.635, 2.760) is 874.008
17 sqrt() Returns the square root of the argument.
	double x =11.635;
	double y =2.76;
	System.out.printf("The value of e is %.4f%n",Math.E);//The value of e is 2.7183
	System.out.printf("sqrt(%.3f) is %.3f%n",x,Math.sqrt(x));//sqrt(11.635) is 3.411
18 sin() Returns the sine of the specified double value.
	double degrees =45.0;
	double radians =Math.toRadians(degrees);
	System.out.format("The value of pi is %.4f%n",Math.PI);//The value of pi is 3.1416
	System.out.format("The sine of %.1f degrees is %.4f%n",degrees,Math.sin(radians));//The sine of 45.0 degrees is 0.7071
19 cos() Returns the cosine of the specified double value.
	double degrees =45.0;
	double radians =Math.toRadians(degrees);
	System.out.format("The value of pi is %.4f%n",Math.PI);//The value of pi is 3.1416
	System.out.format("The cosine of %.1f degrees is %.4f%n",degrees,Math.cos(radians));//The cosine of 45.0 degrees is 0.7071
20 tan() Returns the tangent of the specified double value.
	double degrees =45.0;
	double radians =Math.toRadians(degrees);
	System.out.format("The value of pi is %.4f%n",Math.PI);//The value of pi is 3.1416
	System.out.format("The tangent of %.1f degrees is %.4f%n",degrees,Math.tan(radians));//The tangent of 45.0 degrees is 1.0000
21 asin() Returns the arcsine of the specified double value.
	double degrees =45.0;
	double radians =Math.toRadians(degrees);
	System.out.format("The value of pi is %.4f%n",Math.PI);//The value of pi is 3.1416
	System.out.format("The arcsine of %.4f is %.4f degrees %n",Math.sin(radians),Math.toDegrees(Math.asin(Math.sin(radians))));//The arcsine of 0.7071 is 45.0000 degrees
22 acos() Returns the arccosine of the specified double value.
	double degrees =45.0;
	double radians =Math.toRadians(degrees);
	System.out.format("The value of pi is %.4f%n",Math.PI);//The value of pi is 3.1416
	System.out.format("The arccosine of %.4f is %.4f degrees %n",Math.cos(radians),Math.toDegrees(Math.acos(Math.sin(radians))));//The arccosine of 0.7071 is 45.0000 degrees
23 atan() Returns the arctangent of the specified double value.
	double degrees =45.0;
	double radians =Math.toRadians(degrees);
	System.out.format("The value of pi is %.4f%n",Math.PI);//The value of pi is 3.1416
	System.out.format("The arctangent of %.4f is %.4f degrees %n",Math.cos(radians),Math.toDegrees(Math.atan(Math.sin(radians))));//The arctangent of 1.0000 is 45.0000 degrees
24 atan2() Converts rectangular coordinates (x, y) to polar coordinate (r, theta) and returns theta.
	double x =45.0;
	double y =30.0;
	System.out.println(Math.atan2(x,y));//0.982793723247329
25 toDegrees() Converts the argument to degrees
	double x =45.0;
	double y =30.0;
	System.out.println(Math.toDegrees(x));//2578.3100780887044
	System.out.println(Math.toDegrees(y ));//1718.8733853924698
26 toRadians() Converts the argument to radians.
	double x =45.0;
	double y =30.0;
	System.out.println(Math.toRadians(x));//0.7853981633974483
	System.out.println(Math.toRadians(y ));//0.5235987755982988
27 random() Returns a random number between 0.0 and 1.0. The range is: 0.0 =< Math.random < 1.0. Different ranges can be achieved by using arithmetic
	System.out.println(Math.random());//0.16763945061451657
	System.out.println(Math.random());//0.400551253762343
	
  "Classe abstrata Character(pacote java.lang)".
	 char ch = 'a'; 
	 
	 // Unicode for uppercase Greek omega character 
	 char uniChar = '\u039A'; 
	 
	 // an array of chars 
	 char[] charArray ={'a','b','c','d','e'};
  
  
	Character ch = new Character('a');
	
	if you pass a primitive char into a method that expects an object, the compiler automatically converts the char to a Character for you. 
	This feature is called autoboxing or unboxing, if the conversion goes the other way
	
	// Here following primitive char 'a' 
	// is boxed into the Character object ch 
	Character ch ='a'; 
	// Here primitive 'x' is boxed for method test, 
	// return is unboxed to char 'c' 
	char c =test('x');
	
1 isLetter() Determines whether the specified char value is a letter.
	System.out.println(Character.isLetter('c'));//true
	System.out.println(Character.isLetter('5'));//false
2 isDigit() Determines whether the specified char value is a digit.
	System.out.println(Character.isLetter('c'));//false
	System.out.println(Character.isLetter('5'));//true
3 isWhitespace() Determines whether the specified char value is white space.
	System.out.println(Character.isWhitespace('c'));//false
	System.out.println(Character.isWhitespace(''));//true
	System.out.println(Character.isWhitespace('\n'));//true
	System.out.println(Character.isWhitespace('\t'));//true
4 isUpperCase() Determines whether the specified char value is uppercase.
	System.out.println(Character.isUpperCase('c'));//false
	System.out.println(Character.isUpperCase('C'));//true
	System.out.println(Character.isUpperCase('\n'));//false
	System.out.println(Character.isUpperCase('\t'));//false
5 isLowerCase() Determines whether the specified char value is lowercase.
	System.out.println(Character.isUpperCase('c'));//true
	System.out.println(Character.isUpperCase('C'));//false
	System.out.println(Character.isUpperCase('\n'));//false
	System.out.println(Character.isUpperCase('\t'));//false
6 toUpperCase() Returns the uppercase form of the specified char value.
	System.out.println(Character.toUpperCase('c'));//C
	System.out.println(Character.toUpperCase('C'));//C
7 toLowerCase() Returns the lowercase form of the specified char value.
	System.out.println(Character.toUpperCase('c'));//c
	System.out.println(Character.toUpperCase('C'));//c
8 toString() Returns a String object representing the specified character valuethat is, a one-character string.
	System.out.println(Character.toUpperCase('c'));//c
	System.out.println(Character.toUpperCase('C'));//C
	
  "Classe abstrata String(pacote java.lang)".
  
	String greeting = "Hello world!";
	
	Whenever it encounters a string literal in your code, the compiler creates a String object with its value , in this case, "Hello world!'.
	The String class is immutable, so that once it is created a String object cannot be changed. If there is a necessity to make alot of modifications 
	to Strings of characters , then you should use String Buffer & String Builder Classes.
	
	char[] helloArray ={'h','e','l','l','o','.'};
	String helloString = new String(helloArray);
	System.out.println(helloString);//hello.
	
	"Strings formatadas"
	  printf() e format(reutilizável) Métodos para imprimir uma saída com o número formatado.
	      System.out.printf("The value of the float variable is " + 
	                        "%f, while the value of the integer " +
	                            "variable is %d, and the string " +
	                            "is %s",floatVar,intVar,stringVar);
	      
	      String fs;
	      fs =String.format("The value of the float variable is " +
	                        "%f, while the value of the integer " +
	                        "variable is %d, and the string " +
	                        "is %s",floatVar,intVar,stringVar);
	                        System.out.println(fs);
	
1 char charAt(int index) Returns the character at the specified index.
	String s ="Strings are immutable";
	char result = s.charAt(8);
	System.out.println(result);//a
2 int compareTo(Object o) Compares this String to another Object.
3 int compareTo(String anotherString) Compares two strings lexicographically.
	String str1 ="Strings are immutable";
	String str2 ="Strings are immutable";
	String str3 ="Integers are not immutable";
	int result = str1.compareTo(str2);
	System.out.println(result);//0
	result=str2.compareTo(str3);
	System.out.println(result);//10
	result=str3.compareTo(str1);
	System.out.println(result);//-10
4 int compareToIgnoreCase(String str) Compares two strings lexicographically, ignoring case differences.
	String str1 ="Strings are immutable";
	String str2 ="Strings are immutable";
	String str3 ="Integers are not immutable";
	int result = str1.compareToIgnoreCase(str2);
	System.out.println(result);//0
	result=str2.compareToIgnoreCase(str3);
	System.out.println(result);//10
	result=str3.compareToIgnoreCase(str1);
	System.out.println(result);//-10
5 String concat(String str) Concatenates the specified string to the end of this string.
	String s ="Strings are immutable";
	s = s.concat(" all the time");
	System.out.println(s)//Strings are immutable all the time
6 boolean contentEquals(StringBuffer sb) Returns true if and only if this String represents the same sequence of characters as the specified StringBuffer.
	String str1 = "Not immutable";
	String str2 = "Strings are immutable";
	StringBuffer str3 = new StringBuffer( "Not immutable");
	boolean result =str1.contentEquals(str3);
	System.out.println(result);//true
	result=str2.contentEquals(str3);
	System.out.println(result);//false
7 static String copyValueOf(char[] data) Returns a String that represents the character sequence in the array specified.
8 static String copyValueOf(char[] data, int offset, int count) Returns a String that represents the character sequence in the array specified.
	char[] Str1 ={'h','e','l','l','o',' ','w','o','r','l','d'};
	String Str2 = ""; 
	Str2 = Str2.copyValueOf(Str1);
	System.out.println("Returned String:" + Str2);//Returned String: hello world
	Str2 = Str2.copyValueOf(Str1,2,6);
	System.out.println("Returned String:"+Str2);//Returned String: llo wo
9 boolean endsWith(String suffix) Tests if this string ends with the specified suffix.
	String Str = new String("This is really not immutable!!");
	boolean retVal; 
	retVal = Str.endsWith("immutable!!");
	System.out.println("Returned Value=" + retVal);//Returned Value = true
	retVal = Str.endsWith("immu");
	System.out.println("Returned Value="+retVal);//Returned Value = false
10 boolean equals(Object anObject) Compares this string to the specified object.
	String Str1 = new String("This is really not immutable!!");
	String Str2 = Str1;
	String Str3 = new String("This is really not immutable!!");
	boolean retVal;
	retVal = Str1.equals(Str2);
	System.out.println("Returned Value = " + retVal);//Returned Value = true
	retVal = Str1.equals(Str3);
	System.out.println("Returned Value = " + retVal);//Returned Value = true
11 boolean equalsIgnoreCase(String another String) Compares this String to another String, ignoring case considerations.
	String Str1 = new String("This is really not immutable!!");
	String Str2 = Str1;
	String Str3 = new String("This is really not immutable!!");
	String Str4 = new String("This IS REALLY NOT IMMUTABLE!!");
	boolean retVal;
	retVal = Str1.equals(Str2);
	System.out.println("Returned Value = " + retVal);//Returned Value = true
	retVal = Str1.equals(Str3);
	System.out.println("Returned Value = " + retVal);//Returned Value = true
	retVal = Str1.equalsIgnoreCase(Str4);
	System.out.println("Returned Value = " + retVal);//Returned Value = true
12 byte getBytes() Encodes this String into a sequence of bytes using the platform's default charset,storing the result into a new byte array.
13 byte[] getBytes(String charsetName) Encodes this String into a sequence of bytes using the named charset, storing the result into a new byte array."throws UnsupportedEncoding Exception"
	String Str1 = new String("Welcome to Tutorialspoint.com");
	try{ 
	  byte[] Str2 = Str1.getBytes(); 
	  System.out.println("Returned Value" + Str2);//Returned Value [B@192d342
	  Str2 = Str1.getBytes("UTF 8");
	  System.out.println("Returned Value" + Str2);//Returned Value [B@15ff48b
	  Str2 = Str1.getBytes("ISO-8859-1"); 
	  System.out.println("Returned Value" + Str2 );//Returned Value [B@1b90b39
	} catch(UnsupportedEncodingException e){ 
	  System.out.println("Unsupported character set");
14 void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin) Copies characters from this string into the destination character array." throws IndexOutOfBoundsException"
	String Str1 = new String("Welcome to Tutorials point.com");
	char[] Str2 = newchar[7]; 
	try{ 
	  Str1.getChars(2,9,Str2,0);
	  System.out.print("Copied Value = ");//Copied Value = l come t
	  System.out.println(Str2);
	} catch(Exception ex){
	  System.out.println("Raised exception...");
15 int hashCode() Returns a hash code for this string."s [ 0 ]* 31 ^( n - 1 )+ s [ 1 ]* 31 ^( n - 2 )+...+ s [ n - 1 ]"
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.println("Hashcode for Str :" + Str.hashCode());//Hashcode for Str :1186874997
16 int indexOf(int ch) Returns the index within this string of the first occurrence of the specified character.
17 int indexOf(int ch, int fromIndex) Returns the index within this string of the first occurrence of the specified character, starting the search at the specified index.
18 int indexOf(String str) Returns the index within this string of the first occurrence of the specified substring.
19 int indexOf(String str, int fromIndex) Returns the index within this string of the first occurrence of the specified substring, starting at the specified index.
	String Str = new String("Welcome to Tutorialspoint.com");
	String SubStr1 = new String("Tutorials");
	String SubStr2 = new String("Sutorials"); 
	System.out.print("Found Index:");//Found Index :4
	System.out.println(Str.indexOf('o'));
	System.out.print("Found Index:");//Found Index :9
	System.out.println(Str.indexOf('o',5));
	System.out.print("Found Index:");//Found Index :11
	System.out.println(Str.indexOf( SubStr1 ));
	System.out.print("Found Index:");//Found Index :-1
	System.out.println(Str.indexOf(SubStr1,15));
	System.out.print("Found Index:");//Found Index :-1
	System.out.println(Str.indexOf(SubStr2));
20 String intern() Returns a canonical representation for the string object.
	String Str1 = new String("Welcome to Tutoria lspoint.com");
	String Str2 = new String("WELCOME TO SUTORIALSPOINT.COM");
	System.out.print("Canonical representation:");//Canonical representation: Welcome to Tutorialspoint.com
	System.out.println(Str1.intern());
	System.out.print("Canonical representation:");//Canonical representation: WELCOME TO SUTORIALSPOINT.COM
	System.out.println(Str2.intern());
21 int lastIndexOf(int ch) Returns the index within this string of the last occurrence of the specified character.
22 int lastIndexOf(int ch, int fromIndex) Returns the index within this string of the last occurrence of the specified character, searching backward starting at the specified index.
23 int lastIndexOf(String str) Returns the index within this string of the rightmost occurrence of the specified substring.
24 int lastIndexOf(String str, int fromIndex) Returns the index within this string of the last occurrence of the specified substring, searching backward starting at the specified index.
	String Str = new String ("Welcome to Tutorialspoint.com");
	String SubStr1 = new String("Tutorials");
	String SubStr2 = new String("Sutorials");
	System.out.print("Found Last Index :");
	System.out.println(Str.lastIndexOf('o'));//Found Last Index :27
	System.out.print("Found Last Index :");
	System.out.println(Str.lastIndexOf('o',5));//Found Last Index :4
	System.out.print("Found Last Index :");
	System.out.println(Str.lastIndexOf(SubStr1));//Found Last Index :11
	System.out.print("Found Last Index :");
	System.out.println(Str.lastIndexOf(SubStr1, 15));//Found Last Index :11
	System.out.print("Found L ast Index :");
	System.out.println(Str.lastIndexOf(SubStr2));//Found Last Index :-1
25 int length() Returns the length of this string.
	String Str1 = new String("Welcome to Tutorialspoint.com");
	String Str2 = new String("Tutorials");
	System.out.print("String Length :");
	System.out.println(Str1.length());//String Length :29
	System.out.print("String Length :");
	System.out.println(Str2.length());//String Length :9
26 boolean matches(String regex) Tells whether or not this string matches the given regular expression.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.matches("(.*)Tutorials(.*)"));//Return Value :true
	System.out.print(" Return Value :");
	System.out.println(Str.matches("Tutorials"));//Return Value :false
	System.out.print("Return Value:");
	System.out.println(Str.matches("Welcome(.*)"));//Return Value :true
27 boolean regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len) Tests if two string regions are equal.
28 boolean regionMatches(int toffset, String other, int ooffset, int len) Tests if two string regions are equal.
	String Str1 = new String("Welcome to Tutorialspoint.com");
	String Str2 = new String("Tutorials");
	String Str3 = new String("TUTORIALS");
	System.out.print("ReturnValue:");
	System.out.println(Str1.regionMatches(11,Str2,0,9));//Return Value :true
	System.out.print("Return Value:");
	System.out.println(Str1.regionMatches(11,Str3,0,9));//Return Value :false
	System.out.print("Return Value:");
	System.out.println(Str1.regionMatches(true,11,Str3,0,9));//Return Value :true
29 String replace(char oldChar, char newChar) Returns a new string resulting from replacing all occurrences of oldChar in this string with newChar.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.replace('o','T'));//Return Value :WelcTme tT TutTrialspTint.cTm
	System.out.print("Return Value :");
	System.out.println(Str.replace('l','D'));//Return Value :WeDcome to TutoriaDspoint.com
30 String replaceAll(String regex, String replacement) Replaces each substring of this string that matches the given regular expression with the given replacement.
	StringStr = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.replaceAll("(.*)Tutorials(.*)","AMROOD"));//Return Value :AMROOD
31 String replaceFirst(String regex, String replacement) Replaces the first substring of this string that matches the given regular expression with the given replacement.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.replaceFirst("(.*)Tutorials(.*)","AMROOD"));//Return Value :AMROOD
	System.out.print("ReturnValue:");
	System.out.println(Str.replaceFirst("Tutorials","AMROOD"));//Return Value :Welcome to AMROODpoint.com
32 String[] split(String regex) Splits this string a round matches of the given regular expression.
33 String[] split(String regex, int limit) Splits this string around matches of the given regular expression.
	String Str = new String("Welcome-to-Tutorialspoint.com");
	System.out.println("Return Value: ");
	for(String retval : Str.split("-",2)){
	  System.out.println(retval);
	} 					// Return Value: Welcome to-Tutorialspoint.com
	System.out.println("");
	System.out.println("Return Value :");
	for(Stringretval:Str.split("-",3)){
	  System.out.println(retval);
	}					// Return Value : Welcome to Tutorialspoint.com
	System.out.println("");
	System.out.println( "Return Value :" ); 
	for(String retval : Str.split("-",0)){
	  System.out.println(retval);
	}					// Return Value: Welcome to Tutorialspoint.com
	System.out.println("");
	System.out.println("Return Value :");
	for(String retval : Str.split("-")){
	  System.out.println(retval);
	}					//Return Value : Welcome to Tutorialspoint.com
34 boolean startsWith(String prefix) Tests if this string starts with the specified prefix.
35 boolean startsWith(String prefix,int toffset) Tests if this string starts with the specified prefix beginning a specified index.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.startsWith("Welcome"));//Return Value :true
	System.out.print("Return Value :");
	System.out.println(Str.startsWith("Tutorials"));//Return Value :false
	System.out.print("Return Value :");
	System.out.println(Str.startsWith("Tutorials",11));//Return Value :true
36 CharSequence subSequence(int beginIndex, int endIndex) Returns a new character sequence that is a subsequence of this sequence.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.subSequence(0,10));//Return Value :Welcome to
	System.out.print("Return Value :" );
	System.out.println(Str.subSequence(10,15));//Return Value : Tuto
37 String substring(int beginIndex) Returns a new string that is a substring of this string.
38 String substring(int beginIndex, int endIndex) Returns a new string that is a substring of this string.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.substring(10));//Return Value : Tutorialspoint.com
	System.out.print("Return Value :");
	System.out.println(Str.substring(10,15));//Return Value : Tuto
39 char[] toCharArray() Converts this string to a new character array.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.toCharArray());//Return Value :Welcome to Tutorialspoint.com
40 String toLowerCase() Converts all of the characters in this String to lower case using the rules of the default locale.(Locale.getDefault()).
41 String toLowerCase(Locale locale) Converts all of the characters in this String to lower case using the rules of the given Locale.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.toLowerCase());//TUTORIALS POINT Simply Easy Learning Return Value :welcome to tutorialspoint.com
42 String toString() This object (which is already a string!) is itself returned.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.toString());//Return Value :Welcome to Tutorialspoint.com
43 String toUpperCase() Converts all of the characters in this String to upper case using the rules of the default locale.
44 String toUpperCase(Locale locale) Converts all of the characters in this String to upper case using the rules of the given Locale.
	String Str = new String("Welcome to Tutorialspoint.com");
	System.out.print("Return Value :");
	System.out.println(Str.toUpperCase());
45 String trim() Returns a copy of the string, with leading and trailing whitespace omitted.
	String Str = new String(" Welcome to Tutorialspoint.com ");
	System.out.print("Return Value :");
	System.out.println(Str.trim());//Return Value :Welcome to Tutorialspoint.com
46 static String valueOf(primitive data type x) Returns the string representation of the passed data type argument.
	double d = 102939939.939;
	boolean b = true;
	long l =1232874;
	char[] arr ={'a','b','c','d','e','f','g'};
	System.out.println("Return Value : " + String.valueOf(d));//Return Value : 1.02939939939E8
	System.out.println("Return Value : " + String.valueOf(b));//Return Value : true
	System.out.println("Return Value : " + String.valueOf(l));//Return Value : 1232874
	System.out.println("Return Value : " + String.valueOf(arr));//Return Value : abcdefg
	

  "Classe abstrata Array(pacote java.util)".
	
	dataType[] arrayRefVar ; // preferred way.
	or 
	dataType arrayRefVar[]; // works but not preferred way.
	
	
	dataType[] arrayRefVar = new dataType [ arraySize ];
	ou ainda
	dataType[] arrayRefVar ={ value0 , value1 ,..., valuek };
	
	"Enhanced for loop for arrays"
	  double[] myList ={ 1.9 , 2.9 , 3.4 , 3.5 };
	  // Print all the array elements 
	  for( double element : myList )
	    System.out.println(element) ;
	  
1 public static int binarySearch(Object[] a, Object key) Searches the specified array of Object ( Byte, Int , double, etc.) for the specified value using the binary search
algorithm. The array must be sorted prior to making this call. This returns index of the search key, if it is contained in the list; otherwise, (-(insertion point + 1).
2 public static boolean equals(long[] a, long[] a2) Returns true if the two specified arrays of longs are equal to one another. Two arrays are considered equal if both arrays
contain the same number of elements, and all corresponding pairs of elements in the two arrays are equal. This returns true if the two arrays are equal. Same method could be 
used by all other primitive data types(Byte, short, Int,etc.)
3 public static void fill(int[] a, int val) Assigns the specified int value to each element of the specified array of ints. Same method could be used by all ot her primitive
data types ( Byte, short, Int,etc.)
4 public static void sort(Object[] a) Sorts the specified array of objects into ascending order, according to the natural ordering of its elements. Same method could be used 
by all other primitive data types ( Byte, short, Int,etc.)
	  
  "Classe abstrata Date(pacote java.util)".
	 Encapsula currente data e tempo.
	 
	 Date(); Inicializa com currente data e tempo.
	 Date ( long millisec ); Retorna qtd de milissegundos que se passaram desde January 1, 1970 à meia-noite.
	 
1 boolean after(Date date) Returns true if the invoking Date object contains a date that is later than the one specified by date, otherwise,it returns false.
2 boolean before(Date date) Returns true if the invoking Date object contains a date that is earlier than the one specified by date, otherwise, it returns false.
3 Object clone( ) Duplicates the invoking Date object.
4 int compareTo(Date date) Compares the value of the invoking object with that of date. Returns 0 if the values are equal. Returns a negative value if the invoking object 
is earlier than date. Returns a positive value if the invoking object is later than date.
5 int compareTo(Object obj) Operates identically to compareTo(Date) if obj is of class Date. Otherwise, it throws a ClassCastException.
6 boolean equals(Object date) Returns true if the invoking Date object contains the same time and date as the one specified by date, otherwise, it returns false.
7 long getTime( ) Returns the number of milliseconds that have elapsed since January 1, 1970.
8 int hashCode( ) Returns a hash code for the invoking object.
9 void setTime(long time) Sets the time and date as specified by time, which represents an elapsed time in milliseconds from midnight, January 1, 1970
10 String toString( ) Converts the invoking Date object into a string and returns the result.

	  Date Formatting using SimpleDateFormat(classe concreta que formata Date)
	      Date dNow = new Date(); 
	      SimpleDateFormat ft = new SimpleDateFormat( "E yyyy.MM.dd 'at' hh:mm:ss a zzz" );
	      System.out.println( "Current Date: " + ft.format(dNow)); //CurrentDate : Sun 2004.07.18 at 04:14:09 PM PDT
	      
	      //com printf
	      // Instantiate a Date object 
	      Date date = new Date (); 
	      // display time and date using toString() 
	      System.out.printf("%1$s %2$tB %2$td, %2$tY" , "Due date:" , date ); //Due date : February 09 , 2004
	  
	
	      1 parse(), which tries to parse a string according to the format stored in the given SimpleDateFormat object.
			SimpleDateFormat ft = new SimpleDateFormat( "yyyy - MM - dd" ); 
			String input = args.length == 0 ? "1818-11-11" : args [ 0 ]; 
			System.out.print( input + " Parses as " ); 
			Date t ; 
			try { 
			  t = ft.parse(input);
			  System.out.println( t ); //2007 - 12 - 01 Parses as SatDec 0100 : 00 : 00 GMT 2007
			}catch( ParseException e ){ 
			  System.out.println( "Unparseable using " + ft ); 
			}
	      2 sleep(),you can sleep for any period of time from one millisecond up to the lifetime of your computer.For example,following program would sleep for 10 seconds.
			try { 
			  System.out.println(new Date ()+ "\n" );//SunMay 0318 : 04 : 41 GMT 2009
			  Thread.sleep(5*60*10);
			  System.out.println(new Date ()+ "\n"); //SunMay 0318 : 04 : 51 GMT 2009
			}catch( Exception e){ 
			  System.out.println( "Got an exception!" );
			}
	                
    "Classe concreta GregorianCalendar" implementação concreta da classe Calendar que implementa o calendário gregoriano que você está familiar.
    
	O método getInstance () de Calendar retorna um GregorianCalendar inicializado com a data e hora atual na zona local e horário padrão. GregorianCalendar define 
	dois campos: AD e BC. Estes representam as duas eras definidas pelo calendário gregoriano.
	
	-> Construtores

1 GregorianCalendar() Constructs a default GregorianCalendar using the current time in the default time zone with the default locale.
2 GregorianCalendar(int year, int month, int date) Constructs a GregorianCalendar with the given date set in the default time zone with the default locale.
3 GregorianCalendar(int year, int month, int date, int hour, int minute) Constructs a GregorianCalendar with the given date and time set for the default time zone with the 
default locale.
4 GregorianCalendar(int year, int month, int date, int hour, int minute, int second) Constructs a GregorianCalendar with the given date and time set for the default time zone
with the default locale.
5 GregorianCalendar(Locale aLocale) Constructs a GregorianCalendar based on the current time in the default time zone with the given locale.
6 GregorianCalendar(TimeZone zone) Constructs a GregorianCalendar based on the current time in the given time zone with the default locale.
7 GregorianCalendar(TimeZone zone, Locale aLocale) Constructs a GregorianCalendar based on the current time in the given time zone with the given locale
  
	->Métodos
1 void add(int field, int amount) Adds the specified (signed) amount of time to the given time field, based on the calendar's rules.
2 protected void computeFields() Converts UTC as milliseconds to time field values.
3 protected void computeTime() Overrides Calendar Converts time field values to UTC as milliseconds.
4 boolean equals(Object obj) Compares this GregorianCalendar to an object reference.
5 int get(int field) Gets the value for a given time field.
6 int getActualMaximum(int field) Return the maximum value that this field could have, given the current date.
7 int getActualMinimum(int field) Return the minimum value that this field could have, given the current date.
8 int getGreatestMinimum(int field) Returns highest minimum value for the given field if varies.
9 Date getGregorianChange() Gets the Gregorian Calendar change date.
10 int getLeastMaximum(int field) Returns lowest maximum value for the given field if varies.
11 int getMaximum(int field) Returns maximum value for the given field.
12 Date getTime() Gets this Calendar's current time.
13 long getTimeInMillis() Gets this Calendar's current time as a long.
14 TimeZone getTimeZone() Gets the time zone.
15 int getMinimum(int field) Returns minimum value for the given field.
16 int hashCode() Override hashCode.
17 boolean isLeapYear(int year) Determines if the given year is a leap year.
18 void roll(int field, boolean up) Adds or subtracts (up/down) a single unit of time on the given time field without changing larger fields.
19 void set(int field, int value) Sets the time field with the given value.
20 void set(int year, int month, int date) Sets the values for the fields year, month, and date.
21 void set(int year, int month, int date, int hour, int minute) Sets the values for the fields year, month, date, hour, and minute.
22 void set(int year, int month, int date, int hour, int minute, int second) Sets the values for the fields year, month, date, hour, minute, and second.
23 void setGregorianChange(Date date) Sets the GregorianCalendar change date.
24 void setTime(Date date) Sets this Calendar's current time with the given Date.
25 void setTimeInMillis(long millis) Sets this Calendar's current time from the given long value.
26 void setTimeZone(TimeZone value) Sets the time zone with the given time zone value.
27 String toString() Return a string representation of this calendar.

    " java.util.regex package" for pattern matching with regular expressions.A regular expression is a special sequence of characters that helps you match or find other
			       strings or sets of strings,using a specialized syntax held in a pattern. They can be used to search, edit, or manipulate text and data.
			       
	 Pattern Class: A Pattern object is a compiled representation of a regular expression. The Pattern class provides no public constructors. To create a pattern,
	you must first invoke one of its public static compile methods, which will then return a Pattern object. These methods accept a regular expression as the first
	argument.
	 Matcher Class: A Matcher object is the engine that interprets the pattern and performs match operations against an input string. Like the Pattern class,
	Matcher defines no public constructors. You obtain a Matcher object by invoking the matcher method on a Pattern object.
	 PatternSyntaxException: A PatternSyntaxException object is an unchecked exception that indicates a syntax error in a regular expression pattern.
	
	import java.util.regex.Matcher; 
	import java.util.regex.Pattern;
	
	//String to be scanned to find the pattern.
	String line ="This order was places for QT3000! OK?";
	String pattern = "(.*)( \ \ d+)(.*)" ; 
	
	//Create a Pattern object
	Pattern r = Pattern.compile(pattern);
	
	//Now create matcher 
	object.Matcher m = r.matcher(line);
	
	if(m.find()){
	  System.out.println("Found value: " + m.group(0));//Found value : This order was places for QT3000 ! OK ?
	  System.out.println("Found value: " + m.group(1));//Found value : This order was places for QT300
	  System.out.println("Found value: " + m.group(2));//Found value : 0
	}else{
	  System.out.println("NO MATCH");
	}
	
	Subexpression 								Matches 
	^ 								Matches beginning of line. 
	$							        Matches end of line. 
	. 								Matche s any single character except newline. Using m option allows it to match newline as well.
      [...] 								Matches any single character in brackets. 
      [^...] 								Matches any single character not in brackets 
      \ 								A Beginning of entire string 
      \z 								End of entire string 
      \Z 								End of entire string except allowable final line terminator. 
      re*								Matches 0 or more occurrences of preceding expression. 
      re+ 								Matches 1 or more of the previous thing 
      re? 								Matches 0 or 1 occurrence of preceding expression. 
      re{ n} 								Matches exactly n number of oc currences of preceding expression. 
      re{ n,} 								Matches n or more occurrences of preceding expression. 
      re{ n, m} 							Matches at least n and at most m occurrences of preceding expression. 
      a| b 								Matches either a or b. 
      (re) 								Groups regular expressions and remembers matched text. 
      (?: re)								Groups regular expressions without remembering matched text. 
      (?> re) 								Matches independent pattern without backtracking. 
      \w 								Matches word characters. 
      \W 								Matches nonword characters. 
      \s 								Matches whitespace. Equivalent to [\t\n\r\f]. 
      \S					 			Matches nonwhitespace. 
      \d 								Matches digits. Equivalent to [0-9]. 
      \D 								Matches nondigits. 
      \A 								Matches beginning of string. 
      \Z 								Matches end of string. If a newline exists, it matches just before newline. 
      \z 								Matches end of string. 
      \G 								Matches point where las t match finished. 
      \n 								Back - reference to capture group number "n" 
      \b 								Matches word boundaries when outside brackets. Matches backspace (0x08) when inside brackets. 
      \B 								Matches nonword boundaries. 
      \n,\t,etc.			 				Matches newlines, carriage returns, tabs, etc. 
      \Q 								Escape (quote) all characters up to \E
      \E 								Ends quoting begun with \Q
	
      classe Matcher
  
  Index Methods:    
1 public int start() Returns the start index of the previous match.
2 public int start(int group)Returns the start index of the subsequence captured by the given group during the previous match operation.
3 public int end() Returns the offset after the last character matched.
4 public int end(int group) Returns the offset after the last character of the subsequence captured by the given group during the previous match operation

  Study Methods:
1 public boolean lookingAt() Attempts to match the input sequence, starting at the beginning of the region, against the pattern.
2 public boolean find() Attempts to find the next subsequence of the input sequence that matches the pattern.
3 public boolean find(int start) Resets this matcher and then attempts to find the next subsequence of the input sequence that matches the pattern, starting at the specified 
index.
4 public boolean matches() Attempts to match the entire region against the pattern.

  Replacement Methods:
1 public Matcher appendReplacement(StringBuffer sb, String replacement) Implements a non-terminal append-and-replace step.
2 public StringBuffer appendTail(StringBuffer sb) Implements a terminal append-and-replace step
3 public String replaceAll(String replacement) Replaces every subsequence of the input sequence that matches the pattern with the given replacement string.
4 public String replaceFirst(String replacement) Replaces the first subsequence of the input sequence that matches the pattern with the given replacement string.
5 public static String quoteReplacement(String s) Returns a literal replacement String for the specified String. This method produces a String that will work as a literal 
replacement s in the appendReplacement method of the Matcher class.

      import java.util.regex.Matcher;
      import java.util.regex.Pattern;
      
      private static final String REGEX = "\\bcat\\b";
      private static final String INPUT ="cat cat cat cattie cat";
      
      Pattern p = Pattern.compile(REGEX); 
      Matcher m = p.matcher(INPUT);
      
      // get a matcher object 
      int count = 0; 
      while(m.find()){ 
	count++;
	System.out.println("Match number " + count);
	System.out.println("start():" + m.start());
	System.out.println("end():" + m.end());
      }

      //Match number 1
      //start(): 0 
      //end(): 3 
      //Match number 2 
      //start(): 4 
      //end(): 7
      //Match number 3
      //start(): 8 
      //end(): 11 
      //Match number 4 
      //start(): 19 
      //end(): 22
   
      classe PatternSyntaxException
      
1 public String getDescription() Retrieves the description of the error.
2 public int getIndex() Retrieves the error index.
3 public String getPattern() Retrieves the erroneous regular expression pattern.
4 public String getMessage() Returns a multi-line string containing the description of the syntax error and its index, the erroneous regular expression pattern, and a 
visual indication of the error index within the pattern.

      java.io (contém todas as classes de entrada e saída padrão do java) - "Java Streams, Files and I/O"
	  Uma stream pode ser definida como uma sequência de dados.
	  O InputStream é usado para ler dados de uma fonte e o OutputStream é usado para escrever dados em um destino.
	  
	  Byte Streams(Usados para entrada e saída de variáveis de tamanho 1 byte)
	    ->FileInputStream e FileOutputStream
		  import java.io.*;
		  public static void main(String args[]) throws IOException{
		    FileInputStream in = null;
		    FileOutputStream out = null;
		    try{ 
		      in = new FileInputStream("input.txt"); 
		      out = new FileOutputStream("output.txt");
		      int c; 
		      while((c = in.read())!=-1){ 
			out.write(c);
		      }
		    } 
		    finally{ 
		      if(in!=null){
			in.close();
		      }if(out!= null){
			out.close();
		      } 
		    }
	    
	    Character Streams((Usados para entrada e saída de variáveis de tamanho 2 bytes)
	      ->FileReader e FileWriter (lê e escreve 2 bytes de uma vez)
		    ..só muda nomes do interior ..
		    
	    Standard Streams()
	    
		 Standard Input: This is used to feed the data to user's program and usually a keyboard is used as standard input stream and represented as System.in . 
		 Standard Output: This is used to output the data produced by the user's program and usually a computer screen is used to standard output stream and 
		represented as System.out .
		 Standard Error: This is used to output the error data produced by the user's program and usually a computer screen is used to standard error stream 
		and represented as System.err
		
		FileInputStream and FileOutputStream	
		
		    
		    File f = new File ( "C:/java/hello" ); 
		    InputStream f = new FileInputStream ( f );
		    
1 public void close() throws IOException{} This method closes the file output stream. Releases any system resources associated with the file. Throws an IOException.
2 protected void finalize()throws IOException {} This method cleans up the connection to the file. Ensures that the close method of this file output stream is called when 
there are no more references to this stream. Throws an IOException.
3 public int read(int r)throws IOException{} This method reads the specified byte of data from the InputStream. Returns an int. Returns the next byte of data and-1 will be 
returned if it's end of file.
4 public int read(byte[] r) throws IOException{} This method reads r.length bytes from the input stream into an array. Returns the total number of bytes read. If end of file
-1 will be returned.
5 public int available() throws IOException{} Gives the number of bytes that can be read from this file input stream. Returns an int.

		ByteArrayInputStream - allows a buffer in the memory to be used as an InputStream.  The in put source is a byte array
		
		    ByteArrayInputStream bArray = new ByteArrayInputStream(byte[] a);
		    
1 public int read() This method reads the next byte of data from the InputStream. Returns an int as the next byte of data. If it is end of file then it returns-1.
2 public int read(byte[] r, int off, int len) This method reads upto len number of bytes starting from off from the input stream into an array. Returns the total number of 
bytes read. If end of file-1 will be returned.
3 public int available() Gives the number of bytes that can be read from this file input stream. Returns an int that gives the number of bytes to be read.
4 public void mark(int read) This sets the current marked position in the stream. The parameter gives the maximum limit of bytes that can be read before the marked position 
becomes invalid.
5 public long skip(long n) Skips n number of bytes from the stream. This returns the actual number of bytes skipped.

		DataInputStream - used to read primitives
		
		    InputStream in = DataInputStream ( InputStream in );
		    
1 public final int read(byte[] r, int off, int len)throws IOException Reads up to len bytes of data from the input stream into an array of bytes. Returns the total number
of bytes read into the buffer otherwise-1 if it is end of file.
2 Public final int read(byte [] b)throws IOException Reads some bytes from the inputstream an stores in to the byte array. Returns the total number of bytes read into the 
buffer otherwise-1 if it is end of file.
3 (a) public final Boolean readBooolean()throws IOException, 
  (b) public final byte readByte()throws IOException,
  (c) public final short readShort()throws IOException
  (d) public final Int readInt()throws IOException
These methods will read the bytes from the contained InputStream. Returns the next two bytes of the InputStream as the specific primitive type.
4 public String readLine() throws IOException Reads the next line of text from the input stream. It reads successive bytes, converting each byte separately into a character,
until it encounters a line terminator or end of file; the characters read are then returned as a String.

		FileOutputStream - used to create a file and write data into it. The stream would create a file, if it doesn't already exist, before opening it for output.
		
		File f = new File ( "C:/java/hello" ); 
		OutputStream f = new FileOutputStream ( f );
		
1 public void close() throws IOException{} This method closes the file output stream. Releases any system resources associated with the file. Throws an IOException.
2 protected void finalize()throws IOException {} This method cleans up the connection to the file. Ensures that the close method of this file output stream is called when 
there are  no more references to this stream. Throws an IOException.
3 public void write(int w)throws IOException{} This methods writes the specified byte to the output stream.
4 public void write(byte[] w) Writes w.length bytes from the mentioned byte array to the OutputStream.
		
		ByteArrayOutputStream - The ByteArrayOutputStream class stream creates a buffer in memory and all the data sent to the stream is stored in the buffer.
		
		OutputStream bOut = new By teArrayOutputStream ( int a ) //a é o tamanho do buffer - padrão é 32 bytes.
		
1 public void reset() This method resets the number of valid bytes of the byte array output stream to zero, so all the accumulated output in the stream will be discarded.
2 public byte[] toByteArray() This method creates a newly allocated Byte array. Its size would be the current size of the output stream and the contents of the buffer will 
be copied into it. Returns the current contents of the output stream as a byte array.
3 public String toString() Converts the buffer content into a string. Translation will be done according to the default character encoding. Returns the String translated 
from the buffer's content.
4 public void write(int w) Writes the specified array to the output stream.
5 public void write(byte []b, int of, int len) Writes len number of bytes starting from offset off to the stream.
6 public void writeTo(OutputStream outSt) Writes the entire content of this Stream to the specified stream argument.
		
		DataOutputStream - write the primitives to an output source.
		
		    DataOutputStream out = DataOutputStream ( OutputStream out );
		    
1 public final void write(byte[] w, int off, int len)throws IO Exception Writes len bytes from the specified byte array starting at point off , to the underlying stream.
2 Public final int write(byte [] b)throws IOException Writes the current number of bytes written to this data output stream. Returns the total number of bytes write into 
the buffer.
3 (a) public final void writeBooolean()throws IOException, 
  (b) public final void writeByte()throws IOException,
  (c) public final void writeShort()throws IOException
  (d) public final void writeInt()throws IOException
These methods will write the specific primitive type data into the output stream as bytes.
4 Public void flush()throws IOException Flushes the data output stream.
5 public final void writeBytes(String s) throws IOException Writes out the string to the underlying output stream as a sequence of bytes. Each character in the string is 
written out, in sequence, by discarding its high eight bits.

		File Navigation and I/O: There are several other classes that we would be going through to get to know the basics of File Navigation and I/O.
		     File Class
		     FileReader Class
		     FileWriter Class
		    
		    File Class - presents the files and directory pathnames in an abstract manner. This class is used for creation of files and directories, 
		    file searching, file deletion etc.
		    
		    File ( File parent , String child );
		    File ( String pathname );
		    
1 public String getName() Returns the name of the file or directory denoted by this abstract pathname.
2 public String getParent() Returns the pathname string of this abstract pathname's parent, or null if this pathname does not name a parent directory.
3 public File getParentFile() Returns the abstract pathname of this abstract pathname's parent, or null if this pathname does not name a parent directory.
4 public String getPath() Converts this abstract pathname into a pathname string.
5 public boolean isAbsolute() Tests whether this abstract pathname is absolute. Returns true if this abstract pathname is absolute, false otherwise
6 public String getAbsolutePath() Returns the absolute pathname string of this abstract pathname.
7 public boolean canRead() Tests whether the application can read the file denoted by this abstract pathname. Returns true if and only if the file specified by this abstract 
pathname exists and can be read by the application; false otherwise.
8 public boolean canWrite() Tests whether the application can modify to the file denoted by this abstract pathname. Returns true if and only if the file system actually 
contains a file denoted by this abstract pathname and the application is allowed to write to the file; false otherwise.
9 public boolean exists() Tests whether the file or directory denoted by this abstract pathname exists. Returns true if and only if the file or directory denoted by this 
abstract pathname exists; false otherwise
10 public boolean isDirectory() Tests whether the file denoted by this abstract pathname is a directory. Returns true if and only if the file denoted by this abstract 
pathname exists and is a directory; false otherwise.
11 public boolean isFile() Tests whether the file denoted by this abstract pathname is a normal file. A file is normal if it is not a directory and, in addition, satisfies 
other system-dependent criteria. Any non-directory file created by a Java application is guaranteed to be a normal file. Returns true if and only if the file denoted 
by this abstract pathname exists and is a normal file; false otherwise.
12 public long lastModified() Returns the time that the file denoted by this abstract pathname was last modified. Returns a long value representing the time the file was 
last modified, measured in milliseconds since the epoch (00:00:00 GMT, January 1, 1970), or 0L if the file does not exist or if an I/O error occurs.
13 public long length() Returns the length of the file denoted by this abstract pathname. The return value is unspecified if this pathname denotes a directory.
14 public boolean createNewFile() throws IOException Atomically creates a new, empty file named by this abstract pathname if and only if a file with this name does not 
yet exist. Returns true if the named file does not exist and was successfully created; false if the named file already exists.
15 public boolean delete() Deletes the file or directory denoted by this abstract pathname. If this pathname denotes a directory, then the directory must be empty in order 
to be deleted. Returns true if and only if the file or directory is successfully deleted; false otherwise.
16 public void deleteOnExit() Requests that the file or directory denoted by this abstract pathname be deleted when the virtual machine terminates.
17 public String[] list() Returns an array of strings naming the files and directories in the directory denoted by this abstract pathname.
18 public String[] list(FilenameFilter filter) Returns an array of strings naming the files and directories in the directory denoted by this abstract pathname that
satisfy the specified filter.
20 public File[] listFiles() Returns an array of abstract pathnames denoting the files in the directory denoted by this abstract pathname.
21 public File[] listFiles(FileFilter filter) Returns an array of abstract pathnames denoting the files and directories in the directory denoted by this abstract pathname 
that satisfy the specified filter.
22 public boolean mkdir() Creates the directory named by this abstract pathname. Returns true if and only if the directory was created; false otherwise.
23 public boolean mkdirs() Creates the directory named by this abstract pathname, including any necessary but nonexistent parent directories. Returns true if and only if 
the directory was created, along with all necessary parent directories; false otherwise.
24 public boolean renameTo(File dest) Renames the file denoted by this abstract pathname. Returns true if and only if the renaming succeeded; false otherwise.
25 public boolean setLastModified(long time) Sets the last-modified time of the file or directory named by this abstract pathname. Returns true if and only if the operation 
succeeded; false otherwise.
26 public boolean setReadOnly() Marks the file or directory named by this abstract pathname so that only read operations are allowed. Returns true if and only if the operation
succeeded; false otherwise.
27 public static File createTempFile(String prefix, String suffix, File directory) throws IOException Creates a new empty file in the specified directory, using the given 
prefix and suffix strings to generate its name. Returns an abstract pathname denoting a newly-created empty file.
28 public static File createTempFile(String prefix, String suffix) throws IOException Creates an empty file in the default temporary-file directory, using the given prefix and
suffix to generate its name. Invoking this method is equivalent to invoking createTempFile(prefix, suffix, null). Returns abstract pathname denoting a newly-created empty file.
29 public int compareTo(File pathname) Compares two abstract pathnames lexicographically. Returns zero if the argument is equal to this abstract pathname, a value less than 
zero if this abstract pathname is lexicographically less than the argument, or a value greater than zero if this abstract pathname is lexicographically greater than the
argument.
30 public int compareTo(Object o) Compares this abstract pathname to another object. Returns zero if the argument is equal to this abstract pathname, a value less than zero 
if this abstract pathname is lexicographically less than the argument, or avalue greater than zero if this abstract pathname is lexicographically greater than the argument.
31 public boolean equals(Object obj) Tests this abstract pathname for equality with the given object. Returns true if and only if the argument is not null and is an abstract
pathname that denotes the same file or directory as this abstract pathname.
32 public String toString() Returns the pathname string of this abstract pathname. This is just the string returned by the getPath() method.
		
		  import java.io.File;
		  File f = null;
		  String[] strs = { "test1.txt" , "test2.txt" };
		  try{ 
		    // for each string in string array 
		    for(String s : strs){
		      // create new file 
		      f = new File(s);
		      //true if the file is executable 
		      boolean bool = f.canExecute(); 
		      // find the absolute path 
		      String a = f.getAbsolutePath();
		      // prints absolute path 
		      System.out.print(a);
		      // prints 
		      System.out.println(" is executable: "+bool);
		    }
		  }catch(Exception e ){
		    // if any I/O error occurs 
		    e.printStackTrace();
		  }
		  
		FileReader Class - This class inherits from the InputStreamReader class. FileReader is used for reading streams of characters.
		
		FileReader ( File file );
		FileReader ( String fileName );
		
1 public int read() throws IOException Reads a single character. Returns an int, which represents the character read.
2 public int read (char [] c, int offset, int len) Reads characters into an array. Returns the number of characters read

		  import java . io .*;
		  
		  File file = new File("Hello1.txt"); 
		  // creates the file 
		  file.createNewFile();
		  // creates a FileWriter Object 
		  FileWriter writer = new FileWriter( file ); 
		  // Writes the content to the file 
		  writer.write( "This \ n is \ n an \ n example \ n" );
		  writer.flush();
		  writer.close(); 
		  //Creates a FileReader Object 
		  FileReader fr = new FileReader( file ); 
		  char[] a = new char[50];
		  fr.read( a );
		  // reads the content to the array 
		  for(char c:a) 
		    System.out.print( c );
		  //prints the characters one by one 
		  fr.close();
		  
		FileWriter Class - This class inherits from the OutputStreamWriter class. The class is used for writing streams of characters.
		
		FileWriter ( File file );
		FileWriter ( String fileName );
		
1 public void write(int c) throws IOException Writes a single character.
2 public void write(char [] c, int offset, int len) Writes a portion of an array of characters starting from offset and with a length of len.
3 public void write(String s, int offset, int len) Write a portion of a String starting from offset and with a length of len.

	      Diretórios em Java - You use File object to create directories.
	      
	       The mkdir( ) method creates a directory, returning true on success and false on failure. Failure indicates that the path specified in the File object 
	      already exists, or that the directory cannot be created because the entire path does not exist yet.
	       The mkdirs() method creates both a directory and all the parents of the directory.
	      
	      String dirname = "/tmp/user/java/bin"; 
	      File d = new File(dirname );
	      // Create directory now. 
	      d.mkdirs();
	      
	      You can use list( ) method provided by Fil e object to list down all the files and directories available in a directory.
	      File file = null; 
	      String[] paths; 
	      try{ 
		// create new file object 
		file = new File( "/tmp" ); 
		// array of files and directory 
		paths = file.list(); 
		// for each name in the path array 
		for(String path : paths ){ 
		  // prints filename and directory name 
		  System.out.println(path); 
		} 
	      }catch(Exception e){
		// if any error occurs 
		e.printStackTrace();
	      } 
	      
	      java Exceptions - All exception classes are subtypes of the java.lang.Exception class. The exception class is a subclass of the Throwable class. Other than 
				the exception class there is another subclass called Error which is derived from the Throwable class.
	      
	       Checked exceptions: A checked ex ception is an exception that is typically a user error or a problem that cannot be foreseen by the programmer. For example, 
		if a file is to be opened, but the file cannot be found, an exception occurs. These exceptions cannot simply be ignored at the time of compilation.
	       Runtime exceptions: A runtime exception is an exception that occurs that probably could have been avoided by the programmer. As opposed to checked exceptions, 
		runtime exceptions are ignored at the time of compilation.
	       Errors: These are not exceptions at all, but problems that arise beyond the control of the user or the programmer. Errors are typically ignored in your code 
	      because you can rarely do anything about an error. For example, if a stack overflow occurs, an error will arise. They are also ignored at the time of compilation.

	      Java’s Built - in Exceptions 
	      
	      Java defines several other types of exceptions that relate to its various class libraries. Following is the list of Java Unchecked RuntimeException.
	      
	  Exception								Description
    ArithmeticException						Arithmetic error, such as divide-by-zero.
    ArrayIndexOutOfBoundsException				Array index is out-of-bounds.
    ArrayStoreException						Assignment to an array element of an incompatible type.
    ClassCastException						Invalid cast.
    IllegalArgumentException					Illegal argument used to invoke a method.
    IllegalMonitorStateException				Illegal monitor operation, such as waiting on an unlocked thread.
    IllegalStateException					Environment or application is in incorrect state. 
    IllegalThreadStateException					Requested operation not compatible with current thread state.
    IndexOutOfBoundsException					Some type of index is out-of-bounds.
    NegativeArraySizeException					Array created with a negative size.
    NullPointerException					Invalid use of a null reference.
    NumberFormatException					Invalid conversion of a string to a numeric format.
    SecurityException						Attempt to violate security.	
    StringIndexOutOfBounds					Attempt to index outside the bounds of a string
    UnsupportedOperationException 				An unsupported operation was encountered.
    
	      Java defines several exception classes inside the standard package java.lang.
	      
	 Exception								Description
  ClassNotFoundException					Class not found.	
  CloneNotSupportedException					Attempt to clone an object that does not implement the Cloneable interface.
  IllegalAccessException					Access to a class is denied.
  InstantiationException					Attempt to create an object of an abstract class or interface.
  InterruptedException						One thread has been interrupted by another thread.
  NoSuchFieldException						A requested field does not exist.
  NoSuchMethodException						A requested method does not exist.
  
	      Following is the list of important methods available in the Throwable class.
	      
1 public String getMessage() Returns a detailed message about the exception that has occurred. This message is initialized in the Throwable constructor.
2 public Throwable getCause() Returns the cause of the exception as represented by a Throwable object.
3 public String toString() Returns the name of the class concatenated with the result of getMessage()
4 public void printStackTrace() Prints the result of toString() along with the stack trace to System.err, the error output stream.
5 public StackTraceElement [] getStackTrace() Returns an array containing each element on the stack trace. The element at index 0 represents the top of the call stack, 
and the last element in the array represents the method at the bottom of the call stack.
6 public Throwable fillInStackTrace() Fills the stack trace of this Throwable object with the current stack trace, adding to any previous information in the stack trace.

		try { 
		  //Protected code 
		}catch(ExceptionType1 e1 ) {
		  //Catch block 
		}catch( ExceptionType2 e2 ) {
		  //Catch block 
		}catch( ExceptionType3 e3 ) { 
		  //Catch block 
		}
		
	    ->throws/throw
	    
	    import java.io.*;
	    public class className{ 
	      public void deposit( double amount ) throws RemoteException, InsufficientFundsException {
		// Method implementation 
		throw new RemoteException();
	      } 
	      //Remainder of class definition
	      
	   ->finally
	   
	   int a[]= new int[2];
	   try{ 
	     System.out.println("Access element three :" + a[3]);
	  }catch(ArrayIndexOutOfBoundsException e ){
	    System.out.println("Exception thrown :" + e );
	  }finally{
	    a[0]= 6;
	    System.out.println("First element value: " + a[0]);
	    System.out.println("The finally statement is ex ecuted");
	  }
	  
	  Exception thrown:java.lang.ArrayIndexOutOfBoundsException : 3
	  First element value : 6 
	  The finally statement is executed
	  
	  Declaring you own Exception
	    
	     All exceptions must be a child of Throwable.
	     If you want to write a checked exception that is automatically enforced by the Handle or Declare Rule, you need to extend the Exception class.
	     If you want to write a runtime exception, you need to extend the RuntimeException class
	    
	    class MyException extends Exception { }
	    
	    // File Name InsufficientFundsException.java 
	    import java.io.*;
	    public class InsufficientFundsException extends Exception {
	      private double amount; 
	      
	      public InsufficientFundsException( double amount ) {
		this.amount = amount; 
	      } 
	      public double getAmount(){ 
		return amount; 
	      } 
	    }
	    
	 Herança
	 
	    public class Dog extends Mammal{ 
	      public static void main(String args []){
		Animal a = new Animal();
		Mammal m = new Mammal();
		Dog d = new Dog(); 
		
		System.out.println( m instanceof Animal );//true
		System.out.println( d instanceof Mammal );//true
		System.out.println( d instanceof Animal );//true
	      }
	    }
	    
	  
	Java Data Structures	    
	
	     Enumeration	
	     BitSet
	     Vector
	     Stack
	     Dictionary
	     Hashtable
	     Properties
	    
	    Enumeration
1 boolean hasMoreElements( ) When implemented, it must return true while there are still more elements to extract, and false when all the elements have been enumerated.
2 Object nextElement( ) This returns the next object in the enumeration as a generic Object reference.

	    BitSet
	    The BitSet class implements a group of bits or flags that can be set and cleared individually. 
	    This class is very useful in cases , where you need to keep up with a set of Boolean values; you just assign a bit to each value and set or clear it as appropriate.
	    A BitSet class creates a special type of array that holds bit values. The BitSet array can increase in size as needed. This makes it similar to a vector of bits.
	    
1 void and(BitSet bitSet) ANDs the contents of the invoking BitSet object with those specified by bitSet. The result is placed into the invoking object.
2 void andNot(BitSet bitSet) For each 1 bit in bitSet, the corresponding bit in the invoking BitSet is cleared.
3 int cardinality( ) Returns the number of set bits in the invoking object.
4 void clear( ) Zeros all bits.
5 void clear(int index) Zeros the bit specified by index.
6 void clear(int startIndex, int endIndex) Zeros the bits from startIndex to endIndex.1.
7 Object clone( ) Duplicates the invoking BitSet object.
8 boolean equals(Object bitSet) Returns true if the invoking bit set is equivalent to the one passed in bitSet. Otherwise, the method returns false.
9 void flip(int index) Reverses the bit specified by index. (
10 void flip(int startIndex, int endIndex) Reverses the bits from startIndex to endIndex.1.
11 boolean get(int index) Returns the current state of the bit at the specified index.
12 BitSet get(int startIndex, int endIndex) Returns a BitSet that consists of the bits from startIndex to endIndex.1. The invoking object is not changed.
13 int hashCode( ) Returns the hash code for the invoking object.
14 boolean intersects(BitSet bitSet) Returns true if at least one pair of corresponding bits within the invoking object and bitSet are 1.
15 boolean isEmpty( ) Returns true if all bits in the invoking object are zero.
16 int length( ) Returns the number of bits required to hold the contents of the invoking BitSet. This value is determined by the location of the last 1 bit.
17 int nextClearBit(int startIndex) Returns the index of the next cleared bit, (that is, the next zero bit), starting from the index specified by startIndex
18 int nextSetBit(int startIndex) Returns the index of the next set bit (that is, the next 1 bit), starting from the index specified by startIndex. If no bit is set, .1 is 
   returned.
19 void or(BitSet bitSet) ORs the contents of the invoking BitSet object with that specified by bitSet. The result is placed into the invoking object.
20 void set(int index) Sets the bit specified by index.
21 void set(int index, boolean v) Sets the bit specified by index to the value passed in v. true sets the bit, false clears the bit.
22 void set(int startIndex, int endIndex) Sets the bits from startIndex to endIndex.1.
23 void set(int startIndex, int endIndex, boolean v) Sets the bits from startIndex to endIndex.1, to the value passed i n v. true sets the bits, false clears the bits.
24 int size( ) Returns the number of bits in the invoking BitSet object.
25 String toString( ) Returns the string equivalent of the invoking BitSet object.
26 void xor(BitSet bitSet) XORs the contents of the invoking BitSet object with that specified by bitSet. The result is placed into the invoking object

	  Vector
	  The Vector class is similar to a traditional Java array, except that it can grow as necessary to accommodate new elements.
	  Like an array, elements of a Vector object can be accessed via an index into the vector.
	  
1 void add(int index, Object element) Inserts the specified element at the specified position in this Vector.
2 boolean add(Object o) Appends the specified element to the end of this Vector.
3 boolean addAll(Collection c) Appends all of the elements in the specified Collection to the end of this Vector, in the order that they are returned by the specified 
  Collection's Iterator.
4 boolean addAll(int index, Collection c) Inserts all of the elements in in the specified Collection into this Vector at the specified position.
5 void addElement(Object obj) Adds the specified component to the end of this vector, increasing its size by one.
6 int capacity() Returns the current capacity of this vector.
7 void clear() Removes all of the elements from this Vector.
8 Object clone() Returns a clone of this vector.
9 boolean contains(Object elem) Tests if the specified object is a component in this vector.
10 boolean containsAll(Collection c) Returns true if this Vector contains all of the elements in the specified Collection.
11 void copyInto(Object[] anArray) Copies the components of this vector into the specified array.
12 Object elementAt(int index) Returns the component at the specified index.
13 Enumeration elements() Returns an enumeration of the components of this vector.
14 void ensureCapacity(int minCapacity) Increases the capacity of this vector, if necessary, to ensure that it can hold at least the number of components specified by the minimum 
   capacity argument.
15 boolean equals(Object o) Compares the specified Object with this Vector for equality.
16 Object firstElement() Returns the first component (the item at index 0) of this vector.
17 Object get(int index) Returns the element at the specified position in this Vector.
18 int hashCode() Returns the hash code value for this Vector.
19 int indexOf(Object elem) Searches for the first occurence of the given argument, testing for equality using the equals method.
20 int indexOf(Object elem, int index) Searches for the first occurence of the given argument, beginning the search at index, and testing for equality using the equals method.
21 void insertElementAt(Object obj, int index) Inserts the specified object as a component in this vector at the specified index.
22 boolean isEmpty() Tests if this vector has no components.
23 Object lastElement() Returns the last component of the vector.
24 int lastIndexOf(Object elem) Returns the index of the last occurrence of the specified object in this vector.
25 int lastIndexOf(Object elem, int index) Searches backwards for the specified object, starting from the specified index, and returns an index to it.
26 Object remove(int index) Removes the element at the specified position in this Vector.
27 boolean remove(Object o) Removes the first occurrence of the specified element in this Vector If the Vector does not contain the element, it is unchanged.
28 boolean removeAll(Collection c) Removes from this Vector all of its elements that are contained in the specified Collection.
29 void removeAllElements() Removes all components from this vector and sets its size to zero.
30 boolean removeElement(Object obj) Removes the first (lowest-indexed) occurrence of the argument from this vector.
31 void removeElementAt(int index)
32 protected void removeRange(int fromIndex, int toIndex) Removes from this List all of the elements whose index is between fromIndex, inclusive and toIndex, exclusive.
33 boolean retainAll(Collection c) Retains only the elements in this Vector that are contained in the specified Collection.
34 Object set(int index, Object element) Replaces the element at the specified position in this Vector with the specified element.
35 void setElement At(Object obj, int index) Sets the component at the specified index of this vector to be the specified object.
36 void setSize(int newSize) Sets the size of this vector.
37 int size() Returns the number of components in this vector.
38 List subList(int fromIndex, int toIndex) Returns a view of the portion of this List between fromIndex, inclusive, and toIndex, exclusive.
39 Object[] toArray() Returns an array containing all of the elements in this Vector in the correct order.
40 Object[] toArray(Object[] a) Returns an array containing all of the elements in this Vector in the correct order; the runtime type of the returned array is that of the 
   specified array.
41 String toString() Returns a string representation of this Vector, containing the String representation of each element.
42 void trimToSize() Trims the capacity of this vector to be the vector's current size.

	Stack () - pilha
	The Stack class implements a last - in - firs t - out (LIFO) stack of elements.
	Stack is a subclass of Vector that implements a standard last - in, first - out stack.
	
1 boolean empty() Tests if this stack is empty. Returns true if the stack is empty, and returns false if the stack contains elements.
2 Object peek( ) Returns the element on the top of the stack, but does not remove it.
3 Object pop( ) Returns the element on the top of the stack, removing it in the process.
4 Object push(Object element) Pushes element onto the stack. element is also returned.
5 int search(Object element) Searches for element in the stack. If found, its offset from the top of the stack is returned. Otherwise, .1 is returned.
	    
	Dictionary
	The Dictionary class is an abstract class that defines a data structure for mapping keys to values.
	This is useful in cases where you want to be able to access data via a particular key rather than an integer index.
	
1 Enumeration elements( ) Returns an enumeration of the values contained in the dictionary.
2 Object get(Object key) Returns the object that contains the value associated with key. If key is not in the dictionary, a null object is returned.
3 boolean isEmpty( ) Returns true if the dictionary is empty, and returns false if it contains at least one key.
4 Enumeration keys( ) Returns an enumeration of the keys contained in the dictionary.
5 Object put(Object key, Object value) Inserts a key and its value into the dictionary. Returns null if key is not already in the dictionary; returns the previous value associated with
  key if key is already in the dictionary.
6 Object remove(Object key) Removes key and its value. Returns the value associated with key. If key is not in the dictionary, a null is returned.
7 int size( ) Returns the number of entries in the dictionary.

	Hashtable
	The Hashtable class provides a means of organizing data based on some user - defined key structure.
	Hashtable was part of the original java.util and is a concrete implementation of a Dictionary.
	However, Java 2 reengineered Hashtable so that it also implements the Map interface. Thus, Hashtable is now integrated into the collections framework. It is similar
	    to HashMap, but is synchronized.
	    
1 void clear( ) Resets and empties the hash table.
2 Object clone( ) Returns a duplicate of the invoking object.
3 boolean contains(Object value) Returns true if some value equal to value exists within the hash table. Returns false if the value isn't found.
4 boolean containsKey(Object key) Returns true if some key equal to key exists within the hash table. Returns false if the key isn't  found.
5 boolean containsValue(Object value) Returns true if some value equal to value exists within the hash table. Returns false if the value isn't found.
6 Enumeration elements( ) Returns an enumeration of the values contained in the hash table.
7 Object get(Object key) Returns the object that contains the value associated with key. If key is not in the hash table, a null object is returned.
8 boolean isEmpty( ) Returns true if the hash table is empty; returns false if it contains at least one key.
9 Enumeration keys( ) Returns an enumeration of the keys contained in the hash table.
10 Object put(Object key, Object value) Inserts a key and a value into the hash table. Returns null if key isn't already in the hash table; returns the previous value 
    associated with key if key is already in the hash table.
11 void rehash( ) Increases the size of the hash table and rehashes all of its keys.
12 Object remove(Object key) Removes key and its value. Returns the value associated with key. If key is not in the hash table, a null object is returned.
13 int size( ) Returns the number of entries in the hash table.
14 String toString( ) Returns the string equivalent of a hash table.

	Properties
	Properties is a subclass of Hashtable. It is used to maintain lists of values in which the key is a String and the value is also a String.
	
1 String getProperty(String key) Returns the value associated with key. A null object is returned if key is neither in the list nor in the default property list.
2 String getProperty(String key, String defaultProperty) Returns the value associated with key. defaultProperty is returned if key is neither in the list nor in the default 
  property list.
3 void list(PrintStream streamOut) Sends the property list to the output stream linked to streamOut.
4 void list(PrintWriter streamOut) Sends the property list to the output stream linked to streamOut.
5 void load(InputStream streamIn) throws IOException Inputs a property list from the input stream linked to streamIn.
6 Enumeration propertyNames( ) Returns an enumeration of the keys. This includes those keys found in the default property list, too.
7 Object setProperty(String key, String value) Associates value with key. Returns the previous value associated with key, or returns null if no such association exists.
8 void store(OutputStream streamOut, String description) After writing the string specified by description, the property list is written to the output stream linked to 
  streamOut.
  
	Collections
	A collections framework is a unified architecture for representing and manipulating collections. All collections frameworks contain the following:
      
	 Interfaces: These are abstract data types that represent collections. Interfaces allow collections to be manipulated inde pendently of the details of their 
		      representation. In object-oriented languages, interfaces generally form a hierarchy.
	 Implementations , i.e., Classes: These are the concrete implementations of the collection interfaces. In essence, they are reusable data structures.
	 Algorithms: These are the methods that perform useful computations, such as searching and sorting, on objects that implement collection interfaces. The algorithms 
		      are said to be polymorphic: that is, the same method can be used on many different implementations of the appropriate collection interface.
		      

			Collection Interfaces:
1 The Collection Interface This enables you to work with groups of objects; it is at the top of the collections hierarchy.
2 The List Interface This extends Collection and an instance of List stores an ordered collection of elements.
3 The Set This extends Collection to handle sets, which must contain unique elements
4 The SortedSet This extends Set to handle sorted sets
5 The Map This maps unique keys to values.
6 The Map.Entry This describes an element (a key/value pair) in a map. This is an inner class of Map. 
7 The SortedMap This extends Map so that the keys are maintained in ascending order.
8 The Enumeration This is legacy interface and defines the methods by which you can enumerate (obtain one at a time) the elements in a collection of objects. This legacy 
      interface has been superceded by Iterator
      
			Collection Classes:
1 AbstractCollection Implements most of the Collection interface.
2 AbstractList Extends AbstractCollection and implements most of the List interface.
3 AbstractSequentialList Extends AbstractList for use by a collection that uses sequential rather than random access of its elements.
4 LinkedList Implements a linked list by extending AbstractSequentialList.
5 ArrayList Implements a dynamic array by extending AbstractList.
6 AbstractSet Extends AbstractCollection and implements most of the Set interface.
7 HashSet Extends AbstractSet for use with a hash table.
8 LinkedHashSet Extends HashSet to allow insertion-order iterations.
9 TreeSet Implements a set stored in a tree. Extends AbstractSet.
10 AbstractMap Implements most of the Map interface.
11 HashMap Extends AbstractMap to use a hash table.
12 TreeMap Extends AbstractMap to use a tree.
13 WeakHashMap Extends AbstractMap to use a hash table with weak keys.
14 LinkedHashMap Extends HashMap to allow insertion-order iterations.
15 IdentityHashMap Extends AbstractMap and uses reference equality when comparing documents.

			 core implementation
1 Vector This implements a dynamic array. It is similar to ArrayList, but with some differences.
2 Stack Stack is a subclass of Vector that implements a standard last-in, first-out stack.
3 Dictionary Dictionary is an abstract class that represents a key/value storage repository and operates much like Map.
4 Hashtable Hashtable was part of the original java.util and is a concrete implementation of a Dictionary.
5 Properties Properties is a subclass of Hashtable. It is used to maintain lists of values in which the key is a String and the value is also a String.
6 BitSet A BitSet class creates a special type of array that holds bit values. This array can increase in size as needed.

			Collection Algorithms
1 The Collection Algorithms Here is a list of all the algorithm implementation.

      Iterator
      The easiest way to do this is to employ an iterator, which is an object that implements either the Iterator or the ListIterator interface.
      
			Iterator
1 boolean hasNext( ) Returns true if there are more elements. Otherwise, returns false.
2 Object next( ) Returns the next element. Throws NoSuchElementException if there is not a next element.
3 void remove( ) Removes the current element. Throws IllegalStateException if an attempt is made to call remove( ) that is not preceded by a call to next( ).

			ListIterator
1 void add(Object obj) Inserts obj into the list in front of the element that will be returned by the next call to next( ).
2 boolean hasNext( ) Returns true if there is a next element. Otherwise, returns false.
3 boolean hasPrevious( ) Returns true if there is a previous element. Otherwise, returns false.
4 Object next( ) Returns the next element. A NoSuchElementException is thrown if there is not a next element.
5 int nextIndex( ) Returns the index of the next element. If there is not a next element, returns the size of the list.
6 Object previous( ) Returns the previous element. A NoSuchElementException is thrown if there is not a previous element.
7 int previousIndex( ) Returns the index of the previous element. If there is not a previous element, returns-1.
8 void remove( ) Removes the current element from the list. An IllegalStateException is thrown if remove( ) is called before next( ) or previous( ) is invoked.
9 void set(Object obj) Assigns obj to the current element. This is the element last returned by a call to either next( ) or previous( ).

			Comparator
			It is the comparator that defines precisely what sorted order means.
			
1 int
compare(Object obj1 ,Object obj2) This method returns zero if the objects are equal. It returns a positive value if obj1 is greater than obj2. Otherwise, a negative value is 
	returned.
boolean equals(Object obj)  The method returns true if obj and the invoking object are both Comparator objects and use the same ordering. Otherwise, it returns false.

			Generic
			It would be nice if we could write a single sort method that could sort the elements in an Integer array, a String array or an array of any type that 
			supports ordering.
			
			// generic method printArray
			public static <E> void printArray(E[] inputArray)
			
			// determines the largest of three Comparable objects
			public static <T extends Comparable <T>> T maximum(T x,T y,T z)
			
			public class Box<T>{
			Box<Integer> integerBox = new Box<Integer>();
			
			Serialization
			
			serialization where an object can be represented as a sequence of bytes that includes the object's data as well as information about the object's 
			  type and the types of data stored in the object.
			After a serialized object has been written into a file, it can be read from the file and deserialized that is, the type information and bytes that 
			  represent the object and its data can be used to recreate the object in memory.
			  
			Classes ObjectInputStream and ObjectOutputStream are high-level streams that contain the methods for serializing and deserializing an object.
			
			public final void writeObject(Object x) throws IOException - serializes an Object and sends it to the output stream.
			public final Object readObject() throws IOException,ClassNotFoundException - This method retrieves the next Object out of the stream and deserializes 
			  it.
			public class Employee implements java.io.Serializable
			
			Note: When serializing an object to a file, the standard convention in Java is to give the file a .ser extension.'

			Networking - pacote java.net
			
			TCP: TCP stands for Transmission Control Protocol, which allows for reliable communication between two applications. TCP is typically used over the 
			      Internet Protocol, which is referred to as TCP/IP.
			      UDP: UDP stands for User Datagram Protocol, a connection-less protocol that allows for packets of data to be transmitted between applications.
			      
			  Url Processing
			  
			    protocol :/ /host:port/path?query#re //Examples of protocols include HTTP, HTTPS, FTP, and File. The path is also referred to as the filename, and
								 //the host is also called the authority.
			    exemplo http http:/ /www.amrood.com/index.htm?language=en#j2se
			    
			    //Notice that this URL does not specify a port, in which case the default port for the protocol is used. With HTTP, the default port is 80
			
			java.net.URL
1 public URL(String protocol, String host, int port, String file) throws MalformedURLException. Creates a URL by putting together the given parts.
2 public URL(String protocol, String host, String file) throws MalformedURLException Identical to the previous constructor, except that the default port for the given 
    protocol is used.
3 public URL(String url) throws MalformedURLException Creates a URL from the given String
4 public URL(URL context, String url) throws MalformedURLException Creates a URL by parsing the together the URL and String arguments

1 public String getPath() Returns the path of the URL.
2 public String getQuery() Returns the query part of the URL.
3 public String getAuthority() Returns the authority of the URL.
4 public int getPort() Returns the port of the URL.
5 public int getDefaultPort() Returns the default port for the protocol of the URL.
6 public String getProtocol() Returns the protocol of the URL.
7 public String getHost() Returns the host of the URL.
8 public String getHost() Returns the host of the URL.
9 public String getFile() Returns the filename of the URL.
10 public String getRef() Returns the reference part of the URL.
11 public URLConnection openConnection() throws IOException Opens a connection to the URL, allowing a client to communicate with the resource.

			URLConnections
			The openConnection() method returns a java.net.URLConnection, an abstract class whose subclasses represent the various types of URL connections.
			
1 Object getContent() Retrieves the contents of this URL connection.
2 Object getContent(Class[] classes) Retrieves the contents of this URL connection.
3 String getContentEncoding() Returns the value of the content-encoding header field.
4 int getContentLength() Returns the value of the content-length header field.
5 String getContentType() Returns the value of the content-type header field.
6 int getLastModified() Returns the value of the last-modified header field.
7 long getExpiration() Returns the value of the expires header field.
8 long getIfModifiedSince() Returns the value of this object's ifModifiedSince field.
9 public void setDoInput(boolean input) Passes in true to denote that the connection will be used for input. The default value is true because clients typically read from 
    a URLConnection.
10 public void setDoOutput(boolean output) Passes in true to denote that the connection will be used for output. The default value is false because many types of URLs do 
    not support being written to.
11 public InputStream getInputStream() throws IOException Returns the input stream of the URL connection for reading from the resource.
12 public OutputStream getOutputStream() throws IOException Returns the output stream of the URL connection for writing to the resource
13 public URL getURL() Returns the URL that this URLConnection object is connected to

			Socket Programming
			Sockets provide the communication mechanism between two computers using TCP. A client program creates a socket on its end of the communication and 
			    attempts to connect that socket to a server.
			    
			When the connection is made, the server creates a socket object on its end of the communication. The client and server can now communicate by writing 
			    to and reading from the socket.
			The java.net.Socket class represents a socket, and the java.net.ServerSocket class provides a mechanism for the server program to listen for clients 
			    and establish connections with them.
			    
			ServerSocket Class Methods
			The java.net.ServerSocket class is used by server applications to obtain a port and listen for client requests
			
1 public ServerSocket(int port) throws IOException Attempts to create a server socket bound to the specified port. An exception occurs if the port is already bound by 
  another application.
2 public ServerSocket(int port, int backlog) throws IOException Similar to the previous constructor, the backlog parameter specifies how many incoming clients to store in 
  a wait queue.
3 public ServerSocket(int port, int backlog, InetAddress address) throws IOException Similar to the previous constructor, the InetAddress parameter specifies the local IP
  address tobind to. The InetAddress is used for servers that may have multiple IP addresses, allowing the server to specify which of its IP addresses to accept client 
  requests on
4 public ServerSocket() throws IOException Creates an unbound server socket. When using this constructor, use the bind() method when you are ready to bind the server socket

1 public int getLocalPort() Returns the port that the server socket is listening on. This method is useful if you passed in 0 as the port number in a constructor and let 
  the server find a port for you.
2 public Socket accept() throws IOException Waits for an incoming client. This method blocks until either a client connects to the server on the specified port or the 
  socket times out, assuming that the time-out value has been set using the setSoTimeout() method. Otherwise, this method blocks indefinitely.
3 public void setSoTimeout(int timeout) Sets the time-out value for how long the server socket waits for a client during the accept().
4 public void bind(SocketAddress host, int backlog) Binds the socket to the specified server and port in the SocketAddress object. Use this method if you instantiated the 
  ServerSocket using the no-argument constructor.
  
			    When the ServerSocket invokes accept(), the method does not return until a client connects. After a client does connect, the ServerSocket 
			      creates a new Socket on an unspecified port and returns a reference to this new Socket. A TCP connection now exists between the client 
			      and server, and communication can begin.
			      
			    java.net.Socket
1 public Socket(String host, int port) throws UnknownHostException, IOException. This method attempts to connect to the specified server at the specified port. If this 
  constructor does not throw an exception, the connection is successful and the client is connected to the server.
2 public Socket(InetAddress host, int port) throws IOException This method is identical to the previous constructor, except that the host is denoted by an InetAddress object.
3 public Socket(String host, int port, InetAddress localAddress, int localPort) throws IOException. Connects to the specified host and port, creating a socket on the local
  host at the specified address and port.
4 public Socket(InetAddress host, int port, InetAddress localAddress, int localPort) throws IOException. This method is identical to the previous constructor, except that the
  host is denoted by an InetAddress object instead of a String
5 public Socket() Creates an unconnected socket. Use the connect() method to connect this socket to a server.

1 public void connect(SocketAddress host, int timeout) throws IOException This method connects the socket to the specified host. This method is needed only when you 
  instantiated the Socket using the no-argument constructor.
2 public InetAddress getInetAddress() This method returns the address of the other computer that this socket is connected to.
3 public int getPort() Returns the port the socket is bound to on the remote machine.
4 public int getLocalPort() Returns the port the socket is bound to on the local machine.
5 public SocketAddress getRemoteSocketAddress() Returns the address of the remote socket.
6 public InputStream getInputStream() throws IOException Returns the input stream of the socket. The input stream is connected to the output stream of the remote socket.
7 public OutputStream getOutputStream() throws IOException Returns the output stream of the socket. The output stream is connected to the input stream of the remote socket
8 public void close() throws IOException Closes the socket, which makes this Socket object no longer capable of connecting again to any server

			      InetAddress Class
			      This class represents an Internet Protocol (IP) address. Here are following useful methods ,which you would need while doing socket programming:
			      
1 static InetAddress getByAddress(byte[] addr) Returns an InetAddress object given the raw IP address .
2 static InetAddress getByAddress(String host, byte[] addr) Create an InetAddress based on the provided host name and IP address.
3 static InetAddress getByName(String host) Determines the IP address of a host, given the host's name.
4 String getHostAddress() Returns the IP address string in textual presentation.
5 String getHostName() Gets the host name for this IP address.
6 static InetAddress InetAddress getLocalHost() Returns the local host.
7 String toString() Converts this IP address to a String.

			      Sending E-mail
			      
			      import javax.mail.*;
			      import javax.mail.internet.*;
			      import javax.activation.*;
			      
			      // Recipient's email ID needs to be mentioned.
			      String to = "abcd@gmail.com";
			      // Sender's email ID needs to be mentioned
			      String from = "web@gmail.com";
			      // Assuming you are sending email from localhost
			      String host = "localhost";
			      // Get system properties
			      Properties properties = System.getProperties();
			      // Setup mail server 
			      properties.setProperty("mail.smtp.host",host);
			      // Get the default Session object.
			      Session session = Session.getDefaultInstance(properties);
			      // Create a default MimeMessage object.
			      MimeMessage message = new MimeMessage(session);
			      // Set From: header field of the header.
			      message.setFrom(new InternetAddres(from));
			      // Set To: header field of the header.
			      message.addRecipient(Message.RecipientType.TO,new InternetAddress(to));
			      // Set Subject: header field
			      message.setSubject("This is the Subject Line!");
			      // Now set the actual message
			      message.setText("This is actual message");
			      // Send message
			      Transport.send(message);
			      System.out.println("Sent message successfully....");
			      
			      //P/ múltiplos endereços
			      void addRecipients( Message.RecipientType type, Address[] addresses) throws MessagingException
				     type: This would be set to TO, CC or BCC. Here CC represents Carbon Copy and BCC represents Black Carbon Copy. 
				      Example Message.RecipientType.TO
				     addresses: This is the array of e-mail ID. You would need to use InternetAddress() method while specifying e-mail IDs
				    
			      If it is required to provide user ID and Password to the e-mail server for authentication purpose , then you can set these properties as follows:
				props.setProperty("mail.user","myuser");
				props.setProperty("mail.password","mypwd");
			
			      Multithreading
			      
			      Ciclos de um Thread
			       New: A new thread begins its life cycle in the new state. It remains in this state until the program starts the thread. It is also referred to
				     as a born thread.
			       Runnable: After a newly born thread is started, the thread becomes runnable. A thread in this state is considered to be executing its task.
			       Waiting: Sometimes, a thread transitions to the waiting state while the thread waits for another thread to perform a task.A thread transitions
				     back to the runnable state only when another thread signals the waiting thread to continue executing.
			       Timed waiting: A runnable thread can enter the timed waiting state for a specified interval of time. A thread in this state transitions back 
				     to the runnable state when that time interval expires or when the event it is waiting for occurs.
			       Terminated: A runnable thread enters the terminated state when it completes its task or otherwise terminates.
			      
		Every Java thread has a priority that helps the operating system determine the order in which threads are scheduled. 
		Java thread priorities are in the range between MIN_PRIORITY (a constant of 1) and MAX_PRIORITY (a constant of 10). 
		By default, every thread is given priority NORM_PRIORITY (a constant of 5).
		
	"Create Thread by Implementing Runnable Interface:"
		STEP 1:
As a first step you need to implement a run() method provided by Runnable interface. This method provides entry point for the thread and you will put you complete business 
logic inside this method. Following is simple syntax of run() method: 
		      public void run()
		STEP 2:
At second step you will instantiate a Thread object using the following constructor: 
		      Thread (Runnable threadObj ,String threadName);
Where, threadObj is an instance of a class that implements the Runnable interface and threadName is the name given to the new thread.
		STEP 3
Once Thread object is created, you can start it by calling start( ) method, which executes a call to run( ) method. Following is simple syntax of start() method: 
		      void start();
		      
	"Create Thread by Extending Thread Class:"
	        STEP 1
You will need to override run( ) method available in Thread class. This method provides entry point for the thread and you will put you complete business logic inside this 
method. Following is simple syntax of run() method: 
		      public void run()
		STEP 2
Once Thread object is created, you can start it by calling start( ) method, which executes a call to run( ) method. Following is simple syntax of start() method: 
		      void start();
		      
			     class ThreadDemo extends Thread { 
			       private Thread t;
			       t = new Thread (this , threadName);
			       ThreadDemo T1 = new ThreadDemo ("Thread-1");
			       T1.start();
			       ThreadDemo T2 = new ThreadDemo("Thread-2");
			       T2.start();
			       
			       Thread Methods:
1 public void start() Starts the thread in a separate path of execution, then invokes the run() method on this Thread object.
2 public void run() If this Thread object was instantiated using a separate Runnable target, the run() method is invoked on that Runnable object.
3 public final void setName(String name) Changes the name of the Thread object. There is also a getName() method for retrieving the name.
4 public final void setPriority(int priority) Sets the priority of this Thread object. The possible values are between 1 and 10.
5 public final void setDaemon(boolean on) A parameter of true denotes this Thread as a daemon thread.
6 public final void join(long millisec) The current thread invokes this method on a second thread, causing the current thread to block until the second thread terminates or 
  the specified number of milliseconds passes.
7 public void interrupt() Interrupts this thread, causing it to continue execution if it was blocked for any reason.
8 public final boolean isAlive() Returns true if the thread is alive, which is any time after the thread has been started but before it runs to completion.

1 public static void yield() Causes the currently running thread to yield to any other threads of the same priority that are waiting to be scheduled.
2 public static void sleep(long millisec) Causes the currently running thread to block for at least the specified number of milliseconds.
3 public static boolean holdsLock(Object x) Returns true if the current thread holds the lock on the given Object.
4 public static Thread currentThread() Returns a reference to the currently running thread, which is the thread that invokes this method.
5 public static void dumpStack() Prints the stack trace for the currently running thread, which is useful when debugging a multithreaded application.

      "Para programar com multithreaded é importante saber:"
	 What is thread synchronization?	//sincronizar p/ que só um thread acesse um recurso por vez (vários threads abrindo e fechando o mesmo arquivo)
	    synchronized(objectidentifier){
	      // Access shared variables and other shared resources
	    }
	    //Here, the objectidentifier is a reference to an object whose lock associates with the monitor that the synchronized statement represents. Now we are going to 
	    //see two examples where we will print a counter using two different threads. When threads are not synchronized, they print counter value which is not in sequence,
	    //but when we print counter by putting inside synchronized() block, then it prints counter very much in sequence for both the threads.
	 Handling threads inter communication
	    //Inter thread communication is important when you develop an application where two or more threads exchange some information.
1 public void wait() Causes the current thread to wait until another thread invokes the notify().
2 public void notify() Wakes up a single thread that is waiting on this object's monitor.
3 public void notifyAll() Wakes up all the threads that called wait( ) on the same object.
	 Handling thread deadlock
	    //Deadlock describes a situation where two or more threads are blocked forever, waiting for each other. Deadlock occurs when multiple threads need the same locks 
	    //but obtain them in different order. A Java multithreaded program may suffer from the deadlock condition because the synchronized keyword causes the executing 
	    //thread to block while waiting for the lock, or monitor, associated with the specified object
	 Major thread operations
	    //You can develop a multithreaded program which can be suspended, resumed or stopped completely based on your requirements. There are various static methods which
	    //you can use on thread objects to control their behavior.
1 public void suspend() This method puts a thread in suspended state and can be resumed using resume() method.
2 public void stop() This method stops a thread completely.
3 public void resume() This method resumes a thread which was suspended using suspend() method.
4 public void wait() Causes the current thread to wait until another thread invokes the notify().
5 public void notify() Wakes up a single thread that is waiting on this object's monitor.

				Applet
				An applet is a Java program that runs in a Web browser. An applet can be a fully functional Java application because it has the entire 
				Java API at its disposal.
				
	 An applet is a Java class that extends the java.applet.Applet class.
	 A main() method is not invoked on an applet, and an applet class will not define main().
	 Applets are designed to be embedded within an HTML page.
	 When a user views an HTML page that contains an applet, the code for the applet is downloaded to the user's machine.
	 A JVM is required to view an applet. The JVM can be either a plug-in of the Web browser or a separate runtime environment.
	 The JVM on the user's machine creates an instance of the applet class and invokes various methods during the applet's lifetime.
	 Applets have strict security rules that are enforced by the Web browser. The security of an applet is often referred to as sandbox security, comparing the applet 
	  to a child playing in a sandbox with various rules that must be followed.
	 Other classes that the applet needs can be downloaded in a single Java Archive (JAR) file.
	
	"Applets" can run as standalone programs. As mini applications, Java applets run completely independently from a web page, but are typically called inside of a web page
	for specific functionality. Java applets are more complex, but powerful, stand-alone mini applications for performing more far reaching needs beyond website code and 
	Javascripts.
	
	"Javascripts" are light-weight text-based pieces of code that are placed in line with standard web page code, HTML. Javascripts usually do not required hours of 
	programming or learning a new language. Rather, the average web developer and website designer can pick them up and use them. Javascripts are efficient for such functions as
	manipulating graphics, changing font colors or flipping button styles on a web page. Javascripts work for manipulating form data, moving objects around a web page and 
	running game coding, according to the Web Developers Notes website and its Javascript Tutorials.
	
	 init: This method is intended for whatever initialization is needed for your applet. It is called after the param tags inside the applet tag have been processed.
	 start: This method is automatically called after the browser calls the init method. It is also called whenever the user returns to the page containing the applet
	  after having gone off to other pages.	
	 stop: This method is automatically called when the user moves off the page on which the applet sits. It can, therefore, be called repeatedly in the same applet.
	 destroy: This method is only called when the browser shuts down normally. Because applets are meant to live on an HTML page, you should not normally leave resources 
	  behind after a user leaves the page that contains the applet.
	 paint: Invoked immediately after the start() method, and also any time the applet needs to repaint itself in the browser. The paint() method is actually inherited
	  from the java.awt
	
				 Applet Class
				 Every applet is an extension of the java.applet.Applet class
				 These include methods that do the following:
 Get applet parameters
 Get the network location of the HTML file that contains the applet
 Get the network location of the applet class directory
 Print a status message in the browser
 Fetch an image
 Fetch an audio clip
 Play an audio clip
 Resize the applet

				 Invoking an Applet:
				 An applet may be invoked by embedding directives in an HTML file and viewing the file through an applet viewer or Java-enabled browser. The 
				   <applet> tag is the basis for embedding an applet in an HTML file. Below is an example that invokes the "Hello, World" applet:
				   
<html>
<title>The Hello, World Applet
</title>
<hr>
<appletcode="HelloWorldApplet.class" width="320" height="120">
If your browser was Java-enabled, a "Hello,World" message would appear here.
</applet>
<hr>
</html>

appletviewer SimpleApplet.java 
  
				 EXEMPLO DE CÓDIGO COM PASSAGEM DE PARÃMETROS NO HTML
"*.java"
public void init(){
  String squareSizeParam = getParameter("squareSize");
  parseSquareSize(squareSizeParam);
  String colorParam = getParameter("color");
  Color fg = parseColor(colorParam);
  setBackground(Color.black);
  setForeground(fg);
}

"*.html"
<html>
<title>Checkerboard Applet
</title>
<hr>
<appletcode="CheckerApplet.class"width="480"height="320">
<paramname="color"value="blue">
<paramname="squaresize"value="30">
</applet>
<hr>
</html>

				 Here are the specific steps for converting an application (simple Java AWT class) to an applet.
 Make an HTML page with the appropriate tag to load the applet code.
 Supply a subclass of the JApplet class. Make this class public. Otherwise, the applet cannot be loaded.
 Eliminate the main method in the application. Do not construct a frame window for the application. Your application will be displayed inside the browser.
 Move any initialization code from the frame window constructor to the init method of the applet. You don't need to explicitly construct the applet object.the browser 
  instantiates it for you and calls the init method.
 Remove the call to setSize; for applets, sizing is done with the width and height parameters in the HTML file.
 Remove the call to setDefaultCloseOperation. An applet cannot be closed; it terminates when the browser exits.
 If the application calls setTitle, eliminate the call to the method. Applets cannot have title bars. (You can, of course, title the web page itself, using the HTML title tag.)
 Don't call setVisible(true). The applet is displayed automatically.

    "Como manipulações de eventos" Applets inherit a group of event-handling met hods from the Container class. The Container class defines several methods, such as 
				   processKeyEvent and processMouseEvent, for handling particular types of events, and then one catch-all method called processEvent.
    
    "Com manipulação de imagens" An applet can display images of the format GIF, JPEG, BMP, and others. To display an image within the applet, you use the drawImage() method 
				 found in the java.awt.Graphics class.
				 
				 private Image image;
    "Com manipulação de sons" An applet can play an audio file represented by the AudioClip interface in the java.applet package. The AudioClip interface has three methods, 
			      including:
			      
			       public void play(): Plays the audio clip one time, from the beginning.
			       public void loop(): Causes the audio clip to replay continually.
			       public void stop(): Stops playing the audio clip.
			      
				private AudioClip clip;
				
				
				Documentação Java
				
Javadoc - Javadoc is a tool which comes with JDK and it is used for generating Java code documentation in HTML format from Java source code which has required documentation 
	  in a predefined format
	  
	  <h1>....</h1> for heading and <p> has been used for creating paragraph break (dentro do comentário do Javadoc!!)
	  
	  Tag								Description							Syntax
@author							Adds the author of a class.							@author name-text
{@code}				Displays text in code font without interpreting the text as HTML markup or nested javadoc tags.		{@code text}
{@docRoot}			Represents the relative path to the generated document's root directory from any generated page		{@docRoot}
@deprecated			Adds a comment indicating that this API should no longer be used.					@deprecated deprecated-text
@exception			Adds a Throws subheading to the generated documentation, with the class-name and description text.	@exception class-namedescription
{@inheritDoc}			Inherits a comment from the nearest inheritable class or implementable interface 			Inherits a comment from the immediate 
																	  surperclass.
{@link}				Inserts an in-line link with visible text label that points to the documentation for the specified 	{@link package.class#memberlabel}
				package, class or member name of a referenced class. T							
{@linkplain} 			Identical to {@link}, except the link's label is displayed in plain text than code font.		{@linkplain package.class#member label}
@param				Adds a parameter with the specified parameter-name followed by the specified description to the 	@param parameter section.-name 
				"Parameters"												  description
				 
@return				Adds a "Returns" section with the description text.							@return description
@see				Adds a "See Also" heading with a link or text entry that points to reference.				@see reference
@serial				Used in the doc comment for a default serializable field.						@serial field-description |include | 
@serialData			Documents the data written by the writeObject( ) or writeExternal( ) methods 				@serialData data-description
@serialField			Documents an ObjectStreamField component.								@serialField field-name field-type 
																	  field-description
@since				Adds a "Since" heading with the specified since-text to the generated documentation.			@since release
@throws				The @throws and @exception tags are synonyms.								@throws class-name description
{@value}			When {@value} is used in the doc comment of a static field, it displays the value of that constant:	{@value package.class#field}
@version			Adds a "Version" subheading with the specified version-text to the generated docs when the-		@version version-text exclude
				version option is used.	
				
				Classes da biblioteca Java