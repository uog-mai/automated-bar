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

