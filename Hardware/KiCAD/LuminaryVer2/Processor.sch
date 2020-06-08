EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
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
L MCU_ST_STM32L4:STM32L432KBUx U2
U 1 1 5E63AFC1
P 6250 2550
F 0 "U2" H 6600 3500 50  0000 C CNN
F 1 "STM32L432KBUx" H 6700 3400 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.45x3.45mm" H 5850 1650 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00257205.pdf" H 6250 2550 50  0001 C CNN
F 4 "C94784" H 6250 2550 50  0001 C CNN "LCSC"
F 5 "STM32L432KBU6" H 6250 2550 50  0001 C CNN "PartNumber"
	1    6250 2550
	1    0    0    -1  
$EndComp
Text HLabel 6950 3150 2    50   BiDi ~ 0
SWDIO
Text HLabel 6950 3250 2    50   BiDi ~ 0
SWCLK
Text HLabel 5000 1100 0    50   UnSpc ~ 0
VCC
Text HLabel 4400 1850 0    50   BiDi ~ 0
nRST
Wire Wire Line
	6350 1650 6350 1550
Wire Wire Line
	6350 1550 6250 1550
Connection ~ 6250 1550
Wire Wire Line
	6250 1550 6250 1650
Wire Wire Line
	6150 1650 6150 1550
Wire Wire Line
	6150 1550 6250 1550
$Comp
L Device:C_Small C3
U 1 1 5E64531B
P 5950 1400
F 0 "C3" V 5721 1400 50  0000 C CNN
F 1 "100nF" V 5812 1400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5950 1400 50  0001 C CNN
F 3 "~" H 5950 1400 50  0001 C CNN
F 4 "C1525" H 5950 1400 50  0001 C CNN "LCSC"
F 5 "CL05B104KO5NNNC" H 5950 1400 50  0001 C CNN "PartNumber"
	1    5950 1400
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5E6477BB
P 6550 1400
F 0 "C4" V 6321 1400 50  0000 C CNN
F 1 "100nF" V 6412 1400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6550 1400 50  0001 C CNN
F 3 "~" H 6550 1400 50  0001 C CNN
F 4 "C1525" H 6550 1400 50  0001 C CNN "LCSC"
F 5 "CL05B104KO5NNNC" H 6550 1400 50  0001 C CNN "PartNumber"
	1    6550 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	6450 1400 6250 1400
Connection ~ 6250 1400
Wire Wire Line
	6250 1400 6250 1550
Wire Wire Line
	6050 1400 6250 1400
$Comp
L power:GND #PWR06
U 1 1 5E649A0F
P 5800 1400
F 0 "#PWR06" H 5800 1150 50  0001 C CNN
F 1 "GND" V 5805 1272 50  0000 R CNN
F 2 "" H 5800 1400 50  0001 C CNN
F 3 "" H 5800 1400 50  0001 C CNN
	1    5800 1400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5E64A557
P 6700 1400
F 0 "#PWR08" H 6700 1150 50  0001 C CNN
F 1 "GND" V 6705 1272 50  0000 R CNN
F 2 "" H 6700 1400 50  0001 C CNN
F 3 "" H 6700 1400 50  0001 C CNN
	1    6700 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6650 1400 6700 1400
Wire Wire Line
	5800 1400 5850 1400
Text HLabel 6250 3750 3    50   UnSpc ~ 0
Gnd
Wire Wire Line
	6250 3550 6250 3650
Wire Wire Line
	6150 3550 6150 3650
Wire Wire Line
	6150 3650 6250 3650
Connection ~ 6250 3650
Wire Wire Line
	6250 3650 6250 3750
Wire Wire Line
	6350 3550 6350 3650
Wire Wire Line
	6350 3650 6250 3650
$Comp
L power:GND #PWR07
U 1 1 5E64E3B1
P 5950 3700
F 0 "#PWR07" H 5950 3450 50  0001 C CNN
F 1 "GND" H 5955 3527 50  0000 C CNN
F 2 "" H 5950 3700 50  0001 C CNN
F 3 "" H 5950 3700 50  0001 C CNN
	1    5950 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3700 5950 3650
