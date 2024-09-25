
# QuantumLeaps-blinky-QSpy
#### Basic blinking LED running on a Nucleo-64 board.
In this example the LED starts blinking immediately after the MCU boot, QSpy can be used to debug the state machine.

#### QSpy connection
Connect the QSpy tool and Nucleo board through the serial port at `115200bps`.

> [For Linux] sudo ./qspy -c /dev/ttyACMx -b 115200

# Folders



## UML diagrams
![State diagram](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuUAArefLqDMrKt3AoSpBhlJCoopXuk92SC1oIM2kVreQ5nUKcQTWfH1IMfIdK9AHgk3ZwgAGdmUKWod3a0JgH6Y56ObGcvcRcbzQWj2Fh28FIG6NGsfU2j3L0000)
