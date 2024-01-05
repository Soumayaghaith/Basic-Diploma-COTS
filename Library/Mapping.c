#include "STD_TYPES.h"
#include "Mapping.h"

sint32 Mapping (sint32 Copy_s32InputRangMin, sint32 Copy_s32InputRangMax, sint32 Copy_s32OutputRangMin,sint32 Copy_s32OutputRangMax, sint32 Copy_s32InputValue)
{
	sint32 Local_s32MappingResult;

	Local_s32MappingResult = (( (Copy_s32OutputRangMax - Copy_s32OutputRangMin )*(Copy_s32InputValue - Copy_s32InputRangMin) )/ ( Copy_s32InputRangMax - Copy_s32InputRangMin)) + Copy_s32InputRangMin;




	return Local_s32MappingResult;

}

