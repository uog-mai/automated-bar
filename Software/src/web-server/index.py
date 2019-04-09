from flask import Flask, request, jsonify, render_template
import os
#import dialogflow
import requests
import json
import libextension

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
    response = 'I can see youre a cultured individual, its on its way'
    mixerString = ''.join(mixer)
    alcString = ''.join(alcohol)
    reply = {
        "fulfillmentText": response,
    }

    print("Server recieved ", libextension.serveDrink(mixerString, alcString))

    return jsonify(reply)


# run Flask app
if __name__ == "__main__":
    app.run()
