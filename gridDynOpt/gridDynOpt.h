/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil;  eval: (c-set-offset 'innamespace 0); -*- */
/*
 * LLNS Copyright Start
 * Copyright (c) 2016, Lawrence Livermore National Security
 * This work was performed under the auspices of the U.S. Department
 * of Energy by Lawrence Livermore National Laboratory in part under
 * Contract W-7405-Eng-48 and in part under Contract DE-AC52-07NA27344.
 * Produced at the Lawrence Livermore National Laboratory.
 * All rights reserved.
 * For details, see the LICENSE file.
 * LLNS Copyright End
*/

#ifndef GRIDDYNOPT_H_
#define GRIDDYNOPT_H_

// debug
//#define DEBUG_IDA


// header files
#include "optimizerInterface.h"
#include "gridDyn.h"
// libraries
#include <list>
#include <fstream>
#include <cstdio>
#include <bitset>
#include <array>

//definitions for defining solution mode
enum optimization_type_t
{
  default_optimization, bidstack,
  water, DCOPF, ACOPF
};


//additional flags the controlFlags bitset
enum gdopt_flags
{


};

//for the status flags bitset


//extra local flags
enum gdopt_extra_flags
{

};

class optimData;
class gridAreaOpt;
class gridOptObject;

class gridDynOptimization : public gridDynSimulation
{
public:
protected:
  //storageSpace for sundials solverInterface
  std::vector<std::shared_ptr<optimizerInterface>> oData;
  gridAreaOpt *areaOpt = nullptr;
  std::string defaultOptMode;
  // ---------------solution mode-------------
  // total thread count

  //list of object to PreExecute
  int constraintCount = 0;
  optimization_type_t optimization_mode;
public:
  gridDynOptimization (const std::string &simName = "gridDynOptSim_#");
  ~gridDynOptimization ();
  gridCoreObject * clone (gridCoreObject *obj) const override;



  void setOptimizationMode (optimization_type_t omode)
  {
    if (omode != default_optimization)
      {
        optimization_mode = omode;
      }
  }
  virtual int set (const std::string &param,  const std::string &val) override;
  virtual int set (const std::string &param, double val, gridUnits::units_t unitType = gridUnits::defUnit) override;

  virtual double get (const std::string &param, gridUnits::units_t unitType = gridUnits::defUnit) const override;

  int setFlag (const std::string &flag, bool val = true) override;
  int setFlags (size_t param, int val);
  //void get(std::string param,int &val);
  //void get(std::string param, double &val);

  virtual gridCoreObject * find (const std::string &objname) const override;
  virtual gridCoreObject * getSubObject (const std::string &typeName, index_t num) const override;
  virtual gridCoreObject * findByUserID (const std::string &typeName, index_t searchID) const override;
  /** find the economic data for a corresponding grid core object
  @input gridCoreObject the object for which to find the corresponding econ Data
  */
  virtual gridOptObject * getOptData (gridCoreObject *obj = nullptr);
  virtual gridOptObject * makeOptObjectPath (gridCoreObject *obj);
protected:
  optimizerInterface * updateOptimizer (const optimMode &oMode);

  // SGS this was unused?
  // void updateOffsets (const optimMode &oMode);

  //void pFlowJacobian(const double state[]);
  optimizerInterface * getOptimizerData (const optimMode &oMode)
  {
    return (oData[oMode.offsetIndex].get ());
  }

  const optimizerInterface * getOptimizerData (const optimMode &oMode) const
  {
    return (oData[oMode.offsetIndex].get ());
  }

  void setMaxJacSize (const optimMode &oMode, count_t ssize)
  {
    oData[oMode.offsetIndex]->initializeJacArray (ssize);
  }
  // dynamics protected
  //void dynInitializeObjects(double initTime, double absInitTime);


  void setupOptOffsets (const optimMode &oMode, int setupMode);

};




#endif
