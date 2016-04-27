#ifndef _KEY_PRESSED_CONTROL_h_
#define _KEY_PRESSED_CONTROL_h_

namespace util {

/**
 * KeyPressedControl ist eine Hilfsklasse zur Zwischenspeicherung der
 * gedrückten Tasten (keys). Zielsetzung ist es, festzustellen, ob 
 * zu jedem Tastendruck (**note on**)  ein korrespondierender
 * Tastenhub (**note off**) registriert wurde.
 *
 * - setKeyPressed(int key) setzt den Wert für die Taste key auf true.
 * - isKeyPressed(int key) liefert den Wert die die Taste key.
 * - clearKeyPressed(int key) setzt den Wert für die Taste key zurück.
 * - clear() setzt alle Werte zurück.
 *
 * @author jtm
 * @since 04-2016
 * @version 1.0
 **/

  class KeyPressedControl {
  public:
    KeyPressedControl();
    void setKeyPressed(int key);
    void clearKeyPressed(int key);
    bool isKeyPressed(int key);
    void clear();

  private:
    void initKeys();

    static const int KEYS_SIZE = 128;
    bool KEYS[KEYS_SIZE];
  };
}

#endif
