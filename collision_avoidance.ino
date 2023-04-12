#define echoPin_A 7 // attach pin D4 to Echo pin of sensor A
#define trigPin_A 6 // attach pin D3 to Triger pin of sensor A
#define echoPin_B 9 // attach pin D9 to Echo pin of sensor B
#define trigPin_B 8 // attach pin D8 to Triger pin of sensor B
#define LED_A 5     // attach pin D2 to LED A
#define LED_B 10    // attach pin D10 to LED B
#define Buzzer 4


long duration_A; // duration of sound wave travel for sensor A
long duration_B; // duration of sound wave travel for sensor B
int distance_A; //  distance measurement for sensor A
int distance_B; //  distance measurement for sensor B

void setup() {
  pinMode(trigPin_A, OUTPUT); 
  pinMode(echoPin_A, INPUT); 
  pinMode(trigPin_B, OUTPUT); 
  pinMode(echoPin_B, INPUT); 
  pinMode(LED_A, OUTPUT); 
  pinMode(LED_B, OUTPUT); 

  digitalWrite(LED_A,LOW);
  digitalWrite(LED_B,LOW);
  
  Serial.begin(9600); 
}
void loop() {
  
  digitalWrite(trigPin_A, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin_A, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_A, LOW);
  
  duration_A = pulseIn(echoPin_A, HIGH);
  // Calculating the distance
  distance_A = duration_A * 0.034 / 2; 
  
  Serial.print("Distance_A: ");
  Serial.print(distance_A);
  Serial.println(" cm");

  digitalWrite(trigPin_B, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin_B, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_B, LOW);
 
  duration_B = pulseIn(echoPin_B, HIGH);
  // Calculating the distance
  distance_B = duration_B * 0.034 / 2; 
  
  Serial.print("Distance_B: ");
  Serial.print(distance_B);
  Serial.println(" cm");
  Serial.println("\n");

  if(distance_A <=10)// if distance is less than 10 Cm turn the LED_A ON
{
  digitalWrite(LED_A,HIGH);
  tone(Buzzer, 600);
  delay(500);
  noTone(Buzzer);
  delay(500);
}
  else                // else turn the LED_A OFF
{
  digitalWrite(LED_A,LOW);
  noTone(Buzzer);
}

  if(distance_B <=10) // if distance is less than 10 Cm turn the LED_B ON
{
  digitalWrite(LED_B,HIGH);
  tone(Buzzer, 600);
  delay(500);
  noTone(Buzzer);
  delay(500);
}
  else                // else turn the LED_B OFF
{
  digitalWrite(LED_B,LOW);
  noTone(Buzzer);
}
  
}
