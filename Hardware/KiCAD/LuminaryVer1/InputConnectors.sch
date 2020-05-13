EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2650 2400 2    50   Output ~ 0
Batt_V+
Text HLabel 2650 2500 2    50   Output ~ 0
Batt_V-
$Comp
L Connector:Conn_01x02_Female J10
U 1 1 5E6317AF
P 2350 2400
F 0 "J10" H 2242 2585 50  0000 C CNN
F 1 "ExtBattPwr" H 2242 2494 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2350 2400 50  0001 C CNN
F 3 "~" H 2350 2400 50  0001 C CNN
	1    2350 2400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2550 2400 2650 2400
Wire Wire Line
	2550 2500 2650 2500
Text HLabel 3050 3200 2    50   BiDi ~ 0
SWDIO_TMS
Text HLabel 3050 3300 2    50   BiDi ~ 0
SWCLK_TCLK
Text HLabel 3050 3400 2    50   BiDi ~ 0
SWO_TDO
Text HLabel 3050 3600 2    50   BiDi ~ 0
nRESET
Text HLabel 3050 3500 2    50   BiDi ~ 0
NC_TDI
Text HLabel 6150 2150 2    50   BiDi ~ 0
GPIO_INPUT_0
Text HLabel 6150 2700 2    50   BiDi ~ 0
GPIO_INPUT_1
Text HLabel 6150 3200 2    50   BiDi ~ 0
GPIO_INPUT_2
Text HLabel 6150 3700 2    50   BiDi ~ 0
GPIO_INPUT_3
Text HLabel 6150 4150 2    50   BiDi ~ 0
GPIO_INPUT_4
Text HLabel 6150 4700 2    50   BiDi ~ 0
GPIO_INPUT_5
$Comp
L 74xx:74HC14 U1
U 1 1 5E69C7F1
P 5750 3200
F 0 "U1" H 5750 3517 50  0000 C CNN
F 1 "74HC14" H 5750 3426 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5750 3200 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 5750 3200 50  0001 C CNN
	1    5750 3200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U1
U 2 1 5E69D0A2
P 5750 2700
F 0 "U1" H 5750 3017 50  0000 C CNN
F 1 "74HC14" H 5750 2926 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5750 2700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 5750 2700 50  0001 C CNN
	2    5750 2700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U1
U 3 1 5E69E21D
P 5750 2150
F 0 "U1" H 5750 2467 50  0000 C CNN
F 1 "74HC14" H 5750 2376 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5750 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 5750 2150 50  0001 C CNN
	3    5750 2150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U1
U 4 1 5E69F536
P 5750 4700
F 0 "U1" H 5750 5017 50  0000 C CNN
F 1 "74HC14" H 5750 4926 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5750 4700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 5750 4700 50  0001 C CNN
	4    5750 4700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U1
U 5 1 5E6A0716
P 5750 4150
F 0 "U1" H 5750 4467 50  0000 C CNN
F 1 "74HC14" H 5750 4376 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5750 4150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 5750 4150 50  0001 C CNN
	5    5750 4150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U1
U 6 1 5E6A15AB
P 5750 3700
F 0 "U1" H 5750 4017 50  0000 C CNN
F 1 "74HC14" H 5750 3926 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5750 3700 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 5750 3700 50  0001 C CNN
	6    5750 3700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC14 U1
U 7 1 5E6A1DE1
P 7700 3300
F 0 "U1" H 7930 3346 50  0000 L CNN
F 1 "74HC14" H 7930 3255 50  0000 L CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 7700 3300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC14" H 7700 3300 50  0001 C CNN
	7    7700 3300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J2
U 1 1 5E6A34D5
P 4050 3350
F 0 "J2" H 4050 3750 50  0000 C CNN
F 1 "GPIOInput" H 4050 3650 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4050 3350 50  0001 C CNN
F 3 "~" H 4050 3350 50  0001 C CNN
	1    4050 3350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4900 3150 5200 3150
Wire Wire Line
	5200 3150 5200 2150
Wire Wire Line
	5200 2150 5450 2150
Wire Wire Line
	5250 3250 5250 2700
Wire Wire Line
	5250 2700 5450 2700
Wire Wire Line
	5300 3350 5300 3200
Wire Wire Line
	5300 3200 5450 3200
Wire Wire Line
	5300 3450 5300 3700
Wire Wire Line
	5300 3700 5450 3700
Wire Wire Line
	5250 3550 5250 4150
