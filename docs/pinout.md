# Pinout

| Arduino Nano Pin | Function | Code |
| --- | --- | --- |
| A0 | Rotary encoder signal 1 | `Encoder encoder(A0, A1);` |
| A1 | Rotary encoder signal 2 | `Encoder encoder(A0, A1);` |
| A2 | Rotary encoder push button | `EncoderButton button(A2);` |
| A4 | LCD SDA | Nano I2C default |
| A5 | LCD SCL | Nano I2C default |
| 5V | Power | LCD and encoder VCC |
| GND | Ground | Shared ground |

## LCD Address

The sketch currently uses:

```cpp
LiquidCrystal_I2C lcd(0x27, 20, 4);
```

If your LCD does not display text, scan for the I2C address or try `0x3F`.
