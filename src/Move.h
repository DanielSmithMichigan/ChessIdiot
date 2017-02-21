#ifndef Move_h
#define Move_h
	#define MOVE(from,to,captured,enPassant,promotedPiece,isCastle,blackCanCastleLeft,blackCanCastleRight,whiteCanCastleLeft,whiteCanCastleRight) ( from | (to << 8) | (captured << 16) | (enPassant << 20) | (promotedPiece << 21) | (isCastle << 25) | (blackCanCastleLeft << 26) | (blackCanCastleRight << 27) | (whiteCanCastleLeft << 28) | (whiteCanCastleRight << 29))
	#define FROM(m) ((m) & 0xFF)
	#define TO(m) ((m>>8) & 0xFF)
	#define CAPTURED_PIECE(m) ((m >> 16) & 0xF)
	#define EN_PASSANT(m) ((m >> 20) & 0x1)
	#define PROMOTEDPIECE(m) ((m >> 21) & 0xF)
	#define CASTLE(m) ((m >> 25) & 0x1)
	#define BLACK_CASTLE_RIGHT_FLAG(m) ((m >> 26) & 0x1)
	#define BLACK_CASTLE_LEFT_FLAG(m) ((m >> 27) & 0x1)
	#define WHITE_CASTLE_RIGHT_FLAG(m) ((m >> 28) & 0x1)
	#define WHITE_CASTLE_LEFT_FLAG(m) ((m >> 29) & 0x1)
#endif