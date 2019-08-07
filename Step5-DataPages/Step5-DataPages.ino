/*
 * Шаг №5
 * DataPages
 */
#include <WiFi.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <WebServer.h>   //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <ESP32SSDP.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step3-ssdp
//#include <FS.h>                 //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver

#define FILESYSTEM SPIFFS
// You only need to format the filesystem once
#define FORMAT_FILESYSTEM false
#define DBG_OUTPUT_PORT Serial

#if FILESYSTEM == FFat
#include <FFat.h>
#endif
#if FILESYSTEM == SPIFFS
#include <SPIFFS.h>
#endif

IPAddress apIP(192, 168, 4, 1);

// Web интерфейс для устройства
WebServer HTTP(80);
// Для файловой системы
File fsUploadFile;

// Определяем переменные wifi
String _ssid     = "home"; // Для хранения SSID
String _password = "i12345678"; // Для хранения пароля сети
String _ssidAP = "WiFi";   // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа
String SSDP_Name="SSDP-test"; // Имя SSDP

void setup() {
  Serial.begin(115200);
  Serial.println("");
  //Запускаем файловую систему
  Serial.println("Start 4-FS");
   FS_init();
  Serial.println("Start 1-WIFI");
   //Запускаем WIFI
  WIFIinit();
    //Настраиваем и запускаем SSDP интерфейс
  Serial.println("Start 3-SSDP");
  SSDP_init();
  //Настраиваем и запускаем HTTP интерфейс
  Serial.println("Start 2-WebServer");
  HTTP_init();

}

void loop() {
  HTTP.handleClient();
  delay(1);
}