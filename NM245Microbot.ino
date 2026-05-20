#include <TM1637Display.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define CLK 18
#define DIO 19
#define TOUCH_PIN 4
#define SOUND_PIN 34

// RGB LED pins
#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27

// DHT11
#define DHTPIN 23
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

TM1637Display display(CLK, DIO);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long lastActivity = 0;
bool sleeping = false;

// DFPlayer
SoftwareSerial mySoftwareSerial(16, 17);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// Button for music
#define BUTTON_PIN 32
bool isPlaying = false;
unsigned long startTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);
  display.setBrightness(0x0f);
  display.showNumberDec(8888);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 not found!");
    while (1);
  }
  oled.clearDisplay();
  oled.display();

  dht.begin();

  // DFPlayer init
  mySoftwareSerial.begin(9600);
  delay(1000);  // wait for DFPlayer to wake up
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("DFPlayer not found!");
    while (true);
  }
  myDFPlayer.volume(25);  // sound volume 0-30

  // Startup sounds
  myDFPlayer.play(2);  
  delay(2000);
  myDFPlayer.play(3);  
}

// --- RGB Control ---
void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, 255 - r);
  analogWrite(GREEN_PIN, 255 - g);
  analogWrite(BLUE_PIN, 255 - b);
}

#pragma region Oled_Control
// --- OLED ---
void drawEyes(int xOffset, int yOffset, int size) {
  oled.clearDisplay();
  oled.fillCircle(40 + xOffset, 32 + yOffset, size, SSD1306_WHITE);
  oled.fillCircle(88 + xOffset, 32 + yOffset, size, SSD1306_WHITE);
  oled.display();
}

void drawHeartEyes(int xOffset, int yOffset, int size) {
  oled.clearDisplay();
  // Left heart
  oled.fillCircle(40 + xOffset - size / 2, 32 + yOffset, size / 2, SSD1306_WHITE);
  oled.fillCircle(40 + xOffset + size / 2, 32 + yOffset, size / 2, SSD1306_WHITE);
  oled.fillTriangle(40 + xOffset - size, 32 + yOffset,
                    40 + xOffset + size, 32 + yOffset,
                    40 + xOffset, 32 + yOffset + size, SSD1306_WHITE);

  // Right heart
  oled.fillCircle(88 + xOffset - size / 2, 32 + yOffset, size / 2, SSD1306_WHITE);
  oled.fillCircle(88 + xOffset + size / 2, 32 + yOffset, size / 2, SSD1306_WHITE);
  oled.fillTriangle(88 + xOffset - size, 32 + yOffset,
                    88 + xOffset + size, 32 + yOffset,
                    88 + xOffset, 32 + yOffset + size, SSD1306_WHITE);

  oled.display();
}
#pragma endregion

void loop() {
  int touchState = digitalRead(TOUCH_PIN);
  int soundValue = analogRead(SOUND_PIN);
  float t = dht.readTemperature();

  // --- Button for music ---
  if (!isPlaying && digitalRead(BUTTON_PIN) == LOW) {
    myDFPlayer.play(5);  // 0005.mp3 refren
    startTime = millis();
    isPlaying = true;
  }

  if (isPlaying) {
    unsigned long elapsed = millis() - startTime;

    // OLED "dance" animation 
    int phase = (elapsed / 250) % 4;
    if (phase == 0) drawEyes(-4, 0, 14);
    if (phase == 1) drawEyes(4, 0, 14);
    if (phase == 2) drawEyes(0, -4, 14);
    if (phase == 3) drawEyes(0, 4, 14);

    // Random change color
    int r = random(0, 255);
    int g = random(0, 255);
    int b = random(0, 255);
    setColor(r, g, b);

    // after 10 seconds finish
    if (elapsed > 10000) {
      isPlaying = false;
      setColor(0, 128, 255);  // idle color
      drawEyes(0, 0, 12);     // normal eyes
    }
    return; 
  }

  // --- Touch ---
  if (touchState == HIGH) {
    uint8_t LOUE[] = {
      0b00111000,              // L
      display.encodeDigit(0),  // 0
      0b00111110,              // U
      0b01111001               // E
    };
    display.setSegments(LOUE);

    int phase = (millis() / 300) % 4;
    if (phase == 0) drawHeartEyes(0, 0, 12);
    if (phase == 1) drawHeartEyes(-4, 0, 12);
    if (phase == 2) drawHeartEyes(4, 0, 12);
    if (phase == 3) drawHeartEyes(0, -4, 12);

    setColor(255, 0, 128);
    lastActivity = millis();
    sleeping = false;
  } else if (soundValue > 500) {
    // crazy face
    oled.clearDisplay();
    oled.fillCircle(40, 32, 20, SSD1306_WHITE);
    oled.fillCircle(88, 32, 20, SSD1306_WHITE);
    oled.display();
    setColor(255, 255, 0);
    myDFPlayer.play(1);  
    lastActivity = millis();
    sleeping = false;
  } else if (!isnan(t)) {
    if (t > 28) {
      // boring eyes
      oled.clearDisplay();
      oled.drawLine(34, 32, 46, 32, SSD1306_WHITE);
      oled.drawLine(82, 32, 94, 32, SSD1306_WHITE);
      oled.display();
      setColor(255, 100, 0);
    } else if (t < 18) {
      // cold eyes
      oled.clearDisplay();
      oled.fillCircle(40, 32, 4, SSD1306_WHITE);
      oled.fillCircle(88, 32, 4, SSD1306_WHITE);
      oled.display();
      setColor(0, 0, 255);
    } else {
      // idle anim
      if (millis() - lastActivity > 15000 && !sleeping) {
        for (int i = 0; i < 6; i++) {
          oled.clearDisplay();
          oled.fillRect(40 - 10, 32, 20, 4, SSD1306_WHITE);
          oled.fillRect(88 - 10, 32, 20, 4, SSD1306_WHITE);
          oled.display();
          delay(120);
          drawEyes(0, 0, 12);
          delay(120);
        }
        myDFPlayer.play(4); 
        oled.clearDisplay();
        oled.drawLine(30, 32, 50, 32, SSD1306_WHITE);
        oled.drawLine(78, 32, 98, 32, SSD1306_WHITE);
        oled.display();
        setColor(255, 0, 0);
        sleeping = true;
      } else if (!sleeping) {
        int phase = (millis() / 500) % 8;
        if (phase == 0) drawEyes(0, 0, 12);
        if (phase == 1) drawEyes(-4, 0, 12);
        if (phase == 2) drawEyes(4, 0, 12);
        if (phase == 3) drawEyes(0, -4, 12);
        if (phase == 4) drawEyes(0, 4, 12);
        if (phase == 5) {
          oled.clearDisplay();
          oled.fillRect(40 - 10, 32, 20, 4, SSD1306_WHITE);
          oled.fillRect(88 - 10, 32, 20, 4, SSD1306_WHITE);
          oled.display();
        }
        if (phase == 6) drawEyes(-2, -2, 12);
        if (phase == 7) drawEyes(2, 2, 12);

        setColor(0, 128, 255);
      }
    }
    display.showNumberDec(8888);
  }
  delay(100);
}