Wire Wire Line
	5950 3650 6150 3650
Connection ~ 6150 3650
$Comp
L Device:R_US R3
U 1 1 5E64F79D
P 5400 2250
F 0 "R3" V 5195 2250 50  0000 C CNN
F 1 "10k" V 5286 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5440 2240 50  0001 C CNN
F 3 "~" H 5400 2250 50  0001 C CNN
F 4 "C25744" H 5400 2250 50  0001 C CNN "LCSC"
F 5 "RTT02103JTH" H 5400 2250 50  0001 C CNN "PartNumber"
	1    5400 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5E651078
P 5000 2450
F 0 "#PWR05" H 5000 2200 50  0001 C CNN
F 1 "GND" V 5005 2322 50  0000 R CNN
F 2 "" H 5000 2450 50  0001 C CNN
F 3 "" H 5000 2450 50  0001 C CNN
	1    5000 2450
	1    0    0    -1  
$EndComp
Text HLabel 5650 3250 0    50   BiDi ~ 0
I2C_1_SCL
Text HLabel 5650 3350 0    50   BiDi ~ 0
I2C_1_SDA
Text HLabel 5650 3150 0    50   BiDi ~ 0
SPI_3_MOSI
Text HLabel 5650 3050 0    50   BiDi ~ 0
SPI_3_MISO
Text HLabel 5650 2950 0    50   BiDi ~ 0
SPI_3_SCK
Text HLabel 6950 1950 2    50   BiDi ~ 0
GPIO_0
Text HLabel 6950 2050 2    50   BiDi ~ 0
GPIO_1
Wire Wire Line
	6950 3350 6850 3350
Text HLabel 6950 3350 2    50   BiDi ~ 0
GPIO_3
Text HLabel 6950 3050 2    50   BiDi ~ 0
CAN_1_TX
Text HLabel 6950 2950 2    50   BiDi ~ 0
CAN_1_RX
Text HLabel 6950 2750 2    50   BiDi ~ 0
RS232_1_TX
Text HLabel 6950 2850 2    50   BiDi ~ 0
RS232_1_RX
Text HLabel 5600 2750 0    50   BiDi ~ 0
GPIO_2
Wire Wire Line
	6750 2950 6950 2950
Wire Wire Line
	6950 3050 6750 3050
Text HLabel 6950 2550 2    50   BiDi ~ 0
SPI_1_MOSI
Text HLabel 6950 2450 2    50   BiDi ~ 0
SPI_1_MISO
Text HLabel 6950 2350 2    50   BiDi ~ 0
SPI_1_SCK
Text HLabel 6950 2250 2    50   BiDi ~ 0
ADC_2
Text HLabel 6950 2150 2    50   BiDi ~ 0
ADC_1
Text HLabel 6950 1850 2    50   BiDi ~ 0
ADC_0
Text HLabel 6950 2650 2    50   BiDi ~ 0
GPIO_4
Text HLabel 5600 2850 0    50   BiDi ~ 0
GPIO_5
Wire Wire Line
	6750 3150 6950 3150
Wire Wire Line
	6750 3250 6950 3250
Wire Wire Line
	6750 2850 6950 2850
Wire Wire Line
	6750 2750 6950 2750
Wire Wire Line
	6750 2650 6850 2650
Wire Wire Line
	6950 2550 6750 2550
Wire Wire Line
	6750 2450 6950 2450
Wire Wire Line
	6950 2350 6750 2350
Wire Wire Line
	6750 2250 6950 2250
Wire Wire Line
	6950 2150 6750 2150
Wire Wire Line
	6750 2050 6850 2050
Wire Wire Line
	6950 1950 6850 1950
Wire Wire Line
	6750 1850 6950 1850
Wire Wire Line
	5650 2950 5750 2950
Wire Wire Line
	5650 3050 5750 3050
Wire Wire Line
	5650 3150 5750 3150
Wire Wire Line
	5650 3250 5750 3250
Wire Wire Line
	5650 3350 5750 3350
