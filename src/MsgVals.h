// MsgVals.h
// Copyright (c) Blachford Technology 1999
// 28/4/99

// SAMPLEwindow Messages - Directed to be_app
const uint32 SAM_ZEROALL	= 'sZAL';
const uint32 SAM_OPEN		= 'sOPN';
const uint32 SAM_SAVE		= 'sSAV';
const uint32 SAM_SAVEAS		= 'sSVA';
const uint32 SAM_QUIT		= 'sQUT';
const uint32 SAM_TEMP1		= 'sTM1';
const uint32 SAM_TEMP2		= 'sTM2';
const uint32 SAM_TEMP3		= 'sTM3';
const uint32 SAM_TEMP4		= 'sTM4';
const uint32 SAM_TEMP5		= 'sTM5';
const uint32 SAM_GOMENU		= 'sGMN';
const uint32 SAM_CHNGRNG	= 'sCRG';
const uint32 SAM_RNGVALS	= 'sRVL';


// APP Messages
const uint32    	APP_CURRENT 	= 		'pCUR';
const uint32    	APP_DONE		= 		'pDNE';
const uint32    	APP_FXGO		= 		'pFGO'; // GO + New current effect
const uint32    	APP_FXGONONEW	= 		'pFGN'; // GO only
const uint32    	APP_GETSETTINGS	= 		'pGET';
const uint32    	APP_SETTINGS	= 		'pSET';
const uint32    	APP_MONO		= 		'pMNO';
const uint32    	APP_STEREO		= 		'pSTR';
const uint32    	APP_DRAWBAR		= 		'pDRW';
const uint32    	APP_MEMSETUP	= 		'pMST';
const uint32    	APP_LOAD		=		'pLOD';
const uint32    	APP_SAVE		=		'pSAV';
const uint32    	APP_SAVEAS		=		'pSVS';
const uint32    	APP_DRAWATTRACT	=		'pDRA';
const uint32    	APP_LOADDATA	=		'pLDT';


// Messages from Effector
const uint32    	FXR_DONE	= 			'fDNE';
const uint32    	FXR_DRAWBAR		= 		'fDRW';


// Messages from Attractor
const uint32    	ATT_CLOSED	= 			'tCLO';
const uint32    	ATT_LINES	=			'tLIN';
const uint32    	ATT_INVERT	=			'tINV';


// Messages from Load/Save window
const uint32    	LOAD_CLOSED		= 			'lCLO';
const uint32    	LOAD_RADIOA1	=			'lRA1';
const uint32    	LOAD_RADIOA2	=			'lRA2';
const uint32    	LOAD_RADIOA3	=			'lRA3';
const uint32    	LOAD_RADIOA4	=			'lRA4';
const uint32    	LOAD_RADIOA5	=			'lRA5';
const uint32    	LOAD_RADIOB1	=			'lRB1';
const uint32    	LOAD_RADIOB2	=			'lRB2';
const uint32    	LOAD_RADIOB3	=			'lRB3';
const uint32    	LOAD_RADIOB4	=			'lRB4';
const uint32    	LOAD_RADIOB5	=			'lRB5';
const uint32    	LOAD_RNG		=			'lRNG';
const uint32    	LOAD_ALL		=			'lALL';
const uint32    	LOAD_PICK		=			'lPIK';
const uint32    	LOAD_GO			=			'lGOL';
const uint32    	LOAD_CANCEL		=			'lCAN';
const uint32    	LOAD_REQUESTDATA=			'lREQ';
const uint32    	LOAD_LOAD		=			'lLOD';	// From load file panel
const uint32    	LOAD_SAVE		=			'lSAV';	// From Save file panel


// ALLFX Messages
const uint32    	ALLFX_FXADD1A = 			'aA1A';
const uint32    	ALLFX_FXADD1B = 			'aA1B';
const uint32    	ALLFX_FXSET = 				'aSET';
const uint32    	ALLFX_FXADD2A = 			'aA2A';
const uint32    	ALLFX_FXADD2B = 			'aA2B';
const uint32    	ALLFX_FXPICK_SELECTION = 	'aPSL';
const uint32    	ALLFX_FXPICK_INVOCATION = 	'aPIN';
const uint32    	ALLFX_FXGO = 				'aFGO';
const uint32    	ALLFX_FXLEV1 = 				'aLV1';
const uint32    	ALLFX_FXLEV2 = 				'aLV2';
const uint32    	ALLFX_FXLEV3 = 				'aLV3';
const uint32    	ALLFX_FXLEV4 = 				'aLV4';
const uint32    	ALLFX_FXLEV = 				'aFLV';
const uint32    	ALLFX_FXTYPE_STANDARD_FX = 	'aSFX';
const uint32    	ALLFX_FXTYPE_COMPLEX_FX = 	'aCFX';
const uint32    	ALLFX_FXTYPE_MANIPS_1 = 	'aMN1';
const uint32    	ALLFX_FXTYPE_MANIPS_2 = 	'aMN2';
const uint32    	ALLFX_FXTYPE_DUAL_MANIPS = 	'aDMN';
const uint32    	ALLFX_FXTYPE_STEREO_FX = 	'aSTF';
const uint32    	ALLFX_FXDEFAULT = 			'aDEF';
// ALLFX other messages
const uint32    	ALLFX_FXCURRENT = 			'aCUR';
const uint32    	ALLFX_SETTINGS = 			'aSET';


