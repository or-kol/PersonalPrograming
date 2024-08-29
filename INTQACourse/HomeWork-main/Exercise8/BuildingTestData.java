package com.company;


public class BuildingTestData {

    static final int testCollectMoney_numOfResidents = 20;
    static final boolean testCollectMoney_buildingClean = true;
    static final boolean testCollectMoney_electricityWorking = true;
    static final float testCollectMoney_cashbox = 0;
    static final float testCollectMoney_expectedResult = 80 * testCollectMoney_numOfResidents;



    static final int testMaintainBuilding_noMoneyForCleaning_numOfResidents = 20;
    static final boolean testMaintainBuilding_noMoneyForCleaning_buildingClean = false;
    static final boolean testMaintainBuilding_noMoneyForCleaning_electricityWorking = false;
    static final float testMaintainBuilding_noMoneyForCleaning_cashbox = 50;
    static final boolean testMaintainBuilding_noMoneyForCleaning_expectedResult = false;



    static final int testMaintainBuilding_noMoneyForElectrician_numOfResidents = 20;
    static final boolean testMaintainBuilding_noMoneyForElectrician_buildingClean = false;
    static final boolean testMaintainBuilding_noMoneyForElectrician_electricityWorking = false;
    static final float testMaintainBuilding_noMoneyForElectrician_cashbox = 100;
    static final boolean testMaintainBuilding_noMoneyForElectrician_expectedResult = false;



    static final int testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_numOfResidents = 20;
    static final boolean testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_buildingClean = false;
    static final boolean testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_electricityWorking = true;
    static final float testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_cashbox = 1000;
    static final boolean testMaintainBuilding_enoughMoney_expectedResult = true;
    static final boolean testMaintainBuilding_isCleanTrue_expectedResult = true;
    static final float testMaintainBuilding_cashBoxUpdate_expectedResult = 900;



    static final int testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_numOfResidents = 20;
    static final boolean testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_buildingClean = true;
    static final boolean testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_electricityWorking = false;
    static final float testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_cashbox = 1000;
    static final boolean testMaintainBuilding_enoughMoney2_expectedResult = true;
    static final boolean testMaintainBuilding_IsElectricityTrue_expectedResult = true;
    static final float testMaintainBuilding_cashBoxUpdate2_expectedResult = 700;



}
