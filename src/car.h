//
// Created by lailailee on 2022/6/29.
//

#ifndef ESP32DEV_BLINKER_CAR_CAR_H
#define ESP32DEV_BLINKER_CAR_CAR_H


class Car {
public:
    void front_left_forward();

    void front_left_backward();

    void front_left_stop();

    void front_right_forward();

    void front_right_backward();

    void front_right_stop();

    void back_left_forward();

    void back_left_backward();

    void back_left_stop();

    void back_right_forward();

    void back_right_backward();

    void back_right_stop();

    void forward();

    void backward();

    void stop();

private:
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
    //前左轮
    const int _GPIO_FRONT_LEFT_SPEED = 14;
    const int _GPIO_FRONT_LEFT_FORWARD = 13;
    const int _GPIO_FRONT_LEFT_BACKWARD = 12;
    int _FRONT_LEFT_SPEED = 100;
    byte _FRONT_LEFT_FORWARD = LOW;
    byte _FRONT_LEFT_BACKWARD = LOW;
    //前右轮
    const int _GPIO_FRONT_RIGHT_SPEED = 25;
    const int _GPIO_FRONT_RIGHT_FORWARD = 27;
    const int _GPIO_FRONT_RIGHT_BACKWARD = 26;
    int _FRONT_RIGHT_SPEED = 100;
    byte _FRONT_RIGHT_FORWARD = LOW;
    byte _FRONT_RIGHT_BACKWARD = LOW;
    //后左轮
    const int _GPIO_BACK_LEFT_SPEED = 35;
    const int _GPIO_BACK_LEFT_FORWARD = 33;
    const int _GPIO_BACK_LEFT_BACKWARD = 32;
    int _BACK_LEFT_SPEED = 100;
    byte _BACK_LEFT_FORWARD = LOW;
    byte _BACK_LEFT_BACKWARD = LOW;
    //后右轮
    const int _GPIO_BACK_RIGHT_SPEED = 36;
    const int _GPIO_BACK_RIGHT_FORWARD = 34;
    const int _GPIO_BACK_RIGHT_BACKWARD = 39;
    int _BACK_RIGHT_SPEED = 100;
    byte _BACK_RIGHT_FORWARD = LOW;
    byte _BACK_RIGHT_BACKWARD = LOW;

    void _forward(byte *FORWARD, byte *BACKWARD, int GPIO_FORWARD, int GPIO_BACKWARD);

    void _backward(byte *FORWARD, byte *BACKWARD, int GPIO_FORWARD, int GPIO_BACKWARD);

    void _stop(byte *FORWARD, byte *BACKWARD, int GPIO_FORWARD, int GPIO_BACKWARD);

};


#endif //ESP32DEV_BLINKER_CAR_CAR_H
