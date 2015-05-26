//
//  libESP8266.h
//  ESP8266
//
//  Created by Enrico Gambini on 20/05/15.
//  Copyright (c) 2015 Enrico Gambini. All rights reserved.
//

#ifndef __ESP8266__libESP8266__
#define __ESP8266__libESP8266__

#include <stdio.h>
#include <string.h>

typedef int (*DataCallback)(char *);
typedef void (*ConnectCallback)(void);

enum wifiModes {
    WIFI_MODE_STA = 1,
    WIFI_MODE_AP,
    WIFI_MODE_APSTA
};

enum wifiErrors {
    WIFI_ERR_NONE = 0,
    WIFI_ERR_AT,
    WIFI_ERR_RESET,
    WIFI_ERR_CONNECT,
    WIFI_ERR_LINK
};

#define AT_RESET "AT+RST"
#define AT_WIFI_MODE "AT+CWMODE="
#define AT_JOIN_WIFI "AT+CWJAP="
#define AT_QUIT_WIFI "AT+CWQAP"
#define AT_LINK_MODE "AT+CIPMUX="
#define AT_START_SERVER "AT+CIPSERVER="
#define AT_SEND "AT+CIPSEND="
#define AT_RECEIVED "+IPD,"

// init / connect / disconnect access point
void reset(char* dst);
void setMode(char* dst, int mode);
void connectWifi(char* dst, char *ssid, char *password);
void setLinkMode(char* dst, int mode);

void disconnectWifi();    // TODO future implementation

// server
void startServer(char* dst, int port);

// prepare the message to be sent over serial port to ESP8266
void wrap(char* dst, int conn, char* data);

// read the data field of the message arrived from ESP8266
int unwrap(char* src, int* conn, char* data);


#endif /* defined(__ESP8266__libESP8266__) */