EESchema Schematic File Version 4
EELAYER 30 0
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
Text GLabel 8550 1950 2    50   Input ~ 0
5V
Text GLabel 1850 4950 1    50   Input ~ 0
5V
$Comp
L power:GND #PWR06
U 1 1 6018CE50
P 1850 5550
F 0 "#PWR06" H 1850 5300 50  0001 C CNN
F 1 "GND" H 1855 5377 50  0000 C CNN
F 2 "" H 1850 5550 50  0001 C CNN
F 3 "" H 1850 5550 50  0001 C CNN
	1    1850 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 5550 1850 5450
Wire Wire Line
	1850 5050 1850 4950
$Comp
L Device:R_POT RV3
U 1 1 6018DF95
P 3300 1300
F 0 "RV3" H 3230 1346 50  0000 R CNN
F 1 "PotB" H 3230 1255 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Vishay_T73YP_Vertical" H 3300 1300 50  0001 C CNN
F 3 "~" H 3300 1300 50  0001 C CNN
	1    3300 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 6018EFA6
P 1350 1300
F 0 "RV1" H 1280 1346 50  0000 R CNN
F 1 "PotR" H 1280 1255 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Vishay_T73YP_Vertical" H 1350 1300 50  0001 C CNN
F 3 "~" H 1350 1300 50  0001 C CNN
	1    1350 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV2
U 1 1 6018F437
P 2350 1300
F 0 "RV2" H 2280 1346 50  0000 R CNN
F 1 "PotG" H 2280 1255 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Vishay_T73YP_Vertical" H 2350 1300 50  0001 C CNN
F 3 "~" H 2350 1300 50  0001 C CNN
	1    2350 1300
	1    0    0    -1  
$EndComp
Text GLabel 1600 1300 2    50   Input ~ 0
AnInR
Text GLabel 2600 1300 2    50   Input ~ 0
AnInG
Text GLabel 3550 1300 2    50   Input ~ 0
AnInB
Text GLabel 1350 1050 1    50   Input ~ 0
3.3V
Text GLabel 2350 1050 1    50   Input ~ 0
3.3V
Text GLabel 3300 1050 1    50   Input ~ 0
3.3V
$Comp
L power:GND #PWR01
U 1 1 60190E29
P 1350 1550
F 0 "#PWR01" H 1350 1300 50  0001 C CNN
F 1 "GND" H 1355 1377 50  0000 C CNN
F 2 "" H 1350 1550 50  0001 C CNN
F 3 "" H 1350 1550 50  0001 C CNN
	1    1350 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 601912B1
P 2350 1550
F 0 "#PWR04" H 2350 1300 50  0001 C CNN
F 1 "GND" H 2355 1377 50  0000 C CNN
F 2 "" H 2350 1550 50  0001 C CNN
F 3 "" H 2350 1550 50  0001 C CNN
	1    2350 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 60191487
P 3300 1550
F 0 "#PWR05" H 3300 1300 50  0001 C CNN
F 1 "GND" H 3305 1377 50  0000 C CNN
F 2 "" H 3300 1550 50  0001 C CNN
F 3 "" H 3300 1550 50  0001 C CNN
	1    3300 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1550 1350 1450
Wire Wire Line
	1350 1150 1350 1050
Wire Wire Line
	1500 1300 1600 1300
Wire Wire Line
	2350 1150 2350 1050
Wire Wire Line
	2500 1300 2600 1300
Wire Wire Line
	2350 1550 2350 1450
Wire Wire Line
	3300 1550 3300 1450
Wire Wire Line
	3450 1300 3550 1300
Wire Wire Line
	3300 1150 3300 1050
Text GLabel 1200 5250 0    50   Input ~ 0
start
Wire Wire Line
	1200 5250 1250 5250
Wire Wire Line
	1250 5250 1250 5150
Wire Wire Line
	1250 5150 1350 5150
Wire Wire Line
	1250 5250 1250 5350
Wire Wire Line
	1250 5350 1350 5350
Connection ~ 1250 5250
Text GLabel 2450 5200 1    50   Input ~ 0
notstart
Wire Wire Line
	2350 5250 2450 5250
Text GLabel 1200 4350 0    50   Input ~ 0
start
Text GLabel 1200 4150 0    50   Input ~ 0
out_s
Wire Wire Line
	1200 4150 1350 4150
