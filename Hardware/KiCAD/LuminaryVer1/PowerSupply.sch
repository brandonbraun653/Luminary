EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4400 4100 2    50   UnSpc ~ 0
Battery_In+
Text HLabel 4400 4550 2    50   UnSpc ~ 0
Battery_In-
Text HLabel 10500 3000 2    50   UnSpc ~ 0
+5V
Text HLabel 10500 3400 2    50   UnSpc ~ 0
+3.3V
Text HLabel 6650 4500 0    50   UnSpc ~ 0
Gnd
Text HLabel 6650 4250 0    50   UnSpc ~ 0
Ext_In+
Text HLabel 6650 4400 0    50   UnSpc ~ 0
Ext_In-
$Comp
L Regulator_Linear:AP2112K-3.3 U4
U 1 1 5E7A2B61
P 9750 3500
F 0 "U4" H 9750 3842 50  0000 C CNN
F 1 "AP2112K-3.3" H 9750 3751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 9750 3825 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2112.pdf" H 9750 3600 50  0001 C CNN
F 4 "C51118" H 9750 3500 50  0001 C CNN "LCSC"
F 5 "AP2112K-3.3TRG1" H 9750 3500 50  0001 C CNN "PartNumber"
	1    9750 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5E7A4D07
P 10200 3600
F 0 "C9" H 10292 3646 50  0000 L CNN
F 1 "1uF" H 10292 3555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10200 3600 50  0001 C CNN
F 3 "~" H 10200 3600 50  0001 C CNN
F 4 "C28323" H 10200 3600 50  0001 C CNN "LCSC"
F 5 "CL21B105KBFNNNE" H 10200 3600 50  0001 C CNN "PartNumber"
	1    10200 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 3500 9350 3500
Wire Wire Line
	9350 3500 9350 3400
Connection ~ 9350 3400
Wire Wire Line
	9350 3400 9450 3400
Wire Wire Line
	10050 3400 10200 3400
Wire Wire Line
	10200 3400 10200 3500
Wire Wire Line
	9750 3900 9750 3800
Wire Wire Line
	10200 3700 10200 3900
Wire Wire Line
	10200 3900 9750 3900
Connection ~ 9750 3900
$Comp
L power:GND #PWR019
U 1 1 5E7A6116
P 9750 4000
F 0 "#PWR019" H 9750 3750 50  0001 C CNN
F 1 "GND" H 9755 3827 50  0000 C CNN
F 2 "" H 9750 4000 50  0001 C CNN
F 3 "" H 9750 4000 50  0001 C CNN
	1    9750 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4000 9750 3900
Wire Wire Line
	10200 3400 10500 3400
Connection ~ 10200 3400
$Comp
L LuminaryVer1-rescue:DIO6605-BoostConverters U3
U 1 1 5E7A9C90
P 7700 3350
AR Path="/5E7A9C90" Ref="U3"  Part="1" 
AR Path="/5E5FC17D/5E7A9C90" Ref="U3"  Part="1" 
F 0 "U3" H 7700 3725 50  0000 C CNN
F 1 "DIO6605" H 7700 3634 50  0000 C CNN
F 2 "Package_DFN_QFN:DFN-8-1EP_2x3mm_P0.5mm_EP0.61x2.2mm" H 7700 3500 50  0001 C CNN
F 3 "" H 7700 3500 50  0001 C CNN
F 4 "453-DIO6605BFN8" H 7700 3350 50  0001 C CNN "Mouser"
F 5 "DIO6605BFN8" H 7700 3350 50  0001 C CNN "PartNumber"
	1    7700 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:L L1
U 1 1 5E7AC957
P 7700 2900
F 0 "L1" V 7981 2900 50  0000 C CNN
F 1 "3.3uH" V 7890 2900 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 7700 2900 50  0001 C CNN
F 3 "~" H 7700 2900 50  0001 C CNN
F 4 "MIP20124R7MBE" V 7799 2900 50  0000 C CNN "PartNumber"
F 5 "C315723" H 7700 2900 50  0001 C CNN "LCSC"
	1    7700 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7550 2900 7300 2900
