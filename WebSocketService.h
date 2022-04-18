#pragma once

#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <string>

class WebSocketService
{
public:
    static AsyncWebSocket aws;
    static std::vector<WebSocketService *> *instances;  // the components that will process json message
    static StaticJsonDocument<800> jsonMsg;
    std::string name = "";

    // WebSocketImpl(string awsUrl) : FirmwareModule("WebSocket")
    // {
    //     Serial.printf("[WebSocket] creation");
    //     aws = new AsyncWebSocket(awsUrl.c_str());
    // }
    WebSocketService(std::string name = "defaultservice");

    static void eventHandler(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
                             void *arg, uint8_t *data, size_t len);

    static void routeMessages(void *arg, uint8_t *data, size_t len);

    static void dispatchService(std::string service);


    static void parseJson(std::string jsonStr);

    virtual void processMsg() = 0;
};