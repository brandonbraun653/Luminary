EESchema Schematic File Version 4
LIBS:LightDriverShieldVer1-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RF:NRF24L01_Breakout U4
U 1 1 5EE5133C
P 7300 1750
F 0 "U4" H 7680 1796 50  0000 L CNN
F 1 "NRF24L01_Breakout" H 7680 1705 50  0000 L CNN
F 2 "RF_Module:nRF24L01_Breakout" H 7450 2350 50  0001 L CIN
F 3 "http://www.nordicsemi.com/eng/content/download/2730/34105/file/nRF24L01_Product_Specification_v2_0.pdf" H 7300 1650 50  0001 C CNN
	1    7300 1750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:Si2319CDS Q2
U 1 1 5EE52CAC
P 5350 1050
F 0 "Q2" V 5693 1050 50  0000 C CNN
F 1 "Si2301" V 5602 1050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5550 975 50  0001 L CIN
F 3 "http://www.vishay.com/docs/66709/si2319cd.pdf" H 5350 1050 50  0001 L CNN
F 4 "C10487" V 5350 1050 50  0001 C CNN "LCSC"
	1    5350 1050
	0    1    -1   0   
$EndComp
$Comp
L fs8205a:FS8205A U1
U 1 1 5EE5491F
P 4700 3400
F 0 "U1" H 5028 3353 60  0000 L CNN
F 1 "FS8205A" H 5028 3247 60  0000 L CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 5650 3650 60  0001 C CNN
F 3 "" H 5650 3650 60  0001 C CNN
F 4 "C16052" V 4700 3400 50  0001 C CNN "LCSC"
	1    4700 3400
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3904 Q1
U 1 1 5EE5631C
P 5250 1850
F 0 "Q1" H 5440 1896 50  0000 L CNN
F 1 "2N3904" H 5440 1805 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5450 1775 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 5250 1850 50  0001 L CNN
F 4 "C18536" H 5250 1850 50  0001 C CNN "LCSC"
	1    5250 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5EE57CDD
P 5050 1200
F 0 "R2" H 4982 1154 50  0000 R CNN
F 1 "10k" H 4982 1245 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5090 1190 50  0001 C CNN
F 3 "~" H 5050 1200 50  0001 C CNN
	1    5050 1200
	1    0    0    1   
$EndComp
Wire Wire Line
	5050 1050 5050 950 
Wire Wire Line
	5050 950  5150 950 
Wire Wire Line
	5050 1350 5050 1500
Wire Wire Line
	5050 1500 5350 1500
Wire Wire Line
	5350 1500 5350 1250
Wire Wire Line
	5350 1500 5350 1650
Connection ~ 5350 1500
$Comp
L power:GND #PWR0101
U 1 1 5EE59ADD
P 5350 2150
F 0 "#PWR0101" H 5350 1900 50  0001 C CNN
F 1 "GND" H 5355 1977 50  0000 C CNN
F 2 "" H 5350 2150 50  0001 C CNN
F 3 "" H 5350 2150 50  0001 C CNN
	1    5350 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2050 5350 2150
$Comp
L Device:C_Small C1
U 1 1 5EE5A2E4
P 5650 1150
F 0 "C1" H 5742 1196 50  0000 L CNN
F 1 "1uF" H 5742 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5650 1150 50  0001 C CNN
F 3 "~" H 5650 1150 50  0001 C CNN
F 4 "C52923" H 5650 1150 50  0001 C CNN "LCSC"
	1    5650 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1050 5650 950 
Wire Wire Line
	5650 950  5550 950 
$Comp
L power:GND #PWR0102
U 1 1 5EE5AC0A
P 5650 1300
F 0 "#PWR0102" H 5650 1050 50  0001 C CNN
F 1 "GND" H 5655 1127 50  0000 C CNN
F 2 "" H 5650 1300 50  0001 C CNN
F 3 "" H 5650 1300 50  0001 C CNN
	1    5650 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1300 5650 1250
Wire Wire Line
	7300 1150 7300 950 
Wire Wire Line
	7300 950  5650 950 
