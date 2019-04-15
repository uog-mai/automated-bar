[![Build Status](https://travis-ci.org/uog-mai/automated-bar.svg?branch=develop)](https://travis-ci.org/uog-mai/automated-bar)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d979a961225d45618b61c0bc4588a02c)](https://www.codacy.com/app/eddymj96/automated-bar?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=uog-mai/automated-bar&amp;utm_campaign=Badge_Grade)

# Automated-Bar
### Completed as a project towards Real Time Embedded Programming 5 at the University of Glasgow

This project aims to produce a low-cost, voice-activated, automated drinks vending system for use in high-end consumer and commercial applications. Order your favourite drink through voice commands on Google Home on your mobile or use our custom made GUI to select drinks. 

This page will show you exactly how to build your own automated-bar for under £75, providing you with a components list, all the necessary CAD technical drawings and electronics schematics and an easy one step install for all the required software and firmware. 

Check out our design and build process on our Instagram page: [m{A.I.}.](https://www.instagram.com/m_a.i._/?hl=en)

Or our instructables for our full build instructions: 

## Features
Scalability to any assortment of spirits and mixers

Google API integration for voice ordering

Extensive crawled database of recipes

Based on a Raspberry Pi 3 Model B

Low-cost aluminium extrusion structure

3D printed PLA fixtures

9g servo actuators

## Usage and Install Instructions
To use [dialogflow](https://dialogflow.com/) you must create a free account and import the ```CocktailRecipeBot``` which can be download from the software directory ```automated-bar/Software/dialogflow```. Download, unzip and upload it to dialogflow to begin use.

You will also need to sign-up and download [```ngrok```](https://dashboard.ngrok.com/user/signup) a secure traffic rerouting service for webhooks. This is needed to connect the dialogflow webhook to the Python server. This should be done on the Raspberry Pi.

This following software has only been verified to compile on the Raspberry Pi 3 Model B ```raspian (stretch)``` and ```Ubuntu 16.04```, however it should work on other raspbian distros and RPI models too.

This installation has should be run from the command line of the Raspberry Pi by first cloning this git repo.
```bash
git clone https://github.com/uog-mai/automated-bar/
cd automated-bar/Software/
sudo source build.sh
```
This will download, install and compile all dependencies and the source code for the project.

Once installed, run the following in the ```ngrok``` install directory:
```bash
sudo ./ngrok http 5000
```
This will redirect a dynamically generated URL to your RPI. Where it says:
```Forwarding                    https://yourURL.ngrok.io``` copy the URL (makes sure its https *not* http). In the ``CocktailRecipeBot`` dialogflow on the left hand side where it says ```Fulfillment```, enable the webhook option and paste the ngrok URL.

Now navigate to the server folder inside the software directory, ```automated-bar/Software/Server``` and run:
```bash
python3 index.py
``` 
This should run your webserver (default traffic input through port 5000) on the RPI with the C++ shared object imported as a module. 

*Congratulations* You have completed the software set-up, you can now ask Google Home to talk to ```m{A.I.}``` (through voice or text) and you cna begin ordering your drinks. 

## Overview

### Hardware 

Full CAD resources including Autodesk Inventor files and assemblies of the system can be found within our Hardware subsection, and full electronics design files are available through the [Altium CircuitMaker community.](https://circuitmaker.com/Projects/Details/Peter-Fleming-2/UoG-mai-automated-bar) 

For full build instructions and BOM please see our Instructables page INSTRUCTABLES LINK HERE

### Software

![Alt text](assets/InteractionDiagram.png)

Further details of the software can be found in the Software directory README: ```automated-bar/Software/README```and in the Software section of the Wiki.





