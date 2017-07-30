

int ldr=A0, potenciometro=A1,luz=0, pot=0, buzzer=10;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(potenciometro,INPUT);
  Serial.begin(9600);
}

void loop() {
  luz=analogRead(ldr);
  pot=analogRead(potenciometro);
  Serial.print(luz);
  Serial.print(" -- ");
  Serial.println(pot);
  analogWrite(buzzer,0);
  if(pot>500 && luz<200){
    analogWrite(buzzer,100);
  }
    

}
