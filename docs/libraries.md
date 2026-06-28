# Required Libraries

Rotary Keyboard uses these Arduino libraries:

| Library | Used For |
| --- | --- |
| `Encoder` | Reading rotary encoder movement |
| `LiquidCrystal I2C` / `LiquidCrystal_I2C` | Controlling the 20x4 I2C LCD |
| `EncoderButton` | Handling click, long press, and double-click input |

## Arduino IDE Installation

1. Open **Sketch > Include Library > Manage Libraries...**
2. Search for and install:
   - `Encoder`
   - `LiquidCrystal I2C`
   - `EncoderButton`
3. Restart the Arduino IDE if needed.

## Wokwi

The project includes `libraries.txt`:

```text
LiquidCrystal_I2C
Encoder
EncoderButton
```
