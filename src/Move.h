#ifndef Move_h
#define Move_h
	#define FULL_MOVE(x1,y1,x2,y2,captured,enPassant,firstMove,promotedPiece,castle) ( x1 | (y1 << 4) | (x2 << 8) | (y2 << 12) | (captured << 16) | (enPassant << 20) | (pawnStart << 21) | (promotedPiece << 22) | (castle << 26))
	#define MOVE(x1,y1,x2,y2) ( x1 | (y1 << 4) | (x2 << 8) | (y2 << 12))
	#define X1(m) ((m) & 0xF)
	#define Y1(m) (((m)>>4) & 0xF)
	#define X2(m) (((m)>>8) & 0xF)
	#define Y2(m) (((m)>>12) & 0xF)
#endif