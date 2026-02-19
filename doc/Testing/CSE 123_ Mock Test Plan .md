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
       :--- | :---:
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
    * _Safety Precautions:_ Avoid open flames and keep room ventilation airways clear.
 
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

    * _Observation of External Factors:_ Door openings throughout testing; room temp/humidity; HVAC status


##
  
**Particulate Matter Removal Efficiency Test**
------
* Scope:
    * Test our air purification system in a closed room environment under fixed operating modes (constant fan-speeds).

      The purpose of this test is to quantify the rate at which particulate matter is removed during active purification. This will give us data in regards to the time required to achieve ~90% reduction in PM2.5 concentration. We can then use the data from this experiment in tandem with our data from our _Natural Decay Tests_ to obtain a purifier-only decay rate which would allow us to better estimate the Clean Air Delivery Rate (CADR) at different modes.

    * Defined Parameters & Justification
       Parameter | Justification
       :--- | :---:
       PM 1.0 | -
       PM 2.5 | -
       PM 4.0 | -
       PM 10 | -
       VOC Index | -
       Time | -
       Fan Mode | -
       Room Volume | -

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
    * _Safety Precautions:_ Use approved particulate sources aka avoid open flames. Ensure fire alarms aren't triggered, use proper mask protections and keep room ventilation airways clear.
 
    1. Measure & record room dimensions.
    2. Ensure doors are closed.
    3. Take note of active HVAC (turn off is possible).
    4. Place sensors:
 
    * _Observation of External Factors:_




##
  
** Noise Emission Test**
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
