# USBino
#### Developed by Md. Khairul Hasan, 2012

The code is released under the GNU General Public License.
_________
[![Build Status](https://travis-ci.org/Lauszus/USBino.svg?branch=master)](https://travis-ci.org/Lauszus/USBino)

This is a USBino third-party hardware add-on for the Arduino IDE.

To use this add-on simply add the following url: <https://raw.githubusercontent.com/khairulhasanmd/USBino/master/package_khairulhasanmd_usbino_index.json> to the Arduino boards manager. Please see the following page for more information: <https://learn.adafruit.com/add-boards-arduino-v164>.

Advanced users can install the hardware add-on manually by creating a folder named "hardware" inside your sketchbook directory. Now move the USBino directory inside that folder. The structure would look like this:

* Arduino/
	* hardware/
		* USBino/
			* avr/
			* bootloaders/
			* variants/
			* README.md
			* boards.txt

## Board and firmware

The board uses USBaspLoader firmware to upload code to the chip. The source code can be found [here](https://github.com/khairulhasanmd/USBaspLoader-Atmega32) for now. Only supports the following two chips: Atmega32 and Atmega16.

For more information see the following site: [http://www.arduino.cc/en/Guide/Environment#thirdpartyhardware](http://www.arduino.cc/en/Guide/Environment#thirdpartyhardware)
or send me an email at <a href="mailto:khairulhasanmd@gmail.com?Subject=USBino">khairulhasanmd@gmail.com</a>.
