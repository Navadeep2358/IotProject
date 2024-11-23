# Air Pollution Monitoring System 🌍

This project is an **IoT-based Air Pollution Monitoring System** that provides real-time data about the surrounding air quality, temperature, and humidity. It is designed to detect polluted air and alert users with a warning system. The system also displays environmental data such as temperature and humidity on an LCD screen for better awareness.

---

## 🌟 Features
- **Air Quality Monitoring**: Uses an MQ2 gas sensor to detect air pollution levels.
- **Temperature and Humidity Measurement**: Utilizes a DHT11 sensor to capture environmental data.
- **Visual and Audio Alerts**:
  - Red, green, and blue LEDs indicate different pollution levels.
  - A buzzer sounds an alarm when air pollution exceeds safe thresholds.
- **LCD Display**: Shows temperature, humidity, and air quality readings in real time.

---

## 🛠️ Components Used
### Sensors:
- **MQ2 Gas Sensor**: For air quality detection.
- **DHT11 Sensor**: For temperature and humidity measurement.

### Microcontroller:
- **Arduino-based system**: To process and control the components.

### Indicators:
- **LEDs**:
  - **Red LED**: Indicates high pollution levels.
  - **Blue LED**: Indicates moderate pollution levels.
  - **Green LED**: Indicates good air quality.
- **Buzzer**: Provides audio alerts for high pollution levels.

### Display:
- **16x2 I2C LCD**: Presents real-time temperature, humidity, and air quality data.

---

## 🔧 How It Works
1. The **MQ2 sensor** measures air quality, while the **DHT11 sensor** records temperature and humidity.
2. Real-time readings are displayed on the **LCD screen**.
3. Based on the air quality:
   - **Green LED**: Air quality is good.
   - **Blue LED**: Moderate pollution.
   - **Red LED**: High pollution levels, triggering the **buzzer** for a warning.

