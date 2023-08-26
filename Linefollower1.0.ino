//Black line gives HIGH output in IR
//defining those so that I don't mess up later
#define white LOW
#define black HIGH
int speed = 190;

//IR Sensor
int lIR = 11;
int rIR = 12;

//Left motor
int enL=3;
int l1=5;
int l2=4;

//Right motor
int enR=9;
int r1=7;
int r2=6;

void runMotor(int lMotor, int rMotor) {
  analogWrite(enL, abs(lMotor));
  analogWrite(enR, abs(rMotor));

  if (lMotor < 0) {
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
  } else if (lMotor > 0) {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
  } else {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
  }

  if (rMotor < 0) {
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
  } else if (rMotor > 0) {
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
  } else {
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
  }  
}

void setup() {
  // put your setup code here, to run once:

  //These are the codes for changing the output PWM frequency
  //This is for fine tuning the speed of motor
  //Higher frequency means lower speed
  //D5, D6
  // TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz
  // TCCR0B = TCCR0B & B11111000 | B00000010; // for PWM frequency of 7812.50 Hz
  // TCCR0B = TCCR0B & B11111000 | B00000011; // for PWM frequency of 976.56 Hz (The DEFAULT)
  // TCCR0B = TCCR0B & B11111000 | B00000100; // for PWM frequency of 244.14 Hz
  // TCCR0B = TCCR0B & B11111000 | B00000101; // for PWM frequency of 61.04 Hz

  //D9(right), D10
  // TCCR1B = TCCR1B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  TCCR1B = TCCR1B & B11111000 | B00000010; // for PWM frequency of 3921.16 Hz
  // TCCR1B = TCCR1B & B11111000 | B00000011; // for PWM frequency of 490.20 Hz (The DEFAULT)
  // TCCR1B = TCCR1B & B11111000 | B00000100; // for PWM frequency of 122.55 Hz
  // TCCR1B = TCCR1B & B11111000 | B00000101; // for PWM frequency of 30.64 Hz

  //D3(left), D11
  // TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  TCCR2B = TCCR2B & B11111000 | B00000010; // for PWM frequency of 3921.16 Hz
  // TCCR2B = TCCR2B & B11111000 | B00000011; // for PWM frequency of 980.39 Hz
  // TCCR2B = TCCR2B & B11111000 | B00000100; // for PWM frequency of 490.20 Hz (The DEFAULT)
  // TCCR2B = TCCR2B & B11111000 | B00000101; // for PWM frequency of 245.10 Hz
  // TCCR2B = TCCR2B & B11111000 | B00000110; // for PWM frequency of 122.55 Hz
  // TCCR2B = TCCR2B & B11111000 | B00000111; // for PWM frequency of 30.64 Hz

  pinMode(enL, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(r2, OUTPUT);

  pinMode(enR, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);  
  runMotor(0,0);

}

void loop() {
  // put your main code here, to run repeatedly:
  int leftIR = digitalRead(lIR);
  int rightIR = digitalRead(rIR);

  if (leftIR==white && rightIR==white) {
    runMotor(speed, speed);
  }
  if (leftIR==black && rightIR==white) {
    runMotor(0, speed);
  }
  if (leftIR==white && rightIR==black) {
    runMotor(speed, 0);
  }
  if (leftIR==black && rightIR==black) {
    runMotor(0,0);
  }
}
