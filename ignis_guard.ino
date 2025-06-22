<<<<<<< HEAD
#include <SoftwareSerial.h>

const String PHONE_1 = "+91782709XXXX";  // Your phone number
const String PHONE_2 = "+91964828XXXX";  // Optional
const String PHONE_3 = "";  // Optional

#define rxPin 2
#define txPin 3
SoftwareSerial sim900A(rxPin, txPin);

int Flame_sensor = 5;  // Pin for Flame sensor
int Flame_detected;

#define ledPin 6  // Pin for LED
#define buzzerPin 8  // Pin for Buzzer

void setup() {
  Serial.begin(115200);  // Serial monitor communication
  sim900A.begin(9600);   // Baud rate for SIM900A
  
  pinMode(Flame_sensor, INPUT);   // Set Flame sensor pin as input
  pinMode(ledPin, OUTPUT);        // Set LED pin as output
  pinMode(buzzerPin, OUTPUT);     // Set Buzzer pin as output
  digitalWrite(ledPin, LOW);      // Initial state of LED (off)
  digitalWrite(buzzerPin, LOW);   // Initial state of Buzzer (off)
  
  Serial.println("Initializing...");
  
  // Initialize SIM900A
  sim900A.println("AT");
  delay(1000);
  sim900A.println("AT+CMGF=1");  // Set SMS mode
  delay(1000);
}

void loop() {
  while (sim900A.available()) {
    Serial.println(sim900A.readString());  // Displaying SIM900A responses on Serial Monitor
  }

  Flame_detected = digitalRead(Flame_sensor);  // Read flame sensor value
  Serial.println(Flame_detected);

  if (Flame_detected == 0) {  // Fire detected (0 means flame detected)
    digitalWrite(ledPin, HIGH);   // Turn on LED
    digitalWrite(buzzerPin, HIGH);   // Turn on Buzzer
    Serial.println("Fire detected...! Take action immediately.");
    send_multi_sms();  // Send SMS to multiple numbers
    make_multi_call(); // Make calls to multiple numbers
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
    digitalWrite(buzzerPin, LOW);   // Turn off Buzzer
  }
}

// Function to send SMS to multiple numbers
void send_multi_sms() {
  if (PHONE_1 != "") {
    Serial.print("Sending SMS to Phone 1: ");
    send_sms("Fire detected...! Take action immediately.", PHONE_1);
  }
  if (PHONE_2 != "") {
    Serial.print("Sending SMS to Phone 2: ");
    send_sms("Fire detected...! Take action immediately.", PHONE_2);
  }
  if (PHONE_3 != "") {
    Serial.print("Sending SMS to Phone 3: ");
    send_sms("Fire detected...! Take action immediately.", PHONE_3);
  }
}

// Function to make calls to multiple numbers
void make_multi_call() {
  if (PHONE_1 != "") {
    Serial.print("Making call to Phone 1: ");
    make_call(PHONE_1);
  }
  if (PHONE_2 != "") {
    Serial.print("Making call to Phone 2: ");
    make_call(PHONE_2);
  }
  if (PHONE_3 != "") {
    Serial.print("Making call to Phone 3: ");
    make_call(PHONE_3);
  }
}

// Function to send SMS
void send_sms(String text, String phone) {
  Serial.println("Sending SMS...");
  delay(50);
  sim900A.print("AT+CMGF=1\r");
  delay(1000);
  sim900A.print("AT+CMGS=\"" + phone + "\"\r");
  delay(1000);
  sim900A.print(text);  // SMS body text
  delay(100);
  sim900A.write(0x1A);  // Send Ctrl+Z to send the SMS
  delay(5000);  // Wait for SMS to be sent
}

// Function to make call
void make_call(String phone) {
  Serial.println("Making call...");
  sim900A.println("ATD" + phone + ";");
  delay(20000);  // 20 sec call duration
  sim900A.println("ATH");  // End call
  delay(1000);  // Wait for 1 second
}
=======
#include <SoftwareSerial.h>

