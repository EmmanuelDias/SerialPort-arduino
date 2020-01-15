/* ------------------------------------------------------------------------------
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  ------------------------------------------------------------------------------ */

#ifndef SerialPort
#define SerialPort

#include <Arduino.h>


class SerialPort{
    public:
        serialPort(int path_a, int path_b, int path_c, int path_d, int clk_path= 5){
            PATH_A= path_a;     // port from data A output
            PATH_B= path_b;     // port from data B output
            PATH_C= path_c;     // port from data C output
            PATH_D= path_d;     // port from data D output
            CLK_PATH= clk_path; // port from clock output 
            CLK_TIME= 127;      // intensify of the pulse width

            //states variables
            string level_S00= "LOW";
            string level_S01= "LOW";
            string level_S02= "LOW";
            string level_S03= "LOW";
            string level_S04= "LOW";
            string level_S05= "LOW";
            string level_S06= "LOW";
            string level_S07= "LOW";
            string level_S08= "LOW";
            string level_S09= "LOW";
            string level_S10= "LOW";
            string level_S11= "LOW";
            string level_S12= "LOW";
            string level_S13= "LOW";

            pinMode(PATH_A, OUTPUT);
            pinMode(PATH_B, OUTPUT);
            pinMode(PATH_C, OUTPUT);
            pinMode(PATH_D, OUTPUT);
            pinMode(CLK_PATH, OUTPUT);
            pinMode(CLR_PATH, OUTPUT);
        }

        string get_state(string port){
            if(port == "S00"){ return level_S00; }
            else if(port == "S01"){ return level_S00; }
            else if(port == "S02"){ return level_S01; }
            else if(port == "S03"){ return level_S02; }
            else if(port == "S04"){ return level_S03; }
            else if(port == "S05"){ return level_S04; }
            else if(port == "S06"){ return level_S05; }
            else if(port == "S07"){ return level_S06; }
            else if(port == "S08"){ return level_S07; }
            else if(port == "S09"){ return level_S08; }
            else if(port == "S10"){ return level_S09; }
            else if(port == "S11"){ return level_S10; }
            else if(port == "S12"){ return level_S11; }
            else if(port == "S13"){ return level_S12; }
            else{ return "index out of range"; }
        }

        void call(string text){
            if(text == "S00"){ create_out(false, false, false, true); level_S00= true; }
            else if(text == "S01"){ create_out(false, false, false, true); level_S01= "HIGH"; }
            else if(text == "S02"){ create_out(false, false, true, false); level_S02= "HIGH"; }
            else if(text == "S03"){ create_out(false, false, true, true); level_S03= "HIGH"; }
            else if(text == "S04"){ create_out(false, true, false, false); level_S04= "HIGH"; }
            else if(text == "S05"){ create_out(false, true, false, true); level_S05= "HIGH"; }
            else if(text == "S06"){ create_out(false, true, true, true); level_S06= "HIGH"; }
            else if(text == "S07"){ create_out(true, false, false, false); level_S07= "HIGH"; }
            else if(text == "S08"){ create_out(true, false, false, true); level_S08= "HIGH"; }
            else if(text == "S09"){ create_out(true, false, true, false); level_S09= "HIGH"; }
            else if(text == "S10"){ create_out(true, false, true, true);level_S10= "HIGH"; }
            else if(text == "S11"){ create_out(true, true, false, false); level_S11= "HIGH"; }
            else if(text == "S12"){ create_out(true, true, false, true); level_S12= "HIGH"; }
            else if(text == "S13"){ create_out(true, true, true, false); level_S13= "HIGH"; }
            }

    private:
        void create_out(bool a_path_level, bool b_path_level, bool c_path_level, bool d_path_level){
            if(a_path_level){ digitalWrite(PATH_A, HIGH); } else{ digitalWrite(PATH_A, LOW); }
            if(b_path_level){ digitalWrite(PATH_B, HIGH); } else{ digitalWrite(PATH_B, LOW); }
            if(c_path_level){ digitalWrite(PATH_C, HIGH); } else{ digitalWrite(PATH_C, LOW); }
            if(d_path_level){ digitalWrite(PATH_D, HIGH); } else{ digitalWrite(PATH_D, LOW); }

            analogWrite(CLK_PATH, CLOCK_TIME);
        }
}
