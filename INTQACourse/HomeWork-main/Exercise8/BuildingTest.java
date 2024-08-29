package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class BuildingTest {

    @Test
    public void testCollectMoney() {
        Building building = new Building(BuildingTestData.testCollectMoney_numOfResidents, BuildingTestData.testCollectMoney_buildingClean,
                BuildingTestData.testCollectMoney_electricityWorking, BuildingTestData.testCollectMoney_cashbox);

        building.collectMoney();
        float actual_result = building.getM_cashbox();

        assertEquals(BuildingTestData.testCollectMoney_expectedResult, actual_result);
    }


    @Test
    public void testMaintainBuilding_noMoneyForCleaning() {
        Building building = new Building(BuildingTestData.testMaintainBuilding_noMoneyForCleaning_numOfResidents,
                BuildingTestData.testMaintainBuilding_noMoneyForCleaning_buildingClean,
                BuildingTestData.testMaintainBuilding_noMoneyForCleaning_electricityWorking,
                BuildingTestData.testMaintainBuilding_noMoneyForCleaning_cashbox);

        boolean actual_result = building.maintainBuilding();

        assertEquals(BuildingTestData.testMaintainBuilding_noMoneyForElectrician_expectedResult, actual_result);
    }


    @Test
    public void testMaintainBuilding_noMoneyForElectrician() {
        Building building = new Building(BuildingTestData.testMaintainBuilding_noMoneyForElectrician_numOfResidents,
                BuildingTestData.testMaintainBuilding_noMoneyForElectrician_buildingClean,
                BuildingTestData.testMaintainBuilding_noMoneyForElectrician_electricityWorking,
                BuildingTestData.testMaintainBuilding_noMoneyForElectrician_cashbox);

        boolean actual_result = building.maintainBuilding();

        assertEquals(BuildingTestData.testMaintainBuilding_noMoneyForElectrician_expectedResult, actual_result);
    }


    @Test
    public void testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate() {
        Building building = new Building(BuildingTestData.testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_numOfResidents,
                BuildingTestData.testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_buildingClean,
                BuildingTestData.testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_electricityWorking,
                BuildingTestData.testMaintainBuilding_enoughMoney_isCleanTrue_cashBoxUpdate_cashbox);

        boolean actual_result_enoughMoney = building.maintainBuilding();
        boolean actual_result_isCleanTrue = building.getM_is_building_clean();
        float actual_result_cashboxUpate = building.getM_cashbox();

        assertEquals(BuildingTestData.testMaintainBuilding_enoughMoney_expectedResult, actual_result_enoughMoney);
        assertEquals(BuildingTestData.testMaintainBuilding_isCleanTrue_expectedResult, actual_result_isCleanTrue);
        assertEquals(BuildingTestData.testMaintainBuilding_cashBoxUpdate_expectedResult, actual_result_cashboxUpate);
    }


    @Test
    public void testMaintainBuilding_enoughMoneyAndIsElectricityTrue() {
        Building building = new Building(BuildingTestData.testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_numOfResidents,
                BuildingTestData.testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_buildingClean,
                BuildingTestData.testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_electricityWorking,
                BuildingTestData.testMaintainBuilding_enoughMoney_isElectricityTrue_cashBoxUpdate_cashbox);

        boolean actual_result_enoughMoney = building.maintainBuilding();
        boolean actual_result_isElectricityTrue = building.getM_is_electricity_working();
        float actual_result_cashboxUpate = building.getM_cashbox();

        assertEquals(BuildingTestData.testMaintainBuilding_enoughMoney2_expectedResult, actual_result_enoughMoney);
        assertEquals(BuildingTestData.testMaintainBuilding_IsElectricityTrue_expectedResult, actual_result_isElectricityTrue);
        assertEquals(BuildingTestData.testMaintainBuilding_cashBoxUpdate2_expectedResult, actual_result_cashboxUpate);
    }







}
