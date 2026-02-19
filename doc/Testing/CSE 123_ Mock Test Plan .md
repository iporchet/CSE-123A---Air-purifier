#### Test Plans Outline

• Scope:  
    • Identify the system and goal/purpose of each test  
    • Define parameters for each test and justify inclusion  
    • State expectations of the test ( the Hypothesis \- see later slide )  
• Administrative Details:  
    • Date and Location of Testing  
    • Client or Organization that requested the test  
    • Who is conducting the test  
• Design of each test (a.k.a. Design of Experiment)  
    • Type of testing method and its significance  
    • List of test apparatus and measurement equipment, model \#s, etc…  
    • Identify ‘dependent’ and ‘independent’ variables ( see later slide )  
    • Number of factors considered (single, double (factorial), etc.)  
    • Sampling procedure:  
        • How are samples obtained?  
        • Number of samples  
• Detailed, step-by-step procedure to conduct each test  
    • Safety precautions  
    • Data collection method  
        • Written, recorded, digital, etc.  
    • Observation of external factors  
        • Temperature, wind, noise, vibration, etc.

#### *Design Of Engineering Experiments*

• Formal Hypothesis:  
• A formal statement of what the experimenter expects to find in the data  
• Example:  
“Heat treatment of a material sample will lower the percentage of sample failures under load.”  
• Null Hypothesis:  
• A Hypothesis stated in a null form  
• More easily testable than a formal hypothesis  
• Example:  
“There will be no difference in the percentage failures between samples that were heat-treated, and those that were not.”

#### *Test Variables*

• Independent Variable:  
    • Is a controllable experimental variable  
    • By changing an Independent Variable, we seek to see if that contributes to a change in a Dependent Variable  
• Dependent Variable (Response Variable):  
    • A characteristic outcome of an experiment on which information is to be gathered or obtained  
    • The outcomes of a true experiment should be random, so a dependent variable is implicitly a random variable  
    • There is a probability distribution associated with different kinds of random variables:  
        • Normal, Poisson, Binomial, etc.



##

**Natural Decay & Background Concentration Test**
------
* Scope:
    * Test the closed room environment that will be used for additional future testing.
       The purpose of this test is to quantify the natural decay rate of particulate matter & VOC concentration in our test room without our air purifier on. The goal is to determine the current enviromental air exchange rate so that we can establish a baseline concentration profile to ensure that measured pollutant decay during future tests is correctly attributed to our air purifier rather than natural ventilation.

    * Defined Parameters & Justification
       Parameter | Justification
       --- | ---
       PM 1.0 | -
       PM 2.5 | -
       PM 4.0 | -
       PM 10 | -
       VOC Index | -
       Temperature | -
       Relative Humidity | -
       Time | -

    * Hypothesis
       In a close room with no purification, particulate matter will decay slowly. The natural decay will be significantly smaller than the decay observed during active purification. And VOC levels will remain relatively stable with the absence of an active purification source.

* Administrative Details:
    * Date & Location: TBD
    * Requested By: X
    * Conducted By: Y
 
* Design of Experiment:


##
  
**Natural Decay & Background Concentration Test**
------
Scope:

Administrative Details:

Design of Experiment:

Method:

Apparatus:

Variables:

Procedure:

Step-by-Step Procedure:

Data Collection Method:

External Factors Recorded:




## **MOCK Test 1**

Scope

- Testing the reduction of particle matter concentration with a goal of achieving an IAQI equivalent to AQI \< 50\. Also testing if the system adjusts dynamically based on pollutant levels and if the system can outperform natural ventilation  
-

| Parameter | Justification |
| :---- | :---- |
| PM 1.0 |  |
| PM 2.5  |  |
| PM 10 |  |
| Time to IAQI \>= 81 |  |

- Expect higher fan speeds to reduce particulate concentration faster, and for the system to return to IAQI \>= 81 within half an hour after the pollutant is introduced. And natural ventilation should show significantly slower decay rates in comparison.

Administrative Details:

- Date: TBD; Location: TBH  
- Requested by:  
- Conducted by:

Design of Experiment:  
Two-factor experiment:

- Factor 1: Fan Mode  
- Factor 2: Ventilation Condition

Method

