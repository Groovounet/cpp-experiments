#include "test_translation_table.hpp" 

#include <map>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <cstdlib>

namespace table
{
	enum enum5
	{
		ENUM5_A,
		ENUM5_B,
		ENUM5_C,
		ENUM5_D,
		ENUM5_E,
		ENUM5_COUNT
	};

	enum enum5_out
	{
		ENUM5_OUT_INVALID = -1,
		ENUM5_OUT_A = 16,
		ENUM5_OUT_B = 32,
		ENUM5_OUT_C = 48,
		ENUM5_OUT_D = 57,
		ENUM5_OUT_E = 48
	};

	enum5_out translate_table(enum5 Value)
	{
		static const enum5_out TranslationTable[] =
		{
			ENUM5_OUT_A,	// ENUM5_A
			ENUM5_OUT_B,	// ENUM5_B
			ENUM5_OUT_C,	// ENUM5_C
			ENUM5_OUT_D,	// ENUM5_D
			ENUM5_OUT_E,	// ENUM5_E
		};

		static_assert(
			sizeof(TranslationTable) / sizeof(enum5_out) == ENUM5_COUNT,
			"The translation table needs to be updated.");

		enum5_out Translation = TranslationTable[Value];
		assert(Translation != ENUM5_OUT_INVALID);
		return Translation;
	}

	enum5_out translate_switch(enum5 Value)
	{
		switch(Value)
		{
		default:
		case ENUM5_A:
			return ENUM5_OUT_A;
		case ENUM5_B:
			return ENUM5_OUT_B;
		case ENUM5_C:
			return ENUM5_OUT_C;
		case ENUM5_D:
			return ENUM5_OUT_C;
		case ENUM5_E:
			return ENUM5_OUT_C;
		}
	}

	typedef enum5_out (* translate5) (enum5 Value);



	enum enum10
	{
		ENUM10_A,
		ENUM10_B,
		ENUM10_C,
		ENUM10_D,
		ENUM10_E,
		ENUM10_F,
		ENUM10_G,
		ENUM10_H,
		ENUM10_I,
		ENUM10_J,
		ENUM10_COUNT
	};

	enum enum10_out
	{
		ENUM10_OUT_INVALID = -1,
		ENUM10_OUT_A = 16,
		ENUM10_OUT_B = 32,
		ENUM10_OUT_C = 48,
		ENUM10_OUT_D = 49,
		ENUM10_OUT_E = 50,
		ENUM10_OUT_F = 52,
		ENUM10_OUT_G = 54,
		ENUM10_OUT_H = 56,
		ENUM10_OUT_I = 59,
		ENUM10_OUT_J = 64
	};

	enum10_out translate_table(enum10 Value)
	{
		static const enum10_out TranslationTable[] =
		{
			ENUM10_OUT_A,	// ENUM10_A
			ENUM10_OUT_B,	// ENUM10_B
			ENUM10_OUT_C,	// ENUM10_C
			ENUM10_OUT_D,	// ENUM10_D
			ENUM10_OUT_E,	// ENUM10_E
			ENUM10_OUT_F,	// ENUM10_F
			ENUM10_OUT_G,	// ENUM10_G
			ENUM10_OUT_H,	// ENUM10_H
			ENUM10_OUT_I,	// ENUM10_I
			ENUM10_OUT_J	// ENUM10_J
		};

		static_assert(
			sizeof(TranslationTable) / sizeof(enum10_out) == ENUM10_COUNT,
			"The translation table needs to be updated.");

		enum10_out Translation = TranslationTable[Value];
		assert(Translation != ENUM10_OUT_INVALID);
		return Translation;
	}

	enum10_out translate_switch(enum10 Value)
	{
		switch(Value)
		{
		default:
		case ENUM10_A:
			return ENUM10_OUT_A;
		case ENUM10_B:
			return ENUM10_OUT_B;
		case ENUM10_C:
			return ENUM10_OUT_C;
		case ENUM10_D:
			return ENUM10_OUT_D;
		case ENUM10_E:
			return ENUM10_OUT_E;
		case ENUM10_F:
			return ENUM10_OUT_F;
		case ENUM10_G:
			return ENUM10_OUT_G;
		case ENUM10_H:
			return ENUM10_OUT_H;
		case ENUM10_I:
			return ENUM10_OUT_I;
		case ENUM10_J:
			return ENUM10_OUT_J;
		}
	}

