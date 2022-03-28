// array  array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// an array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

int world[][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0}
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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
//  for (int i = 0; i<8; i++){
//    digitalWrite(col[i],LOW);
//    delay(300);
//    digitalWrite(col[i],HIGH);
//    delay(300);
//  }
   showit();
   

}

void clearit(){
   for (int thisPin = 0; thisPin < 8; thisPin++) {
    
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    digitalWrite(col[thisPin], HIGH);
    // make sure row pins are low, to be ready for scanning
    digitalWrite(row[thisPin],LOW);

  }
}

void showit(){
  for (int y = 0; y <8; y++){
     // turn on the row for scanning
     digitalWrite(row[y],HIGH);
     // check the columns
    for(int x =0; x <8; x++){
      if (world[y][x] == 1){
        // turn on row and column
        digitalWrite(col[x],LOW); 
      }else{
        // turn off the column
        digitalWrite(col[x],HIGH);
      }
     
  }
   // turn off row
     digitalWrite(row[y],LOW);
   // turn off all columns
     for(int i =0; i<8;i++){
     digitalWrite(col[i],HIGH);
     }
  }
}
