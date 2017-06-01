	#include "EngineComparison.h"

	EngineComparison::EngineComparison() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		Board::reset();
		MoveStack::instance->reset();
	}

	EngineComparison::~EngineComparison() {
	}

	void EngineComparison::SetUp() {
		Board::reset();
	}

	void assertStringVectorMatch(vector<string> &a, vector<string> &b, string initialPosition) {
		vector<string> duplicateB = b;
		while (a.size()) {
			string aElement = a.back();
			a.pop_back();
			vector<string>::iterator it;
			it = find (b.begin(), b.end(), aElement);
			if (it == b.end()) {
				ASSERT_NE(it, b.end()) << "NF: " << aElement << endl
					                   << " | Original Position: " << initialPosition << endl
					                   << boost::algorithm::join(duplicateB, "\n") << endl;	
			}
			b.erase(it);
		}
		ASSERT_EQ(b.size(), 0);
	}

	TEST_F(EngineComparison, ExecuteAll) {
		string testCases[] = {
			"test_102075",
			"test_105754",
			"test_113587",
			"test_118681",
			"test_120644",
			"test_130476",
			"test_133281",
			"test_140906",
			"test_141504",
			"test_142089",
			"test_146767",
			"test_159064",
			"test_173427",
			"test_173705",
			"test_175384",
			"test_185501",
			"test_188160",
			"test_188212",
			"test_190584",
			"test_191562",
			"test_193836",
			"test_200330",
			"test_200758",
			"test_204982",
			"test_231489",
			"test_231943",
			"test_234694",
			"test_236900",
			"test_237598",
			"test_239390",
			"test_247493",
			"test_253241",
			"test_254916",
			"test_259182",
			"test_260345",
			"test_262151",
			"test_262867",
			"test_263159",
			"test_269932",
			"test_278015",
			"test_279351",
			"test_280257",
			"test_286034",
			"test_286799",
			"test_287406",
			"test_287509",
			"test_292821",
			"test_296116",
			"test_296172",
			"test_296540",
			"test_298877",
			"test_305861",
			"test_306329",
			"test_306862",
			"test_309448",
			"test_313277",
			"test_319107",
			"test_320189",
			"test_323947",
			"test_325114",
			"test_329406",
			"test_332440",
			"test_353779",
			"test_364222",
			"test_366185",
			"test_369941",
			"test_371092",
			"test_374382",
			"test_380156",
			"test_380811",
			"test_381776",
			"test_382465",
			"test_392681",
			"test_394875",
			"test_395925",
			"test_397584",
			"test_399863",
			"test_400001",
			"test_402871",
			"test_405454",
			"test_407398",
			"test_408064",
			"test_408908",
			"test_428587",
			"test_438582",
			"test_456949",
			"test_459667",
			"test_466518",
			"test_467423",
			"test_468360",
			"test_475448",
			"test_476293",
			"test_478753",
			"test_478960",
			"test_483941",
			"test_486778",
			"test_488360",
			"test_491325",
			"test_506609",
			"test_507492",
			"test_507741",
			"test_509114",
			"test_514549",
			"test_515661",
			"test_523962",
			"test_527718",
			"test_529851",
			"test_530123",
			"test_535400",
			"test_536410",
			"test_543776",
			"test_546390",
			"test_548253",
			"test_554177",
			"test_557523",
			"test_560015",
			"test_563370",
			"test_566491",
			"test_567601",
			"test_567937",
			"test_568046",
			"test_572457",
			"test_574472",
			"test_575348",
			"test_582273",
			"test_586131",
			"test_591762",
			"test_593378",
			"test_594071",
			"test_601002",
			"test_612323",
			"test_625957",
			"test_628235",
			"test_634786",
			"test_638547",
			"test_640313",
			"test_642886",
			"test_647190",
			"test_648964",
			"test_652954",
			"test_655432",
			"test_660883",
			"test_667913",
			"test_669276",
			"test_675198",
			"test_676920",
			"test_677497",
			"test_680447",
			"test_682930",
			"test_686814",
			"test_689197",
			"test_689719",
			"test_689830",
			"test_698906",
			"test_699942",
			"test_704362",
			"test_706327",
			"test_711396",
			"test_711667",
			"test_713857",
			"test_715207",
			"test_720075",
			"test_725576",
			"test_725703",
			"test_725789",
			"test_726262",
			"test_729882",
			"test_730606",
			"test_731407",
			"test_737081",
			"test_743851",
			"test_744796",
			"test_746157",
			"test_747073",
			"test_747862",
			"test_748017",
			"test_749209",
			"test_749258",
			"test_749635",
			"test_750712",
			"test_756110",
			"test_762134",
			"test_762625",
			"test_765996",
			"test_766634",
			"test_772870",
			"test_773231",
			"test_775979",
			"test_777789",
			"test_780774",
			"test_782306",
			"test_788259",
			"test_796121",
			"test_797072",
			"test_799828",
			"test_799836",
			"test_800180",
			"test_800923",
			"test_801770",
			"test_806920",
			"test_809382",
			"test_817672",
			"test_827619",
			"test_829182",
			"test_830871",
			"test_833158",
			"test_839399",
			"test_841848",
			"test_846272",
			"test_852649",
			"test_857976",
			"test_860999",
			"test_862099",
			"test_862361",
			"test_871877",
			"test_873799",
			"test_875767",
			"test_886519",
			"test_891178",
			"test_891355",
			"test_892859",
			"test_893868",
			"test_900079",
			"test_900476",
			"test_903640",
			"test_908012",
			"test_920255",
			"test_920445",
			"test_920673",
			"test_922981",
			"test_924365",
			"test_927590",
			"test_928527",
			"test_932332",
			"test_933793",
			"test_934337",
			"test_937766",
			"test_946049",
			"test_949726",
			"test_953132",
			"test_953765",
			"test_962894",
			"test_971329",
			"test_972437",
			"test_981714",
			"test_982762",
			"test_982985",
			"test_983148",
			"test_987775",
			"test_991120",
			"test_996611",
			"test_999414",
		};
		for (int i = 0; i < 252; i++) {
			executeTestFile(testCases[i]);
		}
	}

	void EngineComparison::executeTestFile(string filename) {
		ifstream infile("../test/engine-comparison/" + filename);
		string fenStr, initialPosition;
		getline(infile, initialPosition);
		Fen::import(initialPosition);
		vector<string> comparisonFens, myFens;
		while (getline(infile, fenStr)) {
			comparisonFens.push_back(fenStr);
		}
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t currentMove;
		while (currentMove = MoveStack::instance->pop()) {
			Board::doMove(currentMove);
			if (canTakeKing()) {
				Board::undoMove();
				continue;
			}
			myFens.push_back(Fen::exportLegacyBoard());
			Board::undoMove();
		}
		assertStringVectorMatch(comparisonFens, myFens, initialPosition);
	}