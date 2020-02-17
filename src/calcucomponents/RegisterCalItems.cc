#include "RegisterCalItems.h"
#include "ICalItemRegistrar.h"
#include "OneGlassPanel.h"


void RegisterCalItems::RegiterAllItems()
{
	RegiterGlassItems();
}


void RegisterCalItems::RegiterGlassItems()
{

	CalItemRegistrar<CalculateItem,OneGlassPanel>oneGlassPanel(GlassParameters::GlassTypeStrs[GlassParameters::ONE]);
}