- Controlled pollutant decay experiment using incense/aerosols/air fresheners as a repeatable particulate source.  
- Simulate real-world indoor pollutant events and provide statistical repeatability.

Apparatus

- Smart Air purifier prototype  
- PMS5003 Sensor, SEN54 sensor  
- Stopwatch  
- Incense sticks/aerosol

Variables

- Fan speed/mode  
- Ventilation condition  
- PM(1.0/ 2.0 /10) concentration  
- Time to IAQI \>= 81

Procedure

- Same environment used for all trials
- One incense stick burned for exactly 20 minutes  
- Purifier activated  
- Measurements taken every minute or so  
- Each configuration repeated 3 times

Step-by-Step Procedure:

1. Measure and record beeline PM and IAQI  
2. Burn an incense stick for 20 minutes  
3. Allow PM levels to stabilize for 1 minute  
4. Turn on the Air Purifier at select fan speed  
5. Start timer  
6. Record PM(1.0/ 2.0 /10) & IAQI every minute  
7. Stop timer once IAQI \>= 81  
8. Record total recovery time  
9. Ventilate the room for 5 minutes before the next trial  
10. Repeat for all configurations

Data Collection Method

- Log data using esp  
- PM, IAQI  vs Time graphs

External Factors Recorded

- Room temp and humidity
- Current ventilation condition



##

## **Fan Configuration Test**

Scope:

- Comparing the effectiveness of series vs parallel fans in reducing PM concentrations and VOCs

| Parameter | Justification |
| :---- | :---- |

Expectations
 -

Administrative Details:

- Date: TBD; Location: TBH
- Requested by:
- Conducted by:

Design of Experiment
 -

Method:

Apparatus:

- Two different testing rigs will be constructed with one that places the fans in series with the filter in between and another that places the fans in parallel with the filters below. Both rigs will be tested under the same conditions to compare their effectiveness.

Variables

- Fan configuration (series vs parallel)
- Ventilation condition
- PM(1.0/ 2.0 /10) concentration
- TVOC concentration

Procedure
  1.

Step-by-Step Procedure
  1.

## **Responsiveness Test**

Scope:

- Testing the responsiveness of the system to dynamically adjust filtration based on air quality readings

| Parameter | Justification |
| :---- | :---- |
| PM 1.0 |  |
| PM 2.5  |  |
| PM 10 |  |
| TVOC  |  |
| Time to IAQI \>= 81 |  |

- It is expected that when pollutants are introduced, the system will adjust fan speed to properly filter pollutants. If predominantly VOCs are detected, the system should adjust to so that filtering through the activated carbon filter is prioritized. If predominantly particulate matter is detected, the system should adjust to prioritize filtering through the HEPA filter.

Administrative Details:

- Date: TBD; Location: TBH
- Requested by:
- Conducted by:

Design of Experiment:

- Two factor experiment:
  - Factor 1: Fan speed/mode
  - Factor 2: Pollutant type (particulate vs VOC)

Method:

- System sensitivity test utilizing controlled pollutant introduction and monitoring system response.

Apparatus:

- In a Filter cartridge prototype, the PWM fans will placed in series with the HEPA H13 filter being place in between them. The filter will be placed with the activated carbon side facing towards the intake of the system.

Variables:

- Fan Speeds/Mode
- Pollutant Type (Particulate vs VOC)
- Ventilation Condition
- Distance from pollutant source

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

- Utilizing sensor readings and ESP32 log data to acquire timestamps of events

External Factors Recorded:

- Room temperature and humidity
- Natural ventilation condition
- Baseline pollutant levels before introduction of pollutants

## Power Consumption Test

Scope:

- Test the power consumption of the system with constant fan speeds as well as dynamically adjusting fan speeds based on pollutant levels.

| Parameter | Justification |
| :---- | :---- |
| PM 1.0 |  |
| PM 2.5  |  |
| PM 10 |  |
| TVOC  |  |
| Time to IAQI \>= 81 |  |

Expectations
 -

Administrative Details:

- Date: TBD; Location: TBH
- Requested by:
- Conducted by:

Design of Experiment:

Method:

Apparatus:

Variables:

Procedure:

Step-by-Step Procedure:

Data Collection Method:

External Factors Recorded:
