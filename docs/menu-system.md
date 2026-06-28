# Menu System

The sketch provides a simple LCD menu controlled by a rotary encoder.

## Controls

| Action | Behavior |
| --- | --- |
| Rotate encoder | Move through menu items or characters |
| Click button | Select menu item or character |
| Long press | Open the menu when not editing |
| Double click | Routed to `RotaryKeyboard::handleDoubleClick()` while editing |

## Menu Items

Current menu items:

- Set USERNAME
- Set PASSWORD
- Set Target Temp
- Set Heat Temp
- Set Cool Temp
- Start Controller

The menu is defined in `sketch.ino`.
