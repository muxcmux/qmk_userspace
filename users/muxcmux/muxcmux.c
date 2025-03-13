#include "muxcmux.h"

bool handle_macros(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case M_LOGIN:
                SEND_STRING_DELAY(SECRET_LOGIN, 1);
                break;
        }
    }
    return true;
}
