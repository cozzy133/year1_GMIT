/* Forward -> F
Back -> B
Left -> L
Right -> R
Forward Left -> G
Forward Right -> I
Backleft -> H
Back Right -> J
Stop -> S
Front Lights on -> W
Front Lights off -> w
Back Lights on -> U
Back lights off ->u
Horn On -> V
Horn Off -> v
Extra On -> X
Extra Off -> x
Speed 10 -> 1
Speed 20 -> 2
Speed 30 -> 3
Speed 40 -> 4
Speed 50 -> 5
Speed 60 -> 6
Speed 70 -> 7
Speed 80 -> 8
Speed 90 -> 9
Speed 100 -> q
Stop All -> D
*/

int moveCar( int x, int y);
int vSpeed = 0;

int motorControl[6] = {5, 6, 8, 13, 10, 12}; // motorRPlus, motorLPlus, motorRE, motorLE, motorRMinus, motorLMinus //
int leds[5] = {A5, A4, 3, 4, 9};

const int bluetooth = 0;
//const int motionSensor = 2;
const int leftLedA = A5; //D12
const int leftLedB = A4; //D13
const int centerLed = 3; //D1
const int rightLedB = 4; // D5
const int rightLedA = 9; // D4
const int bumpR = 11; // D3
const int bumpL = 7; // D2
const int motorRE = 8; // D6
const int motorLE = 13; // D11
const int motorRPlus = 5; // D7
const int motorRMinus = 10; // D8
const int motorLPlus = 6; // D9
const int motorLMinus = 12; // D10

int state = 0;
void setup() {
  Serial.begin(9600);
  pinMode(bluetooth, INPUT);
  pinMode(leftLedA, OUTPUT);
  pinMode(leftLedB, OUTPUT);
  pinMode(centerLed, OUTPUT);
  pinMode(rightLedB, OUTPUT);
  pinMode(rightLedA, OUTPUT);
  pinMode(bumpR, INPUT);
  pinMode(bumpL, INPUT);
  pinMode(motorRE, OUTPUT);
  pinMode(motorLE, OUTPUT);
  pinMode(motorRPlus, OUTPUT);
  pinMode(motorRMinus, OUTPUT);
  pinMode(motorLPlus, OUTPUT);
  pinMode(motorLMinus, OUTPUT);

}

void loop() {

  if (digitalRead(bluetooth) == LOW) {
    state = 'S';
  }

  if (Serial.available() > 0) {
    state = Serial.read();
  }

  if (state == '1') {
    vSpeed = 25;
  }
  else if (state == '2') {
    vSpeed = 50;
  }
  else if (state == '3') {
    vSpeed = 75;
  }
  else if (state == '4') {
    vSpeed = 100;
  }
  else if (state == '5') {
    vSpeed = 125;
  }
  else if (state == '6') {
    vSpeed = 150;
  }
  else if (state == '7') {
    vSpeed = 175;
  }
  else if (state == '8') {
    vSpeed = 200;
  }
  else if (state == '9') {
    vSpeed = 225;
  }
  else if (state == 'q') {
    vSpeed = 255;
  }

  /***********************Forward****************************/
  if (state == 'F') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], vSpeed); moveCar(motorControl[0], vSpeed);
    moveCar(motorControl[5], 0); moveCar(motorControl[4], 0);
  }
  /**********************Forward Left************************/
  else if (state == 'G') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], vSpeed / 2); moveCar(motorControl[0], vSpeed);
    moveCar(motorControl[5], 0); moveCar(motorControl[4], 0);

  }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
  else if (state == 'I') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], vSpeed); moveCar(motorControl[0], vSpeed / 2);
    moveCar(motorControl[5], 0); moveCar(motorControl[4], 0);
  }
  /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
  else if (state == 'B') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], 0); moveCar(motorControl[0], 0);
    moveCar(motorControl[5], vSpeed); moveCar(motorControl[4], vSpeed);
  }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
  else if (state == 'H') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], 0); moveCar(motorControl[0], 0);
    moveCar(motorControl[5], vSpeed / 2); moveCar(motorControl[4], vSpeed);
  }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
  else if (state == 'J') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], 0); moveCar(motorControl[0], 0);
    moveCar(motorControl[5], vSpeed); moveCar(motorControl[4], vSpeed / 2);
  }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left3
  else if (state == 'L') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], 0); moveCar(motorControl[0], vSpeed);
    moveCar(motorControl[5], 0); moveCar(motorControl[4], 0);
  }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
  else if (state == 'R') {
    moveCar(motorControl[3], 255); moveCar(motorControl[2], 255);
    moveCar(motorControl[1], vSpeed); moveCar(motorControl[0], 0);
    moveCar(motorControl[5], 0); moveCar(motorControl[4], 0);
  }
  /************************Lights*****************************/
 /* //If state is equal with letter 'W', turn leds on or off
  else if (state == 'W') {
    }
    state = 'n';
  }
  */
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
  else if (state == 'S') {
    moveCar(motorControl[3], 0); moveCar(motorControl[2], 0);
    moveCar(motorControl[1], 0); moveCar(motorControl[0], 0);
    moveCar(motorControl[5], 0); moveCar(motorControl[4], 0);
  }
  /***********************Battery*****************************/

}


int moveCar( int x, int y) {
  analogWrite( x, y) ;
}
