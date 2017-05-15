#include "BitBoard.h"

uint64_t BitBoard::RookOccupancyMasks[64] = {};
uint64_t BitBoard::BishopOccupancyMasks[64] = {};
uint64_t *BitBoard::RookPointers[64] = {};
uint64_t *BitBoard::BishopPointers[64] = {};
uint64_t BitBoard::RookAttacks[102400] = {};
uint64_t BitBoard::BishopAttacks[5248] = {};
uint64_t BitBoard::RookShifts[64] = {};
uint64_t BitBoard::BishopShifts[64] = {};
void BitBoard::InitRookBitBoards() {
	uint64_t occupancyMask, subset, index;
	uint64_t counter = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		RookPointers[i] = RookAttacks + counter;
		occupancyMask = (generateSlideMove(0, i, 0, -1) & ~row<0>())
					| (generateSlideMove(0, i, 1, 0) & ~file<7>())
					| (generateSlideMove(0, i, 0, 1) & ~row<7>())
					| (generateSlideMove(0, i, -1, 0) & ~file<0>());
		RookOccupancyMasks[i] = occupancyMask;
		RookShifts[i] = 64 - countOnes(occupancyMask);
		subset = 0;
		do {
			subset = (subset - occupancyMask) & occupancyMask;
			index = (subset * RookMagics[i]) >> RookShifts[i];
			RookPointers[i][index] = generateSlideMove(subset, i, 0, -1)
				| generateSlideMove(subset, i, 1, 0)
				| generateSlideMove(subset, i, 0, 1)
				| generateSlideMove(subset, i, -1, 0);
			counter++;
		} while (subset);
	}
}

void BitBoard::InitBishopBitBoards() {
	uint64_t occupancyMask, subset, index;
	uint64_t counter = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		BishopPointers[i] = BishopAttacks + counter;
		occupancyMask = (generateSlideMove(0, i, -1, -1) & ~row<0>() & ~file<0>())
					| (generateSlideMove(0, i, 1, -1) & ~row<0>() & ~file<7>())
					| (generateSlideMove(0, i, 1, 1) & ~row<7>() & ~file<7>())
					| (generateSlideMove(0, i, -1, 1) & ~row<7>() & ~file<0>());
		BishopOccupancyMasks[i] = occupancyMask;
		BishopShifts[i] = 64 - countOnes(occupancyMask);
		subset = 0;
		do {
			subset = (subset - occupancyMask) & occupancyMask;
			index = (subset * BishopMagics[i]) >> BishopShifts[i];
			BishopPointers[i][index] = generateSlideMove(subset, i, -1, -1)
				| generateSlideMove(subset, i, 1, -1)
				| generateSlideMove(subset, i, 1, 1)
				| generateSlideMove(subset, i, -1, 1);
			counter++;
		} while (subset);
	}
}

uint64_t BitBoard::RookMagics[64] = {
	581000103274234634ULL,
	2306986536220002828ULL,
	9597452289627652097ULL,
	10376575086265630725ULL,
	9944229469659078665ULL,
	288265561598071041ULL,
	27489942373409ULL,
	76842952672968713ULL,
	140738578882688ULL,
	2203998749696ULL,
	19140573327851584ULL,
	4398180761728ULL,
	72567903752704ULL,
	4616752845034627584ULL,
	342308757127036992ULL,
	70370891670144ULL,
	10133653216690180ULL,
	82754751393169424ULL,
	72061992118026368ULL,
	54324739358916612ULL,
	1161946296181883008ULL,
	85568668334883072ULL,
	4820260318396418ULL,
	9246030910992711684ULL,
	293024538940145809ULL,
	1159817645839614464ULL,
	2305878468597974032ULL,
	79164921090304ULL,
	14136799301191337984ULL,
	6630442701961568320ULL,
	4650535352715452672ULL,
	8106479604149002240ULL,
	4613943599267258772ULL,
	5226436455714328578ULL,
	72061994232053888ULL,
	36310345010643076ULL,
	2319362606337360000ULL,
	9227884433112301602ULL,
	4629735637820375168ULL,
	9241456806255951922ULL,
	2315978307410330945ULL,
	1689126889849088ULL,
	578995126639526912ULL,
	726205989736939648ULL,
	290483279774093312ULL,
	8075312573203972608ULL,
	621497023460278309ULL,
	1261009270057476096ULL,
	72620595564794241ULL,
	6929351285934129412ULL,
	9512165380408738304ULL,
	9799973561006555264ULL,
	9223653580553062658ULL,
	74450681632657408ULL,
	2883148330349626112ULL,
	9224357201424941088ULL,
	4827859075989537024ULL,
	216191473976345088ULL,
	108088590105314304ULL,
	9403520420038051840ULL,
	4683748079233466376ULL,
	9331476022247293192ULL,
	306244843384872960ULL,
	36034845761093632ULL
};
uint64_t BitBoard::BishopMagics[64] = {
	297457482031202818ULL,
	288280621158656ULL,
	3647950952890171652ULL,
	360571993156231696ULL,
	2287001384560641ULL,
	2311615447474184448ULL,
	36310830358274304ULL,
	633464861900832ULL,
	288802156709953552ULL,
	4809861998801125376ULL,
	4573977028870320ULL,
	3367793459792ULL,
	2199569042432ULL,
	9223602943457558528ULL,
	53377922768896ULL,
	565159751843906ULL,
	1172062930234053121ULL,
	9012164241801362ULL,
	4611969729505001728ULL,
	11268383609717761ULL,
	2305844392201570304ULL,
	12106524622489389120ULL,
	577024806617221121ULL,
	72216131215034368ULL,
	323258566705220ULL,
	4630933124090560640ULL,
	653022223002701824ULL,
	2607584742593274368ULL,
	72092812776374532ULL,
	1126039493543168ULL,
	18595013747409408ULL,
	576821426531602432ULL,
	80299790958848ULL,
	633868487004160ULL,
	4503878834328072ULL,
	281544316960780ULL,
	9529621209969393952ULL,
	1152992972998312960ULL,
	12105992460002930960ULL,
	4574002865652736ULL,
	140746246619649ULL,
	432627049422671872ULL,
	4639554283101031424ULL,
	9802366098845736960ULL,
	2251843308621840ULL,
	4503608219418880ULL,
	2890193994414949908ULL,
	9241387603863945353ULL,
	2341872366927290368ULL,
	13211345094705ULL,
	19864492703776ULL,
	290486587031438082ULL,
	181555775213666304ULL,
	44495878103057ULL,
	3170569356545425984ULL,
	36047501737919488ULL,
	72077387430367232ULL,
	144277933014385184ULL,
	9232662395795540032ULL,
	9234710475655122960ULL,
	693853697540882432ULL,
	1155173871364931584ULL,
	2306986793381142664ULL,
	20267367427753088ULL
};

