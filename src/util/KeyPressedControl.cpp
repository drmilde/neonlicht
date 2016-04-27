#include "KeyPressedControl.h"

using namespace util;

KeyPressedControl::KeyPressedControl() {
  initKeys();
}

void KeyPressedControl::initKeys() {
  for (int i = 0; i < KEYS_SIZE; i++) {
    KEYS[i] = false;
  }
}

void KeyPressedControl::clear() {
  initKeys();
}

void KeyPressedControl::setKeyPressed(int key) {
  KEYS[key] = true;
} 

void KeyPressedControl::clearKeyPressed(int key) {
  KEYS[key] = false;
} 

bool KeyPressedControl::isKeyPressed(int key) {
  return KEYS[key];
}
