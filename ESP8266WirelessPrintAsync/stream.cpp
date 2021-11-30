#ifdef ESP32CAM
#include stream.h
camera_fb_t * fb = NULL;
 // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
 sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_QVGA);
void get_Imag(AsyncWebSocket webSocket, uint8_t num ){
            fb = esp_camera_fb_get();
          //webSocket.sendBIN(num, (const uint8_t *)fb->buf, fb->len);
          webSocket.binary(num, (uint8_t *)fb->buf, fb->len);
          esp_camera_fb_return(fb);
          fb = NULL;
          }
#endif
