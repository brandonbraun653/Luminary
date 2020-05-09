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
P 6750 2550
F 0 "U2" H 7100 3500 50  0000 C CNN
F 1 "STM32L432KBUx" H 7200 3400 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.45x3.45mm" H 6350 1650 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00257205.pdf" H 6750 2550 50  0001 C CNN
	1    6750 2550
	1    0    0    -1  
$EndComp
Text HLabel 7450 3150 2    50   BiDi ~ 0
SWDIO
Text HLabel 7450 3250 2    50   BiDi ~ 0
SWCLK
Text HLabel 6750 950  1    50   UnSpc ~ 0
VCC
Text HLabel 4900 1850 0    50   BiDi ~ 0
nRST
Wire Wire Line
	6850 1650 6850 1550
Wire Wire Line
	6850 1550 6750 1550
Connection ~ 6750 1550
Wire Wire Line
	6750 1550 6750 1650
Wire Wire Line
	6650 1650 6650 1550
Wire Wire Line
	6650 1550 6750 1550
$Comp
L Device:C_Small C3
U 1 1 5E64531B
P 6450 1400
F 0 "C3" V 6221 1400 50  0000 C CNN
F 1 "100nF" V 6312 1400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6450 1400 50  0001 C CNN
F 3 "~" H 6450 1400 50  0001 C CNN
	1    6450 1400
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5E6477BB
P 7050 1400
F 0 "C4" V 6821 1400 50  0000 C CNN
F 1 "100nF" V 6912 1400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7050 1400 50  0001 C CNN
F 3 "~" H 7050 1400 50  0001 C CNN
	1    7050 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 1400 6750 1400
Connection ~ 6750 1400
Wire Wire Line
	6750 1400 6750 1550
Wire Wire Line
	6550 1400 6750 1400
$Comp
L power:GND #PWR06
U 1 1 5E649A0F
P 6300 1400
F 0 "#PWR06" H 6300 1150 50  0001 C CNN
F 1 "GND" V 6305 1272 50  0000 R CNN
F 2 "" H 6300 1400 50  0001 C CNN
F 3 "" H 6300 1400 50  0001 C CNN
	1    6300 1400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5E64A557
P 7200 1400
F 0 "#PWR08" H 7200 1150 50  0001 C CNN
F 1 "GND" V 7205 1272 50  0000 R CNN
F 2 "" H 7200 1400 50  0001 C CNN
F 3 "" H 7200 1400 50  0001 C CNN
	1    7200 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7150 1400 7200 1400
Wire Wire Line
	6300 1400 6350 1400
Text HLabel 6750 3750 3    50   UnSpc ~ 0
Gnd
Wire Wire Line
	6750 3550 6750 3650
Wire Wire Line
	6650 3550 6650 3650
Wire Wire Line
	6650 3650 6750 3650
Connection ~ 6750 3650
Wire Wire Line
	6750 3650 6750 3750
Wire Wire Line
	6850 3550 6850 3650
Wire Wire Line
	6850 3650 6750 3650
$Comp
L power:GND #PWR07
U 1 1 5E64E3B1
P 6450 3700
F 0 "#PWR07" H 6450 3450 50  0001 C CNN
F 1 "GND" H 6455 3527 50  0000 C CNN
F 2 "" H 6450 3700 50  0001 C CNN
F 3 "" H 6450 3700 50  0001 C CNN
	1    6450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3700 6450 3650
Wire Wire Line
	6450 3650 6650 3650
Connection ~ 6650 3650
$Comp
L Device:R_US R3
U 1 1 5E64F79D
P 5900 2250
F 0 "R3" V 5695 2250 50  0000 C CNN
F 1 "10k" V 5786 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5940 2240 50  0001 C CNN
F 3 "~" H 5900 2250 50  0001 C CNN
	1    5900 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5E651078
P 5500 2450
F 0 "#PWR05" H 5500 2200 50  0001 C CNN
F 1 "GND" V 5505 2322 50  0000 R CNN
F 2 "" H 5500 2450 50  0001 C CNN
F 3 "" H 5500 2450 50  0001 C CNN
	1    5500 2450
	1    0    0    -1  
$EndComp
Text HLabel 6150 3250 0    50   BiDi ~ 0
I2C_1_SCL
Text HLabel 6150 3350 0    50   BiDi ~ 0
I2C_1_SDA
Text HLabel 6150 3150 0    50   BiDi ~ 0
SPI_3_MOSI
Text HLabel 6150 3050 0    50   BiDi ~ 0
SPI_3_MISO
Text HLabel 6150 2950 0    50   BiDi ~ 0
SPI_3_SCK
Text HLabel 6150 2750 0    50   BiDi ~ 0
GPIO_0
Text HLabel 6150 2850 0    50   BiDi ~ 0
GPIO_1
Wire Wire Line
	6150 2850 6200 2850
