#define trigPin 13
#define echoPin 12
#define buzzer 11

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= 20) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else if (distance > 20 && distance <= 50) {
    digitalWrite(buzzer, LOW);
    delay(300);
    digitalWrite(buzzer, HIGH);
    delay(300);
  }
  else {
    
    digitalWrite(buzzer, HIGH);
  }
}

