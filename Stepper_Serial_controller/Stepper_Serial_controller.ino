// пины для подключения контактов STEP, DIR
#define PIN_STEP 3
#define PIN_DIR 2
#define PIN_ENABLE 4

// количество шагов на 1 оборот
#define STEP_ROUND 1800

// скорость двигателя
#define SPEED 1


void setup() {
  Serial.begin(9600);
  // режим для STEP и DIR как OUTPUT
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_ENABLE, OUTPUT);

  digitalWrite(PIN_ENABLE, 0);
  // начальные значения
  digitalWrite(PIN_STEP, 0);
  // направление вращения

}

int a = 0;
int DIRECTION = 1;
int ENABLE = 1;

void loop() {
  while (Serial.available()) {
    a = Serial.parseInt();
    Serial.println(a);
    switch (a) {
      case 1:
        for (int i = 0; i < STEP_ROUND; i++) {
          digitalWrite(PIN_STEP, 1);
          delay(SPEED);
          digitalWrite(PIN_STEP, 0);
          delay(SPEED);
        }
        break;

      case 2:
        DIRECTION = inv(DIRECTION);
        Serial.println("DIRECTION:" + String(DIRECTION));
        digitalWrite(PIN_DIR, DIRECTION);
        break;

      case 3:3
        ENABLE = inv(ENABLE);
        Serial.println("ENABLE: " + String(ENABLE));
        digitalWrite(PIN_ENABLE, ENABLE);
    }
  }
}



int inv(int num){
  if (num == 1) return 0;
  return 1;
}
