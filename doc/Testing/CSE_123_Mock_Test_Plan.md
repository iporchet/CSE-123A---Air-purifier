#### Test Plans Outline
- Scope:
    * Identify the system and goal/purpose of each test
    * Define parameters for each test and justify inclusion
    * State expectations of the test ( the Hypothesis )
- Administrative Details:
    * Date & Location of Testing
    * Client or Organization that required the Test
    * Who is conducting the Test
- Design of each Test (a.k.a. Design of Experiment)
    * Type of Testing method and its significance
    * List of Test apparatus and measurement equipment, model \#s, etc.
    * Identify 'dependent' and 'independent' variables
    * Number of factors considered (single, double (factorial), etc.)
    * Sampling procedure:
        * How are samples obtained?
        * Number of samples
- Detailed, Step-by-Step procedure to conduct each Test
    * Safety precautions
    * Data collection method
        * Written, recorded, digital, etc.
    * Observation of external factors
        Temperature, wind, noise, vibration, etc.

#### *Design Of Engineering Experiments*
- Formal Hypothesis:
    * A formal statement what the experimenter expects to find in the data
    * Example:
        * "Heat treatment of a material sample will lower the percentage of sample failures under load."
- Null Hypothesis:
    * A Hypothesis stated in a null form
        * More easily testable than a formal hypothesis
    * Example:
        * "There will be no difference in the percentage failures between samples that were heat-treated, and those that were not.”

#### *Test Variables*
- Independent Variable:
    * Is a controllable experimental variable
    * By changing an Independent Variable, we seek to see if that contributes to a change in a Dependent Variable
- Dependent Variable (Response Variable):
    * A characteristic outcome of an experiment on which information is to be gathered or obtained
    * The outcomes of a true experiment should be random, so a dependent variable is implicitly a random variable
    * There is a probability distribution associated with different kinds of random variables:
        * Normal, Poisson, Binomial, etc.


##

**Natural Decay & Background Concentration Test**
------

* Scope:
    * Test the closed room environment that will be used for additional future testing.

      The purpose of this test is to quantify the natural decay rate of particulate matter & VOC concentration in our test room without our air purifier on. The goal is to determine the current enviromental air exchange rate so that we can establish a baseline concentration profile to ensure that measured pollutant decay during future tests is correctly attributed to our air purifier rather than natural ventilation.

  * Defined Parameters & Justification

       Parameter | Justification
       :--- | :---
       PM 1.0 | Captures ultrafine particulates; useful for combustion/aerosol characterization and size-dependent decay
       PM 2.5 | Primary health-impact metric per EPA standards
       PM 4.0 | Intermediate particle bin to observe size-dependent settling/removal behavior
       PM 10 | Measures larger particulates not captured in PM2.5
       VOC Index | Establishes baseline VOC behavior; used to separate purifier impact from natural room changes
       Temperature | Affects sensor response and air density; controls for environmental drift
       Relative Humidity | Influences particle growth/aggregation and VOC sensor behavior
       Time | Required to estimate decay constant and air exchange rate baseline

    * Hypothesis

      In a close room with no purification, particulate matter will decay slowly. The natural decay will be significantly smaller than the decay observed during active purification. And VOC levels will remain relatively stable with the absence of an active purification source.

* Administrative Details:
    * Date & Location: TBD
    * Requested By: X
    * Conducted By: Y
 
* Design of Experiment:
    * A single factor observational decay test. Helps us establish a natural baseline decay rate. Also ensures the validity of our future purifcation test results.
    * Test Apparatus & Equipment:
        * Plantower PMS5003 & Sensirion SEN54 sensors
        * Measuring Tape (for room dimensions)
        * Stopwatch (could use microcontroller timestamps)
    * Independent & Dependent Variables:
        * _Independent:_ Time
        * _Dependent:_ PM(1.0/2.5/4.0/10) concentration; VOC index; Temperature; Relative Humidity
    * Number of Factors Considered:
        * Single-factor (time). No active purification & No fan speed configuration needed.
    * Sampling Procedure:
        * _How are Sample Obtained:_ Measure pollutant levels at natural ambient conditions.
        * _Number of Samples:_ Record data every 5 seconds or so for ~45 mins, repeat experiment 3 times.
     
* Detailed Procedure:
    1. Measure & record room dimensions.
    2. Ensure doors are closed.
    3. Take note of active HVAC (turn off is possible).
    4. Place sensors:
        - _X_ ft from wall
        - _X_ ft from floor
    5. Turn Air Purifier off and keep unplugged.
    6. Begin data logging (use timestamps).
    7. Record PM1.0, PM2.5, PM4.0, PM10, VOC, temperature, humidity continuously.
    8. After ~45 mins save data.
    9. Repeat for additional trials.
 
    * _Safety Precautions:_ Avoid open flames and keep room ventilation airways clear.
    * _Observation of External Factors:_ Door openings throughout testing; room temp/humidity; HVAC status


