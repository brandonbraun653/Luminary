EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4450 2300 1    50   UnSpc ~ 0
+3.3V
Text HLabel 4550 2700 2    50   UnSpc ~ 0
Gnd
Text HLabel 6950 2350 0    50   Input ~ 0
GPIO_IN_0
Text HLabel 7750 2350 2    50   Output ~ 0
GPIO_OUT_0
Text HLabel 6950 2800 0    50   Input ~ 0
GPIO_IN_1
Text HLabel 6950 3300 0    50   Input ~ 0
GPIO_IN_2
Text HLabel 6950 3800 0    50   Input ~ 0
GPIO_IN_3
Text HLabel 6950 4250 0    50   Input ~ 0
GPIO_IN_4
Text HLabel 6950 4700 0    50   Input ~ 0
GPIO_IN_5
Text HLabel 7750 2800 2    50   Output ~ 0
GPIO_OUT_1
Text HLabel 7750 3300 2    50   Output ~ 0
GPIO_OUT_2
Text HLabel 7750 3800 2    50   Output ~ 0
GPIO_OUT_3
Text HLabel 7750 4250 2    50   Output ~ 0
GPIO_OUT_4
Text HLabel 7750 4700 2    50   Output ~ 0
GPIO_OUT_5
Text HLabel 4300 3350 2    50   Output ~ 0
CAN_HI
Text HLabel 4300 3850 2    50   Output ~ 0
CAN_LO
Text HLabel 2850 3450 0    50   Input ~ 0
CAN_TX
Text HLabel 2850 3550 0    50   Output ~ 0
CAN_RX
$Comp
L Interface_CAN_LIN:SN65HVD232 U5
U 1 1 5E73A28D
P 3450 3550
F 0 "U5" H 3100 3900 50  0000 C CNN
F 1 "SN65HVD232" H 3050 3800 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3450 3050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn65hvd230.pdf" H 3350 3950 50  0001 C CNN
	1    3450 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3450 3050 3450
Wire Wire Line
	2850 3550 3050 3550
$Comp
L Device:R_US R12
U 1 1 5E73B2A1
P 4150 3600
F 0 "R12" H 4218 3646 50  0000 L CNN
F 1 "120" H 4218 3555 50  0000 L CNN
F 2 "" V 4190 3590 50  0001 C CNN
F 3 "~" H 4150 3600 50  0001 C CNN
	1    4150 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3650 3950 3650
Wire Wire Line
	4300 3350 4150 3350
Wire Wire Line
	3950 3350 3950 3550
Wire Wire Line
	3950 3550 3850 3550
Wire Wire Line
	4150 3450 4150 3350
Connection ~ 4150 3350
Wire Wire Line
	4150 3350 3950 3350
Wire Wire Line
	4300 3850 4150 3850
Wire Wire Line
	3950 3850 3950 3650
Wire Wire Line
	4150 3750 4150 3850
Connection ~ 4150 3850
Wire Wire Line
	4150 3850 3950 3850
$Comp
L power:GND #PWR020
U 1 1 5E73C2E6
P 3450 4050
F 0 "#PWR020" H 3450 3800 50  0001 C CNN
F 1 "GND" H 3455 3877 50  0000 C CNN
F 2 "" H 3450 4050 50  0001 C CNN
F 3 "" H 3450 4050 50  0001 C CNN
	1    3450 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3950 3450 4050
$Comp
L 74xx:74LCX07 U6
U 1 1 5E73D050
P 7350 2350
F 0 "U6" H 7350 2667 50  0000 C CNN
F 1 "SN74LVC07ARGYR" H 7350 2576 50  0000 C CNN
F 2 "" H 7350 2350 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 7350 2350 50  0001 C CNN
	1    7350 2350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LCX07 U6
U 2 1 5E73EDCE
P 7350 2800
F 0 "U6" H 7350 3117 50  0000 C CNN
F 1 "SN74LVC07ARGYR" H 7350 3026 50  0000 C CNN
F 2 "" H 7350 2800 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 7350 2800 50  0001 C CNN
	2    7350 2800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LCX07 U6
U 3 1 5E73FA2A
P 7350 3300
F 0 "U6" H 7350 3617 50  0000 C CNN
F 1 "SN74LVC07ARGYR" H 7350 3526 50  0000 C CNN
F 2 "" H 7350 3300 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 7350 3300 50  0001 C CNN
	3    7350 3300
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LCX07 U6
U 4 1 5E740823
P 7350 3800
F 0 "U6" H 7350 4117 50  0000 C CNN
F 1 "SN74LVC07ARGYR" H 7350 4026 50  0000 C CNN
F 2 "" H 7350 3800 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 7350 3800 50  0001 C CNN
	4    7350 3800
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LCX07 U6
U 5 1 5E74175A
P 7350 4250
F 0 "U6" H 7350 4567 50  0000 C CNN
F 1 "SN74LVC07ARGYR" H 7350 4476 50  0000 C CNN
F 2 "" H 7350 4250 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 7350 4250 50  0001 C CNN
	5    7350 4250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LCX07 U6