Connection ~ 5650 950 
$Comp
L power:GND #PWR0103
U 1 1 5EE5B57D
P 7300 2400
F 0 "#PWR0103" H 7300 2150 50  0001 C CNN
F 1 "GND" H 7305 2227 50  0000 C CNN
F 2 "" H 7300 2400 50  0001 C CNN
F 3 "" H 7300 2400 50  0001 C CNN
	1    7300 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2350 7300 2400
Text GLabel 6700 1450 0    50   Input ~ 0
MOSI
Text GLabel 6700 1550 0    50   Input ~ 0
MISO
Text GLabel 6700 1650 0    50   Input ~ 0
SCK
Text GLabel 6700 1750 0    50   Input ~ 0
CS
Text GLabel 6700 1950 0    50   Input ~ 0
CE
Wire Wire Line
	6700 1950 6800 1950
Wire Wire Line
	6700 1750 6800 1750
Wire Wire Line
	6700 1650 6800 1650
Wire Wire Line
	6700 1550 6800 1550
Wire Wire Line
	6700 1450 6800 1450
Text GLabel 4550 1850 0    50   Input ~ 0
RADIO_PWR
$Comp
L Device:R_US R1
U 1 1 5EE5D5A9
P 4800 1850
F 0 "R1" V 4595 1850 50  0000 C CNN
F 1 "1k" V 4686 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4840 1840 50  0001 C CNN
F 3 "~" H 4800 1850 50  0001 C CNN
	1    4800 1850
	0    -1   1    0   
$EndComp
Wire Wire Line
	4550 1850 4650 1850
Wire Wire Line
	4950 1850 5050 1850
$Comp
L Switch:SW_DIP_x06 SW1
U 1 1 5EE5E73B
P 1950 5000
F 0 "SW1" H 1950 5567 50  0000 C CNN
F 1 "SW_DIP_x06" H 1950 5476 50  0000 C CNN
F 2 "Button_Switch_THT:SW_DIP_SPSTx06_Slide_6.7x16.8mm_W7.62mm_P2.54mm_LowProfile" H 1950 5000 50  0001 C CNN
F 3 "~" H 1950 5000 50  0001 C CNN
	1    1950 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5EE609DB
P 1550 5300
F 0 "#PWR0104" H 1550 5050 50  0001 C CNN
F 1 "GND" H 1555 5127 50  0000 C CNN
F 2 "" H 1550 5300 50  0001 C CNN
F 3 "" H 1550 5300 50  0001 C CNN
	1    1550 5300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0105
U 1 1 5EE62F33
P 4800 850
F 0 "#PWR0105" H 4800 700 50  0001 C CNN
F 1 "+3.3V" H 4815 1023 50  0000 C CNN
F 2 "" H 4800 850 50  0001 C CNN
F 3 "" H 4800 850 50  0001 C CNN
	1    4800 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 850  4800 950 
Wire Wire Line
	4800 950  5050 950 
Connection ~ 5050 950 
$Comp
L Connector:Screw_Terminal_01x04 J4
U 1 1 5EE6580E
P 10000 2800
F 0 "J4" H 10080 2792 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 10080 2701 50  0000 L CNN
F 2 "TerminalBlock_TE-Connectivity:TerminalBlock_TE_282834-4_1x04_P2.54mm_Horizontal" H 10000 2800 50  0001 C CNN
F 3 "~" H 10000 2800 50  0001 C CNN
	1    10000 2800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x12 J1
U 1 1 5EE68680
P 1400 1500
F 0 "J1" H 1318 2217 50  0000 C CNN
F 1 "Conn_01x12" H 1450 2150 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 1400 1500 50  0001 C CNN
F 3 "~" H 1400 1500 50  0001 C CNN
	1    1400 1500
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x12 J2
U 1 1 5EE6963D
P 2800 1500
F 0 "J2" H 2750 2200 50  0000 L CNN
F 1 "Conn_01x12" H 2550 2150 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 2800 1500 50  0001 C CNN
F 3 "~" H 2800 1500 50  0001 C CNN
	1    2800 1500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J3
