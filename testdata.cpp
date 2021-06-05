#include "testdata.h"

#include <stdexcept>

namespace
{
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

	static const math::Rational _1aga[] = {
		math::Rational{ 3219, 1000 }, math::Rational{ -637, 1000 }, math::Rational{ 19462, 1000 }, math::Rational{ 2286, 1000 },
		math::Rational{ 4519, 1000 }, math::Rational{ 24, 1000 }, math::Rational{ 18980, 1000 }, math::Rational{ -828, 1000 },
		math::Rational{ 4163, 1000 }, math::Rational{ 1425, 1000 }, math::Rational{ 18481, 1000 }, math::Rational{ -810, 1000 },
		math::Rational{ 3190, 1000 }, math::Rational{ 1341, 1000 }, math::Rational{ 17330, 1000 }, math::Rational{ -170, 1000 },
		math::Rational{ 1962, 1000 }, math::Rational{ 991, 1000 }, math::Rational{ 18165, 1000 }, math::Rational{ 816, 1000 },
		math::Rational{ 2093, 1000 }, math::Rational{ 1952, 1000 }, math::Rational{ 19331, 1000 }, math::Rational{ 276, 1000 },
		math::Rational{ 5119, 1000 }, math::Rational{ -701, 1000 }, math::Rational{ 17908, 1000 }, math::Rational{ -490, 1000 },
		math::Rational{ 3517, 1000 }, math::Rational{ 2147, 1000 }, math::Rational{ 19514, 1000 }, math::Rational{ -207, 1000 },
		math::Rational{ 2970, 1000 }, math::Rational{ 2609, 1000 }, math::Rational{ 16719, 1000 }, math::Rational{ 552, 1000 },
		math::Rational{ 2107, 1000 }, math::Rational{ -398, 1000 }, math::Rational{ 18564, 1000 }, math::Rational{ 403, 1000 },
		math::Rational{ 2847, 1000 }, math::Rational{ 2618, 1000 }, math::Rational{ 15335, 1000 }, math::Rational{ 315, 1000 },
		math::Rational{ 1457, 1000 }, math::Rational{ 3124, 1000 }, math::Rational{ 14979, 1000 }, math::Rational{ 683, 1000 },
		math::Rational{ 1316, 1000 }, math::Rational{ 3291, 1000 }, math::Rational{ 13473, 1000 }, math::Rational{ 446, 1000 },
		math::Rational{ 2447, 1000 }, math::Rational{ 4155, 1000 }, math::Rational{ 12931, 1000 }, math::Rational{ 1324, 1000 },
		math::Rational{ 3795, 1000 }, math::Rational{ 3614, 1000 }, math::Rational{ 13394, 1000 }, math::Rational{ 112, 1000 },
		math::Rational{ 4956, 1000 }, math::Rational{ 4494, 1000 }, math::Rational{ 12982, 1000 }, math::Rational{ 253, 1000 },
		math::Rational{ 483, 1000 }, math::Rational{ 2217, 1000 }, math::Rational{ 15479, 1000 }, math::Rational{ 1316, 1000 },
		math::Rational{ 21, 1000 }, math::Rational{ 3962, 1000 }, math::Rational{ 13166, 1000 }, math::Rational{ 1522, 1000 },
		math::Rational{ 2311, 1000 }, math::Rational{ 5497, 1000 }, math::Rational{ 13395, 1000 }, math::Rational{ 248, 1000 },
		math::Rational{ 3830, 1000 }, math::Rational{ 3522, 1000 }, math::Rational{ 14827, 1000 }, math::Rational{ 591, 1000 },
		math::Rational{ 5150, 1000 }, math::Rational{ 4461, 1000 }, math::Rational{ 11576, 1000 }, math::Rational{ 635, 1000 },
		math::Rational{ -1057, 1000 }, math::Rational{ 3106, 1000 }, math::Rational{ 13132, 1000 }, math::Rational{ 191, 1000 },
		math::Rational{ -2280, 1000 }, math::Rational{ 3902, 1000 }, math::Rational{ 12650, 1000 }, math::Rational{ 1135, 1000 },
		math::Rational{ -3316, 1000 }, math::Rational{ 2893, 1000 }, math::Rational{ 12151, 1000 }, math::Rational{ 794, 1000 },
		math::Rational{ -2756, 1000 }, math::Rational{ 2092, 1000 }, math::Rational{ 11000, 1000 }, math::Rational{ 720, 1000 },
		math::Rational{ -1839, 1000 }, math::Rational{ 1204, 1000 }, math::Rational{ 11835, 1000 }, math::Rational{ -1172, 1000 },
		math::Rational{ -2737, 1000 }, math::Rational{ 837, 1000 }, math::Rational{ 13001, 1000 }, math::Rational{ -313, 1000 },
		math::Rational{ -1952, 1000 }, math::Rational{ 4784, 1000 }, math::Rational{ 11578, 1000 }, math::Rational{ 2082, 1000 },
		math::Rational{ -3617, 1000 }, math::Rational{ 1972, 1000 }, math::Rational{ 13184, 1000 }, math::Rational{ 653, 1000 },
		math::Rational{ -3744, 1000 }, math::Rational{ 1267, 1000 }, math::Rational{ 10389, 1000 }, math::Rational{ -413, 1000 },
		math::Rational{ -709, 1000 }, math::Rational{ 2024, 1000 }, math::Rational{ 12234, 1000 }, math::Rational{ -1747, 1000 },
		math::Rational{ -3690, 1000 }, math::Rational{ 1156, 1000 }, math::Rational{ 9005, 1000 }, math::Rational{ -1275, 1000 },
		math::Rational{ -3434, 1000 }, math::Rational{ -300, 1000 }, math::Rational{ 8649, 1000 }, math::Rational{ 441, 1000 },
		math::Rational{ -3508, 1000 }, math::Rational{ -506, 1000 }, math::Rational{ 7143, 1000 }, math::Rational{ 237, 1000 },
		math::Rational{ -4822, 1000 }, math::Rational{ 42, 1000 }, math::Rational{ 6601, 1000 }, math::Rational{ -2856, 1000 },
		math::Rational{ -5027, 1000 }, math::Rational{ 1480, 1000 }, math::Rational{ 7064, 1000 }, math::Rational{ 985, 1000 },
		math::Rational{ -6370, 1000 }, math::Rational{ 2045, 1000 }, math::Rational{ 6652, 1000 }, math::Rational{ 915, 1000 },
		math::Rational{ -2162, 1000 }, math::Rational{ -690, 1000 }, math::Rational{ 9149, 1000 }, math::Rational{ 1100, 1000 },
		math::Rational{ -3442, 1000 }, math::Rational{ -1963, 1000 }, math::Rational{ 6836, 1000 }, math::Rational{ -81, 1000 },
		math::Rational{ -5916, 1000 }, math::Rational{ -747, 1000 }, math::Rational{ 7065, 1000 }, math::Rational{ -2345, 1000 },
		math::Rational{ -4965, 1000 }, math::Rational{ 1556, 1000 }, math::Rational{ 8497, 1000 }, math::Rational{ 504, 1000 },
		math::Rational{ -6439, 1000 }, math::Rational{ 2230, 1000 }, math::Rational{ 5246, 1000 }, math::Rational{ 1451, 1000 },
		math::Rational{ -2161, 1000 }, math::Rational{ -2469, 1000 }, math::Rational{ 6802, 1000 }, math::Rational{ -1171, 1000 },
		math::Rational{ -2239, 1000 }, math::Rational{ -3925, 1000 }, math::Rational{ 6320, 1000 }, math::Rational{ -1434, 1000 },
		math::Rational{ -847, 1000 }, math::Rational{ -4318, 1000 }, math::Rational{ 5821, 1000 }, math::Rational{ 98, 1000 },
		math::Rational{ -434, 1000 }, math::Rational{ -3433, 1000 }, math::Rational{ 4670, 1000 }, math::Rational{ -1446, 1000 },
		math::Rational{ -123, 1000 }, math::Rational{ -2195, 1000 }, math::Rational{ 5505, 1000 }, math::Rational{ 182, 1000 },
		math::Rational{ 644, 1000 }, math::Rational{ -2789, 1000 }, math::Rational{ 6671, 1000 }, math::Rational{ 865, 1000 },
		math::Rational{ -3167, 1000 }, math::Rational{ -4083, 1000 }, math::Rational{ 5248, 1000 }, math::Rational{ -98, 1000 },
		math::Rational{ 101, 1000 }, math::Rational{ -4119, 1000 }, math::Rational{ 6854, 1000 }, math::Rational{ -1, 1000 },
		math::Rational{ 775, 1000 }, math::Rational{ -3876, 1000 }, math::Rational{ 4059, 1000 }, math::Rational{ 1061, 1000 },
		math::Rational{ -1398, 1000 }, math::Rational{ -1625, 1000 }, math::Rational{ 5904, 1000 }, math::Rational{ 230, 1000 },
		math::Rational{ 844, 1000 }, math::Rational{ -3774, 1000 }, math::Rational{ 2675, 1000 }, math::Rational{ 1313, 1000 },
		math::Rational{ 1977, 1000 }, math::Rational{ -2824, 1000 }, math::Rational{ 2319, 1000 }, math::Rational{ -112, 1000 },
		math::Rational{ 2192, 1000 }, math::Rational{ -2785, 1000 }, math::Rational{ 813, 1000 }, math::Rational{ -981, 1000 },
		math::Rational{ 2375, 1000 }, math::Rational{ -4197, 1000 }, math::Rational{ 271, 1000 }, math::Rational{ -355, 1000 },
		math::Rational{ 1232, 1000 }, math::Rational{ -5093, 1000 }, math::Rational{ 734, 1000 }, math::Rational{ 632, 1000 },
		math::Rational{ 1414, 1000 }, math::Rational{ -6539, 1000 }, math::Rational{ 322, 1000 }, math::Rational{ 576, 1000 },
		math::Rational{ 1678, 1000 }, math::Rational{ -1527, 1000 }, math::Rational{ 2819, 1000 }, math::Rational{ -1187, 1000 },
		math::Rational{ 3421, 1000 }, math::Rational{ -1999, 1000 }, math::Rational{ 496, 1000 }, math::Rational{ -1770, 1000 },
		math::Rational{ 3605, 1000 }, math::Rational{ -4750, 1000 }, math::Rational{ 735, 1000 }, math::Rational{ 1099, 1000 },
		math::Rational{ 1135, 1000 }, math::Rational{ -5078, 1000 }, math::Rational{ 2167, 1000 }, math::Rational{ 854, 1000 },
		math::Rational{ 1289, 1000 }, math::Rational{ -6691, 1000 }, math::Rational{ -1084, 1000 }, math::Rational{ -487, 1000 },
		math::Rational{ -1057, 1000 }, math::Rational{ 3106, 1000 }, math::Rational{ 22602, 1000 }, math::Rational{ -1297, 1000 },
		math::Rational{ -2280, 1000 }, math::Rational{ 3902, 1000 }, math::Rational{ 22120, 1000 }, math::Rational{ 376, 1000 },
		math::Rational{ -3316, 1000 }, math::Rational{ 2893, 1000 }, math::Rational{ 21621, 1000 }, math::Rational{ 932, 1000 },
		math::Rational{ -2756, 1000 }, math::Rational{ 2092, 1000 }, math::Rational{ 20470, 1000 }, math::Rational{ 1680, 1000 },
		math::Rational{ -1839, 1000 }, math::Rational{ 1204, 1000 }, math::Rational{ 21305, 1000 }, math::Rational{ 615, 1000 },
		math::Rational{ -2737, 1000 }, math::Rational{ 837, 1000 }, math::Rational{ 22471, 1000 }, math::Rational{ 899, 1000 },
		math::Rational{ -1952, 1000 }, math::Rational{ 4784, 1000 }, math::Rational{ 21048, 1000 }, math::Rational{ -521, 1000 },
		math::Rational{ -3617, 1000 }, math::Rational{ 1972, 1000 }, math::Rational{ 22654, 1000 }, math::Rational{ 133, 1000 },
		math::Rational{ -3744, 1000 }, math::Rational{ 1267, 1000 }, math::Rational{ 19859, 1000 }, math::Rational{ 81, 1000 },
		math::Rational{ -709, 1000 }, math::Rational{ 2024, 1000 }, math::Rational{ 21704, 1000 }, math::Rational{ 1420, 1000 },
		math::Rational{ -3690, 1000 }, math::Rational{ 1156, 1000 }, math::Rational{ 18475, 1000 }, math::Rational{ -850, 1000 },
		math::Rational{ -3434, 1000 }, math::Rational{ -300, 1000 }, math::Rational{ 18119, 1000 }, math::Rational{ -249, 1000 },
		math::Rational{ -3508, 1000 }, math::Rational{ -506, 1000 }, math::Rational{ 16613, 1000 }, math::Rational{ 1434, 1000 },
		math::Rational{ -4822, 1000 }, math::Rational{ 42, 1000 }, math::Rational{ 16071, 1000 }, math::Rational{ -2466, 1000 },
		math::Rational{ -5027, 1000 }, math::Rational{ 1480, 1000 }, math::Rational{ 16534, 1000 }, math::Rational{ -1045, 1000 },
		math::Rational{ -6370, 1000 }, math::Rational{ 2045, 1000 }, math::Rational{ 16122, 1000 }, math::Rational{ 1707, 1000 },
		math::Rational{ -2162, 1000 }, math::Rational{ -690, 1000 }, math::Rational{ 18619, 1000 }, math::Rational{ -2023, 1000 },
		math::Rational{ -3442, 1000 }, math::Rational{ -1963, 1000 }, math::Rational{ 16336, 1000 }, math::Rational{ -304, 1000 },
		math::Rational{ -5916, 1000 }, math::Rational{ -747, 1000 }, math::Rational{ 16535, 1000 }, math::Rational{ 979, 1000 },
		math::Rational{ -4965, 1000 }, math::Rational{ 1556, 1000 }, math::Rational{ 17967, 1000 }, math::Rational{ -1165, 1000 },
		math::Rational{ -6439, 1000 }, math::Rational{ 2230, 1000 }, math::Rational{ 14716, 1000 }, math::Rational{ 929, 1000 },
		math::Rational{ -2161, 1000 }, math::Rational{ -2469, 1000 }, math::Rational{ 16302, 1000 }, math::Rational{ -234, 1000 },
		math::Rational{ -2239, 1000 }, math::Rational{ -3925, 1000 }, math::Rational{ 15820, 1000 }, math::Rational{ -228, 1000 },
		math::Rational{ -847, 1000 }, math::Rational{ -4318, 1000 }, math::Rational{ 15321, 1000 }, math::Rational{ 1844, 1000 },
		math::Rational{ -434, 1000 }, math::Rational{ -3433, 1000 }, math::Rational{ 14170, 1000 }, math::Rational{ 1132, 1000 },
		math::Rational{ -123, 1000 }, math::Rational{ -2195, 1000 }, math::Rational{ 15005, 1000 }, math::Rational{ 211, 1000 },
		math::Rational{ 644, 1000 }, math::Rational{ -2789, 1000 }, math::Rational{ 16171, 1000 }, math::Rational{ -632, 1000 },
		math::Rational{ -3167, 1000 }, math::Rational{ -4083, 1000 }, math::Rational{ 14748, 1000 }, math::Rational{ -519, 1000 },
		math::Rational{ 101, 1000 }, math::Rational{ -4119, 1000 }, math::Rational{ 16354, 1000 }, math::Rational{ 173, 1000 },
		math::Rational{ 775, 1000 }, math::Rational{ -3876, 1000 }, math::Rational{ 13559, 1000 }, math::Rational{ 1243, 1000 },
		math::Rational{ -1398, 1000 }, math::Rational{ -1625, 1000 }, math::Rational{ 15404, 1000 }, math::Rational{ -187, 1000 },
		math::Rational{ 844, 1000 }, math::Rational{ -3774, 1000 }, math::Rational{ 12175, 1000 }, math::Rational{ -1332, 1000 },
		math::Rational{ 1977, 1000 }, math::Rational{ -2824, 1000 }, math::Rational{ 11819, 1000 }, math::Rational{ -1616, 1000 },
		math::Rational{ 2192, 1000 }, math::Rational{ -2785, 1000 }, math::Rational{ 10313, 1000 }, math::Rational{ 1320, 1000 },
		math::Rational{ 2375, 1000 }, math::Rational{ -4197, 1000 }, math::Rational{ 9771, 1000 }, math::Rational{ 237, 1000 },
		math::Rational{ 1232, 1000 }, math::Rational{ -5093, 1000 }, math::Rational{ 10234, 1000 }, math::Rational{ 851, 1000 },
		math::Rational{ 1414, 1000 }, math::Rational{ -6539, 1000 }, math::Rational{ 9822, 1000 }, math::Rational{ 1816, 1000 },
		math::Rational{ 1678, 1000 }, math::Rational{ -1527, 1000 }, math::Rational{ 12319, 1000 }, math::Rational{ -1657, 1000 },
		math::Rational{ 3421, 1000 }, math::Rational{ -1999, 1000 }, math::Rational{ 10036, 1000 }, math::Rational{ 1559, 1000 },
		math::Rational{ 3605, 1000 }, math::Rational{ -4750, 1000 }, math::Rational{ 10235, 1000 }, math::Rational{ 831, 1000 },
		math::Rational{ 1135, 1000 }, math::Rational{ -5078, 1000 }, math::Rational{ 11667, 1000 }, math::Rational{ 60, 1000 },
		math::Rational{ 1289, 1000 }, math::Rational{ -6691, 1000 }, math::Rational{ 8416, 1000 }, math::Rational{ 1066, 1000 },
		math::Rational{ 3219, 1000 }, math::Rational{ -637, 1000 }, math::Rational{ 10002, 1000 }, math::Rational{ 2111, 1000 },
		math::Rational{ 4519, 1000 }, math::Rational{ 24, 1000 }, math::Rational{ 9520, 1000 }, math::Rational{ -874, 1000 },
		math::Rational{ 4163, 1000 }, math::Rational{ 1425, 1000 }, math::Rational{ 9021, 1000 }, math::Rational{ -1012, 1000 },
		math::Rational{ 3190, 1000 }, math::Rational{ 1341, 1000 }, math::Rational{ 7870, 1000 }, math::Rational{ -250, 1000 },
		math::Rational{ 1962, 1000 }, math::Rational{ 991, 1000 }, math::Rational{ 8705, 1000 }, math::Rational{ -1359, 1000 },
		math::Rational{ 2093, 1000 }, math::Rational{ 1952, 1000 }, math::Rational{ 9871, 1000 }, math::Rational{ -126, 1000 },
		math::Rational{ 5119, 1000 }, math::Rational{ -701, 1000 }, math::Rational{ 8448, 1000 }, math::Rational{ 995, 1000 },
		math::Rational{ 3517, 1000 }, math::Rational{ 2147, 1000 }, math::Rational{ 10054, 1000 }, math::Rational{ 941, 1000 },
		math::Rational{ 2970, 1000 }, math::Rational{ 2609, 1000 }, math::Rational{ 7259, 1000 }, math::Rational{ -562, 1000 },
		math::Rational{ 2107, 1000 }, math::Rational{ -398, 1000 }, math::Rational{ 9104, 1000 }, math::Rational{ -38, 1000 },
		math::Rational{ 2847, 1000 }, math::Rational{ 2618, 1000 }, math::Rational{ 5875, 1000 }, math::Rational{ 398, 1000 },
		math::Rational{ 1457, 1000 }, math::Rational{ 3124, 1000 }, math::Rational{ 5519, 1000 }, math::Rational{ 481, 1000 },
		math::Rational{ 1316, 1000 }, math::Rational{ 3291, 1000 }, math::Rational{ 4013, 1000 }, math::Rational{ -187, 1000 },
		math::Rational{ 2447, 1000 }, math::Rational{ 4155, 1000 }, math::Rational{ 3471, 1000 }, math::Rational{ -429, 1000 },
		math::Rational{ 3795, 1000 }, math::Rational{ 3614, 1000 }, math::Rational{ 3934, 1000 }, math::Rational{ -432, 1000 },
		math::Rational{ 4956, 1000 }, math::Rational{ 4494, 1000 }, math::Rational{ 3522, 1000 }, math::Rational{ -788, 1000 },
		math::Rational{ 483, 1000 }, math::Rational{ 2217, 1000 }, math::Rational{ 6019, 1000 }, math::Rational{ -923, 1000 },
		math::Rational{ 21, 1000 }, math::Rational{ 3962, 1000 }, math::Rational{ 3636, 1000 }, math::Rational{ -316, 1000 },
		math::Rational{ 2311, 1000 }, math::Rational{ 5497, 1000 }, math::Rational{ 3935, 1000 }, math::Rational{ -1917, 1000 },
		math::Rational{ 3830, 1000 }, math::Rational{ 3522, 1000 }, math::Rational{ 5367, 1000 }, math::Rational{ -302, 1000 },
		math::Rational{ 5150, 1000 }, math::Rational{ 4461, 1000 }, math::Rational{ 2116, 1000 }, math::Rational{ -1615, 1000 }
	};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
}

