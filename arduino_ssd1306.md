# Arduino  驱动 SSD1306 屏幕的简单教程

注：本人无任何实际原创，参考了以下此[文档](https://startingelectronics.org/tutorials/arduino/modules/OLED-128x64-I2C-display/) ，有任何疑惑可以点击链接参考学习。

## 本次使用到的硬件：

Arduino Uno 开发板 1块，
公对母杜邦线    4条，
SSD1306 的屏幕 1块。

## 参考接线位置：
```
VCC ——  接5V （正级）
GND —— 接GND （负级）
SCL —— 接A5 (Serial Clock)
SDA —— 接A4 (Serial Data )
```
这里本人使用了一块 I2C接口的OLED屏幕，分辨率为128*64。(也有8根接线的SPI屏幕，分辨率也分两种，128*64,或者128*32,到时候按实际需要修改)

## 操作步骤

1,下载所需驱动库：前人已经为我们写好了文档，需要在 github 上下载以下两个文档，附压缩文档链接：

> https://github.com/adafruit/Adafruit-GFX-Library/archive/master.zip

> https://github.com/adafruit/Adafruit_SSD1306/archive/master.zip

2,加载驱动库：打开 arduino 软件，依次点击“项目”——“加载库”——“添加一个 .ZIP库”，将上一步下载的两个压缩包加载到软件中后，点击“确定”退出。

3,修改加载的文档：在这里，所下载的驱动默认设置，可能和我们所购买的屏幕参数不符，我们需要做一步轻微修正。
打开arduino 第三方库文件位置，windows 系统可能位于` C: \This  PC\Documents\Arduino\libtaries\`  下，linux 系统可能位于 `home/user/Arduino/libraries/` 下。

进入Adafruit_SSD1306（可自己修改）文件夹里，用文本编辑器打开 Adadruit_SSD1306.h 文件，鼠标移到 73-75行，这里有三个分辨率选项，找到你屏幕的分辨率，如下：

```
#define SSD1306_128_64
// #define SSD1306_128_32
// #define SSD1306_96_16
```
上面三行的意思是，选择了 128*64 的分辨率，在 C/C++ 和 Arduino 语言中 ，以//起头的一行，表示注释，不起作用。根据自己实际屏幕，选择分辨率。然后保存。

3,硬件烧写程序：打开 arduino 软件 ，选择 “示例”——“Adafruit_1306”，会出现四个分辨率选项，点击符合屏幕的，进行文档上传至硬件。
这里需要注意，找到 display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 不同的屏幕，起始值不同，或为 0x3C ，或为 0x3D ，验证好自己的硬件，否则屏幕无显示。