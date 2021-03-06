/**
 * @file DynamicStruct.h
 * @brief This file contains all dynamically allocated structures definition used by the orbit Simulator.
 * @author Giuseppe Romeo
 * @date Created:  Nov 15, 2005
 * 
 * $Header: /nfs/slac/g/glast/ground/cvs/ScienceTools-scons/orbitSim/orbitSim/DynamicStruct.h,v 1.3 2008/09/25 17:20:28 vernaleo Exp $
 */


#ifndef DynamicStruct_h
#define DynamicStruct_h

#include <vector>
//#include "functions.h"

//#define DEG2RAD 0.017453292519943295769


#ifdef __cplusplus
extern "C" {
#endif

#include "atFunctions.h"


  /**
   * @brief Structure that contains all ephemeredis information
   * 
   * This structure contains ephemeredis information 
   * 
   * @author Giuseppe Romeo
   * @date Created:  Nov 15, 2005
   * @date Last Modified:  Feb 08, 2006
   */

  //typedef struct EphemData {
struct EphemData {

  ///Default Constructor
  EphemData(): MJD(1), X(1), Y(1), Z(1), Lat(1), Long(1), Alt(1), VelRA(1), VelDEC(1) {};
  EphemData(int num):ent(num){
    MJD.resize(num);
    X.resize(num);
    Y.resize(num);
    Z.resize(num);
    Lat.resize(num);
    Long.resize(num);
    Alt.resize(num);
    VelRA.resize(num);
    VelDEC.resize(num);
  }
  ~EphemData(){
    MJD.clear();
    X.clear();
    Y.clear();
    Z.clear();
    Lat.clear();
    Long.clear();
    Alt.clear();
    VelRA.clear();
    VelDEC.clear();
  }

  void Print(int i){
    std::cout<<"MJD = "<<MJD.at(i)<<std::endl;
    std::cout<<"x = "<<X.at(i)<<std::endl;
    std::cout<<"y = "<<Y.at(i)<<std::endl;
  }

  /// time stamp in MJD format
  std::vector <double> MJD;
  /// array for the X position in EC system
  std::vector <double> X;
  /// array for the Y position in EC system
  std::vector <double> Y;
  /// array for the Z position in EC system
  std::vector <double> Z;
  /// array for the Latitude in EC system
  std::vector <double> Lat;
  /// array for the Longitude in EC system
  std::vector <double> Long;
  /// array for the Height in EC system
  std::vector <double> Alt;
  /// array for the velocity compenent in RA in EC system
  std::vector <double> VelRA;
  /// array for the velocity compenent in DEC in EC system
  std::vector <double> VelDEC;
  ///NOTE: better add Sun positon at here....
  //std::vector<double> 
  /// Ephemeredis Period, not used with the available Ephemeredis
  double Period, 
  /// SemiMajorAxis, not used with the available Ephemeredis
     SemiMajorAxis;
  /// Number of entries in each array
  int ent;
};



  /**
   * @brief Structure that contains all attitude information
   * 
   * This structure contains attitude information 
   * 
   * @author Giuseppe Romeo
   * @date Created:  Nov 15, 2005
   * @date Last Modified:  Feb 08, 2006
   */


  //typedef struct Attitude {
struct Attitude {

  /// Default Constructor
  Attitude(): mjd(1), X(1), Y(1), Z(1), SatRA(1), SatDEC(1), Xra(1), Xdec(1), Zra(1), Zdec(1), Lat(1), Lon(1), Hei(1), in_saa(1), in_occ(1){};

  Attitude(int size){
    this->Resize(size);
  }
  void Resize(int size){
    mjd.resize(size);
    X.resize(size);
    Y.resize(size);
    Z.resize(size);
    SatRA.resize(size);
    SatDEC.resize(size);
    Xra.resize(size);
    Xdec.resize(size);
    Yra.resize(size);
    Ydec.resize(size);
    Zra.resize(size);
    Zdec.resize(size);
    Lat.resize(size);
    Lon.resize(size);
    Hei.resize(size);
    in_saa.resize(size);
    in_occ.resize(size);
    ent = size;
  }
  ~Attitude(){
    mjd.clear();
    SatRA.clear();
    SatDEC.clear();
    Xra.clear();
    Xdec.clear();
    Yra.clear();
    Ydec.clear();
    Zra.clear();
    Zdec.clear();
    X.clear();
    Y.clear();
    Z.clear();
    Lat.clear();
    Lon.clear();
    Hei.clear();
    in_saa.clear();
    in_occ.clear();
  }


  /// mjd time stamp
  std::vector <double> mjd;

  /// X position in ECI
  std::vector <double> X;                                          
  /// Y position in ECI
  std::vector <double> Y;
  /// Z position in ECI
  std::vector <double> Z;
                 
  /// RA for Satellite position
  std::vector <double> SatRA;
  /// DEC for Satellite position
  std::vector <double> SatDEC;            
  /// RA for X-axis
  std::vector <double> Xra;
  /// DEC for X-axis
  std::vector <double> Xdec;                
  /// RA for Y-axis
  std::vector <double> Yra;
  /// DEC for Y-axis
  std::vector <double> Ydec;                
  /// RA for Z-axis
  std::vector <double> Zra;
  /// DEC for Z-axis
  std::vector <double>  Zdec;                
  /// Spacecraft Latitude
  std::vector <double> Lat;
  /// Spacecraft Longitude
  std::vector <double> Lon;
  /// Spacecraft Height
  std::vector <double> Hei;           

  /// Boolean to specify if spacecraft is in saa (1) or not (0)
  std::vector <int> in_saa;                       

  /// Boolean to specify if spacecraft is in occultation (1) or not (0)
  std::vector <int> in_occ;                       
                               
  void print()const
  {
    if(ent != mjd.size()){
      std::cout<<"events number error..."<<ent<<"\tsize = "<<mjd.size()<<std::endl;     
      return;
    }
    for(int i=0;i<ent;++i){
      std::cout<<"i "<<i<<"\tmjd = "<<mjd[i]<<"\t("<<SatRA[i]<<","<<SatDEC[i]<<")\t("<<Xra[i]<<","<<Xdec[i]<<")\t("<<Yra[i]<<","<<Ydec[i]<<")\t("<<Zra[i]<<","<<Zdec[i]<<std::endl;
    }
  }

  void print(int i)const
  {
    //for(int i=0;i<ent;++i){
      std::cout<<"i "<<i<<"\tmjd = "<<mjd[i]<<"\t("<<SatRA[i]<<","<<SatDEC[i]<<")\t("<<Xra[i]<<","<<Xdec[i]<<")\t("<<Yra[i]<<","<<Ydec[i]<<")\t("<<Zra[i]<<","<<Zdec[i]<<std::endl;
    //}
  }

  void copy(Attitude *r,int k)
  {
	mjd[k]    = r->mjd[k];
	SatRA[k]  = r->SatRA[k];
	SatDEC[k] = r->SatDEC[k];
	Xra[k]    = r->Xra[k];
	Xdec[k]   = r->Xdec[k];
	Yra[k]    = r->Yra[k];
	Ydec[k]   = r->Ydec[k];
	Zra[k]    = r->Zra[k];
	Zdec[k]   = r->Zdec[k];
  }

  double zOffset(int k)const
  {
    return angularSepDEG(SatRA[k],SatDEC[k],Zra[k],Zdec[k]);
  }

  void printOffset(int k)const
  {
    double xz=0,yz=0,xy=0;
    double s_x=0,s_y=0,s_z=0;
    xz = angularSepDEG(Xra[k],Xdec[k],Zra[k],Zdec[k]);
    yz = angularSepDEG(Yra[k],Ydec[k],Zra[k],Zdec[k]);
    xy = angularSepDEG(Xra[k],Xdec[k],Yra[k],Ydec[k]);
    s_x = angularSepDEG(SatRA[k],SatDEC[k],Xra[k],Xdec[k]);
    s_y = angularSepDEG(SatRA[k],SatDEC[k],Xra[k],Xdec[k]);
    s_z = angularSepDEG(SatRA[k],SatDEC[k],Xra[k],Xdec[k]);
    std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<")xz="<<xz<<"\tyz="<<yz<<"\txy="<<xy<<"\t\ts_x="<<s_x<<"\ts_y="<<s_y<<"\ts_z="<<s_z<<std::endl;
  }

  /// Number of entries in each array
  int ent;
};



#ifdef __cplusplus
}
#endif



#endif
