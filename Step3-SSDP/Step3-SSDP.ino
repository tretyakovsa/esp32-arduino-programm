/*
 * Шаг №3
 * SSDP
 */
#include <WiFi.h>        //Содержится в пакете
#include <WebServer.h>   //Содержится в пакете
#include <ESP32SSDP.h>        //https://github.com/luc-github/ESP32SSDP

IPAddress apIP(192, 168, 4, 1);

// Web интерфейс для устройства
WebServer HTTP(80);

// Определяем переменные wifi
String _ssid     = "home"; // Для хранения SSID
String _password = "i12345678"; // Для хранения пароля сети
String _ssidAP = "WiFi";   // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа
String SSDP_Name="SSDP-test"; // Имя SSDP

void setup() {
  Serial.begin(115200);
  Serial.println("");
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
