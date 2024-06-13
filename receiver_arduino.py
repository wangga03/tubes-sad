import serial

# Inisialisasi objek Serial dengan port yang sesuai dengan port Arduino di laptop Anda
ser = serial.Serial('/dev/ttyACM0', 9600)  # Ganti 'COM3' dengan port yang sesuai di laptop Anda

try:
    while True:
        # Baca data dari port serial
        data = ser.readline().decode().strip()
        data = data.split()
        print("====================================================")
        print(f"Sensor Value : {data[0]}\nAlkohol PPM : {data[1]}\nVoltage : {data[2]}")
        print("====================================================")
except KeyboardInterrupt:
    print("Program berhenti.")
    ser.close()