Text HLabel 7950 1700 2    50   BiDi ~ 0
GPIO_IN_0
Text HLabel 7950 2000 2    50   BiDi ~ 0
GPIO_IN_1
Text HLabel 4400 2800 0    50   BiDi ~ 0
GPIO_IN_2
Text HLabel 7950 3300 2    50   BiDi ~ 0
GPIO_IN_3
Text HLabel 7950 2600 2    50   BiDi ~ 0
GPIO_IN_4
Text HLabel 4400 3150 0    50   BiDi ~ 0
GPIO_IN_5
Wire Wire Line
	6850 1900 6850 1950
Connection ~ 6850 1950
Wire Wire Line
	6850 1950 6750 1950
Wire Wire Line
	7550 2000 6850 2000
Wire Wire Line
	6850 2000 6850 2050
Connection ~ 6850 2050
Wire Wire Line
	6850 2050 6950 2050
Wire Wire Line
	7550 2600 6850 2600
Wire Wire Line
	6850 2600 6850 2650
Connection ~ 6850 2650
Wire Wire Line
	6850 2650 6950 2650
Wire Wire Line
	7550 3300 6850 3300
Wire Wire Line
	6850 3300 6850 3350
Connection ~ 6850 3350
Wire Wire Line
	6850 3350 6750 3350
Wire Wire Line
	5700 2800 5700 2750
Connection ~ 5700 2750
Wire Wire Line
	5700 2750 5750 2750
Wire Wire Line
	5700 2900 5700 2850
Connection ~ 5700 2850
Wire Wire Line
	5700 2850 5750 2850
$Comp
L Device:R_US R1
U 1 1 5E67EEA7
P 7700 1700
F 0 "R1" V 7905 1700 50  0000 C CNN
F 1 "47k" V 7814 1700 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7740 1690 50  0001 C CNN
F 3 "~" H 7700 1700 50  0001 C CNN
F 4 "C25792" H 7700 1700 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 7700 1700 50  0001 C CNN "PartNumber"
	1    7700 1700
	0    1    -1   0   
$EndComp
$Comp
L Device:R_US R2
U 1 1 5E67F864
P 7700 2000
F 0 "R2" V 7495 2000 50  0000 C CNN
F 1 "47k" V 7586 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7740 1990 50  0001 C CNN
F 3 "~" H 7700 2000 50  0001 C CNN
F 4 "C25792" H 7700 2000 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 7700 2000 50  0001 C CNN "PartNumber"
	1    7700 2000
	0    -1   1    0   
$EndComp
Wire Wire Line
	7950 1700 7850 1700
Wire Wire Line
	7950 2000 7850 2000
$Comp
L Device:R_US R6
U 1 1 5E68A214
P 4650 2800
F 0 "R6" V 4855 2800 50  0000 C CNN
F 1 "47k" V 4764 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4690 2790 50  0001 C CNN
F 3 "~" H 4650 2800 50  0001 C CNN
F 4 "C25792" H 4650 2800 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 4650 2800 50  0001 C CNN "PartNumber"
	1    4650 2800
	0    1    -1   0   
$EndComp
$Comp
L Device:R_US R7
U 1 1 5E68B29C
P 7700 3300
F 0 "R7" V 7905 3300 50  0000 C CNN
F 1 "47k" V 7814 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7740 3290 50  0001 C CNN
F 3 "~" H 7700 3300 50  0001 C CNN
F 4 "C25792" H 7700 3300 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 7700 3300 50  0001 C CNN "PartNumber"
	1    7700 3300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R4
U 1 1 5E68B831
P 7700 2600
F 0 "R4" V 7905 2600 50  0000 C CNN
F 1 "47k" V 7814 2600 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7740 2590 50  0001 C CNN
F 3 "~" H 7700 2600 50  0001 C CNN
F 4 "C25792" H 7700 2600 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 7700 2600 50  0001 C CNN "PartNumber"
	1    7700 2600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R5
