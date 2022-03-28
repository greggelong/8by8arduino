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

int cols =1;
int rows =8;

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
   nextGen();
   

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

int countNeighbors(int y, int x){
    //global oldworld, cols, rows
    int sum = 0;
    for(int j=-1; j <2; j++){

        for (int i = -1; i < 2; i++){
            int row = (y + j + rows) % rows;
            int col = (x + i + cols) % cols;  //using modulo to count over 
             
            sum += oldworld[row][col];
        }
    }

    sum -= oldworld[y][x];
    return sum;
}

void nextGen(){
    // global oldworld rows cols
    // Create a vector containing rows (https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/)
    //vectors of size cols.  
    vector<vector<int> > newworld( rows , vector<int> (cols, 0));
     
    for (int y = 0; y<rows;y++){
        for(int x =0; x<cols;x++){
            
            int nei = countNeighbors(y,x); //make sure you get your x's and y's straight
            if (nei == 3){
                newworld[y][x] = 1;   //live or dead if three neighbors next gen will be live or 1
            }
                
            else if (nei == 2){    //live or dead if two neighbors the next gen will be the same as this one
                newworld[y][x] = oldworld[y][x];
             }   
            
            else{     //else live or dead any other number of neighbors next gen is dead or 0
                
                newworld[y][x] = 0;
            }
      }
    }            
    oldworld = newworld; // you can just copy vectors https://stackoverflow.com/questions/25026958/what-is-the-best-way-to-copy-a-2d-vector
}
