#define D_H 523  
#define RE_H 587  
#define M_H 659  
#define F_H 698  
#define SO_H 784  
#define LA_H 880  
#define S_H 988
#include "Wire.h"
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
#define init_draw 10
unsigned long timer_draw,timer;
int pkj=0;
int length; 
int scale[]={M_H,M_H,RE_H,RE_H,M_H,M_H,RE_H,M_H,M_H,RE_H,SO_H,SO_H,SO_H,SO_H,M_H,M_H,M_H,M_H,RE_H,RE_H,M_H,M_H,RE_H,M_H,M_H,RE_H,LA_H,LA_H,LA_H,LA_H,M_H,M_H,M_H,M_H,RE_H,RE_H,M_H,M_H,RE_H,M_H,M_H,RE_H,SO_H,SO_H,SO_H,SO_H,M_H,RE_H,M_H,M_H,M_H,M_H,M_H,M_H,RE_H,RE_H,RE_H,RE_H,D_H,D_H};       
float durt[]=
{
  0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0,3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0,3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0,3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3};                                                        //音长

int tonepin=10;
String dateStr, ret;
void setup()
{
  Serial.begin(9600);
  timer=millis();
  pinMode(tonepin,OUTPUT);
  length=sizeof(scale)/sizeof(scale[0]);   //计算长度
}

void loop() {
  if (millis() - timer_draw > init_draw)
  {
    pkj-=128;
    u8g.firstPage();
    do {
      draw();
    }
    while ( u8g.nextPage() );
    timer_draw = millis();
    for(int x=0;x<length;x++)
  {
    tone(tonepin,scale[x]);
    delay(500*durt[x]);   //这里用来根据节拍调节延时，500这个指数可以自己调整
    noTone(tonepin);
  }
  delay(2000);
  } 
}
  
  void draw(void) 
{
u8g.setFont(u8g_font_fixed_v0r);
u8g.drawRFrame(0,0,98,24,1);
u8g.setFont(u8g_font_7x13);
u8g.drawStr( 3, 10,  "Justin Bieber");
u8g.drawStr( 40, 20, "Baby ");
u8g.drawFrame(100,0,27,24);
u8g.setFont(u8g_font_baby);
u8g.drawStr( 102, 10, "Acfun");
u8g.drawStr( 104, 20, "Team");
u8g.setPrintPos(pkj, 50); 
u8g.print("And I was like baby baby baby .. I thought youd always be mine ");

 
}