unsigned int expp::TestData::getNumPoints() const
{
	return sizeof(_1aga) / (4 * sizeof(math::Rational));
}

math::Rational const * expp::TestData::getPoint(unsigned int i) const
{
	if (i >= getNumPoints()) return nullptr;
	return &_1aga[i * 4];
}

math::Rational expp::TestData::getReferenceEigenvalue(unsigned int D, unsigned int i) const
{
	switch (D) {
	case 2:
		switch (i) {
		case 0: return 9.62447289926297399961763301774251330057894539467032275382255;
		case 1: return 9.62430715969394210015560961264297422776572580714373620309355;
		}
		break;
	case 3:
		switch (i) {
		case 0: return 37.3274494274683425233695502581182052836449738530676689472257;
		case 1: return 9.62431434161498823505729817436585077939509766554969096873168;
		case 2: return 7.92550178622027216422369326567668971675332732240052872097887;
		}
		break;
	case 4:
		switch (i) {
		case 0: return 37.3477389918792213596879452204499702406947817221901007885630;
		case 1: return 9.62470688921105696017807313860277172063600080413412567999700;
		case 2: return 7.94017075281634999342344275928070533134615133171969063657713;
		case 3: return 1.06170863996588365446060186982477896078741484440002343404155;
		}
		break;
	}
	throw std::runtime_error("arguments wrong");
}