U 1 1 5E68CD5A
P 4650 3150
F 0 "R5" V 4855 3150 50  0000 C CNN
F 1 "47k" V 4764 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4690 3140 50  0001 C CNN
F 3 "~" H 4650 3150 50  0001 C CNN
F 4 "C25792" H 4650 3150 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 4650 3150 50  0001 C CNN "PartNumber"
	1    4650 3150
	0    1    -1   0   
$EndComp
Wire Wire Line
	7550 1700 7350 1700
Wire Wire Line
	7350 1700 7350 1900
Wire Wire Line
	7350 1900 6850 1900
Wire Wire Line
	7850 2600 7950 2600
Wire Wire Line
	4500 3150 4400 3150
Wire Wire Line
	4500 2800 4400 2800
Wire Wire Line
	7850 3300 7950 3300
$Comp
L Device:R_US R11
U 1 1 5E779034
P 5300 1500
F 0 "R11" H 5232 1454 50  0000 R CNN
F 1 "10k" H 5232 1545 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5340 1490 50  0001 C CNN
F 3 "~" H 5300 1500 50  0001 C CNN
F 4 "C25744" H 5300 1500 50  0001 C CNN "LCSC"
F 5 "RTT02103JTH" H 5300 1500 50  0001 C CNN "PartNumber"
	1    5300 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5300 1650 5300 1850
Wire Wire Line
	5300 1850 5750 1850
Wire Wire Line
	5300 1350 5300 1100
Wire Wire Line
	5300 1100 6250 1100
Wire Wire Line
	6250 1100 6250 1400
$Comp
L Switch:SW_Push SW1
U 1 1 5EB3D520
P 4550 2100
F 0 "SW1" V 4596 2052 50  0000 R CNN
F 1 "SW_Push" V 4505 2052 50  0000 R CNN
F 2 "button:LCSC_C255808_HYP_2x4x3.5mm_RightAngle" H 4550 2300 50  0001 C CNN
F 3 "~" H 4550 2300 50  0001 C CNN
F 4 "C255808" H 4550 2100 50  0001 C CNN "LCSC"
F 5 "1TS003B-1600-3500A-CT" H 4550 2100 50  0001 C CNN "PartNumber"
	1    4550 2100
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5EB402BC
P 5000 2050
F 0 "C1" V 4771 2050 50  0000 C CNN
F 1 "100nF" V 4862 2050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5000 2050 50  0001 C CNN
F 3 "~" H 5000 2050 50  0001 C CNN
F 4 "C1525" H 5000 2050 50  0001 C CNN "LCSC"
F 5 "CL05B104KO5NNNC" H 5000 2050 50  0001 C CNN "PartNumber"
	1    5000 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 2250 5750 2250
Wire Wire Line
	4400 1850 4550 1850
Connection ~ 5300 1850
Wire Wire Line
	4550 1900 4550 1850
Connection ~ 4550 1850
Wire Wire Line
	4550 1850 5000 1850
Wire Wire Line
	5000 1950 5000 1850
Connection ~ 5000 1850
Wire Wire Line
	5000 1850 5300 1850
Wire Wire Line
	4550 2300 4550 2400
Wire Wire Line
	4550 2400 5000 2400
Wire Wire Line
	5000 2400 5000 2250
Wire Wire Line
	5250 2250 5000 2250
Connection ~ 5000 2250
Wire Wire Line
	5000 2250 5000 2150
Wire Wire Line
	5000 2400 5000 2450
Connection ~ 5000 2400
$Comp
L power:GND #PWR0101
U 1 1 5EB3DC61
P 8550 5950
F 0 "#PWR0101" H 8550 5700 50  0001 C CNN
F 1 "GND" H 8555 5777 50  0000 C CNN
F 2 "" H 8550 5950 50  0001 C CNN
F 3 "" H 8550 5950 50  0001 C CNN
	1    8550 5950
	1    0    0    -1  
$EndComp
Text HLabel 8550 4750 1    50   UnSpc ~ 0
VCC
Wire Wire Line
	8550 4750 8550 4800
Wire Wire Line
	8550 5850 8550 5950
