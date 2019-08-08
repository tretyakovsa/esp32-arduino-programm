#include <WiFi.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <WebServer.h>   //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <ESP32SSDP.h>        //https://github.com/luc-github/ESP32SSDP Видео с уроком http://esp8266-arduinoide.ru/step3-ssdp
//                    ПЕРЕДАЧА ДАННЫХ НА WEB СТРАНИЦУ. Видео с уроком http://esp8266-arduinoide.ru/step5-datapages/
//                    ПЕРЕДАЧА ДАННЫХ С WEB СТРАНИЦЫ.  Видео с уроком http://esp8266-arduinoide.ru/step6-datasend/
#include <ArduinoJson.h>        //Установить из менеджера библиотек. https://arduinojson.org/
//                    ЗАПИСЬ И ЧТЕНИЕ ПАРАМЕТРОВ КОНФИГУРАЦИИ В ФАЙЛ. Видео с уроком http://esp8266-arduinoide.ru/step7-fileconfig/
#include <Update.h>     //Содержится в пакете.  Видео с уроком http://esp8266-arduinoide.ru/step8-timeupdate/

#define FILESYSTEM SPIFFS
// You only need to format the filesystem once
#define FORMAT_FILESYSTEM false

#if FILESYSTEM == FFat
#include <FFat.h>
#endif
#if FILESYSTEM == SPIFFS
#include <SPIFFS.h>
#endif


// Web интерфейс для устройства
WebServer HTTP(80);

// Для файловой системы
File fsUploadFile;

String configSetup = "{}";
String configJson = "{}";