Wire Wire Line
	1200 4350 1350 4350
Wire Wire Line
	2450 5200 2450 5250
Connection ~ 2450 5250
Text GLabel 2750 5050 0    50   Input ~ 0
TX
Wire Wire Line
	2450 5250 2850 5250
Wire Wire Line
	2750 5050 2850 5050
Wire Wire Line
	3850 5150 3900 5150
Wire Wire Line
	3900 5150 3900 5050
Wire Wire Line
	3900 5050 4000 5050
Wire Wire Line
	3900 5150 3900 5250
Wire Wire Line
	3900 5250 4000 5250
Connection ~ 3900 5150
Wire Wire Line
	5000 5150 5050 5150
Wire Wire Line
	5050 5150 5050 4450
Wire Wire Line
	5050 4450 5100 4450
Wire Wire Line
	5100 4250 2350 4250
$Comp
L 4xxx_IEEE:4011 U1
U 2 1 601A142D
P 1850 4250
F 0 "U1" H 2100 4550 50  0000 L CNN
F 1 "4011" H 2100 4450 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 1850 4250 50  0001 C CNN
F 3 "" H 1850 4250 50  0001 C CNN
	2    1850 4250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 601B1E58
P 6700 4450
F 0 "J2" H 6780 4492 50  0000 L CNN
F 1 "ChoixDMX" H 6780 4401 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 6700 4450 50  0001 C CNN
F 3 "~" H 6700 4450 50  0001 C CNN
	1    6700 4450
	1    0    0    1   
$EndComp
$Comp
L 4xxx_IEEE:4011 U1
U 4 1 601B2BA9
P 5850 5300
F 0 "U1" H 6100 5600 50  0000 L CNN
F 1 "4011" H 6100 5500 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 5850 5300 50  0001 C CNN
F 3 "" H 5850 5300 50  0001 C CNN
	4    5850 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 5200 5300 5200
Wire Wire Line
	5300 5200 5300 5400
Wire Wire Line
	5300 5400 5350 5400
Wire Wire Line
	6350 5300 6400 5300
Wire Wire Line
	5300 5200 5300 4700
Wire Wire Line
	5300 4700 6100 4700
Wire Wire Line
	6100 4700 6100 4350
Connection ~ 5300 5200
Connection ~ 6100 4350
Text GLabel 6450 4450 0    50   Input ~ 0
DMX_TX
Wire Wire Line
	6100 4350 6500 4350
Wire Wire Line
	6500 4450 6450 4450
Wire Wire Line
	6500 4550 6400 4550
Wire Wire Line
	6400 4550 6400 5300
$Comp
L power:GND #PWR09
U 1 1 601DB75A
P 5850 5600
F 0 "#PWR09" H 5850 5350 50  0001 C CNN
F 1 "GND" H 5855 5427 50  0000 C CNN
F 2 "" H 5850 5600 50  0001 C CNN
F 3 "" H 5850 5600 50  0001 C CNN
	1    5850 5600
	1    0    0    -1  
$EndComp
Text GLabel 5850 5000 1    50   Input ~ 0
5V
Wire Wire Line
	5850 5100 5850 5000
Wire Wire Line
	5850 5600 5850 5500
Text GLabel 9850 2350 0    50   Input ~ 0
out_s
Text GLabel 8550 2950 2    50   Input ~ 0
AnInR
Text GLabel 7850 2850 0    50   Input ~ 0
AnInG
Text GLabel 7850 2950 0    50   Input ~ 0
AnInB
Wire Wire Line
	9850 2350 9950 2350
Text GLabel 1850 3950 1    50   Input ~ 0
5V
Text GLabel 3350 4850 1    50   Input ~ 0
5V
Text GLabel 4500 4850 1    50   Input ~ 0
5V
Text GLabel 5600 4050 1    50   Input ~ 0
5V
$Comp
L power:GND #PWR0101
U 1 1 601FA927
P 3350 5450
F 0 "#PWR0101" H 3350 5200 50  0001 C CNN
F 1 "GND" H 3355 5277 50  0000 C CNN
F 2 "" H 3350 5450 50  0001 C CNN
F 3 "" H 3350 5450 50  0001 C CNN
	1    3350 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 601FABBA
