
/* Copyright info
SignalController Program - Arduino C, GUI Java
Copyright 2018 by Alex Christmas and Kyle Dick
*/

char aspect[13];    // used to store the selected rule from Java
char readIn = -1;   // used to read in one character at a time from the Java output
char ack = 6;       // character used to tell Java that serial output has temporarly ended
int indications[5]; // used to store what indications will go to what signals
int pin_call_A[14]; // Stores what LEDs will be lit on each signal
int pin_call_B[14];
int pin_call_C[14];
int pin_call_D[14];
int pin_call_E[14];
int pins[54];       // Matrix that tells the program what action to perform on the individual lights
int flash[10];      // stores what lights will be flashing
int rotate = 0;     // tells the program if it will be rotating through aspects
int dly = 0;        // stores the time to cycle through indications
int running = 0;

// Initalizes the program
void setup() {
  Serial.begin(9600); // Starts serial communication

  // Initalizes all pins to output
  pinMode(2, OUTPUT);  // Top Green
  pinMode(3, OUTPUT);  // Top Yellow
  pinMode(4, OUTPUT);  // Top Red
  pinMode(5, OUTPUT);  // Top Lunar
  pinMode(6, OUTPUT);  // Middle Green
  pinMode(7, OUTPUT);  // Middle Yellow
  pinMode(8, OUTPUT);  // Middle Red
  pinMode(9, OUTPUT);  // Middle Lunar
  pinMode(10, OUTPUT); // Bottom Green
  pinMode(11, OUTPUT); // Bottom Yellow
  pinMode(12, OUTPUT); // Bottom Red
  pinMode(13, OUTPUT); // Bottom Lunar
  
  pinMode(22, OUTPUT); // Top Green
  pinMode(23, OUTPUT); // Top Yellow
  pinMode(24, OUTPUT); // Top Red
  pinMode(25, OUTPUT); // Top Lunar
  pinMode(26, OUTPUT); // Middle Green
  pinMode(27, OUTPUT); // Middle Yellow
  pinMode(28, OUTPUT); // Middle Red
  pinMode(29, OUTPUT); // Middle Lunar
  pinMode(30, OUTPUT); // Spare
  pinMode(31, OUTPUT); // Spare
  
  pinMode(32, OUTPUT); // Top Green
  pinMode(33, OUTPUT); // Top Yellow
  pinMode(34, OUTPUT); // Top Red
  pinMode(35, OUTPUT); // Top Lunar
  pinMode(36, OUTPUT); // Spare
  pinMode(37, OUTPUT); // Spare
  pinMode(38, OUTPUT); // Spare
  pinMode(39, OUTPUT); // Spare
  
  pinMode(40, OUTPUT); // Top Green
  pinMode(41, OUTPUT); // Top Yellow
  pinMode(42, OUTPUT); // Top Red
  pinMode(43, OUTPUT); // Top Lunar
  pinMode(44, OUTPUT); // Middle Green 
  pinMode(45, OUTPUT); // Middle Yellow
  pinMode(46, OUTPUT); // Middle Red
  pinMode(47, OUTPUT); // Middle Lunar
  
  pinMode(48, OUTPUT); // Top Green
  pinMode(49, OUTPUT); // Top Yellow
  pinMode(50, OUTPUT); // Top Red
  pinMode(51, OUTPUT); // Top Lunar
  pinMode(52, OUTPUT); // Spare
  pinMode(53, OUTPUT); // Spare


  // Title Lines
  Serial.print("SignalController Signal Demonstrator - 3rd Iteration\n");
  Serial.print("Version 1-Feb-2018 | Copyright Alex Christmas & Kyle Dick\n\n");
}

void loop() {
  // Java GUI contains all rulebook choices
  
  if (running == 0) {
    Serial.print("Enter in rule number: ");
    Serial.print(ack); // character used to signify end of serial output to Java
    Serial.print(" ");
	running = 1;
  }
  
  int aspLimit = 13; // max number of characters in rule number text - adjust in indication[] initializer
  
  /* Erases existing rule number data */
  for (int i = 0; i < aspLimit; i++) {
    aspect[i] = 0;
  }
  
  readIN(aspect);
  Serial.print("\n");
  selAspect();
}

void readIN(char data[]) {
  while (Serial.available() == 0) { } // Hangs the program while waiting for input from Java
  int i = 0;                          // Variable used to track the position of where the character will go in the string
  while (Serial.available()) {        // Reads in the Java input one character at a time
    delay(15);                      // Halts the program for a short period so that no communication is missed
    readIn = Serial.read();         // Reads in one character at a time
    data[i++] = readIn;           // Puts one character in the aspect string at a time
  }
}

// Flushes any remaining user input
void serialFlush() {
  while (Serial.available()) { Serial.read(); }
}

