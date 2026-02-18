# System Overview

## Architecture

The Smart Air Purifier consists of three subsystems that work together:

```
+-----------------+       WiFi (HTTP POST)       +------------------+
|   ESP32-C3      | ---------------------------> |   Raspberry Pi 4 |
|   (Firmware)    | <--- (response w/ commands)  |   (Server)       |
+-----------------+                              +------------------+
  |         |                                      |
  | I2C     | PWM                                  | Cloud Server /
  v         v                                      | WebSocket
+-------+ +----------------+                    +------------------+
| SEN54 | | Arctic P12 Max |                    |   Mobile App     |
|Sensor | | Fans (x2)      |                    |   (React Native) |
+-------+ +----------------+                    +------------------+
```

### 1. ESP32-C3 Firmware

The ESP32-C3 microcontroller is the real-time controller responsible for:

- **Sensor reading:** Communicates with the SEN54 air quality sensor over I2C to collect PM1.0, PM2.5, PM4.0, PM10, VOC index, temperature, and humidity every 1 second.
- **Fan control:** Drives two Arctic P12 Max fans via 25kHz PWM. Fan speed is automatically determined by PM2.5 concentration using EPA AQI breakpoint thresholds.
- **Data transmission:** Sends sensor readings and current fan speed to the Raspberry Pi 4 as JSON over WiFi HTTP POST every 5 seconds.

### 2. Raspberry Pi 4 Server

The RPi4 runs a Python FastAPI server that acts as the data hub:



### 3. Mobile App

A React Native (Expo) application that provides the user interface:



---

## Hardware Components

| Component | Quantity | Purpose |
|:---|:---:|:---|
| ESP32-C3 DevKit | 1 | Microcontroller for sensor reading and fan control |
| Raspberry Pi 4 | 1 | Server for data storage and mobile app API |
| Sensirion SEN54 | 1 | Air quality sensor (PM, VOC, temp, humidity) |
| Arctic P12 Max | 2 | PWM-controllable fans for air circulation |
| HEPA H13 Filter | 1 | Particulate filtration |
| Buck Regulator | 1 | Voltage regulation for mixed-voltage components |
| Step-Down Voltage Regulator | 1 | 12V to 5V/3.3V conversion |

---

## Communication Protocol

### ESP32 to RPi4

The ESP32 sends sensor data via HTTP POST over the local WiFi network every 5 seconds:

**Request:**
```
POST /api/v1/sensor-data
Content-Type: application/json

{
  
}
```

**Response (with optional fan command):**
```json
{
 
}
```

Fan commands from the mobile app are piggybacked in the POST response, eliminating the need for the ESP32 to poll a separate endpoint.

### RPi4 to Mobile App



## Remote Access

The current architecture operates entirely on a local WiFi network. This means the mobile app can only receive air quality updates when the user's phone is connected to the same network as the RPi4. If a user is away from the purifier's location (e.g., David is away from his makerspace), the app cannot reach the RPi4 or ESP32 directly.

To enable remote monitoring, the RPi4 would need to forward data to a cloud service. The mobile app would then pull from the cloud instead of the local server. Possible approaches:

| Approach | Description | Trade-off |
|:---|:---|:---|
| Cloud relay (Firebase, AWS IoT, MQTT broker) | RPi4 pushes data to a cloud endpoint; app reads from cloud | Most practical; requires internet and a cloud account |
| Port forwarding / Dynamic DNS | Expose the RPi4 API to the public internet | Simple but has security risks; depends on router config |
| VPN (Tailscale, WireGuard) | Place RPi4 and phone on the same virtual private network | No cloud needed; requires setup on both ends |

### Cloud Service Comparison

#### Firebase (Google)

**Pros:**
- Realtime Database pushes updates to mobile clients instantly via SDK — no polling needed
- Generous free tier (1GB stored, 10GB/month transfer)
- Mature React Native SDK with minimal setup
- No custom server code needed — RPi4 pushes via REST API, app subscribes via SDK

**Cons:**
- Vendor lock-in to Google ecosystem
- Pricing can spike with frequent writes (every 5 seconds adds up over time)
- Limited query capabilities compared to a relational database
- NoSQL/JSON data structure can get unwieldy for time-series data

#### AWS IoT Core

**Pros:**
- Purpose-built for IoT devices — native MQTT support, device shadows, rules engine
- Scales to millions of devices
- Can pipe data into DynamoDB, S3, or Lambda for processing
- Industry standard for commercial IoT products

**Cons:**
- Steep learning curve (IAM roles, policies, certificates, thing registries)
- Overkill for a single-device project
- Free tier limited to 250k messages/month for 12 months, then pay-per-message
- More glue code required for mobile app integration

#### MQTT Broker (HiveMQ Cloud, Mosquitto, Adafruit IO)

**Pros:**
- MQTT is the standard IoT protocol — lightweight, low-bandwidth, pub/sub model
- HiveMQ Cloud free tier: 100 connections, 10GB/month
- Adafruit IO is beginner-friendly with built-in dashboards
- ESP32 has excellent MQTT library support (`PubSubClient`, `AsyncMqttClient`)

**Cons:**
- MQTT alone does not store data — a separate database is needed for history
- Adafruit IO free tier is very limited (30 data points/minute, 5 feeds)
- Mobile app needs an MQTT client library, which is less common than REST
- HiveMQ requires managing your own data persistence

#### Supabase

**Pros:**
- Open-source Firebase alternative backed by a real Postgres database
- SQL queries for historical data are far more powerful than Firebase
- Free tier: 500MB database, 5GB bandwidth, 2 projects
- REST API auto-generated from table schema — RPi4 or ESP32 can POST directly
- Realtime subscriptions for the mobile app

**Cons:**
- Smaller community than Firebase or AWS
- Not specifically designed for IoT — no device management features
- Realtime feature can have slightly higher latency than Firebase


---

## Pin Configuration (ESP32-C3)



---

## Fan Speed Auto-Control

Fan speed is determined by PM2.5 concentration using EPA AQI breakpoints:

