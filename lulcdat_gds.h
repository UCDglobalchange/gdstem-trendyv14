/* *************************************************************
LULCDAT_GDS.H - object to read and write the structure of land
                  use / land cover cohort data from/to files

20060422 - DWK created by modifying lulcdat437.h
20060422 - DWK changed class Lulcdata43 to class Lulcdata44
20060422 - DWK deleted public double RAP
20060422 - DWK added public int disturbflag and public int
           disturbmonth
20070105 - TWC changed name to lulcdat45

************************************************************* */

#ifndef LULCDAT_GDS_H
#define LULCDAT_GDS_H

class Lulcdat45
{

  public:

     Lulcdat45( void );

/* *************************************************************
                      Public Functions
************************************************************* */

// read data structure.
     int get( ifstream& infile );
     int getdel( FILE* infile );

//write data structure.
     void out( ofstream& ofile,
               const float& col,
               const float& row,
               const string& varname,
               const int& year,
               const int& icohort,
               const int& isrccohort,
               const int& standage,
               const float& chrtarea,
               const int& potveg,
               const int& currentveg,
               const int& subtype,
               const int& agstate,
               const int& agprevstate,
               const int& disturbflag,
               const string& region );

     void outdel( ofstream& ofile,
                  const float& col,
                  const float& row,
                  const string& varname,
                  const int& year,
                  const int& icohort,
                  const int& isrccohort,
                  const int& standage,
                  const float& chrtarea,
                  const int& potveg,
                  const int& currentveg,
                  const int& subtype,
                  const int& agstate,
                  const int& agprevstate,
                  const int& disturbflag,
                  const string& region );


/* *************************************************************
                     Public Variables
************************************************************* */

     // flag whether or not grid cell was cultivated the previous
     //   year

     int agprevstate;

     // Flag to indicate land-use of cohort. Different values
     //   represent different land uses:
     //   0 = no land use (natural land cover)
     //   1 = row-crop agriculture
     int agstate;

     // area of a cohort within a grid cell
     float chrtarea;

     // column or longitude of grid cell (degrees)
     float col;

     // Index of current vegetation type
     int currentveg;

     // Flag to indicate that a disturbance has occurred
     //   in a particular year.  Different values represent
     //   different types of disturbances:
     //   0 = no disturbance
     //   1 = conversion to agriculture
     //   2 = timber harvest
     //   3 = fire
     int disturbflag;

     // Month in which disturbance occurred
     // (e.g. 1 = January, ...., 12 = December)
     int disturbmonth;

     // Flag to indicate whether cropland in grid cell
     //   experiences optimum fertilizer application
     int fertflag;

     // Cohort index
     int icohort;

     // Flag to indicate whether cropland in grid cell
     //   experiences optimum irrigation
     int irrgflag;

     // Index of cohort that was source of current cohort
     int isrccohort;

     // percent of grid cell covered with agriculture
     double pctag;

     // Index of potential vegetation biome type
     int potveg;

     // Proportion of vegetation carbon extracted for
     // 10-year wood products
     double prod10par;

     // Proportion of vegetation carbon extracted for
     // 100-year wood products
     double prod100par;

     // name of region containing cohort
     string region;

     // row or latitude of grid cell (degrees)
     float row;

     // Proportion of soil organic carbon lost
     // during a disturbance
     double sconvert;

     // Stand age (years)
     int standage;

     // Index for vegetation subtype
     int subtype;

     // Flag to indicate whether cropland in grid cell
     //   is tilled ( = 1 ) or not ( = 0 )
     int tillflag;

     // varname = "AGRICUL" for this data set
     string varname;

     // Proportion of vegetation carbon lost
     // during a disturbance
     double vconvert;

     // Year data represents
     int year;


  private:

/* *************************************************************
                      Private Variables
************************************************************* */

     int lulcend;
     long curpos;
     long lagpos;

};

#endif

