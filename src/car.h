//
// Created by lailailee on 2022/6/29.
//

#ifndef ESP32DEV_BLINKER_CAR_CAR_H
#define ESP32DEV_BLINKER_CAR_CAR_H


class Car {
public:
    //左轮
    //IN1 13
    //IN2 12
    //ENA 14
    //右轮
    //IN3 27
    //IN4 26
    //ENB 25

    int car_state = 0;

    const int left_speed_gpio = 13;
    const int left_forward_gpio = 12;
    const int left_backward_gpio = 14;

    byte left_forward_value = LOW;
    byte left_backward_value = LOW;

    int left_speed = 225;

    //前右轮
    const int right_speed_gpio = 25;
    const int right_forward_gpio = 27;
    const int right_backward_gpio = 26;

    byte right_forward_value = LOW;
    byte right_backward_value = LOW;

    int right_speed = 225;

    void forward();

    void backward();

    void stop();

    void init();

    void turn_left();

    void turn_right();
    void turn_left_back();

    void turn_right_back();

    void execute_speed();

    void execute_speed(int speed);

private:


};


#endif //ESP32DEV_BLINKER_CAR_CAR_H
