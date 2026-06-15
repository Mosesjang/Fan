

# Fan
This is my first bare-metal project.
  It's just a basic fan that turns on a pc fan and a led and changes the motor speed when I push a button using a 3dModel I found online.
I'm on a journey of becoming a good embedded system engineer by building projects. 
This is an experiment to see if this learning technique works. 

**Learning Method: Helps you learn faster**
learning by starting with your goal and work backward.<br>
**For example:** If you want to learn electronics, don't start by learning math then move on to physics and then chemistry before learning electronics.<br>
That would be ridiculously slow. so start by building a circuit you want to make and then learning the things that are stopping your from making your goal Circuit.and then repetition is the key to master. <br>
I learn this from a video titled "How To Master Any Skill Fast (Give Yourself 2 Weeks)" by dan koe

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

## ⚠️ Known Issues
1. Fan airflow is relatively weaker compared to a traditional blade fan
2. 3D printed parts do not align perfectly — some DIY adjustment required during assembly

Why
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
<img width="1366" height="1024" alt="KakaoTalk_20260614_161949553" src="https://github.com/user-attachments/assets/842fd672-a7ca-46aa-992e-a1249894b0b7" />

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
