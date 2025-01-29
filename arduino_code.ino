#include <Keypad.h>
#include <string.h>

#define led_pin1 13
#define led_pin2 12
#define buzzer 10

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char password[100];
int i = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  char key = keypad.getKey();

  if (key != NO_KEY && key != '#')
  {
    password[i] = key;
    i++;
  }

  if (key == '#')
  {
    password[i] = '\0';
    if (strcmp(password, "123") == 0)
    {

      Serial.println("Access Granted!");

      int d = 150;

      for (int i = 0; i < 2; i++)
      {
        digitalWrite(buzzer, HIGH);
        digitalWrite(led_pin2, HIGH);
        delay(d);

        digitalWrite(buzzer, LOW);
        digitalWrite(led_pin2, LOW);
        delay(d);

        digitalWrite(buzzer, HIGH);
        digitalWrite(led_pin2, HIGH);
        delay(d);

        digitalWrite(buzzer, LOW);
        digitalWrite(led_pin2, LOW);
      }
    }
    else
    {
      Serial.println("Access Denied!");

      digitalWrite(led_pin1, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(1000);

      digitalWrite(led_pin1, LOW);
      digitalWrite(buzzer, LOW);
      delay(1000);

      digitalWrite(led_pin1, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(1000);

      digitalWrite(buzzer, LOW);
      digitalWrite(led_pin1, LOW);
    }
    i = 0;
  }
}