Wire Wire Line
	7300 2900 7300 3200
Connection ~ 7300 3200
Wire Wire Line
	7300 3200 7350 3200
$Comp
L Device:C_Small C6
U 1 1 5E7AE292
P 7000 3600
F 0 "C6" H 6909 3554 50  0000 R CNN
F 1 "10uF" H 6909 3645 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7000 3600 50  0001 C CNN
F 3 "~" H 7000 3600 50  0001 C CNN
F 4 "C162316" H 7000 3600 50  0001 C CNN "LCSC"
F 5 "GRM21BB31A106KE18L" H 7000 3600 50  0001 C CNN "PartNumber"
	1    7000 3600
	1    0    0    1   
$EndComp
Wire Wire Line
	7000 3200 7300 3200
$Comp
L Device:C_Small C7
U 1 1 5E7B02F9
P 8750 3600
F 0 "C7" H 8842 3646 50  0000 L CNN
F 1 "10uF" H 8842 3555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8750 3600 50  0001 C CNN
F 3 "~" H 8750 3600 50  0001 C CNN
F 4 "C162316" H 8750 3600 50  0001 C CNN "LCSC"
F 5 "GRM21BB31A106KE18L" H 8750 3600 50  0001 C CNN "PartNumber"
	1    8750 3600
	1    0    0    -1  
$EndComp
Connection ~ 8750 3400
Wire Wire Line
	8750 3400 8750 3500
Wire Wire Line
	8750 3700 8750 3900
$Comp
L Device:D_Schottky D1
U 1 1 5E7C06FD
P 7550 4250
F 0 "D1" H 7550 4034 50  0000 C CNN
F 1 "SS16HE" H 7550 4125 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 7550 4250 50  0001 C CNN
F 3 "~" H 7550 4250 50  0001 C CNN
F 4 "C266798" H 7550 4250 50  0001 C CNN "LCSC"
F 5 "SS16HE3_B/H" H 7550 4250 50  0001 C CNN "PartNumber"
	1    7550 4250
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R10
U 1 1 5E7C8142
P 8300 3500
F 0 "R10" V 8500 3500 50  0000 C CNN
F 1 "47k" V 8400 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8340 3490 50  0001 C CNN
F 3 "~" H 8300 3500 50  0001 C CNN
F 4 "C25792" H 8300 3500 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 8300 3500 50  0001 C CNN "PartNumber"
	1    8300 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 3500 8100 3500
Wire Wire Line
	8050 3400 8550 3400
Wire Wire Line
	8550 3500 8550 3400
Wire Wire Line
	8450 3500 8550 3500
Connection ~ 8550 3400
Wire Wire Line
	8550 3400 8750 3400
$Comp
L Transistor_BJT:2N3904 Q1
U 1 1 5E7D2C44
P 8000 4550
F 0 "Q1" H 8190 4596 50  0000 L CNN
F 1 "2N3904" H 8190 4505 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8200 4475 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 8000 4550 50  0001 L CNN
F 4 "C18536" H 8000 4550 50  0001 C CNN "LCSC"
F 5 "2N3904S-RTK/PS" H 8000 4550 50  0001 C CNN "PartNumber"
	1    8000 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 4350 8100 3500
Connection ~ 8100 3500
Wire Wire Line
	8100 3500 8050 3500
$Comp
L power:GND #PWR018
U 1 1 5E7D5603
P 8100 5150
F 0 "#PWR018" H 8100 4900 50  0001 C CNN
F 1 "GND" H 8105 4977 50  0000 C CNN
F 2 "" H 8100 5150 50  0001 C CNN
F 3 "" H 8100 5150 50  0001 C CNN
	1    8100 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R8
