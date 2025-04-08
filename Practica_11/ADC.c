#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define TEMP_SENSOR_PIN 26  
#define ADC_MAX_VALUE 4096.0f  
#define VOLTAGE_REF 3.3f  

int main() {
    stdio_init_all();  
    adc_init();  
    adc_gpio_init(TEMP_SENSOR_PIN);  
    adc_select_input(0);  

    while (1) {
        uint16_t valor_adc = adc_read();  
        float voltaje = (valor_adc * VOLTAGE_REF) / ADC_MAX_VALUE;  
        float temperatura = voltaje * 100.0f;  

        printf("%.2f,%.2f\n", temperatura, voltaje);  // Enviar datos separados por coma
        fflush(stdout);  // Asegura que los datos se impriman en tiempo real

        sleep_ms(500);  
    }
    return 0;
}