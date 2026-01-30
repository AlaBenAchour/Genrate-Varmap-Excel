#ifndef VENTILATION_H    /* Guard against multiple inclusion */
#define VENTILATION_H

#define APPLICATION_VERSION                         14.0103

#define TERMINAR									1	//

#define false										0	//
#define true										1	//

#if TERMINAR
	#define CONS_CHOIX_REF_PLUS_FROIDE				0	//
	#define CONS_CHOIX_REF_PLUS_CHAUDE				1	//
	#define CONS_CHOIX_REF_MOYENNE					2 	//

#else
	#define CONS_CHOIX_REF_PLUS_FROIDE				-2	//
	#define CONS_CHOIX_REF_PLUS_CHAUDE				-1	//
	#define CONS_CHOIX_REF_MOYENNE					0 	//
#endif

#define BORNE_TOL_TEMP_TAS_HAUTE					30. 	// (en éC)
#define BORNE_TOL_TEMP_TAS_BASSE					-10.	// (en éC)
#define BORNE_TOL_TEMP_PAS_TAS_HAUTE				40. 	// (en éC)
#define BORNE_TOL_TEMP_PAS_TAS_BASSE				-20.	// (en éC)
#define TOLERANCE_MELANGE_D_AIR						0.5 	// (en éC)
#define DELTA_T_CSGN								0.2 	// (en éC)
#define DUREE_TPS_MORT_VNTLTN						15 		// (en minutes)
#define DUREE_TPS_MORT_FROID						30 		// (en minutes)
#define DUREE_ACCEPTION_PERTE_COND					180 	// (en secondes)
#define BORNE_MIN_HYGRO                             15. 	
#define BORNE_MAX_HYGRO             	            100. 

#define ADD_BASE_FLASH_ZONE_1						40000
#define ADD_BASE_FLASH_ZONE_2						40366


#define ETAT_ARRET_VNTLTN							0
#define ETAT_MARCHE_VNTLTN							1
#define ETAT_VENTIL_G1_VNTLTN						2
#define ETAT_VENTIL_G2_VNTLTN						3
#define ETAT_VENTIL_TOUS_VNTLTN						4
#define ETAT_RECYC_VNTLTN							5
#define ETAT_FERMETURE_TRAPPE_VNTLTN				6

#define ETAT_ARRET_FROID							0
#define ETAT_MARCHE_FROID							1
#define ETAT_RECYC_G1_FROID							2
#define ETAT_RECYC_G2_FROID							3
#define ETAT_RECYC_TOUS_FROID						4
#define ETAT_RECYC_FROID							5
#define ETAT_DEGIVRAGE_FROID						6
#define ETAT_FROID_ENCOURS							7

#define ETAT_ARRET_CHAUD							0
#define ETAT_MARCHE_CHAUD							1
#define ETAT_RECYC_G1_CHAUD							2
#define ETAT_RECYC_G2_CHAUD							3
#define ETAT_RECYC_TOUS_CHAUD						4
#define ETAT_RECYC_CHAUD							5
#define ETAT_CHAUD_ENCOURS							6

#define ARRET_FRD_AUCUN								0   
#define ARRET_FRD_ECART_MAX_TAS_JOUR				1
#define ARRET_FRD_EJP								2
#define ARRET_FRD_THERMOSTA_GEL						3
#define ARRET_FRD_PLAGE_HORAIRE						4
#define ARRET_FRD_DMD_CYCLE_VNTLTN					5
#define ARRET_FRD_DMD_CYCLE_DEGAZ					6
#define ARRET_FRD_DMD_CYCLE_RECYC					7
#define ARRET_FRD_T_FINALE_ATTEINTE					8
#define ARRET_FRD_AUTORISATION_CYCLE_DESAC			9
#define ARRET_FRD_T_MIN_GAINE						10
#define ARRET_FRD_CYCLE_DEGIVRAGE					11


#define ARRET_VNT_AUCUN								0
#define ARRET_VNT_TRAPPE_ENTREE_AIR_FERMEE			1
#define ARRET_VNT_TRAPPE_SORTIE_AIR_FERMEE			2
#define ARRET_VNT_ECART_MAX_TAS_JOUR				3
#define ARRET_VNT_EJP								4
#define ARRET_VNT_THERMOSTA_GEL						5
#define ARRET_VNT_PLAGE_HORAIRE						6								   
#define ARRET_VNT_T_FINALE_ATTEINTE					7
#define ARRET_VNT_AUTORISATION_CYCLE_DESAC			8
#define ARRET_VNT_T_MIN_GAINE						9
#define ARRET_VNT_T_MIN_EXT							10														
#define ARRET_VNT_ECART_TAS_EXT_INSUFFUSANT			11							  
#define ARRET_VNT_HYGRO_TROP_BASSE					12									 									
#define ARRET_VNT_MELANGE_AIR_TROP_CHAUD			13						   
#define ARRET_VNT_MELANGE_AIR_TROP_FROID			14


#define ARRET_CHD_AUCUN								0   
#define ARRET_CHD_ECART_MAX_TAS_JOUR				1
#define ARRET_CHD_EJP								2
#define ARRET_CHD_THERMOSTA_GEL						3
#define ARRET_CHD_PLAGE_HORAIRE						4
#define ARRET_CHD_DMD_CYCLE_VNTLTN					5
#define ARRET_CHD_DMD_CYCLE_DEGAZ					6
#define ARRET_CHD_DMD_CYCLE_RECYC					7
#define ARRET_CHD_T_FINALE_ATTEINTE					8
#define ARRET_CHD_AUTORISATION_CYCLE_DESAC			9
#define ARRET_CHD_T_MIN_GAINE						10

#define FRD_AUCUN									0
#define FRD_DMR_FROID								1
#define FRD_VENT_COULOIRE							2
#define FRD_DMR_DEGIVRAGE							3
#define FRD_FIN_DEGIVRAGE							4
#define FRD_ALARME_FROID							5
#define FRD_ALARME_VNTLN							6
#define FRD_ALARME_SONDES_HS						7
#define FRD_ALARME_TAS_CSGN							8

#define CHD_AUCUN									0
#define CHD_DMR_CHAUD								1
#define CHD_VENT_COULOIRE							2
#define CHD_ALARME_ENTREE_DEFAUT_CHAUD				3

#define VNTLN_AUCUN									0
#define VNTLN_VNTLN_EXT								1
#define VNTLN_DMR_DEGAZ								2
#define VNTLN_FIN_DEGAZ								3
#define VNTLN_DMR_RECYC								4
#define VNTLN_FIN_RECYC								5
#define VNTLN_DMR_AEROTH							6
#define VNTLN_FIN_AEROTH							7
#define VNTLN_FIN_AEROTH_T_EXT_TROP_CHAUD			8

#define MAE_INACTIF_VNTLTN							0
#define MAE_DEMARREE_CYCLE_VNTLTN					1
#define MAE_DEMARRE_MELANGE_AIR_VNTLTN				2
#define MAE_DEMARRE_VENTILATEUR_VNTLTN				3
#define MAE_PERTE_COND_VNTLTN						4
#define MAE_RECYCLAGE_VNTLTN						5
#define MAE_DEMARRE_VENTILATEUR_RECYCLAGE_VNTLTN	6
#define MAE_PRE_ARRET_CYCLE_VNTLTN					7
#define MAE_ARRET_CYCLE_VNTLTN						8

#define MAE_INACTIF_FROID							0
#define MAE_DEMARREE_CYCLE_FROID					1
#define MAE_DMR_S2_AMBIANCE_FROID					2
#define MAE_DEMARRE_VENTILATEUR_FROID				3
#define MAE_ARRET_S2_AMBIANCE_FROID					4
#define MAE_DEMARRE_RECYCLAGE_FROID					5
#define MAE_ATT_ARRET_RECYCLAGE_FROID				6
#define MAE_PRE_ARRET_CYCLE_FROID					7
#define MAE_ARRET_CYCLE_FROID						8
#define MAE_PAUSE_FROID								9

#define MAE_INACTIF_CHAUD							0
#define MAE_DEMARREE_CYCLE_CHAUD					1
#define MAE_DMR_S2_AMBIANCE_CHAUD					2
#define MAE_DEMARRE_VENTILATEUR_CHAUD				3
#define MAE_ARRET_S2_AMBIANCE_CHAUD					4
#define MAE_DEMARRE_RECYCLAGE_CHAUD					5
#define MAE_ATT_ARRET_RECYCLAGE_CHAUD				6
#define MAE_PRE_ARRET_CYCLE_CHAUD					7
#define MAE_ARRET_CYCLE_CHAUD						8

#define MAE_INACTIF_DEGIVRAGE						0
#define MAE_DEMARREE_CYCLE_DEGIVRAGE				1
#define MAE_TEMPS_EGOUTTE_DEGIVRAGE					2
#define MAE_ARRET_CYCLE_DEGIVRAGE					3
#define MAE_TEMP_MORT_DEGIVRAGE						4

#define MAE_INACTIF_DEGAZ							0
#define MAE_DEMARREE_CYCLE_DEGAZ					1
#define MAE_OUVR_TRAPPE_DEGAZ						2
#define MAE_DEMARRE_VENTILATEUR_DEGAZ				3
#define MAE_PERTE_COND_CYCLE_DEGAZ					4
#define MAE_PRE_ARRET_CYCLE_DEGAZ					5
#define MAE_ARRET_CYCLE_DEGAZ						6

#define MAE_INACTIF_RECYC							0
#define MAE_DEMARREE_CYCLE_RECYC					1
#define MAE_DEMARRE_VENTILATEUR_RECYC				2
#define MAE_PRE_ARRET_CYCLE_RECYC					3
#define MAE_ARRET_CYCLE_RECYC						4

#define MAE_INACTIF_AEROTH							0
#define MAE_DEMARREE_CYCLE_AEROTH					1
#define MAE_ARRET_CYCLE_AEROTH						2
#define MAE_TEMPS_OFF_AEROTH						3

#define JAF_AUCUN									0
#define JAF_COND_ECART_MAX_TAS_JOUR_VNTL			1
#define JAF_ENTREE_EJP								2
#define JAF_ENTREE_TH_GEL							3
#define JAF_AUTORISER_PLAGE_FROID					4
#define JAF_COND_VNTLTN_FAVO_VNTL					5
#define JAF_COND_RECYC_FAVO_VNTL					6
#define JAF_COND_CSGN_TAS_VENTILATION				7
#define JAF_AUTORISATION_FROID_VNTL					8
#define JAF_COND_TEMP_MINI_GAINE					9
#define JAF_DEGIVRAGE_ENCOURS						10
#define JAF_SEUIL_MIN_SONDE_TAS						11

#define JAC_AUCUN									0
#define JAC_COND_ECART_MAX_TAS_JOUR_VNTL			1
#define JAC_ENTREE_EJP								2
#define JAC_ENTREE_TH_GEL							3
#define JAC_AUTORISER_PLAGE_CHAUD					4
#define JAC_COND_VNTLTN_FAVO_VNTL					5
#define JAC_COND_RECYC_FAVO_VNTL					6
#define JAC_COND_CSGN_TAS_VENTILATION				7
#define JAC_AUTORISATION_CHAUD_VNTL					8
#define JAC_COND_TEMP_MINI_GAINE					9
#define JAC_SEUIL_MIN_SONDE_TAS						10

#define JAV_AUCUN									0
#define JAV_ENTREE_TRAPPE_AIR_FERME					1
#define JAV_ENTREE_SORTIE_AIR_FERME					2
#define JAV_COND_ECART_MAX_TAS_JOUR_VNTL			3
#define JAV_ENTREE_EJP								4
#define JAV_ENTREE_TH_GEL							5
#define JAV_AUTORISER_PLAGE_VENTIL					6
#define JAV_COND_CSGN_TAS_VENTILATION				7
#define JAV_AUTORISATION_VNTLTN_VNTL				8
#define JAV_COND_TEMP_MINI_GAINE					9
#define JAV_COND_T_EXT_DESSUS_MINI_VNTL				10
#define JAV_COND_T_EXT_DESSOUS_TAS_VNTL				11
#define JAV_AU_DESSUS_SEUIL_HYGROMETRIE				12
#define JAV_COND_MELANGE_TROP_CHAUD_VNTL			13
#define JAV_COND_MELANGE_TROP_FROID_VNTL			14
#define JAV_SEUIL_MIN_SONDE_TAS						15
#define JAV_AU_DESSUS_TD			             	16

#define GROUPE_VENTILO_1							0
#define GROUPE_VENTILO_2							1
#define GROUPE_VENTILO_1_2							2
#define GROUPE_VENTILO_TOUS							3

#define MODE_TOR									0
#define MODE_ANA									1

#define TYPE_TRAPPE_TOR								0
#define TYPE_TRAPPE_ANA								1

#define PWM_FERMETURE_TOTALE						0
#define PWM_OUVERTURE_TOTALE						4000

#define ACT_DEF_ENT_TOR_CHOIX_1						0
#define ACT_DEF_ENT_TOR_CHOIX_2						1

#define DG_AIR										0
#define DG_RESISTANCE								1
#define DG_EAU_CHAUDE								2

#define NBR_ALL_SONDES								12
#define NBR_VAR_HISTO								12
#define SONDE_AMBIANCE								0
#define NBR_FV										230  //180
#define NBR_FV2										3
#define NBR_FNV										50
#define NBR_FV3										5						   
#define NBR_FNV2									15
#define NBR_FNV3									6
#define NBR_FNV4									3
#define NBR_RV										110 //60
#define NBR_RNV										150//100
#define NBR_RNV2									110
#define NBR_TMR										60
#define NBR_CASE									8
#define NBR_PLAGE_HORAIRE							4
#define NBR_SONDE									6
#define NBR_VENTILO									12
//#define NBR_RV2										20