Wire Wire Line
	7950 5450 7750 5450
Wire Wire Line
	7750 4800 8550 4800
Connection ~ 8550 4800
Wire Wire Line
	8550 4800 8550 4850
Wire Wire Line
	7950 5550 7750 5550
Wire Wire Line
	7750 4800 7750 5450
Connection ~ 7750 5450
Wire Wire Line
	7750 5450 7750 5550
Text GLabel 5650 2550 0    50   Input ~ 0
FlashCS
Wire Wire Line
	5650 2550 5750 2550
$Comp
L Device:C_Small C2
U 1 1 5EB6F8D9
P 8950 4800
F 0 "C2" V 8721 4800 50  0000 C CNN
F 1 "100nF" V 8812 4800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8950 4800 50  0001 C CNN
F 3 "~" H 8950 4800 50  0001 C CNN
F 4 "C1525" H 8950 4800 50  0001 C CNN "LCSC"
F 5 "CL05B104KO5NNNC" H 8950 4800 50  0001 C CNN "PartNumber"
	1    8950 4800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5EB70B65
P 9150 4800
F 0 "#PWR0102" H 9150 4550 50  0001 C CNN
F 1 "GND" H 9155 4627 50  0000 C CNN
F 2 "" H 9150 4800 50  0001 C CNN
F 3 "" H 9150 4800 50  0001 C CNN
	1    9150 4800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8850 4800 8550 4800
Wire Wire Line
	9050 4800 9150 4800
$Comp
L Memory_Flash:AT25SF081-SSHD-X U6
U 1 1 5EB454BB
P 8550 5350
F 0 "U6" H 8100 5750 50  0000 L CNN
F 1 "AT25SF081-SSHD-X" H 8600 5750 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8550 4750 50  0001 C CNN
F 3 "https://www.adestotech.com/wp-content/uploads/DS-AT25SF081_045.pdf" H 8550 5350 50  0001 C CNN
F 4 "C169368" H 8550 5350 50  0001 C CNN "LCSC"
F 5 "AT25SF081-SSHD-B" H 8550 5350 50  0001 C CNN "PartNumber"
	1    8550 5350
	1    0    0    -1  
$EndComp
Text GLabel 5650 2450 0    50   Input ~ 0
StatusLED
Wire Wire Line
	5650 2450 5750 2450
Text GLabel 2200 2000 0    50   Input ~ 0
StatusLED
$Comp
L Device:R_US R32
U 1 1 5EB6CA05
P 2300 2300
F 0 "R32" V 2095 2300 50  0000 C CNN
F 1 "10k" V 2186 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2340 2290 50  0001 C CNN
F 3 "~" H 2300 2300 50  0001 C CNN
F 4 "C25744" H 2300 2300 50  0001 C CNN "LCSC"
F 5 "RTT02103JTH" H 2300 2300 50  0001 C CNN "PartNumber"
	1    2300 2300
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D10
U 1 1 5EB6F26B
P 2300 2700
F 0 "D10" V 2339 2583 50  0000 R CNN
F 1 "GLED" V 2248 2583 50  0000 R CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2300 2700 50  0001 C CNN
F 3 "~" H 2300 2700 50  0001 C CNN
F 4 "C72043" H 2300 2700 50  0001 C CNN "LCSC"
F 5 "19-217/GHC-YR1S2/3T" H 2300 2700 50  0001 C CNN "PartNumber"
	1    2300 2700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5EB6FE20
P 2300 2950
F 0 "#PWR0109" H 2300 2700 50  0001 C CNN
F 1 "GND" H 2305 2777 50  0000 C CNN
F 2 "" H 2300 2950 50  0001 C CNN
F 3 "" H 2300 2950 50  0001 C CNN
	1    2300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2000 2300 2000
Wire Wire Line
	2300 2000 2300 2150
Wire Wire Line
	2300 2450 2300 2550
Wire Wire Line
	2300 2850 2300 2950
Text Notes 1150 1900 0    50   ~ 0
This LED is driven by a very low current source (PC14) and cannot \nexceed 3mA. See RM0394 for details.
Wire Wire Line
	5000 3150 5000 2900
