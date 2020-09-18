#include <drawlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>


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
  /*playerの動く距離の幅*/
  int pdy = 20;
  /*playerの動く距離の幅*/
  int pdx = 100;
  /*player no iti*/
  int pix = 70; 
  /*playerの初期位置(?)*/
  int px = pix, py = DL_HEIGHT / 2;
  /*playerの入力*/
  int pup = 'w', pdown = 's', pfront = 'e';
/*------------------------------------------------------------------------*/
  /*computerの幅と高さ*/
  int cw = 30, ch = 40;
  /*computerの位置.,DL_WIDTH / 2 は画面中央部*/
  int cix = DL_WIDTH - 70;
  /*computerの初期位置*/
  int cx = cix;
  int cy1 = 30;
  int cy2 = cy1 + ch + 20;
  int cy3 = cy2 + ch + 20;
  int cy4 = cy3 + ch + 20;
  int cy5 = cy4 + ch + 20;
  int cy6 = cy5 + ch + 20;
  int cy7 = cy6 + ch + 20;
  int cy8 = cy7 + ch + 20;
 /*computerの左右の速度*/
  float cvy = -10.0;
/*------------------------------------------------------------------------*/
  /*playerの弾の大きさ*/
  int br = 5;
  /*playerの一発目の速度*/
  float bvx = 40, bvy = 2;
  /*syoki syutugenn iti?*/
  int bx = DL_WIDTH / 2, by = DL_HEIGHT / 2;
/*------------------------------------------------------------------------*/
  /*computer no tama*/
  int cbr = 10;
  /*一発目の速度*/
  float cbvx = -5, cbvy = 2;
  float cbvx1 = -5.0;
  float cbvx2 = -5.0;
  float cbvx3 = -5.0;
  float cbvx4 = -5.0;
  float cbvx5 = -5.0;
  float cbvx6 = -5.0;
  float cbvx7 = -5.0;
  float cbvx8 = -5.0;
  /*?*/
  int cbx1 = DL_WIDTH / 2, cby = 600;//DL_HEIGHT / 2;
  int cbx2 = DL_WIDTH / 2;
  int cbx3 = DL_WIDTH / 2;
  int cbx4 = DL_WIDTH / 2;
  int cbx5 = DL_WIDTH / 2;
  int cbx6 = DL_WIDTH / 2;
  int cbx7 = DL_WIDTH / 2;
  int cbx8 = DL_WIDTH / 2;
  int cbx = DL_WIDTH / 2;
  
  
  int cby1 = cy1;
  int cby2 = cy2;
  int cby3 = cy3;
  int cby4 = cy4;
  int cby5 = cy5;
  int cby6 = cy6;
  int cby7 = cy7;
  int cby8 = cy8;
  
  int score1 = 0, score2 = 0;
  int sx = DL_WIDTH / 2 - 120, sy = 50;
  char sscore[] = "   :   ";
  
  /*dl_get_event用の関数*/
  int t, k, x, y;
  
