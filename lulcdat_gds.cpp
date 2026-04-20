/* *************************************************************
LULCDAT_GDS.CPP - object to read and write the structure of
                   land use/land cover data from/to files

Modifications:

20060422 - DWK created by modifying lulcdat437.cpp
20060422 - DWK changed include from lulcdat437.h to lulcdat44.h
20060422 - DWK changed Lulcdata43:: to Lulcdata44::
20060422 - DWK added int disturbflag and int disturbmonth to
           functions
20070105 - TWC renamed to lulcdat45

************************************************************* */

#include<cstdio>

  using std::fscanf;
  using std::FILE;

#include<iostream>

  using std::ios;
  using std::endl;

#include<fstream>

  using std::ifstream;
  using std::ofstream;

#include<iomanip>

  using std::setprecision;

#include<string>

  using std::string;

#include<cstring>

  using std::memcpy;

#include "lulcdat_gds.h"


Lulcdat45::Lulcdat45( void )
{

  lulcend = 1;
  lagpos = -99;
  curpos = 0;

};

/* **************************************************************
                    Public Functions
************************************************************** */

/* *************************************************************
************************************************************* */

int Lulcdat45::get( ifstream& infile )
{

  lagpos = infile.tellg();

  infile >> col;
  infile >> row;
  infile >> varname;
  infile >> year;
  infile >> icohort;
  infile >> isrccohort;
  infile >> standage;
  infile >> chrtarea;
  infile >> potveg;
  infile >> currentveg;
  infile >> subtype;
  infile >> agstate;
  infile >> agprevstate;
  infile >> disturbflag;
  infile >> region;

  infile.seekg( 0, ios::cur );
  curpos = infile.tellg();

  if( curpos < (lagpos + 10) ) { lulcend = -1; }

  return lulcend;

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */
#define BUF_SIZE 100000
#define MAX_LINE_LENGTH 200

char buf[BUF_SIZE];
size_t indexr = BUF_SIZE;
size_t buf_end = BUF_SIZE;

int Lulcdat45::getdel( FILE* infile )
{
  char tmpvarname[40];
  char tmpregion[80];

    size_t bytes_in_buffer = buf_end - indexr;
    if (buf_end == BUF_SIZE && bytes_in_buffer < MAX_LINE_LENGTH) {
        memcpy(buf, buf + indexr, bytes_in_buffer);
        size_t bytes_read = fread(buf + bytes_in_buffer, 1, indexr, infile);
        buf_end = bytes_in_buffer + bytes_read;
        bytes_in_buffer = buf_end;
        indexr = 0;
    }
    if (bytes_in_buffer < 10) {
        return -1;
    }

lulcend = sscanf( buf + indexr,
                    "%f,%f, %s ,%d,%d,%d,%d,%f,%d,%d,%d,%d,%d,%d, %s",
                    &col,
                    &row,
                    tmpvarname,
                    &year,
                    &icohort,
                    &isrccohort,
                    &standage,
                    &chrtarea,
                    &potveg,
                    &currentveg,
                    &subtype,
                    &agstate,
                    &agprevstate,
                    &disturbflag,
                    tmpregion );

  varname = tmpvarname;
  region = tmpregion;

         while(indexr < BUF_SIZE) {
            if (buf[indexr++] == '\n')
         break;
         }

  return lulcend;

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

void Lulcdat45::out( ofstream& ofile,
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
                      const string& region )
{

  ofile.setf( ios::fixed,ios::floatfield );
  ofile.setf( ios::showpoint );
  ofile.precision( 1 );

  ofile << col << ' ';
  ofile << row << ' ';
  ofile << varname << ' ';
  ofile << year << ' ';
  ofile << icohort << ' ';
  ofile << isrccohort << ' ';
  ofile << standage << ' ';
  ofile << chrtarea << ' ';
  ofile << potveg << ' ';
  ofile << currentveg << ' ';
  ofile << subtype << ' ';
  ofile << agstate << ' ';
  ofile << agprevstate << ' ';
  ofile << disturbflag << ' ';
  ofile << region;
  ofile << endl;

};

/* *************************************************************
************************************************************* */


/* *************************************************************
************************************************************* */

void Lulcdat45::outdel( ofstream& ofile,
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
                         const string& region )
{

  ofile.setf( ios::fixed,ios::floatfield );
  ofile.setf( ios::showpoint );
  ofile.precision( 1 );

  ofile << setprecision(4) << col << ",";
  ofile << setprecision(4) << row << ", ";
  ofile << varname << " ,";
  ofile << year << ",";
  ofile << icohort << ",";
  ofile << isrccohort << ",";
  ofile << standage << ",";
  ofile << chrtarea << ",";
  ofile << potveg << ",";
  ofile << currentveg << ",";
  ofile << subtype << ",";
  ofile << agstate << ",";
  ofile << agprevstate << ",";
  ofile << disturbflag << ",";
  ofile << region;
  ofile << endl;

};