Wire Wire Line
	5000 2900 5700 2900
Wire Wire Line
	5600 2750 5700 2750
Wire Wire Line
	4800 2800 5700 2800
Wire Wire Line
	5000 3150 4800 3150
Wire Wire Line
	5600 2850 5700 2850
Wire Wire Line
	9150 5150 9250 5150
Text HLabel 9250 5150 2    50   BiDi ~ 0
SPI_1_MISO
Wire Wire Line
	7550 5250 7950 5250
Wire Wire Line
	7550 5350 7950 5350
Text GLabel 7550 5350 0    50   Input ~ 0
FlashCS
Text HLabel 7550 5250 0    50   BiDi ~ 0
SPI_1_SCK
Text HLabel 7550 5150 0    50   BiDi ~ 0
SPI_1_MOSI
Wire Wire Line
	7550 5150 7950 5150
$Comp
L Interface_USB:CP2104 U?
U 1 1 5EF3EE53
P 3500 5700
AR Path="/5E5FC13E/5EF3EE53" Ref="U?"  Part="1" 
AR Path="/5E5FC1C1/5EF3EE53" Ref="U10"  Part="1" 
F 0 "U10" H 3000 6650 50  0000 C CNN
F 1 "CP2104" H 3000 6550 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-24-1EP_4x4mm_P0.5mm_EP2.6x2.6mm" H 3650 4750 50  0001 L CNN
F 3 "https://www.silabs.com/documents/public/data-sheets/cp2104.pdf" H 2950 6950 50  0001 C CNN
F 4 "C47742" H 3500 5700 50  0001 C CNN "LCSC"
	1    3500 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EF3EE63
P 4500 4850
AR Path="/5E5FC17D/5EF3EE63" Ref="C?"  Part="1" 
AR Path="/5E5FC13E/5EF3EE63" Ref="C?"  Part="1" 
AR Path="/5E5FC1C1/5EF3EE63" Ref="C14"  Part="1" 
F 0 "C14" H 4592 4896 50  0000 L CNN
F 1 "1uF" H 4592 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4500 4850 50  0001 C CNN
F 3 "~" H 4500 4850 50  0001 C CNN
F 4 "C28323" H 4500 4850 50  0001 C CNN "LCSC"
F 5 "CL21B105KBFNNNE" H 4500 4850 50  0001 C CNN "PartNumber"
	1    4500 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5EF3EE6B
P 2400 5250
AR Path="/5E5FC17D/5EF3EE6B" Ref="D?"  Part="1" 
AR Path="/5E5FC13E/5EF3EE6B" Ref="D?"  Part="1" 
AR Path="/5E5FC1C1/5EF3EE6B" Ref="D4"  Part="1" 
F 0 "D4" H 2550 5200 50  0000 C CNN
F 1 "BLED" H 2400 5350 50  0000 C CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2400 5250 50  0001 C CNN
F 3 "~" H 2400 5250 50  0001 C CNN
F 4 "C72041" H 2400 5250 50  0001 C CNN "LCSC"
F 5 "19-217/BHC-ZL1M2RY/3T" H 2400 5250 50  0001 C CNN "PartNumber"
	1    2400 5250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 5EF3EE73
P 2100 5250
AR Path="/5E5FC17D/5EF3EE73" Ref="D?"  Part="1" 
AR Path="/5E5FC13E/5EF3EE73" Ref="D?"  Part="1" 
AR Path="/5E5FC1C1/5EF3EE73" Ref="D3"  Part="1" 
F 0 "D3" H 2250 5200 50  0000 C CNN
F 1 "BLED" H 2100 5350 50  0000 C CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2100 5250 50  0001 C CNN
F 3 "~" H 2100 5250 50  0001 C CNN
F 4 "C72041" H 2100 5250 50  0001 C CNN "LCSC"
F 5 "19-217/BHC-ZL1M2RY/3T" H 2100 5250 50  0001 C CNN "PartNumber"
	1    2100 5250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5EF3EE7B