P 4500 5450
F 0 "#PWR0102" H 4500 5200 50  0001 C CNN
F 1 "GND" H 4505 5277 50  0000 C CNN
F 2 "" H 4500 5450 50  0001 C CNN
F 3 "" H 4500 5450 50  0001 C CNN
	1    4500 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 601FADED
P 1850 4550
F 0 "#PWR0103" H 1850 4300 50  0001 C CNN
F 1 "GND" H 1855 4377 50  0000 C CNN
F 2 "" H 1850 4550 50  0001 C CNN
F 3 "" H 1850 4550 50  0001 C CNN
	1    1850 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 601FB0CB
P 5600 4650
F 0 "#PWR0104" H 5600 4400 50  0001 C CNN
F 1 "GND" H 5605 4477 50  0000 C CNN
F 2 "" H 5600 4650 50  0001 C CNN
F 3 "" H 5600 4650 50  0001 C CNN
	1    5600 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 4650 5600 4550
Wire Wire Line
	5600 4150 5600 4050
Wire Wire Line
	1850 3950 1850 4050
Wire Wire Line
	1850 4450 1850 4550
Wire Wire Line
	3350 4950 3350 4850
Wire Wire Line
	3350 5450 3350 5350
Wire Wire Line
	4500 5450 4500 5350
Wire Wire Line
	4500 4950 4500 4850
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J4
U 1 1 60418270
P 8150 1950
F 0 "J4" H 8200 3067 50  0000 C CNN
F 1 "MORPHO_G" H 8200 2976 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Vertical" H 8150 1950 50  0001 C CNN
F 3 "~" H 8150 1950 50  0001 C CNN
	1    8150 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J5
U 1 1 6041D09F
P 10150 1950
F 0 "J5" H 10200 3067 50  0000 C CNN
F 1 "MORPHO_D" H 10200 2976 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Vertical" H 10150 1950 50  0001 C CNN
F 3 "~" H 10150 1950 50  0001 C CNN
	1    10150 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 1950 8450 1950
Text GLabel 8550 1850 2    50   Input ~ 0
3.3V
$Comp
L power:GND #PWR03
U 1 1 604230A6
P 7850 2050
F 0 "#PWR03" H 7850 1800 50  0001 C CNN
F 1 "GND" H 7855 1877 50  0000 C CNN
F 2 "" H 7850 2050 50  0001 C CNN
F 3 "" H 7850 2050 50  0001 C CNN
	1    7850 2050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 60423B33
P 8550 2050
F 0 "#PWR010" H 8550 1800 50  0001 C CNN
F 1 "GND" H 8555 1877 50  0000 C CNN
F 2 "" H 8550 2050 50  0001 C CNN
F 3 "" H 8550 2050 50  0001 C CNN
	1    8550 2050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 60423F1F
P 8550 2150
F 0 "#PWR011" H 8550 1900 50  0001 C CNN
F 1 "GND" H 8555 1977 50  0000 C CNN
F 2 "" H 8550 2150 50  0001 C CNN
F 3 "" H 8550 2150 50  0001 C CNN
	1    8550 2150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8450 2050 8550 2050
Wire Wire Line
	8550 2150 8450 2150
Wire Wire Line
	7950 2050 7850 2050
Wire Notes Line
	7550 750  10900 750 
Wire Notes Line
	10900 750  10900 3100
Wire Notes Line
	10900 3100 7550 3100
Wire Notes Line
	7550 3100 7550 750 
Text Notes 8900 850  0    50   ~ 0
Nucleo L476RG
Text GLabel 7850 1150 0    50   Input ~ 0
TX
$Comp
L power:GND #PWR013
U 1 1 60444774
P 10550 2050
F 0 "#PWR013" H 10550 1800 50  0001 C CNN
F 1 "GND" H 10555 1877 50  0000 C CNN
F 2 "" H 10550 2050 50  0001 C CNN
F 3 "" H 10550 2050 50  0001 C CNN
	1    10550 2050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10450 2050 10550 2050
Wire Wire Line
	7850 2850 7950 2850
Wire Wire Line
	7850 2950 7950 2950
Wire Wire Line
	8450 2950 8550 2950
