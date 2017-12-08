#include <Servo.h>

// Arduino pins
// Servos
const int servoPin [4] = {3, 5, 6, 9};

Servo servos [4];

// Servo degrees read from Serial
int degs [4];

// Temp variables for Serial read
char inData[32];
bool isRead = false;
int index = 0;

void setup() {
  // Initialize Servos
  for (int i = 0; i < 4; ++i) {
    servos[i].attach(servoPin[i]);
    degs[i] = 45;
  }
  // Open Serial
  Serial.begin(9600);
}

void loop() {
  // Read from Serial
  readSerialStr(degs, 4);

  // Wrtie degrees to servos
  for (int i = 0; i < 4; ++i) {
    if( degs[i] == 0 or degs[i] == 60 or degs[i] == 120 or degs[i] == 180 ){
      servos[i].write(degs[i]);
    }
  }

  // waits for the servo to get there
  delay(15);
}

void readSerialStr(int data [], int size) {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    while (incomingByte != '\n' && isDigit(incomingByte)) {
      isRead = true;
      inData[index] = incomingByte;
      index++;
      incomingByte = Serial.read();
    }
    inData[index] = '\0';
  }

  if (isRead) {
    char data1_char[4];
    char data2_char[4];
    char data3_char[4];
    char data4_char[4];

    data1_char[0] = inData[0];
    data1_char[1] = inData[1];
    data1_char[2] = inData[2];
    data1_char[3] = '\0';

    data2_char[0] = inData[3];
    data2_char[1] = inData[4];
    data2_char[2] = inData[5];
    data2_char[3] = '\0';

    data3_char[0] = inData[6];
    data3_char[1] = inData[7];
    data3_char[2] = inData[8];
    data3_char[3] = '\0';

    data4_char[0] = inData[9];
    data4_char[1] = inData[10];
    data4_char[2] = inData[11];
    data4_char[3] = '\0';

    data [0] = atoi(data1_char);
    data [1] = atoi(data2_char);
    data [2] = atoi(data3_char);
    data [3] = atoi(data4_char);

    isRead = false;
    index = 0;
  }
}
