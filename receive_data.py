import requests
import time

def get_sensor_data():
    """
    Mengambil data sensor dari server Flask.
    """
    url = "http://alamat_ip_raspberry_pi:5000"  # Ganti dengan alamat IP Raspberry Pi
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        return data
    else:
        print("Gagal mengambil data:", response.status_code)
        return None

def main():
    try:
        while True:
            data = get_sensor_data()
            if data:
                adc_value = data["adc_value"]
                alcohol_level = data["alcohol_level"]
                print("Nilai ADC:", adc_value, "Kadar Alkohol:", alcohol_level)
            time.sleep(1)  # Mengambil data setiap detik
    except KeyboardInterrupt:
        print("Aplikasi dihentikan.")

if __name__ == "__main__":
    main()
