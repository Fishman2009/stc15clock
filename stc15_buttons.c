#include "stc15_buttons.h"

#include <8052.h>

#include "ds1302.h"

#define HOUR_BTN 0
#define HOUR_PIN P3_1
#define MINUTE_BTN 1
#define MINUTE_PIN P3_0

unsigned char buttons[2] = {0, 0};

void button_check(unsigned char index, unsigned char value, void (*action)()) {
  if ( buttons[index] != value ) {
    if (value) (*action)();
    buttons[index] = value;
  }
}

void read_buttons() {
  button_check(HOUR_BTN, HOUR_PIN, &ds1302_increase_hour);
  button_check(MINUTE_BTN, MINUTE_PIN, &ds1302_increase_minute);
}

