const int pin_count = 5;
const int alphabet = 3;
int timing = 63; //mills
int LEDpins[pin_count] = {4, 5, 6, 7, 8};//4 is the lower blue, 8 upper blue closest to the sensor
int a_map[alphabet * 3][pin_count] = 
{{8, 7, 6, 5, 4}, {8, -7, -6, -5, 4}, {8, 7, 6, 5, 4},     //O
 {8, -7, -6, -5, -4}, {8, 7, 6, 5, 4}, {8, -7, -6, -5, -4}, //T
 {8, 7, 6, 5, 4}, {-8, -7, 6, -5, -4}, {8, 7, 6, 5, 4}};  //H

void process_char(int ch) {
  // if all the chars were here int idx = (toLowerCase(ch) - 'a') * 3;
  int idx = ch * 3;
  for(int j = 0; j < 3; j++) {
    for(int i = 0; i < pin_count; i++) {
      if(a_map[idx + j][i] > 0) {
        digitalWrite(a_map[idx + j][i], HIGH);
      }else {
        digitalWrite(abs(a_map[idx + j][i]), LOW);
      }
    }
    delay(timing);
  }
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < pin_count; i++) {
    pinMode(LEDpins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  process_char(1);
  delay(timing);
}