Wire Wire Line
	6150 2750 6200 2750
Wire Wire Line
	7450 3350 7350 3350
Text HLabel 7450 3350 2    50   BiDi ~ 0
PWM_0
Text HLabel 7450 3050 2    50   BiDi ~ 0
CAN_1_TX
Text HLabel 7450 2950 2    50   BiDi ~ 0
CAN_1_RX
Text HLabel 7450 2750 2    50   BiDi ~ 0
RS232_1_TX
Text HLabel 7450 2850 2    50   BiDi ~ 0
RS232_1_RX
Text HLabel 7450 2650 2    50   BiDi ~ 0
GPIO_2
Wire Wire Line
	7250 2950 7450 2950
Wire Wire Line
	7450 3050 7250 3050
Text HLabel 7450 2550 2    50   BiDi ~ 0
SPI_1_MOSI
Text HLabel 7450 2450 2    50   BiDi ~ 0
SPI_1_MISO
Text HLabel 7450 2350 2    50   BiDi ~ 0
SPI_1_SCK
Text HLabel 7450 2250 2    50   BiDi ~ 0
ADC_2
Text HLabel 7450 2150 2    50   BiDi ~ 0
ADC_1
Text HLabel 7450 1850 2    50   BiDi ~ 0
ADC_0
Text HLabel 7450 1950 2    50   BiDi ~ 0
PWM_1
Text HLabel 7450 2050 2    50   BiDi ~ 0
PWM_2
Wire Wire Line
	7250 3150 7450 3150
Wire Wire Line
	7250 3250 7450 3250
Wire Wire Line
	7250 2850 7450 2850
Wire Wire Line
	7250 2750 7450 2750
Wire Wire Line
	7250 2650 7350 2650
Wire Wire Line
	7450 2550 7250 2550
Wire Wire Line
	7250 2450 7450 2450
Wire Wire Line
	7450 2350 7250 2350
Wire Wire Line
	7250 2250 7450 2250
Wire Wire Line
	7450 2150 7250 2150
Wire Wire Line
	7250 2050 7350 2050
Wire Wire Line
	7450 1950 7350 1950
Wire Wire Line
	7250 1850 7450 1850
Wire Wire Line
	6150 2950 6250 2950
Wire Wire Line
	6150 3050 6250 3050
Wire Wire Line
	6150 3150 6250 3150
Wire Wire Line
	6150 3250 6250 3250
Wire Wire Line
	6150 3350 6250 3350
Text HLabel 4650 2800 0    50   BiDi ~ 0
GPIO_IN_0
Text HLabel 4650 3100 0    50   BiDi ~ 0
GPIO_IN_1
Text HLabel 8450 2600 2    50   BiDi ~ 0
GPIO_IN_2
Text HLabel 8450 3300 2    50   BiDi ~ 0
GPIO_IN_3
Text HLabel 8450 1700 2    50   BiDi ~ 0
GPIO_IN_4
Text HLabel 8450 2000 2    50   BiDi ~ 0
GPIO_IN_5
Wire Wire Line
	7350 1900 7350 1950
Connection ~ 7350 1950
Wire Wire Line
	7350 1950 7250 1950
Wire Wire Line
	8050 2000 7350 2000
Wire Wire Line
	7350 2000 7350 2050
Connection ~ 7350 2050
Wire Wire Line
	7350 2050 7450 2050
Wire Wire Line
	8050 2600 7350 2600
Wire Wire Line
	7350 2600 7350 2650
Connection ~ 7350 2650
Wire Wire Line
	7350 2650 7450 2650
Wire Wire Line
	8050 3300 7350 3300
Wire Wire Line
	7350 3300 7350 3350
Connection ~ 7350 3350
Wire Wire Line
	7350 3350 7250 3350
Wire Wire Line
	6200 2800 6200 2750
Connection ~ 6200 2750
Wire Wire Line
	6200 2750 6250 2750
Wire Wire Line
	5500 2900 6200 2900
Wire Wire Line
	6200 2900 6200 2850
Connection ~ 6200 2850
Wire Wire Line
	6200 2850 6250 2850
$Comp
L Device:R_US R1
U 1 1 5E67EEA7
P 4900 2800
F 0 "R1" V 5105 2800 50  0000 C CNN
F 1 "50k" V 5014 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4940 2790 50  0001 C CNN
F 3 "~" H 4900 2800 50  0001 C CNN
	1    4900 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R2
