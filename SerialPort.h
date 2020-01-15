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
        serialPort(int path_a, int path_b, int path_c, int path_d, int clk_path){
            PATH_A= path_a;     // port from data A output
            PATH_B= path_b;     // port from data B output
            PATH_C= path_c;     // port from data C output
            PATH_D= path_d;     // port from data D output
            CLK_PATH= clk_path; // port from clock output 
            CLK_TIME= 2;

            pinMode(PATH_A, OUTPUT);
            pinMode(PATH_B, OUTPUT);
            pinMode(PATH_C, OUTPUT);
            pinMode(PATH_D, OUTPUT);
            pinMode(CLK_PATH, OUTPUT);
            pinMode(CLR_PATH, OUTPUT);
        }

        void call(string text){
            if(text == "S00"){ create_out(false, false, false, true); }
            else if(text == "S01"){ create_out(false, false, false, true); }
            else if(text == "S02"){ create_out(false, false, true, false); }
            else if(text == "S03"){ create_out(false, false, true, true); }
            else if(text == "S04"){ create_out(false, true, false, false); }
            else if(text == "S05"){ create_out(false, true, false, true); }
            else if(text == "S06"){ create_out(false, true, true, true); }
            else if(text == "S07"){ create_out(true, false, false, false); }
            else if(text == "S08"){ create_out(true, false, false, true); }
            else if(text == "S09"){ create_out(true, false, true, false); }
            else if(text == "S10"){ create_out(true, false, true, true); }
            else if(text == "S11"){ create_out(true, true, false, false); }
            else if(text == "S12"){ create_out(true, true, false, true); }
            else if(text == "S13"){ create_out(true, true, true, false); }
        }

    private:
        void create_out(bool a_path_level, bool b_path_level, bool c_path_level, bool d_path_level){
            if(a_path_level){ digitalWrite(PATH_A, HIGH); } else{ digitalWrite(PATH_A, LOW); }
            if(b_path_level){ digitalWrite(PATH_B, HIGH); } else{ digitalWrite(PATH_B, LOW); }
            if(c_path_level){ digitalWrite(PATH_C, HIGH); } else{ digitalWrite(PATH_C, LOW); }
            if(d_path_level){ digitalWrite(PATH_D, HIGH); } else{ digitalWrite(PATH_D, LOW); }

            digitalWrite(CLK_PATH, HIGH);
            delay(CLK_TIME);
            digitalWrite(CLK_PATH, LOW);
        }
}
