#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_motor 22                        // Defina a GPIO 22
// #define PWM_motor 13                     // para definir o led da BitDogLab
#define PWM_FREQ 50                         // Frequência do PWM em Hz
#define PWM_PERIOD_US (1000000 / PWM_FREQ)  // Período do PWM em microssegundos (20ms)

const uint16_t WRAP_PERIOD = 20000; // valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0f;   // divisor do clock para o PWM

// Função para definir o ângulo do servo
void set_servo_angle(uint slice_num, uint channel, float angle)
{
  // O período de PWM para 50Hz é 20ms (20000us)
  // 0,5ms de pulso corresponde a 0 graus e 2,4ms corresponde a 180 graus
  float pulse_width_us = 500 + (angle / 180.0) * 1900;
  uint16_t level = (pulse_width_us * WRAP_PERIOD) / PWM_PERIOD_US;
  pwm_set_chan_level(slice_num, channel, level);
}

int main()
{
  stdio_init_all();

  gpio_set_function(PWM_motor, GPIO_FUNC_PWM);   // habilitar o pino GPIO como PWM
  uint slice = pwm_gpio_to_slice_num(PWM_motor); // obter o canal PWM da GPIO
  pwm_set_clkdiv(slice, PWM_DIVISER);            // define o divisor de clock do PWM
  pwm_set_wrap(slice, WRAP_PERIOD);              // definir o valor de wrap
  uint channel = pwm_gpio_to_channel(PWM_motor);

  pwm_set_enabled(slice, true); // habilita o pwm no slice correspondente

  while (true)
  {
    set_servo_angle(slice, channel, 180);
    sleep_ms(5000);
    set_servo_angle(slice, channel, 90);
    sleep_ms(5000);
    set_servo_angle(slice, channel, 0);
    sleep_ms(5000);

    for (float angle = 0; angle <= 180; angle += 1)
    {
      set_servo_angle(slice, channel, angle);
      sleep_ms(10);
    }
    for (float angle = 180; angle >= 0; angle -= 1)
    {
      set_servo_angle(slice, channel, angle);
      sleep_ms(10);
    }
    for (float angle = 0; angle <= 180; angle += 1)
    {
      set_servo_angle(slice, channel, angle);
      sleep_ms(10);
    }
  }
}
