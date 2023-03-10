/**
 * FILENAME :        StepMotor_TMC2100.cpp          
 *
 * DESCRIPTION :
 *       StepMotor_TMC2100 / Step Motor controller module library.
 *
 * NOTES :
 *       Developped by Villou / LEnsE
 **
 * AUTHOR :    Julien VILLEMEJANE        START DATE :    09/mar/2023
 *
 *       LEnsE / Institut d'Optique Graduate School
 * @see https://learn.watterott.com/silentstepstick/pinconfig/tmc2100/
 */

 #include "StepMotor_TMC2100.h"

 StepMotor_TMC2100::StepMotor_TMC2100(DigitalOut *en, DigitalOut *dir, PwmOut *step, bool config){
    this->_enable = false;
    /* Initialisation of enable output */
    if (en){ delete __en; }
    this->__en = en;
    this->__en->write(1);
    /* Initialisation of direction output */
    if (dir){ delete __dir; }
    this->__dir = dir;
    this->__dir->write(0);
    /* Initialisation of step output */
    if (step){ delete __step; }
    this->__step = step;
    this->__step->period(1);
    this->__step->write(0);
    this->_notConfig = config;
    thread_sleep_for(10);      // 10 ms
 }

void StepMotor_TMC2100::updateMotorState(void){
    this->__dir->write(this->_direction);
    this->__step->period(1.0/this->_frequency);
    if(this->_enable){
        this->__step->write(0.5);
        this->__en->write(0);
    }
    else{
        this->__step->write(0);
        this->__en->write(1);
    }
}

void StepMotor_TMC2100::goForward(float stepsPerSeconds){
    this->_direction = 1;
    this->_enable = true;
    this->_frequency = stepsPerSeconds;
    this->updateMotorState();
}

void StepMotor_TMC2100::goBackward(float stepsPerSeconds){
    this->_direction = 0;
    this->_enable = true;
    this->_frequency = stepsPerSeconds;
    this->updateMotorState();  
}

void StepMotor_TMC2100::stop(void){
    this->_enable = false;
    this->updateMotorState();  
}

void StepMotor_TMC2100::setupConfigPins(DigitalInOut *cfg1, DigitalInOut *cfg2, DigitalInOut *cfg3){
    /* Initialisation of cfg1 pin */
    if (cfg1){ delete __cfg1; }
    this->__cfg1 = cfg1; 
    this->__cfg1->output(); 
    this->__cfg1->write(0); 
    /* Initialisation of cfg2 pin */
    if (cfg2){ delete __cfg2; }
    this->__cfg2 = cfg2; 
    this->__cfg2->output();
    this->__cfg2->write(1);   
    /* Initialisation of cfg3 pin */
    if (cfg3){ delete __cfg3; }
    this->__cfg3 = cfg3; 
    this->__cfg3->input();
}