Wire Wire Line
	8450 2850 8550 2850
Text GLabel 2250 2300 2    50   Input ~ 0
PitchIn
Wire Wire Line
	2350 6250 2450 6250
Wire Wire Line
	1950 6250 2050 6250
$Comp
L power:GND #PWR08
U 1 1 601C960D
P 1950 6250
F 0 "#PWR08" H 1950 6000 50  0001 C CNN
F 1 "GND" V 1955 6122 50  0000 R CNN
F 2 "" H 1950 6250 50  0001 C CNN
F 3 "" H 1950 6250 50  0001 C CNN
	1    1950 6250
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 601C92C8
P 2200 6250
F 0 "R2" V 1993 6250 50  0000 C CNN
F 1 "120" V 2084 6250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2130 6250 50  0001 C CNN
F 3 "~" H 2200 6250 50  0001 C CNN
	1    2200 6250
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 6350 2450 6350
Text GLabel 2350 6350 0    50   Input ~ 0
5V
Wire Wire Line
	2450 6550 2350 6550
Text GLabel 2350 6550 0    50   Input ~ 0
DMX_TX
Wire Wire Line
	2350 6450 2450 6450
Text GLabel 2350 6450 0    50   Input ~ 0
enable
Wire Wire Line
	3400 6550 3550 6550
Connection ~ 3400 6550
Wire Wire Line
	3400 6250 3950 6250
Connection ~ 3400 6250
$Comp
L Device:R R1
U 1 1 6019E031
P 3400 6400
F 0 "R1" H 3470 6446 50  0000 L CNN
F 1 "120" H 3470 6355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3330 6400 50  0001 C CNN
F 3 "~" H 3400 6400 50  0001 C CNN
	1    3400 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 6350 4000 6350
Connection ~ 3800 6350
Wire Wire Line
	3800 6050 3800 6350
Wire Wire Line
	4600 6050 3800 6050
Wire Wire Line
	4600 6350 4600 6050
Wire Wire Line
	4500 6350 4600 6350
Wire Wire Line
	3950 6250 4000 6250
Connection ~ 3950 6250
Wire Wire Line
	4550 6250 4500 6250
Wire Wire Line
	4550 6100 4550 6250
Wire Wire Line
	3950 6100 4550 6100
Wire Wire Line
	3950 6250 3950 6100
Wire Wire Line
	3950 6450 4000 6450
Connection ~ 3950 6450
Wire Wire Line
	3950 6600 3950 6450
Wire Wire Line
	4500 6600 3950 6600
Wire Wire Line
	4500 6450 4500 6600
Wire Wire Line
	2850 7000 2850 6950
Connection ~ 2850 7000
Wire Wire Line
	3650 6450 3950 6450
Wire Wire Line
	3650 7000 3650 6450
Wire Wire Line
	2850 7000 3650 7000
Wire Wire Line
	3550 6350 3800 6350
Wire Wire Line
	3550 6550 3550 6350
Wire Wire Line
	3250 6550 3400 6550
Wire Wire Line
	3250 6250 3400 6250
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J3
U 1 1 60199F28
P 4200 6350
F 0 "J3" H 4250 6550 50  0000 C CNN
F 1 "To_Dmx" H 4250 6150 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 4200 6350 50  0001 C CNN
F 3 "~" H 4200 6350 50  0001 C CNN
	1    4200 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 7050 2850 7000
Wire Wire Line
	2850 5800 2750 5800
Wire Wire Line
	2850 5850 2850 5800
$Comp
L power:GND #PWR07
U 1 1 6018CA32
P 2850 7050
F 0 "#PWR07" H 2850 6800 50  0001 C CNN
F 1 "GND" H 2855 6877 50  0000 C CNN
F 2 "" H 2850 7050 50  0001 C CNN
F 3 "" H 2850 7050 50  0001 C CNN
	1    2850 7050
	1    0    0    -1  
$EndComp
Text GLabel 2750 5800 0    50   Input ~ 0
5V
$Comp
L Interface_UART:MAX485E U3
U 1 1 6018535A
P 2850 6350
F 0 "U3" H 3050 6700 50  0000 C CNN
F 1 "MAX485" H 2850 6550 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 2850 5650 50  0001 C CNN
F 3 "" H 2850 6400 50  0001 C CNN
	1    2850 6350
	1    0    0    -1  