U 1 1 5E67F864
P 4900 3100
F 0 "R2" V 4695 3100 50  0000 C CNN
F 1 "50k" V 4786 3100 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4940 3090 50  0001 C CNN
F 3 "~" H 4900 3100 50  0001 C CNN
	1    4900 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3100 5500 3100
Wire Wire Line
	5500 2900 5500 3100
Wire Wire Line
	4650 2800 4750 2800
Wire Wire Line
	4650 3100 4750 3100
$Comp
L Device:R_US R6
U 1 1 5E68A214
P 8200 2600
F 0 "R6" V 8405 2600 50  0000 C CNN
F 1 "50k" V 8314 2600 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8240 2590 50  0001 C CNN
F 3 "~" H 8200 2600 50  0001 C CNN
	1    8200 2600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R7
U 1 1 5E68B29C
P 8200 3300
F 0 "R7" V 8405 3300 50  0000 C CNN
F 1 "50k" V 8314 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8240 3290 50  0001 C CNN
F 3 "~" H 8200 3300 50  0001 C CNN
	1    8200 3300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R4
U 1 1 5E68B831
P 8200 1700
F 0 "R4" V 8405 1700 50  0000 C CNN
F 1 "50k" V 8314 1700 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8240 1690 50  0001 C CNN
F 3 "~" H 8200 1700 50  0001 C CNN
	1    8200 1700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R5
U 1 1 5E68CD5A
P 8200 2000
F 0 "R5" V 8405 2000 50  0000 C CNN
F 1 "50k" V 8314 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8240 1990 50  0001 C CNN
F 3 "~" H 8200 2000 50  0001 C CNN
	1    8200 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8050 1700 7850 1700
Wire Wire Line
	7850 1700 7850 1900
Wire Wire Line
	7850 1900 7350 1900
Wire Wire Line
	8350 1700 8450 1700
Wire Wire Line
	8350 2000 8450 2000
Wire Wire Line
	8350 2600 8450 2600
Wire Wire Line
	8350 3300 8450 3300
$Comp
L Device:R_US R11
U 1 1 5E779034
P 5800 1500
F 0 "R11" H 5732 1454 50  0000 R CNN
F 1 "10k" H 5732 1545 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5840 1490 50  0001 C CNN
F 3 "~" H 5800 1500 50  0001 C CNN
	1    5800 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5800 1650 5800 1850
Wire Wire Line
	5800 1850 6250 1850
Wire Wire Line
	5800 1350 5800 1100
Wire Wire Line
	5800 1100 6750 1100
Wire Wire Line
	6750 1100 6750 1400
Wire Wire Line
	6750 950  6750 1100
Connection ~ 6750 1100
Wire Wire Line
	5050 2800 6200 2800
$Comp
L Switch:SW_Push SW1
U 1 1 5EB3D520
P 5050 2100
F 0 "SW1" V 5096 2052 50  0000 R CNN
F 1 "SW_Push" V 5005 2052 50  0000 R CNN
F 2 "button:LCSC_C255808_HYP_2x4x3.5mm_RightAngle" H 5050 2300 50  0001 C CNN
F 3 "~" H 5050 2300 50  0001 C CNN
	1    5050 2100
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5EB402BC
P 5500 2050
F 0 "C1" V 5271 2050 50  0000 C CNN
F 1 "100nF" V 5362 2050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 5500 2050 50  0001 C CNN
F 3 "~" H 5500 2050 50  0001 C CNN
	1    5500 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	6050 2250 6250 2250
Wire Wire Line
	4900 1850 5050 1850
Connection ~ 5800 1850
Wire Wire Line
	5050 1900 5050 1850
Connection ~ 5050 1850
Wire Wire Line
	5050 1850 5500 1850
Wire Wire Line
	5500 1950 5500 1850
Connection ~ 5500 1850
Wire Wire Line
	5500 1850 5800 1850
Wire Wire Line
	5050 2300 5050 2400
Wire Wire Line
	5050 2400 5500 2400
Wire Wire Line
	5500 2400 5500 2250
Wire Wire Line
	5750 2250 5500 2250
Connection ~ 5500 2250
Wire Wire Line
	5500 2250 5500 2150
Wire Wire Line
	5500 2400 5500 2450
Connection ~ 5500 2400
$Comp
L power:GND #PWR0101
U 1 1 5EB3DC61
P 4500 5750
F 0 "#PWR0101" H 4500 5500 50  0001 C CNN
F 1 "GND" H 4505 5577 50  0000 C CNN
F 2 "" H 4500 5750 50  0001 C CNN
F 3 "" H 4500 5750 50  0001 C CNN
	1    4500 5750
	1    0    0    -1  