P 2100 5650
AR Path="/5E5FC17D/5EF3EE7B" Ref="R?"  Part="1" 
AR Path="/5E5FC13E/5EF3EE7B" Ref="R?"  Part="1" 
AR Path="/5E5FC1C1/5EF3EE7B" Ref="R16"  Part="1" 
F 0 "R16" V 2300 5650 50  0000 C CNN
F 1 "1k" V 2200 5650 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2140 5640 50  0001 C CNN
F 3 "~" H 2100 5650 50  0001 C CNN
F 4 "C11702" H 2100 5650 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 2100 5650 50  0001 C CNN "PartNumber"
	1    2100 5650
	-1   0    0    1   
$EndComp
Text HLabel 4300 5700 2    50   BiDi ~ 0
RS232_1_TX
Text HLabel 4300 5600 2    50   BiDi ~ 0
RS232_1_RX
Text HLabel 2700 5700 0    50   BiDi ~ 0
D+
Text HLabel 2700 5600 0    50   BiDi ~ 0
D-
$Comp
L Device:R_US R?
U 1 1 5EF5D049
P 2400 5650
AR Path="/5E5FC17D/5EF5D049" Ref="R?"  Part="1" 
AR Path="/5E5FC13E/5EF5D049" Ref="R?"  Part="1" 
AR Path="/5E5FC1C1/5EF5D049" Ref="R17"  Part="1" 
F 0 "R17" V 2600 5650 50  0000 C CNN
F 1 "1k" V 2500 5650 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2440 5640 50  0001 C CNN
F 3 "~" H 2400 5650 50  0001 C CNN
F 4 "C11702" H 2400 5650 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 2400 5650 50  0001 C CNN "PartNumber"
	1    2400 5650
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 5800 2400 5900
Wire Wire Line
	2400 5900 2800 5900
Wire Wire Line
	2100 5800 2100 6000
Wire Wire Line
	2100 6000 2800 6000
Wire Wire Line
	3700 4800 3700 4700
Wire Wire Line
	3700 4700 3500 4700
Wire Wire Line
	3300 4700 3300 4800
Wire Wire Line
	3500 4800 3500 4700
Connection ~ 3500 4700
Wire Wire Line
	3500 4700 3300 4700
$Comp
L Device:R_US R?
U 1 1 5EF75F53
P 4950 5900
AR Path="/5E5FC17D/5EF75F53" Ref="R?"  Part="1" 
AR Path="/5E5FC13E/5EF75F53" Ref="R?"  Part="1" 
AR Path="/5E5FC1C1/5EF75F53" Ref="R18"  Part="1" 
F 0 "R18" V 5150 5900 50  0000 C CNN
F 1 "1k" V 5050 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4990 5890 50  0001 C CNN
F 3 "~" H 4950 5900 50  0001 C CNN
F 4 "C11702" H 4950 5900 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 4950 5900 50  0001 C CNN "PartNumber"
	1    4950 5900
	-1   0    0    1   
$EndComp
Wire Wire Line
	4950 6050 4950 6200
Wire Wire Line
	4950 6200 4200 6200
Wire Wire Line
	4950 5750 4950 4700
Wire Wire Line
	4950 4700 4500 4700
Connection ~ 3700 4700
Text HLabel 1600 4700 0    50   BiDi ~ 0
USB+5v
Wire Wire Line
	2100 4700 2100 5100
Wire Wire Line
	2100 4700 2400 4700
Wire Wire Line
	2400 4700 2400 5100
Connection ~ 2100 4700
Wire Wire Line
	2400 5400 2400 5500
Wire Wire Line
	2100 5400 2100 5500
Wire Wire Line
	2800 5300 2550 5300
Wire Wire Line
	2550 5300 2550 5100
Wire Wire Line
	2550 4700 2400 4700
Connection ~ 2400 4700
Wire Wire Line
	2800 5100 2550 5100
Connection ~ 2550 5100
Wire Wire Line
	2550 5100 2550 4700
Wire Wire Line
	2700 5600 2800 5600
