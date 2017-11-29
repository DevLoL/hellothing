/*
 * ESP Boilerplate OS - main.cpp
 * (c) by Christoph (doebi) Döberl
 *
 */
#include "ESPThing.h"

const int relay = 5;
int relayState = LOW;

void hello_cb(const MQTT::Publish& pub) {
    if (pub.payload_string() == "hello") {
        digitalWrite(relay, LOW);        
        delay(200);
        digitalWrite(relay, HIGH);        
        delay(8000);
        digitalWrite(relay, LOW);        
    }
}

void setup() {
    pinMode(relay, OUTPUT);
    digitalWrite(relay, LOW);
    Thing.addInput(Input("hello", hello_cb));
}

void loop() {
    Thing.loop();
}