$EndComp
Wire Notes Line
	700  3400 7350 3400
Wire Notes Line
	7350 3400 7350 6400
Wire Notes Line
	7350 6400 6050 6400
Wire Notes Line
	6050 6400 6050 7500
Wire Notes Line
	6050 7500 700  7500
Wire Notes Line
	700  7500 700  3400
Text Notes 5250 7400 0    50   ~ 0
DMX512 signals
Text GLabel 8550 2250 2    50   Input ~ 0
Vinput
Wire Wire Line
	8450 2250 8550 2250
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 6049F305
P 900 2400
F 0 "J6" H 818 2075 50  0000 C CNN
F 1 "Power" H 818 2166 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-3-2-5.08_1x02_P5.08mm_Horizontal" H 900 2400 50  0001 C CNN
F 3 "~" H 900 2400 50  0001 C CNN
	1    900  2400
	-1   0    0    1   
$EndComp
Text GLabel 1200 2300 2    50   Input ~ 0
Vinput
$Comp
L power:GND #PWR014
U 1 1 604A02F0
P 1200 2400
F 0 "#PWR014" H 1200 2150 50  0001 C CNN
F 1 "GND" H 1205 2227 50  0000 C CNN
F 2 "" H 1200 2400 50  0001 C CNN
F 3 "" H 1200 2400 50  0001 C CNN
	1    1200 2400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1100 2300 1200 2300
Wire Wire Line
	1100 2400 1200 2400
Text GLabel 9850 2550 0    50   Input ~ 0
start
Wire Wire Line
	9950 2550 9850 2550
Wire Wire Line
	7850 1150 7950 1150
Text GLabel 10550 1250 2    50   Input ~ 0
enable
Wire Wire Line
	10450 1250 10550 1250
Wire Wire Line
	8450 1850 8550 1850
$Comp
L 4xxx_IEEE:4011 U2
U 1 1 601A3E2D
P 3350 5150
F 0 "U2" H 3600 5450 50  0000 L CNN
F 1 "4011" H 3600 5350 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 3350 5150 50  0001 C CNN
F 3 "" H 3350 5150 50  0001 C CNN
	1    3350 5150
	1    0    0    -1  
$EndComp
$Comp
L 4xxx_IEEE:4011 U2
U 3 1 601ABF92
P 5600 4350
F 0 "U2" H 5850 4650 50  0000 L CNN
F 1 "4011" H 5850 4550 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 5600 4350 50  0001 C CNN
F 3 "" H 5600 4350 50  0001 C CNN
	3    5600 4350
	1    0    0    -1  
$EndComp
$Comp
L 4xxx_IEEE:4011 U2
U 4 1 601A8B96
P 4500 5150
F 0 "U2" H 4750 5450 50  0000 L CNN
F 1 "4011" H 4750 5350 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 4500 5150 50  0001 C CNN
F 3 "" H 4500 5150 50  0001 C CNN
	4    4500 5150
	1    0    0    -1  
$EndComp
$Comp
L 4xxx_IEEE:4011 U2
U 2 1 6018989A
P 1850 5250
F 0 "U2" H 2100 5550 50  0000 L CNN
F 1 "4011" H 2100 5450 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 1850 5250 50  0001 C CNN
F 3 "" H 1850 5250 50  0001 C CNN
	2    1850 5250
	1    0    0    -1  
$EndComp
Text GLabel 8550 2750 2    50   Input ~ 0
PitchIn_Adapt
Text GLabel 3350 2300 2    50   Input ~ 0
VolumeIn
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 60543545
P 1950 2400
F 0 "J1" H 1868 2075 50  0000 C CNN
F 1 "PitchIn" H 1868 2166 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-3-2-5.08_1x02_P5.08mm_Horizontal" H 1950 2400 50  0001 C CNN
F 3 "~" H 1950 2400 50  0001 C CNN
	1    1950 2400
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 60543695
P 2250 2400
F 0 "#PWR012" H 2250 2150 50  0001 C CNN
F 1 "GND" H 2255 2227 50  0000 C CNN
F 2 "" H 2250 2400 50  0001 C CNN
F 3 "" H 2250 2400 50  0001 C CNN
	1    2250 2400
	0    -1   -1   0   
