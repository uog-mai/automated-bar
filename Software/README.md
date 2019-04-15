# Software
## Structure
The software consisists of two main sections: the server and the firmware. Firmware is the c++ source code that compiles to a shared object that contains the automated bar logic and interacts with the load cell (HX711), servos and proximity sensor. The server directory contains the a python web server that imports the shared object as a module, once it recieves a webhook from dialogflow it subsequently parses and accesses the desired behaviour through the binding.
```bash
.
|
|
├── build.sh
├── Firmware
│   ├── build
│   ├── CMakeLists.txt
│   ├── dependencies.sh
│   ├── include
│   ├── lib
│   ├── src
│   └── test
├── README.md
└── Server
    ├── database.py
    ├── index.py
    ├── __pycache__
    └── README.md
```
### Firmware

```build.sh```  is a bash script that automatically downlaods, installs and compiles the entire project on a RaspberryPi  model 3 B with raspian (stretch), it has also been verified to compile on Ubuntu 16.04 (However you wont be able to run it since you have no GPIO pins). This file calls the ```dependencies``` bash script which clones and isntalls the ```WiringPi``` and ```pca9685``` libraries. It also installs ```Python3```and ```pybind11``` a c++ --> python binding module. 

```include``` contains the c++ header files which are added during compilation.

```lib``` contains the external library source files that are not already installed for compilation.

```src``` contains the ```cpp``` source code which defines all the bar logic and behaviour.

``` test``` contains the unit tests which are automatically performed during compilation time.

### Server
```index.py``` is the Python file that uses ```Flask``` import modules to run as a web server. It recieves the webhook from dialogflow, parses the input and refers to the ```database.py``` Python script which contains methods and data that allows the server to retrieve the necessary densities of drinks and to provide a response to the user.

## Logic and Behaviour
The behaviour of the autotamated bar can be represented as a state machine shown in the figure below. Once a cup has been placed  is ready for an order, once recieved it will begin to dispense. When completed it will go back to a ready state for another drink and if the cup ise ever removed it will go back to waiting it to be placed.

The cup detection is done by the proximity sensor which returns a boolean value depending on whether or not it reads high or low.

Dispension is monitored by the weight sensor; once the python web server receives an order it calculates the required weight to dispense from the required volume and a density lookup table. The servos mapped to that drink are then found and subsequently actuated until the weight is matched. Once completed the the server returns a response to dialogflow indicating to the user that their drink is ready.

### State Transition Diagram
<p align="center">
<img src="https://github.com/uog-mai/automated-bar/blob/develop/Software/assets/MooreStateModel.png">
</p>

The following diagram displays the sequence of events; it is a completely sequential logic since it could be formulated as such. The response time is more than satsisfactory and making it parallel would only provide further complication. If it can be done in sequence then there is no reason to overcomplicate it.

### Sequence Diagram
<p align="center">
<img src="https://github.com/uog-mai/automated-bar/blob/develop/Software/assets/UMLDiagram.png">
</p>

## Web Server
A Python web server is hosted in 