// Flags Volatiles Ventilation
#define FV_MANU_GROUPE_FROID						 1024
#define FV_AUTO_GROUPE_FROID						 1025
#define FV_AUCUNE_SND_TAS_VALIDE_VNTL(NumCase)		(1026 + ((NumCase) * NBR_FV))
#define FV_TOUTES_SONDES_TAS_OK_VNTL(NumCase)		(1027 + ((NumCase) * NBR_FV))
#define FV_COND_CSGN_TAS_VENTILATION(NumCase)		(1028 + ((NumCase) * NBR_FV))
#define FV_COND_T_EXT_DESSUS_MINI_VNTL(NumCase)		(1029 + ((NumCase) * NBR_FV))
#define FV_COND_T_EXT_DESSOUS_TAS_VNTL(NumCase)		(1030 + ((NumCase) * NBR_FV))
#define FV_COND_TOLERENCE_DEGAZ_VNTL(NumCase)		(1031 + ((NumCase) * NBR_FV))
#define FV_COND_HDP_VNTLTN_VNTL(NumCase)			(1032 + ((NumCase) * NBR_FV))
#define FV_COND_HDP_FROID_VNTL(NumCase)				(1033 + ((NumCase) * NBR_FV))
#define FV_TPS_MORT_VNTLTN_VNTL(NumCase)			(1034 + ((NumCase) * NBR_FV))
#define FV_TPS_MORT_FROID_VNTL(NumCase)				(1035 + ((NumCase) * NBR_FV))
#define FV_COND_VNTLTN_TEMPORISE_VNTL(NumCase)		(1036 + ((NumCase) * NBR_FV))
#define FV_COND_FROID_TEMPORISE_VNTL(NumCase)		(1037 + ((NumCase) * NBR_FV))
#define FV_COND_DEGAZ_TEMPORISE_VNTL(NumCase)		(1038 + ((NumCase) * NBR_FV))
#define FV_COND_VNTLTN_NORMALE_VNTL(NumCase)		(1039 + ((NumCase) * NBR_FV))
#define FV_COND_FROID_NORMALE_VNTL(NumCase)			(1040 + ((NumCase) * NBR_FV))
#define FV_COND_RECYC_NORMALE_VNTL(NumCase)			(1041 + ((NumCase) * NBR_FV))
#define FV_COND_DEGAZ_NORMALE_VNTL(NumCase)			(1042 + ((NumCase) * NBR_FV))
#define FV_COND_VNTLTN_SPECIF_VNTL(NumCase)			(1043 + ((NumCase) * NBR_FV))
#define FV_COND_FROID_SPECIF_VNTL(NumCase)			(1044 + ((NumCase) * NBR_FV))
#define FV_COND_RECYC_SPECIF_VNTL(NumCase)			(1045 + ((NumCase) * NBR_FV))
#define FV_COND_DEGAZ_SPECIF_VNTL(NumCase)			(1046 + ((NumCase) * NBR_FV))
#define FV_COND_VNTLTN_FAVO_VNTL(NumCase)			(1047 + ((NumCase) * NBR_FV))
#define FV_COND_FROID_FAVO_VNTL(NumCase)			(1048 + ((NumCase) * NBR_FV))
#define FV_COND_RECYC_FAVO_VNTL(NumCase)			(1049 + ((NumCase) * NBR_FV))
#define FV_COND_DEGAZ_FAVO_VNTL(NumCase)			(1050 + ((NumCase) * NBR_FV))
#define FV_COND_VNTLTN_AUTORISE_VNTL(NumCase)		(1051 + ((NumCase) * NBR_FV))
#define FV_COND_FROID_AUTORISE_VNTL(NumCase)		(1052 + ((NumCase) * NBR_FV))
#define FV_COND_RECYC_AUTORISE_VNTL(NumCase)		(1053 + ((NumCase) * NBR_FV))
#define FV_COND_DEGAZ_AUTORISE_VNTL(NumCase)		(1054 + ((NumCase) * NBR_FV))
#define FV_CYCLE_VNTLTN_ENCOURS_VNTL(NumCase)		(1055 + ((NumCase) * NBR_FV))
#define FV_CYCLE_FROID_ENCOURS_VNTL(NumCase)		(1056 + ((NumCase) * NBR_FV))
#define FV_CYCLE_RECYC_ENCOURS_VNTL(NumCase)		(1057 + ((NumCase) * NBR_FV))
#define FV_CYCLE_DEGAZ_ENCOURS_VNTL(NumCase)		(1058 + ((NumCase) * NBR_FV))
#define FV_COND_TPS_SNS_VNTL_DEGZ_VNTL(NumCase)		(1059 + ((NumCase) * NBR_FV))
#define FV_COND_TPS_SNS_VNTL_RCYC_VNTL(NumCase)		(1060 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_VNTLTN_VNTL(NumCase)			(1061 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_FROID_VNTL(NumCase)			(1062 + ((NumCase) * NBR_FV))
#define FV_MELANGE_AIR_VNTL(NumCase)				(1063 + ((NumCase) * NBR_FV))
#define FV_COND_MELANGE_TROP_CHAUD_VNTL(NumCase)	(1064 + ((NumCase) * NBR_FV))
#define FV_COND_MELANGE_TROP_FROID_VNTL(NumCase)	(1065 + ((NumCase) * NBR_FV))
#define FV_RAZ_CPTR_VNTL(NumCase)					(1066 + ((NumCase) * NBR_FV))
#define FV_INACTIF_VNTLTN_VNTL(NumCase)				(1067 + ((NumCase) * NBR_FV))
#define FV_DEMARRE_CYCLE_VNTLTN_VNTL(NumCase)		(1068 + ((NumCase) * NBR_FV))
#define FV_DEMARRE_MELANGE_AIR_VNTL(NumCase)		(1069 + ((NumCase) * NBR_FV))
#define FV_PERTE_COND_VNTLTN_VNTL(NumCase)			(1070 + ((NumCase) * NBR_FV))
#define FV_ARRET_CYCLE_VNTLTN_VNTL(NumCase)			(1071 + ((NumCase) * NBR_FV))
#define FV_INACTIF_FROID_VNTL(NumCase)				(1072 + ((NumCase) * NBR_FV))
#define FV_DEMARREE_CYCLE_FROID_VNTL(NumCase)		(1073 + ((NumCase) * NBR_FV))
#define FV_ARRET_CYCLE_FROID_VNTL(NumCase)			(1074 + ((NumCase) * NBR_FV))
#define FV_INACTIF_DEGAZ_VNTL(NumCase)				(1075 + ((NumCase) * NBR_FV))
#define FV_DEMARREE_CYCLE_DEGAZ_VNTL(NumCase)		(1076 + ((NumCase) * NBR_FV))
#define FV_PERTE_COND_CYCLE_DEGAZ_VNTL(NumCase)		(1077 + ((NumCase) * NBR_FV))
#define FV_ARRET_CYCLE_DEGAZ_VNTL(NumCase)			(1078 + ((NumCase) * NBR_FV))
#define FV_INACTIF_RECYC_VNTL(NumCase)				(1079 + ((NumCase) * NBR_FV))
#define FV_DEMARREE_CYCLE_RECYC_VNTL(NumCase)		(1080 + ((NumCase) * NBR_FV))
#define FV_ARRET_CYCLE_RECYC_VNTL(NumCase)			(1081 + ((NumCase) * NBR_FV))
#define FV_TEMP_EXT_INVALIDE_VNTL(NumCase)			(1082 + ((NumCase) * NBR_FV))
#define FV_TEMP_GAINE_INVALIDE_VNTL(NumCase)		(1083 + ((NumCase) * NBR_FV))
#define FV_COND_RECYC_TEMPORISE_VNTL(NumCase)		(1084 + ((NumCase) * NBR_FV))
#define FV_DEFAULT_CONFIG_VNTL(NumCase)				(1085 + ((NumCase) * NBR_FV))
#define FV_OUVRE_TRAPPE_DEGAZ_VNTL(NumCase)			(1086 + ((NumCase) * NBR_FV))
#define FV_COND_ECART_MAX_TAS_JOUR_VNTL(NumCase)	(1087 + ((NumCase) * NBR_FV))
#define FV_AUTO_VENTILO_VENTILATION(Num, NumCase)  ((1088 + Num) + ((NumCase) * NBR_FV))
#define FV_AUTO_ELECTROVANNE(Num, NumCase)		   ((1100 + Num) + ((NumCase) * NBR_FV))
#define FV_AUTO_EVAPORATEUR(Num, NumCase)		   ((1102 + Num) + ((NumCase) * NBR_FV))
#define FV_AUTO_OUVR_ENTREE_AIR(NumCase)			(1104 + ((NumCase) * NBR_FV))
#define FV_AUTO_FERM_ENTREE_AIR(NumCase)			(1105 + ((NumCase) * NBR_FV))
#define FV_AUTO_TURBINE_OUVR_SORTIE_AIR(NumCase)	(1106 + ((NumCase) * NBR_FV))
#define FV_ENTREE_EJP(NumCase)						(1107 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_EXT_VENTIL(NumCase)			(1108 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_EXT_FROID(NumCase)				(1109 + ((NumCase) * NBR_FV))
#define FV_ENTREE_TRAPPE_AIR_FERME(NumCase)			(1110 + ((NumCase) * NBR_FV))
#define FV_ENTREE_SORTIE_AIR_OUVR(NumCase)			(1111 + ((NumCase) * NBR_FV))
#define FV_COND_T_GAINE_DESSUS_TAS_VNTL(NumCase)	(1112 + ((NumCase) * NBR_FV))
#define FV_CYLE_MARCHE(NumCase)						(1113 + ((NumCase) * NBR_FV))
#define FV_AUTO_VENTILO_FROID(Num, NumCase)		   ((1114 + Num) + ((NumCase) * NBR_FV))
#define FV_AUTO_VENTILO_RECYCLAGE(Num, NumCase)	   ((1126 + Num) + ((NumCase) * NBR_FV))
#define FV_AUTO_VENTILO_DEGAZAGE(Num, NumCase)	   ((1138 + Num) + ((NumCase) * NBR_FV))
#define FV_TPS_MORT_DEGAZAGE_VNTL(NumCase)		    (1150 + ((NumCase) * NBR_FV))
#define FV_FERM_SORTIE_AIR(NumCase)					(1151 + ((NumCase) * NBR_FV))
#define FV_UTILISATION_SORTIE_AIR(NumCase)			(1152 + ((NumCase) * NBR_FV))
#define FV_UTILISATION_PRIORITE_VENTIL(NumCase)		(1153 + ((NumCase) * NBR_FV))
#define FV_UTILISATION_PRIORITE_FROID(NumCase)		(1154 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PRIORITE_VENTIL(NumCase)		(1155 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PRIORITE_FROID(NumCase)		(1156 + ((NumCase) * NBR_FV))
#define FV_AU_DESSUS_SEUIL_HYGROMETRIE(NumCase)		(1157 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_DEGAZ_VNTL(NumCase)			(1158 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_RECYC_VNTL(NumCase)			(1159 + ((NumCase) * NBR_FV))
#define FV_DEFAUT_CASE(NumCase)						(1160 + ((NumCase) * NBR_FV))
#define FV_ETAT_SORTIE_AIR(NumCase)					(1161 + ((NumCase) * NBR_FV))
#define FV_DEFAUT_VENTILATEUR(NumCase)				(1162 + ((NumCase) * NBR_FV))
#define FV_DEFAUT_GROUPE(NumCase)					(1163 + ((NumCase) * NBR_FV))
#define FV_DEFAUT_SORTIE_AIR(NumCase)				(1164 + ((NumCase) * NBR_FV))
#define FV_DEFAUT_ENTREE_AIR(NumCase)				(1165 + ((NumCase) * NBR_FV))
#define FV_ALARME_DEFAUT_VENTILATEUR(NumCase)		(1166 + ((NumCase) * NBR_FV))
#define FV_ALARME_DEFAUT_GROUPE(NumCase)			(1167 + ((NumCase) * NBR_FV))
#define FV_ALARME_DEFAUT_SORTIE_AIR(NumCase)		(1168 + ((NumCase) * NBR_FV))
#define FV_ALARME_DEFAUT_ENTREE_AIR(NumCase)		(1169 + ((NumCase) * NBR_FV))
#define FV_ALARME_ABSCENCE_RECYCLAGE(NumCase)		(1170 + ((NumCase) * NBR_FV))
#define FV_ALARME_SONDE_HORS_SERVICE(NumCase)		(1171 + ((NumCase) * NBR_FV))
#define FV_ALARME_SEUIL_MAX_SONDE_TAS(NumCase)		(1172 + ((NumCase) * NBR_FV))
#define FV_ALARME_SEUIL_SONDE_GAINE(NumCase)		(1173 + ((NumCase) * NBR_FV))
#define FV_ALARME_SEUIL_SONDE_AMBIANCE(NumCase)		(1174 + ((NumCase) * NBR_FV))
#define FV_SORTIE_ALARME_CASE(NumCase)				(1175 + ((NumCase) * NBR_FV))
#define FV_COND_AEROTHERME_TEMPORISE(NumCase)		(1176 + ((NumCase) * NBR_FV))
#define FV_COND_AEROTHERME_NORMALE(NumCase)			(1177 + ((NumCase) * NBR_FV))
#define FV_COND_AEROTHERME_SPECIF(NumCase)			(1178 + ((NumCase) * NBR_FV))
#define FV_COND_AEROTHERME_FAVO(NumCase)			(1179 + ((NumCase) * NBR_FV))
#define FV_COND_AEROTHERME_AUTORISE(NumCase)		(1180 + ((NumCase) * NBR_FV))
#define FV_CYCLE_AEROTHERME_ENCOURS(NumCase)		(1181 + ((NumCase) * NBR_FV))
#define FV_TEMPS_OFF_AEROTHERME(NumCase)			(1182 + ((NumCase) * NBR_FV))
#define FV_COND_HDP_AEROTHERME(NumCase)				(1183 + ((NumCase) * NBR_FV))
#define FV_SORTIE_AEROTHERME(NumCase)				(1184 + ((NumCase) * NBR_FV))
#define FV_COND_T_EXT_DESSOUS_TAS_AEROTH(NumCase)	(1185 + ((NumCase) * NBR_FV))
#define FV_COND_ECART_TAS_EXT_AEROTH(NumCase)		(1186 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_AEROTHERME(NumCase)			(1187 + ((NumCase) * NBR_FV))
#define FV_SMS_ALARME_CASE(NumCase)					(1188 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PLAGE_VENTIL(NumCase)			(1189 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PLAGE_FROID(NumCase)			(1190 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PLAGE_DEGAZ(NumCase)			(1191 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PLAGE_RECYC(NumCase)			(1192 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PLAGE_AEROTH(NumCase)			(1193 + ((NumCase) * NBR_FV))
#define FV_PLAGE_ENCOURS(Num, NumCase)			   ((1194 + Num) + ((NumCase) * NBR_FV))
#define FV_ENTREE_TH_GEL(NumCase)					(1198 + ((NumCase) * NBR_FV))
#define FV_COND_TEMP_MINI_GAINE(NumCase)			(1199 + ((NumCase) * NBR_FV))
#define FV_SORTIE_BRUMISATION(NumCase)				(1200 + ((NumCase) * NBR_FV))
#define FV_COND_CSGN_TAS_FROID(NumCase)				(1201 + ((NumCase) * NBR_FV))
#define FV_SORTIE_RESISTANCE_DEGIVRAGE(NumCase)		(1202 + ((NumCase) * NBR_FV))
#define FV_ACTIVATION_VENTILATION(NumCase)			(1203 + ((NumCase) * NBR_FV))
#define FV_ACTIVATION_FROID(NumCase)				(1204 + ((NumCase) * NBR_FV))
#define FV_DEGIVRAGE_ENCOURS(NumCase)				(1205 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_VENTILATION_G1(NumCase)		(1206 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_VENTILATION_G2(NumCase)		(1207 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_OUVR_ENTREE_AIR(NumCase)	(1208 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_FERM_ENTREE_AIR(NumCase)	(1209 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_TURBINE_OUVR_SORTIE_AIR(NumCase)    (1210 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_FERM_SORTIE_AIR(NumCase)	(1211 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_ELECTROVANNE(NumCase)		(1212 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_EVAPORATEUR(NumCase)		(1213 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_BRUMISATION(NumCase)		(1214 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_AEROTHERME(NumCase)			(1215 + ((NumCase) * NBR_FV))
#define FV_VISU_ARRET_THG_TF(NumCase)     			(1216 + ((NumCase) * NBR_FV))
#define FV_DEFAUT_BRUMISATION(NumCase)				(1217 + ((NumCase) * NBR_FV))
#define FV_ALARME_DEFAUT_BRUMISATION(NumCase)		(1218 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_BRUMISATION(NumCase)			(1219 + ((NumCase) * NBR_FV))
#define FV_DMD_FROID(NumCase)						(1220 + ((NumCase) * NBR_FV))
#define FV_DMD_DEGIVRAGE(NumCase)					(1221 + ((NumCase) * NBR_FV))
#define FV_DEGIVRAGE_EAU_CHAUDE(NumCase)			(1222 + ((NumCase) * NBR_FV))
#define FV_ALARME_SEUIL_MIN_SONDE_TAS(NumCase)		(1223 + ((NumCase) * NBR_FV))
#define FV_EVAP_FORCEE(NumCase)    					(1224 + ((NumCase) * NBR_FV))
#define FV_EVAP_FORCEE_ENCOURS(NumCase)    			(1225 + ((NumCase) * NBR_FV))
#define FV_ENTREE_CO2(NumCase)						(1226 + ((NumCase) * NBR_FV))
#define FV_SORTIE_CHAUD(NumCase)				    (1227 + ((NumCase) * NBR_FV))
#define FV_COND_ENTREE_CO2(NumCase)					(1228 + ((NumCase) * NBR_FV))
#define FV_CYCLE_CHAUD_ENCOURS_VNTL(NumCase)		(1229 + ((NumCase) * NBR_FV))
#define FV_CPTR_HORO_CHAUD_VNTL(NumCase)			(1230 + ((NumCase) * NBR_FV))
#define FV_INACTIF_CHAUD_VNTL(NumCase)              (1231 + ((NumCase) * NBR_FV))
#define FV_DEMARREE_CYCLE_CHAUD_VNTL(NumCase)		(1232 + ((NumCase) * NBR_FV))
#define FV_ARRET_CYCLE_CHAUD_VNTL(NumCase)			(1233 + ((NumCase) * NBR_FV))
#define FV_DMD_CHAUD(NumCase)						(1234 + ((NumCase) * NBR_FV))
#define FV_COND_CHAUD_AUTORISE_VNTL(NumCase)		(1235 + ((NumCase) * NBR_FV))
#define FV_TREF_AU_DESSUS_TD(NumCase)		        (1236 + ((NumCase) * NBR_FV))
#define FV_COND_AU_DESSUS_SEUIL_CO2(NumCase)		(1237 + ((NumCase) * NBR_FV))
#define FV_AUTORISER_PLAGE_CHAUD(NumCase)			(1238 + ((NumCase) * NBR_FV))
#define FV_TPS_MORT_CHAUD_VNTL(NumCase)		        (1239 + ((NumCase) * NBR_FV))
#define FV_COND_CSGN_TAS_CHAUD(NumCase)		        (1240 + ((NumCase) * NBR_FV))
#define FV_COND_CHAUD_TEMPORISE_VNTL(NumCase)		(1241 + ((NumCase) * NBR_FV))
#define FV_COND_CHAUD_NORMALE_VNTL(NumCase)		    (1242 + ((NumCase) * NBR_FV))
#define FV_COND_CHAUD_SPECIF_VNTL(NumCase)		    (1243 + ((NumCase) * NBR_FV))
#define FV_COND_CHAUD_FAVO_VNTL(NumCase)		    (1244 + ((NumCase) * NBR_FV))
#define FV_IMAGE_SORTIE_CHAUD(NumCase)			    (1245 + ((NumCase) * NBR_FV))
#define FV_COND_AUTORISER_EXT_VENTIL(NumCase)		(1246 + ((NumCase) * NBR_FV))
#define FV_COND_AUTORISER_EXT_FROID(NumCase)		(1247 + ((NumCase) * NBR_FV))
#define FV_ENTREE_DEFAUT_CHAUD(NumCase)	        	(1248 + ((NumCase) * NBR_FV))
#define FV_ALARME_ENTREE_DEFAUT_CHAUD(NumCase)		(1249 + ((NumCase) * NBR_FV))