U 6 1 5E74234A
P 7350 4700
F 0 "U6" H 7350 5017 50  0000 C CNN
F 1 "SN74LVC07ARGYR" H 7350 4926 50  0000 C CNN
F 2 "" H 7350 4700 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 7350 4700 50  0001 C CNN
	6    7350 4700
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LCX07 U6
U 7 1 5E742E44
P 5550 3550
F 0 "U6" H 5780 3596 50  0000 L CNN
F 1 "SN74LVC07ARGYR" H 5780 3505 50  0000 L CNN
F 2 "" H 5550 3550 50  0001 C CNN
F 3 "www.st.com/resource/en/datasheet/74lcx07.pdf" H 5550 3550 50  0001 C CNN
	7    5550 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R_PWR_2
U 1 1 5E745739
P 3450 3000
F 0 "R_PWR_2" H 3518 3046 50  0000 L CNN
F 1 "0" H 3518 2955 50  0000 L CNN
F 2 "" V 3490 2990 50  0001 C CNN
F 3 "~" H 3450 3000 50  0001 C CNN
	1    3450 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3150 3450 3250
Wire Wire Line
	6950 2350 7050 2350
Wire Wire Line
	6950 2800 7050 2800
Wire Wire Line
	6950 3300 7050 3300
Wire Wire Line
	6950 3800 7050 3800
Wire Wire Line
	6950 4250 7050 4250
Wire Wire Line
	6950 4700 7050 4700
Wire Wire Line
	7650 4700 7750 4700
Wire Wire Line
	7650 4250 7750 4250
Wire Wire Line
	7650 3800 7750 3800
Wire Wire Line
	7650 3300 7750 3300
Wire Wire Line
	7650 2800 7750 2800
Wire Wire Line
	7650 2350 7750 2350
$Comp
L Device:C_Small C10
U 1 1 5E74DEC8
P 5150 3550
F 0 "C10" H 5059 3504 50  0000 R CNN
F 1 "100nF" H 5059 3595 50  0000 R CNN
F 2 "" H 5150 3550 50  0001 C CNN
F 3 "~" H 5150 3550 50  0001 C CNN
	1    5150 3550
	1    0    0    1   
$EndComp
Wire Wire Line
	5150 3650 5150 4200
Wire Wire Line
	5150 4200 5550 4200
Wire Wire Line
	5550 4200 5550 4050
Wire Wire Line
	5150 3450 5150 2950
Wire Wire Line
	5150 2950 5550 2950
Wire Wire Line
	5550 2950 5550 3050
$Comp
L power:GND #PWR022
U 1 1 5E754F57
P 5550 4300
F 0 "#PWR022" H 5550 4050 50  0001 C CNN
F 1 "GND" H 5555 4127 50  0000 C CNN
F 2 "" H 5550 4300 50  0001 C CNN
F 3 "" H 5550 4300 50  0001 C CNN
	1    5550 4300
	1    0    0    -1  
$EndComp
Connection ~ 5550 4200
Wire Wire Line
	5550 4300 5550 4200
$Comp
L Device:R_US R_PWR_3
U 1 1 5E7560D0
P 5550 2750
F 0 "R_PWR_3" H 5618 2796 50  0000 L CNN
F 1 "0" H 5618 2705 50  0000 L CNN
F 2 "" V 5590 2740 50  0001 C CNN
F 3 "~" H 5550 2750 50  0001 C CNN
	1    5550 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 2900 5550 2950
Connection ~ 5550 2950
Wire Wire Line
	4450 2300 4450 2450
Wire Wire Line
	4450 2450 5550 2450
Wire Wire Line
	5550 2450 5550 2600
Wire Wire Line
	3450 2850 3450 2450
Wire Wire Line
	3450 2450 4450 2450
Connection ~ 4450 2450
$Comp
L power:GND #PWR021
U 1 1 5E758224
P 4450 2800
F 0 "#PWR021" H 4450 2550 50  0001 C CNN
F 1 "GND" H 4455 2627 50  0000 C CNN
F 2 "" H 4450 2800 50  0001 C CNN
F 3 "" H 4450 2800 50  0001 C CNN
	1    4450 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2700 4450 2700
Wire Wire Line
	4450 2700 4450 2800
$EndSCHEMATC
