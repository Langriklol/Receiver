#define BUFFER_SIZE 12

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 pinMode(6, OUTPUT);
 tone(6, 600);
 delay(100);
 noTone(6);
}

void loop() {
  // put your main code here, to run repeatedly
  //String s = String(Serial.readString());
  //Serial.println(s);
  
  char* toneName;
  float frequency = 0.0F;
  float duration = 0.0F;
  char* durationHelper;

  char data[BUFFER_SIZE];
  Serial.setTimeout(1);
  String readSerial = Serial.readString();
  readSerial.toCharArray(data, BUFFER_SIZE);
  Serial.println(readSerial);
  Serial.println(data);
  toneName = strtok(data, ",");
  frequency = atof(strtok_r(nullptr, ",", &durationHelper));
  Serial.println(durationHelper);
  duration = atof(durationHelper);
  Serial.print("Tone:");
  Serial.print(toneName);
  Serial.print(" Frequency: ");
  Serial.print(frequency);
  Serial.print(" Hz Duration: ");
  Serial.print(duration);
  Serial.println(" ms");
}
