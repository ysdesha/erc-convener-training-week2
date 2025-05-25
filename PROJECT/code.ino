#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Paddle
const int paddleHeight = 16;
const int paddleWidth = 3;
int paddle1Y = 0;
int paddle2Y = 0;
const int paddleSpeed = 3;

// Ball
int ballX = SCREEN_WIDTH / 2;
int ballY = SCREEN_HEIGHT / 2;
int ballSpeedX = 3;
int ballSpeedY = 2;

// Button pins
const int P1_UP = 4;
const int P1_DOWN = 5;
const int P2_UP = 2;
const int P2_DOWN = 3;

// Buzzer
const int buzzerPin = 8;

// Score
int score1 = 0;
int score2 = 0;

bool gameStarted = false;

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);

  pinMode(P1_UP, INPUT_PULLUP);
  pinMode(P1_DOWN, INPUT_PULLUP);
  pinMode(P2_UP, INPUT_PULLUP);
  pinMode(P2_DOWN, INPUT_PULLUP);

  playStartupSound();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED failed"));
    while (1);
  }

  display.clearDisplay();
  display.display();

  startCountdown(); // Show 3-2-1-GO
  gameStarted = true;
}


void loop() {
  // Read button inputs
  if (digitalRead(P1_UP) == LOW) paddle1Y -= paddleSpeed;
  if (digitalRead(P1_DOWN) == LOW) paddle1Y += paddleSpeed;
  if (digitalRead(P2_UP) == LOW) paddle2Y -= paddleSpeed;
  if (digitalRead(P2_DOWN) == LOW) paddle2Y += paddleSpeed;

  // Clamp paddle positions
  paddle1Y = constrain(paddle1Y, 0, SCREEN_HEIGHT - paddleHeight);
  paddle2Y = constrain(paddle2Y, 0, SCREEN_HEIGHT - paddleHeight);

  // Move ball
  ballX += ballSpeedX;
  ballY += ballSpeedY;

  // Wall bounce
  if (ballY <= 0 || ballY >= SCREEN_HEIGHT - 1) {
    ballSpeedY *= -1;
    tone(buzzerPin, 1200, 40);
  }

  // Paddle 1 hit
  if (ballX <= paddleWidth + 2 && ballY >= paddle1Y && ballY <= paddle1Y + paddleHeight) {
    ballSpeedX *= -1;
    ballX = paddleWidth + 3;
    tone(buzzerPin, 1000, 50);
  }

  // Paddle 2 hit
  if (ballX >= SCREEN_WIDTH - paddleWidth - 2 &&
      ballY >= paddle2Y && ballY <= paddle2Y + paddleHeight) {
    ballSpeedX *= -1;
    ballX = SCREEN_WIDTH - paddleWidth - 3;
    tone(buzzerPin, 1000, 50);
  }

  // Score
  if (ballX < 0) {
    score2++;
    tone(buzzerPin, 300, 300);
    resetBall();
  } else if (ballX > SCREEN_WIDTH) {
    score1++;
    tone(buzzerPin, 300, 300);
    resetBall();
  }

  // Draw
  display.clearDisplay();
  display.fillRect(0, paddle1Y, paddleWidth, paddleHeight, WHITE);
  display.fillRect(SCREEN_WIDTH - paddleWidth, paddle2Y, paddleWidth, paddleHeight, WHITE);
  display.fillRect(ballX, ballY, 2, 2, WHITE);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30, 0);
  display.print("P1:");
  display.print(score1);
  display.setCursor(80, 0);
  display.print("P2:");
  display.print(score2);

  display.display();
  delay(20);
}

void resetBall() {
  // Reset ball position
  ballX = SCREEN_WIDTH / 2;
  ballY = SCREEN_HEIGHT / 2;
  ballSpeedX = 0;
  ballSpeedY = 0;

  // Countdown before next serve
  startCountdown();
}
void startCountdown() {
  for (int i = 3; i >= 1; i--) {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor((SCREEN_WIDTH - 18) / 2, (SCREEN_HEIGHT - 24) / 2);
    display.print(i);
    display.display();
    tone(buzzerPin, 1000 + i * 100, 200);
    delay(600);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor((SCREEN_WIDTH - 36) / 2, (SCREEN_HEIGHT - 16) / 2);
  display.print("GO!");
  display.display();
  tone(buzzerPin, 1600, 200);
  delay(400);
  noTone(buzzerPin);

  // Launch ball
  ballX = SCREEN_WIDTH / 2;
  ballY = SCREEN_HEIGHT / 2;
  ballSpeedX = 3;
  ballSpeedY = 2;
}




void playStartupSound() {
  tone(buzzerPin, 800, 100);
  delay(120);
  tone(buzzerPin, 1000, 100);
  delay(120);
  tone(buzzerPin, 1200, 100);
  delay(120);
  noTone(buzzerPin);
}
