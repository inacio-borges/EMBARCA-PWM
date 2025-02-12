# Controle de Ângulo de Servomotor com Raspberry Pi Pico e PWM

Aluno: Inacio Oliveira Borges

link para o video da execução do projeto: [Projeto em execucao](https://youtu.be/uKKFQBjEgQM)

## Descrição do Projeto

Este projeto demonstra como controlar o ângulo de um servomotor usando o módulo PWM presente no microcontrolador RP2040, utilizando a GPIO 22 com frequência de PWM de aproximadamente 50Hz.

## Requisitos

1. Definir a frequência de PWM para aproximadamente 50Hz (período de 20ms) utilizando a GPIO 22.
2. Ajustar o ciclo ativo do módulo PWM para 2.400µs (microssegundos) para posicionar a flange do servomotor a aproximadamente 180 graus e aguardar 5 segundos.
3. Ajustar o ciclo ativo do módulo PWM para 1.470µs (microssegundos) para posicionar a flange do servomotor a aproximadamente 90 graus e aguardar 5 segundos.
4. Ajustar o ciclo ativo do módulo PWM para 500µs (microssegundos) para posicionar a flange do servomotor a aproximadamente 0 graus e aguardar 5 segundos. 
5. Criar uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus, com movimentação suave e incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms.
6. Realizar um experimento com o código utilizando o LED RGB na GPIO 12 com a Ferramenta Educacional BitDogLab e observar o comportamento da iluminação do LED.

## Configuração

### Hardware
- Microcontrolador: RP2040
- Pino PWM: GPIO 22
- Frequência PWM: 50Hz (Período de 20ms)
- Servomotor

### Software
- SDK: Pico SDK
- Linguagem de Programação: C