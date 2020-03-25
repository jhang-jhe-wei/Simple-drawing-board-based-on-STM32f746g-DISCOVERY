  /**
  ******************************************************************************
  * @file    GUI_App.c
  * @author  MCD Application Team
  * @brief   Simple demo drawing "Hello world"  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright © 2018 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "GUI_App.h"
#include "GUI.h"
#include "stdio.h"
#include "DIALOG.h"
extern  WM_HWIN CreateFramewin(void); 
extern void BSP_Touch_Update(void);

void GRAPHICS_MainTask(void) {
  /* 1- Create a FrameWin using GUIBuilder */		
	GUI_Init();	
	WM_HWIN hWin=CreateFramewin();
	WM_HWIN hWinOld;
	GUI_PID_STATE a;
	GUI_SetBkColor(GUI_WHITE);
	GUI_SetColor(GUI_BLACK);
/* USER CODE BEGIN GRAPHICS_MainTask */
 /* User can implement his graphic application here */ 
		 
/* USER CODE END GRAPHICS_MainTask */
	
  while(1)
{			
			
			hWinOld = WM_SelectWindow(WM_GetClientWindow(hWin));	
			GUI_SetPenSize(10);	
			GUI_PID_GetState(&a);
			if(a.x<=390)
				{
					int oldx=a.x;
					int oldy=a.y;
					while(GUI_PID_IsPressed())
									{	
										if(a.x>390)
											a.x=390;										
										GUI_DrawLine(oldx,oldy,a.x,a.y);
										oldx=a.x;
										oldy=a.y;
										BSP_Touch_Update();
										GUI_PID_GetState(&a);
									}		
				}								     				
      WM_SelectWindow(hWinOld);				
			BSP_Touch_Update();				
			GUI_Delay(10);
}
}

/*************************** End of file ****************************/
