//
//  main.c
//  ESP8266
//
//  Created by Enrico Gambini on 20/05/15.
//  Copyright (c) 2015 Enrico Gambini. All rights reserved.
//

#include <stdio.h>
#include "libESP8266.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char message[100];
    int conn = 255;
    int res = unwrap("+IPD,0,4:ciao", &conn, message);
    if(res){
        printf("Got %d char message \"%s\" from connection n: %d", res, message, conn);
    }
    else
        printf("Not found");
    getchar();
    return 0;
}