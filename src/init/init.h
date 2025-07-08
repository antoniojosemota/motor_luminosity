// init.h
#ifndef INIT_H
#define INIT_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"
#include "servo.h"
#include "bh1750.h"

extern ssd1306_t display; // estrutura do display

// inicializa os pinos e o barramento I2C
void initDisplayI2C();

// inicializa todo o sistema: stdio, I2C, display e sensor
void initializeSystem(void);

#endif // INIT_H
