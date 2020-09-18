#include <drawlib.h>
#include <stdio.h>


int main(void) {
  float wait_time = 0.01;
  
  /*playerの幅と高さ*/
  int pw = 40, ph = 30;
  /*playerの動く距離の幅*/
  int pdy = 20;
  /*playerの動く距離の幅*/
  int pdx = 200;
  /*playerの位置*/
  int pix = 70; 
  /*playerの初期位置*/
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
  /*computerの弾*/
  int cbr = 10;
  float cbvx = -5;
  float cbvx1 = -5.0;
  
  
  int cbx1 = DL_WIDTH / 2, cby = 600;  int cby1 = cy1;
  int cbx2 = DL_WIDTH / 2;             int cby2 = cy2;
  int cbx3 = DL_WIDTH / 2;             int cby3 = cy3;
  int cbx4 = DL_WIDTH / 2;             int cby4 = cy4;
  int cbx5 = DL_WIDTH / 2;             int cby5 = cy5;
  int cbx6 = DL_WIDTH / 2;             int cby6 = cy6;
  int cbx7 = DL_WIDTH / 2;             int cby7 = cy7;
  int cbx8 = DL_WIDTH / 2;             int cby8 = cy8;
  int cbx = DL_WIDTH / 2;
  
  /*dl_get_event用の関数*/
  int t, k, x, y;
  
/*------------------------------------------------------------------------*/
  printf("ーーーー　操作説明とゲームルール　ーーーー\n");
  printf("Wキーで上に上がる\n");
  printf("Sキーで下に下がる\n");
  printf("Eキーで敵に近づく\n");
  printf("敵（赤い四角）をすべて倒すとクリア\n");
  printf("敵が出す弾に当たるとクリア失敗\n");

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
    } 
    else if (by + br >= DL_HEIGHT) {
      by = DL_HEIGHT - br - 1;
      bvy *= -1;
    }
    
    cbx += cbvx1;
    
  /*当たり判定----------------------------------------------------------------------------*/

    /* cy8*/
    if (by > cy8 - ch / 2 && by < cy8 + ch / 2) {
        /*画面外に置き、消えた風に見せる*/
         cy8 = -300;
         cbvx1 = -9.0;
         /*衝突時に弾を消す*/
         br = 0;
      }
    /* cy2*/
    if (by > cy2 - ch / 2 && by < cy2 + ch / 2) {
         cy2 = -300;
         cbvx1 = -4.0;
         cbr = 20;
         br = 0;  
      }
    /* cy1*/
    if (by > cy1 - ch / 2 && by < cy1 + ch / 2) {
         cy1 = -300;
         cbvx1 = -30.0;
         pdy = 100;
         br = 0;
      }
    /* cy3*/
    if (by > cy3 - ch / 2 && by < cy3 + ch / 2) {
         cy3 = -300;
         cbvx1 = -6.0;
         br = 0;  
      }
    /* cy4*/
    if (by > cy4 - ch / 2 && by < cy4 + ch / 2) {
         cy4 = -300;
         cbvx1 = -12.0;
         pdy = 40;
         br = 0;  
      }
    /* cy5*/
    if (by > cy5 - ch / 2 && by < cy5 + ch / 2) {
         cy5 = -300;
         cbr = 5;
         br = 0;  
      }
    /* cy6*/
    if (by > cy6 - ch / 2 && by < cy6 + ch / 2) {
         cy6 = -300;
         cbvx1 = -3;
         cbr = 13;
         br = 0;  
      }
    /* cy7*/
    if (by > cy7 - ch / 2 && by < cy7 + ch / 2) {
         cy7 = -300;
         cbvx1 = -6;
         cy5 = cy4 + ch + 20;
         br = 0;  
      }
   
    /* playerの当たり判定----------------------------------------------------------------------*/
    if (cby1 > py - ph / 2 && cby1 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby2 > py - ph / 2 && cby2 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby3 > py - ph / 2 && cby3 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby4 > py - ph / 2 && cby4 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby5 > py - ph / 2 && cby5 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby6 > py - ph / 2 && cby6 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby7 > py - ph / 2 && cby7 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
    if (cby8 > py - ph / 2 && cby8 < py + ph / 2) {
      if (cbvx < 0 && cbx - cbr <= px + pw / 2 && cbx - cbr >= px - pw / 2) {
         py = 900;
         br = 0;
      }
    }
  

    /*自動射撃---------------------------------------------------------------------------------*/
   /*playerの射撃*/
      if (bx + br >= DL_WIDTH || bx - br <= 0) {
        br = 5;
        bx = px + pw + 1;
        by = py;
        bvx = 20.0;
        bvy = 2.0;
        }
      
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
        }
          
    /*終了-------------------------------------------------------------------------------------------*/
        if(py == 900) {
          printf("ーーーーーーーーーー　ゲームクリア失敗　!!　ーーーーーーーーーー\n");
          break;
          }
        
      if(cy1 == -300 && cy2 == -300 && cy3 == -300 && cy4 == -300 && cy5 == -300 && cy6 == -300 && cy7 == -300 && cy8 == -300) {
      printf("ーーーーーーーーーー　ゲームクリア !!　ーーーーーーーーーー\n");
      break;
      }
    
    dl_stop();
    dl_clear(DL_C("black"));
    /*playerの操作対象*/
    dl_rectangle(px - pw / 2, py - ph / 2, px + pw / 2, py + ph / 2, DL_C("white"), 2, 0);
    /*computerの操作対象*/
    dl_rectangle(cx - cw / 2, cy1 - ch / 2, cx + cw / 2, cy1 + ch / 2, DL_C("red"), 2, 0);
    dl_rectangle(cx - cw / 2, cy2 - ch / 2, cx + cw / 2, cy2 + ch / 2, DL_C("red"), 1, 1);
    dl_rectangle(cx - cw / 2, cy3 - ch / 2, cx + cw / 2, cy3 + ch / 2, DL_C("red"), 2, 0);
    dl_rectangle(cx - cw / 2, cy4 - ch / 2, cx + cw / 2, cy4 + ch / 2, DL_C("red"), 1, 1);
    dl_rectangle(cx - cw / 2, cy5 - ch / 2, cx + cw / 2, cy5 + ch / 2, DL_C("red"), 2, 0);
    dl_rectangle(cx - cw / 2, cy6 - ch / 2, cx + cw / 2, cy6 + ch / 2, DL_C("red"), 1, 1);
    dl_rectangle(cx - cw / 2, cy7 - ch / 2, cx + cw / 2, cy7 + ch / 2, DL_C("red"), 2, 0);
    dl_rectangle(cx - cw / 2, cy8 - ch / 2, cx + cw / 2, cy8 + ch / 2, DL_C("red"), 1, 1);
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
 
    dl_resume();
    dl_wait(wait_time);
  }

  return 0;
}
