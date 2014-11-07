void setup()
{
  Serial.begin(9600);
  pinMode(5,OUTPUT);
}
void loop()
{
  int value = analogRead(0);
  Serial.println(value);
  
  if(value>300)
  {
    digitalWrite(5,HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(5,LOW);
    delay(1000);
  }
  digitalWrite(5,LOW);
}
