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

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "gridDyn.h"
#include "gridDynFileInput.h"
#include "testHelper.h"
#include "solvers/solverInterface.h"
#include "simulation/diagnostics.h"
#include <cstdio>
#include <iostream>


static std::string solverMode_test_directory = std::string(GRIDDYN_TEST_DIRECTORY "/solvermode_tests/");

BOOST_FIXTURE_TEST_SUITE (solverMode_tests, gridDynSimulationTestFixture)




BOOST_AUTO_TEST_SUITE_END()