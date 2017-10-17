# ssd1306_i2c
一个适合树莓派的ssd1306(四针I2C)屏幕驱动
因为网上的有专门的ssd1306_spi驱动（来自 adafruit项目），
我就参考TA的代码，重写了一个I2C的，树莓派2实测正常显示，
有问题可以反馈，萌新写代码，乱写一气也是

-------------------

针脚参考(对应物理针脚)：

VCC-----Pin 17

GND-----Pin 9

SCL-----Pin 5

SDA-----Pin 3

由于之前接了一个DHT22 的传感器，所以大家可以对应接其它的，在此就不举例了。

--------------------


预安装(最新系统已默认安装)：

sudo apt update

sudo apt install build-essential python-dev


下载adafruit提供的代码：

git clone https://github.com/adafruit/Adafruit_Python_SSD1306.git

cd Adaffruit_Python_SSD1306

sudo python setup.py install


执行本地代码：

git clone https://github.com/liulitchi/ssd1306_i2c.git 

cd ssd1306_i2c

sudo python ssd1306_stats.py