U 1 1 5EE6A8E5
P 2450 4900
F 0 "J3" H 2368 5317 50  0000 C CNN
F 1 "Conn_01x06" H 2368 5226 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 2450 4900 50  0001 C CNN
F 3 "~" H 2450 4900 50  0001 C CNN
	1    2450 4900
	1    0    0    -1  
$EndComp
Text GLabel 1700 2000 2    50   Input ~ 0
OUT3
Text GLabel 2500 1200 0    50   Input ~ 0
MOSI
Text GLabel 2500 1300 0    50   Input ~ 0
MISO
Text GLabel 2500 1400 0    50   Input ~ 0
SCK
Text GLabel 2500 1100 0    50   Input ~ 0
CS
Text GLabel 2500 1000 0    50   Input ~ 0
CE
Wire Wire Line
	2500 1000 2600 1000
Wire Wire Line
	2500 1100 2600 1100
Wire Wire Line
	2500 1200 2600 1200
Wire Wire Line
	2500 1300 2600 1300
Wire Wire Line
	2500 1400 2600 1400
$Comp
L power:+3.3V #PWR0106
U 1 1 5EE7F05A
P 1700 1100
F 0 "#PWR0106" H 1700 950 50  0001 C CNN
F 1 "+3.3V" V 1715 1228 50  0000 L CNN
F 2 "" H 1700 1100 50  0001 C CNN
F 3 "" H 1700 1100 50  0001 C CNN
	1    1700 1100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5EE805A8
P 1700 1200
F 0 "#PWR0107" H 1700 950 50  0001 C CNN
F 1 "GND" V 1705 1072 50  0000 R CNN
F 2 "" H 1700 1200 50  0001 C CNN
F 3 "" H 1700 1200 50  0001 C CNN
	1    1700 1200
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5EE859F6
P 1700 1000
F 0 "#PWR0108" H 1700 850 50  0001 C CNN
F 1 "+5V" V 1715 1128 50  0000 L CNN
F 2 "" H 1700 1000 50  0001 C CNN
F 3 "" H 1700 1000 50  0001 C CNN
	1    1700 1000
	0    1    1    0   
$EndComp
Text GLabel 6700 2050 0    50   Input ~ 0
IRQ
Text GLabel 3000 5700 0    50   Input ~ 0
OUT2
Text GLabel 5900 4500 0    50   Input ~ 0
OUT3
Wire Wire Line
	1700 1900 1600 1900
$Comp
L Transistor_BJT:2N3904 Q3
U 1 1 5EE884FA
P 3700 3800
F 0 "Q3" H 3890 3846 50  0000 L CNN
F 1 "2N3904" H 3890 3755 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3900 3725 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 3700 3800 50  0001 L CNN
F 4 "C18536" H 3700 3800 50  0001 C CNN "LCSC"
	1    3700 3800
	1    0    0    -1  
$EndComp
Text GLabel 1700 1300 2    50   Input ~ 0
OUT1
Wire Wire Line
	1700 1300 1600 1300
Text GLabel 1700 2100 2    50   Input ~ 0
OUT2
Text GLabel 1700 1900 2    50   Input ~ 0
RADIO_PWR
Wire Wire Line
	1700 2000 1600 2000
Wire Wire Line
	1700 2100 1600 2100
Text Notes 650  1300 0    50   ~ 0
PA0: TIM2_CH1
Text Notes 650  2000 0    50   ~ 0
PA1: TIM2_CH2
Text Notes 650  2100 0    50   ~ 0
PA2: TIM2_CH3
Text Notes 650  1900 0    50   ~ 0
PB0: GPIO_OUT
Text Notes 2950 1000 0    50   ~ 0
PB7: GPIOx
Text Notes 2950 1100 0    50   ~ 0
PB6: GPIOx
Wire Wire Line
	1600 1000 1700 1000
Wire Wire Line
	1600 1100 1700 1100
Wire Wire Line
	1600 1200 1700 1200