U 1 1 5E7D7B1A
P 7550 4550
F 0 "R8" V 7345 4550 50  0000 C CNN
F 1 "100" V 7436 4550 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7590 4540 50  0001 C CNN
F 3 "~" H 7550 4550 50  0001 C CNN
F 4 "C325391" H 7550 4550 50  0001 C CNN "LCSC"
F 5 "RMC04021005%N" H 7550 4550 50  0001 C CNN "PartNumber"
	1    7550 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	7700 4550 7750 4550
$Comp
L Device:R_US R9
U 1 1 5E7DA2F8
P 7750 4800
F 0 "R9" H 7682 4754 50  0000 R CNN
F 1 "10k" H 7682 4845 50  0000 R CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 7790 4790 50  0001 C CNN
F 3 "~" H 7750 4800 50  0001 C CNN
F 4 "C102759" H 7750 4800 50  0001 C CNN "LCSC"
F 5 "RTT02103JTH" H 7750 4800 50  0001 C CNN "PartNumber"
	1    7750 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	8550 4250 8550 3500
Connection ~ 8550 3500
Connection ~ 8750 3900
Wire Wire Line
	7750 4650 7750 4550
Connection ~ 7750 4550
Wire Wire Line
	7750 4550 7800 4550
Wire Wire Line
	8100 4750 8100 5050
Wire Wire Line
	7750 4950 7750 5050
Wire Wire Line
	7750 5050 8100 5050
Connection ~ 8100 5050
Wire Wire Line
	8100 5050 8100 5150
Wire Wire Line
	6650 4250 7200 4250
Wire Wire Line
	7400 4550 7200 4550
Wire Wire Line
	7200 4550 7200 4250
Connection ~ 7200 4250
Wire Wire Line
	7200 4250 7400 4250
Wire Wire Line
	7700 4250 8550 4250
Wire Wire Line
	7000 3900 7300 3900
Wire Wire Line
	7350 3400 7300 3400
Wire Wire Line
	7300 3400 7300 3500
Connection ~ 7300 3900
Wire Wire Line
	7300 3900 8750 3900
Wire Wire Line
	7350 3500 7300 3500
Connection ~ 7300 3500
Wire Wire Line
	7300 3500 7300 3900
Wire Wire Line
	8050 3200 8100 3200
Wire Wire Line
	8100 3200 8100 2900
Wire Wire Line
	8100 2900 7850 2900
Wire Wire Line
	9350 3400 9350 3000
Wire Wire Line
	9350 3000 10500 3000
Wire Wire Line
	7000 3200 7000 3500
Wire Wire Line
	7000 3700 7000 3900
$Comp
L fs8205a:FS8205A U8
U 1 1 5EB46409
P 2750 5400
F 0 "U8" V 2263 5300 60  0000 C CNN
F 1 "FS8205A" V 2369 5300 60  0000 C CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 3700 5650 60  0001 C CNN
F 3 "" H 3700 5650 60  0001 C CNN
F 4 "C16052" H 2750 5400 50  0001 C CNN "LCSC"
F 5 "FS8205A" H 2750 5400 50  0001 C CNN "PartNumber"
	1    2750 5400
	0    1    1    0   
$EndComp
$Comp
L tp4056:TP4056 U9
U 1 1 5EB46B29
P 3350 2200
F 0 "U9" H 3350 2737 60  0000 C CNN
F 1 "TP4056" H 3350 2631 60  0000 C CNN
F 2 "PMIC:TP4056_SOP-8-PP" H 3350 2200 60  0001 C CNN
F 3 "" H 3350 2200 60  0000 C CNN
F 4 "C382139" H 3350 2200 50  0001 C CNN "LCSC"
F 5 "TP4056" H 3350 2200 50  0001 C CNN "PartNumber"
	1    3350 2200
	1    0    0    -1  
$EndComp
$Comp
L dw01:DW01 U7
U 1 1 5EB472EE
P 2650 4250
F 0 "U7" H 2675 4687 60  0000 C CNN
F 1 "DW01" H 2675 4581 60  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 2600 3950 60  0001 C CNN
F 3 "" H 2600 3950 60  0001 C CNN
F 4 "C61503" H 2650 4250 50  0001 C CNN "LCSC"
F 5 "DW01A-G" H 2650 4250 50  0001 C CNN "PartNumber"
	1    2650 4250
	1    0    0    -1  
