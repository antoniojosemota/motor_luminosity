#include <stdio.h>
#include "pico/stdlib.h"
#include "ssd1306.h"
#include "init.h"
#include "servo.h"
#include "bh1750.h"

float lux;

void txt_display(const char *txt)
{
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, 0, 0, 1, txt);
    ssd1306_show(&display);
}

int main()
{
    initializeSystem();
    initDisplayI2C();


    while (true)
    {
        bh1750_read_lux(i2c0, &lux);
        printf("Lux: %.2f\n", lux);
        char bufferread[50];
        snprintf(bufferread, sizeof(bufferread), "Lux: %.2f", lux);

        if(lux > 10){
            int angle = (int)(lux + 10); // Convertendo lux para um ângulo proporcional
            servo_set_angle(angle);
            sleep_ms(100);
            char buffer[50];
            snprintf(buffer, sizeof(buffer), "Angulo: %d", angle);
            //txt_display(buffer);
            txt_display(bufferread);    
            sleep_ms(100);
        }  
        else {
            servo_set_angle(0); // Se lux for menor que 10, posiciona o servo em 0 graus
            txt_display("Lux muito baixo");
        }
    }
    
    
}
