#define ZONE_BASESERVERPACKET_ID 0x1
#define ZONE_CLIENTFINISHEDLOADING_ID 0x2
#define ZONE_SENDSELFTOCLIENT_ID 0x3
#define ZONE_CLIENTISREADY_ID 0x4
#define ZONE_ZONEDONESENDINGINITIALDATA_ID 0x5
#define ZONE_CHATBASE_ID 0x60000
#define ZONE_CHAT_CHAT_ID 0x60001
#define ZONE_CHAT_CHATTEXT_ID 0x60005
#define ZONE_CLIENTLOGOUT_ID 0x7
#define ZONE_TARGETCLIENTNOTONLINE_ID 0x8
#define ZONE_COMMANDITEMDEFINITIONREQUEST_ID 0x900000045
#define ZONE_COMMANDITEMDEFINITIONREPLY_ID 0x900000046
#define ZONE_COMMANDITEMDEFINITIONS_ID 0x900000047
#define ZONE_ADMINBASE_ID 0xa0000
#define ZONE_CLIENTBEGINZONING_ID 0xb
#define ZONE_COMBATBASE_ID 0xc0000
#define ZONE_PROJECTILEDEBUG_ID 0xd
#define ZONE_MAILBASE_ID 0xe0000
#define ZONE_CHARACTERBASE_ID 0xf0000
#define ZONE_CHARACTER_REMOVEPLAYER_ID 0xf0001
#define ZONE_CHARACTER_KNOCKBACK_ID 0xf0002
#define ZONE_CHARACTER_UPDATEHITPOINTS_ID 0xf0003
#define ZONE_CHARACTER_PLAYANIMATION_ID 0xf0004
#define ZONE_CHARACTER_UPDATESCALE_ID 0xf0005
#define ZONE_CHARACTER_UPDATETEMPORARYAPPEARANCE_ID 0xf0006
#define ZONE_CHARACTER_REMOVETEMPORARYAPPEARANCE_ID 0xf0007
#define ZONE_CHARACTER_SETLOOKAT_ID 0xf0008
#define ZONE_CHARACTER_RENAMEPLAYER_ID 0xf0009
#define ZONE_CHARACTER_WEAPONSTANCE_ID 0xf0020
#define ZONE_CHARACTER_CHARACTERSTATEDELTA_ID 0xf003f
#define ZONE_ABILITYBASE_ID 0x100000
#define ZONE_CLIENTUPDATEBASE_ID 0x110000
#define ZONE_CLIENTUPDATE_HITPOINTS_ID 0x110001
#define ZONE_CLIENTUPDATE_ITEMADD_ID 0x110002
#define ZONE_CLIENTUPDATE_ITEMUPDATE_ID 0x110003
#define ZONE_CLIENTUPDATE_ITEMDELETE_ID 0x110004
#define ZONE_CLIENTUPDATE_UPDATESTAT_ID 0x110005
#define ZONE_CLIENTUPDATE_COLLECTIONSTART_ID 0x110006
#define ZONE_CLIENTUPDATE_COLLECTIONREMOVE_ID 0x110007
#define ZONE_CLIENTUPDATE_COLLECTIONADDENTRY_ID 0x110008
#define ZONE_CLIENTUPDATE_COLLECTIONREMOVEENTRY_ID 0x110009
#define ZONE_CLIENTUPDATE_UPDATELOCATION_ID 0x11000a
#define ZONE_CLIENTUPDATE_MANA_ID 0x11000b
#define ZONE_CLIENTUPDATE_UPDATEPROFILEEXPERIENCE_ID 0x11000c
#define ZONE_CLIENTUPDATE_ADDPROFILEABILITYSETAPL_ID 0x11000d
#define ZONE_CLIENTUPDATE_ADDEFFECTTAG_ID 0x11000e
#define ZONE_CLIENTUPDATE_REMOVEEFFECTTAG_ID 0x11000f
#define ZONE_CLIENTUPDATE_UPDATEPROFILERANK_ID 0x110010
#define ZONE_CLIENTUPDATE_COINCOUNT_ID 0x110011
#define ZONE_CLIENTUPDATE_DELETEPROFILE_ID 0x110012
#define ZONE_CLIENTUPDATE_ACTIVATEPROFILE_ID 0x110013
#define ZONE_CLIENTUPDATE_ADDABILITY_ID 0x110014
#define ZONE_CLIENTUPDATE_NOTIFYPLAYER_ID 0x110015
#define ZONE_CLIENTUPDATE_UPDATEPROFILEABILITYSETAPL_ID 0x110016
#define ZONE_CLIENTUPDATE_REMOVEACTIONBARS_ID 0x110017
#define ZONE_CLIENTUPDATE_UPDATEACTIONBARSLOT_ID 0x110018
#define ZONE_CLIENTUPDATE_DONESENDINGPRELOADCHARACTERS_ID 0x110019
#define ZONE_CLIENTUPDATE_SETGRANDFATHEREDSTATUS_ID 0x11001a
#define ZONE_CLIENTUPDATE_UPDATEACTIONBARSLOTUSED_ID 0x11001b
#define ZONE_CLIENTUPDATE_PHASECHANGE_ID 0x11001c
#define ZONE_CLIENTUPDATE_UPDATEKINGDOMEXPERIENCE_ID 0x11001d
#define ZONE_CLIENTUPDATE_UPDATEPACKETDAMAGEINFO_ID 0x11001e
#define ZONE_CLIENTUPDATE_RESPAWNLOCATIONS_ID 0x11001f
#define ZONE_CLIENTUPDATE_MODIFYMOVEMENTSPEED_ID 0x110020
#define ZONE_CLIENTUPDATE_MODIFYTURNRATE_ID 0x110021
#define ZONE_CLIENTUPDATE_MODIFYSTRAFESPEED_ID 0x110022
#define ZONE_CLIENTUPDATE_UPDATEMANAGEDLOCATION_ID 0x110023
#define ZONE_CLIENTUPDATE_MANAGEDMOVEMENTVERSION_ID 0x110024
#define ZONE_CLIENTUPDATE_UPDATEWEAPONADDCLIPS_ID 0x110025
#define ZONE_CLIENTUPDATE_SPOTPROBATION_ID 0x110026
#define ZONE_CLIENTUPDATE_DAILYRIBBONCOUNT_ID 0x110027
#define ZONE_CLIENTUPDATE_DESPAWNNPCUPDATE_ID 0x110029
#define ZONE_CLIENTUPDATE_LOYALTYPOINTS_ID 0x11002a
#define ZONE_CLIENTUPDATE_RESETMISSIONRESPAWNTIMER_ID 0x11002b
#define ZONE_CLIENTUPDATE_FREEZE_ID 0x11002c
#define ZONE_CLIENTUPDATE_INGAMEPURCHASERESULT_ID 0x11002d
#define ZONE_CLIENTUPDATE_QUIZCOMPLETE_ID 0x11002e
#define ZONE_CLIENTUPDATE_STARTTIMER_ID 0x11002f
#define ZONE_CLIENTUPDATE_COMPLETELOGOUTPROCESS_ID 0x110030
#define ZONE_CLIENTUPDATE_PROXIMATEITEMS_ID 0x110031
#define ZONE_CLIENTUPDATE_TEXTALERT_ID 0x110032
#define ZONE_CLIENTUPDATE_CLEARENTITLEMENTVALUES_ID 0x110033
#define ZONE_CLIENTUPDATE_ADDENTITLEMENTVALUE_ID 0x110034
#define ZONE_CLIENTUPDATE_NETWORKPROXIMITYUPDATESCOMPLETE_ID 0x110035
#define ZONE_CLIENTUPDATE_FILEVALIDATIONREQUEST_ID 0x110036
#define ZONE_CLIENTUPDATE_FILEVALIDATIONRESPONSE_ID 0x110037
#define ZONE_CLIENTUPDATE_DEATHMETRICS_ID 0x110038
#define ZONE_CLIENTUPDATE_SETCURRENTADVENTURE_ID 0x11003c
#define ZONE_CLIENTUPDATE_CHARACTERSLOT_ID 0x11003d
#define ZONE_CLIENTUPDATE_MANAGEDOBJECTREQUESTCONTROL_ID 0x110039
#define ZONE_CLIENTUPDATE_MANAGEDOBJECTRESPONSECONTROL_ID 0x11003a
#define ZONE_CLIENTUPDATE_MANAGEDOBJECTRELEASECONTROL_ID 0x11003b
#define ZONE_CLIENTUPDATE_CUSTOMIZATIONDATA_ID 0x11003e
#define ZONE_CLIENTUPDATE_UPDATECURRENCY_ID 0x11003f
#define ZONE_CLIENTUPDATE_ADDNOTIFICATIONS_ID 0x110040
#define ZONE_CLIENTUPDATE_REMOVENOTIFICATIONS_ID 0x110041
#define ZONE_CLIENTUPDATE_NPCRELEVANCE_ID 0x110042
#define ZONE_CLIENTUPDATE_INITIATENAMECHANGE_ID 0x110043
#define ZONE_CLIENTUPDATE_NAMECHANGERESULT_ID 0x110044
#define ZONE_CLIENTUPDATE_MONITORTIMEDRIFT_ID 0x110045
#define ZONE_CLIENTUPDATE_NOTIFYSERVEROFSTALLEDEVENT_ID 0x110046
#define ZONE_CLIENTUPDATE_UPDATESIGHTS_ID 0x110047
#define ZONE_CLIENTUPDATE_UPDATEREWARDANDGRINDERSTATE_ID 0x110049
#define ZONE_CLIENTUPDATE_UPDATEACTIVITYMETRICS_ID 0x11004b
#define ZONE_CLIENTUPDATE_STOPWITHERROR_ID 0x11004c
#define ZONE_CLIENTUPDATE_SETWORLDWIPETIMER_ID 0x11004d
#define ZONE_CLIENTUPDATE_UPDATELOCKOUTTIMES_ID 0x11004e
#define ZONE_CLIENTUPDATE_ZONESTATUS_ID 0x11004f
#define ZONE_CLIENTUPDATE_SETDATACENTER_ID 0x110050
#define ZONE_CLIENTUPDATE_UPDATEBATTLEYEREGISTRATION_ID 0x110051
#define ZONE_GROUPSBASE_ID 0x13
#define ZONE_ENCOUNTERBASE_ID 0x14
#define ZONE_INVENTORYBASE_ID 0x15
#define ZONE_SENDZONEDETAILS_ID 0x16
#define ZONE_REFERENCEDATAWEAPONDEFINITIONS_ID 0x170004
#define ZONE_OBJECTIVEBASE_ID 0x18
#define ZONE_DEBUGBASE_ID 0x19
#define ZONE_UIBASE_ID 0x1a
#define ZONE_QUESTBASE_ID 0x1b
#define ZONE_REWARDBASE_ID 0x1c
#define ZONE_GAMETIMESYNC_ID 0x1d
#define ZONE_PETBASE_ID 0x1e
#define ZONE_POINTOFINTERESTDEFINITIONREQUEST_ID 0x1f
#define ZONE_POINTOFINTERESTDEFINITIONREPLY_ID 0x20
#define ZONE_WORLDTELEPORTREQUEST_ID 0x21
#define ZONE_TRADEBASE_ID 0x22
#define ZONE_ESCROWGIVEPACKAGE_ID 0x23
#define ZONE_ESCROWGOTPACKAGE_ID 0x24
#define ZONE_UPDATEENCOUNTERDATACOMMON_ID 0x25
#define ZONE_RECIPEBASE_ID 0x26
#define ZONE_INGAMEPURCHASEBASE_ID 0x27
#define ZONE_QUICKCHATBASE_ID 0x28
#define ZONE_REPORTBASE_ID 0x29
#define ZONE_LIVEGAMERBASE_ID 0x2a
#define ZONE_ACQUAINTANCEBASE_ID 0x2b
#define ZONE_CLIENTSERVERSHUTTINGDOWN_ID 0x2c
#define ZONE_FRIENDBASE_ID 0x2d
#define ZONE_BROADCASTBASE_ID 0x2e
#define ZONE_CLIENTKICKEDFROMSERVER_ID 0x2f
#define ZONE_UPDATECLIENTSESSIONDATA_ID 0x30
#define ZONE_BUGSUBMISSIONBASE_ID 0x31
#define ZONE_WORLDDISPLAYINFO_ID 0x32
#define ZONE_MOTD_ID 0x33
#define ZONE_SETLOCALE_ID 0x34
#define ZONE_SETCLIENTAREA_ID 0x35
#define ZONE_ZONETELEPORTREQUEST_ID 0x36
#define ZONE_TRADINGCARDBASE_ID 0x37
#define ZONE_WORLDSHUTDOWNNOTICE_ID 0x38
#define ZONE_LOADWELCOMESCREEN_ID 0x39
#define ZONE_SHIPCOMBATBASE_ID 0x3a
#define ZONE_KEEPALIVE_ID 0x3c
#define ZONE_CLIENTEXITLAUNCHURI_ID 0x3d
#define ZONE_CLIENTPATH_ID 0x3e
#define ZONE_CLIENTPENDINGKICKFROMSERVER_ID 0x3f
#define ZONE_CLIENTMEMBERSHIPACTIVATION_ID 0x40
#define ZONE_LOBBYBASE_ID 0x41
#define ZONE_LOBBYGAMEDEFINITIONBASE_ID 0x42
#define ZONE_SHOWSYSTEMMESSAGE_ID 0x43
#define ZONE_POICHANGEMESSAGE_ID 0x44
#define ZONE_CLIENTMETRICS_ID 0x45
#define ZONE_FIRSTTIMEEVENTBASE_ID 0x46
#define ZONE_CLAIMBASE_ID 0x47
#define ZONE_CLIENTLOG_ID 0x48
#define ZONE_IGNOREBASE_ID 0x49
#define ZONE_SNOOPEDPLAYERBASE_ID 0x4a
#define ZONE_PROMOTIONALBASE_ID 0x4b
#define ZONE_ADDCLIENTPORTRAITCRC_ID 0x4c
#define ZONE_OBJECTIVETARGETBASE_ID 0x4d0000
#define ZONE_COMMERCESESSIONREQUEST_ID 0x4e
#define ZONE_COMMERCESESSIONRESPONSE_ID 0x4f
#define ZONE_TRACKEDEVENT_ID 0x50
#define ZONE_CLIENTLOGINFAILED_ID 0x51
#define ZONE_LOGINTOUCHAT_ID 0x52
#define ZONE_ZONESAFETELEPORTREQUEST_ID 0x53
#define ZONE_REMOTEINTERACTIONREQUEST_ID 0x54
#define ZONE_UPDATECAMERA_ID 0x57
#define ZONE_GUILDBASE_ID 0x59
#define ZONE_ADMINGUILDBASE_ID 0x5a0000
#define ZONE_BATTLEMAGESBASE_ID 0x5b0000
#define ZONE_WORLDTOWORLDBASE_ID 0x5c0000
#define ZONE_PERFORMACTION_ID 0x5d
#define ZONE_ENCOUNTERMATCHMAKINGBASE_ID 0x5e0000
#define ZONE_CLIENTLUAMETRICS_ID 0x5f0000
#define ZONE_REPEATINGACTIVITYBASE_ID 0x600000
#define ZONE_CLIENTGAMESETTINGS_ID 0x61
#define ZONE_CLIENTTRIALPROFILEUPSELL_ID 0x62
#define ZONE_ACTIVITYMANAGERBASE_ID 0x63
#define ZONE_REQUESTSENDITEMDEFINITIONSTOCLIENT_ID 0x64
#define ZONE_INSPECTBASE_ID 0x650000
#define ZONE_ACHIEVEMENTBASE_ID 0x660000
#define ZONE_PLAYERTITLEBASE_ID 0x670000
#define ZONE_MATCHHISTORYBASE_ID 0x680000
#define ZONE_UPDATEUSERAGE_ID 0x69
#define ZONE_LOOTBASE_ID 0x6a0000
#define ZONE_ACTIONBARMANAGERBASE_ID 0x6b0000
#define ZONE_CLIENTTRIALPROFILEUPSELLREQUEST_ID 0x6c
#define ZONE_PLAYERUPDATEJUMP_ID 0x6d
#define ZONE_COINSTOREBASE_ID 0x6e0000
#define ZONE_INITIALIZATIONPARAMETERS_ID 0x6f
#define ZONE_ACTIVITYBASE_ID 0x700000
#define ZONE_MOUNTBASE_ID 0x71
#define ZONE_MOUNT_MOUNTREQUEST_ID 0x710001
#define ZONE_MOUNT_MOUNTRESPONSE_ID 0x710002
#define ZONE_MOUNT_DISMOUNTREQUEST_ID 0x710003
#define ZONE_MOUNT_DISMOUNTRESPONSE_ID 0x710004
#define ZONE_MOUNT_MOUNTLIST_ID 0x710005
#define ZONE_MOUNT_MOUNTSPAWN_ID 0x710006
#define ZONE_MOUNT_MOUNTDESPAWN_ID 0x710007
#define ZONE_MOUNT_MOUNTSPAWNBYITEMDEFINITIONID_ID 0x710008
#define ZONE_MOUNT_MOUNTOFFERUPSELL_ID 0x710009
#define ZONE_MOUNT_SEATCHANGEREQUEST_ID 0x71000a
#define ZONE_MOUNT_SEATCHANGERESPONSE_ID 0x71000b
#define ZONE_MOUNT_SEATSWAPREQUEST_ID 0x71000c
#define ZONE_MOUNT_SEATSWAPRESPONSE_ID 0x71000d
#define ZONE_MOUNT_MOUNTPACKETTYPECOUNT_ID 0x71000f
#define ZONE_MOUNT_FLIPMOUNT_ID 0x71000e
#define ZONE_CLIENTINITIALIZATIONDETAILS_ID 0x72
#define ZONE_CLIENTAREATIMER_ID 0x73
#define ZONE_LOYALTYREWARDBASE_ID 0x740000
#define ZONE_RATINGBASE_ID 0x750000
#define ZONE_CLIENTACTIVITYLAUNCHBASE_ID 0x760000
#define ZONE_SERVERACTIVITYLAUNCHBASE_ID 0x770000
#define ZONE_CLIENTFLASHTIMER_ID 0x78
#define ZONE_PLAYERUPDATEPOSITION_ID 0x79
#define ZONE_INVITEANDSTARTMINIGAME_ID 0x7a
#define ZONE_QUIZBASE_ID 0x7b
#define ZONE_PLAYERUPDATEPOSITIONONPLATFORM_ID 0x7c
#define ZONE_CLIENTMEMBERSHIPVIPINFO_ID 0x7d
#define ZONE_TARGETBASE_ID 0x7e0000
#define ZONE_GUIDESTONEBASE_ID 0x80
#define ZONE_RAIDSBASE_ID 0x810000
#define ZONE_VOICEBASE_ID 0x820000
#define ZONE_WEAPONBASE_ID 0x830000
#define ZONE_MATCHSCHEDULEBASE_ID 0x84
#define ZONE_FACILITYBASE_ID 0x850000
#define ZONE_FACILITY_REFERENCEDATA_ID 0x850001
#define ZONE_FACILITY_FACILITYDATA_ID 0x850002
#define ZONE_FACILITY_CURRENTFACILITYUPDATE_ID 0x850003
#define ZONE_FACILITY_SPAWNDATAREQUEST_ID 0x850004
#define ZONE_FACILITY_FACILITYSPAWNDATA_ID 0x850005
#define ZONE_FACILITY_FACILITYUPDATE_ID 0x850006
#define ZONE_FACILITY_FACILITYSPAWNSTATUS_ID 0x850007
#define ZONE_FACILITY_FACILITYSPAWNSTATUSTRACKED_ID 0x850008
#define ZONE_FACILITY_NOTIFICATIONFACILITYCAPTURED_ID 0x850009
#define ZONE_FACILITY_NOTIFICATIONFACILITYSIGNIFICANTCAPTUREPROGRESS_ID 0x85000a
#define ZONE_FACILITY_NOTIFICATIONFACILITYCLOSETOCAPTURE_ID 0x85000b
#define ZONE_FACILITY_NOTIFICATIONFACILITYSPAWNBEGINCAPTURE_ID 0x85000c
#define ZONE_FACILITY_NOTIFICATIONFACILITYSPAWNFINISHCAPTURE_ID 0x85000d
#define ZONE_FACILITY_NOTIFICATIONLEAVINGFACILITYDURINGCONTENTION_ID 0x85000e
#define ZONE_FACILITY_PROXIMITYSPAWNCAPTUREUPDATE_ID 0x85000f
#define ZONE_FACILITY_CLEARPROXIMITYSPAWN_ID 0x850010
#define ZONE_FACILITY_GRIDSTABILIZETIMERUPDATED_ID 0x850011
#define ZONE_FACILITY_SPAWNCOLLISIONCHANGED_ID 0x850012
#define ZONE_FACILITY_NOTIFICATIONFACILITYSECONDARYOBJECTIVEEVENTPACKET_ID 0x850013
#define ZONE_FACILITY_PENETRATESHIELDEFFECT_ID 0x850014
#define ZONE_FACILITY_SPAWNUPDATEGUID_ID 0x850015
#define ZONE_FACILITY_FACILITYUPDATEREQUEST_ID 0x850016
#define ZONE_FACILITY_EMPIRESCOREVALUEUPDATE_ID 0x850017
#define ZONE_SKILLSBASE_ID 0x860000
#define ZONE_LOADOUTSBASE_ID 0x870000
#define ZONE_EXPERIENCEBASE_ID 0x880000
#define ZONE_VEHICLEBASE_ID 0x890000
#define ZONE_VEHICLE_OWNER_ID 0x890001
#define ZONE_VEHICLE_OCCUPY_ID 0x890002
#define ZONE_VEHICLE_STATEDATA_ID 0x890003
#define ZONE_VEHICLE_STATEDAMAGE_ID 0x890004
#define ZONE_VEHICLE_PLAYERMANAGER_ID 0x890005
#define ZONE_VEHICLE_SPAWN_ID 0x890006
#define ZONE_VEHICLE_TINT_ID 0x890007
#define ZONE_VEHICLE_LOADVEHICLETERMINALDEFINITIONMANAGER_ID 0x890008
#define ZONE_VEHICLE_ACTIVEWEAPON_ID 0x890009
#define ZONE_VEHICLE_STATS_ID 0x89000a
#define ZONE_VEHICLE_DAMAGEINFO_ID 0x89000b
#define ZONE_VEHICLE_STATUPDATE_ID 0x89000c
#define ZONE_VEHICLE_UPDATEWEAPON_ID 0x89000d
#define ZONE_VEHICLE_REMOVEDFROMQUEUE_ID 0x89000e
#define ZONE_VEHICLE_UPDATEQUEUEPOSITION_ID 0x89000f
#define ZONE_VEHICLE_PADDESTROYNOTIFY_ID 0x890010
#define ZONE_VEHICLE_SETAUTODRIVE_ID 0x890011
#define ZONE_VEHICLE_LOCKONINFO_ID 0x890012
#define ZONE_VEHICLE_LOCKONSTATE_ID 0x890013
#define ZONE_VEHICLE_TRACKINGSTATE_ID 0x890014
#define ZONE_VEHICLE_COUNTERMEASURESTATE_ID 0x890015
#define ZONE_VEHICLE_LOADVEHICLEDEFINITIONMANAGER_ID 0x890016
#define ZONE_VEHICLE_ACQUIRESTATE_ID 0x890017
#define ZONE_VEHICLE_DISMISS_ID 0x890018
#define ZONE_VEHICLE_AUTOMOUNT_ID 0x890019
#define ZONE_VEHICLE_DEPLOY_ID 0x89001a
#define ZONE_VEHICLE_ENGINE_ID 0x89001b
#define ZONE_VEHICLE_ACCESSTYPE_ID 0x89001c
#define ZONE_VEHICLE_KICKPLAYER_ID 0x89001d
#define ZONE_VEHICLE_HEALTHUPDATEOWNER_ID 0x89001e
#define ZONE_VEHICLE_OWNERPASSENGERLIST_ID 0x89001f
#define ZONE_VEHICLE_KICKPACKET_ID 0x890020
#define ZONE_VEHICLE_NOACCESSPACKET_ID 0x890021
#define ZONE_VEHICLE_EXPIRATIONPACKET_ID 0x890022
#define ZONE_VEHICLE_GROUPPACKET_ID 0x890023
#define ZONE_VEHICLE_DEPLOYRESPONSEPACKET_ID 0x890024
#define ZONE_VEHICLE_EXITPOINTS_ID 0x890025
#define ZONE_VEHICLE_CONTROLLERLOGOUT_ID 0x890026
#define ZONE_VEHICLE_CURRENTMOVEMODE_ID 0x890027
#define ZONE_VEHICLE_ITEMDEFINITIONREQUEST_ID 0x890028
#define ZONE_VEHICLE_ITEMDEFINITIONREPLY_ID 0x890029
#define ZONE_VEHICLE_INVENTORYITEMS_ID 0x89002a
#define ZONE_GRIEFBASE_ID 0x8a
#define ZONE_SPOTPLAYER_ID 0x8b
#define ZONE_FACTIONSBASE_ID 0x8c
#define ZONE_SYNCHRONIZATION_ID 0x8d
#define ZONE_RESOURCEEVENTBASE_ID 0x8e
#define ZONE_COLLISIONBASE_ID 0x8f
#define ZONE_LEADERBOARDBASE_ID 0x90
#define ZONE_PLAYERUPDATEMANAGEDPOSITION_ID 0x91
#define ZONE_PLAYERUPDATEVEHICLEWEAPON_ID 0x93
#define ZONE_PROFILESTATSBASE_ID 0x94
#define ZONE_EQUIPMENTSETCHARACTEREQUIPMENT_ID 0x950001
#define ZONE_DEFINITIONFILTERSBASE_ID 0x96
#define ZONE_CONTINENTBATTLEINFO_ID 0x97
#define ZONE_SENDSECURITYPACKETANDSELFDESTRUCT_ID 0x99
#define ZONE_GETCONTINENTBATTLEINFO_ID 0x98
#define ZONE_GETRESPAWNLOCATIONS_ID 0x9a
#define ZONE_WALLOFDATABASE_ID 0x9b0000
#define ZONE_WALLOFDATA_UIEVENT_ID 0x9b0005
#define ZONE_WALLOFDATA_CLIENTSYSTEMINFO_ID 0x9b0006
#define ZONE_WALLOFDATA_VOICECHATEVENT_ID 0x9b0007
#define ZONE_WALLOFDATA_NUDGEEVENT_ID 0x9b0009
#define ZONE_WALLOFDATA_LAUNCHPADFINGERPRINT_ID 0x9b000a
#define ZONE_WALLOFDATA_VIDEOCAPTURE_ID 0x9b000b
#define ZONE_WALLOFDATA_CLIENTTRANSITION_ID 0x9b000c
#define ZONE_IMPLANTSBASE_ID 0x9c0000
#define ZONE_INGAMEPURCHASE_ID 0x9d
#define ZONE_MISSIONSBASE_ID 0x9e0000
#define ZONE_EFFECTSBASE_ID 0x9f0000
#define ZONE_REWARDBUFFSBASE_ID 0xa00000
#define ZONE_ABILITIESBASE_ID 0xa10000
#define ZONE_DEPLOYABLEBASE_ID 0xa20000
#define ZONE_SECURITY_ID 0xa3
#define ZONE_MAPREGIONBASE_ID 0xa4
#define ZONE_HUDMANAGERBASE_ID 0xa5
#define ZONE_ACQUIRETIMERSBASE_ID 0xa6
#define ZONE_LOGINBASE_ID 0xa7
#define ZONE_SERVERPOPULATIONINFO_ID 0xa8
#define ZONE_GETSERVERPOPULATIONINFO_ID 0xa9
#define ZONE_PLAYERUPDATEVEHICLECOLLISION_ID 0xaa
#define ZONE_PLAYERSTOP_ID 0xab
#define ZONE_CURRENCYBASE_ID 0xac
#define ZONE_ITEMSBASE_ID 0xad
#define ZONE_PLAYERUPDATEATTACHOBJECT_ID 0xae
#define ZONE_PLAYERUPDATEDETACHOBJECT_ID 0xaf
#define ZONE_CLIENTSETTINGS_ID 0xb0
#define ZONE_REWARDBUFFINFO_ID 0xb1
#define ZONE_GETREWARDBUFFINFO_ID 0xb2
#define ZONE_CAISBASE_ID 0xb3
#define ZONE_ZONESETTINGBASE_ID 0xb4
#define ZONE_REQUESTPROMOELIGIBILITYUPDATE_ID 0xb5
#define ZONE_PROMOELIGIBILITYREPLY_ID 0xb6
#define ZONE_METAGAMEEVENTBASE_ID 0xb7
#define ZONE_REQUESTWALLETTOPUPUPDATE_ID 0xb8
#define ZONE_STATIONCASHACTIVEPROMOREQUESTUPDATE_ID 0xb9
#define ZONE_OPERATIONBASE_ID 0xbc
#define ZONE_WORDFILTERBASE_ID 0xbd
#define ZONE_STATICFACILITYINFOBASE_ID 0xbe
#define ZONE_FACILITYINFO_REQUEST_ID 0xbe0001
#define ZONE_FACILITYINFO_REPLY_ID 0xbe0002
#define ZONE_FACILITYINFO_ALLZONES_ID 0xbe0003
#define ZONE_PROXIEDPLAYERBASE_ID 0xbf
#define ZONE_RESISTSBASE_ID 0xc0
#define ZONE_INGAMEPURCHASINGBASE_ID 0xc1
#define ZONE_BUSINESSENVIRONMENTS_ID 0xc2
#define ZONE_EMPIRESCOREPACKETBASE_ID 0xc3
#define ZONE_CHARACTERSELECTSESSIONREQUEST_ID 0xc4
#define ZONE_CHARACTERSELECTSESSIONRESPONSE_ID 0xc5
#define ZONE_STATSBASE_ID 0xc6
#define ZONE_SCOREBASE_ID 0xc7
#define ZONE_RESOURCESBASE_ID 0xc8
#define ZONE_CONSTRUCTIONBASE_ID 0xca
#define ZONE_UPDATEWEATHERDATA_ID 0xcb
#define ZONE_NAVGENBASE_ID 0xcc
#define ZONE_LOCKSBASE_ID 0xcd
#define ZONE_RAGDOLLBASE_ID 0xce
#define ZONE_CHARACTERSTATEBASE_ID 0xd0
#define ZONE_TIMEDGRANTBASE_ID 0xd1
#define ZONE_WEATHERBASE_ID 0xd2
#define ZONE_GAMEESCROWBASE_ID 0xd3
#define ZONE_PLAYCOMPOSITEEFFECT_ID 0xd4
#define ZONE_SETSPOTTED_ID 0xd5
#define ZONE_ADDLIGHTWEIGHTPC_ID 0xd6
#define ZONE_ADDLIGHTWEIGHTNPC_ID 0xd7
#define ZONE_ADDLIGHTWEIGHTVEHICLE_ID 0xd8
#define ZONE_ADDPROXIEDOBJECT_ID 0xd9
#define ZONE_ADDSIMPLENPC_ID 0x92
#define ZONE_LIGHTWEIGHTTOFULLPC_ID 0xda
#define ZONE_LIGHTWEIGHTTOFULLNPC_ID 0xdb
#define ZONE_LIGHTWEIGHTTOFULLVEHICLE_ID 0xdc
#define ZONE_CHECKLOCALVALUES_ID 0xde
#define ZONE_CHRONICLEBASE_ID 0xdf
#define ZONE_GRINDERBASE_ID 0xe0
#define ZONE_REQUESTOBJECT_ID 0xe1
#define ZONE_SCREENEFFECTBASE_ID 0xe2
#define ZONE_SPECTATORBASE_ID 0xe3
#define ZONE_WHITELISTBASE_ID 0xe4
#define ZONE_NPCFOUNDATIONPERMISSIONSMANAGERBASE_ID 0xe5
#define ZONE_BATTLEYEDATA_ID 0xe6
#define ZONE_ONLINEIDBASE_ID 0xe7
#define ZONE_PS4PLAYGOBASE_ID 0xe8
#define ZONE_SYNCHRONIZEDTELEPORTBASE_ID 0xe9
#define ZONE_STATICVIEWBASE_ID 0xea
#define ZONE_REPLICATIONBASE_ID 0xeb
#define ZONE_DATASHEETSBASE_ID 0xec
#define ZONE_PLAYERWORLDTRANSFERREQUEST_ID 0xed
#define ZONE_PLAYERWORLDTRANSFERREPLY_ID 0xee
#define ZONE_CANCELQUEUEONWORLD_ID 0xef
#define ZONE_DECLINEENTERGAMEONWORLD_ID 0xf0
#define ZONE_ACCESSEDCHARACTERBASE_ID 0xf1
#define ZONE_SHADERPARAMETEROVERRIDEBASE_ID 0xf2
#define ZONE_VEHICLESKINBASE_ID 0xf3
#define ZONE_WEAPONLAGLOCKPARAMETERS_ID 0xf5
#define ZONE_CRATEOPENINGBASE_ID 0xf6
#define ZONE_PLAYERHEATWARNING_ID 0xf7
#define ZONE_ANIMATIONBASE_ID 0xf8

#define ZONE_PACKET_KINDS \
ZONE_PACKET_KIND(Zone_Packet_Kind_Unhandled, "Unhandled"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_BaseServerPacket, "BaseServerPacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientFinishedLoading, "ClientFinishedLoading"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SendSelfToClient, "SendSelfToClient"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientIsReady, "ClientIsReady"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ZoneDoneSendingInitialData, "ZoneDoneSendingInitialData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ChatBase, "ChatBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Chat_Chat, "Chat_Chat"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Chat_ChatText, "Chat_ChatText"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientLogout, "ClientLogout"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_TargetClientNotOnline, "TargetClientNotOnline"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CommandItemDefinitionRequest, "CommandItemDefinitionRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CommandItemDefinitionReply, "CommandItemDefinitionReply"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CommandItemDefinitions, "CommandItemDefinitions"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AdminBase, "AdminBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientBeginZoning, "ClientBeginZoning"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CombatBase, "CombatBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ProjectileDebug, "ProjectileDebug"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MailBase, "MailBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CharacterBase, "CharacterBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_RemovePlayer, "Character_RemovePlayer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_Knockback, "Character_Knockback"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_UpdateHitpoints, "Character_UpdateHitpoints"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_PlayAnimation, "Character_PlayAnimation"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_UpdateScale, "Character_UpdateScale"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_UpdateTemporaryAppearance, "Character_UpdateTemporaryAppearance"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_RemoveTemporaryAppearance, "Character_RemoveTemporaryAppearance"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_SetLookAt, "Character_SetLookAt"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_RenamePlayer, "Character_RenamePlayer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_WeaponStance, "Character_WeaponStance"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Character_CharacterStateDelta, "Character_CharacterStateDelta"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AbilityBase, "AbilityBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdateBase, "ClientUpdateBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_Hitpoints, "ClientUpdate_Hitpoints"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ItemAdd, "ClientUpdate_ItemAdd"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ItemUpdate, "ClientUpdate_ItemUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ItemDelete, "ClientUpdate_ItemDelete"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateStat, "ClientUpdate_UpdateStat"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CollectionStart, "ClientUpdate_CollectionStart"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CollectionRemove, "ClientUpdate_CollectionRemove"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CollectionAddEntry, "ClientUpdate_CollectionAddEntry"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CollectionRemoveEntry, "ClientUpdate_CollectionRemoveEntry"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateLocation, "ClientUpdate_UpdateLocation"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_Mana, "ClientUpdate_Mana"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateProfileExperience, "ClientUpdate_UpdateProfileExperience"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_AddProfileAbilitySetApl, "ClientUpdate_AddProfileAbilitySetApl"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_AddEffectTag, "ClientUpdate_AddEffectTag"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_RemoveEffectTag, "ClientUpdate_RemoveEffectTag"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateProfileRank, "ClientUpdate_UpdateProfileRank"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CoinCount, "ClientUpdate_CoinCount"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_DeleteProfile, "ClientUpdate_DeleteProfile"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ActivateProfile, "ClientUpdate_ActivateProfile"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_AddAbility, "ClientUpdate_AddAbility"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_NotifyPlayer, "ClientUpdate_NotifyPlayer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateProfileAbilitySetApl, "ClientUpdate_UpdateProfileAbilitySetApl"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_RemoveActionBars, "ClientUpdate_RemoveActionBars"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateActionBarSlot, "ClientUpdate_UpdateActionBarSlot"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, "ClientUpdate_DoneSendingPreloadCharacters"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_SetGrandfatheredStatus, "ClientUpdate_SetGrandfatheredStatus"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateActionBarSlotUsed, "ClientUpdate_UpdateActionBarSlotUsed"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_PhaseChange, "ClientUpdate_PhaseChange"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateKingdomExperience, "ClientUpdate_UpdateKingdomExperience"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdatePacketDamageInfo, "ClientUpdate_UpdatePacketDamageInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_RespawnLocations, "ClientUpdate_RespawnLocations"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ModifyMovementSpeed, "ClientUpdate_ModifyMovementSpeed"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ModifyTurnRate, "ClientUpdate_ModifyTurnRate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ModifyStrafeSpeed, "ClientUpdate_ModifyStrafeSpeed"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateManagedLocation, "ClientUpdate_UpdateManagedLocation"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ManagedMovementVersion, "ClientUpdate_ManagedMovementVersion"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateWeaponAddClips, "ClientUpdate_UpdateWeaponAddClips"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_SpotProbation, "ClientUpdate_SpotProbation"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_DailyRibbonCount, "ClientUpdate_DailyRibbonCount"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_DespawnNpcUpdate, "ClientUpdate_DespawnNpcUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_LoyaltyPoints, "ClientUpdate_LoyaltyPoints"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ResetMissionRespawnTimer, "ClientUpdate_ResetMissionRespawnTimer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_Freeze, "ClientUpdate_Freeze"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_InGamePurchaseResult, "ClientUpdate_InGamePurchaseResult"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_QuizComplete, "ClientUpdate_QuizComplete"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_StartTimer, "ClientUpdate_StartTimer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CompleteLogoutProcess, "ClientUpdate_CompleteLogoutProcess"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ProximateItems, "ClientUpdate_ProximateItems"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_TextAlert, "ClientUpdate_TextAlert"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ClearEntitlementValues, "ClientUpdate_ClearEntitlementValues"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_AddEntitlementValue, "ClientUpdate_AddEntitlementValue"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, "ClientUpdate_NetworkProximityUpdatesComplete"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_FileValidationRequest, "ClientUpdate_FileValidationRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_FileValidationResponse, "ClientUpdate_FileValidationResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_DeathMetrics, "ClientUpdate_DeathMetrics"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_SetCurrentAdventure, "ClientUpdate_SetCurrentAdventure"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CharacterSlot, "ClientUpdate_CharacterSlot"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ManagedObjectRequestControl, "ClientUpdate_ManagedObjectRequestControl"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ManagedObjectResponseControl, "ClientUpdate_ManagedObjectResponseControl"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ManagedObjectReleaseControl, "ClientUpdate_ManagedObjectReleaseControl"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_CustomizationData, "ClientUpdate_CustomizationData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateCurrency, "ClientUpdate_UpdateCurrency"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_AddNotifications, "ClientUpdate_AddNotifications"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_RemoveNotifications, "ClientUpdate_RemoveNotifications"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_NpcRelevance, "ClientUpdate_NpcRelevance"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_InitiateNameChange, "ClientUpdate_InitiateNameChange"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_NameChangeResult, "ClientUpdate_NameChangeResult"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift, "ClientUpdate_MonitorTimeDrift"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_NotifyServerOfStalledEvent, "ClientUpdate_NotifyServerOfStalledEvent"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateSights, "ClientUpdate_UpdateSights"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateRewardAndGrinderState, "ClientUpdate_UpdateRewardAndGrinderState"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateActivityMetrics, "ClientUpdate_UpdateActivityMetrics"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_StopWithError, "ClientUpdate_StopWithError"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_SetWorldWipeTimer, "ClientUpdate_SetWorldWipeTimer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateLockoutTimes, "ClientUpdate_UpdateLockoutTimes"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_ZoneStatus, "ClientUpdate_ZoneStatus"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_SetDataCenter, "ClientUpdate_SetDataCenter"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration, "ClientUpdate_UpdateBattlEyeRegistration"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GroupsBase, "GroupsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EncounterBase, "EncounterBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InventoryBase, "InventoryBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SendZoneDetails, "SendZoneDetails"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ReferenceDataWeaponDefinitions, "ReferenceDataWeaponDefinitions"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ObjectiveBase, "ObjectiveBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_DebugBase, "DebugBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_UiBase, "UiBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_QuestBase, "QuestBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RewardBase, "RewardBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GameTimeSync, "GameTimeSync"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PetBase, "PetBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PointOfInterestDefinitionRequest, "PointOfInterestDefinitionRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PointOfInterestDefinitionReply, "PointOfInterestDefinitionReply"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WorldTeleportRequest, "WorldTeleportRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_TradeBase, "TradeBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EscrowGivePackage, "EscrowGivePackage"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EscrowGotPackage, "EscrowGotPackage"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_UpdateEncounterDataCommon, "UpdateEncounterDataCommon"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RecipeBase, "RecipeBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InGamePurchaseBase, "InGamePurchaseBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_QuickChatBase, "QuickChatBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ReportBase, "ReportBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LiveGamerBase, "LiveGamerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AcquaintanceBase, "AcquaintanceBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientServerShuttingDown, "ClientServerShuttingDown"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FriendBase, "FriendBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_BroadcastBase, "BroadcastBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientKickedFromServer, "ClientKickedFromServer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_UpdateClientSessionData, "UpdateClientSessionData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_BugSubmissionBase, "BugSubmissionBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WorldDisplayInfo, "WorldDisplayInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MOTD, "MOTD"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SetLocale, "SetLocale"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SetClientArea, "SetClientArea"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ZoneTeleportRequest, "ZoneTeleportRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_TradingCardBase, "TradingCardBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WorldShutdownNotice, "WorldShutdownNotice"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LoadWelcomeScreen, "LoadWelcomeScreen"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ShipCombatBase, "ShipCombatBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_KeepAlive, "KeepAlive"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientExitLaunchUri, "ClientExitLaunchUri"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientPath, "ClientPath"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientPendingKickFromServer, "ClientPendingKickFromServer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientMembershipActivation, "ClientMembershipActivation"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LobbyBase, "LobbyBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LobbyGameDefinitionBase, "LobbyGameDefinitionBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ShowSystemMessage, "ShowSystemMessage"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_POIChangeMessage, "POIChangeMessage"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientMetrics, "ClientMetrics"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FirstTimeEventBase, "FirstTimeEventBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClaimBase, "ClaimBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientLog, "ClientLog"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_IgnoreBase, "IgnoreBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SnoopedPlayerBase, "SnoopedPlayerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PromotionalBase, "PromotionalBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AddClientPortraitCrc, "AddClientPortraitCrc"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ObjectiveTargetBase, "ObjectiveTargetBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CommerceSessionRequest, "CommerceSessionRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CommerceSessionResponse, "CommerceSessionResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_TrackedEvent, "TrackedEvent"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientLoginFailed, "ClientLoginFailed"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LoginToUChat, "LoginToUChat"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ZoneSafeTeleportRequest, "ZoneSafeTeleportRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RemoteInteractionRequest, "RemoteInteractionRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_UpdateCamera, "UpdateCamera"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GuildBase, "GuildBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AdminGuildBase, "AdminGuildBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_BattleMagesBase, "BattleMagesBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WorldToWorldBase, "WorldToWorldBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PerformAction, "PerformAction"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EncounterMatchmakingBase, "EncounterMatchmakingBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientLuaMetrics, "ClientLuaMetrics"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RepeatingActivityBase, "RepeatingActivityBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientGameSettings, "ClientGameSettings"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientTrialProfileUpsell, "ClientTrialProfileUpsell"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ActivityManagerBase, "ActivityManagerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RequestSendItemDefinitionsToClient, "RequestSendItemDefinitionsToClient"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InspectBase, "InspectBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AchievementBase, "AchievementBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerTitleBase, "PlayerTitleBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MatchHistoryBase, "MatchHistoryBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_UpdateUserAge, "UpdateUserAge"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LootBase, "LootBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ActionBarManagerBase, "ActionBarManagerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientTrialProfileUpsellRequest, "ClientTrialProfileUpsellRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdateJump, "PlayerUpdateJump"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CoinStoreBase, "CoinStoreBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InitializationParameters, "InitializationParameters"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ActivityBase, "ActivityBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MountBase, "MountBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountRequest, "Mount_MountRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountResponse, "Mount_MountResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_DismountRequest, "Mount_DismountRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_DismountResponse, "Mount_DismountResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountList, "Mount_MountList"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountSpawn, "Mount_MountSpawn"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountDespawn, "Mount_MountDespawn"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountSpawnByItemDefinitionId, "Mount_MountSpawnByItemDefinitionId"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountOfferUpsell, "Mount_MountOfferUpsell"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_SeatChangeRequest, "Mount_SeatChangeRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_SeatChangeResponse, "Mount_SeatChangeResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_SeatSwapRequest, "Mount_SeatSwapRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_SeatSwapResponse, "Mount_SeatSwapResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_MountPacketTypeCount, "Mount_MountPacketTypeCount"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Mount_FlipMount, "Mount_FlipMount"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientInitializationDetails, "ClientInitializationDetails"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientAreaTimer, "ClientAreaTimer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LoyaltyRewardBase, "LoyaltyRewardBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RatingBase, "RatingBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientActivityLaunchBase, "ClientActivityLaunchBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ServerActivityLaunchBase, "ServerActivityLaunchBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientFlashTimer, "ClientFlashTimer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdatePosition, "PlayerUpdatePosition"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InviteAndStartMiniGame, "InviteAndStartMiniGame"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_QuizBase, "QuizBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdatePositionOnPlatform, "PlayerUpdatePositionOnPlatform"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientMembershipVipInfo, "ClientMembershipVipInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_TargetBase, "TargetBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GuideStoneBase, "GuideStoneBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RaidsBase, "RaidsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_VoiceBase, "VoiceBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WeaponBase, "WeaponBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MatchScheduleBase, "MatchScheduleBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FacilityBase, "FacilityBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_ReferenceData, "Facility_ReferenceData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_FacilityData, "Facility_FacilityData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_CurrentFacilityUpdate, "Facility_CurrentFacilityUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_SpawnDataRequest, "Facility_SpawnDataRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_FacilitySpawnData, "Facility_FacilitySpawnData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_FacilityUpdate, "Facility_FacilityUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_FacilitySpawnStatus, "Facility_FacilitySpawnStatus"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_FacilitySpawnStatusTracked, "Facility_FacilitySpawnStatusTracked"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationFacilityCaptured, "Facility_NotificationFacilityCaptured"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationFacilitySignificantCaptureProgress, "Facility_NotificationFacilitySignificantCaptureProgress"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationFacilityCloseToCapture, "Facility_NotificationFacilityCloseToCapture"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationFacilitySpawnBeginCapture, "Facility_NotificationFacilitySpawnBeginCapture"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationFacilitySpawnFinishCapture, "Facility_NotificationFacilitySpawnFinishCapture"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationLeavingFacilityDuringContention, "Facility_NotificationLeavingFacilityDuringContention"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_ProximitySpawnCaptureUpdate, "Facility_ProximitySpawnCaptureUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_ClearProximitySpawn, "Facility_ClearProximitySpawn"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_GridStabilizeTimerUpdated, "Facility_GridStabilizeTimerUpdated"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_SpawnCollisionChanged, "Facility_SpawnCollisionChanged"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_NotificationFacilitySecondaryObjectiveEventPacket, "Facility_NotificationFacilitySecondaryObjectiveEventPacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_PenetrateShieldEffect, "Facility_PenetrateShieldEffect"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_SpawnUpdateGuid, "Facility_SpawnUpdateGuid"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_FacilityUpdateRequest, "Facility_FacilityUpdateRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Facility_EmpireScoreValueUpdate, "Facility_EmpireScoreValueUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SkillsBase, "SkillsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LoadoutsBase, "LoadoutsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ExperienceBase, "ExperienceBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_VehicleBase, "VehicleBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Owner, "Vehicle_Owner"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Occupy, "Vehicle_Occupy"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_StateData, "Vehicle_StateData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_StateDamage, "Vehicle_StateDamage"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_PlayerManager, "Vehicle_PlayerManager"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Spawn, "Vehicle_Spawn"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Tint, "Vehicle_Tint"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_LoadVehicleTerminalDefinitionManager, "Vehicle_LoadVehicleTerminalDefinitionManager"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_ActiveWeapon, "Vehicle_ActiveWeapon"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Stats, "Vehicle_Stats"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_DamageInfo, "Vehicle_DamageInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_StatUpdate, "Vehicle_StatUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_UpdateWeapon, "Vehicle_UpdateWeapon"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_RemovedFromQueue, "Vehicle_RemovedFromQueue"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_UpdateQueuePosition, "Vehicle_UpdateQueuePosition"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_PadDestroyNotify, "Vehicle_PadDestroyNotify"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_SetAutoDrive, "Vehicle_SetAutoDrive"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_LockOnInfo, "Vehicle_LockOnInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_LockOnState, "Vehicle_LockOnState"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_TrackingState, "Vehicle_TrackingState"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_CounterMeasureState, "Vehicle_CounterMeasureState"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_LoadVehicleDefinitionManager, "Vehicle_LoadVehicleDefinitionManager"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_AcquireState, "Vehicle_AcquireState"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Dismiss, "Vehicle_Dismiss"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_AutoMount, "Vehicle_AutoMount"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Deploy, "Vehicle_Deploy"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_Engine, "Vehicle_Engine"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_AccessType, "Vehicle_AccessType"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_KickPlayer, "Vehicle_KickPlayer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_HealthUpdateOwner, "Vehicle_HealthUpdateOwner"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_OwnerPassengerList, "Vehicle_OwnerPassengerList"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_KickPacket, "Vehicle_KickPacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_NoAccessPacket, "Vehicle_NoAccessPacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_ExpirationPacket, "Vehicle_ExpirationPacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_GroupPacket, "Vehicle_GroupPacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_DeployResponsePacket, "Vehicle_DeployResponsePacket"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_ExitPoints, "Vehicle_ExitPoints"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_ControllerLogOut, "Vehicle_ControllerLogOut"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_CurrentMoveMode, "Vehicle_CurrentMoveMode"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_ItemDefinitionRequest, "Vehicle_ItemDefinitionRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_ItemDefinitionReply, "Vehicle_ItemDefinitionReply"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Vehicle_InventoryItems, "Vehicle_InventoryItems"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GriefBase, "GriefBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SpotPlayer, "SpotPlayer"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FactionsBase, "FactionsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Synchronization, "Synchronization"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ResourceEventBase, "ResourceEventBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CollisionBase, "CollisionBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LeaderboardBase, "LeaderboardBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdateManagedPosition, "PlayerUpdateManagedPosition"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdateVehicleWeapon, "PlayerUpdateVehicleWeapon"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ProfileStatsBase, "ProfileStatsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EquipmentSetCharacterEquipment, "EquipmentSetCharacterEquipment"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_DefinitionFiltersBase, "DefinitionFiltersBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ContinentBattleInfo, "ContinentBattleInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SendSecurityPacketAndSelfDestruct, "SendSecurityPacketAndSelfDestruct"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GetContinentBattleInfo, "GetContinentBattleInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GetRespawnLocations, "GetRespawnLocations"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfDataBase, "WallOfDataBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_UIEvent, "WallOfData_UIEvent"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_ClientSystemInfo, "WallOfData_ClientSystemInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_VoiceChatEvent, "WallOfData_VoiceChatEvent"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_NudgeEvent, "WallOfData_NudgeEvent"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_LaunchPadFingerprint, "WallOfData_LaunchPadFingerprint"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_VideoCapture, "WallOfData_VideoCapture"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WallOfData_ClientTransition, "WallOfData_ClientTransition"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ImplantsBase, "ImplantsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InGamePurchase, "InGamePurchase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MissionsBase, "MissionsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EffectsBase, "EffectsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RewardBuffsBase, "RewardBuffsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AbilitiesBase, "AbilitiesBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_DeployableBase, "DeployableBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Security, "Security"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MapRegionBase, "MapRegionBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_HudManagerBase, "HudManagerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AcquireTimersBase, "AcquireTimersBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LoginBase, "LoginBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ServerPopulationInfo, "ServerPopulationInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GetServerPopulationInfo, "GetServerPopulationInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdateVehicleCollision, "PlayerUpdateVehicleCollision"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerStop, "PlayerStop"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CurrencyBase, "CurrencyBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ItemsBase, "ItemsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdateAttachObject, "PlayerUpdateAttachObject"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerUpdateDetachObject, "PlayerUpdateDetachObject"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ClientSettings, "ClientSettings"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RewardBuffInfo, "RewardBuffInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GetRewardBuffInfo, "GetRewardBuffInfo"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CaisBase, "CaisBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ZoneSettingBase, "ZoneSettingBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RequestPromoEligibilityUpdate, "RequestPromoEligibilityUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PromoEligibilityReply, "PromoEligibilityReply"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_MetaGameEventBase, "MetaGameEventBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RequestWalletTopupUpdate, "RequestWalletTopupUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_StationCashActivePromoRequestUpdate, "StationCashActivePromoRequestUpdate"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_OperationBase, "OperationBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WordFilterBase, "WordFilterBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_StaticFacilityInfoBase, "StaticFacilityInfoBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FacilityInfo_Request, "FacilityInfo_Request"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FacilityInfo_Reply, "FacilityInfo_Reply"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_FacilityInfo_AllZones, "FacilityInfo_AllZones"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ProxiedPlayerBase, "ProxiedPlayerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ResistsBase, "ResistsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_InGamePurchasingBase, "InGamePurchasingBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_BusinessEnvironments, "BusinessEnvironments"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_EmpireScorePacketBase, "EmpireScorePacketBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CharacterSelectSessionRequest, "CharacterSelectSessionRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CharacterSelectSessionResponse, "CharacterSelectSessionResponse"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_StatsBase, "StatsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ScoreBase, "ScoreBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ResourcesBase, "ResourcesBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ConstructionBase, "ConstructionBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_UpdateWeatherData, "UpdateWeatherData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_NavGenBase, "NavGenBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LocksBase, "LocksBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RagdollBase, "RagdollBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CharacterStateBase, "CharacterStateBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_TimedGrantBase, "TimedGrantBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WeatherBase, "WeatherBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GameEscrowBase, "GameEscrowBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayCompositeEffect, "PlayCompositeEffect"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SetSpotted, "SetSpotted"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AddLightweightPc, "AddLightweightPc"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AddLightweightNpc, "AddLightweightNpc"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AddLightweightVehicle, "AddLightweightVehicle"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AddProxiedObject, "AddProxiedObject"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AddSimpleNpc, "AddSimpleNpc"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LightweightToFullPc, "LightweightToFullPc"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LightweightToFullNpc, "LightweightToFullNpc"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_LightweightToFullVehicle, "LightweightToFullVehicle"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CheckLocalValues, "CheckLocalValues"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ChronicleBase, "ChronicleBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_GrinderBase, "GrinderBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_RequestObject, "RequestObject"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ScreenEffectBase, "ScreenEffectBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SpectatorBase, "SpectatorBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WhitelistBase, "WhitelistBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_NpcFoundationPermissionsManagerBase, "NpcFoundationPermissionsManagerBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_BattlEyeData, "BattlEyeData"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_OnlineIdBase, "OnlineIdBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_Ps4PlayGoBase, "Ps4PlayGoBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_SynchronizedTeleportBase, "SynchronizedTeleportBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_StaticViewBase, "StaticViewBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ReplicationBase, "ReplicationBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_DatasheetsBase, "DatasheetsBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerWorldTransferRequest, "PlayerWorldTransferRequest"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerWorldTransferReply, "PlayerWorldTransferReply"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CancelQueueOnWorld, "CancelQueueOnWorld"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_DeclineEnterGameOnWorld, "DeclineEnterGameOnWorld"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AccessedCharacterBase, "AccessedCharacterBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_ShaderParameterOverrideBase, "ShaderParameterOverrideBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_VehicleSkinBase, "VehicleSkinBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_WeaponLagLockParameters, "WeaponLagLockParameters"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_CrateOpeningBase, "CrateOpeningBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_PlayerHeatWarning, "PlayerHeatWarning"), \
ZONE_PACKET_KIND(Zone_Packet_Kind_AnimationBase, "AnimationBase"), \
ZONE_PACKET_KIND(Zone_Packet_Kind__End, "")

typedef enum Zone_Packet_Kind
{
#define ZONE_PACKET_KIND(e, s) e
ZONE_PACKET_KINDS
#undef ZONE_PACKET_KIND
} Zone_Packet_Kind;

char* zone_packet_names[Zone_Packet_Kind__End + 1] =
{
#define ZONE_PACKET_KIND(e, s) s
ZONE_PACKET_KINDS
#undef ZONE_PACKET_KIND
};


u32 zone_registered_ids[] =
{
[Zone_Packet_Kind_BaseServerPacket] = 0x1,
[Zone_Packet_Kind_ClientFinishedLoading] = 0x2,
[Zone_Packet_Kind_SendSelfToClient] = 0x3,
[Zone_Packet_Kind_ClientIsReady] = 0x4,
[Zone_Packet_Kind_ZoneDoneSendingInitialData] = 0x5,
[Zone_Packet_Kind_ChatBase] = 0x60000,
[Zone_Packet_Kind_Chat_Chat] = 0x60001,
[Zone_Packet_Kind_Chat_ChatText] = 0x60005,
[Zone_Packet_Kind_ClientLogout] = 0x7,
[Zone_Packet_Kind_TargetClientNotOnline] = 0x8,
[Zone_Packet_Kind_CommandItemDefinitionRequest] = 0x900000045,
[Zone_Packet_Kind_CommandItemDefinitionReply] = 0x900000046,
[Zone_Packet_Kind_CommandItemDefinitions] = 0x900000047,
[Zone_Packet_Kind_AdminBase] = 0xa0000,
[Zone_Packet_Kind_ClientBeginZoning] = 0xb,
[Zone_Packet_Kind_CombatBase] = 0xc0000,
[Zone_Packet_Kind_ProjectileDebug] = 0xd,
[Zone_Packet_Kind_MailBase] = 0xe0000,
[Zone_Packet_Kind_CharacterBase] = 0xf0000,
[Zone_Packet_Kind_Character_RemovePlayer] = 0xf0001,
[Zone_Packet_Kind_Character_Knockback] = 0xf0002,
[Zone_Packet_Kind_Character_UpdateHitpoints] = 0xf0003,
[Zone_Packet_Kind_Character_PlayAnimation] = 0xf0004,
[Zone_Packet_Kind_Character_UpdateScale] = 0xf0005,
[Zone_Packet_Kind_Character_UpdateTemporaryAppearance] = 0xf0006,
[Zone_Packet_Kind_Character_RemoveTemporaryAppearance] = 0xf0007,
[Zone_Packet_Kind_Character_SetLookAt] = 0xf0008,
[Zone_Packet_Kind_Character_RenamePlayer] = 0xf0009,
[Zone_Packet_Kind_Character_WeaponStance] = 0xf0020,
[Zone_Packet_Kind_Character_CharacterStateDelta] = 0xf003f,
[Zone_Packet_Kind_AbilityBase] = 0x100000,
[Zone_Packet_Kind_ClientUpdateBase] = 0x110000,
[Zone_Packet_Kind_ClientUpdate_Hitpoints] = 0x110001,
[Zone_Packet_Kind_ClientUpdate_ItemAdd] = 0x110002,
[Zone_Packet_Kind_ClientUpdate_ItemUpdate] = 0x110003,
[Zone_Packet_Kind_ClientUpdate_ItemDelete] = 0x110004,
[Zone_Packet_Kind_ClientUpdate_UpdateStat] = 0x110005,
[Zone_Packet_Kind_ClientUpdate_CollectionStart] = 0x110006,
[Zone_Packet_Kind_ClientUpdate_CollectionRemove] = 0x110007,
[Zone_Packet_Kind_ClientUpdate_CollectionAddEntry] = 0x110008,
[Zone_Packet_Kind_ClientUpdate_CollectionRemoveEntry] = 0x110009,
[Zone_Packet_Kind_ClientUpdate_UpdateLocation] = 0x11000a,
[Zone_Packet_Kind_ClientUpdate_Mana] = 0x11000b,
[Zone_Packet_Kind_ClientUpdate_UpdateProfileExperience] = 0x11000c,
[Zone_Packet_Kind_ClientUpdate_AddProfileAbilitySetApl] = 0x11000d,
[Zone_Packet_Kind_ClientUpdate_AddEffectTag] = 0x11000e,
[Zone_Packet_Kind_ClientUpdate_RemoveEffectTag] = 0x11000f,
[Zone_Packet_Kind_ClientUpdate_UpdateProfileRank] = 0x110010,
[Zone_Packet_Kind_ClientUpdate_CoinCount] = 0x110011,
[Zone_Packet_Kind_ClientUpdate_DeleteProfile] = 0x110012,
[Zone_Packet_Kind_ClientUpdate_ActivateProfile] = 0x110013,
[Zone_Packet_Kind_ClientUpdate_AddAbility] = 0x110014,
[Zone_Packet_Kind_ClientUpdate_NotifyPlayer] = 0x110015,
[Zone_Packet_Kind_ClientUpdate_UpdateProfileAbilitySetApl] = 0x110016,
[Zone_Packet_Kind_ClientUpdate_RemoveActionBars] = 0x110017,
[Zone_Packet_Kind_ClientUpdate_UpdateActionBarSlot] = 0x110018,
[Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters] = 0x110019,
[Zone_Packet_Kind_ClientUpdate_SetGrandfatheredStatus] = 0x11001a,
[Zone_Packet_Kind_ClientUpdate_UpdateActionBarSlotUsed] = 0x11001b,
[Zone_Packet_Kind_ClientUpdate_PhaseChange] = 0x11001c,
[Zone_Packet_Kind_ClientUpdate_UpdateKingdomExperience] = 0x11001d,
[Zone_Packet_Kind_ClientUpdate_UpdatePacketDamageInfo] = 0x11001e,
[Zone_Packet_Kind_ClientUpdate_RespawnLocations] = 0x11001f,
[Zone_Packet_Kind_ClientUpdate_ModifyMovementSpeed] = 0x110020,
[Zone_Packet_Kind_ClientUpdate_ModifyTurnRate] = 0x110021,
[Zone_Packet_Kind_ClientUpdate_ModifyStrafeSpeed] = 0x110022,
[Zone_Packet_Kind_ClientUpdate_UpdateManagedLocation] = 0x110023,
[Zone_Packet_Kind_ClientUpdate_ManagedMovementVersion] = 0x110024,
[Zone_Packet_Kind_ClientUpdate_UpdateWeaponAddClips] = 0x110025,
[Zone_Packet_Kind_ClientUpdate_SpotProbation] = 0x110026,
[Zone_Packet_Kind_ClientUpdate_DailyRibbonCount] = 0x110027,
[Zone_Packet_Kind_ClientUpdate_DespawnNpcUpdate] = 0x110029,
[Zone_Packet_Kind_ClientUpdate_LoyaltyPoints] = 0x11002a,
[Zone_Packet_Kind_ClientUpdate_ResetMissionRespawnTimer] = 0x11002b,
[Zone_Packet_Kind_ClientUpdate_Freeze] = 0x11002c,
[Zone_Packet_Kind_ClientUpdate_InGamePurchaseResult] = 0x11002d,
[Zone_Packet_Kind_ClientUpdate_QuizComplete] = 0x11002e,
[Zone_Packet_Kind_ClientUpdate_StartTimer] = 0x11002f,
[Zone_Packet_Kind_ClientUpdate_CompleteLogoutProcess] = 0x110030,
[Zone_Packet_Kind_ClientUpdate_ProximateItems] = 0x110031,
[Zone_Packet_Kind_ClientUpdate_TextAlert] = 0x110032,
[Zone_Packet_Kind_ClientUpdate_ClearEntitlementValues] = 0x110033,
[Zone_Packet_Kind_ClientUpdate_AddEntitlementValue] = 0x110034,
[Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete] = 0x110035,
[Zone_Packet_Kind_ClientUpdate_FileValidationRequest] = 0x110036,
[Zone_Packet_Kind_ClientUpdate_FileValidationResponse] = 0x110037,
[Zone_Packet_Kind_ClientUpdate_DeathMetrics] = 0x110038,
[Zone_Packet_Kind_ClientUpdate_SetCurrentAdventure] = 0x11003c,
[Zone_Packet_Kind_ClientUpdate_CharacterSlot] = 0x11003d,
[Zone_Packet_Kind_ClientUpdate_ManagedObjectRequestControl] = 0x110039,
[Zone_Packet_Kind_ClientUpdate_ManagedObjectResponseControl] = 0x11003a,
[Zone_Packet_Kind_ClientUpdate_ManagedObjectReleaseControl] = 0x11003b,
[Zone_Packet_Kind_ClientUpdate_CustomizationData] = 0x11003e,
[Zone_Packet_Kind_ClientUpdate_UpdateCurrency] = 0x11003f,
[Zone_Packet_Kind_ClientUpdate_AddNotifications] = 0x110040,
[Zone_Packet_Kind_ClientUpdate_RemoveNotifications] = 0x110041,
[Zone_Packet_Kind_ClientUpdate_NpcRelevance] = 0x110042,
[Zone_Packet_Kind_ClientUpdate_InitiateNameChange] = 0x110043,
[Zone_Packet_Kind_ClientUpdate_NameChangeResult] = 0x110044,
[Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift] = 0x110045,
[Zone_Packet_Kind_ClientUpdate_NotifyServerOfStalledEvent] = 0x110046,
[Zone_Packet_Kind_ClientUpdate_UpdateSights] = 0x110047,
[Zone_Packet_Kind_ClientUpdate_UpdateRewardAndGrinderState] = 0x110049,
[Zone_Packet_Kind_ClientUpdate_UpdateActivityMetrics] = 0x11004b,
[Zone_Packet_Kind_ClientUpdate_StopWithError] = 0x11004c,
[Zone_Packet_Kind_ClientUpdate_SetWorldWipeTimer] = 0x11004d,
[Zone_Packet_Kind_ClientUpdate_UpdateLockoutTimes] = 0x11004e,
[Zone_Packet_Kind_ClientUpdate_ZoneStatus] = 0x11004f,
[Zone_Packet_Kind_ClientUpdate_SetDataCenter] = 0x110050,
[Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration] = 0x110051,
[Zone_Packet_Kind_GroupsBase] = 0x13,
[Zone_Packet_Kind_EncounterBase] = 0x14,
[Zone_Packet_Kind_InventoryBase] = 0x15,
[Zone_Packet_Kind_SendZoneDetails] = 0x16,
[Zone_Packet_Kind_ReferenceDataWeaponDefinitions] = 0x170004,
[Zone_Packet_Kind_ObjectiveBase] = 0x18,
[Zone_Packet_Kind_DebugBase] = 0x19,
[Zone_Packet_Kind_UiBase] = 0x1a,
[Zone_Packet_Kind_QuestBase] = 0x1b,
[Zone_Packet_Kind_RewardBase] = 0x1c,
[Zone_Packet_Kind_GameTimeSync] = 0x1d,
[Zone_Packet_Kind_PetBase] = 0x1e,
[Zone_Packet_Kind_PointOfInterestDefinitionRequest] = 0x1f,
[Zone_Packet_Kind_PointOfInterestDefinitionReply] = 0x20,
[Zone_Packet_Kind_WorldTeleportRequest] = 0x21,
[Zone_Packet_Kind_TradeBase] = 0x22,
[Zone_Packet_Kind_EscrowGivePackage] = 0x23,
[Zone_Packet_Kind_EscrowGotPackage] = 0x24,
[Zone_Packet_Kind_UpdateEncounterDataCommon] = 0x25,
[Zone_Packet_Kind_RecipeBase] = 0x26,
[Zone_Packet_Kind_InGamePurchaseBase] = 0x27,
[Zone_Packet_Kind_QuickChatBase] = 0x28,
[Zone_Packet_Kind_ReportBase] = 0x29,
[Zone_Packet_Kind_LiveGamerBase] = 0x2a,
[Zone_Packet_Kind_AcquaintanceBase] = 0x2b,
[Zone_Packet_Kind_ClientServerShuttingDown] = 0x2c,
[Zone_Packet_Kind_FriendBase] = 0x2d,
[Zone_Packet_Kind_BroadcastBase] = 0x2e,
[Zone_Packet_Kind_ClientKickedFromServer] = 0x2f,
[Zone_Packet_Kind_UpdateClientSessionData] = 0x30,
[Zone_Packet_Kind_BugSubmissionBase] = 0x31,
[Zone_Packet_Kind_WorldDisplayInfo] = 0x32,
[Zone_Packet_Kind_MOTD] = 0x33,
[Zone_Packet_Kind_SetLocale] = 0x34,
[Zone_Packet_Kind_SetClientArea] = 0x35,
[Zone_Packet_Kind_ZoneTeleportRequest] = 0x36,
[Zone_Packet_Kind_TradingCardBase] = 0x37,
[Zone_Packet_Kind_WorldShutdownNotice] = 0x38,
[Zone_Packet_Kind_LoadWelcomeScreen] = 0x39,
[Zone_Packet_Kind_ShipCombatBase] = 0x3a,
[Zone_Packet_Kind_KeepAlive] = 0x3c,
[Zone_Packet_Kind_ClientExitLaunchUri] = 0x3d,
[Zone_Packet_Kind_ClientPath] = 0x3e,
[Zone_Packet_Kind_ClientPendingKickFromServer] = 0x3f,
[Zone_Packet_Kind_ClientMembershipActivation] = 0x40,
[Zone_Packet_Kind_LobbyBase] = 0x41,
[Zone_Packet_Kind_LobbyGameDefinitionBase] = 0x42,
[Zone_Packet_Kind_ShowSystemMessage] = 0x43,
[Zone_Packet_Kind_POIChangeMessage] = 0x44,
[Zone_Packet_Kind_ClientMetrics] = 0x45,
[Zone_Packet_Kind_FirstTimeEventBase] = 0x46,
[Zone_Packet_Kind_ClaimBase] = 0x47,
[Zone_Packet_Kind_ClientLog] = 0x48,
[Zone_Packet_Kind_IgnoreBase] = 0x49,
[Zone_Packet_Kind_SnoopedPlayerBase] = 0x4a,
[Zone_Packet_Kind_PromotionalBase] = 0x4b,
[Zone_Packet_Kind_AddClientPortraitCrc] = 0x4c,
[Zone_Packet_Kind_ObjectiveTargetBase] = 0x4d0000,
[Zone_Packet_Kind_CommerceSessionRequest] = 0x4e,
[Zone_Packet_Kind_CommerceSessionResponse] = 0x4f,
[Zone_Packet_Kind_TrackedEvent] = 0x50,
[Zone_Packet_Kind_ClientLoginFailed] = 0x51,
[Zone_Packet_Kind_LoginToUChat] = 0x52,
[Zone_Packet_Kind_ZoneSafeTeleportRequest] = 0x53,
[Zone_Packet_Kind_RemoteInteractionRequest] = 0x54,
[Zone_Packet_Kind_UpdateCamera] = 0x57,
[Zone_Packet_Kind_GuildBase] = 0x59,
[Zone_Packet_Kind_AdminGuildBase] = 0x5a0000,
[Zone_Packet_Kind_BattleMagesBase] = 0x5b0000,
[Zone_Packet_Kind_WorldToWorldBase] = 0x5c0000,
[Zone_Packet_Kind_PerformAction] = 0x5d,
[Zone_Packet_Kind_EncounterMatchmakingBase] = 0x5e0000,
[Zone_Packet_Kind_ClientLuaMetrics] = 0x5f0000,
[Zone_Packet_Kind_RepeatingActivityBase] = 0x600000,
[Zone_Packet_Kind_ClientGameSettings] = 0x61,
[Zone_Packet_Kind_ClientTrialProfileUpsell] = 0x62,
[Zone_Packet_Kind_ActivityManagerBase] = 0x63,
[Zone_Packet_Kind_RequestSendItemDefinitionsToClient] = 0x64,
[Zone_Packet_Kind_InspectBase] = 0x650000,
[Zone_Packet_Kind_AchievementBase] = 0x660000,
[Zone_Packet_Kind_PlayerTitleBase] = 0x670000,
[Zone_Packet_Kind_MatchHistoryBase] = 0x680000,
[Zone_Packet_Kind_UpdateUserAge] = 0x69,
[Zone_Packet_Kind_LootBase] = 0x6a0000,
[Zone_Packet_Kind_ActionBarManagerBase] = 0x6b0000,
[Zone_Packet_Kind_ClientTrialProfileUpsellRequest] = 0x6c,
[Zone_Packet_Kind_PlayerUpdateJump] = 0x6d,
[Zone_Packet_Kind_CoinStoreBase] = 0x6e0000,
[Zone_Packet_Kind_InitializationParameters] = 0x6f,
[Zone_Packet_Kind_ActivityBase] = 0x700000,
[Zone_Packet_Kind_MountBase] = 0x71,
[Zone_Packet_Kind_Mount_MountRequest] = 0x710001,
[Zone_Packet_Kind_Mount_MountResponse] = 0x710002,
[Zone_Packet_Kind_Mount_DismountRequest] = 0x710003,
[Zone_Packet_Kind_Mount_DismountResponse] = 0x710004,
[Zone_Packet_Kind_Mount_MountList] = 0x710005,
[Zone_Packet_Kind_Mount_MountSpawn] = 0x710006,
[Zone_Packet_Kind_Mount_MountDespawn] = 0x710007,
[Zone_Packet_Kind_Mount_MountSpawnByItemDefinitionId] = 0x710008,
[Zone_Packet_Kind_Mount_MountOfferUpsell] = 0x710009,
[Zone_Packet_Kind_Mount_SeatChangeRequest] = 0x71000a,
[Zone_Packet_Kind_Mount_SeatChangeResponse] = 0x71000b,
[Zone_Packet_Kind_Mount_SeatSwapRequest] = 0x71000c,
[Zone_Packet_Kind_Mount_SeatSwapResponse] = 0x71000d,
[Zone_Packet_Kind_Mount_MountPacketTypeCount] = 0x71000f,
[Zone_Packet_Kind_Mount_FlipMount] = 0x71000e,
[Zone_Packet_Kind_ClientInitializationDetails] = 0x72,
[Zone_Packet_Kind_ClientAreaTimer] = 0x73,
[Zone_Packet_Kind_LoyaltyRewardBase] = 0x740000,
[Zone_Packet_Kind_RatingBase] = 0x750000,
[Zone_Packet_Kind_ClientActivityLaunchBase] = 0x760000,
[Zone_Packet_Kind_ServerActivityLaunchBase] = 0x770000,
[Zone_Packet_Kind_ClientFlashTimer] = 0x78,
[Zone_Packet_Kind_PlayerUpdatePosition] = 0x79,
[Zone_Packet_Kind_InviteAndStartMiniGame] = 0x7a,
[Zone_Packet_Kind_QuizBase] = 0x7b,
[Zone_Packet_Kind_PlayerUpdatePositionOnPlatform] = 0x7c,
[Zone_Packet_Kind_ClientMembershipVipInfo] = 0x7d,
[Zone_Packet_Kind_TargetBase] = 0x7e0000,
[Zone_Packet_Kind_GuideStoneBase] = 0x80,
[Zone_Packet_Kind_RaidsBase] = 0x810000,
[Zone_Packet_Kind_VoiceBase] = 0x820000,
[Zone_Packet_Kind_WeaponBase] = 0x830000,
[Zone_Packet_Kind_MatchScheduleBase] = 0x84,
[Zone_Packet_Kind_FacilityBase] = 0x850000,
[Zone_Packet_Kind_Facility_ReferenceData] = 0x850001,
[Zone_Packet_Kind_Facility_FacilityData] = 0x850002,
[Zone_Packet_Kind_Facility_CurrentFacilityUpdate] = 0x850003,
[Zone_Packet_Kind_Facility_SpawnDataRequest] = 0x850004,
[Zone_Packet_Kind_Facility_FacilitySpawnData] = 0x850005,
[Zone_Packet_Kind_Facility_FacilityUpdate] = 0x850006,
[Zone_Packet_Kind_Facility_FacilitySpawnStatus] = 0x850007,
[Zone_Packet_Kind_Facility_FacilitySpawnStatusTracked] = 0x850008,
[Zone_Packet_Kind_Facility_NotificationFacilityCaptured] = 0x850009,
[Zone_Packet_Kind_Facility_NotificationFacilitySignificantCaptureProgress] = 0x85000a,
[Zone_Packet_Kind_Facility_NotificationFacilityCloseToCapture] = 0x85000b,
[Zone_Packet_Kind_Facility_NotificationFacilitySpawnBeginCapture] = 0x85000c,
[Zone_Packet_Kind_Facility_NotificationFacilitySpawnFinishCapture] = 0x85000d,
[Zone_Packet_Kind_Facility_NotificationLeavingFacilityDuringContention] = 0x85000e,
[Zone_Packet_Kind_Facility_ProximitySpawnCaptureUpdate] = 0x85000f,
[Zone_Packet_Kind_Facility_ClearProximitySpawn] = 0x850010,
[Zone_Packet_Kind_Facility_GridStabilizeTimerUpdated] = 0x850011,
[Zone_Packet_Kind_Facility_SpawnCollisionChanged] = 0x850012,
[Zone_Packet_Kind_Facility_NotificationFacilitySecondaryObjectiveEventPacket] = 0x850013,
[Zone_Packet_Kind_Facility_PenetrateShieldEffect] = 0x850014,
[Zone_Packet_Kind_Facility_SpawnUpdateGuid] = 0x850015,
[Zone_Packet_Kind_Facility_FacilityUpdateRequest] = 0x850016,
[Zone_Packet_Kind_Facility_EmpireScoreValueUpdate] = 0x850017,
[Zone_Packet_Kind_SkillsBase] = 0x860000,
[Zone_Packet_Kind_LoadoutsBase] = 0x870000,
[Zone_Packet_Kind_ExperienceBase] = 0x880000,
[Zone_Packet_Kind_VehicleBase] = 0x890000,
[Zone_Packet_Kind_Vehicle_Owner] = 0x890001,
[Zone_Packet_Kind_Vehicle_Occupy] = 0x890002,
[Zone_Packet_Kind_Vehicle_StateData] = 0x890003,
[Zone_Packet_Kind_Vehicle_StateDamage] = 0x890004,
[Zone_Packet_Kind_Vehicle_PlayerManager] = 0x890005,
[Zone_Packet_Kind_Vehicle_Spawn] = 0x890006,
[Zone_Packet_Kind_Vehicle_Tint] = 0x890007,
[Zone_Packet_Kind_Vehicle_LoadVehicleTerminalDefinitionManager] = 0x890008,
[Zone_Packet_Kind_Vehicle_ActiveWeapon] = 0x890009,
[Zone_Packet_Kind_Vehicle_Stats] = 0x89000a,
[Zone_Packet_Kind_Vehicle_DamageInfo] = 0x89000b,
[Zone_Packet_Kind_Vehicle_StatUpdate] = 0x89000c,
[Zone_Packet_Kind_Vehicle_UpdateWeapon] = 0x89000d,
[Zone_Packet_Kind_Vehicle_RemovedFromQueue] = 0x89000e,
[Zone_Packet_Kind_Vehicle_UpdateQueuePosition] = 0x89000f,
[Zone_Packet_Kind_Vehicle_PadDestroyNotify] = 0x890010,
[Zone_Packet_Kind_Vehicle_SetAutoDrive] = 0x890011,
[Zone_Packet_Kind_Vehicle_LockOnInfo] = 0x890012,
[Zone_Packet_Kind_Vehicle_LockOnState] = 0x890013,
[Zone_Packet_Kind_Vehicle_TrackingState] = 0x890014,
[Zone_Packet_Kind_Vehicle_CounterMeasureState] = 0x890015,
[Zone_Packet_Kind_Vehicle_LoadVehicleDefinitionManager] = 0x890016,
[Zone_Packet_Kind_Vehicle_AcquireState] = 0x890017,
[Zone_Packet_Kind_Vehicle_Dismiss] = 0x890018,
[Zone_Packet_Kind_Vehicle_AutoMount] = 0x890019,
[Zone_Packet_Kind_Vehicle_Deploy] = 0x89001a,
[Zone_Packet_Kind_Vehicle_Engine] = 0x89001b,
[Zone_Packet_Kind_Vehicle_AccessType] = 0x89001c,
[Zone_Packet_Kind_Vehicle_KickPlayer] = 0x89001d,
[Zone_Packet_Kind_Vehicle_HealthUpdateOwner] = 0x89001e,
[Zone_Packet_Kind_Vehicle_OwnerPassengerList] = 0x89001f,
[Zone_Packet_Kind_Vehicle_KickPacket] = 0x890020,
[Zone_Packet_Kind_Vehicle_NoAccessPacket] = 0x890021,
[Zone_Packet_Kind_Vehicle_ExpirationPacket] = 0x890022,
[Zone_Packet_Kind_Vehicle_GroupPacket] = 0x890023,
[Zone_Packet_Kind_Vehicle_DeployResponsePacket] = 0x890024,
[Zone_Packet_Kind_Vehicle_ExitPoints] = 0x890025,
[Zone_Packet_Kind_Vehicle_ControllerLogOut] = 0x890026,
[Zone_Packet_Kind_Vehicle_CurrentMoveMode] = 0x890027,
[Zone_Packet_Kind_Vehicle_ItemDefinitionRequest] = 0x890028,
[Zone_Packet_Kind_Vehicle_ItemDefinitionReply] = 0x890029,
[Zone_Packet_Kind_Vehicle_InventoryItems] = 0x89002a,
[Zone_Packet_Kind_GriefBase] = 0x8a,
[Zone_Packet_Kind_SpotPlayer] = 0x8b,
[Zone_Packet_Kind_FactionsBase] = 0x8c,
[Zone_Packet_Kind_Synchronization] = 0x8d,
[Zone_Packet_Kind_ResourceEventBase] = 0x8e,
[Zone_Packet_Kind_CollisionBase] = 0x8f,
[Zone_Packet_Kind_LeaderboardBase] = 0x90,
[Zone_Packet_Kind_PlayerUpdateManagedPosition] = 0x91,
[Zone_Packet_Kind_PlayerUpdateVehicleWeapon] = 0x93,
[Zone_Packet_Kind_ProfileStatsBase] = 0x94,
[Zone_Packet_Kind_EquipmentSetCharacterEquipment] = 0x950001,
[Zone_Packet_Kind_DefinitionFiltersBase] = 0x96,
[Zone_Packet_Kind_ContinentBattleInfo] = 0x97,
[Zone_Packet_Kind_SendSecurityPacketAndSelfDestruct] = 0x99,
[Zone_Packet_Kind_GetContinentBattleInfo] = 0x98,
[Zone_Packet_Kind_GetRespawnLocations] = 0x9a,
[Zone_Packet_Kind_WallOfDataBase] = 0x9b0000,
[Zone_Packet_Kind_WallOfData_UIEvent] = 0x9b0005,
[Zone_Packet_Kind_WallOfData_ClientSystemInfo] = 0x9b0006,
[Zone_Packet_Kind_WallOfData_VoiceChatEvent] = 0x9b0007,
[Zone_Packet_Kind_WallOfData_NudgeEvent] = 0x9b0009,
[Zone_Packet_Kind_WallOfData_LaunchPadFingerprint] = 0x9b000a,
[Zone_Packet_Kind_WallOfData_VideoCapture] = 0x9b000b,
[Zone_Packet_Kind_WallOfData_ClientTransition] = 0x9b000c,
[Zone_Packet_Kind_ImplantsBase] = 0x9c0000,
[Zone_Packet_Kind_InGamePurchase] = 0x9d,
[Zone_Packet_Kind_MissionsBase] = 0x9e0000,
[Zone_Packet_Kind_EffectsBase] = 0x9f0000,
[Zone_Packet_Kind_RewardBuffsBase] = 0xa00000,
[Zone_Packet_Kind_AbilitiesBase] = 0xa10000,
[Zone_Packet_Kind_DeployableBase] = 0xa20000,
[Zone_Packet_Kind_Security] = 0xa3,
[Zone_Packet_Kind_MapRegionBase] = 0xa4,
[Zone_Packet_Kind_HudManagerBase] = 0xa5,
[Zone_Packet_Kind_AcquireTimersBase] = 0xa6,
[Zone_Packet_Kind_LoginBase] = 0xa7,
[Zone_Packet_Kind_ServerPopulationInfo] = 0xa8,
[Zone_Packet_Kind_GetServerPopulationInfo] = 0xa9,
[Zone_Packet_Kind_PlayerUpdateVehicleCollision] = 0xaa,
[Zone_Packet_Kind_PlayerStop] = 0xab,
[Zone_Packet_Kind_CurrencyBase] = 0xac,
[Zone_Packet_Kind_ItemsBase] = 0xad,
[Zone_Packet_Kind_PlayerUpdateAttachObject] = 0xae,
[Zone_Packet_Kind_PlayerUpdateDetachObject] = 0xaf,
[Zone_Packet_Kind_ClientSettings] = 0xb0,
[Zone_Packet_Kind_RewardBuffInfo] = 0xb1,
[Zone_Packet_Kind_GetRewardBuffInfo] = 0xb2,
[Zone_Packet_Kind_CaisBase] = 0xb3,
[Zone_Packet_Kind_ZoneSettingBase] = 0xb4,
[Zone_Packet_Kind_RequestPromoEligibilityUpdate] = 0xb5,
[Zone_Packet_Kind_PromoEligibilityReply] = 0xb6,
[Zone_Packet_Kind_MetaGameEventBase] = 0xb7,
[Zone_Packet_Kind_RequestWalletTopupUpdate] = 0xb8,
[Zone_Packet_Kind_StationCashActivePromoRequestUpdate] = 0xb9,
[Zone_Packet_Kind_OperationBase] = 0xbc,
[Zone_Packet_Kind_WordFilterBase] = 0xbd,
[Zone_Packet_Kind_StaticFacilityInfoBase] = 0xbe,
[Zone_Packet_Kind_FacilityInfo_Request] = 0xbe0001,
[Zone_Packet_Kind_FacilityInfo_Reply] = 0xbe0002,
[Zone_Packet_Kind_FacilityInfo_AllZones] = 0xbe0003,
[Zone_Packet_Kind_ProxiedPlayerBase] = 0xbf,
[Zone_Packet_Kind_ResistsBase] = 0xc0,
[Zone_Packet_Kind_InGamePurchasingBase] = 0xc1,
[Zone_Packet_Kind_BusinessEnvironments] = 0xc2,
[Zone_Packet_Kind_EmpireScorePacketBase] = 0xc3,
[Zone_Packet_Kind_CharacterSelectSessionRequest] = 0xc4,
[Zone_Packet_Kind_CharacterSelectSessionResponse] = 0xc5,
[Zone_Packet_Kind_StatsBase] = 0xc6,
[Zone_Packet_Kind_ScoreBase] = 0xc7,
[Zone_Packet_Kind_ResourcesBase] = 0xc8,
[Zone_Packet_Kind_ConstructionBase] = 0xca,
[Zone_Packet_Kind_UpdateWeatherData] = 0xcb,
[Zone_Packet_Kind_NavGenBase] = 0xcc,
[Zone_Packet_Kind_LocksBase] = 0xcd,
[Zone_Packet_Kind_RagdollBase] = 0xce,
[Zone_Packet_Kind_CharacterStateBase] = 0xd0,
[Zone_Packet_Kind_TimedGrantBase] = 0xd1,
[Zone_Packet_Kind_WeatherBase] = 0xd2,
[Zone_Packet_Kind_GameEscrowBase] = 0xd3,
[Zone_Packet_Kind_PlayCompositeEffect] = 0xd4,
[Zone_Packet_Kind_SetSpotted] = 0xd5,
[Zone_Packet_Kind_AddLightweightPc] = 0xd6,
[Zone_Packet_Kind_AddLightweightNpc] = 0xd7,
[Zone_Packet_Kind_AddLightweightVehicle] = 0xd8,
[Zone_Packet_Kind_AddProxiedObject] = 0xd9,
[Zone_Packet_Kind_AddSimpleNpc] = 0x92,
[Zone_Packet_Kind_LightweightToFullPc] = 0xda,
[Zone_Packet_Kind_LightweightToFullNpc] = 0xdb,
[Zone_Packet_Kind_LightweightToFullVehicle] = 0xdc,
[Zone_Packet_Kind_CheckLocalValues] = 0xde,
[Zone_Packet_Kind_ChronicleBase] = 0xdf,
[Zone_Packet_Kind_GrinderBase] = 0xe0,
[Zone_Packet_Kind_RequestObject] = 0xe1,
[Zone_Packet_Kind_ScreenEffectBase] = 0xe2,
[Zone_Packet_Kind_SpectatorBase] = 0xe3,
[Zone_Packet_Kind_WhitelistBase] = 0xe4,
[Zone_Packet_Kind_NpcFoundationPermissionsManagerBase] = 0xe5,
[Zone_Packet_Kind_BattlEyeData] = 0xe6,
[Zone_Packet_Kind_OnlineIdBase] = 0xe7,
[Zone_Packet_Kind_Ps4PlayGoBase] = 0xe8,
[Zone_Packet_Kind_SynchronizedTeleportBase] = 0xe9,
[Zone_Packet_Kind_StaticViewBase] = 0xea,
[Zone_Packet_Kind_ReplicationBase] = 0xeb,
[Zone_Packet_Kind_DatasheetsBase] = 0xec,
[Zone_Packet_Kind_PlayerWorldTransferRequest] = 0xed,
[Zone_Packet_Kind_PlayerWorldTransferReply] = 0xee,
[Zone_Packet_Kind_CancelQueueOnWorld] = 0xef,
[Zone_Packet_Kind_DeclineEnterGameOnWorld] = 0xf0,
[Zone_Packet_Kind_AccessedCharacterBase] = 0xf1,
[Zone_Packet_Kind_ShaderParameterOverrideBase] = 0xf2,
[Zone_Packet_Kind_VehicleSkinBase] = 0xf3,
[Zone_Packet_Kind_WeaponLagLockParameters] = 0xf5,
[Zone_Packet_Kind_CrateOpeningBase] = 0xf6,
[Zone_Packet_Kind_PlayerHeatWarning] = 0xf7,
[Zone_Packet_Kind_AnimationBase] = 0xf8,
};


typedef struct Zone_Packet_Chat_Chat Zone_Packet_Chat_Chat;
struct Zone_Packet_Chat_Chat
{
u16 unk_u16;
u16 channel;
u64 character_id;
u64 character_id2;
u32 unk_u32;
u32 unk_u32_2;
u32 unk_u32_3;
u32 character_first_name_length;
char* character_first_name;
u32 character_last_name_length;
char* character_last_name;
u32 unk_string_length;
char* unk_string;
u32 character_name_length;
char* character_name;
u64 unk_u64;
u32 unk_u32_4;
u32 unk_u32_5;
u32 unk_u32_6;
u32 character_first_name_2_length;
char* character_first_name_2;
u32 character_last_name_2_length;
char* character_last_name_2;
u32 unk_string_2_length;
char* unk_string_2;
u32 character_name_2_length;
char* character_name_2;
u64 unk_u64_2;
u32 message_length;
char* message;
vec4 position;
u64 unk_guid;
u32 unk_u32_7;
u32 color_1;
u32 color_2;
u8 unk_u8;
u8 unk_u8_2;
};


typedef struct Zone_Packet_Chat_ChatText Zone_Packet_Chat_ChatText;
struct Zone_Packet_Chat_ChatText
{
u32 message_length;
char* message;
u32 unk_u32;
u32 color;
u32 unk_u32_2;
u8 unk_u8;
u8 unk_u8_2;
};


typedef struct Zone_Packet_CommandItemDefinitionRequest Zone_Packet_CommandItemDefinitionRequest;
struct Zone_Packet_CommandItemDefinitionRequest
{
u32 id;
};


typedef struct Zone_Packet_CommandItemDefinitionReply Zone_Packet_CommandItemDefinitionReply;
struct Zone_Packet_CommandItemDefinitionReply
{
u32 item_def_reply_1_length;
struct item_def_reply_1_s
{
u8 bitflags1;
u8 bitflags2;
u32 name_id;
u32 description_id;
u32 content_id;
u32 image_set_id;
u32 tint_id;
u32 hud_image_set_id;
u32 unk_dword_1;
u32 unk_dword_2;
u32 cost;
u32 item_class;
u32 profile_override;
u32 model_name_length;
char* model_name;
u32 texture_alias_length;
char* texture_alias;
u32 gender_usage;
u32 item_type;
u32 category_id;
u32 weapon_trail_effect_id;
u32 composite_effect_id;
u32 power_rating;
u32 min_profile_rank;
u32 rarity;
u32 activatable_ability_id;
u32 activatable_ability_set_id;
u32 passive_ability_id;
u32 passive_ability_set_id;
u32 max_stack_size;
u32 min_stack_size;
u32 tint_alias_length;
char* tint_alias;
u32 tint_group_id;
u32 member_discount;
u32 vip_rank_required;
u32 race_set_id;
u32 ui_model_camera_id_1;
u32 equip_count_max;
i32 curreny_type;
u32 datasheet_id;
u32 item_type_1;
u32 skill_set_id;
u32 overlay_texture_length;
char* overlay_texture;
u32 decal_slot_length;
char* decal_slot;
u32 overlay_adjustment;
u32 trial_duration_sec;
u32 next_trial_delay_sec;
u32 client_use_requirement;
u32 override_appearance_length;
char* override_appearance;
u32 override_camera_id;
u32 unk_dword_3;
u32 unk_dword_4;
u32 unk_dword_5;
u32 bulk;
u32 active_equip_slot_id;
u32 passive_equip_slot_id;
u32 passive_equip_slot_group_id;
u32 unk_dword_6;
u32 grinder_reward_set_id;
u32 build_bar_group_id;
u32 unk_string_1_length;
char* unk_string_1;
b8 unk_bool_1;
b8 is_armor;
u32 unk_dword_7;
u32 param1;
u32 param2;
u32 param3;
u32 string_param1_length;
char* string_param1;
u32 ui_model_camera_id_2;
u32 unk_dword_8;
i32 scrap_value_override;
u32 stats_item_def_1_count;
struct stats_item_def_1_s
{
u32 unk_dword_9;
u32 stat_id;
f32 base;
f32 modifier;
u32 unk_dword_10;
}* stats_item_def_1;
}* item_def_reply_1;
};


typedef struct Zone_Packet_CommandItemDefinitions Zone_Packet_CommandItemDefinitions;
struct Zone_Packet_CommandItemDefinitions
{
u32 item_def_reply_2_length;
struct item_def_reply_2_s
{
u32 item_defs_count;
struct item_defs_s
{
u32 defs_id;
u8 bitflags1;
u8 bitflags2;
u32 name_id;
u32 description_id;
u32 content_id;
u32 image_set_id;
u32 tint_id;
u32 hud_image_set_id;
u32 unk_dword_1;
u32 unk_dword_2;
u32 cost;
u32 item_class;
u32 profile_override;
u32 model_name_length;
char* model_name;
u32 texture_alias_length;
char* texture_alias;
u32 gender_usage;
u32 item_type;
u32 category_id;
u32 weapon_trail_effect_id;
u32 composite_effect_id;
u32 power_rating;
u32 min_profile_rank;
u32 rarity;
u32 activatable_ability_id;
u32 activatable_ability_set_id;
u32 passive_ability_id;
u32 passive_ability_set_id;
u32 max_stack_size;
u32 min_stack_size;
u32 tint_alias_length;
char* tint_alias;
u32 tint_group_id;
u32 member_discount;
u32 vip_rank_required;
u32 race_set_id;
u32 ui_model_camera_id_1;
u32 equip_count_max;
i32 curreny_type;
u32 datasheet_id;
u32 item_type_1;
u32 skill_set_id;
u32 overlay_texture_length;
char* overlay_texture;
u32 decal_slot_length;
char* decal_slot;
u32 overlay_adjustment;
u32 trial_duration_sec;
u32 next_trial_delay_sec;
u32 client_use_requirement;
u32 override_appearance_length;
char* override_appearance;
u32 override_camera_id;
u32 unk_dword_3;
u32 unk_dword_4;
u32 unk_dword_5;
u32 bulk;
u32 active_equip_slot_id;
u32 passive_equip_slot_id;
u32 passive_equip_slot_group_id;
u32 unk_dword_6;
u32 grinder_reward_set_id;
u32 build_bar_group_id;
u32 unk_string_1_length;
char* unk_string_1;
b8 unk_bool_1;
b8 is_armor;
u32 unk_dword_7;
u32 param1;
u32 param2;
u32 param3;
u32 string_param1_length;
char* string_param1;
u32 ui_model_camera_id_2;
u32 unk_dword_8;
i32 scrap_value_override;
u32 stats_item_def_2_count;
struct stats_item_def_2_s
{
u32 unk_dword_9;
u32 stat_id;
u32 base;
u32 modifier;
u32 unk_dword_10;
}* stats_item_def_2;
}* item_defs;
}* item_def_reply_2;
};


typedef struct Zone_Packet_Character_RemovePlayer Zone_Packet_Character_RemovePlayer;
struct Zone_Packet_Character_RemovePlayer
{
u64 character_id;
u16 unk_u16;
u8 unk_u8;
u32 unk_u32;
u32 effect_delay;
u32 effect_id;
u32 sticky_effect_id;
u32 time_to_disappear;
};


typedef struct Zone_Packet_Character_UpdateScale Zone_Packet_Character_UpdateScale;
struct Zone_Packet_Character_UpdateScale
{
u64 character_id;
vec4 scale;
};


typedef struct Zone_Packet_Character_WeaponStance Zone_Packet_Character_WeaponStance;
struct Zone_Packet_Character_WeaponStance
{
u64 character_id;
u32 stance;
};


typedef struct Zone_Packet_Character_CharacterStateDelta Zone_Packet_Character_CharacterStateDelta;
struct Zone_Packet_Character_CharacterStateDelta
{
u64 guid_1;
u64 guid_2;
u64 guid_3;
u64 guid_4;
u32 game_time;
};


typedef struct Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters;
struct Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters
{
b8 is_done;
};


typedef struct Zone_Packet_ClientUpdate_TextAlert Zone_Packet_ClientUpdate_TextAlert;
struct Zone_Packet_ClientUpdate_TextAlert
{
u32 message_length;
char* message;
};


typedef struct Zone_Packet_ClientUpdate_MonitorTimeDrift Zone_Packet_ClientUpdate_MonitorTimeDrift;
struct Zone_Packet_ClientUpdate_MonitorTimeDrift
{
u32 time_drift;
};


typedef struct Zone_Packet_SendZoneDetails Zone_Packet_SendZoneDetails;
struct Zone_Packet_SendZoneDetails
{
u32 zone_name_length;
char* zone_name;
u32 zone_type;
u8 unk_bool;
f32 unknownDword1;
f32 fog_density;
f32 fog_floor;
f32 fog_gradient;
f32 rain;
f32 temp;
f32 color_gradient;
f32 unknown_dword8;
f32 unknown_dword9;
f32 unknown_dword10;
f32 unknown_dword11;
f32 unknown_dword12;
f32 sun_axis_x;
f32 sun_axis_y;
f32 unknown_dword15;
f32 disable_trees;
f32 disable_trees1;
f32 disable_trees2;
f32 wind;
f32 unknown_dword20;
f32 unknown_dword21;
u32 name_length;
char* name;
f32 unknown_dword22;
f32 unknown_dword23;
f32 unknown_dword24;
f32 unknown_dword25;
f32 unknown_dword26;
f32 unknown_dword27;
f32 unknown_dword28;
f32 unknown_dword29;
f32 ao_size;
f32 ao_gamma;
f32 ao_blackpoint;
f32 unknown_dword33;
u32 zone_id;
u32 zone_id_2;
u32 name_id;
u8 unk_bool2;
u32 lighting_length;
char* lighting;
u8 unk_bool3;
};


typedef struct Zone_Packet_ReferenceDataWeaponDefinitions Zone_Packet_ReferenceDataWeaponDefinitions;
struct Zone_Packet_ReferenceDataWeaponDefinitions
{
u32 weapon_byteswithlength_length;
struct weapon_byteswithlength_s
{
u32 weapon_defs_count;
struct weapon_defs_s
{
u32 id1;
u32 id2;
u32 weapon_group_id;
u8 flags1;
u32 equip_ms;
u32 unequip_ms;
u32 from_passive_ms;
u32 to_passive_ms;
u32 xp_category;
u32 to_iron_sights_ms;
u32 from_iron_sights_ms;
u32 to_iron_sights_anim_ms;
u32 from_iron_sights_anim_ms;
u32 sprint_recovery_ms;
u32 next_use_delay_msec;
f32 turn_rate_modifier;
f32 movement_speed_modifier;
u32 propulsion_type;
u32 heat_bleed_off_rate;
u32 heat_capacity;
u32 overheat_penalty_ms;
u32 range_string_id;
u32 melee_detect_width;
u32 melee_detect_height;
u32 anim_set_name_length;
char* anim_set_name;
u32 vehicle_fp_camera_id;
u32 vehicle_tp_camera_id;
u32 overheat_effect_id;
f32 min_pitch;
f32 max_pitch;
u32 audio_game_object;
u32 ammo_slots_count;
struct ammo_slots_s
{
u32 ammo_id;
u32 clip_size;
u32 capacity;
b8 start_empty;
u32 refill_ammo_per_tick;
u32 refill_ammo_delay_ms;
u32 clip_attachment_slot;
u32 clip_model_name_length;
char* clip_model_name;
u32 reload_weapon_bone_length;
char* reload_weapon_bone;
u32 reload_character_bone_length;
char* reload_character_bone;
}* ammo_slots;
u32 fire_groups_count;
struct fire_groups_s
{
u32 fire_group_id;
}* fire_groups;
}* weapon_defs;
u32 fire_group_defs_count;
struct fire_group_defs_s
{
u32 id3;
u32 id4;
u32 fire_mode_list_count;
struct fire_mode_list_s
{
u32 fire_mode_1;
}* fire_mode_list;
u8 flags2;
u32 chamber_duration_ms;
u32 image_set_override;
u32 transition_duration_ms;
u32 anim_actor_slot_override;
u32 deployable_id;
u32 spin_up_time_ms;
u32 spin_up_movement_modifier;
u32 spin_up_turn_rate_modifier;
u32 spool_up_time_ms;
u32 spool_up_initial_refire_ms;
}* fire_group_defs;
u32 fire_mode_defs_count;
struct fire_mode_defs_s
{
u32 id5;
u32 id6;
u8 flag1;
u8 flag2;
u8 flag3;
u8 type;
u32 ammo_item_id;
u8 ammo_slot;
u8 burst_count;
u16 fire_duration_ms;
u16 fire_cooldown_duration_ms;
u16 refire_time_ms;
u16 auto_fire_time_ms;
u16 cook_time_ms;
f32 range;
u8 ammo_per_shot;
u16 reload_time_ms;
u16 reload_chamber_time_ms;
u16 reload_ammo_fill_time_ms;
u16 reload_loop_start_time_ms;
u16 reload_loop_end_time_ms;
u8 pellets_per_shot;
f32 pellet_spread;
f32 cof_recoil;
f32 cof_scalar;
f32 cof_scalar_moving;
f32 cof_override;
f32 recoil_angle_min;
f32 recoil_angle_max;
f32 recoil_horizontal_tolerance;
f32 recoil_horizontal_min;
f32 recoil_horizontal_max;
f32 recoil_magnitude_min;
f32 recoil_magnitude_max;
u16 recoil_recovery_delay_ms;
f32 recoil_recovery_rate;
f32 recoil_recovery_acceleration;
u8 recoil_shots_at_min_magnitude;
f32 recoil_max_total_magnitude;
f32 recoil_increase;
f32 recoil_increase_crouched;
f32 recoil_first_shot_modifier;
f32 recoil_horizontal_min_increase;
f32 recoil_horizontal_max_increase;
u16 fire_detect_range;
f32 effect_group;
f32 player_state_group_id;
f32 movement_modifier;
f32 turn_modifier;
f32 lock_on_icon_id;
f32 lock_on_angle;
f32 lock_on_radius;
f32 lock_on_range;
f32 lock_on_range_close;
f32 lock_on_range_far;
u16 lock_on_acquire_time_ms;
u16 lock_on_acquire_time_close_ms;
u16 lock_on_acquire_time_far_ms;
u16 lock_on_lose_time_ms;
f32 default_zoom;
f32 fp_offset_x;
f32 fp_offset_y;
f32 fp_offset_z;
u8 reticle_id;
u8 full_screen_effect;
u32 heat_per_shot;
u32 heat_threshold;
u16 heat_recovery_delay_ms;
f32 sway_amplitude_x;
f32 sway_amplitude_y;
f32 sway_period_x;
f32 sway_period_y;
f32 sway_initial_y_offset;
f32 arms_fov_scalar;
f32 anim_kick_magnitude;
f32 anim_recoil_magnitude;
u32 description_id;
u32 indirect_effect;
f32 bullet_arc_kick_angle;
f32 projectile_speed_override;
u32 inherit_from_id;
f32 inherit_from_charge_power;
u32 hud_image_id;
u32 target_requirement;
u32 fire_anim_duration_ms;
u8 sequential_fire_anim_start;
u8 sequential_fire_anim_count;
f32 cylof_recoil;
f32 cylof_scalar;
f32 cylof_scalar_moving;
f32 cylof_override;
u32 melee_composite_effect_id;
u32 melee_ability_id;
f32 sway_crouch_scalar;
f32 sway_prone_scalar;
f32 launch_pitch_additive_degrees;
b8 tp_force_camera_overrides;
f32 tp_camera_look_offset_x;
f32 tp_camera_look_offset_y;
f32 tp_camera_look_offset_z;
f32 tp_camera_position_offset_x;
f32 tp_camera_position_offset_y;
f32 tp_camera_position_offset_z;
f32 tp_camera_fov;
b8 fp_force_camera_overrides;
f32 tp_extra_lead_from_pitch_a;
f32 tp_extra_lead_from_pitch_b;
f32 tp_extra_lead_pitch_a;
f32 tp_extra_lead_pitch_b;
f32 tp_extra_height_from_pitch_a;
f32 tp_extra_height_from_pitch_b;
f32 tp_extra_height_pitch_a;
f32 tp_extra_height_pitch_b;
f32 fp_camera_fov;
f32 tp_cr_camera_look_offset_x;
f32 tp_cr_camera_look_offset_y;
f32 tp_cr_camera_look_offset_z;
f32 tp_cr_camera_position_offset_x;
f32 tp_cr_camera_position_offset_y;
f32 tp_cr_camera_position_offset_z;
f32 tp_pr_camera_look_offset_x;
f32 tp_pr_camera_look_offset_y;
f32 tp_pr_camera_look_offset_z;
f32 tp_pr_camera_position_offset_x;
f32 tp_pr_camera_position_offset_y;
f32 tp_pr_camera_position_offset_z;
f32 tp_cr_extra_lead_from_pitch_a;
f32 tp_cr_extra_lead_from_pitch_b;
f32 tp_cr_extra_lead_pitch_a;
f32 tp_cr_extra_lead_pitch_b;
f32 tp_cr_extra_height_from_pitch_a;
f32 tp_cr_extra_height_from_pitch_b;
f32 tp_cr_extra_height_pitch_a;
f32 tp_cr_extra_height_pitch_b;
f32 tp_pr_extra_lead_from_pitch_a;
f32 tp_pr_extra_lead_from_pitch_b;
f32 tp_pr_extra_lead_pitch_a;
f32 tp_pr_extra_lead_pitch_b;
f32 tp_pr_extra_height_from_pitch_a;
f32 tp_pr_extra_height_from_pitch_b;
f32 tp_pr_extra_height_pitch_a;
f32 tp_pr_extra_height_pitch_b;
f32 tp_camera_distance;
f32 tp_cr_camera_distance;
f32 tp_pr_camera_distance;
f32 tp_cr_camera_fov;
f32 tp_pr_camera_fov;
f32 fp_cr_camera_fov;
f32 fp_pr_camera_fov;
b8 force_fp_scope;
u32 aim_assist_config;
b8 allow_depth_adjustment;
f32 tp_extra_draw_from_pitch_a;
f32 tp_extra_draw_from_pitch_b;
f32 tp_extra_draw_pitch_a;
f32 tp_extra_draw_pitch_b;
f32 tp_cr_extra_draw_from_pitch_a;
f32 tp_cr_extra_draw_from_pitch_b;
f32 tp_cr_extra_draw_pitch_a;
f32 tp_cr_extra_draw_pitch_b;
f32 tp_camera_pos_offset_y_mov;
f32 tp_camera_look_offset_y_mov;
f32 tp_cr_camera_pos_offset_y_mov;
f32 tp_cr_camera_look_offset_y_mov;
b8 tp_allow_move_heights;
}* fire_mode_defs;
u32 player_state_group_defs_count;
struct player_state_group_defs_s
{
u32 id7;
u32 _id8;
u32 player_state_properties_count;
struct player_state_properties_s
{
u32 group_id;
u32 id9;
u8 flags3;
f32 min_cof;
f32 max_cof;
f32 cof_recovery_rate;
f32 cof_turn_penalty;
u32 shots_before_cof_penalty;
f32 cof_recovery_delay_threshold;
u32 cof_recovery_delay_ms;
f32 cof_grow_rate;
f32 min_cyl_of_fire;
f32 max_cyl_of_fire;
f32 cylof_recovery_rate;
f32 cylof_turn_penalty;
u32 shots_before_cylof_penalty;
f32 cylof_recovery_delay_threshold;
u32 cylof_recovery_delay_ms;
f32 cylof_grow_rate;
}* player_state_properties;
}* player_state_group_defs;
u32 fire_mode_projectile_mapping_data_count;
struct fire_mode_projectile_mapping_data_s
{
u32 id10;
u32 id11;
u32 index;
u32 projectile_definition_id;
}* fire_mode_projectile_mapping_data;
u32 aim_assist_defs_count;
struct aim_assist_defs_s
{
u32 id12;
f32 cone_angle;
f32 cone_range;
f32 fall_off_cone_range;
f32 magnet_cone_angle;
f32 magnet_cone_range;
f32 target_override_delay;
f32 target_oos_delay;
f32 arrive_time;
f32 target_motion_update_time;
f32 weight;
f32 min_input_weight_delay_in;
f32 max_input_weight_delay_in;
f32 min_input_weight_delay_out;
f32 max_input_weight_delay_out;
f32 min_input_actor;
f32 max_input_actor;
u32 requirement_id;
f32 magnet_min_angle;
f32 magnet_dist_for_min_angle;
f32 magnet_max_angle;
f32 magnet_dist_for_max_angle;
f32 min_input_strafe_arrive_time;
f32 max_input_strafe_arrive_time;
}* aim_assist_defs;
}* weapon_byteswithlength;
};


typedef struct Zone_Packet_GameTimeSync Zone_Packet_GameTimeSync;
struct Zone_Packet_GameTimeSync
{
u64 time;
f32 cycle_speed;
b8 unk_bool;
};


typedef struct Zone_Packet_SetLocale Zone_Packet_SetLocale;
struct Zone_Packet_SetLocale
{
u32 locale_length;
char* locale;
};


typedef struct Zone_Packet_KeepAlive Zone_Packet_KeepAlive;
struct Zone_Packet_KeepAlive
{
u32 game_time;
};


typedef struct Zone_Packet_ClientLog Zone_Packet_ClientLog;
struct Zone_Packet_ClientLog
{
u32 file_length;
char* file;
u32 message_length;
char* message;
};


typedef struct Zone_Packet_ClientGameSettings Zone_Packet_ClientGameSettings;
struct Zone_Packet_ClientGameSettings
{
u32 unk_u32;
u32 interact_glow_and_dist;
u8 unk_bool;
f32 timescale;
u32 enable_weapons;
u32 unk_u32_2;
f32 unk_float1;
f32 unk_float2;
f32 damage_multiplier;
};


typedef struct Zone_Packet_InitializationParameters Zone_Packet_InitializationParameters;
struct Zone_Packet_InitializationParameters
{
u32 environment_length;
char* environment;
u32 unk_string_1_length;
char* unk_string_1;
u32 ruleset_definitions_count;
struct ruleset_definitions_s
{
u32 unk_u32_1;
u32 unk_u32_2;
u32 ruleset_length;
char* ruleset;
u32 unk_string_2_length;
char* unk_string_2;
u32 rulesets_count;
struct rulesets_s
{
u32 ID;
u32 data_id;
u32 ruleset_id;
u32 content_pack_id;
u32 content_pack_action_id;
}* rulesets;
}* ruleset_definitions;
};


typedef struct Zone_Packet_ClientInitializationDetails Zone_Packet_ClientInitializationDetails;
struct Zone_Packet_ClientInitializationDetails
{
u32 unk_u32_1;
};


typedef struct Zone_Packet_Synchronization Zone_Packet_Synchronization;
struct Zone_Packet_Synchronization
{
u64 client_hours_ms;
u64 client_hours_ms2;
u64 client_time;
u64 server_time;
u64 unk_time;
};


typedef struct Zone_Packet_PlayerUpdateManagedPosition Zone_Packet_PlayerUpdateManagedPosition;
struct Zone_Packet_PlayerUpdateManagedPosition
{
uint2b transient_id;
};


typedef struct Zone_Packet_EquipmentSetCharacterEquipment Zone_Packet_EquipmentSetCharacterEquipment;
struct Zone_Packet_EquipmentSetCharacterEquipment
{
u32 profile_id;
u64 character_id;
u32 unk_dword_1;
u32 unk_string_1_length;
char* unk_string_1;
u32 unk_string_2_length;
char* unk_string_2;
u32 equipment_slot_array_count;
struct equipment_slot_array_s
{
u32 equipment_slot_id_1;
u32 equipment_slot_id_2;
u64 guid;
u32 tint_alias_length;
char* tint_alias;
u32 decal_alias_length;
char* decal_alias;
}* equipment_slot_array;
u32 attachments_data_1_count;
struct attachments_data_1_s
{
u32 model_name_length;
char* model_name;
u32 texture_alias_length;
char* texture_alias;
u32 tint_alias_length;
char* tint_alias;
u32 decal_alias_length;
char* decal_alias;
u32 unk_dword_1;
u32 unk_dword_2;
u32 effect_id;
u32 slot_id;
u32 unk_dword_3;
u32 unk_array_1337_count;
struct unk_array_1337_s
{
u32 unk_dword_4;
}* unk_array_1337;
b8 unk_bool_1;
}* attachments_data_1;
b8 unk_bool_2;
};


typedef struct Zone_Packet_WallOfData_UIEvent Zone_Packet_WallOfData_UIEvent;
struct Zone_Packet_WallOfData_UIEvent
{
u32 object_length;
char* object;
u32 function_length;
char* function;
u32 argument_length;
char* argument;
};


typedef struct Zone_Packet_WallOfData_ClientSystemInfo Zone_Packet_WallOfData_ClientSystemInfo;
struct Zone_Packet_WallOfData_ClientSystemInfo
{
u32 info_length;
char* info;
};


typedef struct Zone_Packet_WallOfData_ClientTransition Zone_Packet_WallOfData_ClientTransition;
struct Zone_Packet_WallOfData_ClientTransition
{
u32 old_state;
u32 new_state;
u32 ms_elapsed;
};


internal u32
zone_packet_pack(Zone_Packet_Kind packet_kind, void* packet_ptr, u8* buffer)
{
u32 offset = 0;

printf("\n");
switch(packet_kind)
{
case Zone_Packet_Kind_BaseServerPacket:
{
printf("[*] Packing BaseServerPacket...\n");
endian_write_u8_little(buffer + offset, 0x1);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientFinishedLoading:
{
printf("[*] Packing ClientFinishedLoading...\n");
endian_write_u8_little(buffer + offset, 0x2);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SendSelfToClient:
{
printf("[*] Packing SendSelfToClient...\n");
endian_write_u8_little(buffer + offset, 0x3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientIsReady:
{
printf("[*] Packing ClientIsReady...\n");
endian_write_u8_little(buffer + offset, 0x4);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ZoneDoneSendingInitialData:
{
printf("[*] Packing ZoneDoneSendingInitialData...\n");
endian_write_u8_little(buffer + offset, 0x5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ChatBase:
{
printf("[*] Packing ChatBase...\n");
endian_write_u8_little(buffer + offset, 0x6);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Chat_Chat:
{
printf("[*] Packing Chat_Chat...\n");
Zone_Packet_Chat_Chat* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x6);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

// u16 unk_u16
endian_write_u16_little(buffer + offset, packet->unk_u16);
offset += sizeof(u16);
printf("-- unk_u16                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u16, (u64)packet->unk_u16, (f64)packet->unk_u16);

// u16 channel
endian_write_u16_little(buffer + offset, packet->channel);
offset += sizeof(u16);
printf("-- channel                 \t%lld\t%llxh\t%f\n", (i64)packet->channel, (u64)packet->channel, (f64)packet->channel);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u64 character_id2
endian_write_u64_little(buffer + offset, packet->character_id2);
offset += sizeof(u64);
printf("-- character_id2           \t%lld\t%llxh\t%f\n", (i64)packet->character_id2, (u64)packet->character_id2, (f64)packet->character_id2);

// u32 unk_u32
endian_write_u32_little(buffer + offset, packet->unk_u32);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 unk_u32_2
endian_write_u32_little(buffer + offset, packet->unk_u32_2);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_2, (u64)packet->unk_u32_2, (f64)packet->unk_u32_2);

// u32 unk_u32_3
endian_write_u32_little(buffer + offset, packet->unk_u32_3);
offset += sizeof(u32);
printf("-- unk_u32_3               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_3, (u64)packet->unk_u32_3, (f64)packet->unk_u32_3);

// string character_first_name
endian_write_u32_little(buffer + offset, packet->character_first_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->character_first_name_length, (u64)packet->character_first_name_length, (f64)packet->character_first_name_length);
for (u32 character_first_name_iter = 0; character_first_name_iter < packet->character_first_name_length; character_first_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->character_first_name[character_first_name_iter]);
offset++;
}

// string character_last_name
endian_write_u32_little(buffer + offset, packet->character_last_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->character_last_name_length, (u64)packet->character_last_name_length, (f64)packet->character_last_name_length);
for (u32 character_last_name_iter = 0; character_last_name_iter < packet->character_last_name_length; character_last_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->character_last_name[character_last_name_iter]);
offset++;
}

// string unk_string
endian_write_u32_little(buffer + offset, packet->unk_string_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->unk_string_length, (u64)packet->unk_string_length, (f64)packet->unk_string_length);
for (u32 unk_string_iter = 0; unk_string_iter < packet->unk_string_length; unk_string_iter++)
{
endian_write_i8_little(buffer + offset, packet->unk_string[unk_string_iter]);
offset++;
}

// string character_name
endian_write_u32_little(buffer + offset, packet->character_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->character_name_length, (u64)packet->character_name_length, (f64)packet->character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->character_name_length; character_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->character_name[character_name_iter]);
offset++;
}

// u64 unk_u64
endian_write_u64_little(buffer + offset, packet->unk_u64);
offset += sizeof(u64);
printf("-- unk_u64                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u64, (u64)packet->unk_u64, (f64)packet->unk_u64);

// u32 unk_u32_4
endian_write_u32_little(buffer + offset, packet->unk_u32_4);
offset += sizeof(u32);
printf("-- unk_u32_4               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_4, (u64)packet->unk_u32_4, (f64)packet->unk_u32_4);

// u32 unk_u32_5
endian_write_u32_little(buffer + offset, packet->unk_u32_5);
offset += sizeof(u32);
printf("-- unk_u32_5               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_5, (u64)packet->unk_u32_5, (f64)packet->unk_u32_5);

// u32 unk_u32_6
endian_write_u32_little(buffer + offset, packet->unk_u32_6);
offset += sizeof(u32);
printf("-- unk_u32_6               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_6, (u64)packet->unk_u32_6, (f64)packet->unk_u32_6);

// string character_first_name_2
endian_write_u32_little(buffer + offset, packet->character_first_name_2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->character_first_name_2_length, (u64)packet->character_first_name_2_length, (f64)packet->character_first_name_2_length);
for (u32 character_first_name_2_iter = 0; character_first_name_2_iter < packet->character_first_name_2_length; character_first_name_2_iter++)
{
endian_write_i8_little(buffer + offset, packet->character_first_name_2[character_first_name_2_iter]);
offset++;
}

// string character_last_name_2
endian_write_u32_little(buffer + offset, packet->character_last_name_2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->character_last_name_2_length, (u64)packet->character_last_name_2_length, (f64)packet->character_last_name_2_length);
for (u32 character_last_name_2_iter = 0; character_last_name_2_iter < packet->character_last_name_2_length; character_last_name_2_iter++)
{
endian_write_i8_little(buffer + offset, packet->character_last_name_2[character_last_name_2_iter]);
offset++;
}

// string unk_string_2
endian_write_u32_little(buffer + offset, packet->unk_string_2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->unk_string_2_length, (u64)packet->unk_string_2_length, (f64)packet->unk_string_2_length);
for (u32 unk_string_2_iter = 0; unk_string_2_iter < packet->unk_string_2_length; unk_string_2_iter++)
{
endian_write_i8_little(buffer + offset, packet->unk_string_2[unk_string_2_iter]);
offset++;
}

// string character_name_2
endian_write_u32_little(buffer + offset, packet->character_name_2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->character_name_2_length, (u64)packet->character_name_2_length, (f64)packet->character_name_2_length);
for (u32 character_name_2_iter = 0; character_name_2_iter < packet->character_name_2_length; character_name_2_iter++)
{
endian_write_i8_little(buffer + offset, packet->character_name_2[character_name_2_iter]);
offset++;
}

// u64 unk_u64_2
endian_write_u64_little(buffer + offset, packet->unk_u64_2);
offset += sizeof(u64);
printf("-- unk_u64_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u64_2, (u64)packet->unk_u64_2, (f64)packet->unk_u64_2);

// string message
endian_write_u32_little(buffer + offset, packet->message_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->message_length, (u64)packet->message_length, (f64)packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
endian_write_i8_little(buffer + offset, packet->message[message_iter]);
offset++;
}

// vec4 position
endian_write_vec4_little(buffer + offset, packet->position);
offset += sizeof(f32) * 4;
printf("-- position                \t%f\t%f\t%f\t%f\n", (f64)packet->position.x, (f64)packet->position.y, (f64)packet->position.x, (f64)packet->position.w);

// u64 unk_guid
endian_write_u64_little(buffer + offset, packet->unk_guid);
offset += sizeof(u64);
printf("-- unk_guid                \t%lld\t%llxh\t%f\n", (i64)packet->unk_guid, (u64)packet->unk_guid, (f64)packet->unk_guid);

// u32 unk_u32_7
endian_write_u32_little(buffer + offset, packet->unk_u32_7);
offset += sizeof(u32);
printf("-- unk_u32_7               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_7, (u64)packet->unk_u32_7, (f64)packet->unk_u32_7);

// u32 color_1
endian_write_u32_little(buffer + offset, packet->color_1);
offset += sizeof(u32);
printf("-- color_1                 \t%lld\t%llxh\t%f\n", (i64)packet->color_1, (u64)packet->color_1, (f64)packet->color_1);

// u32 color_2
endian_write_u32_little(buffer + offset, packet->color_2);
offset += sizeof(u32);
printf("-- color_2                 \t%lld\t%llxh\t%f\n", (i64)packet->color_2, (u64)packet->color_2, (f64)packet->color_2);

// u8 unk_u8
endian_write_u8_little(buffer + offset, packet->unk_u8);
offset += sizeof(u8);
printf("-- unk_u8                  \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8, (u64)packet->unk_u8, (f64)packet->unk_u8);

// u8 unk_u8_2
endian_write_u8_little(buffer + offset, packet->unk_u8_2);
offset += sizeof(u8);
printf("-- unk_u8_2                \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8_2, (u64)packet->unk_u8_2, (f64)packet->unk_u8_2);

} break;

case Zone_Packet_Kind_Chat_ChatText:
{
printf("[*] Packing Chat_ChatText...\n");
Zone_Packet_Chat_ChatText* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x6);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

// string message
endian_write_u32_little(buffer + offset, packet->message_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->message_length, (u64)packet->message_length, (f64)packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
endian_write_i8_little(buffer + offset, packet->message[message_iter]);
offset++;
}

// u32 unk_u32
endian_write_u32_little(buffer + offset, packet->unk_u32);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 color
endian_write_u32_little(buffer + offset, packet->color);
offset += sizeof(u32);
printf("-- color                   \t%lld\t%llxh\t%f\n", (i64)packet->color, (u64)packet->color, (f64)packet->color);

// u32 unk_u32_2
endian_write_u32_little(buffer + offset, packet->unk_u32_2);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_2, (u64)packet->unk_u32_2, (f64)packet->unk_u32_2);

// u8 unk_u8
endian_write_u8_little(buffer + offset, packet->unk_u8);
offset += sizeof(u8);
printf("-- unk_u8                  \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8, (u64)packet->unk_u8, (f64)packet->unk_u8);

// u8 unk_u8_2
endian_write_u8_little(buffer + offset, packet->unk_u8_2);
offset += sizeof(u8);
printf("-- unk_u8_2                \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8_2, (u64)packet->unk_u8_2, (f64)packet->unk_u8_2);

} break;

case Zone_Packet_Kind_ClientLogout:
{
printf("[*] Packing ClientLogout...\n");
endian_write_u8_little(buffer + offset, 0x7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_TargetClientNotOnline:
{
printf("[*] Packing TargetClientNotOnline...\n");
endian_write_u8_little(buffer + offset, 0x8);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CommandItemDefinitionRequest:
{
printf("[*] Packing CommandItemDefinitionRequest...\n");
Zone_Packet_CommandItemDefinitionRequest* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9);
offset += sizeof(u8);

endian_write_u32_little(buffer + offset, 0x45);
offset += sizeof(u32);

// u32 id
endian_write_u32_little(buffer + offset, packet->id);
offset += sizeof(u32);
printf("-- id                      \t%lld\t%llxh\t%f\n", (i64)packet->id, (u64)packet->id, (f64)packet->id);

} break;

case Zone_Packet_Kind_CommandItemDefinitionReply:
{
printf("[*] Packing CommandItemDefinitionReply...\n");
Zone_Packet_CommandItemDefinitionReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9);
offset += sizeof(u8);

endian_write_u32_little(buffer + offset, 0x46);
offset += sizeof(u32);

// stream item_def_reply_1
void* item_def_reply_1_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1_length, (u64)packet->item_def_reply_1_length, (f64)packet->item_def_reply_1_length);

u32 will_pack_item_def_reply_1 = packet->item_def_reply_1_length == ~(u32)0 ? 0 : 1;
for (u32 item_def_reply_1_iter = 0; item_def_reply_1_iter < will_pack_item_def_reply_1; item_def_reply_1_iter++)
{
// u8 bitflags1
endian_write_u8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].bitflags1);
offset += sizeof(u8);
printf("-- bitflags1               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags1);

// u8 bitflags2
endian_write_u8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].bitflags2);
offset += sizeof(u8);
printf("-- bitflags2               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags2);

// u32 name_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].name_id);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].name_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].name_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].name_id);

// u32 description_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].description_id);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].description_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].description_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].description_id);

// u32 content_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].content_id);
offset += sizeof(u32);
printf("-- content_id              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].content_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].content_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].content_id);

// u32 image_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].image_set_id);
offset += sizeof(u32);
printf("-- image_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].image_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].image_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].image_set_id);

// u32 tint_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].tint_id);
offset += sizeof(u32);
printf("-- tint_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].tint_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].tint_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].tint_id);

// u32 hud_image_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id);
offset += sizeof(u32);
printf("-- hud_image_set_id        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id);

// u32 unk_dword_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1);

// u32 unk_dword_2
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2);
offset += sizeof(u32);
printf("-- unk_dword_2             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2);

// u32 cost
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].cost);
offset += sizeof(u32);
printf("-- cost                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].cost, (u64)packet->item_def_reply_1[item_def_reply_1_iter].cost, (f64)packet->item_def_reply_1[item_def_reply_1_iter].cost);

// u32 item_class
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].item_class);
offset += sizeof(u32);
printf("-- item_class              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].item_class, (u64)packet->item_def_reply_1[item_def_reply_1_iter].item_class, (f64)packet->item_def_reply_1[item_def_reply_1_iter].item_class);

// u32 profile_override
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].profile_override);
offset += sizeof(u32);
printf("-- profile_override        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].profile_override, (u64)packet->item_def_reply_1[item_def_reply_1_iter].profile_override, (f64)packet->item_def_reply_1[item_def_reply_1_iter].profile_override);

// string model_name
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].model_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].model_name_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].model_name_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->item_def_reply_1[item_def_reply_1_iter].model_name_length; model_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].model_name[model_name_iter]);
offset++;
}

// string texture_alias
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length);
for (u32 texture_alias_iter = 0; texture_alias_iter < packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length; texture_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].texture_alias[texture_alias_iter]);
offset++;
}

// u32 gender_usage
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].gender_usage);
offset += sizeof(u32);
printf("-- gender_usage            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].gender_usage, (u64)packet->item_def_reply_1[item_def_reply_1_iter].gender_usage, (f64)packet->item_def_reply_1[item_def_reply_1_iter].gender_usage);

// u32 item_type
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].item_type);
offset += sizeof(u32);
printf("-- item_type               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].item_type, (u64)packet->item_def_reply_1[item_def_reply_1_iter].item_type, (f64)packet->item_def_reply_1[item_def_reply_1_iter].item_type);

// u32 category_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].category_id);
offset += sizeof(u32);
printf("-- category_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].category_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].category_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].category_id);

// u32 weapon_trail_effect_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id);
offset += sizeof(u32);
printf("-- weapon_trail_effect_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id);

// u32 composite_effect_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id);
offset += sizeof(u32);
printf("-- composite_effect_id     \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id);

// u32 power_rating
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].power_rating);
offset += sizeof(u32);
printf("-- power_rating            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].power_rating, (u64)packet->item_def_reply_1[item_def_reply_1_iter].power_rating, (f64)packet->item_def_reply_1[item_def_reply_1_iter].power_rating);

// u32 min_profile_rank
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank);
offset += sizeof(u32);
printf("-- min_profile_rank        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank, (u64)packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank, (f64)packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank);

// u32 rarity
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].rarity);
offset += sizeof(u32);
printf("-- rarity                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].rarity, (u64)packet->item_def_reply_1[item_def_reply_1_iter].rarity, (f64)packet->item_def_reply_1[item_def_reply_1_iter].rarity);

// u32 activatable_ability_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id);
offset += sizeof(u32);
printf("-- activatable_ability_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id);

// u32 activatable_ability_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id);
offset += sizeof(u32);
printf("-- activatable_ability_set_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id);

// u32 passive_ability_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id);
offset += sizeof(u32);
printf("-- passive_ability_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id);

// u32 passive_ability_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id);
offset += sizeof(u32);
printf("-- passive_ability_set_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id);

// u32 max_stack_size
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size);
offset += sizeof(u32);
printf("-- max_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size, (u64)packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size, (f64)packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size);

// u32 min_stack_size
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size);
offset += sizeof(u32);
printf("-- min_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size, (u64)packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size, (f64)packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size);

// string tint_alias
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length; tint_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].tint_alias[tint_alias_iter]);
offset++;
}

// u32 tint_group_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id);
offset += sizeof(u32);
printf("-- tint_group_id           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id);

// u32 member_discount
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].member_discount);
offset += sizeof(u32);
printf("-- member_discount         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].member_discount, (u64)packet->item_def_reply_1[item_def_reply_1_iter].member_discount, (f64)packet->item_def_reply_1[item_def_reply_1_iter].member_discount);

// u32 vip_rank_required
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required);
offset += sizeof(u32);
printf("-- vip_rank_required       \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required, (u64)packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required, (f64)packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required);

// u32 race_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].race_set_id);
offset += sizeof(u32);
printf("-- race_set_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].race_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].race_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].race_set_id);

// u32 ui_model_camera_id_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1);
offset += sizeof(u32);
printf("-- ui_model_camera_id_1    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1);

// u32 equip_count_max
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max);
offset += sizeof(u32);
printf("-- equip_count_max         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max, (u64)packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max, (f64)packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max);

// i32 curreny_type
endian_write_i32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].curreny_type);
offset += sizeof(i32);
printf("-- curreny_type            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].curreny_type, (u64)packet->item_def_reply_1[item_def_reply_1_iter].curreny_type, (f64)packet->item_def_reply_1[item_def_reply_1_iter].curreny_type);

// u32 datasheet_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id);
offset += sizeof(u32);
printf("-- datasheet_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id);

// u32 item_type_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].item_type_1);
offset += sizeof(u32);
printf("-- item_type_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].item_type_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].item_type_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].item_type_1);

// u32 skill_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id);
offset += sizeof(u32);
printf("-- skill_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id);

// string overlay_texture
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length);
for (u32 overlay_texture_iter = 0; overlay_texture_iter < packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length; overlay_texture_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture[overlay_texture_iter]);
offset++;
}

// string decal_slot
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length);
for (u32 decal_slot_iter = 0; decal_slot_iter < packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length; decal_slot_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].decal_slot[decal_slot_iter]);
offset++;
}

// u32 overlay_adjustment
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment);
offset += sizeof(u32);
printf("-- overlay_adjustment      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment, (u64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment, (f64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment);

// u32 trial_duration_sec
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec);
offset += sizeof(u32);
printf("-- trial_duration_sec      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec, (u64)packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec, (f64)packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec);

// u32 next_trial_delay_sec
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec);
offset += sizeof(u32);
printf("-- next_trial_delay_sec    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec, (u64)packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec, (f64)packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec);

// u32 client_use_requirement
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement);
offset += sizeof(u32);
printf("-- client_use_requirement  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement, (u64)packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement, (f64)packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement);

// string override_appearance
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length);
for (u32 override_appearance_iter = 0; override_appearance_iter < packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length; override_appearance_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].override_appearance[override_appearance_iter]);
offset++;
}

// u32 override_camera_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id);
offset += sizeof(u32);
printf("-- override_camera_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id);

// u32 unk_dword_3
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3);
offset += sizeof(u32);
printf("-- unk_dword_3             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3);

// u32 unk_dword_4
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4);
offset += sizeof(u32);
printf("-- unk_dword_4             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4);

// u32 unk_dword_5
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5);
offset += sizeof(u32);
printf("-- unk_dword_5             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5);

// u32 bulk
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].bulk);
offset += sizeof(u32);
printf("-- bulk                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].bulk, (u64)packet->item_def_reply_1[item_def_reply_1_iter].bulk, (f64)packet->item_def_reply_1[item_def_reply_1_iter].bulk);

// u32 active_equip_slot_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id);
offset += sizeof(u32);
printf("-- active_equip_slot_id    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id);

// u32 passive_equip_slot_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id);
offset += sizeof(u32);
printf("-- passive_equip_slot_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id);

// u32 passive_equip_slot_group_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id);
offset += sizeof(u32);
printf("-- passive_equip_slot_group_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id);

// u32 unk_dword_6
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6);
offset += sizeof(u32);
printf("-- unk_dword_6             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6);

// u32 grinder_reward_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id);
offset += sizeof(u32);
printf("-- grinder_reward_set_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id);

// u32 build_bar_group_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id);
offset += sizeof(u32);
printf("-- build_bar_group_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id);

// string unk_string_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length; unk_string_1_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1[unk_string_1_iter]);
offset++;
}

// b8 unk_bool_1
endian_write_b8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1);
offset += sizeof(b8);
printf("-- unk_bool_1              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1);

// b8 is_armor
endian_write_b8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].is_armor);
offset += sizeof(b8);
printf("-- is_armor                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].is_armor, (u64)packet->item_def_reply_1[item_def_reply_1_iter].is_armor, (f64)packet->item_def_reply_1[item_def_reply_1_iter].is_armor);

// u32 unk_dword_7
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7);
offset += sizeof(u32);
printf("-- unk_dword_7             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7);

// u32 param1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].param1);
offset += sizeof(u32);
printf("-- param1                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].param1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].param1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].param1);

// u32 param2
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].param2);
offset += sizeof(u32);
printf("-- param2                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].param2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].param2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].param2);

// u32 param3
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].param3);
offset += sizeof(u32);
printf("-- param3                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].param3, (u64)packet->item_def_reply_1[item_def_reply_1_iter].param3, (f64)packet->item_def_reply_1[item_def_reply_1_iter].param3);

// string string_param1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length, (u64)packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length, (f64)packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length);
for (u32 string_param1_iter = 0; string_param1_iter < packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length; string_param1_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].string_param1[string_param1_iter]);
offset++;
}

// u32 ui_model_camera_id_2
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2);
offset += sizeof(u32);
printf("-- ui_model_camera_id_2    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2);

// u32 unk_dword_8
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8);
offset += sizeof(u32);
printf("-- unk_dword_8             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8);

// i32 scrap_value_override
endian_write_i32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override);
offset += sizeof(i32);
printf("-- scrap_value_override    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override, (u64)packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override, (f64)packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override);

// list stats_item_def_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count);

for (u32 stats_item_def_1_iter = 0; stats_item_def_1_iter < packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count; stats_item_def_1_iter++)
{
// u32 unk_dword_9
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9);
offset += sizeof(u32);
printf("-- unk_dword_9             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9);

// u32 stat_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id);
offset += sizeof(u32);
printf("-- stat_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id);

// f32 base
endian_write_f32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base);
offset += sizeof(f32);
printf("-- base                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base);

// f32 modifier
endian_write_f32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier);
offset += sizeof(f32);
printf("-- modifier                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier);

// u32 unk_dword_10
endian_write_u32_little(buffer + offset, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10);
offset += sizeof(u32);
printf("-- unk_dword_10            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10);

} // stats_item_def_1

} // item_def_reply_1
endian_write_u32_little((u8*)item_def_reply_1_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)item_def_reply_1_length_ptr - sizeof(u32)));

} break;

case Zone_Packet_Kind_CommandItemDefinitions:
{
printf("[*] Packing CommandItemDefinitions...\n");
Zone_Packet_CommandItemDefinitions* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9);
offset += sizeof(u8);

endian_write_u32_little(buffer + offset, 0x47);
offset += sizeof(u32);

// stream item_def_reply_2
void* item_def_reply_2_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2_length, (u64)packet->item_def_reply_2_length, (f64)packet->item_def_reply_2_length);

u32 will_pack_item_def_reply_2 = packet->item_def_reply_2_length == ~(u32)0 ? 0 : 1;
for (u32 item_def_reply_2_iter = 0; item_def_reply_2_iter < will_pack_item_def_reply_2; item_def_reply_2_iter++)
{
// list item_defs
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count);

for (u32 item_defs_iter = 0; item_defs_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count; item_defs_iter++)
{
// u32 defs_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id);
offset += sizeof(u32);
printf("-- defs_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id);

// u8 bitflags1
endian_write_u8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1);
offset += sizeof(u8);
printf("-- bitflags1               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1);

// u8 bitflags2
endian_write_u8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2);
offset += sizeof(u8);
printf("-- bitflags2               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2);

// u32 name_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id);

// u32 description_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id);

// u32 content_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id);
offset += sizeof(u32);
printf("-- content_id              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id);

// u32 image_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id);
offset += sizeof(u32);
printf("-- image_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id);

// u32 tint_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id);
offset += sizeof(u32);
printf("-- tint_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id);

// u32 hud_image_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id);
offset += sizeof(u32);
printf("-- hud_image_set_id        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id);

// u32 unk_dword_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1);

// u32 unk_dword_2
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2);
offset += sizeof(u32);
printf("-- unk_dword_2             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2);

// u32 cost
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost);
offset += sizeof(u32);
printf("-- cost                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost);

// u32 item_class
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class);
offset += sizeof(u32);
printf("-- item_class              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class);

// u32 profile_override
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override);
offset += sizeof(u32);
printf("-- profile_override        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override);

// string model_name
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length; model_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name[model_name_iter]);
offset++;
}

// string texture_alias
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length);
for (u32 texture_alias_iter = 0; texture_alias_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length; texture_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias[texture_alias_iter]);
offset++;
}

// u32 gender_usage
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage);
offset += sizeof(u32);
printf("-- gender_usage            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage);

// u32 item_type
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type);
offset += sizeof(u32);
printf("-- item_type               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type);

// u32 category_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id);
offset += sizeof(u32);
printf("-- category_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id);

// u32 weapon_trail_effect_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id);
offset += sizeof(u32);
printf("-- weapon_trail_effect_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id);

// u32 composite_effect_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id);
offset += sizeof(u32);
printf("-- composite_effect_id     \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id);

// u32 power_rating
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating);
offset += sizeof(u32);
printf("-- power_rating            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating);

// u32 min_profile_rank
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank);
offset += sizeof(u32);
printf("-- min_profile_rank        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank);

// u32 rarity
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity);
offset += sizeof(u32);
printf("-- rarity                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity);

// u32 activatable_ability_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id);
offset += sizeof(u32);
printf("-- activatable_ability_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id);

// u32 activatable_ability_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id);
offset += sizeof(u32);
printf("-- activatable_ability_set_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id);

// u32 passive_ability_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id);
offset += sizeof(u32);
printf("-- passive_ability_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id);

// u32 passive_ability_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id);
offset += sizeof(u32);
printf("-- passive_ability_set_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id);

// u32 max_stack_size
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size);
offset += sizeof(u32);
printf("-- max_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size);

// u32 min_stack_size
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size);
offset += sizeof(u32);
printf("-- min_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size);

// string tint_alias
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length; tint_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias[tint_alias_iter]);
offset++;
}

// u32 tint_group_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id);
offset += sizeof(u32);
printf("-- tint_group_id           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id);

// u32 member_discount
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount);
offset += sizeof(u32);
printf("-- member_discount         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount);

// u32 vip_rank_required
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required);
offset += sizeof(u32);
printf("-- vip_rank_required       \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required);

// u32 race_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id);
offset += sizeof(u32);
printf("-- race_set_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id);

// u32 ui_model_camera_id_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1);
offset += sizeof(u32);
printf("-- ui_model_camera_id_1    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1);

// u32 equip_count_max
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max);
offset += sizeof(u32);
printf("-- equip_count_max         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max);

// i32 curreny_type
endian_write_i32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type);
offset += sizeof(i32);
printf("-- curreny_type            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type);

// u32 datasheet_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id);
offset += sizeof(u32);
printf("-- datasheet_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id);

// u32 item_type_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1);
offset += sizeof(u32);
printf("-- item_type_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1);

// u32 skill_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id);
offset += sizeof(u32);
printf("-- skill_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id);

// string overlay_texture
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length);
for (u32 overlay_texture_iter = 0; overlay_texture_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length; overlay_texture_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture[overlay_texture_iter]);
offset++;
}

// string decal_slot
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length);
for (u32 decal_slot_iter = 0; decal_slot_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length; decal_slot_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot[decal_slot_iter]);
offset++;
}

// u32 overlay_adjustment
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment);
offset += sizeof(u32);
printf("-- overlay_adjustment      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment);

// u32 trial_duration_sec
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec);
offset += sizeof(u32);
printf("-- trial_duration_sec      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec);

// u32 next_trial_delay_sec
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec);
offset += sizeof(u32);
printf("-- next_trial_delay_sec    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec);

// u32 client_use_requirement
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement);
offset += sizeof(u32);
printf("-- client_use_requirement  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement);

// string override_appearance
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length);
for (u32 override_appearance_iter = 0; override_appearance_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length; override_appearance_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance[override_appearance_iter]);
offset++;
}

// u32 override_camera_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id);
offset += sizeof(u32);
printf("-- override_camera_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id);

// u32 unk_dword_3
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3);
offset += sizeof(u32);
printf("-- unk_dword_3             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3);

// u32 unk_dword_4
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4);
offset += sizeof(u32);
printf("-- unk_dword_4             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4);

// u32 unk_dword_5
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5);
offset += sizeof(u32);
printf("-- unk_dword_5             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5);

// u32 bulk
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk);
offset += sizeof(u32);
printf("-- bulk                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk);

// u32 active_equip_slot_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id);
offset += sizeof(u32);
printf("-- active_equip_slot_id    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id);

// u32 passive_equip_slot_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id);
offset += sizeof(u32);
printf("-- passive_equip_slot_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id);

// u32 passive_equip_slot_group_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id);
offset += sizeof(u32);
printf("-- passive_equip_slot_group_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id);

// u32 unk_dword_6
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6);
offset += sizeof(u32);
printf("-- unk_dword_6             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6);

// u32 grinder_reward_set_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id);
offset += sizeof(u32);
printf("-- grinder_reward_set_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id);

// u32 build_bar_group_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id);
offset += sizeof(u32);
printf("-- build_bar_group_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id);

// string unk_string_1
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length; unk_string_1_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1[unk_string_1_iter]);
offset++;
}

// b8 unk_bool_1
endian_write_b8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1);
offset += sizeof(b8);
printf("-- unk_bool_1              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1);

// b8 is_armor
endian_write_b8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor);
offset += sizeof(b8);
printf("-- is_armor                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor);

// u32 unk_dword_7
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7);
offset += sizeof(u32);
printf("-- unk_dword_7             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7);

// u32 param1
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1);
offset += sizeof(u32);
printf("-- param1                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1);

// u32 param2
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2);
offset += sizeof(u32);
printf("-- param2                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2);

// u32 param3
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3);
offset += sizeof(u32);
printf("-- param3                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3);

// string string_param1
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length);
for (u32 string_param1_iter = 0; string_param1_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length; string_param1_iter++)
{
endian_write_i8_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1[string_param1_iter]);
offset++;
}

// u32 ui_model_camera_id_2
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2);
offset += sizeof(u32);
printf("-- ui_model_camera_id_2    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2);

// u32 unk_dword_8
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8);
offset += sizeof(u32);
printf("-- unk_dword_8             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8);

// i32 scrap_value_override
endian_write_i32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override);
offset += sizeof(i32);
printf("-- scrap_value_override    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override);

// list stats_item_def_2
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count);

for (u32 stats_item_def_2_iter = 0; stats_item_def_2_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count; stats_item_def_2_iter++)
{
// u32 unk_dword_9
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9);
offset += sizeof(u32);
printf("-- unk_dword_9             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9);

// u32 stat_id
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id);
offset += sizeof(u32);
printf("-- stat_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id);

// u32 base
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base);
offset += sizeof(u32);
printf("-- base                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base);

// u32 modifier
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier);
offset += sizeof(u32);
printf("-- modifier                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier);

// u32 unk_dword_10
endian_write_u32_little(buffer + offset, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10);
offset += sizeof(u32);
printf("-- unk_dword_10            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10);

} // stats_item_def_2

} // item_defs

} // item_def_reply_2
endian_write_u32_little((u8*)item_def_reply_2_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)item_def_reply_2_length_ptr - sizeof(u32)));

} break;

case Zone_Packet_Kind_AdminBase:
{
printf("[*] Packing AdminBase...\n");
endian_write_u8_little(buffer + offset, 0xa);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientBeginZoning:
{
printf("[*] Packing ClientBeginZoning...\n");
endian_write_u8_little(buffer + offset, 0xb);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CombatBase:
{
printf("[*] Packing CombatBase...\n");
endian_write_u8_little(buffer + offset, 0xc);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ProjectileDebug:
{
printf("[*] Packing ProjectileDebug...\n");
endian_write_u8_little(buffer + offset, 0xd);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_MailBase:
{
printf("[*] Packing MailBase...\n");
endian_write_u8_little(buffer + offset, 0xe);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_CharacterBase:
{
printf("[*] Packing CharacterBase...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_RemovePlayer:
{
printf("[*] Packing Character_RemovePlayer...\n");
Zone_Packet_Character_RemovePlayer* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u16 unk_u16
endian_write_u16_little(buffer + offset, packet->unk_u16);
offset += sizeof(u16);
printf("-- unk_u16                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u16, (u64)packet->unk_u16, (f64)packet->unk_u16);

// u8 unk_u8
endian_write_u8_little(buffer + offset, packet->unk_u8);
offset += sizeof(u8);
printf("-- unk_u8                  \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8, (u64)packet->unk_u8, (f64)packet->unk_u8);

// u32 unk_u32
endian_write_u32_little(buffer + offset, packet->unk_u32);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 effect_delay
endian_write_u32_little(buffer + offset, packet->effect_delay);
offset += sizeof(u32);
printf("-- effect_delay            \t%lld\t%llxh\t%f\n", (i64)packet->effect_delay, (u64)packet->effect_delay, (f64)packet->effect_delay);

// u32 effect_id
endian_write_u32_little(buffer + offset, packet->effect_id);
offset += sizeof(u32);
printf("-- effect_id               \t%lld\t%llxh\t%f\n", (i64)packet->effect_id, (u64)packet->effect_id, (f64)packet->effect_id);

// u32 sticky_effect_id
endian_write_u32_little(buffer + offset, packet->sticky_effect_id);
offset += sizeof(u32);
printf("-- sticky_effect_id        \t%lld\t%llxh\t%f\n", (i64)packet->sticky_effect_id, (u64)packet->sticky_effect_id, (f64)packet->sticky_effect_id);

// u32 time_to_disappear
endian_write_u32_little(buffer + offset, packet->time_to_disappear);
offset += sizeof(u32);
printf("-- time_to_disappear       \t%lld\t%llxh\t%f\n", (i64)packet->time_to_disappear, (u64)packet->time_to_disappear, (f64)packet->time_to_disappear);

} break;

case Zone_Packet_Kind_Character_Knockback:
{
printf("[*] Packing Character_Knockback...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_UpdateHitpoints:
{
printf("[*] Packing Character_UpdateHitpoints...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_PlayAnimation:
{
printf("[*] Packing Character_PlayAnimation...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_UpdateScale:
{
printf("[*] Packing Character_UpdateScale...\n");
Zone_Packet_Character_UpdateScale* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// vec4 scale
endian_write_vec4_little(buffer + offset, packet->scale);
offset += sizeof(f32) * 4;
printf("-- scale                   \t%f\t%f\t%f\t%f\n", (f64)packet->scale.x, (f64)packet->scale.y, (f64)packet->scale.x, (f64)packet->scale.w);

} break;

case Zone_Packet_Kind_Character_UpdateTemporaryAppearance:
{
printf("[*] Packing Character_UpdateTemporaryAppearance...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x6);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_RemoveTemporaryAppearance:
{
printf("[*] Packing Character_RemoveTemporaryAppearance...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x7);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_SetLookAt:
{
printf("[*] Packing Character_SetLookAt...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x8);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_RenamePlayer:
{
printf("[*] Packing Character_RenamePlayer...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x9);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Character_WeaponStance:
{
printf("[*] Packing Character_WeaponStance...\n");
Zone_Packet_Character_WeaponStance* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x20);
offset += sizeof(u16);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 stance
endian_write_u32_little(buffer + offset, packet->stance);
offset += sizeof(u32);
printf("-- stance                  \t%lld\t%llxh\t%f\n", (i64)packet->stance, (u64)packet->stance, (f64)packet->stance);

} break;

case Zone_Packet_Kind_Character_CharacterStateDelta:
{
printf("[*] Packing Character_CharacterStateDelta...\n");
Zone_Packet_Character_CharacterStateDelta* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3f);
offset += sizeof(u16);

// u64 guid_1
endian_write_u64_little(buffer + offset, packet->guid_1);
offset += sizeof(u64);
printf("-- guid_1                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_1, (u64)packet->guid_1, (f64)packet->guid_1);

// u64 guid_2
endian_write_u64_little(buffer + offset, packet->guid_2);
offset += sizeof(u64);
printf("-- guid_2                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_2, (u64)packet->guid_2, (f64)packet->guid_2);

// u64 guid_3
endian_write_u64_little(buffer + offset, packet->guid_3);
offset += sizeof(u64);
printf("-- guid_3                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_3, (u64)packet->guid_3, (f64)packet->guid_3);

// u64 guid_4
endian_write_u64_little(buffer + offset, packet->guid_4);
offset += sizeof(u64);
printf("-- guid_4                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_4, (u64)packet->guid_4, (f64)packet->guid_4);

// u32 game_time
endian_write_u32_little(buffer + offset, packet->game_time);
offset += sizeof(u32);
printf("-- game_time               \t%lld\t%llxh\t%f\n", (i64)packet->game_time, (u64)packet->game_time, (f64)packet->game_time);

} break;

case Zone_Packet_Kind_AbilityBase:
{
printf("[*] Packing AbilityBase...\n");
endian_write_u8_little(buffer + offset, 0x10);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdateBase:
{
printf("[*] Packing ClientUpdateBase...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_Hitpoints:
{
printf("[*] Packing ClientUpdate_Hitpoints...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ItemAdd:
{
printf("[*] Packing ClientUpdate_ItemAdd...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ItemUpdate:
{
printf("[*] Packing ClientUpdate_ItemUpdate...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ItemDelete:
{
printf("[*] Packing ClientUpdate_ItemDelete...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateStat:
{
printf("[*] Packing ClientUpdate_UpdateStat...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CollectionStart:
{
printf("[*] Packing ClientUpdate_CollectionStart...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x6);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CollectionRemove:
{
printf("[*] Packing ClientUpdate_CollectionRemove...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x7);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CollectionAddEntry:
{
printf("[*] Packing ClientUpdate_CollectionAddEntry...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x8);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CollectionRemoveEntry:
{
printf("[*] Packing ClientUpdate_CollectionRemoveEntry...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x9);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateLocation:
{
printf("[*] Packing ClientUpdate_UpdateLocation...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xa);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_Mana:
{
printf("[*] Packing ClientUpdate_Mana...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xb);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateProfileExperience:
{
printf("[*] Packing ClientUpdate_UpdateProfileExperience...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xc);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_AddProfileAbilitySetApl:
{
printf("[*] Packing ClientUpdate_AddProfileAbilitySetApl...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xd);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_AddEffectTag:
{
printf("[*] Packing ClientUpdate_AddEffectTag...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xe);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_RemoveEffectTag:
{
printf("[*] Packing ClientUpdate_RemoveEffectTag...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xf);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateProfileRank:
{
printf("[*] Packing ClientUpdate_UpdateProfileRank...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x10);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CoinCount:
{
printf("[*] Packing ClientUpdate_CoinCount...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x11);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_DeleteProfile:
{
printf("[*] Packing ClientUpdate_DeleteProfile...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x12);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ActivateProfile:
{
printf("[*] Packing ClientUpdate_ActivateProfile...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x13);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_AddAbility:
{
printf("[*] Packing ClientUpdate_AddAbility...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x14);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_NotifyPlayer:
{
printf("[*] Packing ClientUpdate_NotifyPlayer...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x15);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateProfileAbilitySetApl:
{
printf("[*] Packing ClientUpdate_UpdateProfileAbilitySetApl...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x16);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_RemoveActionBars:
{
printf("[*] Packing ClientUpdate_RemoveActionBars...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x17);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateActionBarSlot:
{
printf("[*] Packing ClientUpdate_UpdateActionBarSlot...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x18);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters:
{
printf("[*] Packing ClientUpdate_DoneSendingPreloadCharacters...\n");
Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x19);
offset += sizeof(u16);

// b8 is_done
endian_write_b8_little(buffer + offset, packet->is_done);
offset += sizeof(b8);
printf("-- is_done                 \t%lld\t%llxh\t%f\n", (i64)packet->is_done, (u64)packet->is_done, (f64)packet->is_done);

} break;

case Zone_Packet_Kind_ClientUpdate_SetGrandfatheredStatus:
{
printf("[*] Packing ClientUpdate_SetGrandfatheredStatus...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1a);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateActionBarSlotUsed:
{
printf("[*] Packing ClientUpdate_UpdateActionBarSlotUsed...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1b);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_PhaseChange:
{
printf("[*] Packing ClientUpdate_PhaseChange...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1c);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateKingdomExperience:
{
printf("[*] Packing ClientUpdate_UpdateKingdomExperience...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1d);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdatePacketDamageInfo:
{
printf("[*] Packing ClientUpdate_UpdatePacketDamageInfo...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1e);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_RespawnLocations:
{
printf("[*] Packing ClientUpdate_RespawnLocations...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1f);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ModifyMovementSpeed:
{
printf("[*] Packing ClientUpdate_ModifyMovementSpeed...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x20);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ModifyTurnRate:
{
printf("[*] Packing ClientUpdate_ModifyTurnRate...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x21);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ModifyStrafeSpeed:
{
printf("[*] Packing ClientUpdate_ModifyStrafeSpeed...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x22);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateManagedLocation:
{
printf("[*] Packing ClientUpdate_UpdateManagedLocation...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x23);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ManagedMovementVersion:
{
printf("[*] Packing ClientUpdate_ManagedMovementVersion...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x24);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateWeaponAddClips:
{
printf("[*] Packing ClientUpdate_UpdateWeaponAddClips...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x25);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_SpotProbation:
{
printf("[*] Packing ClientUpdate_SpotProbation...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x26);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_DailyRibbonCount:
{
printf("[*] Packing ClientUpdate_DailyRibbonCount...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x27);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_DespawnNpcUpdate:
{
printf("[*] Packing ClientUpdate_DespawnNpcUpdate...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x29);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_LoyaltyPoints:
{
printf("[*] Packing ClientUpdate_LoyaltyPoints...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2a);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ResetMissionRespawnTimer:
{
printf("[*] Packing ClientUpdate_ResetMissionRespawnTimer...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2b);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_Freeze:
{
printf("[*] Packing ClientUpdate_Freeze...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2c);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_InGamePurchaseResult:
{
printf("[*] Packing ClientUpdate_InGamePurchaseResult...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2d);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_QuizComplete:
{
printf("[*] Packing ClientUpdate_QuizComplete...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2e);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_StartTimer:
{
printf("[*] Packing ClientUpdate_StartTimer...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2f);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CompleteLogoutProcess:
{
printf("[*] Packing ClientUpdate_CompleteLogoutProcess...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x30);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ProximateItems:
{
printf("[*] Packing ClientUpdate_ProximateItems...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x31);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_TextAlert:
{
printf("[*] Packing ClientUpdate_TextAlert...\n");
Zone_Packet_ClientUpdate_TextAlert* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x32);
offset += sizeof(u16);

// string message
endian_write_u32_little(buffer + offset, packet->message_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->message_length, (u64)packet->message_length, (f64)packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
endian_write_i8_little(buffer + offset, packet->message[message_iter]);
offset++;
}

} break;

case Zone_Packet_Kind_ClientUpdate_ClearEntitlementValues:
{
printf("[*] Packing ClientUpdate_ClearEntitlementValues...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x33);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_AddEntitlementValue:
{
printf("[*] Packing ClientUpdate_AddEntitlementValue...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x34);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete:
{
printf("[*] Packing ClientUpdate_NetworkProximityUpdatesComplete...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x35);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_FileValidationRequest:
{
printf("[*] Packing ClientUpdate_FileValidationRequest...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x36);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_FileValidationResponse:
{
printf("[*] Packing ClientUpdate_FileValidationResponse...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x37);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_DeathMetrics:
{
printf("[*] Packing ClientUpdate_DeathMetrics...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x38);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_SetCurrentAdventure:
{
printf("[*] Packing ClientUpdate_SetCurrentAdventure...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3c);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CharacterSlot:
{
printf("[*] Packing ClientUpdate_CharacterSlot...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3d);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ManagedObjectRequestControl:
{
printf("[*] Packing ClientUpdate_ManagedObjectRequestControl...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x39);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ManagedObjectResponseControl:
{
printf("[*] Packing ClientUpdate_ManagedObjectResponseControl...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3a);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ManagedObjectReleaseControl:
{
printf("[*] Packing ClientUpdate_ManagedObjectReleaseControl...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3b);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_CustomizationData:
{
printf("[*] Packing ClientUpdate_CustomizationData...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3e);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateCurrency:
{
printf("[*] Packing ClientUpdate_UpdateCurrency...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3f);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_AddNotifications:
{
printf("[*] Packing ClientUpdate_AddNotifications...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x40);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_RemoveNotifications:
{
printf("[*] Packing ClientUpdate_RemoveNotifications...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x41);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_NpcRelevance:
{
printf("[*] Packing ClientUpdate_NpcRelevance...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x42);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_InitiateNameChange:
{
printf("[*] Packing ClientUpdate_InitiateNameChange...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x43);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_NameChangeResult:
{
printf("[*] Packing ClientUpdate_NameChangeResult...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x44);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift:
{
printf("[*] Packing ClientUpdate_MonitorTimeDrift...\n");
Zone_Packet_ClientUpdate_MonitorTimeDrift* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x45);
offset += sizeof(u16);

// u32 time_drift
endian_write_u32_little(buffer + offset, packet->time_drift);
offset += sizeof(u32);
printf("-- time_drift              \t%lld\t%llxh\t%f\n", (i64)packet->time_drift, (u64)packet->time_drift, (f64)packet->time_drift);

} break;

case Zone_Packet_Kind_ClientUpdate_NotifyServerOfStalledEvent:
{
printf("[*] Packing ClientUpdate_NotifyServerOfStalledEvent...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x46);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateSights:
{
printf("[*] Packing ClientUpdate_UpdateSights...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x47);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateRewardAndGrinderState:
{
printf("[*] Packing ClientUpdate_UpdateRewardAndGrinderState...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x49);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateActivityMetrics:
{
printf("[*] Packing ClientUpdate_UpdateActivityMetrics...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4b);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_StopWithError:
{
printf("[*] Packing ClientUpdate_StopWithError...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4c);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_SetWorldWipeTimer:
{
printf("[*] Packing ClientUpdate_SetWorldWipeTimer...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4d);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateLockoutTimes:
{
printf("[*] Packing ClientUpdate_UpdateLockoutTimes...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4e);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_ZoneStatus:
{
printf("[*] Packing ClientUpdate_ZoneStatus...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4f);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_SetDataCenter:
{
printf("[*] Packing ClientUpdate_SetDataCenter...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x50);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration:
{
printf("[*] Packing ClientUpdate_UpdateBattlEyeRegistration...\n");
endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x51);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_GroupsBase:
{
printf("[*] Packing GroupsBase...\n");
endian_write_u8_little(buffer + offset, 0x13);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_EncounterBase:
{
printf("[*] Packing EncounterBase...\n");
endian_write_u8_little(buffer + offset, 0x14);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_InventoryBase:
{
printf("[*] Packing InventoryBase...\n");
endian_write_u8_little(buffer + offset, 0x15);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SendZoneDetails:
{
printf("[*] Packing SendZoneDetails...\n");
Zone_Packet_SendZoneDetails* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x16);
offset += sizeof(u8);

// string zone_name
endian_write_u32_little(buffer + offset, packet->zone_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->zone_name_length, (u64)packet->zone_name_length, (f64)packet->zone_name_length);
for (u32 zone_name_iter = 0; zone_name_iter < packet->zone_name_length; zone_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->zone_name[zone_name_iter]);
offset++;
}

// u32 zone_type
endian_write_u32_little(buffer + offset, packet->zone_type);
offset += sizeof(u32);
printf("-- zone_type               \t%lld\t%llxh\t%f\n", (i64)packet->zone_type, (u64)packet->zone_type, (f64)packet->zone_type);

// u8 unk_bool
endian_write_u8_little(buffer + offset, packet->unk_bool);
offset += sizeof(u8);
printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

// f32 unknownDword1
endian_write_f32_little(buffer + offset, packet->unknownDword1);
offset += sizeof(f32);
printf("-- unknownDword1           \t%lld\t%llxh\t%f\n", (i64)packet->unknownDword1, (u64)packet->unknownDword1, (f64)packet->unknownDword1);

// f32 fog_density
endian_write_f32_little(buffer + offset, packet->fog_density);
offset += sizeof(f32);
printf("-- fog_density             \t%lld\t%llxh\t%f\n", (i64)packet->fog_density, (u64)packet->fog_density, (f64)packet->fog_density);

// f32 fog_floor
endian_write_f32_little(buffer + offset, packet->fog_floor);
offset += sizeof(f32);
printf("-- fog_floor               \t%lld\t%llxh\t%f\n", (i64)packet->fog_floor, (u64)packet->fog_floor, (f64)packet->fog_floor);

// f32 fog_gradient
endian_write_f32_little(buffer + offset, packet->fog_gradient);
offset += sizeof(f32);
printf("-- fog_gradient            \t%lld\t%llxh\t%f\n", (i64)packet->fog_gradient, (u64)packet->fog_gradient, (f64)packet->fog_gradient);

// f32 rain
endian_write_f32_little(buffer + offset, packet->rain);
offset += sizeof(f32);
printf("-- rain                    \t%lld\t%llxh\t%f\n", (i64)packet->rain, (u64)packet->rain, (f64)packet->rain);

// f32 temp
endian_write_f32_little(buffer + offset, packet->temp);
offset += sizeof(f32);
printf("-- temp                    \t%lld\t%llxh\t%f\n", (i64)packet->temp, (u64)packet->temp, (f64)packet->temp);

// f32 color_gradient
endian_write_f32_little(buffer + offset, packet->color_gradient);
offset += sizeof(f32);
printf("-- color_gradient          \t%lld\t%llxh\t%f\n", (i64)packet->color_gradient, (u64)packet->color_gradient, (f64)packet->color_gradient);

// f32 unknown_dword8
endian_write_f32_little(buffer + offset, packet->unknown_dword8);
offset += sizeof(f32);
printf("-- unknown_dword8          \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword8, (u64)packet->unknown_dword8, (f64)packet->unknown_dword8);

// f32 unknown_dword9
endian_write_f32_little(buffer + offset, packet->unknown_dword9);
offset += sizeof(f32);
printf("-- unknown_dword9          \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword9, (u64)packet->unknown_dword9, (f64)packet->unknown_dword9);

// f32 unknown_dword10
endian_write_f32_little(buffer + offset, packet->unknown_dword10);
offset += sizeof(f32);
printf("-- unknown_dword10         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword10, (u64)packet->unknown_dword10, (f64)packet->unknown_dword10);

// f32 unknown_dword11
endian_write_f32_little(buffer + offset, packet->unknown_dword11);
offset += sizeof(f32);
printf("-- unknown_dword11         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword11, (u64)packet->unknown_dword11, (f64)packet->unknown_dword11);

// f32 unknown_dword12
endian_write_f32_little(buffer + offset, packet->unknown_dword12);
offset += sizeof(f32);
printf("-- unknown_dword12         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword12, (u64)packet->unknown_dword12, (f64)packet->unknown_dword12);

// f32 sun_axis_x
endian_write_f32_little(buffer + offset, packet->sun_axis_x);
offset += sizeof(f32);
printf("-- sun_axis_x              \t%lld\t%llxh\t%f\n", (i64)packet->sun_axis_x, (u64)packet->sun_axis_x, (f64)packet->sun_axis_x);

// f32 sun_axis_y
endian_write_f32_little(buffer + offset, packet->sun_axis_y);
offset += sizeof(f32);
printf("-- sun_axis_y              \t%lld\t%llxh\t%f\n", (i64)packet->sun_axis_y, (u64)packet->sun_axis_y, (f64)packet->sun_axis_y);

// f32 unknown_dword15
endian_write_f32_little(buffer + offset, packet->unknown_dword15);
offset += sizeof(f32);
printf("-- unknown_dword15         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword15, (u64)packet->unknown_dword15, (f64)packet->unknown_dword15);

// f32 disable_trees
endian_write_f32_little(buffer + offset, packet->disable_trees);
offset += sizeof(f32);
printf("-- disable_trees           \t%lld\t%llxh\t%f\n", (i64)packet->disable_trees, (u64)packet->disable_trees, (f64)packet->disable_trees);

// f32 disable_trees1
endian_write_f32_little(buffer + offset, packet->disable_trees1);
offset += sizeof(f32);
printf("-- disable_trees1          \t%lld\t%llxh\t%f\n", (i64)packet->disable_trees1, (u64)packet->disable_trees1, (f64)packet->disable_trees1);

// f32 disable_trees2
endian_write_f32_little(buffer + offset, packet->disable_trees2);
offset += sizeof(f32);
printf("-- disable_trees2          \t%lld\t%llxh\t%f\n", (i64)packet->disable_trees2, (u64)packet->disable_trees2, (f64)packet->disable_trees2);

// f32 wind
endian_write_f32_little(buffer + offset, packet->wind);
offset += sizeof(f32);
printf("-- wind                    \t%lld\t%llxh\t%f\n", (i64)packet->wind, (u64)packet->wind, (f64)packet->wind);

// f32 unknown_dword20
endian_write_f32_little(buffer + offset, packet->unknown_dword20);
offset += sizeof(f32);
printf("-- unknown_dword20         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword20, (u64)packet->unknown_dword20, (f64)packet->unknown_dword20);

// f32 unknown_dword21
endian_write_f32_little(buffer + offset, packet->unknown_dword21);
offset += sizeof(f32);
printf("-- unknown_dword21         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword21, (u64)packet->unknown_dword21, (f64)packet->unknown_dword21);

// string name
endian_write_u32_little(buffer + offset, packet->name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->name_length, (u64)packet->name_length, (f64)packet->name_length);
for (u32 name_iter = 0; name_iter < packet->name_length; name_iter++)
{
endian_write_i8_little(buffer + offset, packet->name[name_iter]);
offset++;
}

// f32 unknown_dword22
endian_write_f32_little(buffer + offset, packet->unknown_dword22);
offset += sizeof(f32);
printf("-- unknown_dword22         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword22, (u64)packet->unknown_dword22, (f64)packet->unknown_dword22);

// f32 unknown_dword23
endian_write_f32_little(buffer + offset, packet->unknown_dword23);
offset += sizeof(f32);
printf("-- unknown_dword23         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword23, (u64)packet->unknown_dword23, (f64)packet->unknown_dword23);

// f32 unknown_dword24
endian_write_f32_little(buffer + offset, packet->unknown_dword24);
offset += sizeof(f32);
printf("-- unknown_dword24         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword24, (u64)packet->unknown_dword24, (f64)packet->unknown_dword24);

// f32 unknown_dword25
endian_write_f32_little(buffer + offset, packet->unknown_dword25);
offset += sizeof(f32);
printf("-- unknown_dword25         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword25, (u64)packet->unknown_dword25, (f64)packet->unknown_dword25);

// f32 unknown_dword26
endian_write_f32_little(buffer + offset, packet->unknown_dword26);
offset += sizeof(f32);
printf("-- unknown_dword26         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword26, (u64)packet->unknown_dword26, (f64)packet->unknown_dword26);

// f32 unknown_dword27
endian_write_f32_little(buffer + offset, packet->unknown_dword27);
offset += sizeof(f32);
printf("-- unknown_dword27         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword27, (u64)packet->unknown_dword27, (f64)packet->unknown_dword27);

// f32 unknown_dword28
endian_write_f32_little(buffer + offset, packet->unknown_dword28);
offset += sizeof(f32);
printf("-- unknown_dword28         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword28, (u64)packet->unknown_dword28, (f64)packet->unknown_dword28);

// f32 unknown_dword29
endian_write_f32_little(buffer + offset, packet->unknown_dword29);
offset += sizeof(f32);
printf("-- unknown_dword29         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword29, (u64)packet->unknown_dword29, (f64)packet->unknown_dword29);

// f32 ao_size
endian_write_f32_little(buffer + offset, packet->ao_size);
offset += sizeof(f32);
printf("-- ao_size                 \t%lld\t%llxh\t%f\n", (i64)packet->ao_size, (u64)packet->ao_size, (f64)packet->ao_size);

// f32 ao_gamma
endian_write_f32_little(buffer + offset, packet->ao_gamma);
offset += sizeof(f32);
printf("-- ao_gamma                \t%lld\t%llxh\t%f\n", (i64)packet->ao_gamma, (u64)packet->ao_gamma, (f64)packet->ao_gamma);

// f32 ao_blackpoint
endian_write_f32_little(buffer + offset, packet->ao_blackpoint);
offset += sizeof(f32);
printf("-- ao_blackpoint           \t%lld\t%llxh\t%f\n", (i64)packet->ao_blackpoint, (u64)packet->ao_blackpoint, (f64)packet->ao_blackpoint);

// f32 unknown_dword33
endian_write_f32_little(buffer + offset, packet->unknown_dword33);
offset += sizeof(f32);
printf("-- unknown_dword33         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword33, (u64)packet->unknown_dword33, (f64)packet->unknown_dword33);

// u32 zone_id
endian_write_u32_little(buffer + offset, packet->zone_id);
offset += sizeof(u32);
printf("-- zone_id                 \t%lld\t%llxh\t%f\n", (i64)packet->zone_id, (u64)packet->zone_id, (f64)packet->zone_id);

// u32 zone_id_2
endian_write_u32_little(buffer + offset, packet->zone_id_2);
offset += sizeof(u32);
printf("-- zone_id_2               \t%lld\t%llxh\t%f\n", (i64)packet->zone_id_2, (u64)packet->zone_id_2, (f64)packet->zone_id_2);

// u32 name_id
endian_write_u32_little(buffer + offset, packet->name_id);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->name_id, (u64)packet->name_id, (f64)packet->name_id);

// u8 unk_bool2
endian_write_u8_little(buffer + offset, packet->unk_bool2);
offset += sizeof(u8);
printf("-- unk_bool2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool2, (u64)packet->unk_bool2, (f64)packet->unk_bool2);

// string lighting
endian_write_u32_little(buffer + offset, packet->lighting_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->lighting_length, (u64)packet->lighting_length, (f64)packet->lighting_length);
for (u32 lighting_iter = 0; lighting_iter < packet->lighting_length; lighting_iter++)
{
endian_write_i8_little(buffer + offset, packet->lighting[lighting_iter]);
offset++;
}

// u8 unk_bool3
endian_write_u8_little(buffer + offset, packet->unk_bool3);
offset += sizeof(u8);
printf("-- unk_bool3               \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool3, (u64)packet->unk_bool3, (f64)packet->unk_bool3);

} break;

case Zone_Packet_Kind_ReferenceDataWeaponDefinitions:
{
printf("[*] Packing ReferenceDataWeaponDefinitions...\n");
Zone_Packet_ReferenceDataWeaponDefinitions* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x17);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4);
offset += sizeof(u16);

// stream weapon_byteswithlength
void* weapon_byteswithlength_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength_length, (u64)packet->weapon_byteswithlength_length, (f64)packet->weapon_byteswithlength_length);

u32 will_pack_weapon_byteswithlength = packet->weapon_byteswithlength_length == ~(u32)0 ? 0 : 1;
for (u32 weapon_byteswithlength_iter = 0; weapon_byteswithlength_iter < will_pack_weapon_byteswithlength; weapon_byteswithlength_iter++)
{
// list weapon_defs
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count);

for (u32 weapon_defs_iter = 0; weapon_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count; weapon_defs_iter++)
{
// u32 id1
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1);
offset += sizeof(u32);
printf("-- id1                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1);

// u32 id2
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2);
offset += sizeof(u32);
printf("-- id2                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2);

// u32 weapon_group_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id);
offset += sizeof(u32);
printf("-- weapon_group_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id);

// u8 flags1
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1);
offset += sizeof(u8);
printf("-- flags1                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1);

// u32 equip_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms);
offset += sizeof(u32);
printf("-- equip_ms                \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms);

// u32 unequip_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms);
offset += sizeof(u32);
printf("-- unequip_ms              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms);

// u32 from_passive_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms);
offset += sizeof(u32);
printf("-- from_passive_ms         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms);

// u32 to_passive_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms);
offset += sizeof(u32);
printf("-- to_passive_ms           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms);

// u32 xp_category
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category);
offset += sizeof(u32);
printf("-- xp_category             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category);

// u32 to_iron_sights_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms);
offset += sizeof(u32);
printf("-- to_iron_sights_ms       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms);

// u32 from_iron_sights_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms);
offset += sizeof(u32);
printf("-- from_iron_sights_ms     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms);

// u32 to_iron_sights_anim_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms);
offset += sizeof(u32);
printf("-- to_iron_sights_anim_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms);

// u32 from_iron_sights_anim_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms);
offset += sizeof(u32);
printf("-- from_iron_sights_anim_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms);

// u32 sprint_recovery_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms);
offset += sizeof(u32);
printf("-- sprint_recovery_ms      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms);

// u32 next_use_delay_msec
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec);
offset += sizeof(u32);
printf("-- next_use_delay_msec     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec);

// f32 turn_rate_modifier
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier);
offset += sizeof(f32);
printf("-- turn_rate_modifier      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier);

// f32 movement_speed_modifier
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier);
offset += sizeof(f32);
printf("-- movement_speed_modifier \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier);

// u32 propulsion_type
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type);
offset += sizeof(u32);
printf("-- propulsion_type         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type);

// u32 heat_bleed_off_rate
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate);
offset += sizeof(u32);
printf("-- heat_bleed_off_rate     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate);

// u32 heat_capacity
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity);
offset += sizeof(u32);
printf("-- heat_capacity           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity);

// u32 overheat_penalty_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms);
offset += sizeof(u32);
printf("-- overheat_penalty_ms     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms);

// u32 range_string_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id);
offset += sizeof(u32);
printf("-- range_string_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id);

// u32 melee_detect_width
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width);
offset += sizeof(u32);
printf("-- melee_detect_width      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width);

// u32 melee_detect_height
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height);
offset += sizeof(u32);
printf("-- melee_detect_height     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height);

// string anim_set_name
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length);
for (u32 anim_set_name_iter = 0; anim_set_name_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length; anim_set_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name[anim_set_name_iter]);
offset++;
}

// u32 vehicle_fp_camera_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id);
offset += sizeof(u32);
printf("-- vehicle_fp_camera_id    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id);

// u32 vehicle_tp_camera_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id);
offset += sizeof(u32);
printf("-- vehicle_tp_camera_id    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id);

// u32 overheat_effect_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id);
offset += sizeof(u32);
printf("-- overheat_effect_id      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id);

// f32 min_pitch
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch);
offset += sizeof(f32);
printf("-- min_pitch               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch);

// f32 max_pitch
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch);
offset += sizeof(f32);
printf("-- max_pitch               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch);

// u32 audio_game_object
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object);
offset += sizeof(u32);
printf("-- audio_game_object       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object);

// list ammo_slots
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count);

for (u32 ammo_slots_iter = 0; ammo_slots_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count; ammo_slots_iter++)
{
// u32 ammo_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id);
offset += sizeof(u32);
printf("-- ammo_id                 \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id);

// u32 clip_size
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size);
offset += sizeof(u32);
printf("-- clip_size               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size);

// u32 capacity
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity);
offset += sizeof(u32);
printf("-- capacity                \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity);

// b8 start_empty
endian_write_b8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty);
offset += sizeof(b8);
printf("-- start_empty             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty);

// u32 refill_ammo_per_tick
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick);
offset += sizeof(u32);
printf("-- refill_ammo_per_tick    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick);

// u32 refill_ammo_delay_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms);
offset += sizeof(u32);
printf("-- refill_ammo_delay_ms    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms);

// u32 clip_attachment_slot
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot);
offset += sizeof(u32);
printf("-- clip_attachment_slot    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot);

// string clip_model_name
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length);
for (u32 clip_model_name_iter = 0; clip_model_name_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length; clip_model_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name[clip_model_name_iter]);
offset++;
}

// string reload_weapon_bone
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length);
for (u32 reload_weapon_bone_iter = 0; reload_weapon_bone_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length; reload_weapon_bone_iter++)
{
endian_write_i8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone[reload_weapon_bone_iter]);
offset++;
}

// string reload_character_bone
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length);
for (u32 reload_character_bone_iter = 0; reload_character_bone_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length; reload_character_bone_iter++)
{
endian_write_i8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone[reload_character_bone_iter]);
offset++;
}

} // ammo_slots

// list fire_groups
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count);

for (u32 fire_groups_iter = 0; fire_groups_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count; fire_groups_iter++)
{
// u32 fire_group_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id);
offset += sizeof(u32);
printf("-- fire_group_id           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id);

} // fire_groups

} // weapon_defs

// list fire_group_defs
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count);

for (u32 fire_group_defs_iter = 0; fire_group_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count; fire_group_defs_iter++)
{
// u32 id3
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3);
offset += sizeof(u32);
printf("-- id3                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3);

// u32 id4
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4);
offset += sizeof(u32);
printf("-- id4                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4);

// list fire_mode_list
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count);

for (u32 fire_mode_list_iter = 0; fire_mode_list_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count; fire_mode_list_iter++)
{
// u32 fire_mode_1
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1);
offset += sizeof(u32);
printf("-- fire_mode_1             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1);

} // fire_mode_list

// u8 flags2
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2);
offset += sizeof(u8);
printf("-- flags2                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2);

// u32 chamber_duration_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms);
offset += sizeof(u32);
printf("-- chamber_duration_ms     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms);

// u32 image_set_override
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override);
offset += sizeof(u32);
printf("-- image_set_override      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override);

// u32 transition_duration_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms);
offset += sizeof(u32);
printf("-- transition_duration_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms);

// u32 anim_actor_slot_override
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override);
offset += sizeof(u32);
printf("-- anim_actor_slot_override\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override);

// u32 deployable_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id);
offset += sizeof(u32);
printf("-- deployable_id           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id);

// u32 spin_up_time_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms);
offset += sizeof(u32);
printf("-- spin_up_time_ms         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms);

// u32 spin_up_movement_modifier
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier);
offset += sizeof(u32);
printf("-- spin_up_movement_modifier\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier);

// u32 spin_up_turn_rate_modifier
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier);
offset += sizeof(u32);
printf("-- spin_up_turn_rate_modifier\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier);

// u32 spool_up_time_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms);
offset += sizeof(u32);
printf("-- spool_up_time_ms        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms);

// u32 spool_up_initial_refire_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms);
offset += sizeof(u32);
printf("-- spool_up_initial_refire_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms);

} // fire_group_defs

// list fire_mode_defs
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count);

for (u32 fire_mode_defs_iter = 0; fire_mode_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count; fire_mode_defs_iter++)
{
// u32 id5
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5);
offset += sizeof(u32);
printf("-- id5                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5);

// u32 id6
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6);
offset += sizeof(u32);
printf("-- id6                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6);

// u8 flag1
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1);
offset += sizeof(u8);
printf("-- flag1                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1);

// u8 flag2
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2);
offset += sizeof(u8);
printf("-- flag2                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2);

// u8 flag3
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3);
offset += sizeof(u8);
printf("-- flag3                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3);

// u8 type
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type);
offset += sizeof(u8);
printf("-- type                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type);

// u32 ammo_item_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id);
offset += sizeof(u32);
printf("-- ammo_item_id            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id);

// u8 ammo_slot
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot);
offset += sizeof(u8);
printf("-- ammo_slot               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot);

// u8 burst_count
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count);
offset += sizeof(u8);
printf("-- burst_count             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count);

// u16 fire_duration_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms);
offset += sizeof(u16);
printf("-- fire_duration_ms        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms);

// u16 fire_cooldown_duration_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms);
offset += sizeof(u16);
printf("-- fire_cooldown_duration_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms);

// u16 refire_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms);
offset += sizeof(u16);
printf("-- refire_time_ms          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms);

// u16 auto_fire_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms);
offset += sizeof(u16);
printf("-- auto_fire_time_ms       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms);

// u16 cook_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms);
offset += sizeof(u16);
printf("-- cook_time_ms            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms);

// f32 range
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range);
offset += sizeof(f32);
printf("-- range                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range);

// u8 ammo_per_shot
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot);
offset += sizeof(u8);
printf("-- ammo_per_shot           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot);

// u16 reload_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms);
offset += sizeof(u16);
printf("-- reload_time_ms          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms);

// u16 reload_chamber_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms);
offset += sizeof(u16);
printf("-- reload_chamber_time_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms);

// u16 reload_ammo_fill_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms);
offset += sizeof(u16);
printf("-- reload_ammo_fill_time_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms);

// u16 reload_loop_start_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms);
offset += sizeof(u16);
printf("-- reload_loop_start_time_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms);

// u16 reload_loop_end_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms);
offset += sizeof(u16);
printf("-- reload_loop_end_time_ms \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms);

// u8 pellets_per_shot
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot);
offset += sizeof(u8);
printf("-- pellets_per_shot        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot);

// f32 pellet_spread
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread);
offset += sizeof(f32);
printf("-- pellet_spread           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread);

// f32 cof_recoil
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil);
offset += sizeof(f32);
printf("-- cof_recoil              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil);

// f32 cof_scalar
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar);
offset += sizeof(f32);
printf("-- cof_scalar              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar);

// f32 cof_scalar_moving
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving);
offset += sizeof(f32);
printf("-- cof_scalar_moving       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving);

// f32 cof_override
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override);
offset += sizeof(f32);
printf("-- cof_override            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override);

// f32 recoil_angle_min
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min);
offset += sizeof(f32);
printf("-- recoil_angle_min        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min);

// f32 recoil_angle_max
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max);
offset += sizeof(f32);
printf("-- recoil_angle_max        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max);

// f32 recoil_horizontal_tolerance
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance);
offset += sizeof(f32);
printf("-- recoil_horizontal_tolerance\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance);

// f32 recoil_horizontal_min
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min);
offset += sizeof(f32);
printf("-- recoil_horizontal_min   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min);

// f32 recoil_horizontal_max
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max);
offset += sizeof(f32);
printf("-- recoil_horizontal_max   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max);

// f32 recoil_magnitude_min
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min);
offset += sizeof(f32);
printf("-- recoil_magnitude_min    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min);

// f32 recoil_magnitude_max
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max);
offset += sizeof(f32);
printf("-- recoil_magnitude_max    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max);

// u16 recoil_recovery_delay_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms);
offset += sizeof(u16);
printf("-- recoil_recovery_delay_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms);

// f32 recoil_recovery_rate
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate);
offset += sizeof(f32);
printf("-- recoil_recovery_rate    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate);

// f32 recoil_recovery_acceleration
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration);
offset += sizeof(f32);
printf("-- recoil_recovery_acceleration\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration);

// u8 recoil_shots_at_min_magnitude
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude);
offset += sizeof(u8);
printf("-- recoil_shots_at_min_magnitude\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude);

// f32 recoil_max_total_magnitude
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude);
offset += sizeof(f32);
printf("-- recoil_max_total_magnitude\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude);

// f32 recoil_increase
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase);
offset += sizeof(f32);
printf("-- recoil_increase         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase);

// f32 recoil_increase_crouched
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched);
offset += sizeof(f32);
printf("-- recoil_increase_crouched\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched);

// f32 recoil_first_shot_modifier
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier);
offset += sizeof(f32);
printf("-- recoil_first_shot_modifier\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier);

// f32 recoil_horizontal_min_increase
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase);
offset += sizeof(f32);
printf("-- recoil_horizontal_min_increase\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase);

// f32 recoil_horizontal_max_increase
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase);
offset += sizeof(f32);
printf("-- recoil_horizontal_max_increase\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase);

// u16 fire_detect_range
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range);
offset += sizeof(u16);
printf("-- fire_detect_range       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range);

// f32 effect_group
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group);
offset += sizeof(f32);
printf("-- effect_group            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group);

// f32 player_state_group_id
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id);
offset += sizeof(f32);
printf("-- player_state_group_id   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id);

// f32 movement_modifier
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier);
offset += sizeof(f32);
printf("-- movement_modifier       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier);

// f32 turn_modifier
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier);
offset += sizeof(f32);
printf("-- turn_modifier           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier);

// f32 lock_on_icon_id
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id);
offset += sizeof(f32);
printf("-- lock_on_icon_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id);

// f32 lock_on_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle);
offset += sizeof(f32);
printf("-- lock_on_angle           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle);

// f32 lock_on_radius
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius);
offset += sizeof(f32);
printf("-- lock_on_radius          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius);

// f32 lock_on_range
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range);
offset += sizeof(f32);
printf("-- lock_on_range           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range);

// f32 lock_on_range_close
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close);
offset += sizeof(f32);
printf("-- lock_on_range_close     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close);

// f32 lock_on_range_far
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far);
offset += sizeof(f32);
printf("-- lock_on_range_far       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far);

// u16 lock_on_acquire_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms);
offset += sizeof(u16);
printf("-- lock_on_acquire_time_ms \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms);

// u16 lock_on_acquire_time_close_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms);
offset += sizeof(u16);
printf("-- lock_on_acquire_time_close_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms);

// u16 lock_on_acquire_time_far_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms);
offset += sizeof(u16);
printf("-- lock_on_acquire_time_far_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms);

// u16 lock_on_lose_time_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms);
offset += sizeof(u16);
printf("-- lock_on_lose_time_ms    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms);

// f32 default_zoom
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom);
offset += sizeof(f32);
printf("-- default_zoom            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom);

// f32 fp_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x);
offset += sizeof(f32);
printf("-- fp_offset_x             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x);

// f32 fp_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y);
offset += sizeof(f32);
printf("-- fp_offset_y             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y);

// f32 fp_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z);
offset += sizeof(f32);
printf("-- fp_offset_z             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z);

// u8 reticle_id
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id);
offset += sizeof(u8);
printf("-- reticle_id              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id);

// u8 full_screen_effect
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect);
offset += sizeof(u8);
printf("-- full_screen_effect      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect);

// u32 heat_per_shot
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot);
offset += sizeof(u32);
printf("-- heat_per_shot           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot);

// u32 heat_threshold
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold);
offset += sizeof(u32);
printf("-- heat_threshold          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold);

// u16 heat_recovery_delay_ms
endian_write_u16_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms);
offset += sizeof(u16);
printf("-- heat_recovery_delay_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms);

// f32 sway_amplitude_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x);
offset += sizeof(f32);
printf("-- sway_amplitude_x        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x);

// f32 sway_amplitude_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y);
offset += sizeof(f32);
printf("-- sway_amplitude_y        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y);

// f32 sway_period_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x);
offset += sizeof(f32);
printf("-- sway_period_x           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x);

// f32 sway_period_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y);
offset += sizeof(f32);
printf("-- sway_period_y           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y);

// f32 sway_initial_y_offset
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset);
offset += sizeof(f32);
printf("-- sway_initial_y_offset   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset);

// f32 arms_fov_scalar
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar);
offset += sizeof(f32);
printf("-- arms_fov_scalar         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar);

// f32 anim_kick_magnitude
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude);
offset += sizeof(f32);
printf("-- anim_kick_magnitude     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude);

// f32 anim_recoil_magnitude
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude);
offset += sizeof(f32);
printf("-- anim_recoil_magnitude   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude);

// u32 description_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id);

// u32 indirect_effect
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect);
offset += sizeof(u32);
printf("-- indirect_effect         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect);

// f32 bullet_arc_kick_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle);
offset += sizeof(f32);
printf("-- bullet_arc_kick_angle   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle);

// f32 projectile_speed_override
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override);
offset += sizeof(f32);
printf("-- projectile_speed_override\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override);

// u32 inherit_from_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id);
offset += sizeof(u32);
printf("-- inherit_from_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id);

// f32 inherit_from_charge_power
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power);
offset += sizeof(f32);
printf("-- inherit_from_charge_power\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power);

// u32 hud_image_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id);
offset += sizeof(u32);
printf("-- hud_image_id            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id);

// u32 target_requirement
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement);
offset += sizeof(u32);
printf("-- target_requirement      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement);

// u32 fire_anim_duration_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms);
offset += sizeof(u32);
printf("-- fire_anim_duration_ms   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms);

// u8 sequential_fire_anim_start
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start);
offset += sizeof(u8);
printf("-- sequential_fire_anim_start\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start);

// u8 sequential_fire_anim_count
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count);
offset += sizeof(u8);
printf("-- sequential_fire_anim_count\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count);

// f32 cylof_recoil
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil);
offset += sizeof(f32);
printf("-- cylof_recoil            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil);

// f32 cylof_scalar
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar);
offset += sizeof(f32);
printf("-- cylof_scalar            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar);

// f32 cylof_scalar_moving
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving);
offset += sizeof(f32);
printf("-- cylof_scalar_moving     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving);

// f32 cylof_override
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override);
offset += sizeof(f32);
printf("-- cylof_override          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override);

// u32 melee_composite_effect_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id);
offset += sizeof(u32);
printf("-- melee_composite_effect_id\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id);

// u32 melee_ability_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id);
offset += sizeof(u32);
printf("-- melee_ability_id        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id);

// f32 sway_crouch_scalar
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar);
offset += sizeof(f32);
printf("-- sway_crouch_scalar      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar);

// f32 sway_prone_scalar
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar);
offset += sizeof(f32);
printf("-- sway_prone_scalar       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar);

// f32 launch_pitch_additive_degrees
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees);
offset += sizeof(f32);
printf("-- launch_pitch_additive_degrees\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees);

// b8 tp_force_camera_overrides
endian_write_b8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides);
offset += sizeof(b8);
printf("-- tp_force_camera_overrides\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides);

// f32 tp_camera_look_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_x \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x);

// f32 tp_camera_look_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_y \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y);

// f32 tp_camera_look_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_z \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z);

// f32 tp_camera_position_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x);
offset += sizeof(f32);
printf("-- tp_camera_position_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x);

// f32 tp_camera_position_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y);
offset += sizeof(f32);
printf("-- tp_camera_position_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y);

// f32 tp_camera_position_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z);
offset += sizeof(f32);
printf("-- tp_camera_position_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z);

// f32 tp_camera_fov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov);
offset += sizeof(f32);
printf("-- tp_camera_fov           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov);

// b8 fp_force_camera_overrides
endian_write_b8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides);
offset += sizeof(b8);
printf("-- fp_force_camera_overrides\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides);

// f32 tp_extra_lead_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_extra_lead_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a);

// f32 tp_extra_lead_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_extra_lead_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b);

// f32 tp_extra_lead_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a);
offset += sizeof(f32);
printf("-- tp_extra_lead_pitch_a   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a);

// f32 tp_extra_lead_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b);
offset += sizeof(f32);
printf("-- tp_extra_lead_pitch_b   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b);

// f32 tp_extra_height_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_extra_height_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a);

// f32 tp_extra_height_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_extra_height_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b);

// f32 tp_extra_height_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a);
offset += sizeof(f32);
printf("-- tp_extra_height_pitch_a \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a);

// f32 tp_extra_height_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b);
offset += sizeof(f32);
printf("-- tp_extra_height_pitch_b \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b);

// f32 fp_camera_fov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov);
offset += sizeof(f32);
printf("-- fp_camera_fov           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov);

// f32 tp_cr_camera_look_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x);

// f32 tp_cr_camera_look_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y);

// f32 tp_cr_camera_look_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z);

// f32 tp_cr_camera_position_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x);
offset += sizeof(f32);
printf("-- tp_cr_camera_position_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x);

// f32 tp_cr_camera_position_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y);
offset += sizeof(f32);
printf("-- tp_cr_camera_position_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y);

// f32 tp_cr_camera_position_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z);
offset += sizeof(f32);
printf("-- tp_cr_camera_position_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z);

// f32 tp_pr_camera_look_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x);
offset += sizeof(f32);
printf("-- tp_pr_camera_look_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x);

// f32 tp_pr_camera_look_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y);
offset += sizeof(f32);
printf("-- tp_pr_camera_look_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y);

// f32 tp_pr_camera_look_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z);
offset += sizeof(f32);
printf("-- tp_pr_camera_look_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z);

// f32 tp_pr_camera_position_offset_x
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x);
offset += sizeof(f32);
printf("-- tp_pr_camera_position_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x);

// f32 tp_pr_camera_position_offset_y
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y);
offset += sizeof(f32);
printf("-- tp_pr_camera_position_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y);

// f32 tp_pr_camera_position_offset_z
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z);
offset += sizeof(f32);
printf("-- tp_pr_camera_position_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z);

// f32 tp_cr_extra_lead_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a);

// f32 tp_cr_extra_lead_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b);

// f32 tp_cr_extra_lead_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a);

// f32 tp_cr_extra_lead_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b);

// f32 tp_cr_extra_height_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a);

// f32 tp_cr_extra_height_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b);

// f32 tp_cr_extra_height_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a);

// f32 tp_cr_extra_height_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b);

// f32 tp_pr_extra_lead_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a);

// f32 tp_pr_extra_lead_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b);

// f32 tp_pr_extra_lead_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a);

// f32 tp_pr_extra_lead_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b);

// f32 tp_pr_extra_height_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a);

// f32 tp_pr_extra_height_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b);

// f32 tp_pr_extra_height_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a);

// f32 tp_pr_extra_height_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b);

// f32 tp_camera_distance
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance);
offset += sizeof(f32);
printf("-- tp_camera_distance      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance);

// f32 tp_cr_camera_distance
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance);
offset += sizeof(f32);
printf("-- tp_cr_camera_distance   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance);

// f32 tp_pr_camera_distance
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance);
offset += sizeof(f32);
printf("-- tp_pr_camera_distance   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance);

// f32 tp_cr_camera_fov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov);
offset += sizeof(f32);
printf("-- tp_cr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov);

// f32 tp_pr_camera_fov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov);
offset += sizeof(f32);
printf("-- tp_pr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov);

// f32 fp_cr_camera_fov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov);
offset += sizeof(f32);
printf("-- fp_cr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov);

// f32 fp_pr_camera_fov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov);
offset += sizeof(f32);
printf("-- fp_pr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov);

// b8 force_fp_scope
endian_write_b8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope);
offset += sizeof(b8);
printf("-- force_fp_scope          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope);

// u32 aim_assist_config
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config);
offset += sizeof(u32);
printf("-- aim_assist_config       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config);

// b8 allow_depth_adjustment
endian_write_b8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment);
offset += sizeof(b8);
printf("-- allow_depth_adjustment  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment);

// f32 tp_extra_draw_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_extra_draw_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a);

// f32 tp_extra_draw_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_extra_draw_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b);

// f32 tp_extra_draw_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a);
offset += sizeof(f32);
printf("-- tp_extra_draw_pitch_a   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a);

// f32 tp_extra_draw_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b);
offset += sizeof(f32);
printf("-- tp_extra_draw_pitch_b   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b);

// f32 tp_cr_extra_draw_from_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a);

// f32 tp_cr_extra_draw_from_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b);

// f32 tp_cr_extra_draw_pitch_a
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a);

// f32 tp_cr_extra_draw_pitch_b
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b);

// f32 tp_camera_pos_offset_y_mov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov);
offset += sizeof(f32);
printf("-- tp_camera_pos_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov);

// f32 tp_camera_look_offset_y_mov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov);

// f32 tp_cr_camera_pos_offset_y_mov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov);
offset += sizeof(f32);
printf("-- tp_cr_camera_pos_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov);

// f32 tp_cr_camera_look_offset_y_mov
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov);

// b8 tp_allow_move_heights
endian_write_b8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights);
offset += sizeof(b8);
printf("-- tp_allow_move_heights   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights);

} // fire_mode_defs

// list player_state_group_defs
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count);

for (u32 player_state_group_defs_iter = 0; player_state_group_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count; player_state_group_defs_iter++)
{
// u32 id7
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7);
offset += sizeof(u32);
printf("-- id7                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7);

// u32 _id8
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8);
offset += sizeof(u32);
printf("-- _id8                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8);

// list player_state_properties
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count);

for (u32 player_state_properties_iter = 0; player_state_properties_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count; player_state_properties_iter++)
{
// u32 group_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id);
offset += sizeof(u32);
printf("-- group_id                \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id);

// u32 id9
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9);
offset += sizeof(u32);
printf("-- id9                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9);

// u8 flags3
endian_write_u8_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3);
offset += sizeof(u8);
printf("-- flags3                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3);

// f32 min_cof
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof);
offset += sizeof(f32);
printf("-- min_cof                 \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof);

// f32 max_cof
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof);
offset += sizeof(f32);
printf("-- max_cof                 \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof);

// f32 cof_recovery_rate
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate);
offset += sizeof(f32);
printf("-- cof_recovery_rate       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate);

// f32 cof_turn_penalty
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty);
offset += sizeof(f32);
printf("-- cof_turn_penalty        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty);

// u32 shots_before_cof_penalty
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty);
offset += sizeof(u32);
printf("-- shots_before_cof_penalty\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty);

// f32 cof_recovery_delay_threshold
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold);
offset += sizeof(f32);
printf("-- cof_recovery_delay_threshold\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold);

// u32 cof_recovery_delay_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms);
offset += sizeof(u32);
printf("-- cof_recovery_delay_ms   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms);

// f32 cof_grow_rate
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate);
offset += sizeof(f32);
printf("-- cof_grow_rate           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate);

// f32 min_cyl_of_fire
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire);
offset += sizeof(f32);
printf("-- min_cyl_of_fire         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire);

// f32 max_cyl_of_fire
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire);
offset += sizeof(f32);
printf("-- max_cyl_of_fire         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire);

// f32 cylof_recovery_rate
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate);
offset += sizeof(f32);
printf("-- cylof_recovery_rate     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate);

// f32 cylof_turn_penalty
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty);
offset += sizeof(f32);
printf("-- cylof_turn_penalty      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty);

// u32 shots_before_cylof_penalty
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty);
offset += sizeof(u32);
printf("-- shots_before_cylof_penalty\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty);

// f32 cylof_recovery_delay_threshold
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold);
offset += sizeof(f32);
printf("-- cylof_recovery_delay_threshold\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold);

// u32 cylof_recovery_delay_ms
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms);
offset += sizeof(u32);
printf("-- cylof_recovery_delay_ms \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms);

// f32 cylof_grow_rate
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate);
offset += sizeof(f32);
printf("-- cylof_grow_rate         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate);

} // player_state_properties

} // player_state_group_defs

// list fire_mode_projectile_mapping_data
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count);

for (u32 fire_mode_projectile_mapping_data_iter = 0; fire_mode_projectile_mapping_data_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count; fire_mode_projectile_mapping_data_iter++)
{
// u32 id10
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10);
offset += sizeof(u32);
printf("-- id10                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10);

// u32 id11
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11);
offset += sizeof(u32);
printf("-- id11                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11);

// u32 index
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index);
offset += sizeof(u32);
printf("-- index                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index);

// u32 projectile_definition_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id);
offset += sizeof(u32);
printf("-- projectile_definition_id\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id);

} // fire_mode_projectile_mapping_data

// list aim_assist_defs
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count);

for (u32 aim_assist_defs_iter = 0; aim_assist_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count; aim_assist_defs_iter++)
{
// u32 id12
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12);
offset += sizeof(u32);
printf("-- id12                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12);

// f32 cone_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle);
offset += sizeof(f32);
printf("-- cone_angle              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle);

// f32 cone_range
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range);
offset += sizeof(f32);
printf("-- cone_range              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range);

// f32 fall_off_cone_range
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range);
offset += sizeof(f32);
printf("-- fall_off_cone_range     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range);

// f32 magnet_cone_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle);
offset += sizeof(f32);
printf("-- magnet_cone_angle       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle);

// f32 magnet_cone_range
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range);
offset += sizeof(f32);
printf("-- magnet_cone_range       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range);

// f32 target_override_delay
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay);
offset += sizeof(f32);
printf("-- target_override_delay   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay);

// f32 target_oos_delay
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay);
offset += sizeof(f32);
printf("-- target_oos_delay        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay);

// f32 arrive_time
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time);
offset += sizeof(f32);
printf("-- arrive_time             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time);

// f32 target_motion_update_time
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time);
offset += sizeof(f32);
printf("-- target_motion_update_time\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time);

// f32 weight
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight);
offset += sizeof(f32);
printf("-- weight                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight);

// f32 min_input_weight_delay_in
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in);
offset += sizeof(f32);
printf("-- min_input_weight_delay_in\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in);

// f32 max_input_weight_delay_in
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in);
offset += sizeof(f32);
printf("-- max_input_weight_delay_in\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in);

// f32 min_input_weight_delay_out
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out);
offset += sizeof(f32);
printf("-- min_input_weight_delay_out\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out);

// f32 max_input_weight_delay_out
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out);
offset += sizeof(f32);
printf("-- max_input_weight_delay_out\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out);

// f32 min_input_actor
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor);
offset += sizeof(f32);
printf("-- min_input_actor         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor);

// f32 max_input_actor
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor);
offset += sizeof(f32);
printf("-- max_input_actor         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor);

// u32 requirement_id
endian_write_u32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id);
offset += sizeof(u32);
printf("-- requirement_id          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id);

// f32 magnet_min_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle);
offset += sizeof(f32);
printf("-- magnet_min_angle        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle);

// f32 magnet_dist_for_min_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle);
offset += sizeof(f32);
printf("-- magnet_dist_for_min_angle\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle);

// f32 magnet_max_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle);
offset += sizeof(f32);
printf("-- magnet_max_angle        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle);

// f32 magnet_dist_for_max_angle
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle);
offset += sizeof(f32);
printf("-- magnet_dist_for_max_angle\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle);

// f32 min_input_strafe_arrive_time
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time);
offset += sizeof(f32);
printf("-- min_input_strafe_arrive_time\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time);

// f32 max_input_strafe_arrive_time
endian_write_f32_little(buffer + offset, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time);
offset += sizeof(f32);
printf("-- max_input_strafe_arrive_time\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time);

} // aim_assist_defs

} // weapon_byteswithlength
endian_write_u32_little((u8*)weapon_byteswithlength_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)weapon_byteswithlength_length_ptr - sizeof(u32)));

} break;

case Zone_Packet_Kind_ObjectiveBase:
{
printf("[*] Packing ObjectiveBase...\n");
endian_write_u8_little(buffer + offset, 0x18);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_DebugBase:
{
printf("[*] Packing DebugBase...\n");
endian_write_u8_little(buffer + offset, 0x19);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_UiBase:
{
printf("[*] Packing UiBase...\n");
endian_write_u8_little(buffer + offset, 0x1a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_QuestBase:
{
printf("[*] Packing QuestBase...\n");
endian_write_u8_little(buffer + offset, 0x1b);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RewardBase:
{
printf("[*] Packing RewardBase...\n");
endian_write_u8_little(buffer + offset, 0x1c);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GameTimeSync:
{
printf("[*] Packing GameTimeSync...\n");
Zone_Packet_GameTimeSync* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x1d);
offset += sizeof(u8);

// u64 time
endian_write_u64_little(buffer + offset, packet->time);
offset += sizeof(u64);
printf("-- time                    \t%lld\t%llxh\t%f\n", (i64)packet->time, (u64)packet->time, (f64)packet->time);

// f32 cycle_speed
endian_write_f32_little(buffer + offset, packet->cycle_speed);
offset += sizeof(f32);
printf("-- cycle_speed             \t%lld\t%llxh\t%f\n", (i64)packet->cycle_speed, (u64)packet->cycle_speed, (f64)packet->cycle_speed);

// b8 unk_bool
endian_write_b8_little(buffer + offset, packet->unk_bool);
offset += sizeof(b8);
printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

} break;

case Zone_Packet_Kind_PetBase:
{
printf("[*] Packing PetBase...\n");
endian_write_u8_little(buffer + offset, 0x1e);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PointOfInterestDefinitionRequest:
{
printf("[*] Packing PointOfInterestDefinitionRequest...\n");
endian_write_u8_little(buffer + offset, 0x1f);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PointOfInterestDefinitionReply:
{
printf("[*] Packing PointOfInterestDefinitionReply...\n");
endian_write_u8_little(buffer + offset, 0x20);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WorldTeleportRequest:
{
printf("[*] Packing WorldTeleportRequest...\n");
endian_write_u8_little(buffer + offset, 0x21);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_TradeBase:
{
printf("[*] Packing TradeBase...\n");
endian_write_u8_little(buffer + offset, 0x22);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_EscrowGivePackage:
{
printf("[*] Packing EscrowGivePackage...\n");
endian_write_u8_little(buffer + offset, 0x23);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_EscrowGotPackage:
{
printf("[*] Packing EscrowGotPackage...\n");
endian_write_u8_little(buffer + offset, 0x24);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_UpdateEncounterDataCommon:
{
printf("[*] Packing UpdateEncounterDataCommon...\n");
endian_write_u8_little(buffer + offset, 0x25);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RecipeBase:
{
printf("[*] Packing RecipeBase...\n");
endian_write_u8_little(buffer + offset, 0x26);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_InGamePurchaseBase:
{
printf("[*] Packing InGamePurchaseBase...\n");
endian_write_u8_little(buffer + offset, 0x27);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_QuickChatBase:
{
printf("[*] Packing QuickChatBase...\n");
endian_write_u8_little(buffer + offset, 0x28);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ReportBase:
{
printf("[*] Packing ReportBase...\n");
endian_write_u8_little(buffer + offset, 0x29);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LiveGamerBase:
{
printf("[*] Packing LiveGamerBase...\n");
endian_write_u8_little(buffer + offset, 0x2a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AcquaintanceBase:
{
printf("[*] Packing AcquaintanceBase...\n");
endian_write_u8_little(buffer + offset, 0x2b);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientServerShuttingDown:
{
printf("[*] Packing ClientServerShuttingDown...\n");
endian_write_u8_little(buffer + offset, 0x2c);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_FriendBase:
{
printf("[*] Packing FriendBase...\n");
endian_write_u8_little(buffer + offset, 0x2d);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_BroadcastBase:
{
printf("[*] Packing BroadcastBase...\n");
endian_write_u8_little(buffer + offset, 0x2e);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientKickedFromServer:
{
printf("[*] Packing ClientKickedFromServer...\n");
endian_write_u8_little(buffer + offset, 0x2f);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_UpdateClientSessionData:
{
printf("[*] Packing UpdateClientSessionData...\n");
endian_write_u8_little(buffer + offset, 0x30);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_BugSubmissionBase:
{
printf("[*] Packing BugSubmissionBase...\n");
endian_write_u8_little(buffer + offset, 0x31);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WorldDisplayInfo:
{
printf("[*] Packing WorldDisplayInfo...\n");
endian_write_u8_little(buffer + offset, 0x32);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_MOTD:
{
printf("[*] Packing MOTD...\n");
endian_write_u8_little(buffer + offset, 0x33);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SetLocale:
{
printf("[*] Packing SetLocale...\n");
Zone_Packet_SetLocale* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x34);
offset += sizeof(u8);

// string locale
endian_write_u32_little(buffer + offset, packet->locale_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->locale_length, (u64)packet->locale_length, (f64)packet->locale_length);
for (u32 locale_iter = 0; locale_iter < packet->locale_length; locale_iter++)
{
endian_write_i8_little(buffer + offset, packet->locale[locale_iter]);
offset++;
}

} break;

case Zone_Packet_Kind_SetClientArea:
{
printf("[*] Packing SetClientArea...\n");
endian_write_u8_little(buffer + offset, 0x35);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ZoneTeleportRequest:
{
printf("[*] Packing ZoneTeleportRequest...\n");
endian_write_u8_little(buffer + offset, 0x36);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_TradingCardBase:
{
printf("[*] Packing TradingCardBase...\n");
endian_write_u8_little(buffer + offset, 0x37);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WorldShutdownNotice:
{
printf("[*] Packing WorldShutdownNotice...\n");
endian_write_u8_little(buffer + offset, 0x38);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LoadWelcomeScreen:
{
printf("[*] Packing LoadWelcomeScreen...\n");
endian_write_u8_little(buffer + offset, 0x39);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ShipCombatBase:
{
printf("[*] Packing ShipCombatBase...\n");
endian_write_u8_little(buffer + offset, 0x3a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_KeepAlive:
{
printf("[*] Packing KeepAlive...\n");
Zone_Packet_KeepAlive* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x3c);
offset += sizeof(u8);

// u32 game_time
endian_write_u32_little(buffer + offset, packet->game_time);
offset += sizeof(u32);
printf("-- game_time               \t%lld\t%llxh\t%f\n", (i64)packet->game_time, (u64)packet->game_time, (f64)packet->game_time);

} break;

case Zone_Packet_Kind_ClientExitLaunchUri:
{
printf("[*] Packing ClientExitLaunchUri...\n");
endian_write_u8_little(buffer + offset, 0x3d);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientPath:
{
printf("[*] Packing ClientPath...\n");
endian_write_u8_little(buffer + offset, 0x3e);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientPendingKickFromServer:
{
printf("[*] Packing ClientPendingKickFromServer...\n");
endian_write_u8_little(buffer + offset, 0x3f);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientMembershipActivation:
{
printf("[*] Packing ClientMembershipActivation...\n");
endian_write_u8_little(buffer + offset, 0x40);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LobbyBase:
{
printf("[*] Packing LobbyBase...\n");
endian_write_u8_little(buffer + offset, 0x41);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LobbyGameDefinitionBase:
{
printf("[*] Packing LobbyGameDefinitionBase...\n");
endian_write_u8_little(buffer + offset, 0x42);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ShowSystemMessage:
{
printf("[*] Packing ShowSystemMessage...\n");
endian_write_u8_little(buffer + offset, 0x43);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_POIChangeMessage:
{
printf("[*] Packing POIChangeMessage...\n");
endian_write_u8_little(buffer + offset, 0x44);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientMetrics:
{
printf("[*] Packing ClientMetrics...\n");
endian_write_u8_little(buffer + offset, 0x45);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_FirstTimeEventBase:
{
printf("[*] Packing FirstTimeEventBase...\n");
endian_write_u8_little(buffer + offset, 0x46);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClaimBase:
{
printf("[*] Packing ClaimBase...\n");
endian_write_u8_little(buffer + offset, 0x47);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientLog:
{
printf("[*] Packing ClientLog...\n");
Zone_Packet_ClientLog* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x48);
offset += sizeof(u8);

// string file
endian_write_u32_little(buffer + offset, packet->file_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->file_length, (u64)packet->file_length, (f64)packet->file_length);
for (u32 file_iter = 0; file_iter < packet->file_length; file_iter++)
{
endian_write_i8_little(buffer + offset, packet->file[file_iter]);
offset++;
}

// string message
endian_write_u32_little(buffer + offset, packet->message_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->message_length, (u64)packet->message_length, (f64)packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
endian_write_i8_little(buffer + offset, packet->message[message_iter]);
offset++;
}

} break;

case Zone_Packet_Kind_IgnoreBase:
{
printf("[*] Packing IgnoreBase...\n");
endian_write_u8_little(buffer + offset, 0x49);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SnoopedPlayerBase:
{
printf("[*] Packing SnoopedPlayerBase...\n");
endian_write_u8_little(buffer + offset, 0x4a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PromotionalBase:
{
printf("[*] Packing PromotionalBase...\n");
endian_write_u8_little(buffer + offset, 0x4b);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AddClientPortraitCrc:
{
printf("[*] Packing AddClientPortraitCrc...\n");
endian_write_u8_little(buffer + offset, 0x4c);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ObjectiveTargetBase:
{
printf("[*] Packing ObjectiveTargetBase...\n");
endian_write_u8_little(buffer + offset, 0x4d);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_CommerceSessionRequest:
{
printf("[*] Packing CommerceSessionRequest...\n");
endian_write_u8_little(buffer + offset, 0x4e);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CommerceSessionResponse:
{
printf("[*] Packing CommerceSessionResponse...\n");
endian_write_u8_little(buffer + offset, 0x4f);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_TrackedEvent:
{
printf("[*] Packing TrackedEvent...\n");
endian_write_u8_little(buffer + offset, 0x50);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientLoginFailed:
{
printf("[*] Packing ClientLoginFailed...\n");
endian_write_u8_little(buffer + offset, 0x51);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LoginToUChat:
{
printf("[*] Packing LoginToUChat...\n");
endian_write_u8_little(buffer + offset, 0x52);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ZoneSafeTeleportRequest:
{
printf("[*] Packing ZoneSafeTeleportRequest...\n");
endian_write_u8_little(buffer + offset, 0x53);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RemoteInteractionRequest:
{
printf("[*] Packing RemoteInteractionRequest...\n");
endian_write_u8_little(buffer + offset, 0x54);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_UpdateCamera:
{
printf("[*] Packing UpdateCamera...\n");
endian_write_u8_little(buffer + offset, 0x57);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GuildBase:
{
printf("[*] Packing GuildBase...\n");
endian_write_u8_little(buffer + offset, 0x59);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AdminGuildBase:
{
printf("[*] Packing AdminGuildBase...\n");
endian_write_u8_little(buffer + offset, 0x5a);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_BattleMagesBase:
{
printf("[*] Packing BattleMagesBase...\n");
endian_write_u8_little(buffer + offset, 0x5b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WorldToWorldBase:
{
printf("[*] Packing WorldToWorldBase...\n");
endian_write_u8_little(buffer + offset, 0x5c);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_PerformAction:
{
printf("[*] Packing PerformAction...\n");
endian_write_u8_little(buffer + offset, 0x5d);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_EncounterMatchmakingBase:
{
printf("[*] Packing EncounterMatchmakingBase...\n");
endian_write_u8_little(buffer + offset, 0x5e);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientLuaMetrics:
{
printf("[*] Packing ClientLuaMetrics...\n");
endian_write_u8_little(buffer + offset, 0x5f);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_RepeatingActivityBase:
{
printf("[*] Packing RepeatingActivityBase...\n");
endian_write_u8_little(buffer + offset, 0x60);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientGameSettings:
{
printf("[*] Packing ClientGameSettings...\n");
Zone_Packet_ClientGameSettings* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x61);
offset += sizeof(u8);

// u32 unk_u32
endian_write_u32_little(buffer + offset, packet->unk_u32);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 interact_glow_and_dist
endian_write_u32_little(buffer + offset, packet->interact_glow_and_dist);
offset += sizeof(u32);
printf("-- interact_glow_and_dist  \t%lld\t%llxh\t%f\n", (i64)packet->interact_glow_and_dist, (u64)packet->interact_glow_and_dist, (f64)packet->interact_glow_and_dist);

// u8 unk_bool
endian_write_u8_little(buffer + offset, packet->unk_bool);
offset += sizeof(u8);
printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

// f32 timescale
endian_write_f32_little(buffer + offset, packet->timescale);
offset += sizeof(f32);
printf("-- timescale               \t%lld\t%llxh\t%f\n", (i64)packet->timescale, (u64)packet->timescale, (f64)packet->timescale);

// u32 enable_weapons
endian_write_u32_little(buffer + offset, packet->enable_weapons);
offset += sizeof(u32);
printf("-- enable_weapons          \t%lld\t%llxh\t%f\n", (i64)packet->enable_weapons, (u64)packet->enable_weapons, (f64)packet->enable_weapons);

// u32 unk_u32_2
endian_write_u32_little(buffer + offset, packet->unk_u32_2);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_2, (u64)packet->unk_u32_2, (f64)packet->unk_u32_2);

// f32 unk_float1
endian_write_f32_little(buffer + offset, packet->unk_float1);
offset += sizeof(f32);
printf("-- unk_float1              \t%lld\t%llxh\t%f\n", (i64)packet->unk_float1, (u64)packet->unk_float1, (f64)packet->unk_float1);

// f32 unk_float2
endian_write_f32_little(buffer + offset, packet->unk_float2);
offset += sizeof(f32);
printf("-- unk_float2              \t%lld\t%llxh\t%f\n", (i64)packet->unk_float2, (u64)packet->unk_float2, (f64)packet->unk_float2);

// f32 damage_multiplier
endian_write_f32_little(buffer + offset, packet->damage_multiplier);
offset += sizeof(f32);
printf("-- damage_multiplier       \t%lld\t%llxh\t%f\n", (i64)packet->damage_multiplier, (u64)packet->damage_multiplier, (f64)packet->damage_multiplier);

} break;

case Zone_Packet_Kind_ClientTrialProfileUpsell:
{
printf("[*] Packing ClientTrialProfileUpsell...\n");
endian_write_u8_little(buffer + offset, 0x62);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ActivityManagerBase:
{
printf("[*] Packing ActivityManagerBase...\n");
endian_write_u8_little(buffer + offset, 0x63);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RequestSendItemDefinitionsToClient:
{
printf("[*] Packing RequestSendItemDefinitionsToClient...\n");
endian_write_u8_little(buffer + offset, 0x64);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_InspectBase:
{
printf("[*] Packing InspectBase...\n");
endian_write_u8_little(buffer + offset, 0x65);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_AchievementBase:
{
printf("[*] Packing AchievementBase...\n");
endian_write_u8_little(buffer + offset, 0x66);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_PlayerTitleBase:
{
printf("[*] Packing PlayerTitleBase...\n");
endian_write_u8_little(buffer + offset, 0x67);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_MatchHistoryBase:
{
printf("[*] Packing MatchHistoryBase...\n");
endian_write_u8_little(buffer + offset, 0x68);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_UpdateUserAge:
{
printf("[*] Packing UpdateUserAge...\n");
endian_write_u8_little(buffer + offset, 0x69);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LootBase:
{
printf("[*] Packing LootBase...\n");
endian_write_u8_little(buffer + offset, 0x6a);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ActionBarManagerBase:
{
printf("[*] Packing ActionBarManagerBase...\n");
endian_write_u8_little(buffer + offset, 0x6b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientTrialProfileUpsellRequest:
{
printf("[*] Packing ClientTrialProfileUpsellRequest...\n");
endian_write_u8_little(buffer + offset, 0x6c);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdateJump:
{
printf("[*] Packing PlayerUpdateJump...\n");
endian_write_u8_little(buffer + offset, 0x6d);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CoinStoreBase:
{
printf("[*] Packing CoinStoreBase...\n");
endian_write_u8_little(buffer + offset, 0x6e);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_InitializationParameters:
{
printf("[*] Packing InitializationParameters...\n");
Zone_Packet_InitializationParameters* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x6f);
offset += sizeof(u8);

// string environment
endian_write_u32_little(buffer + offset, packet->environment_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->environment_length, (u64)packet->environment_length, (f64)packet->environment_length);
for (u32 environment_iter = 0; environment_iter < packet->environment_length; environment_iter++)
{
endian_write_i8_little(buffer + offset, packet->environment[environment_iter]);
offset++;
}

// string unk_string_1
endian_write_u32_little(buffer + offset, packet->unk_string_1_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->unk_string_1_length, (u64)packet->unk_string_1_length, (f64)packet->unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->unk_string_1_length; unk_string_1_iter++)
{
endian_write_i8_little(buffer + offset, packet->unk_string_1[unk_string_1_iter]);
offset++;
}

// list ruleset_definitions
endian_write_u32_little(buffer + offset, packet->ruleset_definitions_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions_count, (u64)packet->ruleset_definitions_count, (f64)packet->ruleset_definitions_count);

for (u32 ruleset_definitions_iter = 0; ruleset_definitions_iter < packet->ruleset_definitions_count; ruleset_definitions_iter++)
{
// u32 unk_u32_1
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1);
offset += sizeof(u32);
printf("-- unk_u32_1               \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1, (u64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1, (f64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1);

// u32 unk_u32_2
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2, (u64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2, (f64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2);

// string ruleset
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length, (u64)packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length, (f64)packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length);
for (u32 ruleset_iter = 0; ruleset_iter < packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length; ruleset_iter++)
{
endian_write_i8_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].ruleset[ruleset_iter]);
offset++;
}

// string unk_string_2
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length, (u64)packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length, (f64)packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length);
for (u32 unk_string_2_iter = 0; unk_string_2_iter < packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length; unk_string_2_iter++)
{
endian_write_i8_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2[unk_string_2_iter]);
offset++;
}

// list rulesets
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count);

for (u32 rulesets_iter = 0; rulesets_iter < packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count; rulesets_iter++)
{
// u32 ID
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID);
offset += sizeof(u32);
printf("-- ID                      \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID);

// u32 data_id
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id);
offset += sizeof(u32);
printf("-- data_id                 \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id);

// u32 ruleset_id
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id);
offset += sizeof(u32);
printf("-- ruleset_id              \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id);

// u32 content_pack_id
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id);
offset += sizeof(u32);
printf("-- content_pack_id         \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id);

// u32 content_pack_action_id
endian_write_u32_little(buffer + offset, packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id);
offset += sizeof(u32);
printf("-- content_pack_action_id  \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id);

} // rulesets

} // ruleset_definitions

} break;

case Zone_Packet_Kind_ActivityBase:
{
printf("[*] Packing ActivityBase...\n");
endian_write_u8_little(buffer + offset, 0x70);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_MountBase:
{
printf("[*] Packing MountBase...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_Mount_MountRequest:
{
printf("[*] Packing Mount_MountRequest...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountResponse:
{
printf("[*] Packing Mount_MountResponse...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_DismountRequest:
{
printf("[*] Packing Mount_DismountRequest...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_DismountResponse:
{
printf("[*] Packing Mount_DismountResponse...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountList:
{
printf("[*] Packing Mount_MountList...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountSpawn:
{
printf("[*] Packing Mount_MountSpawn...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x6);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountDespawn:
{
printf("[*] Packing Mount_MountDespawn...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x7);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountSpawnByItemDefinitionId:
{
printf("[*] Packing Mount_MountSpawnByItemDefinitionId...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x8);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountOfferUpsell:
{
printf("[*] Packing Mount_MountOfferUpsell...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x9);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_SeatChangeRequest:
{
printf("[*] Packing Mount_SeatChangeRequest...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xa);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_SeatChangeResponse:
{
printf("[*] Packing Mount_SeatChangeResponse...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xb);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_SeatSwapRequest:
{
printf("[*] Packing Mount_SeatSwapRequest...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xc);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_SeatSwapResponse:
{
printf("[*] Packing Mount_SeatSwapResponse...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xd);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_MountPacketTypeCount:
{
printf("[*] Packing Mount_MountPacketTypeCount...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xf);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Mount_FlipMount:
{
printf("[*] Packing Mount_FlipMount...\n");
endian_write_u8_little(buffer + offset, 0x71);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xe);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientInitializationDetails:
{
printf("[*] Packing ClientInitializationDetails...\n");
Zone_Packet_ClientInitializationDetails* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x72);
offset += sizeof(u8);

// u32 unk_u32_1
endian_write_u32_little(buffer + offset, packet->unk_u32_1);
offset += sizeof(u32);
printf("-- unk_u32_1               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_1, (u64)packet->unk_u32_1, (f64)packet->unk_u32_1);

} break;

case Zone_Packet_Kind_ClientAreaTimer:
{
printf("[*] Packing ClientAreaTimer...\n");
endian_write_u8_little(buffer + offset, 0x73);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LoyaltyRewardBase:
{
printf("[*] Packing LoyaltyRewardBase...\n");
endian_write_u8_little(buffer + offset, 0x74);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_RatingBase:
{
printf("[*] Packing RatingBase...\n");
endian_write_u8_little(buffer + offset, 0x75);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientActivityLaunchBase:
{
printf("[*] Packing ClientActivityLaunchBase...\n");
endian_write_u8_little(buffer + offset, 0x76);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ServerActivityLaunchBase:
{
printf("[*] Packing ServerActivityLaunchBase...\n");
endian_write_u8_little(buffer + offset, 0x77);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ClientFlashTimer:
{
printf("[*] Packing ClientFlashTimer...\n");
endian_write_u8_little(buffer + offset, 0x78);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdatePosition:
{
printf("[*] Packing PlayerUpdatePosition...\n");
endian_write_u8_little(buffer + offset, 0x79);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_InviteAndStartMiniGame:
{
printf("[*] Packing InviteAndStartMiniGame...\n");
endian_write_u8_little(buffer + offset, 0x7a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_QuizBase:
{
printf("[*] Packing QuizBase...\n");
endian_write_u8_little(buffer + offset, 0x7b);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdatePositionOnPlatform:
{
printf("[*] Packing PlayerUpdatePositionOnPlatform...\n");
endian_write_u8_little(buffer + offset, 0x7c);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientMembershipVipInfo:
{
printf("[*] Packing ClientMembershipVipInfo...\n");
endian_write_u8_little(buffer + offset, 0x7d);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_TargetBase:
{
printf("[*] Packing TargetBase...\n");
endian_write_u8_little(buffer + offset, 0x7e);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_GuideStoneBase:
{
printf("[*] Packing GuideStoneBase...\n");
endian_write_u8_little(buffer + offset, 0x80);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RaidsBase:
{
printf("[*] Packing RaidsBase...\n");
endian_write_u8_little(buffer + offset, 0x81);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_VoiceBase:
{
printf("[*] Packing VoiceBase...\n");
endian_write_u8_little(buffer + offset, 0x82);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WeaponBase:
{
printf("[*] Packing WeaponBase...\n");
endian_write_u8_little(buffer + offset, 0x83);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_MatchScheduleBase:
{
printf("[*] Packing MatchScheduleBase...\n");
endian_write_u8_little(buffer + offset, 0x84);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_FacilityBase:
{
printf("[*] Packing FacilityBase...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_ReferenceData:
{
printf("[*] Packing Facility_ReferenceData...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_FacilityData:
{
printf("[*] Packing Facility_FacilityData...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_CurrentFacilityUpdate:
{
printf("[*] Packing Facility_CurrentFacilityUpdate...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_SpawnDataRequest:
{
printf("[*] Packing Facility_SpawnDataRequest...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_FacilitySpawnData:
{
printf("[*] Packing Facility_FacilitySpawnData...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_FacilityUpdate:
{
printf("[*] Packing Facility_FacilityUpdate...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x6);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_FacilitySpawnStatus:
{
printf("[*] Packing Facility_FacilitySpawnStatus...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x7);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_FacilitySpawnStatusTracked:
{
printf("[*] Packing Facility_FacilitySpawnStatusTracked...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x8);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationFacilityCaptured:
{
printf("[*] Packing Facility_NotificationFacilityCaptured...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x9);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationFacilitySignificantCaptureProgress:
{
printf("[*] Packing Facility_NotificationFacilitySignificantCaptureProgress...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xa);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationFacilityCloseToCapture:
{
printf("[*] Packing Facility_NotificationFacilityCloseToCapture...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xb);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationFacilitySpawnBeginCapture:
{
printf("[*] Packing Facility_NotificationFacilitySpawnBeginCapture...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xc);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationFacilitySpawnFinishCapture:
{
printf("[*] Packing Facility_NotificationFacilitySpawnFinishCapture...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xd);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationLeavingFacilityDuringContention:
{
printf("[*] Packing Facility_NotificationLeavingFacilityDuringContention...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xe);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_ProximitySpawnCaptureUpdate:
{
printf("[*] Packing Facility_ProximitySpawnCaptureUpdate...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xf);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_ClearProximitySpawn:
{
printf("[*] Packing Facility_ClearProximitySpawn...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x10);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_GridStabilizeTimerUpdated:
{
printf("[*] Packing Facility_GridStabilizeTimerUpdated...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x11);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_SpawnCollisionChanged:
{
printf("[*] Packing Facility_SpawnCollisionChanged...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x12);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_NotificationFacilitySecondaryObjectiveEventPacket:
{
printf("[*] Packing Facility_NotificationFacilitySecondaryObjectiveEventPacket...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x13);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_PenetrateShieldEffect:
{
printf("[*] Packing Facility_PenetrateShieldEffect...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x14);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_SpawnUpdateGuid:
{
printf("[*] Packing Facility_SpawnUpdateGuid...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x15);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_FacilityUpdateRequest:
{
printf("[*] Packing Facility_FacilityUpdateRequest...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x16);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Facility_EmpireScoreValueUpdate:
{
printf("[*] Packing Facility_EmpireScoreValueUpdate...\n");
endian_write_u8_little(buffer + offset, 0x85);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x17);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_SkillsBase:
{
printf("[*] Packing SkillsBase...\n");
endian_write_u8_little(buffer + offset, 0x86);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_LoadoutsBase:
{
printf("[*] Packing LoadoutsBase...\n");
endian_write_u8_little(buffer + offset, 0x87);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ExperienceBase:
{
printf("[*] Packing ExperienceBase...\n");
endian_write_u8_little(buffer + offset, 0x88);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_VehicleBase:
{
printf("[*] Packing VehicleBase...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Owner:
{
printf("[*] Packing Vehicle_Owner...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Occupy:
{
printf("[*] Packing Vehicle_Occupy...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_StateData:
{
printf("[*] Packing Vehicle_StateData...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_StateDamage:
{
printf("[*] Packing Vehicle_StateDamage...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x4);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_PlayerManager:
{
printf("[*] Packing Vehicle_PlayerManager...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Spawn:
{
printf("[*] Packing Vehicle_Spawn...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x6);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Tint:
{
printf("[*] Packing Vehicle_Tint...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x7);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_LoadVehicleTerminalDefinitionManager:
{
printf("[*] Packing Vehicle_LoadVehicleTerminalDefinitionManager...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x8);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_ActiveWeapon:
{
printf("[*] Packing Vehicle_ActiveWeapon...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x9);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Stats:
{
printf("[*] Packing Vehicle_Stats...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xa);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_DamageInfo:
{
printf("[*] Packing Vehicle_DamageInfo...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xb);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_StatUpdate:
{
printf("[*] Packing Vehicle_StatUpdate...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xc);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_UpdateWeapon:
{
printf("[*] Packing Vehicle_UpdateWeapon...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xd);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_RemovedFromQueue:
{
printf("[*] Packing Vehicle_RemovedFromQueue...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xe);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_UpdateQueuePosition:
{
printf("[*] Packing Vehicle_UpdateQueuePosition...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xf);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_PadDestroyNotify:
{
printf("[*] Packing Vehicle_PadDestroyNotify...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x10);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_SetAutoDrive:
{
printf("[*] Packing Vehicle_SetAutoDrive...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x11);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_LockOnInfo:
{
printf("[*] Packing Vehicle_LockOnInfo...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x12);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_LockOnState:
{
printf("[*] Packing Vehicle_LockOnState...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x13);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_TrackingState:
{
printf("[*] Packing Vehicle_TrackingState...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x14);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_CounterMeasureState:
{
printf("[*] Packing Vehicle_CounterMeasureState...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x15);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_LoadVehicleDefinitionManager:
{
printf("[*] Packing Vehicle_LoadVehicleDefinitionManager...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x16);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_AcquireState:
{
printf("[*] Packing Vehicle_AcquireState...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x17);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Dismiss:
{
printf("[*] Packing Vehicle_Dismiss...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x18);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_AutoMount:
{
printf("[*] Packing Vehicle_AutoMount...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x19);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Deploy:
{
printf("[*] Packing Vehicle_Deploy...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1a);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_Engine:
{
printf("[*] Packing Vehicle_Engine...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1b);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_AccessType:
{
printf("[*] Packing Vehicle_AccessType...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1c);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_KickPlayer:
{
printf("[*] Packing Vehicle_KickPlayer...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1d);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_HealthUpdateOwner:
{
printf("[*] Packing Vehicle_HealthUpdateOwner...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1e);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_OwnerPassengerList:
{
printf("[*] Packing Vehicle_OwnerPassengerList...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1f);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_KickPacket:
{
printf("[*] Packing Vehicle_KickPacket...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x20);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_NoAccessPacket:
{
printf("[*] Packing Vehicle_NoAccessPacket...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x21);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_ExpirationPacket:
{
printf("[*] Packing Vehicle_ExpirationPacket...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x22);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_GroupPacket:
{
printf("[*] Packing Vehicle_GroupPacket...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x23);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_DeployResponsePacket:
{
printf("[*] Packing Vehicle_DeployResponsePacket...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x24);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_ExitPoints:
{
printf("[*] Packing Vehicle_ExitPoints...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x25);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_ControllerLogOut:
{
printf("[*] Packing Vehicle_ControllerLogOut...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x26);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_CurrentMoveMode:
{
printf("[*] Packing Vehicle_CurrentMoveMode...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x27);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_ItemDefinitionRequest:
{
printf("[*] Packing Vehicle_ItemDefinitionRequest...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x28);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_ItemDefinitionReply:
{
printf("[*] Packing Vehicle_ItemDefinitionReply...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x29);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Vehicle_InventoryItems:
{
printf("[*] Packing Vehicle_InventoryItems...\n");
endian_write_u8_little(buffer + offset, 0x89);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2a);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_GriefBase:
{
printf("[*] Packing GriefBase...\n");
endian_write_u8_little(buffer + offset, 0x8a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SpotPlayer:
{
printf("[*] Packing SpotPlayer...\n");
endian_write_u8_little(buffer + offset, 0x8b);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_FactionsBase:
{
printf("[*] Packing FactionsBase...\n");
endian_write_u8_little(buffer + offset, 0x8c);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_Synchronization:
{
printf("[*] Packing Synchronization...\n");
Zone_Packet_Synchronization* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x8d);
offset += sizeof(u8);

// u64 client_hours_ms
endian_write_u64_little(buffer + offset, packet->client_hours_ms);
offset += sizeof(u64);
printf("-- client_hours_ms         \t%lld\t%llxh\t%f\n", (i64)packet->client_hours_ms, (u64)packet->client_hours_ms, (f64)packet->client_hours_ms);

// u64 client_hours_ms2
endian_write_u64_little(buffer + offset, packet->client_hours_ms2);
offset += sizeof(u64);
printf("-- client_hours_ms2        \t%lld\t%llxh\t%f\n", (i64)packet->client_hours_ms2, (u64)packet->client_hours_ms2, (f64)packet->client_hours_ms2);

// u64 client_time
endian_write_u64_little(buffer + offset, packet->client_time);
offset += sizeof(u64);
printf("-- client_time             \t%lld\t%llxh\t%f\n", (i64)packet->client_time, (u64)packet->client_time, (f64)packet->client_time);

// u64 server_time
endian_write_u64_little(buffer + offset, packet->server_time);
offset += sizeof(u64);
printf("-- server_time             \t%lld\t%llxh\t%f\n", (i64)packet->server_time, (u64)packet->server_time, (f64)packet->server_time);

// u64 unk_time
endian_write_u64_little(buffer + offset, packet->unk_time);
offset += sizeof(u64);
printf("-- unk_time                \t%lld\t%llxh\t%f\n", (i64)packet->unk_time, (u64)packet->unk_time, (f64)packet->unk_time);

} break;

case Zone_Packet_Kind_ResourceEventBase:
{
printf("[*] Packing ResourceEventBase...\n");
endian_write_u8_little(buffer + offset, 0x8e);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CollisionBase:
{
printf("[*] Packing CollisionBase...\n");
endian_write_u8_little(buffer + offset, 0x8f);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LeaderboardBase:
{
printf("[*] Packing LeaderboardBase...\n");
endian_write_u8_little(buffer + offset, 0x90);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdateManagedPosition:
{
printf("[*] Packing PlayerUpdateManagedPosition...\n");
Zone_Packet_PlayerUpdateManagedPosition* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x91);
offset += sizeof(u8);

// uint2b transient_id
offset += endian_write_uint2b_little(buffer + offset, packet->transient_id.value);
printf("-- transient_id            \t%lld\t%llxh\n", (i64)packet->transient_id.value, (u64)packet->transient_id.value);

} break;

case Zone_Packet_Kind_PlayerUpdateVehicleWeapon:
{
printf("[*] Packing PlayerUpdateVehicleWeapon...\n");
endian_write_u8_little(buffer + offset, 0x93);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ProfileStatsBase:
{
printf("[*] Packing ProfileStatsBase...\n");
endian_write_u8_little(buffer + offset, 0x94);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_EquipmentSetCharacterEquipment:
{
printf("[*] Packing EquipmentSetCharacterEquipment...\n");
Zone_Packet_EquipmentSetCharacterEquipment* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x95);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

// u32 profile_id
endian_write_u32_little(buffer + offset, packet->profile_id);
offset += sizeof(u32);
printf("-- profile_id              \t%lld\t%llxh\t%f\n", (i64)packet->profile_id, (u64)packet->profile_id, (f64)packet->profile_id);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 unk_dword_1
endian_write_u32_little(buffer + offset, packet->unk_dword_1);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->unk_dword_1, (u64)packet->unk_dword_1, (f64)packet->unk_dword_1);

// string unk_string_1
endian_write_u32_little(buffer + offset, packet->unk_string_1_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->unk_string_1_length, (u64)packet->unk_string_1_length, (f64)packet->unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->unk_string_1_length; unk_string_1_iter++)
{
endian_write_i8_little(buffer + offset, packet->unk_string_1[unk_string_1_iter]);
offset++;
}

// string unk_string_2
endian_write_u32_little(buffer + offset, packet->unk_string_2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->unk_string_2_length, (u64)packet->unk_string_2_length, (f64)packet->unk_string_2_length);
for (u32 unk_string_2_iter = 0; unk_string_2_iter < packet->unk_string_2_length; unk_string_2_iter++)
{
endian_write_i8_little(buffer + offset, packet->unk_string_2[unk_string_2_iter]);
offset++;
}

// list equipment_slot_array
endian_write_u32_little(buffer + offset, packet->equipment_slot_array_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array_count, (u64)packet->equipment_slot_array_count, (f64)packet->equipment_slot_array_count);

for (u32 equipment_slot_array_iter = 0; equipment_slot_array_iter < packet->equipment_slot_array_count; equipment_slot_array_iter++)
{
// u32 equipment_slot_id_1
endian_write_u32_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1);
offset += sizeof(u32);
printf("-- equipment_slot_id_1     \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1, (u64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1, (f64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1);

// u32 equipment_slot_id_2
endian_write_u32_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2);
offset += sizeof(u32);
printf("-- equipment_slot_id_2     \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2, (u64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2, (f64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2);

// u64 guid
endian_write_u64_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].guid);
offset += sizeof(u64);
printf("-- guid                    \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].guid, (u64)packet->equipment_slot_array[equipment_slot_array_iter].guid, (f64)packet->equipment_slot_array[equipment_slot_array_iter].guid);

// string tint_alias
endian_write_u32_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length, (u64)packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length, (f64)packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length; tint_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].tint_alias[tint_alias_iter]);
offset++;
}

// string decal_alias
endian_write_u32_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length, (u64)packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length, (f64)packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length);
for (u32 decal_alias_iter = 0; decal_alias_iter < packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length; decal_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->equipment_slot_array[equipment_slot_array_iter].decal_alias[decal_alias_iter]);
offset++;
}

} // equipment_slot_array

// list attachments_data_1
endian_write_u32_little(buffer + offset, packet->attachments_data_1_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1_count, (u64)packet->attachments_data_1_count, (f64)packet->attachments_data_1_count);

for (u32 attachments_data_1_iter = 0; attachments_data_1_iter < packet->attachments_data_1_count; attachments_data_1_iter++)
{
// string model_name
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].model_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].model_name_length, (u64)packet->attachments_data_1[attachments_data_1_iter].model_name_length, (f64)packet->attachments_data_1[attachments_data_1_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->attachments_data_1[attachments_data_1_iter].model_name_length; model_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].model_name[model_name_iter]);
offset++;
}

// string texture_alias
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].texture_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].texture_alias_length, (u64)packet->attachments_data_1[attachments_data_1_iter].texture_alias_length, (f64)packet->attachments_data_1[attachments_data_1_iter].texture_alias_length);
for (u32 texture_alias_iter = 0; texture_alias_iter < packet->attachments_data_1[attachments_data_1_iter].texture_alias_length; texture_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].texture_alias[texture_alias_iter]);
offset++;
}

// string tint_alias
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].tint_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].tint_alias_length, (u64)packet->attachments_data_1[attachments_data_1_iter].tint_alias_length, (f64)packet->attachments_data_1[attachments_data_1_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->attachments_data_1[attachments_data_1_iter].tint_alias_length; tint_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].tint_alias[tint_alias_iter]);
offset++;
}

// string decal_alias
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].decal_alias_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].decal_alias_length, (u64)packet->attachments_data_1[attachments_data_1_iter].decal_alias_length, (f64)packet->attachments_data_1[attachments_data_1_iter].decal_alias_length);
for (u32 decal_alias_iter = 0; decal_alias_iter < packet->attachments_data_1[attachments_data_1_iter].decal_alias_length; decal_alias_iter++)
{
endian_write_i8_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].decal_alias[decal_alias_iter]);
offset++;
}

// u32 unk_dword_1
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].unk_dword_1);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_1, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_1, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_1);

// u32 unk_dword_2
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].unk_dword_2);
offset += sizeof(u32);
printf("-- unk_dword_2             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_2, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_2, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_2);

// u32 effect_id
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].effect_id);
offset += sizeof(u32);
printf("-- effect_id               \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].effect_id, (u64)packet->attachments_data_1[attachments_data_1_iter].effect_id, (f64)packet->attachments_data_1[attachments_data_1_iter].effect_id);

// u32 slot_id
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].slot_id);
offset += sizeof(u32);
printf("-- slot_id                 \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].slot_id, (u64)packet->attachments_data_1[attachments_data_1_iter].slot_id, (f64)packet->attachments_data_1[attachments_data_1_iter].slot_id);

// u32 unk_dword_3
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].unk_dword_3);
offset += sizeof(u32);
printf("-- unk_dword_3             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_3, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_3, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_3);

// list unk_array_1337
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count);

for (u32 unk_array_1337_iter = 0; unk_array_1337_iter < packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count; unk_array_1337_iter++)
{
// u32 unk_dword_4
endian_write_u32_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4);
offset += sizeof(u32);
printf("-- unk_dword_4             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4);

} // unk_array_1337

// b8 unk_bool_1
endian_write_b8_little(buffer + offset, packet->attachments_data_1[attachments_data_1_iter].unk_bool_1);
offset += sizeof(b8);
printf("-- unk_bool_1              \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_bool_1, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_bool_1, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_bool_1);

} // attachments_data_1

// b8 unk_bool_2
endian_write_b8_little(buffer + offset, packet->unk_bool_2);
offset += sizeof(b8);
printf("-- unk_bool_2              \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool_2, (u64)packet->unk_bool_2, (f64)packet->unk_bool_2);

} break;

case Zone_Packet_Kind_DefinitionFiltersBase:
{
printf("[*] Packing DefinitionFiltersBase...\n");
endian_write_u8_little(buffer + offset, 0x96);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ContinentBattleInfo:
{
printf("[*] Packing ContinentBattleInfo...\n");
endian_write_u8_little(buffer + offset, 0x97);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SendSecurityPacketAndSelfDestruct:
{
printf("[*] Packing SendSecurityPacketAndSelfDestruct...\n");
endian_write_u8_little(buffer + offset, 0x99);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GetContinentBattleInfo:
{
printf("[*] Packing GetContinentBattleInfo...\n");
endian_write_u8_little(buffer + offset, 0x98);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GetRespawnLocations:
{
printf("[*] Packing GetRespawnLocations...\n");
endian_write_u8_little(buffer + offset, 0x9a);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WallOfDataBase:
{
printf("[*] Packing WallOfDataBase...\n");
endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WallOfData_UIEvent:
{
printf("[*] Packing WallOfData_UIEvent...\n");
Zone_Packet_WallOfData_UIEvent* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x5);
offset += sizeof(u16);

// string object
endian_write_u32_little(buffer + offset, packet->object_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->object_length, (u64)packet->object_length, (f64)packet->object_length);
for (u32 object_iter = 0; object_iter < packet->object_length; object_iter++)
{
endian_write_i8_little(buffer + offset, packet->object[object_iter]);
offset++;
}

// string function
endian_write_u32_little(buffer + offset, packet->function_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->function_length, (u64)packet->function_length, (f64)packet->function_length);
for (u32 function_iter = 0; function_iter < packet->function_length; function_iter++)
{
endian_write_i8_little(buffer + offset, packet->function[function_iter]);
offset++;
}

// string argument
endian_write_u32_little(buffer + offset, packet->argument_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->argument_length, (u64)packet->argument_length, (f64)packet->argument_length);
for (u32 argument_iter = 0; argument_iter < packet->argument_length; argument_iter++)
{
endian_write_i8_little(buffer + offset, packet->argument[argument_iter]);
offset++;
}

} break;

case Zone_Packet_Kind_WallOfData_ClientSystemInfo:
{
printf("[*] Packing WallOfData_ClientSystemInfo...\n");
Zone_Packet_WallOfData_ClientSystemInfo* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x6);
offset += sizeof(u16);

// string info
endian_write_u32_little(buffer + offset, packet->info_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->info_length, (u64)packet->info_length, (f64)packet->info_length);
for (u32 info_iter = 0; info_iter < packet->info_length; info_iter++)
{
endian_write_i8_little(buffer + offset, packet->info[info_iter]);
offset++;
}

} break;

case Zone_Packet_Kind_WallOfData_VoiceChatEvent:
{
printf("[*] Packing WallOfData_VoiceChatEvent...\n");
endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x7);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WallOfData_NudgeEvent:
{
printf("[*] Packing WallOfData_NudgeEvent...\n");
endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x9);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WallOfData_LaunchPadFingerprint:
{
printf("[*] Packing WallOfData_LaunchPadFingerprint...\n");
endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xa);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WallOfData_VideoCapture:
{
printf("[*] Packing WallOfData_VideoCapture...\n");
endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xb);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_WallOfData_ClientTransition:
{
printf("[*] Packing WallOfData_ClientTransition...\n");
Zone_Packet_WallOfData_ClientTransition* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9b);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0xc);
offset += sizeof(u16);

// u32 old_state
endian_write_u32_little(buffer + offset, packet->old_state);
offset += sizeof(u32);
printf("-- old_state               \t%lld\t%llxh\t%f\n", (i64)packet->old_state, (u64)packet->old_state, (f64)packet->old_state);

// u32 new_state
endian_write_u32_little(buffer + offset, packet->new_state);
offset += sizeof(u32);
printf("-- new_state               \t%lld\t%llxh\t%f\n", (i64)packet->new_state, (u64)packet->new_state, (f64)packet->new_state);

// u32 ms_elapsed
endian_write_u32_little(buffer + offset, packet->ms_elapsed);
offset += sizeof(u32);
printf("-- ms_elapsed              \t%lld\t%llxh\t%f\n", (i64)packet->ms_elapsed, (u64)packet->ms_elapsed, (f64)packet->ms_elapsed);

} break;

case Zone_Packet_Kind_ImplantsBase:
{
printf("[*] Packing ImplantsBase...\n");
endian_write_u8_little(buffer + offset, 0x9c);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_InGamePurchase:
{
printf("[*] Packing InGamePurchase...\n");
endian_write_u8_little(buffer + offset, 0x9d);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_MissionsBase:
{
printf("[*] Packing MissionsBase...\n");
endian_write_u8_little(buffer + offset, 0x9e);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_EffectsBase:
{
printf("[*] Packing EffectsBase...\n");
endian_write_u8_little(buffer + offset, 0x9f);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_RewardBuffsBase:
{
printf("[*] Packing RewardBuffsBase...\n");
endian_write_u8_little(buffer + offset, 0xa0);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_AbilitiesBase:
{
printf("[*] Packing AbilitiesBase...\n");
endian_write_u8_little(buffer + offset, 0xa1);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_DeployableBase:
{
printf("[*] Packing DeployableBase...\n");
endian_write_u8_little(buffer + offset, 0xa2);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_Security:
{
printf("[*] Packing Security...\n");
endian_write_u8_little(buffer + offset, 0xa3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_MapRegionBase:
{
printf("[*] Packing MapRegionBase...\n");
endian_write_u8_little(buffer + offset, 0xa4);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_HudManagerBase:
{
printf("[*] Packing HudManagerBase...\n");
endian_write_u8_little(buffer + offset, 0xa5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AcquireTimersBase:
{
printf("[*] Packing AcquireTimersBase...\n");
endian_write_u8_little(buffer + offset, 0xa6);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LoginBase:
{
printf("[*] Packing LoginBase...\n");
endian_write_u8_little(buffer + offset, 0xa7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ServerPopulationInfo:
{
printf("[*] Packing ServerPopulationInfo...\n");
endian_write_u8_little(buffer + offset, 0xa8);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GetServerPopulationInfo:
{
printf("[*] Packing GetServerPopulationInfo...\n");
endian_write_u8_little(buffer + offset, 0xa9);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdateVehicleCollision:
{
printf("[*] Packing PlayerUpdateVehicleCollision...\n");
endian_write_u8_little(buffer + offset, 0xaa);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerStop:
{
printf("[*] Packing PlayerStop...\n");
endian_write_u8_little(buffer + offset, 0xab);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CurrencyBase:
{
printf("[*] Packing CurrencyBase...\n");
endian_write_u8_little(buffer + offset, 0xac);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ItemsBase:
{
printf("[*] Packing ItemsBase...\n");
endian_write_u8_little(buffer + offset, 0xad);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdateAttachObject:
{
printf("[*] Packing PlayerUpdateAttachObject...\n");
endian_write_u8_little(buffer + offset, 0xae);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerUpdateDetachObject:
{
printf("[*] Packing PlayerUpdateDetachObject...\n");
endian_write_u8_little(buffer + offset, 0xaf);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ClientSettings:
{
printf("[*] Packing ClientSettings...\n");
endian_write_u8_little(buffer + offset, 0xb0);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RewardBuffInfo:
{
printf("[*] Packing RewardBuffInfo...\n");
endian_write_u8_little(buffer + offset, 0xb1);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GetRewardBuffInfo:
{
printf("[*] Packing GetRewardBuffInfo...\n");
endian_write_u8_little(buffer + offset, 0xb2);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CaisBase:
{
printf("[*] Packing CaisBase...\n");
endian_write_u8_little(buffer + offset, 0xb3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ZoneSettingBase:
{
printf("[*] Packing ZoneSettingBase...\n");
endian_write_u8_little(buffer + offset, 0xb4);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RequestPromoEligibilityUpdate:
{
printf("[*] Packing RequestPromoEligibilityUpdate...\n");
endian_write_u8_little(buffer + offset, 0xb5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PromoEligibilityReply:
{
printf("[*] Packing PromoEligibilityReply...\n");
endian_write_u8_little(buffer + offset, 0xb6);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_MetaGameEventBase:
{
printf("[*] Packing MetaGameEventBase...\n");
endian_write_u8_little(buffer + offset, 0xb7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RequestWalletTopupUpdate:
{
printf("[*] Packing RequestWalletTopupUpdate...\n");
endian_write_u8_little(buffer + offset, 0xb8);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_StationCashActivePromoRequestUpdate:
{
printf("[*] Packing StationCashActivePromoRequestUpdate...\n");
endian_write_u8_little(buffer + offset, 0xb9);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_OperationBase:
{
printf("[*] Packing OperationBase...\n");
endian_write_u8_little(buffer + offset, 0xbc);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WordFilterBase:
{
printf("[*] Packing WordFilterBase...\n");
endian_write_u8_little(buffer + offset, 0xbd);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_StaticFacilityInfoBase:
{
printf("[*] Packing StaticFacilityInfoBase...\n");
endian_write_u8_little(buffer + offset, 0xbe);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_FacilityInfo_Request:
{
printf("[*] Packing FacilityInfo_Request...\n");
endian_write_u8_little(buffer + offset, 0xbe);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x1);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_FacilityInfo_Reply:
{
printf("[*] Packing FacilityInfo_Reply...\n");
endian_write_u8_little(buffer + offset, 0xbe);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x2);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_FacilityInfo_AllZones:
{
printf("[*] Packing FacilityInfo_AllZones...\n");
endian_write_u8_little(buffer + offset, 0xbe);
offset += sizeof(u8);

endian_write_u16_little(buffer + offset, 0x3);
offset += sizeof(u16);

} break;

case Zone_Packet_Kind_ProxiedPlayerBase:
{
printf("[*] Packing ProxiedPlayerBase...\n");
endian_write_u8_little(buffer + offset, 0xbf);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ResistsBase:
{
printf("[*] Packing ResistsBase...\n");
endian_write_u8_little(buffer + offset, 0xc0);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_InGamePurchasingBase:
{
printf("[*] Packing InGamePurchasingBase...\n");
endian_write_u8_little(buffer + offset, 0xc1);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_BusinessEnvironments:
{
printf("[*] Packing BusinessEnvironments...\n");
endian_write_u8_little(buffer + offset, 0xc2);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_EmpireScorePacketBase:
{
printf("[*] Packing EmpireScorePacketBase...\n");
endian_write_u8_little(buffer + offset, 0xc3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CharacterSelectSessionRequest:
{
printf("[*] Packing CharacterSelectSessionRequest...\n");
endian_write_u8_little(buffer + offset, 0xc4);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CharacterSelectSessionResponse:
{
printf("[*] Packing CharacterSelectSessionResponse...\n");
endian_write_u8_little(buffer + offset, 0xc5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_StatsBase:
{
printf("[*] Packing StatsBase...\n");
endian_write_u8_little(buffer + offset, 0xc6);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ScoreBase:
{
printf("[*] Packing ScoreBase...\n");
endian_write_u8_little(buffer + offset, 0xc7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ResourcesBase:
{
printf("[*] Packing ResourcesBase...\n");
endian_write_u8_little(buffer + offset, 0xc8);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ConstructionBase:
{
printf("[*] Packing ConstructionBase...\n");
endian_write_u8_little(buffer + offset, 0xca);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_UpdateWeatherData:
{
printf("[*] Packing UpdateWeatherData...\n");
endian_write_u8_little(buffer + offset, 0xcb);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_NavGenBase:
{
printf("[*] Packing NavGenBase...\n");
endian_write_u8_little(buffer + offset, 0xcc);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LocksBase:
{
printf("[*] Packing LocksBase...\n");
endian_write_u8_little(buffer + offset, 0xcd);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RagdollBase:
{
printf("[*] Packing RagdollBase...\n");
endian_write_u8_little(buffer + offset, 0xce);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CharacterStateBase:
{
printf("[*] Packing CharacterStateBase...\n");
endian_write_u8_little(buffer + offset, 0xd0);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_TimedGrantBase:
{
printf("[*] Packing TimedGrantBase...\n");
endian_write_u8_little(buffer + offset, 0xd1);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WeatherBase:
{
printf("[*] Packing WeatherBase...\n");
endian_write_u8_little(buffer + offset, 0xd2);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GameEscrowBase:
{
printf("[*] Packing GameEscrowBase...\n");
endian_write_u8_little(buffer + offset, 0xd3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayCompositeEffect:
{
printf("[*] Packing PlayCompositeEffect...\n");
endian_write_u8_little(buffer + offset, 0xd4);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SetSpotted:
{
printf("[*] Packing SetSpotted...\n");
endian_write_u8_little(buffer + offset, 0xd5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AddLightweightPc:
{
printf("[*] Packing AddLightweightPc...\n");
endian_write_u8_little(buffer + offset, 0xd6);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AddLightweightNpc:
{
printf("[*] Packing AddLightweightNpc...\n");
endian_write_u8_little(buffer + offset, 0xd7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AddLightweightVehicle:
{
printf("[*] Packing AddLightweightVehicle...\n");
endian_write_u8_little(buffer + offset, 0xd8);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AddProxiedObject:
{
printf("[*] Packing AddProxiedObject...\n");
endian_write_u8_little(buffer + offset, 0xd9);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AddSimpleNpc:
{
printf("[*] Packing AddSimpleNpc...\n");
endian_write_u8_little(buffer + offset, 0x92);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LightweightToFullPc:
{
printf("[*] Packing LightweightToFullPc...\n");
endian_write_u8_little(buffer + offset, 0xda);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LightweightToFullNpc:
{
printf("[*] Packing LightweightToFullNpc...\n");
endian_write_u8_little(buffer + offset, 0xdb);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_LightweightToFullVehicle:
{
printf("[*] Packing LightweightToFullVehicle...\n");
endian_write_u8_little(buffer + offset, 0xdc);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CheckLocalValues:
{
printf("[*] Packing CheckLocalValues...\n");
endian_write_u8_little(buffer + offset, 0xde);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ChronicleBase:
{
printf("[*] Packing ChronicleBase...\n");
endian_write_u8_little(buffer + offset, 0xdf);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_GrinderBase:
{
printf("[*] Packing GrinderBase...\n");
endian_write_u8_little(buffer + offset, 0xe0);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_RequestObject:
{
printf("[*] Packing RequestObject...\n");
endian_write_u8_little(buffer + offset, 0xe1);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ScreenEffectBase:
{
printf("[*] Packing ScreenEffectBase...\n");
endian_write_u8_little(buffer + offset, 0xe2);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SpectatorBase:
{
printf("[*] Packing SpectatorBase...\n");
endian_write_u8_little(buffer + offset, 0xe3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WhitelistBase:
{
printf("[*] Packing WhitelistBase...\n");
endian_write_u8_little(buffer + offset, 0xe4);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_NpcFoundationPermissionsManagerBase:
{
printf("[*] Packing NpcFoundationPermissionsManagerBase...\n");
endian_write_u8_little(buffer + offset, 0xe5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_BattlEyeData:
{
printf("[*] Packing BattlEyeData...\n");
endian_write_u8_little(buffer + offset, 0xe6);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_OnlineIdBase:
{
printf("[*] Packing OnlineIdBase...\n");
endian_write_u8_little(buffer + offset, 0xe7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_Ps4PlayGoBase:
{
printf("[*] Packing Ps4PlayGoBase...\n");
endian_write_u8_little(buffer + offset, 0xe8);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_SynchronizedTeleportBase:
{
printf("[*] Packing SynchronizedTeleportBase...\n");
endian_write_u8_little(buffer + offset, 0xe9);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_StaticViewBase:
{
printf("[*] Packing StaticViewBase...\n");
endian_write_u8_little(buffer + offset, 0xea);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ReplicationBase:
{
printf("[*] Packing ReplicationBase...\n");
endian_write_u8_little(buffer + offset, 0xeb);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_DatasheetsBase:
{
printf("[*] Packing DatasheetsBase...\n");
endian_write_u8_little(buffer + offset, 0xec);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerWorldTransferRequest:
{
printf("[*] Packing PlayerWorldTransferRequest...\n");
endian_write_u8_little(buffer + offset, 0xed);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerWorldTransferReply:
{
printf("[*] Packing PlayerWorldTransferReply...\n");
endian_write_u8_little(buffer + offset, 0xee);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CancelQueueOnWorld:
{
printf("[*] Packing CancelQueueOnWorld...\n");
endian_write_u8_little(buffer + offset, 0xef);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_DeclineEnterGameOnWorld:
{
printf("[*] Packing DeclineEnterGameOnWorld...\n");
endian_write_u8_little(buffer + offset, 0xf0);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AccessedCharacterBase:
{
printf("[*] Packing AccessedCharacterBase...\n");
endian_write_u8_little(buffer + offset, 0xf1);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_ShaderParameterOverrideBase:
{
printf("[*] Packing ShaderParameterOverrideBase...\n");
endian_write_u8_little(buffer + offset, 0xf2);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_VehicleSkinBase:
{
printf("[*] Packing VehicleSkinBase...\n");
endian_write_u8_little(buffer + offset, 0xf3);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_WeaponLagLockParameters:
{
printf("[*] Packing WeaponLagLockParameters...\n");
endian_write_u8_little(buffer + offset, 0xf5);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_CrateOpeningBase:
{
printf("[*] Packing CrateOpeningBase...\n");
endian_write_u8_little(buffer + offset, 0xf6);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_PlayerHeatWarning:
{
printf("[*] Packing PlayerHeatWarning...\n");
endian_write_u8_little(buffer + offset, 0xf7);
offset += sizeof(u8);

} break;

case Zone_Packet_Kind_AnimationBase:
{
printf("[*] Packing AnimationBase...\n");
endian_write_u8_little(buffer + offset, 0xf8);
offset += sizeof(u8);

} break;

default:
{
printf("[!] Packing %s not implemented\n", zone_packet_names[packet_kind]);
}
}
return offset;
}

internal void
zone_packet_unpack(u8* data, u32 data_length, Zone_Packet_Kind packet_kind, void* packet_ptr, Memory_Arena* arena)
{
u32 offset = 0;

printf("\n");
switch (packet_kind)
{
case Zone_Packet_Kind_Chat_Chat:
{
printf("[*] Unpacking Chat_Chat...\n");
Zone_Packet_Chat_Chat* packet = packet_ptr;

// u16 unk_u16
packet->unk_u16 = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- unk_u16                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u16, (u64)packet->unk_u16, (f64)packet->unk_u16);

// u16 channel
packet->channel = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- channel                 \t%lld\t%llxh\t%f\n", (i64)packet->channel, (u64)packet->channel, (f64)packet->channel);

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u64 character_id2
packet->character_id2 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id2           \t%lld\t%llxh\t%f\n", (i64)packet->character_id2, (u64)packet->character_id2, (f64)packet->character_id2);

// u32 unk_u32
packet->unk_u32 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 unk_u32_2
packet->unk_u32_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_2, (u64)packet->unk_u32_2, (f64)packet->unk_u32_2);

// u32 unk_u32_3
packet->unk_u32_3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_3               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_3, (u64)packet->unk_u32_3, (f64)packet->unk_u32_3);

// string character_first_name
packet->character_first_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->character_first_name = memory_arena_push_length(arena, packet->character_first_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->character_first_name_length);
for (u32 character_first_name_iter = 0; character_first_name_iter < packet->character_first_name_length; character_first_name_iter++)
{
packet->character_first_name[character_first_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string character_last_name
packet->character_last_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->character_last_name = memory_arena_push_length(arena, packet->character_last_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->character_last_name_length);
for (u32 character_last_name_iter = 0; character_last_name_iter < packet->character_last_name_length; character_last_name_iter++)
{
packet->character_last_name[character_last_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unk_string
packet->unk_string_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->unk_string = memory_arena_push_length(arena, packet->unk_string_length);
printf("-- STRING_LENGTH           \t%d\n", packet->unk_string_length);
for (u32 unk_string_iter = 0; unk_string_iter < packet->unk_string_length; unk_string_iter++)
{
packet->unk_string[unk_string_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string character_name
packet->character_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->character_name = memory_arena_push_length(arena, packet->character_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->character_name_length; character_name_iter++)
{
packet->character_name[character_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u64 unk_u64
packet->unk_u64 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- unk_u64                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u64, (u64)packet->unk_u64, (f64)packet->unk_u64);

// u32 unk_u32_4
packet->unk_u32_4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_4               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_4, (u64)packet->unk_u32_4, (f64)packet->unk_u32_4);

// u32 unk_u32_5
packet->unk_u32_5 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_5               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_5, (u64)packet->unk_u32_5, (f64)packet->unk_u32_5);

// u32 unk_u32_6
packet->unk_u32_6 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_6               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_6, (u64)packet->unk_u32_6, (f64)packet->unk_u32_6);

// string character_first_name_2
packet->character_first_name_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->character_first_name_2 = memory_arena_push_length(arena, packet->character_first_name_2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->character_first_name_2_length);
for (u32 character_first_name_2_iter = 0; character_first_name_2_iter < packet->character_first_name_2_length; character_first_name_2_iter++)
{
packet->character_first_name_2[character_first_name_2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string character_last_name_2
packet->character_last_name_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->character_last_name_2 = memory_arena_push_length(arena, packet->character_last_name_2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->character_last_name_2_length);
for (u32 character_last_name_2_iter = 0; character_last_name_2_iter < packet->character_last_name_2_length; character_last_name_2_iter++)
{
packet->character_last_name_2[character_last_name_2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unk_string_2
packet->unk_string_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->unk_string_2 = memory_arena_push_length(arena, packet->unk_string_2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->unk_string_2_length);
for (u32 unk_string_2_iter = 0; unk_string_2_iter < packet->unk_string_2_length; unk_string_2_iter++)
{
packet->unk_string_2[unk_string_2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string character_name_2
packet->character_name_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->character_name_2 = memory_arena_push_length(arena, packet->character_name_2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->character_name_2_length);
for (u32 character_name_2_iter = 0; character_name_2_iter < packet->character_name_2_length; character_name_2_iter++)
{
packet->character_name_2[character_name_2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u64 unk_u64_2
packet->unk_u64_2 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- unk_u64_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u64_2, (u64)packet->unk_u64_2, (f64)packet->unk_u64_2);

// string message
packet->message_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->message = memory_arena_push_length(arena, packet->message_length);
printf("-- STRING_LENGTH           \t%d\n", packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
packet->message[message_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// vec4 position
packet->position = endian_read_vec4_little(data + offset);
offset += sizeof(f32) * 4;
printf("-- position                \t%f\t%f\t%f\t%f\n", (f64)packet->position.x, (f64)packet->position.y, (f64)packet->position.z, (f64)packet->position.w);

// u64 unk_guid
packet->unk_guid = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- unk_guid                \t%lld\t%llxh\t%f\n", (i64)packet->unk_guid, (u64)packet->unk_guid, (f64)packet->unk_guid);

// u32 unk_u32_7
packet->unk_u32_7 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_7               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_7, (u64)packet->unk_u32_7, (f64)packet->unk_u32_7);

// u32 color_1
packet->color_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- color_1                 \t%lld\t%llxh\t%f\n", (i64)packet->color_1, (u64)packet->color_1, (f64)packet->color_1);

// u32 color_2
packet->color_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- color_2                 \t%lld\t%llxh\t%f\n", (i64)packet->color_2, (u64)packet->color_2, (f64)packet->color_2);

// u8 unk_u8
packet->unk_u8 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_u8                  \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8, (u64)packet->unk_u8, (f64)packet->unk_u8);

// u8 unk_u8_2
packet->unk_u8_2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_u8_2                \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8_2, (u64)packet->unk_u8_2, (f64)packet->unk_u8_2);

} break;

case Zone_Packet_Kind_Chat_ChatText:
{
printf("[*] Unpacking Chat_ChatText...\n");
Zone_Packet_Chat_ChatText* packet = packet_ptr;

// string message
packet->message_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->message = memory_arena_push_length(arena, packet->message_length);
printf("-- STRING_LENGTH           \t%d\n", packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
packet->message[message_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 unk_u32
packet->unk_u32 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 color
packet->color = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- color                   \t%lld\t%llxh\t%f\n", (i64)packet->color, (u64)packet->color, (f64)packet->color);

// u32 unk_u32_2
packet->unk_u32_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_2, (u64)packet->unk_u32_2, (f64)packet->unk_u32_2);

// u8 unk_u8
packet->unk_u8 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_u8                  \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8, (u64)packet->unk_u8, (f64)packet->unk_u8);

// u8 unk_u8_2
packet->unk_u8_2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_u8_2                \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8_2, (u64)packet->unk_u8_2, (f64)packet->unk_u8_2);

} break;

case Zone_Packet_Kind_CommandItemDefinitionRequest:
{
printf("[*] Unpacking CommandItemDefinitionRequest...\n");
Zone_Packet_CommandItemDefinitionRequest* packet = packet_ptr;

// u32 id
packet->id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id                      \t%lld\t%llxh\t%f\n", (i64)packet->id, (u64)packet->id, (f64)packet->id);

} break;

case Zone_Packet_Kind_CommandItemDefinitionReply:
{
printf("[*] Unpacking CommandItemDefinitionReply...\n");
Zone_Packet_CommandItemDefinitionReply* packet = packet_ptr;

// stream item_def_reply_1
packet->item_def_reply_1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1 = memory_arena_push_length(arena, packet->item_def_reply_1_length * sizeof(packet->item_def_reply_1[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->item_def_reply_1_length);
for (u32 item_def_reply_1_iter = 0; item_def_reply_1_iter < (packet->item_def_reply_1_length > (u32)0 ? (u32)1 : (u32)0); item_def_reply_1_iter++)
{
// u8 bitflags1
packet->item_def_reply_1[item_def_reply_1_iter].bitflags1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- bitflags1               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags1);

// u8 bitflags2
packet->item_def_reply_1[item_def_reply_1_iter].bitflags2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- bitflags2               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].bitflags2);

// u32 name_id
packet->item_def_reply_1[item_def_reply_1_iter].name_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].name_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].name_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].name_id);

// u32 description_id
packet->item_def_reply_1[item_def_reply_1_iter].description_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].description_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].description_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].description_id);

// u32 content_id
packet->item_def_reply_1[item_def_reply_1_iter].content_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- content_id              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].content_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].content_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].content_id);

// u32 image_set_id
packet->item_def_reply_1[item_def_reply_1_iter].image_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- image_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].image_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].image_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].image_set_id);

// u32 tint_id
packet->item_def_reply_1[item_def_reply_1_iter].tint_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- tint_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].tint_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].tint_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].tint_id);

// u32 hud_image_set_id
packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- hud_image_set_id        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].hud_image_set_id);

// u32 unk_dword_1
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_1);

// u32 unk_dword_2
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_2             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_2);

// u32 cost
packet->item_def_reply_1[item_def_reply_1_iter].cost = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- cost                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].cost, (u64)packet->item_def_reply_1[item_def_reply_1_iter].cost, (f64)packet->item_def_reply_1[item_def_reply_1_iter].cost);

// u32 item_class
packet->item_def_reply_1[item_def_reply_1_iter].item_class = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_class              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].item_class, (u64)packet->item_def_reply_1[item_def_reply_1_iter].item_class, (f64)packet->item_def_reply_1[item_def_reply_1_iter].item_class);

// u32 profile_override
packet->item_def_reply_1[item_def_reply_1_iter].profile_override = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- profile_override        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].profile_override, (u64)packet->item_def_reply_1[item_def_reply_1_iter].profile_override, (f64)packet->item_def_reply_1[item_def_reply_1_iter].profile_override);

// string model_name
packet->item_def_reply_1[item_def_reply_1_iter].model_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].model_name = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].model_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->item_def_reply_1[item_def_reply_1_iter].model_name_length; model_name_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].model_name[model_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string texture_alias
packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].texture_alias = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length);
for (u32 texture_alias_iter = 0; texture_alias_iter < packet->item_def_reply_1[item_def_reply_1_iter].texture_alias_length; texture_alias_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].texture_alias[texture_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 gender_usage
packet->item_def_reply_1[item_def_reply_1_iter].gender_usage = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- gender_usage            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].gender_usage, (u64)packet->item_def_reply_1[item_def_reply_1_iter].gender_usage, (f64)packet->item_def_reply_1[item_def_reply_1_iter].gender_usage);

// u32 item_type
packet->item_def_reply_1[item_def_reply_1_iter].item_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_type               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].item_type, (u64)packet->item_def_reply_1[item_def_reply_1_iter].item_type, (f64)packet->item_def_reply_1[item_def_reply_1_iter].item_type);

// u32 category_id
packet->item_def_reply_1[item_def_reply_1_iter].category_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- category_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].category_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].category_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].category_id);

// u32 weapon_trail_effect_id
packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- weapon_trail_effect_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].weapon_trail_effect_id);

// u32 composite_effect_id
packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- composite_effect_id     \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].composite_effect_id);

// u32 power_rating
packet->item_def_reply_1[item_def_reply_1_iter].power_rating = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- power_rating            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].power_rating, (u64)packet->item_def_reply_1[item_def_reply_1_iter].power_rating, (f64)packet->item_def_reply_1[item_def_reply_1_iter].power_rating);

// u32 min_profile_rank
packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- min_profile_rank        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank, (u64)packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank, (f64)packet->item_def_reply_1[item_def_reply_1_iter].min_profile_rank);

// u32 rarity
packet->item_def_reply_1[item_def_reply_1_iter].rarity = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- rarity                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].rarity, (u64)packet->item_def_reply_1[item_def_reply_1_iter].rarity, (f64)packet->item_def_reply_1[item_def_reply_1_iter].rarity);

// u32 activatable_ability_id
packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- activatable_ability_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_id);

// u32 activatable_ability_set_id
packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- activatable_ability_set_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].activatable_ability_set_id);

// u32 passive_ability_id
packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_ability_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_id);

// u32 passive_ability_set_id
packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_ability_set_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_ability_set_id);

// u32 max_stack_size
packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- max_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size, (u64)packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size, (f64)packet->item_def_reply_1[item_def_reply_1_iter].max_stack_size);

// u32 min_stack_size
packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- min_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size, (u64)packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size, (f64)packet->item_def_reply_1[item_def_reply_1_iter].min_stack_size);

// string tint_alias
packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].tint_alias = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->item_def_reply_1[item_def_reply_1_iter].tint_alias_length; tint_alias_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].tint_alias[tint_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 tint_group_id
packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- tint_group_id           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].tint_group_id);

// u32 member_discount
packet->item_def_reply_1[item_def_reply_1_iter].member_discount = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- member_discount         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].member_discount, (u64)packet->item_def_reply_1[item_def_reply_1_iter].member_discount, (f64)packet->item_def_reply_1[item_def_reply_1_iter].member_discount);

// u32 vip_rank_required
packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- vip_rank_required       \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required, (u64)packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required, (f64)packet->item_def_reply_1[item_def_reply_1_iter].vip_rank_required);

// u32 race_set_id
packet->item_def_reply_1[item_def_reply_1_iter].race_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- race_set_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].race_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].race_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].race_set_id);

// u32 ui_model_camera_id_1
packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ui_model_camera_id_1    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_1);

// u32 equip_count_max
packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- equip_count_max         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max, (u64)packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max, (f64)packet->item_def_reply_1[item_def_reply_1_iter].equip_count_max);

// i32 curreny_type
packet->item_def_reply_1[item_def_reply_1_iter].curreny_type = endian_read_i32_little(data + offset);
offset += sizeof(i32);
printf("-- curreny_type            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].curreny_type, (u64)packet->item_def_reply_1[item_def_reply_1_iter].curreny_type, (f64)packet->item_def_reply_1[item_def_reply_1_iter].curreny_type);

// u32 datasheet_id
packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- datasheet_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].datasheet_id);

// u32 item_type_1
packet->item_def_reply_1[item_def_reply_1_iter].item_type_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_type_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].item_type_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].item_type_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].item_type_1);

// u32 skill_set_id
packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- skill_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].skill_set_id);

// string overlay_texture
packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length);
for (u32 overlay_texture_iter = 0; overlay_texture_iter < packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture_length; overlay_texture_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].overlay_texture[overlay_texture_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string decal_slot
packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].decal_slot = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length);
for (u32 decal_slot_iter = 0; decal_slot_iter < packet->item_def_reply_1[item_def_reply_1_iter].decal_slot_length; decal_slot_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].decal_slot[decal_slot_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 overlay_adjustment
packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- overlay_adjustment      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment, (u64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment, (f64)packet->item_def_reply_1[item_def_reply_1_iter].overlay_adjustment);

// u32 trial_duration_sec
packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- trial_duration_sec      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec, (u64)packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec, (f64)packet->item_def_reply_1[item_def_reply_1_iter].trial_duration_sec);

// u32 next_trial_delay_sec
packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- next_trial_delay_sec    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec, (u64)packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec, (f64)packet->item_def_reply_1[item_def_reply_1_iter].next_trial_delay_sec);

// u32 client_use_requirement
packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- client_use_requirement  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement, (u64)packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement, (f64)packet->item_def_reply_1[item_def_reply_1_iter].client_use_requirement);

// string override_appearance
packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].override_appearance = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length);
for (u32 override_appearance_iter = 0; override_appearance_iter < packet->item_def_reply_1[item_def_reply_1_iter].override_appearance_length; override_appearance_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].override_appearance[override_appearance_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 override_camera_id
packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- override_camera_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].override_camera_id);

// u32 unk_dword_3
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_3             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_3);

// u32 unk_dword_4
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_4             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_4);

// u32 unk_dword_5
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_5             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_5);

// u32 bulk
packet->item_def_reply_1[item_def_reply_1_iter].bulk = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- bulk                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].bulk, (u64)packet->item_def_reply_1[item_def_reply_1_iter].bulk, (f64)packet->item_def_reply_1[item_def_reply_1_iter].bulk);

// u32 active_equip_slot_id
packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- active_equip_slot_id    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].active_equip_slot_id);

// u32 passive_equip_slot_id
packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_equip_slot_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_id);

// u32 passive_equip_slot_group_id
packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_equip_slot_group_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].passive_equip_slot_group_id);

// u32 unk_dword_6
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_6             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_6);

// u32 grinder_reward_set_id
packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- grinder_reward_set_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].grinder_reward_set_id);

// u32 build_bar_group_id
packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- build_bar_group_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].build_bar_group_id);

// string unk_string_1
packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1 = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1_length; unk_string_1_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].unk_string_1[unk_string_1_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// b8 unk_bool_1
packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1 = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- unk_bool_1              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_bool_1);

// b8 is_armor
packet->item_def_reply_1[item_def_reply_1_iter].is_armor = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_armor                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].is_armor, (u64)packet->item_def_reply_1[item_def_reply_1_iter].is_armor, (f64)packet->item_def_reply_1[item_def_reply_1_iter].is_armor);

// u32 unk_dword_7
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_7             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_7);

// u32 param1
packet->item_def_reply_1[item_def_reply_1_iter].param1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- param1                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].param1, (u64)packet->item_def_reply_1[item_def_reply_1_iter].param1, (f64)packet->item_def_reply_1[item_def_reply_1_iter].param1);

// u32 param2
packet->item_def_reply_1[item_def_reply_1_iter].param2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- param2                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].param2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].param2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].param2);

// u32 param3
packet->item_def_reply_1[item_def_reply_1_iter].param3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- param3                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].param3, (u64)packet->item_def_reply_1[item_def_reply_1_iter].param3, (f64)packet->item_def_reply_1[item_def_reply_1_iter].param3);

// string string_param1
packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].string_param1 = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length);
for (u32 string_param1_iter = 0; string_param1_iter < packet->item_def_reply_1[item_def_reply_1_iter].string_param1_length; string_param1_iter++)
{
packet->item_def_reply_1[item_def_reply_1_iter].string_param1[string_param1_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 ui_model_camera_id_2
packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ui_model_camera_id_2    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2, (u64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2, (f64)packet->item_def_reply_1[item_def_reply_1_iter].ui_model_camera_id_2);

// u32 unk_dword_8
packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_8             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8, (u64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8, (f64)packet->item_def_reply_1[item_def_reply_1_iter].unk_dword_8);

// i32 scrap_value_override
packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override = endian_read_i32_little(data + offset);
offset += sizeof(i32);
printf("-- scrap_value_override    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override, (u64)packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override, (f64)packet->item_def_reply_1[item_def_reply_1_iter].scrap_value_override);

// list stats_item_def_1
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1 = memory_arena_push_length(arena, packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count * sizeof(packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[0]));
printf("-- LIST_COUNT              \t%d\n", packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count);
for (u32 stats_item_def_1_iter = 0; stats_item_def_1_iter < packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1_count; stats_item_def_1_iter++)
{
// u32 unk_dword_9
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_9             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_9);

// u32 stat_id
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- stat_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].stat_id);

// f32 base
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- base                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].base);

// f32 modifier
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- modifier                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].modifier);

// u32 unk_dword_10
packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_10            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10, (u64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10, (f64)packet->item_def_reply_1[item_def_reply_1_iter].stats_item_def_1[stats_item_def_1_iter].unk_dword_10);

} // stats_item_def_1

} // item_def_reply_1

} break;

case Zone_Packet_Kind_CommandItemDefinitions:
{
printf("[*] Unpacking CommandItemDefinitions...\n");
Zone_Packet_CommandItemDefinitions* packet = packet_ptr;

// stream item_def_reply_2
packet->item_def_reply_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2 = memory_arena_push_length(arena, packet->item_def_reply_2_length * sizeof(packet->item_def_reply_2[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->item_def_reply_2_length);
for (u32 item_def_reply_2_iter = 0; item_def_reply_2_iter < (packet->item_def_reply_2_length > (u32)0 ? (u32)1 : (u32)0); item_def_reply_2_iter++)
{
// list item_defs
packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count * sizeof(packet->item_def_reply_2[item_def_reply_2_iter].item_defs[0]));
printf("-- LIST_COUNT              \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count);
for (u32 item_defs_iter = 0; item_defs_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs_count; item_defs_iter++)
{
// u32 defs_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- defs_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].defs_id);

// u8 bitflags1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- bitflags1               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags1);

// u8 bitflags2
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- bitflags2               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bitflags2);

// u32 name_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].name_id);

// u32 description_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].description_id);

// u32 content_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- content_id              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].content_id);

// u32 image_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- image_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].image_set_id);

// u32 tint_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- tint_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_id);

// u32 hud_image_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- hud_image_set_id        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].hud_image_set_id);

// u32 unk_dword_1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_1);

// u32 unk_dword_2
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_2             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_2);

// u32 cost
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- cost                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].cost);

// u32 item_class
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_class              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_class);

// u32 profile_override
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- profile_override        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].profile_override);

// string model_name
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name_length; model_name_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].model_name[model_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string texture_alias
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length);
for (u32 texture_alias_iter = 0; texture_alias_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias_length; texture_alias_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].texture_alias[texture_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 gender_usage
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- gender_usage            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].gender_usage);

// u32 item_type
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_type               \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type);

// u32 category_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- category_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].category_id);

// u32 weapon_trail_effect_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- weapon_trail_effect_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].weapon_trail_effect_id);

// u32 composite_effect_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- composite_effect_id     \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].composite_effect_id);

// u32 power_rating
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- power_rating            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].power_rating);

// u32 min_profile_rank
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- min_profile_rank        \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_profile_rank);

// u32 rarity
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- rarity                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].rarity);

// u32 activatable_ability_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- activatable_ability_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_id);

// u32 activatable_ability_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- activatable_ability_set_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].activatable_ability_set_id);

// u32 passive_ability_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_ability_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_id);

// u32 passive_ability_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_ability_set_id  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_ability_set_id);

// u32 max_stack_size
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- max_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].max_stack_size);

// u32 min_stack_size
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- min_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].min_stack_size);

// string tint_alias
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias_length; tint_alias_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_alias[tint_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 tint_group_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- tint_group_id           \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].tint_group_id);

// u32 member_discount
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- member_discount         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].member_discount);

// u32 vip_rank_required
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- vip_rank_required       \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].vip_rank_required);

// u32 race_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- race_set_id             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].race_set_id);

// u32 ui_model_camera_id_1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ui_model_camera_id_1    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_1);

// u32 equip_count_max
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- equip_count_max         \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].equip_count_max);

// i32 curreny_type
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type = endian_read_i32_little(data + offset);
offset += sizeof(i32);
printf("-- curreny_type            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].curreny_type);

// u32 datasheet_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- datasheet_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].datasheet_id);

// u32 item_type_1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_type_1             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].item_type_1);

// u32 skill_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- skill_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].skill_set_id);

// string overlay_texture
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length);
for (u32 overlay_texture_iter = 0; overlay_texture_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture_length; overlay_texture_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_texture[overlay_texture_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string decal_slot
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length);
for (u32 decal_slot_iter = 0; decal_slot_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot_length; decal_slot_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].decal_slot[decal_slot_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 overlay_adjustment
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- overlay_adjustment      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].overlay_adjustment);

// u32 trial_duration_sec
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- trial_duration_sec      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].trial_duration_sec);

// u32 next_trial_delay_sec
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- next_trial_delay_sec    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].next_trial_delay_sec);

// u32 client_use_requirement
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- client_use_requirement  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].client_use_requirement);

// string override_appearance
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length);
for (u32 override_appearance_iter = 0; override_appearance_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance_length; override_appearance_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_appearance[override_appearance_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 override_camera_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- override_camera_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].override_camera_id);

// u32 unk_dword_3
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_3             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_3);

// u32 unk_dword_4
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_4             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_4);

// u32 unk_dword_5
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_5             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_5);

// u32 bulk
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- bulk                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].bulk);

// u32 active_equip_slot_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- active_equip_slot_id    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].active_equip_slot_id);

// u32 passive_equip_slot_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_equip_slot_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_id);

// u32 passive_equip_slot_group_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_equip_slot_group_id\t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].passive_equip_slot_group_id);

// u32 unk_dword_6
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_6             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_6);

// u32 grinder_reward_set_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- grinder_reward_set_id   \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].grinder_reward_set_id);

// u32 build_bar_group_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- build_bar_group_id      \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].build_bar_group_id);

// string unk_string_1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1 = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1_length; unk_string_1_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_string_1[unk_string_1_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// b8 unk_bool_1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1 = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- unk_bool_1              \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_bool_1);

// b8 is_armor
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_armor                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].is_armor);

// u32 unk_dword_7
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_7             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_7);

// u32 param1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- param1                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param1);

// u32 param2
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- param2                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param2);

// u32 param3
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- param3                  \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].param3);

// string string_param1
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1 = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length);
printf("-- STRING_LENGTH           \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length);
for (u32 string_param1_iter = 0; string_param1_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1_length; string_param1_iter++)
{
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].string_param1[string_param1_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 ui_model_camera_id_2
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ui_model_camera_id_2    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].ui_model_camera_id_2);

// u32 unk_dword_8
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_8             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].unk_dword_8);

// i32 scrap_value_override
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override = endian_read_i32_little(data + offset);
offset += sizeof(i32);
printf("-- scrap_value_override    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].scrap_value_override);

// list stats_item_def_2
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2 = memory_arena_push_length(arena, packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count * sizeof(packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[0]));
printf("-- LIST_COUNT              \t%d\n", packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count);
for (u32 stats_item_def_2_iter = 0; stats_item_def_2_iter < packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2_count; stats_item_def_2_iter++)
{
// u32 unk_dword_9
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_9             \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_9);

// u32 stat_id
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- stat_id                 \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].stat_id);

// u32 base
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- base                    \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].base);

// u32 modifier
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- modifier                \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].modifier);

// u32 unk_dword_10
packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_10            \t%lld\t%llxh\t%f\n", (i64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10, (u64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10, (f64)packet->item_def_reply_2[item_def_reply_2_iter].item_defs[item_defs_iter].stats_item_def_2[stats_item_def_2_iter].unk_dword_10);

} // stats_item_def_2

} // item_defs

} // item_def_reply_2

} break;

case Zone_Packet_Kind_Character_RemovePlayer:
{
printf("[*] Unpacking Character_RemovePlayer...\n");
Zone_Packet_Character_RemovePlayer* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u16 unk_u16
packet->unk_u16 = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- unk_u16                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u16, (u64)packet->unk_u16, (f64)packet->unk_u16);

// u8 unk_u8
packet->unk_u8 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_u8                  \t%lld\t%llxh\t%f\n", (i64)packet->unk_u8, (u64)packet->unk_u8, (f64)packet->unk_u8);

// u32 unk_u32
packet->unk_u32 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 effect_delay
packet->effect_delay = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- effect_delay            \t%lld\t%llxh\t%f\n", (i64)packet->effect_delay, (u64)packet->effect_delay, (f64)packet->effect_delay);

// u32 effect_id
packet->effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- effect_id               \t%lld\t%llxh\t%f\n", (i64)packet->effect_id, (u64)packet->effect_id, (f64)packet->effect_id);

// u32 sticky_effect_id
packet->sticky_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- sticky_effect_id        \t%lld\t%llxh\t%f\n", (i64)packet->sticky_effect_id, (u64)packet->sticky_effect_id, (f64)packet->sticky_effect_id);

// u32 time_to_disappear
packet->time_to_disappear = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- time_to_disappear       \t%lld\t%llxh\t%f\n", (i64)packet->time_to_disappear, (u64)packet->time_to_disappear, (f64)packet->time_to_disappear);

} break;

case Zone_Packet_Kind_Character_UpdateScale:
{
printf("[*] Unpacking Character_UpdateScale...\n");
Zone_Packet_Character_UpdateScale* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// vec4 scale
packet->scale = endian_read_vec4_little(data + offset);
offset += sizeof(f32) * 4;
printf("-- scale                   \t%f\t%f\t%f\t%f\n", (f64)packet->scale.x, (f64)packet->scale.y, (f64)packet->scale.z, (f64)packet->scale.w);

} break;

case Zone_Packet_Kind_Character_WeaponStance:
{
printf("[*] Unpacking Character_WeaponStance...\n");
Zone_Packet_Character_WeaponStance* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 stance
packet->stance = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- stance                  \t%lld\t%llxh\t%f\n", (i64)packet->stance, (u64)packet->stance, (f64)packet->stance);

} break;

case Zone_Packet_Kind_Character_CharacterStateDelta:
{
printf("[*] Unpacking Character_CharacterStateDelta...\n");
Zone_Packet_Character_CharacterStateDelta* packet = packet_ptr;

// u64 guid_1
packet->guid_1 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- guid_1                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_1, (u64)packet->guid_1, (f64)packet->guid_1);

// u64 guid_2
packet->guid_2 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- guid_2                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_2, (u64)packet->guid_2, (f64)packet->guid_2);

// u64 guid_3
packet->guid_3 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- guid_3                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_3, (u64)packet->guid_3, (f64)packet->guid_3);

// u64 guid_4
packet->guid_4 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- guid_4                  \t%lld\t%llxh\t%f\n", (i64)packet->guid_4, (u64)packet->guid_4, (f64)packet->guid_4);

// u32 game_time
packet->game_time = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- game_time               \t%lld\t%llxh\t%f\n", (i64)packet->game_time, (u64)packet->game_time, (f64)packet->game_time);

} break;

case Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters:
{
printf("[*] Unpacking ClientUpdate_DoneSendingPreloadCharacters...\n");
Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters* packet = packet_ptr;

// b8 is_done
packet->is_done = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_done                 \t%lld\t%llxh\t%f\n", (i64)packet->is_done, (u64)packet->is_done, (f64)packet->is_done);

} break;

case Zone_Packet_Kind_ClientUpdate_TextAlert:
{
printf("[*] Unpacking ClientUpdate_TextAlert...\n");
Zone_Packet_ClientUpdate_TextAlert* packet = packet_ptr;

// string message
packet->message_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->message = memory_arena_push_length(arena, packet->message_length);
printf("-- STRING_LENGTH           \t%d\n", packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
packet->message[message_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} break;

case Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift:
{
printf("[*] Unpacking ClientUpdate_MonitorTimeDrift...\n");
Zone_Packet_ClientUpdate_MonitorTimeDrift* packet = packet_ptr;

// u32 time_drift
packet->time_drift = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- time_drift              \t%lld\t%llxh\t%f\n", (i64)packet->time_drift, (u64)packet->time_drift, (f64)packet->time_drift);

} break;

case Zone_Packet_Kind_SendZoneDetails:
{
printf("[*] Unpacking SendZoneDetails...\n");
Zone_Packet_SendZoneDetails* packet = packet_ptr;

// string zone_name
packet->zone_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->zone_name = memory_arena_push_length(arena, packet->zone_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->zone_name_length);
for (u32 zone_name_iter = 0; zone_name_iter < packet->zone_name_length; zone_name_iter++)
{
packet->zone_name[zone_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 zone_type
packet->zone_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- zone_type               \t%lld\t%llxh\t%f\n", (i64)packet->zone_type, (u64)packet->zone_type, (f64)packet->zone_type);

// u8 unk_bool
packet->unk_bool = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

// f32 unknownDword1
packet->unknownDword1 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknownDword1           \t%lld\t%llxh\t%f\n", (i64)packet->unknownDword1, (u64)packet->unknownDword1, (f64)packet->unknownDword1);

// f32 fog_density
packet->fog_density = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fog_density             \t%lld\t%llxh\t%f\n", (i64)packet->fog_density, (u64)packet->fog_density, (f64)packet->fog_density);

// f32 fog_floor
packet->fog_floor = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fog_floor               \t%lld\t%llxh\t%f\n", (i64)packet->fog_floor, (u64)packet->fog_floor, (f64)packet->fog_floor);

// f32 fog_gradient
packet->fog_gradient = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fog_gradient            \t%lld\t%llxh\t%f\n", (i64)packet->fog_gradient, (u64)packet->fog_gradient, (f64)packet->fog_gradient);

// f32 rain
packet->rain = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- rain                    \t%lld\t%llxh\t%f\n", (i64)packet->rain, (u64)packet->rain, (f64)packet->rain);

// f32 temp
packet->temp = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- temp                    \t%lld\t%llxh\t%f\n", (i64)packet->temp, (u64)packet->temp, (f64)packet->temp);

// f32 color_gradient
packet->color_gradient = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- color_gradient          \t%lld\t%llxh\t%f\n", (i64)packet->color_gradient, (u64)packet->color_gradient, (f64)packet->color_gradient);

// f32 unknown_dword8
packet->unknown_dword8 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword8          \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword8, (u64)packet->unknown_dword8, (f64)packet->unknown_dword8);

// f32 unknown_dword9
packet->unknown_dword9 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword9          \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword9, (u64)packet->unknown_dword9, (f64)packet->unknown_dword9);

// f32 unknown_dword10
packet->unknown_dword10 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword10         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword10, (u64)packet->unknown_dword10, (f64)packet->unknown_dword10);

// f32 unknown_dword11
packet->unknown_dword11 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword11         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword11, (u64)packet->unknown_dword11, (f64)packet->unknown_dword11);

// f32 unknown_dword12
packet->unknown_dword12 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword12         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword12, (u64)packet->unknown_dword12, (f64)packet->unknown_dword12);

// f32 sun_axis_x
packet->sun_axis_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sun_axis_x              \t%lld\t%llxh\t%f\n", (i64)packet->sun_axis_x, (u64)packet->sun_axis_x, (f64)packet->sun_axis_x);

// f32 sun_axis_y
packet->sun_axis_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sun_axis_y              \t%lld\t%llxh\t%f\n", (i64)packet->sun_axis_y, (u64)packet->sun_axis_y, (f64)packet->sun_axis_y);

// f32 unknown_dword15
packet->unknown_dword15 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword15         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword15, (u64)packet->unknown_dword15, (f64)packet->unknown_dword15);

// f32 disable_trees
packet->disable_trees = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- disable_trees           \t%lld\t%llxh\t%f\n", (i64)packet->disable_trees, (u64)packet->disable_trees, (f64)packet->disable_trees);

// f32 disable_trees1
packet->disable_trees1 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- disable_trees1          \t%lld\t%llxh\t%f\n", (i64)packet->disable_trees1, (u64)packet->disable_trees1, (f64)packet->disable_trees1);

// f32 disable_trees2
packet->disable_trees2 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- disable_trees2          \t%lld\t%llxh\t%f\n", (i64)packet->disable_trees2, (u64)packet->disable_trees2, (f64)packet->disable_trees2);

// f32 wind
packet->wind = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- wind                    \t%lld\t%llxh\t%f\n", (i64)packet->wind, (u64)packet->wind, (f64)packet->wind);

// f32 unknown_dword20
packet->unknown_dword20 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword20         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword20, (u64)packet->unknown_dword20, (f64)packet->unknown_dword20);

// f32 unknown_dword21
packet->unknown_dword21 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword21         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword21, (u64)packet->unknown_dword21, (f64)packet->unknown_dword21);

// string name
packet->name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->name = memory_arena_push_length(arena, packet->name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->name_length);
for (u32 name_iter = 0; name_iter < packet->name_length; name_iter++)
{
packet->name[name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// f32 unknown_dword22
packet->unknown_dword22 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword22         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword22, (u64)packet->unknown_dword22, (f64)packet->unknown_dword22);

// f32 unknown_dword23
packet->unknown_dword23 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword23         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword23, (u64)packet->unknown_dword23, (f64)packet->unknown_dword23);

// f32 unknown_dword24
packet->unknown_dword24 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword24         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword24, (u64)packet->unknown_dword24, (f64)packet->unknown_dword24);

// f32 unknown_dword25
packet->unknown_dword25 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword25         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword25, (u64)packet->unknown_dword25, (f64)packet->unknown_dword25);

// f32 unknown_dword26
packet->unknown_dword26 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword26         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword26, (u64)packet->unknown_dword26, (f64)packet->unknown_dword26);

// f32 unknown_dword27
packet->unknown_dword27 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword27         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword27, (u64)packet->unknown_dword27, (f64)packet->unknown_dword27);

// f32 unknown_dword28
packet->unknown_dword28 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword28         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword28, (u64)packet->unknown_dword28, (f64)packet->unknown_dword28);

// f32 unknown_dword29
packet->unknown_dword29 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword29         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword29, (u64)packet->unknown_dword29, (f64)packet->unknown_dword29);

// f32 ao_size
packet->ao_size = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- ao_size                 \t%lld\t%llxh\t%f\n", (i64)packet->ao_size, (u64)packet->ao_size, (f64)packet->ao_size);

// f32 ao_gamma
packet->ao_gamma = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- ao_gamma                \t%lld\t%llxh\t%f\n", (i64)packet->ao_gamma, (u64)packet->ao_gamma, (f64)packet->ao_gamma);

// f32 ao_blackpoint
packet->ao_blackpoint = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- ao_blackpoint           \t%lld\t%llxh\t%f\n", (i64)packet->ao_blackpoint, (u64)packet->ao_blackpoint, (f64)packet->ao_blackpoint);

// f32 unknown_dword33
packet->unknown_dword33 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unknown_dword33         \t%lld\t%llxh\t%f\n", (i64)packet->unknown_dword33, (u64)packet->unknown_dword33, (f64)packet->unknown_dword33);

// u32 zone_id
packet->zone_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- zone_id                 \t%lld\t%llxh\t%f\n", (i64)packet->zone_id, (u64)packet->zone_id, (f64)packet->zone_id);

// u32 zone_id_2
packet->zone_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- zone_id_2               \t%lld\t%llxh\t%f\n", (i64)packet->zone_id_2, (u64)packet->zone_id_2, (f64)packet->zone_id_2);

// u32 name_id
packet->name_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->name_id, (u64)packet->name_id, (f64)packet->name_id);

// u8 unk_bool2
packet->unk_bool2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_bool2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool2, (u64)packet->unk_bool2, (f64)packet->unk_bool2);

// string lighting
packet->lighting_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->lighting = memory_arena_push_length(arena, packet->lighting_length);
printf("-- STRING_LENGTH           \t%d\n", packet->lighting_length);
for (u32 lighting_iter = 0; lighting_iter < packet->lighting_length; lighting_iter++)
{
packet->lighting[lighting_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u8 unk_bool3
packet->unk_bool3 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_bool3               \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool3, (u64)packet->unk_bool3, (f64)packet->unk_bool3);

} break;

case Zone_Packet_Kind_ReferenceDataWeaponDefinitions:
{
printf("[*] Unpacking ReferenceDataWeaponDefinitions...\n");
Zone_Packet_ReferenceDataWeaponDefinitions* packet = packet_ptr;

// stream weapon_byteswithlength
packet->weapon_byteswithlength_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength = memory_arena_push_length(arena, packet->weapon_byteswithlength_length * sizeof(packet->weapon_byteswithlength[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->weapon_byteswithlength_length);
for (u32 weapon_byteswithlength_iter = 0; weapon_byteswithlength_iter < (packet->weapon_byteswithlength_length > (u32)0 ? (u32)1 : (u32)0); weapon_byteswithlength_iter++)
{
// list weapon_defs
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count);
for (u32 weapon_defs_iter = 0; weapon_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs_count; weapon_defs_iter++)
{
// u32 id1
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id1                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id1);

// u32 id2
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id2                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].id2);

// u32 weapon_group_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- weapon_group_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].weapon_group_id);

// u8 flags1
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flags1                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].flags1);

// u32 equip_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- equip_ms                \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].equip_ms);

// u32 unequip_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unequip_ms              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].unequip_ms);

// u32 from_passive_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- from_passive_ms         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_passive_ms);

// u32 to_passive_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- to_passive_ms           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_passive_ms);

// u32 xp_category
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- xp_category             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].xp_category);

// u32 to_iron_sights_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- to_iron_sights_ms       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_ms);

// u32 from_iron_sights_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- from_iron_sights_ms     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_ms);

// u32 to_iron_sights_anim_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- to_iron_sights_anim_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].to_iron_sights_anim_ms);

// u32 from_iron_sights_anim_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- from_iron_sights_anim_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].from_iron_sights_anim_ms);

// u32 sprint_recovery_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- sprint_recovery_ms      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].sprint_recovery_ms);

// u32 next_use_delay_msec
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- next_use_delay_msec     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].next_use_delay_msec);

// f32 turn_rate_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- turn_rate_modifier      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].turn_rate_modifier);

// f32 movement_speed_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- movement_speed_modifier \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].movement_speed_modifier);

// u32 propulsion_type
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- propulsion_type         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].propulsion_type);

// u32 heat_bleed_off_rate
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- heat_bleed_off_rate     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_bleed_off_rate);

// u32 heat_capacity
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- heat_capacity           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].heat_capacity);

// u32 overheat_penalty_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- overheat_penalty_ms     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_penalty_ms);

// u32 range_string_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- range_string_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].range_string_id);

// u32 melee_detect_width
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- melee_detect_width      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_width);

// u32 melee_detect_height
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- melee_detect_height     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].melee_detect_height);

// string anim_set_name
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length);
for (u32 anim_set_name_iter = 0; anim_set_name_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name_length; anim_set_name_iter++)
{
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].anim_set_name[anim_set_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 vehicle_fp_camera_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- vehicle_fp_camera_id    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_fp_camera_id);

// u32 vehicle_tp_camera_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- vehicle_tp_camera_id    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].vehicle_tp_camera_id);

// u32 overheat_effect_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- overheat_effect_id      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].overheat_effect_id);

// f32 min_pitch
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_pitch               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].min_pitch);

// f32 max_pitch
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_pitch               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].max_pitch);

// u32 audio_game_object
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- audio_game_object       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].audio_game_object);

// list ammo_slots
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count);
for (u32 ammo_slots_iter = 0; ammo_slots_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots_count; ammo_slots_iter++)
{
// u32 ammo_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ammo_id                 \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].ammo_id);

// u32 clip_size
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- clip_size               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_size);

// u32 capacity
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- capacity                \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].capacity);

// b8 start_empty
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- start_empty             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].start_empty);

// u32 refill_ammo_per_tick
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- refill_ammo_per_tick    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_per_tick);

// u32 refill_ammo_delay_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- refill_ammo_delay_ms    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].refill_ammo_delay_ms);

// u32 clip_attachment_slot
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- clip_attachment_slot    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_attachment_slot);

// string clip_model_name
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length);
for (u32 clip_model_name_iter = 0; clip_model_name_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name_length; clip_model_name_iter++)
{
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].clip_model_name[clip_model_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string reload_weapon_bone
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length);
printf("-- STRING_LENGTH           \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length);
for (u32 reload_weapon_bone_iter = 0; reload_weapon_bone_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone_length; reload_weapon_bone_iter++)
{
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_weapon_bone[reload_weapon_bone_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string reload_character_bone
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length);
printf("-- STRING_LENGTH           \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length);
for (u32 reload_character_bone_iter = 0; reload_character_bone_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone_length; reload_character_bone_iter++)
{
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].ammo_slots[ammo_slots_iter].reload_character_bone[reload_character_bone_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} // ammo_slots

// list fire_groups
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count);
for (u32 fire_groups_iter = 0; fire_groups_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups_count; fire_groups_iter++)
{
// u32 fire_group_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- fire_group_id           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].weapon_defs[weapon_defs_iter].fire_groups[fire_groups_iter].fire_group_id);

} // fire_groups

} // weapon_defs

// list fire_group_defs
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count);
for (u32 fire_group_defs_iter = 0; fire_group_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs_count; fire_group_defs_iter++)
{
// u32 id3
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id3                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id3);

// u32 id4
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id4                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].id4);

// list fire_mode_list
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count);
for (u32 fire_mode_list_iter = 0; fire_mode_list_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list_count; fire_mode_list_iter++)
{
// u32 fire_mode_1
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- fire_mode_1             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].fire_mode_list[fire_mode_list_iter].fire_mode_1);

} // fire_mode_list

// u8 flags2
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flags2                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].flags2);

// u32 chamber_duration_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- chamber_duration_ms     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].chamber_duration_ms);

// u32 image_set_override
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- image_set_override      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].image_set_override);

// u32 transition_duration_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- transition_duration_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].transition_duration_ms);

// u32 anim_actor_slot_override
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- anim_actor_slot_override\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].anim_actor_slot_override);

// u32 deployable_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- deployable_id           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].deployable_id);

// u32 spin_up_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- spin_up_time_ms         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_time_ms);

// u32 spin_up_movement_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- spin_up_movement_modifier\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_movement_modifier);

// u32 spin_up_turn_rate_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- spin_up_turn_rate_modifier\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spin_up_turn_rate_modifier);

// u32 spool_up_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- spool_up_time_ms        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_time_ms);

// u32 spool_up_initial_refire_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- spool_up_initial_refire_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_group_defs[fire_group_defs_iter].spool_up_initial_refire_ms);

} // fire_group_defs

// list fire_mode_defs
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count);
for (u32 fire_mode_defs_iter = 0; fire_mode_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs_count; fire_mode_defs_iter++)
{
// u32 id5
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id5                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id5);

// u32 id6
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id6                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].id6);

// u8 flag1
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flag1                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag1);

// u8 flag2
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flag2                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag2);

// u8 flag3
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flag3                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].flag3);

// u8 type
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- type                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].type);

// u32 ammo_item_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ammo_item_id            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_item_id);

// u8 ammo_slot
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- ammo_slot               \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_slot);

// u8 burst_count
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- burst_count             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].burst_count);

// u16 fire_duration_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- fire_duration_ms        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_duration_ms);

// u16 fire_cooldown_duration_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- fire_cooldown_duration_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_cooldown_duration_ms);

// u16 refire_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- refire_time_ms          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].refire_time_ms);

// u16 auto_fire_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- auto_fire_time_ms       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].auto_fire_time_ms);

// u16 cook_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- cook_time_ms            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cook_time_ms);

// f32 range
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- range                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].range);

// u8 ammo_per_shot
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- ammo_per_shot           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].ammo_per_shot);

// u16 reload_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- reload_time_ms          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_time_ms);

// u16 reload_chamber_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- reload_chamber_time_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_chamber_time_ms);

// u16 reload_ammo_fill_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- reload_ammo_fill_time_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_ammo_fill_time_ms);

// u16 reload_loop_start_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- reload_loop_start_time_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_start_time_ms);

// u16 reload_loop_end_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- reload_loop_end_time_ms \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reload_loop_end_time_ms);

// u8 pellets_per_shot
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- pellets_per_shot        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellets_per_shot);

// f32 pellet_spread
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- pellet_spread           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].pellet_spread);

// f32 cof_recoil
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_recoil              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_recoil);

// f32 cof_scalar
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_scalar              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar);

// f32 cof_scalar_moving
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_scalar_moving       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_scalar_moving);

// f32 cof_override
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_override            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cof_override);

// f32 recoil_angle_min
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_angle_min        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_min);

// f32 recoil_angle_max
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_angle_max        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_angle_max);

// f32 recoil_horizontal_tolerance
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_horizontal_tolerance\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_tolerance);

// f32 recoil_horizontal_min
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_horizontal_min   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min);

// f32 recoil_horizontal_max
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_horizontal_max   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max);

// f32 recoil_magnitude_min
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_magnitude_min    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_min);

// f32 recoil_magnitude_max
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_magnitude_max    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_magnitude_max);

// u16 recoil_recovery_delay_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- recoil_recovery_delay_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_delay_ms);

// f32 recoil_recovery_rate
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_recovery_rate    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_rate);

// f32 recoil_recovery_acceleration
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_recovery_acceleration\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_recovery_acceleration);

// u8 recoil_shots_at_min_magnitude
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- recoil_shots_at_min_magnitude\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_shots_at_min_magnitude);

// f32 recoil_max_total_magnitude
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_max_total_magnitude\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_max_total_magnitude);

// f32 recoil_increase
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_increase         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase);

// f32 recoil_increase_crouched
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_increase_crouched\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_increase_crouched);

// f32 recoil_first_shot_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_first_shot_modifier\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_first_shot_modifier);

// f32 recoil_horizontal_min_increase
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_horizontal_min_increase\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_min_increase);

// f32 recoil_horizontal_max_increase
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- recoil_horizontal_max_increase\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].recoil_horizontal_max_increase);

// u16 fire_detect_range
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- fire_detect_range       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_detect_range);

// f32 effect_group
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- effect_group            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].effect_group);

// f32 player_state_group_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- player_state_group_id   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].player_state_group_id);

// f32 movement_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- movement_modifier       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].movement_modifier);

// f32 turn_modifier
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- turn_modifier           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].turn_modifier);

// f32 lock_on_icon_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- lock_on_icon_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_icon_id);

// f32 lock_on_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- lock_on_angle           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_angle);

// f32 lock_on_radius
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- lock_on_radius          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_radius);

// f32 lock_on_range
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- lock_on_range           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range);

// f32 lock_on_range_close
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- lock_on_range_close     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_close);

// f32 lock_on_range_far
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- lock_on_range_far       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_range_far);

// u16 lock_on_acquire_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- lock_on_acquire_time_ms \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_ms);

// u16 lock_on_acquire_time_close_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- lock_on_acquire_time_close_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_close_ms);

// u16 lock_on_acquire_time_far_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- lock_on_acquire_time_far_ms\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_acquire_time_far_ms);

// u16 lock_on_lose_time_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- lock_on_lose_time_ms    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].lock_on_lose_time_ms);

// f32 default_zoom
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- default_zoom            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].default_zoom);

// f32 fp_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fp_offset_x             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_x);

// f32 fp_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fp_offset_y             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_y);

// f32 fp_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fp_offset_z             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_offset_z);

// u8 reticle_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- reticle_id              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].reticle_id);

// u8 full_screen_effect
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- full_screen_effect      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].full_screen_effect);

// u32 heat_per_shot
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- heat_per_shot           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_per_shot);

// u32 heat_threshold
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- heat_threshold          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_threshold);

// u16 heat_recovery_delay_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms = endian_read_u16_little(data + offset);
offset += sizeof(u16);
printf("-- heat_recovery_delay_ms  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].heat_recovery_delay_ms);

// f32 sway_amplitude_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_amplitude_x        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_x);

// f32 sway_amplitude_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_amplitude_y        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_amplitude_y);

// f32 sway_period_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_period_x           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_x);

// f32 sway_period_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_period_y           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_period_y);

// f32 sway_initial_y_offset
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_initial_y_offset   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_initial_y_offset);

// f32 arms_fov_scalar
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- arms_fov_scalar         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].arms_fov_scalar);

// f32 anim_kick_magnitude
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- anim_kick_magnitude     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_kick_magnitude);

// f32 anim_recoil_magnitude
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- anim_recoil_magnitude   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].anim_recoil_magnitude);

// u32 description_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].description_id);

// u32 indirect_effect
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- indirect_effect         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].indirect_effect);

// f32 bullet_arc_kick_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- bullet_arc_kick_angle   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].bullet_arc_kick_angle);

// f32 projectile_speed_override
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- projectile_speed_override\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].projectile_speed_override);

// u32 inherit_from_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- inherit_from_id         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_id);

// f32 inherit_from_charge_power
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- inherit_from_charge_power\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].inherit_from_charge_power);

// u32 hud_image_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- hud_image_id            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].hud_image_id);

// u32 target_requirement
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- target_requirement      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].target_requirement);

// u32 fire_anim_duration_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- fire_anim_duration_ms   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fire_anim_duration_ms);

// u8 sequential_fire_anim_start
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- sequential_fire_anim_start\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_start);

// u8 sequential_fire_anim_count
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- sequential_fire_anim_count\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sequential_fire_anim_count);

// f32 cylof_recoil
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_recoil            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_recoil);

// f32 cylof_scalar
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_scalar            \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar);

// f32 cylof_scalar_moving
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_scalar_moving     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_scalar_moving);

// f32 cylof_override
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_override          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].cylof_override);

// u32 melee_composite_effect_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- melee_composite_effect_id\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_composite_effect_id);

// u32 melee_ability_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- melee_ability_id        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].melee_ability_id);

// f32 sway_crouch_scalar
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_crouch_scalar      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_crouch_scalar);

// f32 sway_prone_scalar
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- sway_prone_scalar       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].sway_prone_scalar);

// f32 launch_pitch_additive_degrees
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- launch_pitch_additive_degrees\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].launch_pitch_additive_degrees);

// b8 tp_force_camera_overrides
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- tp_force_camera_overrides\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_force_camera_overrides);

// f32 tp_camera_look_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_x \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_x);

// f32 tp_camera_look_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_y \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y);

// f32 tp_camera_look_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_z \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_z);

// f32 tp_camera_position_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_position_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_x);

// f32 tp_camera_position_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_position_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_y);

// f32 tp_camera_position_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_position_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_position_offset_z);

// f32 tp_camera_fov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_fov           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_fov);

// b8 fp_force_camera_overrides
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- fp_force_camera_overrides\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_force_camera_overrides);

// f32 tp_extra_lead_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_lead_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_a);

// f32 tp_extra_lead_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_lead_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_from_pitch_b);

// f32 tp_extra_lead_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_lead_pitch_a   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_a);

// f32 tp_extra_lead_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_lead_pitch_b   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_lead_pitch_b);

// f32 tp_extra_height_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_height_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_a);

// f32 tp_extra_height_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_height_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_from_pitch_b);

// f32 tp_extra_height_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_height_pitch_a \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_a);

// f32 tp_extra_height_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_height_pitch_b \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_height_pitch_b);

// f32 fp_camera_fov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fp_camera_fov           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_camera_fov);

// f32 tp_cr_camera_look_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_x);

// f32 tp_cr_camera_look_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y);

// f32 tp_cr_camera_look_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_z);

// f32 tp_cr_camera_position_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_position_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_x);

// f32 tp_cr_camera_position_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_position_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_y);

// f32 tp_cr_camera_position_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_position_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_position_offset_z);

// f32 tp_pr_camera_look_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_look_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_x);

// f32 tp_pr_camera_look_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_look_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_y);

// f32 tp_pr_camera_look_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_look_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_look_offset_z);

// f32 tp_pr_camera_position_offset_x
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_position_offset_x\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_x);

// f32 tp_pr_camera_position_offset_y
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_position_offset_y\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_y);

// f32 tp_pr_camera_position_offset_z
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_position_offset_z\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_position_offset_z);

// f32 tp_cr_extra_lead_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_a);

// f32 tp_cr_extra_lead_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_from_pitch_b);

// f32 tp_cr_extra_lead_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_a);

// f32 tp_cr_extra_lead_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_lead_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_lead_pitch_b);

// f32 tp_cr_extra_height_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_a);

// f32 tp_cr_extra_height_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_from_pitch_b);

// f32 tp_cr_extra_height_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_a);

// f32 tp_cr_extra_height_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_height_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_height_pitch_b);

// f32 tp_pr_extra_lead_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_a);

// f32 tp_pr_extra_lead_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_from_pitch_b);

// f32 tp_pr_extra_lead_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_a);

// f32 tp_pr_extra_lead_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_lead_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_lead_pitch_b);

// f32 tp_pr_extra_height_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_a);

// f32 tp_pr_extra_height_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_from_pitch_b);

// f32 tp_pr_extra_height_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_a);

// f32 tp_pr_extra_height_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_extra_height_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_extra_height_pitch_b);

// f32 tp_camera_distance
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_distance      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_distance);

// f32 tp_cr_camera_distance
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_distance   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_distance);

// f32 tp_pr_camera_distance
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_distance   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_distance);

// f32 tp_cr_camera_fov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_fov);

// f32 tp_pr_camera_fov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_pr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_pr_camera_fov);

// f32 fp_cr_camera_fov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fp_cr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_cr_camera_fov);

// f32 fp_pr_camera_fov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fp_pr_camera_fov        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].fp_pr_camera_fov);

// b8 force_fp_scope
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- force_fp_scope          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].force_fp_scope);

// u32 aim_assist_config
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- aim_assist_config       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].aim_assist_config);

// b8 allow_depth_adjustment
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- allow_depth_adjustment  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].allow_depth_adjustment);

// f32 tp_extra_draw_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_draw_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_a);

// f32 tp_extra_draw_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_draw_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_from_pitch_b);

// f32 tp_extra_draw_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_draw_pitch_a   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_a);

// f32 tp_extra_draw_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_extra_draw_pitch_b   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_extra_draw_pitch_b);

// f32 tp_cr_extra_draw_from_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_from_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_a);

// f32 tp_cr_extra_draw_from_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_from_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_from_pitch_b);

// f32 tp_cr_extra_draw_pitch_a
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_pitch_a\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_a);

// f32 tp_cr_extra_draw_pitch_b
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_extra_draw_pitch_b\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_extra_draw_pitch_b);

// f32 tp_camera_pos_offset_y_mov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_pos_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_pos_offset_y_mov);

// f32 tp_camera_look_offset_y_mov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_camera_look_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_camera_look_offset_y_mov);

// f32 tp_cr_camera_pos_offset_y_mov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_pos_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_pos_offset_y_mov);

// f32 tp_cr_camera_look_offset_y_mov
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- tp_cr_camera_look_offset_y_mov\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_cr_camera_look_offset_y_mov);

// b8 tp_allow_move_heights
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- tp_allow_move_heights   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_defs[fire_mode_defs_iter].tp_allow_move_heights);

} // fire_mode_defs

// list player_state_group_defs
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count);
for (u32 player_state_group_defs_iter = 0; player_state_group_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs_count; player_state_group_defs_iter++)
{
// u32 id7
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id7                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].id7);

// u32 _id8
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- _id8                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter]._id8);

// list player_state_properties
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count);
for (u32 player_state_properties_iter = 0; player_state_properties_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties_count; player_state_properties_iter++)
{
// u32 group_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- group_id                \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].group_id);

// u32 id9
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id9                     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].id9);

// u8 flags3
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flags3                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].flags3);

// f32 min_cof
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_cof                 \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cof);

// f32 max_cof
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_cof                 \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cof);

// f32 cof_recovery_rate
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_recovery_rate       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_rate);

// f32 cof_turn_penalty
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_turn_penalty        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_turn_penalty);

// u32 shots_before_cof_penalty
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- shots_before_cof_penalty\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cof_penalty);

// f32 cof_recovery_delay_threshold
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_recovery_delay_threshold\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_threshold);

// u32 cof_recovery_delay_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- cof_recovery_delay_ms   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_recovery_delay_ms);

// f32 cof_grow_rate
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cof_grow_rate           \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cof_grow_rate);

// f32 min_cyl_of_fire
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_cyl_of_fire         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].min_cyl_of_fire);

// f32 max_cyl_of_fire
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_cyl_of_fire         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].max_cyl_of_fire);

// f32 cylof_recovery_rate
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_recovery_rate     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_rate);

// f32 cylof_turn_penalty
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_turn_penalty      \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_turn_penalty);

// u32 shots_before_cylof_penalty
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- shots_before_cylof_penalty\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].shots_before_cylof_penalty);

// f32 cylof_recovery_delay_threshold
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_recovery_delay_threshold\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_threshold);

// u32 cylof_recovery_delay_ms
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- cylof_recovery_delay_ms \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_recovery_delay_ms);

// f32 cylof_grow_rate
packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cylof_grow_rate         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].player_state_group_defs[player_state_group_defs_iter].player_state_properties[player_state_properties_iter].cylof_grow_rate);

} // player_state_properties

} // player_state_group_defs

// list fire_mode_projectile_mapping_data
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count);
for (u32 fire_mode_projectile_mapping_data_iter = 0; fire_mode_projectile_mapping_data_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data_count; fire_mode_projectile_mapping_data_iter++)
{
// u32 id10
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id10                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id10);

// u32 id11
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id11                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].id11);

// u32 index
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- index                   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].index);

// u32 projectile_definition_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- projectile_definition_id\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].fire_mode_projectile_mapping_data[fire_mode_projectile_mapping_data_iter].projectile_definition_id);

} // fire_mode_projectile_mapping_data

// list aim_assist_defs
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs = memory_arena_push_length(arena, packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count * sizeof(packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[0]));
printf("-- LIST_COUNT              \t%d\n", packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count);
for (u32 aim_assist_defs_iter = 0; aim_assist_defs_iter < packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs_count; aim_assist_defs_iter++)
{
// u32 id12
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id12                    \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].id12);

// f32 cone_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cone_angle              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_angle);

// f32 cone_range
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cone_range              \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].cone_range);

// f32 fall_off_cone_range
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- fall_off_cone_range     \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].fall_off_cone_range);

// f32 magnet_cone_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- magnet_cone_angle       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_angle);

// f32 magnet_cone_range
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- magnet_cone_range       \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_cone_range);

// f32 target_override_delay
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- target_override_delay   \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_override_delay);

// f32 target_oos_delay
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- target_oos_delay        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_oos_delay);

// f32 arrive_time
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- arrive_time             \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].arrive_time);

// f32 target_motion_update_time
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- target_motion_update_time\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].target_motion_update_time);

// f32 weight
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- weight                  \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].weight);

// f32 min_input_weight_delay_in
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_input_weight_delay_in\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_in);

// f32 max_input_weight_delay_in
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_input_weight_delay_in\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_in);

// f32 min_input_weight_delay_out
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_input_weight_delay_out\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_weight_delay_out);

// f32 max_input_weight_delay_out
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_input_weight_delay_out\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_weight_delay_out);

// f32 min_input_actor
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_input_actor         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_actor);

// f32 max_input_actor
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_input_actor         \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_actor);

// u32 requirement_id
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- requirement_id          \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].requirement_id);

// f32 magnet_min_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- magnet_min_angle        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_min_angle);

// f32 magnet_dist_for_min_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- magnet_dist_for_min_angle\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_min_angle);

// f32 magnet_max_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- magnet_max_angle        \t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_max_angle);

// f32 magnet_dist_for_max_angle
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- magnet_dist_for_max_angle\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].magnet_dist_for_max_angle);

// f32 min_input_strafe_arrive_time
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- min_input_strafe_arrive_time\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].min_input_strafe_arrive_time);

// f32 max_input_strafe_arrive_time
packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- max_input_strafe_arrive_time\t%lld\t%llxh\t%f\n", (i64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time, (u64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time, (f64)packet->weapon_byteswithlength[weapon_byteswithlength_iter].aim_assist_defs[aim_assist_defs_iter].max_input_strafe_arrive_time);

} // aim_assist_defs

} // weapon_byteswithlength

} break;

case Zone_Packet_Kind_GameTimeSync:
{
printf("[*] Unpacking GameTimeSync...\n");
Zone_Packet_GameTimeSync* packet = packet_ptr;

// u64 time
packet->time = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- time                    \t%lld\t%llxh\t%f\n", (i64)packet->time, (u64)packet->time, (f64)packet->time);

// f32 cycle_speed
packet->cycle_speed = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- cycle_speed             \t%lld\t%llxh\t%f\n", (i64)packet->cycle_speed, (u64)packet->cycle_speed, (f64)packet->cycle_speed);

// b8 unk_bool
packet->unk_bool = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

} break;

case Zone_Packet_Kind_SetLocale:
{
printf("[*] Unpacking SetLocale...\n");
Zone_Packet_SetLocale* packet = packet_ptr;

// string locale
packet->locale_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->locale = memory_arena_push_length(arena, packet->locale_length);
printf("-- STRING_LENGTH           \t%d\n", packet->locale_length);
for (u32 locale_iter = 0; locale_iter < packet->locale_length; locale_iter++)
{
packet->locale[locale_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} break;

case Zone_Packet_Kind_KeepAlive:
{
printf("[*] Unpacking KeepAlive...\n");
Zone_Packet_KeepAlive* packet = packet_ptr;

// u32 game_time
packet->game_time = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- game_time               \t%lld\t%llxh\t%f\n", (i64)packet->game_time, (u64)packet->game_time, (f64)packet->game_time);

} break;

case Zone_Packet_Kind_ClientLog:
{
printf("[*] Unpacking ClientLog...\n");
Zone_Packet_ClientLog* packet = packet_ptr;

// string file
packet->file_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->file = memory_arena_push_length(arena, packet->file_length);
printf("-- STRING_LENGTH           \t%d\n", packet->file_length);
for (u32 file_iter = 0; file_iter < packet->file_length; file_iter++)
{
packet->file[file_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string message
packet->message_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->message = memory_arena_push_length(arena, packet->message_length);
printf("-- STRING_LENGTH           \t%d\n", packet->message_length);
for (u32 message_iter = 0; message_iter < packet->message_length; message_iter++)
{
packet->message[message_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} break;

case Zone_Packet_Kind_ClientGameSettings:
{
printf("[*] Unpacking ClientGameSettings...\n");
Zone_Packet_ClientGameSettings* packet = packet_ptr;

// u32 unk_u32
packet->unk_u32 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// u32 interact_glow_and_dist
packet->interact_glow_and_dist = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- interact_glow_and_dist  \t%lld\t%llxh\t%f\n", (i64)packet->interact_glow_and_dist, (u64)packet->interact_glow_and_dist, (f64)packet->interact_glow_and_dist);

// u8 unk_bool
packet->unk_bool = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unk_bool                \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool, (u64)packet->unk_bool, (f64)packet->unk_bool);

// f32 timescale
packet->timescale = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- timescale               \t%lld\t%llxh\t%f\n", (i64)packet->timescale, (u64)packet->timescale, (f64)packet->timescale);

// u32 enable_weapons
packet->enable_weapons = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- enable_weapons          \t%lld\t%llxh\t%f\n", (i64)packet->enable_weapons, (u64)packet->enable_weapons, (f64)packet->enable_weapons);

// u32 unk_u32_2
packet->unk_u32_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_2, (u64)packet->unk_u32_2, (f64)packet->unk_u32_2);

// f32 unk_float1
packet->unk_float1 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unk_float1              \t%lld\t%llxh\t%f\n", (i64)packet->unk_float1, (u64)packet->unk_float1, (f64)packet->unk_float1);

// f32 unk_float2
packet->unk_float2 = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- unk_float2              \t%lld\t%llxh\t%f\n", (i64)packet->unk_float2, (u64)packet->unk_float2, (f64)packet->unk_float2);

// f32 damage_multiplier
packet->damage_multiplier = endian_read_f32_little(data + offset);
offset += sizeof(f32);
printf("-- damage_multiplier       \t%lld\t%llxh\t%f\n", (i64)packet->damage_multiplier, (u64)packet->damage_multiplier, (f64)packet->damage_multiplier);

} break;

case Zone_Packet_Kind_InitializationParameters:
{
printf("[*] Unpacking InitializationParameters...\n");
Zone_Packet_InitializationParameters* packet = packet_ptr;

// string environment
packet->environment_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->environment = memory_arena_push_length(arena, packet->environment_length);
printf("-- STRING_LENGTH           \t%d\n", packet->environment_length);
for (u32 environment_iter = 0; environment_iter < packet->environment_length; environment_iter++)
{
packet->environment[environment_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unk_string_1
packet->unk_string_1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->unk_string_1 = memory_arena_push_length(arena, packet->unk_string_1_length);
printf("-- STRING_LENGTH           \t%d\n", packet->unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->unk_string_1_length; unk_string_1_iter++)
{
packet->unk_string_1[unk_string_1_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// list ruleset_definitions
packet->ruleset_definitions_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->ruleset_definitions = memory_arena_push_length(arena, packet->ruleset_definitions_count * sizeof(packet->ruleset_definitions[0]));
printf("-- LIST_COUNT              \t%d\n", packet->ruleset_definitions_count);
for (u32 ruleset_definitions_iter = 0; ruleset_definitions_iter < packet->ruleset_definitions_count; ruleset_definitions_iter++)
{
// u32 unk_u32_1
packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_1               \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1, (u64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1, (f64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_1);

// u32 unk_u32_2
packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_2               \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2, (u64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2, (f64)packet->ruleset_definitions[ruleset_definitions_iter].unk_u32_2);

// string ruleset
packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->ruleset_definitions[ruleset_definitions_iter].ruleset = memory_arena_push_length(arena, packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length);
printf("-- STRING_LENGTH           \t%d\n", packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length);
for (u32 ruleset_iter = 0; ruleset_iter < packet->ruleset_definitions[ruleset_definitions_iter].ruleset_length; ruleset_iter++)
{
packet->ruleset_definitions[ruleset_definitions_iter].ruleset[ruleset_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unk_string_2
packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2 = memory_arena_push_length(arena, packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length);
for (u32 unk_string_2_iter = 0; unk_string_2_iter < packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2_length; unk_string_2_iter++)
{
packet->ruleset_definitions[ruleset_definitions_iter].unk_string_2[unk_string_2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// list rulesets
packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->ruleset_definitions[ruleset_definitions_iter].rulesets = memory_arena_push_length(arena, packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count * sizeof(packet->ruleset_definitions[ruleset_definitions_iter].rulesets[0]));
printf("-- LIST_COUNT              \t%d\n", packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count);
for (u32 rulesets_iter = 0; rulesets_iter < packet->ruleset_definitions[ruleset_definitions_iter].rulesets_count; rulesets_iter++)
{
// u32 ID
packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ID                      \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ID);

// u32 data_id
packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- data_id                 \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].data_id);

// u32 ruleset_id
packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ruleset_id              \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].ruleset_id);

// u32 content_pack_id
packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- content_pack_id         \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_id);

// u32 content_pack_action_id
packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- content_pack_action_id  \t%lld\t%llxh\t%f\n", (i64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id, (u64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id, (f64)packet->ruleset_definitions[ruleset_definitions_iter].rulesets[rulesets_iter].content_pack_action_id);

} // rulesets

} // ruleset_definitions

} break;

case Zone_Packet_Kind_ClientInitializationDetails:
{
printf("[*] Unpacking ClientInitializationDetails...\n");
Zone_Packet_ClientInitializationDetails* packet = packet_ptr;

// u32 unk_u32_1
packet->unk_u32_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32_1               \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32_1, (u64)packet->unk_u32_1, (f64)packet->unk_u32_1);

} break;

case Zone_Packet_Kind_Synchronization:
{
printf("[*] Unpacking Synchronization...\n");
Zone_Packet_Synchronization* packet = packet_ptr;

// u64 client_hours_ms
packet->client_hours_ms = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- client_hours_ms         \t%lld\t%llxh\t%f\n", (i64)packet->client_hours_ms, (u64)packet->client_hours_ms, (f64)packet->client_hours_ms);

// u64 client_hours_ms2
packet->client_hours_ms2 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- client_hours_ms2        \t%lld\t%llxh\t%f\n", (i64)packet->client_hours_ms2, (u64)packet->client_hours_ms2, (f64)packet->client_hours_ms2);

// u64 client_time
packet->client_time = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- client_time             \t%lld\t%llxh\t%f\n", (i64)packet->client_time, (u64)packet->client_time, (f64)packet->client_time);

// u64 server_time
packet->server_time = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- server_time             \t%lld\t%llxh\t%f\n", (i64)packet->server_time, (u64)packet->server_time, (f64)packet->server_time);

// u64 unk_time
packet->unk_time = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- unk_time                \t%lld\t%llxh\t%f\n", (i64)packet->unk_time, (u64)packet->unk_time, (f64)packet->unk_time);

} break;

case Zone_Packet_Kind_PlayerUpdateManagedPosition:
{
printf("[*] Unpacking PlayerUpdateManagedPosition...\n");
Zone_Packet_PlayerUpdateManagedPosition* packet = packet_ptr;

// uint2b transient_id
packet->transient_id = endian_read_uint2b_little(data + offset);
offset += packet->transient_id.length;
printf("-- transient_id            \t%lld\t%llxh\n", (i64)packet->transient_id.value, (u64)packet->transient_id.value);

} break;

case Zone_Packet_Kind_EquipmentSetCharacterEquipment:
{
printf("[*] Unpacking EquipmentSetCharacterEquipment...\n");
Zone_Packet_EquipmentSetCharacterEquipment* packet = packet_ptr;

// u32 profile_id
packet->profile_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- profile_id              \t%lld\t%llxh\t%f\n", (i64)packet->profile_id, (u64)packet->profile_id, (f64)packet->profile_id);

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 unk_dword_1
packet->unk_dword_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->unk_dword_1, (u64)packet->unk_dword_1, (f64)packet->unk_dword_1);

// string unk_string_1
packet->unk_string_1_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->unk_string_1 = memory_arena_push_length(arena, packet->unk_string_1_length);
printf("-- STRING_LENGTH           \t%d\n", packet->unk_string_1_length);
for (u32 unk_string_1_iter = 0; unk_string_1_iter < packet->unk_string_1_length; unk_string_1_iter++)
{
packet->unk_string_1[unk_string_1_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unk_string_2
packet->unk_string_2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->unk_string_2 = memory_arena_push_length(arena, packet->unk_string_2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->unk_string_2_length);
for (u32 unk_string_2_iter = 0; unk_string_2_iter < packet->unk_string_2_length; unk_string_2_iter++)
{
packet->unk_string_2[unk_string_2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// list equipment_slot_array
packet->equipment_slot_array_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->equipment_slot_array = memory_arena_push_length(arena, packet->equipment_slot_array_count * sizeof(packet->equipment_slot_array[0]));
printf("-- LIST_COUNT              \t%d\n", packet->equipment_slot_array_count);
for (u32 equipment_slot_array_iter = 0; equipment_slot_array_iter < packet->equipment_slot_array_count; equipment_slot_array_iter++)
{
// u32 equipment_slot_id_1
packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- equipment_slot_id_1     \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1, (u64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1, (f64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_1);

// u32 equipment_slot_id_2
packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- equipment_slot_id_2     \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2, (u64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2, (f64)packet->equipment_slot_array[equipment_slot_array_iter].equipment_slot_id_2);

// u64 guid
packet->equipment_slot_array[equipment_slot_array_iter].guid = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- guid                    \t%lld\t%llxh\t%f\n", (i64)packet->equipment_slot_array[equipment_slot_array_iter].guid, (u64)packet->equipment_slot_array[equipment_slot_array_iter].guid, (f64)packet->equipment_slot_array[equipment_slot_array_iter].guid);

// string tint_alias
packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->equipment_slot_array[equipment_slot_array_iter].tint_alias = memory_arena_push_length(arena, packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->equipment_slot_array[equipment_slot_array_iter].tint_alias_length; tint_alias_iter++)
{
packet->equipment_slot_array[equipment_slot_array_iter].tint_alias[tint_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string decal_alias
packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->equipment_slot_array[equipment_slot_array_iter].decal_alias = memory_arena_push_length(arena, packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length);
for (u32 decal_alias_iter = 0; decal_alias_iter < packet->equipment_slot_array[equipment_slot_array_iter].decal_alias_length; decal_alias_iter++)
{
packet->equipment_slot_array[equipment_slot_array_iter].decal_alias[decal_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} // equipment_slot_array

// list attachments_data_1
packet->attachments_data_1_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->attachments_data_1 = memory_arena_push_length(arena, packet->attachments_data_1_count * sizeof(packet->attachments_data_1[0]));
printf("-- LIST_COUNT              \t%d\n", packet->attachments_data_1_count);
for (u32 attachments_data_1_iter = 0; attachments_data_1_iter < packet->attachments_data_1_count; attachments_data_1_iter++)
{
// string model_name
packet->attachments_data_1[attachments_data_1_iter].model_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->attachments_data_1[attachments_data_1_iter].model_name = memory_arena_push_length(arena, packet->attachments_data_1[attachments_data_1_iter].model_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->attachments_data_1[attachments_data_1_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->attachments_data_1[attachments_data_1_iter].model_name_length; model_name_iter++)
{
packet->attachments_data_1[attachments_data_1_iter].model_name[model_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string texture_alias
packet->attachments_data_1[attachments_data_1_iter].texture_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->attachments_data_1[attachments_data_1_iter].texture_alias = memory_arena_push_length(arena, packet->attachments_data_1[attachments_data_1_iter].texture_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->attachments_data_1[attachments_data_1_iter].texture_alias_length);
for (u32 texture_alias_iter = 0; texture_alias_iter < packet->attachments_data_1[attachments_data_1_iter].texture_alias_length; texture_alias_iter++)
{
packet->attachments_data_1[attachments_data_1_iter].texture_alias[texture_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string tint_alias
packet->attachments_data_1[attachments_data_1_iter].tint_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->attachments_data_1[attachments_data_1_iter].tint_alias = memory_arena_push_length(arena, packet->attachments_data_1[attachments_data_1_iter].tint_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->attachments_data_1[attachments_data_1_iter].tint_alias_length);
for (u32 tint_alias_iter = 0; tint_alias_iter < packet->attachments_data_1[attachments_data_1_iter].tint_alias_length; tint_alias_iter++)
{
packet->attachments_data_1[attachments_data_1_iter].tint_alias[tint_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string decal_alias
packet->attachments_data_1[attachments_data_1_iter].decal_alias_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->attachments_data_1[attachments_data_1_iter].decal_alias = memory_arena_push_length(arena, packet->attachments_data_1[attachments_data_1_iter].decal_alias_length);
printf("-- STRING_LENGTH           \t%d\n", packet->attachments_data_1[attachments_data_1_iter].decal_alias_length);
for (u32 decal_alias_iter = 0; decal_alias_iter < packet->attachments_data_1[attachments_data_1_iter].decal_alias_length; decal_alias_iter++)
{
packet->attachments_data_1[attachments_data_1_iter].decal_alias[decal_alias_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 unk_dword_1
packet->attachments_data_1[attachments_data_1_iter].unk_dword_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_1             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_1, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_1, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_1);

// u32 unk_dword_2
packet->attachments_data_1[attachments_data_1_iter].unk_dword_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_2             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_2, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_2, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_2);

// u32 effect_id
packet->attachments_data_1[attachments_data_1_iter].effect_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- effect_id               \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].effect_id, (u64)packet->attachments_data_1[attachments_data_1_iter].effect_id, (f64)packet->attachments_data_1[attachments_data_1_iter].effect_id);

// u32 slot_id
packet->attachments_data_1[attachments_data_1_iter].slot_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- slot_id                 \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].slot_id, (u64)packet->attachments_data_1[attachments_data_1_iter].slot_id, (f64)packet->attachments_data_1[attachments_data_1_iter].slot_id);

// u32 unk_dword_3
packet->attachments_data_1[attachments_data_1_iter].unk_dword_3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_3             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_3, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_3, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_dword_3);

// list unk_array_1337
packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->attachments_data_1[attachments_data_1_iter].unk_array_1337 = memory_arena_push_length(arena, packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count * sizeof(packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[0]));
printf("-- LIST_COUNT              \t%d\n", packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count);
for (u32 unk_array_1337_iter = 0; unk_array_1337_iter < packet->attachments_data_1[attachments_data_1_iter].unk_array_1337_count; unk_array_1337_iter++)
{
// u32 unk_dword_4
packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_dword_4             \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_array_1337[unk_array_1337_iter].unk_dword_4);

} // unk_array_1337

// b8 unk_bool_1
packet->attachments_data_1[attachments_data_1_iter].unk_bool_1 = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- unk_bool_1              \t%lld\t%llxh\t%f\n", (i64)packet->attachments_data_1[attachments_data_1_iter].unk_bool_1, (u64)packet->attachments_data_1[attachments_data_1_iter].unk_bool_1, (f64)packet->attachments_data_1[attachments_data_1_iter].unk_bool_1);

} // attachments_data_1

// b8 unk_bool_2
packet->unk_bool_2 = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- unk_bool_2              \t%lld\t%llxh\t%f\n", (i64)packet->unk_bool_2, (u64)packet->unk_bool_2, (f64)packet->unk_bool_2);

} break;

case Zone_Packet_Kind_WallOfData_UIEvent:
{
printf("[*] Unpacking WallOfData_UIEvent...\n");
Zone_Packet_WallOfData_UIEvent* packet = packet_ptr;

// string object
packet->object_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->object = memory_arena_push_length(arena, packet->object_length);
printf("-- STRING_LENGTH           \t%d\n", packet->object_length);
for (u32 object_iter = 0; object_iter < packet->object_length; object_iter++)
{
packet->object[object_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string function
packet->function_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->function = memory_arena_push_length(arena, packet->function_length);
printf("-- STRING_LENGTH           \t%d\n", packet->function_length);
for (u32 function_iter = 0; function_iter < packet->function_length; function_iter++)
{
packet->function[function_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string argument
packet->argument_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->argument = memory_arena_push_length(arena, packet->argument_length);
printf("-- STRING_LENGTH           \t%d\n", packet->argument_length);
for (u32 argument_iter = 0; argument_iter < packet->argument_length; argument_iter++)
{
packet->argument[argument_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} break;

case Zone_Packet_Kind_WallOfData_ClientSystemInfo:
{
printf("[*] Unpacking WallOfData_ClientSystemInfo...\n");
Zone_Packet_WallOfData_ClientSystemInfo* packet = packet_ptr;

// string info
packet->info_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->info = memory_arena_push_length(arena, packet->info_length);
printf("-- STRING_LENGTH           \t%d\n", packet->info_length);
for (u32 info_iter = 0; info_iter < packet->info_length; info_iter++)
{
packet->info[info_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} break;

case Zone_Packet_Kind_WallOfData_ClientTransition:
{
printf("[*] Unpacking WallOfData_ClientTransition...\n");
Zone_Packet_WallOfData_ClientTransition* packet = packet_ptr;

// u32 old_state
packet->old_state = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- old_state               \t%lld\t%llxh\t%f\n", (i64)packet->old_state, (u64)packet->old_state, (f64)packet->old_state);

// u32 new_state
packet->new_state = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- new_state               \t%lld\t%llxh\t%f\n", (i64)packet->new_state, (u64)packet->new_state, (f64)packet->new_state);

// u32 ms_elapsed
packet->ms_elapsed = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ms_elapsed              \t%lld\t%llxh\t%f\n", (i64)packet->ms_elapsed, (u64)packet->ms_elapsed, (f64)packet->ms_elapsed);

} break;

default:
{
printf("[!] Unpacking %s not implemented\n", zone_packet_names[packet_kind]);
}
}
}