math::Rational expp::TestData::getReferenceEigenvector(unsigned int D, unsigned int i, unsigned int c) const
{
	switch (D) {
	case 2:
		switch (i) {
		case 0:
			switch (c) {
			case 0: return -0.503510847492551904906870957742619139443409162857537237123308;
			case 1: return 1;
			}
			break;
		case 1:
			switch (c) {
			case 0: return 1.98605453086051402895741763848787613048533838388005162794043;
			case 1: return 1;
			}
			break;
		}
		break;
	case 3:
		switch (i) {
		case 0:
			switch (c) {
			case 0: return -0.154972738414395866005286433008304444294405085038689821864654;
			case 1: return 0.193161285869815165989799191097521722568079378840201629578695;
			case 2: return 1;
			}
			break;
		case 1:
			switch (c) {
			case 0: return -158565.112775416943154745839952575022429933119522746586149868;
			case 1: return -127221.506282351944358932458687410410814983610301927832439675;
			case 2: return 1;
			}
			break;
		case 2:
			switch (c) {
			case 0: return 2.52702248596556806145700361724323960543858113426446460406536;
			case 1: return -3.14959802931313870497377546974185300816008580801457419079412;
			case 2: return 1;
			}
			break;
		}
		break;
	case 4:
		switch (i) {
		case 0:
			switch (c) {
			case 0: return -6.35322390281037045217295803597357821705371650876122113027264;
			case 1: return 7.91546394153385394517767054617789939529794642646629201212056;
			case 2: return 41.0301543819240679808549819457450130787045236815736490549663;
			case 3: return 1;
			}
			break;
		case 1:
			switch (c) {
			case 0: return -114.622418941087829756565311692197154422302604224781253861297;
			case 1: return -92.2070185807065289900871215218752013659402949497379896153118;
			case 2: return 0.0155846091025912430932734548933329458404665760587569100867246;
			case 3: return 1;
			}
			break;
		case 2:
			switch (c) {
			case 0: return 13.1771887761559019483954743159026938257325190511642952175789;
			case 1: return -16.3688257459634877666638419310116970616615816436949741766895;
			case 2: return 5.17386502341472097227408249233288958059579189051394773143190;
			case 3: return 1;
			}
			break;
		case 3:
			switch (c) {
			case 0: return -0.0192777078948229800494895064532553117703859768210647632969276;
			case 1: return 0.0348034950916108873629241563077465542944938906271231198634442;
			case 2: return -0.0340715609308469289267379681032545422644143611273049912226126;
			case 3: return 1;
			}
			break;
		}
		break;
	}
	throw std::runtime_error("arguments wrong");
}