##
  
**Particulate Matter Removal Efficiency Test**
------
* Scope:
    * Test our air purification system in a closed room environment under fixed operating modes (constant fan-speeds).

      The purpose of this test is to quantify the rate at which particulate matter is removed during active purification. This will give us data in regards to the time required to achieve ~90% reduction in PM2.5 concentration. We can then use the data from this experiment in tandem with our data from our _Natural Decay Tests_ to obtain a purifier-only decay rate which would allow us to better estimate the Clean Air Delivery Rate (CADR) at different modes.

    * Defined Parameters & Justification
       Parameter | Justification
       :--- | ---
       PM 1.0 | Tracks ultrafine particulate removal; helps compare size-dependent efficiency across modes
       PM 2.5 | Primary health-impact metric per EPA standards
       PM 4.0 | Intermediate particulate bin for size-dependent efficiency assessment
       PM 10 | Measures larger particulates not captured in PM2.5
       VOC Index | Evaluates carbon filter effectiveness (secondary metric during PM-focused test)
       Time | Required to fit exponential decay and compute removal rate
       Fan Mode | Determines airflow rate; primary controllable factor influencing decay constant
       Room Volume | Needed to compute CADR from purifier-only decay constant


    * Hypothesis
 
      Particulate matter concentration will follow an exponential decay during active purification. Higher fan speed will produce larger decay rates, and the time to ~90% reduction should decrease as fan speed increases. We expect the purifier-only decay rate to be significantly greater than the baseline decay rate.  
      
* Administrative Details:
    * Date & Location: TBD
    * Requested By: X
    * Conducted By: Y

* Design of Experiment:
    * A single-factor decay rate test conducted at 3 fixed operating modes:
        - Boost Mode ( high fan speed )
        - Normal Mode ( \<45 dBa fan speed (TBD) )
        - Sleep Mode ( fixed fan speed corresponding to IAQI \>=81 condition)
    * Test Apparatus & Equipment:
        * Air Purifier
        * Plantower PMS5003 & Sensirion SEN54 sensors
        * Sound Level Meter
        * Measuring tape
    * Independent & Dependent Variables:
        * _Independent:_ Time; Operating Mode (fan speed)
        * _Dependent:_ PM(2.5/4.0/10) concentration; VOC index
    * Number of Factors Considered:
        * Two-factor: time & operating mode.
    * Sampling Procedure:
        * _How are Sample Obtained:_ Turn off HVAC is possible, then introduce a controlled particulate source (aerosol spray/spray paint). Then beginning logging data after ~1 minute (calibration).
        * _Number of Samples:_ Record data every 5 seconds or so until concentration falls below 10% of initial value, repeat experiment 3 times for each fan speed. 

* Detailed Procedure:
    1. Measure & record room dimensions.
    2. Ensure doors are closed.
    3. Take note of active HVAC (turn off is possible).
    4. Place sensors:

    * _Safety Precautions:_ Use approved particulate sources aka avoid open flames. Ensure fire alarms aren't triggered, use proper mask protections and keep room ventilation airways clear.
    * _Observation of External Factors:_


##
  
**Noise Emission Test**
------
* Scope:
* Administrative Details:
* Design of Experiment:
* Detailed Procedure:
    * _Safety Precautions:_
    * _Observation of External Factors:_



##

## **Fan Configuration Test**

Scope:

* The purpose of this test is to compare the effectiveness of different fan configurations: series and parallel as well as filter placement. The test will evaluate performance differences in airflow, filtration efficiency, and pollutant reduction to determine which configuration provides better purification performance.

| Parameter         | Justification |
| ----------------- | --------------------------------------- |
| PM 1.0            | Enables size-dependent performance comparison and captures ultrafine particle behavior |
| PM 2.5            | Primary health-impact metric per EPA standards and main performance indicator |
| PM 10             | Measures larger particulates to evaluate coarse particle removal efficiency |
| VOC Index         | Evaluates effectiveness of activated carbon filtration |
| Time to IAQI ≥ 81 | Quantifies recovery time and overall purification performance |
| Fan RPM / PWM     | Confirms consistent operating conditions and validates airflow differences between configurations |

Expectations

* Fans in series are expected to generate higher static pressure and improved airflow through restrictive filters, resulting in faster pollutant reduction compared to parallel configuration. Parallel configuration may produce higher airflow in low-resistance conditions but reduced effectiveness with dense filters. Configurations where fans are positioned after the filter (pull configuration) are expected to produce more uniform airflow and improved filtration efficiency compared to push configurations.