/*------------------------------------------------------------------------*/
  dl_initialize(1.0);
  
  
  while (1) {
  /*player 移動*/
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
    
      /*弾に関係すること-------------------------------------*/
    bx += bvx;
    
    if (by - br <= 0) {
      by = br + 1;
      bvy *= -1;
    } else if (by + br >= DL_HEIGHT) {
      by = DL_HEIGHT - br - 1;
      bvy *= -1;
    }
    
    
    
    cbx += cbvx1;
    if (cby - cbr <= 0) {
      cby = cbr + 1;
      cbvy *= -1;
     }
     
    
     
     
     
  

  /*当たり判定----------------------------------------------------------------------------*/

    /* cy8*/
    if (by > cy8 - ch / 2 && by < cy8 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*画面外に置き、消えた風に見せる*/
         cy8 = -300;
         /*衝突時に弾を消す*/
         br = 0;
      }
    }
    /* cy2*/

    if (by > cy2 - ch / 2 && by < cy2 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy2 = -300;
         /*tama wo kesu*/
         br = 0;
         
      }
    }
    /* cy1*/
    if (by > cy1 - ch / 2 && by < cy1 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy1 = -300;
         /*tama wo kesu*/
         br = 0;
      }
    }
    
    /* cy3*/
    if (by > cy3 - ch / 2 && by < cy3 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy3 = -300;
         /*tama wo kesu*/
         br = 0;
         
      }
    }
    /* cy4*/
    if (by > cy4 - ch / 2 && by < cy4 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy4 = -300;
         cbvx1 = -40.0;
         /*tama wo kesu*/
         br = 0;
         
      }
    }
    
    /*cx5 to cy5*/
    if (by > cy5 - ch / 2 && by < cy5 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy5 = -300;
         cbr = 5;
         /*tama wo kesu*/
         br = 0;
         
      }
    }
    /* cy6*/
    if (by > cy6 - ch / 2 && by < cy6 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy6 = -300;
         cbvx1 = -10;
         /*tama wo kesu*/
         br = 0;
         
      }
    }
    /* cy7*/
    if (by > cy7 - ch / 2 && by < cy7 + ch / 2) {
      if (bvx < 0 && bx - br <= cx + cw / 2 && bx - br >= cx - cw / 2
        || bvx > 0 && bx + br >= cx - cw / 2 && bx + br <= cx + cw / 2) {
        /*gamenngai ni oite kesiteiruhuunisuru*/
         cy7 = -300;
         /*tama wo kesu*/
         br = 0;
         
      }
    }
    
    /* player*/
    if (cby4 > py - ph / 2 && cby4 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2
        || cbvx > 0 && cbx + cbr >= px - pw / 2 && cbx + cbr <= px + pw / 2) {
         py = 900;
         /*tama wo kesu*/
         br = 0;
      }
    }
    if (cby5 > py - ph / 2 && cby5 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2
        || cbvx > 0 && cbx + cbr >= px - pw / 2 && cbx + cbr <= px + pw / 2) {
         py = 900;
         /*tama wo kesu*/
         br = 0;
      }
    }


    /*自動射撃---------------------------------------------------------------------------------*/
   /*playerの射撃*/
     if (bx + br >= DL_WIDTH || bx - br <= 0) { //|| br == 0) {
        br = 5;
        bx = px + pw + 1;
        by = py;
        bvx = 40.0;
        bvy = 2.0;
       }

    /**/
     /*computerの射撃*/
  if (cbx + cbr >= DL_WIDTH || cbx - cbr <= 0) {
        cbx = cx + cw + 1;
        
        cby1 = cy1;
        cby2 = cy2;
        cby3 = cy3;
        cby4 = cy4;
        cby5 = cy5;
        cby6 = cy6;
        cby7 = cy7;
        cby8 = cy8;
        cbvx = -5.0;
        cbvy = 2.0;
        }
        /*
        if (cbx1 + cbr >= DL_WIDTH || cbx1 - cbr <= 0) {
        cbx1 = cx + cw + 1;
        cbvx1 = -40.0;
        cby1 = cy1;
        }
        
        cbvx2 = -5.0;
        cbvx3 = -5.0;
        cbvx4 = -5.0;
        cbvx5 = -5.0;
        cbvx6 = -5.0;
        cbvx7 = -5.0;
        cbvx8 = -5.0;
        
        cbvy = 2.0;
        } 
        */
        
        /*
        if(py == -300) {
          printf("!!!!\n");
          break;
          }
        */
        
     

     
      if(cy1 == -300 && cy2 == -300 && cy3 == -300 && cy4 == -300 && cy5 == -300 && cy6 == -300 && cy7 == -300 && cy8 == -300) {
      printf("FINISHI !!\n");
      break;
      }
      
       
        //
    
    
    dl_stop();
    dl_clear(DL_C("black"));
    /*playerの操作対象*/
    dl_rectangle(px - pw / 2, py - ph / 2, px + pw / 2, py + ph / 2, DL_C("white"), 2, 0);
    /*computerの操作対象*/
    dl_rectangle(cx - cw / 2, cy1 - ch / 2, cx + cw / 2, cy1 + ch / 2, DL_C("green"), 1, 1);
    dl_rectangle(cx - cw / 2, cy2 - ch / 2, cx + cw / 2, cy2 + ch / 2, DL_C("red"), 1, 1);
    dl_rectangle(cx - cw / 2, cy3 - ch / 2, cx + cw / 2, cy3 + ch / 2, DL_C("red"), 2, 0);
    dl_rectangle(cx - cw / 2, cy4 - ch / 2, cx + cw / 2, cy4 + ch / 2, DL_C("yellow"), 1, 1);
    dl_rectangle(cx - cw / 2, cy5 - ch / 2, cx + cw / 2, cy5 + ch / 2, DL_C("yellow"), 2, 0);
    dl_rectangle(cx - cw / 2, cy6 - ch / 2, cx + cw / 2, cy6 + ch / 2, DL_C("cyan"), 1, 1);
    dl_rectangle(cx - cw / 2, cy7 - ch / 2, cx + cw / 2, cy7 + ch / 2, DL_C("cyan"), 2, 0);
    dl_rectangle(cx - cw / 2, cy8 - ch / 2, cx + cw / 2, cy8 + ch / 2, DL_C("magenda"), 1, 1);
    /*playerの弾*/
    dl_circle(bx, by, br, DL_C("white"), 1, 1);
    /*computerの弾*/
    
    dl_circle(cbx, cby1, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby2, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby3, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby4, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby5, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby6, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby7, cbr, DL_C("white"), 1, 1);
    dl_circle(cbx, cby8, cbr, DL_C("white"), 1, 1);
    
    dl_circle(cbx, cby, cbr, DL_C("white"), 1, 1);
    
    sprintf(sscore, "%3d:%d", score1, score2);
    dl_text(sscore, sx, sy, 2.0, DL_C("white"), 2);
    
    dl_resume();

    dl_wait(wait_time);
  }

  return 0;
}
