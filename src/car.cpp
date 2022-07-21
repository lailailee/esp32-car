//
// Created by lailailee on 2022/6/29.
//
#include <Arduino.h>
#include "car.h"

//前左轮
//IN1 13
//IN2 12
//ENA 14
//前右轮
//IN3 27
//IN4 26
//ENB 25
//后左轮
//IN1 33
//IN2 32
//ENA 35
//后右轮
//IN3 34
//IN4 39
//ENB 36

//_forward 前进
void Car::_forward(byte *FORWARD, byte *BACKWARD, int GPIO_FORWARD, int GPIO_BACKWARD) {
    *FORWARD = HIGH;
    *BACKWARD = LOW;
    //打印输出
    Serial.println("forward");
    Serial.println(GPIO_FORWARD + "HIGH");
    Serial.println(GPIO_BACKWARD + "LOW");
    digitalWrite(GPIO_FORWARD, *FORWARD);
    digitalWrite(GPIO_BACKWARD, *BACKWARD);
}

//_backward 后退
void Car::_backward(byte *FORWARD, byte *BACKWARD, int GPIO_FORWARD, int GPIO_BACKWARD) {
    *FORWARD = LOW;
    *BACKWARD = HIGH;
    digitalWrite(GPIO_FORWARD, *FORWARD);
    digitalWrite(GPIO_BACKWARD, *BACKWARD);
}

//stop 停止
void Car::_stop(byte *FORWARD, byte *BACKWARD, int GPIO_FORWARD, int GPIO_BACKWARD) {
    *FORWARD = LOW;
    *BACKWARD = LOW;
    digitalWrite(GPIO_FORWARD, *FORWARD);
    digitalWrite(GPIO_BACKWARD, *BACKWARD);
}

// 前左轮前进
void Car::front_left_forward() {
    _forward(&_FRONT_LEFT_FORWARD, &_FRONT_LEFT_BACKWARD, _GPIO_FRONT_LEFT_FORWARD, _GPIO_FRONT_LEFT_BACKWARD);
}

// 前左轮后退
void Car::front_left_backward() {
    _backward(&_FRONT_LEFT_FORWARD, &_FRONT_LEFT_BACKWARD, _GPIO_FRONT_LEFT_FORWARD, _GPIO_FRONT_LEFT_BACKWARD);
}

// 前左轮停止
void Car::front_left_stop() {
    _stop(&_FRONT_LEFT_FORWARD, &_FRONT_LEFT_BACKWARD, _GPIO_FRONT_LEFT_FORWARD, _GPIO_FRONT_LEFT_BACKWARD);
}

// 前右轮前进
void Car::front_right_forward() {
    _forward(&_FRONT_RIGHT_FORWARD, &_FRONT_RIGHT_BACKWARD, _GPIO_FRONT_RIGHT_FORWARD, _GPIO_FRONT_RIGHT_BACKWARD);
}

// 前右轮后退
void Car::front_right_backward() {
    _backward(&_FRONT_RIGHT_FORWARD, &_FRONT_RIGHT_BACKWARD, _GPIO_FRONT_RIGHT_FORWARD, _GPIO_FRONT_RIGHT_BACKWARD);
}

// 前右轮停止
void Car::front_right_stop() {
    _stop(&_FRONT_RIGHT_FORWARD, &_FRONT_RIGHT_BACKWARD, _GPIO_FRONT_RIGHT_FORWARD, _GPIO_FRONT_RIGHT_BACKWARD);
}

// 后左轮前进
void Car::back_left_forward() {
    _forward(&_BACK_LEFT_FORWARD, &_BACK_LEFT_BACKWARD, _GPIO_BACK_LEFT_FORWARD, _GPIO_BACK_LEFT_BACKWARD);
}

// 后左轮后退
void Car::back_left_backward() {
    _backward(&_BACK_LEFT_FORWARD, &_BACK_LEFT_BACKWARD, _GPIO_BACK_LEFT_FORWARD, _GPIO_BACK_LEFT_BACKWARD);
}

// 后左轮停止
void Car::back_left_stop() {
    _stop(&_BACK_LEFT_FORWARD, &_BACK_LEFT_BACKWARD, _GPIO_BACK_LEFT_FORWARD, _GPIO_BACK_LEFT_BACKWARD);
}

// 后右轮前进
void Car::Car::back_right_forward() {
    _forward(&_BACK_RIGHT_FORWARD, &_BACK_RIGHT_BACKWARD, _GPIO_BACK_RIGHT_FORWARD, _GPIO_BACK_RIGHT_BACKWARD);
}

// 后右轮后退
void Car::back_right_backward() {
    _backward(&_BACK_RIGHT_FORWARD, &_BACK_RIGHT_BACKWARD, _GPIO_BACK_RIGHT_FORWARD, _GPIO_BACK_RIGHT_BACKWARD);
}

// 后右轮停止
void Car::back_right_stop() {
    _stop(&_BACK_RIGHT_FORWARD, &_BACK_RIGHT_BACKWARD, _GPIO_BACK_RIGHT_FORWARD, _GPIO_BACK_RIGHT_BACKWARD);
}


// 整体前进
void Car::forward() {
    front_left_forward();
    front_right_forward();
    back_left_forward();
    back_right_forward();
}

// 整体后退
void Car::backward() {
    front_left_backward();
    front_right_backward();
    back_left_backward();
    back_right_backward();
}

// 整体停止
void Car::stop() {
    front_left_stop();
    front_right_stop();
    back_left_stop();
    back_right_stop();
}

