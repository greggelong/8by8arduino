// array  array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// an array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

  


void setup() {
  // put your setup code here, to run once:

  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    digitalWrite(col[thisPin], HIGH);
    digitalWrite(row[thisPin],HIGH);
  }

   

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i<8; i++){
    digitalWrite(col[i],LOW);
    delay(300);
    digitalWrite(col[i],HIGH);
    delay(300);
  }

}
