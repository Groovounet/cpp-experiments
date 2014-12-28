#include "test_translation_table.hpp" 

#include <map>
#include <vector>
#include <array>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <cstdlib>

#define TABLE_QUALIFIER static const

namespace translation4
{
	enum index
	{
		INDEX_A = 0,
		INDEX_B,
		INDEX_C,
		INDEX_D,
		INDEX_COUNT
	};

	enum translated
	{
		TRANSLATED_A = 0xA0E7,
		TRANSLATED_B = 0x01C2,
		TRANSLATED_C = 0x2C35,
		TRANSLATED_D = 0x8AEF,
		TRANSLATED_COUNT = 4
	};

	translated const_table_translate(index Index)
	{
		const translated Table[] =
		{
			TRANSLATED_A,		// INDEX_A
			TRANSLATED_B,		// INDEX_B
			TRANSLATED_C,		// INDEX_C
			TRANSLATED_D		// INDEX_D
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	translated static_table_translate(index Index)
	{
		static const translated Table[] =
		{
			TRANSLATED_A,		// INDEX_A
			TRANSLATED_B,		// INDEX_B
			TRANSLATED_C,		// INDEX_C
			TRANSLATED_D		// INDEX_D
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	std::array<translated, INDEX_COUNT> g_Array;

	void array_table_init()
	{
		g_Array[INDEX_A] = TRANSLATED_A;
		g_Array[INDEX_B] = TRANSLATED_B;
		g_Array[INDEX_C] = TRANSLATED_C;
		g_Array[INDEX_D] = TRANSLATED_D;
	}

	translated array_table_translate(index Index)
	{
		return g_Array[Index];
	}

	std::vector<translated> g_Table;

	void dynamic_table_init()
	{
		g_Table.resize(INDEX_COUNT);
		g_Table[INDEX_A] = TRANSLATED_A;
		g_Table[INDEX_B] = TRANSLATED_B;
		g_Table[INDEX_C] = TRANSLATED_C;
		g_Table[INDEX_D] = TRANSLATED_D;
	}

	translated dynamic_table_translate(index Index)
	{
		assert(g_Table.size() == INDEX_COUNT);

		return g_Table[Index];
	}

	translated index_switch_translate(index Index)
	{
		switch(Index)
		{
		default:
		case INDEX_A: return TRANSLATED_A;
		case INDEX_B: return TRANSLATED_B;
		case INDEX_C: return TRANSLATED_C;
		case INDEX_D: return TRANSLATED_D;
		}
	}

	index value_switch_translate(translated Value)
	{
		switch(Value)
		{
		default:
		case TRANSLATED_A: return INDEX_A;
		case TRANSLATED_B: return INDEX_B;
		case TRANSLATED_C: return INDEX_C;
		case TRANSLATED_D: return INDEX_D;
		}
	}
}//namespace translation4

namespace translation8
{
	enum index
	{
		INDEX_A,
		INDEX_B,
		INDEX_C,
		INDEX_D,
		INDEX_E,
		INDEX_F,
		INDEX_G,
		INDEX_H,
		INDEX_COUNT
	};

	enum translated
	{
		TRANSLATED_A = 0xA0E7,
		TRANSLATED_B = 0x01C2,
		TRANSLATED_C = 0x2C35,
		TRANSLATED_D = 0x8AEF,
		TRANSLATED_E = 0xAF61,
		TRANSLATED_F = 0xC3FF,
		TRANSLATED_G = 0xFA12,
		TRANSLATED_H = 0x42B9,
		TRANSLATED_COUNT = 8
	};

	translated const_table_translate(index Index)
	{
		const translated Table[] =
		{
			TRANSLATED_A,		// INDEX_A
			TRANSLATED_B,		// INDEX_B
			TRANSLATED_C,		// INDEX_C
			TRANSLATED_D,		// INDEX_D
			TRANSLATED_E,		// INDEX_E
			TRANSLATED_F,		// INDEX_F
			TRANSLATED_G,		// INDEX_G
			TRANSLATED_H		// INDEX_H
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	translated static_table_translate(index Index)
	{
		static const translated Table[] =
		{
			TRANSLATED_A,		// INDEX_A
			TRANSLATED_B,		// INDEX_B
			TRANSLATED_C,		// INDEX_C
			TRANSLATED_D,		// INDEX_D
			TRANSLATED_E,		// INDEX_E
			TRANSLATED_F,		// INDEX_F
			TRANSLATED_G,		// INDEX_G
			TRANSLATED_H		// INDEX_H
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	std::array<translated, INDEX_COUNT> g_Array;

	void array_table_init()
	{
		g_Array[INDEX_A] = TRANSLATED_A;
		g_Array[INDEX_B] = TRANSLATED_B;
		g_Array[INDEX_C] = TRANSLATED_C;
		g_Array[INDEX_D] = TRANSLATED_D;
		g_Array[INDEX_E] = TRANSLATED_E;
		g_Array[INDEX_F] = TRANSLATED_F;
		g_Array[INDEX_G] = TRANSLATED_G;
		g_Array[INDEX_H] = TRANSLATED_H;
	}

	translated array_table_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		return g_Array[Index];
	}

	std::vector<translated> g_Table;

	void dynamic_table_init()
	{
		g_Table.resize(INDEX_COUNT);
		g_Table[INDEX_A] = TRANSLATED_A;
		g_Table[INDEX_B] = TRANSLATED_B;
		g_Table[INDEX_C] = TRANSLATED_C;
		g_Table[INDEX_D] = TRANSLATED_D;
		g_Table[INDEX_E] = TRANSLATED_E;
		g_Table[INDEX_F] = TRANSLATED_F;
		g_Table[INDEX_G] = TRANSLATED_G;
		g_Table[INDEX_H] = TRANSLATED_H;
	}

	translated dynamic_table_translate(index Index)
	{
		assert(g_Table.size() == INDEX_COUNT);
		assert(Index < INDEX_COUNT);

		return g_Table[Index];
	}

	translated index_switch_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		switch(Index)
		{
		default:
		case INDEX_A: return TRANSLATED_A;
		case INDEX_B: return TRANSLATED_B;
		case INDEX_C: return TRANSLATED_C;
		case INDEX_D: return TRANSLATED_D;
		case INDEX_E: return TRANSLATED_E;
		case INDEX_F: return TRANSLATED_F;
		case INDEX_G: return TRANSLATED_G;
		case INDEX_H: return TRANSLATED_H;
		}
	}

	index value_switch_translate(translated Value)
	{
		assert(Value < TRANSLATED_COUNT);

		switch(Value)
		{
		default:
		case TRANSLATED_A: return INDEX_A;
		case TRANSLATED_B: return INDEX_B;
		case TRANSLATED_C: return INDEX_C;
		case TRANSLATED_D: return INDEX_D;
		case TRANSLATED_E: return INDEX_E;
		case TRANSLATED_F: return INDEX_F;
		case TRANSLATED_G: return INDEX_G;
		case TRANSLATED_H: return INDEX_H;
		}
	}
}//namespace translation8

namespace translation16
{
	enum index
	{
		INDEX_A0,
		INDEX_B0,
		INDEX_C0,
		INDEX_D0,
		INDEX_E0,
		INDEX_F0,
		INDEX_G0,
		INDEX_H0,
		INDEX_A1,
		INDEX_B1,
		INDEX_C1,
		INDEX_D1,
		INDEX_E1,
		INDEX_F1,
		INDEX_G1,
		INDEX_H1,
		INDEX_COUNT
	};

	enum translated
	{
		TRANSLATED_A0 = 0xA0E7,
		TRANSLATED_B0 = 0x01C2,
		TRANSLATED_C0 = 0x2C35,
		TRANSLATED_D0 = 0x8AEF,
		TRANSLATED_E0 = 0xAF61,
		TRANSLATED_F0 = 0xC3FF,
		TRANSLATED_G0 = 0xFA12,
		TRANSLATED_H0 = 0x42B9,
		TRANSLATED_A1 = 0xB0E7,
		TRANSLATED_B1 = 0xB1C2,
		TRANSLATED_C1 = 0xBC35,
		TRANSLATED_D1 = 0xBAEF,
		TRANSLATED_E1 = 0xBF61,
		TRANSLATED_F1 = 0xB3FF,
		TRANSLATED_G1 = 0xBA12,
		TRANSLATED_H1 = 0xB2B9,
		TRANSLATED_COUNT = 16
	};

	translated const_table_translate(index Index)
	{
		const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1		// INDEX_H1
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	translated static_table_translate(index Index)
	{
		static const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1		// INDEX_H1
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	std::array<translated, INDEX_COUNT> g_Array;

	void array_table_init()
	{
		g_Array[INDEX_A0] = TRANSLATED_A0;
		g_Array[INDEX_B0] = TRANSLATED_B0;
		g_Array[INDEX_C0] = TRANSLATED_C0;
		g_Array[INDEX_D0] = TRANSLATED_D0;
		g_Array[INDEX_E0] = TRANSLATED_E0;
		g_Array[INDEX_F0] = TRANSLATED_F0;
		g_Array[INDEX_G0] = TRANSLATED_G0;
		g_Array[INDEX_H0] = TRANSLATED_H0;
		g_Array[INDEX_A1] = TRANSLATED_A1;
		g_Array[INDEX_B1] = TRANSLATED_B1;
		g_Array[INDEX_C1] = TRANSLATED_C1;
		g_Array[INDEX_D1] = TRANSLATED_D1;
		g_Array[INDEX_E1] = TRANSLATED_E1;
		g_Array[INDEX_F1] = TRANSLATED_F1;
		g_Array[INDEX_G1] = TRANSLATED_G1;
		g_Array[INDEX_H1] = TRANSLATED_H1;
	}

	translated array_table_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		return g_Array[Index];
	}

	std::vector<translated> g_Table;

	void dynamic_table_init()
	{
		g_Table.resize(INDEX_COUNT);
		g_Table[INDEX_A0] = TRANSLATED_A0;
		g_Table[INDEX_B0] = TRANSLATED_B0;
		g_Table[INDEX_C0] = TRANSLATED_C0;
		g_Table[INDEX_D0] = TRANSLATED_D0;
		g_Table[INDEX_E0] = TRANSLATED_E0;
		g_Table[INDEX_F0] = TRANSLATED_F0;
		g_Table[INDEX_G0] = TRANSLATED_G0;
		g_Table[INDEX_H0] = TRANSLATED_H0;
		g_Table[INDEX_A1] = TRANSLATED_A1;
		g_Table[INDEX_B1] = TRANSLATED_B1;
		g_Table[INDEX_C1] = TRANSLATED_C1;
		g_Table[INDEX_D1] = TRANSLATED_D1;
		g_Table[INDEX_E1] = TRANSLATED_E1;
		g_Table[INDEX_F1] = TRANSLATED_F1;
		g_Table[INDEX_G1] = TRANSLATED_G1;
		g_Table[INDEX_H1] = TRANSLATED_H1;
	}

	translated dynamic_table_translate(index Index)
	{
		assert(g_Table.size() == INDEX_COUNT);
		assert(Index < INDEX_COUNT);

		return g_Table[Index];
	}

	translated index_switch_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		switch(Index)
		{
		default:
		case INDEX_A0: return TRANSLATED_A0;
		case INDEX_B0: return TRANSLATED_B0;
		case INDEX_C0: return TRANSLATED_C0;
		case INDEX_D0: return TRANSLATED_D0;
		case INDEX_E0: return TRANSLATED_E0;
		case INDEX_F0: return TRANSLATED_F0;
		case INDEX_G0: return TRANSLATED_G0;
		case INDEX_H0: return TRANSLATED_H0;
		case INDEX_A1: return TRANSLATED_A1;
		case INDEX_B1: return TRANSLATED_B1;
		case INDEX_C1: return TRANSLATED_C1;
		case INDEX_D1: return TRANSLATED_D1;
		case INDEX_E1: return TRANSLATED_E1;
		case INDEX_F1: return TRANSLATED_F1;
		case INDEX_G1: return TRANSLATED_G1;
		case INDEX_H1: return TRANSLATED_H1;
		}
	}

	index value_switch_translate(translated Value)
	{
		assert(Value < TRANSLATED_COUNT);

		switch(Value)
		{
		default:
		case TRANSLATED_A0: return INDEX_A0;
		case TRANSLATED_B0: return INDEX_B0;
		case TRANSLATED_C0: return INDEX_C0;
		case TRANSLATED_D0: return INDEX_D0;
		case TRANSLATED_E0: return INDEX_E0;
		case TRANSLATED_F0: return INDEX_F0;
		case TRANSLATED_G0: return INDEX_G0;
		case TRANSLATED_H0: return INDEX_H0;
		case TRANSLATED_A1: return INDEX_A1;
		case TRANSLATED_B1: return INDEX_B1;
		case TRANSLATED_C1: return INDEX_C1;
		case TRANSLATED_D1: return INDEX_D1;
		case TRANSLATED_E1: return INDEX_E1;
		case TRANSLATED_F1: return INDEX_F1;
		case TRANSLATED_G1: return INDEX_G1;
		case TRANSLATED_H1: return INDEX_H1;
		}
	}
}//namespace translation16

namespace translation32
{
	enum index
	{
		INDEX_A0,
		INDEX_B0,
		INDEX_C0,
		INDEX_D0,
		INDEX_E0,
		INDEX_F0,
		INDEX_G0,
		INDEX_H0,
		INDEX_A1,
		INDEX_B1,
		INDEX_C1,
		INDEX_D1,
		INDEX_E1,
		INDEX_F1,
		INDEX_G1,
		INDEX_H1,
		INDEX_A2,
		INDEX_B2,
		INDEX_C2,
		INDEX_D2,
		INDEX_E2,
		INDEX_F2,
		INDEX_G2,
		INDEX_H2,
		INDEX_A3,
		INDEX_B3,
		INDEX_C3,
		INDEX_D3,
		INDEX_E3,
		INDEX_F3,
		INDEX_G3,
		INDEX_H3,
		INDEX_COUNT
	};

	enum translated
	{
		TRANSLATED_A0 = 0xA0E7,
		TRANSLATED_B0 = 0x01C2,
		TRANSLATED_C0 = 0x2C35,
		TRANSLATED_D0 = 0x8AEF,
		TRANSLATED_E0 = 0xAF61,
		TRANSLATED_F0 = 0xC3FF,
		TRANSLATED_G0 = 0xFA12,
		TRANSLATED_H0 = 0x42B9,
		TRANSLATED_A1 = 0xB0E7,
		TRANSLATED_B1 = 0xB1C2,
		TRANSLATED_C1 = 0xBC35,
		TRANSLATED_D1 = 0xBAEF,
		TRANSLATED_E1 = 0xBF61,
		TRANSLATED_F1 = 0xB3FF,
		TRANSLATED_G1 = 0xBA12,
		TRANSLATED_H1 = 0xB2B9,
		TRANSLATED_A2 = 0xC0E7,
		TRANSLATED_B2 = 0xC1C2,
		TRANSLATED_C2 = 0xCC35,
		TRANSLATED_D2 = 0xCAEF,
		TRANSLATED_E2 = 0xCF61,
		TRANSLATED_F2 = 0xCAFF,
		TRANSLATED_G2 = 0xCA12,
		TRANSLATED_H2 = 0xC2B9,
		TRANSLATED_A3 = 0xD0E7,
		TRANSLATED_B3 = 0xD1C2,
		TRANSLATED_C3 = 0xDC35,
		TRANSLATED_D3 = 0xDAEF,
		TRANSLATED_E3 = 0xDF61,
		TRANSLATED_F3 = 0xD3FF,
		TRANSLATED_G3 = 0xDA12,
		TRANSLATED_H3 = 0xD2B9,
		TRANSLATED_COUNT = 32
	};

	translated const_table_translate(index Index)
	{
		const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1,		// INDEX_H1
			TRANSLATED_A2,		// INDEX_A2
			TRANSLATED_B2,		// INDEX_B2
			TRANSLATED_C2,		// INDEX_C2
			TRANSLATED_D2,		// INDEX_D2
			TRANSLATED_E2,		// INDEX_E2
			TRANSLATED_F2,		// INDEX_F2
			TRANSLATED_G2,		// INDEX_G2
			TRANSLATED_H2,		// INDEX_H2
			TRANSLATED_A3,		// INDEX_A3
			TRANSLATED_B3,		// INDEX_B3
			TRANSLATED_C3,		// INDEX_C3
			TRANSLATED_D3,		// INDEX_D3
			TRANSLATED_E3,		// INDEX_E3
			TRANSLATED_F3,		// INDEX_F3
			TRANSLATED_G3,		// INDEX_G3
			TRANSLATED_H3		// INDEX_H3
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	translated static_table_translate(index Index)
	{
		static const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1,		// INDEX_H1
			TRANSLATED_A2,		// INDEX_A2
			TRANSLATED_B2,		// INDEX_B2
			TRANSLATED_C2,		// INDEX_C2
			TRANSLATED_D2,		// INDEX_D2
			TRANSLATED_E2,		// INDEX_E2
			TRANSLATED_F2,		// INDEX_F2
			TRANSLATED_G2,		// INDEX_G2
			TRANSLATED_H2,		// INDEX_H2
			TRANSLATED_A3,		// INDEX_A3
			TRANSLATED_B3,		// INDEX_B3
			TRANSLATED_C3,		// INDEX_C3
			TRANSLATED_D3,		// INDEX_D3
			TRANSLATED_E3,		// INDEX_E3
			TRANSLATED_F3,		// INDEX_F3
			TRANSLATED_G3,		// INDEX_G3
			TRANSLATED_H3		// INDEX_H3
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	std::array<translated, INDEX_COUNT> g_Array;

	void array_table_init()
	{
		g_Array[INDEX_A0] = TRANSLATED_A0;
		g_Array[INDEX_B0] = TRANSLATED_B0;
		g_Array[INDEX_C0] = TRANSLATED_C0;
		g_Array[INDEX_D0] = TRANSLATED_D0;
		g_Array[INDEX_E0] = TRANSLATED_E0;
		g_Array[INDEX_F0] = TRANSLATED_F0;
		g_Array[INDEX_G0] = TRANSLATED_G0;
		g_Array[INDEX_H0] = TRANSLATED_H0;
		g_Array[INDEX_A1] = TRANSLATED_A1;
		g_Array[INDEX_B1] = TRANSLATED_B1;
		g_Array[INDEX_C1] = TRANSLATED_C1;
		g_Array[INDEX_D1] = TRANSLATED_D1;
		g_Array[INDEX_E1] = TRANSLATED_E1;
		g_Array[INDEX_F1] = TRANSLATED_F1;
		g_Array[INDEX_G1] = TRANSLATED_G1;
		g_Array[INDEX_H1] = TRANSLATED_H1;
		g_Array[INDEX_A2] = TRANSLATED_A2;
		g_Array[INDEX_B2] = TRANSLATED_B2;
		g_Array[INDEX_C2] = TRANSLATED_C2;
		g_Array[INDEX_D2] = TRANSLATED_D2;
		g_Array[INDEX_E2] = TRANSLATED_E2;
		g_Array[INDEX_F2] = TRANSLATED_F2;
		g_Array[INDEX_G2] = TRANSLATED_G2;
		g_Array[INDEX_H2] = TRANSLATED_H2;
		g_Array[INDEX_A3] = TRANSLATED_A3;
		g_Array[INDEX_B3] = TRANSLATED_B3;
		g_Array[INDEX_C3] = TRANSLATED_C3;
		g_Array[INDEX_D3] = TRANSLATED_D3;
		g_Array[INDEX_E3] = TRANSLATED_E3;
		g_Array[INDEX_F3] = TRANSLATED_F3;
		g_Array[INDEX_G3] = TRANSLATED_G3;
		g_Array[INDEX_H3] = TRANSLATED_H3;
	}

	translated array_table_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		return g_Array[Index];
	}

	std::vector<translated> g_Table;

	void dynamic_table_init()
	{
		g_Table.resize(INDEX_COUNT);
		g_Table[INDEX_A0] = TRANSLATED_A0;
		g_Table[INDEX_B0] = TRANSLATED_B0;
		g_Table[INDEX_C0] = TRANSLATED_C0;
		g_Table[INDEX_D0] = TRANSLATED_D0;
		g_Table[INDEX_E0] = TRANSLATED_E0;
		g_Table[INDEX_F0] = TRANSLATED_F0;
		g_Table[INDEX_G0] = TRANSLATED_G0;
		g_Table[INDEX_H0] = TRANSLATED_H0;
		g_Table[INDEX_A1] = TRANSLATED_A1;
		g_Table[INDEX_B1] = TRANSLATED_B1;
		g_Table[INDEX_C1] = TRANSLATED_C1;
		g_Table[INDEX_D1] = TRANSLATED_D1;
		g_Table[INDEX_E1] = TRANSLATED_E1;
		g_Table[INDEX_F1] = TRANSLATED_F1;
		g_Table[INDEX_G1] = TRANSLATED_G1;
		g_Table[INDEX_H1] = TRANSLATED_H1;
		g_Table[INDEX_A2] = TRANSLATED_A2;
		g_Table[INDEX_B2] = TRANSLATED_B2;
		g_Table[INDEX_C2] = TRANSLATED_C2;
		g_Table[INDEX_D2] = TRANSLATED_D2;
		g_Table[INDEX_E2] = TRANSLATED_E2;
		g_Table[INDEX_F2] = TRANSLATED_F2;
		g_Table[INDEX_G2] = TRANSLATED_G2;
		g_Table[INDEX_H2] = TRANSLATED_H2;
		g_Table[INDEX_A3] = TRANSLATED_A3;
		g_Table[INDEX_B3] = TRANSLATED_B3;
		g_Table[INDEX_C3] = TRANSLATED_C3;
		g_Table[INDEX_D3] = TRANSLATED_D3;
		g_Table[INDEX_E3] = TRANSLATED_E3;
		g_Table[INDEX_F3] = TRANSLATED_F3;
		g_Table[INDEX_G3] = TRANSLATED_G3;
		g_Table[INDEX_H3] = TRANSLATED_H3;
	}

	translated dynamic_table_translate(index Index)
	{
		assert(g_Table.size() == INDEX_COUNT);
		assert(Index < INDEX_COUNT);

		return g_Table[Index];
	}

	translated index_switch_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		switch(Index)
		{
		default:
		case INDEX_A0: return TRANSLATED_A0;
		case INDEX_B0: return TRANSLATED_B0;
		case INDEX_C0: return TRANSLATED_C0;
		case INDEX_D0: return TRANSLATED_D0;
		case INDEX_E0: return TRANSLATED_E0;
		case INDEX_F0: return TRANSLATED_F0;
		case INDEX_G0: return TRANSLATED_G0;
		case INDEX_H0: return TRANSLATED_H0;
		case INDEX_A1: return TRANSLATED_A1;
		case INDEX_B1: return TRANSLATED_B1;
		case INDEX_C1: return TRANSLATED_C1;
		case INDEX_D1: return TRANSLATED_D1;
		case INDEX_E1: return TRANSLATED_E1;
		case INDEX_F1: return TRANSLATED_F1;
		case INDEX_G1: return TRANSLATED_G1;
		case INDEX_H1: return TRANSLATED_H1;
		case INDEX_A2: return TRANSLATED_A2;
		case INDEX_B2: return TRANSLATED_B2;
		case INDEX_C2: return TRANSLATED_C2;
		case INDEX_D2: return TRANSLATED_D2;
		case INDEX_E2: return TRANSLATED_E2;
		case INDEX_F2: return TRANSLATED_F2;
		case INDEX_G2: return TRANSLATED_G2;
		case INDEX_H2: return TRANSLATED_H2;
		case INDEX_A3: return TRANSLATED_A3;
		case INDEX_B3: return TRANSLATED_B3;
		case INDEX_C3: return TRANSLATED_C3;
		case INDEX_D3: return TRANSLATED_D3;
		case INDEX_E3: return TRANSLATED_E3;
		case INDEX_F3: return TRANSLATED_F3;
		case INDEX_G3: return TRANSLATED_G3;
		case INDEX_H3: return TRANSLATED_H3;
		}
	}

	index value_switch_translate(translated Value)
	{
		assert(Value < TRANSLATED_COUNT);

		switch(Value)
		{
		default:
		case TRANSLATED_A0: return INDEX_A0;
		case TRANSLATED_B0: return INDEX_B0;
		case TRANSLATED_C0: return INDEX_C0;
		case TRANSLATED_D0: return INDEX_D0;
		case TRANSLATED_E0: return INDEX_E0;
		case TRANSLATED_F0: return INDEX_F0;
		case TRANSLATED_G0: return INDEX_G0;
		case TRANSLATED_H0: return INDEX_H0;
		case TRANSLATED_A1: return INDEX_A1;
		case TRANSLATED_B1: return INDEX_B1;
		case TRANSLATED_C1: return INDEX_C1;
		case TRANSLATED_D1: return INDEX_D1;
		case TRANSLATED_E1: return INDEX_E1;
		case TRANSLATED_F1: return INDEX_F1;
		case TRANSLATED_G1: return INDEX_G1;
		case TRANSLATED_H1: return INDEX_H1;
		case TRANSLATED_A2: return INDEX_A2;
		case TRANSLATED_B2: return INDEX_B2;
		case TRANSLATED_C2: return INDEX_C2;
		case TRANSLATED_D2: return INDEX_D2;
		case TRANSLATED_E2: return INDEX_E2;
		case TRANSLATED_F2: return INDEX_F2;
		case TRANSLATED_G2: return INDEX_G2;
		case TRANSLATED_H2: return INDEX_H2;
		case TRANSLATED_A3: return INDEX_A3;
		case TRANSLATED_B3: return INDEX_B3;
		case TRANSLATED_C3: return INDEX_C3;
		case TRANSLATED_D3: return INDEX_D3;
		case TRANSLATED_E3: return INDEX_E3;
		case TRANSLATED_F3: return INDEX_F3;
		case TRANSLATED_G3: return INDEX_G3;
		case TRANSLATED_H3: return INDEX_H3;
		}
	}
}//namespace translation32

namespace translation64
{
	enum index
	{
		INDEX_A0,
		INDEX_B0,
		INDEX_C0,
		INDEX_D0,
		INDEX_E0,
		INDEX_F0,
		INDEX_G0,
		INDEX_H0,
		INDEX_A1,
		INDEX_B1,
		INDEX_C1,
		INDEX_D1,
		INDEX_E1,
		INDEX_F1,
		INDEX_G1,
		INDEX_H1,
		INDEX_A2,
		INDEX_B2,
		INDEX_C2,
		INDEX_D2,
		INDEX_E2,
		INDEX_F2,
		INDEX_G2,
		INDEX_H2,
		INDEX_A3,
		INDEX_B3,
		INDEX_C3,
		INDEX_D3,
		INDEX_E3,
		INDEX_F3,
		INDEX_G3,
		INDEX_H3,
		INDEX_A4,
		INDEX_B4,
		INDEX_C4,
		INDEX_D4,
		INDEX_E4,
		INDEX_F4,
		INDEX_G4,
		INDEX_H4,
		INDEX_A5,
		INDEX_B5,
		INDEX_C5,
		INDEX_D5,
		INDEX_E5,
		INDEX_F5,
		INDEX_G5,
		INDEX_H5,
		INDEX_A6,
		INDEX_B6,
		INDEX_C6,
		INDEX_D6,
		INDEX_E6,
		INDEX_F6,
		INDEX_G6,
		INDEX_H6,
		INDEX_A7,
		INDEX_B7,
		INDEX_C7,
		INDEX_D7,
		INDEX_E7,
		INDEX_F7,
		INDEX_G7,
		INDEX_H7,
		INDEX_COUNT
	};

	enum translated
	{
		TRANSLATED_A0 = 0xA0E7,
		TRANSLATED_B0 = 0x01C2,
		TRANSLATED_C0 = 0x2C35,
		TRANSLATED_D0 = 0x8AEF,
		TRANSLATED_E0 = 0xAF61,
		TRANSLATED_F0 = 0xC3FF,
		TRANSLATED_G0 = 0xFA12,
		TRANSLATED_H0 = 0x42B9,
		TRANSLATED_A1 = 0xB0E7,
		TRANSLATED_B1 = 0xB1C2,
		TRANSLATED_C1 = 0xBC35,
		TRANSLATED_D1 = 0xBAEF,
		TRANSLATED_E1 = 0xBF61,
		TRANSLATED_F1 = 0xB3FF,
		TRANSLATED_G1 = 0xBA12,
		TRANSLATED_H1 = 0xB2B9,
		TRANSLATED_A2 = 0xC0E7,
		TRANSLATED_B2 = 0xC1C2,
		TRANSLATED_C2 = 0xCC35,
		TRANSLATED_D2 = 0xCAEF,
		TRANSLATED_E2 = 0xCF61,
		TRANSLATED_F2 = 0xCAFF,
		TRANSLATED_G2 = 0xCA12,
		TRANSLATED_H2 = 0xC2B9,
		TRANSLATED_A3 = 0xD0E7,
		TRANSLATED_B3 = 0xD1C2,
		TRANSLATED_C3 = 0xDC35,
		TRANSLATED_D3 = 0xDAEF,
		TRANSLATED_E3 = 0xDF61,
		TRANSLATED_F3 = 0xD3FF,
		TRANSLATED_G3 = 0xDA12,
		TRANSLATED_H3 = 0xD2B9,
		TRANSLATED_A4 = 0xA0A7,
		TRANSLATED_B4 = 0x01A2,
		TRANSLATED_C4 = 0x2CA5,
		TRANSLATED_D4 = 0x8AAF,
		TRANSLATED_E4 = 0xAFA1,
		TRANSLATED_F4 = 0xC3AF,
		TRANSLATED_G4 = 0xFAA2,
		TRANSLATED_H4 = 0x42A9,
		TRANSLATED_A5 = 0xB0B7,
		TRANSLATED_B5 = 0xB1B2,
		TRANSLATED_C5 = 0xBCB5,
		TRANSLATED_D5 = 0xBABF,
		TRANSLATED_E5 = 0xBFB1,
		TRANSLATED_F5 = 0xB3BF,
		TRANSLATED_G5 = 0xBAB2,
		TRANSLATED_H5 = 0xB2BB,
		TRANSLATED_A6 = 0xC0C7,
		TRANSLATED_B6 = 0xC1CC,
		TRANSLATED_C6 = 0xCCC5,
		TRANSLATED_D6 = 0xCBCF,
		TRANSLATED_E6 = 0xCFC1,
		TRANSLATED_F6 = 0xCACF,
		TRANSLATED_G6 = 0xCAC2,
		TRANSLATED_H6 = 0xC2C9,
		TRANSLATED_A7 = 0xD0D7,
		TRANSLATED_B7 = 0xD1D2,
		TRANSLATED_C7 = 0xDCD5,
		TRANSLATED_D7 = 0xDADF,
		TRANSLATED_E7 = 0xDFD1,
		TRANSLATED_F7 = 0xD3DF,
		TRANSLATED_G7 = 0xDAD2,
		TRANSLATED_H7 = 0xD2D9,
		TRANSLATED_COUNT = 64
	};

	translated const_table_translate(index Index)
	{
		const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1,		// INDEX_H1
			TRANSLATED_A2,		// INDEX_A2
			TRANSLATED_B2,		// INDEX_B2
			TRANSLATED_C2,		// INDEX_C2
			TRANSLATED_D2,		// INDEX_D2
			TRANSLATED_E2,		// INDEX_E2
			TRANSLATED_F2,		// INDEX_F2
			TRANSLATED_G2,		// INDEX_G2
			TRANSLATED_H2,		// INDEX_H2
			TRANSLATED_A3,		// INDEX_A3
			TRANSLATED_B3,		// INDEX_B3
			TRANSLATED_C3,		// INDEX_C3
			TRANSLATED_D3,		// INDEX_D3
			TRANSLATED_E3,		// INDEX_E3
			TRANSLATED_F3,		// INDEX_F3
			TRANSLATED_G3,		// INDEX_G3
			TRANSLATED_H3,		// INDEX_H3

			TRANSLATED_A4,		// INDEX_A4
			TRANSLATED_B4,		// INDEX_B4
			TRANSLATED_C4,		// INDEX_C4
			TRANSLATED_D4,		// INDEX_D4
			TRANSLATED_E4,		// INDEX_E4
			TRANSLATED_F4,		// INDEX_F4
			TRANSLATED_G4,		// INDEX_G4
			TRANSLATED_H4,		// INDEX_H4
			TRANSLATED_A5,		// INDEX_A5
			TRANSLATED_B5,		// INDEX_B5
			TRANSLATED_C5,		// INDEX_C5
			TRANSLATED_D5,		// INDEX_D5
			TRANSLATED_E5,		// INDEX_E5
			TRANSLATED_F5,		// INDEX_F5
			TRANSLATED_G5,		// INDEX_G5
			TRANSLATED_H5,		// INDEX_H5
			TRANSLATED_A6,		// INDEX_A6
			TRANSLATED_B6,		// INDEX_B6
			TRANSLATED_C6,		// INDEX_C6
			TRANSLATED_D6,		// INDEX_D6
			TRANSLATED_E6,		// INDEX_E6
			TRANSLATED_F6,		// INDEX_F6
			TRANSLATED_G6,		// INDEX_G6
			TRANSLATED_H6,		// INDEX_H6
			TRANSLATED_A7,		// INDEX_A7
			TRANSLATED_B7,		// INDEX_B7
			TRANSLATED_C7,		// INDEX_C7
			TRANSLATED_D7,		// INDEX_D7
			TRANSLATED_E7,		// INDEX_E7
			TRANSLATED_F7,		// INDEX_F7
			TRANSLATED_G7,		// INDEX_G7
			TRANSLATED_H7		// INDEX_H7
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	translated static_table_translate(index Index)
	{
		static const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1,		// INDEX_H1
			TRANSLATED_A2,		// INDEX_A2
			TRANSLATED_B2,		// INDEX_B2
			TRANSLATED_C2,		// INDEX_C2
			TRANSLATED_D2,		// INDEX_D2
			TRANSLATED_E2,		// INDEX_E2
			TRANSLATED_F2,		// INDEX_F2
			TRANSLATED_G2,		// INDEX_G2
			TRANSLATED_H2,		// INDEX_H2
			TRANSLATED_A3,		// INDEX_A3
			TRANSLATED_B3,		// INDEX_B3
			TRANSLATED_C3,		// INDEX_C3
			TRANSLATED_D3,		// INDEX_D3
			TRANSLATED_E3,		// INDEX_E3
			TRANSLATED_F3,		// INDEX_F3
			TRANSLATED_G3,		// INDEX_G3
			TRANSLATED_H3,		// INDEX_H3

			TRANSLATED_A4,		// INDEX_A4
			TRANSLATED_B4,		// INDEX_B4
			TRANSLATED_C4,		// INDEX_C4
			TRANSLATED_D4,		// INDEX_D4
			TRANSLATED_E4,		// INDEX_E4
			TRANSLATED_F4,		// INDEX_F4
			TRANSLATED_G4,		// INDEX_G4
			TRANSLATED_H4,		// INDEX_H4
			TRANSLATED_A5,		// INDEX_A5
			TRANSLATED_B5,		// INDEX_B5
			TRANSLATED_C5,		// INDEX_C5
			TRANSLATED_D5,		// INDEX_D5
			TRANSLATED_E5,		// INDEX_E5
			TRANSLATED_F5,		// INDEX_F5
			TRANSLATED_G5,		// INDEX_G5
			TRANSLATED_H5,		// INDEX_H5
			TRANSLATED_A6,		// INDEX_A6
			TRANSLATED_B6,		// INDEX_B6
			TRANSLATED_C6,		// INDEX_C6
			TRANSLATED_D6,		// INDEX_D6
			TRANSLATED_E6,		// INDEX_E6
			TRANSLATED_F6,		// INDEX_F6
			TRANSLATED_G6,		// INDEX_G6
			TRANSLATED_H6,		// INDEX_H6
			TRANSLATED_A7,		// INDEX_A7
			TRANSLATED_B7,		// INDEX_B7
			TRANSLATED_C7,		// INDEX_C7
			TRANSLATED_D7,		// INDEX_D7
			TRANSLATED_E7,		// INDEX_E7
			TRANSLATED_F7,		// INDEX_F7
			TRANSLATED_G7,		// INDEX_G7
			TRANSLATED_H7		// INDEX_H7
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	std::array<translated, INDEX_COUNT> g_Array;

	void array_table_init()
	{
		g_Array[INDEX_A0] = TRANSLATED_A0;
		g_Array[INDEX_B0] = TRANSLATED_B0;
		g_Array[INDEX_C0] = TRANSLATED_C0;
		g_Array[INDEX_D0] = TRANSLATED_D0;
		g_Array[INDEX_E0] = TRANSLATED_E0;
		g_Array[INDEX_F0] = TRANSLATED_F0;
		g_Array[INDEX_G0] = TRANSLATED_G0;
		g_Array[INDEX_H0] = TRANSLATED_H0;
		g_Array[INDEX_A1] = TRANSLATED_A1;
		g_Array[INDEX_B1] = TRANSLATED_B1;
		g_Array[INDEX_C1] = TRANSLATED_C1;
		g_Array[INDEX_D1] = TRANSLATED_D1;
		g_Array[INDEX_E1] = TRANSLATED_E1;
		g_Array[INDEX_F1] = TRANSLATED_F1;
		g_Array[INDEX_G1] = TRANSLATED_G1;
		g_Array[INDEX_H1] = TRANSLATED_H1;
		g_Array[INDEX_A2] = TRANSLATED_A2;
		g_Array[INDEX_B2] = TRANSLATED_B2;
		g_Array[INDEX_C2] = TRANSLATED_C2;
		g_Array[INDEX_D2] = TRANSLATED_D2;
		g_Array[INDEX_E2] = TRANSLATED_E2;
		g_Array[INDEX_F2] = TRANSLATED_F2;
		g_Array[INDEX_G2] = TRANSLATED_G2;
		g_Array[INDEX_H2] = TRANSLATED_H2;
		g_Array[INDEX_A3] = TRANSLATED_A3;
		g_Array[INDEX_B3] = TRANSLATED_B3;
		g_Array[INDEX_C3] = TRANSLATED_C3;
		g_Array[INDEX_D3] = TRANSLATED_D3;
		g_Array[INDEX_E3] = TRANSLATED_E3;
		g_Array[INDEX_F3] = TRANSLATED_F3;
		g_Array[INDEX_G3] = TRANSLATED_G3;
		g_Array[INDEX_H3] = TRANSLATED_H3;

		g_Array[INDEX_A4] = TRANSLATED_A4;
		g_Array[INDEX_B4] = TRANSLATED_B4;
		g_Array[INDEX_C4] = TRANSLATED_C4;
		g_Array[INDEX_D4] = TRANSLATED_D4;
		g_Array[INDEX_E4] = TRANSLATED_E4;
		g_Array[INDEX_F4] = TRANSLATED_F4;
		g_Array[INDEX_G4] = TRANSLATED_G4;
		g_Array[INDEX_H4] = TRANSLATED_H4;
		g_Array[INDEX_A5] = TRANSLATED_A5;
		g_Array[INDEX_B5] = TRANSLATED_B5;
		g_Array[INDEX_C5] = TRANSLATED_C5;
		g_Array[INDEX_D5] = TRANSLATED_D5;
		g_Array[INDEX_E5] = TRANSLATED_E5;
		g_Array[INDEX_F5] = TRANSLATED_F5;
		g_Array[INDEX_G5] = TRANSLATED_G5;
		g_Array[INDEX_H5] = TRANSLATED_H5;
		g_Array[INDEX_A6] = TRANSLATED_A6;
		g_Array[INDEX_B6] = TRANSLATED_B6;
		g_Array[INDEX_C6] = TRANSLATED_C6;
		g_Array[INDEX_D6] = TRANSLATED_D6;
		g_Array[INDEX_E6] = TRANSLATED_E6;
		g_Array[INDEX_F6] = TRANSLATED_F6;
		g_Array[INDEX_G6] = TRANSLATED_G6;
		g_Array[INDEX_H6] = TRANSLATED_H6;
		g_Array[INDEX_A7] = TRANSLATED_A7;
		g_Array[INDEX_B7] = TRANSLATED_B7;
		g_Array[INDEX_C7] = TRANSLATED_C7;
		g_Array[INDEX_D7] = TRANSLATED_D7;
		g_Array[INDEX_E7] = TRANSLATED_E7;
		g_Array[INDEX_F7] = TRANSLATED_F7;
		g_Array[INDEX_G7] = TRANSLATED_G7;
		g_Array[INDEX_H7] = TRANSLATED_H7;
	}

	translated array_table_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		return g_Array[Index];
	}

	std::vector<translated> g_Table;

	void dynamic_table_init()
	{
		g_Table.resize(INDEX_COUNT);
		g_Table[INDEX_A0] = TRANSLATED_A0;
		g_Table[INDEX_B0] = TRANSLATED_B0;
		g_Table[INDEX_C0] = TRANSLATED_C0;
		g_Table[INDEX_D0] = TRANSLATED_D0;
		g_Table[INDEX_E0] = TRANSLATED_E0;
		g_Table[INDEX_F0] = TRANSLATED_F0;
		g_Table[INDEX_G0] = TRANSLATED_G0;
		g_Table[INDEX_H0] = TRANSLATED_H0;
		g_Table[INDEX_A1] = TRANSLATED_A1;
		g_Table[INDEX_B1] = TRANSLATED_B1;
		g_Table[INDEX_C1] = TRANSLATED_C1;
		g_Table[INDEX_D1] = TRANSLATED_D1;
		g_Table[INDEX_E1] = TRANSLATED_E1;
		g_Table[INDEX_F1] = TRANSLATED_F1;
		g_Table[INDEX_G1] = TRANSLATED_G1;
		g_Table[INDEX_H1] = TRANSLATED_H1;
		g_Table[INDEX_A2] = TRANSLATED_A2;
		g_Table[INDEX_B2] = TRANSLATED_B2;
		g_Table[INDEX_C2] = TRANSLATED_C2;
		g_Table[INDEX_D2] = TRANSLATED_D2;
		g_Table[INDEX_E2] = TRANSLATED_E2;
		g_Table[INDEX_F2] = TRANSLATED_F2;
		g_Table[INDEX_G2] = TRANSLATED_G2;
		g_Table[INDEX_H2] = TRANSLATED_H2;
		g_Table[INDEX_A3] = TRANSLATED_A3;
		g_Table[INDEX_B3] = TRANSLATED_B3;
		g_Table[INDEX_C3] = TRANSLATED_C3;
		g_Table[INDEX_D3] = TRANSLATED_D3;
		g_Table[INDEX_E3] = TRANSLATED_E3;
		g_Table[INDEX_F3] = TRANSLATED_F3;
		g_Table[INDEX_G3] = TRANSLATED_G3;
		g_Table[INDEX_H3] = TRANSLATED_H3;

		g_Table[INDEX_A4] = TRANSLATED_A4;
		g_Table[INDEX_B4] = TRANSLATED_B4;
		g_Table[INDEX_C4] = TRANSLATED_C4;
		g_Table[INDEX_D4] = TRANSLATED_D4;
		g_Table[INDEX_E4] = TRANSLATED_E4;
		g_Table[INDEX_F4] = TRANSLATED_F4;
		g_Table[INDEX_G4] = TRANSLATED_G4;
		g_Table[INDEX_H4] = TRANSLATED_H4;
		g_Table[INDEX_A5] = TRANSLATED_A5;
		g_Table[INDEX_B5] = TRANSLATED_B5;
		g_Table[INDEX_C5] = TRANSLATED_C5;
		g_Table[INDEX_D5] = TRANSLATED_D5;
		g_Table[INDEX_E5] = TRANSLATED_E5;
		g_Table[INDEX_F5] = TRANSLATED_F5;
		g_Table[INDEX_G5] = TRANSLATED_G5;
		g_Table[INDEX_H5] = TRANSLATED_H5;
		g_Table[INDEX_A6] = TRANSLATED_A6;
		g_Table[INDEX_B6] = TRANSLATED_B6;
		g_Table[INDEX_C6] = TRANSLATED_C6;
		g_Table[INDEX_D6] = TRANSLATED_D6;
		g_Table[INDEX_E6] = TRANSLATED_E6;
		g_Table[INDEX_F6] = TRANSLATED_F6;
		g_Table[INDEX_G6] = TRANSLATED_G6;
		g_Table[INDEX_H6] = TRANSLATED_H6;
		g_Table[INDEX_A7] = TRANSLATED_A7;
		g_Table[INDEX_B7] = TRANSLATED_B7;
		g_Table[INDEX_C7] = TRANSLATED_C7;
		g_Table[INDEX_D7] = TRANSLATED_D7;
		g_Table[INDEX_E7] = TRANSLATED_E7;
		g_Table[INDEX_F7] = TRANSLATED_F7;
		g_Table[INDEX_G7] = TRANSLATED_G7;
		g_Table[INDEX_H7] = TRANSLATED_H7;
	}

	translated dynamic_table_translate(index Index)
	{
		assert(g_Table.size() == INDEX_COUNT);
		assert(Index < INDEX_COUNT);

		return g_Table[Index];
	}

	translated index_switch_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		switch(Index)
		{
		default:
		case INDEX_A0: return TRANSLATED_A0;
		case INDEX_B0: return TRANSLATED_B0;
		case INDEX_C0: return TRANSLATED_C0;
		case INDEX_D0: return TRANSLATED_D0;
		case INDEX_E0: return TRANSLATED_E0;
		case INDEX_F0: return TRANSLATED_F0;
		case INDEX_G0: return TRANSLATED_G0;
		case INDEX_H0: return TRANSLATED_H0;
		case INDEX_A1: return TRANSLATED_A1;
		case INDEX_B1: return TRANSLATED_B1;
		case INDEX_C1: return TRANSLATED_C1;
		case INDEX_D1: return TRANSLATED_D1;
		case INDEX_E1: return TRANSLATED_E1;
		case INDEX_F1: return TRANSLATED_F1;
		case INDEX_G1: return TRANSLATED_G1;
		case INDEX_H1: return TRANSLATED_H1;
		case INDEX_A2: return TRANSLATED_A2;
		case INDEX_B2: return TRANSLATED_B2;
		case INDEX_C2: return TRANSLATED_C2;
		case INDEX_D2: return TRANSLATED_D2;
		case INDEX_E2: return TRANSLATED_E2;
		case INDEX_F2: return TRANSLATED_F2;
		case INDEX_G2: return TRANSLATED_G2;
		case INDEX_H2: return TRANSLATED_H2;
		case INDEX_A3: return TRANSLATED_A3;
		case INDEX_B3: return TRANSLATED_B3;
		case INDEX_C3: return TRANSLATED_C3;
		case INDEX_D3: return TRANSLATED_D3;
		case INDEX_E3: return TRANSLATED_E3;
		case INDEX_F3: return TRANSLATED_F3;
		case INDEX_G3: return TRANSLATED_G3;
		case INDEX_H3: return TRANSLATED_H3;

		case INDEX_A4: return TRANSLATED_A4;
		case INDEX_B4: return TRANSLATED_B4;
		case INDEX_C4: return TRANSLATED_C4;
		case INDEX_D4: return TRANSLATED_D4;
		case INDEX_E4: return TRANSLATED_E4;
		case INDEX_F4: return TRANSLATED_F4;
		case INDEX_G4: return TRANSLATED_G4;
		case INDEX_H4: return TRANSLATED_H4;
		case INDEX_A5: return TRANSLATED_A5;
		case INDEX_B5: return TRANSLATED_B5;
		case INDEX_C5: return TRANSLATED_C5;
		case INDEX_D5: return TRANSLATED_D5;
		case INDEX_E5: return TRANSLATED_E5;
		case INDEX_F5: return TRANSLATED_F5;
		case INDEX_G5: return TRANSLATED_G5;
		case INDEX_H5: return TRANSLATED_H5;
		case INDEX_A6: return TRANSLATED_A6;
		case INDEX_B6: return TRANSLATED_B6;
		case INDEX_C6: return TRANSLATED_C6;
		case INDEX_D6: return TRANSLATED_D6;
		case INDEX_E6: return TRANSLATED_E6;
		case INDEX_F6: return TRANSLATED_F6;
		case INDEX_G6: return TRANSLATED_G6;
		case INDEX_H6: return TRANSLATED_H6;
		case INDEX_A7: return TRANSLATED_A7;
		case INDEX_B7: return TRANSLATED_B7;
		case INDEX_C7: return TRANSLATED_C7;
		case INDEX_D7: return TRANSLATED_D7;
		case INDEX_E7: return TRANSLATED_E7;
		case INDEX_F7: return TRANSLATED_F7;
		case INDEX_G7: return TRANSLATED_G7;
		case INDEX_H7: return TRANSLATED_H7;
		}
	}

	index value_switch_translate(translated Value)
	{
		assert(Value < TRANSLATED_COUNT);

		switch(Value)
		{
		default:
		case TRANSLATED_A0: return INDEX_A0;
		case TRANSLATED_B0: return INDEX_B0;
		case TRANSLATED_C0: return INDEX_C0;
		case TRANSLATED_D0: return INDEX_D0;
		case TRANSLATED_E0: return INDEX_E0;
		case TRANSLATED_F0: return INDEX_F0;
		case TRANSLATED_G0: return INDEX_G0;
		case TRANSLATED_H0: return INDEX_H0;
		case TRANSLATED_A1: return INDEX_A1;
		case TRANSLATED_B1: return INDEX_B1;
		case TRANSLATED_C1: return INDEX_C1;
		case TRANSLATED_D1: return INDEX_D1;
		case TRANSLATED_E1: return INDEX_E1;
		case TRANSLATED_F1: return INDEX_F1;
		case TRANSLATED_G1: return INDEX_G1;
		case TRANSLATED_H1: return INDEX_H1;
		case TRANSLATED_A2: return INDEX_A2;
		case TRANSLATED_B2: return INDEX_B2;
		case TRANSLATED_C2: return INDEX_C2;
		case TRANSLATED_D2: return INDEX_D2;
		case TRANSLATED_E2: return INDEX_E2;
		case TRANSLATED_F2: return INDEX_F2;
		case TRANSLATED_G2: return INDEX_G2;
		case TRANSLATED_H2: return INDEX_H2;
		case TRANSLATED_A3: return INDEX_A3;
		case TRANSLATED_B3: return INDEX_B3;
		case TRANSLATED_C3: return INDEX_C3;
		case TRANSLATED_D3: return INDEX_D3;
		case TRANSLATED_E3: return INDEX_E3;
		case TRANSLATED_F3: return INDEX_F3;
		case TRANSLATED_G3: return INDEX_G3;
		case TRANSLATED_H3: return INDEX_H3;

		case TRANSLATED_A4: return INDEX_A4;
		case TRANSLATED_B4: return INDEX_B4;
		case TRANSLATED_C4: return INDEX_C4;
		case TRANSLATED_D4: return INDEX_D4;
		case TRANSLATED_E4: return INDEX_E4;
		case TRANSLATED_F4: return INDEX_F4;
		case TRANSLATED_G4: return INDEX_G4;
		case TRANSLATED_H4: return INDEX_H4;
		case TRANSLATED_A5: return INDEX_A5;
		case TRANSLATED_B5: return INDEX_B5;
		case TRANSLATED_C5: return INDEX_C5;
		case TRANSLATED_D5: return INDEX_D5;
		case TRANSLATED_E5: return INDEX_E5;
		case TRANSLATED_F5: return INDEX_F5;
		case TRANSLATED_G5: return INDEX_G5;
		case TRANSLATED_H5: return INDEX_H5;
		case TRANSLATED_A6: return INDEX_A6;
		case TRANSLATED_B6: return INDEX_B6;
		case TRANSLATED_C6: return INDEX_C6;
		case TRANSLATED_D6: return INDEX_D6;
		case TRANSLATED_E6: return INDEX_E6;
		case TRANSLATED_F6: return INDEX_F6;
		case TRANSLATED_G6: return INDEX_G6;
		case TRANSLATED_H6: return INDEX_H6;
		case TRANSLATED_A7: return INDEX_A7;
		case TRANSLATED_B7: return INDEX_B7;
		case TRANSLATED_C7: return INDEX_C7;
		case TRANSLATED_D7: return INDEX_D7;
		case TRANSLATED_E7: return INDEX_E7;
		case TRANSLATED_F7: return INDEX_F7;
		case TRANSLATED_G7: return INDEX_G7;
		case TRANSLATED_H7: return INDEX_H7;
		}
	}
}//namespace translation64

namespace translation128
{
	enum index
	{
		INDEX_A0,
		INDEX_B0,
		INDEX_C0,
		INDEX_D0,
		INDEX_E0,
		INDEX_F0,
		INDEX_G0,
		INDEX_H0,
		INDEX_A1,
		INDEX_B1,
		INDEX_C1,
		INDEX_D1,
		INDEX_E1,
		INDEX_F1,
		INDEX_G1,
		INDEX_H1,
		INDEX_A2,
		INDEX_B2,
		INDEX_C2,
		INDEX_D2,
		INDEX_E2,
		INDEX_F2,
		INDEX_G2,
		INDEX_H2,
		INDEX_A3,
		INDEX_B3,
		INDEX_C3,
		INDEX_D3,
		INDEX_E3,
		INDEX_F3,
		INDEX_G3,
		INDEX_H3,
		INDEX_A4,
		INDEX_B4,
		INDEX_C4,
		INDEX_D4,
		INDEX_E4,
		INDEX_F4,
		INDEX_G4,
		INDEX_H4,
		INDEX_A5,
		INDEX_B5,
		INDEX_C5,
		INDEX_D5,
		INDEX_E5,
		INDEX_F5,
		INDEX_G5,
		INDEX_H5,
		INDEX_A6,
		INDEX_B6,
		INDEX_C6,
		INDEX_D6,
		INDEX_E6,
		INDEX_F6,
		INDEX_G6,
		INDEX_H6,
		INDEX_A7,
		INDEX_B7,
		INDEX_C7,
		INDEX_D7,
		INDEX_E7,
		INDEX_F7,
		INDEX_G7,
		INDEX_H7,

		INDEX_A8,
		INDEX_B8,
		INDEX_C8,
		INDEX_D8,
		INDEX_E8,
		INDEX_F8,
		INDEX_G8,
		INDEX_H8,
		INDEX_A9,
		INDEX_B9,
		INDEX_C9,
		INDEX_D9,
		INDEX_E9,
		INDEX_F9,
		INDEX_G9,
		INDEX_H9,
		INDEX_AA,
		INDEX_BA,
		INDEX_CA,
		INDEX_DA,
		INDEX_EA,
		INDEX_FA,
		INDEX_GA,
		INDEX_HA,
		INDEX_AB,
		INDEX_BB,
		INDEX_CB,
		INDEX_DB,
		INDEX_EB,
		INDEX_FB,
		INDEX_GB,
		INDEX_HB,
		INDEX_AC,
		INDEX_BC,
		INDEX_CC,
		INDEX_DC,
		INDEX_EC,
		INDEX_FC,
		INDEX_GC,
		INDEX_HC,
		INDEX_AD,
		INDEX_BD,
		INDEX_CD,
		INDEX_DD,
		INDEX_ED,
		INDEX_FD,
		INDEX_GD,
		INDEX_HD,
		INDEX_AE,
		INDEX_BE,
		INDEX_CE,
		INDEX_DE,
		INDEX_EE,
		INDEX_FE,
		INDEX_GE,
		INDEX_HE,
		INDEX_AF,
		INDEX_BF,
		INDEX_CF,
		INDEX_DF,
		INDEX_EF,
		INDEX_FF,
		INDEX_GF,
		INDEX_HF,
		INDEX_COUNT
	};

	enum translated
	{
		TRANSLATED_A0 = 0xA0E7,
		TRANSLATED_B0 = 0x01C2,
		TRANSLATED_C0 = 0x2C35,
		TRANSLATED_D0 = 0x8AEF,
		TRANSLATED_E0 = 0xAF61,
		TRANSLATED_F0 = 0xC3FF,
		TRANSLATED_G0 = 0xFA12,
		TRANSLATED_H0 = 0x42B9,
		TRANSLATED_A1 = 0xB0E7,
		TRANSLATED_B1 = 0xB1C2,
		TRANSLATED_C1 = 0xBC35,
		TRANSLATED_D1 = 0xBAEF,
		TRANSLATED_E1 = 0xBF61,
		TRANSLATED_F1 = 0xB3FF,
		TRANSLATED_G1 = 0xBA12,
		TRANSLATED_H1 = 0xB289,
		TRANSLATED_A2 = 0xC0E7,
		TRANSLATED_B2 = 0xC1C2,
		TRANSLATED_C2 = 0xCC35,
		TRANSLATED_D2 = 0xCAEF,
		TRANSLATED_E2 = 0xCF61,
		TRANSLATED_F2 = 0xCAFF,
		TRANSLATED_G2 = 0xCA12,
		TRANSLATED_H2 = 0xC2B9,
		TRANSLATED_A3 = 0xD0E7,
		TRANSLATED_B3 = 0xD1C2,
		TRANSLATED_C3 = 0xDC35,
		TRANSLATED_D3 = 0xDAEF,
		TRANSLATED_E3 = 0xDF61,
		TRANSLATED_F3 = 0xD3FF,
		TRANSLATED_G3 = 0xDA12,
		TRANSLATED_H3 = 0xE2B9,
		TRANSLATED_A4 = 0xF0A7,
		TRANSLATED_B4 = 0x01A9,
		TRANSLATED_C4 = 0x2CA9,
		TRANSLATED_D4 = 0x8AA9,
		TRANSLATED_E4 = 0xAFA9,
		TRANSLATED_F4 = 0xC3A9,
		TRANSLATED_G4 = 0xFAA9,
		TRANSLATED_H4 = 0x52A9,
		TRANSLATED_A5 = 0x00B7,
		TRANSLATED_B5 = 0x11B2,
		TRANSLATED_C5 = 0x22B5,
		TRANSLATED_D5 = 0x33BF,
		TRANSLATED_E5 = 0x44B1,
		TRANSLATED_F5 = 0x55BF,
		TRANSLATED_G5 = 0x66B2,
		TRANSLATED_H5 = 0x77BB,
		TRANSLATED_A6 = 0xC0C7,
		TRANSLATED_B6 = 0xC1CC,
		TRANSLATED_C6 = 0xCCC5,
		TRANSLATED_D6 = 0xCBCF,
		TRANSLATED_E6 = 0xCFC1,
		TRANSLATED_F6 = 0xCACF,
		TRANSLATED_G6 = 0xCAC2,
		TRANSLATED_H6 = 0xC2C9,
		TRANSLATED_A7 = 0xD0D7,
		TRANSLATED_B7 = 0xD1D2,
		TRANSLATED_C7 = 0xDCD5,
		TRANSLATED_D7 = 0xDADF,
		TRANSLATED_E7 = 0xDFD1,
		TRANSLATED_F7 = 0xD3DF,
		TRANSLATED_G7 = 0xDAD2,
		TRANSLATED_H7 = 0xD2D9,

		TRANSLATED_A8 = 0xA0A7,
		TRANSLATED_B8 = 0x01A2,
		TRANSLATED_C8 = 0x2CA5,
		TRANSLATED_D8 = 0x8AAF,
		TRANSLATED_E8 = 0xAFA1,
		TRANSLATED_F8 = 0xC3AF,
		TRANSLATED_G8 = 0xFAA2,
		TRANSLATED_H8 = 0x42A9,
		TRANSLATED_A9 = 0xB0B7,
		TRANSLATED_B9 = 0xB1B2,
		TRANSLATED_C9 = 0xBCB5,
		TRANSLATED_D9 = 0xBABF,
		TRANSLATED_E9 = 0xBFB1,
		TRANSLATED_F9 = 0xB3BF,
		TRANSLATED_G9 = 0xBAB2,
		TRANSLATED_H9 = 0xB2B9,
		TRANSLATED_AA = 0xC0B7,
		TRANSLATED_BA = 0xC1B2,
		TRANSLATED_CA = 0xCCB5,
		TRANSLATED_DA = 0xCAB0,
		TRANSLATED_EA = 0xCBC1,
		TRANSLATED_FA = 0xCABF,
		TRANSLATED_GA = 0xCAB2,
		TRANSLATED_HA = 0xC2BB,
		TRANSLATED_AB = 0xD0B7,
		TRANSLATED_BB = 0xD1B2,
		TRANSLATED_CB = 0xDCB5,
		TRANSLATED_DB = 0xDABF,
		TRANSLATED_EB = 0xDFB1,
		TRANSLATED_FB = 0xD3EF,
		TRANSLATED_GB = 0xDAB2,
		TRANSLATED_HB = 0xD2B9,
		TRANSLATED_AC = 0x00A7,
		TRANSLATED_BC = 0x11A2,
		TRANSLATED_CC = 0x3CA5,
		TRANSLATED_DC = 0x2AAF,
		TRANSLATED_EC = 0x4FA1,
		TRANSLATED_FC = 0x53AF,
		TRANSLATED_GC = 0x6AA2,
		TRANSLATED_HC = 0x72A9,
		TRANSLATED_AD = 0x80B7,
		TRANSLATED_BD = 0x91B2,
		TRANSLATED_CD = 0xACB5,
		TRANSLATED_DD = 0xBBBF,
		TRANSLATED_ED = 0xCFB1,
		TRANSLATED_FD = 0xD3BF,
		TRANSLATED_GD = 0xEAB2,
		TRANSLATED_HD = 0xF2BB,
		TRANSLATED_AE = 0x00C7,
		TRANSLATED_BE = 0x01CC,
		TRANSLATED_CE = 0x0CC5,
		TRANSLATED_DE = 0x0BCF,
		TRANSLATED_EE = 0x0FC1,
		TRANSLATED_FE = 0x0ACF,
		TRANSLATED_GE = 0x0AC2,
		TRANSLATED_HE = 0x02C9,
		TRANSLATED_AF = 0x10D7,
		TRANSLATED_BF = 0x11D2,
		TRANSLATED_CF = 0x1CD5,
		TRANSLATED_DF = 0x1ADF,
		TRANSLATED_EF = 0x1FD1,
		TRANSLATED_FF = 0x13DF,
		TRANSLATED_GF = 0x1AD2,
		TRANSLATED_HF = 0x12D9,
		TRANSLATED_COUNT = 128
	};

	translated const_table_translate(index Index)
	{
		const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1,		// INDEX_H1
			TRANSLATED_A2,		// INDEX_A2
			TRANSLATED_B2,		// INDEX_B2
			TRANSLATED_C2,		// INDEX_C2
			TRANSLATED_D2,		// INDEX_D2
			TRANSLATED_E2,		// INDEX_E2
			TRANSLATED_F2,		// INDEX_F2
			TRANSLATED_G2,		// INDEX_G2
			TRANSLATED_H2,		// INDEX_H2
			TRANSLATED_A3,		// INDEX_A3
			TRANSLATED_B3,		// INDEX_B3
			TRANSLATED_C3,		// INDEX_C3
			TRANSLATED_D3,		// INDEX_D3
			TRANSLATED_E3,		// INDEX_E3
			TRANSLATED_F3,		// INDEX_F3
			TRANSLATED_G3,		// INDEX_G3
			TRANSLATED_H3,		// INDEX_H3

			TRANSLATED_A4,		// INDEX_A4
			TRANSLATED_B4,		// INDEX_B4
			TRANSLATED_C4,		// INDEX_C4
			TRANSLATED_D4,		// INDEX_D4
			TRANSLATED_E4,		// INDEX_E4
			TRANSLATED_F4,		// INDEX_F4
			TRANSLATED_G4,		// INDEX_G4
			TRANSLATED_H4,		// INDEX_H4
			TRANSLATED_A5,		// INDEX_A5
			TRANSLATED_B5,		// INDEX_B5
			TRANSLATED_C5,		// INDEX_C5
			TRANSLATED_D5,		// INDEX_D5
			TRANSLATED_E5,		// INDEX_E5
			TRANSLATED_F5,		// INDEX_F5
			TRANSLATED_G5,		// INDEX_G5
			TRANSLATED_H5,		// INDEX_H5
			TRANSLATED_A6,		// INDEX_A6
			TRANSLATED_B6,		// INDEX_B6
			TRANSLATED_C6,		// INDEX_C6
			TRANSLATED_D6,		// INDEX_D6
			TRANSLATED_E6,		// INDEX_E6
			TRANSLATED_F6,		// INDEX_F6
			TRANSLATED_G6,		// INDEX_G6
			TRANSLATED_H6,		// INDEX_H6
			TRANSLATED_A7,		// INDEX_A7
			TRANSLATED_B7,		// INDEX_B7
			TRANSLATED_C7,		// INDEX_C7
			TRANSLATED_D7,		// INDEX_D7
			TRANSLATED_E7,		// INDEX_E7
			TRANSLATED_F7,		// INDEX_F7
			TRANSLATED_G7,		// INDEX_G7
			TRANSLATED_H7,		// INDEX_H7

			TRANSLATED_A8,		// INDEX_A0
			TRANSLATED_B8,		// INDEX_B0
			TRANSLATED_C8,		// INDEX_C0
			TRANSLATED_D8,		// INDEX_D0
			TRANSLATED_E8,		// INDEX_E0
			TRANSLATED_F8,		// INDEX_F0
			TRANSLATED_G8,		// INDEX_G0
			TRANSLATED_H8,		// INDEX_H0
			TRANSLATED_A9,		// INDEX_A1
			TRANSLATED_B9,		// INDEX_B1
			TRANSLATED_C9,		// INDEX_C1
			TRANSLATED_D9,		// INDEX_D1
			TRANSLATED_E9,		// INDEX_E1
			TRANSLATED_F9,		// INDEX_F1
			TRANSLATED_G9,		// INDEX_G1
			TRANSLATED_H9,		// INDEX_H1
			TRANSLATED_AA,		// INDEX_A2
			TRANSLATED_BA,		// INDEX_B2
			TRANSLATED_CA,		// INDEX_C2
			TRANSLATED_DA,		// INDEX_D2
			TRANSLATED_EA,		// INDEX_E2
			TRANSLATED_FA,		// INDEX_F2
			TRANSLATED_GA,		// INDEX_G2
			TRANSLATED_HA,		// INDEX_H2
			TRANSLATED_AB,		// INDEX_A3
			TRANSLATED_BB,		// INDEX_B3
			TRANSLATED_CB,		// INDEX_C3
			TRANSLATED_DB,		// INDEX_D3
			TRANSLATED_EB,		// INDEX_E3
			TRANSLATED_FB,		// INDEX_F3
			TRANSLATED_GB,		// INDEX_G3
			TRANSLATED_HB,		// INDEX_H3

			TRANSLATED_AC,		// INDEX_A4
			TRANSLATED_BC,		// INDEX_B4
			TRANSLATED_CC,		// INDEX_C4
			TRANSLATED_DC,		// INDEX_D4
			TRANSLATED_EC,		// INDEX_E4
			TRANSLATED_FC,		// INDEX_F4
			TRANSLATED_GC,		// INDEX_G4
			TRANSLATED_HC,		// INDEX_H4
			TRANSLATED_AD,		// INDEX_A5
			TRANSLATED_BD,		// INDEX_B5
			TRANSLATED_CD,		// INDEX_C5
			TRANSLATED_DD,		// INDEX_D5
			TRANSLATED_ED,		// INDEX_E5
			TRANSLATED_FD,		// INDEX_F5
			TRANSLATED_GD,		// INDEX_G5
			TRANSLATED_HD,		// INDEX_H5
			TRANSLATED_AE,		// INDEX_A6
			TRANSLATED_BE,		// INDEX_B6
			TRANSLATED_CE,		// INDEX_C6
			TRANSLATED_DE,		// INDEX_D6
			TRANSLATED_EE,		// INDEX_E6
			TRANSLATED_FE,		// INDEX_F6
			TRANSLATED_GE,		// INDEX_G6
			TRANSLATED_HE,		// INDEX_H6
			TRANSLATED_AF,		// INDEX_A7
			TRANSLATED_BF,		// INDEX_B7
			TRANSLATED_CF,		// INDEX_C7
			TRANSLATED_DF,		// INDEX_D7
			TRANSLATED_EF,		// INDEX_E7
			TRANSLATED_FF,		// INDEX_F7
			TRANSLATED_GF,		// INDEX_G7
			TRANSLATED_HF		// INDEX_H7
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	translated static_table_translate(index Index)
	{
		static const translated Table[] =
		{
			TRANSLATED_A0,		// INDEX_A0
			TRANSLATED_B0,		// INDEX_B0
			TRANSLATED_C0,		// INDEX_C0
			TRANSLATED_D0,		// INDEX_D0
			TRANSLATED_E0,		// INDEX_E0
			TRANSLATED_F0,		// INDEX_F0
			TRANSLATED_G0,		// INDEX_G0
			TRANSLATED_H0,		// INDEX_H0
			TRANSLATED_A1,		// INDEX_A1
			TRANSLATED_B1,		// INDEX_B1
			TRANSLATED_C1,		// INDEX_C1
			TRANSLATED_D1,		// INDEX_D1
			TRANSLATED_E1,		// INDEX_E1
			TRANSLATED_F1,		// INDEX_F1
			TRANSLATED_G1,		// INDEX_G1
			TRANSLATED_H1,		// INDEX_H1
			TRANSLATED_A2,		// INDEX_A2
			TRANSLATED_B2,		// INDEX_B2
			TRANSLATED_C2,		// INDEX_C2
			TRANSLATED_D2,		// INDEX_D2
			TRANSLATED_E2,		// INDEX_E2
			TRANSLATED_F2,		// INDEX_F2
			TRANSLATED_G2,		// INDEX_G2
			TRANSLATED_H2,		// INDEX_H2
			TRANSLATED_A3,		// INDEX_A3
			TRANSLATED_B3,		// INDEX_B3
			TRANSLATED_C3,		// INDEX_C3
			TRANSLATED_D3,		// INDEX_D3
			TRANSLATED_E3,		// INDEX_E3
			TRANSLATED_F3,		// INDEX_F3
			TRANSLATED_G3,		// INDEX_G3
			TRANSLATED_H3,		// INDEX_H3

			TRANSLATED_A4,		// INDEX_A4
			TRANSLATED_B4,		// INDEX_B4
			TRANSLATED_C4,		// INDEX_C4
			TRANSLATED_D4,		// INDEX_D4
			TRANSLATED_E4,		// INDEX_E4
			TRANSLATED_F4,		// INDEX_F4
			TRANSLATED_G4,		// INDEX_G4
			TRANSLATED_H4,		// INDEX_H4
			TRANSLATED_A5,		// INDEX_A5
			TRANSLATED_B5,		// INDEX_B5
			TRANSLATED_C5,		// INDEX_C5
			TRANSLATED_D5,		// INDEX_D5
			TRANSLATED_E5,		// INDEX_E5
			TRANSLATED_F5,		// INDEX_F5
			TRANSLATED_G5,		// INDEX_G5
			TRANSLATED_H5,		// INDEX_H5
			TRANSLATED_A6,		// INDEX_A6
			TRANSLATED_B6,		// INDEX_B6
			TRANSLATED_C6,		// INDEX_C6
			TRANSLATED_D6,		// INDEX_D6
			TRANSLATED_E6,		// INDEX_E6
			TRANSLATED_F6,		// INDEX_F6
			TRANSLATED_G6,		// INDEX_G6
			TRANSLATED_H6,		// INDEX_H6
			TRANSLATED_A7,		// INDEX_A7
			TRANSLATED_B7,		// INDEX_B7
			TRANSLATED_C7,		// INDEX_C7
			TRANSLATED_D7,		// INDEX_D7
			TRANSLATED_E7,		// INDEX_E7
			TRANSLATED_F7,		// INDEX_F7
			TRANSLATED_G7,		// INDEX_G7
			TRANSLATED_H7,		// INDEX_H7

			TRANSLATED_A8,		// INDEX_A0
			TRANSLATED_B8,		// INDEX_B0
			TRANSLATED_C8,		// INDEX_C0
			TRANSLATED_D8,		// INDEX_D0
			TRANSLATED_E8,		// INDEX_E0
			TRANSLATED_F8,		// INDEX_F0
			TRANSLATED_G8,		// INDEX_G0
			TRANSLATED_H8,		// INDEX_H0
			TRANSLATED_A9,		// INDEX_A1
			TRANSLATED_B9,		// INDEX_B1
			TRANSLATED_C9,		// INDEX_C1
			TRANSLATED_D9,		// INDEX_D1
			TRANSLATED_E9,		// INDEX_E1
			TRANSLATED_F9,		// INDEX_F1
			TRANSLATED_G9,		// INDEX_G1
			TRANSLATED_H9,		// INDEX_H1
			TRANSLATED_AA,		// INDEX_A2
			TRANSLATED_BA,		// INDEX_B2
			TRANSLATED_CA,		// INDEX_C2
			TRANSLATED_DA,		// INDEX_D2
			TRANSLATED_EA,		// INDEX_E2
			TRANSLATED_FA,		// INDEX_F2
			TRANSLATED_GA,		// INDEX_G2
			TRANSLATED_HA,		// INDEX_H2
			TRANSLATED_AB,		// INDEX_A3
			TRANSLATED_BB,		// INDEX_B3
			TRANSLATED_CB,		// INDEX_C3
			TRANSLATED_DB,		// INDEX_D3
			TRANSLATED_EB,		// INDEX_E3
			TRANSLATED_FB,		// INDEX_F3
			TRANSLATED_GB,		// INDEX_G3
			TRANSLATED_HB,		// INDEX_H3

			TRANSLATED_AC,		// INDEX_A4
			TRANSLATED_BC,		// INDEX_B4
			TRANSLATED_CC,		// INDEX_C4
			TRANSLATED_DC,		// INDEX_D4
			TRANSLATED_EC,		// INDEX_E4
			TRANSLATED_FC,		// INDEX_F4
			TRANSLATED_GC,		// INDEX_G4
			TRANSLATED_HC,		// INDEX_H4
			TRANSLATED_AD,		// INDEX_A5
			TRANSLATED_BD,		// INDEX_B5
			TRANSLATED_CD,		// INDEX_C5
			TRANSLATED_DD,		// INDEX_D5
			TRANSLATED_ED,		// INDEX_E5
			TRANSLATED_FD,		// INDEX_F5
			TRANSLATED_GD,		// INDEX_G5
			TRANSLATED_HD,		// INDEX_H5
			TRANSLATED_AE,		// INDEX_A6
			TRANSLATED_BE,		// INDEX_B6
			TRANSLATED_CE,		// INDEX_C6
			TRANSLATED_DE,		// INDEX_D6
			TRANSLATED_EE,		// INDEX_E6
			TRANSLATED_FE,		// INDEX_F6
			TRANSLATED_GE,		// INDEX_G6
			TRANSLATED_HE,		// INDEX_H6
			TRANSLATED_AF,		// INDEX_A7
			TRANSLATED_BF,		// INDEX_B7
			TRANSLATED_CF,		// INDEX_C7
			TRANSLATED_DF,		// INDEX_D7
			TRANSLATED_EF,		// INDEX_E7
			TRANSLATED_FF,		// INDEX_F7
			TRANSLATED_GF,		// INDEX_G7
			TRANSLATED_HF		// INDEX_H7
		};

		static_assert(sizeof(Table) / sizeof(translated) == INDEX_COUNT, "The translation table needs to be updated.");
		assert(Index < INDEX_COUNT);

		return Table[Index];
	}

	std::array<translated, INDEX_COUNT> g_Array;

	void array_table_init()
	{
		g_Array[INDEX_A0] = TRANSLATED_A0;
		g_Array[INDEX_B0] = TRANSLATED_B0;
		g_Array[INDEX_C0] = TRANSLATED_C0;
		g_Array[INDEX_D0] = TRANSLATED_D0;
		g_Array[INDEX_E0] = TRANSLATED_E0;
		g_Array[INDEX_F0] = TRANSLATED_F0;
		g_Array[INDEX_G0] = TRANSLATED_G0;
		g_Array[INDEX_H0] = TRANSLATED_H0;
		g_Array[INDEX_A1] = TRANSLATED_A1;
		g_Array[INDEX_B1] = TRANSLATED_B1;
		g_Array[INDEX_C1] = TRANSLATED_C1;
		g_Array[INDEX_D1] = TRANSLATED_D1;
		g_Array[INDEX_E1] = TRANSLATED_E1;
		g_Array[INDEX_F1] = TRANSLATED_F1;
		g_Array[INDEX_G1] = TRANSLATED_G1;
		g_Array[INDEX_H1] = TRANSLATED_H1;
		g_Array[INDEX_A2] = TRANSLATED_A2;
		g_Array[INDEX_B2] = TRANSLATED_B2;
		g_Array[INDEX_C2] = TRANSLATED_C2;
		g_Array[INDEX_D2] = TRANSLATED_D2;
		g_Array[INDEX_E2] = TRANSLATED_E2;
		g_Array[INDEX_F2] = TRANSLATED_F2;
		g_Array[INDEX_G2] = TRANSLATED_G2;
		g_Array[INDEX_H2] = TRANSLATED_H2;
		g_Array[INDEX_A3] = TRANSLATED_A3;
		g_Array[INDEX_B3] = TRANSLATED_B3;
		g_Array[INDEX_C3] = TRANSLATED_C3;
		g_Array[INDEX_D3] = TRANSLATED_D3;
		g_Array[INDEX_E3] = TRANSLATED_E3;
		g_Array[INDEX_F3] = TRANSLATED_F3;
		g_Array[INDEX_G3] = TRANSLATED_G3;
		g_Array[INDEX_H3] = TRANSLATED_H3;

		g_Array[INDEX_A4] = TRANSLATED_A4;
		g_Array[INDEX_B4] = TRANSLATED_B4;
		g_Array[INDEX_C4] = TRANSLATED_C4;
		g_Array[INDEX_D4] = TRANSLATED_D4;
		g_Array[INDEX_E4] = TRANSLATED_E4;
		g_Array[INDEX_F4] = TRANSLATED_F4;
		g_Array[INDEX_G4] = TRANSLATED_G4;
		g_Array[INDEX_H4] = TRANSLATED_H4;
		g_Array[INDEX_A5] = TRANSLATED_A5;
		g_Array[INDEX_B5] = TRANSLATED_B5;
		g_Array[INDEX_C5] = TRANSLATED_C5;
		g_Array[INDEX_D5] = TRANSLATED_D5;
		g_Array[INDEX_E5] = TRANSLATED_E5;
		g_Array[INDEX_F5] = TRANSLATED_F5;
		g_Array[INDEX_G5] = TRANSLATED_G5;
		g_Array[INDEX_H5] = TRANSLATED_H5;
		g_Array[INDEX_A6] = TRANSLATED_A6;
		g_Array[INDEX_B6] = TRANSLATED_B6;
		g_Array[INDEX_C6] = TRANSLATED_C6;
		g_Array[INDEX_D6] = TRANSLATED_D6;
		g_Array[INDEX_E6] = TRANSLATED_E6;
		g_Array[INDEX_F6] = TRANSLATED_F6;
		g_Array[INDEX_G6] = TRANSLATED_G6;
		g_Array[INDEX_H6] = TRANSLATED_H6;
		g_Array[INDEX_A7] = TRANSLATED_A7;
		g_Array[INDEX_B7] = TRANSLATED_B7;
		g_Array[INDEX_C7] = TRANSLATED_C7;
		g_Array[INDEX_D7] = TRANSLATED_D7;
		g_Array[INDEX_E7] = TRANSLATED_E7;
		g_Array[INDEX_F7] = TRANSLATED_F7;
		g_Array[INDEX_G7] = TRANSLATED_G7;
		g_Array[INDEX_H7] = TRANSLATED_H7;

		g_Array[INDEX_A8] = TRANSLATED_A8;
		g_Array[INDEX_B8] = TRANSLATED_B8;
		g_Array[INDEX_C8] = TRANSLATED_C8;
		g_Array[INDEX_D8] = TRANSLATED_D8;
		g_Array[INDEX_E8] = TRANSLATED_E8;
		g_Array[INDEX_F8] = TRANSLATED_F8;
		g_Array[INDEX_G8] = TRANSLATED_G8;
		g_Array[INDEX_H8] = TRANSLATED_H8;
		g_Array[INDEX_A9] = TRANSLATED_A9;
		g_Array[INDEX_B9] = TRANSLATED_B9;
		g_Array[INDEX_C9] = TRANSLATED_C9;
		g_Array[INDEX_D9] = TRANSLATED_D9;
		g_Array[INDEX_E9] = TRANSLATED_E9;
		g_Array[INDEX_F9] = TRANSLATED_F9;
		g_Array[INDEX_G9] = TRANSLATED_G9;
		g_Array[INDEX_H9] = TRANSLATED_H9;
		g_Array[INDEX_AA] = TRANSLATED_AA;
		g_Array[INDEX_BA] = TRANSLATED_BA;
		g_Array[INDEX_CA] = TRANSLATED_CA;
		g_Array[INDEX_DA] = TRANSLATED_DA;
		g_Array[INDEX_EA] = TRANSLATED_EA;
		g_Array[INDEX_FA] = TRANSLATED_FA;
		g_Array[INDEX_GA] = TRANSLATED_GA;
		g_Array[INDEX_HA] = TRANSLATED_HA;
		g_Array[INDEX_AB] = TRANSLATED_AB;
		g_Array[INDEX_BB] = TRANSLATED_BB;
		g_Array[INDEX_CB] = TRANSLATED_CB;
		g_Array[INDEX_DB] = TRANSLATED_DB;
		g_Array[INDEX_EB] = TRANSLATED_EB;
		g_Array[INDEX_FB] = TRANSLATED_FB;
		g_Array[INDEX_GB] = TRANSLATED_GB;
		g_Array[INDEX_HB] = TRANSLATED_HB;

		g_Array[INDEX_AC] = TRANSLATED_AC;
		g_Array[INDEX_BC] = TRANSLATED_BC;
		g_Array[INDEX_CC] = TRANSLATED_CC;
		g_Array[INDEX_DC] = TRANSLATED_DC;
		g_Array[INDEX_EC] = TRANSLATED_EC;
		g_Array[INDEX_FC] = TRANSLATED_FC;
		g_Array[INDEX_GC] = TRANSLATED_GC;
		g_Array[INDEX_HC] = TRANSLATED_HC;
		g_Array[INDEX_AD] = TRANSLATED_AD;
		g_Array[INDEX_BD] = TRANSLATED_BD;
		g_Array[INDEX_CD] = TRANSLATED_CD;
		g_Array[INDEX_DD] = TRANSLATED_DD;
		g_Array[INDEX_ED] = TRANSLATED_ED;
		g_Array[INDEX_FD] = TRANSLATED_FD;
		g_Array[INDEX_GD] = TRANSLATED_GD;
		g_Array[INDEX_HD] = TRANSLATED_HD;
		g_Array[INDEX_AE] = TRANSLATED_AE;
		g_Array[INDEX_BE] = TRANSLATED_BE;
		g_Array[INDEX_CE] = TRANSLATED_CE;
		g_Array[INDEX_DE] = TRANSLATED_DE;
		g_Array[INDEX_EE] = TRANSLATED_EE;
		g_Array[INDEX_FE] = TRANSLATED_FE;
		g_Array[INDEX_GE] = TRANSLATED_GE;
		g_Array[INDEX_HE] = TRANSLATED_HE;
		g_Array[INDEX_AF] = TRANSLATED_AF;
		g_Array[INDEX_BF] = TRANSLATED_BF;
		g_Array[INDEX_CF] = TRANSLATED_CF;
		g_Array[INDEX_DF] = TRANSLATED_DF;
		g_Array[INDEX_EF] = TRANSLATED_EF;
		g_Array[INDEX_FF] = TRANSLATED_FF;
		g_Array[INDEX_GF] = TRANSLATED_GF;
		g_Array[INDEX_HF] = TRANSLATED_HF;
	}

	translated array_table_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		return g_Array[Index];
	}

	std::vector<translated> g_Table;

	void dynamic_table_init()
	{
		g_Table.resize(INDEX_COUNT);
		g_Table[INDEX_A0] = TRANSLATED_A0;
		g_Table[INDEX_B0] = TRANSLATED_B0;
		g_Table[INDEX_C0] = TRANSLATED_C0;
		g_Table[INDEX_D0] = TRANSLATED_D0;
		g_Table[INDEX_E0] = TRANSLATED_E0;
		g_Table[INDEX_F0] = TRANSLATED_F0;
		g_Table[INDEX_G0] = TRANSLATED_G0;
		g_Table[INDEX_H0] = TRANSLATED_H0;
		g_Table[INDEX_A1] = TRANSLATED_A1;
		g_Table[INDEX_B1] = TRANSLATED_B1;
		g_Table[INDEX_C1] = TRANSLATED_C1;
		g_Table[INDEX_D1] = TRANSLATED_D1;
		g_Table[INDEX_E1] = TRANSLATED_E1;
		g_Table[INDEX_F1] = TRANSLATED_F1;
		g_Table[INDEX_G1] = TRANSLATED_G1;
		g_Table[INDEX_H1] = TRANSLATED_H1;
		g_Table[INDEX_A2] = TRANSLATED_A2;
		g_Table[INDEX_B2] = TRANSLATED_B2;
		g_Table[INDEX_C2] = TRANSLATED_C2;
		g_Table[INDEX_D2] = TRANSLATED_D2;
		g_Table[INDEX_E2] = TRANSLATED_E2;
		g_Table[INDEX_F2] = TRANSLATED_F2;
		g_Table[INDEX_G2] = TRANSLATED_G2;
		g_Table[INDEX_H2] = TRANSLATED_H2;
		g_Table[INDEX_A3] = TRANSLATED_A3;
		g_Table[INDEX_B3] = TRANSLATED_B3;
		g_Table[INDEX_C3] = TRANSLATED_C3;
		g_Table[INDEX_D3] = TRANSLATED_D3;
		g_Table[INDEX_E3] = TRANSLATED_E3;
		g_Table[INDEX_F3] = TRANSLATED_F3;
		g_Table[INDEX_G3] = TRANSLATED_G3;
		g_Table[INDEX_H3] = TRANSLATED_H3;

		g_Table[INDEX_A4] = TRANSLATED_A4;
		g_Table[INDEX_B4] = TRANSLATED_B4;
		g_Table[INDEX_C4] = TRANSLATED_C4;
		g_Table[INDEX_D4] = TRANSLATED_D4;
		g_Table[INDEX_E4] = TRANSLATED_E4;
		g_Table[INDEX_F4] = TRANSLATED_F4;
		g_Table[INDEX_G4] = TRANSLATED_G4;
		g_Table[INDEX_H4] = TRANSLATED_H4;
		g_Table[INDEX_A5] = TRANSLATED_A5;
		g_Table[INDEX_B5] = TRANSLATED_B5;
		g_Table[INDEX_C5] = TRANSLATED_C5;
		g_Table[INDEX_D5] = TRANSLATED_D5;
		g_Table[INDEX_E5] = TRANSLATED_E5;
		g_Table[INDEX_F5] = TRANSLATED_F5;
		g_Table[INDEX_G5] = TRANSLATED_G5;
		g_Table[INDEX_H5] = TRANSLATED_H5;
		g_Table[INDEX_A6] = TRANSLATED_A6;
		g_Table[INDEX_B6] = TRANSLATED_B6;
		g_Table[INDEX_C6] = TRANSLATED_C6;
		g_Table[INDEX_D6] = TRANSLATED_D6;
		g_Table[INDEX_E6] = TRANSLATED_E6;
		g_Table[INDEX_F6] = TRANSLATED_F6;
		g_Table[INDEX_G6] = TRANSLATED_G6;
		g_Table[INDEX_H6] = TRANSLATED_H6;
		g_Table[INDEX_A7] = TRANSLATED_A7;
		g_Table[INDEX_B7] = TRANSLATED_B7;
		g_Table[INDEX_C7] = TRANSLATED_C7;
		g_Table[INDEX_D7] = TRANSLATED_D7;
		g_Table[INDEX_E7] = TRANSLATED_E7;
		g_Table[INDEX_F7] = TRANSLATED_F7;
		g_Table[INDEX_G7] = TRANSLATED_G7;
		g_Table[INDEX_H7] = TRANSLATED_H7;

		g_Table[INDEX_A8] = TRANSLATED_A8;
		g_Table[INDEX_B8] = TRANSLATED_B8;
		g_Table[INDEX_C8] = TRANSLATED_C8;
		g_Table[INDEX_D8] = TRANSLATED_D8;
		g_Table[INDEX_E8] = TRANSLATED_E8;
		g_Table[INDEX_F8] = TRANSLATED_F8;
		g_Table[INDEX_G8] = TRANSLATED_G8;
		g_Table[INDEX_H8] = TRANSLATED_H8;
		g_Table[INDEX_A9] = TRANSLATED_A9;
		g_Table[INDEX_B9] = TRANSLATED_B9;
		g_Table[INDEX_C9] = TRANSLATED_C9;
		g_Table[INDEX_D9] = TRANSLATED_D9;
		g_Table[INDEX_E9] = TRANSLATED_E9;
		g_Table[INDEX_F9] = TRANSLATED_F9;
		g_Table[INDEX_G9] = TRANSLATED_G9;
		g_Table[INDEX_H9] = TRANSLATED_H9;
		g_Table[INDEX_AA] = TRANSLATED_AA;
		g_Table[INDEX_BA] = TRANSLATED_BA;
		g_Table[INDEX_CA] = TRANSLATED_CA;
		g_Table[INDEX_DA] = TRANSLATED_DA;
		g_Table[INDEX_EA] = TRANSLATED_EA;
		g_Table[INDEX_FA] = TRANSLATED_FA;
		g_Table[INDEX_GA] = TRANSLATED_GA;
		g_Table[INDEX_HA] = TRANSLATED_HA;
		g_Table[INDEX_AB] = TRANSLATED_AB;
		g_Table[INDEX_BB] = TRANSLATED_BB;
		g_Table[INDEX_CB] = TRANSLATED_CB;
		g_Table[INDEX_DB] = TRANSLATED_DB;
		g_Table[INDEX_EB] = TRANSLATED_EB;
		g_Table[INDEX_FB] = TRANSLATED_FB;
		g_Table[INDEX_GB] = TRANSLATED_GB;
		g_Table[INDEX_HB] = TRANSLATED_HB;

		g_Table[INDEX_AC] = TRANSLATED_AC;
		g_Table[INDEX_BC] = TRANSLATED_BC;
		g_Table[INDEX_CC] = TRANSLATED_CC;
		g_Table[INDEX_DC] = TRANSLATED_DC;
		g_Table[INDEX_EC] = TRANSLATED_EC;
		g_Table[INDEX_FC] = TRANSLATED_FC;
		g_Table[INDEX_GC] = TRANSLATED_GC;
		g_Table[INDEX_HC] = TRANSLATED_HC;
		g_Table[INDEX_AD] = TRANSLATED_AD;
		g_Table[INDEX_BD] = TRANSLATED_BD;
		g_Table[INDEX_CD] = TRANSLATED_CD;
		g_Table[INDEX_DD] = TRANSLATED_DD;
		g_Table[INDEX_ED] = TRANSLATED_ED;
		g_Table[INDEX_FD] = TRANSLATED_FD;
		g_Table[INDEX_GD] = TRANSLATED_GD;
		g_Table[INDEX_HD] = TRANSLATED_HD;
		g_Table[INDEX_AE] = TRANSLATED_AE;
		g_Table[INDEX_BE] = TRANSLATED_BE;
		g_Table[INDEX_CE] = TRANSLATED_CE;
		g_Table[INDEX_DE] = TRANSLATED_DE;
		g_Table[INDEX_EE] = TRANSLATED_EE;
		g_Table[INDEX_FE] = TRANSLATED_FE;
		g_Table[INDEX_GE] = TRANSLATED_GE;
		g_Table[INDEX_HE] = TRANSLATED_HE;
		g_Table[INDEX_AF] = TRANSLATED_AF;
		g_Table[INDEX_BF] = TRANSLATED_BF;
		g_Table[INDEX_CF] = TRANSLATED_CF;
		g_Table[INDEX_DF] = TRANSLATED_DF;
		g_Table[INDEX_EF] = TRANSLATED_EF;
		g_Table[INDEX_FF] = TRANSLATED_FF;
		g_Table[INDEX_GF] = TRANSLATED_GF;
		g_Table[INDEX_HF] = TRANSLATED_HF;
	}

	translated dynamic_table_translate(index Index)
	{
		assert(g_Table.size() == INDEX_COUNT);
		assert(Index < INDEX_COUNT);

		return g_Table[Index];
	}

	translated index_switch_translate(index Index)
	{
		assert(Index < INDEX_COUNT);

		switch(Index)
		{
		default:
		case INDEX_A0: return TRANSLATED_A0;
		case INDEX_B0: return TRANSLATED_B0;
		case INDEX_C0: return TRANSLATED_C0;
		case INDEX_D0: return TRANSLATED_D0;
		case INDEX_E0: return TRANSLATED_E0;
		case INDEX_F0: return TRANSLATED_F0;
		case INDEX_G0: return TRANSLATED_G0;
		case INDEX_H0: return TRANSLATED_H0;
		case INDEX_A1: return TRANSLATED_A1;
		case INDEX_B1: return TRANSLATED_B1;
		case INDEX_C1: return TRANSLATED_C1;
		case INDEX_D1: return TRANSLATED_D1;
		case INDEX_E1: return TRANSLATED_E1;
		case INDEX_F1: return TRANSLATED_F1;
		case INDEX_G1: return TRANSLATED_G1;
		case INDEX_H1: return TRANSLATED_H1;
		case INDEX_A2: return TRANSLATED_A2;
		case INDEX_B2: return TRANSLATED_B2;
		case INDEX_C2: return TRANSLATED_C2;
		case INDEX_D2: return TRANSLATED_D2;
		case INDEX_E2: return TRANSLATED_E2;
		case INDEX_F2: return TRANSLATED_F2;
		case INDEX_G2: return TRANSLATED_G2;
		case INDEX_H2: return TRANSLATED_H2;
		case INDEX_A3: return TRANSLATED_A3;
		case INDEX_B3: return TRANSLATED_B3;
		case INDEX_C3: return TRANSLATED_C3;
		case INDEX_D3: return TRANSLATED_D3;
		case INDEX_E3: return TRANSLATED_E3;
		case INDEX_F3: return TRANSLATED_F3;
		case INDEX_G3: return TRANSLATED_G3;
		case INDEX_H3: return TRANSLATED_H3;

		case INDEX_A4: return TRANSLATED_A4;
		case INDEX_B4: return TRANSLATED_B4;
		case INDEX_C4: return TRANSLATED_C4;
		case INDEX_D4: return TRANSLATED_D4;
		case INDEX_E4: return TRANSLATED_E4;
		case INDEX_F4: return TRANSLATED_F4;
		case INDEX_G4: return TRANSLATED_G4;
		case INDEX_H4: return TRANSLATED_H4;
		case INDEX_A5: return TRANSLATED_A5;
		case INDEX_B5: return TRANSLATED_B5;
		case INDEX_C5: return TRANSLATED_C5;
		case INDEX_D5: return TRANSLATED_D5;
		case INDEX_E5: return TRANSLATED_E5;
		case INDEX_F5: return TRANSLATED_F5;
		case INDEX_G5: return TRANSLATED_G5;
		case INDEX_H5: return TRANSLATED_H5;
		case INDEX_A6: return TRANSLATED_A6;
		case INDEX_B6: return TRANSLATED_B6;
		case INDEX_C6: return TRANSLATED_C6;
		case INDEX_D6: return TRANSLATED_D6;
		case INDEX_E6: return TRANSLATED_E6;
		case INDEX_F6: return TRANSLATED_F6;
		case INDEX_G6: return TRANSLATED_G6;
		case INDEX_H6: return TRANSLATED_H6;
		case INDEX_A7: return TRANSLATED_A7;
		case INDEX_B7: return TRANSLATED_B7;
		case INDEX_C7: return TRANSLATED_C7;
		case INDEX_D7: return TRANSLATED_D7;
		case INDEX_E7: return TRANSLATED_E7;
		case INDEX_F7: return TRANSLATED_F7;
		case INDEX_G7: return TRANSLATED_G7;
		case INDEX_H7: return TRANSLATED_H7;

		case INDEX_A8: return TRANSLATED_A8;
		case INDEX_B8: return TRANSLATED_B8;
		case INDEX_C8: return TRANSLATED_C8;
		case INDEX_D8: return TRANSLATED_D8;
		case INDEX_E8: return TRANSLATED_E8;
		case INDEX_F8: return TRANSLATED_F8;
		case INDEX_G8: return TRANSLATED_G8;
		case INDEX_H8: return TRANSLATED_H8;
		case INDEX_A9: return TRANSLATED_A9;
		case INDEX_B9: return TRANSLATED_B9;
		case INDEX_C9: return TRANSLATED_C9;
		case INDEX_D9: return TRANSLATED_D9;
		case INDEX_E9: return TRANSLATED_E9;
		case INDEX_F9: return TRANSLATED_F9;
		case INDEX_G9: return TRANSLATED_G9;
		case INDEX_H9: return TRANSLATED_H9;
		case INDEX_AA: return TRANSLATED_AA;
		case INDEX_BA: return TRANSLATED_BA;
		case INDEX_CA: return TRANSLATED_CA;
		case INDEX_DA: return TRANSLATED_DA;
		case INDEX_EA: return TRANSLATED_EA;
		case INDEX_FA: return TRANSLATED_FA;
		case INDEX_GA: return TRANSLATED_GA;
		case INDEX_HA: return TRANSLATED_HA;
		case INDEX_AB: return TRANSLATED_AB;
		case INDEX_BB: return TRANSLATED_BB;
		case INDEX_CB: return TRANSLATED_CB;
		case INDEX_DB: return TRANSLATED_DB;
		case INDEX_EB: return TRANSLATED_EB;
		case INDEX_FB: return TRANSLATED_FB;
		case INDEX_GB: return TRANSLATED_GB;
		case INDEX_HB: return TRANSLATED_HB;

		case INDEX_AC: return TRANSLATED_AC;
		case INDEX_BC: return TRANSLATED_BC;
		case INDEX_CC: return TRANSLATED_CC;
		case INDEX_DC: return TRANSLATED_DC;
		case INDEX_EC: return TRANSLATED_EC;
		case INDEX_FC: return TRANSLATED_FC;
		case INDEX_GC: return TRANSLATED_GC;
		case INDEX_HC: return TRANSLATED_HC;
		case INDEX_AD: return TRANSLATED_AD;
		case INDEX_BD: return TRANSLATED_BD;
		case INDEX_CD: return TRANSLATED_CD;
		case INDEX_DD: return TRANSLATED_DD;
		case INDEX_ED: return TRANSLATED_ED;
		case INDEX_FD: return TRANSLATED_FD;
		case INDEX_GD: return TRANSLATED_GD;
		case INDEX_HD: return TRANSLATED_HD;
		case INDEX_AE: return TRANSLATED_AE;
		case INDEX_BE: return TRANSLATED_BE;
		case INDEX_CE: return TRANSLATED_CE;
		case INDEX_DE: return TRANSLATED_DE;
		case INDEX_EE: return TRANSLATED_EE;
		case INDEX_FE: return TRANSLATED_FE;
		case INDEX_GE: return TRANSLATED_GE;
		case INDEX_HE: return TRANSLATED_HE;
		case INDEX_AF: return TRANSLATED_AF;
		case INDEX_BF: return TRANSLATED_BF;
		case INDEX_CF: return TRANSLATED_CF;
		case INDEX_DF: return TRANSLATED_DF;
		case INDEX_EF: return TRANSLATED_EF;
		case INDEX_FF: return TRANSLATED_FF;
		case INDEX_GF: return TRANSLATED_GF;
		case INDEX_HF: return TRANSLATED_HF;
		}
	}

	index value_switch_translate(translated Value)
	{
		assert(Value < TRANSLATED_COUNT);

		switch(Value)
		{
		default:
		case TRANSLATED_A0: return INDEX_A0;
		case TRANSLATED_B0: return INDEX_B0;
		case TRANSLATED_C0: return INDEX_C0;
		case TRANSLATED_D0: return INDEX_D0;
		case TRANSLATED_E0: return INDEX_E0;
		case TRANSLATED_F0: return INDEX_F0;
		case TRANSLATED_G0: return INDEX_G0;
		case TRANSLATED_H0: return INDEX_H0;
		case TRANSLATED_A1: return INDEX_A1;
		case TRANSLATED_B1: return INDEX_B1;
		case TRANSLATED_C1: return INDEX_C1;
		case TRANSLATED_D1: return INDEX_D1;
		case TRANSLATED_E1: return INDEX_E1;
		case TRANSLATED_F1: return INDEX_F1;
		case TRANSLATED_G1: return INDEX_G1;
		case TRANSLATED_H1: return INDEX_H1;
		case TRANSLATED_A2: return INDEX_A2;
		case TRANSLATED_B2: return INDEX_B2;
		case TRANSLATED_C2: return INDEX_C2;
		case TRANSLATED_D2: return INDEX_D2;
		case TRANSLATED_E2: return INDEX_E2;
		case TRANSLATED_F2: return INDEX_F2;
		case TRANSLATED_G2: return INDEX_G2;
		case TRANSLATED_H2: return INDEX_H2;
		case TRANSLATED_A3: return INDEX_A3;
		case TRANSLATED_B3: return INDEX_B3;
		case TRANSLATED_C3: return INDEX_C3;
		case TRANSLATED_D3: return INDEX_D3;
		case TRANSLATED_E3: return INDEX_E3;
		case TRANSLATED_F3: return INDEX_F3;
		case TRANSLATED_G3: return INDEX_G3;
		case TRANSLATED_H3: return INDEX_H3;

		case TRANSLATED_A4: return INDEX_A4;
		case TRANSLATED_B4: return INDEX_B4;
		case TRANSLATED_C4: return INDEX_C4;
		case TRANSLATED_D4: return INDEX_D4;
		case TRANSLATED_E4: return INDEX_E4;
		case TRANSLATED_F4: return INDEX_F4;
		case TRANSLATED_G4: return INDEX_G4;
		case TRANSLATED_H4: return INDEX_H4;
		case TRANSLATED_A5: return INDEX_A5;
		case TRANSLATED_B5: return INDEX_B5;
		case TRANSLATED_C5: return INDEX_C5;
		case TRANSLATED_D5: return INDEX_D5;
		case TRANSLATED_E5: return INDEX_E5;
		case TRANSLATED_F5: return INDEX_F5;
		case TRANSLATED_G5: return INDEX_G5;
		case TRANSLATED_H5: return INDEX_H5;
		case TRANSLATED_A6: return INDEX_A6;
		case TRANSLATED_B6: return INDEX_B6;
		case TRANSLATED_C6: return INDEX_C6;
		case TRANSLATED_D6: return INDEX_D6;
		case TRANSLATED_E6: return INDEX_E6;
		case TRANSLATED_F6: return INDEX_F6;
		case TRANSLATED_G6: return INDEX_G6;
		case TRANSLATED_H6: return INDEX_H6;
		case TRANSLATED_A7: return INDEX_A7;
		case TRANSLATED_B7: return INDEX_B7;
		case TRANSLATED_C7: return INDEX_C7;
		case TRANSLATED_D7: return INDEX_D7;
		case TRANSLATED_E7: return INDEX_E7;
		case TRANSLATED_F7: return INDEX_F7;
		case TRANSLATED_G7: return INDEX_G7;
		case TRANSLATED_H7: return INDEX_H7;

		case TRANSLATED_A8: return INDEX_A8;
		case TRANSLATED_B8: return INDEX_B8;
		case TRANSLATED_C8: return INDEX_C8;
		case TRANSLATED_D8: return INDEX_D8;
		case TRANSLATED_E8: return INDEX_E8;
		case TRANSLATED_F8: return INDEX_F8;
		case TRANSLATED_G8: return INDEX_G8;
		case TRANSLATED_H8: return INDEX_H8;
		case TRANSLATED_A9: return INDEX_A9;
		case TRANSLATED_B9: return INDEX_B9;
		case TRANSLATED_C9: return INDEX_C9;
		case TRANSLATED_D9: return INDEX_D9;
		case TRANSLATED_E9: return INDEX_E9;
		case TRANSLATED_F9: return INDEX_F9;
		case TRANSLATED_G9: return INDEX_G9;
		case TRANSLATED_H9: return INDEX_H9;
		case TRANSLATED_AA: return INDEX_AA;
		case TRANSLATED_BA: return INDEX_BA;
		case TRANSLATED_CA: return INDEX_CA;
		case TRANSLATED_DA: return INDEX_DA;
		case TRANSLATED_EA: return INDEX_EA;
		case TRANSLATED_FA: return INDEX_FA;
		case TRANSLATED_GA: return INDEX_GA;
		case TRANSLATED_HA: return INDEX_HA;
		case TRANSLATED_AB: return INDEX_AB;
		case TRANSLATED_BB: return INDEX_BB;
		case TRANSLATED_CB: return INDEX_CB;
		case TRANSLATED_DB: return INDEX_DB;
		case TRANSLATED_EB: return INDEX_EB;
		case TRANSLATED_FB: return INDEX_FB;
		case TRANSLATED_GB: return INDEX_GB;
		case TRANSLATED_HB: return INDEX_HB;

		case TRANSLATED_AC: return INDEX_AC;
		case TRANSLATED_BC: return INDEX_BC;
		case TRANSLATED_CC: return INDEX_CC;
		case TRANSLATED_DC: return INDEX_DC;
		case TRANSLATED_EC: return INDEX_EC;
		case TRANSLATED_FC: return INDEX_FC;
		case TRANSLATED_GC: return INDEX_GC;
		case TRANSLATED_HC: return INDEX_HC;
		case TRANSLATED_AD: return INDEX_AD;
		case TRANSLATED_BD: return INDEX_BD;
		case TRANSLATED_CD: return INDEX_CD;
		case TRANSLATED_DD: return INDEX_DD;
		case TRANSLATED_ED: return INDEX_ED;
		case TRANSLATED_FD: return INDEX_FD;
		case TRANSLATED_GD: return INDEX_GD;
		case TRANSLATED_HD: return INDEX_HD;
		case TRANSLATED_AE: return INDEX_AE;
		case TRANSLATED_BE: return INDEX_BE;
		case TRANSLATED_CE: return INDEX_CE;
		case TRANSLATED_DE: return INDEX_DE;
		case TRANSLATED_EE: return INDEX_EE;
		case TRANSLATED_FE: return INDEX_FE;
		case TRANSLATED_GE: return INDEX_GE;
		case TRANSLATED_HE: return INDEX_HE;
		case TRANSLATED_AF: return INDEX_AF;
		case TRANSLATED_BF: return INDEX_BF;
		case TRANSLATED_CF: return INDEX_CF;
		case TRANSLATED_DF: return INDEX_DF;
		case TRANSLATED_EF: return INDEX_EF;
		case TRANSLATED_FF: return INDEX_FF;
		case TRANSLATED_GF: return INDEX_GF;
		case TRANSLATED_HF: return INDEX_HF;
		}
	}
}//namespace translation128

template <typename INDEX_ENUM>
std::vector<INDEX_ENUM> generate_linear_data(std::size_t TotalCount, std::size_t IndexCount)
{
	std::vector<INDEX_ENUM> Data(TotalCount);
	for(std::size_t i = 0; i < TotalCount; ++i)
		Data[i] = static_cast<INDEX_ENUM>(i % IndexCount);
	return Data;
}

template <typename INDEX_ENUM>
std::vector<INDEX_ENUM> generate_uniform_data(std::size_t TotalCount, std::size_t IndexCount)
{
	std::size_t const SectionCount = TotalCount / IndexCount;
	std::vector<INDEX_ENUM> Data(TotalCount);

	for(std::size_t i = 0; i < TotalCount; ++i)
		Data[i] = static_cast<INDEX_ENUM>(i / SectionCount);

	return Data;
}

template <typename INDEX_ENUM>
std::vector<INDEX_ENUM> generate_random_data(std::size_t TotalCount, std::size_t IndexCount)
{
	std::vector<INDEX_ENUM> Data(TotalCount);
	for(std::size_t i = 0; i < TotalCount; ++i)
		Data[i] = static_cast<INDEX_ENUM>(std::rand() % IndexCount);
	return Data;
}

template <typename INDEX_ENUM, typename TRANSLATED_ENUM>
std::clock_t exec(std::vector<INDEX_ENUM> const & Tests, TRANSLATED_ENUM (*Translate) (INDEX_ENUM), int & Result)
{
	std::clock_t TimeStart = std::clock();

	for(std::size_t i = 0; i < Tests.size(); ++i)
		Result += Translate(Tests[i]);

	std::clock_t TimeEnd = std::clock();

	return TimeEnd - TimeStart;
}

template <typename INDEX_ENUM, typename TRANSLATED_ENUM>
void test_translation_set(FILE* File, char const * Title, std::size_t IterationCount, std::size_t TotalCount, std::size_t IndexCount, TRANSLATED_ENUM (*Translate) (INDEX_ENUM))
{
	std::vector<INDEX_ENUM> const UniformData(generate_uniform_data<INDEX_ENUM>(TotalCount, IndexCount));
	std::vector<INDEX_ENUM> const LinearData(generate_linear_data<INDEX_ENUM>(TotalCount, IndexCount));
	std::vector<INDEX_ENUM> const RandomData(generate_random_data<INDEX_ENUM>(TotalCount, IndexCount));

	int Result = 0;
	std::clock_t TimeTableUniform = 0;
	for(std::size_t i = 0; i < IterationCount; ++i)
		TimeTableUniform += exec<INDEX_ENUM, TRANSLATED_ENUM>(UniformData, Translate, Result);
	TimeTableUniform /= IterationCount;

	std::clock_t TimeTableLinear = 0;
	for(std::size_t i = 0; i < IterationCount; ++i)
		TimeTableLinear += exec<INDEX_ENUM, TRANSLATED_ENUM>(LinearData, Translate, Result);
	TimeTableLinear /= IterationCount;

	std::clock_t TimeTableRandom = 0;
	for(std::size_t i = 0; i < IterationCount; ++i)
		TimeTableRandom += exec<INDEX_ENUM, TRANSLATED_ENUM>(RandomData, Translate, Result);
	TimeTableRandom /= IterationCount;

	std::printf("%d\r", Result);
	std::printf(
		"%s: uniform %lu ms, linear %lu ms, random %lu ms\n",
		Title,
		TimeTableUniform * 1000 / CLOCKS_PER_SEC,
		TimeTableLinear * 1000 / CLOCKS_PER_SEC,
		TimeTableRandom * 1000 /  CLOCKS_PER_SEC);

	std::fprintf(
		File,
		"%s, %lu, %lu, %lu\n",
		Title,
		TimeTableUniform * 1000 / CLOCKS_PER_SEC,
		TimeTableLinear * 1000 / CLOCKS_PER_SEC,
		TimeTableRandom * 1000 /  CLOCKS_PER_SEC);
}

void test_translation_table()
{
	std::size_t const DuplicateCount = 3;
	std::size_t const IterationCount = 5;
	std::size_t const TotalCount = 50000000;

	translation4::array_table_init();
	translation4::dynamic_table_init();
	translation8::array_table_init();
	translation8::dynamic_table_init();
	translation16::array_table_init();
	translation16::dynamic_table_init();
	translation32::array_table_init();
	translation32::dynamic_table_init();
	translation64::array_table_init();
	translation64::dynamic_table_init();
	translation128::array_table_init();
	translation128::dynamic_table_init();

	FILE* File = fopen("results.csv", "a+");
	assert(File != NULL);

	for(std::size_t i = 0; i < DuplicateCount; ++i)
	{
		// 4 enum values
		char const * Title4 = "4, uniform (ms), linear (ms), random (ms)";
		std::printf("%s\n", Title4);
		std::fprintf(File, "%s\n", Title4);

		test_translation_set<translation4::index, translation4::translated>(
			File, "const table    ", IterationCount, TotalCount, translation4::INDEX_COUNT, translation4::const_table_translate);

		test_translation_set<translation4::index, translation4::translated>(
			File, "static table   ", IterationCount, TotalCount, translation4::INDEX_COUNT, translation4::static_table_translate);

		test_translation_set<translation4::index, translation4::translated>(
			File, "array table    ", IterationCount, TotalCount, translation4::INDEX_COUNT, translation4::array_table_translate);

		test_translation_set<translation4::index, translation4::translated>(
			File, "dynamic table  ", IterationCount, TotalCount, translation4::INDEX_COUNT, translation4::dynamic_table_translate);

		test_translation_set<translation4::index, translation4::translated>(
			File, "index switch   ", IterationCount, TotalCount, translation4::INDEX_COUNT, translation4::index_switch_translate);

		test_translation_set<translation4::translated, translation4::index>(
			File, "value switch   ", IterationCount, TotalCount, translation4::TRANSLATED_COUNT, translation4::value_switch_translate);

		// 8 enum values
		char const * Title8 = "8, uniform (ms), linear (ms), random (ms)";
		std::printf("%s\n", Title8);
		std::fprintf(File, "%s\n", Title8);

		test_translation_set<translation8::index, translation8::translated>(
			File, "const table    ", IterationCount, TotalCount, translation8::INDEX_COUNT, translation8::const_table_translate);

		test_translation_set<translation8::index, translation8::translated>(
			File, "static table   ", IterationCount, TotalCount, translation8::INDEX_COUNT, translation8::static_table_translate);

		test_translation_set<translation8::index, translation8::translated>(
			File, "array table    ", IterationCount, TotalCount, translation8::INDEX_COUNT, translation8::array_table_translate);

		test_translation_set<translation8::index, translation8::translated>(
			File, "dynamic table  ", IterationCount, TotalCount, translation8::INDEX_COUNT, translation8::dynamic_table_translate);

		test_translation_set<translation8::index, translation8::translated>(
			File, "index switch   ", IterationCount, TotalCount, translation8::INDEX_COUNT, translation8::index_switch_translate);

		test_translation_set<translation8::translated, translation8::index>(
			File, "value switch   ", IterationCount, TotalCount, translation8::TRANSLATED_COUNT, translation8::value_switch_translate);

		// 16 enum values
		char const * Title16 = "16, uniform (ms), linear (ms), random (ms)";
		std::printf("%s\n", Title16);
		std::fprintf(File, "%s\n", Title16);

		test_translation_set<translation16::index, translation16::translated>(
			File, "const table   ", IterationCount, TotalCount, translation16::INDEX_COUNT, translation16::const_table_translate);

		test_translation_set<translation16::index, translation16::translated>(
			File, "static table  ", IterationCount, TotalCount, translation16::INDEX_COUNT, translation16::static_table_translate);

		test_translation_set<translation16::index, translation16::translated>(
			File, "array table   ", IterationCount, TotalCount, translation16::INDEX_COUNT, translation16::array_table_translate);

		test_translation_set<translation16::index, translation16::translated>(
			File, "dynamic table ", IterationCount, TotalCount, translation16::INDEX_COUNT, translation16::dynamic_table_translate);

		test_translation_set<translation16::index, translation16::translated>(
			File, "index switch  ", IterationCount, TotalCount, translation16::INDEX_COUNT, translation16::index_switch_translate);

		test_translation_set<translation16::translated, translation16::index>(
			File, "value switch  ", IterationCount, TotalCount, translation16::TRANSLATED_COUNT, translation16::value_switch_translate);

		// 32 enum values
		char const * Title32 = "32, uniform (ms), linear (ms), random (ms)";
		std::printf("%s\n", Title32);
		std::fprintf(File, "%s\n", Title32);

		test_translation_set<translation32::index, translation32::translated>(
			File, "const table   ", IterationCount, TotalCount, translation32::INDEX_COUNT, translation32::const_table_translate);

		test_translation_set<translation32::index, translation32::translated>(
			File, "static table  ", IterationCount, TotalCount, translation32::INDEX_COUNT, translation32::static_table_translate);

		test_translation_set<translation32::index, translation32::translated>(
			File, "array table   ", IterationCount, TotalCount, translation32::INDEX_COUNT, translation32::array_table_translate);

		test_translation_set<translation32::index, translation32::translated>(
			File, "dynamic table ", IterationCount, TotalCount, translation32::INDEX_COUNT, translation32::dynamic_table_translate);

		test_translation_set<translation32::index, translation32::translated>(
			File, "index switch  ", IterationCount, TotalCount, translation32::INDEX_COUNT, translation32::index_switch_translate);

		test_translation_set<translation32::translated, translation32::index>(
			File, "value switch  ", IterationCount, TotalCount, translation32::TRANSLATED_COUNT, translation32::value_switch_translate);

		// 64 enum values
		char const * Title64 = "64, uniform (ms), linear (ms), random (ms)";
		std::printf("%s\n", Title64);
		std::fprintf(File, "%s\n", Title64);

		test_translation_set<translation64::index, translation64::translated>(
			File, "const table   ", IterationCount, TotalCount, translation64::INDEX_COUNT, translation64::const_table_translate);

		test_translation_set<translation64::index, translation64::translated>(
			File, "static table  ", IterationCount, TotalCount, translation64::INDEX_COUNT, translation64::static_table_translate);

		test_translation_set<translation64::index, translation64::translated>(
			File, "array table   ", IterationCount, TotalCount, translation64::INDEX_COUNT, translation64::array_table_translate);

		test_translation_set<translation64::index, translation64::translated>(
			File, "dynamic table ", IterationCount, TotalCount, translation64::INDEX_COUNT, translation64::dynamic_table_translate);

		test_translation_set<translation64::index, translation64::translated>(
			File, "index switch  ", IterationCount, TotalCount, translation64::INDEX_COUNT, translation64::index_switch_translate);

		test_translation_set<translation64::translated, translation64::index>(
			File, "value switch  ", IterationCount, TotalCount, translation64::TRANSLATED_COUNT, translation64::value_switch_translate);

		// 128 enum values
		char const * Title128 = "128, uniform (ms), linear (ms), random (ms)";
		std::printf("%s\n", Title128);
		std::fprintf(File, "%s\n", Title128);

		test_translation_set<translation128::index, translation128::translated>(
			File, "const table   ", IterationCount, TotalCount, translation128::INDEX_COUNT, translation128::const_table_translate);

		test_translation_set<translation128::index, translation128::translated>(
			File, "static table  ", IterationCount, TotalCount, translation128::INDEX_COUNT, translation128::static_table_translate);

		test_translation_set<translation128::index, translation128::translated>(
			File, "array table   ", IterationCount, TotalCount, translation128::INDEX_COUNT, translation128::array_table_translate);

		test_translation_set<translation128::index, translation128::translated>(
			File, "dynamic table ", IterationCount, TotalCount, translation128::INDEX_COUNT, translation128::dynamic_table_translate);

		test_translation_set<translation128::index, translation128::translated>(
			File, "index switch  ", IterationCount, TotalCount, translation128::INDEX_COUNT, translation128::index_switch_translate);

		test_translation_set<translation128::translated, translation128::index>(
			File, "value switch  ", IterationCount, TotalCount, translation128::TRANSLATED_COUNT, translation128::value_switch_translate);
	}

	fclose(File);

	return;
}
