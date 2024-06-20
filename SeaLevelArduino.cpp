#define temp_pin A0
const int trigger=13; 
const int echo=12; 
float dist;

void TriggerControll(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);        
  digitalWrite(trigger,HIGH);  
  delayMicroseconds(10);      
  digitalWrite(trigger,LOW);
}

float distanceCalculate(float distance){
  float result = distance/58;
  return result;
}

float convertToVolt(int analogValue){
  float volt = analogValue * 0.00489;
  return volt;
}

float convertVoltToCel (float voltIn){
  float result = (40 * voltIn) - 50;
  return result;
}

void setup(){
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(A0, INPUT);
}
void loop(){
  float value = convertToVolt(analogRead(A0));
  float temp_cel = convertVoltToCel(value);
  TriggerControll();
  dist = distanceCalculate(pulseIn(echo,HIGH));
  Serial.println("Distancia = " + String(dist) + " cm.");
  Serial.println("Temperature = " + String(temp_cel) + " cel");
  delay (200);                
}                             
