# ESP8266
A c library to encapsulate and decapsulate AT strings for the ESP8266 module intended to be used on microcontrollers that don't support classes

This library provides a set of functions to prepare and read AT commands exchanged with the ESP8266 module.
####Important! The library doesn't actually sends or receive data from the module but only prepare the string to be sent by the user

For example, a receiving message is formatted like _"+IPD,0,11:Hello World"_, the unwrap function decapsulates the message and fills an char array with _"Hello World"_

##References:
Each following function need an array to be filled with the message

```c
void reset(char* dst);
//Reset the module
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
void setMode(char* dst, int mode);
//Set the wifi mode such as: Access Point, Station, or Mixed
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put <br>
>_mode:_ Integer that sets the wifi mode (STA, AP, APSTA)
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
void connectWifi(char* dst, char *ssid, char *password);
//Estabilish a connection with a determinated wifi network in Station mode
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put <br>
>_ssid:_ Wifi name you want to connect <br>
>_password:_ Wifi network password  
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
void setLinkMode(char* dst, int mode);
//Set the number of simultaneous connections allowed
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put <br>
>_mode:_ Integer that sets the link mode (ONE_CONNECTION, MULTIPLE_CONNECTIONS)
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
void disconnectWifi(char* dst);
//Disconnect from the current wifi
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
void startServer(char* dst, int port);
//Start a server listening in a specified port
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put <br>
>_port:_ Integer that specify on which port you want to accept connections
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
void wrap(char* dst, int conn, char* data);
//Prepare data to be sent
```
>**Arguments:** <br>
>_dst:_ Char array where the generated string is put <br>
>_conn:_ Integer containind the connection number you want to send data <br>
>_data:_ Char array you should fill with data you want to send to the "conn" connection
>
>**Returns:** <br>
>_null_ (nothing)

---
```c
int unwrap(char* src, int* conn, char* data);
//Decapsulate data from the received packet
```
>**Arguments:** <br>
>_src:_ Char array where you should put the entire packet arrived from the module <br>
>_conn:_ Integer filled with the connection number specified in received packet <br>
>_data:_ Char array filled with the actual data contained in the received packet
>
>**Returns:** <br>
>Integer that indicates data length 

---

Thanks to [ssokol](https://github.com/ssokol/esp8266) where I retrived some useful information