$EndComp
Text GLabel 8550 2850 2    50   Input ~ 0
VolumeIn_Adapt
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 6054641F
P 3050 2400
F 0 "J7" H 2968 2075 50  0000 C CNN
F 1 "VolumeIn" H 2968 2166 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-3-2-5.08_1x02_P5.08mm_Horizontal" H 3050 2400 50  0001 C CNN
F 3 "~" H 3050 2400 50  0001 C CNN
	1    3050 2400
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 6054647D
P 3350 2400
F 0 "#PWR015" H 3350 2150 50  0001 C CNN
F 1 "GND" H 3355 2227 50  0000 C CNN
F 2 "" H 3350 2400 50  0001 C CNN
F 3 "" H 3350 2400 50  0001 C CNN
	1    3350 2400
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_POT RV4
U 1 1 605467B1
P 1950 2900
F 0 "RV4" H 1880 2946 50  0000 R CNN
F 1 "ReglageVc" H 1880 2855 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Vishay_T73YP_Vertical" H 1950 2900 50  0001 C CNN
F 3 "~" H 1950 2900 50  0001 C CNN
	1    1950 2900
	1    0    0    -1  
$EndComp
Text GLabel 1950 2700 1    50   Input ~ 0
3.3V
$Comp
L power:GND #PWR02
U 1 1 6054698D
P 1950 3100
F 0 "#PWR02" H 1950 2850 50  0001 C CNN
F 1 "GND" H 1955 2927 50  0000 C CNN
F 2 "" H 1950 3100 50  0001 C CNN
F 3 "" H 1950 3100 50  0001 C CNN
	1    1950 3100
	1    0    0    -1  
$EndComp
Text GLabel 3300 3000 2    50   Input ~ 0
PitchDC
$Comp
L Amplifier_Operational:LM358 U4
U 1 1 60546CB6
P 6400 2200
F 0 "U4" H 6400 2567 50  0000 C CNN
F 1 "LM358" H 6400 2476 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 6400 2200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 6400 2200 50  0001 C CNN
	1    6400 2200
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM358 U4
U 3 1 60546DB3
P 4350 1350
F 0 "U4" H 4308 1396 50  0000 L CNN
F 1 "LM358" H 4308 1305 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 4350 1350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 4350 1350 50  0001 C CNN
	3    4350 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 60546EDE
P 4250 1750
F 0 "#PWR016" H 4250 1500 50  0001 C CNN
F 1 "GND" H 4255 1577 50  0000 C CNN
F 2 "" H 4250 1750 50  0001 C CNN
F 3 "" H 4250 1750 50  0001 C CNN
	1    4250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1050 4250 950 
Wire Wire Line
	4250 1750 4250 1650
$Comp
L Device:R R5
U 1 1 6054C8FA
P 5750 1750
F 0 "R5" V 5543 1750 50  0000 C CNN
F 1 "47k" V 5634 1750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5680 1750 50  0001 C CNN
F 3 "~" H 5750 1750 50  0001 C CNN
	1    5750 1750
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 6054CA6A
P 5750 2100
F 0 "R6" V 5957 2100 50  0000 C CNN
F 1 "22k" V 5866 2100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5680 2100 50  0001 C CNN
F 3 "~" H 5750 2100 50  0001 C CNN
	1    5750 2100
	0    -1   -1   0   
$EndComp
Text GLabel 5500 1750 0    50   Input ~ 0
PitchIn
Text GLabel 5500 2100 0    50   Input ~ 0
PitchDC
Wire Wire Line
	2150 2300 2250 2300
Wire Wire Line
	2150 2400 2250 2400
Wire Wire Line
	3250 2300 3350 2300
Wire Wire Line
	3250 2400 3350 2400
Wire Wire Line
	1950 2750 1950 2700
Wire Wire Line
	1950 3100 1950 3050
Wire Wire Line
	5500 1750 5600 1750
Wire Wire Line
	5900 1750 6000 1750
Wire Wire Line
	6000 1750 6000 2100
Wire Wire Line
	6000 2100 6100 2100
Wire Wire Line
	6000 2100 5900 2100
Connection ~ 6000 2100
Wire Wire Line
	5600 2100 5500 2100