	typedef enum10_out (* translate10) (enum10 Value);




	enum enum100
	{
		ENUM100_A0,
		ENUM100_B0,
		ENUM100_C0,
		ENUM100_D0,
		ENUM100_E0,
		ENUM100_F0,
		ENUM100_G0,
		ENUM100_H0,
		ENUM100_I0,
		ENUM100_J0,

		ENUM100_A1,
		ENUM100_B1,
		ENUM100_C1,
		ENUM100_D1,
		ENUM100_E1,
		ENUM100_F1,
		ENUM100_G1,
		ENUM100_H1,
		ENUM100_I1,
		ENUM100_J1,

		ENUM100_A2,
		ENUM100_B2,
		ENUM100_C2,
		ENUM100_D2,
		ENUM100_E2,
		ENUM100_F2,
		ENUM100_G2,
		ENUM100_H2,
		ENUM100_I2,
		ENUM100_J2,

		ENUM100_A3,
		ENUM100_B3,
		ENUM100_C3,
		ENUM100_D3,
		ENUM100_E3,
		ENUM100_F3,
		ENUM100_G3,
		ENUM100_H3,
		ENUM100_I3,
		ENUM100_J3,

		ENUM100_A4,
		ENUM100_B4,
		ENUM100_C4,
		ENUM100_D4,
		ENUM100_E4,
		ENUM100_F4,
		ENUM100_G4,
		ENUM100_H4,
		ENUM100_I4,
		ENUM100_J4,

		ENUM100_A5,
		ENUM100_B5,
		ENUM100_C5,
		ENUM100_D5,
		ENUM100_E5,
		ENUM100_F5,
		ENUM100_G5,
		ENUM100_H5,
		ENUM100_I5,
		ENUM100_J5,

		ENUM100_A6,
		ENUM100_B6,
		ENUM100_C6,
		ENUM100_D6,
		ENUM100_E6,
		ENUM100_F6,
		ENUM100_G6,
		ENUM100_H6,
		ENUM100_I6,
		ENUM100_J6,

		ENUM100_A7,
		ENUM100_B7,
		ENUM100_C7,
		ENUM100_D7,
		ENUM100_E7,
		ENUM100_F7,
		ENUM100_G7,
		ENUM100_H7,
		ENUM100_I7,
		ENUM100_J7,

		ENUM100_A8,
		ENUM100_B8,
		ENUM100_C8,
		ENUM100_D8,
		ENUM100_E8,
		ENUM100_F8,
		ENUM100_G8,
		ENUM100_H8,
		ENUM100_I8,
		ENUM100_J8,

		ENUM100_A9,
		ENUM100_B9,
		ENUM100_C9,
		ENUM100_D9,
		ENUM100_E9,
		ENUM100_F9,
		ENUM100_G9,
		ENUM100_H9,
		ENUM100_I9,
		ENUM100_J9,

		ENUM100_COUNT
	};

	enum enum100_out
	{
		ENUM100_OUT_INVALID = -1,

		ENUM100_OUT_A0 = 16,
		ENUM100_OUT_B0 = 32,
		ENUM100_OUT_C0 = 48,
		ENUM100_OUT_D0 = 49,
		ENUM100_OUT_E0 = 50,
		ENUM100_OUT_F0 = 52,
		ENUM100_OUT_G0 = 54,
		ENUM100_OUT_H0 = 56,
		ENUM100_OUT_I0 = 59,
		ENUM100_OUT_J0 = 64,

		ENUM100_OUT_A1 = 216,
		ENUM100_OUT_B1 = 232,
		ENUM100_OUT_C1 = 248,
		ENUM100_OUT_D1 = 249,
		ENUM100_OUT_E1 = 250,
		ENUM100_OUT_F1 = 252,
		ENUM100_OUT_G1 = 254,
		ENUM100_OUT_H1 = 256,
		ENUM100_OUT_I1 = 259,
		ENUM100_OUT_J1 = 264,

