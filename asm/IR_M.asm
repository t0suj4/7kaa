;Filename    : IR_M.ASM
;Description : Remap a bitmap on vga image buffer, with mirroring


INCLUDE IMGFUN.inc

.CODE

;--------- BEGIN OF FUNCTION IMGremapHMirror -----------
;
; Remap on the VGA screen
;
; Note : No border checking is made in this function.
;	 Placing an icon outside image buffer will cause serious BUG.
;
; char *imageBuf   - the pointer to the display surface buffer
; int  pitch       - the pitch of the display surface buffer
; int  x1,y1         - the top left vertex of the bar
; char *bitmapPtr  - the pointer to the bitmap array
; char **colorTableArray - the pointer to the scale 0 of remap table array
;
		PUBLIC IMGremapHMirror
IMGremapHMirror PROC   imageBuf, pitch, x1, y1, bitmapPtr, colorTableArray
		LOCAL  mapWidth:DWORD, destLineDiff:DWORD
		STARTPROC

		MOV	EAX, imageBuf		; store the address of the image buffer to a variable
		MOV	image_buf, EAX

		;------ calc bar width and height -----;

		MOV     AX , DS
		MOV	ES , AX

		XOR	EAX, EAX
		MOV	ESI, bitmapPtr
		LODSW
		MOV	mapWidth, EAX
		LODSW
		MOV	ECX, EAX

		MOV	EDX, pitch
		ADD	EDX, mapWidth
		MOV	destLineDiff, EDX

		MOV	EDX, colorTableArray

		CLD                              ; clear direction flag for MOVSB

		;------- pixels copying loop --------;

		CALC_ADDR EDI, x1, y1, pitch            ; Get the offset to the image buffer address
		ADD	EDI, mapWidth
		DEC	EDI				; point to top right hand corner

@@startY:	PUSH	ECX
		MOV	ECX, mapWidth
@@startX:
		LODSB
		MOVSX	EAX, AL
		MOV	EBX, [EDX + 4*EAX]
		MOV	AL,[EDI]
		XLATB	[EBX]
		MOV	[EDI], AL
		DEC	EDI
		LOOP	@@startX

		POP	ECX
		ADD	EDI, destLineDiff
		LOOP	@@startY

@@end:		ENDPROC

IMGremapHMirror ENDP


;---------- END OF FUNCTION IMGremapHMirror ------------

END