int warning=13; //replace 13 with the pin number of the pin your LED and Buzzer are connected to
void setup()
{
  Serial.begin(9600); //sets the Baud rate of Serial Monitor
  pinMode(warning,OUTPUT); //for the output warning to declare the Alert Level
}
void loop()
{
  digitalWrite(warning,LOW);
  int sensorValue = analogRead(A0); //replace AO with the Analog pin number your sensor's analog output is connected to
  Serial.print("Air Quality = ");
  Serial.print(sensorValue);
  Serial.print("*PPM");
  Serial.println();
  if(sensorValue>50 && sensorValue<75)
  {
    Serial.println("THE AIR QUALITY IS MODERATE, IT'S BETTER TO OPEN THE WINDOWS AND TURN ON THE EXHAUST FAN");
  }
  else if (sensorValue>75 )
  {
    digitalWrite(warning, HIGH); //turns the LED and Buzzer on
    Serial.println("THE AIR QUALITY IS VERY POOR, OPEN UP THE WINDOWS AND TURN ON THE EXHAUST FANS");
  }
  Serial.println(); 
  delay(1000); //waits for 1s or 1000ms before taking another reading, increase or decrease the value to alter the rate



}
