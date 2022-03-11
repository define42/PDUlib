#include <Arduino.h>
#include <pdulib.h>

PDU mypdu = PDU();
// ascii yen aleph spade ace_of_spaces hebrew
char const *inpdu[] = {
 // "07917952140230F2040C917952777777770008120170016131212200680065006C006C006F003000A505D02660D83CDCA1D83DDE0005E905DC05D505DD",
 // "07917952140230F2040C9179527777777700001201216123732106CA405B8D6000", //    GSM 7 bit
 // "07917952939899F9240C917952630247660000120151113404210A814D79C3DBF8C2E231",  // includes escape euro
 // "07917952140230F2040C91795277777777000812012161238121180061006200630064D83CDF56D83DDE0305D005D105D205D3",  // hebrew emojis
//  "07917952140230F2040C91795277777777000012012161335221A061F1985C369FD169F59ADD76BFE171F99C5EB7DFF1797D503824168D476452B964369D4F68543AA556AD576C561B168FC965F3199D56AFD96DF71B1E97CFE975FB1D9FD707854362D1784426954B66D3F98446A5536AD57AC566B561F1985C369FD169F59ADD76BFE171F99C5EB7DFF1797D503824168D476452B964369D4F68543AA556AD576C561B93CD68", // full length
   // greek in GSM 7 bit
//  "06910379010023040DD05774983EAFC20100002230603023928046456C318901D960B013C8027D62404FCA13447D3A41CB27A6F904519F59D01519A49EA6A02A146479664114E4E4997582A8482708167BC168A0984C078301", 
//  "06910379010023040DD05774983EAFC20100002230604054558046456C318901D960B013C8027D62404FCA13447D3A41CB27A6F904519F59D01519A49EA6A02A146479664114E4E4997582A8482708167BC168A0984C078301", 
//  "06910379010023040DD05774983EAFC20100002230608044508047456C31890161B2CE2725B90C8262B09BED04B2409F18D0931204518320487249CD064196671644414E9E5927888A748262B5176CF692C16432504CA683C100", 
//  "06910379010023040DD05774983EAFC2010000223060804401803C456C318901C564301868DA9C822CD0270654CC3893CB2008925C52B34190E5990551909367D609A2229DA058ED059B8164341D0C06",
  "06910379010023040DD05774983EAFC20100002230608044518049456C318901C570B51808528116834E5053089A2483200BE5899C2031481086FA04259DD4A2D459A4829A452C3409A226312098EC05A3BD6430990C04B3E96630"
};
void setup() {
  Serial.begin(9600);
#ifdef PM
  Serial.println("Using PM");
#else
  Serial.println("Not using PM");
#endif
  for (int i=0; i< sizeof(inpdu)/sizeof(const char *); i++) {
    if (mypdu.decodePDU(inpdu[i])) {
      Serial.println("-------------------------------");
      Serial.println(mypdu.getSCAnumber());
      Serial.println(mypdu.getSender());
      Serial.println(mypdu.getTimeStamp());
      Serial.println(mypdu.getText());
    }
    else
      Serial.println("failed");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}