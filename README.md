# Rotary Keyboard

![License: MIT](https://img.shields.io/badge/Code-MIT-green.svg)
![Docs: CC BY 4.0](https://img.shields.io/badge/Docs-CC%20BY%204.0-blue.svg)
![Arduino](https://img.shields.io/badge/Arduino-Nano-00979D.svg)
![Wokwi](https://img.shields.io/badge/Simulator-Wokwi-purple.svg)

A Wokwi/Arduino rotary encoder keyboard and menu project using an Arduino Nano, a 20x4 I2C LCD, and a KY-040 style rotary encoder.

![Rotary Keyboard wiring diagram](images/wiring-diagram.png)

## Wokwi Simulation

Original Wokwi project:

https://wokwi.com/projects/441642530815823873

## Features

- Rotary encoder driven LCD menu
- Encoder push-button selection
- Long press menu activation
- Double-click support routed through `EncoderButton`
- 20x4 I2C LCD display
- Simple editable fields for username, password, and temperature settings
- Arduino Nano friendly wiring

## Hardware

| Part | Quantity | Notes |
| --- | ---: | --- |
| Arduino Nano | 1 | Main controller |
| 20x4 I2C LCD | 1 | I2C address currently set to `0x27` |
| KY-040 Rotary Encoder | 1 | CLK, DT, SW, VCC, GND |
| Jumper wires | As needed | Breadboard/prototype wiring |

## Required Libraries

Install these from the Arduino Library Manager or include them in Wokwi `libraries.txt`:

| Library | Purpose |
| --- | --- |
| `Encoder` | Reads the rotary encoder position |
| `LiquidCrystal I2C` / `LiquidCrystal_I2C` | Drives the I2C LCD display |
| `EncoderButton` | Handles click, long press, and double-click events |

The included `libraries.txt` contains:

```text
LiquidCrystal_I2C
Encoder
EncoderButton
```

## Current Pinout

| Arduino Nano Pin | Connected Device | Code Reference |
| --- | --- | --- |
| `A0` | Rotary encoder signal | `Encoder encoder(A0, A1);` |
| `A1` | Rotary encoder signal | `Encoder encoder(A0, A1);` |
| `A2` | Rotary encoder push button | `EncoderButton button(A2);` |
| `A4` | LCD SDA | Arduino Nano I2C default |
| `A5` | LCD SCL | Arduino Nano I2C default |
| `5V` | LCD/encoder VCC | Power |
| `GND` | LCD/encoder GND | Ground |

## Installation

1. Clone the repository.
2. Open `sketch.ino` in the Arduino IDE or import the project into Wokwi.
3. Install the required libraries listed above.
4. Select **Arduino Nano** as the board.
5. Compile and upload.

## Project Status

The extracted project currently includes the visible `sketch.ino` and library list. The Wokwi page showed additional tabs named `diagram.json`, `RotaryKeyboard.cpp`, and `RotaryKeyboard.h`; add those source files from Wokwi when available so the sketch can compile as a complete standalone project.

## Documentation

- [Wiring Guide](docs/wiring.md)
- [Pinout](docs/pinout.md)
- [Libraries](docs/libraries.md)
- [Menu System](docs/menu-system.md)
- [Customization](docs/customization.md)

## License

- Source code is licensed under the [MIT License](LICENSE).
- Documentation and images are licensed under [Creative Commons Attribution 4.0 International](LICENSE-DOCS).

Copyright (c) 2026 Larry Brendel.