// Selects the specified aspect to output
void selAspect() {
  if (strcmp(aspect, "CSX 1281") == 0) { // If the indication matches the rule...
    initAspects(1, 2, 3, 4, 0);
    
  } else if (strcmp(aspect, "CSX 1281B") == 0) {
    initAspects(13, 14, 0, 16, 0);
    
  } else if (strcmp(aspect, "CSX 1281C") == 0) {
    initAspects(15, 16, 0, 16, 0);
    
  } else if (strcmp(aspect, "CSX 1281D") == 0) {
    initAspects(17, 18, 0, 18, 0);
    
  } else if (strcmp(aspect, "CSX 1282") == 0) {
    initAspects(19, 20, 0, 20, 0);
    
  } else if (strcmp(aspect, "CSX 1282A") == 0) {
    initAspects(21, 22, 0, 0, 0);
    
  } else if (strcmp(aspect, "CSX 1283") == 0) {
    initAspects(5, 6, 0, 6, 0);
    
  } else if (strcmp(aspect, "CSX 1283A") == 0) {
    initAspects(23, 0, 0, 0, 0);
    
  } else if (strcmp(aspect, "CSX 1283B") == 0) {
    initAspects(24, 0, 0, 0, 0);
    
  } else if (strcmp(aspect, "CSX 1283C") == 0) {
    initAspects(25, 0, 0, 22, 0);
    
  } else if (strcmp(aspect, "CSX 1284") == 0) {
    initAspects(26, 0, 0, 0, 0); 
    
  } else if (strcmp(aspect, "CSX 1285") == 0) {
    initAspects(7, 8, 9, 0, 0);
    
  } else if (strcmp(aspect, "CSX 1286") == 0) {
    initAspects(28, 29, 0, 29, 0);
    
  } else if (strcmp(aspect, "CSX 1287") == 0) {
    initAspects(30, 0, 0, 2, 3);
    
  } else if (strcmp(aspect, "CSX 1288") == 0) {
    initAspects(31, 0, 0, 8, 9); 
    
  } else if (strcmp(aspect, "CSX 1290") == 0) {
    initAspects(32, 36, 37, 36, 37);
    
  } else if (strcmp(aspect, "CSX 1291") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(aspect, "CSX 1292") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(aspect, "CSX 1293") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(aspect, "CSX 1294") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(aspect, "CSX 1298") == 0) {
    initAspects(10, 11, 12, 11, 12);
	
  } else if (strcmp(aspect, "") == 0) {
    initAspects(0, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CSX C1281") == 0) {
    initAspects(41, 2, 3, 0, 0);

  } else if (strcmp(aspect, "CSX C1281B") == 0) {
    initAspects(47, 14, 0, 14, 0);

  } else if (strcmp(aspect, "CSX C1281C") == 0) {
    initAspects(64, 16, 0, 0, 0);

  } else if (strcmp(aspect, "CSX C1281D") == 0) {
    initAspects(68, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CSX C1282") == 0) {
    initAspects(80, 20, 0, 20, 0);

  } else if (strcmp(aspect, "CSX C1283") == 0) {
    initAspects(81, 6, 0, 0, 51);

  } else if (strcmp(aspect, "CSX C1283A") == 0) {
    initAspects(23, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CSX C1283B") == 0) {
    initAspects(24, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CSX C1284") == 0) {
    initAspects(46, 22, 0, 0, 0);

  } else if (strcmp(aspect, "CSX C1285") == 0) {
    initAspects(82, 8, 9, 0, 9);

  } else if (strcmp(aspect, "CSX C1286") == 0) {
    initAspects(25, 0, 0, 0, 27);

  } else if (strcmp(aspect, "CSX C1287") == 0) {
    initAspects(30, 0, 0, 2, 3);

  } else if (strcmp(aspect, "CSX C1288") == 0) {
    initAspects(28, 0, 0, 8, 0);

  } else if (strcmp(aspect, "CSX C1290") == 0) {
    initAspects(40, 29, 0, 29, 37);

  } else if (strcmp(aspect, "CSX C1291") == 0) {
    initAspects(39, 11, 12, 11, 12);

  } else if (strcmp(aspect, "CSX C1292") == 0) {
    initAspects(39, 11, 12, 11, 12);

  } else if (strcmp(aspect, "CSX C1298") == 0) {
    initAspects(39, 11, 12, 11, 12);

  } else if (strcmp(aspect, "CSX CR1281") == 0) {
    initAspects(1, 2, 3, 4, 0);

  } else if (strcmp(aspect, "CSX CR1281A") == 0) {
    initAspects(53, 54, 51, 0, 0);

  } else if (strcmp(aspect, "CSX CR1281B") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "CSX CR1281C") == 0) {
    initAspects(15, 16, 0, 54, 51);

  } else if (strcmp(aspect, "CSX CR1282") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "CSX CR1283") == 0) {
    initAspects(5, 6, 0, 61, 0);

  } else if (strcmp(aspect, "CSX CR1283A") == 0) {
    initAspects(24, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CSX CR1284") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "CSX CR1285") == 0) {
    initAspects(7, 8, 0, 0, 9);

  } else if (strcmp(aspect, "CSX CR1286") == 0) {
    initAspects(28, 18, 0, 43, 0);

  } else if (strcmp(aspect, "CSX CR1287") == 0) {
    initAspects(30, 0, 0, 2, 3);

  } else if (strcmp(aspect, "CSX CR1288") == 0) {
    initAspects(44, 0, 0, 8, 27);

  } else if (strcmp(aspect, "CSX CR1290 Y") == 0) {
    initAspects(31, 29, 0, 29, 9);

  } else if (strcmp(aspect, "CSX CR1290 L") == 0) {
    initAspects(32, 36, 37, 0, 37);

  } else if (strcmp(aspect, "CSX CR1291") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "CSX CR1292") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "CN 803") == 0) {
    initAspects(1, 2, 3, 42, 0);

  } else if (strcmp(aspect, "CN 804") == 0) {
    initAspects(55, 56, 27, 0, 0);

  } else if (strcmp(aspect, "CN 805") == 0) {
    initAspects(7, 8, 9, 0, 27);

  } else if (strcmp(aspect, "CN 806") == 0) {
    initAspects(104, 43, 0, 0, 0);

  } else if (strcmp(aspect, "CN 807") == 0) {
    initAspects(0, 54, 51, 0, 0);

  } else if (strcmp(aspect, "CN 808") == 0) {
    initAspects(19, 20, 0, 0, 0);

  } else if (strcmp(aspect, "CN 809") == 0) {
    initAspects(5, 6, 0, 0, 0);

  } else if (strcmp(aspect, "CN 810") == 0) {
    initAspects(15, 16, 0, 0, 0);

  } else if (strcmp(aspect, "CN 811") == 0) {
    initAspects(17, 18, 0, 0, 0);

  } else if (strcmp(aspect, "CN 812") == 0) {
    initAspects(25, 29, 0, 0, 0);

  } else if (strcmp(aspect, "CN 813") == 0) {
    initAspects(113, 114, 0, 0, 0);

  } else if (strcmp(aspect, "CN 814") == 0) {
    initAspects(115, 116, 79, 0, 0);

  } else if (strcmp(aspect, "CN 815") == 0) {
    initAspects(10, 11, 12, 120, 12);

  } else if (strcmp(aspect, "CN 816") == 0) {
    initAspects(10, 11, 12, 120, 12);

  } else if (strcmp(aspect, "CN 817") == 0) {
    initAspects(1, 2, 3, 4, 0);

  } else if (strcmp(aspect, "CN 818") == 0) {
    initAspects(55, 56, 27, 0, 0);

  } else if (strcmp(aspect, "CN 818.1") == 0) {
    initAspects(25, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CN 818.2") == 0) {
    initAspects(70, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CN 819") == 0) {
    initAspects(7, 8, 9, 0, 0);

  } else if (strcmp(aspect, "CN 820") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "CN 821") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "CN 822") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "CN 823") == 0) {
    initAspects(15, 0, 0, 54, 0);

  } else if (strcmp(aspect, "CN 824") == 0) {
    initAspects(65, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CN 825") == 0) {
    initAspects(17, 0, 0, 56, 0);

  } else if (strcmp(aspect, "CN 826") == 0) {
    initAspects(5, 0, 0, 2, 0);

  } else if (strcmp(aspect, "CN 827") == 0) {
    initAspects(107, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CN 828") == 0) {
    initAspects(28, 0, 0, 8, 0);

  } else if (strcmp(aspect, "CN 829") == 0) {
    initAspects(30, 6, 0, 6, 3);

  } else if (strcmp(aspect, "CN 830") == 0) {
    initAspects(44, 18, 0, 18, 27);

  } else if (strcmp(aspect, "CN 831") == 0) {
    initAspects(31, 29, 0, 29, 9);

  } else if (strcmp(aspect, "CN 832") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "CN 833") == 0) {
    initAspects(0, 2, 3, 0, 0);

  } else if (strcmp(aspect, "CN 834") == 0) {
    initAspects(0, 50, 0, 0, 0);

  } else if (strcmp(aspect, "CN 835") == 0) {
    initAspects(0, 49, 0, 0, 0);

  } else if (strcmp(aspect, "CN 836") == 0) {
    initAspects(0, 20, 0, 0, 0);

  } else if (strcmp(aspect, "CN 837") == 0) {
    initAspects(0, 16, 0, 0, 51);

  } else if (strcmp(aspect, "CN 838") == 0) {
    initAspects(0, 6, 0, 0, 0);

  } else if (strcmp(aspect, "CN 839") == 0) {
    initAspects(0, 8, 9, 0, 0);

  } else if (strcmp(aspect, "CN 840") == 0) {
    initAspects(0, 18, 0, 0, 0);

  } else if (strcmp(aspect, "CN 841") == 0) {
    initAspects(0, 0, 0, 0, 3);

  } else if (strcmp(aspect, "CN 842") == 0) {
    initAspects(0, 0, 0, 0, 27);

  } else if (strcmp(aspect, "CN 843") == 0) {
    initAspects(0, 29, 12, 0, 79);

  } else if (strcmp(aspect, "CN 844") == 0) {
    initAspects(0, 11, 0, 0, 12);

  } else if (strcmp(aspect, "LS&I 230") == 0) {
    initAspects(0, 2, 3, 0, 0);

  } else if (strcmp(aspect, "LS&I 231") == 0) {
    initAspects(0, 8, 9, 0, 0);

  } else if (strcmp(aspect, "LS&I 232") == 0) {
    initAspects(0, 6, 0, 0, 0);

  } else if (strcmp(aspect, "LS&I 233") == 0) {
    initAspects(0, 29, 0, 0, 0);

  } else if (strcmp(aspect, "LS&I 234") == 0) {
    initAspects(0, 35, 37, 0, 0);

  } else if (strcmp(aspect, "LS&I 235") == 0) {
    initAspects(0, 11, 12, 0, 0);

  } else if (strcmp(aspect, "BNSF 9.1.3") == 0) {
    initAspects(1, 2, 3, 2, 3);

  } else if (strcmp(aspect, "BNSF 9.1.4") == 0) {
    initAspects(0, 14, 0, 14, 0);

  } else if (strcmp(aspect, "BNSF 9.1.5") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "BNSF 9.1.6") == 0) {
    initAspects(55, 56, 27, 56, 27);

  } else if (strcmp(aspect, "BNSF 9.1.7") == 0) {
    initAspects(106, 105, 0, 105, 0);

  } else if (strcmp(aspect, "BNSF 9.1.8") == 0) {
    initAspects(7, 8, 9, 8, 9);

  } else if (strcmp(aspect, "BNSF 9.1.9") == 0) {
    initAspects(5, 6, 0, 6, 0);

  } else if (strcmp(aspect, "BNSF 9.1.10") == 0) {
    initAspects(25, 0, 0, 0, 0);

  } else if (strcmp(aspect, "BNSF 9.1.11") == 0) {
    initAspects(17, 18, 0, 18, 0);

  } else if (strcmp(aspect, "BNSF 9.1.12") == 0) {
    initAspects(28, 29, 0, 0, 0);

  } else if (strcmp(aspect, "BNSF 9.1.13") == 0) {
    initAspects(115, 116, 79, 116, 79);

  } else if (strcmp(aspect, "BNSF 9.1.15") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "AMTK 9.1.1") == 0) {
    initAspects(1, 2, 3, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.2") == 0) {
    initAspects(55, 56, 25, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.3") == 0) {
    initAspects(21, 22, 0, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.4") == 0) {
    initAspects(7, 8, 9, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.5") == 0) {
    initAspects(0, 0, 0, 0, 3);

  } else if (strcmp(aspect, "AMTK 9.1.6") == 0) {
    initAspects(0, 0, 0, 0, 27);

  } else if (strcmp(aspect, "AMTK 9.1.7") == 0) {
    initAspects(31, 29, 0, 0, 9);

  } else if (strcmp(aspect, "AMTK 9.1.8") == 0) {
    initAspects(10, 11, 12, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.9") == 0) {
    initAspects(10, 11, 12, 0, 12);

  } else if (strcmp(aspect, "AMTK 9.1.10") == 0) {
    initAspects(19, 20, 0, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.11") == 0) {
    initAspects(13, 14, 0, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.12") == 0) {
    initAspects(5, 6, 0, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.13") == 0) {
    initAspects(15, 16, 0, 0, 0);

  } else if (strcmp(aspect, "AMTK 9.1.14") == 0) {
    initAspects(28, 18, 0, 0, 0);

  } else if (strcmp(aspect, "NS 306") == 0) {
    initAspects(1, 2, 3, 4, 0);

  } else if (strcmp(aspect, "NS 307") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "NS 308") == 0) {
    initAspects(15, 16, 0, 54, 51);

  } else if (strcmp(aspect, "NS 309") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "NS 310") == 0) {
    initAspects(55, 56, 27, 0, 0);

  } else if (strcmp(aspect, "NS 311") == 0) {
    initAspects(5, 6, 0, 61, 0);

  } else if (strcmp(aspect, "NS 312") == 0) {
    initAspects(24, 0, 0, 0, 0);

  } else if (strcmp(aspect, "NS 313") == 0) {
    initAspects(26, 22, 0, 22, 0);

  } else if (strcmp(aspect, "NS 314") == 0) {
    initAspects(7, 8, 9, 0, 0);

  } else if (strcmp(aspect, "NS 315") == 0) {
    initAspects(28, 18, 0, 43, 0);

  } else if (strcmp(aspect, "NS 316") == 0) {
    initAspects(30, 0, 0, 2, 3);

  } else if (strcmp(aspect, "NS 317") == 0) {
    initAspects(44, 0, 0, 8, 27);

  } else if (strcmp(aspect, "NS 318") == 0) {
    initAspects(31, 29, 12, 0, 9);

  } else if (strcmp(aspect, "NS 319") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "NS 326") == 0) {
    initAspects(1, 2, 3, 2, 3);

  } else if (strcmp(aspect, "NS 327") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "NS 328") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "NS 329") == 0) {
    initAspects(5, 6, 0, 6, 0);

  } else if (strcmp(aspect, "NS 330") == 0) {
    initAspects(17, 127, 0, 127, 0);

  } else if (strcmp(aspect, "NS 331") == 0) {
    initAspects(7, 8, 9, 0, 9);

  } else if (strcmp(aspect, "NS 333") == 0) {
    initAspects(28, 128, 0, 128, 0);

  } else if (strcmp(aspect, "NS 334") == 0) {
    initAspects(30, 0, 0, 0, 3);

  } else if (strcmp(aspect, "NS 335") == 0) {
    initAspects(0, 0, 0, 8, 27);

  } else if (strcmp(aspect, "NS 336") == 0) {
    initAspects(31, 29, 0, 29, 9);

  } else if (strcmp(aspect, "NS 337") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "NS 340") == 0) {
    initAspects(1, 2, 3, 2, 3);

  } else if (strcmp(aspect, "NS 341") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "NS 342") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "NS 343") == 0) {
    initAspects(5, 6, 0, 6, 0);

  } else if (strcmp(aspect, "NS 344") == 0) {
    initAspects(55, 56, 27, 56, 27);

  } else if (strcmp(aspect, "NS 345") == 0) {
    initAspects(17, 18, 0, 18, 0);

  } else if (strcmp(aspect, "NS 346") == 0) {
    initAspects(7, 8, 9, 8, 9);

  } else if (strcmp(aspect, "NS 347") == 0) {
    initAspects(28, 29, 0, 29, 0);

  } else if (strcmp(aspect, "NS 348") == 0) {
    initAspects(31, 29, 12, 0, 9);

  } else if (strcmp(aspect, "NS 349") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "NYC 281") == 0) {
    initAspects(1, 2, 3, 4, 0);

  } else if (strcmp(aspect, "NYC 281-A") == 0) {
    initAspects(48, 49, 0, 49, 0);

  } else if (strcmp(aspect, "NYC 281-B") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "NYC 281-C") == 0) {
    initAspects(15, 16, 0, 16, 51);

  } else if (strcmp(aspect, "NYC 281-D") == 0) {
    initAspects(17, 18, 0, 18, 27);

  } else if (strcmp(aspect, "NYC 282") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "NYC 282-A") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "NYC 283") == 0) {
    initAspects(5, 6, 0, 0, 0);

  } else if (strcmp(aspect, "NYC 283-A") == 0) {
    initAspects(25, 0, 0, 0, 0);

  } else if (strcmp(aspect, "NYC 283-B") == 0) {
    initAspects(24, 0, 0, 0, 0);

  } else if (strcmp(aspect, "NYC 284") == 0) {
    initAspects(26, 0, 0, 0, 0);

  } else if (strcmp(aspect, "NYC 285") == 0) {
    initAspects(7, 8, 9, 0, 0);

  } else if (strcmp(aspect, "NYC 286") == 0) {
    initAspects(28, 0, 0, 0, 0);

  } else if (strcmp(aspect, "NYC 287") == 0) {
    initAspects(30, 6, 0, 2, 3);

  } else if (strcmp(aspect, "NYC 288") == 0) {
    initAspects(0, 0, 0, 8, 0);

  } else if (strcmp(aspect, "NYC 290") == 0) {
    initAspects(31, 29, 0, 29, 9);

  } else if (strcmp(aspect, "NYC 291") == 0) {
    initAspects(10, 11, 12, 0, 0);

  } else if (strcmp(aspect, "NYC 292") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "UPRR 9.2.1") == 0) {
    initAspects(1, 2, 3, 2, 3);

  } else if (strcmp(aspect, "UPRR 9.2.2") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "UPRR 9.2.3") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "UPRR 9.2.4") == 0) {
    initAspects(55, 56, 27, 56, 27);

  } else if (strcmp(aspect, "UPRR 9.2.4P") == 0) {
    initAspects(55, 56, 27, 56, 27);

  } else if (strcmp(aspect, "UPRR 9.2.5") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "UPRR 9.2.6") == 0) {
    initAspects(7, 8, 9, 8, 9);

  } else if (strcmp(aspect, "UPRR 9.2.7") == 0) {
    initAspects(106, 105, 0, 105, 0);

  } else if (strcmp(aspect, "UPRR 9.2.8") == 0) {
    initAspects(15, 16, 0, 16, 0);

  } else if (strcmp(aspect, "UPRR 9.2.9") == 0) {
    initAspects(5, 6, 0, 6, 0);

  } else if (strcmp(aspect, "UPRR 9.2.10") == 0) {
    initAspects(17, 18, 0, 18, 0);

  } else if (strcmp(aspect, "UPRR 9.2.10P") == 0) {
    initAspects(17, 18, 0, 18, 0);

  } else if (strcmp(aspect, "UPRR 9.2.11") == 0) {
    initAspects(28, 29, 0, 29, 0);

  } else if (strcmp(aspect, "UPRR 9.2.12") == 0) {
    initAspects(25, 0, 0, 0, 0);

  } else if (strcmp(aspect, "UPRR 9.2.13") == 0) {
    initAspects(33, 35, 37, 35, 37);

  } else if (strcmp(aspect, "UPRR 9.2.14") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "UPRR 9.2.15") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "UPRR 9.2.16") == 0) {
    initAspects(24, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 405") == 0) {
    initAspects(1, 2, 3, 4, 0);

  } else if (strcmp(aspect, "CROR 406") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "CROR 407") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "CROR 408") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "CROR 409") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "CROR 410") == 0) {
    initAspects(109, 43, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 411") == 0) {
    initAspects(7, 8, 9, 0, 0);

  } else if (strcmp(aspect, "CROR 412") == 0) {
    initAspects(96, 97, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 413") == 0) {
    initAspects(58, 95, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 414") == 0) {
    initAspects(99, 100, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 414A") == 0) {
    initAspects(99, 100, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 415") == 0) {
    initAspects(55, 56, 27, 0, 0);

  } else if (strcmp(aspect, "CROR 416") == 0) {
    initAspects(15, 0, 0, 54, 0);

  } else if (strcmp(aspect, "CROR 417") == 0) {
    initAspects(65, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 418") == 0) {
    initAspects(66, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 419") == 0) {
    initAspects(67, 0, 0, 130, 0);

  } else if (strcmp(aspect, "CROR 419A") == 0) {
    initAspects(67, 0, 0, 130, 0);

  } else if (strcmp(aspect, "CROR 420") == 0) {
    initAspects(72, 131, 0, 101, 0);

  } else if (strcmp(aspect, "CROR 421") == 0) {
    initAspects(17, 0, 0, 56, 0);

  } else if (strcmp(aspect, "CROR 422") == 0) {
    initAspects(5, 0, 0, 2, 0);

  } else if (strcmp(aspect, "CROR 423") == 0) {
    initAspects(132, 0, 0, 133, 0);

  } else if (strcmp(aspect, "CROR 424") == 0) {
    initAspects(107, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 425") == 0) {
    initAspects(134, 0, 0, 50, 0);

  } else if (strcmp(aspect, "CROR 425A") == 0) {
    initAspects(134, 0, 0, 50, 0);

  } else if (strcmp(aspect, "CROR 426") == 0) {
    initAspects(135, 61, 0, 43, 0);

  } else if (strcmp(aspect, "CROR 427") == 0) {
    initAspects(28, 0, 0, 8, 0);

  } else if (strcmp(aspect, "CROR 428") == 0) {
    initAspects(30, 6, 0, 6, 3);

  } else if (strcmp(aspect, "CROR 429") == 0) {
    initAspects(44, 18, 0, 18, 27);

  } else if (strcmp(aspect, "CROR 430") == 0) {
    initAspects(31, 29, 0, 29, 9);

  } else if (strcmp(aspect, "CROR 431") == 0) {
    initAspects(30, 6, 0, 6, 3);

  } else if (strcmp(aspect, "CROR 432") == 0) {
    initAspects(73, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 432A") == 0) {
    initAspects(73, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 433") == 0) {
    initAspects(74, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 433A") == 0) {
    initAspects(74, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 434") == 0) {
    initAspects(70, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 434A") == 0) {
    initAspects(70, 0, 0, 0, 0);

  } else if (strcmp(aspect, "CROR 435") == 0) {
    initAspects(44, 18, 0, 18, 27);

  } else if (strcmp(aspect, "CROR 436") == 0) {
    initAspects(31, 29, 12, 29, 9);

  } else if (strcmp(aspect, "CROR 437") == 0) {
    initAspects(0, 11, 12, 0, 0);

  } else if (strcmp(aspect, "CROR 438") == 0) {
    initAspects(77, 78, 0, 78, 79);

  } else if (strcmp(aspect, "CROR 439") == 0) {
    initAspects(10, 11, 12, 11, 12);

  } else if (strcmp(aspect, "NORAC 281") == 0) {
    initAspects(1, 2, 3, 4, 0);

  } else if (strcmp(aspect, "NORAC 281-A") == 0) {
    initAspects(53, 54, 51, 0, 0);

  } else if (strcmp(aspect, "NORAC 281-B") == 0) {
    initAspects(13, 14, 0, 14, 0);

  } else if (strcmp(aspect, "NORAC 281-C") == 0) {
    initAspects(15, 16, 0, 54, 51);

  } else if (strcmp(aspect, "NORAC 282") == 0) {
    initAspects(19, 20, 0, 20, 0);

  } else if (strcmp(aspect, "NORAC 282-A") == 0) {
    initAspects(55, 56, 27, 0, 0);

  } else if (strcmp(aspect, "NORAC 283") == 0) {
    initAspects(5, 6, 0, 61, 0);

  } else if (strcmp(aspect, "NORAC 283-A") == 0) {
    initAspects(24, 0, 0, 0, 0);

  } else if (strcmp(aspect, "NORAC 284") == 0) {
    initAspects(21, 22, 0, 22, 0);

  } else if (strcmp(aspect, "NORAC 285") == 0) {
    initAspects(7, 8, 9, 0, 0);

  } else if (strcmp(aspect, "NORAC 286") == 0) {
    initAspects(28, 18, 0, 43, 0);

  } else if (strcmp(aspect, "NORAC 287") == 0) {
    initAspects(30, 0, 0, 2, 3);

  } else if (strcmp(aspect, "NORAC 288") == 0) {
    initAspects(44, 0, 0, 8, 27);

  } else if (strcmp(aspect, "NORAC 290") == 0) {
    initAspects(31, 29, 0, 29, 9);

  } else if (strcmp(aspect, "NORAC 291") == 0) {
    initAspects(10, 11, 12, 11, 0);

  } else if (strcmp(aspect, "NORAC 292") == 0) {
    initAspects(10, 11, 12, 11, 12);
  
  } else if (strcmp(aspect, "ROTATE") == 0 || strcmp(aspect, "RANDOM") == 0) {
    rotate = 1;
    Serial.print("Enter time to cycle (1-99 sec), send 'C' to cancel ");
    Serial.print(ack);
    Serial.print(" ");
    char cycleDelay[3] = {0, 0, 0};
    readIN(cycleDelay);
	if (cycleDelay[0] == 'C') {
		Serial.print("\nEnter in rule number ");
		loop();
	}
    sscanf(cycleDelay, "%d", &dly);
    if (strcmp(aspect, "ROTATE") == 0) {
	  Serial.print("\nCycling... Send anything to terminate the cycle\n");
      while (Serial.available() == 0) { sigCycle(); }
      serialFlush();
    } else if (strcmp(aspect, "RANDOM") == 0) {
	  Serial.print("\nCycling... Send anything to terminate the cycle\n");
      while (Serial.available() == 0) { sigRand(); }
      serialFlush();
      Serial.print("\n");
    }
  } else { // Otherwise, send non-existant error
    Serial.print("ERROR: NON_EXISTANT\n");
	Serial.print("Enter a rule number ");
	Serial.print(ack);
    loop();
  }
  pinCall();
}

// Method used to rotate through the different indications
void sigCycle() {
  for (int i = 0; i < 136; i++) {
    Serial.print("Indication #");
    Serial.print(i);
    Serial.print(ack);
    Serial.print("\n");
    initAspects(i, i, i, i, i);
    pinCall();
  }
}

// Method used to randomly rotate through the different indications
void sigRand() {
  int r = random(0, 135);
  Serial.print("Indication #");
  Serial.print(r);
  Serial.print(ack);
  Serial.print("\n");
  initAspects(r, r, r, r, r);
  pinCall();
}

// Loads the aspects into the program to be translated into the pin call arrays
void initAspects(int A, int B, int C, int D, int E) { // Signal A, B, C, D, E - On the physical layout, from left to right: E, D, C, B, A
  indications[0] = A; // Sets signal #0 to indication A
  indications[1] = B;
  indications[2] = C;
  indications[3] = D;
  indications[4] = E;
}

// Initalizes all the pin calls
void pinCall() {
  indicationList(0, pin_call_A);
  indicationList(1, pin_call_B);
  indicationList(2, pin_call_C);
  indicationList(3, pin_call_D);
  indicationList(4, pin_call_E);
  
  pinAssign();
}

// Chooses from the list what aspect the indication needs to be assigned to
void indicationList(int j, int pinMatrix[]) {
  if (indications[j] == 0) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 1) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 2) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 3) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 4) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 5) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 6) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 7) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 8) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 9) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 10) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 11) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 12) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 13) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 14) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 15) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 16) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 17) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 18) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 19) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 20) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 21) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 22) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 23) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 2, 0, 0, 0);
    
  } else if (indications[j] == 24) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 25) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0);
    
  } else if (indications[j] == 26) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 27) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 28) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 29) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 30) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 31) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0);
    
  } else if (indications[j] == 32) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    
  } else if (indications[j] == 33) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 34) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    
  } else if (indications[j] == 35) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 36) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (indications[j] == 37) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 38) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 39) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 40) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 41) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 42) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 43) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 44) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 0);
    
  } else if (indications[j] == 45) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 46) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 47) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 48) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 49) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 50) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 51) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 52) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 53) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 54) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 55) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 56) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 57) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 58) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 59) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 60) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 61) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 62) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 63) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 64) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 65) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0);
    
  } else if (indications[j] == 66) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 67) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 2, 0, 0);
    
  } else if (indications[j] == 68) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 1, 0, 0);
    
  } else if (indications[j] == 69) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 70) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 2, 0, 0);
    
  } else if (indications[j] == 71) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 72) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 2, 0);
    
  } else if (indications[j] == 73) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 2, 0, 0, 0);
    
  } else if (indications[j] == 74) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 75) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 76) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0);
    
  } else if (indications[j] == 77) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0);
    
  } else if (indications[j] == 78) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 79) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 80) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 81) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 82) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 83) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 84) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 85) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 86) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 87) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 88) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 89) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 90) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (indications[j] == 91) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 92) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 93) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 94) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 95) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 96) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 97) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 98) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 99) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 100) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 101) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 102) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 103) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0);
    
  } else if (indications[j] == 104) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 105) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (indications[j] == 106) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    
  } else if (indications[j] == 107) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0);
    
  } else if (indications[j] == 108) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 109) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0);
    
  } else if (indications[j] == 110) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0);
    
  } else if (indications[j] == 111) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0);
    
  } else if (indications[j] == 112) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 113) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 114) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 115) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 116) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 117) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 118) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    
  } else if (indications[j] == 119) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 120) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (indications[j] == 121) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 122) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 123) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (indications[j] == 124) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 125) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 126) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0);
    
  } else if (indications[j] == 127) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 128) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 129) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0);
    
  } else if (indications[j] == 130) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 131) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 132) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0);
    
  } else if (indications[j] == 133) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (indications[j] == 134) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 2, 0, 0);
    
  } else if (indications[j] == 135) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2, 0);
  }
}

