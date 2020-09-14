/*
SignalController Program - Arduino C 
Copyright 2018 by Alex Christmas and Kyle Dick
*/

char rulebook[9];    // Stores the rulebook from user input, adjust number to highest possible number of characters for a rulebook abbreviation
char readIn = -1;    // Used to read in a single character from user input
char indication[12]; // Vice versa for above
int aspects[5];      // Stores what aspects will be displayed on each signal
int pin_call_A[14];  // Stores what LEDs will be lit on each signal
int pin_call_B[14];
int pin_call_C[14];
int pin_call_D[14];
int pin_call_E[14];
int pins[54];        // Stores what action the LEDs will take (0 = OFF, 1 = ON, 2 = FLASHING)
int flash[10];       // Stores what LEDs will be flashing
int rotate = 0;      // Tells the program if it will simply be cycling through indications
int limit = 0;       // Tells the program if the limit of the input feed was exceeded
int dly = 0;         // Delay timer used for rotating through different indications
char ack = 6;        // Used as a serial print out terminate character

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
  Serial.print("SignalController Signal Demonstrator\n");
  Serial.print("Version 22-Jan-2018 | Copyright Alex Christmas & Kyle Dick\n\n");
}

// Rulebook Choices
void loop() {
  int chR = 9; // Max number of characters that can go into the rulebook array (change inital array at top too)
	
	/* Rulebooks programmed in:
	CSX-SBD: CSX System Standard / Seaboard Color-Light
	  CSX-CS: CSX Chessie System / C&O Color-Light
	  CSX-CR: CSX Conrail Color-Light
	    CN-R: CN Route Color-Light
	    CN-S: CN Speed Color-Light
	  CN-BLE: CN Bessemer & Lake Erie Color-Light
	    LS&I: Lake Superior and Ishpeming Color-Light
	    BNSF: BNSF Railway Color-Light
	AMTK-AML: Amtrak Michigan Line Color-Light
	   NS-CR: NS Conrail Territory Color-Light
	   NS-NW: NS N&W Territory Color-Light
	  NS-SOU: NS Southern Territory Color-Light
	     NYC: New York Central Color-Light
	    UPRR: Union Pacific Color-Light
	    CROR: Canadian Railroad Operating Rules Color-Light
	   NORAC: NORAC Color-Light
	  ROTATE: Cycle through all indications every XX seconds
	  RANDOM: Cycle through indications at random
	This list will need to be updated in the Java program if changes are made*/
	
  Serial.print("Enter Rulebook ");
  Serial.print(ack); // Tells the Java program to end Serial read (shows up as a square on Arduino)
  Serial.print(" ");
  
  for (int i = 0; i < chR; i++) {     // Erases any existing data in the rulebook array
    rulebook[i] = 0;
  }
  
  while (Serial.available() == 0) { } // Hangs the program while waiting for input from Java
  int i = 0;                          // Variable used to track the position of where the character will go in the string
  while (Serial.available()) {        // Reads in the Java input one character at a time
    delay(15);                        // Halts the program for a short period so that no communication is missed
    readIn = Serial.read();           // Reads in one character at a time
    rulebook[i] = readIn;             // Puts one character in the rulebook string at a time
    i++;
  }
  Serial.print("\n");
  selBook();
}

// Flushes any remaining user input
void serialFlush() {
  while (Serial.available()) { Serial.read(); }
}