uint64_t BitBoard::KnightBoards[64] = {
	9077567998918656ULL,
	4679521487814656ULL,
	38368557762871296ULL,
	19184278881435648ULL,
	9592139440717824ULL,
	4796069720358912ULL,
	2257297371824128ULL,
	1128098930098176ULL,
	2305878468463689728ULL,
	1152939783987658752ULL,
	9799982666336960512ULL,
	4899991333168480256ULL,
	2449995666584240128ULL,
	1224997833292120064ULL,
	576469569871282176ULL,
	288234782788157440ULL,
	4620693356194824192ULL,
	11533718717099671552ULL,
	5802888705324613632ULL,
	2901444352662306816ULL,
	1450722176331153408ULL,
	725361088165576704ULL,
	362539804446949376ULL,
	145241105196122112ULL,
	18049583422636032ULL,
	45053588738670592ULL,
	22667534005174272ULL,
	11333767002587136ULL,
	5666883501293568ULL,
	2833441750646784ULL,
	1416171111120896ULL,
	567348067172352ULL,
	70506185244672ULL,
	175990581010432ULL,
	88545054707712ULL,
	44272527353856ULL,
	22136263676928ULL,
	11068131838464ULL,
	5531918402816ULL,
	2216203387392ULL,
	275414786112ULL,
	687463207072ULL,
	345879119952ULL,
	172939559976ULL,
	86469779988ULL,
	43234889994ULL,
	21609056261ULL,
	8657044482ULL,
	1075839008ULL,
	2685403152ULL,
	1351090312ULL,
	675545156ULL,
	337772578ULL,
	168886289ULL,
	84410376ULL,
	33816580ULL,
	4202496ULL,
	10489856ULL,
	5277696ULL,
	2638848ULL,
	1319424ULL,
	659712ULL,
	329728ULL,
	132096ULL
};

uint64_t KingBoards[64] = {
	4665729213955833856ULL,
	11592265440851656704ULL,
	5796132720425828352ULL,
	2898066360212914176ULL,
	1449033180106457088ULL,
	724516590053228544ULL,
	362258295026614272ULL,
	144959613005987840ULL,
	13853283560024178688ULL,
	16186183351374184448ULL,
	8093091675687092224ULL,
	4046545837843546112ULL,
	2023272918921773056ULL,
	1011636459460886528ULL,
	505818229730443264ULL,
	216739030602088448ULL,
	54114388906344448ULL,
	63227278716305408ULL,
	31613639358152704ULL,
	15806819679076352ULL,
	7903409839538176ULL,
	3951704919769088ULL,
	1975852459884544ULL,
	846636838289408ULL,
	211384331665408ULL,
	246981557485568ULL,
	123490778742784ULL,
	61745389371392ULL,
	30872694685696ULL,
	15436347342848ULL,
	7718173671424ULL,
	3307175149568ULL,
	825720045568ULL,
	964771708928ULL,
	482385854464ULL,
	241192927232ULL,
	120596463616ULL,
	60298231808ULL,
	30149115904ULL,
	12918652928ULL,
	3225468928ULL,
	3768639488ULL,
	1884319744ULL,
	942159872ULL,
	471079936ULL,
	235539968ULL,
	117769984ULL,
	50463488ULL,
	12599488ULL,
	14721248ULL,
	7360624ULL,
	3680312ULL,
	1840156ULL,
	920078ULL,
	460039ULL,
	197123ULL,
	49216ULL,
	57504ULL,
	28752ULL,
	14376ULL,
	7188ULL,
	3594ULL,
	1797ULL,
	770ULL
};