#define FV_DG_E_ALARME_ECART(NumCase)               (1250 + ((NumCase) * NBR_FV))
#define FV_FERMETURE_TRAPPE_APRES_RESET(NumCase)    (1251 + ((NumCase) * NBR_FV))

///////////////// 
#define FV_RAZ_HISTO								 2866
#define FV_OUVR_SORTIE_AIR_COMMUNE					 2867
#define FV_FERM_SORTIE_AIR_COMMUNE					 2868
#define FV_IMAGE_OUVR_SORTIE_AIR_COMMUNE			 2869
#define FV_IMAGE_FERM_SORTIE_AIR_COMMUNE			 2870
#define FV_ETAT_SORTIE_AIR_COMMUNE					 2871
#define FV_ALARME_GENERALE							 2872
#define FV_ALARME_GENERALE_TEMPORAIRE				 2873
#define FV_INIT_CPT_ERREUR_SBUS						 2874
#define FV_INIT_CPT_ERREUR_STATION					 2875
//#define FV_ALARME_INIT_FLASH                         2876
#define FV_INIT_VAL_USINE                            2877


#define FV_SLV_ALARME_MANQUE_EAU_PF					 2924
#define FV_SLV_ALARME_DEFAUT_PPF_PF					 2925
#define FV_SLV_ALARME_ABSCENCE_DEBIT_PF				 2926
#define FV_SLV_ALARME_DEFAUT_CIRCUIT_PF				 2927
#define FV_SLV_ALARME_DEFAUT_ALIM_VANNE				 2928
#define FV_SLV_ALARME_DEFAUT_PPC_PC					 2929
#define FV_SLV_ALARME_ABSCENCE_DEBIT_PC				 2930
#define FV_SLV_ALARME_DEFAUT_PSF_CC					 2931
#define FV_SLV_ALARME_DEFAUT_PSC_CC					 2932
                                                     
#define FV_SLV_ALARME_DEFAUT_PSF(NumCase)			(2934 + ((NumCase) * NBR_FV2))
#define FV_SLV_ALARME_DEFAUT_PSC(NumCase)			(2935 + ((NumCase) * NBR_FV2))
#define FV_SLV_ALARME_DEFAUT_CDT_MAX(NumCase)		(2936 + ((NumCase) * NBR_FV2))

//Variable reserve pour l'afficheur
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C1                2958
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C2                2959
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C3                2960
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C4                2961
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C5                2962
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C6                2963
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C7                2964
#define FV_VISU_CPT_JOUR_OU_JOUR_1_C8                2965
//////////////

#define FV_AFFICHEUR_TRAPPE_EA_FERMEE(NumCase)    	(2966 + ((NumCase) * NBR_FV3))

// Prochaine adresse    2742 + ( 8 *5 ) = 2782

// Flags Non Volatiles Ventilation
#define FNV_ACTIVE_VNTL								21024
#define FNV_AUTORISATION_VNTLTN_VNTL(NumCase)		(21025 + ((NumCase) * NBR_FNV))
#define FNV_AUTORISATION_FROID_VNTL(NumCase)		(21026 + ((NumCase) * NBR_FNV))
#define FNV_AUTORISATION_DEGAZ_VNTL(NumCase)		(21027 + ((NumCase) * NBR_FNV))
#define FNV_AUTORISATION_RECYC_VNTL(NumCase)		(21028 + ((NumCase) * NBR_FNV))
#define FNV_DEGIVRAGE_SONDE_REF_VNTL(NumCase)		(21029 + ((NumCase) * NBR_FNV))
#define FNV_RAZ_TEMP_TAS_MINUIT_VNTL(NumCase)		(21030 + ((NumCase) * NBR_FNV))
#define FNV_ACTIVE_SMS_ALARME(NumCase)				(21031 + ((NumCase) * NBR_FNV))
#define FNV_ACTIVE_SORTIE_ALARME(NumCase)			(21032 + ((NumCase) * NBR_FNV))
#define FNV_AUTORISER_PLAGE_VENTIL(Num, NumCase)	((21033 + Num) + ((NumCase) * NBR_FNV))
#define FNV_AUTORISER_PLAGE_FROID(Num, NumCase)		((21037 + Num) + ((NumCase) * NBR_FNV))
#define FNV_AUTORISER_PLAGE_DEGAZ(Num, NumCase)		((21041 + Num) + ((NumCase) * NBR_FNV))
#define FNV_AUTORISER_PLAGE_RECYC(Num, NumCase)		((21045 + Num) + ((NumCase) * NBR_FNV))
#define FNV_AUTORISER_PLAGE_AEROTH(Num, NumCase)	((21049 + Num) + ((NumCase) * NBR_FNV))
#define FNV_AUTORISATION_AEROTHERME(NumCase)		(21053 + ((NumCase) * NBR_FNV))
#define FNV_AVEC_GLYCOLEE(NumCase)					(21054 + ((NumCase) * NBR_FNV))
#define FNV_ACTIVATION_VENTILATION(NumCase)			(21055 + ((NumCase) * NBR_FNV))
#define FNV_ACTIVATION_FROID(NumCase)				(21056 + ((NumCase) * NBR_FNV))
#define FNV_CHAUFFAGE_REFROIDISSEMENT(NumCase)		(21057 + ((NumCase) * NBR_FNV))
#define FNV_AUTORISATION_CHAUD_VNTL(NumCase)		(21058 + ((NumCase) * NBR_FNV))
#define FNV_AUTORISER_PLAGE_CHAUD(Num, NumCase)		((21059 + Num) + ((NumCase) * NBR_FNV))
//début adresse   50*8 + 21025=21425

#define FNV_ENTREE_DEFAUT_CHAUD(NumCase)            (21425 + ((NumCase) * NBR_FNV4)) //a verifier l'adresse


// Activation Esclave
//#define FNV_ACTIVE_SORTIE_ANA			30452
#define FNV_ACTIF_TOR_100_SANA						21500
#define FNV_ACTIF_TOR_101_SANA						21501
#define FNV_ACTIF_TOR_102_SANA						21502
#define FNV_ACTIF_TOR_103_SANA						21503
#define FNV_ACTIF_TOR_104_SANA						21504
#define FNV_ACTIF_TOR_105_SANA						21505
#define FNV_ACTIF_TOR_106_SANA						21506
#define FNV_ACTIF_TOR_107_SANA						21507

#define FNV_ACTIF_TEMPERATURE_100					21508
#define FNV_ACTIF_TEMPERATURE_101					21509
#define FNV_ACTIF_TEMPERATURE_102					21510
#define FNV_ACTIF_TEMPERATURE_103					21511
#define FNV_ACTIF_TEMPERATURE_104					21512
#define FNV_ACTIF_TEMPERATURE_105					21513
#define FNV_ACTIF_TEMPERATURE_106					21514
#define FNV_ACTIF_TEMPERATURE_107					21515
#define FNV_ACTIF_ANA_100							21516
#define FNV_ACTIF_ANA_101							21517
#define FNV_ACTIF_ANA_102							21518
#define FNV_ACTIF_ANA_103							21519
#define FNV_ACTIF_ANA_104							21520
#define FNV_ACTIF_ANA_105							21521
#define FNV_ACTIF_ANA_106							21522
#define FNV_ACTIF_ANA_107							21523
#define FNV_ACTIF_TOR_100_E							21524
#define FNV_ACTIF_TOR_101_E							21525
#define FNV_ACTIF_TOR_102_E							21526
#define FNV_ACTIF_TOR_103_E							21527
#define FNV_ACTIF_TOR_104_E							21528
#define FNV_ACTIF_TOR_105_E							21529
#define FNV_ACTIF_TOR_106_E							21530
#define FNV_ACTIF_TOR_107_E							21531
#define FNV_ACTIF_TOR_100_S							21532
#define FNV_ACTIF_TOR_101_S							21533
#define FNV_ACTIF_TOR_102_S							21534
#define FNV_ACTIF_TOR_103_S							21535
#define FNV_ACTIF_TOR_104_S							21536
#define FNV_ACTIF_TOR_105_S							21537
#define FNV_ACTIF_TOR_106_S							21538
#define FNV_ACTIF_TOR_107_S							21539
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C(Num)		(21540 + Num)
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C1			21540
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C2			21541
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C3			21542
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C4			21543
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C5			21544
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C6			21545
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C7			21546
#define FNV_ACTIVE_SORTIE_AIR_COMMUNE_C8			21547
#define FNV_PLUSIEURS_SONDES_GAINES					21548

// Entrées TOR
#define FNV_ENTREE_EJP(NumCase)						(21549 + ((NumCase) * NBR_FNV2))
#define FNV_AUTORISER_EXT_VENTIL(NumCase)			(21550 + ((NumCase) * NBR_FNV2))
#define FNV_AUTORISER_EXT_FROID(NumCase)			(21551 + ((NumCase) * NBR_FNV2))
#define FNV_ENTREE_TRAPPE_AIR_FERME(NumCase)		(21552 + ((NumCase) * NBR_FNV2))
#define FNV_ENTREE_SORTIE_AIR_OUVR(NumCase)			(21553 + ((NumCase) * NBR_FNV2))
#define FNV_UTILISATION_SORTIE_AIR(NumCase)			(21554 + ((NumCase) * NBR_FNV2))
#define FNV_UTILISATION_PRIO_VENTIL(NumCase)		(21555 + ((NumCase) * NBR_FNV2))
#define FNV_UTILISATION_PRIO_FROID(NumCase)			(21556 + ((NumCase) * NBR_FNV2))
#define FNV_DEFAUT_VENTILATEUR(NumCase)				(21557 + ((NumCase) * NBR_FNV2))
#define FNV_DEFAUT_GROUPE(NumCase)					(21558 + ((NumCase) * NBR_FNV2))
#define FNV_DEFAUT_SORTIE_AIR(NumCase)				(21559 + ((NumCase) * NBR_FNV2))
#define FNV_DEFAUT_ENTREE_AIR(NumCase)				(21560 + ((NumCase) * NBR_FNV2))
#define FNV_ENTREE_TH_GEL(NumCase)					(21561 + ((NumCase) * NBR_FNV2))
#define FNV_DEFAUT_BRUMISATION(NumCase)				(21562 + ((NumCase) * NBR_FNV2))
#define FNV_ENTREE_CO2(NumCase)						(21563 + ((NumCase) * NBR_FNV2))


