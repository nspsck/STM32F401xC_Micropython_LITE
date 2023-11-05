# STM32F401xC_Micropython_LITE

This let you build a cutdown version of Micropython running on a STM32F401xC device. Note `pin.csv` has to be changed if you are not using these cheap baords (roughly 2 dollars) on Aliexpress which doesn't made all the pins available.

This is a WIP, nothing is final yet.

## Pins definition
`REPL` is on `USART1`.

| USART  | USART1 | USART2 | USART6 |
| ------ | ------ | ------ | ------ |
| TX     | A9     | A2     | A11    |
| RX     | A10    | A3     | A12    |

| I2C  | I2C1 | I2C2 | I2C3 |
| ---- | ---- | ---- | ---- |
| SCL  | B6   | B10  | A8   |
| SDA  | B7   | B3   | B4   |

| SPI    | SPI1   | SPI2   | SPI3   |
| ------ | ------ | ------ | ------ |
| NSS    | A4     | B12    | A15    |
| SCK    | A5     | B13    | B3     |
| MISO   | A6     | B14    | B4     |
| MOSI   | A7     | B15    | B5     |

| LED  | KEY | USB_DM | USB_DP | SWDIO | SWCLK |
| ---- | --- | ------ | ------ | ----- | ----- |
| C13  | A0  | PA11   | PA12   | PA13  | PA14  |

## Available modules

As you can tell by the name, this board definition does not provide you all the default functionalities that a usual Micropython build would have offered. For the sake of reducing firmware size to fit Micropython on the 256KB flash, some modules was removed and some's functionality has been reduced.

Available modules are (printed by `help('modules')`):
```python
__main__          errno             micropython       struct
array             gc                os                sys
binascii          io                pyb               time
builtins          machine           random
```

### Removed modules
- `socket`: mainly used for network.
- `network`: provides network funcionality.
- `onewire`: provides a onewire communication protocol.
- `stm`: provides STM32 registers, you can still modify registers with `machine` module.
- `heapq`: heap queue (a data structure).
- `framebuf`: a framebuffer class used to provide minimum drawing/texting functionalities for the display.
- `hashlib`: provides `sha256` hashing functionalities.
- `json`: provides `.json`-file related functionalities.
- `platform`: prints building and general information about the firmware.
- `math` and `cmath`: provides mathematical functions and constans.
- `collections`: collections (a data structure).
- `re`: regular expression functionalities.
- `deflate`: allows compression and decompression of binary data with the DEFLATE algorithm.
- `select`: provides functions to efficiently wait for events on multiple streams.
- `asyncio`: a asynchronous I/O scheduler.
- `uctypes`: allows to access binary data in a structured way.
### Reduced modules
- `pyb`: lost legacy contents i.e. `SPI`, `I2C`, `info`, etc. Tho all these functions are more or less duplicated.
- `binascii`: lost `crc32`.
### Removed functionalities
- All THUMB emitters are removed now. (`@micropython.native`, `@micropython.viper` no longer available.)
- `GOTO` compilation has been removed, this drops the performance by roughly 10%.

## Storage and Filesystem

This build provides you `32KB` of storage for both filesystem and file storage and `208KB` for the firmware `.text`. Due to the nature of `FAT`, the first sector of size `16KB` is used for the filesystem, hence you only have `16KB` of space to store your codes.

## How to build
### Vanilla
First of all, you have to have a linux enviroment and get the compilers.
```shell
sudo apt-get -y install gcc-arm-none-eabi build-essential
```
After that, open the terminal and clone the official Micropython repo:
```shell
git clone https://github.com/micropython/micropython.git
cd micropython
git submodule update --init --recursive
cd mpy-cross
make -j
```
Copy `STM32F401xC` to the `micropython/ports/stm32/boards` folder. To build the firmware, make sure you are in the `micropython/ports/stm32` folder, and type the following:
```shell
make -j LTO=1 BOARD=STM32F401xC # With recent update, the LTO=1 can be omitted.
```

## How to Flash

### Flashing the firmware
You can flash the firmware by following the official guide on i.e. [https://micropython.org/download/NUCLEO_F411RE/](https://micropython.org/download/NUCLEO_F411RE/) for both `.hex` and `.dfu` file.

### Mass erase

`st-flash`:
```shell
st-flash erase
```

`STM32CubeProgrammer`:
```shell
STM32_Programmer.sh -c port=SWD -e all
```

`dfu-util`:
```shell
# You can save the following as a file and run it with: sh file.sh
#!/bin/sh
set -x
echo -e -n "\xff" > ff.bin
dfu-util -s :mass-erase:force -a 0 -d 0483:df11 -D ff.bin
```

### STM32CubeProgrammer

In addtion to that, if you were using `STM32CubeProgrammer` with a GUI, everything should be very straight foward. And this is the most easy way to flash your device imo. There are 3 options available: `ST-Link, UART and USB` each corresponding to using a `st-link`, using a `uart-bridge` and using the built-in `dfu`.
