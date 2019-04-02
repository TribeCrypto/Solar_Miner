# Solar_Miner simple automation test program
Analog Input Voltage Pin: A0
Digital Output Pin: Pin 12
I am also switching LED on Pin 13 ON/OFF

Calculations:
With 10K, 4.7K Voltage divider, when you take voltage off of 4.7K, following is the rough voltage that gets fed to Arduino Input.

Voltage -- Arduino Input from 4.7K
12.0V -- 3.836V
12.5V -- 3.996V Approx 4Volts

3.83 and 4.0V are used for switching between ON/OFF states.
Serial Monitor at 9600 baud shows rough voltage.
