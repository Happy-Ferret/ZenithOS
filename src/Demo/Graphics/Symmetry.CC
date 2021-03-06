/*Demonstrates symmetry.
Right-click and draw line of symmetry.
If the line of symmetry is a point, symmetry is turned-off.
*/

U0 SymmetryDemo()
{
	I64 message_code,x1,y1,x2,y2,arg1,arg2;
	CDC *dc=DCAlias;

	SettingsPush; //See $LK,"SettingsPush",A="MN:SettingsPush"$
	Fs->win_inhibit=WIG_TASK_DEFAULT-WIF_SELF_FOCUS-WIF_SELF_BORDER;

	WinBorder;
	WinMax;
	DocClear;
	DCFill;
	dc->flags|=DCF_SYMMETRY;
	DCSymmetrySet(dc,Fs->pix_width/2,0,Fs->pix_width/2,1);
	do {
		message_code=GetMessage(&arg1,&arg2,
					1<<MESSAGE_KEY_DOWN+1<<MESSAGE_MS_L_DOWN+
					1<<MESSAGE_MS_R_DOWN);
		switch (message_code) {
			case MESSAGE_MS_R_DOWN:
				dc->flags&=~DCF_SYMMETRY;
				dc->color=ROP_XOR+RED^TRANSPARENT;
				x1=arg1; y1=arg2;
				x2=arg1; y2=arg2;
				while (message_code!=MESSAGE_MS_R_UP) {
					GrLine3(dc,x1,y1,0,x2,y2,0);
					message_code=GetMessage(&arg1,&arg2,
								1<<MESSAGE_MS_R_UP+1<<MESSAGE_MS_MOVE);
					GrLine3(dc,x1,y1,0,x2,y2,0);
					x2=arg1; y2=arg2;
				}
				GrLine3(dc,x1,y1,0,x2,y2,0);
				if (DCSymmetry3Set(dc,x1,y1,0,x2,y2,0,x2,y2,1))
					dc->flags|=DCF_SYMMETRY;
				break;
			case MESSAGE_MS_L_DOWN:
				dc->color=ROP_XOR+BLACK^TRANSPARENT;
				x1=arg1; y1=arg2;
				x2=arg1; y2=arg2;
				while (message_code!=MESSAGE_MS_L_UP) {
					GrLine3(dc,x1,y1,0,x2,y2,0);
					message_code=GetMessage(&arg1,&arg2,
								1<<MESSAGE_MS_L_UP+1<<MESSAGE_MS_MOVE);
					GrLine3(dc,x1,y1,0,x2,y2,0);
					x2=arg1; y2=arg2;
				}
				GrLine3(dc,x1,y1,0,x2,y2,0);
				break;
		}
	} while (message_code!=MESSAGE_KEY_DOWN || (arg1!=CH_ESC && arg1!=CH_SHIFT_ESC));
	GetMessage(,,1<<MESSAGE_KEY_UP);
	DCFill;
	DCDel(dc);
	SettingsPop;
}

SymmetryDemo;  //Execute when #included
