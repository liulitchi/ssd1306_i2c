/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h> 

#define SCREEN_WIDTH 128 // 显示屏宽度
#define SCREEN_HEIGHT 64 // 显示屏高度

// SSD1306 接线设定
#define OLED_RESET     4 // SDA接线位置 a4，SCL接线位置a5
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN  2                        // DHT22 接线位置，digital2，可自由设定
#define DHTTYPE DHT22                    // DHT11 或DHT22，选择型号
DHT dht(DHTPIN, DHTTYPE);                // 配置 DHT 库

char temperature[] = " 00.0 C";
char humidity[]    = " 00.0 %";

void setup(void) {
  delay(5000); //延时5s，可适当调大或调小，建议 >=1000

  // 电压3.3V或5V
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // 初始化I2C 地址 ，0x3D或0x3C
  // init done

  dht.begin();               // 初始化 DHT 库文件

  // Clear the display buffer.
  display.clearDisplay();

  // display.drawFastHLine(0, 16, SSD1306_LCDWIDTH, WHITE);

  display.setTextSize(1); //
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0,0);
  display.print("AS THOU WISH");//可自己设定
  display.setCursor(0, 31); //TEMP位置，X值和Y值
  display.print("TEMPERATURE:");
  display.setCursor(0,47 ); //HUMI位置，X值和Y值
  display.print("HUMIDITY:");
  display.display();
}

void loop() {

  // 读取湿度值
  int RH = dht.readHumidity() * 10;
  // 读取温度值（摄氏度）
  int Temp = dht.readTemperature() * 10;

  if(Temp < 0){
    temperature[0] = '-';
    Temp = abs(Temp);
  }
  else
    temperature[0] = ' ';
  temperature[1]  = (Temp / 100) % 10  + 48;
  temperature[2]  = (Temp / 10)  % 10  + 48;
  temperature[4]  =  Temp % 10 + 48;
  if(RH >= 1000)
    humidity[0]   = '1';
  else
    humidity[0]   = ' ';
  humidity[1]     = (RH / 100) % 10 + 48;
  humidity[2]     = (RH / 10) % 10 + 48;
  humidity[4]     =  RH % 10 + 48;

  display.setCursor(80, 31); //温度值的位置起始点
  display.print(temperature);
  display.setCursor(80, 47); //湿度值的位置起始点
  display.print(humidity);
  display.display();

  delay(5000); //延时5s，可适当调大或调小，建议 >=1000

}
