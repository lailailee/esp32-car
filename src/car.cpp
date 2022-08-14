//
// Created by lailailee on 2022/6/29.
//
#include <Arduino.h>
#include "car.h"


void Car::init() {
    pinMode(left_speed_gpio, OUTPUT);
    pinMode(left_forward_gpio, OUTPUT);
    pinMode(left_backward_gpio, OUTPUT);
    pinMode(right_speed_gpio, OUTPUT);
    pinMode(right_forward_gpio, OUTPUT);
    pinMode(right_backward_gpio, OUTPUT);

    execute_speed();
}

void Car::forward() {
//    car_state = 1;
    digitalWrite(left_forward_gpio, HIGH);
    digitalWrite(left_backward_gpio, LOW);
    digitalWrite(right_forward_gpio, HIGH);
    digitalWrite(right_backward_gpio, LOW);
}

void Car::backward() {
//    car_state = 2;
    digitalWrite(left_forward_gpio, LOW);
    digitalWrite(left_backward_gpio, HIGH);
    digitalWrite(right_forward_gpio, LOW);
    digitalWrite(right_backward_gpio, HIGH);
}

void Car::stop() {
//    car_state = 0;
    digitalWrite(left_forward_gpio, LOW);
    digitalWrite(left_backward_gpio, LOW);
    digitalWrite(right_forward_gpio, LOW);
    digitalWrite(right_backward_gpio, LOW);
}

void Car::turn_left() {
    digitalWrite(left_forward_gpio, LOW);
    digitalWrite(left_backward_gpio, LOW);
    digitalWrite(right_forward_gpio, HIGH);
    digitalWrite(right_backward_gpio, LOW);
}

void Car::turn_right() {
    digitalWrite(left_forward_gpio, HIGH);
    digitalWrite(left_backward_gpio, LOW);
    digitalWrite(right_forward_gpio, LOW);
    digitalWrite(right_backward_gpio, LOW);
}

void Car::turn_left_back() {
    digitalWrite(left_forward_gpio, LOW);
    digitalWrite(left_backward_gpio, LOW);
    digitalWrite(right_forward_gpio, LOW);
    digitalWrite(right_backward_gpio, HIGH);
}

void Car::turn_right_back() {
    digitalWrite(left_forward_gpio, LOW);
    digitalWrite(left_backward_gpio, HIGH);
    digitalWrite(right_forward_gpio, LOW);
    digitalWrite(right_backward_gpio, LOW);
}
void Car::execute_speed() {
    analogWrite(left_speed_gpio, left_speed);
    analogWrite(right_speed_gpio, right_speed);
}
void Car::execute_speed(int speed) {
    left_speed= speed;
    right_speed = speed;
    analogWrite(left_speed_gpio, left_speed);
    analogWrite(right_speed_gpio, right_speed);
}

