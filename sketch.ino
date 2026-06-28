#include <LiquidCrystal_I2C.h>
#include <Encoder.h>
#include <EncoderButton.h>
#include "RotaryKeyboard.h"

// --- LCD and encoder setup ---
LiquidCrystal_I2C lcd(0x27, 20, 4);
Encoder encoder(A0, A1);
EncoderButton button(A2);
//unsigned long doubleClickThreshold = 200; // Max time (ms) between clicks
#define DOUBLE_CLICK_DELAY 175
//#define DOUBLE_CLICK_DELAY 200

// --- RotaryKeyboard characters ---
const char kbChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,!?:;+-*/=_@#\b\x1B\n";
RotaryKeyboard rk(lcd, encoder, button, kbChars, 1,2,3,4);
// --- Parameters ---
String P_USERNAME = "";
String P_PASSWORD = "";
String P_TARGET_TEMP = "";
String P_HEAT_TEMP = "";
String P_COOL_TEMP = "";

// --- Menu items ---
const char* menuItems[] = {"Set USERNAME","Set PASSWORD","Set Target Temp","Set Heat Temp","Set Cool Temp","Start Controller"};
const int menuLength = 6;
int menuIndex = 0;
int menuTopIndex = 0;
long lastEncCount = 0;
bool menuActive = false;
// --- Custom right arrow for menu ---
byte rightArrow[8] = {B00000,B11000,B01100,B00110,B11111,B00110,B01100,B11000};

// --- Controller function ---
void startController() {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Controller Started!");
    Serial.println("Controller Started!");
}
// --- RotaryKeyboard callbacks ---
void onSaveUsername(String value){ P_USERNAME=value; menuActive=true; }
void onSavePassword(String value){ P_PASSWORD=value; menuActive=true; }
void onSaveTargetTemp(String value){ P_TARGET_TEMP=value; menuActive=true; }
void onSaveHeatTemp(String value){ P_HEAT_TEMP=value; menuActive=true; }
void onSaveCoolTemp(String value){ P_COOL_TEMP=value; menuActive=true; }
void onCancel(){ lcd.setCursor(0,3); lcd.print("Cancelled"); menuActive=true; }
// --- Draw menu ---
void drawMenu(){
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("Use encoder & Btn");
    for(int row=0; row<3; row++){
        int idx = menuTopIndex+row;
        if(idx>=menuLength) break;
        lcd.setCursor(0,row+1);
        lcd.print("                    ");
        lcd.setCursor(0,row+1);
        lcd.write(idx==menuIndex?byte(0):' ');
        lcd.print(menuItems[idx]);
    }
}
// --- Menu selection ---
void menuSelect(EncoderButton &b){
    if(!menuActive) return;
    menuActive = false;
    switch(menuIndex){
        case 0: rk.start("Set USERNAME:", onSaveUsername, onCancel); break;
        case 1: rk.start("Set PASSWORD:", onSavePassword, onCancel); break;
        case 2: rk.start("Set Target Temp:", onSaveTargetTemp, onCancel); break;
        case 3: rk.start("Set Heat Temp:", onSaveHeatTemp, onCancel); break;
        case 4: rk.start("Set Cool Temp:", onSaveCoolTemp, onCancel); break;
        case 5: startController(); lcd.clear(); break;
    }
}
void setup() {
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();

    rk.begin();
    lcd.createChar(0,rightArrow);

    button.setClickHandler([](EncoderButton &b){
        if(rk.isActive()){
            RotaryKeyboard::handleClick(b);  // send to RK
        } else if(menuActive){
            menuSelect(b);                   // menu item selection
        }
    });
    button.setLongPressHandler([](EncoderButton &b){
        if(rk.isActive()){
            RotaryKeyboard::handleLongPress(b);  // send to RK
        } else if(!menuActive){
            menuActive = true;
            drawMenu();                        // open menu
        }
    });

    button.setDoubleClickHandler([](EncoderButton &b){
        if(rk.isActive()){
            RotaryKeyboard::handleDoubleClick(b);  // send to RK
        }
    });
}
void loop(){
    rk.update();
    button.update();

    if(menuActive && !rk.isActive()){
        long encCount = encoder.read();
        long delta = encCount - lastEncCount;
        if(abs(delta)>=4){
            int step = delta/4;
            menuIndex+=step;
            lastEncCount+=step*4;

            if(menuIndex<0) menuIndex=0;
            if(menuIndex>=menuLength) menuIndex=menuLength-1;
            if(menuIndex<menuTopIndex) menuTopIndex=menuIndex;
            else if(menuIndex>=menuTopIndex+3) menuTopIndex=menuIndex-2;

            drawMenu();
        }
    }
}