// EDIT Messages
const uint32    EDIT_EDITCUT = 			'eCUT';
const uint32    EDIT_EDITPASTEINTO =	'ePIN';
const uint32    EDIT_EDITSETZONE = 		'eSEZ';
const uint32    EDIT_EDITZONEOVER =		'eZOV';
const uint32    EDIT_EDITZONEINTO =		'eZIN';
const uint32    EDIT_EDITPLAYVIEW =		'ePVW';
const uint32    EDIT_EDITPLAYRANGE =	'ePRG';
const uint32    EDIT_EDITPLAYALL =		'ePAL';
const uint32    EDIT_EDITPLAYLOOP =		'ePLP';
const uint32    EDIT_EDITSHOWRNG =		'eSRG';
const uint32    EDIT_EDITSHOWALL =		'eSAL';
const uint32    EDIT_EDITMOVEZONE =		'eMVZ';
const uint32    EDIT_EDITLR =			'eCLR';
const uint32    EDIT_EDITRANGEALL =		'eRGA';
const uint32    EDIT_EDITZERO =			'eEZO';
const uint32    EDIT_EDITRESCALE =		'eRSC';
const uint32    EDIT_EDITSCALE =		'eESC';
const uint32    EDIT_EDITCOPY =			'eECP';
const uint32    EDIT_EDITGO =			'eEGO';
const uint32    EDIT_EDITPASTEOVER =	'ePOV';
const uint32    EDIT_EDITUNDO =			'eUND';
const uint32    EDIT_EDITZOOMIN =		'eZMI';
const uint32    EDIT_EDITZOOMOUT =		'eZMO';
const uint32    EDIT_EDITSTART =		'eSRT';
const uint32    EDIT_EDITFASTBACK =		'eFBA';
const uint32    EDIT_EDITBACK =			'eBAC';
const uint32    EDIT_EDITFORWARD =		'eFWD';
const uint32    EDIT_EDITFASTFORWARD =	'eFFW';
const uint32    EDIT_EDITEND =			'eEND';
const uint32    EDIT_EDITRL =			'eCRL';
const uint32    EDIT_EDITREDRAW =		'eRDR';
const uint32    EDIT_EDITSCALEVAL =		'eSVA';
const uint32    EDIT_EDITMAG =			'eMAG';
const uint32    EDIT_EDITRATE =			'eRAT';
const uint32    EDIT_EDITDRAW =			'eDRW';
const uint32    EDIT_EDITLEFT =			'eLFT';
const uint32    EDIT_EDITRIGHT =		'eRHT';
const uint32    EDIT_EDITSTEREO =		'eSTR';
const uint32    EDIT_EDITMONO =			'eMON';
const uint32    EDIT_EDITLOOP =			'eLOP';


// MEMORY Messages
const uint32    MEM_LEV 	=			'mLEV';
const uint32    MEM_OK 		=			'mMOK';
const uint32    MEM_SET		=			'mSET';
const uint32    MEM_SMALL 	=			'mSMA';
const uint32    MEM_MEDIUM	=			'mMED';
const uint32    MEM_LARGE	=			'mLAR';
const uint32    MEM_FETCH	=			'mFET';
const uint32    MEM_NOT		=			'mNOT';


// Individual Window (EQs etc) Messages
const uint32    IW_NEWVAL 	=			'iNEW';	// control value changed
const uint32    IAP_NEWVAL =			'iPNW';	// reply from APP
const uint32    IAP_REQSET 	=			'iREQ';	// request for settings
const uint32    IAL_SET 	=			'iLST';	// settings from ALLFX
const uint32    IAP_SET 	=			'iPST';	// settings from APP
const uint32    IAPGO_REQSET =			'iGRS';	// go pressed, request settings
const uint32    IALGO_SET 	=			'iGST';	// go settings from ALLFX
const uint32    IAPGO_SET 	=			'iGST';	// go settings from APP
const uint32    EQ20_MIN 	=			'e2MN';
const uint32    EQ20_MID 	=			'e2MD';
const uint32    EQ20_MAX 	=			'e2MX';
const uint32    IW_CLOSED 	=			'iCLO';	// window closed