#define FNV_SONDE_VISU_UNIQUEMENT(Num, NumCase)		((21669 + Num) + ((NumCase) * NBR_FNV3))

#define FNV_ACTIVATION_MTR_EAU_GLYCOLEE			    21717
#define FNV_ACTIF_EAU_GLYCOLEE_200					21718
#define FNV_ACTIF_EAU_GLYCOLEE_201					21719
#define FNV_ACTIF_EAU_GLYCOLEE_202					21720
#define FNV_ACTIF_EAU_GLYCOLEE_203					21721
#define FNV_ACTIF_EAU_GLYCOLEE_204					21722
#define FNV_ACTIF_EAU_GLYCOLEE_205					21723
#define FNV_ACTIF_EAU_GLYCOLEE_206					21724
#define FNV_ACTIF_EAU_GLYCOLEE_207					21725


// Registres Volatiles Ventilation
#define RV_CPTR_HORO_TOTAL_VNTLTN_VNTL(NumCase)		(1024+ ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_FROID_VNTL(NumCase)		(1025 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_EXT(NumCase)					(1026 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_GAINE(NumCase)				(1027 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_EVAP(NumCase)					(1028 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_HYGRO_EXT(NumCase)			(1029 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE(Num, NumCase)				   ((1030 + Num) + ((NumCase) * NBR_RV)) //6 au lieu de 14
#define RV_TEMP_SONDE_CO2(NumCase)                  (1036 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_HYGRO_INT(NumCase)            (1037 + ((NumCase) * NBR_RV))
#define RV_SONDE_PLUS_FROIDE(NumCase)				(1038 + ((NumCase) * NBR_RV))
#define RV_SONDE_PLUS_CHAUDE(NumCase)				(1039 + ((NumCase) * NBR_RV))
#define RV_SONDE_MOYENNE(NumCase)					(1040 + ((NumCase) * NBR_RV))
#define RV_SONDE_REF(NumCase)						(1041 + ((NumCase) * NBR_RV))
#define RV_CPTR_HOR_SNS_VNTL_DEGAZ_VNTL(NumCase)	(1042 + ((NumCase) * NBR_RV))
#define RV_CPTR_HOR_SNS_VNTL_RECYC_VNTL(NumCase)	(1043 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_VNTLTN_VNTL(NumCase)			(1044 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_FROID_VNTL(NumCase)			(1045 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_DEGAZ_VNTL(NumCase)			(1046 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_RECYC_VNTL(NumCase)			(1047 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_VNTLTN_VNTL(NumCase)			(1048 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_FROID_VNTL(NumCase)			(1049 + ((NumCase) * NBR_RV))
#define RV_TEMP_TAS_MINUT(NumCase)					(1050 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_DEGIVRAGE_VNTL(NumCase)		(1051 + ((NumCase) * NBR_RV))
#define RV_TPS_RESTANT_ALTERN_VENTILO_VNTL(NumCase)	(1052 + ((NumCase) * NBR_RV))
#define RV_GROUPE_VENTILO_VNTLTN_ENCOURS(NumCase)	(1053 + ((NumCase) * NBR_RV))
#define RV_GROUPE_VENTILO_VNTLTN_SAUVEGRD(NumCase)	(1054 + ((NumCase) * NBR_RV))
#define RV_TPS_RESTANT_ALTERN_VENTILO_FROID(NumCase)(1055 + ((NumCase) * NBR_RV))
#define RV_GROUPE_VENTILO_FROID_ENCOURS(NumCase)	(1056 + ((NumCase) * NBR_RV))
#define RV_GROUPE_VENTILO_FROID_SAUVEGRD(NumCase)	(1057 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_AMBIANCE(NumCase)				(1058 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_DEGAZ_VNTL(NumCase)		(1059 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_RECYC_VNTL(NumCase)		(1060 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_DEGAZ_VNTL(NumCase)			(1061 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_RECYC_VNTL(NumCase)			(1062 + ((NumCase) * NBR_RV))
#define RV_ETAT_VNTLTN_VNTL(NumCase)				(1063 + ((NumCase) * NBR_RV))
#define RV_ETAT_FROID_VNTL(NumCase)					(1064 + ((NumCase) * NBR_RV))
#define RV_TEMPS_RECYCL_VNTLTN(NumCase)				(1065 + ((NumCase) * NBR_RV))
#define RV_TEMPS_RECYCL_FROID(NumCase)				(1066 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_AEROTHERME(NumCase)		(1067 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_AEROTHERME(NumCase)			(1068 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_AEROTHERME(NumCase)			(1069 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_VNTLTN_PREC(NumCase)			(1070 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_FROID_PREC(NumCase)			(1071 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_DEGAZ_PREC(NumCase)			(1072 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_RECYC_PREC(NumCase)			(1073 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_AEROTHERME_PREC(NumCase)		(1074 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_FROID(NumCase)			(1075 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_DEGAZ(NumCase)			(1076 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_RECYC(NumCase)			(1077 + ((NumCase) * NBR_RV))
#define RV_OBJECTIF_A_ATTEINDRE_GAINE(NumCase)		(1078 + ((NumCase) * NBR_RV))
#define RV_TEMPS_FCT_AV_DEGIVRAGE(NumCase)			(1079 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_VENTILATION_FROID(NumCase)		(1080 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_VENTILATION_RECYC(NumCase)		(1081 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_VENTILATION_DEGAZ(NumCase)		(1082 + ((NumCase) * NBR_RV))
#define RV_TPS_AVT_PROCHAIN_DEGIVRAGE(NumCase)		(1083 + ((NumCase) * NBR_RV))
#define RV_NBR_FERM_TRAPPE_SUCC(NumCase)			(1084 + ((NumCase) * NBR_RV))
#define RV_DG_E_COMPTEUR(NumCase)                   (1085 + ((NumCase) * NBR_RV))
#define RV_JOURNAL_ARRET_FROID(NumCase)				(1086 + ((NumCase) * NBR_RV))
#define RV_JOURNAL_ARRET_VENTIL(NumCase)			(1087 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_DEGIVRAGE(NumCase)		(1088 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_BRUMISATION(NumCase)		(1089 + ((NumCase) * NBR_RV))
#define RV_TPS_AVT_PROCHAIN_DEGAZ(NumCase)			(1090 + ((NumCase) * NBR_RV))
#define RV_ETAT_CYCLE_FROID(NumCase)				(1091 + ((NumCase) * NBR_RV))
#define RV_ETAT_CYCLE_VNTLN(NumCase)				(1092 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_BRUMISATION(NumCase)			(1093 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_BRUMISATION_PREC(NumCase)	(1094 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_DEGIVRAGE(NumCase)			(1095 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_DEGIVRAGE_PREC(NumCase)		(1096 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_FROID_PREC(NumCase)	(1097 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_RECYC_PREC(NumCase)	(1098 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_DEGAZ_PREC(NumCase)	(1099 + ((NumCase) * NBR_RV))
#define RV_SORTIE_ANA_TRAPPE(NumCase)				(1100 + ((NumCase) * NBR_RV))
#define RV_POURCENTAGE_OUVR_E_TRAPPE_ANA(NumCase)	(1101 + ((NumCase) * NBR_RV))
#define RV_TEMP_TAS_MIN(NumCase)					(1102 + ((NumCase) * NBR_RV))
#define RV_TEMP_TAS_MAX(NumCase)					(1103 + ((NumCase) * NBR_RV))
#define RV_TEMP_EXT_MIN(NumCase)					(1104 + ((NumCase) * NBR_RV))
#define RV_TEMP_EXT_MAX(NumCase)					(1105 + ((NumCase) * NBR_RV))
#define RV_ETAT_CYCLE_CHAUD(NumCase)				(1106 + ((NumCase) * NBR_RV))
#define RV_ETAT_CHAUD_VNTL(NumCase)					(1107 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_CHAUD(NumCase)			(1108 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_VENTILATION_CHAUD(NumCase)		(1109 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_CHAUD_VNTL(NumCase)			(1110 + ((NumCase) * NBR_RV))
#define RV_CPTR_HORO_TOTAL_CHAUD_VNTL(NumCase)		(1111 + ((NumCase) * NBR_RV))
#define RV_JOURNAL_ARRET_CHAUD(NumCase)             (1112 + ((NumCase) * NBR_RV))
#define RV_MAE_CYCLE_CHAUD_VNTL(NumCase)			(1113 + ((NumCase) * NBR_RV))
#define RV_DUREE_CYCLE_CHAUD_PREC(NumCase)			(1114 + ((NumCase) * NBR_RV))
#define RV_DUREE_VENTILATION_CHAUD_PREC(NumCase)	(1115 + ((NumCase) * NBR_RV))
#define RV_TD(NumCase)                              (1116 + ((NumCase) * NBR_RV))
#define RV_TEMPS_RECYCL_CHAUD(NumCase)				(1117 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_CO2_MIN(NumCase)				(1118 + ((NumCase) * NBR_RV))
#define RV_TEMP_SONDE_CO2_MAX(NumCase)				(1119 + ((NumCase) * NBR_RV))
#define RV_TEMP_HYGRO_INT_MIN(NumCase)				(1120 + ((NumCase) * NBR_RV))
#define RV_TEMP_HYGRO_INT_MAX(NumCase)				(1121 + ((NumCase) * NBR_RV))

//début adresse   110*8 + 1024=1904

//#define RV_NUM_REG_SONDE_GAINE(NumCase)				(846 + ((NumCase) * 4))

#define RV_CPT_ERREUR_SBUS							 1904
// Compteur Erreur communication SBus avec toutes les stations esclaves
#define RV_CPTR_ERREUR								 1912

#define RV_MIN_TFINAL_CASES                          1913
#define RV_SORTIE_ANA_PUISSANCE_GROUPE      		 1914
//#define RV_JOURNAL_ARRET_FROID(NumCase)				(900 + ((NumCase) * NBR_RV2))
//#define RV_JOURNAL_ARRET_VENTIL(NumCase)			(901 + ((NumCase) * NBR_RV2))