		ENUM100_OUT_A2 = 316,
		ENUM100_OUT_B2 = 332,
		ENUM100_OUT_C2 = 348,
		ENUM100_OUT_D2 = 349,
		ENUM100_OUT_E2 = 350,
		ENUM100_OUT_F2 = 352,
		ENUM100_OUT_G2 = 354,
		ENUM100_OUT_H2 = 356,
		ENUM100_OUT_I2 = 359,
		ENUM100_OUT_J2 = 364,

		ENUM100_OUT_A3 = 516,
		ENUM100_OUT_B3 = 532,
		ENUM100_OUT_C3 = 548,
		ENUM100_OUT_D3 = 549,
		ENUM100_OUT_E3 = 550,
		ENUM100_OUT_F3 = 552,
		ENUM100_OUT_G3 = 554,
		ENUM100_OUT_H3 = 556,
		ENUM100_OUT_I3 = 559,
		ENUM100_OUT_J3 = 564,

		ENUM100_OUT_A4 = 516,
		ENUM100_OUT_B4 = 532,
		ENUM100_OUT_C4 = 548,
		ENUM100_OUT_D4 = 549,
		ENUM100_OUT_E4 = 550,
		ENUM100_OUT_F4 = 552,
		ENUM100_OUT_G4 = 554,
		ENUM100_OUT_H4 = 556,
		ENUM100_OUT_I4 = 559,
		ENUM100_OUT_J4 = 564,

		ENUM100_OUT_A5 = 816,
		ENUM100_OUT_B5 = 832,
		ENUM100_OUT_C5 = 848,
		ENUM100_OUT_D5 = 849,
		ENUM100_OUT_E5 = 850,
		ENUM100_OUT_F5 = 852,
		ENUM100_OUT_G5 = 854,
		ENUM100_OUT_H5 = 856,
		ENUM100_OUT_I5 = 859,
		ENUM100_OUT_J5 = 864,

		ENUM100_OUT_A6 = 916,
		ENUM100_OUT_B6 = 932,
		ENUM100_OUT_C6 = 948,
		ENUM100_OUT_D6 = 949,
		ENUM100_OUT_E6 = 950,
		ENUM100_OUT_F6 = 952,
		ENUM100_OUT_G6 = 954,
		ENUM100_OUT_H6 = 956,
		ENUM100_OUT_I6 = 959,
		ENUM100_OUT_J6 = 964,

		ENUM100_OUT_A7 = 1016,
		ENUM100_OUT_B7 = 1032,
		ENUM100_OUT_C7 = 1048,
		ENUM100_OUT_D7 = 1049,
		ENUM100_OUT_E7 = 1050,
		ENUM100_OUT_F7 = 1052,
		ENUM100_OUT_G7 = 1054,
		ENUM100_OUT_H7 = 1056,
		ENUM100_OUT_I7 = 1059,
		ENUM100_OUT_J7 = 1064,

		ENUM100_OUT_A8 = 1216,
		ENUM100_OUT_B8 = 1232,
		ENUM100_OUT_C8 = 1248,
		ENUM100_OUT_D8 = 1249,
		ENUM100_OUT_E8 = 1250,
		ENUM100_OUT_F8 = 1252,
		ENUM100_OUT_G8 = 1254,
		ENUM100_OUT_H8 = 1256,
		ENUM100_OUT_I8 = 1259,
		ENUM100_OUT_J8 = 1264,

		ENUM100_OUT_A9 = 1516,
		ENUM100_OUT_B9 = 1532,
		ENUM100_OUT_C9 = 1548,
		ENUM100_OUT_D9 = 1549,
		ENUM100_OUT_E9 = 1550,
		ENUM100_OUT_F9 = 1552,
		ENUM100_OUT_G9 = 1554,
		ENUM100_OUT_H9 = 1556,
		ENUM100_OUT_I9 = 1559,
		ENUM100_OUT_J9 = 1564
	};

