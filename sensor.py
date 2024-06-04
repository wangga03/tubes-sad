from flask import Flask, jsonify
import serial

app = Flask(__name__)

# Inisialisasi objek Serial dengan port yang sesuai dengan port Arduino di laptop Anda
ser = serial.Serial('/dev/ttyACM0', 9600)  # Ganti '/dev/ttyACM0' dengan port yang sesuai di laptop Anda

def read_serial():
    while True:
        data = ser.readline().decode().strip()
        data = data.split()
        sensor_value = data[0]
        alkohol_ppm = data[1]
        voltage = data[2]
        yield jsonify(sensor_value=sensor_value, alkohol_ppm=alkohol_ppm, voltage=voltage)

@app.route('/stream')
def stream():
    return read_serial()

if __name__ == '__main__':
    app.run(debug=True)