$EndComp
NoConn ~ 3150 5600
NoConn ~ 2150 5600
$Comp
L Device:C_Small C13
U 1 1 5EB609C6
P 3750 4300
F 0 "C13" H 3842 4346 50  0000 L CNN
F 1 "100nF" H 3842 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 3750 4300 50  0001 C CNN
F 3 "~" H 3750 4300 50  0001 C CNN
F 4 "C1525" H 3750 4300 50  0001 C CNN "LCSC"
F 5 "CL05B104KO5NNNC" H 3750 4300 50  0001 C CNN "PartNumber"
	1    3750 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4200 3750 4100
Wire Wire Line
	3300 4550 3300 4300
Wire Wire Line
	3300 4300 3250 4300
Connection ~ 3400 4550
Wire Wire Line
	3400 4550 3300 4550
Wire Wire Line
	3750 4400 3750 4550
Connection ~ 3750 4550
Wire Wire Line
	3750 4550 3400 4550
$Comp
L Device:R_US R30
U 1 1 5EB6ACE5
P 4000 4100
F 0 "R30" V 4200 4100 50  0000 C CNN
F 1 "120" V 4100 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4040 4090 50  0001 C CNN
F 3 "~" H 4000 4100 50  0001 C CNN
F 4 "C25079" H 4000 4100 50  0001 C CNN "LCSC"
F 5 "0402WGF1200TCE" H 4000 4100 50  0001 C CNN "PartNumber"
	1    4000 4100
	0    1    -1   0   
$EndComp
Wire Wire Line
	3850 4100 3750 4100
Connection ~ 3750 4100
Wire Wire Line
	4150 4100 4400 4100
Wire Wire Line
	3750 4550 4400 4550
NoConn ~ 2100 4100
Wire Wire Line
	2150 5200 2150 4850
Wire Wire Line
	2150 4850 2500 4850
Wire Wire Line
	2500 4850 2500 4700
Wire Wire Line
	2800 4850 3150 4850
Wire Wire Line
	3150 4850 3150 5200
Wire Wire Line
	2800 4700 2800 4850
Wire Wire Line
	3150 5300 3250 5300
Wire Wire Line
	3250 5300 3250 5400
Wire Wire Line
	3250 5500 3150 5500
Wire Wire Line
	2150 5300 2050 5300
Wire Wire Line
	2050 5300 2050 5400
Wire Wire Line
	2050 5500 2150 5500
Wire Wire Line
	3250 5400 3400 5400
Wire Wire Line
	3400 5400 3400 4550
Connection ~ 3250 5400
Wire Wire Line
	3250 5400 3250 5500
$Comp
L power:GND #PWR03
U 1 1 5EB84A6D
P 1900 5500
F 0 "#PWR03" H 1900 5250 50  0001 C CNN
F 1 "GND" H 1905 5327 50  0000 C CNN
F 2 "" H 1900 5500 50  0001 C CNN
F 3 "" H 1900 5500 50  0001 C CNN
	1    1900 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 5500 1900 5400
Wire Wire Line
	1900 5400 2050 5400
Connection ~ 2050 5400
Wire Wire Line
	2050 5400 2050 5500
Text HLabel 4250 1950 2    50   UnSpc ~ 0
Battery_In+
$Comp
L Device:R_US R29
U 1 1 5EB90E1A
P 3950 2600
F 0 "R29" V 4150 2600 50  0000 C CNN
F 1 "10k" V 4050 2600 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 3990 2590 50  0001 C CNN
F 3 "~" H 3950 2600 50  0001 C CNN
F 4 "C102759" H 3950 2600 50  0001 C CNN "LCSC"
F 5 "RTT02103JTH" H 3950 2600 50  0001 C CNN "PartNumber"
	1    3950 2600
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5EB921EF
P 3350 2900
F 0 "#PWR04" H 3350 2650 50  0001 C CNN
F 1 "GND" H 3355 2727 50  0000 C CNN
F 2 "" H 3350 2900 50  0001 C CNN
F 3 "" H 3350 2900 50  0001 C CNN
	1    3350 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2750 3950 2850
