#include <iostream>
#include "pdulib.h"

//aleph bet gimmel dialled from 0545919886 SCA 9725412003
//+CMT: "",27
//                  0         1         2         3         4         5         6         7            
const char pdu[] = "07917952140230F2040C917952541989680008128013713105210805D005D105D205D3";
const char pdu2[] = "0C917952541989680008128013713105210805D005D105D205D3";
const char pdu3[] = "0791797232080060040CA14487772342580000128013716170210441F1980C";
const char pdu4[] = "0791797232080040040CA14487772342580008129061214053210605D005D105D2";

char pdubuffer[200];  // should be big enough

PDU pduEngine = PDU();

void decode(const char *P) {
  pduEngine.decodePDU(P);
  std::cout << "From: " << pduEngine.getSender() << std::endl;
  std::cout << "Via: " << pduEngine.getSCA() << std::endl;
  std::cout << "Time: " << pduEngine.getTimeStamp() << std::endl;
  std::cout << "Message: ";
  const unsigned char *mess = pduEngine.getText();
  std::cout << mess << std::endl;
}

int main() {
  int len;
  //decode(pdu);
  //decode(pdu3);
  //decode(pdu4);
//  len = pduEngine.encodePDU("0545919886",NATIONAL_NUMERIC,"hello 12",ALPHABET_7BIT);
//  len = pduEngine.encodePDU("+972545919886",INTL_NUMERIC,"hello 23",ALPHABET_7BIT);
  len = pduEngine.encodePDU("+972545919886",INTL_NUMERIC,"abcאבג",ALPHABET_16BIT);
//    pduEngine.setAddress("972545919886",INTL_NUMERIC);
//    pduEngine.setAddress("0545919886",NATIONAL_NUMERIC);
//    pduEngine.setAddress("david",ALPHABETIC);
//  pduEngine.decodeAddress(pdu2,pdubuffer,NIBBLES);
}