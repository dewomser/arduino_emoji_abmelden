#include <Keyboard.h>

const int emojiPin = 2;   // Taster für Emojis (Meta + .)
const int logoutPin = 3;  // Taster für Abmelden (Meta + L)

bool lastEmojiState = HIGH;
bool lastLogoutState = HIGH;

void setup() {
  pinMode(emojiPin, INPUT_PULLUP);
  pinMode(logoutPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // --- LOGIK FÜR EMOJI (PIN 2) ---
  int currentEmojiState = digitalRead(emojiPin);
  if (currentEmojiState == LOW && lastEmojiState == HIGH) {
    Keyboard.press(KEY_LEFT_GUI); 
    delay(100); 
    Keyboard.press('.');          // Punkt für Emojis
    delay(100);
    Keyboard.releaseAll();
    delay(500); // Entprellen
  }
  lastEmojiState = currentEmojiState;

  // --- LOGIK FÜR ABMELDEN (PIN 3) ---
  int currentLogoutState = digitalRead(logoutPin);
  if (currentLogoutState == LOW && lastLogoutState == HIGH) {
    Keyboard.press(KEY_LEFT_GUI); 
    delay(100); 
    Keyboard.press('l');          // Kleines 'l' für Meta+L
    delay(100);
    Keyboard.releaseAll();
    delay(500); // Entprellen
  }
  lastLogoutState = currentLogoutState;
}
