#include "MidiUtil.h"

float util::MidiUtil::midi2frequency(int key) {
    return 440.0 * pow(2.0,(key - 69)/12.0);
}