$Comp
L Device:R R8
U 1 1 605747AE
P 6450 2650
F 0 "R8" V 6657 2650 50  0000 C CNN
F 1 "22k" V 6566 2650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6380 2650 50  0001 C CNN
F 3 "~" H 6450 2650 50  0001 C CNN
	1    6450 2650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 60574814
P 6000 2900
F 0 "R7" H 5930 2854 50  0000 R CNN
F 1 "47k" H 5930 2945 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5930 2900 50  0001 C CNN
F 3 "~" H 6000 2900 50  0001 C CNN
	1    6000 2900
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR018
U 1 1 60574897
P 6000 3150
F 0 "#PWR018" H 6000 2900 50  0001 C CNN
F 1 "GND" H 6005 2977 50  0000 C CNN
F 2 "" H 6000 3150 50  0001 C CNN
F 3 "" H 6000 3150 50  0001 C CNN
	1    6000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2750 6000 2650
Wire Wire Line
	6000 2650 6300 2650
Wire Wire Line
	6000 2650 6000 2300
Wire Wire Line
	6000 2300 6100 2300
Connection ~ 6000 2650
Wire Wire Line
	6600 2650 6800 2650
Wire Wire Line
	6800 2650 6800 2200
Wire Wire Line
	6800 2200 6700 2200
Wire Wire Line
	6000 3150 6000 3050
Wire Wire Line
	8450 2750 8550 2750
Text GLabel 6900 2200 2    50   Input ~ 0
PitchIn_Adapt
Wire Wire Line
	6900 2200 6800 2200
Connection ~ 6800 2200
$Comp
L Device:R R3
U 1 1 6058D20D
P 4300 2550
F 0 "R3" H 4370 2596 50  0000 L CNN
F 1 "22k" H 4370 2505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4230 2550 50  0001 C CNN
F 3 "~" H 4300 2550 50  0001 C CNN
	1    4300 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 6058D2A5
P 4300 3000
F 0 "R4" H 4370 3046 50  0000 L CNN
F 1 "10k" H 4370 2955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4230 3000 50  0001 C CNN
F 3 "~" H 4300 3000 50  0001 C CNN
	1    4300 3000
	1    0    0    -1  
$EndComp
Text GLabel 4250 2350 0    50   Input ~ 0
VolumeIn
Text GLabel 4400 2750 2    50   Input ~ 0
VolumeIn_Adapt
Wire Wire Line
	4250 2350 4300 2350
Wire Wire Line
	4300 2350 4300 2400
Wire Wire Line
	4300 2850 4300 2750
Wire Wire Line
	4400 2750 4300 2750
Connection ~ 4300 2750
Wire Wire Line
	4300 2750 4300 2700
$Comp
L power:GND #PWR017
U 1 1 6059AC5C
P 4300 3200
F 0 "#PWR017" H 4300 2950 50  0001 C CNN
F 1 "GND" H 4305 3027 50  0000 C CNN
F 2 "" H 4300 3200 50  0001 C CNN
F 3 "" H 4300 3200 50  0001 C CNN
	1    4300 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3200 4300 3150
$Comp
L Amplifier_Operational:LM358 U4
U 2 1 6059FA9D
P 2850 3000
F 0 "U4" H 2850 3367 50  0000 C CNN
F 1 "LM358" H 2850 3276 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket_LongPads" H 2850 3000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 2850 3000 50  0001 C CNN
	2    2850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3100 2500 3100
Wire Wire Line
	2500 3100 2500 3300
Wire Wire Line
	2500 3300 3200 3300
Wire Wire Line
	3200 3300 3200 3000
Wire Wire Line
	3200 3000 3300 3000
Wire Wire Line
	3150 3000 3200 3000
Connection ~ 3200 3000
Wire Wire Line
	2100 2900 2550 2900
Text GLabel 4250 950  1    50   Input ~ 0
Vinput
$Comp
L Connector_Generic:Conn_01x03 J8
U 1 1 619A83DA
P 10300 3550
F 0 "J8" H 10380 3592 50  0000 L CNN
F 1 "MODE_EPI_SMO" H 10380 3501 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 10300 3550 50  0001 C CNN
F 3 "~" H 10300 3550 50  0001 C CNN
	1    10300 3550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J9
