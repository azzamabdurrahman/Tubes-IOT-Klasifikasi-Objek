#define WIFI_SSID "ESP32"
#define WIFI_PASS "esp32cam"
#define HOSTNAME  "esp32cam"

#include <eloquent_esp32cam.h>
#include <eloquent_esp32cam/viz/mjpeg.h>

using namespace eloq;
using namespace eloq::viz;

void setup() {
    delay(3000);
    Serial.begin(115200);
    Serial.println("___MJPEG STREAM SERVER___");

    camera.pinout.aithinker();
    camera.brownout.disable();
    camera.resolution.vga();
    camera.quality.high();

    // init camera
    while (!camera.begin().isOk())
        Serial.println(camera.exception.toString());

    // connect to WiFi
    while (!wifi.connect().isOk())
        Serial.println(wifi.exception.toString());

    // start mjpeg http server
    while (!mjpeg.begin().isOk())
        Serial.println(mjpeg.exception.toString());

    Serial.println("Camera OK");
    Serial.println("WiFi OK");
    Serial.println("MjpegStream OK");
    Serial.println(mjpeg.address());
}


void loop() {
    // HTTP server runs in a task, no need to do anything here
}