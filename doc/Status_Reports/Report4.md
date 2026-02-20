# Status Report 4



Individual Work



-Randall

--Work Completed

- During Week 4, I focused on strengthening the technical rigor and completeness of our air purifier testing framework. I revised the test plan to ensure that each experiment includes clearly defined parameters, justified variable selection, formal hypotheses, and measurable performance metrics. I corrected table formatting inconsistencies, filled in missing justifications for PM size bins (PM1.0, PM2.5, PM10), VOC index tracking, and system performance indicators such as Time to IAQI ≥ 81.


Future Work

-Next week, I will shift focus from documentation refinement to controlled experimental execution and data validation. I plan to implement structured timestamped logging through the ESP32 to capture PM, VOC, temperature, humidity, and control-state transitions during testing. I will also verify sensor placement, and confirm calibration stability.

-In parallel, I will begin developing data analysis scripts (likely in Python or MATLAB) to compute decay constants (k-values) from logged concentration data and automate CADR estimation. I also plan to validate the dynamic control responsiveness algorithm using controlled pollutant introduction and confirm that power measurement logging accurately captures voltage, current, and energy consumption under different operating modes.


- **Andrew**
    - Worked On:
        * Drafted tests plans for baseline particulate concentration decay and particulate matter removal efficiency.
        * Outlined probable Indoor Air Quality Index thresholds and formula.
    - Future Work:
        * Help with preliminary ESP32 sensor integration to detect temperature & humidity as we await the arrival of the particulate matter sensors.
        * Learn how the MCU interacts with the cloud server & mobile app to better assist with those aspects of the system. 
        * Add more items to backlog.
