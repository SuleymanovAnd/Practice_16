//
// Created by Андрей on 02.07.2022.
//
#include <iostream>
#include <sstream>
using namespace std;
bool stringInBool (string value){
    if (value == "on"|| value == "yes"){
        return true;
    } else if (value == "no" || value == "off") {
        return false;
    }
}

enum switches {
    HOUSE_POWER_SUPPLY =1,
    SOCKETS = 2,
    LIGHTS_INSIDE = 4,
    LIGHTS_OUTSIDE = 8,
    HEATERS = 16,
    WATER_PIPE_HEATING = 32,
    CONDITIONER = 64
};
void smart_house (){

    string buffer;
    float day = 1;
    int lIn_state = 0;
    int lOut_state = 0;
    int water_pump_state = 0;
    int heater_state = 0;
    int conditioner_state = 0;
    int color_temperature = 5000;


        for (int time = 0; time <=24; time++){
            if (time == 24) {day++; time =0;}
            if (day == 3) break;
            cout <<"time is "<< time <<":00"<< day << endl;

            cout << "Enter the value, separated by a space, of the:"
                    "\n* temperature outside (-50 to 50)"
                    "\n* temperature inside (-50 to 50)"
                    "\n* is there movement outside (yes or no)"
                    "\n* is the light on in the house (on or off)"
                    "\n:";
            getline (cin,buffer);
            stringstream buffer_stream (buffer);
            int tOutside;
            int tInside;
            string movOutside;
            string onLightInHouse;
            buffer_stream >>tOutside >> tInside >> movOutside >> onLightInHouse;

            while (abs(tOutside) > 50 || abs(tInside)>50            //проверка ввода
                || movOutside != "yes"&& movOutside != "no"
                || onLightInHouse != "on" && onLightInHouse != "off"){
                cout << "Incorrect input. Try again: ";
                getline (cin,buffer) ;
                stringstream error_stream (buffer);
                error_stream >>tOutside >> tInside >> movOutside >> onLightInHouse;
            }
            bool bMovOutside = stringInBool (movOutside);
            bool bOnLightInHouse = stringInBool (onLightInHouse);
            //cout << bMovOutside << bOnLightInHouse;


            if (time >=16 && time <=20) { color_temperature -= 460;}
            if (time == 0) {color_temperature = 5000;}

            if (bOnLightInHouse) {
               if (!(lIn_state & LIGHTS_INSIDE)) {lIn_state |= LIGHTS_INSIDE;
               cout << "# LIGHT ON"<< endl;}
                cout << "color temperature = " << color_temperature << endl;
            } else if (lIn_state & LIGHTS_INSIDE) {lIn_state &= ~LIGHTS_INSIDE;cout << "# LIGHT OFF"<< endl;}

           if ((!(water_pump_state & WATER_PIPE_HEATING))&& tOutside < 0) {water_pump_state |= WATER_PIPE_HEATING ;
               cout << "# WATER PIPE HEATING is ON" << endl;}
           else if (tOutside > 5 && water_pump_state & WATER_PIPE_HEATING) {water_pump_state &= ~WATER_PIPE_HEATING;
               cout << "# WATER PIPE HEATING is OFF" << endl;}
            cout << ((time < 5 || time >= 16) && (!(lOut_state & LIGHTS_OUTSIDE)));
           if ( (time < 5 || time >= 16) && (!(lOut_state & LIGHTS_OUTSIDE))){
               if (bMovOutside) {lOut_state |= LIGHTS_OUTSIDE ; cout << "# LIGHTS OUTSIDE is ON"<< endl;}
               else {lOut_state &= ~LIGHTS_OUTSIDE; cout << "# LIGHTS OUTSIDE is OFF"<< endl;}
           }else if ((time >= 5 && time < 16) && lOut_state & LIGHTS_OUTSIDE) {
               lOut_state &= ~LIGHTS_OUTSIDE;
               cout << "# LIGHTS OUTSIDE is OFF"<< endl;}

           if ((!(heater_state & HEATERS)) && tInside < 22 ) {heater_state |= HEATERS;
           cout << "# HEATERS in house ON"<<endl;}
           else if (tInside >=25 && heater_state & HEATERS) {heater_state &= ~HEATERS;
           cout << "# HEATERS in house OFF"<<endl;}

           if (tInside >=30 && !(conditioner_state & CONDITIONER)) {conditioner_state |= CONDITIONER;
               cout << "# CONDITIONER is ON"<<endl;}
           else if (tInside <= 25 && conditioner_state & CONDITIONER) {conditioner_state &= ~CONDITIONER;
               cout << "# CONDITIONER is OFF"<<endl;}
        cout << endl;
        }




}