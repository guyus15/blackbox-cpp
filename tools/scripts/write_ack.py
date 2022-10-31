# write_ack.py
# Can be used to let the panel know to stop sending the same packet in
# the case where the program fails to during development.
# Requires pyserial: 'python -m pip install pyserial'

import serial

ACK = 0x06

with serial.Serial(port="COM8",
                    baudrate=115200,
                    timeout=0,
                    bytesize=serial.EIGHTBITS,
                    parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE) as ser:
    ser.write([ACK])