const String PHONE_1 = "+91782709XXXX";  // Your phone number
const String PHONE_2 = "+91964828XXXX";  // Optional
const String PHONE_3 = "";  // Optional

#define rxPin 2
#define txPin 3
SoftwareSerial sim900A(rxPin, txPin);

int Flame_sensor = 5;  // Pin for Flame sensor
int Flame_detected;

#define ledPin 6  // Pin for LED
#define buzzerPin 8  // Pin for Buzzer

void setup() {
  Serial.begin(115200);  // Serial monitor communication
  sim900A.begin(9600);   // Baud rate for SIM900A
  
  pinMode(Flame_sensor, INPUT);   // Set Flame sensor pin as input
  pinMode(ledPin, OUTPUT);        // Set LED pin as output
  pinMode(buzzerPin, OUTPUT);     // Set Buzzer pin as output
  digitalWrite(ledPin, LOW);      // Initial state of LED (off)
  digitalWrite(buzzerPin, LOW);   // Initial state of Buzzer (off)
  
  Serial.println("Initializing...");
  
  // Initialize SIM900A
  sim900A.println("AT");
  delay(1000);
  sim900A.println("AT+CMGF=1");  // Set SMS mode
  delay(1000);
}

void loop() {
  while (sim900A.available()) {
    Serial.println(sim900A.readString());  // Displaying SIM900A responses on Serial Monitor
  }

  Flame_detected = digitalRead(Flame_sensor);  // Read flame sensor value
  Serial.println(Flame_detected);

  if (Flame_detected == 0) {  // Fire detected (0 means flame detected)
    digitalWrite(ledPin, HIGH);   // Turn on LED
    digitalWrite(buzzerPin, HIGH);   // Turn on Buzzer
    Serial.println("Fire detected...! Take action immediately.");
    send_multi_sms();  // Send SMS to multiple numbers
    make_multi_call(); // Make calls to multiple numbers
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
    digitalWrite(buzzerPin, LOW);   // Turn off Buzzer
  }
}

// Function to send SMS to multiple numbers
void send_multi_sms() {
  if (PHONE_1 != "") {
    Serial.print("Sending SMS to Phone 1: ");
    send_sms("Fire detected...! Take action immediately.", PHONE_1);
  }
  if (PHONE_2 != "") {
    Serial.print("Sending SMS to Phone 2: ");
    send_sms("Fire detected...! Take action immediately.", PHONE_2);
  }
  if (PHONE_3 != "") {
    Serial.print("Sending SMS to Phone 3: ");
    send_sms("Fire detected...! Take action immediately.", PHONE_3);
  }
}

// Function to make calls to multiple numbers
void make_multi_call() {
  if (PHONE_1 != "") {
    Serial.print("Making call to Phone 1: ");
    make_call(PHONE_1);
  }
  if (PHONE_2 != "") {
    Serial.print("Making call to Phone 2: ");
    make_call(PHONE_2);
  }
  if (PHONE_3 != "") {
    Serial.print("Making call to Phone 3: ");
    make_call(PHONE_3);
  }
}

// Function to send SMS
void send_sms(String text, String phone) {
  Serial.println("Sending SMS...");
  delay(50);
  sim900A.print("AT+CMGF=1\r");
  delay(1000);
  sim900A.print("AT+CMGS=\"" + phone + "\"\r");
  delay(1000);
  sim900A.print(text);  // SMS body text
  delay(100);
  sim900A.write(0x1A);  // Send Ctrl+Z to send the SMS
  delay(5000);  // Wait for SMS to be sent
}

// Function to make call
void make_call(String phone) {
  Serial.println("Making call...");
  sim900A.println("ATD" + phone + ";");
  delay(20000);  // 20 sec call duration
  sim900A.println("ATH");  // End call
  delay(1000);  // Wait for 1 second
}
>>>>>>> e40ff09d7261b7584b214028d3c9ddab412edc4e
