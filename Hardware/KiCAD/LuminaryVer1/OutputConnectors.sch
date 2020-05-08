EESchema Schematic File Version 4
EELAYER 30 0
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
Text HLabel 6500 3450 2    50   Input ~ 0
CAN_1_HI
Text HLabel 6500 3550 2    50   Input ~ 0
CAN_1_LO
Text HLabel 5000 2800 2    50   UnSpc ~ 0
ADC_1
Text HLabel 5000 2900 2    50   UnSpc ~ 0
ADC_2
Text HLabel 5000 3000 2    50   UnSpc ~ 0
ADC_3
Wire Wire Line
	4900 3400 5100 3400
Wire Wire Line
	4900 3500 5100 3500
Wire Wire Line
	4900 3600 5100 3600
Wire Wire Line
	4900 3950 5100 3950
Wire Wire Line
	4900 4050 5100 4050
Wire Wire Line
	4900 4150 5100 4150
Wire Wire Line
	6400 3450 6500 3450
Wire Wire Line
	6400 3550 6500 3550
Wire Wire Line
	4900 2800 5000 2800
Wire Wire Line
	4900 2900 5000 2900
Wire Wire Line
	4900 3000 5000 3000
Wire Wire Line
	6400 2900 6500 2900
Wire Wire Line
	6400 3000 6500 3000
Wire Wire Line
	6400 3950 6500 3950
Wire Wire Line
	6400 4050 6500 4050
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
$Comp
L Connector:Conn_01x12_Female J13
U 1 1 5ECB3CF3
P 2750 2500
F 0 "J13" H 2778 2476 50  0000 L CNN
F 1 "CN1" H 2778 2385 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 2750 2500 50  0001 C CNN
F 3 "~" H 2750 2500 50  0001 C CNN
	1    2750 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x12_Female J14
U 1 1 5ECB51B2
P 3200 4150
F 0 "J14" H 3228 4126 50  0000 L CNN
F 1 "CN2" H 3228 4035 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 3200 4150 50  0001 C CNN
F 3 "~" H 3200 4150 50  0001 C CNN
	1    3200 4150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