	enum100_out translate_table(enum100 Value)
	{
		static const enum100_out TranslationTable[] =
		{
			ENUM100_OUT_A0,	// ENUM10_A
			ENUM100_OUT_B0,	// ENUM10_B
			ENUM100_OUT_C0,	// ENUM10_C
			ENUM100_OUT_D0,	// ENUM10_D
			ENUM100_OUT_E0,	// ENUM10_E
			ENUM100_OUT_F0,	// ENUM10_F
			ENUM100_OUT_G0,	// ENUM10_G
			ENUM100_OUT_H0,	// ENUM10_H
			ENUM100_OUT_I0,	// ENUM10_I
			ENUM100_OUT_J0,	// ENUM10_J

			ENUM100_OUT_A1,	// ENUM10_A
			ENUM100_OUT_B1,	// ENUM10_B
			ENUM100_OUT_C1,	// ENUM10_C
			ENUM100_OUT_D1,	// ENUM10_D
			ENUM100_OUT_E1,	// ENUM10_E
			ENUM100_OUT_F1,	// ENUM10_F
			ENUM100_OUT_G1,	// ENUM10_G
			ENUM100_OUT_H1,	// ENUM10_H
			ENUM100_OUT_I1,	// ENUM10_I
			ENUM100_OUT_J1,	// ENUM10_J

			ENUM100_OUT_A2,	// ENUM10_A
			ENUM100_OUT_B2,	// ENUM10_B
			ENUM100_OUT_C2,	// ENUM10_C
			ENUM100_OUT_D2,	// ENUM10_D
			ENUM100_OUT_E2,	// ENUM10_E
			ENUM100_OUT_F2,	// ENUM10_F
			ENUM100_OUT_G2,	// ENUM10_G
			ENUM100_OUT_H2,	// ENUM10_H
			ENUM100_OUT_I2,	// ENUM10_I
			ENUM100_OUT_J2,	// ENUM10_J

			ENUM100_OUT_A3,	// ENUM10_A
			ENUM100_OUT_B3,	// ENUM10_B
			ENUM100_OUT_C3,	// ENUM10_C
			ENUM100_OUT_D3,	// ENUM10_D
			ENUM100_OUT_E3,	// ENUM10_E
			ENUM100_OUT_F3,	// ENUM10_F
			ENUM100_OUT_G3,	// ENUM10_G
			ENUM100_OUT_H3,	// ENUM10_H
			ENUM100_OUT_I3,	// ENUM10_I
			ENUM100_OUT_J3,	// ENUM10_J

			ENUM100_OUT_A4,	// ENUM10_A
			ENUM100_OUT_B4,	// ENUM10_B
			ENUM100_OUT_C4,	// ENUM10_C
			ENUM100_OUT_D4,	// ENUM10_D
			ENUM100_OUT_E4,	// ENUM10_E
			ENUM100_OUT_F4,	// ENUM10_F
			ENUM100_OUT_G4,	// ENUM10_G
			ENUM100_OUT_H4,	// ENUM10_H
			ENUM100_OUT_I4,	// ENUM10_I
			ENUM100_OUT_J4,	// ENUM10_J

			ENUM100_OUT_A5,	// ENUM10_A
			ENUM100_OUT_B5,	// ENUM10_B
			ENUM100_OUT_C5,	// ENUM10_C
			ENUM100_OUT_D5,	// ENUM10_D
			ENUM100_OUT_E5,	// ENUM10_E
			ENUM100_OUT_F5,	// ENUM10_F
			ENUM100_OUT_G5,	// ENUM10_G
			ENUM100_OUT_H5,	// ENUM10_H
			ENUM100_OUT_I5,	// ENUM10_I
			ENUM100_OUT_J5,	// ENUM10_J

			ENUM100_OUT_A6,	// ENUM10_A
			ENUM100_OUT_B6,	// ENUM10_B
			ENUM100_OUT_C6,	// ENUM10_C
			ENUM100_OUT_D6,	// ENUM10_D
			ENUM100_OUT_E6,	// ENUM10_E
			ENUM100_OUT_F6,	// ENUM10_F
			ENUM100_OUT_G6,	// ENUM10_G
			ENUM100_OUT_H6,	// ENUM10_H
			ENUM100_OUT_I6,	// ENUM10_I
			ENUM100_OUT_J6,	// ENUM10_J

			ENUM100_OUT_A7,	// ENUM10_A
			ENUM100_OUT_B7,	// ENUM10_B
			ENUM100_OUT_C7,	// ENUM10_C
			ENUM100_OUT_D7,	// ENUM10_D
			ENUM100_OUT_E7,	// ENUM10_E
			ENUM100_OUT_F7,	// ENUM10_F
			ENUM100_OUT_G7,	// ENUM10_G
			ENUM100_OUT_H7,	// ENUM10_H
			ENUM100_OUT_I7,	// ENUM10_I
			ENUM100_OUT_J7,	// ENUM10_J

			ENUM100_OUT_A8,	// ENUM10_A
			ENUM100_OUT_B8,	// ENUM10_B
			ENUM100_OUT_C8,	// ENUM10_C
			ENUM100_OUT_D8,	// ENUM10_D
			ENUM100_OUT_E8,	// ENUM10_E
			ENUM100_OUT_F8,	// ENUM10_F
			ENUM100_OUT_G8,	// ENUM10_G
			ENUM100_OUT_H8,	// ENUM10_H
			ENUM100_OUT_I8,	// ENUM10_I
			ENUM100_OUT_J8,	// ENUM10_J

			ENUM100_OUT_A9,	// ENUM10_A
			ENUM100_OUT_B9,	// ENUM10_B
			ENUM100_OUT_C9,	// ENUM10_C
			ENUM100_OUT_D9,	// ENUM10_D
			ENUM100_OUT_E9,	// ENUM10_E
			ENUM100_OUT_F9,	// ENUM10_F
			ENUM100_OUT_G9,	// ENUM10_G
			ENUM100_OUT_H9,	// ENUM10_H
			ENUM100_OUT_I9,	// ENUM10_I
			ENUM100_OUT_J9	// ENUM10_J
		};

		static_assert(
			sizeof(TranslationTable) / sizeof(enum100_out) == ENUM100_COUNT,
			"The translation table needs to be updated.");

		enum100_out Translation = TranslationTable[Value];
		assert(Translation != ENUM100_OUT_INVALID);
		return Translation;
	}

