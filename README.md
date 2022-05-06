# super-clock
基于瑞萨R7FA2E1A72DFL的万年历

# 缘起
瑞萨x立创eda联合举办的活动，白嫖器件，白嫖pcb，白嫖3d打印
https://maker.lceda.cn/LCEDA_RAMCU

# 元件
| 描述  | 型号 |
| ------------- | ------------- |
| MCU  | R7FA2E1A72DFL  |
| 温度传感器  | GXHT30（同SHT30）  |
| 蓝牙  |  CH571k  |
| LED  |  WS2812B  |

# 外观设计
三明治结构
阻焊，开窗
# 开发环境
e2 studio
# 代码结构
```
├─adc adc读取光敏电阻
├─buzzer pwm驱动无源蜂鸣器
├─color  hsv色域转换
├─debug  调试串口
├─fcal   农历转换
├─GXHT30   温湿度传感器
├─rtc    实时时钟
├─timer  屏幕刷新信号
└─ws2812  led驱动

main.cpp 主要逻辑
utils.h  工具类
```
# 技术参考
## 调试输出函数设计
## spi驱动ws2812
## 瑞萨spi驱动ws2812的坑
## 色域转换
## 压电无源蜂鸣器
## midi
## 随机数生成（加密）的坑
## 时间戳
## 蓝牙广播

# 天坑