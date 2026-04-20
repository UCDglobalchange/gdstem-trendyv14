/* **************************************************************
*****************************************************************
BIOMS_GDS.HPP - describes components comprising biomass
*****************************************************************
************************************************************** */
#ifndef BIOMS_GDS_HPP
#define BIOMS_GDS_HPP

class Biomass {

  public:

/* **************************************************************
		 Public Variables
************************************************************** */

     double carbon;       // (Units are grams /square meter)
     double nitrogen;     // (Units are grams /square meter)
     double allocc;       // (Units are grams /(square meter-month))
     double allocn;       //  "
     double allocic;       
     double allocin;       
     double ltrc;
     double ltrn;
     double rm;
     double nresorb;
     double rg;
     double cleaf;
     double csap;
     double cheart;
     double clabile;
     double nleaf;
     double nsap;
     double nheart;
     double nlabile;

};

#endif