Text Notes 2950 1400 0    50   ~ 0
PB3: SPI3_SCK
Text Notes 2950 1300 0    50   ~ 0
PB4: SPI3_MISO
Text Notes 2950 1200 0    50   ~ 0
PB5: SPI3_MOSI
Text GLabel 2500 1900 0    50   Input ~ 0
IRQ
Wire Wire Line
	2500 1900 2600 1900
Wire Wire Line
	6700 2050 6800 2050
Text GLabel 3000 3800 0    50   Input ~ 0
OUT1
Text Notes 2950 1900 0    50   ~ 0
PA15: GPIO_IN
$Comp
L Device:R_US R5
U 1 1 5EE9B50F
P 3800 3250
F 0 "R5" H 3732 3204 50  0000 R CNN
F 1 "10k" H 3732 3295 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3840 3240 50  0001 C CNN
F 3 "~" H 3800 3250 50  0001 C CNN
	1    3800 3250
	1    0    0    1   
$EndComp
Wire Wire Line
	4500 3000 4500 2900
Wire Wire Line
	4500 2900 4250 2900
Wire Wire Line
	4250 2900 4250 3500
Wire Wire Line
	4250 4100 4500 4100
Wire Wire Line
	4500 4100 4500 4000
Wire Wire Line
	3800 3400 3800 3500
Wire Wire Line
	3800 3500 4250 3500
Connection ~ 3800 3500
Wire Wire Line
	3800 3500 3800 3600
Connection ~ 4250 3500
Wire Wire Line
	4250 3500 4250 4100
$Comp
L power:+5V #PWR0109
U 1 1 5EEA0E3E
P 3800 3000
F 0 "#PWR0109" H 3800 2850 50  0001 C CNN
F 1 "+5V" H 3815 3173 50  0000 C CNN
F 2 "" H 3800 3000 50  0001 C CNN
F 3 "" H 3800 3000 50  0001 C CNN
	1    3800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3000 3800 3100
$Comp
L power:GND #PWR0110
U 1 1 5EEA2F1F
P 4600 4300
F 0 "#PWR0110" H 4600 4050 50  0001 C CNN
F 1 "GND" H 4605 4127 50  0000 C CNN
F 2 "" H 4600 4300 50  0001 C CNN
F 3 "" H 4600 4300 50  0001 C CNN
	1    4600 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4000 3800 4200
Wire Wire Line
	3800 4200 4600 4200
Wire Wire Line
	4600 4200 4600 4000
Wire Wire Line
	4600 4300 4600 4200
Connection ~ 4600 4200
Wire Wire Line
	4800 4000 4800 4200
Wire Wire Line
	4800 4200 4600 4200
$Comp
L power:GND #PWR0111
U 1 1 5EEA81A9
P 4700 2900
F 0 "#PWR0111" H 4700 2650 50  0001 C CNN
F 1 "GND" H 4705 2727 50  0000 C CNN
F 2 "" H 4700 2900 50  0001 C CNN
F 3 "" H 4700 2900 50  0001 C CNN
	1    4700 2900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 3000 4600 2900
Wire Wire Line
	4600 2900 4700 2900
Wire Wire Line
	4800 3000 4800 2900
Wire Wire Line
	4800 2900 4700 2900
Connection ~ 4700 2900
$Comp
L Device:R_US R3
U 1 1 5EEABE82
P 3250 3800
F 0 "R3" V 3045 3800 50  0000 C CNN
F 1 "1k" V 3136 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3290 3790 50  0001 C CNN
F 3 "~" H 3250 3800 50  0001 C CNN
	1    3250 3800
	0    -1   1    0   
$EndComp
Wire Wire Line
	4900 3000 4900 2900
Wire Wire Line
	4900 2900 5450 2900
Wire Wire Line
	5450 2900 5450 3500
Wire Wire Line
	5450 4100 4900 4100
Wire Wire Line
	4900 4100 4900 4000
Text GLabel 5500 3500 2    50   Input ~ 0
DRV0
Wire Wire Line
	3400 3800 3500 3800