// Registres Non Volatiles Ventilation
#define RNV_TEMP_FINALE_VNTL(NumCase)				(21024 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MINI_TAS_CSGN_VENTILATION(NumCase)(21025 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_MIN_EXT_VNTL(NumCase)				(21026 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MAXI_TAS_GAINE_VNTL(NumCase)		(21027 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MINI_TAS_EXT_VNTL(NumCase)		(21028 + ((NumCase) * NBR_RNV))
#define RNV_DEBUT_HDP_VNTL_VNTL(NumCase)			(21029 + ((NumCase) * NBR_RNV))
#define RNV_FIN_HDP_VNTL_VNTL(NumCase)				(21030 + ((NumCase) * NBR_RNV))
#define RNV_DEBUT_HDP_FROID_VNTL(NumCase)			(21031 + ((NumCase) * NBR_RNV))
#define RNV_FIN_HDP_FROID_VNTL(NumCase)				(21032 + ((NumCase) * NBR_RNV))
#define RNV_TPS_ACTN_OUVR_TRAPPE_AIR(NumCase)		(21033 + ((NumCase) * NBR_RNV))
#define RNV_TPS_ATTE_ENTRE_2_ACTN_VNTL(NumCase)		(21034 + ((NumCase) * NBR_RNV))
#define RNV_TPS_MAX_SNS_VNTL_DEGZ_VNTL(NumCase)		(21035 + ((NumCase) * NBR_RNV))
#define RNV_TPS_MAX_SNS_VNTL_RCYC_VNTL(NumCase)		(21036 + ((NumCase) * NBR_RNV))
#define RNV_TPS_RECYC_VNTL(NumCase)					(21037 + ((NumCase) * NBR_RNV))
#define RNV_TPS_DEGAZ_VNTL(NumCase)					(21038 + ((NumCase) * NBR_RNV))
#define RNV_TPS_OUVER_TRAPPE_DEGAZ_VNTL(NumCase)	(21039 + ((NumCase) * NBR_RNV))
#define RNV_TOL_DEGAZ_VNTL(NumCase)					(21040 + ((NumCase) * NBR_RNV))
#define RNV_NOMBRE_SONDE_VNTL(NumCase)				(21041 + ((NumCase) * NBR_RNV))
#define RNV_SONDE_REF_VNTL(NumCase)					(21042 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_VNTLTN_VNTL(NumCase)			(21043 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_FROID_VNTL(NumCase)			(21044 + ((NumCase) * NBR_RNV))
#define RNV_LIMITE_SONDE_MINI_VNTL(NumCase)			(21045 + ((NumCase) * NBR_RNV))
#define RNV_LIMITE_SONDE_MAXI_VNTL(NumCase)			(21046 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_TPS_MORT_VNTLTN_VNTL(NumCase)		(21047 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_TPS_MORT_FROID_VNTL(NumCase)		(21048 + ((NumCase) * NBR_RNV))
#define RNV_POINT_ACTN_OUVR_VNTL(NumCase)			(21049 + ((NumCase) * NBR_RNV))
#define RNV_DG_E_TEMPS_DIGIVRAGE(NumCase)                       (21150 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MAXI_TAS_AMBIANCE_VNTL(NumCase)	(21051 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MAXI_TAS_PAR_JOUR_VNTL(NumCase)	(21052 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_ENTRE_DMR_VENTILO_VNTL(NumCase)	(21053 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_MINI_SONDE_EVAP_VNTL(NumCase)		(21054 + ((NumCase) * NBR_RNV))
#define RNV_NBR_HEURE_FCT_FROID_VNTL(NumCase)		(21055 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_DEGIVRAGE_VNTL(NumCase)			(21056 + ((NumCase) * NBR_RNV))
#define RNV_TPS_FERM_TRAPPE_VNTL(NumCase)			(21057 + ((NumCase) * NBR_RNV))
#define RNV_TPS_ALTERNANCE_VENTILO_VNTL(NumCase)	(21058 + ((NumCase) * NBR_RNV))
#define RNV_TPS_ALTERNANCE_VENTILO_RCYC(NumCase)	(21059 + ((NumCase) * NBR_RNV))
#define RNV_TPS_ALTERNANCE_VENTILO_FROID(NumCase)	(21060 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_MIN_GAINE_VNTL(NumCase)			(21061 + ((NumCase) * NBR_RNV))
#define RNV_DG_E_NBR(NumCase)                                   (21162 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_HYGROMETRIE(NumCase)				(21063 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_DEGAZ_VNTL(NumCase)			(21064 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_RECYC_VNTL(NumCase)			(21065 + ((NumCase) * NBR_RNV))
#define RNV_POURCENT_CYCLE_VNTL(NumCase)			(21066 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_MIN_RECYC_VNTL(NumCase)			(21067 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_MAX_RECYC_VNTL(NumCase)			(21068 + ((NumCase) * NBR_RNV))
#define RNV_TPS_OUVERTURE_SORTIE_AIR_VNTL(NumCase)	(21069 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_DEFAUT_VENTILATEUR(NumCase)		(21070 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_DEFAUT_GROUPE(NumCase)			(21071 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_DEFAUT_SORTIE_AIR(NumCase)		(21072 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_DEFAUT_ENTREE_AIR(NumCase)		(21073 + ((NumCase) * NBR_RNV))
#define RNV_TPS_MAX_SNS_VENTILATION(NumCase)		(21074 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_SONDE_HORS_SERVICE(NumCase)		(21075 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_MAX_SONDE_TAS(NumCase)			(21076 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_SONDE_GAINE(NumCase)				(21077 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_SONDE_AMBIANCE(NumCase)			(21078 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_SEUIL_MAX_SONDE_TAS(NumCase)		(21079 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_SEUIL_SONDE_GAINE(NumCase)		(21080 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_SEUIL_SONDE_AMBIANCE(NumCase)	(21081 + ((NumCase) * NBR_RNV))
#define RNV_CHOIX_MODE_TOR_ANA(NumCase)				(21082 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_ENTRE_ACTION(NumCase)				(21083 + ((NumCase) * NBR_RNV))
#define RNV_TPS_ACTN_FERM_TRAPPE_AIR(NumCase)		(21084 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_MIN_SONDE_TAS(NumCase)			(21085 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_SEUIL_MIN_SONDE_TAS(NumCase)		(21086 + ((NumCase) * NBR_RNV))
#define RNV_HEURE_DEBUT_ALARME(NumCase)				(21087 + ((NumCase) * NBR_RNV))
#define RNV_HEURE_FIN_ALARME(NumCase)				(21088 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_ON_AEROTHERME(NumCase)			(21089 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_OFF_AEROTHERME(NumCase)			(21090 + ((NumCase) * NBR_RNV))
#define RNV_ECART_TAS_EXT_AEROTHERME(NumCase)		(21091 + ((NumCase) * NBR_RNV))
#define RNV_DEBUT_HDP_AEROTHERME(NumCase)			(21092 + ((NumCase) * NBR_RNV))
#define RNV_FIN_HDP_AEROTHERME(NumCase)				(21093 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_AEROTHERME(NumCase)			(21094 + ((NumCase) * NBR_RNV))
#define RNV_DEBUT_PLAGE(Num, NumCase)				((21095 + (Num * 2)) + ((NumCase) * NBR_RNV))
#define RNV_FIN_PLAGE(Num, NumCase)					((21096 + (Num * 2)) + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_MIN_FCT_FROID_ECOULE(NumCase)		(21103 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_MAXI_SANS_BRASSAGE(NumCase)		(21104 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_MAXI_BRASSAGE(NumCase)			(21105 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_MINI_BRASSAGE(NumCase)			(21106 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MAXI_TAS_GAINE_FROID(NumCase)		(21107 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_TEMP_MINI_GAINE(NumCase)			(21108 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_TAS_MINUT(NumCase)					(21109 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MINI_TAS_CSGN_FROID(NumCase)		(21110 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_BRUMISATION_ON(NumCase)			(21111 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_BRUMISATION_OFF(NumCase)			(21112 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_EGOUTTE_DEGIVRAGE(NumCase)		(21113 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_VNTLTN_VNTL(NumCase)		(21114 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_FROID_VNTL(NumCase)			(21115 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_DEGAZ_VNTL(NumCase)			(21116 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_RECYC_VNTL(NumCase)			(21117 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_AEROTHERME(NumCase)			(21118 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_VNTLTN_PREC(NumCase)		(21119 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_FROID_PREC(NumCase)			(21120 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_DEGAZ_PREC(NumCase)			(21121 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_RECYC_PREC(NumCase)			(21122 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_AEROTHERME_PREC(NumCase)	(21123 + ((NumCase) * NBR_RNV))
// Totalisateur
#define RNV_CPTR_HORO_VENTILATION_FROID(NumCase)	(21124 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_VENTILATION_RECYC(NumCase)	(21125 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_VENTILATION_DEGAZ(NumCase)	(21126 + ((NumCase) * NBR_RNV))
#define RNV_TEMPS_MINI_DEGIVRAGE_VNTL(NumCase)		(21127 + ((NumCase) * NBR_RNV))
#define RNV_CHOIX_SONDE_GAINE(NumCase)				(21128 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_DEFAUT_BRUMISATION(NumCase)		(21129 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_BRUMISATION(NumCase)		(21130 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_BRUMISATION_PREC(NumCase)	(21131 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_BRUMISATION(NumCase)			(21132 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_DEGIVRAGE(NumCase)			(21133 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_DEGIVRAGE(NumCase)			(21134 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_DEGIVRAGE_PREC(NumCase)		(21135 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_FROID(NumCase)		(21136 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_RECYC(NumCase)		(21137 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_DEGAZ(NumCase)		(21138 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_FROID_PREC(NumCase)	(21139 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_RECYC_PREC(NumCase)	(21140 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_DEGAZ_PREC(NumCase)	(21141 + ((NumCase) * NBR_RNV))
#define RNV_CHOIX_TYPE_TRAPPE_ANA_TOR(NumCase)		(21142 + ((NumCase) * NBR_RNV))
#define RNV_POINT_ACTN_FERM_VNTL(NumCase)			(21143 + ((NumCase) * NBR_RNV))
#define RNV_POINT_OUVER_TRAPPE_DEGAZ_VNTL(NumCase)	(21144 + ((NumCase) * NBR_RNV))
#define RNV_PWM_FERMETURE_TOTALE(NumCase)			(21145 + ((NumCase) * NBR_RNV))
#define RNV_PWM_OUVERTURE_TOTALE(NumCase)			(21146 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_BRUMISATION_FROID_ON(NumCase)		(21147 + ((NumCase) * NBR_RNV))
#define RNV_TEMP_BRUMISATION_FROID_OFF(NumCase)		(21148 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MIN_TAS_GAINE_EAU_GLYCOL(NumCase)	(21149 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MAX_TAS_GAINE_EAU_GLYCOL(NumCase)	(21150 + ((NumCase) * NBR_RNV))
#define RNV_CHOIX_DEGIVRAGE(NumCase)				(21151 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_CHAUD_VNTL(NumCase)			(21152 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_CHAUD(NumCase)		(21153 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_VENTILATION_CHAUD(NumCase)	(21154 + ((NumCase) * NBR_RNV))
#define RNV_CPTR_HORO_CHAUD_VNTL(NumCase)			(21155 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_CYCLE_CHAUD_PREC(NumCase)			(21156 + ((NumCase) * NBR_RNV))
#define RNV_DUREE_VENTILATION_CHAUD_PREC(NumCase)	(21157 + ((NumCase) * NBR_RNV))
#define RNV_SEUIL_CO2(NumCase)                  	(21158 + ((NumCase) * NBR_RNV))
#define RNV_ECART_MINI_TAS_CSGN_CHAUD(NumCase)		(21159 + ((NumCase) * NBR_RNV))
#define RNV_FILTRE_ENTREE_DEFAUT_CHAUD(NumCase)		(21160 + ((NumCase) * NBR_RNV))


#define RNV_DG_T_REF_1(NumCase)                                 (21161 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_2(NumCase)                                 (21162 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_3(NumCase)                                 (21163 + ((NumCase) * NBR_RNV))
 
#define RNV_DG_T_REF_TEMPS_DIGIVRAGE_1(NumCase)                 (21164 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_TEMPS_DIGIVRAGE_2(NumCase)                 (21165 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_TEMPS_DIGIVRAGE_3(NumCase)                 (21166 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_TEMPS_DIGIVRAGE_4(NumCase)                 (21167 + ((NumCase) * NBR_RNV))

#define RNV_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_1(NumCase)           (21168 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_2(NumCase)           (21169 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_3(NumCase)           (21170 + ((NumCase) * NBR_RNV))
#define RNV_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_4(NumCase)           (21171 + ((NumCase) * NBR_RNV))

#define RNV_DG_E_ECART_TAS_SOUFFLAGE(NumCase)                   (21172 + ((NumCase) * NBR_RNV))
#define RNV_DG_E_TEMPS_MIN_FCT_FROID_ECOULE(NumCase)            (21173 + ((NumCase) * NBR_RNV))




//début adresse   150*8 + 21024=22224
// Sorties TOR
#define RNV_VENTILO_VENTILATION_1(NumCase)			(22250 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_2(NumCase)			(22251 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_3(NumCase)			(22252 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_4(NumCase)			(22253 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_5(NumCase)			(22254 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_6(NumCase)			(22255 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_7(NumCase)			(22256 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_8(NumCase)			(22257 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_9(NumCase)			(22258 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_10(NumCase)			(22259 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_11(NumCase)			(22260 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_VENTILATION_12(NumCase)			(22261 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_1(NumCase)			    (22262 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_2(NumCase)			    (22263 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_3(NumCase)				(22264 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_4(NumCase)				(22265 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_5(NumCase)				(22266 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_6(NumCase)				(22267 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_7(NumCase)				(22268 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_8(NumCase)				(22269 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_9(NumCase)				(22270 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_10(NumCase)				(22271 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_11(NumCase)				(22272 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_FROID_12(NumCase)				(22273 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_1(NumCase)			(22274 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_2(NumCase)			(22275 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_3(NumCase)			(22276 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_4(NumCase)			(22277 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_5(NumCase)			(22278 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_6(NumCase)			(22279 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_7(NumCase)			(22280 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_8(NumCase)			(22281 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_9(NumCase)			(22282 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_10(NumCase)			(22283 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_11(NumCase)			(22284 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_RECYCLAGE_12(NumCase)			(22285 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_1(NumCase)				(22286 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_2(NumCase)				(22287 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_3(NumCase)				(22288 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_4(NumCase)				(22289 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_5(NumCase)				(22290 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_6(NumCase)				(22291 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_7(NumCase)				(22292 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_8(NumCase)				(22293 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_9(NumCase)				(22294 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_10(NumCase)			(22295 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_11(NumCase)			(22296 + ((NumCase) * NBR_RNV2))
#define RNV_VENTILO_DEGAZAGE_12(NumCase)			(22297 + ((NumCase) * NBR_RNV2))
#define RNV_ELECTROVANNE_1(NumCase)					(22298 + ((NumCase) * NBR_RNV2))
#define RNV_ELECTROVANNE_2(NumCase)					(22299 + ((NumCase) * NBR_RNV2))
#define RNV_EVAPORATEUR_1(NumCase)					(22300 + ((NumCase) * NBR_RNV2))
#define RNV_EVAPORATEUR_2(NumCase)					(22301 + ((NumCase) * NBR_RNV2))
#define RNV_OUVR_ENTREE_AIR(NumCase)				(22302 + ((NumCase) * NBR_RNV2))
#define RNV_FERM_ENTREE_AIR(NumCase)				(22303 + ((NumCase) * NBR_RNV2))
#define RNV_TURBINE_OUVR_SORTIE_AIR(NumCase)		(22304 + ((NumCase) * NBR_RNV2))
#define RNV_FERM_SORTIE_AIR(NumCase)				(22305 + ((NumCase) * NBR_RNV2))
#define RNV_SORTIE_AEROTHERME(NumCase)				(22306 + ((NumCase) * NBR_RNV2))
#define RNV_SORTIE_BRUMISATION(NumCase)				(22307 + ((NumCase) * NBR_RNV2))
#define RNV_SORTIE_RESISTANCE_DEGIVRAGE(NumCase)	(22308 + ((NumCase) * NBR_RNV2))
#define RNV_SORTIE_ANA_TRAPPE(NumCase)				(22309 + ((NumCase) * NBR_RNV2))
#define RNV_SORTIE_CHAUD(NumCase)				    (22310 + ((NumCase) * NBR_RNV2))


// Entrées TOR
#define RNV_ENTREE_EJP(NumCase)						(22315 + ((NumCase) * NBR_RNV2))
#define RNV_AUTORISER_EXT_VENTIL(NumCase)			(22316 + ((NumCase) * NBR_RNV2))
#define RNV_AUTORISER_EXT_FROID(NumCase)			(22317 + ((NumCase) * NBR_RNV2))
#define RNV_ENTREE_TRAPPE_AIR_FERME(NumCase)		(22318 + ((NumCase) * NBR_RNV2))
#define RNV_ENTREE_SORTIE_AIR_OUVR(NumCase)			(22319 + ((NumCase) * NBR_RNV2))
#define RNV_UTILISATION_SORTIE_AIR(NumCase)			(22320 + ((NumCase) * NBR_RNV2))
#define RNV_UTILISATION_PRIO_VENTIL(NumCase)		(22321 + ((NumCase) * NBR_RNV2))
#define RNV_UTILISATION_PRIO_FROID(NumCase)			(22322 + ((NumCase) * NBR_RNV2))
#define RNV_DEFAUT_VENTILATEUR(NumCase)				(22323 + ((NumCase) * NBR_RNV2))
#define RNV_DEFAUT_GROUPE(NumCase)					(22324 + ((NumCase) * NBR_RNV2))
#define RNV_DEFAUT_SORTIE_AIR(NumCase)				(22325 + ((NumCase) * NBR_RNV2))
#define RNV_DEFAUT_ENTREE_AIR(NumCase)				(22326 + ((NumCase) * NBR_RNV2))
#define RNV_ENTREE_TH_GEL(NumCase)					(22327 + ((NumCase) * NBR_RNV2))
#define RNV_DEFAUT_BRUMISATION(NumCase)				(22328 + ((NumCase) * NBR_RNV2))
#define RNV_ENTREE_CO2(NumCase)						(22329 + ((NumCase) * NBR_RNV2))
#define RNV_ENTREE_DEFAUT_CHAUD(NumCase)			(22330 + ((NumCase) * NBR_RNV2))