	enum100_out translate_switch(enum100 Value)
	{
		switch(Value)
		{
		default:
		case ENUM100_A0:
			return ENUM100_OUT_A0;
		case ENUM100_B0:
			return ENUM100_OUT_B0;
		case ENUM100_C0:
			return ENUM100_OUT_C0;
		case ENUM100_D0:
			return ENUM100_OUT_D0;
		case ENUM100_E0:
			return ENUM100_OUT_E0;
		case ENUM100_F0:
			return ENUM100_OUT_F0;
		case ENUM100_G0:
			return ENUM100_OUT_G0;
		case ENUM100_H0:
			return ENUM100_OUT_H0;
		case ENUM100_I0:
			return ENUM100_OUT_I0;
		case ENUM100_J0:
			return ENUM100_OUT_J0;

		case ENUM100_A1:
			return ENUM100_OUT_A1;
		case ENUM100_B1:
			return ENUM100_OUT_B1;
		case ENUM100_C1:
			return ENUM100_OUT_C1;
		case ENUM100_D1:
			return ENUM100_OUT_D1;
		case ENUM100_E1:
			return ENUM100_OUT_E1;
		case ENUM100_F1:
			return ENUM100_OUT_F1;
		case ENUM100_G1:
			return ENUM100_OUT_G1;
		case ENUM100_H1:
			return ENUM100_OUT_H1;
		case ENUM100_I1:
			return ENUM100_OUT_I1;
		case ENUM100_J1:
			return ENUM100_OUT_J1;

		case ENUM100_A2:
			return ENUM100_OUT_A2;
		case ENUM100_B2:
			return ENUM100_OUT_B2;
		case ENUM100_C2:
			return ENUM100_OUT_C2;
		case ENUM100_D2:
			return ENUM100_OUT_D2;
		case ENUM100_E2:
			return ENUM100_OUT_E2;
		case ENUM100_F2:
			return ENUM100_OUT_F2;
		case ENUM100_G2:
			return ENUM100_OUT_G2;
		case ENUM100_H2:
			return ENUM100_OUT_H2;
		case ENUM100_I2:
			return ENUM100_OUT_I2;
		case ENUM100_J2:
			return ENUM100_OUT_J2;

		case ENUM100_A3:
			return ENUM100_OUT_A3;
		case ENUM100_B3:
			return ENUM100_OUT_B3;
		case ENUM100_C3:
			return ENUM100_OUT_C3;
		case ENUM100_D3:
			return ENUM100_OUT_D3;
		case ENUM100_E3:
			return ENUM100_OUT_E3;
		case ENUM100_F3:
			return ENUM100_OUT_F3;
		case ENUM100_G3:
			return ENUM100_OUT_G3;
		case ENUM100_H3:
			return ENUM100_OUT_H3;
		case ENUM100_I3:
			return ENUM100_OUT_I3;
		case ENUM100_J3:
			return ENUM100_OUT_J3;

		case ENUM100_A4:
			return ENUM100_OUT_A4;
		case ENUM100_B4:
			return ENUM100_OUT_B4;
		case ENUM100_C4:
			return ENUM100_OUT_C4;
		case ENUM100_D4:
			return ENUM100_OUT_D4;
		case ENUM100_E4:
			return ENUM100_OUT_E4;
		case ENUM100_F4:
			return ENUM100_OUT_F4;
		case ENUM100_G4:
			return ENUM100_OUT_G4;
		case ENUM100_H4:
			return ENUM100_OUT_H4;
		case ENUM100_I4:
			return ENUM100_OUT_I4;
		case ENUM100_J4:
			return ENUM100_OUT_J4;

		case ENUM100_A5:
			return ENUM100_OUT_A5;
		case ENUM100_B5:
			return ENUM100_OUT_B5;
		case ENUM100_C5:
			return ENUM100_OUT_C5;
		case ENUM100_D5:
			return ENUM100_OUT_D5;
		case ENUM100_E5:
			return ENUM100_OUT_E5;
		case ENUM100_F5:
			return ENUM100_OUT_F5;
		case ENUM100_G5:
			return ENUM100_OUT_G5;
		case ENUM100_H5:
			return ENUM100_OUT_H5;
		case ENUM100_I5:
			return ENUM100_OUT_I5;
		case ENUM100_J5:
			return ENUM100_OUT_J5;

		case ENUM100_A6:
			return ENUM100_OUT_A6;
		case ENUM100_B6:
			return ENUM100_OUT_B6;
		case ENUM100_C6:
			return ENUM100_OUT_C6;
		case ENUM100_D6:
			return ENUM100_OUT_D6;
		case ENUM100_E6:
			return ENUM100_OUT_E6;
		case ENUM100_F6:
			return ENUM100_OUT_F6;
		case ENUM100_G6:
			return ENUM100_OUT_G6;
		case ENUM100_H6:
			return ENUM100_OUT_H6;
		case ENUM100_I6:
			return ENUM100_OUT_I6;
		case ENUM100_J6:
			return ENUM100_OUT_J6;

		case ENUM100_A7:
			return ENUM100_OUT_A7;
		case ENUM100_B7:
			return ENUM100_OUT_B7;
		case ENUM100_C7:
			return ENUM100_OUT_C7;
		case ENUM100_D7:
			return ENUM100_OUT_D7;
		case ENUM100_E7:
			return ENUM100_OUT_E7;
		case ENUM100_F7:
			return ENUM100_OUT_F7;
		case ENUM100_G7:
			return ENUM100_OUT_G7;
		case ENUM100_H7:
			return ENUM100_OUT_H7;
		case ENUM100_I7:
			return ENUM100_OUT_I7;
		case ENUM100_J7:
			return ENUM100_OUT_J7;

		case ENUM100_A8:
			return ENUM100_OUT_A8;
		case ENUM100_B8:
			return ENUM100_OUT_B8;
		case ENUM100_C8:
			return ENUM100_OUT_C8;
		case ENUM100_D8:
			return ENUM100_OUT_D8;
		case ENUM100_E8:
			return ENUM100_OUT_E8;
		case ENUM100_F8:
			return ENUM100_OUT_F8;
		case ENUM100_G8:
			return ENUM100_OUT_G8;
		case ENUM100_H8:
			return ENUM100_OUT_H8;
		case ENUM100_I8:
			return ENUM100_OUT_I8;
		case ENUM100_J8:
			return ENUM100_OUT_J8;

		case ENUM100_A9:
			return ENUM100_OUT_A9;
		case ENUM100_B9:
			return ENUM100_OUT_B9;
		case ENUM100_C9:
			return ENUM100_OUT_C9;
		case ENUM100_D9:
			return ENUM100_OUT_D9;
		case ENUM100_E9:
			return ENUM100_OUT_E9;
		case ENUM100_F9:
			return ENUM100_OUT_F9;
		case ENUM100_G9:
			return ENUM100_OUT_G9;
		case ENUM100_H9:
			return ENUM100_OUT_H9;
		case ENUM100_I9:
			return ENUM100_OUT_I9;
		case ENUM100_J9:
			return ENUM100_OUT_J9;
		}
	}

