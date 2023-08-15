const int sample_len = 50;
const int average_len = 50;

int sample[sample_len];
int max_array[average_len];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < average_len; i++){
    for (int j = 0; j < sample_len; j++){
    sample[j] = analogRead(A0);
      }
     int max_val = sample[0];
    for (int k = 0; k < sample_len; k++){
      if (sample[k] > max_val) {
         max_val = sample[k];
        }      
      }
      max_array[i] = max_val;
   }
   int total = 0;
   for (int m = 0; m < average_len; m++){
    total += max_array[m];
    }
    Serial.println(total/average_len);
     delay(5000);
}