$EndComp
Text HLabel 4500 4150 1    50   UnSpc ~ 0
VCC
$Comp
L Device:R_US R13
U 1 1 5EB3E2A2
P 4500 4400
F 0 "R13" V 4705 4400 50  0000 C CNN
F 1 "0" V 4614 4400 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4540 4390 50  0001 C CNN
F 3 "~" H 4500 4400 50  0001 C CNN
	1    4500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4150 4500 4250
Wire Wire Line
	4500 4550 4500 4600
Wire Wire Line
	4500 5650 4500 5750
Text HLabel 3500 5050 0    50   BiDi ~ 0
SPI_1_SCK
Text HLabel 5200 4950 2    50   BiDi ~ 0
SPI_1_MISO
Text HLabel 3500 4950 0    50   BiDi ~ 0
SPI_1_MOSI
Wire Wire Line
	3900 5250 3700 5250
Wire Wire Line
	3700 4600 4500 4600
Connection ~ 4500 4600
Wire Wire Line
	4500 4600 4500 4650
Wire Wire Line
	3900 5350 3700 5350
Wire Wire Line
	3700 4600 3700 5250
Connection ~ 3700 5250
Wire Wire Line
	3700 5250 3700 5350
Wire Wire Line
	5100 4950 5200 4950
Wire Wire Line
	3500 4950 3900 4950
Wire Wire Line
	3500 5050 3900 5050
Wire Wire Line
	3500 5150 3900 5150
Text GLabel 6150 2550 0    50   Input ~ 0
FlashCS
Text GLabel 3500 5150 0    50   Input ~ 0
FlashCS
Wire Wire Line
	6150 2550 6250 2550
$Comp
L Device:C_Small C2
U 1 1 5EB6F8D9
P 4900 4600
F 0 "C2" V 4671 4600 50  0000 C CNN
F 1 "100nF" V 4762 4600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 4900 4600 50  0001 C CNN
F 3 "~" H 4900 4600 50  0001 C CNN
	1    4900 4600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5EB70B65
P 5100 4600
F 0 "#PWR0102" H 5100 4350 50  0001 C CNN
F 1 "GND" H 5105 4427 50  0000 C CNN
F 2 "" H 5100 4600 50  0001 C CNN
F 3 "" H 5100 4600 50  0001 C CNN
	1    5100 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 4600 4500 4600
Wire Wire Line
	5000 4600 5100 4600
$Comp
L Memory_Flash:AT25SF081-SSHD-X U6
U 1 1 5EB454BB
P 4500 5150
F 0 "U6" H 5144 5196 50  0000 L CNN
F 1 "AT25SF081-SSHD-X" H 5144 5105 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4500 4550 50  0001 C CNN
F 3 "https://www.adestotech.com/wp-content/uploads/DS-AT25SF081_045.pdf" H 4500 5150 50  0001 C CNN
	1    4500 5150
	1    0    0    -1  
$EndComp
Text GLabel 6150 2450 0    50   Input ~ 0
StatusLED
Wire Wire Line
	6150 2450 6250 2450
Text GLabel 2700 2000 0    50   Input ~ 0
StatusLED
$Comp
L Device:R_US R32
U 1 1 5EB6CA05
P 2800 2300
F 0 "R32" V 2595 2300 50  0000 C CNN
F 1 "10k" V 2686 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2840 2290 50  0001 C CNN
F 3 "~" H 2800 2300 50  0001 C CNN
	1    2800 2300
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D10
U 1 1 5EB6F26B
P 2800 2700
F 0 "D10" V 2839 2583 50  0000 R CNN
F 1 "GLED" V 2748 2583 50  0000 R CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2800 2700 50  0001 C CNN
F 3 "~" H 2800 2700 50  0001 C CNN
	1    2800 2700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5EB6FE20
P 2800 2950
F 0 "#PWR0109" H 2800 2700 50  0001 C CNN
F 1 "GND" H 2805 2777 50  0000 C CNN
F 2 "" H 2800 2950 50  0001 C CNN
F 3 "" H 2800 2950 50  0001 C CNN
	1    2800 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 2000 2800 2000
Wire Wire Line
	2800 2000 2800 2150
Wire Wire Line
	2800 2450 2800 2550
Wire Wire Line
	2800 2850 2800 2950
Text Notes 1650 1900 0    50   ~ 0
This LED is driven by a very low current source (PC14) and cannot \nexceed 3mA. See RM0394 for details.
$EndSCHEMATC
