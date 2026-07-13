#ifndef NESTED_ITEM_MENU_H
#define NESTED_ITEM_MENU_H

#include <Arduino.h>
#include <Encoder.h>
#include <LiquidCrystal_I2C.h>

struct NestedMenuItem {
    const char* label;
    const NestedMenuItem* children;
    uint8_t childCount;
    void (*action)();
};

class NestedItemMenu {
public:
    NestedItemMenu(LiquidCrystal_I2C& lcd,
                   Encoder& encoder,
                   uint8_t columns = 20,
                   uint8_t rows = 4,
                   uint8_t arrowCharIndex = 0,
                   uint8_t encoderCountsPerStep = 4,
                   uint8_t maxDepth = 6);

    void begin(const byte arrowGlyph[8] = nullptr);
    void open(const char* title, const NestedMenuItem* items, uint8_t itemCount);
    void close();
    void pause();
    void resume();
    void update();
    void select();
    void back();
    void redraw();

    bool isActive() const;
    bool isPaused() const;
    uint8_t selectedIndex() const;
    const NestedMenuItem* selectedItem() const;

private:
    struct MenuLevel {
        const char* title;
        const NestedMenuItem* items;
        uint8_t itemCount;
        uint8_t selectedIndex;
        uint8_t topIndex;
    };

    LiquidCrystal_I2C& _lcd;
    Encoder& _encoder;
    uint8_t _columns;
    uint8_t _rows;
    uint8_t _visibleRows;
    uint8_t _arrowCharIndex;
    uint8_t _countsPerStep;
    uint8_t _maxDepth;
    MenuLevel* _levels;
    uint8_t _depth;
    long _lastEncoderCount;
    bool _active;
    bool _paused;

    MenuLevel& currentLevel();
    const MenuLevel& currentLevel() const;
    void moveSelection(int step);
    void pushLevel(const NestedMenuItem& item);
    void printPadded(const char* text, uint8_t width);
};

#endif