// Sets up the signal array
void initPinCall(int pinCall[], int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13) {
  pinCall[0] = a0;
  pinCall[1] = a1;
  pinCall[2] = a2;
  pinCall[3] = a3;
  pinCall[4] = a4;
  pinCall[5] = a5;
  pinCall[6] = a6;
  pinCall[7] = a7;
  pinCall[8] = a8;
  pinCall[9] = a9;
  pinCall[10] = a10;
  pinCall[11] = a11;
  pinCall[12] = a12;
  pinCall[13] = a13;
}

// Assigns actions to all the pins on the Arduino board
void pinAssign() {
  int k = 2;                      // Sets up the code to light up signal A
  for (int i = 2; i < 14; i++) {  // Reads through the signal matrix
    pins[i] = pin_call_A[k];
    k++;
  }

  k = 2;                          // Signal B
  for (int i = 22; i < 32; i++) {
    pins[i] = pin_call_B[k];
    k++;
  }

  k = 2;                          // Signal C
  for (int i = 32; i < 40; i++) {
    pins[i] = pin_call_C[k];
    k++;
  }

  k = 2;                          // Signal D
  for (int i = 40; i < 48; i++) {
    pins[i] = pin_call_D[k];
    k++;
  }

  k = 2;                          // Signal E
  for (int i = 48; i < 54; i++) {
    pins[i] = pin_call_E[k];
    k++;
  }

  powerOn();
}

