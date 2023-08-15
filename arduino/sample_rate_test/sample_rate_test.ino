const int detect = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(detect, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(detect));
}
