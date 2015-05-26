//
//  libESP8266.c
//  ESP8266
//
//  Created by Enrico Gambini on 20/05/15.
//  Copyright (c) 2015 Enrico Gambini. All rights reserved.
//

#include "libESP8266.h"


void reset(char* dst) {
    // reset WiFi module
    strcpy(dst, AT_RESET);
}

void setMode(char* dst, int mode) {
    // set the connectivity mode 1=sta, 2=ap, 3=sta+ap
    sprintf(dst, "%s%d", AT_WIFI_MODE, mode);
}

void connectWifi(char* dst, char* ssid, char* password) {
    // set the access point value and connect
    sprintf(dst, "%s\"%s\",\"%s\"", AT_JOIN_WIFI, ssid, password);
}

void disconnectWifi(char* dst) {
    strcpy(dst, AT_QUIT_WIFI);
}

void setLinkMode(char* dst, int mode) {
    // set if multiple connections are allowed or not
    sprintf(dst, "%s%d", AT_LINK_MODE, mode);
}

void startServer(char* dst, int port) {
    // start a TCP server listening on the specified port
    sprintf(dst, "%s1,%d", AT_START_SERVER, port);
}

void wrap(char* dst, int conn, char* data) {
    sprintf(dst, "%s%d,%d%s", AT_SEND, conn, (int)strlen(data), data);
}

int unwrap(char* src, int* conn, char* data) {
    char* pointer = 0;
    int length = 0;
    
    // control if the message is a received packet from server
    pointer = strstr(src, AT_RECEIVED);
    
    // if not exit and return 0
    if(!pointer)
        return 0;
    
    // skip the keyword found
    pointer += strlen(AT_RECEIVED);
    // get the connection number and the data field length
    sscanf(pointer, "%d,%d", conn, &length);
    
    // if no data return 0
    if(!length)
        return 0;
    
    // set the pointer to the first data character
    while(*pointer!=':') pointer++;
    pointer++;
    // copy the data field in data to be used outside
    strcpy(data, pointer);
    
    return length;
}