// Entr饳 ANA
#define RNV_TEMP_SONDE_EXT(NumCase)			 		(22333 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_GAINE(NumCase)		 		(22334 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_EVAP(NumCase)			 	(22335 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_HYGRO_EXT(NumCase)	 		(22336 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_1(NumCase)			 		(22337 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_2(NumCase)			 		(22338 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_3(NumCase)			 		(22339 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_4(NumCase)			 		(22340 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_5(NumCase)			 		(22341 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_6(NumCase)			 		(22342 + ((NumCase) * NBR_RNV2))																	   																	   																	   																																																																																									
#define RNV_TEMP_SONDE_AMBIANCE(NumCase)		 	(22343 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_CO2(NumCase)                 (22344 + ((NumCase) * NBR_RNV2))
#define RNV_TEMP_SONDE_HYGRO_INT(NumCase)			(22345 + ((NumCase) * NBR_RNV2))  //#define RNV_ANA_LIBRE_1(NumCase)				 	(22338 + ((NumCase) * NBR_RNV2))																	 																		 			   																																									 																				 																		
#define RNV_NBR_SONDE(NumCase)		 				(22346 + ((NumCase) * NBR_RNV2))
// d颵t adresse   110*8 + 22250=23130

// Alarme G鮩rale
#define RNV_SORTIE_ALARME_GENERALE					23130
// Groupe froid
#define RNV_GROUPE_FROID							23131

#define RNV_NBR_CASE								23132
#define RNV_SORTIE_OUVR_SORTIE_AIR_COMMUNE			23133
#define RNV_SORTIE_FERM_SORTIE_AIR_COMMUNE			23134
#define RNV_SORTIE_ANA_PUISSANCE_GROUPE				23135
#define RNV_TEMPS_ON_ALARME_GENERALE				23136
#define RNV_TEMPS_OFF_ALARME_GENERALE				23137
#define RNV_GRP_FROID_TEMP_MIN                      23138
#define RNV_GRP_FROID_TEMP_MAX                      23139
#define RNV_GRP_FROID_NBR_POINT_SANA_TEMP_MIN       23140
#define RNV_GRP_FROID_NBR_POINT_SANA_TEMP_MAX       23141




#define RNV_NOM_CASE_1(NumCase)                     (23150 + (NumCase*2))
#define RNV_NOM_CASE_2(NumCase)                     (23151 + (NumCase*2))
#define RNV_NOM_CASE1_1                             23150
#define RNV_NOM_CASE1_2                             23151
#define RNV_NOM_CASE2_1         					23152
#define RNV_NOM_CASE2_2         					23153
#define RNV_NOM_CASE3_1         					23154
#define RNV_NOM_CASE3_2         					23155
#define RNV_NOM_CASE4_1         					23156
#define RNV_NOM_CASE4_2         					23157
#define RNV_NOM_CASE5_1         					23158
#define RNV_NOM_CASE5_2         					23159
#define RNV_NOM_CASE6_1         					23160
#define RNV_NOM_CASE6_2         					23161
#define RNV_NOM_CASE7_1         					23162
#define RNV_NOM_CASE7_2         					23163
#define RNV_NOM_CASE8_1         					23164
#define RNV_NOM_CASE8_2         					23165



#define RNV_FREQ_SAUVEGARDE_HISTO					23166
#define RNV_INDEX_SAUVEGARDE						23167
#define RNV_VALEUR_ABERRANTE_1						23168
#define RNV_VALEUR_ABERRANTE_2						23169
#define RNV_NBR_TENTATIVE_ERREUR					23170


// Timers Ventilation
#define TMR_VALID_AU_MOINS_1_TAS_VNTL(NumCase)		(1024 + ((NumCase) * NBR_TMR))
#define TMR_VALID_TOUTES_TAS_VNTL(NumCase)			(1025 + ((NumCase) * NBR_TMR))
#define TMR_COND_CSGN_TAS_VENTILATION(NumCase)		(1026 + ((NumCase) * NBR_TMR))
#define TMR_COND_T_EXT_DESSUS_MINI_VNTL(NumCase)	(1027 + ((NumCase) * NBR_TMR))
#define TMR_COND_T_EXT_DESSOUS_TAS_VNTL(NumCase)	(1028 + ((NumCase) * NBR_TMR))
#define TMR_COND_TOLERENCE_DEGAZ_VNTL(NumCase)		(1029 + ((NumCase) * NBR_TMR))
#define TMR_CYLCE_VNTLTN_VNTL(NumCase)				(1030 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_FROID_VNTL(NumCase)				(1031 + ((NumCase) * NBR_TMR))
#define TMR_COND_TROP_CHAUD_FROID_VNTL(NumCase)		(1032 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_DEGAZ_VNTL(NumCase)				(1033 + ((NumCase) * NBR_TMR))
#define TMR_VALID_SONDE_EXT_VNTL(NumCase)			(1034 + ((NumCase) * NBR_TMR))
#define TMR_VALID_SONDE_GAINE_VNTL(NumCase)			(1035 + ((NumCase) * NBR_TMR))
#define TMR_MAXI_TAS_PAR_JOUR_VNTL(NumCase)			(1036 + ((NumCase) * NBR_TMR))
#define TMR_COND_T_GAINE_DESSUS_TAS_VNTL(NumCase)	(1037 + ((NumCase) * NBR_TMR))
#define TMR_ALTERNANCE_VENTILATEUR(NumCase)			(1038 + ((NumCase) * NBR_TMR))
#define TMR_VERIF_TRAPE_AIR_FERME(NumCase)			(1039 + ((NumCase) * NBR_TMR))
#define TMR_HYGROMETRIE(NumCase)					(1040 + ((NumCase) * NBR_TMR))
#define TMR_VERIF_SORTIE_AIR_OUVERTE(NumCase)		(1041 + ((NumCase) * NBR_TMR))
#define TMR_TPS_ENTRE_VENTILO_VNTL(NumCase)			(1042 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_DEFAUT_VENTILATEUR(NumCase)		(1043 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_DEFAUT_GROUPE(NumCase)			(1044 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_DEFAUT_SORTIE_AIR(NumCase)		(1045 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_DEFAUT_ENTREE_AIR(NumCase)		(1046 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_RECYC_VNTL(NumCase)				(1047 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_DEGIVRAGE_VNTL(NumCase)			(1048 + ((NumCase) * NBR_TMR))
#define TMR_TPS_MAX_SNS_VENTILATION(NumCase)		(1049 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_SONDE_HORS_SERVICE(NumCase)		(1050 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_SEUIL_MAX_SONDE_TAS(NumCase)		(1051 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_SEUIL_SONDE_GAINE(NumCase)		(1052 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_SEUIL_SONDE_AMBIANCE(NumCase)	(1053 + ((NumCase) * NBR_TMR))
#define TMR_COND_T_EXT_DESSOUS_TAS_AEROTH(NumCase)	(1054 + ((NumCase) * NBR_TMR))
#define TMR_COND_ECART_TAS_EXT_AEROTH(NumCase)		(1055 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_AEROTHERME(NumCase)				(1056 + ((NumCase) * NBR_TMR))
#define TMR_TEMPS_MAXI_SANS_BRASSAGE(NumCase)		(1057 + ((NumCase) * NBR_TMR))
#define TMR_TEMPS_MAXI_BRASSAGE(NumCase)			(1058 + ((NumCase) * NBR_TMR))
#define TMR_TEMPS_MINI_BRASSAGE(NumCase)			(1059 + ((NumCase) * NBR_TMR))
#define TMR_TEMP_MINI_GAINE(NumCase)				(1060 + ((NumCase) * NBR_TMR))
#define TMR_COND_CSGN_TAS_FROID(NumCase)			(1061 + ((NumCase) * NBR_TMR))
#define TMR_BRUMISATION(NumCase)					(1062 + ((NumCase) * NBR_TMR))
#define TMR_DEGIVRAGE_MAXI(NumCase)					(1063 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_DEGAZ_VENTILO(NumCase)			(1064 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_DEFAUT_BRUMISATION(NumCase)		(1065 + ((NumCase) * NBR_TMR))
#define TMR_BRUMISATION_FROID(NumCase)				(1066 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_SEUIL_MIN_SONDE_TAS(NumCase)		(1067 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_ENTREE_CO2(NumCase)				(1068 + ((NumCase) * NBR_TMR))
#define TMR_CYCLE_CHAUD_VNTL(NumCase)				(1069 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_SEUIL_SONDE_CO2(NumCase)		    (1070 + ((NumCase) * NBR_TMR))
#define TMR_COND_CSGN_TAS_CHAUD(NumCase)			(1071 + ((NumCase) * NBR_TMR))
#define TMR_COND_T_REF_TD(NumCase)				    (1072 + ((NumCase) * NBR_TMR))
#define TMR_FILTRE_ENTREE_DEFAUT_CHAUD(NumCase)		(1073 + ((NumCase) * NBR_TMR))
#define TMR_DG_E_TEMPS_MIN_FCT_FROID_ECOULE(NumCase)	(1074 + ((NumCase) * NBR_TMR))



#define TMR_SAUVEGARDE_HISTO						1504
#define TMR_ENTRE_TRAME								1505
#define TMR_TEMPS_ALARME_GENERALE					1506
#define TMR_TEMPS_OFF_ALARME_GENERALE				1507
#define TMR_RETARD_MINUIT							1508
#define TMR_INIT_VAL_USINE							1509


