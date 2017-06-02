#ifndef Zobrist_cpp
#define Zobrist_cpp
	#include "Zobrist.h"

	uint64_t Zobrist::PieceBySquare[7][64] = {
		{0x7646D91E77D1E858ULL,0x28C56199B924DD5BULL,0xA62A1B4B85DB7648ULL,0x28205E70C5685467ULL,0x54DD2A80936B4D0AULL,0x242EC51A103555DBULL,0x575DC663C787C3D6ULL,0x47C0931C243B9E3CULL,0x749E18BB77047E9CULL,0x367A8BB622495B93ULL,0x52BBE6740C0D9C2BULL,0x5E1835A92A63A014ULL,0x5823C16457E96CBBULL,0x9D7EA49C2D87D27DULL,0x248A983795ED6900ULL,0x68191C561B6465A4ULL,0xB4E1BC83C2BA1983ULL,0x51E83E02EE357CC2ULL,0x4EE37751CD5174C3ULL,0x19A35AA8DD07D808ULL,0x473A737C3E364393ULL,0xC2A9C69A2E046832ULL,0x71C6683999E89815ULL,0xB946E44DDBC1B479ULL,0x762BC462D8D82881ULL,0x8EE6939C3C0EDDC3ULL,0x9C78E22696EB3689ULL,0xD69B535DD849CA7AULL,0x2B310E642C295C14ULL,0xD7A99DE53C76705EULL,0x178C8424836C0BAAULL,0x3ECE494D1B79560AULL,0xA09502D9EDDDC40EULL,0x236B64293C1BC304ULL,0x270A47ADD102AB5BULL,0x26E517E7AB013E38ULL,0x2149485B7CA8CE2AULL,0x02367CE28AA5791EULL,0x4E83C0341E32096CULL,0xBD3DC2C592CC4EA7ULL,0x977AD8640B65009AULL,0x8C8CD82509786D25ULL,0x0BC599C0AEE05455ULL,0xB547A3916C7B4609ULL,0xC086C1E1E5046899ULL,0x695AC3EA5A74AB49ULL,0x9D00152404B4BA46ULL,0xE9027D9393790622ULL,0x19DD04A0EB3A0109ULL,0x692D55DA05A5D3A8ULL,0xC783816943173CB5ULL,0xD31B737D7AC1B7B2ULL,0x8722D5ADABAD81C1ULL,0xD9671398BB176A09ULL,0x791037BDADC086B1ULL,0x650A4004E0B81BCCULL,0x0E449A072B97C1A8ULL,0x123797AB11CDE6CCULL,0x230EDB7ED33A1A9DULL,0x8A72D571AB526C88ULL,0x490730B1809D8A6CULL,0xC9B07792CC35D224ULL,0x78E582336C33C04DULL,0x962558AAC723B172ULL},
		{0x086A865EC7912B2EULL,0x485BCA3CC69139A5ULL,0xDEB88C2B69891B32ULL,0x40EE87D69A3C5008ULL,0xA9A810CA29102C6AULL,0xC236E070AB7CCC2BULL,0x624165AC53D2D22EULL,0x4B2103050972B11DULL,0xD4941A8C1BDB07E1ULL,0x2C98451C52AC3EC6ULL,0xE1C8124EA3B0369BULL,0x6AB307EA53592BADULL,0xD2768E177C124C86ULL,0xADA2B0D5B55A48E0ULL,0x25932D35ACCD7B18ULL,0x384DA5B904AB776DULL,0x30EB6134051A284DULL,0x1A173BBE0513B552ULL,0xA5B3CDD2EB39E809ULL,0x89E9A505226153E1ULL,0x87CDAD3B4D54A21EULL,0xC8659108B7B5E492ULL,0xA3E215A11DE254D5ULL,0x738120305357E526ULL,0x039D4EC78BB28855ULL,0x29C3294D9B74DAACULL,0x97A7582DCAE878B5ULL,0xB17406A015C3492BULL,0x88485D219176DB4AULL,0x7365D79E59D0514DULL,0x3ABED544D79B4673ULL,0x3627882A026E4860ULL,0x13D97BD1C75B71B3ULL,0x1E99D3ED6DC0E0C7ULL,0x467321B8B6E3137AULL,0xD911AC3A40718D17ULL,0xD5BEDB1C9A03BE99ULL,0x0A021A9D2B124013ULL,0x00D646E1B9259957ULL,0xB2B10402DC9EC499ULL,0x1332B76D05142B25ULL,0xB60530131D150DC6ULL,0x6353A530DEE82A66ULL,0x733A614AD4639EA7ULL,0xD9E093D496A18AC4ULL,0x74608E698AAE9A88ULL,0x9C4BB955D3817706ULL,0x228CA824180AEDCBULL,0x60396E34708B79A1ULL,0xDA2511761B8664EEULL,0x198C177644A667AEULL,0x4ABDCECB6D3E2856ULL,0xD2955E0300A439B5ULL,0xD96936E4EBCAC225ULL,0xCCDB13429CACD10AULL,0xDB8ACE080943BE9BULL,0xCE7DCA78EA586371ULL,0x6380077A7DE3EC35ULL,0x37BA895E19320A00ULL,0x4D921DDAD5972E4CULL,0xEE7BDDA2D69B345BULL,0xC3B2A35BB3A572A3ULL,0x37338ED12A9DD35AULL,0x7B75D2C211BC381DULL},
		{0x65D1E8ED2A0C1DB3ULL,0xCD7881A117DD50E7ULL,0x9904B3980C67E115ULL,0xDDEB26A066A15E7DULL,0x4AE4D6A4BD915493ULL,0x48AC38731A1D5BA2ULL,0x4820B02CA182E7B2ULL,0x8D038946BB3366E7ULL,0x77E82C98211B2D63ULL,0xEA8488B06A1980E6ULL,0x7304869736693CA7ULL,0x076AC8AC459363BBULL,0x08E68E8503905379ULL,0xADE22881B7081CC7ULL,0x300BDE784B237804ULL,0x892666C98E67EBDCULL,0x3C719B733E1B78BBULL,0xB14B5953DE326B29ULL,0xD1C861A8E17CD767ULL,0xB4A7BC2B0E509862ULL,0x0BC3E4181CBEA358ULL,0x25C31E9100662D11ULL,0x2347574DE883B73BULL,0xE9B90376BC46D5B1ULL,0x5D0E0546110B1418ULL,0x35378EAA8C55B8C8ULL,0x4D1A564E9ABDE67AULL,0x0E7C9165E4EDB87BULL,0x553B418B2575E6D9ULL,0x714827B132EE859EULL,0x4B684A519E8C4C9BULL,0x81DBA512B9659974ULL,0xE93957875C19B378ULL,0x226AD1D1212024BBULL,0x2541874459D2690BULL,0x489244ED725304DDULL,0x7B563ECAE4455B62ULL,0xB782E1251BDDCB07ULL,0xB7B233D6E59D3080ULL,0x241319BBA0EA6C8BULL,0x3402DB252EA27376ULL,0x626CCEEDDE99DD38ULL,0x9BB4984BCAED9059ULL,0x784965754E6533DEULL,0x49AD6A3595C03E97ULL,0x2237A7D704B080DDULL,0x9C666AA422BA5A55ULL,0x1838EB1719675859ULL,0x354328063988642EULL,0xB173B5AEEEC90223ULL,0x862199167534DA96ULL,0x4E75C8C55633E842ULL,0xE120931E20D1307AULL,0x7390D6D1592C840BULL,0xA839DAA7A645391EULL,0x2796B0AE820A547BULL,0xE2846A0343722417ULL,0xC72A397607124D9AULL,0x66D48B66CEB2ACD9ULL,0x414696CE5E374C13ULL,0x6D9EA8C36B947072ULL,0x18B4A8AAA745C572ULL,0x6312ECE67BD35855ULL,0xED535ECC87797866ULL},
		{0x5C7B1A03C27CC705ULL,0xA5163EC9ABB87727ULL,0xA1048CB1EC9D0466ULL,0x62DDE454E9681858ULL,0x690BD83E3E56BD96ULL,0xE18005C64883594AULL,0xCE42C3BD00ACCCADULL,0x77234DE1C601B94BULL,0x8E2257E666A79951ULL,0x1E86DAE30DC259CAULL,0x6340591A84A1792EULL,0xE0A2AEC8274421BEULL,0x76A2A8D929A2E70DULL,0xBBC9630C3C78C4E4ULL,0x865DCAE0064DD303ULL,0x3C3C810420282793ULL,0x003869DD80CD05CAULL,0xB106B6B6887E32AAULL,0x710DAE716B9B0255ULL,0x7A2A0E4147EA701EULL,0xDAB2839270D017B5ULL,0x5BE19E21011C0C25ULL,0xC193833EA01C5073ULL,0xEE4218A9884891A9ULL,0x6DD1C5E9735280E4ULL,0x61CE02CB69EEAA48ULL,0x9B63485A81B3E3B2ULL,0x18D89EC7BC9D6DC4ULL,0xD0AC78C8464DA4D1ULL,0x2317798EB83226BCULL,0xC8267E75C188C64EULL,0x4E48D57DE6E0DB5EULL,0x734366E9E1853E5EULL,0x4A3B6C048BD9192CULL,0xE9123586DE34BB9AULL,0x4AB1A65285BD98C8ULL,0x54D4EA861DCA8455ULL,0x54D4948159D5600EULL,0xBCB3BCB3EC70CD10ULL,0xB9E586129E10599EULL,0x8A7D1EA3EA546A77ULL,0xA16E2CC7A6B53923ULL,0x28C7E6D8A95A9DA5ULL,0x06E5A9E2669E220CULL,0x124C79278D89694BULL,0xE2CB007721873372ULL,0xB08B8D6D2486D50AULL,0x31C049C4B2B1025CULL,0x285B5111E9BD9D08ULL,0xA95AC182A9834468ULL,0x6373DC7E70ED6870ULL,0x6A14A2A5DE2A2DCEULL,0xE51E38065AD24B96ULL,0xB0E4232C1C6E9ED6ULL,0x1B5BDCE65A6C36B8ULL,0x6D9715CCB9DA9EBAULL,0xBA84100E0E69C51CULL,0x2930395852DD2CA2ULL,0x5516425164447851ULL,0x67E9D87024E388CCULL,0x29163A9AE66C778CULL,0xB91400271166B0A3ULL,0xA7B42BA942651DD1ULL,0x4619731B47D261A0ULL},
		{0xDB20E4815DAE28B5ULL,0x0C06458D965BA1C0ULL,0x26080CEC0A0433C1ULL,0x380B52C7508D2016ULL,0x2D353708475ABC56ULL,0x4E226E91A0514A27ULL,0x44B76607138B9B2AULL,0x65B8539C79D41B1DULL,0x15C920D20BBC3AA2ULL,0x984929522D79A8E9ULL,0xADE681DCCA453ABEULL,0xBEDBAC394E070BDBULL,0x685A399CA83B2237ULL,0x8EBCA3DC80A285D7ULL,0xAA2ADA94D54D85CCULL,0x6D2236D28BE8260EULL,0x93D80DB5B7B28C8EULL,0x561A15918E1C5972ULL,0x0A3D3AB8843917BCULL,0xBA1054251D889D56ULL,0xB25326AD182B354DULL,0x7A734062D3746E30ULL,0x3C95210AB781518AULL,0x848D8B98B26C0628ULL,0x2E559B30048899BCULL,0xC76876AA662DDE85ULL,0x198658BAC1DEEC5DULL,0x6BC642307914486DULL,0x0E47E44CE0E87C0CULL,0xE0947385025D7BBCULL,0x1A71BB677529A23BULL,0xE559A1E85864E0CDULL,0xA2C0EDB6945A5423ULL,0x25E8533CCED81747ULL,0xD9BCDA625CD60329ULL,0x9645EDAEC0018DBEULL,0x2B1696C58804CCA3ULL,0x62124BD6CCAE0C0DULL,0xE5290C94D134A99AULL,0x456713387156CEE3ULL,0x8E0BE1DD7A75A71CULL,0x344BBEB9D04E8ACEULL,0x5E5E38C1502477B1ULL,0x0C794E10A1652817ULL,0x5AC54BA0826291D1ULL,0x9BEA55D970BAC7DAULL,0xB3EB85128560D913ULL,0xA63997A31C731DCDULL,0x4A3AB10C789250B5ULL,0xAA6A46E8CCBD41A6ULL,0x5A7EC5E8484729B2ULL,0xBCAC7CE4727E36ACULL,0x44702B5E94609139ULL,0xC00D609C3A338A1EULL,0x9291B72CA31E61D4ULL,0x7D857D867C06AB3AULL,0xE9E41265AB85B9E5ULL,0xDE282DEDE0D26319ULL,0x36D026AD143BA93EULL,0xABA71EA5C1D56BD7ULL,0xC6022A5C335383E2ULL,0x2532C61169514D12ULL,0x57E69B88962D1D7DULL,0x7C8A979D8E499DB4ULL},
		{0x578E8AD739626CDAULL,0x4EA66A3428D8C17AULL,0x741784A0008D3B5AULL,0x7C4EE45D8AC2D9D9ULL,0x366E211C67C28CD3ULL,0xC1D3660473BBC7AAULL,0x630793E68C2BBD32ULL,0xE833902BD32A2893ULL,0x7CDB1283E7E21A90ULL,0x52659C5B80316BB2ULL,0x0E3645E1231CA194ULL,0x63615B9C300C9E75ULL,0x003BBD2E8398266DULL,0x115297551AA630C7ULL,0x91B1D28940C704CDULL,0x4A68AC5D74A8928AULL,0xE62875A11B3E3483ULL,0xC51ED67143E084DDULL,0x7D498115C0AB6E30ULL,0x24E4B76D026691A0ULL,0xADA36664EAAB650AULL,0x2E26B56534ED4BEAULL,0xBAD74288894022B2ULL,0x7AAC425C9CADE953ULL,0x027679C93A78C964ULL,0x3870BDCA6355A3C6ULL,0x848D6930C0547455ULL,0xA6B5455714255D3DULL,0x9DEE1DB5ACCDA806ULL,0x32B217588C1D168EULL,0x256EB6D83897843DULL,0xB813A724898C7237ULL,0x2038C6578D9B99C7ULL,0x8B770E8BED86A0D2ULL,0x6A29E266C5EA42CEULL,0x64DC6A191E186AC3ULL,0x1CC5D9A88908CD9CULL,0x34DCDB945EE9A1E6ULL,0xD6A8AB974DC839C6ULL,0x2570BC28CE6E5205ULL,0xDAC3AD95D73245CBULL,0x74C4E5B3AA0D16C0ULL,0x94EDE82CDA3B6574ULL,0x525D436A2137A1B5ULL,0xAB5906B411E85AECULL,0x1877914494267448ULL,0x9186C539549B958EULL,0x314B8E775C976926ULL,0xB0524B05A43A02A3ULL,0xA7960C28BD8006ACULL,0x8D06739476C376A0ULL,0xAB43AB3D27ABDE0DULL,0x532BC6BB5D5D0DD9ULL,0x2172A15B34E64B60ULL,0xDDC65B207B9B0A11ULL,0xC8582590E322A985ULL,0xDEAA759C70666184ULL,0x4D8973E5B4873225ULL,0x1067E061BD07A162ULL,0x44C43692C52A889CULL,0x5030D8829067C31EULL,0xEB9D4DBA6358DE18ULL,0xB802895DB2EDA01BULL,0x678DD658932A839EULL},
		{0x89CDB6A0CD8C2E40ULL,0x299A95CE377BC0DAULL,0x51277097ABB94466ULL,0x9B09B5C0427575EAULL,0x29DB8999CA4226DAULL,0xAC4D9E6CA881901AULL,0xCCBAC23B7D3A6CCAULL,0xEA9288C15653B633ULL,0x38BD93EA8A3DA552ULL,0xC5D87A92CC4E2588ULL,0xAB1743134E69DC4CULL,0x630AC76A6A3550A4ULL,0x03617B2B8C336B4EULL,0xC9A9B54290D8B72DULL,0x35931EE1120EACA4ULL,0xE836725EA05BDD12ULL,0x9326B1D036A489D3ULL,0x6C4260AE950CB054ULL,0xCD150A9A6CE8A90CULL,0xBAC94BA05E3913BDULL,0xB0318100CEBCB991ULL,0x62323E9887EA8BEDULL,0x77B6432698E36310ULL,0xC6123B7172AE0382ULL,0x94B69A5DCD66AD17ULL,0x806E40C5AD4DD452ULL,0x78DC45BD10D7735AULL,0x725902B9B9464105ULL,0x45D9492B4E1D634AULL,0x506E5D2021205CD4ULL,0x5B89D7CDACBD61C1ULL,0xE34248B698517A6AULL,0x6E47A35551A29B6BULL,0x35AC85E015074DE7ULL,0x2B0A68CEA810C0E7ULL,0xCE98B5D5C520233AULL,0x130B4D11B10679AAULL,0x9E989090B2D107D4ULL,0xB1328997E49B0742ULL,0xC3E153C069A910C3ULL,0x162BE361DD96666EULL,0x18E177C4A699CB50ULL,0x0B83E9A0C51E6CD1ULL,0x48C6C0AC4A604AE0ULL,0x7A90772A40726924ULL,0xBD3488B0E76B7B22ULL,0x7DA61980DD6E7084ULL,0xB2B6116D2A8B50BDULL,0x20E48D37704CC3D9ULL,0x838903417988CA70ULL,0x8936087C15B8AC8DULL,0xE8B9209ED073A632ULL,0xD05000AB3A9DC8BCULL,0xD0D66E7B41CA81EAULL,0x86A2403C1D0140DDULL,0xC730AEDCA4DDC1B7ULL,0x8A59B178880409EEULL,0xB619546E89185290ULL,0xBE8A858B7291515BULL,0x0BBDBC9D7C20602BULL,0xD84EB57843D7D3C7ULL,0x17786CC25C1E0904ULL,0x83265C8603B0218AULL,0xB2A07DC5A148E68CULL}
	};

	uint64_t Zobrist::SideToMove[3] = {
		0,
		0,
		0xA996BE54244B96E0ULL
	};

	uint64_t Zobrist::CastlingRights[16] = {0x96854EC626BCD871ULL,0x83A9B67127F402DCULL,0xA905D1FFF23156DBULL,0x9EE80BB2D2E9F599ULL,0xA0D89FE2B89464BDULL,0xE04AE52E21ACCFB1ULL,0x5D28EDD4D26E24B7ULL,0x82CA1C45FF83E45FULL,0x011B95339ABA42EAULL,0xF919EC8C0275BE99ULL,0x32E632E3197032FBULL,0x9BF6F7C09BB7D4F6ULL,0xCF5364AC0C646BAAULL,0xB63F08059A2E9111ULL,0x42C3C3B8FC5F9F42ULL,0xF8AE08EF2C968383ULL};

	uint64_t Zobrist::EnPassant[65] = {
		0x8A23763558B53859ULL,
		0xD4CF6FB55D9C0AF3ULL,
		0xC29D8A959D213624ULL,
		0xFAD7C5A9E9F6BAF9ULL,
		0xF50E76B9A9FF5AA3ULL,
		0x01BDB71CC442B28EULL,
		0xCF4B19D349397F0EULL,
		0x6D47B0EA82E20B2AULL,
		0xAAFB855759955305ULL,
		0x64F9EEA818B2B947ULL,
		0x33EC469E9B8E79BEULL,
		0x11A72091CD1C3F96ULL,
		0xD94BC344D8B4E8D6ULL,
		0xBD9012E13AFAD3EFULL,
		0xA0850D2A3E2D44A4ULL,
		0x170F1F991821DE0DULL,
		0xB89C6D244EF34C29ULL,
		0xF9B874E42416B48DULL,
		0x5EC48674213D11E2ULL,
		0xF602F4B30A7DA3D4ULL,
		0x00EBD10F54C8C257ULL,
		0xBD293CCF103025BCULL,
		0x49E4A9574D397671ULL,
		0xA76A91897C5F9E60ULL,
		0xA576C4CB52C1F3D9ULL,
		0x187BE7FEBBC49122ULL,
		0x6A0BF2F3A36FC223ULL,
		0x0CE8B20ED66EB91FULL,
		0x44B5C87CA6001DFAULL,
		0xAF37409693A92F52ULL,
		0x6E7B89F6F578913CULL,
		0xA033F9A00F484853ULL,
		0xCACF67DB8F6E126DULL,
		0xA627EEEFDC1769D2ULL,
		0x5C5B120123798742ULL,
		0x830BC33722B2EDD2ULL,
		0x9E86A3D6806FAB48ULL,
		0x04E420EF86033788ULL,
		0x82284C8FA6C513ABULL,
		0xBE7C9F1FBD12C9FEULL,
		0x46DC08B92B276887ULL,
		0x416CB18EE6C89B2FULL,
		0x56B9D46E9E1CCDE5ULL,
		0xC4A26A95D6341EF1ULL,
		0xE6836486E788A43DULL,
		0xCED525B639609D84ULL,
		0xAB4C30AEBACDEFD0ULL,
		0xD1F3C8FE1C0DF31DULL,
		0x29A040A78E347E99ULL,
		0x3C2714D8677D5CDEULL,
		0x7602D79E4C96DFDDULL,
		0x2FDC01FB4FB50565ULL,
		0x27D770B989ECA4D6ULL,
		0x3E1A80AF74B068C0ULL,
		0xFA3B74AB9CC5F2DBULL,
		0xA9EC907C82E6C1ADULL,
		0x50AE1FD17E3AC316ULL,
		0xC393B1B9C631CB04ULL,
		0x941F434A9D203CCFULL,
		0x24DFC7BC64B0A58EULL,
		0x39B530166660A4EDULL,
		0x23ECB7BBDBE72CA9ULL,
		0x3B44C1EEE947ACEEULL,
		0x9E0F51A33223B7F3ULL,
		0x3D7387CC5D3D5E72ULL
	};
	
#endif