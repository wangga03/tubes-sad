from flask import Flask, jsonify
import RPi.GPIO as GPIO
import threading
import time

app = Flask(__name__)

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN)

sensor_status = {"gas_detected": False}

def read_sensor():
    global sensor_status
    while True:
        sensor_status["gas_detected"] = GPIO.input(17)
        time.sleep(1)

@app.route('/data')
def get_data():
    return jsonify(sensor_status)

if __name__ == '__main__':
    threading.Thread(target=read_sensor).start()
    app.run(host='0.0.0.0', port=5000)