Text GLabel 9700 2900 0    50   Input ~ 0
DRV1
Text GLabel 9700 3000 0    50   Input ~ 0
DRV2
Text GLabel 9700 2700 0    50   Input ~ 0
VCCO
Text GLabel 9700 2800 0    50   Input ~ 0
DRV0
Wire Wire Line
	9700 2700 9800 2700
Wire Wire Line
	9700 2800 9800 2800
Wire Wire Line
	9700 2900 9800 2900
Wire Wire Line
	9700 3000 9800 3000
$Comp
L fs8205a:FS8205A U2
U 1 1 5EEC3548
P 4700 5300
F 0 "U2" H 5028 5253 60  0000 L CNN
F 1 "FS8205A" H 5028 5147 60  0000 L CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 5650 5550 60  0001 C CNN
F 3 "" H 5650 5550 60  0001 C CNN
F 4 "C16052" V 4700 5300 50  0001 C CNN "LCSC"
	1    4700 5300
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3904 Q4
U 1 1 5EEC354F
P 3700 5700
F 0 "Q4" H 3890 5746 50  0000 L CNN
F 1 "2N3904" H 3890 5655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3900 5625 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 3700 5700 50  0001 L CNN
F 4 "C18536" H 3700 5700 50  0001 C CNN "LCSC"
	1    3700 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R6
U 1 1 5EEC3555
P 3800 5150
F 0 "R6" H 3732 5104 50  0000 R CNN
F 1 "10k" H 3732 5195 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3840 5140 50  0001 C CNN
F 3 "~" H 3800 5150 50  0001 C CNN
	1    3800 5150
	1    0    0    1   
$EndComp
Wire Wire Line
	4500 4900 4500 4800
Wire Wire Line
	4500 4800 4250 4800
Wire Wire Line
	4250 4800 4250 5400
Wire Wire Line
	4250 6000 4500 6000
Wire Wire Line
	4500 6000 4500 5900
Wire Wire Line
	3800 5300 3800 5400
Wire Wire Line
	3800 5400 4250 5400
Connection ~ 3800 5400
Wire Wire Line
	3800 5400 3800 5500
Connection ~ 4250 5400
Wire Wire Line
	4250 5400 4250 6000
$Comp
L power:+5V #PWR0112
U 1 1 5EEC3566
P 3800 4900
F 0 "#PWR0112" H 3800 4750 50  0001 C CNN
F 1 "+5V" H 3815 5073 50  0000 C CNN
F 2 "" H 3800 4900 50  0001 C CNN
F 3 "" H 3800 4900 50  0001 C CNN
	1    3800 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4900 3800 5000
$Comp
L power:GND #PWR0113
U 1 1 5EEC356D
P 4600 6200
F 0 "#PWR0113" H 4600 5950 50  0001 C CNN
F 1 "GND" H 4605 6027 50  0000 C CNN
F 2 "" H 4600 6200 50  0001 C CNN
F 3 "" H 4600 6200 50  0001 C CNN
	1    4600 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 5900 3800 6100
Wire Wire Line
	3800 6100 4600 6100
Wire Wire Line
	4600 6100 4600 5900
Wire Wire Line
	4600 6200 4600 6100
Connection ~ 4600 6100
Wire Wire Line
	4800 5900 4800 6100
Wire Wire Line
	4800 6100 4600 6100
$Comp
L power:GND #PWR0114
U 1 1 5EEC357A
P 4700 4800
F 0 "#PWR0114" H 4700 4550 50  0001 C CNN
F 1 "GND" H 4705 4627 50  0000 C CNN
F 2 "" H 4700 4800 50  0001 C CNN
F 3 "" H 4700 4800 50  0001 C CNN
	1    4700 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 4900 4600 4800
Wire Wire Line
	4600 4800 4700 4800
Wire Wire Line
	4800 4900 4800 4800
Wire Wire Line
	4800 4800 4700 4800
Connection ~ 4700 4800
$Comp
L Device:R_US R4
U 1 1 5EEC3585
P 3250 5700
F 0 "R4" V 3045 5700 50  0000 C CNN
F 1 "1k" V 3136 5700 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3290 5690 50  0001 C CNN
F 3 "~" H 3250 5700 50  0001 C CNN
	1    3250 5700
	0    -1   1    0   
$EndComp
Wire Wire Line
	4900 4900 4900 4800
Wire Wire Line
	4900 4800 5450 4800
Wire Wire Line
	5450 4800 5450 5400
Wire Wire Line
	5450 6000 4900 6000
Wire Wire Line
	4900 6000 4900 5900
Wire Wire Line
	3400 5700 3500 5700
$Comp
L fs8205a:FS8205A U3
U 1 1 5EEF5F90
P 7600 4100
F 0 "U3" H 7928 4053 60  0000 L CNN
F 1 "FS8205A" H 7928 3947 60  0000 L CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 8550 4350 60  0001 C CNN
F 3 "" H 8550 4350 60  0001 C CNN
F 4 "C16052" V 7600 4100 50  0001 C CNN "LCSC"
	1    7600 4100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3904 Q5
U 1 1 5EEF5F97
P 6600 4500
F 0 "Q5" H 6790 4546 50  0000 L CNN
F 1 "2N3904" H 6790 4455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6800 4425 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 6600 4500 50  0001 L CNN
F 4 "C18536" H 6600 4500 50  0001 C CNN "LCSC"
	1    6600 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R8
U 1 1 5EEF5F9D
P 6700 3950
F 0 "R8" H 6632 3904 50  0000 R CNN
F 1 "10k" H 6632 3995 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6740 3940 50  0001 C CNN
F 3 "~" H 6700 3950 50  0001 C CNN
	1    6700 3950
	1    0    0    1   
$EndComp
Wire Wire Line
	7400 3700 7400 3600
Wire Wire Line
	7400 3600 7150 3600
Wire Wire Line
	7150 3600 7150 4200
Wire Wire Line
	7150 4800 7400 4800
Wire Wire Line
	7400 4800 7400 4700
Wire Wire Line
	6700 4100 6700 4200
Wire Wire Line
	6700 4200 7150 4200
Connection ~ 6700 4200
Wire Wire Line
	6700 4200 6700 4300
Connection ~ 7150 4200
Wire Wire Line
	7150 4200 7150 4800
$Comp
L power:+5V #PWR0115
U 1 1 5EEF5FAE
P 6700 3700
F 0 "#PWR0115" H 6700 3550 50  0001 C CNN
F 1 "+5V" H 6715 3873 50  0000 C CNN
F 2 "" H 6700 3700 50  0001 C CNN
F 3 "" H 6700 3700 50  0001 C CNN
	1    6700 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3700 6700 3800
$Comp
L power:GND #PWR0116
U 1 1 5EEF5FB5
P 7500 5000
F 0 "#PWR0116" H 7500 4750 50  0001 C CNN
F 1 "GND" H 7505 4827 50  0000 C CNN
F 2 "" H 7500 5000 50  0001 C CNN
F 3 "" H 7500 5000 50  0001 C CNN
	1    7500 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 4700 6700 4900
Wire Wire Line
	6700 4900 7500 4900
Wire Wire Line
	7500 4900 7500 4700
Wire Wire Line
	7500 5000 7500 4900
Connection ~ 7500 4900
Wire Wire Line
	7700 4700 7700 4900
Wire Wire Line
	7700 4900 7500 4900
$Comp
L power:GND #PWR0117
U 1 1 5EEF5FC2
P 7600 3600
F 0 "#PWR0117" H 7600 3350 50  0001 C CNN
F 1 "GND" H 7605 3427 50  0000 C CNN
F 2 "" H 7600 3600 50  0001 C CNN
F 3 "" H 7600 3600 50  0001 C CNN
	1    7600 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	7500 3700 7500 3600
Wire Wire Line
	7500 3600 7600 3600
Wire Wire Line
	7700 3700 7700 3600
Wire Wire Line
	7700 3600 7600 3600
