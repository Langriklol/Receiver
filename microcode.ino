String getValue(String data, char separator, int index); //Prototype, just because why not.. :D 

String toneName;
float frequency = 0.0F;
float duration;

//initial function
void setup() {
 Serial.begin(115200);
 pinMode(6, OUTPUT);
 Serial.setTimeout(1);
 tone(6, 600);
 delay(100);
 noTone(6);
}

//function is called every 1ms
void loop() {
  String readSerial = Serial.readString();
  Serial.println(readSerial);
  toneName = getValue(readSerial, ',', 0);
  frequency = getValue(readSerial, ',', 1).toFloat();
  duration = getValue(readSerial, ',', 2).toFloat();
  if(frequency > 30.0F){
    tone(6, frequency);
    delay(duration);
    noTone(6);
  }else{
    delay(duration);
  }
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
