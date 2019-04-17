#include "DrinkServer.h"
#include <memory>

#include <cstdio>
#include <stdexcept>



DrinkServer::DrinkServer(const mai::DrinksConfig &drinks_config) {
    for (const auto& drink: drinks_config.m_drinks_map) {
        const mai::Drinks::Type drink_type = drink.first;
        const mai::Drinks::Position drink_pos = drink.second;
        servo_map[drink.first] = std::make_shared<ServoHandler>(static_cast<int>(drink_pos));
    }

    
   // if (setup_status == -1)
	//throw::std::runtime_error("Failed to setup wiringPi in DrinkServer");


}

DrinkServer::Status DrinkServer::weight_match(const float target_weight){

    /*

    const float offset = scale.read_trimmed_avg();

    while( (offset -  float(scale.read_trimmed_avg()) ) <= target_weight){
       
	 // Wait until weight is matched, stop if cup is not detected
		
                bool cup_detected = prox_sensor.detect_cup();

	        if(!cup_detected){
        		
			return DrinkServer::Status::DISPENSE_FAILURE;
        	}

	
	
		if (servo->activate() != ServoHandler::ServoStatus::ACTION_SUCCESS){
        		throw std::runtime_error("Could not activate servo ");
		}

		delay(m_delay_time);


    		if (servo->deactivate() != ServoHandler::ServoStatus::ACTION_SUCCESS){  	
        		throw std::runtime_error("Could not deactivate servo ");
    		}

    }	
    return DrinkServer::Status::DISPENSE_SUCCESS;
	*/
}


DrinkServer::Status DrinkServer::dispense_drink(const mai::Drinks::Type drink_type, const float weight_gm) {
    /* @TODO */
    
    //ServoHandler& servo = servo_map.find(drink_type)->second;

    std::shared_ptr<ServoHandler> servo = servo_map.find(drink_type)->second;

    scale.tare();

    //servo->activate()

    printf("Target weight %f \n", weight_gm);

    //DrinkServer::Status weight_status = weight_match(servo, weight_gm);
    
    const float offset = scale.read_trimmed_avg();

    while( (offset -  float(scale.read_trimmed_avg()) ) <= weight_gm){

         // Wait until weight is matched, stop if cup is not detected

    	bool cup_detected = prox_sensor.detect_cup();

   	if(!cup_detected){

    		return DrinkServer::Status::DISPENSE_FAILURE;
        }



     	if (servo->activate() != ServoHandler::ServoStatus::ACTION_SUCCESS){
        	throw std::runtime_error("Could not activate servo ");
      	}

      	delay(m_delay_time);


     	if (servo->deactivate() != ServoHandler::ServoStatus::ACTION_SUCCESS){
        	throw std::runtime_error("Could not deactivate servo ");
     	}

    }

    return DrinkServer::Status::DISPENSE_SUCCESS;
   
}


