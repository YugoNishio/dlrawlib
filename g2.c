#include <drawlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

  void reflect (float *vx, float *vy, int y, int bary, int barh) {
  float hity = fabs((float)(y - bary) / (barh / 2));
  float weight = 0.75 * hity + 0.75;
  *vx *= -1.0 * weight;
  *vy *= weight; 
}

int main(void) {
  float wait_time = 0.01;
  /*playerの幅と高さ*/
  int pw = 50, ph = 30;
  /*computer no haba to takasa*/
  int cw = 30, ch = 60;
  /*playerの動く距離の幅*/
  int pdy = 20;
  /*playerの動く距離の幅*/
  int pdx = 100;
  /*player,computerの位置.,DL_WIDTH / 2 は画面中央部*/
  int pix = 70, cix = DL_WIDTH - 70;
  /*playerの初期位置(?)*/
  int px = pix, py = DL_HEIGHT / 2;
  /*赤板の入力装置*/
  int pup = 'w', pdown = 's', pfront = 'e';
  /*computerの初期位置*/
  int cx = cix, cy = DL_HEIGHT / 2;
  /*computer no sayuu no sokudo*/
  float cvy = -10.0;
  /*弾の大きさ*/
  int br = 5;
  /*弾の速度*/
  float bvx = 40, bvy = 2;
  /*?*/
  int bx = DL_WIDTH / 2, by = DL_HEIGHT / 2;
  
  int score1 = 0, score2 = 0;
  int sx = DL_WIDTH / 2 - 120, sy = 50;
  char sscore[] = "   :   ";
  
  /*dl_get_event用の関数*/
  int t, k, x, y;
  
  dl_initialize(1.0);
  
  while (1) {
  /*player idou*/
    while (dl_get_event(&t, &k, &x, &y)) {
      if (t == DL_EVENT_KEY) {
      	if (k == pup)
          py -= pdy;
        else if (k == pdown)
          py += pdy;
        else if (k == pfront) {
          if (px > pix) 
            px = pix;
          else
            px += pdx;
        } 
        /*com idou*/
  
     }
     }
        
    if (py - ph / 2 < 0)
      py = ph / 2;
    if (py + ph / 2 > DL_HEIGHT)
      py = DL_HEIGHT - ph / 2;
    if (cy - ph / 2 < 0)
      cy = ph / 2;
    if (cy + ph / 2 > DL_HEIGHT)
      cy = DL_HEIGHT - ph / 2;
      
      /**/
    bx += bvx;
    
    if (by - br <= 0) {
      by = br + 1;
      bvy *= -1;
    } else if (by + br >= DL_HEIGHT) {
      by = DL_HEIGHT - br - 1;
      bvy *= -1;
    }


  /*atari hanntei*/

    
    if (by > cy - ch / 2 && by < cy + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        reflect (&bvx, &bvy, by, cy, ch);
      }
    }

    

    /*自動射撃*/
   
     if (bx + br >= DL_WIDTH || bx - br <= 0) {
        bx = px + pw + 1;
        by = py;
        bvx = 40.0;
        bvy = 2.0;
          }
      
      


    if(score1 > 999)
      score1 = 999;
    if(score2 > 999)
      score2 = 999;
    
    dl_stop();
    dl_clear(DL_C("black"));
    /*player*/
    dl_rectangle(px - pw / 2, py - ph / 2, px + pw / 2, py + ph / 2, DL_C("white"), 2, 0);
    /*computer*/
    dl_rectangle(cx - cw / 2, cy - ch / 2, cx + cw / 2, cy + ch / 2, DL_C("green"), 1, 1);
    
    dl_circle(bx, by, br, DL_C("white"), 1, 1);
    sprintf(sscore, "%3d:%d", score1, score2);
    dl_text(sscore, sx, sy, 2.0, DL_C("white"), 2);
    
    dl_resume();

    dl_wait(wait_time);
  }

  return 0;
}