	typedef enum100_out (* translate100) (enum100 Value);

	template <typename ENUM_TYPE, int ENUM_COUNT>
	std::vector<ENUM_TYPE> generateLinearData(std::size_t const Count)
	{
		std::vector<ENUM_TYPE> Data(Count);
		for(std::size_t i = 0; i < Count; ++i)
			Data[i] = static_cast<ENUM_TYPE>(i % ENUM_COUNT);
		return Data;
	}

	template <typename ENUM_TYPE, int ENUM_COUNT>
	std::vector<ENUM_TYPE> generateUniformData(std::size_t const Count)
	{
		std::size_t const SectionCount = Count / ENUM_COUNT;
		std::vector<ENUM_TYPE> Data(Count);

		for(std::size_t i = 0; i < Count; ++i)
			Data[i] = static_cast<ENUM_TYPE>(i / SectionCount);

		return Data;
	}

	template <typename ENUM_TYPE, int ENUM_COUNT>
	std::vector<ENUM_TYPE> generateRandomData(std::size_t const Count)
	{
		std::vector<ENUM_TYPE> Data(Count);
		for(std::size_t i = 0; i < Count; ++i)
			Data[i] = static_cast<ENUM_TYPE>(std::rand() % ENUM_COUNT);
		return Data;
	}