// Selects the rulebook specified
void selBook() {   
    /* CSX-SBD Rules programmed in:
	CSX 1281  - Clear
    CSX 1281B - Approach Limited
    CSX 1281C - Limited Clear
    CSX 1281D - Limited Approach
    CSX 1282  - Approach Medium
    CSX 1282A - Advance Approach
    CSX 1283  - Medium Clear
    CSX 1283A - Medium Approach Medium
    CSX 1283B - Medium Approach Slow
    CSX 1283C - Medium Advance Approach
    CSX 1284  - Approach Slow
    CSX 1285  - Approach
    CSX 1286  - Medium Approach
    CSX 1287  - Slow Clear
    CSX 1288  - Slow Approach
    CSX 1290  - Restricting
    CSX 1291  - Restricted Proceed
    CSX 1292  - Stop
    CSX 1293  - Stop and Check
    CSX 1294  - Stop and Open Switch
    CSX 1298  - Grade
	This list will need to be updated in Java if changes are made*/
    
  if (strcmp(rulebook, "CSX-SBD") == 0) {
  
  } else if (strcmp(rulebook,"CSX-CS") == 0) { // CSX - Chessie System // If Java's input matches this rulebook, print out the rules
    
    Serial.print("CSX C1281  - Clear\n");
    Serial.print("CSX C1281B - Approach Limited\n");
    Serial.print("CSX C1281C - Limited Clear\n");
    Serial.print("CSX C1281D - Limited Approach\n");
    Serial.print("CSX C1282  - Approach Medium\n");
    Serial.print("CSX C1283  - Medium Clear\n");
    Serial.print("CSX C1283A - Medium Approach Medium\n");
    Serial.print("CSX C1283B - Medium Approach Slow\n");
    Serial.print("CSX C1284  - Approach Slow\n");
    Serial.print("CSX C1285  - Approach\n");
    Serial.print("CSX C1286  - Medium Approach\n");
    Serial.print("CSX C1287  - Slow Clear\n");
    Serial.print("CSX C1288  - Slow Approach\n");
    Serial.print("CSX C1290  - Restricting\n");
    Serial.print("CSX C1291  - Restricted Proceed\n");
    Serial.print("CSX C1292  - Stop\n");
    Serial.print("CSX C1298  - Grade\n");

  } else if (strcmp(rulebook,"CSX-CR") == 0) { // CSX - Conrail
    
    Serial.print("CSX CR1281   - Clear\n");
    Serial.print("CSX CR1281A  - Cab Speed\n");
    Serial.print("CSX CR1281B  - Approach Limited\n");
    Serial.print("CSX CR1281C  - Limited Clear\n");
    Serial.print("CSX CR1282   - Approach Medium\n");
    Serial.print("CSX CR1282A  - Advanced Approach\n");
    Serial.print("CSX CR1283   - Medium Clear\n");
    Serial.print("CSX CR1283A  - Medium Approach Medium\n");
    Serial.print("CSX CR1284   - Approach Slow\n");
    Serial.print("CSX CR1285   - Approach\n");
    Serial.print("CSX CR1286   - Medium Approach\n");
    Serial.print("CSX CR1287   - Slow Clear\n");
    Serial.print("CSX CR1288   - Slow Approach\n");
    Serial.print("CSX CR1290 Y - Restricting (Yellow)\n");
	Serial.print("CSX CR1290 L - Restricting (Lunar)\n");
    Serial.print("CSX CR1291   - Restricted Proceed\n");
    Serial.print("CSX CR1292   - Stop\n");

  } else if (strcmp(rulebook,"CN-R") == 0) { // CN - Route Signals
    
    Serial.print("CN 803 - Clear\n");
    Serial.print("CN 804 - Advance Approach\n");
    Serial.print("CN 805 - Approach\n");
    Serial.print("CN 806 - Approach Restricting\n");
    Serial.print("CN 807 - Advance Approach Diverging\n");
    Serial.print("CN 808 - Approach Diverging\n");
    Serial.print("CN 809 - Diverging Clear\n");
    Serial.print("CN 810 - Diverging Clear Approach Diverging\n");
    Serial.print("CN 811 - Diverging Advance Approach\n");
    Serial.print("CN 812 - Diverging Approach\n");
    Serial.print("CN 813 - Diverging Approach Restricting\n");
    Serial.print("CN 814 - Restricting\n");
    Serial.print("CN 815 - Restricted Proceed\n");
    Serial.print("CN 816 - Stop\n");
 
  } else if (strcmp(rulebook,"CN-S") == 0) { // CN - Speed Signals
  
    Serial.print("CN 817   - Clear\n");
    Serial.print("CN 818   - Advance Approach\n");
    Serial.print("CN 818-1 - Medium Advance Approach\n");
    Serial.print("CN 818-2 - Limited Advance Approach\n");
    Serial.print("CN 819   - Approach\n");
    Serial.print("CN 820   - Approach Limited\n");
    Serial.print("CN 821   - Approach Medium\n");
    Serial.print("CN 822   - Approach Slow\n");
    Serial.print("CN 823   - Limited Clear\n");
    Serial.print("CN 824   - Limited Clear Limited\n");
    Serial.print("CN 825   - Limited Approach\n");
    Serial.print("CN 826   - Medium Clear\n");
    Serial.print("CN 827   - Medium Clear Medium\n");
    Serial.print("CN 828   - Medium Approach\n");
    Serial.print("CN 829   - Slow Clear\n");
    Serial.print("CN 830   - Slow Approach\n");
    Serial.print("CN 831   - Restricting\n");
    Serial.print("CN 832   - Stop\n");

  } else if (strcmp(rulebook,"CN-BLE") == 0) { // CN - BLE
    
    Serial.print("CN 833 - Clear\n");
    Serial.print("CN 834 - Approach Limited\n");
    Serial.print("CN 835 - Limited Clear\n");
    Serial.print("CN 836 - Approach Medium\n");
    Serial.print("CN 837 - Medium Clear\n");
    Serial.print("CN 838 - Medium Approach Medium\n");
    Serial.print("CN 839 - Approach\n");
    Serial.print("CN 840 - Medium Approach\n");
    Serial.print("CN 841 - Slow Clear\n");
    Serial.print("CN 842 - Slow Approach\n");
    Serial.print("CN 843 - Restricting\n");
    Serial.print("CN 844 - Stop");

  } else if (strcmp(rulebook,"LS&I") == 0) { // LS&I
    
    Serial.print("LSI 230 - Clear\n");
    Serial.print("LSI 231 - Approach\n");
    Serial.print("LSI 232 - Diverging Clear\n");
    Serial.print("LSI 233 - Diverging Approach\n");
    Serial.print("LSI 234 - Restricting\n");
    Serial.print("LSI 235 - Stop\n");

  } else if (strcmp(rulebook,"BNSF") == 0) { // BNSF
    
    Serial.print("BNSF 9-1-3  - Clear\n");
    Serial.print("BNSF 9-1-4  - Approach Limited\n");
    Serial.print("BNSF 9-1-5  - Advance Approach\n");
    Serial.print("BNSF 9-1-6  - Approach Medium\n");
    Serial.print("BNSF 9-1-7  - Approach Restricting\n");
    Serial.print("BNSF 9-1-8  - Approach\n");
    Serial.print("BNSF 9-1-9  - Diverging Clear\n");
    Serial.print("BNSF 9-1-10 - Diverging Approach Diverging\n");
    Serial.print("BNSF 9-1-11 - Diverging Approach Medium\n");
    Serial.print("BNSF 9-1-12 - Diverging Approach\n");
    Serial.print("BNSF 9-1-13 - Restricting\n");
    Serial.print("BNSF 9-1-14 - Restricting\n");
    Serial.print("BNSF 9-1-15 - Stop\n");

  } else if (strcmp(rulebook,"AMTK-AML") == 0) { // AMTK - Michigan Line
    
    Serial.print("AMTK 9-1-1  - Clear\n");
    Serial.print("AMTK 9-1-2  - Advance Approach\n");
    Serial.print("AMTK 9-1-3  - Approach Slow\n");
    Serial.print("AMTK 9-1-4  - Approach\n");
    Serial.print("AMTK 9-1-5  - Slow Clear\n");
    Serial.print("AMTK 9-1-6  - Slow Approach\n");
    Serial.print("AMTK 9-1-7  - Restricting\n");
    Serial.print("AMTK 9-1-8  - Stop and Proceed\n");
    Serial.print("AMTK 9-1-9  - Stop\n");
    Serial.print("AMTK 9-1-10 - Approach Medium\n");
    Serial.print("AMTK 9-1-11 - Approach Limited\n");
    Serial.print("AMTK 9-1-12 - Medium Clear\n");
    Serial.print("AMTK 9-1-13 - Limited Clear\n");
    Serial.print("AMTK 9-1-14 - Medium Approach\n");

  } else if (strcmp(rulebook,"NS-CR") == 0) { // NS - Conrail
    
    Serial.print("NS 306 - Clear\n");
    Serial.print("NS 307 - Approach Limited\n");
    Serial.print("NS 308 - Limited Clear\n");
    Serial.print("NS 309 - Approach Medium\n");
    Serial.print("NS 310 - Advance Approach\n");
    Serial.print("NS 311 - Medium Clear\n");
    Serial.print("NS 312 - Medium Approach Medium\n");
    Serial.print("NS 313 - Approach Slow\n");
    Serial.print("NS 314 - Approach\n");
    Serial.print("NS 315 - Medium Approach\n");
    Serial.print("NS 316 - Slow Clear\n");
    Serial.print("NS 317 - Slow Approach\n");
    Serial.print("NS 318 - Restricting\n");
    Serial.print("NS 319 - Stop\n");

  } else if (strcmp(rulebook,"NS-NW") == 0) { // NS - N&W
    
    Serial.print("NS 326 - Clear\n");
    Serial.print("NS 327 - Approach Diverging\n");
    Serial.print("NS 328 - Advance Approach\n");
    Serial.print("NS 329 - Diverging Clear\n");
    Serial.print("NS 330 - Diverging Approach Diverging\n");
    Serial.print("NS 331 - Approach\n");
    Serial.print("NS 333 - Diverging Approach\n");
    Serial.print("NS 334 - Slow Clear\n");
    Serial.print("NS 335 - Slow Approach\n");
    Serial.print("NS 336 - Restricting\n");
    Serial.print("NS 337 - Stop\n");

  } else if (strcmp(rulebook,"NS-SOU") == 0) { // NS - SOU
    
    Serial.print("NS 340 - Clear\n");
    Serial.print("NS 341 - Approach Diverging\n");
    Serial.print("NS 342 - Advance Approach\n");
    Serial.print("NS 343 - Diverging Clear\n");
    Serial.print("NS 344 - Approach Restricted\n");
    Serial.print("NS 345 - Diverging Approach Restricted\n");
    Serial.print("NS 346 - Approach\n");
    Serial.print("NS 347 - Diverging Approach\n");
    Serial.print("NS 348 - Restricting\n");
    Serial.print("NS 349 - Stop\n");

  } else if (strcmp(rulebook,"NYC") == 0) { // NS - New York Central
    
    Serial.print("NYC 281  - Clear\n");
    Serial.print("NYC 281A - Advance Approach Medium\n");
    Serial.print("NYC 281B - Approach Limited\n");
    Serial.print("NYC 281C - Limited Clear\n");
    Serial.print("NYC 281D - Limited Approach\n");
    Serial.print("NYC 282  - Approach Medium\n");
    Serial.print("NYC 282A - Advance Approach\n");
    Serial.print("NYC 283  - Medium Clear\n");
    Serial.print("NYC 283A - Medium Advance Approach\n");
    Serial.print("NYC 283B - Medium Approach Slow\n");
    Serial.print("NYC 284  - Approach Slow\n");
    Serial.print("NYC 285  - Approach\n");
    Serial.print("NYC 286  - Medium Approach\n");
    Serial.print("NYC 287  - Slow Clear\n");
    Serial.print("NYC 288  - Slow Approach\n");
    Serial.print("NYC 290  - Restricting\n");
    Serial.print("NYC 291  - Stop and Proceed\n");
    Serial.print("NYC 292  - Stop\n");

  } else if (strcmp(rulebook,"UPRR") == 0) { // UPRR (Union Pacific);
    
    Serial.print("UP 9-2-1  - Clear\n");
    Serial.print("UP 9-2-2  - Approach Clear Sixty\n");
    Serial.print("UP 9-2-3  - Approach Clear Fifty\n");
    Serial.print("UP 9-2-4  - Advance Approach\n");
    Serial.print("UP 9-2-5  - Approach Diverging\n");
    Serial.print("UP 9-2-6  - Approach\n");
    Serial.print("UP 9-2-7  - Approach Restricting\n");
    Serial.print("UP 9-2-8  - Diverging Clear Limited\n");
    Serial.print("UP 9-2-9  - Diverging Clear\n");
    Serial.print("UP 9-2-10 - Diverging Advance Approach\n");
    Serial.print("UP 9-2-11 - Diverging Approach\n");
    Serial.print("UP 9-2-12 - Diverging Approach Diverging\n");
    Serial.print("UP 9-2-13 - Restricting\n");
    Serial.print("UP 9-2-14 - Restricted Proceed\n");
    Serial.print("UP 9-2-15 - Stop\n");
    Serial.print("UP 9-2-16 - Diverging Approach Clear Fifty\n");

  } else if (strcmp(rulebook,"CROR") == 0) { // CROR
    
    Serial.print("CROR 405 - Clear\n");
    Serial.print("CROR 406 - Clear to Limited\n");
    Serial.print("CROR 407 - Clear to Medium\n");
    Serial.print("CROR 408 - Clear to Diverging\n");
    Serial.print("CROR 409 - Clear to Slow\n");
    Serial.print("CROR 410 - Clear to Restricting\n");
    Serial.print("CROR 411 - Clear to Stop\n");
    Serial.print("CROR 412 - Advance Clear to Limited\n");
    Serial.print("CROR 413 - Advance Clear to Medium\n");
    Serial.print("CROR 414 - Advance Clear to Slow\n");
    Serial.print("CROR 415 - Advance Clear to Stop\n");
    Serial.print("CROR 416 - Limited to Clear\n");
    Serial.print("CROR 417 - Limited to Limited\n");
    Serial.print("CROR 418 - Limited to Medium\n");
    Serial.print("CROR 419 - Limited to Slow\n");
    Serial.print("CROR 420 - Limited to Restricting\n");
    Serial.print("CROR 421 - Limited to Stop\n");
    Serial.print("CROR 422 - Medium to Clear\n");
    Serial.print("CROR 423 - Medium to Limited\n");
    Serial.print("CROR 424 - Medium to Medium\n");
    Serial.print("CROR 425 - Medium to Slow\n");
    Serial.print("CROR 426 - Medium to Restricting\n");
    Serial.print("CROR 427 - Medium to Stop\n");
    Serial.print("CROR 428 - Diverging to Clear\n");
    Serial.print("CROR 429 - Diverging to Stop\n");
    Serial.print("CROR 430 - Diverging\n");
    Serial.print("CROR 431 - Slow to Clear\n");
    Serial.print("CROR 432 - Slow to Limited\n");
    Serial.print("CROR 433 - Slow to Medium\n");
    Serial.print("CROR 434 - Slow to Slow\n");
    Serial.print("CROR 435 - Slow to Stop\n");
    Serial.print("CROR 436 - Restricting\n");
    Serial.print("CROR 437 - Stop and Proceed\n");
    Serial.print("CROR 438 - Take/Leave Siding\n");
    Serial.print("CROR 439 - Stop\n");
    
  } else if (strcmp(rulebook,"NORAC") == 0) { // NORAC
    
    Serial.print("NORAC 281  - Clear\n");
    Serial.print("NORAC 281A - Cab Speed\n");
    Serial.print("NORAC 281B - Approach Limited\n");
    Serial.print("NORAC 281C - Limited Clear\n");
    Serial.print("NORAC 282  - Approach Medium\n");
    Serial.print("NORAC 282A - Advanced Approach\n");
    Serial.print("NORAC 283  - Medium Clear\n");
    Serial.print("NORAC 284  - Approach Slow\n");
    Serial.print("NORAC 285  - Approach\n");
    Serial.print("NORAC 286  - Medium Approach\n");
    Serial.print("NORAC 287  - Slow Clear\n");
    Serial.print("NORAC 288  - Slow Approach\n");
    Serial.print("NORAC 290  - Restricting\n");
    Serial.print("NORAC 291  - Stop and Proceed\n");
    Serial.print("NORAC 292  - Stop\n");
  
  } else if (strcmp(rulebook, "ROTATE") == 0 || strcmp(rulebook, "RANDOM") == 0) { // change to just an if statement when the Serial.print()'s are removed above
  
    rotate = 1;
    Serial.print("Enter time to cycle (1-99) ");
	Serial.print(ack);
	Serial.print(" ");
    while (Serial.available() == 0) { }
    int i = 0;
    char cycleDelay[3] = {0, 0, 0}; // Stores the length of the indication cycle as a string
    while (Serial.available()) {
      delay(5);
      readIn = Serial.read();
      cycleDelay[i] = readIn;
      i++;
    }
    sscanf(cycleDelay, "%d", &dly); // Stores the delay as an integer
    if (strcmp(rulebook, "ROTATE") == 0) {
    Serial.print("\n\nCycling... Click kill button in Java to terminate cycle\n");
    Serial.print(ack);
      while (Serial.available() == 0) {
        sigCycle();
      }
      serialFlush();
    } else if (strcmp(rulebook, "RANDOM") == 0) {
      Serial.print("\n\nRandom Cycling... Click kill button in Java to terminate cycle\n");
      Serial.print(ack);
      while (Serial.available() == 0) {
        sigRand();
      }
      serialFlush();
      Serial.print("\n");
    }

  } else {
    Serial.print("ERROR: ");
    Serial.print(rulebook);
    Serial.print(" doesn't exist. Please try again.\n");
    loop();
  }

  int chM = 13; // Max number of characters the indication array can hold
  for (int i = 0; i < chM; i++) {
    indication[i] = 0;
  }

  if (rotate == 0) {
    Serial.print("Enter signal indication ");
    Serial.print(ack);
	Serial.print(" ");
    while (Serial.available() == 0) { }
    int i = 0;
    while (Serial.available()) {
      delay(5);
      readIn = Serial.read();
      indication[i] = readIn;
      i++;
    }
    Serial.print("\n\n");
    if (strcmp(indication, "BACK") == 0) {
      loop();
    }
    selRule();
  } else if (rotate == 1) {
    rotate = 0;
  }
}

