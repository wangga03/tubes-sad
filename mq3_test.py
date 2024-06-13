from flask import Flask, jsonify
import RPi.GPIO as GPIO
import time

# Konfigurasi pin GPIO Raspberry Pi
ANALOG_PIN = 7  # Ganti dengan nomor pin analog yang Anda gunakan

app = Flask(__name__)

def read_analog(pin):
    """
    Membaca nilai analog dari pin GPIO pada Raspberry Pi.
    """
    GPIO.setup(pin, GPIO.IN)
    adc_value = GPIO.input(pin)
    return adc_value

def convert_to_alcohol_level(adc_value):
    """
    Mengonversi nilai ADC menjadi kadar alkohol.
    Di sini Anda akan memerlukan kalibrasi berdasarkan karakteristik sensor MQ-3.
    """
    # Misalnya, Anda dapat menggunakan formula linier untuk mengonversi nilai ADC menjadi kadar alkohol
    # Anda perlu mengganti nilai-nilai konstanta dengan nilai-nilai yang sesuai dari kalibrasi sensor Anda.
    alcohol_level = adc_value * 0.1  # Contoh sederhana, ganti dengan rumus yang sesuai
    return alcohol_level

@app.route('/')
def index():
    adc_value = read_analog(ANALOG_PIN)
    alcohol_level = convert_to_alcohol_level(adc_value)
    return jsonify({"adc_value": adc_value, "alcohol_level": alcohol_level})

if __name__ == "__main__":
    try:
        GPIO.setmode(GPIO.BOARD)  # Mode GPIO menggunakan nomor pin fisik Raspberry Pi
        app.run(host='127.0.0.1', port=5000)  # Menjalankan Flask pada alamat IP 0.0.0.0 dan port 5000
    except KeyboardInterrupt:
        GPIO.cleanup()  # Membersihkan pin GPIO saat program dihentikan
