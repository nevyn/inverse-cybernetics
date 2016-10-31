# wat.

Project Inverse Cybernetics Mk I, aka `cybersting`. Instead of teaching a computer how to talk to a human... teach a human how to talk to a computer through direct computer-to-human connections (eight in each direction).

# Notes

* [El sequencer data sheet](http://cdn.sparkfun.com/datasheets/Components/EL/SparkFun_EL_Sequencer_v23.pdf)
* To trigger pin 4, send H (01001000)

## I2C

So let's use i2c to hook up the el shield to a bean+. Does the el sequencer have i2c? yes it does. On pins 4 and 5.

* A4 = SDA 
* A5 = SCL

* [Everything I have ever wanted to know about i2c](https://learn.sparkfun.com/tutorials/i2c).
* [Wire ardu lib](https://www.arduino.cc/en/Reference/Wire) for i2c comms

# Dev diary

## 20161030

Ok so the first idea came to me as I was playing with the EL Sequencer board for burning man, and getting stinged by its 100 volt circuits (from a 5v inverter, very low ampere) as they touched my skin. What if I could trigger very very short bursts of 100V to sting me enough to feel the signal, but not enough to hurt? That'd be great, because then we have a solid state way of communicating with the human. Other alternatives would be solenoids, vibration motors, servos, etc; all bulky and complicated electronics.

The crux here of course is that I have no idea what I'm doing. One such connection to my skin worked fine, but when I attached all of them, they interacted even when all channels were off, giving me a constant eletric tingling across my skin. Yeahhh maybe let's not.

Gonna see if I can maybe have them more spaced out; or if that doesn't work, maybe use vibration motors instead...

![9dc585d8-57f5-46bc-b72a-f2b93dcb368a](https://cloud.githubusercontent.com/assets/34791/19842884/5df219bc-9eda-11e6-9f16-8c9023bd18ff.JPG)
![img_0169 jpg](https://cloud.githubusercontent.com/assets/34791/19842636/0be0825a-9ed8-11e6-96b6-9733080a1f49.jpeg)

