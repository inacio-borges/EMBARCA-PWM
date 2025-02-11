#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_motor 22
const uint16_t WRAP_PERIOD = 62500; //valor máximo do contador - WRAP
const float PWM_DIVISER = 40.0; //divisor do clock para o PWM
int carga=0;
uint16_t motor_level = 7500; //nível inicial do pwm (duty cycle)
const uint32_t motor_STEP = 16;

int main() {
  stdio_init_all();
  gpio_set_function(PWM_motor, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM
  uint slice = pwm_gpio_to_slice_num(PWM_motor); //obter o canal PWM da GPIO
  pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM
  pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

  pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
  uint up_down = 1;
  while (true) {
        pwm_set_gpio_level(PWM_motor, motor_level); //definir o ciclo de trabalho (duty cycle) do pwm

        switch(carga)
        {
          case 0 :  
         
          carga++;
          break;
          case 1 :
        
          motor_level= 4594;
          sleep_ms(5000);
          carga++;
          break;
          case 2 :
        
          motor_level= 1563;
          
          carga++;
          break;
          case 3 :
          sleep_ms(5000);
          carga++;
          break;
        }
         if (carga>3)
         {  
          sleep_ms(10);
          if(up_down ) {
            
            motor_level += motor_STEP; // Incrementa o nível do motor

            if (motor_level >= 7500)
                up_down = 0; // Muda direção para diminuir quando atingir o período máximo
          }
          else
          { 
            motor_level -= motor_STEP; // Decrementa o nível do motor
          
            if (motor_level <= motor_STEP)
                up_down = 1; // Muda direção para aumentar quando atingir o mínimo
          }
         }

  }
}