Administrative Details:

* Date: TBD; Location: TBH
* Requested by:
* Conducted by:

Design of Experiment

* Two-factor experiment:
  * Factor 1: Fan configuration / placement
    * Series configurations (3 layouts)
    * Parallel configurations (2 layouts)
  * Factor 2: Ventilation condition
    * Closed room
    * Partial ventilation (door slightly open)

Method:

* A controlled pollutant source will be introduced into the testing environment. Each fan configuration will then be activated while monitoring particulate matter and VOC concentration decay over time. Performance will be compared across configurations using recovery time and decay rate metrics.

Apparatus:

* Testing rigs, that allows for the following configurations to test airflow in the filter:
  * Series:
    * Intake->Fan->Filter->Fan->Exhaust
    * Intake->Fan->Fan->Filter->Exhaust
    * Intake->Filter->Fan->Fan->Exhaust

  * Parallel:
    * Intake-> Fan | Fan -> Filter -> Exhaust
    * Intake-> Filter -> Fan | Fan -> Exhaust

Variables

* Fan configuration
* Ventilation condition
* PM(1.0/ 2.0 /10) concentration
* TVOC concentration

Procedure
  1.

Step-by-Step Procedure
  1.

Data Collection:

* ESP32 sensor logs with timestamps
* PM and VOC vs time graphs
* Recovery time comparison between configurations
* Decay rate slope calculations
* Fan PWM/RPM verification logs
* External Factors Recorded:

External Factors:

* Room temperature and humidity
* Ventilation status (door/window condition)

## **Responsiveness Test**

Scope:

* Testing the responsiveness of the system to dynamically adjust filtration based on air quality readings

| Parameter | Justification |
| :---- | :---- |
| PM 1.0 | Detects ultrafine particle spikes and assists in pollutant-type classification |
| PM 2.5 | Primary health-impact metric per EPA standards and main control threshold variable |
| PM 10 | Detects coarse particulate changes to support adaptive control decisions |
| TVOC | Identifies VOC-dominant events to trigger carbon-filter prioritization |
| Time to IAQI ≥ 81 | Measures recovery time under dynamic control and evaluates responsiveness performance |


* It is expected that when pollutants are introduced, the system will adjust fan speed to properly filter pollutants. If predominantly VOCs are detected, the system should adjust to so that filtering through the activated carbon filter is prioritized. If predominantly particulate matter is detected, the system should adjust to prioritize filtering through the HEPA filter.

Administrative Details:

* Date: TBD; Location: TBH
* Requested by:
* Conducted by:

Design of Experiment:

* Two factor experiment:
  * Factor 1: Fan speed/mode
  * Factor 2: Pollutant type (particulate vs VOC)

Method:

* System sensitivity test utilizing controlled pollutant introduction and monitoring system response.

Apparatus:

* In a Filter cartridge prototype, the PWM fans will placed in series with the HEPA H13 filter being place in between them. The filter will be placed with the activated carbon side facing towards the intake of the system.

Variables:

* Fan Speeds/Mode
* Pollutant Type (Particulate vs VOC)
* Ventilation Condition
* Distance from pollutant source

Procedure:

1. Introduce controlled amounts of particulate matter (incense/aerosol) or VOCs (air freshener)
2. Allow pollutant levels to stabilize for 1 minute
3. Time system's response time to adjust fan speed and filter priority based on pollutant type
4. Adjust pollutant distance from the system
5. Repeat for both pollutant types
6. Also perform baseline test to compare effectiveness of system against a constant fan speed

Step-by-Step Procedure:

1. Measure and record baseline PM, TVOC, and IAQI
2. Have the fan located at <x> distance from the pollutant source
3. Introduce pollutant to environment and time how long it takes for the system to adjust fan speed and filter priority
4. Record once system has adjusted
5. Record how long it takes for air quality to return to normal levels

Data Collection Method:

* Utilizing sensor readings and ESP32 log data to acquire timestamps of events

External Factors Recorded:

* Room temperature and humidity
* Natural ventilation condition
* Baseline pollutant levels before introduction of pollutants

## HTTP Request Handling & Network Robustness Test