Connection ~ 7600 3600
$Comp
L Device:R_US R7
U 1 1 5EEF5FCD
P 6150 4500
F 0 "R7" V 5945 4500 50  0000 C CNN
F 1 "1k" V 6036 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6190 4490 50  0001 C CNN
F 3 "~" H 6150 4500 50  0001 C CNN
	1    6150 4500
	0    -1   1    0   
$EndComp
Wire Wire Line
	7800 3700 7800 3600
Wire Wire Line
	7800 3600 8350 3600
Wire Wire Line
	8350 3600 8350 4200
Wire Wire Line
	8350 4800 7800 4800
Wire Wire Line
	7800 4800 7800 4700
Wire Wire Line
	6300 4500 6400 4500
Wire Wire Line
	3000 3800 3100 3800
Wire Wire Line
	3000 5700 3100 5700
Wire Wire Line
	6000 4500 5900 4500
Text GLabel 5500 5400 2    50   Input ~ 0
DRV1
Text GLabel 8400 4200 2    50   Input ~ 0
DRV2
Wire Wire Line
	8400 4200 8350 4200
Connection ~ 8350 4200
Wire Wire Line
	8350 4200 8350 4800
Wire Wire Line
	5500 5400 5450 5400
Connection ~ 5450 5400
Wire Wire Line
	5450 5400 5450 6000
Wire Wire Line
	5450 3500 5500 3500
Connection ~ 5450 3500
Wire Wire Line
	5450 3500 5450 4100
$Comp
L power:+5V #PWR0118
U 1 1 5EF1D85C
P 9550 1000
F 0 "#PWR0118" H 9550 850 50  0001 C CNN
F 1 "+5V" H 9565 1173 50  0000 C CNN
F 2 "" H 9550 1000 50  0001 C CNN
F 3 "" H 9550 1000 50  0001 C CNN
	1    9550 1000
	1    0    0    -1  
$EndComp
Text GLabel 9350 1300 0    50   Input ~ 0
VCCO
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 5EF1E891
P 9550 1300
F 0 "JP1" V 9504 1368 50  0000 L CNN
F 1 "SolderJumper_3_Open" V 9595 1368 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P2.0mm_Open_TrianglePad1.0x1.5mm_NumberLabels" H 9550 1300 50  0001 C CNN
F 3 "~" H 9550 1300 50  0001 C CNN
	1    9550 1300
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5EF21204
P 9850 1650
F 0 "J5" H 9930 1642 50  0000 L CNN
F 1 "ExtVCC" H 9930 1551 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9850 1650 50  0001 C CNN
F 3 "~" H 9850 1650 50  0001 C CNN
	1    9850 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1650 9550 1650
Wire Wire Line
	9550 1650 9550 1500
Wire Wire Line
	9550 1100 9550 1000
Wire Wire Line
	9400 1300 9350 1300
$Comp
L power:GND #PWR0119
U 1 1 5EF321C9
P 9550 1800
F 0 "#PWR0119" H 9550 1550 50  0001 C CNN
F 1 "GND" H 9555 1627 50  0000 C CNN
F 2 "" H 9550 1800 50  0001 C CNN
F 3 "" H 9550 1800 50  0001 C CNN
	1    9550 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 1800 9550 1750
Wire Wire Line
	9550 1750 9650 1750
Wire Wire Line
	1550 5300 1550 5200
Wire Wire Line
	1550 4700 1650 4700
Wire Wire Line
	1650 4800 1550 4800
Connection ~ 1550 4800
Wire Wire Line
	1550 4800 1550 4700
Wire Wire Line
	1650 4900 1550 4900
Connection ~ 1550 4900
Wire Wire Line
	1550 4900 1550 4800
Wire Wire Line
	1650 5000 1550 5000
Connection ~ 1550 5000
Wire Wire Line
	1550 5000 1550 4900
Wire Wire Line
	1650 5100 1550 5100
Connection ~ 1550 5100
Wire Wire Line
	1550 5100 1550 5000
Wire Wire Line
	1650 5200 1550 5200
Connection ~ 1550 5200
Wire Wire Line
	1550 5200 1550 5100
$EndSCHEMATC
