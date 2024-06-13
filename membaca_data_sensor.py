import RPi.GPIO as GPIO
import time

# Konfigurasi pin GPIO Raspberry Pi
ANALOG_PIN = 7  # Ganti dengan nomor pin analog yang Anda gunakan

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

def main():
    try:
        GPIO.setmode(GPIO.BOARD)  # Mode GPIO menggunakan nomor pin fisik Raspberry Pi
        while True:
            adc_value = read_analog(ANALOG_PIN)
            alcohol_level = convert_to_alcohol_level(adc_value)
            print("Nilai ADC: {}, Kadar Alkohol: {:.2f}".format(adc_value, alcohol_level))
            time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()  # Membersihkan pin GPIO saat program dihentikan

if __name__ == "__main__":
    main()
