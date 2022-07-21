#define BLINKER_WIFI
#define BLINKER_APCONFIG

#include <Blinker.h>
#include "OneButton.h"
#include <Arduino.h>

#include "car.h"

//// 前左轮转动
//void front_left_rotate(int speed) {
//    analogWrite(GPIO_FRONT_LEFT_SPEED, speed);
//}


//Car car;

void setup() {
// write your initialization code here
//    car.forward();
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(14,LOW);


}

void loop() {
    // write your code here
    //    if (car.is_forward()) {
    //        car.forward();
    //    } else if (car.is_backward()) {
    //        car.backward();
    //    } else {
    //        car.stop();
    //    }
    //    休眠10秒
//    delay(10000);
//    car.stop();
//    // 休眠10s
//    delay(10000);
//    car.backward();
}