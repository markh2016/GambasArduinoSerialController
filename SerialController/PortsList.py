#!/usr/bin/env python3
import serial.tools.list_ports

class SerialPortManager:
    def __init__(self):
        self.available_ports = self.get_available_serial_ports()

    def get_available_serial_ports(self):
        ports = serial.tools.list_ports.comports()
        return [p.device for p in ports]

    def list_available_ports(self):
        return self.available_ports

if __name__ == "__main__":
    port_manager = SerialPortManager()
    available_ports = port_manager.list_available_ports()
    for port in available_ports:
        print(f"{port}")
