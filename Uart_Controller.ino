String id;
String digitLine = "000000000000";
String in;
String inId;
String analog_data;
#define PORT2 2
#define PORT3 3
#define PORT4 4
#define PORT5 5
#define PORT6 6
#define PORT7 7
#define PORT8 8
#define PORT9 9
#define PORT10 10
#define PORT11 11
#define PORT12 12
#define PORT13 13
#define APORT0 A0
#define APORT1 A1
#define APORT2 A2

void setup() {
  Serial.begin(57600);
  id = "0010";
  pinMode(PORT2, OUTPUT);
  pinMode(PORT3, OUTPUT);
  pinMode(PORT4, OUTPUT);
  pinMode(PORT5, OUTPUT);
  pinMode(PORT6, OUTPUT);
  pinMode(PORT7, OUTPUT);
  pinMode(PORT8, OUTPUT);
  pinMode(PORT9, OUTPUT);
  pinMode(PORT10, OUTPUT);
  pinMode(PORT11, OUTPUT);
  pinMode(PORT12, OUTPUT);
  pinMode(PORT13, OUTPUT);
  
  pinMode(APORT0, INPUT);
  pinMode(APORT1, INPUT);
  pinMode(APORT2, INPUT);
}

void loop(){
  Serial.begin(57600);
  if(Serial.available() > 0){
    in = Serial.readString();
    Serial.flush();
    inId = getInId(in);
    if (inId == id) {
      digitLine = getInDigits(in);
      for (int i = 0; i < 12; i++) {
        setPORT(digitLine[i], i + 2);
      }
      set_mess(id + analog_data);
    }else{
      Serial.end();
      offPORT13();
      delay(500);
      onPORT13();
      delay(500);
      offPORT13();
      delay(500);
      Serial.begin(57600);
    }
  }
  analog_data = readAnalogData();
  delay(100);
}
String readAnalogData() {
  return "." + String(analogRead(APORT0), DEC) + "." + String(analogRead(APORT1), DEC) + "." + String(analogRead(APORT2), DEC);
  //return "." + String(analogRead(APORT0)) + "." + String(analogRead(APORT1)) + "." + String(analogRead(APORT2));
}

void set_mess(String out) {
  char *buff = new char[out.length()];

  for (int i = 0; i < out.length(); i++)
    buff[i] = out[i];

  Serial.write(buff, out.length());
}


String getInId(String in) {
  String in_id = "";
  for (int i = 0; i < 4; i++)
    in_id += in[i];

  return in_id;
}
  
String getInDigits(String in) {
  String line = "";
  for (int i = 4; i < 16; i++)
    line += in[i];

  return line;
}


void setPORT(char com, int num) {
  if (num == 2) {
    if (com == '1')
      onPORT2();
    else
      offPORT2();
  } else if (num == 3) {
    if (com == '1')
      onPORT3();
    else
      offPORT3();
  } else if (num == 4) {
    if (com == '1')
      onPORT4();
    else
      offPORT4();
  } else if (num == 5) {
    if (com == '1')
      onPORT5();
    else
      offPORT5();
  } else if (num == 6) {
    if (com == '1')
      onPORT6();
    else
      offPORT6();
  } else if (num == 7) {
    if (com == '1')
      onPORT7();
    else
      offPORT7();
  } else if (num == 8) {
    if (com == '1')
      onPORT8();
    else
      offPORT8();
  } else if (num == 9) {
    if (com == '1')
      onPORT9();
    else
      offPORT9();
  } else if (num == 10) {
    if (com == '1')
      onPORT10();
    else
      offPORT10();
  } else if (num == 11) {
    if (com == '1')
      onPORT11();
    else
      offPORT11();
  } else if (num == 12) {
    if (com == '1')
      onPORT12();
    else
      offPORT12();
  } else if (num == 13) {
    if (com == '1')
      onPORT13();
    else
      offPORT13();
  }
}



void onPORT2() {
  digitalWrite(PORT2, HIGH);
}
void offPORT2() {
  digitalWrite(PORT2, LOW);
}


void onPORT3() {
  digitalWrite(PORT3, HIGH);
}
void offPORT3() {
  digitalWrite(PORT3, LOW);
}


void onPORT4() {
  digitalWrite(PORT4, HIGH);
}
void offPORT4() {
  digitalWrite(PORT4, LOW);
}


void onPORT5() {
  digitalWrite(PORT5, HIGH);
}
void offPORT5() {
  digitalWrite(PORT5, LOW);
}


void onPORT6() {
  digitalWrite(PORT6, HIGH);
}
void offPORT6() {
  digitalWrite(PORT6, LOW);
}


void onPORT7() {
  digitalWrite(PORT7, HIGH);
}
void offPORT7() {
  digitalWrite(PORT7, LOW);
}


void onPORT8() {
  digitalWrite(PORT8, HIGH);
}
void offPORT8() {
  digitalWrite(PORT8, LOW);
}


void onPORT9() {
  digitalWrite(PORT9, HIGH);
}
void offPORT9() {
  digitalWrite(PORT9, LOW);
}


void onPORT10() {
  digitalWrite(PORT10, HIGH);
}
void offPORT10() {
  digitalWrite(PORT10, LOW);
}


void onPORT11() {
  digitalWrite(PORT11, HIGH);
}
void offPORT11() {
  digitalWrite(PORT11, LOW);
}


void onPORT12() {
  digitalWrite(PORT12, HIGH);
}
void offPORT12() {
  digitalWrite(PORT12, LOW);
}


void onPORT13() {
  digitalWrite(PORT13, HIGH);
}
void offPORT13() {
  digitalWrite(PORT13, LOW);
}
