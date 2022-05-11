#ifndef LED_H_
#define LED_H_

#include "main.h"

typedef union led_typedef {
    u16 reg;
    struct {
        u16 LOWER_LEFT_FRONT    :1;     // LED Lower Left Front
        u16 LOWER_LEFT_BACK     :1;     // LED Lower Left Back
        u16 LOWER_FRONT_LEFT    :1;     // LED Lower Front Left
        u16 LOWER_FRONT_RIGHT   :1;     // LED Lower Front Right
        u16 LOWER_BACK_LEFT     :1;     // LED Lower Back Left
        u16 LOWER_BACK_RIGHT    :1;     // LED Lower Back Right
        u16 LOWER_RIGHT_FRONT   :1;     // LED Lower Right Front
        u16 LOWER_RIGHT_BACK    :1;     // LED Lower Right Back
        u16 MIDDLE_LEFT         :1;     // LED Middle Left
        u16 MIDDLE_FRONT        :1;     // LED Middle Front
        u16 MIDDLE_BACK         :1;     // LED Middle Back
        u16 MIDDLE_RIGHT        :1;     // LED Middle Right
        u16 UPPER_LEFT          :1;     // LED Upper Left
        u16 UPPER_FRONT         :1;     // LED Upper Left
        u16 UPPER_BACK          :1;     // LED Upper Left
        u16 UPPER_RIGHT         :1;     // LED Upper Left
    } fields;
} LED_TypeDef;

void led_setup();
void led_set(LED_TypeDef leds);

#endif /* LED_H_ */