#include "FS.h"
#include "SPIFFS.h"

void setup() {
    Serial.begin(115200);
    if(!SPIFFS.begin()){
        Serial.println("SPIFFS begin error");
        return;
    }
    File file = SPIFFS.open("/test.txt");
    if(!file || file.isDirectory()){
        Serial.println("File open error");
        return;
    }
    while(file.available()){
        Serial.write(file.read());
    }
    file.close();

}

void loop() {
}
