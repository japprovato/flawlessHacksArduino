// April 16, 2016

const int pinSoundSensor = A1;     // Sound sensor
const int LED = 7;                 // LED Socket
const int LOUD_VAL = 400;          // 

void setup()
{
    Serial.begin(9600);

    pinMode(LED, OUTPUT);
    pinMode(pinSoundSensor, INPUT);
}

void loop()
{
    int a = analogRead(pinSoundSensor);

    if(a > LOUD_VAL)
    {
      digitalWrite(LED,HIGH);
      delay(200);
    }
    digitalWrite(LED,LOW);
}