Wire Wire Line
	5250 4150 5450 4150
Wire Wire Line
	5200 3650 5200 4700
Wire Wire Line
	5200 4700 5450 4700
Wire Wire Line
	6050 4700 6150 4700
Wire Wire Line
	6050 4150 6150 4150
Wire Wire Line
	6150 3700 6050 3700
Wire Wire Line
	6050 3200 6150 3200
Wire Wire Line
	6050 2700 6150 2700
Wire Wire Line
	6050 2150 6150 2150
Text HLabel 8200 2750 2    50   BiDi ~ 0
3.3V+
Text HLabel 7750 3900 2    50   BiDi ~ 0
Gnd
$Comp
L power:GND #PWR02
U 1 1 5E6A8EF7
P 7700 3950
F 0 "#PWR02" H 7700 3700 50  0001 C CNN
F 1 "GND" H 7705 3777 50  0000 C CNN
F 2 "" H 7700 3950 50  0001 C CNN
F 3 "" H 7700 3950 50  0001 C CNN
	1    7700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 3950 7700 3900
Wire Wire Line
	7700 3900 7750 3900
Wire Wire Line
	7800 2750 7700 2750
Wire Wire Line
	7700 2750 7700 2800
Wire Wire Line
	7700 3800 7700 3900
Connection ~ 7700 3900
Text HLabel 3100 4400 2    50   Output ~ 0
Ext_V+
Text HLabel 3100 5100 2    50   Output ~ 0
Ext_V-
$Comp
L Device:C_Small C5
U 1 1 5E79D1C1
P 7300 3300
F 0 "C5" H 7209 3254 50  0000 R CNN
F 1 "100nF" H 7209 3345 50  0000 R CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7300 3300 50  0001 C CNN
F 3 "~" H 7300 3300 50  0001 C CNN
	1    7300 3300
	1    0    0    1   
$EndComp
Wire Wire Line
	7300 3200 7300 2750
Wire Wire Line
	7300 2750 7700 2750
Connection ~ 7700 2750
Wire Wire Line
	7300 3400 7300 3900
Wire Wire Line
	7300 3900 7700 3900
$Comp
L Device:R_US R_PWR_1
U 1 1 5E7A034A
P 7950 2750
F 0 "R_PWR_1" V 7745 2750 50  0000 C CNN
F 1 "0" V 7836 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7990 2740 50  0001 C CNN
F 3 "~" H 7950 2750 50  0001 C CNN
	1    7950 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	8200 2750 8100 2750
$Comp
L Connector:USB_B_Micro J12
U 1 1 5E7EE1F3
P 2700 4600
F 0 "J12" H 2757 5067 50  0000 C CNN
F 1 "USB_B_Micro" H 2757 4976 50  0000 C CNN
F 2 "USB:Amphenol-MicroB" H 2850 4550 50  0001 C CNN
F 3 "~" H 2850 4550 50  0001 C CNN
	1    2700 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5E7F0A7B
P 2600 5150
F 0 "#PWR016" H 2600 4900 50  0001 C CNN
F 1 "GND" H 2605 4977 50  0000 C CNN
F 2 "" H 2600 5150 50  0001 C CNN
F 3 "" H 2600 5150 50  0001 C CNN
	1    2600 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5000 2600 5100
Wire Wire Line
	2700 5000 2700 5100
Wire Wire Line
	2700 5100 2600 5100
Connection ~ 2600 5100
Wire Wire Line
	2600 5100 2600 5150
Wire Wire Line
	3100 5100 2700 5100
Connection ~ 2700 5100
Wire Wire Line
	3100 4400 3000 4400
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J1
U 1 1 5E7F6637
P 2650 3400
F 0 "J1" H 2700 3817 50  0000 C CNN
F 1 "JTAG" H 2700 3726 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 2650 3400 50  0001 C CNN
F 3 "~" H 2650 3400 50  0001 C CNN
	1    2650 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5E7F83C5
P 2350 3700
F 0 "#PWR015" H 2350 3450 50  0001 C CNN
F 1 "GND" H 2355 3527 50  0000 C CNN
F 2 "" H 2350 3700 50  0001 C CNN
F 3 "" H 2350 3700 50  0001 C CNN
	1    2350 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3300 2350 3300
Wire Wire Line
	2350 3300 2350 3400
Wire Wire Line
	2450 3400 2350 3400
Connection ~ 2350 3400
Wire Wire Line
	2350 3400 2350 3600
