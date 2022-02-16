#include "gtest/gtest.h"
#include "DBManager.h"

namespace {
        void AddSampleEmployeeInfos(DBManager &manager) {
            ASSERT_EQ(manager.query("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,14130827,RPO JK,CL4,010-3231-1698,20090201,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,01122329,DN WD,CL4,010-7174-5680,20071117,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,12117017,LFIS JJIVL,CL1,010-7914-4067,20120812,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,11125777,TKOQKIS HC,CL1,010-6734-2289,19991001,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,PRO"), \
                "");
            ASSERT_EQ(manager.query("ADD, , , ,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO"), \
                "");
        }
}

TEST(DBManagerTest, NullTest) {
    DBManager manager;
    EXPECT_EQ(manager.query(""), "");
}

TEST(DBManagerTest, BasicDBTest) {
    DBManager manager;
    AddSampleEmployeeInfos(manager);
    ASSERT_EQ(manager.query("SCH,-p,-d, ,birthday,04"), \
        "SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\n");
    ASSERT_EQ(manager.query("MOD,-p, , ,name,FB NTAWR,birthday,20050520"), \
        "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO\n");
    ASSERT_EQ(manager.query("SCH, , , ,employeeNum,79110836"), \
        "SCH,NONE\n");
    ASSERT_EQ(manager.query("DEL, , , ,employeeNum,18115040"), \
        "DEL,1\n");
    ASSERT_EQ(manager.query("DEL,-p,-l, ,name,MPOSXU"), \
        "DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV\n");
    ASSERT_EQ(manager.query("SCH,-p, , ,certi,PRO"), \
        "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\n\
SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\n\
SCH,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO\n\
SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,08123556,WN XV,CL1,010-7986-5047,20100614,PRO\n");
    ASSERT_EQ(manager.query("SCH, , , ,certi,ADV"), \
        "SCH,6\n");
    ASSERT_EQ(manager.query("SCH,-p, , ,cl,CL4"), \
        "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\n\
SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\n\
SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\n\
SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV\n");
    ASSERT_EQ(manager.query("SCH, ,-m, ,birthday,09"), \
        "SCH,1\n");
    ASSERT_EQ(manager.query("MOD,-p, , ,name,FB NTAWR,cl,CL3"), \
        "MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO\n");
    ASSERT_EQ(manager.query("MOD,-p, , ,employeeNum,08123556,birthday,20110706"), \
        "MOD,08123556,WN XV,CL1,010-7986-5047,20100614,PRO\n");
    ASSERT_EQ(manager.query("SCH,-p,-y, ,birthday,2003"), \
        "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO\n");
    ASSERT_EQ(manager.query("SCH,-p, , ,employeeNum,05101762"), \
        "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n");
    ASSERT_EQ(manager.query("SCH,-p,-m, ,phoneNum,3112"), \
        "SCH,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV\n");
    ASSERT_EQ(manager.query("SCH,-p,-l, ,phoneNum,4605"), \
        "SCH,NONE\n");
    ASSERT_EQ(manager.query("SCH,-p, , ,employeeNum,10127115"), \
        "SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV\n");
    ASSERT_EQ(manager.query("MOD,-p, , ,phoneNum,010-8900-1478,certi,PRO"), \
        "MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV\n");
    ASSERT_EQ(manager.query("SCH, ,-f, ,name,LDEXRI"), \
        "SCH,NONE\n");
    ASSERT_EQ(manager.query("MOD, , , ,name,VCUHLE HMU,birthday,19910808"), \
        "MOD,1\n");
    ASSERT_EQ(manager.query("SCH, , , ,name,FB NTAWR"), \
        "SCH,1\n");
}