// Lights up the signals
void powerOn() {
  int j = 0;
  for (int i = 2; i < 54; i++) { // DO NOT START i AT 0! ARDUINO WILL GO HAYWIRE!
    if (pins[i] == 0) {          // If 0:
      digitalWrite(i, LOW);      // Turn light off
    } else if (pins[i] == 1) {   // If 1:
      digitalWrite(i, HIGH);     // Turn light on
    } else if (pins[i] == 2) {   // If 2:
      digitalWrite(i, HIGH);     // Turn light on
      flash[j++] = i;            // Mark light for flashing
    }
  }

  if (rotate == 0) { // If the program will NOT rotate through indications
	Serial.print("Enter a rule number: ");
	Serial.print(ack);
    while (Serial.available() == 0) { // This while block will flash the appropriate heads, if no flashing is needed, it will hang the program until data is recieved from Java
      delay(1000);                    // Waits a second (1000 nano seconds)
      for (int i = 0; i < j; i++) {   // Goes through signals marked for flashing
        digitalWrite(flash[i], LOW);  // and turns them off
      }
      delay(1000);                    // Waits a second (1000 nano seconds)
      for (int i = 0; i < j; i++) {
        digitalWrite(flash[i], HIGH); // then turns them back on
      }
    }
    //serialFlush();                    // Flushes any left over Java input (safeguard)
    Serial.print("\n");
    loop();                           // returns to the aspect selector
  } else if (rotate == 1) { // This block will hang the program on an indication for a specified period of time
    while (Serial.available() == 0) { // Allows the cycle to be interrupted at any given time
      int s = dly;                    // stores the delay specified by the Java output
      while (s > 0) {                 // While time from next indication is greater than 0
        delay(1000);                  // repeat flash section
        for (int i = 0; i < j; i++) {
          digitalWrite(flash[i], LOW);
        }
        s--;
        delay(1000);
        for (int i = 0; i < j; i++) {
          digitalWrite(flash[i], HIGH);
        }
        s--;
      }
    break;
    }
  }
}













// End of code