typedef struct
{
	unsigned gbToutesValide:1;
	unsigned gbAuMoinsUneValide:1;
	unsigned gbCondFirst:1;
	unsigned gbCond_Consigne_Tas_Ventilation_New:1;
	unsigned gbCond_Consigne_Tas_Ventilation_Old:1;
	unsigned gbCond_Consigne_Tas_Ventilation_Tempo:1;
	unsigned gbCond_Consigne_Tas_Froid_New:1;
	unsigned gbCond_Consigne_Tas_Froid_Old:1;
	unsigned gbCond_Consigne_Tas_Froid_Tempo:1;
    unsigned gbCond_Consigne_Tas_Chaud_New:1;
	unsigned gbCond_Consigne_Tas_Chaud_Old:1;
	unsigned gbCond_Consigne_Tas_Chaud_Tempo:1;
	unsigned gbCond_TempExtAuDessusMini_New:1;
	unsigned gbCond_TempExtAuDessusMini_Old:1;
	unsigned gbCond_TempExtEnDessousTas_New:1;
	unsigned gbCond_TempExtEnDessousTas_Old:1;
    unsigned gbCond_TempExtEnDessousTas_Tempo:1; //  RABII
	unsigned gbCond_TempExtEnDessousTasAerotherme_New:1;
	unsigned gbCond_TempExtEnDessousTasAerotherme_Old:1;
	unsigned gbCond_EcartTasExtAerotherme_New:1;
	unsigned gbCond_EcartTasExtAerotherme_Old:1;
	unsigned gbCond_TempMinGaine_New:1;
	unsigned gbCond_TempMinGaine_Old:1;
	unsigned gbCond_ToleranceDegazage_New:1;
	unsigned gbCond_ToleranceDegazage_Old:1;
	unsigned gbCondition_TropFroid_New:1;
	unsigned gbCondition_TropChaud_New:1;
	unsigned gbCondition_TropFroid_Old:1;
	unsigned gbCondition_TropChaud_Old:1;
	unsigned gbCondAmbianceInfTas:1;
	unsigned gbCond_MaxiTasParJour_New:1;
	unsigned gbCond_MaxiTasParJour_Old:1;
	unsigned gbCond_EntreeCO2_New:1;
	unsigned gbCond_EntreeCO2_Old:1;
	unsigned gbCond_SondeCO2AuDessusSeuil_New:1;
	unsigned gbCond_SondeCO2AuDessusSeuil_Old:1;    
	unsigned gbInitVentiloG1:1;
	unsigned gbInitVentiloG2:1;
	unsigned gbTimerOuvertureEntreeAir:1;
	unsigned gbTimerTempsMortVentilation:1;
	unsigned gbTimerTempsMortFroid:1;
	unsigned gbTimerTempsMortChaud:1;
	unsigned gbTimerTempsMortDegazage:1;
	unsigned gbTimerSeuilHygrometrie:1;
	unsigned gbTimerEntreVentiloG1:1;
	unsigned gbTimerEntreVentiloG2:1;
	unsigned gbSondeExtValide:1;
	unsigned gbSondeGaineValide:1;
	unsigned gbToutesSondesOK:1;
	unsigned gbDegivrageSondeRef:1;
	unsigned gbCond_Gaine_Tas_New:1;
	unsigned gbCond_Gaine_Tas_Old:1;
	unsigned gbRecyclageVentilation:1;
	unsigned gbTimerFiltreDefautVentilateur:1;
    unsigned gbTimerFiltreEntreeDefautChaud:1;
	unsigned gbTimerFiltreDefautBumisation:1;
	unsigned gbTimerFiltreDefautGroupe:1;
	unsigned gbTimerFiltreDefautSortieAir:1;
	unsigned gbTimerFiltreDefautEntreeAir:1;
	unsigned gbTimerFiltreSondeHorsService:1;
	unsigned gbTimerFiltreSeuilMaxSondeTas:1;
	unsigned gbTimerFiltreSeuilMinSondeTas:1;
	unsigned gbTimerFiltreSeuilSondeGaine:1;
	unsigned gbTimerFiltreSeuilSondeAmbiance:1;
	unsigned gbEvapoForcee:1;
	unsigned gbMinuit:1;
	unsigned gbRetardMinuit:1;
	unsigned gImageSortieVentilationG1:1;
	unsigned gImageSortieVentilationG2:1;
	unsigned gImageSortieOuvertEntreeAir:1;
	unsigned gImageSortieFermEntreeAir:1;
	unsigned gImageSortieTurbineAirOuvrtSortieAir:1;
	unsigned gImageSortieFermSortieAir:1;
	unsigned gImageSortieElectrovanne:1;
	unsigned gImageSortieEvaporateur:1;
	unsigned gImageSortieBrumisation:1;
    unsigned gImageSortieChaud:1;
    unsigned gbTimerTempRefAuDessusTD:1;
    unsigned gbAlarme_Sonde_Hors_Service_New:1;
    unsigned gbAlarme_Sonde_Hors_Service_Old:1;
    unsigned gbAlarme_Seuil_Max_Tas_New:1;
    unsigned gbAlarme_Seuil_Max_Tas_Old:1;
    unsigned gbAlarme_Defaut_Ventil_New:1;
    unsigned gbAlarme_Defaut_Ventil_Old:1;
    unsigned gbAlarme_Defaut_Groupe_New:1;
    unsigned gbAlarme_Defaut_Groupe_Old:1;
    unsigned gbAlarme_Entree_Defaut_Chaud_New:1;
    unsigned gbAlarme_Entree_Defaut_Chaud_Old:1;
    unsigned gbTimerFiltreDefautEntreeChaud:1;
    unsigned gbAlarmeDegivrageEcart:1;
    unsigned gbFermeTrappeApresReset:1;
}StructBoolVentil;

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////             valeurs par defaut           //////////////////////
//////////////////////////////////////////////////////////////////////////////////////
#define VAL_NBR_CASE                               		NBR_CASE                 
#define VAL_FREQ_SAUVEGARDE_HISTO                  		1144	// 24h             
#define VAL_INDEX_SAUVEGARDE                       		0 	                     
#define VAL_VALEUR_ABERRANTE_1                     		-99 	                   
#define VAL_VALEUR_ABERRANTE_2                     		-88 	                   
#define VAL_NBR_TENTATIVE_ERREUR                   		3 	                     
#define VAL_TEMPS_ON_ALARME_GENERALE               		2                        
#define VAL_TEMPS_OFF_ALARME_GENERALE              		2 	
#define VAL_GRP_FROID_TEMP_MIN              		    2
#define VAL_GRP_FROID_TEMP_MAX              		    10
#define VAL_GRP_FROID_NBR_POINT_SANA_TEMP_MIN           4000
#define VAL_GRP_FROID_NBR_POINT_SANA_TEMP_MAX           0
#define VAL_SORTIE_ALARME_GENERALE                 		POUBELLE                 
#define VAL_GROUPE_FROID                           		POUBELLE                 
#define VAL_SORTIE_OUVR_SORTIE_AIR_COMMUNE         		POUBELLE                 
#define VAL_SORTIE_FERM_SORTIE_AIR_COMMUNE         		POUBELLE      
#define VAL_SORTIE_ANA_PUISSANCE_GROUPE                 POUBELLE
#define VAL_TEMP_FINALE_VNTL                       		6. 		                   
#define VAL_ECART_MAXI_TAS_GAINE_VNTL              		3. 		                   
#define VAL_ECART_MAXI_TAS_GAINE_FROID             		3. 		                   
#define VAL_TEMP_MIN_EXT_VNTL                      		0. 		                   
#define VAL_ECART_MINI_TAS_CSGN_VENTILATION        		0.3                      
#define VAL_ECART_MINI_TAS_CSGN_FROID              		0.3 	
#define VAL_ECART_MINI_TAS_CSGN_CHAUD              		0.3 
#define VAL_ECART_MINI_TAS_EXT_VNTL                		1. 		                   
#define VAL_DEBUT_HDP_VNTL_VNTL                    		0 		                   
#define VAL_FIN_HDP_VNTL_VNTL                      		0 		                   
#define VAL_DEBUT_HDP_AEROTHERME                   		0 		                   
#define VAL_FIN_HDP_AEROTHERME                     		0 		                   
#define VAL_DEBUT_HDP_FROID_VNTL                   		0 		                   
#define VAL_FIN_HDP_FROID_VNTL                     		0 		                   
#define VAL_TPS_ACTN_OUVR_TRAPPE_AIR               		10 		                   
#define VAL_TPS_ACTN_FERM_TRAPPE_AIR               		8 		                   
#define VAL_TPS_ATTE_ENTRE_2_ACTN_VNTL             		30 		                   
#define VAL_TPS_MAX_SNS_VNTL_DEGZ_VNTL             		1080 		                 
#define VAL_TPS_MAX_SNS_VNTL_RCYC_VNTL             		1440 		                 
#define VAL_TPS_RECYC_VNTL                         		10 		                   
#define VAL_TPS_DEGAZ_VNTL                         		10 		                   
#define VAL_TPS_OUVER_TRAPPE_DEGAZ_VNTL            		30 		                   
#define VAL_TOL_DEGAZ_VNTL                         		5. 		                   
#define VAL_CHOIX_TYPE_TRAPPE_ANA_TOR              		TYPE_TRAPPE_TOR 		     
#define VAL_POINT_ACTN_OUVR_VNTL                   		300                      
#define VAL_POINT_ACTN_FERM_VNTL                   		250 			               
#define VAL_POINT_OUVER_TRAPPE_DEGAZ_VNTL          		800                      
#define VAL_NOMBRE_SONDE_VNTL                      		0                        
#define VAL_SONDE_REF_VNTL                         		CONS_CHOIX_REF_MOYENNE 		
#define VAL_TEMPS_MIN_FCT_FROID_ECOULE             		10 			                 
#define VAL_TEMPS_MAXI_SANS_BRASSAGE               		20 			                 
#define VAL_TEMPS_MAXI_BRASSAGE                    		12 			                 
#define VAL_TEMPS_MINI_BRASSAGE                    		5 			                 
#define VAL_TEMPS_TEMP_MINI_GAINE                  		1 			                 
#define VAL_TEMP_BRUMISATION_ON                    		0 			                 
#define VAL_TEMP_BRUMISATION_OFF                   		0 			                 
#define VAL_TEMP_BRUMISATION_FROID_ON              		0 			                 
#define VAL_TEMP_BRUMISATION_FROID_OFF             		0 			                 
#define VAL_TEMPS_EGOUTTE_DEGIVRAGE                		5 			                 
#define VAL_ECART_MIN_TAS_GAINE_EAU_GLYCOL         		0.5 			               
#define VAL_ECART_MAX_TAS_GAINE_EAU_GLYCOL         		3 			                 
#define VAL_CHOIX_DEGIVRAGE                        		DG_AIR 			             
#define VAL_PWM_FERMETURE_TOTALE                   		PWM_FERMETURE_TOTALE 			
#define VAL_PWM_OUVERTURE_TOTALE                   		PWM_OUVERTURE_TOTALE 			
#define VAL_CPTR_HORO_VNTLTN_VNTL                  		0 			                 
#define VAL_CPTR_HORO_FROID_VNTL                   		0 			                 
#define VAL_CPTR_HORO_DEGAZ_VNTL                   		0 			                 
#define VAL_CPTR_HORO_RECYC_VNTL                   		0 			                 
#define VAL_CPTR_HORO_AEROTHERME                   		0 			                 
#define VAL_CPTR_HORO_BRUMISATION                  		0 			                 
#define VAL_CPTR_HORO_DEGIVRAGE                    		0 			                 
#define VAL_DUREE_CYCLE_VNTLTN_VNTL                		0 			                 
#define VAL_DUREE_CYCLE_FROID_VNTL                 		0 
#define VAL_DUREE_CYCLE_CHAUD_VNTL                 		0 
#define VAL_DUREE_CYCLE_DEGAZ_VNTL                 		0 			                 
#define VAL_DUREE_CYCLE_RECYC_VNTL                 		0 			                 
#define VAL_DUREE_CYCLE_AEROTHERME                 		0 			                 
#define VAL_DUREE_CYCLE_BRUMISATION                		0 			                 
#define VAL_DUREE_CYCLE_DEGIVRAGE                  		0 			                 
#define VAL_DUREE_VENTILATION_FROID                		0 			                 
#define VAL_DUREE_VENTILATION_RECYC                		0 			                 
#define VAL_DUREE_VENTILATION_DEGAZ                		0 			                 
#define VAL_DUREE_CYCLE_VNTLTN_PREC                		0 			                 
#define VAL_DUREE_CYCLE_FROID_PREC                 		0 	
#define VAL_DUREE_CYCLE_CHAUD_PREC                 		0 
#define VAL_DUREE_CYCLE_DEGAZ_PREC                 		0 			                 
#define VAL_DUREE_CYCLE_RECYC_PREC                 		0 			                 
#define VAL_DUREE_CYCLE_AEROTHERME_PREC            		0 			                 
#define VAL_DUREE_CYCLE_BRUMISATION_PREC           		0 			                 
#define VAL_DUREE_CYCLE_DEGIVRAGE_PREC             		0 			                 
#define VAL_DUREE_VENTILATION_FROID_PREC           		0 			                 
#define VAL_DUREE_VENTILATION_RECYC_PREC           		0 			                 
#define VAL_DUREE_VENTILATION_DEGAZ_PREC           		0 			                 
#define VAL_CPTR_HORO_VENTILATION_FROID            		0 			                 
#define VAL_CPTR_HORO_VENTILATION_DEGAZ            		0 			                 
#define VAL_CPTR_HORO_VENTILATION_RECYC            		0 			                 
#define VAL_LIMITE_SONDE_MINI_VNTL                 		BORNE_TOL_TEMP_TAS_BASSE 
#define VAL_LIMITE_SONDE_MAXI_VNTL                 		BORNE_TOL_TEMP_TAS_HAUTE 
#define VAL_DUREE_TPS_MORT_VNTLTN_VNTL             		DUREE_TPS_MORT_VNTLTN 		
#define VAL_DUREE_TPS_MORT_FROID_VNTL              		DUREE_TPS_MORT_FROID 			
#define VAL_ECART_MAXI_TAS_AMBIANCE_VNTL           		3. 			                 
#define VAL_ECART_MAXI_TAS_PAR_JOUR_VNTL           		0.3 			               
#define VAL_TEMPS_ENTRE_DMR_VENTILO_VNTL           		0.5 			               
#define VAL_SEUIL_MINI_SONDE_EVAP_VNTL             		0 			                 
#define VAL_NBR_HEURE_FCT_FROID_VNTL               		180 			               
#define VAL_TEMPS_DEGIVRAGE_VNTL                   		60 			                 
#define VAL_TEMPS_MINI_DEGIVRAGE_VNTL              		5 			                 
#define VAL_CHOIX_SONDE_GAINE                      		1 			                 
#define VAL_TPS_FERM_TRAPPE_VNTL                   		0 			                 
#define VAL_TPS_ALTERNANCE_VENTILO_VNTL            		0 			                 
#define VAL_TPS_ALTERNANCE_VENTILO_RCYC            		0 			                 
#define VAL_TPS_ALTERNANCE_VENTILO_FROID           		0 			                 
#define VAL_TEMP_MIN_GAINE_VNTL                    		0. 		                   
#define VAL_SEUIL_HYGROMETRIE                      		0 		                   
#define VAL_POURCENT_CYCLE_VNTL                    		10 		                   
#define VAL_DUREE_MIN_RECYC_VNTL                   		10 		                   
#define VAL_DUREE_MAX_RECYC_VNTL                   		15 		                   
#define VAL_TPS_OUVERTURE_SORTIE_AIR_VNTL          		30 		                   
#define VAL_FILTRE_DEFAUT_VENTILATEUR              		5 		                   
#define VAL_FILTRE_DEFAUT_GROUPE                   		5 		                   
#define VAL_FILTRE_DEFAUT_SORTIE_AIR               		0 		                   
#define VAL_FILTRE_DEFAUT_ENTREE_AIR               		5 		                   
#define VAL_FILTRE_DEFAUT_BRUMISATION              		0 		                   
#define VAL_TPS_MAX_SNS_VENTILATION                		2880	// 48 h            
#define VAL_FILTRE_SONDE_HORS_SERVICE              		5 		                   
#define VAL_SEUIL_MAX_SONDE_TAS                    		0 		                   
#define VAL_SEUIL_MIN_SONDE_TAS                    		3 		                   
#define VAL_SEUIL_SONDE_GAINE                      		0 		                   
#define VAL_SEUIL_SONDE_AMBIANCE                   		0 		                   
#define VAL_FILTRE_SEUIL_MAX_SONDE_TAS             		0 		                   
#define VAL_FILTRE_SEUIL_MIN_SONDE_TAS             		1 		                   
#define VAL_HEURE_DEBUT_ALARME                     		0 		                   
#define VAL_HEURE_FIN_ALARME                       		0 		                   
#define VAL_FILTRE_SEUIL_SONDE_GAINE               		0 		                   
#define VAL_FILTRE_SEUIL_SONDE_AMBIANCE            		0 		                   
#define VAL_CHOIX_MODE_TOR_ANA                     		MODE_TOR 		             
#define VAL_TEMPS_ENTRE_ACTION                     		0 		                   
#define VAL_TEMPS_ON_AEROTHERME                    		0 		                   
#define VAL_TEMPS_OFF_AEROTHERME                   		0 		                   
#define VAL_ECART_TAS_EXT_AEROTHERME               		5. 	
#define VAL_SEUIL_CO2             	                	0 

#define VAL_DG_T_REF_1                                  8.
#define VAL_DG_T_REF_2                                  6.
#define VAL_DG_T_REF_3                                  4.
#define VAL_DG_T_REF_TEMPS_DIGIVRAGE_1                  30 //mn
#define VAL_DG_T_REF_TEMPS_DIGIVRAGE_2                  30 //mn
#define VAL_DG_T_REF_TEMPS_DIGIVRAGE_3                  30 //mn
#define VAL_DG_T_REF_TEMPS_DIGIVRAGE_4                  45 //mn
#define VAL_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_1            1080 //mn = 18 h
#define VAL_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_2            720  //mn = 12 h
#define VAL_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_3            360  //mn = 6 h
#define VAL_DG_T_REF_TEMPS_ENTRE_DIGIVRAGE_4            360  //mn = 6 h 
#define VAL_DG_E_ECART_TAS_SOUFFLAGE                    2.5
#define VAL_DG_E_TEMPS_MIN_FCT_FROID_ECOULE             90   //mn = 1h:30mn
#define VAL_DG_E_TEMPS_DIGIVRAGE                        50 //mn
#define VAL_DG_E_NBR                                    3