	template <typename OUT_TYPE, int INVALID_VALUE, typename ENUM_TYPE, int ENUM_COUNT>
	std::clock_t exec5(std::vector<ENUM_TYPE> const & Tests, translate5 Translate)
	{
		int Error = 0;

		std::clock_t TimeStart = std::clock();

		for(std::size_t i = 0; i < Tests.size(); ++i)
		{
			OUT_TYPE Result = Translate(Tests[i]);
			Error += Result != INVALID_VALUE ? 0 : 1;
		}

		std::clock_t TimeEnd = std::clock();

		return Error ? 0 : TimeEnd - TimeStart;
	}

	template <typename OUT_TYPE, int INVALID_VALUE, typename ENUM_TYPE, int ENUM_COUNT>
	std::clock_t exec10(std::vector<ENUM_TYPE> const & Tests, translate10 Translate)
	{
		int Error = 0;

		std::clock_t TimeStart = std::clock();

		for(std::size_t i = 0; i < Tests.size(); ++i)
		{
			OUT_TYPE Result = Translate(Tests[i]);
			Error += Result != INVALID_VALUE ? 0 : 1;
		}

		std::clock_t TimeEnd = std::clock();

		return Error ? 0 : TimeEnd - TimeStart;
	}

	template <typename OUT_TYPE, int INVALID_VALUE, typename ENUM_TYPE, int ENUM_COUNT>
	std::clock_t exec100(std::vector<ENUM_TYPE> const & Tests, translate100 Translate)
	{
		int Error = 0;

		std::clock_t TimeStart = std::clock();

		for(std::size_t i = 0; i < Tests.size(); ++i)
		{
			OUT_TYPE Result = Translate(Tests[i]);
			Error += Result != INVALID_VALUE ? 0 : 1;
		}

		std::clock_t TimeEnd = std::clock();

		return Error ? 0 : TimeEnd - TimeStart;
	}
}//namespace table

