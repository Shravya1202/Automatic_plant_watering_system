int dry;          //declare an integer type variable to store sensor value
int rel_ch1 = 4; //declare a variable to store relay In1 pin value
int threshold = 400; // threshold will store the value after which relay will turn on
void setup()
{
  Serial.begin(9600);          // start serial comm. at 9600 baud rate
  pinMode(rel_ch1, OUTPUT);    //config rel_ch1 pin as OUTPUT
  digitalWrite(rel_ch1, HIGH); //  DE-ACTIVATES RELAY AT HIGH PULSE
}

void loop()
{
  dry = analogRead(A0);  //store sensor value in dry variable
  Serial.println(dry);
  delay(2000);
  if (dry > threshold)  //check if plant is dry; value ranges between 0 to 1023 ; 0 means conductivity is 100% 1023 means conductivity is 0
  {
    Serial.println("Plant Needs Water");  // print the message on serial monitor.

    digitalWrite(rel_ch1, LOW);   //ACTIVATES AT LOW PULSE
  }
  else  //if plant is not dry condition
  {
    Serial.println("Plant does not need water");
    digitalWrite(rel_ch1, HIGH);   //DE-ACTIVATE RELAY AT HIGH PULSE
  }
  delay(5000);
}