U 1 1 619A8DF2
P 10300 4000
F 0 "J9" H 10380 4042 50  0000 L CNN
F 1 "MODE_DEMO_MUSIC" H 10380 3951 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 10300 4000 50  0001 C CNN
F 3 "~" H 10300 4000 50  0001 C CNN
	1    10300 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J10
U 1 1 619A8F5B
P 10300 4450
F 0 "J10" H 10380 4492 50  0000 L CNN
F 1 "CHOIX_THERE" H 10380 4401 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 10300 4450 50  0001 C CNN
F 3 "~" H 10300 4450 50  0001 C CNN
	1    10300 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J11
U 1 1 619A91AC
P 10300 4900
F 0 "J11" H 10380 4942 50  0000 L CNN
F 1 "MODE_AUTRE" H 10380 4851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 10300 4900 50  0001 C CNN
F 3 "~" H 10300 4900 50  0001 C CNN
	1    10300 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 619A962F
P 10000 3450
F 0 "#PWR019" H 10000 3200 50  0001 C CNN
F 1 "GND" H 10005 3277 50  0000 C CNN
F 2 "" H 10000 3450 50  0001 C CNN
F 3 "" H 10000 3450 50  0001 C CNN
	1    10000 3450
	0    1    1    0   
$EndComp
Text GLabel 10000 3550 0    50   Input ~ 0
3.3V
Text GLabel 10000 4000 0    50   Input ~ 0
3.3V
$Comp
L power:GND #PWR020
U 1 1 619A9D68
P 10000 3900
F 0 "#PWR020" H 10000 3650 50  0001 C CNN
F 1 "GND" H 10005 3727 50  0000 C CNN
F 2 "" H 10000 3900 50  0001 C CNN
F 3 "" H 10000 3900 50  0001 C CNN
	1    10000 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR021
U 1 1 619AA19E
P 10000 4350
F 0 "#PWR021" H 10000 4100 50  0001 C CNN
F 1 "GND" H 10005 4177 50  0000 C CNN
F 2 "" H 10000 4350 50  0001 C CNN
F 3 "" H 10000 4350 50  0001 C CNN
	1    10000 4350
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 619AA4BA
P 10000 4800
F 0 "#PWR022" H 10000 4550 50  0001 C CNN
F 1 "GND" H 10005 4627 50  0000 C CNN
F 2 "" H 10000 4800 50  0001 C CNN
F 3 "" H 10000 4800 50  0001 C CNN
	1    10000 4800
	0    1    1    0   
$EndComp
Text GLabel 10000 4450 0    50   Input ~ 0
3.3V
Text GLabel 10000 4900 0    50   Input ~ 0
3.3V
Text GLabel 7850 2650 0    50   Input ~ 0
Mode_Demo
Text GLabel 7850 2550 0    50   Input ~ 0
Mode_Epi
Text GLabel 7850 2450 0    50   Input ~ 0
Choix_There
Text GLabel 7850 2350 0    50   Input ~ 0
Mode_Autre
Wire Wire Line
	7850 2350 7950 2350
Wire Wire Line
	7850 2450 7950 2450
Wire Wire Line
	7850 2550 7950 2550
Wire Wire Line
	7850 2650 7950 2650
Wire Wire Line
	10000 3450 10100 3450
Wire Wire Line
	10000 3650 10100 3650
Wire Wire Line
	10000 3900 10100 3900
Wire Wire Line
	10000 4100 10100 4100
Wire Wire Line
	10000 4350 10100 4350
Wire Wire Line
	10000 4550 10100 4550
Wire Wire Line
	10000 4800 10100 4800
Wire Wire Line
	10000 5000 10100 5000
Text GLabel 10000 5000 0    50   Input ~ 0
Mode_Autre
Text GLabel 10000 4550 0    50   Input ~ 0
Choix_There
Text GLabel 10000 3650 0    50   Input ~ 0
Mode_Epi
Text GLabel 10000 4100 0    50   Input ~ 0
Mode_Demo
Wire Wire Line
	10000 4000 10100 4000
Wire Wire Line
	10000 3550 10100 3550
Wire Wire Line
	10000 4450 10100 4450
Wire Wire Line
	10000 4900 10100 4900
$EndSCHEMATC