void test_translation_table()
{
	std::size_t const Count = 10000000;

	// 5
	{
		std::clock_t Time = table::exec5<table::enum5_out, table::ENUM5_OUT_INVALID, table::enum5, table::ENUM5_COUNT>(
			table::generateUniformData<table::enum5, table::ENUM5_COUNT>(Count), 
			table::translate_table);

		std::printf("enum5(table, uniform) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec5<table::enum5_out, table::ENUM5_OUT_INVALID, table::enum5, table::ENUM5_COUNT>(
			table::generateLinearData<table::enum5, table::ENUM5_COUNT>(Count), 
			table::translate_table);

		std::printf("enum5(table, linear) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec5<table::enum5_out, table::ENUM5_OUT_INVALID, table::enum5, table::ENUM5_COUNT>(
			table::generateRandomData<table::enum5, table::ENUM5_COUNT>(Count), 
			table::translate_table);

		std::printf("enum5(table, random) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec5<table::enum5_out, table::ENUM5_OUT_INVALID, table::enum5, table::ENUM5_COUNT>(
			table::generateUniformData<table::enum5, table::ENUM5_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum5(switch, uniform) %ld clocks\n", Time);
	}


	{
		std::clock_t Time = table::exec5<table::enum5_out, table::ENUM5_OUT_INVALID, table::enum5, table::ENUM5_COUNT>(
			table::generateLinearData<table::enum5, table::ENUM5_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum5(switch, linear) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec5<table::enum5_out, table::ENUM5_OUT_INVALID, table::enum5, table::ENUM5_COUNT>(
			table::generateRandomData<table::enum5, table::ENUM5_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum5(switch, random) %ld clocks\n", Time);
	}


	// 10
	{
		std::clock_t Time = table::exec10<table::enum10_out, table::ENUM10_OUT_INVALID, table::enum10, table::ENUM10_COUNT>(
			table::generateUniformData<table::enum10, table::ENUM10_COUNT>(Count), 
			table::translate_table);

		std::printf("enum10(table, uniform) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec10<table::enum10_out, table::ENUM10_OUT_INVALID, table::enum10, table::ENUM10_COUNT>(
			table::generateLinearData<table::enum10, table::ENUM10_COUNT>(Count), 
			table::translate_table);

		std::printf("enum10(table, linear) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec10<table::enum10_out, table::ENUM10_OUT_INVALID, table::enum10, table::ENUM10_COUNT>(
			table::generateRandomData<table::enum10, table::ENUM10_COUNT>(Count), 
			table::translate_table);

		std::printf("enum10(table, random) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec10<table::enum10_out, table::ENUM10_OUT_INVALID, table::enum10, table::ENUM10_COUNT>(
			table::generateUniformData<table::enum10, table::ENUM10_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum10(switch, uniform) %ld clocks\n", Time);
	}


	{
		std::clock_t Time = table::exec10<table::enum10_out, table::ENUM10_OUT_INVALID, table::enum10, table::ENUM10_COUNT>(
			table::generateLinearData<table::enum10, table::ENUM10_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum10(switch, linear) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec10<table::enum10_out, table::ENUM10_OUT_INVALID, table::enum10, table::ENUM10_COUNT>(
			table::generateRandomData<table::enum10, table::ENUM10_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum10(switch, random) %ld clocks\n", Time);
	}


	// 100
	{
		std::clock_t Time = table::exec100<table::enum100_out, table::ENUM100_OUT_INVALID, table::enum100, table::ENUM100_COUNT>(
			table::generateUniformData<table::enum100, table::ENUM100_COUNT>(Count), 
			table::translate_table);

		std::printf("enum100(table, uniform) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec100<table::enum100_out, table::ENUM100_OUT_INVALID, table::enum100, table::ENUM100_COUNT>(
			table::generateLinearData<table::enum100, table::ENUM100_COUNT>(Count), 
			table::translate_table);

		std::printf("enum100(table, linear) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec100<table::enum100_out, table::ENUM100_OUT_INVALID, table::enum100, table::ENUM100_COUNT>(
			table::generateRandomData<table::enum100, table::ENUM100_COUNT>(Count), 
			table::translate_table);

		std::printf("enum100(table, random) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec100<table::enum100_out, table::ENUM100_OUT_INVALID, table::enum100, table::ENUM100_COUNT>(
			table::generateUniformData<table::enum100, table::ENUM100_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum100(switch, uniform) %ld clocks\n", Time);
	}


	{
		std::clock_t Time = table::exec100<table::enum100_out, table::ENUM100_OUT_INVALID, table::enum100, table::ENUM100_COUNT>(
			table::generateLinearData<table::enum100, table::ENUM100_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum100(switch, linear) %ld clocks\n", Time);
	}

	{
		std::clock_t Time = table::exec100<table::enum100_out, table::ENUM100_OUT_INVALID, table::enum100, table::ENUM100_COUNT>(
			table::generateRandomData<table::enum100, table::ENUM100_COUNT>(Count), 
			table::translate_switch);

		std::printf("enum100(switch, random) %ld clocks\n", Time);
	}

	return;
}
