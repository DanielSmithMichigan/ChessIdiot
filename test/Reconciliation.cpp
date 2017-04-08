	#include "Reconciliation.h"
	string allFileLocations[] = {"startingPosition","test_102699","test_105112","test_107204","test_110219","test_122484","test_141103","test_146181","test_149605","test_170845","test_173098","test_181621","test_82218","test_183876","test_185403","test_197730","test_198373","test_207225","test_207614","test_214950","test_222437","test_226000","test_226219","test_231897","test_233151","tes_233607","test_233873","test_234743","test_236855","test_239585","test_244560","test_257334","test_267832","test_274299","test_287516","test_289327","test_293140","test_313718","tst_337239","test_339642","test_345919","test_369595","test_379167","test_379819","test_380692","test_384373","test_391851","test_392850","test_393143","test_397265","test_401200","test_403660","test_404066","test_422749","test_431436","test_435887","test_447789","test_452290","test_460910","test_460920","test_466716","test_480489","test_491405","test_502503","test_506164","test_516128","test_517566","test_521300","test_560777","test_561756","test_571779","test_587135","test_587420","test_592952","test_595547","test_600490","test_60243","test_603435","test_607059","test_617395","test_619876","test_620825","test_622567","test_629245","test_655524","test_678138","test_693836","test_696800","test_711575","test_71683","test_718812","test_731427","test_742469","test_751926","test_759154","test_764731","test_765196","test_767525","test_768201","test_769438","test_773977","test_796649","test_02478","test_803068","test_818338","test_826509","test_827795","test_829406","test_832116","test_848068","test_854959","test_857683","test_862765","test_869830","test_872721","tes_880173","test_884619","test_887365","test_902700","test_922359","test_926761","test_940613","test_951330","test_967182","test_980088","test_991494","test_999512"};
	int numTests = 127;
	Reconciliation::Reconciliation() {
		board.reset(new TestBoard());
		moveStack.reset(new TestMoveStack(board));
		attackedSquare.reset(new AttackedSquare(board));
		moveGenerationController.reset(new MoveGenerationController(board, moveStack, attackedSquare));
		fen.reset(new Fen(board));
	}

	Reconciliation::~Reconciliation() {
	}

	void Reconciliation::executeTestFile(string filename) {
		ifstream infile("../test/Reconciliation/" + filename);
		string fenStr;
		getline(infile, fenStr);
		fen->import(fenStr);
		vector<string> comparisonFens, myFens;
		while (getline(infile, fenStr)) {
			comparisonFens.push_back(fenStr);
		}
		moveGenerationController->generateAllMoves();
		uint32_t currentMove;
		while (currentMove = moveStack->pop()) {
			board->doMove(currentMove);
			if (attackedSquare->kingInCheck(GET_OPPOSING_COLOR(board->turn))) {
				board->undoMove();
				continue;
			}
			myFens.push_back(fen->exportLegacyBoard());
			board->undoMove();
		}
		assertStringVectorMatch(comparisonFens, myFens);
	}

	TEST_F(Reconciliation, startingPosition) {
		executeTestFile("startingPosition");
	}
	TEST_F(Reconciliation, test_296540) {
		executeTestFile("test_296540");
	}
	TEST_F(Reconciliation, test_515661) {
		executeTestFile("test_515661");
	}
	TEST_F(Reconciliation, test_689719) {
		executeTestFile("test_689719");
	}
	TEST_F(Reconciliation, test_830871) {
		executeTestFile("test_830871");
	}
	TEST_F(Reconciliation, test_102075) {
		executeTestFile("test_102075");
	}
	TEST_F(Reconciliation, test_298877) {
		executeTestFile("test_298877");
	}
	TEST_F(Reconciliation, test_527718) {
		executeTestFile("test_527718");
	}
	TEST_F(Reconciliation, test_699942) {
		executeTestFile("test_699942");
	}
	TEST_F(Reconciliation, test_833158) {
		executeTestFile("test_833158");
	}
	TEST_F(Reconciliation, test_105754) {
		executeTestFile("test_105754");
	}
	TEST_F(Reconciliation, test_305861) {
		executeTestFile("test_305861");
	}
	TEST_F(Reconciliation, test_529851) {
		executeTestFile("test_529851");
	}
	TEST_F(Reconciliation, test_706327) {
		executeTestFile("test_706327");
	}
	TEST_F(Reconciliation, test_841848) {
		executeTestFile("test_841848");
	}
	TEST_F(Reconciliation, test_118681) {
		executeTestFile("test_118681");
	}
	TEST_F(Reconciliation, test_306329) {
		executeTestFile("test_306329");
	}
	TEST_F(Reconciliation, test_535400) {
		executeTestFile("test_535400");
	}
	TEST_F(Reconciliation, test_711396) {
		executeTestFile("test_711396");
	}
	TEST_F(Reconciliation, test_852649) {
		executeTestFile("test_852649");
	}
	TEST_F(Reconciliation, test_120644) {
		executeTestFile("test_120644");
	}
	TEST_F(Reconciliation, test_332440) {
		executeTestFile("test_332440");
	}
	TEST_F(Reconciliation, test_536410) {
		executeTestFile("test_536410");
	}
	TEST_F(Reconciliation, test_715207) {
		executeTestFile("test_715207");
	}
	TEST_F(Reconciliation, test_860999) {
		executeTestFile("test_860999");
	}
	TEST_F(Reconciliation, test_130476) {
		executeTestFile("test_130476");
	}
	TEST_F(Reconciliation, test_353779) {
		executeTestFile("test_353779");
	}
	TEST_F(Reconciliation, test_546390) {
		executeTestFile("test_546390");
	}
	TEST_F(Reconciliation, test_720075) {
		executeTestFile("test_720075");
	}
	TEST_F(Reconciliation, test_862099) {
		executeTestFile("test_862099");
	}
	TEST_F(Reconciliation, test_133281) {
		executeTestFile("test_133281");
	}
	TEST_F(Reconciliation, test_364222) {
		executeTestFile("test_364222");
	}
	TEST_F(Reconciliation, test_554177) {
		executeTestFile("test_554177");
	}
	TEST_F(Reconciliation, test_725576) {
		executeTestFile("test_725576");
	}
	TEST_F(Reconciliation, test_871877) {
		executeTestFile("test_871877");
	}
	TEST_F(Reconciliation, test_140906) {
		executeTestFile("test_140906");
	}
	TEST_F(Reconciliation, test_369941) {
		executeTestFile("test_369941");
	}
	TEST_F(Reconciliation, test_557523) {
		executeTestFile("test_557523");
	}
	TEST_F(Reconciliation, test_725703) {
		executeTestFile("test_725703");
	}
	TEST_F(Reconciliation, test_891355) {
		executeTestFile("test_891355");
	}
	TEST_F(Reconciliation, test_141504) {
		executeTestFile("test_141504");
	}
	TEST_F(Reconciliation, test_371092) {
		executeTestFile("test_371092");
	}
	TEST_F(Reconciliation, test_560015) {
		executeTestFile("test_560015");
	}
	TEST_F(Reconciliation, test_725789) {
		executeTestFile("test_725789");
	}
	TEST_F(Reconciliation, test_892859) {
		executeTestFile("test_892859");
	}
	TEST_F(Reconciliation, test_142089) {
		executeTestFile("test_142089");
	}
	TEST_F(Reconciliation, test_374382) {
		executeTestFile("test_374382");
	}
	TEST_F(Reconciliation, test_567937) {
		executeTestFile("test_567937");
	}
	TEST_F(Reconciliation, test_726262) {
		executeTestFile("test_726262");
	}
	TEST_F(Reconciliation, test_893868) {
		executeTestFile("test_893868");
	}
	TEST_F(Reconciliation, test_146767) {
		executeTestFile("test_146767");
	}
	TEST_F(Reconciliation, test_380156) {
		executeTestFile("test_380156");
	}
	TEST_F(Reconciliation, test_568046) {
		executeTestFile("test_568046");
	}
	TEST_F(Reconciliation, test_729882) {
		executeTestFile("test_729882");
	}
	TEST_F(Reconciliation, test_900079) {
		executeTestFile("test_900079");
	}
	TEST_F(Reconciliation, test_159064) {
		executeTestFile("test_159064");
	}
	TEST_F(Reconciliation, test_380811) {
		executeTestFile("test_380811");
	}
	TEST_F(Reconciliation, test_574472) {
		executeTestFile("test_574472");
	}
	TEST_F(Reconciliation, test_731407) {
		executeTestFile("test_731407");
	}
	TEST_F(Reconciliation, test_920255) {
		executeTestFile("test_920255");
	}
	TEST_F(Reconciliation, test_173427) {
		executeTestFile("test_173427");
	}
	TEST_F(Reconciliation, test_395925) {
		executeTestFile("test_395925");
	}
	TEST_F(Reconciliation, test_575348) {
		executeTestFile("test_575348");
	}
	TEST_F(Reconciliation, test_747073) {
		executeTestFile("test_747073");
	}
	TEST_F(Reconciliation, test_920445) {
		executeTestFile("test_920445");
	}
	TEST_F(Reconciliation, test_185501) {
		executeTestFile("test_185501");
	}
	TEST_F(Reconciliation, test_402871) {
		executeTestFile("test_402871");
	}
	TEST_F(Reconciliation, test_591762) {
		executeTestFile("test_591762");
	}
	TEST_F(Reconciliation, test_749258) {
		executeTestFile("test_749258");
	}
	TEST_F(Reconciliation, test_920673) {
		executeTestFile("test_920673");
	}
	TEST_F(Reconciliation, test_188160) {
		executeTestFile("test_188160");
	}
	TEST_F(Reconciliation, test_408064) {
		executeTestFile("test_408064");
	}
	TEST_F(Reconciliation, test_594071) {
		executeTestFile("test_594071");
	}
	TEST_F(Reconciliation, test_749635) {
		executeTestFile("test_749635");
	}
	TEST_F(Reconciliation, test_922981) {
		executeTestFile("test_922981");
	}
	TEST_F(Reconciliation, test_193836) {
		executeTestFile("test_193836");
	}
	TEST_F(Reconciliation, test_438582) {
		executeTestFile("test_438582");
	}
	TEST_F(Reconciliation, test_625957) {
		executeTestFile("test_625957");
	}
	TEST_F(Reconciliation, test_756110) {
		executeTestFile("test_756110");
	}
	TEST_F(Reconciliation, test_928527) {
		executeTestFile("test_928527");
	}
	TEST_F(Reconciliation, test_200758) {
		executeTestFile("test_200758");
	}
	TEST_F(Reconciliation, test_466518) {
		executeTestFile("test_466518");
	}
	TEST_F(Reconciliation, test_628235) {
		executeTestFile("test_628235");
	}
	TEST_F(Reconciliation, test_762134) {
		executeTestFile("test_762134");
	}
	TEST_F(Reconciliation, test_933793) {
		executeTestFile("test_933793");
	}
	TEST_F(Reconciliation, test_231489) {
		executeTestFile("test_231489");
	}
	TEST_F(Reconciliation, test_468360) {
		executeTestFile("test_468360");
	}
	TEST_F(Reconciliation, test_638547) {
		executeTestFile("test_638547");
	}
	TEST_F(Reconciliation, test_762625) {
		executeTestFile("test_762625");
	}
	TEST_F(Reconciliation, test_937766) {
		executeTestFile("test_937766");
	}
	TEST_F(Reconciliation, test_231943) {
		executeTestFile("test_231943");
	}
	TEST_F(Reconciliation, test_475448) {
		executeTestFile("test_475448");
	}
	TEST_F(Reconciliation, test_642886) {
		executeTestFile("test_642886");
	}
	TEST_F(Reconciliation, test_772870) {
		executeTestFile("test_772870");
	}
	TEST_F(Reconciliation, test_971329) {
		executeTestFile("test_971329");
	}
	TEST_F(Reconciliation, test_236900) {
		executeTestFile("test_236900");
	}
	TEST_F(Reconciliation, test_476293) {
		executeTestFile("test_476293");
	}
	TEST_F(Reconciliation, test_652954) {
		executeTestFile("test_652954");
	}
	TEST_F(Reconciliation, test_775979) {
		executeTestFile("test_775979");
	}
	TEST_F(Reconciliation, test_982762) {
		executeTestFile("test_982762");
	}
	TEST_F(Reconciliation, test_259182) {
		executeTestFile("test_259182");
	}
	TEST_F(Reconciliation, test_478960) {
		executeTestFile("test_478960");
	}
	TEST_F(Reconciliation, test_655432) {
		executeTestFile("test_655432");
	}
	TEST_F(Reconciliation, test_782306) {
		executeTestFile("test_782306");
	}
	TEST_F(Reconciliation, test_983148) {
		executeTestFile("test_983148");
	}
	TEST_F(Reconciliation, test_262151) {
		executeTestFile("test_262151");
	}
	TEST_F(Reconciliation, test_488360) {
		executeTestFile("test_488360");
	}
	TEST_F(Reconciliation, test_660883) {
		executeTestFile("test_660883");
	}
	TEST_F(Reconciliation, test_788259) {
		executeTestFile("test_788259");
	}
	TEST_F(Reconciliation, test_987775) {
		executeTestFile("test_987775");
	}
	TEST_F(Reconciliation, test_262867) {
		executeTestFile("test_262867");
	}
	TEST_F(Reconciliation, test_491325) {
		executeTestFile("test_491325");
	}
	TEST_F(Reconciliation, test_669276) {
		executeTestFile("test_669276");
	}
	TEST_F(Reconciliation, test_797072) {
		executeTestFile("test_797072");
	}
	TEST_F(Reconciliation, test_996611) {
		executeTestFile("test_996611");
	}
	TEST_F(Reconciliation, test_279351) {
		executeTestFile("test_279351");
	}
	TEST_F(Reconciliation, test_507492) {
		executeTestFile("test_507492");
	}
	TEST_F(Reconciliation, test_677497) {
		executeTestFile("test_677497");
	}
	TEST_F(Reconciliation, test_799836) {
		executeTestFile("test_799836");
	}
	TEST_F(Reconciliation, test_287509) {
		executeTestFile("test_287509");
	}
	TEST_F(Reconciliation, test_507741) {
		executeTestFile("test_507741");
	}
	TEST_F(Reconciliation, test_682930) {
		executeTestFile("test_682930");
	}
	TEST_F(Reconciliation, test_817672) {
		executeTestFile("test_817672");
	}
	TEST_F(Reconciliation, test_296116) {
		executeTestFile("test_296116");
	}
	TEST_F(Reconciliation, test_509114) {
		executeTestFile("test_509114");
	}
	TEST_F(Reconciliation, test_686814) {
		executeTestFile("test_686814");
	}
	TEST_F(Reconciliation, test_829182) {
		executeTestFile("test_829182");
	}