Wire Wire Line
	3950 2850 3350 2850
Wire Wire Line
	3350 2850 3350 2900
Wire Wire Line
	3350 2600 3350 2850
Connection ~ 3350 2850
Wire Wire Line
	3850 2350 3950 2350
Wire Wire Line
	3950 2350 3950 2450
Wire Wire Line
	4050 2850 3950 2850
Connection ~ 3950 2850
Text HLabel 1050 1950 0    50   UnSpc ~ 0
Ext_In+
Wire Wire Line
	2850 2050 2750 2050
Wire Wire Line
	2750 2050 2750 1950
Wire Wire Line
	2750 1950 2850 1950
Wire Wire Line
	2850 2150 2750 2150
Wire Wire Line
	2750 2150 2750 2050
Connection ~ 2750 2050
$Comp
L Device:LED D8
U 1 1 5EBB5DA4
P 2050 2150
F 0 "D8" H 2200 2200 50  0000 C CNN
F 1 "RLED" H 2050 2050 50  0000 C CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2050 2150 50  0001 C CNN
F 3 "~" H 2050 2150 50  0001 C CNN
F 4 "C205446" H 2050 2150 50  0001 C CNN "LCSC"
F 5 "ORH-R36G" H 2050 2150 50  0001 C CNN "PartNumber"
	1    2050 2150
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D9
U 1 1 5EBB6CDA
P 2050 2450
F 0 "D9" H 2200 2400 50  0000 C CNN
F 1 "BLED" H 2050 2550 50  0000 C CNN
F 2 "Diode_SMD:D_0603_1608Metric" H 2050 2450 50  0001 C CNN
F 3 "~" H 2050 2450 50  0001 C CNN
F 4 "C193191" H 2050 2450 50  0001 C CNN "LCSC"
F 5 "ORH-B36G" H 2050 2450 50  0001 C CNN "PartNumber"
	1    2050 2450
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R27
U 1 1 5EBC14CC
P 2450 2150
F 0 "R27" V 2650 2150 50  0000 C CNN
F 1 "1k" V 2550 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2490 2140 50  0001 C CNN
F 3 "~" H 2450 2150 50  0001 C CNN
F 4 "C11702" H 2450 2150 50  0001 C CNN "LCSC"
F 5 "0402WGF1001TCE" H 2450 2150 50  0001 C CNN "PartNumber"
	1    2450 2150
	0    1    -1   0   
$EndComp
$Comp
L Device:R_US R28
U 1 1 5EBC1E57
P 2450 2450
F 0 "R28" V 2650 2450 50  0000 C CNN
F 1 "1k" V 2550 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2490 2440 50  0001 C CNN
F 3 "~" H 2450 2450 50  0001 C CNN
F 4 "C11702" H 2450 2450 50  0001 C CNN "LCSC"
F 5 "0402WGF1001TCE" H 2450 2450 50  0001 C CNN "PartNumber"
	1    2450 2450
	0    1    -1   0   
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5EBC4824
P 1350 2300
F 0 "C11" H 1442 2346 50  0000 L CNN
F 1 "100nF" H 1442 2255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 1350 2300 50  0001 C CNN
F 3 "~" H 1350 2300 50  0001 C CNN
F 4 "C1525" H 1350 2300 50  0001 C CNN "LCSC"
F 5 "CL05B104KO5NNNC" H 1350 2300 50  0001 C CNN "PartNumber"
	1    1350 2300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2700 2350 2850 2350
Wire Wire Line
	2600 2150 2700 2150
Wire Wire Line
	2700 2150 2700 2250
Wire Wire Line
	2700 2250 2850 2250
Wire Wire Line
	2600 2450 2700 2450
Wire Wire Line
	2700 2450 2700 2350
