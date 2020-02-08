EESchema Schematic File Version 4
LIBS:LuminaryVer1-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5100 3400 2    50   Input ~ 0
SPI_1_SCK
Text HLabel 5100 3500 2    50   Input ~ 0
SPI_1_MOSI
Text HLabel 5100 3600 2    50   Output ~ 0
SPI_1_MISO
Text HLabel 5100 3950 2    50   Input ~ 0
SPI_2_SCK
Text HLabel 5100 4050 2    50   Input ~ 0
SPI_2_MOSI
Text HLabel 5100 4150 2    50   Output ~ 0
SPI_2_MISO
Text HLabel 6500 2900 2    50   Input ~ 0
I2C_1_SDA
Text HLabel 6500 3000 2    50   Input ~ 0
I2C_1_SCL
Text HLabel 6500 3950 2    50   Input ~ 0
RS232_1_TX
Text HLabel 6500 4050 2    50   Input ~ 0
RS232_1_RX
Text HLabel 6500 4150 2    50   UnSpc ~ 0
RS232_1_GND
Text HLabel 6500 3100 2    50   UnSpc ~ 0
I2C_1_GND
Text HLabel 5100 3700 2    50   UnSpc ~ 0
SPI_1_GND
Text HLabel 5100 4250 2    50   UnSpc ~ 0
SPI_2_GND
Text HLabel 6500 3450 2    50   Input ~ 0
CAN_1_HI
Text HLabel 6500 3650 2    50   UnSpc ~ 0
CAN_1_GND
Text HLabel 6500 3550 2    50   Input ~ 0
CAN_1_LO
Text HLabel 5000 2800 2    50   UnSpc ~ 0
ADC_1
Text HLabel 5000 2900 2    50   UnSpc ~ 0
ADC_2
Text HLabel 5000 3000 2    50   UnSpc ~ 0
ADC_3
Text HLabel 5000 3100 2    50   UnSpc ~ 0
ADC_GND
Wire Wire Line
	4900 3400 5100 3400
Wire Wire Line
	4900 3500 5100 3500
Wire Wire Line
	4900 3600 5100 3600
Wire Wire Line
	4900 3700 5100 3700
Wire Wire Line
	4900 3950 5100 3950
Wire Wire Line
	4900 4050 5100 4050
Wire Wire Line
	4900 4150 5100 4150
Wire Wire Line
	4900 4250 5100 4250
$Comp
L Connector:Conn_01x03_Female J5
U 1 1 5E60C918
P 6200 3000
F 0 "J5" H 6092 3285 50  0000 C CNN
F 1 "I2C_1_Connections" H 6092 3194 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S3B-PH-K_1x03_P2.00mm_Horizontal" H 6200 3000 50  0001 C CNN
F 3 "~" H 6200 3000 50  0001 C CNN
	1    6200 3000
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J7
U 1 1 5E61127F
P 6200 4050
F 0 "J7" H 6092 4335 50  0000 C CNN
F 1 "RS232_1_Connections" H 6092 4244 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S3B-PH-K_1x03_P2.00mm_Horizontal" H 6200 4050 50  0001 C CNN
F 3 "~" H 6200 4050 50  0001 C CNN
	1    6200 4050
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female J3
U 1 1 5E6137F9
P 6200 3550
F 0 "J3" H 6092 3835 50  0000 C CNN
F 1 "CAN_Connections" H 6092 3744 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S3B-PH-K_1x03_P2.00mm_Horizontal" H 6200 3550 50  0001 C CNN
F 3 "~" H 6200 3550 50  0001 C CNN
	1    6200 3550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6400 3450 6500 3450
Wire Wire Line
	6400 3550 6500 3550
Wire Wire Line
	6400 3650 6500 3650
Wire Wire Line
	4900 2800 5000 2800
Wire Wire Line
	4900 2900 5000 2900
Wire Wire Line
	4900 3000 5000 3000
Wire Wire Line
	4900 3100 5000 3100
Wire Wire Line
	6400 2900 6500 2900
Wire Wire Line
	6400 3000 6500 3000
Wire Wire Line
	6500 3100 6400 3100
Wire Wire Line
	6400 3950 6500 3950
Wire Wire Line
	6400 4050 6500 4050
Wire Wire Line
	6400 4150 6500 4150
$Comp
L Connector:Conn_01x04_Female J4
U 1 1 5E6BE6A5
P 4700 2900
F 0 "J4" H 4592 3185 50  0000 C CNN
F 1 "ADC_Connections" H 4592 3094 50  0000 C CNN
F 2 "" H 4700 2900 50  0001 C CNN
F 3 "~" H 4700 2900 50  0001 C CNN
	1    4700 2900
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J6
U 1 1 5E6BF710
P 4700 3500
F 0 "J6" H 4592 3785 50  0000 C CNN
F 1 "SPI_1_Connections" H 4592 3694 50  0000 C CNN
F 2 "" H 4700 3500 50  0001 C CNN
F 3 "~" H 4700 3500 50  0001 C CNN
	1    4700 3500
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J8
U 1 1 5E6BFED7
P 4700 4050
F 0 "J8" H 4592 4335 50  0000 C CNN
F 1 "SPI_3_Connections" H 4592 4244 50  0000 C CNN
F 2 "" H 4700 4050 50  0001 C CNN
F 3 "~" H 4700 4050 50  0001 C CNN
	1    4700 4050
	-1   0    0    -1  
$EndComp
Text HLabel 5000 2000 2    50   Output ~ 0
GPIO_OUT_0
Text HLabel 5000 2100 2    50   Output ~ 0
GPIO_OUT_1
Text HLabel 5000 2200 2    50   Output ~ 0
GPIO_OUT_2
Text HLabel 5000 2300 2    50   Output ~ 0
GPIO_OUT_3
Text HLabel 5000 2400 2    50   Output ~ 0
GPIO_OUT_4
Text HLabel 5000 2500 2    50   Output ~ 0
GPIO_OUT_5
$Comp
L Connector:Conn_01x06_Female J9
U 1 1 5E6FC150
P 4700 2200
F 0 "J9" H 4592 2585 50  0000 C CNN
F 1 "GPIO_Connections" H 4592 2494 50  0000 C CNN
F 2 "" H 4700 2200 50  0001 C CNN
F 3 "~" H 4700 2200 50  0001 C CNN
	1    4700 2200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4900 2000 5000 2000
Wire Wire Line
	4900 2100 5000 2100
Wire Wire Line
	4900 2200 5000 2200
Wire Wire Line
	4900 2300 5000 2300
Wire Wire Line
	4900 2400 5000 2400
Wire Wire Line
	4900 2500 5000 2500
$Comp
L Connector:Conn_01x03_Female J11
U 1 1 5E70C26B
P 6200 2150
F 0 "J11" H 6092 2435 50  0000 C CNN
F 1 "Power_Connections" H 6092 2344 50  0000 C CNN
F 2 "Connector_JST:JST_PH_S3B-PH-K_1x03_P2.00mm_Horizontal" H 6200 2150 50  0001 C CNN
F 3 "~" H 6200 2150 50  0001 C CNN
	1    6200 2150
	-1   0    0    -1  
$EndComp
Text HLabel 6500 2050 2    50   UnSpc ~ 0
+5v
Text HLabel 6500 2150 2    50   UnSpc ~ 0
+3.3v
Text HLabel 6500 2250 2    50   UnSpc ~ 0
Gnd
Wire Wire Line
	6400 2250 6500 2250
Wire Wire Line
	6400 2150 6500 2150
Wire Wire Line
	6400 2050 6500 2050
$EndSCHEMATC
