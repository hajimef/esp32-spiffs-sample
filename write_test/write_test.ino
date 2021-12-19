#include "FS.h"
#include "SPIFFS.h"

void setup() {
    Serial.begin(115200);
    if(!SPIFFS.begin(true)){
        Serial.println("SPIFFS begin error");
        return;
    }
    File file = SPIFFS.open("/test.txt", FILE_WRITE);
    if(!file){
        Serial.println("File open error");
        return;
    }
    if(!file.print("Hello, ESP32")){
        Serial.println("File write error");
    }
    file.close();
}

void loop() {
}