Wire Wire Line
	2700 5700 2800 5700
Wire Wire Line
	4300 5600 4200 5600
Wire Wire Line
	4200 5700 4300 5700
$Comp
L Device:C_Small C?
U 1 1 5EFB9D8C
P 1750 5000
AR Path="/5E5FC17D/5EFB9D8C" Ref="C?"  Part="1" 
AR Path="/5E5FC13E/5EFB9D8C" Ref="C?"  Part="1" 
AR Path="/5E5FC1C1/5EFB9D8C" Ref="C12"  Part="1" 
F 0 "C12" H 1842 5046 50  0000 L CNN
F 1 "1uF" H 1842 4955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1750 5000 50  0001 C CNN
F 3 "~" H 1750 5000 50  0001 C CNN
F 4 "C28323" H 1750 5000 50  0001 C CNN "LCSC"
F 5 "CL21B105KBFNNNE" H 1750 5000 50  0001 C CNN "PartNumber"
	1    1750 5000
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 4900 1750 4700
Wire Wire Line
	1750 4700 1600 4700
Wire Wire Line
	1750 4700 2100 4700
Connection ~ 1750 4700
$Comp
L power:GND #PWR0103
U 1 1 5EFC92BE
P 4500 5000
F 0 "#PWR0103" H 4500 4750 50  0001 C CNN
F 1 "GND" H 4505 4827 50  0000 C CNN
F 2 "" H 4500 5000 50  0001 C CNN
F 3 "" H 4500 5000 50  0001 C CNN
	1    4500 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5EFC9869
P 1750 5150
F 0 "#PWR0104" H 1750 4900 50  0001 C CNN
F 1 "GND" H 1755 4977 50  0000 C CNN
F 2 "" H 1750 5150 50  0001 C CNN
F 3 "" H 1750 5150 50  0001 C CNN
	1    1750 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4750 4500 4700
Connection ~ 4500 4700
Wire Wire Line
	4500 4700 3700 4700
Wire Wire Line
	4500 4950 4500 5000
Wire Wire Line
	1750 5100 1750 5150
$Comp
L power:GND #PWR0105
U 1 1 5EFDD9F3
P 3550 6800
F 0 "#PWR0105" H 3550 6550 50  0001 C CNN
F 1 "GND" H 3555 6627 50  0000 C CNN
F 2 "" H 3550 6800 50  0001 C CNN
F 3 "" H 3550 6800 50  0001 C CNN
	1    3550 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 6700 3500 6800
Wire Wire Line
	3500 6800 3550 6800
Wire Wire Line
	3600 6700 3600 6800
Wire Wire Line
	3600 6800 3550 6800
Connection ~ 3550 6800
Wire Notes Line
	1000 4500 5500 4500
Wire Notes Line
	5500 4500 5500 7000
Wire Notes Line
	5500 7000 1000 7000
Wire Notes Line
	1000 7000 1000 4500
NoConn ~ 4200 5100
NoConn ~ 4200 5200
NoConn ~ 4200 5300
NoConn ~ 4200 5400
NoConn ~ 4200 5900
NoConn ~ 4200 6000
NoConn ~ 4200 6300
NoConn ~ 4200 6400
NoConn ~ 2800 6400
NoConn ~ 2800 6200
NoConn ~ 2800 6100
Text Notes 1000 4500 0    50   ~ 0
USB to Serial Converter
Text Notes 7000 4500 0    50   ~ 0
System Flash Memory
Wire Notes Line
	7000 4500 10000 4500
Wire Notes Line
	10000 4500 10000 6250
Wire Notes Line
	10000 6250 7000 6250
Wire Notes Line
	7000 6250 7000 4500
Wire Wire Line
	5000 1100 5300 1100
Connection ~ 5300 1100
Wire Notes Line
	1000 1000 1000 4000
Wire Notes Line
	1000 4000 8500 4000
Wire Notes Line
	8500 4000 8500 1000
Wire Notes Line
	8500 1000 1000 1000
Text Notes 1000 1000 0    50   ~ 0
Processor
$EndSCHEMATC