Wire Wire Line
	2450 3600 2350 3600
Connection ~ 2350 3600
Wire Wire Line
	2350 3600 2350 3700
Text HLabel 2250 3200 0    50   BiDi ~ 0
3.3V+
Wire Wire Line
	2250 3200 2450 3200
Wire Wire Line
	2950 3200 3050 3200
Wire Wire Line
	2950 3300 3050 3300
Wire Wire Line
	2950 3400 3050 3400
Wire Wire Line
	2950 3500 3050 3500
Wire Wire Line
	2950 3600 3050 3600
Text Notes 4900 1750 0    50   ~ 0
Schmitt triggered inputs to provide clean edges
$Comp
L Device:R_US R25
U 1 1 5EB8BB66
P 4900 2250
F 0 "R25" H 4968 2296 50  0000 L CNN
F 1 "50k" H 4968 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4940 2240 50  0001 C CNN
F 3 "~" H 4900 2250 50  0001 C CNN
	1    4900 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R23
U 1 1 5EB8CACB
P 4650 2250
F 0 "R23" H 4718 2296 50  0000 L CNN
F 1 "50k" H 4718 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4690 2240 50  0001 C CNN
F 3 "~" H 4650 2250 50  0001 C CNN
	1    4650 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R21
U 1 1 5EB8D03C
P 4400 2250
F 0 "R21" H 4468 2296 50  0000 L CNN
F 1 "50k" H 4468 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4440 2240 50  0001 C CNN
F 3 "~" H 4400 2250 50  0001 C CNN
	1    4400 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R22
U 1 1 5EB8D3BF
P 4550 1850
F 0 "R22" H 4618 1896 50  0000 L CNN
F 1 "50k" H 4618 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4590 1840 50  0001 C CNN
F 3 "~" H 4550 1850 50  0001 C CNN
	1    4550 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R24
U 1 1 5EB8DB7F
P 4800 1850
F 0 "R24" H 4868 1896 50  0000 L CNN
F 1 "50k" H 4868 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4840 1840 50  0001 C CNN
F 3 "~" H 4800 1850 50  0001 C CNN
	1    4800 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R20
U 1 1 5EB8E180
P 4300 1850
F 0 "R20" H 4368 1896 50  0000 L CNN
F 1 "50k" H 4368 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4340 1840 50  0001 C CNN
F 3 "~" H 4300 1850 50  0001 C CNN
	1    4300 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2100 4650 1600
Wire Wire Line
	4650 1600 4800 1600
Wire Wire Line
	7700 1600 7700 2750
Wire Wire Line
	4800 1700 4800 1600
Connection ~ 4800 1600
Wire Wire Line
	4800 1600 4900 1600
Wire Wire Line
	4550 1700 4550 1600
Wire Wire Line
	4550 1600 4650 1600
Connection ~ 4650 1600
Wire Wire Line
	4300 1700 4300 1600
Wire Wire Line
	4300 1600 4400 1600
Connection ~ 4550 1600
Wire Wire Line
	4400 2100 4400 1600
Connection ~ 4400 1600
Wire Wire Line
	4400 1600 4550 1600
Wire Wire Line
	4900 2100 4900 1600
Connection ~ 4900 1600
Wire Wire Line
	4900 1600 7700 1600
Wire Wire Line
	4900 2400 4900 3150
Wire Wire Line
	4250 3150 4900 3150
Connection ~ 4900 3150
Wire Wire Line
	4250 3250 4800 3250
Wire Wire Line
	4250 3350 4650 3350
Wire Wire Line
	4250 3450 4550 3450
Wire Wire Line
	4250 3550 4400 3550
Wire Wire Line
	4250 3650 4300 3650
Wire Wire Line
	4800 2000 4800 3250
Connection ~ 4800 3250
Wire Wire Line
	4800 3250 5250 3250
Wire Wire Line
	4650 2400 4650 3350
Connection ~ 4650 3350
Wire Wire Line
	4650 3350 5300 3350
Wire Wire Line
	4550 2000 4550 3450
Connection ~ 4550 3450
Wire Wire Line
	4550 3450 5300 3450
Wire Wire Line
	4400 2400 4400 3550
Connection ~ 4400 3550
Wire Wire Line
	4400 3550 5250 3550
Wire Wire Line
	4300 2000 4300 3650
Connection ~ 4300 3650
Wire Wire Line
	4300 3650 5200 3650
$EndSCHEMATC
