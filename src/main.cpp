#define BLINKER_WIFI
#define BLINKER_APCONFIG

#include <Blinker.h>
#include "OneButton.h"

#include "car.h"

#define BUTTON_FORWARD "btn-forward"
#define BUTTON_BACKWARD "btn-backward"
#define BUTTON_LEFT "btn-left"
#define BUTTON_RIGHT "btn-right"
#define BUTTON_LEFT_BACK "btn-left-back"
#define BUTTON_RIGHT_BACK "btn-right-back"

#define BUTTON_STOP "btn-stop"
#define RAN_SPEED "ran-speed"


BlinkerButton btn_forward(BUTTON_FORWARD);
BlinkerButton btn_backward(BUTTON_BACKWARD);
BlinkerButton btn_left(BUTTON_LEFT);
BlinkerButton btn_right(BUTTON_RIGHT);
BlinkerButton btn_left_back(BUTTON_LEFT_BACK);
BlinkerButton btn_right_back(BUTTON_RIGHT_BACK);
BlinkerButton btn_stop(BUTTON_STOP);
BlinkerSlider ran_speed(RAN_SPEED);


bool switch_state = false;

void heartbeat();

String summary();

void switch_callback(const String &state);

void deviceReset();

void dataRead(const String &data);

void btn_forward_callback(const String &state);

void btn_backward_callback(const String &state);

void btn_left_callback(const String &state);

void btn_right_callback(const String &state);

void btn_left_back_callback(const String &state);

void btn_right_back_callback(const String &state);


void btn_stop_callback(const String &state);

void ran_speed_callback(int32_t value);


// button trigged when pin input level is LOW
OneButton button(BLINKER_BUTTON_PIN, true);

Car car;

char auth[] = "822898c1c417";  // 2687b29a7a8e


void setup() {
    Serial.begin(115200);
    car.init();
    car.execute_speed();
    Serial.println("Start");

    BLINKER_DEBUG.stream(Serial);
    Blinker.begin(auth);
    Blinker.attachData(dataRead);
    button.attachLongPressStop(deviceReset);
    Blinker.attachHeartbeat(heartbeat);
    Blinker.attachSummary(summary);

    btn_forward.attach(btn_forward_callback);
    btn_backward.attach(btn_backward_callback);
    btn_left.attach(btn_left_callback);
    btn_right.attach(btn_right_callback);
    btn_left_back.attach(btn_left_back_callback);
    btn_right_back.attach(btn_right_back_callback);
    btn_stop.attach(btn_stop_callback);
    ran_speed.attach(ran_speed_callback);
}


void btn_forward_callback(const String &state) {
    Serial.println("btn_forward_callback: " + state);
    if (state == "tap") {
        car.forward();
    } else if (state == "press") {

//  car.execute_wheel_ward();
    } else if (state == "pressup") {
//        car.reset_speed();
    }
}

void btn_backward_callback(const String &state) {
    Serial.println("btn_backward_callback: " + state);
    if (state == "tap") {
        car.backward();
    } else if (state == "press") {

//        car.execute_wheel_ward();
    } else if (state == "pressup") {
//        car.reset_speed();
    }
}


void btn_left_back_callback(const String &state) {
    Serial.println("btn_left_back_callback: " + state);
    if (state == "tap") {

    } else if (state == "press") {
        car.turn_left_back();
    } else if (state == "pressup") {
        car.backward();
    }
}

void btn_right_back_callback(const String &state) {
    Serial.println("btn_right_callback: " + state);
    if (state == "tap") {

    } else if (state == "press") {
        car.turn_right_back();
    } else if (state == "pressup") {
        car.backward();
    }

}

void btn_left_callback(const String &state) {
    Serial.println("btn_left_callback: " + state);
    if (state == "tap") {
//        car.turn_left();
    } else if (state == "press") {
        car.turn_left();
    } else if (state == "pressup") {
        car.forward();
    }

}

void btn_right_callback(const String &state) {
    Serial.println("btn_right_callback: " + state);
    if (state == "tap") {

    } else if (state == "press") {
        car.turn_right();
    } else if (state == "pressup") {
        car.forward();
    }

}

void btn_stop_callback(const String &state) {
    Serial.println("btn_stop_callback: " + state);
    if (state == "tap") {
        car.stop();
    } else if (state == "press") {

    } else if (state == "pressup") {
//        car.reset_speed();
    }
}

void ran_speed_callback(int32_t value) {
    Serial.println("ran_speed_callback: " + String(value));
    car.execute_speed(value);
}


void loop() {
    Blinker.run();
    button.tick();
}

void deviceReset() {
    // Reset device ,erase WiFi config.
    Blinker.reset();
}


void dataRead(const String &data) {
    BLINKER_LOG("Blinker readString: ", data);
    Blinker.vibrate();
    uint32_t BlinkerTime = millis();
    Blinker.print("millis", BlinkerTime);
}


void switch_callback(const String &state) {
    BLINKER_LOG("get switch state: ", state);

    if (state == BLINKER_CMD_ON) {
        switch_state = true;
//        openELec();
        BUILTIN_SWITCH.print("on");
    } else if (state == BLINKER_CMD_OFF) {
        switch_state = false;
//        closeELec();
        BUILTIN_SWITCH.print("off");
    }
}

String summary() {
    String data = "online, switch: " + STRING_format(switch_state ? "on" : "off");

    return data;
}


void heartbeat() {

    if (switch_state) BUILTIN_SWITCH.print("on");
    else BUILTIN_SWITCH.print("off");

}