// Method used to rotate through the different indications
void sigCycle() {
  for (int i = 0; i < 136; i++) {
    //Serial.print("Indication #");
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
  //Serial.print("Indication #");
  Serial.print(r);
  Serial.print(ack);
  Serial.print("\n");
  initAspects(r, r, r, r, r);
  pinCall();
}

// Loads the aspects into the program to be translated into the pin call arrays
void initAspects(int A, int B, int C, int D, int E) { // Signal A, B, C, D, E - On the physical layout, from left to right: E, D, C, B, A
  aspects[0] = A;
  aspects[1] = B;
  aspects[2] = C;
  aspects[3] = D;
  aspects[4] = E;
}

// Sets the aspects to the corresponding rules and signal types
void selRule() {  
  if (strcmp(indication, "CSX 1281") == 0) { // If the indication matches the rule...
    initAspects(1, 2, 3, 4, 0);
    
  } else if (strcmp(indication, "CSX 1281B") == 0) {
    initAspects(13, 14, 0, 16, 0);
    
  } else if (strcmp(indication, "CSX 1281C") == 0) {
    initAspects(15, 16, 0, 16, 0);
    
  } else if (strcmp(indication, "CSX 1281D") == 0) {
    initAspects(17, 18, 0, 18, 0);
    
  } else if (strcmp(indication, "CSX 1282") == 0) {
    initAspects(19, 20, 0, 20, 0);
    
  } else if (strcmp(indication, "CSX 1282A") == 0) {
    initAspects(21, 22, 0, 0, 0);
    
  } else if (strcmp(indication, "CSX 1283") == 0) {
    initAspects(5, 6, 0, 6, 0);
    
  } else if (strcmp(indication, "CSX 1283A") == 0) {
    initAspects(23, 0, 0, 0, 0);
    
  } else if (strcmp(indication, "CSX 1283B") == 0) {
    initAspects(24, 0, 0, 0, 0);
    
  } else if (strcmp(indication, "CSX 1283C") == 0) {
    initAspects(25, 0, 0, 22, 0);
    
  } else if (strcmp(indication, "CSX 1284") == 0) {
    initAspects(26, 0, 0, 0, 0); 
    
  } else if (strcmp(indication, "CSX 1285") == 0) {
    initAspects(7, 8, 9, 0, 0);
    
  } else if (strcmp(indication, "CSX 1286") == 0) {
    initAspects(28, 29, 0, 29, 0);
    
  } else if (strcmp(indication, "CSX 1287") == 0) {
    initAspects(30, 0, 0, 2, 3);
    
  } else if (strcmp(indication, "CSX 1288") == 0) {
    initAspects(31, 0, 0, 8, 9); 
    
  } else if (strcmp(indication, "CSX 1290") == 0) {
    initAspects(32, 36, 37, 36, 37);
    
  } else if (strcmp(indication, "CSX 1291") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(indication, "CSX 1292") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(indication, "CSX 1293") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(indication, "CSX 1294") == 0) {
    initAspects(10, 11, 12, 11, 12);
    
  } else if (strcmp(indication, "CSX 1298") == 0) {
    initAspects(10, 11, 12, 11, 12);
  } else {
    Serial.print("ERROR: ");
    Serial.print(indication);
    Serial.print(" doesn't exist. Please try again.\n");
    selBook();
  }
  pinCall();
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

// Chooses from the list what aspect the indication needs to be assigned to
void indicationList(int j, int pinMatrix[]) {
  if (aspects[j] == 0) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 1) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 2) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 3) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 4) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 5) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 6) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 7) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 8) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 9) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 10) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 11) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 12) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 13) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 14) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 15) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 16) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 17) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 18) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 19) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 20) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 21) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 22) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 23) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 2, 0, 0, 0);
    
  } else if (aspects[j] == 24) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 25) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0);
    
  } else if (aspects[j] == 26) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 27) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 28) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 29) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 30) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 31) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0);
    
  } else if (aspects[j] == 32) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    
  } else if (aspects[j] == 33) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 34) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    
  } else if (aspects[j] == 35) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 36) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (aspects[j] == 37) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 38) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 39) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 40) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 41) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 42) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 43) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 44) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 0);
    
  } else if (aspects[j] == 45) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 46) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 47) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 48) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 49) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 50) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 51) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 52) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 53) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 54) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 55) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 56) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 57) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 58) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 59) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 60) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 61) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 62) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 63) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 64) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 65) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0);
    
  } else if (aspects[j] == 66) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 67) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 2, 0, 0);
    
  } else if (aspects[j] == 68) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 1, 0, 0);
    
  } else if (aspects[j] == 69) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 70) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 2, 0, 0);
    
  } else if (aspects[j] == 71) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 72) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 2, 0);
    
  } else if (aspects[j] == 73) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 2, 0, 0, 0);
    
  } else if (aspects[j] == 74) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 75) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 76) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0);
    
  } else if (aspects[j] == 77) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0);
    
  } else if (aspects[j] == 78) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 79) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 80) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 81) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 82) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 83) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 84) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 85) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 86) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 87) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 88) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 89) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 90) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (aspects[j] == 91) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 92) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 93) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 94) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 95) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 96) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 97) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 98) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 99) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 100) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 101) {
    initPinCall(pinMatrix, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 102) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 103) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0);
    
  } else if (aspects[j] == 104) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 105) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (aspects[j] == 106) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    
  } else if (aspects[j] == 107) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0);
    
  } else if (aspects[j] == 108) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 109) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0);
    
  } else if (aspects[j] == 110) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0);
    
  } else if (aspects[j] == 111) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0);
    
  } else if (aspects[j] == 112) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 113) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 114) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 115) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 116) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 117) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 118) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
    
  } else if (aspects[j] == 119) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 120) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (aspects[j] == 121) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 122) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 123) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    
  } else if (aspects[j] == 124) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 125) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 126) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0);
    
  } else if (aspects[j] == 127) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 128) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 129) {
    initPinCall(pinMatrix, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0);
    
  } else if (aspects[j] == 130) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 131) {
    initPinCall(pinMatrix, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 132) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0);
    
  } else if (aspects[j] == 133) {
    initPinCall(pinMatrix, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0);
    
  } else if (aspects[j] == 134) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 2, 0, 0);
    
  } else if (aspects[j] == 135) {
    initPinCall(pinMatrix, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 2, 0);
  }
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

// Assigns actions to all the pins on the Arduino board
void pinAssign() {
  int k = 2;                      // Sets up the code to light up signal A
  for (int i = 2; i < 14; i++) {
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
    if (pins[i] == 0) {        // OFF
      digitalWrite(i, LOW);
    } else if (pins[i] == 1) { // ON
      digitalWrite(i, HIGH);
    } else if (pins[i] == 2) { // FLASH
      digitalWrite(i, HIGH);
      flash[j] = i;
      j++;
    }
  }

  if (rotate == 0) {
    Serial.print("Press the reset button in Java to select a different aspect");
  Serial.print(ack);
    while (Serial.available() == 0) { // This while block will flash the appropriate heads, if no flashing is needed, it will hang the program until the user sends something in
      delay(1000);
      for (int i = 0; i < j; i++) {
        digitalWrite(flash[i], LOW);
      }
      delay(1000);
      for (int i = 0; i < j; i++) {
        digitalWrite(flash[i], HIGH);
      }
    }
    serialFlush();
    Serial.print("\n\n");
    selBook(); // returns to the rulebook
  } else if (rotate == 1) { // This block will hang the program on an indication for a specified period of time
    int s = dly;
    while (s > 0) {
      delay(1000);
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
  }
}



















// End of Code