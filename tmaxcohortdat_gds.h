/* *************************************************************
TMAXCOHORTDAT_GDS.H - object to read and write the structure of
                       maximum number of cohorts grid cell data
                       from/to files used by the
                       Terrestrial Ecosystem Model

Modifications:

20060114 - DWK created by modifying tcohortdat433.h
20060114 - DWK changed class Cohortdata43 to
           class MaxCohortData43
20060114 - DWK added public int year
20060114 - DWK deleted tcohortdat433.cpp from bottom of file
20070105 - TWC changed name to tmaxcohortdat45

****************************************************************
************************************************************* */

#ifndef TMAXCOHORTDAT_GDS_H
#define TMAXCOHORTDAT_GDS_H

class MaxCohortdat45
{

  public:

     MaxCohortdat45( void );

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
               const float& carea,
               const int& year,
               const int& total,
               const string& contnent );

     void outdel( ofstream& ofile,
                  const float& col,
                  const float& row,
                  const string& varname,
                  const float& carea,
                  const int& year,
                  const int& total,
                  const string& contnent );


/* *************************************************************
                     Public Variables
************************************************************* */

     // area covered by grid cell (sq. km)
     float carea;

     // column or longitude of grid cell (degrees)
     float col;

     // name of continent containing grid cell
     string contnent;

     // row or latitude of grid cell (degrees)
     float row;

     // total number of cohorts in a grid cell
     int total;

     // "MAXNCHRT"
     string varname;

     // date represented by data
     int year;

  private:

/* *************************************************************
                      Private Variables
************************************************************* */

     int chrtend;
     long curpos;
     long lagpos;

};

#endif

