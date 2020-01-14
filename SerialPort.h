#ifndef SerialPort
#define SerialPort

#include <Arduino.h>

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

class SerialPort{
    public:
        SerialPort(int data01, int data02, int data03, int data04){
            _data01= data01;
            _data02= data02;
            _data03= data03;
            _data04= data04;

            pinMode(_data01, OUTPUT);
            pinMode(_data02, OUTPUT);
            pinMode(_data03, OUTPUT);
            pinMode(_data04, OUTPUT);

            // reset count
            digitalWrite(_data01, LOW);
            digitalWrite(_data02, LOW);
            digitalWrite(_data03, LOW);
            digitalWrite(_data04, LOW);
        }

        void call(string port){
            if(port == "A"){call_output(false, false, false, false);}
            else if(port == "B"){call_output(false, false, false, true);}
            else if(port == "C"){call_output(false, false, true, false);}
            else if(port == "D"){call_output(false, false, true, true);}
            else if(port == "E"){call_output(false, true, false, false);}
            else if(port == "F"){call_output(false, true, false, true);}
            else if(port == "G"){call_output(false, true, true, false);}
            else if(port == "H"){call_output(false, true, true, true);}
            else if(port == "I"){call_output(true, false, false, false);}
            else if(port == "J"){call_output(true, false, false, true);}
            else if(port == "K"){call_output(true, false, true, false);}
            else if(port == "L"){call_output(true, false, true, true);}
            else if(port == "M"){call_output(true, true, false, false);}
            else if(port == "N"){call_output(true, true, false, true);}
            else if(port == "O"){call_output(true, true, true, false);}
            else if(port == "P"){call_output(true, true, true, true);}
        }
    
    private:
        void call_output(bool count01, bool count02, bool count03, bool count04){
            if(count01){digitalWrite(_data01, HIGH);}
            else{digitalWrite(_data01, LOW);}
          
            if(count02){digitalWrite(_data02, HIGH);}
            else{digitalWrite(_data02, LOW);}
          
            if(count03){digitalWrite(_data03, HIGH);}
            else{digitalWrite(_data03, LOW);}
          
            if(count04){digitalWrite(_data04, HIGH);}
            else{digitalWrite(_data04, LOW);}
        }
}
