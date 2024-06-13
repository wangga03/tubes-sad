from flask import Flask, jsonify
import RPi.GPIO as GPIO
import threading
import time

app = Flask(__name__)

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN)

sensor_data = {"ppm": 0}

# Fungsi sederhana untuk mengonversi status digital ke estimasi PPM
# Ini adalah fungsi dummy; sesuaikan dengan data kalibrasi aktual
def digital_to_ppm(digital_value):
    if digital_value:
        return 200  # Misal, jika gas terdeteksi, anggap 200 PPM
    else:
        return 0  # Jika tidak terdeteksi, 0 PPM

def read_sensor():
    global sensor_data
    while True:
        digital_value = GPIO.input(17)
        ppm = digital_to_ppm(digital_value)
        sensor_data["ppm"] = ppm
        time.sleep(1)

@app.route('/data')
def get_data():
    return jsonify(sensor_data)

if __name__ == '__main__':
    threading.Thread(target=read_sensor).start()
    app.run(host='0.0.0.0', port=5000)
