# ESP8266dev

# このレポジトリについて

このレポジトリは　[Aizu Advent Calendar 2017](https://adventar.org/calendars/2262) の16日目の記事のレポジトリです．

# ESP-WROOM-02について
ESP WROOM 02は650円くらいで購入ができます．

[購入ページ](http://akizukidenshi.com/catalog/g/gK-09758/)

# File structures
```
.
├── README.md
└── wrm02
    ├── lib
    │   └── readme.txt
    ├── platformio.ini
    └── src
        ├── Ltika
        │   ├── lib
        │   │   └── readme.txt
        │   ├── platformio.ini
        │   └── src
        │       └── Ltika_GPIO13.ino
        ├── Matrix
        │   ├── lib
        │   │   └── readme.txt
        │   ├── platformio.ini
        │   └── src
        │       └── Matrix.ino
        └── Tobirano-kaihei-Kun
            ├── lib
            │   └── readme.txt
            ├── platformio.ini
            └── src
                └── Tobira_kaihe.ino
                
```

# Detail of directory

### Ltika
Ltika's directory is to blink the LED.
To attach LED for ESP8266's GPIO 13 PIN.
(You must to attach about 1k $Omega$ ~ resistor)

### Matrix
This directory is how to use matrixLED for ESP8266.
[Matrix LED](http://docs.fabo.io/fabo/arduino/brick_color/404_brick_3pin_led_matrix.html)
Matrix LED's cable pattern 

- red cable -> VCC (+)
- black cable -> GND (-)
- yellow cable -> I/O (GPIO)

Exsample of circle.

- red cable -> ESP8266's 3V3 PIN
- black cable -> ESP8266's GND PIN
- yellow cable -> ESP8266's GPIO PIN

### Tobirano-Kaihei-Kun
To post slack channel of Door's status.
To use read switch.