/*

Ground truth covar matrix

	9.62434068027210898322 (8842363/918750)
	-0.00006657369614512471 (-29359/441000000)
	-4.29321376568405099761 (-1419980453/330750000)
	0.01879374187452758846 (49728241/2646000000)

	-0.00006657369614512471 (-29359/441000000)
	9.62443937868480681175 (2122188883/220500000)
	5.35113872637944076871 (1415911307/264600000)
	-0.11569259145880574080 (-306122597/2646000000)

	-4.29321376568405099761 (-1419980453/330750000)
	5.35113872637944076871 (1415911307/264600000)
	35.62848549634668415820 (28281891787/793800000)
	0.90874239254220201545 (901699639/992250000)

	0.01879374187452758846 (49728241/2646000000)
	-0.11569259145880574080 (-306122597/2646000000)
	0.90874239254220201545 (901699639/992250000)
	1.09705971856890904803 (4354230023/3969000000)


Wolfram alpha:
https://www.wolframalpha.com/input/?i=eigenvalue+%7B%7B-1%2C2%2C5%7D%2C%7B3%2F4%2C4%2C-12%2F2%7D%2C%7B7%2C-8%2C9%7D%7D


2x2

eigenvalues {{8842363/918750,-29359/441000000},{-29359/441000000,2122188883/220500000}}

l1 = ( 4244356003 + 5 * sqrt(53423162) ) / 441000000
l2 = ( 4244356003 - 5 * sqrt(53423162) ) / 441000000
v1 = {
	(21763 - 5 * sqrt(53423162)) / 29359,
	1
}
v2 = {
	(21763 + 5 * sqrt(53423162)) / 29359,
	1
}

λ_1≈9.62447
λ_2≈9.62431

v_1≈(-0.503511, 1)
v_2≈(1.98605, 1)


3x3

eigenvalues {{8842363/918750,-29359/441000000,-1419980453/330750000},{-29359/441000000,2122188883/220500000,1415911307/264600000},{-1419980453/330750000,1415911307/264600000,28281891787/793800000}}

exact forms no longer reasonable

λ_1≈37.3274
λ_2≈9.62431
λ_3≈7.9255

v_1≈(-0.154973, 0.193161, 1)
v_2≈(-158565., -127222., 1)
v_3≈(2.52702, -3.1496, 1)


4x4

Input not possible:
eigenvalues {{8842363/918750,-29359/441000000,-1419980453/330750000,49728241/2646000000},{-29359/441000000,2122188883/220500000,1415911307/264600000,-306122597/2646000000},{-1419980453/330750000,1415911307/264600000,28281891787/793800000,901699639/992250000},{49728241/2646000000,-306122597/2646000000,901699639/992250000,4354230023/3969000000}}

eigenvalues {{9.6243406,-0.0000665,-4.2932137,0.0187937},{-0.0000665,9.6244393,5.3511387,-0.1156925},{-4.2932137,5.3511387,35.6284854,0.9087423},{0.0187937,-0.1156925,0.9087423,1.0970597}}

λ_1≈37.3477
λ_2≈9.62471
λ_3≈7.94017
λ_4≈1.06171

v_1≈(-6.35322, 7.91546, 41.0302, 1)
v_2≈(-114.622, -92.2071, 0.015585, 1)
v_3≈(13.1772, -16.3688, 5.17387, 1)
v_4≈(-0.0192777, 0.0348035, -0.0340716, 1)


https://www.symbolab.com/solver/matrix-eigenvectors-calculator
eigenvectors\:\begin{pmatrix}\frac{8842363}{918750}&\frac{-29359}{441000000}\\ \frac{-29359}{441000000}&\frac{2122188883}{220500000}\end{pmatrix}



https://matrixcalc.org/en/vectors.html

https://matrixcalc.org/en/vectors.html#eigenvectors%28%7B%7B8842363/918750,-29359/441000000%7D,%7B-29359/441000000,2122188883/220500000%7D%7D%29

λ_1=9.62430715969394210015560961264297422776572580714373620309355
λ_2=9.62447289926297399961763301774251330057894539467032275382255

v_1=({{(1.98605453086051402895741763848787613048533838388005162794043)}, {1}})
v_2=({{(-0.503510847492551904906870957742619139443409162857537237123308)}, {1}})

https://matrixcalc.org/en/vectors.html#eigenvectors%28%7B%7B8842363/918750,-29359/441000000,-1419980453/330750000%7D,%7B-29359/441000000,2122188883/220500000,1415911307/264600000%7D,%7B-1419980453/330750000,1415911307/264600000,28281891787/793800000%7D%7D%29

λ_1≈7.92550178622027216422369326567668971675332732240052872097887
λ_2≈9.62431434161498823505729817436585077939509766554969096873168
λ_3≈37.3274494274683425233695502581182052836449738530676689472257

v_1≈({{(2.52702248596556806145700361724323960543858113426446460406536)}, {(-3.14959802931313870497377546974185300816008580801457419079412)}, {1}})
v_2≈({{(-158565.112775416943154745839952575022429933119522746586149868)}, {(-127221.506282351944358932458687410410814983610301927832439675)}, {1}})
v_3≈({{(-0.154972738414395866005286433008304444294405085038689821864654)}, {(0.193161285869815165989799191097521722568079378840201629578695)}, {1}})

https://matrixcalc.org/en/vectors.html#eigenvectors%28%7B%7B8842363/918750,-29359/441000000,-1419980453/330750000,49728241/2646000000%7D,%7B-29359/441000000,2122188883/220500000,1415911307/264600000,-306122597/2646000000%7D,%7B-1419980453/330750000,1415911307/264600000,28281891787/793800000,901699639/992250000%7D,%7B49728241/2646000000,-306122597/2646000000,901699639/992250000,4354230023/3969000000%7D%7D%29

λ_1≈1.06170863996588365446060186982477896078741484440002343404155
λ_2≈7.94017075281634999342344275928070533134615133171969063657713
λ_3≈9.62470688921105696017807313860277172063600080413412567999700
λ_4≈37.3477389918792213596879452204499702406947817221901007885630

v_1≈({{(-0.0192777078948229800494895064532553117703859768210647632969276)}, {(0.0348034950916108873629241563077465542944938906271231198634442)}, {(-0.0340715609308469289267379681032545422644143611273049912226126)}, {1}})
v_2≈({{(13.1771887761559019483954743159026938257325190511642952175789)}, {(-16.3688257459634877666638419310116970616615816436949741766895)}, {(5.17386502341472097227408249233288958059579189051394773143190)}, {1}})
v_3≈({{(-114.622418941087829756565311692197154422302604224781253861297)}, {(-92.2070185807065289900871215218752013659402949497379896153118)}, {(0.0155846091025912430932734548933329458404665760587569100867246)}, {1}})
v_4≈({{(-6.35322390281037045217295803597357821705371650876122113027264)}, {(7.91546394153385394517767054617789939529794642646629201212056)}, {(41.0301543819240679808549819457450130787045236815736490549663)}, {1}})

*/
