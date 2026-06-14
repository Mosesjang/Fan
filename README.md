<img width="1366" height="1024" alt="KakaoTalk_20260614_161949553" src="https://github.com/user-attachments/assets/842fd672-a7ca-46aa-992e-a1249894b0b7" />
<img width="1366" height="1024" alt="KakaoTalk_20260614_161949553" src="https://github.com/user-attachments/assets/72398ee0-10ed-4294-80f9-91bd99d7ffe8" />
# Fan
This is my first bare-metal project.
  It's just a basic fan that turns on a pc fan and a led and changes the motor speed  when I push a button.
I'm on a journey of becoming a good embedded system engineer by building project.

## Code
Two versions of this project exist:

**Bare-metal STM32 (learning version)**
- Written in pure C, direct register manipulation
- No HAL, no libraries
- Used for learning embedded fundamentals
- See `/stm32_baremetal` folder

**ESP32 Arduino (final product)**
- Ported to ESP32 for the physical product
- Arduino framework for faster deployment
- See `/esp32_arduino` folder

# Fan 🌀

A bare-metal STM32F401RE fan controller with 3 speed settings, 
RGB LED indicators and PWM motor control.

## Demo
[video here]

## Features
- 3 speed settings + off
- RGB LED shows current speed
- Single button cycling
- PWM motor control via MOSFET

## Components
| Component | Value |
|-----------|-------|
| MCU | STM32F401RE Nucleo |
| MOSFET | IRLZ44N |
| Fan | 12V DC PC Fan |
| PSU | 12V AC/DC |
| Flyback Diode | 1N5819 |

## Wiring
[schematic photo here]

## Problems & Solutions
### Problem 1: MOSFET not switching at 3.3V
- IRFZ44N needs 4V+ on gate
- Solution: switched to IRLZ44N (logic level)

### Problem 2: PWM frequency too high
- 25kHz prevented proper switching
- Solution: dropped to 1kHz

## What I Learned
- Bare metal STM32 register programming
- PWM, GPIO, UART, Interrupts
- MOSFET gate voltage requirements
