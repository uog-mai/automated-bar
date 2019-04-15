from flask import Flask, request, jsonify, render_template
import requests

import database
import sys, os

import libextension
import libDrinksConfig

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/get_drink', methods=['POST'])
def get_drink():

    data = request.get_json(silent=True)

    mixer = data['queryResult']['parameters']['mixer']
    alcohol = data['queryResult']['parameters']['alcohol']
    print(mixer, alcohol)

    
    # Get alcohol name
    mixerString = ''.join(mixer)
    alcString = ''.join(alcohol)

    # Calculate required drink weights
    alc_weight = database.get_alcohol_weight(alcString, 20)
    
    
    response = database.random_response()       
                
    reply = {
        "fulfillmentText": response,
    }

    print("Server recieved ", libextension.dispense_drink(alcString, alc_weight))

    return jsonify(reply)
    


# run Flask app
if __name__ == "__main__":
    app.run()