* Scope:
    * Test the reliability, latency, and fault tolerance of the HTTP communication pipeline between the ESP32-C3 microcontroller and the Raspberry Pi 4 server.

      The purpose of this test is to verify that the ESP32 successfully sends sensor data via HTTP POST every 5 seconds and accurately parses piggybacked fan commands in the response. Additionally, it will evaluate how the system handles network interruptions to ensure the ESP32 does not crash and can maintain local auto-control when the server is unreachable.

    * Defined Parameters & Justification:

       Parameter | Justification
       :--- | :---:
       Request Latency | Measures the round-trip time for data delivery and command retrieval
       Packet Success Rate | Ensures data integrity over the local WiFi network
       Reconnection Time | Evaluates system recovery speed after a network drop

    * Hypothesis:

      Under normal network conditions, the ESP32 will successfully transmit data and receive commands with a round-trip latency of under 500ms. If the WiFi network or RPi4 server is disconnected, the ESP32 will handle the HTTP timeout gracefully, continue operating the fans using local AQI thresholds, and automatically resume POST requests once the connection is restored without requiring a manual reboot.

* Administrative Details:
    * Date & Location: TBD
    * Requested By: X
    * Conducted By: Y
 
* Design of Experiment:
    * A two-factor system integration test evaluating communication performance under normal and interrupted network conditions.
    * Test Apparatus & Equipment:
        * ESP32-C3 DevKit (running firmware)
        * Raspberry Pi 4 
        * WiFi Router
        * Server logs 
    * Independent & Dependent Variables:
        * _Independent:_ Network connectivity status; Server response payload (empty vs. fan command included)
        * _Dependent:_ HTTP request latency (ms); ESP32 crash/reboot events; Fan RPM change delay
    * Number of Factors Considered:
        * Two-factor: Network state (Connected vs. Disconnected) & Command State (Idle vs. Active Command).
    * Sampling Procedure:
        * _How are Samples Obtained:_ Monitor server logs and ESP32 serial output while running the device, sending periodic app commands, and physically toggling the router.
        * _Number of Samples:_ Record 100 consecutive requests for baseline latency. Perform 5 network drop-and-recovery cycles.
     
* Detailed Procedure:

 
    1. Power on the RPi4 server and local WiFi router.
    2. Power on the ESP32 and ensure it connects to the network.
    3. Monitor the RPi4 server logs and record the timestamp and latency of the 5-second HTTP POST requests for 10 minutes (baseline).
    4. Using the API/Mobile app, queue a fan speed override command.
    5. Time the delay between the server receiving the command and the ESP32 physically adjusting the fan PWM (should occur on the next 5-second interval).
    6. Disconnect the WiFi router from power (simulate network drop).
    7. Observe the ESP32 via Serial Monitor. Verify it logs HTTP timeouts/connection failures but continues reading the SEN54 sensor and running local auto-fan logic.
    8. Leave disconnected for 2 minutes.
    9. Power the WiFi router back on and record how long it takes for the ESP32 to successfully resume sending HTTP POST requests.
    10. Save server logs and serial outputs for analysis.



## Power Consumption Test

Scope:

* Test the power consumption of the system with constant fan speeds as well as dynamically adjusting fan speeds and different fan configurations.

| Parameter         | Justification                                    |
| ----------------- | ------------------------------------------------ |
| Voltage           | Verifies regulated supply stability under each load condition |
| Current           | Used with voltage to compute power; validates wiring/regulator limits |
| Power (Watts)     | Primary instantaneous consumption metric |
| Energy (Wh)       | Measures real usage over time; supports efficiency comparison |
| PM 2.5            | Links power draw to cleaning performance (efficiency metric) |
| VOC Index         | Links power draw to VOC removal behavior (if applicable) |
| Time to IAQI ≥ 81 | Efficiency metric: energy required to reach acceptable air quality |
| Fan PWM / RPM     | Ensures consistent operating points across trials |
| Fan Configuration | Determines airflow resistance and power-efficiency tradeoffs |


Expectations
 -

Administrative Details:

* Date: TBD; Location: TBH
* Requested by:
* Conducted by:

Design of Experiment:

Method:

Apparatus:

* Testing rig that allows for running of the filter system in different fan configurations to test power efficiency. Fan configurations include:
  * Series:
    * Intake->Fan->Filter->Fan->Exhaust
    * Intake->Fan->Fan->Filter->Exhaust
    * Intake->Filter->Fan->Fan->Exhaust

  * Parallel:
    * Intake-> Fan | Fan -> Filter -> Exhaust
    * Intake-> Filter -> Fan | Fan -> Exhaust

Variables:

* Fan configuration
* Control mode (constant vs dynamic)
* Fan PWM level (if applicable)
* Power consumption (W)
* Energy usage (Wh)
* PM and VOC decay rate

Procedure:

Step-by-Step Procedure:

Data Collection Method:

* ESP32 logs of fan speeds and Sensor readings

External Factors Recorded:

* Room temperature
* Relative humidity
* Ventilation condition