Wire Wire Line
	2200 2150 2300 2150
Wire Wire Line
	2200 2450 2300 2450
Connection ~ 2750 1950
Connection ~ 1650 1950
Wire Wire Line
	1650 1950 1800 1950
Wire Wire Line
	1900 2150 1800 2150
Wire Wire Line
	1800 2150 1800 1950
Connection ~ 1800 1950
Wire Wire Line
	1800 1950 2750 1950
Wire Wire Line
	1900 2450 1800 2450
Wire Wire Line
	1800 2450 1800 2150
Connection ~ 1800 2150
Wire Wire Line
	1650 2850 3350 2850
$Comp
L Switch:SW_SPDT SW2
U 1 1 5EC25530
P 6450 3200
F 0 "SW2" H 6450 3485 50  0000 C CNN
F 1 "SW_BATT_DISCONNECT" H 6450 3394 50  0000 C CNN
F 2 "toggle:LCSC_C136659_HRO_SPDT_6.7x2.6mm_ToggleSwitch" H 6450 3200 50  0001 C CNN
F 3 "~" H 6450 3200 50  0001 C CNN
F 4 "C136659" H 6450 3200 50  0001 C CNN "LCSC"
F 5 "K3-1296S-E2" H 6450 3200 50  0001 C CNN "PartNumber"
	1    6450 3200
	-1   0    0    -1  
$EndComp
Text HLabel 6150 3100 0    50   UnSpc ~ 0
Battery_In+
Wire Wire Line
	6150 3100 6250 3100
Wire Wire Line
	6650 3200 7000 3200
Connection ~ 7000 3200
NoConn ~ 6250 3300
Wire Wire Line
	6650 4500 6800 4500
Wire Wire Line
	6800 4500 6800 5050
Wire Wire Line
	6800 5050 7750 5050
Connection ~ 7750 5050
Wire Wire Line
	6650 4400 6800 4400
Wire Wire Line
	6800 4400 6800 4500
Connection ~ 6800 4500
$Comp
L Device:R_US R31
U 1 1 5EC6C5A1
P 1650 2500
F 0 "R31" V 1850 2500 50  0000 C CNN
F 1 "47k" V 1750 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 1690 2490 50  0001 C CNN
F 3 "~" H 1650 2500 50  0001 C CNN
F 4 "C25792" H 1650 2500 50  0001 C CNN "LCSC"
F 5 "0402WGF4702TCE" H 1650 2500 50  0001 C CNN "PartNumber"
	1    1650 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1650 1950 1650 2350
Wire Wire Line
	1650 2650 1650 2850
Wire Wire Line
	1350 2400 1350 2850
Wire Wire Line
	1350 2850 1650 2850
Connection ~ 1650 2850
Wire Wire Line
	1350 2200 1350 1950
Wire Wire Line
	1350 1950 1650 1950
Wire Wire Line
	1050 1950 1350 1950
Connection ~ 1350 1950
Wire Wire Line
	3850 2250 4050 2250
Wire Wire Line
	4050 2250 4050 2850
$Comp
L Device:R_US R26
U 1 1 5EB87D96
P 1900 4800
F 0 "R26" V 2100 4800 50  0000 C CNN
F 1 "1k" V 2000 4800 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 1940 4790 50  0001 C CNN
F 3 "~" H 1900 4800 50  0001 C CNN
F 4 "C11702" H 1900 4800 50  0001 C CNN "LCSC"
F 5 "0402WGF1001TCE" H 1900 4800 50  0001 C CNN "PartNumber"
	1    1900 4800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1900 4300 2100 4300
Wire Wire Line
	1900 4650 1900 4300
Connection ~ 1900 5400
Wire Wire Line
	1900 4950 1900 5400
Wire Wire Line
	3250 4100 3750 4100
Wire Wire Line
	3850 1950 4250 1950
Wire Wire Line
	8750 3400 9350 3400
Wire Wire Line
	8750 3900 9750 3900
$EndSCHEMATC
