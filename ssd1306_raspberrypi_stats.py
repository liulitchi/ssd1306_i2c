#-*- coding:utf-8 -*-
#https://github.com/adafruit/Adafruit_Python_SSD1306

import time

import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

import subprocess

RST = None

#以下适合SPI:
#DC=23
#SPI_PORT = 0 
#SPI_DEVICE = 0

#型号：分辨率128*64 硬件 I2C 
disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)

disp.begin()

disp.clear()
disp.display()

#设置空白框
#确保图片 mode  '1' 1-bit
width = disp.width
height = disp.height
image = Image.new('1', (width,height))

#图片上设定字符
draw = ImageDraw.Draw(image)

#绘制黑色区域，区分
draw.rectangle((0,0,width,height), outline=0, fill=0)

#绘制图形
padding = -2
top = padding
bottom = height-padding

x = 0

#加载默认字体
font = ImageFont.load_default()

#font = ImageFont.truetype('Minecraftia.ttf',8)

while True:
    #黑色填充方块
    draw.rectangle((0,0,width,height),outline=0, fill=0)

    #系统显示  shell scripts
    cmd = "hostname -I | cut -d\' \' -f1"
    IP = subprocess.check_output(cmd,shell = True )
    cmd = "top -bn1 | grep load | awk '{printf \"CPU Load: %2.f\", $(NF-2)}'"
    CPU =subprocess.check_output(cmd, shell = True )
    cmd = "free -m | awk 'NR==2{printf \"Mem: %s/%sMB %.2f%%\", $3,$2,$3*100/$2 }'"
    MemUsage = subprocess.check_output(cmd, shell = True )
    cmd = "df -h | awk '$NF==\"/\"{printf \"Disk: %d/%dGB %s\", $3,$2,$5}'"
    Disk = subprocess.check_output(cmd, shell = True )

    #写两行文字
    draw.text((x, top),    "IP:" + str(IP), font=font, fill=255 )
    draw.text((x, top+8),  str(CPU), font=font, fill=255 )
    draw.text((x, top+16), str(MemUsage), font=font, fill=255 ) 
    draw.text((x, top+25), str(Disk), font=font, fill=255 )

    #显示界面
    disp.image(image)
    disp.display()
    time.sleep(3)
