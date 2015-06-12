# Project
Ethernet based Internet clock

Internet Clock
Abhijit Govindaraju    Ajay Krishna Sreehari

This project uses NTP protocol time server to set the correct time by using the internet. 
Background - 
Manually setting clocks on all your electronic devices is such a pain. They all seem to have a different user pushbutton interface and if you don't have the manual handy, trial and error may be required. Some clocks automatically sync using a special radio time signal from an atomic clock time standard. WWV is one such example of this radio signal that is broadcast in the United States and there are even low cost ICs available to pick up this signal, but it might take several days for them to receive a strong signal indoors.
Using NTP Client - 
If an embedded device has a network connection, it can be used to set the time. This Internet of Things example features a clock that is automatically set to the correct time using a network time protocol (NTP) time server on the internet. It combines two existing cookbook code examples, NTP Client and Text LCD with a small amount of additional code.
List of Parts needed – 
•	RJ45 Ethernet Magjack 
•	Breadboard
•	Jumper Wires
•	Mbed LPC1768
•	Serial Miniature LCD Module – uLCD-144-G2 GFX

Observations – 
Before anything we need to connect the Ethernet cable to the board. Once we load the code and press the mbed reset button, I see that the LCD comes up and I see the time display on the LCD breakout board.