#define VAL_ELECTROVANNE_1                         		POUBELLE                 
#define VAL_ELECTROVANNE_2                         		POUBELLE                 
#define VAL_EVAPORATEUR_1                          		POUBELLE                 
#define VAL_EVAPORATEUR_2                          		POUBELLE                 
#define VAL_OUVR_ENTREE_AIR                        		POUBELLE                 
#define VAL_FERM_ENTREE_AIR                        		POUBELLE                 
#define VAL_TURBINE_OUVR_SORTIE_AIR                		POUBELLE                 
#define VAL_FERM_SORTIE_AIR                        		POUBELLE                 
#define VAL_SORTIE_AEROTHERME                      		POUBELLE                 
#define VAL_SORTIE_BRUMISATION                     		POUBELLE                 
#define VAL_SORTIE_RESISTANCE_DEGIVRAGE            		POUBELLE 		             
#define VAL_SORTIE_ANA_TRAPPE		            		POUBELLE 
#define VAL_SORTIE_CHAUD		            		    POUBELLE   // Sortie Chauffage   //Rabii
#define VAL_ENTREE_EJP                             		MICRONAR2_FAUX           
#define VAL_AUTORISER_EXT_VENTIL                   		MICRONAR2_FAUX           
#define VAL_AUTORISER_EXT_FROID                    		MICRONAR2_FAUX           
#define VAL_ENTREE_TRAPPE_AIR_FERME                		MICRONAR2_FAUX           
#define VAL_ENTREE_SORTIE_AIR_OUVR                 		MICRONAR2_FAUX           
#define VAL_UTILISATION_SORTIE_AIR                 		MICRONAR2_FAUX           
#define VAL_UTILISATION_PRIO_VENTIL                		MICRONAR2_FAUX           
#define VAL_UTILISATION_PRIO_FROID                 		MICRONAR2_FAUX           
#define VAL_DEFAUT_VENTILATEUR                     		MICRONAR2_FAUX           
#define VAL_DEFAUT_GROUPE                          		MICRONAR2_FAUX           
#define VAL_DEFAUT_SORTIE_AIR                      		MICRONAR2_FAUX           
#define VAL_DEFAUT_ENTREE_AIR                      		MICRONAR2_FAUX           
#define VAL_ENTREE_TH_GEL                          		MICRONAR2_FAUX           
#define VAL_DEFAUT_BRUMISATION                     		MICRONAR2_FAUX 			     
#define VAL_ENTREE_CO2                          		MICRONAR2_FAUX  
#define VAL_ENTREE_DEFAUT_CHAUD                         MICRONAR2_FAUX
#define VAL_TEMP_SONDE_EXT                         		ANA_ZERO                 
#define VAL_TEMP_SONDE_GAINE                       		ANA_ZERO                 
#define VAL_TEMP_SONDE_EVAP                        		ANA_ZERO                 
#define VAL_TEMP_SONDE_HYGRO_EXT                   		ANA_ZERO                 
#define VAL_TEMP_SONDE_AMBIANCE                    		ANA_ZERO             
#define VAL_NBR_SONDE                              		0                        
#define VAL_DEBUT_PLAGE                            		0                        
#define VAL_FIN_PLAGE                              		0                        
#define VAL_VENTILO_VENTILATION_1                 		POUBELLE 
#define VAL_VENTILO_FROID_1                       		POUBELLE 
#define VAL_VENTILO_RECYCLAGE_1                   		POUBELLE 
#define VAL_VENTILO_DEGAZAGE_1                    		POUBELLE 
#define VAL_TEMP_SONDE_1                          		ANA_ZERO 
#define VAL_TEMP_SONDE_HYGRO_INT                   		ANA_ZERO 
#define VAL_TEMP_SONDE_CO2                   	        ANA_ZERO 
//////////////////////////////////////////////////////////////////////////////////////




// Prototypes des fonctions Ventilation
void InitVentilation();
void GestionRoutineVentilation();
void GestionConditions(int NumCase);
void GestionSondes(int NumCase);
void GestionRef(int NumCase);
void GestionHygrometrie(int NumCase);
void GestionCondTD(int NumCase);
void GestionPointSortieANA();
void GestionCycleVentilation(int NumCase);
void InitGrpVentiloVentilation(int NumCase);
int DemarrageGrpVentiloVentilation(int NumCase);
void AlternanceGrpVentiloVentilation(int NumCase);
void SauvegardeGrpVentiloVentilation(int NumCase);
void StartVentilation(int NumCase);
void StopVentilation(int NumCase);
void GestionCycleFroid(int NumCase);
void GestionDegivrage(int NumCase);
void InitGrpVentiloFroid(int NumCase);
int DemarrageGrpVentiloFroid(int NumCase);
void AlternanceGrpVentiloFroid(int NumCase);
void SauvegardeGrpVentiloFroid(int NumCase);
void StartFroid(int NumCase);
void StopFroid(int NumCase);
void GestionCycleChaud(int NumCase);
void StartChaud(int NumCase);
void StopChaud(int NumCase);
void GestionGroupeFroid();
int MelangeAir(int NumCase);
void GestionComptHoraires(int NumCase);
void GestionCycleDegazage(int NumCase);
void StartDegazage(int NumCase);
void StopDegazage(int NumCase);
void GestionCycleRecyclage(int NumCase);
void StartRecyclage(int NumCase);
void StopRecyclage(int NumCase);
void GestionCycleAerotherme(int NumCase);
void StartAerotherme(int NumCase);
void StopAerotherme(int NumCase);
void GestionBrumisation(int NumCase);
void GestionBrumisationFroid(int NumCase);
void GestionMAE(int NumCase);
void GestionSorties(int NumCase);
void GestionSortiesAirCommune();
void GestionAlarmeDefaut(int NumCase);
void GestionAlarmeGeneraleCase(int NumCase);
void GestionAlarmeGenerale();
void SetDefaultConfig(int NumCase);
void ArreterVentiloVentilation(int NumCase, char NumDebut, char NumFin);
void ArreterVentiloFroid(int NumCase, char NumDebut, char NumFin);
void ArreterVentiloRecyclage(int NumCase, char NumDebut, char NumFin);
void ArreterVentiloDegazage(int NumCase, char NumDebut, char NumFin);

void ManuVentilation(int NumCase);

int GetActiveRoutineVentilation(void);
int GetAutorisationVentilation(int NumCase);
int GetAutorisationFroid(int NumCase);
int GetAutorisationChaud(int NumCase);
int GetAutorisationRecyclage(int NumCase);
int GetAutorisationDegazage(int NumCase);
int GetModeDegivrage(int NumCase);
int GetAutorisationAerotherme(int NumCase);
int GetRazTempTasMinuit(int NumCase);

float GetConsigneTempVentil(int NumCase);
float GetEcartMaxiTasGaine(int NumCase);
float GetEcartMaxiTasGaineFroid(int NumCase);
float GetEcartMaxiTasGaineEauGlycol(int NumCase);
float GetTempMinExt(int NumCase);
float GetEcartMiniTasConsigneVentilation(int NumCase);
float GetEcartMiniTasConsigneFroid(int NumCase);
float GetEcartMiniTasConsigneChaud(int NumCase);
float GetEcartMiniTasAmbiance(int NumCase);
float GetEcartMaxiTasAmbiance(int NumCase);
float GetEcartMaxiTasParJour(int NumCase);
float GetEcartMiniTasExt(int NumCase);
float GetEcartTasExtAerotherme(int NumCase);
long GetDebutHDPVentilation(int NumCase);
long GetFinHDPVentilation(int NumCase);
long GetDebutHDPFroid(int NumCase);
long GetFinHDPFroid(int NumCase);
long GetDebutHDPAerotherme(int NumCase);
long GetFinHDPAerotherme(int NumCase);
long GetDebutPlage(int NumPlage, int NumCase);
long GetFinPlage(int NumPlage, int NumCase);
long GetTempsActionOuvrTrappeAir(int NumCase);
long GetTempsActionFermTrappeAir(int NumCase);
long GetTempsEntre2Actions(int NumCase);
long GetTempsMaxSansVentilerDegazage(int NumCase);
long GetTempsMaxSnsVentilerRecyclage(int NumCase);
long GetTempsRecyclage(int NumCase);
long GetTempsDegazage(int NumCase);
long GetTempsOuvertureTrappeDegazage(int NumCase);
long GetTempsOnAerotherme(int NumCase);
long GetTempsOffAerotherme(int NumCase);
long GetTempsMaxiSansBrassage(int NumCase);
long GetTempsMaxiBrassage(int NumCase);
long GetTempsMiniBrassage(int NumCase);
long GetTempsTempMinGaine(int NumCase);
long GetTempsBrumisationOn(int NumCase);
long GetTempsBrumisationOff(int NumCase);
long GetTempsBrumisationFroidOn(int NumCase);
long GetTempsBrumisationFroidOff(int NumCase);
long GetTempsEgoutteDegivrage(int NumCase);
float GetToleranceDegazage(int NumCase);
long GetSeuilHygrometrie(int NumCase);
long GetNombreSonde(int NumCase);
long GetSondeReference(int NumCase);
float GetTempReference(int NumCase);
float GetTempSonde(int NumCase, unsigned char NumSonde);
int GetSondeVisuUniquement(int NumCase, unsigned char NumSonde);
float GetTempAmbiance(int NumCase);
float GetSondeCO2(int NumCase);
long GetSeuilCO2(int NumCase);  //rabii
float GetTempExt(int NumCase);
float GetTempGaine(int NumCase);
float GetTempEvap(int NumCase);
float GetHygroExt(int NumCase);
float GetHygroInt(int NumCase);
float GetTD(int NumCase);
float GetLimiteSondeMini(int NumCase);
float GetLimiteSondeMaxi(int NumCase);
long GetDureeTempsMortVentilation(int NumCase);
long GetDureeTempsMortFroid(int NumCase);
float GetTempsEntreDmrVentilo(int NumCase);
float GetSeuilMiniSondeEvap(int NumCase);
long GetNbrHeureFctFroid(int NumCase);
long GetTempsMaxiDegivrage(int NumCase);
long GetTempsMiniDegivrage(int NumCase);
long GetTempsFermetureTrappe(int NumCase);
long GetTempsOuvertureSortieAir(int NumCase);
long GetTempsRecyclageVentilCalculer(int NumCase);
long GetTempsRecyclageFroidCalculer(int NumCase);
long GetTempsRecyclageChaudCalculer(int NumCase);
float GetTempMinGaine(int NumCase);
long GetChoixSondeGaine(int NumCase);

int GetMarcheVentilation(int NumCase);
int GetMarcheFroid(int NumCase);
int GetMarcheChaud(int NumCase);
int GetMarcheDegivrage(int NumCase);
int GetMarcheRecyclage(int NumCase);
int GetMarcheDegazage(int NumCase);
int GetMarcheSortieAirCommune();
void SetSortieVentiloVentilation(int NumCase, char Etat, char NumVentilo);
char GetSortieVentiloVentilation(int NumCase, char NumVentilo);
void SetSortieVentiloFroid(int NumCase, char Etat, char NumVentilo);
char GetSortieVentiloFroid(int NumCase, char NumVentilo);
void SetSortieVentiloRecyclage(int NumCase, char Etat, char NumVentilo);
char GetSortieVentiloRecyclage(int NumCase, char NumVentilo);
void SetSortieVentiloDegazage(int NumCase, char Etat, char NumVentilo);
char GetSortieVentiloDegazage(int NumCase, char NumVentilo);
void SetSortieFroid(char Etat);
void SetSortieChaud(int NumCase, char Etat);
void SetElectroVanne(int NumCase, char Etat, char NumEclectrovanne);
int GetElectroVanne(int NumCase, char NumEclectrovanne);
void SetEvaporateur(int NumCase, char Etat, char NumEvaporateur);
void SetSortieOuvertureTrappeAir(int NumCase, char Etat);
void SetSortieFermetureTrappeAir(int NumCase, char Etat);
void SetSortieTurbineOuvrSortieAir(int NumCase, char Etat);
int GetSortieTurbineOuvrSortieAir(int NumCase);
void SetSortieAerotherme(int NumCase, char Etat);
void SetSortieOuvrSortieAirCommune(char Etat);
int GetSortieOuvrSortieAirCommune();
void SetSortieFermSortieAir(int NumCase, char Etat);
int GetSortieFermSortieAir(int NumCase);
void SetSortieFermSortieAirCommune(char Etat);
int GetSortieFermSortieAirCommune();
void SetEtatSortieAir(int NumCase, char Etat);
int GetEtatSortieAir(int NumCase);
void SetEtatSortieAirCommune(char Etat);
int GetEtatSortieAirCommune();
int GetEntreeEJP(int NumCase);
int GetEntreeTH_GEL(int NumCase);
int GetEntreeCO2(int NumCase);
int IsRefroidissement(int NumCase);
int GetEntreeAutorisationExtVentilation(int NumCase);
int GetEntreeAutorisationExtFroid(int NumCase);
int GetEntreeTrappeAirFermee(int NumCase);
int GetEntreeSortieAirOuverte(int NumCase);
int GetSortieAirPhysique(int NumCase);
int GetEntreeUtilisationSortieAir(int NumCase);


int CDT_SeuilMinTas(int NumCase);
int CDT_TempExtAuDessusMini(int NumCase);
int CDT_TempExtAuDessousTas(int NumCase);
int CDT_TempExtAuDessousTasAerotherme(int NumCase);
int CDT_EcartTasExtAerotherme(int NumCase);
int CDT_TempExtToleranceTasDegazage(int NumCase);
int CDT_AuMoinsUneSondeTasValide(int NumCase);
int CDT_ToutesLesSondesTasValides(int NumCase);
int CDT_SondeExtValide(int NumCase);
int CDT_SondeGaineValide(int NumCase);
int CDT_AnaValide(int NumCase);
int CDT_DemandeRefroidissementVentilation(int NumCase);
int CDT_DemandeRefroidissementFroid(int NumCase);
int CDT_DemandeRefroidissementChaud(int NumCase);
int CDT_TempExtAuDessusMini(int NumCase);
int CDT_TempExtAuDessousTas(int NumCase);
int CDT_HorsHeurePointeVentilation(int NumCase);
int CDT_HorsHeurePointeFroid(int NumCase);
int CDT_TempsMortVentilation(int NumCase);
int CDT_TempsMortFroid(int NumCase);
int CDT_TempsMortChaud(int NumCase);
int CDT_TempsMortDegazage(int NumCase);
int CDT_TempsMaxSnsVentilerDegazage(int NumCase);
int CDT_TempsMaxSnsVentileRecyclage(int NumCase);
int CDT_MelangeTropChaud(int NumCase);
int CDT_MelangeTropFroid(int NumCase);
int CDT_EcartMaxiTasParJour(int NumCase);
int CDT_TempGaineAuDessusTas(int NumCase);
//int CDT_EntreeCO2(int NumCase);
int CDT_SondeCO2AuDessusSeuil(int NumCase);
int CDT_AutorisationPrioriteVentilation(int NumCase);
int CDT_AutorisationPrioriteFroid(int NumCase);
int CDT_AuDessusSeuilHygrometrie(int NumCase);
int CDT_TrefAuDessusTD(int NumCase);
int CDT_HorsHeurePointeAerotherme(int NumCase);
int CDT_TempsOffAerotherme(int NumCase);
int CDT_AutoriserVentilation(int NumCase);
int CDT_AutoriserFroid(int NumCase);
int CDT_AutoriserChaud(int NumCase);
int CDT_AutoriserDegazage(int NumCase);
int CDT_AutoriserRecyclage(int NumCase);
int CDT_AutoriserAerotherme(int NumCase);
int CDT_TempMinGaine(int NumCase);

int Condition_Froid(int NumCase);
void GestionConditionFroid(int NumCase);

int GetDefautsGlobaleEG(int NumCase);
int GetDefautsCaseEG(int NumCase);
void GestionTemperatureRose(int NumCase);

#endif /* VENTILATION_H */
